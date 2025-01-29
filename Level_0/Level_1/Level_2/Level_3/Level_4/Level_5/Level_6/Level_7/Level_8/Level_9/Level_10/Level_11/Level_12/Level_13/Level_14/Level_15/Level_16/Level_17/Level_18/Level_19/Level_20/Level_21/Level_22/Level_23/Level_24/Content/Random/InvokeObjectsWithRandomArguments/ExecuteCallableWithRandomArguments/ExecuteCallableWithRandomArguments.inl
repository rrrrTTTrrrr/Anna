// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *********************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - To allow deducing the return and function argument types   ********************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //


//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< typename ReturnType, typename... ArgumentTypes >
inline ExecuteCallableWithRandomArguments< ReturnType ( ArgumentTypes... ) >::ExecuteCallableWithRandomArguments() :
	member_callablePointer( nullptr ),
	member_history( MemoryHandlerName::SingleLinkedList )
{}


template< typename ReturnType, typename... ArgumentTypes >
inline ExecuteCallableWithRandomArguments< ReturnType ( ArgumentTypes... ) >::ExecuteCallableWithRandomArguments( const Callable< SelfFunctionType >& callable ) :
	member_callablePointer( &callable ),
	member_history( MemoryHandlerName::SingleLinkedList )
{}


template< typename ReturnType, typename... ArgumentTypes >
inline LargestUnsignedInteger ExecuteCallableWithRandomArguments< ReturnType ( ArgumentTypes... ) >::NumberOfExecutions() const
{
	// Return the number of times the function was invoked, which is the size of the history member
	return ( member_history.Size() );
}


template< typename ReturnType, typename... ArgumentTypes >
template< typename... ConstraintsOnRandomArgumentsTypes >
inline void ExecuteCallableWithRandomArguments< ReturnType ( ArgumentTypes... ) >::Invoke( ConstraintsOnRandomArgumentsTypes... constraintsOnRandomArguments )
{
	// This boolean will store if the function threw an exception
	Boolean wasExceptionThrown = false;

	// This boolean will store the error message if an exception was thrown
	Language::String errorMessage;

	// Generate the random arguments required for the function invocation
	Memory::Tuple< ArgumentTypes... > randomGeneratedArguments = Random::Generator::Tuple< ArgumentTypes... >::template Next< ConstraintsOnRandomArgumentsTypes... >( ForwardUniversalReference< ConstraintsOnRandomArgumentsTypes >( constraintsOnRandomArguments )... );

	// This object will store the return value of the function
	ReturnType returnValue;

	// Try catch block in case the function will throw an exception
	try
	{
		// Invoke the function using the random generate arguments
		returnValue = (*member_callablePointer)( randomGeneratedArguments );

	}
	catch ( const Error::Exception& exception )
	{
		// Set that an exception was thrown
		wasExceptionThrown = true;

		// Store the exception error message
		errorMessage = TakeResourcesAndLeaveInstanceInDefaultState( Language::String( exception.ErrorMessage() ) );
	}

	// This object will store the information on the current function call
	CallableExecutionInformation< SelfFunctionType > executionInformation;

	// Set the function call inforamtion
	executionInformation.AddArguments( TakeResourcesAndLeaveInstanceInDefaultState( randomGeneratedArguments ) );
	executionInformation.AddReturnValue( TakeResourcesAndLeaveInstanceInDefaultState( returnValue ) );
	executionInformation.AddWasExceptionThrown( wasExceptionThrown );
	executionInformation.AddExceptionErrorMessage( TakeResourcesAndLeaveInstanceInDefaultState( errorMessage ) );

	// Add all the information of the current invocation of the function to the history
	member_history.InsertSingleElementAtTheEnd( TakeResourcesAndLeaveInstanceInDefaultState( executionInformation ) );
}


