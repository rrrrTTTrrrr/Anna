//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



template< Concepts::RawButPointerIsAllowed ReturnType, Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
inline ReturnType OperatorPointer::Addition( const LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand )
{
	// Invoke the addition operator on the operands and return the result
	return ( leftSideOperand + rightSideOperand );
}


template< Concepts::RawButPointerIsAllowed ReturnType, Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
inline ReturnType OperatorPointer::Subtraction( const LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand )
{
	// Invoke the subtraction operator on the operands and return the result
	return ( leftSideOperand - rightSideOperand );
}


template< Concepts::RawButPointerIsAllowed ReturnType, Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
inline ReturnType OperatorPointer::Multiplication( const LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand )
{
	// Invoke the multiplication operator on the operands and return the result
	return ( leftSideOperand * rightSideOperand );
}


template< Concepts::RawButPointerIsAllowed ReturnType, Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
inline ReturnType OperatorPointer::Division( const LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand )
{
	// Invoke the division operator on the operands and return the result
	return ( leftSideOperand / rightSideOperand );
}


template< Concepts::RawButPointerIsAllowed ReturnType, Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
inline ReturnType OperatorPointer::Modulo( const LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand )
{
	// Invoke the modulo operator on the operands and return the result
	return ( leftSideOperand % rightSideOperand );
}


template< Concepts::RawButPointerIsAllowed ReturnType, Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
inline ReturnType& OperatorPointer::AssignmentAddition( LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand )
{
	// Invoke the assignment addition operator on the operands and return the result
	return ( leftSideOperand += rightSideOperand );
}


template< Concepts::RawButPointerIsAllowed ReturnType, Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
inline ReturnType& OperatorPointer::AssignmentSubtraction( LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand )
{
	// Invoke the assignment subtraction operator on the operands and return the result
	return ( leftSideOperand -= rightSideOperand );
}


template< Concepts::RawButPointerIsAllowed ReturnType, Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
inline ReturnType& OperatorPointer::AssignmentMultiplication( LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand )
{
	// Invoke the assignment mutliplication operator on the operands and return the result
	return ( leftSideOperand *= rightSideOperand );
}


template< Concepts::RawButPointerIsAllowed ReturnType, Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
inline ReturnType& OperatorPointer::AssignmentDivision( LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand )
{
	// Invoke the assignment division operator on the operands and return the result
	return ( leftSideOperand /= rightSideOperand );
}


template< Concepts::RawButPointerIsAllowed ReturnType, Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
inline ReturnType& OperatorPointer::AssignmentModulo( LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand )
{
	// Invoke the assignment modulo operator on the operands and return the result
	return ( leftSideOperand %= rightSideOperand );
}


template< Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
inline Boolean OperatorPointer::Equal( const LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand )
{
	// Invoke the equal operator on the operands and return the result
	return ( leftSideOperand == rightSideOperand );
}


template< Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
inline Boolean OperatorPointer::NonEqual( const LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand )
{
	// Invoke the non equal operator on the operands and return the result
	return ( leftSideOperand != rightSideOperand );
}


template< Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
inline Boolean OperatorPointer::Larger( const LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand )
{
	// Invoke the larger operator on the operands and return the result
	return ( leftSideOperand > rightSideOperand );
}


template< Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
inline Boolean OperatorPointer::Smaller( const LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand )
{
	// Invoke the smaller operator on the operands and return the result
	return ( leftSideOperand < rightSideOperand );
}


template< Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
inline Boolean OperatorPointer::LargerOrEqual( const LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand )
{
	// Invoke the equal or larger operator on the operands and return the result
	return ( leftSideOperand >= rightSideOperand );
}


template< Concepts::RawButPointerIsAllowed LeftSideOperandType, Concepts::RawButPointerIsAllowed RightSideOperandType >
inline Boolean OperatorPointer::SmallerOrEqual( const LeftSideOperandType& leftSideOperand, const RightSideOperandType& rightSideOperand )
{
	// Invoke the equal or smaller operator on the operands and return the result
	return ( leftSideOperand <= rightSideOperand );
}



}  //  Namespace Universe