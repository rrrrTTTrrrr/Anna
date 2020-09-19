//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



	template< typename ReturnValueType, typename... FunctionArgumentTypes >
	inline FunctionPointer< ReturnValueType, FunctionArgumentTypes... >::FunctionPointer() :
		member_functionPointer( 0UL )
	{}


	template< typename ReturnValueType, typename... FunctionArgumentTypes >
	inline FunctionPointer< ReturnValueType, FunctionArgumentTypes... >::FunctionPointer( FunctionPointerType functionMemoryAddress ) :
		member_functionPointer( functionMemoryAddress )
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	    // instance is ready to be used
		AssertPointer_MACRO( functionMemoryAddress );
	}


	template< typename ReturnValueType, typename... FunctionArgumentTypes >
	inline FunctionPointer< ReturnValueType, FunctionArgumentTypes... >::FunctionPointer( const FunctionPointer< ReturnValueType, FunctionArgumentTypes... >& other ) :
		member_functionPointer( other.member_functionPointer )
	{}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



	template< typename ReturnValueType, typename... FunctionArgumentTypes >
	ReturnValueType FunctionPointer< ReturnValueType, FunctionArgumentTypes... >::operator()( FunctionArgumentTypes... arguments )
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	    // instance is ready to be used
		AssertPointer_MACRO( member_functionPointer );

		// Invoke the function using the arguments, and return the value
		return ( ( *member_functionPointer )( arguments... ) );
	}


	template< typename ReturnValueType, typename... FunctionArgumentTypes >
	inline ReturnValueType FunctionPointer< ReturnValueType, FunctionArgumentTypes... >::operator()( FunctionArgumentTypes... arguments ) const
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	    // instance is ready to be used
		AssertPointer_MACRO( member_functionPointer );

		// Invoke the function using the arguments, and return the value
		return ( ( *member_functionPointer )( arguments... ) );
	}


    template< typename ReturnValueType, typename... FunctionArgumentTypes >
    ReturnValueType FunctionPointer< ReturnValueType, FunctionArgumentTypes... >::operator()( const Tuple< FunctionArgumentTypes... >& arguments )
    {
	    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	    // instance is ready to be used
		AssertPointer_MACRO( member_functionPointer );

        // Invoke the function with the tuple of arguments, and return the value
        return ( InvokeUsingTuple__Private( arguments, IncrementingIntegerSequence< sizeof...( FunctionArgumentTypes ) >{} ) );
    }


    template< typename ReturnValueType, typename... FunctionArgumentTypes >
    inline ReturnValueType FunctionPointer< ReturnValueType, FunctionArgumentTypes... >::operator()( const Tuple< FunctionArgumentTypes... >& arguments ) const
    {
	    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	    // instance is ready to be used
		AssertPointer_MACRO( member_functionPointer );

        // Invoke the function with the tuple of arguments, and return the value
        return ( InvokeUsingTuple__Private( arguments, IncrementingIntegerSequence< sizeof...( FunctionArgumentTypes ) >{} ) );
    }


	template< typename ReturnValueType, typename... FunctionArgumentTypes >
	inline Boolean FunctionPointer< ReturnValueType, FunctionArgumentTypes... >::operator==( const FunctionPointer< ReturnValueType, FunctionArgumentTypes... >& other ) const
	{
		// Check if the instances point to the same function, and return the result
		return ( member_functionPointer == other.member_functionPointer );
	}


	template< typename ReturnValueType, typename... FunctionArgumentTypes >
	inline Boolean FunctionPointer< ReturnValueType, FunctionArgumentTypes... >::operator!=( const FunctionPointer< ReturnValueType, FunctionArgumentTypes... >& other ) const
	{
		// Return the negotiated value from the equal operator
		return ( !( *this == other ) );
	}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



    template< typename ReturnValueType, typename... FunctionArgumentTypes >
    template< UnsignedInteger64bits... ArgumentIndices >
    inline ReturnValueType FunctionPointer< ReturnValueType, FunctionArgumentTypes... >::InvokeUsingTuple__Private( const Tuple< FunctionArgumentTypes... >& arguments, IncrementingIntegerSequenceHolder< ArgumentIndices... > ) const
    {
        // Invoke the function with the given tuple of arguments
        return ( ( *member_functionPointer )( arguments.template Entry< ArgumentIndices >()... ) );
    }



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - No arguments to function   ************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



	template< typename ReturnValueType >
	inline FunctionPointer< ReturnValueType >::FunctionPointer() :
		member_functionPointer( 0UL )
	{}


	template< typename ReturnValueType >
	inline FunctionPointer< ReturnValueType >::FunctionPointer( FunctionPointerType functionMemoryAddress ) :
		member_functionPointer( functionMemoryAddress )
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	    // instance is ready to be used
		AssertPointer_MACRO( functionMemoryAddress );
	}


	template< typename ReturnValueType >
	inline FunctionPointer< ReturnValueType >::FunctionPointer( const FunctionPointer< ReturnValueType >& other ) :
		member_functionPointer( other.member_functionPointer )
	{}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



	template< typename ReturnValueType >
	ReturnValueType FunctionPointer< ReturnValueType >::operator()()
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	    // instance is ready to be used
		AssertPointer_MACRO( member_functionPointer );

		// Invoke the function, and return the return value
		return ( ( *member_functionPointer )() );
	}


	template< typename ReturnValueType >
	inline ReturnValueType FunctionPointer< ReturnValueType >::operator()() const
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	    // instance is ready to be used
		AssertPointer_MACRO( member_functionPointer );

		// Invoke the function, and return the return value
		return ( ( *member_functionPointer )() );
	}


	template< typename ReturnValueType >
	inline Boolean FunctionPointer< ReturnValueType >::operator==( const FunctionPointer< ReturnValueType >& other ) const
	{
		// Check if the instances point to the same function, and return the result
		return ( member_functionPointer == other.member_functionPointer );
	}


	template< typename ReturnValueType >
	inline Boolean FunctionPointer< ReturnValueType >::operator!=( const FunctionPointer< ReturnValueType >& other ) const
	{
		// Return the negotiated value from the equal operator
		return ( !( *this == other ) );
	}



