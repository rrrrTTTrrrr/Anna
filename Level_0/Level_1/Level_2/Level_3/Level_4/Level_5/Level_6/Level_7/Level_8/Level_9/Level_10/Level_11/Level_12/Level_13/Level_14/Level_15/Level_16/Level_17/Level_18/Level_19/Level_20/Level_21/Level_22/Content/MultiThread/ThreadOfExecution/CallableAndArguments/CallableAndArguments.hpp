namespace Universe
{


namespace MultiThread
{



// Class Information :
//
//  Purpose :
//
//		Artifical Inteligence
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
template< typename ReturnType, typename... ArgumentsTypes >
class CallableAndArguments NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = CallableAndArguments< ReturnType, ArgumentsTypes... >;

	// Create a type definition for the function signature
	using FunctionSignatureType = ReturnType ( ArgumentsTypes... );


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
	//			1. functionPointer - a pointer with the memory address to call
	//			2. arguments - all the required arguments to call the function
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
	//		1. The given pointer to the function to call should not be NULL
	//		2.
	//
	//  Possible errors :
	//
	//		They will come
	//
	explicit inline CallableAndArguments( const Callable< FunctionSignatureType >& callable, ArgumentsTypes... arguments );


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
	inline ~CallableAndArguments() = default;


	// This part will contain all the get and set methods for the members of the object :


	GetByValue_Creator( /* GetMethodName */ GetCallablePointer, /* MemberName */ member_callablePointer, /* MemberType */ const Callable< FunctionSignatureType >* )
	GetByReference_Creator( /* GetMethodName */ GetArgumentsTuple, /* MemberName */ member_argumentsTuple, /* MemberType */ Memory::Tuple< ArgumentsTypes... > )


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


	// This pointer will store the memory address of the callable instance the user provided
	const Callable< FunctionSignatureType >* member_callablePointer;

	// This tuple will contain the arguments to the callable
	Memory::Tuple< ArgumentsTypes... > member_argumentsTuple;


};  //  Class CallableAndArguments