template< typename ReturnType, typename... ArgumentTypes >
inline void ExecuteCallableWithRandomArguments< ReturnType ( ArgumentTypes... ) >::Invoke()
{
	// This boolean will store if the function threw an exception
	Boolean wasExceptionThrown = false;

	// This boolean will store the error message if an exception was thrown
	Language::String errorMessage;

	// Generate the random arguments required for the function invocation
	Memory::Tuple< ArgumentTypes... > randomGeneratedArguments = Random::Generator::Tuple< ArgumentTypes... >::Next();

	// This object will store the return value of the function
	ReturnType returnValue;

	// Try catch block in case the function will throw an exception
	try
	{
		// Invoke the function using the random generate arguments
		returnValue = (*member_callablePointer)( randomGeneratedArguments );

	}
	catch ( const Error::Exception& exception )
	{
		// Set that an exception was thrown
		wasExceptionThrown = true;

		// Store the exception error message
		errorMessage = TakeResourcesAndLeaveInstanceInDefaultState( Language::String( exception.ErrorMessage() ) );
	}

	// This object will store the information on the current function call
	CallableExecutionInformation< SelfFunctionType > executionInformation;

	// Set the function call inforamtion
	executionInformation.AddArguments( TakeResourcesAndLeaveInstanceInDefaultState( randomGeneratedArguments ) );
	executionInformation.AddReturnValue( TakeResourcesAndLeaveInstanceInDefaultState( returnValue ) );
	executionInformation.AddWasExceptionThrown( wasExceptionThrown );
	executionInformation.AddExceptionErrorMessage( TakeResourcesAndLeaveInstanceInDefaultState( errorMessage ) );

	// Add all the information of the current invocation of the function to the history
	member_history.InsertSingleElementAtTheEnd( TakeResourcesAndLeaveInstanceInDefaultState( executionInformation ) );
}


template< typename ReturnType, typename... ArgumentTypes >
template< typename... ConstraintsOnRandomArgumentsTypes >
inline void ExecuteCallableWithRandomArguments< ReturnType ( ArgumentTypes... ) >::InvokeMultipleTimes( const LargestUnsignedInteger numberOfTimesToInvoke, ConstraintsOnRandomArgumentsTypes... constraintsOnRandomArguments )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsLargerThenZero( numberOfTimesToInvoke );

	// Loop the number of times the function needs to be invoked
	for ( LargestUnsignedInteger numberOfExecutions = 0UL ; numberOfExecutions < numberOfTimesToInvoke ; ++numberOfExecutions )
	{
		// Invoke the function using random arguments
		Invoke( ForwardUniversalReference< ConstraintsOnRandomArgumentsTypes >( constraintsOnRandomArguments )... );
	}
}


template< typename ReturnType, typename... ArgumentTypes >
inline const CallableExecutionInformation< ReturnType ( ArgumentTypes... ) >& ExecuteCallableWithRandomArguments< ReturnType ( ArgumentTypes... ) >::ExecutionInformation( const LargestUnsignedInteger index ) const
{
	// Return a constant reference to the required invocation information
	return ( member_history[ index ] );
}


template< typename ReturnType, typename... ArgumentTypes >
inline const CallableExecutionInformation< ReturnType ( ArgumentTypes... ) >& ExecuteCallableWithRandomArguments< ReturnType ( ArgumentTypes... ) >::LastInvocationInformation() const
{
	// Return a constant reference to the required invocation information
	return ( member_history.Last() );
}



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ********************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - To allow deducing the return type   ********************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //


//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< typename ReturnType >
inline ExecuteCallableWithRandomArguments< ReturnType () >::ExecuteCallableWithRandomArguments() :
	member_callablePointer( nullptr ),
	member_history( MemoryHandlerName::SingleLinkedList )
{}


template< typename ReturnType >
inline ExecuteCallableWithRandomArguments< ReturnType () >::ExecuteCallableWithRandomArguments( const Callable< SelfFunctionType >& callable ) :
	member_callablePointer( &callable ),
	member_history( MemoryHandlerName::SingleLinkedList )
{}


template< typename ReturnType >
inline LargestUnsignedInteger ExecuteCallableWithRandomArguments< ReturnType () >::NumberOfExecutions() const
{
	// Return the number of times the function was invoked, which is the size of the history member
	return ( member_history.Size() );
}


