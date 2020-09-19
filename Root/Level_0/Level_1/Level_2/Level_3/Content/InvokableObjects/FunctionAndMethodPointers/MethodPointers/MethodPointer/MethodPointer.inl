//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



	template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentTypes >
	inline MethodPointer< ObjectType, ReturnValueType, MethodArgumentTypes... >::MethodPointer() :
		member_methodPointer( 0UL )
	{}


	template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentTypes >
	inline MethodPointer< ObjectType, ReturnValueType, MethodArgumentTypes... >::MethodPointer( MethodPointerType methodMemoryAddress ) :
		member_methodPointer( methodMemoryAddress )
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	    // instance is ready to be used
		AssertPointer_MACRO( methodMemoryAddress );
	}


	template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentTypes >
	inline MethodPointer< ObjectType, ReturnValueType, MethodArgumentTypes... >::MethodPointer( const MethodPointer< ObjectType, ReturnValueType, MethodArgumentTypes... >& other ) :
		member_methodPointer( other.member_methodPointer )
	{}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



	template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentTypes >
	inline ReturnValueType MethodPointer< ObjectType, ReturnValueType, MethodArgumentTypes... >::operator()( ObjectType& instance, MethodArgumentTypes... arguments ) const
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	    // instance is ready to be used
		AssertPointer_MACRO( member_methodPointer );

		// Invoke the method using the arguments on the instance of the object that contains the method, and return value
		return ( ( instance.*member_methodPointer )( arguments... ) );
	}


    template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentTypes >
    inline ReturnValueType MethodPointer< ObjectType, ReturnValueType, MethodArgumentTypes... >::operator()( ObjectType& instance, const Tuple< MethodArgumentTypes... >& arguments ) const
    {
	    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	    // instance is ready to be used
		AssertPointer_MACRO( member_methodPointer );

        // Set the return value from invoking the function with the tuple of arguments, and return the value
        return ( InvokeUsingTuple__Private( instance, arguments, IncrementingIntegerSequence< sizeof...( MethodArgumentTypes ) >{} ) );
    }


	template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentTypes >
	inline Boolean MethodPointer< ObjectType, ReturnValueType, MethodArgumentTypes... >::operator==( const MethodPointer< ObjectType, ReturnValueType, MethodArgumentTypes... >& other ) const
	{
		// Check if the instances point to the same function, and return the result
		return ( member_methodPointer == other.member_methodPointer );
	}


	template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentTypes >
	inline Boolean MethodPointer< ObjectType, ReturnValueType, MethodArgumentTypes... >::operator!=( const MethodPointer< ObjectType, ReturnValueType, MethodArgumentTypes... >& other ) const
	{
		// Return the negotiated value from the equal operator
		return ( !( *this == other ) );
	}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



    template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentTypes >
    template< UnsignedInteger64bits... ArgumentIndices >
    inline ReturnValueType MethodPointer< ObjectType, ReturnValueType, MethodArgumentTypes... >::InvokeUsingTuple__Private( ObjectType& instance, const Tuple< MethodArgumentTypes... >& arguments, IncrementingIntegerSequenceHolder< ArgumentIndices... > ) const
    {
        // Invoke the method with the given tuple of arguments
        return ( ( instance.*member_methodPointer )( arguments.template Entry< ArgumentIndices >()... ) );
    }



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - No arguments to function   ************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



	template< typename ObjectType, typename ReturnValueType >
	inline MethodPointer< ObjectType, ReturnValueType >::MethodPointer() :
		member_methodPointer( 0UL )
	{}


	template< typename ObjectType, typename ReturnValueType >
	inline MethodPointer< ObjectType, ReturnValueType >::MethodPointer( MethodPointerType methodMemoryAddress ) :
		member_methodPointer( methodMemoryAddress )
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	    // instance is ready to be used
		AssertPointer_MACRO( methodMemoryAddress );
	}


	template< typename ObjectType, typename ReturnValueType >
	inline MethodPointer< ObjectType, ReturnValueType >::MethodPointer( const MethodPointer< ObjectType, ReturnValueType >& other ) :
		member_methodPointer( other.member_methodPointer )
	{}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



	template< typename ObjectType, typename ReturnValueType >
	inline ReturnValueType MethodPointer< ObjectType, ReturnValueType >::operator()( ObjectType& instance ) const
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	    // instance is ready to be used
		AssertPointer_MACRO( member_methodPointer );

		// Invoke the method, and return the value
		return ( ( instance.*member_methodPointer )() );
	}


	template< typename ObjectType, typename ReturnValueType >
	inline Boolean MethodPointer< ObjectType, ReturnValueType >::operator==( const MethodPointer< ObjectType, ReturnValueType >& other ) const
	{
		// Check if the instances point to the same function, and return the result
		return ( member_methodPointer == other.member_methodPointer );
	}


	template< typename ObjectType, typename ReturnValueType >
	inline Boolean MethodPointer< ObjectType, ReturnValueType >::operator!=( const MethodPointer< ObjectType, ReturnValueType >& other ) const
	{
		// Return the negotiated value from the equal operator
		return ( !( *this == other ) );
	}



