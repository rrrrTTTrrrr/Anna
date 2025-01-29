namespace Universe
{



// Deduction refers to the process of determining the type of a template parameter from a given argument. It applies to function templates, auto
// and few other cases ( e.g partial specialization ). For example, consider :
//
//		template< typename Type >
//		void Flow( std::list< Type > );
//
// Now if the function is used as 'Flow( X )', where X was declared as :
//
//		std::list< int > X;
//
// Then the template type is deduced as 'int', and the resulting specialization 'Flow< int >'.
//
// In order for deduction to work, the template parameter type that is to be deduced has to appear in a deducible context. In this example, the
// function parameter of 'Flow' is such a deducible context. That is, an argument in the function call expression allows us to determine what 
// the template parameter should be in order for the call expression to be valid.
//
// However there are non deduced contexts, where no deduction is possible. The canonical example is "a template parameter that appears to the
// left of a ::" :
//
//		template< typename Type >
//		class Anna;
//
// 		template< typename Type >
//		void FuckAnna( typename Anna< Type >::type );
//
// In this function template, the template argument is a non deduced context. Thus it cannot be be used as 'FuckAnna( X )' and deduce the template
// argument. The reason for this is that there is no "backwards correspondence" between arbitrary types and members. For example, the following
// specializations can be created :
//
//		template<>
//		class FuckAnna< int >
//		{
//			using type = double;
//		}
//
//		template<>
//		class FuckAnna< double >
//		{
//			using type = double;
//		}
//
//		template<>
//		class FuckAnna< char >
//		{
//			using type = short;
//		}
//
// As can be seen calling the function as 'FuckAnna( int() )' has two possible answers for the template argument!



// What are aggregates and why they are speical?
//
// Formal definition form the C++ standard - an aggregate is an array or a class with no user declared constructors, no private or protected 
// non static data members, no base classes, and no virtual functions!
//
// First of all, any array is an aggregate. A class can also be an aggregate, and although noting is said about structures and unions, they
// also can be aggregates. In C++ the term class referes to all classes, structures and unions. A class then can only be an aggregate if it
// satisfies the criteria from the above definitions. What do these criteria imply?
//
// 	1. This does not mean an aggregate class cannot have constructors, in fact it can have default consturctor, copy and move constructors as
//     long as they are implicitly decalred by the compiler, and not explicitly by the user
//
// 	2. No private or protected non static data members. It can have many private and protected member functions as well as many private and
//     protected static data members and member functions as needed and not violate the rules for aggregate classes
//
// 	3. An aggregate class can have a user defined copy assignment operator and destructor
//
// 	4. An array is an aggregate even if it has non aggregate class type as data
//
// Aggregates, unlike non aggregate calsses can be initialized with curly braces '{}'. For exmaple :
//
//		LargestUnsignedInteger Array[ size ] = { 1, 2, 3, ... };
//
// There are 4 cases :
//
//	1. The size is equal to the number of values - all the elements of the array are initialized
//
//	2. The size of the array is larger then number of values - only the first entries of the array are initialized with the values and the rest
//	   if possible are value initialized
//
//	3. The size of the array is smaller then number of values - the compiler will issue an error
//
//	4. In case the size of the array is not supplied, it is the same as case 1



// The following definitions are used to make the access to the tuple entries more clear. In other words it will provide an enumeration
// to the value instead of using the value itself :
//
#define WAS_DATA_FOUND 0UL
#define DATA_LOCATION 1UL
#define DOES_PATTERN_WAS_FOUND 0UL
#define PATTERN_STARTING_LOCATION 1UL



// The purpose of this enumeration is to allow picking between the different memory handlers during run time
enum class MemoryHandlerName
{

	Vector,

	SingleLinkedList,

	DoubleLinkedList,

	PagesArray

};



// Class Information :
//
//  Purpose :
//
//		Artifical Inteligence
//
//  Description :
//
//		1. This object is used as a base object in inheritance. Therefore it must have a few methods virtual. When an object has a virtual method, the
//		   C++ automatically creates a table with all the pointers to the virtual methods, where the pointer to the table is stored in the beginning of
//		   the object. The problem arises when a new method needs to be created with the same signature as one in the base object, and the use of pointers.
//		   Take a look at next example :
//
//				class Base
//				{
//				    void Display() { cout << "Lord" << endl; }
//				};
//
//				class Derived : public Base
//				{
//				    void Display(); { cout << "Help Me" << endl; }    -> Derived inherits Display from Base but needs another behavior
//				};
//
//         Now if a call is made :
//
//				Base* base = new Base;
//				Derived* derived = new Derived;
//
//				base->Display( 5 );   -> Outputs "Lord"
//				derived->Display();   -> Outputs "Help Me"
//
//         So far so good, a normal method is called by the static type of the pointer. This means no matter what the object the pointer is
//		   pointing to it will call the method of the type he was declared as. This is a problematic behavior in inheritance, we need to point
//		   to derived objects with base pointers and that the correct method will be called. But now :
//
//				void Do( Base* base ) { base->Display(); }
//
//				Base* base = new Base;
//				Derived* derived = new Derived;
//
//				Do( base );        -> Outputs "Lord"
//				Do( derived );     -> Outputs "Lord"
//
//         This is what virtual allow in C++, instead of calling the method by the static type in compilation, the call to the method is picked
//		   dynamically by the actual type of the object. This is done by the pointer in the beginning of the object that points to the virtual
//		   table of the type. Of course it can be overloaded to the derived, but then if there is a deep inheritance a method will be needed to
//		   be overloaded for each one
//
// 		2. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
//		   providing 3 keywords :
//
//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
//						member is public all the encapsulation is lost, so it should be avoided in most cases
//
//			2. Protected - this part is for developing purposes, inheritance. A developer can inherit from this object and it will
//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few
//						   data members
//
//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this
//						 part will end with the suffix __Private
//
//		3. Template arguments :
//
//			1.
//
//      4. The search pattern algorithm :
//
//          Notion : n = data size, k = pattern size
//
//          This object deals with searching data in containers that manage array. Now if the required pattern consist of entry in the array,
//          in the search every element should be checked until a match is found or the end of the array reached. This search for one specific 
//          entry then will have a worst case of passing on all the entries ( O(n) ). This is not the case if the pattern is a set of more then 
//          one entry. Every entry now must be matched with the pattern and this makes the worst case to O(n*k). To reduce the need of constant
//          repeat checking entries in the data that were already checked, a lookup table is created, which tells the index on the data where
//          to move next and start a new search for the pattern. While nothing is known on the data, the pattern is do known
//
//          To logic is as follows :
//
//          All the entries before the current entry must be used to find if a match is found. A match between entries starting from the beginning of
//          the pattern, and entries starting from the second entry. They both have an initial size of the current index on the pattern minus 1.
//          In each loop the size is decreasing by 1. Then for the first set of entries th beginning point is fixed, and the end point decreases
//          as the size decreases. For second set the end point is fixed and the beginning point increases as the size decreases. It looks for the
//          longest match 
//
//          For example,
//
//                                  pattern -> bbfddsdfffbbfyyy
//
//          pattern[4] has before him "bbfd", so the following check must be done  :
//
//
//                              First loop
//
//                                  entries starting from the beginning -> bbf
//                                  entries starting from the second entry -> bfd
//                                  size = 3
//                                  
//                              Second loop
//
//                                  entries starting from the beginning -> bb
//                                  entries starting from the second entry -> fd
//                                  size = 2
//
//                              Third loop
//
//                                  entries starting from the beginning -> b
//                                  entries starting from the second entry -> d
//                                  size = 1
//
//          As can be seen the sets dont match in any case therefore the index on the data should advance the amount pattern index has,
//          which means all this data before can not match no need to check it again
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType = Memory::MainMemoryManager >
class SequentialDataStructure
{
public:


	// Create a type definition for this object
	using SelfType = SequentialDataStructure< DataType, MemoryManagerType >;

	// Create a type definition for the data type
	using SelfDataType = DataType;

	// Create a type definition for the vector
	using SelfVectorType = Memory::Vector< DataType, MemoryManagerType >;

	// Create a type definition for the single linked list
	using SelfSingleLinkedListType = Memory::SingleLinkedList< DataType, MemoryManagerType >;

	// Create a type definition for the double linked list
	using SelfDoubleLinkedListType = Memory::DoubleLinkedList< DataType, MemoryManagerType >;

	// Create a type definition for the pages array
	using SelfPagesArrayType = Memory::PagesArray< DataType, MemoryManagerType >;


	// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
	// the compiler generates a basic behavior for them if possible :


	// Method Information :
	//
	//  Description :
	//
	//		Constructor,
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. memoryHandlerName - the enumeration of the memory handler to use
	//			2. anyArgumentsNeededToConstructMemoryHandler - any argument needed to construct an instance of the memory handler
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
	//		1. One of the memory handler constructors except the given arguments
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	template< typename... AnyArgumentsNeededToConstructMemoryHandlerTypes >
	explicit inline SequentialDataStructure( const MemoryHandlerName memoryHandlerName = MemoryHandlerName::Vector, AnyArgumentsNeededToConstructMemoryHandlerTypes&&... anyArgumentsNeededToConstructMemoryHandler );


	// Method Information :
	//
	//  Description :
	//
	//		Constructor, to allow copying only part of the other instance. It will start from the given index on the other instance until
	//		the given size
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. other - a constant reference to other sequential data structure instance
	//			2. otherInstanceStartingIndex - the index of the first entry that should be copied from the other instance
	//			3. size - the size from the other instance to copy to this instance
	//			4. memoryHandlerName - the enumeration of the memory handler to use
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
	//		1. The size of the other instance should be larger then 0
	//		2. The index to start from on the other instance should be smaller then the size of the other instance
	//		3. The size from other to copy must be larger then 0
	//		4. The size of the other instance minus the index to start from should be larger or equal then the size to copy
	//		5.
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	explicit inline SequentialDataStructure( const SelfType& other, const LargestUnsignedInteger otherInstanceStartingIndex, const LargestUnsignedInteger size, const MemoryHandlerName memoryHandlerName );


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
	//		    other - a reference to the instance that should be copied
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
	//		They will come
	//
	inline SequentialDataStructure( const SelfType& other );


	// Add the following infrastructure to the object :
	//
	//		1. Assigenment operator
	//		2. Move constructor
	//		3. Move assigenment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure_ForInheritance( SequentialDataStructure )


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
	//		They will come
	//
	virtual ~SequentialDataStructure();


	// This part will contain all the get and set methods for the members of the object :


	GetByValue_Creator( /* GetMethodName */ UsedMemoryHandlerName, /* MemberName */ member_memoryHandlerName, /* MemberType */ MemoryHandlerName )


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		Use the method to switch between memory handlers
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			newMemoryHandlerName - the new memory handler to use in the instance
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
	//		1. The current memory handler used is different then the new memory handler
	//		2.
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	inline void SwitchMemoryHandler( const MemoryHandlerName newMemoryHandlerName );


	// Method Information :
	//
	//  Description :
	//
	//		Use the method to get the size
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
	//		The size of the instance
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
	EnsureRetrunValueIsUsed inline LargestUnsignedInteger Size() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the size in bytes of the data in the instance
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
	//		The size of the data in the instance multiplied by the data type size in bytes
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
    EnsureRetrunValueIsUsed inline LargestUnsignedInteger SizeInBytes() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the size in bytes of the data type used in the object
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
	//		The size of the data type used in the object
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
    EnsureRetrunValueIsUsed inline LargestUnsignedInteger DataTypeSizeInBytes() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use the method to set a part of the sequential data structure to the required data
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. startingIndex - the index from which setting will start
	//			2. size - the size of the sequential data structure to set
	//			3. data - a constant reference to the data to set
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
	//		1. The size to set must be larger then 0
	//		2. The index to start from on the instance should be smaller then the size of the instance
	//		3. The size left in the instance after the starting index should be larger or equal to the size to set
	//		4. 
	//
	//  Possible errors :
	//
	//		NONE
	//
	inline void Set( const LargestUnsignedInteger startingIndex, const LargestUnsignedInteger size, const DataType& data );


	// Method Information :
	//
	//  Description :
	//
	//		Use the method to copy a part of the other sequential data structure instance into this instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    1. other - a constant reference to the instance that should be copied
	//			2. thisInstanceStartingIndex - the index from which copying the other instance will start on this instance
	//			3. otherInstanceStartingIndex - the index from which the copying will start from on the other instance
	//			4. size - the size to copy from the other instance
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
	//		1. The size to copy must be larger then 0
	//		2. The index to start from on the instance should be smaller then the size of the instance
	//		3. The index to start from on the other instance should be smaller then the size of the other instance
	//		4. The size left in the instance after the starting index should be larger or equal to the size to set
	//		5. The size left in the other instance after the starting index should be larger or equal to the size to set
	//		6. 
	//
	//  Possible errors :
	//
	//		NONE
	//
	inline void Copy( const SelfType& other, const LargestUnsignedInteger thisInstanceStartingIndex, const LargestUnsignedInteger otherInstanceStartingIndex, const LargestUnsignedInteger size );


	// Method Information :
	//
	//  Description :
	//
	//		Use the method to move a part of the other sequential data structure instance into this instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    1. other - an rvalue reference to the instance that should be movied
	//			2. thisInstanceStartingIndex - the index from which moving the other instance will start on this instance
	//			3. otherInstanceStartingIndex - the index from which the moving will start from on the other instance
	//			4. size - the size to move from the other instance
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
	//		1. The size to move must be larger then 0
	//		2. The index to start from on the instance should be smaller then the size of the instance
	//		3. The index to start from on the other instance should be smaller then the size of the other instance
	//		4. The size left in the instance after the starting index should be larger or equal to the size to set
	//		5. The size left in the other instance after the starting index should be larger or equal to the size to set
	//		6. 
	//
	//  Possible errors :
	//
	//		NONE
	//
	inline void Move( SelfType&& other, const LargestUnsignedInteger thisInstanceStartingIndex, const LargestUnsignedInteger otherInstanceStartingIndex, const LargestUnsignedInteger size );


	// Method Information :
	//
	//  Description :
	//
	//		Use the method to move a part of the other sequential data structure instance into this instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    1. other - a constant reference to the instance that should be compared
	//			2. thisInstanceStartingIndex - the index from which comparing the other instance will start on this instance
	//			3. otherInstanceStartingIndex - the index from which the comparing will start from on the other instance
	//			4. size - the size to compare from the other instance
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
	//		1. The size to compare must be larger then 0
	//		2. The index to start from on the instance should be smaller then the size of the instance
	//		3. The index to start from on the other instance should be smaller then the size of the other instance
	//		4. The size left in the instance after the starting index should be larger or equal to the size to set
	//		5. The size left in the other instance after the starting index should be larger or equal to the size to set
	//		6. 
	//
	//  Possible errors :
	//
	//		NONE
	//
	EnsureRetrunValueIsUsed inline Boolean Compare( const SelfType& other, const LargestUnsignedInteger thisInstanceStartingIndex, const LargestUnsignedInteger otherInstanceStartingIndex, const LargestUnsignedInteger size ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to add data to the instance. The data will be added at the provided index, which means that after the
	//		addition accessing the data with the given index will return the currently added data, furthermore the data currently represented
	//		by the index will be advanced one index up, as well as all the rest of the data above the index
	//
	//		Note 1 - if the data should be added to the end of the instance, provide as index the current size of the instance
	//		Note 2 - if the instance is in default state, the only valid index to insert datat to is 0
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. index - the index in which the data should be added in the instance
	//			2. data - a universal reference to the data to add
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
	//		1. The given index should be smaller or equal to the instance size
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	template< typename UniversalReferenceDataType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceDataType, DataType >::Result == true )
    inline void InsertSingleElement( const LargestUnsignedInteger index, UniversalReferenceDataType&& data );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to add data to the instance. The data will be added starting from the provided index. This overload is 
	//		to allow setting the data starting from an offset on the other instance until the required size
	//
	//		Note 1 - if the data should be added to the end of the instance, provide as index the current size of the instance
	//		Note 2 - if the instance is in default state, the only valid index to insert datat to is 0
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. other - a constant reference to other memory handler
	//			2. thisInstanceStartingIndex - the index at which the data from the other instance needs to be inserted to
	//			3. otherInstanceStartingIndex - the index of the first entry to insert from the other instance
	//			4. size - the size from the other instance to insert
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
	//		1. The other instance size should be larger then 0
	//		2. The index to start from on the this instance should be smaller then the size of this instance
	//		3. The index to start from on the other instance should be smaller then the size of the other instance
	//		4. This instance size minus index to start from on this instance should be equal or larger then the size to set
	//		5. The other instance size minus index to start from on the other instance should be equal or larger then the size to set
	//		6.
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
    template< typename... AnyArgumentNeededToConstructDataInstanceTypes >
    inline void InsertSingleElementCreateFromArguments( const LargestUnsignedInteger index, AnyArgumentNeededToConstructDataInstanceTypes&&... anyArgumentNeededToConstructDataIstance );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to add data to the instance. The data will be added starting from the provided index. This overload is
	//		to allow adding the same data to multiple entries
	//
	//		Note 1 - if the data should be added to the end of the instance, provide as index the current size of the instance
	//		Note 2 - if the instance is in default state, the only valid index to insert datat to is 0
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. index - the index in which the data should be added in the instance
	//			2. size - the number of elements to add
	//			3. data - the data the will be store in the new entries
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
	//		1. The first index to add should be smaller or equal to the size of this instance
	//		2.
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
    inline void InsertMultipleTimesTheSameElement( const LargestUnsignedInteger index, const LargestUnsignedInteger size, const DataType& data = DataType() );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to add data to the instance. The data will be added starting from the provided index. It allows setting the
	//		data starting from an offset on the other instance until the required size
	//
	//		Note 1 - if the data should be added to the end of the instance, provide as index the current size of the instance
	//		Note 2 - if the instance is in default state, the only valid index to insert datat to is 0
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. other - a constant reference to another instance
	//			2. thisInstanceStartingIndex - the index at which the data from the other instance needs to be inserted to
	//			3. otherInstanceStartingIndex - the index of the first entry to insert from the other instance
	//			4. size - the size from the other instance to insert
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
	//		1. The other instance size should be larger then 0
	//		2. The index to start from on the this instance should be smaller then the size of this instance
	//		3. The index to start from on the other instance should be smaller then the size of the other instance
	//		4. This instance size minus index to start from on this instance should be equal or larger then the size to set
	//		5. The other instance size minus index to start from on the other instance should be equal or larger then the size to set
	//		6.
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
    inline void InsertElementsFromOtherInstance( const SelfType& other, const LargestUnsignedInteger thisInstanceStartingIndex, const LargestUnsignedInteger otherInstanceStartingIndex, const LargestUnsignedInteger size );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to add data to the instance. The data will be added starting from the provided index. It allows setting 
	//		the data starting from an offset on the other instance until the required size. This overload is for rvalue reference
	//		instances, that the data can be moved from and there is no need to copy
	//
	//		Note 1 - if the data should be added to the end of the instance, provide as index the current size of the instance
	//		Note 2 - if the instance is in default state, the only valid index to insert datat to is 0
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. other - a constant reference to another instance
	//			2. thisInstanceStartingIndex - the index at which the data from the other instance needs to be inserted to
	//			3. otherInstanceStartingIndex - the index of the first entry to insert from the other instance
	//			4. size - the size from the other instance to insert
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
	//		1. The other instance size should be larger then 0
	//		2. The index to start from on the this instance should be smaller then the size of this instance
	//		3. The index to start from on the other instance should be smaller then the size of the other instance
	//		4. This instance size minus index to start from on this instance should be equal or larger then the size to set
	//		5. The other instance size minus index to start from on the other instance should be equal or larger then the size to set
	//		6.
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
    inline void InsertElementsFromOtherInstance( SelfType&& other, LargestUnsignedInteger thisInstanceStartingIndex, LargestUnsignedInteger otherInstanceStartingIndex, LargestUnsignedInteger size );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to add data to the instance. The data will be added starting from the provided index
	//
	//		Note 1 - if the data should be added to the end of the instance, provide as index the current size of the instance
	//		Note 2 - if the instance is in default state, the only valid index to insert datat to is 0
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. dataPointer - a pointer with the memory address of the data
	//			2. index - the index at which the data needs to be inserted to
	//			3. size - the size of the data the pointer points to
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
	//		1. The given pointer to the data is not NULL
	//		2. The index to start from on the this instance should be smaller then the size of this instance
	//		3. The data size should be larger then 0
	//		4. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	inline void InsertElementsFromRawData( const DataType* const dataPointer, const LargestUnsignedInteger index, const LargestUnsignedInteger size );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to add data to the beginning of the instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			data - a universal reference to the data to add
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
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
    template< typename UniversalReferenceDataType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceDataType, DataType >::Result == true )
    inline void InsertSingleElementAtTheBeginning( UniversalReferenceDataType&& data );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to add data to the end of the instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			data - a universal reference to the data to add
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
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
    template< typename UniversalReferenceDataType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceDataType, DataType >::Result == true )
    inline void InsertSingleElementAtTheEnd( UniversalReferenceDataType&& data );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to remove data from the instance. The data will be added at the provided index, which means that after 
	//		the removal the data currently represented by the index plus one will be drawn back one index down, as well as all the rest of 
	//		the data above the index
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. index - the first index from which data should be removed from the array instance
	//			2. size - the number of entries to remove from the array
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
	//		2. The given index to the remove the data plus the size to remove must result in a sum smaller or equal to the instance size
	//		3. 
	//
	//  Possible errors :
	//
	//		NONE
	//
	inline void Remove( const LargestUnsignedInteger index, const LargestUnsignedInteger size );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to remove the first element
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
	//		NONE
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. The instance should contain at least one element
	//		3.
	//
	//  Possible errors :
	//
	//		NONE
	//
    inline void RemoveFirst();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to remove the last element
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
	//		NONE
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. The instance should contain at least one element
	//		3.
	//
	//  Possible errors :
	//
	//		NONE
	//
    inline void RemoveLast();


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to get the location of a specific apperance of a single element in the data
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. data - the data to search for in the instance
	//			2. apperanceNumber - this will be used to determine which apperance the user require to search for the position
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//   	A tuple with the first entry containing a boolean to describe if the required apperance of the data was found or not.
	//		If it was found the boolean will contain true, then the second entry will contain the index that the data was found
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. The apperance number must be larger then 0
	//		3.
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Memory::Tuple< Boolean, LargestUnsignedInteger > SearchSingleElement( const DataType& data, const LargestUnsignedInteger apperanceNumber = 1UL ) const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to get the location of a all the apperances of a single element in the data
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			data - the data to search for in the instance
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		An vector containing all the apperances of the required data in the sequential data structure instance
	//
	//  Expectations :
	//
	//		1. The instance should be ready 
	//		2. The apperance number must be larger then 0
	//		3.
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	EnsureRetrunValueIsUsed inline SequentialDataStructure< LargestUnsignedInteger > SearchAllApperancesOfSingleElement( const DataType& data ) const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to get the location of a specific apperance of the pattern in the data
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. pattern - a constant reference to a sequential data structure instance that contains information that needs to be found in the data
	//			2. apperanceNumber - this will be used to determine which apperance the user require to search for the position
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//   	A tuple with the first entry containing a boolean to describe if the required apperance of the pattern was found or not.
	//		If it was found the boolean will contain true, then the second entry will contain the index that the pattern was found
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. The pattern size should be larger then 0
	//		3. The apperance number must be larger then 0
	//		4. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	template< typename PatternMemoryManagerType >
	EnsureRetrunValueIsUsed inline Memory::Tuple< Boolean, LargestUnsignedInteger > SearchPattern( const SequentialDataStructure< DataType, PatternMemoryManagerType >& pattern, const LargestUnsignedInteger apperanceNumber = 1UL ) const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to get the location of a all the apperances of the pattern in the data
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			pattern - a constant reference to a sequential data structure instance that contains information that needs to be found in the data
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		An vector containing all the apperances of the pattern in the sequential data structure instance
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. The pattern size should be larger then 0
	//		3. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	template< typename PatternMemoryManagerType >
	EnsureRetrunValueIsUsed inline SequentialDataStructure< LargestUnsignedInteger, MemoryManagerType > SearchAllApperancesOfPattern( const SequentialDataStructure< DataType, PatternMemoryManagerType >& pattern ) const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to get check if the instance contains the pattern
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			pattern - a constant reference to a sequential data structure instance that contains information that needs to be found in the data
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//   	True if the instance contains the pattern, and false otherwise
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. The pattern size should be larger then 0
	//		3. 
	//
	//  Possible errors :
	//
	//		They will comde
	//
	template< typename PatternMemoryManagerType >
	EnsureRetrunValueIsUsed inline Boolean Contains( const SequentialDataStructure< DataType, PatternMemoryManagerType >& pattern ) const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to get a reference to the first element
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			NONE
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		A reference to the first element
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. There should be at least one element
	//		3. 
	//
	//  Possible errors :
	//
	//		NONE 
	//
    EnsureRetrunValueIsUsed inline DataType& First();


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to get a constant reference to the first element
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			NONE
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		A constant reference to the first element
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. There should be at least one element
	//		3. 
	//
	//  Possible errors :
	//
	//		NONE 
	//
    EnsureRetrunValueIsUsed inline const DataType& First() const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to get a reference to the last element
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			NONE
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		A reference to the last element
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. There should be at least one element
	//		3. 
	//
	//  Possible errors :
	//
	//		NONE 
	//
    EnsureRetrunValueIsUsed inline DataType& Last();


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to get a constant reference to the last element
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			NONE
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		A constant reference to the last element
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. There should be at least one element
	//		3. 
	//
	//  Possible errors :
	//
	//		NONE 
	//
    EnsureRetrunValueIsUsed inline const DataType& Last() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use the method to get the a constant reference to the memory handler inside, in this case the vector. It is the responsibility
	//		of the user to ensure that the instance is currently using the vector as the memory handler otherwise an exception will be
	//		thrown
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
	//		A constant reference to the vector memory handler
	//
	//  Expectations :
	//
	//		1. The instance is currently using the vector as the memory handler
	//		2. 
	//
	//  Possible errors :
	//
    //		NONE
	//
    EnsureRetrunValueIsUsed inline DataType* DataPointer() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use the method to get the a constant reference to the memory handler inside, in this case the pages array. It is the responsibility
	//		of the user to ensure that the instance is currently using the pages array as the memory handler otherwise an exception will be
	//		thrown
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
	//		A constant reference to the pages array memory handler
	//
	//  Expectations :
	//
	//		1. The instance is currently using the pages array as the memory handler
	//		2. 
	//
	//  Possible errors :
	//
    //		NONE
	//
    EnsureRetrunValueIsUsed inline const Memory::Vector< DataType* >& PointersToPages() const;


	// The following methods declare the overloaded operators for the object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to check if the this instance match the other
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a reference to the instance that should be compared with this object
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		1. true - if the 2 instances are the same
	//		2. false - otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Boolean operator==( const SelfType& other ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to check if the this instance does not match the other
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a reference to the instance that should be compared with this object
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		1. true - if the 2 instances are not the same
	//		2. false - otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Boolean operator!=( const SelfType& other ) const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to get a reference the value inside the required entry
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			index - the index of the required entry
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
    //      A reference to the value inside the required entry
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. The given index is smaller then the array size
	//		3. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline DataType& operator[]( const LargestUnsignedInteger index );


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to get a constant reference the value inside the required entry
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			index - the index of the required entry
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
    //      A constant reference to the value inside the required entry
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. The given index is smaller then the array size
	//		3. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline const DataType& operator[]( const LargestUnsignedInteger index ) const;


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


	// This union will store pointers to all the possible memory handlers, and only the pointer for the required memory handler will
	// be used at each time
	union
	{

		SelfVectorType* member_vectorPointer;

		SelfSingleLinkedListType* member_singleLinkedListPointer;

		SelfDoubleLinkedListType* member_doubleLinkedListPointer;

		SelfPagesArrayType* member_pagesArrayPointer;

	} member_memoryHandler;

	// This object will store the enumeration of the current used memory handler
	MemoryHandlerName member_memoryHandlerName;


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of
	// the interface, but rather help implement it :


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to construct the memory handler
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			anyArgumentsNeededToConstructMemoryHandler - any argument needed to construct an instance of the memory handler
	//
	//      Information returned to the user :
	//
	//          NONE
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
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	template< typename... AnyArgumentsNeededToConstructMemoryHandlerTypes >
	inline void ConstructMemoryHandler__Private( AnyArgumentsNeededToConstructMemoryHandlerTypes... anyArgumentsNeededToConstructMemoryHandler );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to switch between memory handlers
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. newMemoryHandlerName - the new memory handler to use in the instance
	//			2. currentMemoryHandlerPointer - a pointer with memory address of the current memory handler
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		1. The given pointer to the current memory handler is not NULL
	//		2.
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	template< typename CurrentMemoryHandlerType >
	inline void SwitchMemoryHandler__Private( const MemoryHandlerName newMemoryHandlerName, CurrentMemoryHandlerType* const currentMemoryHandlerPointer );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to get the location of a specific apperance of a single element in the data
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. memoryHandler - a constant reference to the current memory handler used in the instance
	//			2. data - the data to search for in the instance
	//			3. apperanceNumber - this will be used to determine which apperance the user require to search for the position
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//   	A tuple with the first entry containing a boolean to describe if the required apperance of the data was found or not.
	//		If it was found the boolean will contain true, then the second entry will contain the index that the data was found
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. The apperance number must be larger then 0
	//		3.
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename MemoryHandlerType >
	EnsureRetrunValueIsUsed inline Memory::Tuple< Boolean, LargestUnsignedInteger > SearchSingleElement__Private( const MemoryHandlerType& memoryHandler, const DataType& data, const LargestUnsignedInteger apperanceNumber ) const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to get the location of a all the apperances of a single element in the data
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. memoryHandler - a constant reference to the current memory handler used in the instance
	//			2. data - the data to search for in the instance
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		An vector containing all the apperances of the required data in the sequential data structure instance
	//
	//  Expectations :
	//
	//		1. The instance should be ready 
	//		2. The apperance number must be larger then 0
	//		3.
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	template< typename MemoryHandlerType >
	EnsureRetrunValueIsUsed inline SequentialDataStructure< LargestUnsignedInteger > SearchAllApperancesOfSingleElement__Private( const MemoryHandlerType& memoryHandler, const DataType& data ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to process the pattern and produce a look up table to perform a more fast search over the sequential data 
	//		structure instance
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			pattern - a constant reference to a sequential data structure view that contains the pattern
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      An array with the same size as the pattern, that contains the amount to move the index before the next search if a mismatch
	//		between the entry in the sequential data structure instance and the pattern was found
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. The pattern size should be larger then 0
	//		3. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	template< typename PatternMemoryHandlerType >
	EnsureRetrunValueIsUsed inline Memory::Vector< LargestUnsignedInteger > ProcessPatternToFindTheStartingPointForTheNextSearchIfMismatchWasFoundBetweenThePatternAndTheData__Private( const PatternMemoryHandlerType& pattern ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to check if the two parts of the pattern match
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. pattern - a constant reference to a sequential data structure view that contains information that needs to be found in the data
	//			2. subpatternFirstEntryIndex - the index of the first entry of the subpattern
	//			3. subpatternSize - the size of the subpattern to compare
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//   	True if the two parts of the pattern match, and false otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename PatternMemoryHandlerType >
	EnsureRetrunValueIsUsed inline Boolean Compare__Private( const PatternMemoryHandlerType& pattern, const LargestUnsignedInteger subpatternFirstEntryIndex, const LargestUnsignedInteger subpatternSize ) const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to get the location of the next apperance of the pattern in the data. The search will start from the given index on the data
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. memoryHandler - a constant reference to the current memory handler used in the instance
	//			2. pattern - a constant reference to a sequential data structure view that contains information that needs to be found in the data
	//			3. startSearchFromThisIndex - the index from which the search needs to start
	//			4. startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch - a constant reference to an vector instance, with
	//			   the information on how to proceed if a mismatch between the sequential data structure instance and the pattern was found
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//   	The index of the next apperance of the pattern in the data. If no apperance was found then the size of the sequential data 
	//		structure instance will be returned
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename MemoryHandlerType, typename PatternMemoryHandlerType >
	EnsureRetrunValueIsUsed inline LargestUnsignedInteger FindNextApperance__Private( const MemoryHandlerType& memoryHandler, const LargestUnsignedInteger startSearchFromThisIndex, const PatternMemoryHandlerType& pattern, const Memory::Vector< LargestUnsignedInteger >& startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch ) const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to get the location of a specific apperance of the pattern in the data
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. memoryHandler - a constant reference to the current memory handler used in the instance
	//			2. pattern - a constant reference to a memory handler instance that contains information that needs to be found in the data
	//			3. apperanceNumber - this will be used to determine which apperance the user require to search for the position
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//   	A tuple with the first entry containing a boolean to describe if the required apperance of the pattern was found or not.
	//		If it was found the boolean will contain true, then the second entry will contain the index that the pattern was found
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. The pattern size should be larger then 0
	//		3. The apperance number must be larger then 0
	//		4. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	template< typename MemoryHandlerType, typename PatternMemoryHandlerType >
	EnsureRetrunValueIsUsed inline Memory::Tuple< Boolean, LargestUnsignedInteger > SearchPattern__Private( const MemoryHandlerType& memoryHandler, const PatternMemoryHandlerType& pattern, const LargestUnsignedInteger apperanceNumber ) const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to get the location of a all the apperances of the pattern in the data
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. memoryHandler - a constant reference to the current memory handler used in the instance
	//			2. pattern - a constant reference to a memory handler instance that contains information that needs to be found in the data
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		An vector containing all the apperances of the pattern in the sequential data structure instance
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. The pattern size should be larger then 0
	//		3. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	template< typename MemoryHandlerType, typename PatternMemoryHandlerType >
	EnsureRetrunValueIsUsed inline SequentialDataStructure< LargestUnsignedInteger > SearchAllApperancesOfPattern__Private( const MemoryHandlerType& memoryHandler, const PatternMemoryHandlerType& pattern ) const;


};  //  Class SequentialDataStructure