//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< Concepts::NonVoid ReturnType, typename FirstArgumentType, typename... RestOfArgumentsTypes >
inline ThreadOfExecution< ReturnType ( FirstArgumentType, RestOfArgumentsTypes... ) >::ThreadOfExecution( Callable< FunctionSignatureType >&& callable, FirstArgumentType&& firstArgument, RestOfArgumentsTypes&&... arguments ) :
	member_callable( TakeResourcesAndLeaveInstanceInDefaultState( callable ) ),
	member_posixThreadPointer( &FunctionThatWillRunInTheNewThreadOfExecution__Private, Memory::MainMemoryManager::template AllocateAndConstruct< CallableAndArguments< ReturnType, FirstArgumentType, RestOfArgumentsTypes... > >( member_callable, ForwardUniversalReference< FirstArgumentType >( firstArgument ), ForwardUniversalReference< RestOfArgumentsTypes >( arguments )... ) ),
	member_result()
{
	// The actual function signature that the thread of execution can be given is :
	//
	//		void* Function( void* argument )
	//
	// As can be seen only one argument, of type pointer to void can be provided. This means that if multiple arguments are needed, they must
	// be packed into a structure, or in this case a tuple, and then unpacked inside the function itself.
	//
	// To allow calling threads as regular C++ functions, all the functionality of the packing and unpacking will be done inside this object.
	// A tuple will be created that will contain, a pointer to the function the user provided, and all the given arguments as well. Then a
	// new thread will be created, and instead of passing it the function the user provided, a private function of this object will be run
	// instead. Inside the function the tuple will be unpacked, and finally the function the user provided will be called with all the
	// arguments
	//
	// An instance that will contain all the required infromation will be created :
	//
	//	1. A pointer to the callable to invoke
	//	2. All the required arguments
	//
	// Create the posix thread of execution, provide it with the private function and the tuple, and start the thread of execution
}


