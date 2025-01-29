namespace Universe
{



// Class Information :
//
//  Purpose :
//
//		Use this object to invoke an object overloaded operator. The possibilities are :
//
//		  1. Addition '+'
//		  2. Subtraction '-'
//		  3. Division '/'
//		  4. Multiplication '*'
//		  5. Modulo '%'
//		  6. AssignmentAddition '+='
//		  7. AssignmentSubtraction '-='
//		  8. AssignmentDivision '/='
//		  9. AssignmentMultiplication '*='
//		  10. AssignmentModulo '%='
//		  11. Equal '=='
//		  12. NonEqual '!='
//		  13. Larger '>'
//		  14. Smaller '<'
//		  15. LargerOrEqual '>='
//		  16. SmallerOrEqual '<='
//
//  Description :
//
//		1. This object is used only to wrap some static methods, which can be used without any instance of the object. Then this object is
//		   an interface which conatins only static methods, and does not need to never be instantied
//
//		2. This object has all the methods to create, destory, copy and move disabled to ensure that no instances of it will be created
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
class OperatorPointer
{
public:


	// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions
	// only have access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only
	// purpose then of declaring a static function is when a private static data member needs to be manipulated, or some functionality needed that
	// does not involve the non static data members


	// Arithmetic operators :


	// Method Information :
    //
    //  Description :
	//
	//		Use this method to invoke the addition operator '+' on the two operands
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. leftSideOperand - the left side operand of the operation
	//			2. rightSideOperand - the right side operand of the operation
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The result from invoking the addition operator
	//
	//  Expectations :
	//
	//		1. The left side operand type has overloaded the addition operator. The siganture must match the types provided
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< Concepts::RawButPointerIsAllowed ReturnType, Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
	EnsureRetrunValueIsUsed static inline ReturnType Addition( const LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand );


	// Method Information :
    //
    //  Description :
	//
	//		Use this method to invoke the subtraction operator '-' on the two operands
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. leftSideOperand - the left side operand of the operation
	//			2. rightSideOperand - the right side operand of the operation
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The result from invoking the subtraction operator
	//
	//  Expectations :
	//
	//		1. The left side operand type has overloaded the subtraction operator. The siganture must match the types provided
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< Concepts::RawButPointerIsAllowed ReturnType, Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
	EnsureRetrunValueIsUsed static inline ReturnType Subtraction( const LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand );


	// Method Information :
    //
    //  Description :
	//
	//		Use this method to invoke the multiplication operator '*' on the two operands
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. leftSideOperand - the left side operand of the operation
	//			2. rightSideOperand - the right side operand of the operation
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The result from invoking the multiplication operator
	//
	//  Expectations :
	//
	//		1. The left side operand type has overloaded the multiplication operator. The siganture must match the types provided
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< Concepts::RawButPointerIsAllowed ReturnType, Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
	EnsureRetrunValueIsUsed static inline ReturnType Multiplication( const LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand );


	// Method Information :
    //
    //  Description :
	//
	//		Use this method to invoke the division operator '/' on the two operands
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. leftSideOperand - the left side operand of the operation
	//			2. rightSideOperand - the right side operand of the operation
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The result from invoking the division operator
	//
	//  Expectations :
	//
	//		1. The left side operand type has overloaded the division operator. The siganture must match the types provided
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< Concepts::RawButPointerIsAllowed ReturnType, Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
	EnsureRetrunValueIsUsed static inline ReturnType Division( const LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand );


	// Method Information :
    //
    //  Description :
	//
	//		Use this method to invoke the modulo operator '%' on the two operands
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. leftSideOperand - the left side operand of the operation
	//			2. rightSideOperand - the right side operand of the operation
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The result from invoking the modulo operator
	//
	//  Expectations :
	//
	//		1. The left side operand type has overloaded the modulo operator. The siganture must match the types provided
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< Concepts::RawButPointerIsAllowed ReturnType, Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
	EnsureRetrunValueIsUsed static inline ReturnType Modulo( const LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand );


	// Arithmetic assignment operators :


	// Method Information :
    //
    //  Description :
	//
	//		Use this method to invoke the assignment addition operator '+=' on the two operands
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. leftSideOperand - the left side operand of the operation
	//			2. rightSideOperand - the right side operand of the operation
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The result from invoking the addition operator
	//
	//  Expectations :
	//
	//		1. The left side operand type has overloaded the assignment addition operator. The siganture must match the types provided
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< Concepts::RawButPointerIsAllowed ReturnType, Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
	EnsureRetrunValueIsUsed static inline ReturnType& AssignmentAddition( LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand );


	// Method Information :
    //
    //  Description :
	//
	//		Use this method to invoke the assignment subtraction operator '-+' on the two operands
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. leftSideOperand - the left side operand of the operation
	//			2. rightSideOperand - the right side operand of the operation
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The result from invoking the subtraction operator
	//
	//  Expectations :
	//
	//		1. The left side operand type has overloaded the assignment subtraction operator. The siganture must match the types provided
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< Concepts::RawButPointerIsAllowed ReturnType, Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
	EnsureRetrunValueIsUsed static inline ReturnType& AssignmentSubtraction( LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand );


	// Method Information :
    //
    //  Description :
	//
	//		Use this method to invoke the assignment multiplication operator '*=' on the two operands
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. leftSideOperand - the left side operand of the operation
	//			2. rightSideOperand - the right side operand of the operation
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The result from invoking the multiplication operator
	//
	//  Expectations :
	//
	//		1. The left side operand type has overloaded the assignment multiplication operator. The siganture must match the types provided
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< Concepts::RawButPointerIsAllowed ReturnType, Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
	EnsureRetrunValueIsUsed static inline ReturnType& AssignmentMultiplication( LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand );


	// Method Information :
    //
    //  Description :
	//
	//		Use this method to invoke the assignment division operator '/=' on the two operands
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. leftSideOperand - the left side operand of the operation
	//			2. rightSideOperand - the right side operand of the operation
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The result from invoking the division operator
	//
	//  Expectations :
	//
	//		1. The left side operand type has overloaded the assignment division operator. The siganture must match the types provided
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< Concepts::RawButPointerIsAllowed ReturnType, Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
	EnsureRetrunValueIsUsed static inline ReturnType& AssignmentDivision( LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand );


	// Method Information :
    //
    //  Description :
	//
	//		Use this method to invoke the assignment modulo operator '%=' on the two operands
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. leftSideOperand - the left side operand of the operation
	//			2. rightSideOperand - the right side operand of the operation
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The result from invoking the modulo operator
	//
	//  Expectations :
	//
	//		1. The left side operand type has overloaded the assignment modulo operator. The siganture must match the types provided
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< Concepts::RawButPointerIsAllowed ReturnType, Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
	EnsureRetrunValueIsUsed static inline ReturnType& AssignmentModulo( LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand );


	// Relational operators :


	// Method Information :
    //
    //  Description :
	//
	//		Use this method to invoke the equal operator '==' on the two operands
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. leftSideOperand - the left side operand of the operation
	//			2. rightSideOperand - the right side operand of the operation
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The result from invoking the equal operator
	//
	//  Expectations :
	//
	//		1. The left side operand type has overloaded the equal operator. The siganture must match the types provided
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
	EnsureRetrunValueIsUsed static inline Boolean Equal( const LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand );


	// Method Information :
    //
    //  Description :
	//
	//		Use this method to invoke the non equal operator '!=' on the two operands
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. leftSideOperand - the left side operand of the operation
	//			2. rightSideOperand - the right side operand of the operation
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The result from invoking the non equal operator
	//
	//  Expectations :
	//
	//		1. The left side operand type has overloaded the non equal operator. The siganture must match the types provided
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
	EnsureRetrunValueIsUsed static inline Boolean NonEqual( const LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand );


	// Method Information :
    //
    //  Description :
	//
	//		Use this method to invoke the larger operator '>' on the two operands
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. leftSideOperand - the left side operand of the operation
	//			2. rightSideOperand - the right side operand of the operation
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The result from invoking the larger operator
	//
	//  Expectations :
	//
	//		1. The left side operand type has overloaded the larger operator. The siganture must match the types provided
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
	EnsureRetrunValueIsUsed static inline Boolean Larger( const LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand );


	// Method Information :
    //
    //  Description :
	//
	//		Use this method to invoke the smaller operator '<' on the two operands
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. leftSideOperand - the left side operand of the operation
	//			2. rightSideOperand - the right side operand of the operation
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The result from invoking the smaller operator
	//
	//  Expectations :
	//
	//		1. The left side operand type has overloaded the smaller operator. The siganture must match the types provided
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
	EnsureRetrunValueIsUsed static inline Boolean Smaller( const LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand );


	// Method Information :
    //
    //  Description :
	//
	//		Use this method to invoke the equal or larger operator '>=' on the two operands
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. leftSideOperand - the left side operand of the operation
	//			2. rightSideOperand - the right side operand of the operation
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The result from invoking the equal or larger operator
	//
	//  Expectations :
	//
	//		1. The left side operand type has overloaded the equal or larger operator. The siganture must match the types provided
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
	EnsureRetrunValueIsUsed static inline Boolean LargerOrEqual( const LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand );


	// Method Information :
    //
    //  Description :
	//
	//		Use this method to invoke the equal or smaller operator '<=' on the two operands
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. leftSideOperand - the left side operand of the operation
	//			2. rightSideOperand - the right side operand of the operation
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The result from invoking the equal or smaller operator
	//
	//  Expectations :
	//
	//		1. The left side operand type has overloaded the equal or smaller operator. The siganture must match the types provided
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
	EnsureRetrunValueIsUsed static inline Boolean SmallerOrEqual( const LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand );


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
	NoInstances( OperatorPointer );


};  //  Class OperatorPointer