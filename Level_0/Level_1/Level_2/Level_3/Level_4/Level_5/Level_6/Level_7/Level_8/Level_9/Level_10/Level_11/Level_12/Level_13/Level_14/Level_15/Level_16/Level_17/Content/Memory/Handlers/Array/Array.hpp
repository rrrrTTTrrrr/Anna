namespace Universe
{


namespace Memory
{



// There are two versions of using the operator new :
//
//      new unsigned int;       // default initialized ( nothing happens )
//      new unsigned int();     // zero initialized ( set to 0 )
//
// Also works for arrays :
//
//      new unsigned int[5];    // default initialized ( nothing happens )
//      new unsigned int[5]();  // zero initialized ( all elements set to 0 )



// Both "class" and "typename" within C++ indicate a type parameter since the keywords do not hold any platform significance – for example, class is not meant to 
// suggest a native type nor is typename meant to suggest a CLI type. Rather, both equivalently indicate that the name following represents a parameterized type 
// placeholder that will be replaced by a user-specfied actual type. The reason for the two keywords is historical. In the original template specification, 
// Stroustrup reused the existing class keyword to specify a type parameter rather than introduce a new keyword that might of course break existing programs. It wasn’t
// that a new keyword wasn’t considered — just that it wasn’t considered necessary given its potential disruption. And up until the ISO-C++ standard, this was the only 
// way to declare a type parameter. Reuses of existing keywords seems to always sow confusion. What we found is that beginners were whether the use of the class 
// constrained or limited the type arguments a user could specify to be class types rather than, say, a built-in or pointer type. So, there was some feeling that not 
// having introduced a new keyword was a mistake. During standardization, certain constructs were discovered within a template definition that resolved to expressions 
// although they were meant to indicate declarations. For example,
//
//          template <class T>
//
//          class Demonstration {
//
//          public:
//
//              void method() {
//  
//                  T::A *aObj; // oops …
//
//                  // …
//
//         };
//
//
// While the statement containing aObj is intended by the programmer to be interpreted as the declaration of a pointer to a nested type A within the type parameter T, 
// the language grammar interprets it as an arithmetic expression multiplying the static member A of type T with aObj and throwing away the result. Isn’t that annoying! 
// ( This sort of dilemna is not possible within generics – there is no way to safely verify that any T contains an A so that the runtime can safely construct an instance 
// of the generic type ). The committee decided that a new keyword was just the ticket to get the compiler off its unfortunate obsession with expressions. The new keyword 
// was the self-describing typename. When applied to a statement, such as,
//
//
//          typename T::A* a6; // declare pointer to T’s A
//
//
// it instructs the compiler to treat the subsequent statement as a declaration. Since the keyword was on the payroll, heck, why not fix the confusion caused by the original 
// decision to reuse the class keyword. Of course, given the extensive body of existing code and books and articles and talks and postings using the class keyword, they chose 
// to also retain support for that use of the keyword as well. So that’s why you have both



// The main point of an object is to manage resources ( In theory every object should maintain one and only one resource ), one of the important aspects of managing
// a resource is performance, the amount of time every operation take should be as minimal as possible, the basic operations should take almost the same as when 
// working with the resource without the object covering it



// top-level const qualifier affects the object itself. Others are only relevant with pointers and references. They do not make the object const, and only prevent 
// modification through a path using the pointer or reference. Thus :
//
//      char x;
//
//      char const* p = &x;
//
// This is not a top-level const, and none of the objects are immutable. The expression *p cannot be used to modify x, but other expressions can be; x is not const. 
// For that matter :
//
//      *const_cast< char* >( p ) = 't';
//
// is legal and well defined.
//
// But,
//
//      char const x = 't';
//
//      char const* p = &x;
//
// This time, there is a top-level const on x, so x is immutable. No expression is allowed to change it ( even if const_cast is used ). The compiler may put x in 
// read-only memory, and it may assume that the value of x never changes, regardless of what other code may do.
// 
// To give the pointer top-level const, you'd write:
//
//      char x = 't';
//
//      char *const p = &x;
//
// In this case, p will point to x forever; any attempt to change this is undefined behavior ( and the compiler may put p in read-only memory, or assume that *p refers 
// to x, regardless of any other code )



// Two method can have the same signature except that one is const and the other is not. The const method will be called on const objects and the non const method is 
// called on non-const objects. C++ allows member methods to be overloaded on the basis of const type. Overloading on the basis of const type can be useful when a 
// function return reference or pointer. It is possible to make one function const, that returns a const reference or const pointer, other non-const function, that 
// returns non-const reference or pointer



// In C++ any of the following 38 operators can be overloaded :
//
//  "+", "-", "*", "/", "%", "^", "&", "|", "~", "!", "=", "<", ">", "+=", "-=", "*=", "/=", "%=", "^=", "&=", "|=", "<<", ">>", ">>=", "<<="
//  "==", "!=", "<=", ">=", "&&", "||", "++", "--", ",", "->*", "->", "( )", "[ ]"
//
// Assignment operator ( = ), curel brackets operator ( () ), square brackets opeartor ( [] ), and pointer dereference operator ( -> ) can 
// not be non members!!



// When aggregate initializers ( initializers in {} ) are used in the "traditional" ANSI C language ( C89/90 ), an individual initializer must be supplied for each 
// structure member in order, beginning with the first, for example :
//
//      struct S { int a, b, c, d; };
//
//      struct S s = { 1, 2, 3, 4 };
//
// 1 for `s.a`, 2 for `s.b` and so on...
//
// You are not required to specify initializers for all members, i.e. you can stop at any time ( remaining members will be zero-initialized ). If for some reason you 
// only cared to explicitly initialize the third member of the structure, you had to supply "dummy" explicit initializers for the first and the second members ( just 
// to get to the desired third ), for example :
//
// We only care to explicitly initialize `s.c`
//
//      struct S s = { 0, 0, 3 };
//
// but we have to explicitly initialize `s.a` and `s.b` as well
//
// Or abandon specific initialization entirely ( likely replacing it with generic = { 0 } ) and use a subsequent assignment to specific members, for example :
//
//      struct S s = { 0 };
//      s.c = 3;
//
// One notable benefit of this assignment-based approach is that it is independent from the position of member c in the declaration of struct S. The new specification 
// of C language ( C99 ) allows you to use "tagged" initializers by supplying the desired member name within the {}, for example :
//
//      struct S s = { .c = 3 };
//
// That way you only explicitly initialize the desired member(s) ( and have the compiler to zero-initialize the rest ).This not only saves you some typing but also 
// makes the aggregate initializers independent from the order in which the members are specified in the struct type declaration.
//
// Aggregate initializers, can be used with arrays, too. And C99 supports "tagged" initialization with arrays as well. How the "tags" look in case of an array is 
// illustrated by the following example :
//
//      int a[10] = { [5] = 3 };
//
// It is worth noting one more time that C language continues to stick to the "all or nothing" approach to aggregate initialization: if you specify an explicit 
// initializer for just one ( or some ) members of a struct or an array, the whole aggregate ( struct or array ) gets initialized, and the members without explicit 
// initializers get zero-initialized



// Explicit ( Full ) template specialization :
//
//  Any of the following can be fully specialized :
//
//      1. function template
//      2. class template
//      3. variable template
//      4. member function of a class template
//      5. static data member of a class template
//      6. member class of a class template
//      7. member enumeration of a class template
//      8. member class template of a class or class template
//      9. member function template of a class or class template
//
//  For example,
//
//      template<typename T>            // primary template
//      class Universe
//      {};
//
//      template<>                      // explicit specialization for T = int
//      struct Universe< int >
//      {};



// A function definition should only appear in a header file if :
//
//      It has been declared with the inline keyword
//      It is defined within a class definition
//      It involves at least one template parameter
//
// Those are among the cases where the multiple-identical-definitions version of ODR applies.
//
// So inline is not usually required with template functions. But an explicit specialization doesn't actually have any template parameters, so it should be marked 
// as inline if it is in the header file



// In order to access private members of template class instantiated with different types, the friend keyword is needed to allow that access :
//
//      template< typename Type >
//      class Cock
//      {
//
//          template< typename OtherType >
//          friend class Cock;
//
//      };
//
// In case the two types are different, then both cocks are two completely different classes, one cannot access private members of other if you
// don't make friend one of other. Note, in the code above all instantations of the class template are friend of each other. That is if the cock
// is intstantied with 'char', 'int' and 'short' then :
//
//      - 'Cock< int >' will be friend both of 'Cock< char >' and 'Cock< short >'
//      - 'Cock< char >' will be friend both of 'Cock< int >' and 'Cock< short >'
//      - 'Cock< short >' will be friend both of 'Cock< char >' and 'Cock< int >'
//
// The interesting pharse here is "friend of each other". Usually this doesn't happen. For example, the following code :
//
//      class A
//      {
//          friend class B;
//      };
//
// Here only B is friend of A, but A is not friend of B! ( fuck you snob A!! )
//
// In order to declare a friend with the same template argument, the template argument should not be givin a name :
//
//      template< typename Type >
//      class Cock
//      {
//
//          template< typename >
//          friend class Balls;
//
//      };



// Template Class Information :
//
//  Purpose :
//
//		Use this object to store multiple instances of the same type. The size of the array is provided as a template argument, which means that
//      it is known already in compile time. The size then is determined and can not be changed. This is mandatory because the array will be 
//      placed in the stack memory segment, and the compiler must know in advance how much memory space is needed to allocate it
//
//  Description :
//
//		1. This object contains an instance of the object "State" to allow each instance of this object to have a defined state
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
//          2. Size - the number of entries for the array
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< Concepts::RawButPointerIsAllowed DataType, LargestUnsignedInteger ArraySize > requires( ArraySize > 0UL )
class Array NotForInheritance
{
public:


    // Create a type definition for this object
    using SelfType = Array< DataType, ArraySize >;

    // Create a type definition for the data
    using SelfDataType = DataType;


	// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
	// the compiler generates a basic behavior for them if possible :


    // Method Information :
    //
    //  Description :
    //
    //      Default Constructor,
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
    inline Array();


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
    //          data - a reference to an instance that will be used to initialize all the entries
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
	explicit inline Array( const DataType& data );


    // Method Information :
    //
    //  Description :
    //
    //      Constructor, to accept initializer list
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          initializerList - a C++ standard way of constructing instances from initialization list, aka { 1, 2, 3 ... }
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
    inline Array( const std::initializer_list< DataType >& initializerList );


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
    //          other - the memory handler that contains the data to initialize the instance with
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
    //      1. The other instance size must be larger then 0 
    //		2. The other instance size must be equal to the stack array size
    //      3. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< template< typename, typename... > class OtherMemoryHandlerType >
    explicit inline Array( const OtherMemoryHandlerType< DataType >& other );


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
	//		They will come
	//
	inline Array( const SelfType& other );


	// This macro will be used to all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
	// simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
	// any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
	// be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
	// macro will be used to add the following methods to each object :
	//
	//		1. Assignment operator
	//		2. Move constructor
	//		3. Move assignment operator
	//		4. Swap
	//		5. Reset
    //
    ObjectInfrastructure_ForInheritance( Array )


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
	inline ~Array() = default;


    // This part will contain all the get and set methods for the members of the object :


    GetByValue_Creator( /* GetMethodName */ Size, /* MemberName */ ArraySize, /* MemberType */ LargestUnsignedInteger )


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
	//			other - a reference to the instance that should be compared with this object
	//
	//      Information returned to the user :
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
	//			other - a reference to the instance that should be compared with this object
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
    //      Use this operator to get a reference to the required entry
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          index - the index of the required entry
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      A reference to the required entry
    //
    //  Expectations :
    //
    //      1. The given index is smaller then the single linked list size
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline DataType& operator[]( LargestUnsignedInteger index );


    // Method Information :
    //
    //  Description :
    //
    //      Use this operator to get a constant reference to the required entry
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          index - the index of the required entry
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      A constant reference to the required entry
    //
    //  Expectations :
    //
    //      1. The given index is smaller then the single linked list size
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline const DataType& operator[]( LargestUnsignedInteger index ) const;


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
		static void UnitTest() __attribute__ (( __unused__ ));

	)  //  End of debug tool


private:


	// This object is the array to contain the required information
	DataType member_array[ ArraySize ];


};  //  Class Array  