template< typename ReturnType >
inline void ExecuteCallableWithRandomArguments< ReturnType () >::Invoke()
{
	// This boolean will store if the function threw an exception
	Boolean wasExceptionThrown = false;

	// This boolean will store the error message if an exception was thrown
	Language::String errorMessage;

	// This object will store the return value of the function
	ReturnType returnValue;

	// Try catch block in case the function will throw an exception
	try
	{
		// Invoke the function
		returnValue = (*member_callablePointer)();

	}
	catch ( const Error::Exception& exception )
	{
		// Set that an exception was thrown
		wasExceptionThrown = true;

		// Store the exception error message
		errorMessage = TakeResourcesAndLeaveInstanceInDefaultState( Language::String( exception.ErrorMessage() ) );
	}

	// This object will store the information on the current function call
	CallableExecutionInformation< SelfFunctionType > executionInformation;

	// Set the function call inforamtion
	executionInformation.AddReturnValue( TakeResourcesAndLeaveInstanceInDefaultState( returnValue ) );
	executionInformation.AddWasExceptionThrown( wasExceptionThrown );
	executionInformation.AddExceptionErrorMessage( TakeResourcesAndLeaveInstanceInDefaultState( errorMessage ) );

	// Add all the information of the current invocation of the function to the history
	member_history.InsertSingleElementAtTheEnd( TakeResourcesAndLeaveInstanceInDefaultState( executionInformation ) );
}


template< typename ReturnType >
inline void ExecuteCallableWithRandomArguments< ReturnType () >::InvokeMultipleTimes( const LargestUnsignedInteger numberOfTimesToInvoke )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsLargerThenZero( numberOfTimesToInvoke );

	// Loop the number of times the function needs to be invoked
	for ( LargestUnsignedInteger numberOfExecutions = 0UL ; numberOfExecutions < numberOfTimesToInvoke ; ++numberOfExecutions )
	{
		// Invoke the function
		Invoke();
	}
}


template< typename ReturnType >
inline const CallableExecutionInformation< ReturnType () >& ExecuteCallableWithRandomArguments< ReturnType () >::ExecutionInformation( const LargestUnsignedInteger index ) const
{
	// Return a constant reference to the required invocation information
	return ( member_history[ index ] );
}


template< typename ReturnType >
inline const CallableExecutionInformation< ReturnType () >& ExecuteCallableWithRandomArguments< ReturnType () >::LastInvocationInformation() const
{
	// Return a constant reference to the required invocation information
	return ( member_history.Last() );
}



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// **************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - To allow deducing the function argument types   **************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //


//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< typename... ArgumentTypes >
inline ExecuteCallableWithRandomArguments< void ( ArgumentTypes... ) >::ExecuteCallableWithRandomArguments() :
	member_callablePointer( nullptr ),
	member_history( MemoryHandlerName::SingleLinkedList )
{}


template< typename... ArgumentTypes >
inline ExecuteCallableWithRandomArguments< void ( ArgumentTypes... ) >::ExecuteCallableWithRandomArguments( const Callable< SelfFunctionType >& callable ) :
	member_callablePointer( &callable ),
	member_history( MemoryHandlerName::SingleLinkedList )
{}


template< typename... ArgumentTypes >
inline LargestUnsignedInteger ExecuteCallableWithRandomArguments< void ( ArgumentTypes... ) >::NumberOfExecutions() const
{
	// Return the number of times the function was invoked, which is the size of the history member
	return ( member_history.Size() );
}


template< typename... ArgumentTypes >
template< typename... ConstraintsOnRandomArgumentsTypes >
inline void ExecuteCallableWithRandomArguments< void ( ArgumentTypes... ) >::Invoke( ConstraintsOnRandomArgumentsTypes... constraintsOnRandomArguments )
{
	// This boolean will store if the function threw an exception
	Boolean wasExceptionThrown = false;

	// This boolean will store the error message if an exception was thrown
	Language::String errorMessage;

	// Generate the random arguments required for the function invocation
	Memory::Tuple< ArgumentTypes... > randomGeneratedArguments = Random::Generator::Tuple< ArgumentTypes... >::template Next< ConstraintsOnRandomArgumentsTypes... >( ForwardUniversalReference< ConstraintsOnRandomArgumentsTypes >( constraintsOnRandomArguments )... );

	// Try catch block in case the function will throw an exception
	try
	{
		// Invoke the function using the random generate arguments
		(*member_callablePointer)( randomGeneratedArguments );

	}
	catch ( const Error::Exception& exception )
	{
		// Set that an exception was thrown
		wasExceptionThrown = true;

		// Store the exception error message
		errorMessage = TakeResourcesAndLeaveInstanceInDefaultState( Language::String( exception.ErrorMessage() ) );
	}

	// This object will store the information on the current function call
	CallableExecutionInformation< SelfFunctionType > executionInformation;

	// Set the function call inforamtion
	executionInformation.AddArguments( TakeResourcesAndLeaveInstanceInDefaultState( randomGeneratedArguments ) );
	executionInformation.AddWasExceptionThrown( wasExceptionThrown );
	executionInformation.AddExceptionErrorMessage( TakeResourcesAndLeaveInstanceInDefaultState( errorMessage ) );

	// Add all the information of the current invocation of the function to the history
	member_history.InsertSingleElementAtTheEnd( TakeResourcesAndLeaveInstanceInDefaultState( executionInformation ) );
}


