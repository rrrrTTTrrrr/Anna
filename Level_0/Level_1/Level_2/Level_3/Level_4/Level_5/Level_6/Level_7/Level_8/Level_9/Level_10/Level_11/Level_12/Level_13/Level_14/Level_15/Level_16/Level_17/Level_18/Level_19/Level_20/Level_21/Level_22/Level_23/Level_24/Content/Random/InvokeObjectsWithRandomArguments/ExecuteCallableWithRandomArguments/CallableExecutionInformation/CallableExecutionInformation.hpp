namespace Universe
{


namespace Random
{



// Template Class Information :
//
//  Purpose :
//
//		Use this object to store the memory address of a specific method, and allowing to invoke it during run time. The difference between a
//		function and method, is that method is a function that belongs to an object
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
//			1. ObjectType - the type of the object the method belongs to
//			2. ReturnType - the return value type of the required function
//			3. MethodArgumentTypes - the arguments types of the required function
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< typename FunctionType >
class CallableExecutionInformation
{
private:


	// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
	NoInstances( CallableExecutionInformation );


};



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// **************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Method with arguments   **************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



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
template< typename ReturnType, typename... ArgumentTypes >
class CallableExecutionInformation< ReturnType ( ArgumentTypes... ) > NotForInheritance
{
public:


	// Create a type definition for the function
	using SelfFunctionType = ReturnType ( ArgumentTypes... );

	// Create a type definition for this object
	using SelfType = CallableExecutionInformation< SelfFunctionType >;


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
	inline CallableExecutionInformation();


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
	inline CallableExecutionInformation( const SelfType& other );


	// Add the following infrastructure to the object :
	//
	//		1. Assigenment operator
	//		2. Move constructor
	//		3. Move assigenment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure( CallableExecutionInformation )


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
	inline ~CallableExecutionInformation() = default;


	// This part will contain all the get and set methods for the members of the object :


	GetByConstantReference_Creator( /* GetMethodName */ GetArguments, /* MemberName */ member_arguments, /* MemberType */ Memory::Tuple< ArgumentTypes... > )
	GetByConstantReference_Creator( /* GetMethodName */ GetReturnValue, /* MemberName */ member_returnValue, /* MemberType */ ReturnType )
	GetByConstantReference_Creator( /* GetMethodName */ WasExceptionThrown, /* MemberName */ member_wasExceptionThrown, /* MemberType */ Boolean )
	GetByConstantReference_Creator( /* GetMethodName */ GetErrorMessage, /* MemberName */ member_errorMessage, /* MemberType */ Language::String )


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to add the arguments of the function call
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          arguments - a universal reference to a tuple with the arguments
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
	//		NONE
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< typename UniversalReferenceTupleWithArgumentsType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceTupleWithArgumentsType, Memory::Tuple< ArgumentTypes... > >::Result == true )
	inline void AddArguments( UniversalReferenceTupleWithArgumentsType&& arguments );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to add the return value from the function call
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          returnValue - a universal reference to return value
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
	//		NONE
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< typename UniversalReferenceReturnType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceReturnType, ReturnType >::Result == true )
	inline void AddReturnValue( UniversalReferenceReturnType&& returnValue );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to add if an exception was thrown dring the function execution
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          wasExceptionThrown - a boolean describing if an exception was thrown
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
	//		NONE
	//
	//  Possible errors :
	//
	//      They will come
	//
	inline void AddWasExceptionThrown( const Boolean wasExceptionThrown );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to add the return value from the function call
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          errorMessage - a universal reference to the error message of the exception if one was thrown
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
	//		NONE
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< Concepts::String UniversalReferenceStringType >
	inline void AddExceptionErrorMessage( UniversalReferenceStringType&& errorMessage );


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


	// This tuple will store the arguments used to invoke the function
	Memory::Tuple< ArgumentTypes... > member_arguments;

	// This object will store the return value of the function
	ReturnType member_returnValue;

	// This object will store if the function threw an exception
	Boolean member_wasExceptionThrown;

	// This object will store the error message of the exception if thrown
	Language::String member_errorMessage;


};  //  Class CallableExecutionInformation



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - No arguments to function   ************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



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
template< typename ReturnType >
class CallableExecutionInformation< ReturnType () >  NotForInheritance
{
public:


	// Create a type definition for the function
	using SelfFunctionType = ReturnType ();

	// Create a type definition for this object
	using SelfType = CallableExecutionInformation< SelfFunctionType >;


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
	inline CallableExecutionInformation();


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
	inline CallableExecutionInformation( const SelfType& other );


	// Add the following infrastructure to the object :
	//
	//		1. Assigenment operator
	//		2. Move constructor
	//		3. Move assigenment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure( CallableExecutionInformation )


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
	inline ~CallableExecutionInformation() = default;


	// This part will contain all the get and set methods for the members of the object :


	GetByConstantReference_Creator( /* GetMethodName */ GetReturnValue, /* MemberName */ member_returnValue, /* MemberType */ ReturnType )
	GetByConstantReference_Creator( /* GetMethodName */ WasExceptionThrown, /* MemberName */ member_wasExceptionThrown, /* MemberType */ Boolean )
	GetByConstantReference_Creator( /* GetMethodName */ GetErrorMessage, /* MemberName */ member_errorMessage, /* MemberType */ Language::String )


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to add the return value from the function call
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          returnValue - a universal reference to return value
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
	//		NONE
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< typename UniversalReferenceReturnType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceReturnType, ReturnType >::Result == true )
	inline void AddReturnValue( UniversalReferenceReturnType&& returnValue );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to add if an exception was thrown dring the function execution
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          wasExceptionThrown - a boolean describing if an exception was thrown
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
	//		NONE
	//
	//  Possible errors :
	//
	//      They will come
	//
	inline void AddWasExceptionThrown( const Boolean wasExceptionThrown );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to add the return value from the function call
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          errorMessage - a universal reference to the error message of the exception if one was thrown
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
	//		NONE
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< Concepts::String UniversalReferenceStringType >
	inline void AddExceptionErrorMessage( UniversalReferenceStringType&& errorMessage );


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
		static inline void UnitTest() __attribute__ (( __unused__ )) { CallableExecutionInformation< UnsignedInteger64bits ( UnsignedInteger64bits ) >::UnitTest(); }

	)  //  End of debug tool


