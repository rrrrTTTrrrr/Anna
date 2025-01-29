namespace Universe
{


namespace Random
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
template< typename ReturnType, typename LeftSideOperandType, typename RightSideOperandType >
class OperatorExecutionInformation NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = OperatorExecutionInformation< ReturnType, LeftSideOperandType, RightSideOperandType >;


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
	inline OperatorExecutionInformation();


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
	inline OperatorExecutionInformation( const SelfType& other );


	// Add the following infrastructure to the object :
	//
	//		1. Assigenment operator
	//		2. Move constructor
	//		3. Move assigenment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure( OperatorExecutionInformation )


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
	inline ~OperatorExecutionInformation() = default;


	// This part will contain all the get and set methods for the members of the object :


	GetByConstantReference_Creator( /* GetMethodName */ GetLeftSideOperandBeforeOperatorCall, /* MemberName */ member_leftSideOperandBeforeInvokingOperator, /* MemberType */ LeftSideOperandType )
	GetByConstantReference_Creator( /* GetMethodName */ GetLeftSideOperandAfterOperatorCall, /* MemberName */ member_leftSideOperandAfterInvokingOperator, /* MemberType */ LeftSideOperandType )
	GetByConstantReference_Creator( /* GetMethodName */ GetRightSideOperandBeforeOperatorCall, /* MemberName */ member_rightSideOperandBeforeInvokingOperator, /* MemberType */ RightSideOperandType )
	GetByConstantReference_Creator( /* GetMethodName */ GetRightSideOperandAfterOperatorCall, /* MemberName */ member_rightSideOperandAfterInvokingOperator, /* MemberType */ RightSideOperandType )
	GetByConstantReference_Creator( /* GetMethodName */ GetReturnValue, /* MemberName */ member_returnValue, /* MemberType */ ReturnType )
	GetByConstantReference_Creator( /* GetMethodName */ WasExceptionThrown, /* MemberName */ member_wasExceptionThrown, /* MemberType */ Boolean )
	GetByConstantReference_Creator( /* GetMethodName */ GetErrorMessage, /* MemberName */ member_errorMessage, /* MemberType */ Language::String )


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to add a copy of the left side operand before the operator was invoked
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          instance - a universal reference to an instance of the left side operand template object type 
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
	template< typename UniversalReferenceLeftSideOperandType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceLeftSideOperandType, LeftSideOperandType >::Result == true )
	inline void AddLeftSideOperandBeforeOperatorCall( UniversalReferenceLeftSideOperandType&& leftSideOperandBeforeOperatorCall );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to add a copy of the left side operand after the operator was invoked
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          instance - a universal reference to an instance of the left side operand template object type 
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
	template< typename UniversalReferenceLeftSideOperandType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceLeftSideOperandType, LeftSideOperandType >::Result == true )
	inline void AddLeftSideOperandAfterOperatorCall( UniversalReferenceLeftSideOperandType&& leftSideOperandAfterOperatorCall );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to add a copy of the right side operand before the operator was invoked
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          instance - a universal reference to an instance of the right side operand template object type 
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
	template< typename UniversalReferenceRightSideOperandType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceRightSideOperandType, RightSideOperandType >::Result == true )
	inline void AddRightSideOperandBeforeOperatorCall( UniversalReferenceRightSideOperandType&& rightSideOperandBeforeOperatorCall );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to add a copy of the right side operand after the operator was invoked
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          instance - a universal reference to an instance of the right side operand template object type 
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
	template< typename UniversalReferenceRightSideOperandType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceRightSideOperandType, RightSideOperandType >::Result == true )
	inline void AddRightSideOperandAfterOperatorCall( UniversalReferenceRightSideOperandType&& rightSideOperandAfterOperatorCall );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to add the return value from the operator call
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
	//      Use this method to add if an exception was thrown during the operator execution
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
	inline void AddExceptionWasThrown( const Boolean wasExceptionThrown );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to add the return value from the operator call
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


	// This object will store a copy of the left side operand before the operator was invoked on
	LeftSideOperandType member_leftSideOperandBeforeInvokingOperator;

	// This object will store a copy of the left side operand after the operator was invoked on
	LeftSideOperandType member_leftSideOperandAfterInvokingOperator;

	// This object will store a copy of the right side operand before the operator was invoked on
	RightSideOperandType member_rightSideOperandBeforeInvokingOperator;

	// This object will store a copy of the right side operand after the operator was invoked on
	RightSideOperandType member_rightSideOperandAfterInvokingOperator;

	// This object will store the return value of the function
	ReturnType member_returnValue;

	// This object will store if the function threw an exception
	Boolean member_wasExceptionThrown;

	// This object will store the error message of the exception if thrown
	Language::String member_errorMessage;


};  //  Class OperatorExecutionInformation