// *********************************************************************************   TESTING   ********************************************************************************



	DEBUG_TOOL(

		template< typename ReturnValueType COMMA typename... FunctionArgumentTypes >
		void FunctionPointer< ReturnValueType COMMA FunctionArgumentTypes... >::Test()
		{
			// Create an instance
			FunctionPointer< UnsignedInteger32bits COMMA UnsignedInteger32bits COMMA UnsignedInteger64bits > testFunctionPointer_1( Testing::TestFunctions::TestFunction_1 );

			// Invoke the function
			auto returnValue_1 = testFunctionPointer_1( 8, 9 );

			// Check that the number of arguments is correct
            Assert_Test_MACRO( testFunctionPointer_1.ArgumentsNumber() == 2 );

			// Check that the return value is correct
            Assert_Test_MACRO( returnValue_1 == 9 );

			// Create an instance
			FunctionPointer< UnsignedInteger32bits COMMA UnsignedInteger32bits COMMA UnsignedInteger64bits COMMA UnsignedInteger64bits > testFunctionPointer_2( Testing::TestFunctions::TestFunction_2 );

			// Invoke the function
			returnValue_1 = testFunctionPointer_2( 8, 9, 84758 );

			// Check that the number of arguments is correct
            Assert_Test_MACRO( testFunctionPointer_2.ArgumentsNumber() == 3 );

			// Check that the return value is correct
            Assert_Test_MACRO( returnValue_1 == 99 );

            // Check for a function that doesn't has no retrun value or arguments
            FunctionPointer< void > testFunctionPointer_3( Testing::TestFunctions::TestFunction_3 );

			// Invoke the function
			testFunctionPointer_3();

			// Check that the number of arguments is correct
            Assert_Test_MACRO( testFunctionPointer_3.ArgumentsNumber() == 0 );

            // Create an instance of the tuple function pointer
	        FunctionPointer< UnsignedInteger32bits COMMA UnsignedInteger32bits COMMA UnsignedInteger64bits COMMA UnsignedInteger64bits > testFunctionPointer_4( Testing::TestFunctions::TestFunction_2 );

	        // Check that the number of arguments is correct
	        Assert_Test_MACRO( testFunctionPointer_4.ArgumentsNumber() == 3 );

	        // Invoke the function using a parameter pack
	        returnValue_1 = testFunctionPointer_4( 99, 100, 101 );

	        // Check that the return value is correct
	        Assert_Test_MACRO( returnValue_1 == 99 );

	        // Create a tuple instance
	        Tuple< UnsignedInteger32bits COMMA UnsignedInteger64bits COMMA UnsignedInteger64bits > testTuple_1( 8, 9, 84758 );

	        // Invoke the method using the tuple
	        returnValue_1 = testFunctionPointer_4( testTuple_1 );

	        // Check that the return value is correct
	        Assert_Test_MACRO( returnValue_1 == 99 );

	        // Create an instance of the tuple function pointer
	        FunctionPointer< void COMMA UnsignedInteger32bits COMMA UnsignedInteger64bits > TestFunctionPointer_5( Testing::TestFunctions::TestFunction_5 );

	        // Check that the number of arguments is correct
	        Assert_Test_MACRO( TestFunctionPointer_5.ArgumentsNumber() == 2 );

	        // Invoke the function using a parameter pack
	        TestFunctionPointer_5( 99, 100 );

	        // Create a tuple instance
	        Tuple< UnsignedInteger32bits COMMA UnsignedInteger64bits > testTuple_2( 8, 9 );

	        // Invoke the method using the tuple
	        TestFunctionPointer_5( testTuple_2 );

            // Create an instance of the tuple function pointer
	        FunctionPointer< UnsignedInteger32bits > testFunctionPointer_6( Testing::TestFunctions::TestFunction_4 );

	        // Invoke the function
	        testFunctionPointer_6();

	        // Create a variable to allow passing a reference to it to the function
	        UnsignedInteger32bits testVariable_1 = 98;

	        // Create a variable to allow passing a pointer to it to the function
	        UnsignedInteger64bits testVariable_2 = 98;

            // Create an instance of the tuple function pointer
	        FunctionPointer< void COMMA UnsignedInteger32bits* COMMA UnsignedInteger64bits* > testFunctionPointer_7( Testing::TestFunctions::TestFunction_6 );

	        // Invoke the function
	        testFunctionPointer_7( &testVariable_1, &testVariable_2 );

	        // Check that passing a reference to the variable worked
	        Assert_Test_MACRO( testVariable_1 == 888333 );
		
	        // Check that passing a pointer to the variable worked
	        Assert_Test_MACRO( testVariable_2 == 7777 );

	        // Set the variables to 0
	        testVariable_1 = 0;
	        testVariable_2 = 0UL;

	        // Create a tuple instance
	        Tuple< UnsignedInteger32bits* COMMA UnsignedInteger64bits* > testTuple_3( &testVariable_1, &testVariable_2 );

	        // Invoke the method using the tuple
	        testFunctionPointer_7( testTuple_3 );

	        // Check that passing a reference to the variable worked
	        Assert_Test_MACRO( testVariable_1 == 888333 );
		
	        // Check that passing a pointer to the variable worked
	        Assert_Test_MACRO( testVariable_2 == 7777 );
		}

	)  //  End of debug tool