template< typename... ArgumentTypes >
inline void ExecuteCallableWithRandomArguments< void ( ArgumentTypes... ) >::Invoke()
{
	// This boolean will store if the function threw an exception
	Boolean wasExceptionThrown = false;

	// This boolean will store the error message if an exception was thrown
	Language::String errorMessage;

	// Generate the random arguments required for the function invocation
	Memory::Tuple< ArgumentTypes... > randomGeneratedArguments = Random::Generator::Tuple< ArgumentTypes... >::Next();

	// Try catch block in case the function will throw an exception
	try
	{
		// Invoke the function using the random generate arguments
		(*member_callablePointer)( randomGeneratedArguments );

	}
	catch ( const Error::Exception& exception )
	{
		// Set that an exception was thrown
		wasExceptionThrown = true;

		// Store the exception error message
		errorMessage = TakeResourcesAndLeaveInstanceInDefaultState( Language::String( exception.ErrorMessage() ) );
	}

	// This object will store the information on the current function call
	CallableExecutionInformation< SelfFunctionType > executionInformation;

	// Set the function call inforamtion
	executionInformation.AddArguments( TakeResourcesAndLeaveInstanceInDefaultState( randomGeneratedArguments ) );
	executionInformation.AddWasExceptionThrown( wasExceptionThrown );
	executionInformation.AddExceptionErrorMessage( TakeResourcesAndLeaveInstanceInDefaultState( errorMessage ) );

	// Add all the information of the current invocation of the function to the history
	member_history.InsertSingleElementAtTheEnd( TakeResourcesAndLeaveInstanceInDefaultState( executionInformation ) );
}


template< typename... ArgumentTypes >
template< typename... ConstraintsOnRandomArgumentsTypes >
inline void ExecuteCallableWithRandomArguments< void ( ArgumentTypes... ) >::InvokeMultipleTimes( const LargestUnsignedInteger numberOfTimesToInvoke, ConstraintsOnRandomArgumentsTypes... constraintsOnRandomArguments )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsLargerThenZero( numberOfTimesToInvoke );

	// Loop the number of times the function needs to be invoked
	for ( LargestUnsignedInteger numberOfExecutions = 0UL ; numberOfExecutions < numberOfTimesToInvoke ; ++numberOfExecutions )
	{
		// Invoke the function using random arguments
		Invoke( ForwardUniversalReference< ConstraintsOnRandomArgumentsTypes >( constraintsOnRandomArguments )... );
	}
}


template< typename... ArgumentTypes >
inline const CallableExecutionInformation< void ( ArgumentTypes... ) >& ExecuteCallableWithRandomArguments< void ( ArgumentTypes... ) >::ExecutionInformation( const LargestUnsignedInteger index ) const
{
	// Return a constant reference to the required invocation information
	return ( member_history[ index ] );
}


template< typename... ArgumentTypes >
inline const CallableExecutionInformation< void ( ArgumentTypes... ) >& ExecuteCallableWithRandomArguments< void ( ArgumentTypes... ) >::LastInvocationInformation() const
{
	// Return a constant reference to the required invocation information
	return ( member_history.Last() );
}



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ********************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - To allow deducing the return type   ********************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //


//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline ExecuteCallableWithRandomArguments< void () >::ExecuteCallableWithRandomArguments() :
	member_callablePointer( nullptr ),
	member_history( MemoryHandlerName::SingleLinkedList )
{}


inline ExecuteCallableWithRandomArguments< void () >::ExecuteCallableWithRandomArguments( const Callable< SelfFunctionType >& callable ) :
	member_callablePointer( &callable ),
	member_history( MemoryHandlerName::SingleLinkedList )
{}


inline LargestUnsignedInteger ExecuteCallableWithRandomArguments< void () >::NumberOfExecutions() const
{
	// Return the number of times the function was invoked, which is the size of the history member
	return ( member_history.Size() );
}