template< Concepts::NonVoid ReturnType, typename FirstArgumentType, typename... RestOfArgumentsTypes >
inline void ThreadOfExecution< ReturnType ( FirstArgumentType, RestOfArgumentsTypes... ) >::WaitForThreadOfExecutionToFinish()
{
	// Wait for the thread of execution to finish, and store the pointer to the results of the run
	ThreadOfExecutionResult< ReturnType >* const resultPointer = reinterpret_cast< ThreadOfExecutionResult< ReturnType >* >( member_posixThreadPointer->WaitForThreadOfExecutionToFinish() );

	// Fill the results
	member_result = TakeResourcesAndLeaveInstanceInDefaultState( *resultPointer );

	// Delete the tuple
	Memory::MainMemoryManager::Done< ThreadOfExecutionResult< ReturnType > >( resultPointer );
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



template< Concepts::NonVoid ReturnType, typename FirstArgumentType, typename... RestOfArgumentsTypes >
inline void* ThreadOfExecution< ReturnType ( FirstArgumentType, RestOfArgumentsTypes... ) >::FunctionThatWillRunInTheNewThreadOfExecution__Private( void* argument )
{
	Boolean wasExceptionThrown = false;
	Language::String errorMessage;
	ReturnType returnValue;

	try
	{
		// This pointer will point to the argument as tuple. In the constructor of this instance, the function pointer and all the arguments
		// the user provided, were packed into a tuple. Now it is time to start unpacking it
		CallableAndArguments< ReturnType, FirstArgumentType, RestOfArgumentsTypes... >* const callableAndArgumentsPointer = reinterpret_cast< CallableAndArguments< ReturnType, FirstArgumentType, RestOfArgumentsTypes... >* >( argument );

		// Call the function that will be used to unpack all the arguments in the tuple, and call the function that the user provided with them.
		// Finally allocate memory space and initialize using it the return value. This is needed to allow returning any type
		returnValue = FunctionToUnpackTheTupleAndInvokeTheCallableWithTheArguments__Private( *callableAndArgumentsPointer->GetCallablePointer(), callableAndArgumentsPointer->GetArgumentsTuple(), IncrementingIntegerSequence< 1 + sizeof...( RestOfArgumentsTypes ) >{} );

		// Delete the allocated wrapper instance for the function pointer and arguments
		Memory::MainMemoryManager::Done< CallableAndArguments< ReturnType, FirstArgumentType, RestOfArgumentsTypes... > >( callableAndArgumentsPointer );

	}
	catch ( const Error::Exception& exception )
	{
		wasExceptionThrown = true;
		errorMessage = exception.ErrorMessage();
	}
	catch ( const std::exception& stdException )
	{
		wasExceptionThrown = true;
		errorMessage = stdException.what();
	}
	catch ( ... )
	{
		wasExceptionThrown = true;
		errorMessage = "Function call failed. Unknown exception was caught";
	}

	ThreadOfExecutionResult< ReturnType >* const resultPointer = Memory::MainMemoryManager::AllocateAndConstruct< ThreadOfExecutionResult< ReturnType > >( TakeResourcesAndLeaveInstanceInDefaultState( returnValue ), wasExceptionThrown, errorMessage );

	// Cast the return value to void and return it
	return ( reinterpret_cast< void* >( resultPointer ) );
}


template< Concepts::NonVoid ReturnType, typename FirstArgumentType, typename... RestOfArgumentsTypes >
template< UnsignedInteger64bits... ArgumentIndices >
inline ReturnType ThreadOfExecution< ReturnType ( FirstArgumentType, RestOfArgumentsTypes... ) >::FunctionToUnpackTheTupleAndInvokeTheCallableWithTheArguments__Private( const Callable< FunctionSignatureType >& callable, Memory::Tuple< FirstArgumentType, RestOfArgumentsTypes... >& arguments, IncrementingIntegerSequenceHolder< ArgumentIndices... > )
{
	// Invoke the callable with the required arguments
	return ( callable( arguments.template Entry< ArgumentIndices >()... ) );
}




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - With no return value and at least one argument   ***************************************  //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //




//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< typename FirstArgumentType, typename... RestOfArgumentsTypes >
inline ThreadOfExecution< void ( FirstArgumentType, RestOfArgumentsTypes... ) >::ThreadOfExecution( Callable< FunctionSignatureType >&& callable, FirstArgumentType&& firstArgument, RestOfArgumentsTypes&&... arguments ) :
	member_callable( TakeResourcesAndLeaveInstanceInDefaultState( callable ) ),
	member_posixThreadPointer( &FunctionThatWillRunInTheNewThreadOfExecution__Private, Memory::MainMemoryManager::template AllocateAndConstruct< CallableAndArguments< void, FirstArgumentType, RestOfArgumentsTypes... > >( member_callable, ForwardUniversalReference< FirstArgumentType >( firstArgument ), ForwardUniversalReference< RestOfArgumentsTypes >( arguments )... ) ),
	member_result()
{
	// The actual function signature that the thread of execution can be given is :
	//
	//		void* Function( void* argument )
	//
	// As can be seen only one argument, of type pointer to void can be provided. This means that if multiple arguments are needed, they must
	// be packed into a structure, or in this case a tuple, and then unpacked inside the function itself.
	//
	// To allow calling threads as regular C++ functions, all the functionality of the packing and unpacking will be done inside this object.
	// A tuple will be created that will contain, a pointer to the function the user provided, and all the given arguments as well. Then a
	// new thread will be created, and instead of passing it the function the user provided, a private function of this object will be run
	// instead. Inside the function the tuple will be unpacked, and finally the function the user provided will be called with all the
	// arguments
	//
	// An instance that will contain all the required infromation will be created :
	//
	//	1. A pointer to the callable to invoke
	//	2. All the required arguments
	//
	// Create the posix thread of execution, provide it with the private function and the tuple, and start the thread of execution
}


template< typename FirstArgumentType, typename... RestOfArgumentsTypes >
inline void ThreadOfExecution< void ( FirstArgumentType, RestOfArgumentsTypes... ) >::WaitForThreadOfExecutionToFinish()
{
	// Wait for the thread of execution to finish, and store the return value casted to the tuple
	ThreadOfExecutionResult< void >* const resultPointer = reinterpret_cast< ThreadOfExecutionResult< void >* >( member_posixThreadPointer->WaitForThreadOfExecutionToFinish() );

	// Fill the results
	member_result = TakeResourcesAndLeaveInstanceInDefaultState( *resultPointer );

	// Delete the tuple
	Memory::MainMemoryManager::Done< ThreadOfExecutionResult< void > >( resultPointer );
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



template< typename FirstArgumentType, typename... RestOfArgumentsTypes >
inline void* ThreadOfExecution< void ( FirstArgumentType, RestOfArgumentsTypes... ) >::FunctionThatWillRunInTheNewThreadOfExecution__Private( void* argument )
{
	Boolean wasExceptionThrown = false;
	Language::String errorMessage;

	try
	{
		// This pointer will point to the argument as tuple. In the constructor of this instance, the function pointer and all the arguments
		// the user provided, were packed into a tuple. Now it is time to start unpacking it
		CallableAndArguments< void, FirstArgumentType, RestOfArgumentsTypes... >* const callableAndArgumentsPointer = reinterpret_cast< CallableAndArguments< void, FirstArgumentType, RestOfArgumentsTypes... >* >( argument );

		// Call the function that will be used to unpack all the arguments in the tuple, and call the function that the user provided with them.
		// Finally allocate memory space and initialize using it the return value. This is needed to allow returning any type
		FunctionToUnpackTheTupleAndInvokeTheCallableWithTheArguments__Private( *callableAndArgumentsPointer->GetCallablePointer(), callableAndArgumentsPointer->GetArgumentsTuple(), IncrementingIntegerSequence< 1 + sizeof...( RestOfArgumentsTypes ) >{} );

		// Delete the allocated wrapper instance for the function pointer and arguments
		Memory::MainMemoryManager::Done< CallableAndArguments< void, FirstArgumentType, RestOfArgumentsTypes... > >( callableAndArgumentsPointer );

	}
	catch ( const Error::Exception& exception )
	{
		wasExceptionThrown = true;
		errorMessage = exception.ErrorMessage();
	}
	catch ( const std::exception& stdException )
	{
		wasExceptionThrown = true;
		errorMessage = stdException.what();
	}
	catch ( ... )
	{
		wasExceptionThrown = true;
		errorMessage = "Function call failed. Unknown exception was caught";
	}

	ThreadOfExecutionResult< void >* const resultPointer = Memory::MainMemoryManager::AllocateAndConstruct< ThreadOfExecutionResult< void > >( wasExceptionThrown, errorMessage );

	// Cast the return value to void and return it
	return ( reinterpret_cast< void* >( resultPointer ) );
}


template< typename FirstArgumentType, typename... RestOfArgumentsTypes >
template< UnsignedInteger64bits... ArgumentIndices >
inline void ThreadOfExecution< void ( FirstArgumentType, RestOfArgumentsTypes... ) >::FunctionToUnpackTheTupleAndInvokeTheCallableWithTheArguments__Private( const Callable< FunctionSignatureType >& callable, Memory::Tuple< FirstArgumentType, RestOfArgumentsTypes... >& arguments, IncrementingIntegerSequenceHolder< ArgumentIndices... > )
{
	// Invoke the callable with the required arguments
	callable( arguments.template Entry< ArgumentIndices >()... );
}



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - No arguments to function   ************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< Concepts::NonVoid ReturnType >
inline ThreadOfExecution< ReturnType () >::ThreadOfExecution( Callable< FunctionSignatureType >&& callable ) :
	member_callable( TakeResourcesAndLeaveInstanceInDefaultState( callable ) ),
	member_posixThreadPointer( &FunctionThatWillRunInTheNewThreadOfExecution__Private, &member_callable ),
	member_result()
{}


template< Concepts::NonVoid ReturnType >
inline void ThreadOfExecution< ReturnType () >::WaitForThreadOfExecutionToFinish()
{
	// Wait for the thread of execution to finish, and store the return value casted to the tuple
	ThreadOfExecutionResult< ReturnType >* const resultPointer = reinterpret_cast< ThreadOfExecutionResult< ReturnType >* >( member_posixThreadPointer->WaitForThreadOfExecutionToFinish() );

	// Fill the results
	member_result = TakeResourcesAndLeaveInstanceInDefaultState( *resultPointer );

	// Delete the tuple
	Memory::MainMemoryManager::Done< ThreadOfExecutionResult< ReturnType > >( resultPointer );
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



template< Concepts::NonVoid ReturnType >
inline void* ThreadOfExecution< ReturnType () >::FunctionThatWillRunInTheNewThreadOfExecution__Private( void* argument )
{
	Boolean wasExceptionThrown = false;
	Language::String errorMessage;
	ReturnType returnValue;

	try
	{
		// Cast the given pointer argument to the callable type
		const Callable< FunctionSignatureType >* const callablePointer = reinterpret_cast< const Callable< FunctionSignatureType >* >( argument );

		// Call the function that will be used to unpack all the arguments in the tuple, and call the function that the user provided with them
		returnValue = (*callablePointer)();

	}
	catch ( const Error::Exception& exception )
	{
		wasExceptionThrown = true;
		errorMessage = exception.ErrorMessage();
	}
	catch ( const std::exception& stdException )
	{
		wasExceptionThrown = true;
		errorMessage = stdException.what();
	}
	catch ( ... )
	{
		wasExceptionThrown = true;
		errorMessage = "Function call failed. Unknown exception was caught";
	}

	ThreadOfExecutionResult< ReturnType >* const resultPointer = Memory::MainMemoryManager::AllocateAndConstruct< ThreadOfExecutionResult< ReturnType > >( TakeResourcesAndLeaveInstanceInDefaultState( returnValue ), wasExceptionThrown, errorMessage );

	// Cast the return value to void and return it
	return ( reinterpret_cast< void* >( resultPointer ) );
}



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ****************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - No arguments to function and return value   ****************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline ThreadOfExecution< void () >::ThreadOfExecution( Callable< FunctionSignatureType >&& callable ) :
	member_callable( TakeResourcesAndLeaveInstanceInDefaultState( callable ) ),
	member_posixThreadPointer( &FunctionThatWillRunInTheNewThreadOfExecution__Private, &member_callable ),
	member_result()
{}


inline void ThreadOfExecution< void () >::WaitForThreadOfExecutionToFinish()
{
	// Wait for the thread of execution to finish, and store the return value casted to the tuple
	const ThreadOfExecutionResult< void >* const resultPointer = reinterpret_cast< ThreadOfExecutionResult< void >* >( member_posixThreadPointer->WaitForThreadOfExecutionToFinish() );

	// Fill the results
	member_result = TakeResourcesAndLeaveInstanceInDefaultState( *resultPointer );

	// Delete the tuple
	Memory::MainMemoryManager::Done< ThreadOfExecutionResult< void > >( resultPointer );
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



inline void* ThreadOfExecution< void () >::FunctionThatWillRunInTheNewThreadOfExecution__Private( void* argument )
{
	Boolean wasExceptionThrown = false;
	Language::String errorMessage;

	try
	{
		// Cast the given pointer argument to the callable type
		const Callable< FunctionSignatureType >* const callablePointer = reinterpret_cast< const Callable< FunctionSignatureType >* >( argument );

		// Call the function that will be used to unpack all the arguments in the tuple, and call the function that the user provided with them
		(*callablePointer)();

	}
	catch ( const Error::Exception& exception )
	{
		wasExceptionThrown = true;
		errorMessage = exception.ErrorMessage();
	}
	catch ( const std::exception& stdException )
	{
		wasExceptionThrown = true;
		errorMessage = stdException.what();
	}
	catch ( ... )
	{
		wasExceptionThrown = true;
		errorMessage = "Function call failed. Unknown exception was caught";
	}

	ThreadOfExecutionResult< void >* const resultPointer = Memory::MainMemoryManager::AllocateAndConstruct< ThreadOfExecutionResult< void > >( wasExceptionThrown, errorMessage );

	// Cast the return value to void and return it
	return ( reinterpret_cast< void* >( resultPointer ) );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	inline UnsignedInteger64bits FunctioWithArgumentsAndReturnValue( UnsignedInteger64bits integer )
	{
		Assert_Test( integer == 89UL );

		return ( 445UL );
	}

	inline UnsignedInteger64bits FunctioWithNoArgumentsButReturnValueExist()
	{
		return ( 445UL );
	}

	inline void FunctioWithNoArgumentsAndNoReturnValue()
	{}

	template< Concepts::NonVoid ReturnType COMMA typename FirstArgumentType COMMA typename... RestOfArgumentsTypes >
	inline void ThreadOfExecution< ReturnType ( FirstArgumentType, RestOfArgumentsTypes... ) >::UnitTest()
	{
		// TEST FUNCTIONS :

		Callable< UnsignedInteger64bits ( UnsignedInteger64bits ) > testCallable_0( &FunctioWithArgumentsAndReturnValue );
		ThreadOfExecution< UnsignedInteger64bits ( UnsignedInteger64bits ) > testThreadOfExecution_0( TakeResourcesAndLeaveInstanceInDefaultState( testCallable_0 ), 89UL );

		testThreadOfExecution_0.WaitForThreadOfExecutionToFinish();

		Assert_Test( testThreadOfExecution_0.WasExceptionThrown() == false );
		Assert_Test( testThreadOfExecution_0.ReturnValue() == 445UL );

		Callable< UnsignedInteger64bits () > testCallable_1( &FunctioWithNoArgumentsButReturnValueExist );
		ThreadOfExecution< UnsignedInteger64bits () > testThreadOfExecution_1( TakeResourcesAndLeaveInstanceInDefaultState( testCallable_1 ) );

		testThreadOfExecution_1.WaitForThreadOfExecutionToFinish();

		Assert_Test( testThreadOfExecution_1.WasExceptionThrown() == false );
		Assert_Test( testThreadOfExecution_1.ReturnValue() == 445UL );

		Callable< void () > testCallable_2( &FunctioWithNoArgumentsAndNoReturnValue );
		ThreadOfExecution< void () > testThreadOfExecution_2( TakeResourcesAndLeaveInstanceInDefaultState( testCallable_2 ) );

		testThreadOfExecution_2.WaitForThreadOfExecutionToFinish();

		Assert_Test( testThreadOfExecution_2.WasExceptionThrown() == false );

		// TEST FUNCTOR :

		Test::FunctorObject< UnsignedInteger64bits COMMA UnsignedInteger64bits COMMA UnsignedInteger64bits > testFunctor( 89UL );

		Callable< UnsignedInteger64bits ( UnsignedInteger64bits ) > testCallable_3( testFunctor );
		ThreadOfExecution< UnsignedInteger64bits ( UnsignedInteger64bits ) > testThreadOfExecution_3( TakeResourcesAndLeaveInstanceInDefaultState( testCallable_3 ), 79UL );

		testThreadOfExecution_3.WaitForThreadOfExecutionToFinish();

		Assert_Test( testThreadOfExecution_3.WasExceptionThrown() == false );
		Assert_Test( testThreadOfExecution_3.ReturnValue() == 79UL );

		// TEST METHOD :

		Test::Object testObject( 89UL, 445UL );

		Callable< void () > testCallable_4( testObject, &Test::Object::Method_3 );
		ThreadOfExecution< void () > testThreadOfExecution_4( TakeResourcesAndLeaveInstanceInDefaultState( testCallable_4 ) );

		testThreadOfExecution_4.WaitForThreadOfExecutionToFinish();

		Assert_Test( testThreadOfExecution_4.WasExceptionThrown() == false );

		// TEST LAMBDA EXPRESSION :

		UnsignedInteger64bits sum = 0;
		
		Callable< void ( UnsignedInteger64bits* ) > testCallable_6( []( UnsignedInteger64bits* sumPointer ) 
		{
			Assert_Test( sumPointer != nullptr );

			for ( UnsignedInteger64bits index = 0UL ; index < 10000UL ; ++index )
			{
				*sumPointer += 1;
			}

		} );

		ThreadOfExecution< void ( UnsignedInteger64bits* ) > testThreadOfExecution_5( TakeResourcesAndLeaveInstanceInDefaultState( testCallable_6 ), &sum );

		testThreadOfExecution_5.WaitForThreadOfExecutionToFinish();

		Assert_Test( testThreadOfExecution_5.WasExceptionThrown() == false );
		Assert_Test( sum == 10000UL );

		auto sumUp = [ &sum ]() 
		{
			for ( UnsignedInteger64bits index = 0UL ; index < 10000UL ; ++index )
			{
				sum += 1UL;
			}
		};

		Callable< void () > testCallable_7( sumUp );

		ThreadOfExecution< void () > testThreadOfExecution_6( TakeResourcesAndLeaveInstanceInDefaultState( testCallable_7 ) );

		testThreadOfExecution_6.WaitForThreadOfExecutionToFinish();

		Assert_Test( testThreadOfExecution_6.WasExceptionThrown() == false );
		Assert_Test( sum == ( 10000UL * 2UL ) );


		// TEST EXCEPTION THROWING : 

		Callable< void () > testCallable_8( []() 
		{
			ThrowException( "NICE" );
		} );

		ThreadOfExecution< void () > testThreadOfExecution_7( TakeResourcesAndLeaveInstanceInDefaultState( testCallable_8 ) );

		testThreadOfExecution_7.WaitForThreadOfExecutionToFinish();

		Assert_Test( testThreadOfExecution_7.WasExceptionThrown() == true );
		Assert_Test( testThreadOfExecution_7.ErrorMessage().Contains( Language::String( "NICE" ) ) == true );
	}

)  //  End of debug tool



}  //  Namespace MultiThread


}  //  Namespace Universe