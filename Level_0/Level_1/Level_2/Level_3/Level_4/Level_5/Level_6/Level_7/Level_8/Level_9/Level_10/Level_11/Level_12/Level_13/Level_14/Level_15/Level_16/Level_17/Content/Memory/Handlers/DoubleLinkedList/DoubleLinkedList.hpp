namespace Universe
{


namespace Memory
{


// In C the purpose of the keyword "typedef" with structures, was to reduce to need to add the keyword "struct" with every decleration of new
// instance of the structure. In C++ this is not needed anymore



// Array VS Linked List :
//
//	Array and linked list both are used to work with multiple elements of the same kind mostly. The difference starts first of all by the 
//	fact that an array will always be a contigous segment in memory, which means all the entires are located at the same memory location 
//	one after the other. This has the advantage that accessing every entry is immediate ( O( 1 ) ), because every entry location is known,
//	the third entry is 2 jumps of the pointer from the beginning of the array. The disadvantage is that there must be a long enough contigous
//	segment in memory. Linked list as it's name implies, is a set of interconnected entries. Each entry has a pointer to the next entry 
//	( double linked list ) and possibly to the previous one ( double linked list ). The advantage then is that each entry can be anywhere 
//	in memory, and when the next entry is required the pointer to the next entry is used. The disadvantage is that accessing the entries 
//	is more complicated. In the most simple linked lists, all there is to store is the address of the first entry ( the same as in the array 
//	case ), and then all the route to the entry needs to be done ( use the pointer in the first entry to the next entry, and so on until the
//	required entry is reached ). In very long linked lists this can take much time.
//
//	Beside this, the next consideration is derived from the usage. If the number of entries is known in advance then array is usually the 
//	better choice, because the access is faster. In cases where there should be many adding and deleting of entries, then linked list is 
//	better. This is because when an entry needs to be added, a bigger memory space is needed, and all the array should be copied to, while 
//	in linked list all there is to do is to change the pointer to the new entry and set the new entry to point to the rest of the linked list



// In C the purpose of the keyword "typedef" with structures, was to reduce to need to add the key word "struct" with every decleration of new instance of the
// structure. In C++ this is not needed anymore



// In order to parse a C++ program, the compiler needs to know whether certain names are types or not. The following example demonstrates that :
//
//      t * f;
//
// How should this be parsed? For many languages a compiler doesn't need to know the meaning of a name in order to parse and basically know what action a line of 
// code does. In C++, the above however can yield vastly different interpretations depending on what t means. If it's a type, then it will be a declaration of a 
// pointer f. However if it's not a type, it will be a multiplication. So the C++ Standard says at paragraph ( 3/7 ) :
//
// Some names denote types or templates. In general, whenever a name is encountered it is necessary to determine whether that name denotes one of these entities 
// before continuing to parse the program that contains it. The process that determines this is called name lookup
//
// How will the compiler find out what a name t::x refers to, if t refers to a template type parameter? 
//
// x could be a static int data member that could be multiplied or could equally well be a nested class or typedef that could yield to a declaration. If a name 
// has this property - that it can't be looked up until the actual template arguments are known - then it's called a dependent name ( it "depends" on the template 
// parameters )
//
// You might recommend to just wait till the user instantiates the template:
//
// Let's wait until the user instantiates the template, and then later find out the real meaning of t::x * f;.
//
// This will work and actually is allowed by the Standard as a possible implementation approach. These compilers basically copy the template's text into an internal 
// buffer, and only when an instantiation is needed, they parse the template and possibly detect errors in the definition. But instead of bothering the template's 
// users (poor colleagues!) with errors made by a template's author, other implementations choose to check templates early on and give errors in the definition as 
// soon as possible, before an instantiation even takes place
//
// So there has to be a way to tell the compiler that certain names are types and that certain names aren't
//
// The "typename" keyword :
//
// The answer is: We decide how the compiler should parse this. If t::x is a dependent name, then we need to prefix it by typename to tell the compiler to parse it 
// in a certain way. The Standard says at ( 14.6/2 ) :
//
// A name used in a template declaration or definition and that is dependent on a template-parameter is assumed not to name a type unless the applicable name lookup 
// finds a type name or the name is qualified by the keyword typename
//
// There are many names for which typename is not necessary, because the compiler can, with the applicable name lookup in the template definition, figure out how to 
// parse a construct itself - for example with T *f;, when T is a type template parameter. But for t::x * f; to be a declaration, it must be written as typename 
// t::x *f;. If you omit the keyword and the name is taken to be a non-type, but when instantiation finds it denotes a type, the usual error messages are emitted by 
// the compiler. Sometimes, the error consequently is given at definition time:
//
// t::x is taken as non-type, but as an expression the following misses an operator between the two names or a semicolon separating them
//
//      t::x f;
//
// The syntax allows typename only before qualified names - it is therefor taken as granted that unqualified names are always known to refer to types if they do so
//
// A similar gotcha exists for names that denote templates, as hinted at by the introductory text.
//
// The "template" keyword :
//
// Remember the initial quote above and how the Standard requires special handling for templates as well? Let's take the following innocent-looking example :
//
//      boost::function< int() > f;
//
// It might look obvious to a human reader. Not so for the compiler. Imagine the following arbitrary definition of 
// boost::function and f :
//
//      namespace boost { int function = 0; }
//      int main() 
//      { 
//          int f = 0;
//          boost::function< int() > f; 
//      }
//
// That's actually a valid expression! It uses the less-than operator to compare boost::function against zero ( int() ), and then uses the greater-than operator to 
// compare the resulting bool against f. However as you might well know, boost::function in real life is a template, so the compiler knows ( 14.2/3 ) :
//
// After name lookup ( 3.4 ) finds that a name is a template-name, if this name is followed by a <, the < is always taken as the beginning of a template-argument-list 
// and never as a name followed by the less-than operator
//
// Now we are back to the same problem as with typename. What if we can't know yet whether the name is a template when parsing the code? We will need to insert 
// template immediately before the template name, as specified by 14.2/4. This looks like :
//
//      t::template f<int>(); // call a function template
//
// Template names can not only occur after a :: but also after a -> or . in a class member access. You need to insert the keyword there too :
//
//      this->template f<int>(); // call a function template
//
// 
// Dependencies :
//
// In template declarations some constructs have different meanings depending on what template arguments you use to instantiate the template : Expressions may have 
// different types or values, variables may have different types or function calls might end up calling different functions. Such constructs are generally said to 
// depend on template parameters
//
// The Standard defines precisely the rules by whether a construct is dependent or not. It separates them into logically different groups: One catches types, another 
// catches expressions. Expressions may depend by their value and/or their type. So we have, with typical examples appended :
//
// Dependent types ( e.g: a type template parameter T )
// Value-dependent expressions ( e.g: a non-type template parameter N )
// Type-dependent expressions ( e.g: a cast to a type template parameter (T)0 )
//
// Most of the rules are intuitive and are built up recursively: For example, a type constructed as T[N] is a dependent type if N is a value-dependent expression or 
// T is a dependent type. The details of this can be read in section ( 14.6.2/1 ) for dependent types, ( 14.6.2.2 ) for type-dependent expressions and ( 14.6.2.3 ) 
// for value-dependent expressions.
//
// Dependent names
//
// The Standard is a bit unclear about what exactly is a dependent name. On a simple read, all it defines as a dependent name is the special case for function names 
// below. But since clearly T::x also needs to be looked up in the instantiation context, it also needs to be a dependent name ( fortunately, as of mid C++14 the 
// committee has started to look into how to fix this confusing definition )
//
// Of all the constructs that denote dependent types or expressions, a subset of them represent names. Those names are therefore "dependent names". A name can take 
// different forms - the Standard says :
//
// A name is a use of an identifier ( 2.11 ), operator-function-id ( 13.5 ), conversion-function-id ( 12.3.2 ), or template-id ( 14.2 ) that denotes an entity or label 
// ( 6.6.4, 6.1 )
//
// An identifier is just a plain sequence of characters / digits, while the next two are the operator + and operator type form. The last form is template-name 
// < argument list >. All these are names, and by conventional use in the Standard, a name can also include qualifiers that say what namespace or class a name should be 
// looked up in
//
// A value dependent expression 1 + N is not a name, but N is. The subset of all dependent constructs that are names is called dependent name. Function names, however, 
// may have different meaning in different instantiations of a template, but unfortunately are not caught by this general rule 
//
// Dependent function names
//
// Not primarily a concern of this article, but still worth mentioning: Function names are an exception that are handled separately. An identifier function name is 
// dependent not by itself, but by the type dependent argument expressions used in a call. In the example f( (T)0 ), f is a dependent name. In the Standard, this is 
// specified at ( 14.6.2/1 ) :
//
// Additional notes and examples
//
// In enough cases we need both of typename and template. Your code should look like the following
//
//      template <typename T, typename Tail>
//      struct UnionNode : public Tail {
//      // ...
//      template<typename U> struct inUnion {
//      typedef typename Tail::template inUnion<U> dummy;
//      };
//      // ...
//      };
//
// The keyword template doesn't always have to appear in the last part of a name. It can appear in the middle before a class name that's used as a scope, like in the 
// following example
//
//      typename t::template iterator<int>::value_type v;
//
// In some cases, the keywords are forbidden, as detailed below
//
// On the name of a dependent base class you are not allowed to write typename. It's assumed that the name given is a class type name. This is true for both names 
// in the base-class list and the constructor initializer list :
//
//      template <typename T>
//      struct derive_from_Has_type : /* typename */ SomeBase<T>::type 
//      { };
//
// In using-declarations it's not possible to use template after the last ::, and the C++ committee said not to work on a solution.
//
//      template <typename T>
//      struct derive_from_Has_type : SomeBase<T> {
//      using SomeBase<T>::template type; // error
//      using typename SomeBase<T>::type; // typename *is* allowed
//      };



// Template Class Information :
//
//  Purpose :
//
//		Use this object to store multiple instances of the same type. The instances will not be stored in contigous memory space, but rather
//		as seperated nodes connected through pointers. Each node will have a pointer to the next node in the list. This allows making changes
//		without the needs to copy large amout of contigous memory spaces, in other words changes in this platform cost very little in terms
//		of performance. This is a double linked list which means the current node only knows about the next node, and therefore passes on this
//		platform are only in one direction
//
//  Description :
//
//		1. This object contains an instance of the object "InstnaceState" to allow each instance of this object to have a defined state
//
// 		2. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
//		   providing 3 keywords :
//
//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
//						member is public all the encapsulation is lost, so it should be avoided in most cases
//
//			2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will
//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few
//						   data members
//
//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this
//						 part will end with the suffix __Private
//
//		3. Template arguments :
//
//			1. DataType - any type
//
//		4. If a node needs to be added at index 2 then :
//
//				Currently the singled linked list looks :
//
//					--------------	--------------	--------------	--------------	  
//					| Old Node 0 |	| Old Node 1 |	| Old Node 2 |	| Old Node 3 |	...
//					--------------	--------------	--------------	--------------  
//
//				After the addition :
//
//														Added 	  Moved up by 1 index
//														  |				   |
//					--------------	--------------	--------------	--------------	--------------	  
//					| Old Node 0 |	| Old Node 1 |	| New Node 2 |	| Old Node 3 |	| Old Node 4 |	...
//					--------------	--------------	--------------	--------------	-------------- 
//
//			As can be seen all the nodes that exist in the double linked list before the addition, starting from the node with the required index,
//			will be moved one index up
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType = MainMemoryManager >
class DoubleLinkedList
{
public:


	// Create a type definition for this object
	using SelfType = DoubleLinkedList< DataType, MemoryManagerType >;

	// Create a type definition for the nodes of this object
	using NodeType = DoubleLinkedListNode< DataType >;

    // Create a type definition for the data
    using SelfDataType = DataType;


	// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
	// the compiler generates a basic behavior for them if possible :


	// Method Information :
    //
    //  Description :
	//
	//		Default Constructor,
	//
	//  Required arguments :
	//
	//		User information needed :
	//
    //          memoryManagerPointer - a pointer to a memory manger. The pointr should be NULL if the main memory manager to be used
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline DoubleLinkedList();


    // Method Information :
    //
    //  Description :
    //
    //      Constructor,
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. size - the number of entries in the double linked list
    //          2. data - a constant reference to the data that will be used to initialize all the nodes
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      NONE
    //
    //  Expectations :
    //
    //      1. The given size is larger then 0
    //      2. 
    //
    //  Possible errors :
    //
    //      1. No more free memory space exist in the heap - Class Error::Exception is thrown
    //      2. 
    //
    explicit inline DoubleLinkedList( const LargestUnsignedInteger size, const DataType& data = ActAccordingToType::GetDefaultInstance< DataType >() );


    // Method Information :
    //
    //  Description :
    //
    //      Constructor, to allow copying only from the given index on the other instance until the given size
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. other - a constant reference to other memory handler instancewith
    //          2. startingIndexOnOtherInstance - the index of the first entry that should be copied from the other instance
    //          3. sizeFromOther - the size from the other instance to copy to this instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      NONE
    //
    //  Expectations :
    //
    //      1. The size of the other instance should be larger then 0
    //      2. The index to start from on the other instance should be smaller then the size of the other instance
    //      3. The size from other to copy must be larger then 0
    //      4. The size of the other instance minus the index to start from should be larger or equal then the size to copy
    //      5.
    //
    //  Possible errors :
    //
    //      1. There is no more free memory space - Class Error::Exception is thrown
    //      2. 
    //
    template< template< typename, typename > class OtherMemoryHandlerType, typename OtherMemoryHandlerMemoryManagerType = MainMemoryManager >
    explicit inline DoubleLinkedList( const OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >& other, const LargestUnsignedInteger startingIndexOnOtherInstance, const LargestUnsignedInteger sizeFromOther );


    // Method Information :
    //
    //  Description :
    //
    //      Constructor, to allow copying only from the given index on the other instance until the given size. This overload is for
    //      rvalue reference, it will move the data from the other instance instead of copying it
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. other - an rvalue reference to other memory handler instancewith
    //          2. startingIndexOnOtherInstance - the index of the first entry that should be copied from the other instance
    //          3. sizeFromOther - the size from the other instance to copy to this instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      NONE
    //
    //  Expectations :
    //
    //      1. The size of the other instance should be larger then 0
    //      2. The index to start from on the other instance should be smaller then the size of the other instance
    //      3. The size from other to copy must be larger then 0
    //      4. The size of the other instance minus the index to start from should be larger or equal then the size to copy
    //      5.
    //
    //  Possible errors :
    //
    //      1. There is no more free memory space - Class Error::Exception is thrown
    //      2. 
    //
    template< template< typename, typename > class OtherMemoryHandlerType, typename OtherMemoryHandlerMemoryManagerType = MainMemoryManager >
    explicit inline DoubleLinkedList( OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >&& other, const LargestUnsignedInteger startingIndexOnOtherInstance, const LargestUnsignedInteger sizeFromOther );


	// Method Information :
	//
	//  Description :
	//
	//		Copy constructor, will operate correctly even if the other instance is in default state or self assignment
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			other - a reference to the instance that should be copied
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		1. No more free memory space exist in the heap - Class Error::Exception is thrown
	//		2. 
	//
	inline DoubleLinkedList( const SelfType& other );


	// Add the following infrastructure to the object :
	//
	//		1. Assignment operator
	//		2. Move constructor
	//		3. Move assignment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure_ForInheritance( DoubleLinkedList )


	// Method Information :
	//
	//  Description :
	//
	//		Destructor, does not throw
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	virtual ~DoubleLinkedList();


	// This part will contain all the get and set methods for the members of the object :


	GetByValue_Creator( /* GetMethodName */ Size, /* MemberName */ member_size, /* MemberType */ LargestUnsignedInteger )


	// The following methods give access and manipulate the data inside this object :


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to get the size in bytes of the data in the instance
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          NONE
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      The size of the data in the instance multiplied by the data type size in bytes
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      NONE
    //
    EnsureRetrunValueIsUsed inline LargestUnsignedInteger SizeInBytes() const;


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to get the size in bytes of the data type used in the object
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          NONE
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      The size of the data type used in the object
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      NONE
    //
    EnsureRetrunValueIsUsed inline LargestUnsignedInteger DataTypeSizeInBytes() const;


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to add data to the instance. The data will be added at the provided index, which means that after the
    //      addition accessing the data with the given index will return the currently added data, furthermore the data currently represented
    //      by the index will be advanced one index up, as well as all the rest of the data above the index
    //
    //      Note 1 - if the data should be added to the end of the instance, provide as index the current size of the instance
    //      Note 2 - if the instance is in default state, the only valid index to insert datat to is 0
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. addTheDataAtThisIndex - the index in which the data should be added
    //          2. data - a universal reference to the data to add
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      NONE
    //
    //  Expectations :
    //
    //      1. The given index should be smaller or equal to the instance size
    //      2. 
    //
    //  Possible errors :
    //
    //      1. There is no more free memory space - Class Error::Exception is thrown
    //      2. 
    //
    template< typename UniversalReferenceDataType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceDataType, DataType >::Result == true )
    inline void InsertSingleElement( const LargestUnsignedInteger addTheDataAtThisIndex, UniversalReferenceDataType&& data );


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to add data to the instance. The data will be added starting from the provided index. This overload is
    //      to allow constructing the data instance from arguments
    //
    //      Note 1 - if the data should be added to the end of the instance, provide as index the current size of the instance
    //      Note 2 - if the instance is in default state, the only valid index to insert datat to is 0
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. addTheDataAtThisIndex - the index at which the data will be inserted to
    //          2. anyArgumentNeededToConstructDataIstance - any arguments needed to construct an instance of the data
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      NONE
    //
    //  Expectations :
    //
    //      1. The index to add the data must be smaller or equal to the size of the memory handler
    //      2. There is a constructor of the data object that accepts the given arguemnts
    //      3. 
    //
    //  Possible errors :
    //
    //      1. There is no more free memory space - Class Error::Exception is thrown
    //      2. 
    //
    template< typename... AnyArgumentNeededToConstructDataInstanceTypes >
    inline void InsertSingleElementCreateFromArguments( const LargestUnsignedInteger addTheDataAtThisIndex, AnyArgumentNeededToConstructDataInstanceTypes&&... anyArgumentNeededToConstructDataIstance );


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to add data to the instance. The data will be added starting from the provided index. This overload is
    //      to allow adding the same data to multiple entries
    //
    //      Note 1 - if the data should be added to the end of the instance, provide as index the current size of the instance
    //      Note 2 - if the instance is in default state, the only valid index to insert datat to is 0
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. addTheDataAtThisIndex - the index in which the data should be added in the instance
    //          2. sizeToAdd - the number of elements to add
    //          3. data - the data the will be store in the new entries
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      NONE
    //
    //  Expectations :
    //
    //      1. The first index to add should be smaller or equal to the size of this instance
    //      2.
    //
    //  Possible errors :
    //
    //      1. There is no more free memory space - Class Error::Exception is thrown
    //      2. 
    //
    inline void InsertMultipleTimesTheSameElement( const LargestUnsignedInteger addTheDataAtThisIndex, const LargestUnsignedInteger sizeToAdd, const DataType& data = DataType() );


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to add data to the instance. The data will be added starting from the provided index. It allows setting the
    //      data starting from an offset on the other instance until the required size
    //
    //      Note 1 - if the data should be added to the end of the instance, provide as index the current size of the instance
    //      Note 2 - if the instance is in default state, the only valid index to insert datat to is 0
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. other - a constant reference to other memory handler
    //          2. addDataStartingFromThisIndexInThisInstance - the index at which the data from the other instance needs to be inserted to
    //          3. addDataStartingFromThisIndexOnOtherInstance - the index of the first entry to insert from the other instance
    //          4. sizeToAdd - the size from the other instance to insert
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      NONE
    //
    //  Expectations :
    //
    //      1. The other instance size should be larger then 0
    //      2. The index to start from on the this instance should be smaller then the size of this instance
    //      3. The index to start from on the other instance should be smaller then the size of the other instance
    //      4. This instance size minus index to start from on this instance should be equal or larger then the size to set
    //      5. The other instance size minus index to start from on the other instance should be equal or larger then the size to set
    //      6.
    //
    //  Possible errors :
    //
    //      1. There is no more free memory space - Class Error::Exception is thrown
    //      2. 
    //
    template< template< typename, typename > class OtherMemoryHandlerType, typename OtherMemoryHandlerMemoryManagerType = MainMemoryManager >
    inline void InsertElementsFromOtherInstance( const OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >& other, const LargestUnsignedInteger addDataStartingFromThisIndexInThisInstance, const LargestUnsignedInteger addDataStartingFromThisIndexOnOtherInstance, const LargestUnsignedInteger sizeToAdd );


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to add data to the instance. The data will be added starting from the provided index. It allows setting 
    //      the data starting from an offset on the other instance until the required size. This overload is for rvalue reference
    //      instances, that the data can be moved from and there is no need to copy
    //
    //      Note 1 - if the data should be added to the end of the instance, provide as index the current size of the instance
    //      Note 2 - if the instance is in default state, the only valid index to insert datat to is 0
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. other - a constant reference to other memory handler
    //          2. addDataStartingFromThisIndexInThisInstance - the index at which the data from the other instance needs to be inserted to
    //          3. addDataStartingFromThisIndexOnOtherInstance - the index of the first entry to insert from the other instance
    //          4. sizeToAdd - the size from the other instance to insert
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      NONE
    //
    //  Expectations :
    //
    //      1. The other instance size should be larger then 0
    //      2. The index to start from on the this instance should be smaller then the size of this instance
    //      3. The index to start from on the other instance should be smaller then the size of the other instance
    //      4. This instance size minus index to start from on this instance should be equal or larger then the size to set
    //      5. The other instance size minus index to start from on the other instance should be equal or larger then the size to set
    //      6.
    //
    //  Possible errors :
    //
    //      1. There is no more free memory space - Class Error::Exception is thrown
    //      2. 
    //
    template< template< typename, typename > class OtherMemoryHandlerType, typename OtherMemoryHandlerMemoryManagerType = MainMemoryManager >
    inline void InsertElementsFromOtherInstance( OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >&& other, const LargestUnsignedInteger addDataStartingFromThisIndexInThisInstance, const LargestUnsignedInteger addDataStartingFromThisIndexOnOtherInstance, const LargestUnsignedInteger sizeToAdd );


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to add data to the instance. The data will be added starting from the provided index
    //
    //      Note 1 - if the data should be added to the end of the instance, provide as index the current size of the instance
    //      Note 2 - if the instance is in default state, the only valid index to insert datat to is 0
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. dataPointer - a pointer with the memory address of the data
    //          2. addTheDataAtThisIndex - the index at which the data needs to be inserted to
    //          3. dataSize - the size of the data the pointer points to
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      NONE
    //
    //  Expectations :
    //
    //      1. The given pointer to the data is not NULL
    //      2. The index to start from on the this instance should be smaller then the size of this instance
    //      3. The data size should be larger then 0
    //      4. 
    //
    //  Possible errors :
    //
    //      1. There is no more free memory space - Class Error::Exception is thrown
    //      2. 
    //
    inline void InsertElementsFromRawData( const DataType* const dataPointer, const LargestUnsignedInteger addTheDataAtThisIndex, const LargestUnsignedInteger dataSize );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to remove entries from the instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			indexOfFirstDataToRemove - the index of the first entry to remove
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. The given index is smaller then the instance size
	//		3. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void Remove( const LargestUnsignedInteger indexOfFirstDataToRemove, const LargestUnsignedInteger sizeToRemove );


	// The following methods declare the overloaded operators for the object :


    // Method Information :
    //
    //  Description :
    //
    //      Use this operator to check if the this instance match the other
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          other - a constnt reference to a single linekd list instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      1. true - if the 2 instances are the same
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline Boolean operator==( const SelfType& other ) const;


    // Method Information :
    //
    //  Description :
    //
    //      Use this operator to check if the this instance does not match the other
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          other - a reference to the instance that should be compared with this object
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      1. true - if the 2 instances are not the same
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline Boolean operator!=( const SelfType& other ) const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to get a reference to the required data
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			index - the index of the required data
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A reference to the required data
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. The given index is smaller then the double linked list size
	//		3. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline DataType& operator[]( LargestUnsignedInteger index );


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to get a constant reference to the required data
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			index - the index of the required data
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
    //      A constant reference to the required data
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. The given index is smaller then the double linked list size
	//		3. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline const DataType& operator[]( LargestUnsignedInteger index ) const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to add the content of another instance to the end of this instance
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			other - a reference to the instance that should be concatenated to the end of this instance
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A referene to this instance
	//
	//  Expectations :
	//
	//		1. The other instance must be ready
	//		2. The other instance size must be larger then 0
	//		3.
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	inline SelfType& operator+=( const SelfType& other );


	DEBUG_TOOL(

		// This part of the object is dedicated for testing :


		// Method Information :
		//
		//  Description :
		//
		//		This method is used to test the object. It is not part of the implementation, it is only used to find problems with the code
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			NONE
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//			NONE
		//
		//  Expectations :
		//
		//		Please let the test pass lord!!
		//
		//  Possible errors :
		//
		//		It says there are no problems, which is even scarier, did I just wrote a working code??
		//
		static inline void UnitTest() __attribute__ (( __unused__ ));

	)  //  End of debug tool


private:


	// This object will be the root of the double linked list instance
	NodeType* member_root;

	// This object will store the memory address of the last node in the double linked list instance
	NodeType* member_lastNode;

	// This object will store the number of nodes in the double linked list instance
	LargestUnsignedInteger member_size;


	// The following data members are added to make specific optimizations. The first one is to store the memory address of the last node, to allow 
	// adding a node to the end of the double linked list without passing on all the nodes for it. The second and third are used to store the memory
	// address and index of the last used node. This will allow first of all another starting point beside the beginning of the double linked list
	// to find specific nodes, furthermore, it will allow passing on all the nodes, without starting each time from the root :

	// This object will store the active node, meaning the node that the instance is currently workin on
	mutable NodeType* member_activeNode;

	// This object will store the active node index, meaning the node index that the instance is currently workin on
	mutable LargestUnsignedInteger member_activeNodeIndex;


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
	// rather help implement it :


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to connect two subsequent nodes. This action set the next node pointer of the former node to point to the latter node, and
    //      the previous node of the latter node to point to the former node
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. formerNode - the node which is with a lower index
    //          2. followingNode - the node which is with the higher index
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      NONE
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    inline void ConnectTwoSubsequentNodes__Private( NodeType* const formerNode, NodeType* const followingNode );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to delete all the node from the double linked list
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			firstNodeToDelete - the memory address of the first node to delete
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		1. The given pointer is not NULL
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void DeleteNodes__Private( NodeType* const firstNodeToDelete );


	// Method Information :
	//
	//  Description :
	//
    //		Use this method to add a chain of nodes into the instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. firstNodePointer - a pointer with the memory address of the first node in the chain
	//			2. lastNodePointer - a pointer with the memory address of the last noode in the chain
	//			3. addNodesStartingFromThisIndex - the first index from which nodes should be added to the double linked list instance
	//			4. size - the number of nodes
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		1. The given pointer to the first node should not be NULL
	//		2. The given pointer to the last node should not be NULL
	//		3. The given index should be smaller or equal to the double linked list size
	//		4. The given size of the chain should be larger then 0
	//		5. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void InsertTheNewNodesToTheRequiredLocation__Private( NodeType* const firstNodePointer, NodeType* const lastNodePointer, const LargestUnsignedInteger addNodesStartingFromThisIndex, const LargestUnsignedInteger size );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to get the memory address of a specific node. The method will check if the shortest path to the required node is from
	//		the beginning or from the last used node, and take that path. The required node will be stored in the active node member
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			index - the index of the required node
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
    //      NONE
	//
	//  Expectations :
	//
	//		1. The given index is smaller then the double linked list size
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void TakeShortestPathToNodeAndSetItAsTheActiveNode__Private( const LargestUnsignedInteger index ) const;


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to advance from the given node to the required node, and store at as the active node
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. node - the memory address of the node to start from
    //          2. numberOfNodesToTargetNode - the number of nodes that the required node is away from the given node
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      NONE
    //
    //  Expectations :
    //
    //      1. The given pointer is not NULL
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    inline void MoveForwardUntilRequiredNodeAndReturnTheMemoryAddress__Private( NodeType* const node, const LargestUnsignedInteger numberOfNodesToTargetNode ) const;


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to backward from the given node to the required node, and store at as the active node
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. node - the memory address of the node to start from
    //          2. numberOfNodesToTargetNode - the number of nodes that the required node is away from the given node
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      NONE
    //
    //  Expectations :
    //
    //      1. The given pointer is not NULL
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    inline void MoveBackwardUntilRequiredNodeAndReturnTheMemoryAddress__Private( NodeType* const node, const LargestUnsignedInteger numberOfNodesToTargetNode ) const;


};  //  Class DoubleLinkedList