inline void ExecuteCallableWithRandomArguments< void () >::Invoke()
{
	// This boolean will store if the function threw an exception
	Boolean wasExceptionThrown = false;

	// This boolean will store the error message if an exception was thrown
	Language::String errorMessage;

	// Try catch block in case the function will throw an exception
	try
	{
		// Invoke the function
		(*member_callablePointer)();

	}
	catch ( const Error::Exception& exception )
	{
		// Set that an exception was thrown
		wasExceptionThrown = true;

		// Store the exception error message
		errorMessage = TakeResourcesAndLeaveInstanceInDefaultState( Language::String( exception.ErrorMessage() ) );
	}

	// This object will store the information on the current function call
	CallableExecutionInformation< SelfFunctionType > executionInformation;

	// Set the function call inforamtion
	executionInformation.AddWasExceptionThrown( wasExceptionThrown );
	executionInformation.AddExceptionErrorMessage( TakeResourcesAndLeaveInstanceInDefaultState( errorMessage ) );

	// Add all the information of the current invocation of the function to the history
	member_history.InsertSingleElementAtTheEnd( TakeResourcesAndLeaveInstanceInDefaultState( executionInformation ) );
}


inline void ExecuteCallableWithRandomArguments< void () >::InvokeMultipleTimes( const LargestUnsignedInteger numberOfTimesToInvoke )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsLargerThenZero( numberOfTimesToInvoke );

	// Loop the number of times the function needs to be invoked
	for ( LargestUnsignedInteger numberOfExecutions = 0UL ; numberOfExecutions < numberOfTimesToInvoke ; ++numberOfExecutions )
	{
		// Invoke the function
		Invoke();
	}
}


inline const CallableExecutionInformation< void () >& ExecuteCallableWithRandomArguments< void () >::ExecutionInformation( const LargestUnsignedInteger index ) const
{
	// Return a constant reference to the required invocation information
	return ( member_history[ index ] );
}


inline const CallableExecutionInformation< void () >& ExecuteCallableWithRandomArguments< void () >::LastInvocationInformation() const
{
	// Return a constant reference to the required invocation information
	return ( member_history.Last() );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	LargestUnsignedInteger Test_Function_1( LargestUnsignedInteger argument_1 )
	{
		return ( argument_1 + 54UL );
	}

	LargestUnsignedInteger Test_Function_2()
	{
		return ( 54UL );
	}

	void Test_Function_3( LargestUnsignedInteger )
	{}

	void Test_Function_4()
	{}

	template< typename ReturnType COMMA typename... ArgumentTypes >
	inline void ExecuteCallableWithRandomArguments< ReturnType ( ArgumentTypes... ) >::UnitTest()
	{
		Callable< LargestUnsignedInteger ( LargestUnsignedInteger ) > testCallable_1( &Test_Function_1 );

		// Create a test instance
		ExecuteCallableWithRandomArguments< LargestUnsignedInteger ( LargestUnsignedInteger ) > testInstance_1( testCallable_1 );

		// Invoke the funnction with random arguments
		testInstance_1.Invoke();

		// Invoke the funnction with random arguments
		testInstance_1.InvokeMultipleTimes( 3UL );

		Callable< LargestUnsignedInteger () > testCallable_2( &Test_Function_2 );

		// Create a test instance
		ExecuteCallableWithRandomArguments< LargestUnsignedInteger () > testInstance_2( testCallable_2 );

		// Invoke the funnction with random arguments
		testInstance_2.Invoke();

		// Invoke the funnction with random arguments
		testInstance_2.InvokeMultipleTimes( 3UL );

		Callable< void ( LargestUnsignedInteger ) > testCallable_3( &Test_Function_3 );

		// Create a test instance
		ExecuteCallableWithRandomArguments< void ( LargestUnsignedInteger ) > testInstance_3( testCallable_3 );

		// Invoke the funnction with random arguments
		testInstance_3.Invoke();

		// Invoke the funnction with random arguments
		testInstance_3.InvokeMultipleTimes( 3UL );

		Callable< void () > testCallable_4( &Test_Function_4 );

		// Create a test instance
		ExecuteCallableWithRandomArguments< void () > testInstance_4( testCallable_4 );

		// Invoke the funnction with random arguments
		testInstance_4.Invoke();

		// Invoke the funnction with random arguments
		testInstance_4.InvokeMultipleTimes( 3UL );
	}

)  //  End of debug tool



}  //  Namespace Random


}  //  Namespace Universe