// *********************************************************************************   TESTING   ********************************************************************************



	DEBUG_TOOL(

		template< typename ObjectType COMMA typename ReturnValueType COMMA typename... MethodArgumentTypes >
		void MethodPointer< ObjectType COMMA ReturnValueType COMMA MethodArgumentTypes... >::Test()
		{
			// Create a test instance 
			Testing::TestObject_2 testObject_1( 654, 56 );

			// Create an instance
			MethodPointer< Testing::TestObject_2 COMMA UnsignedInteger32bits COMMA UnsignedInteger32bits COMMA UnsignedInteger64bits > testMethodPointer_1( &Testing::TestObject_2::TestMethod_1 );

			// Invoke the method
			testMethodPointer_1( testObject_1, 8, 9 );

			// Check that the number of arguments is correct
            Assert_Test_MACRO( testMethodPointer_1.ArgumentsNumber() == 2 );

			// Check that there is return value
            Assert_Test_MACRO( testMethodPointer_1.ReturnValueExist() == true );

			// Create an instance
			MethodPointer< Testing::TestObject_2 COMMA UnsignedInteger32bits COMMA UnsignedInteger32bits COMMA UnsignedInteger64bits COMMA UnsignedInteger64bits > testMethodPointer_2( &Testing::TestObject_2::TestMethod_2 );

			// Invoke the method
			auto testReturnValue_1 = testMethodPointer_2( testObject_1, 8, 9, 84758 );

			// Check that the number of arguments is correct
            Assert_Test_MACRO( testMethodPointer_2.ArgumentsNumber() == 3 );

			// Check that the return value is correct
            Assert_Test_MACRO( testReturnValue_1 == 99 );

            // Check for a function that doesn't has no retrun value or arguments
            MethodPointer< Testing::TestObject_2 COMMA void > testMethodPointer_3( &Testing::TestObject_2::TestMethod_3 );

			// Invoke the method
			testMethodPointer_3( testObject_1 );

			// Check that the number of arguments is correct
            Assert_Test_MACRO( testMethodPointer_3.ArgumentsNumber() == 0 );

            // Create an instance of the tuple function pointer
	        MethodPointer< Testing::TestObject_2 COMMA UnsignedInteger32bits COMMA UnsignedInteger32bits COMMA UnsignedInteger64bits COMMA UnsignedInteger64bits > testMethodPointer_4( &Testing::TestObject_2::TestMethod_2 );

	        // Check that the number of arguments is correct
	        Assert_Test_MACRO( testMethodPointer_4.ArgumentsNumber() == 3 );

	        // Invoke the method using a parameter pack
	        auto testReturnValue_2 = testMethodPointer_4( testObject_1, 99, 100, 101 );

	        // Check that the return value is correct
	        Assert_Test_MACRO( testReturnValue_2 == 99 );

	        // Create a tuple instance
	        Tuple< UnsignedInteger32bits COMMA UnsignedInteger64bits COMMA UnsignedInteger64bits > testTuple_1( 8, 9, 84758 );

	        // Invoke the method using the tuple
	        auto testReturnValue_3 = testMethodPointer_4( testObject_1, testTuple_1 );

	        // Check that the return value is correct
	        Assert_Test_MACRO( testReturnValue_3 == 99 );

	        // Create an instance of the tuple function pointer
	        MethodPointer< Testing::TestObject_2 COMMA void COMMA UnsignedInteger32bits COMMA UnsignedInteger64bits > TestMethodPointer_5( &Testing::TestObject_2::TestMethod_5 );

	        // Check that the number of arguments is correct
	        Assert_Test_MACRO( TestMethodPointer_5.ArgumentsNumber() == 2 );

	        // Invoke the method using a parameter pack
	        TestMethodPointer_5( testObject_1, 99, 100 );

	        // Create a tuple instance
	        Tuple< UnsignedInteger32bits COMMA UnsignedInteger64bits > testTuple_2( 8, 9 );

	        // Invoke the method using the tuple
	        TestMethodPointer_5( testObject_1, testTuple_2 );

            // Create an instance of the tuple function pointer
	        MethodPointer< Testing::TestObject_2 COMMA UnsignedInteger32bits > testMethodPointer_6( &Testing::TestObject_2::TestMethod_4 );

	        // Invoke the method
	        testMethodPointer_6( testObject_1 );
		}

	)  //  End of debug tool