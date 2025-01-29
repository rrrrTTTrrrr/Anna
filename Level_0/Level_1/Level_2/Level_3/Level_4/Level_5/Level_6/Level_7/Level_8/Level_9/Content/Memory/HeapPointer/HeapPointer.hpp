namespace Universe
{


namespace Memory
{



// An attribute cannot appear on a friend declaration which isn't also a definition!!



class MainMemoryManager;



// Class Information :
//
//  Purpose :
//
//		An object that can allocate and release memory space on the Heap memory segment automaitcally. The main usgae is for cases where
//		multiple allocations are made. If an allocation fails, it throws an exception. If all the allocations are in the same scope,
//		for example a constructor of an object, than this object can be used to ensure that in that case the previous allocated memory
//		will be released
//
//  Description :
//
// 		1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
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
//		2. Template arguments :
//
//			1.
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< typename Type, typename MemoryManagerType = MainMemoryManager >
class HeapPointer NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = HeapPointer< Type, MemoryManagerType >;


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
    //      NONE
    //
    inline HeapPointer();


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
    //          1. constructorArguments - all the arguments required to construct an instance of the template type
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
    template< typename FirstConstructorArgumentType, typename... RestOfConstructorArgumentTypes >
    explicit inline HeapPointer( FirstConstructorArgumentType&& firstArgument, RestOfConstructorArgumentTypes&&... restOfCconstructorArguments );


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
    //          1. pointer - a pointer with the memory address to a preallocated memory
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
    explicit inline HeapPointer( Type* const pointer );


	// Add the following infrastructure to the object :
	//
	//		1. Move constructor
	//		2. Move assigenment operator
	//		3. Swap
	//		4. Reset
	//
	ObjectInfrastructureWithoutTheAbilityToCopyItself( HeapPointer )


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
	inline ~HeapPointer();


	// The following methods give access and manipulate the data inside this object :


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to get the size in bytes of the memory space pointed to by this instance
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
    //      The size in bytes of the memory space pointed to by this instance
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline LargestUnsignedInteger SizeInBytes() const;


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to get the memory address of the resource
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
    //      A pointer with the memory address of the resource
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline Type* Get();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the memory address of the resource, and take responsibility on releasing the memory address when done
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
	//		A pointer with the memory address of the resource
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
    EnsureRetrunValueIsUsed inline Type* Acquire();


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
	EnsureRetrunValueIsUsed Boolean operator==( const SelfType& other ) const;


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
    //      Override operator "->" so the use would be the same as with regular pointer, pointer->member = ( *pointer ).member
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
    //      The resource inside the pointer object
    //
    //  Expectations :
    //
    //      1. The instance should have been initialized and memory space was allocated. Which will result in a pointer different than NULL
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline Type* operator->();


    // Method Information :
    //
    //  Description :
    //
    //      Override operator "+" so the use would be the same as with regular pointer, pointer + n = the address of object n
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          offset - the offset of the required entry in the resource
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      The address of the required entry in the resource
    //
    //  Expectations :
    //
    //		NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline Type* operator+( const LargestUnsignedInteger offset ) const;


    // Method Information :
    //
    //  Description :
    //
    //      Override operator "-" so the use would be the same as with regular pointer, pointer - n = the address of object n behind
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          offset - the offset of the required entry in the resource
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      The address of the required entry in the resource
    //
    //  Expectations :
    //
    //		NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline Type* operator-( const LargestUnsignedInteger offset ) const;


    // Method Information :
    //
    //  Description :
    //
    //      Override operator ">" so the use would be the same as with regular pointer, pointer > otherPointer
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          other - a reference to other instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      1. true - if the pointer inside this instance has higher address then the pointer in the other instance
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //		NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline Boolean operator>( const SelfType& other ) const;


    // Method Information :
    //
    //  Description :
    //
    //      Override operator "<" so the use would be the same as with regular pointer, pointer < otherPointer
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          other - a reference to other instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      1. true - if the pointer inside this instance has lower address then the pointer in the other instance
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //		NONE
    //
    //  Possible errors :
    //
    //      They will come 
    //
    EnsureRetrunValueIsUsed inline Boolean operator<( const SelfType& other ) const;


    // Method Information :
    //
    //  Description :
    //
    //      Override operator ">=" so the use would be the same as with regular pointer, pointer >= otherPointer
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          other - a reference to other instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      1. true - if the pointer inside this instance has higher or equal address to the pointer in the other instance
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //		NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline Boolean operator>=( const SelfType& other ) const;


    // Method Information :
    //
    //  Description :
    //
    //      Override operator "<=" so the use would be the same as with regular pointer, pointer <= otherPointer
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          other - a reference to other instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      1. true - if the pointer inside this instance has lower or equal address to the pointer in the other instance
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //		NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline Boolean operator<=( const SelfType& other ) const;


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


	// Disable all the abilites of the object to copy itself, this include the copy constructor and assignment operator
	DisableCopyConstructorAndAssignmentOperator( HeapPointer );


	// This pointer will store the memory address of the allocated space in the heap memory segment
	Type* member_pointer;


	// Friend class or friend function can access private and protected members of other object in which it is declared as friend. It is
	// sometimes useful to allow a particular object to access private members of other object. The declration of such function is private,
	// because these functions are part of the implemntation, which the user should not be aware of. The use of this functions is not limited
	// to the object's scope. One of the problems that friend declaration solves is when the object needs to be as a right side operand in
	// expressions. Every method in the object is implicitly added a pointer to the location of the object data with the name "this", and
	// to enable this the method must be called from an existing instance. This means that the object can only be implemented as the left side
	// operand of an expression with methods, and friend functions and objects does not have this limitation


    // Method Information :
    //
    //  Description :
    //
    //      Create the operator "*" so the use would be the same as with regular pointer, *pointer = object
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          pointer - a reference to a pointer instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      A reference to the resource pointed by the pointer
    //
    //  Expectations :
    //
    //      1. The pointer instance should be ready
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename TYPE >
    friend inline TYPE& operator*( HeapPointer< TYPE, MemoryManagerType >& heapPointer );


};  //  Class HeapPointer