private:


	// This object will store the return value of the function
	ReturnType member_returnValue;

	// This object will store if the function threw an exception
	Boolean member_wasExceptionThrown;

	// This object will store the error message of the exception if thrown
	Language::String member_errorMessage;


};  //  Class CallableExecutionInformation



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ******************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - No return value   ****************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



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
template< typename... ArgumentTypes >
class CallableExecutionInformation< void ( ArgumentTypes... ) > NotForInheritance
{
public:


	// Create a type definition for the function
	using SelfFunctionType = void ( ArgumentTypes... );

	// Create a type definition for this object
	using SelfType = CallableExecutionInformation< SelfFunctionType >;


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
	inline CallableExecutionInformation();


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
	inline CallableExecutionInformation( const SelfType& other );


	// Add the following infrastructure to the object :
	//
	//		1. Assigenment operator
	//		2. Move constructor
	//		3. Move assigenment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure( CallableExecutionInformation )


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
	inline ~CallableExecutionInformation() = default;


	// This part will contain all the get and set methods for the members of the object :


	GetByConstantReference_Creator( /* GetMethodName */ GetArguments, /* MemberName */ member_arguments, /* MemberType */ Memory::Tuple< ArgumentTypes... > )
	GetByConstantReference_Creator( /* GetMethodName */ WasExceptionThrown, /* MemberName */ member_wasExceptionThrown, /* MemberType */ Boolean )
	GetByConstantReference_Creator( /* GetMethodName */ GetErrorMessage, /* MemberName */ member_errorMessage, /* MemberType */ Language::String )


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to add the arguments of the function call
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          arguments - a universal reference to a tuple with the arguments
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
	//		NONE
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< typename UniversalReferenceTupleWithArgumentsType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceTupleWithArgumentsType, Memory::Tuple< ArgumentTypes... > >::Result == true )
	inline void AddArguments( UniversalReferenceTupleWithArgumentsType&& arguments );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to add if an exception was thrown dring the function execution
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          wasExceptionThrown - a boolean describing if an exception was thrown
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
	//		NONE
	//
	//  Possible errors :
	//
	//      They will come
	//
	inline void AddWasExceptionThrown( const Boolean wasExceptionThrown );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to add the return value from the function call
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          errorMessage - a universal reference to the error message of the exception if one was thrown
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
	//		NONE
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< Concepts::String UniversalReferenceStringType >
	inline void AddExceptionErrorMessage( UniversalReferenceStringType&& errorMessage );


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
		static inline void UnitTest() __attribute__ (( __unused__ )) { CallableExecutionInformation< UnsignedInteger64bits ( UnsignedInteger64bits ) >::UnitTest(); };

	)  //  End of debug tool


private:


	// This tuple will store the arguments used to invoke the function
	Memory::Tuple< ArgumentTypes... > member_arguments;

	// This object will store if the function threw an exception
	Boolean member_wasExceptionThrown;

	// This object will store the error message of the exception if thrown
	Language::String member_errorMessage;


};  //  Class CallableExecutionInformation



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ****************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - No arguments to function and return value   ****************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



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
template<>
class CallableExecutionInformation< void () >  NotForInheritance
{
public:


	// Create a type definition for the function
	using SelfFunctionType = void ();

	// Create a type definition for this object
	using SelfType = CallableExecutionInformation< SelfFunctionType >;


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
	inline CallableExecutionInformation();


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
	inline CallableExecutionInformation( const SelfType& other );


	// Add the following infrastructure to the object :
	//
	//		1. Assigenment operator
	//		2. Move constructor
	//		3. Move assigenment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure( CallableExecutionInformation )


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
	inline ~CallableExecutionInformation() = default;


	// This part will contain all the get and set methods for the members of the object :


	GetByConstantReference_Creator( /* GetMethodName */ WasExceptionThrown, /* MemberName */ member_wasExceptionThrown, /* MemberType */ Boolean )
	GetByConstantReference_Creator( /* GetMethodName */ GetErrorMessage, /* MemberName */ member_errorMessage, /* MemberType */ Language::String )


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to add if an exception was thrown dring the function execution
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          wasExceptionThrown - a boolean describing if an exception was thrown
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
	//		NONE
	//
	//  Possible errors :
	//
	//      They will come
	//
	inline void AddWasExceptionThrown( const Boolean wasExceptionThrown );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to add the return value from the function call
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          errorMessage - a universal reference to the error message of the exception if one was thrown
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
	//		NONE
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< Concepts::String UniversalReferenceStringType >
	inline void AddExceptionErrorMessage( UniversalReferenceStringType&& errorMessage );


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
		static inline void UnitTest() __attribute__ (( __unused__ )) { CallableExecutionInformation< UnsignedInteger64bits ( UnsignedInteger64bits ) >::UnitTest(); }

	)  //  End of debug tool


private:


	// This object will store if the function threw an exception
	Boolean member_wasExceptionThrown;

	// This object will store the error message of the exception if thrown
	Language::String member_errorMessage;


};  //  Class CallableExecutionInformation