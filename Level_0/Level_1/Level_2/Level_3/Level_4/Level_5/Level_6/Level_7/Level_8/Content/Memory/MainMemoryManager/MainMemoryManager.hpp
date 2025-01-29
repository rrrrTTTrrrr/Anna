namespace Universe
{


namespace Memory
{



// Static memory, is when all the required memory is determined before program execution by defining the variables needed. But there may be cases where the memory 
// needs of a program can only be determined during runtime, this is called Dynamic memory. For example, when the memory needed depends on user input. On these cases, 
// programs need to dynamically allocate memory, for which the C++ language integrates the operators new and delete
//
// Syntax :
//
// 	For one object :
//
// 		Operator new for allocating one object  ->   intYPE* pointer = new int;
// 		Operator delete for deleting one object  ->   delete pointer;
//
//	For array of objects :
//
// 		Operator new for allocating array of objects  ->   intYPE* pointer = new int[78];
// 		Operator delete for deleting array of objects  ->   delete[] pointer;
//
// For basic types objects, this is usually enough, but when dealing with self defined objects which needs constructor and destructor that perform more complex 
// initialization and deletion the things get more messy. There are cases where the allocation space needs to at outlast the life of the object in it, for this exist 
// the displacment new. This operator instead of allocating memory space and then calling the constructor on the space, receive a preallocated space and
// only initialize it
//
// Syntax :
//
//		Operator displacment new   ->   new ( address ) ClassConstructor();
//
// The address is given and the object constructor that should initialize the memory space
// 
// Now if the object created using displacment new, needs to be deleted but not the memory space, an explicit call to the destructor must be made
//
// Syntax :
//
//		ClassInstance.~Destructor()
//		PointerToClass->~Destructor()



// Class Information :
//
//  Purpose :
//
//		Artifical Inteligence
//
//  Description :
//
//		1. This object is used only to wrap some static methods, which can be used without any instance of the object
//
//		2. This object has all the methods to create, destory, copy and move disabled to ensure that no instances of it will be created
//
// 		3. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
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
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
class MainMemoryManager NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = MainMemoryManager;


	// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object.
	// Satic functions only have access to static data members, which also don't belong to any instance, this means all other data members
	// can not be used. The only purpose then of declaring a static function is when a private static data member needs to be manipulated,
	// or some functionality needed that does not involve the non static data members


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to allocate memory space, and initialize it using the default constructor. For built-in types this means that
	//		memory space will be initialized with unknown content
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			size - the instances number of the template type to allocate
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A pointer with the memory address of the allocated memory space
	//
	//  Expectations :
	//
	//		1. The given size is larger then 0
	//		2.
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. The constructor of the type failed - class Error::Exception is thrown
	//		3.
	//
	template< Concepts::RawButPointerIsAllowed Type > requires ( Concepts::DefaultConstructible< Type > )
	EnsureRetrunValueIsUsed static inline Type* AllocateAndDefaultConstruct( const LargestUnsignedInteger size = 1UL );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to allocate memory space, and initialize it with the given arguments
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			constructorArguments - list of arguments the template type constructor requires
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A pointer with the memory address of the allocated memory space
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. The constructor of the type failed - class Error::Exception is thrown
	//		3.
	//
	template< typename Type, typename... ConstructorArgumentTypes >
	EnsureRetrunValueIsUsed static inline Type* AllocateAndConstruct( ConstructorArgumentTypes&&... constructorArguments );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to release memory space allocated
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. pointer - a pointer with the memory address to release
	//			2. wasSingleInstanceAllocated - a boolean to determine if a single instance or multiple was allocated
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
	//		1. The given pointer to release is no NULL
	//		2. The memory address stored in the pointer was acquired by using the 'Allocate' methods
	//		3. 
	//
	//  Possible errors :
	//
	//		NONE
	//
	template< Concepts::RawButPointerIsAllowed Type >
	static inline void Done( const Type* const pointer, const Boolean wasSingleInstanceAllocated = true );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to initialize, an already allocated memory space, by calling the constructor of the type with the given arguments
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. pointer - a pointer with the preallocated memory space
	//			2. constructorArguments - list of arguments the template type constructor requires
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
	//		1. The constructor of the type failed - class Error::Exception is thrown
	//		2.
	//
	template< Concepts::RawButPointerIsAllowed Type, typename... ConstructorArgumentTypes >
	static inline void Construct( void* const pointer, ConstructorArgumentTypes... constructorArguments );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to call the destructor on the memory
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			pointer - a pointer with the pre constructed memory space
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
	//		1. The constructor was called on the memory address
	//		2.
	//
	//  Possible errors :
	//
	//		1. The destructor of the type failed - class Error::Exception is thrown
	//		2.
	//
	template< Concepts::RawButPointerIsAllowed Type > requires ( Concepts::Destructible< Type > )
	static inline void Destruct( void* const pointer );


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


	// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
	NoInstances( MainMemoryManager );


};  //  Class MainMemoryManager
