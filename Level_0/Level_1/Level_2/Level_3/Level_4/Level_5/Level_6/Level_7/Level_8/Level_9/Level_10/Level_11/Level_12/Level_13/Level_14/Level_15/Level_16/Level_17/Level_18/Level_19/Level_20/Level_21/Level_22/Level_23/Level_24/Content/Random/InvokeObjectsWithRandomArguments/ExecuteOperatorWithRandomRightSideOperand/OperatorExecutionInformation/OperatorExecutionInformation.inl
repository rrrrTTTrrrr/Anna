//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< typename ReturnType, typename LeftSideOperandType, typename RightSideOperandType >
inline OperatorExecutionInformation< ReturnType, LeftSideOperandType, RightSideOperandType >::OperatorExecutionInformation() :
	member_leftSideOperandBeforeInvokingOperator(),
	member_leftSideOperandAfterInvokingOperator(),
	member_rightSideOperandBeforeInvokingOperator(),
	member_rightSideOperandAfterInvokingOperator(),
	member_returnValue(),
	member_wasExceptionThrown( false ),
	member_errorMessage()
{}


template< typename ReturnType, typename LeftSideOperandType, typename RightSideOperandType >
inline OperatorExecutionInformation< ReturnType, LeftSideOperandType, RightSideOperandType >::OperatorExecutionInformation( const SelfType& other ) :
	member_leftSideOperandBeforeInvokingOperator( other.member_leftSideOperandBeforeInvokingOperator ),
	member_leftSideOperandAfterInvokingOperator( other.member_leftSideOperandAfterInvokingOperator ),
	member_rightSideOperandBeforeInvokingOperator( other.member_rightSideOperandBeforeInvokingOperator ),
	member_rightSideOperandAfterInvokingOperator( other.member_rightSideOperandAfterInvokingOperator ),
	member_returnValue( other.member_returnValue ),
	member_wasExceptionThrown( false ),
	member_errorMessage( other.member_errorMessage )
{}


template< typename ReturnType, typename LeftSideOperandType, typename RightSideOperandType >
template< typename UniversalReferenceLeftSideOperandType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceLeftSideOperandType, LeftSideOperandType >::Result == true )
inline void OperatorExecutionInformation< ReturnType, LeftSideOperandType, RightSideOperandType >::AddLeftSideOperandBeforeOperatorCall( UniversalReferenceLeftSideOperandType&& leftSideOperandBeforeOperatorCall )
{
	// Set the left side operand before the operator call
	member_leftSideOperandBeforeInvokingOperator = ForwardUniversalReference< UniversalReferenceLeftSideOperandType >( leftSideOperandBeforeOperatorCall );
}


template< typename ReturnType, typename LeftSideOperandType, typename RightSideOperandType >
template< typename UniversalReferenceLeftSideOperandType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceLeftSideOperandType, LeftSideOperandType >::Result == true )
inline void OperatorExecutionInformation< ReturnType, LeftSideOperandType, RightSideOperandType >::AddLeftSideOperandAfterOperatorCall( UniversalReferenceLeftSideOperandType&& leftSideOperandAfterOperatorCall )
{
	// Set the left side operand after the operator call
	member_leftSideOperandAfterInvokingOperator = ForwardUniversalReference< UniversalReferenceLeftSideOperandType >( leftSideOperandAfterOperatorCall );
}


template< typename ReturnType, typename LeftSideOperandType, typename RightSideOperandType >
template< typename UniversalReferenceRightSideOperandType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceRightSideOperandType, RightSideOperandType >::Result == true )
inline void OperatorExecutionInformation< ReturnType, LeftSideOperandType, RightSideOperandType >::AddRightSideOperandBeforeOperatorCall( UniversalReferenceRightSideOperandType&& rightSideOperandBeforeOperatorCall )
{
	// Set the right side operand before the operator call
	member_rightSideOperandBeforeInvokingOperator = ForwardUniversalReference< UniversalReferenceRightSideOperandType >( rightSideOperandBeforeOperatorCall );
}


template< typename ReturnType, typename LeftSideOperandType, typename RightSideOperandType >
template< typename UniversalReferenceRightSideOperandType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceRightSideOperandType, RightSideOperandType >::Result == true )
inline void OperatorExecutionInformation< ReturnType, LeftSideOperandType, RightSideOperandType >::AddRightSideOperandAfterOperatorCall( UniversalReferenceRightSideOperandType&& rightSideOperandAfterOperatorCall )
{
	// Set the right side operand after the operator call
	member_rightSideOperandAfterInvokingOperator = ForwardUniversalReference< UniversalReferenceRightSideOperandType >( rightSideOperandAfterOperatorCall );
}


template< typename ReturnType, typename LeftSideOperandType, typename RightSideOperandType >
template< typename UniversalReferenceReturnType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceReturnType, ReturnType >::Result == true )
inline void OperatorExecutionInformation< ReturnType, LeftSideOperandType, RightSideOperandType >::AddReturnValue( UniversalReferenceReturnType&& returnValue )
{
	// Set the return value
	member_returnValue = ForwardUniversalReference< UniversalReferenceReturnType >( returnValue );
}


template< typename ReturnType, typename LeftSideOperandType, typename RightSideOperandType >
inline void OperatorExecutionInformation< ReturnType, LeftSideOperandType, RightSideOperandType >::AddExceptionWasThrown( const Boolean wasExceptionThrown )
{
	// Set the boolean to true in case an exception was thrown
	member_wasExceptionThrown = wasExceptionThrown;
}


template< typename ReturnType, typename LeftSideOperandType, typename RightSideOperandType >
template< Concepts::String UniversalReferenceStringType >
inline void OperatorExecutionInformation< ReturnType, LeftSideOperandType, RightSideOperandType >::AddExceptionErrorMessage( UniversalReferenceStringType&& errorMessage )
{
	// Set the error message of the exception, if one was thrown
	member_errorMessage = ForwardUniversalReference< UniversalReferenceStringType >( errorMessage );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< typename ReturnType, typename LeftSideOperandType, typename RightSideOperandType >
inline Boolean OperatorExecutionInformation< ReturnType, LeftSideOperandType, RightSideOperandType >::operator==( const SelfType& other ) const
{
	// Compare the content of the instances and return the result
	return ( ( member_leftSideOperandBeforeInvokingOperator == other.member_leftSideOperandBeforeInvokingOperator ) &&
			 ( member_leftSideOperandAfterInvokingOperator == other.member_leftSideOperandAfterInvokingOperator ) &&
			 ( member_rightSideOperandBeforeInvokingOperator == other.member_rightSideOperandBeforeInvokingOperator ) &&
			 ( member_rightSideOperandAfterInvokingOperator == other.member_rightSideOperandAfterInvokingOperator ) &&
			 ( member_returnValue == other.member_returnValue ) &&
			 ( member_wasExceptionThrown == other.member_wasExceptionThrown ) &&
			 ( member_errorMessage == other.member_errorMessage ) );
}


template< typename ReturnType, typename LeftSideOperandType, typename RightSideOperandType >
inline Boolean OperatorExecutionInformation< ReturnType, LeftSideOperandType, RightSideOperandType >::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< typename ReturnType COMMA typename LeftSideOperandType COMMA typename RightSideOperandType >
	inline void OperatorExecutionInformation< ReturnType COMMA LeftSideOperandType COMMA RightSideOperandType >::UnitTest()
	{}

)  //  End of debug tool



}  //  Namespace Random


}  //  Namespace Universe