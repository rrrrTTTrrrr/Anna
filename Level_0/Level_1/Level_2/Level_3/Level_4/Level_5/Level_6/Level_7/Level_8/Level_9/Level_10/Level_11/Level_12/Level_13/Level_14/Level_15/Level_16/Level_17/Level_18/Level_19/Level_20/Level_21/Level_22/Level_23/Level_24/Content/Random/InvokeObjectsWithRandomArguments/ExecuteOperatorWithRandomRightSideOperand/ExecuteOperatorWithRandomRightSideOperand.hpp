namespace Universe
{


namespace Random
{



// Use this macro to create a template specialization for the object 'IsUnsignedInteger'.
//
// The required arguments are :
//
//      OperatorName - the name of the operator to invoke with random arguments
//
#define CreateExecuteOperatorWithRandomRightSideOperand( OperatorName )																																								\
																																																											\
																																																											\
	template< typename ReturnType, typename LeftSideOperandType, typename RightSideOperandType >																																			\
	class Execute ## OperatorName ## OperatorWithRandomRightSideOperand NotForInheritance 																																					\
	{ 																																																										\
	public: 																																																								\
																																																											\
																																																											\
		using SelfType = Execute ## OperatorName ## OperatorWithRandomRightSideOperand< ReturnType, LeftSideOperandType, RightSideOperandType >; 																							\
																																																											\
																																																											\
		inline Execute ## OperatorName ## OperatorWithRandomRightSideOperand() : 																																							\
			member_history() 																																																				\
		{} 																																																									\
																																																											\
																																																											\
		inline Execute ## OperatorName ## OperatorWithRandomRightSideOperand( const SelfType& other ) : 																																	\
			member_history( other.member_history ) 																																															\
		{} 																																																									\
																																																											\
																																																											\
		/* Add the following infrastructure to the object : 																																												\
		 																																																									\
				1. Assigenment operator 																																																	\
				2. Move constructor 																																																		\
				3. Move assigenment operator 																																																\
				4. Swap 																																																					\
				5. Reset  */ 																																																				\
		 																																																									\
		ObjectInfrastructure( Execute ## OperatorName ## OperatorWithRandomRightSideOperand ) 																																		\
																																																											\
																																																											\
		inline ~Execute ## OperatorName ## OperatorWithRandomRightSideOperand() = default; 																																					\
																																																											\
																																																											\
		EnsureRetrunValueIsUsed inline LargestUnsignedInteger NumberOfTimesMethodWasInvoked() const 																																		\
		{ 																																																									\
			/* Return the number of times the method was invoked, which is the size of the history member */ 																																\
			return ( member_history.Size() ); 																																																\
		}																																																									\
																																																											\
																																																											\
		inline void Invoke( LeftSideOperandType& leftSideOperand, const Range< RightSideOperandType >& rangeForTheRightSideOperandRandomValue ) 																							\
		{ 																																																									\
			/* This boolean will store if the operator threw an exception */ 																																								\
			Boolean wasExceptionThrown = false; 																																															\
																																																											\
			/* This boolean will store the error message if an exception was thrown */																																						\
			Language::String errorMessage; 																																																	\
																																																											\
			/* Generate the random arguments required for the operator invocation */																																						\
			RightSideOperandType randomGeneratedRightSideOperand = TakeResourcesAndLeaveInstanceInDefaultState( RunTimeGenerator::Numeric::Next< RightSideOperandType >( rangeForTheRightSideOperandRandomValue ) );						\
																																																											\
			/* This object will store the return value of the method */																																										\
			ReturnType returnValue; 																																																		\
																																																											\
			/* This object will store the information on the current operator call */																																						\
			OperatorExecutionInformation< ReturnType, LeftSideOperandType, RightSideOperandType > operatorCallInformation; 																													\
																																																											\
			/* Set a copy of the left side operand before the operator call */																																								\
			operatorCallInformation.AddLeftSideOperandBeforeOperatorCall( leftSideOperand ); 																																				\
																																																											\
			/* Set a copy of the right side operand before the operator call */																																								\
			operatorCallInformation.AddRightSideOperandBeforeOperatorCall( randomGeneratedRightSideOperand ); 																																\
																																																											\
			/* Try catch block in case the operator will throw an exception */																																								\
			try 																																																							\
			{ 																																																								\
				/* Invoke the operator using the random generated right side operand */																																						\
				returnValue = OperatorPointer::OperatorName< ReturnType, LeftSideOperandType, RightSideOperandType >( leftSideOperand, randomGeneratedRightSideOperand ); 																	\
			}																																																								\
			catch ( const Error::Exception& exception )																																														\
			{ 																																																								\
				/* Set that an exception was thrown */																																														\
				wasExceptionThrown = true; 																																																	\
																																																											\
				/* Store the exception error message */																																														\
				errorMessage = TakeResourcesAndLeaveInstanceInDefaultState( Language::String( exception.ErrorMessage() ) ); 																												\
			}																																																								\
																																																											\
			/* Set a copy of the left side operand after the operator call */																																								\
			operatorCallInformation.AddLeftSideOperandAfterOperatorCall( leftSideOperand ); 																																				\
																																																											\
			/* Set a copy of the right side operand after the operator call */																																								\
			operatorCallInformation.AddRightSideOperandAfterOperatorCall( TakeResourcesAndLeaveInstanceInDefaultState( randomGeneratedRightSideOperand ) ); 																				\
																																																											\
			/* Set the operator call inforamtion */																																															\
			operatorCallInformation.AddReturnValue( TakeResourcesAndLeaveInstanceInDefaultState( returnValue ) ); 																															\
			operatorCallInformation.AddWasExceptionThrown( wasExceptionThrown ); 																																							\
			operatorCallInformation.AddExceptionErrorMessage( TakeResourcesAndLeaveInstanceInDefaultState( errorMessage ) ); 																												\
																																																											\
			/* Add all the information of the current invocation of the operator to the history */ 																																			\
			member_history.InsertSingleElementAtTheEnd( TakeResourcesAndLeaveInstanceInDefaultState( operatorCallInformation ) );																											\
		} 																																																									\
																																																											\
																																																											\
		inline void InvokeMultipleTimes( LargestUnsignedInteger numberOfTimesToInvoke, LeftSideOperandType& leftSideOperand, const Range< RightSideOperandType >& rangeForTheRightSideOperandRandomValue )									\
		{ 																																																									\
			/* Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current 																										\
			 instance is ready to be used */																																																\
			AssertValueIsLargerThenZero( numberOfTimesToInvoke ); 																																									\
																																																											\
			/* Loop the number of times the operator needs to be invoked */																																									\
			for ( LargestUnsignedInteger numberOfTimesOperatorWasInvoked = 0UL ; numberOfTimesOperatorWasInvoked < numberOfTimesToInvoke ; ++numberOfTimesOperatorWasInvoked ) 																\
			{ 																																																								\
				/* Invoke the operator using random right side operand */																																									\
				Invoke( leftSideOperand, rangeForTheRightSideOperandRandomValue ); 																																							\
			} 																																																								\
		} 																																																									\
																																																											\
																																																											\
		EnsureRetrunValueIsUsed inline const OperatorExecutionInformation< ReturnType, LeftSideOperandType, RightSideOperandType >& InvocationInformation( LargestUnsignedInteger index ) const 											\
		{ 																																																									\
			/* Return a constant reference to the required invocation information */																																						\
			return ( member_history[ index ] ); 																																															\
		} 																																																									\
																																																											\
																																																											\
		EnsureRetrunValueIsUsed inline const OperatorExecutionInformation< ReturnType, LeftSideOperandType, RightSideOperandType >& LastInvocationInformation() const 																		\
		{																																																									\
			/* Return a constant reference to the required invocation information */																																						\
			return ( member_history.Last() ); 																																																\
		} 																																																									\
																																																											\
																																																											\
	private: 																																																								\
																																																											\
																																																											\
		/* This object will store the following properties on each invocation of the operator : 																																			\
		 																																																									\
			1. A copy of the random left side operand generated before the operator call 																																					\
			2. A copy of the random left side operand after the operator call 																																								\
			3. A copy of the random right side operand generated before the operator call 																																					\
			4. A copy of the random right side operand after the operator call 																																								\
			5. The return value, if no exception was thrown 																																												\
			6. If an exception was thrown 																																																	\
			7. The error message in case an exception was thrown  */																																										\
		 																																																									\
		SequentialDataStructure< OperatorExecutionInformation< ReturnType, LeftSideOperandType, RightSideOperandType > > member_history; 																									\
																																																											\
																																																											\
	}  //  Class ExecuteOperatorWithRandomArguments



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *******************************************************************   CREATE ALL THE REQUIRED OBJECTS   ****************************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



// Create an object for every operator supported :
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
CreateExecuteOperatorWithRandomRightSideOperand( Addition );
CreateExecuteOperatorWithRandomRightSideOperand( Subtraction );
CreateExecuteOperatorWithRandomRightSideOperand( Division );
CreateExecuteOperatorWithRandomRightSideOperand( Multiplication );
CreateExecuteOperatorWithRandomRightSideOperand( Modulo );
CreateExecuteOperatorWithRandomRightSideOperand( AssignmentAddition );
CreateExecuteOperatorWithRandomRightSideOperand( AssignmentSubtraction );
CreateExecuteOperatorWithRandomRightSideOperand( AssignmentDivision );
CreateExecuteOperatorWithRandomRightSideOperand( AssignmentMultiplication );
CreateExecuteOperatorWithRandomRightSideOperand( AssignmentModulo );
CreateExecuteOperatorWithRandomRightSideOperand( Equal );
CreateExecuteOperatorWithRandomRightSideOperand( NonEqual );
CreateExecuteOperatorWithRandomRightSideOperand( Larger );
CreateExecuteOperatorWithRandomRightSideOperand( Smaller );
CreateExecuteOperatorWithRandomRightSideOperand( LargerOrEqual );
CreateExecuteOperatorWithRandomRightSideOperand( SmallerOrEqual );



}  //  Namespace Random


}  //  Namespace Universe