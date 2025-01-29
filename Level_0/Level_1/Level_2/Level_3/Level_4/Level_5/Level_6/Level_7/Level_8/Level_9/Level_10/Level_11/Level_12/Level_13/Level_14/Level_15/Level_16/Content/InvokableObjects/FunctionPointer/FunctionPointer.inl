//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< typename ReturnType, typename... ArgumentTypes >
inline FunctionPointer< ReturnType ( ArgumentTypes... ) >::FunctionPointer() :
	member_functionPointer( nullptr )
{}


template< typename ReturnType, typename... ArgumentTypes >
inline FunctionPointer< ReturnType ( ArgumentTypes... ) >::FunctionPointer( FunctionPointerType const functionPointer ) :
	member_functionPointer( functionPointer )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertPointerIsNotNull( functionPointer );
}


template< typename ReturnType, typename... ArgumentTypes >
inline FunctionPointer< ReturnType ( ArgumentTypes... ) >::FunctionPointer( const FunctionPointer< ReturnType ( ArgumentTypes... ) >& other ) :
	member_functionPointer( other.member_functionPointer )
{}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< typename ReturnType, typename... ArgumentTypes >
ReturnType FunctionPointer< ReturnType ( ArgumentTypes... ) >::operator()( ArgumentTypes... arguments )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertPointerIsNotNull( member_functionPointer );

	// Invoke the function using the arguments, and return the value
	return ( ( *member_functionPointer )( ForwardUniversalReference< ArgumentTypes >( arguments )... ) );
}


template< typename ReturnType, typename... ArgumentTypes >
ReturnType FunctionPointer< ReturnType ( ArgumentTypes... ) >::operator()( ArgumentTypes... arguments ) const
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertPointerIsNotNull( member_functionPointer );

	// Invoke the function using the arguments, and return the value
	return ( ( *member_functionPointer )( ForwardUniversalReference< ArgumentTypes >( arguments )... ) );
}


template< typename ReturnType, typename... ArgumentTypes >
inline ReturnType FunctionPointer< ReturnType ( ArgumentTypes... ) >::operator()( const Memory::Tuple< ArgumentTypes... >& arguments ) const
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertPointerIsNotNull( member_functionPointer );

    // Invoke the function with the tuple of arguments, and return the value
    return ( InvokeUsingTuple__Private( arguments, IncrementingIntegerSequence< sizeof...( ArgumentTypes ) >{} ) );
}


template< typename ReturnType, typename... ArgumentTypes >
inline Boolean FunctionPointer< ReturnType ( ArgumentTypes... ) >::operator==( const FunctionPointer< ReturnType ( ArgumentTypes... ) >& other ) const
{
	// Check if the instances point to the same function, and return the result
	return ( member_functionPointer == other.member_functionPointer );
}


template< typename ReturnType, typename... ArgumentTypes >
inline Boolean FunctionPointer< ReturnType ( ArgumentTypes... ) >::operator!=( const FunctionPointer< ReturnType ( ArgumentTypes... ) >& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



template< typename ReturnType, typename... ArgumentTypes >
template< UnsignedInteger64bits... ArgumentIndices >
inline ReturnType FunctionPointer< ReturnType ( ArgumentTypes... ) >::InvokeUsingTuple__Private( const Memory::Tuple< ArgumentTypes... >& arguments, IncrementingIntegerSequenceHolder< ArgumentIndices... > ) const
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



template< typename ReturnType >
inline FunctionPointer< ReturnType () >::FunctionPointer() :
	member_functionPointer( nullptr )
{}


template< typename ReturnType >
inline FunctionPointer< ReturnType () >::FunctionPointer( FunctionPointerType const functionPointer ) :
	member_functionPointer( functionPointer )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertPointerIsNotNull( functionPointer );
}


template< typename ReturnType >
inline FunctionPointer< ReturnType () >::FunctionPointer( const FunctionPointer< ReturnType () >& other ) :
	member_functionPointer( other.member_functionPointer )
{}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< typename ReturnType >
ReturnType FunctionPointer< ReturnType () >::operator()()
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertPointerIsNotNull( member_functionPointer );

	// Invoke the function, and return the return value
	return ( ( *member_functionPointer )() );
}


template< typename ReturnType >
inline ReturnType FunctionPointer< ReturnType () >::operator()() const
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertPointerIsNotNull( member_functionPointer );

	// Invoke the function, and return the return value
	return ( ( *member_functionPointer )() );
}


template< typename ReturnType >
inline Boolean FunctionPointer< ReturnType () >::operator==( const FunctionPointer< ReturnType () >& other ) const
{
	// Check if the instances point to the same function, and return the result
	return ( member_functionPointer == other.member_functionPointer );
}


template< typename ReturnType >
inline Boolean FunctionPointer< ReturnType () >::operator!=( const FunctionPointer< ReturnType () >& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< typename ReturnType COMMA typename... ArgumentTypes >
	void FunctionPointer< ReturnType ( ArgumentTypes... ) >::UnitTest()
	{
		// Create an instance
		FunctionPointer< UnsignedInteger32bits ( UnsignedInteger32bits COMMA UnsignedInteger64bits )  > testFunctionPointer_1( Test::Functions::Function_1 );

		// Invoke the function
		auto returnValue_1 = testFunctionPointer_1( 8, 9 );

		// Check that the number of arguments is correct
        Assert_Test( testFunctionPointer_1.ArgumentsNumber() == 2 );

		// Check that the return value is correct
        Assert_Test( returnValue_1 == 9 );

		// Create an instance
		FunctionPointer< UnsignedInteger32bits ( UnsignedInteger32bits COMMA UnsignedInteger64bits COMMA UnsignedInteger64bits ) > testFunctionPointer_2( Test::Functions::Function_2 );

		// Invoke the function
		returnValue_1 = testFunctionPointer_2( 8, 9, 84758 );

		// Check that the number of arguments is correct
        Assert_Test( testFunctionPointer_2.ArgumentsNumber() == 3 );

		// Check that the return value is correct
        Assert_Test( returnValue_1 == 99 );

        // Check for a function that doesn't has no retrun value or arguments
        FunctionPointer< void () > testFunctionPointer_3( Test::Functions::Function_3 );
        FunctionPointer< void (*)() > testFunctionPointer_55( Test::Functions::Function_3 );

		// Invoke the function
		testFunctionPointer_3();

		// Check that the number of arguments is correct
        Assert_Test( testFunctionPointer_3.ArgumentsNumber() == 0 );

        // Create an instance of the tuple function pointer
        FunctionPointer< UnsignedInteger32bits ( UnsignedInteger32bits COMMA UnsignedInteger64bits COMMA UnsignedInteger64bits ) > testFunctionPointer_4( Test::Functions::Function_2 );

        // Check that the number of arguments is correct
        Assert_Test( testFunctionPointer_4.ArgumentsNumber() == 3 );

        // Invoke the function using a parameter pack
        returnValue_1 = testFunctionPointer_4( 99, 100, 101 );

        // Check that the return value is correct
        Assert_Test( returnValue_1 == 99 );

        // Create a tuple instance
        Memory::Tuple< UnsignedInteger32bits COMMA UnsignedInteger64bits COMMA UnsignedInteger64bits > testTuple_1( 8, 9, 84758 );

        // Invoke the method using the tuple
        returnValue_1 = testFunctionPointer_4( testTuple_1 );

        // Check that the return value is correct
        Assert_Test( returnValue_1 == 99 );

        // Create an instance of the tuple function pointer
        FunctionPointer< void ( UnsignedInteger32bits COMMA UnsignedInteger64bits ) > TestFunctionPointer_5( Test::Functions::Function_5 );

        // Check that the number of arguments is correct
        Assert_Test( TestFunctionPointer_5.ArgumentsNumber() == 2 );

        // Invoke the function using a parameter pack
        TestFunctionPointer_5( 99, 100 );

        // Create a tuple instance
        Memory::Tuple< UnsignedInteger32bits COMMA UnsignedInteger64bits > testTuple_2( 8, 9 );

        // Invoke the method using the tuple
        TestFunctionPointer_5( testTuple_2 );

        // Create an instance of the tuple function pointer
        FunctionPointer< UnsignedInteger32bits () > testFunctionPointer_6( Test::Functions::Function_4 );

        // Invoke the function
        testFunctionPointer_6();

        // Create a variable to allow passing a reference to it to the function
        UnsignedInteger32bits testVariable_1 = 98;

        // Create a variable to allow passing a pointer to it to the function
        UnsignedInteger64bits testVariable_2 = 98;

        // Create an instance of the tuple function pointer
        FunctionPointer< void ( UnsignedInteger32bits* COMMA UnsignedInteger64bits* ) > testFunctionPointer_7( Test::Functions::Function_6 );

        // Invoke the function
        testFunctionPointer_7( &testVariable_1, &testVariable_2 );

        // Check that passing a reference to the variable worked
        Assert_Test( testVariable_1 == 888333 );
	
        // Check that passing a pointer to the variable worked
        Assert_Test( testVariable_2 == 7777 );

        // Set the variables to 0
        testVariable_1 = 0;
        testVariable_2 = 0UL;

        // Create a tuple instance
        Memory::Tuple< UnsignedInteger32bits* COMMA UnsignedInteger64bits* > testTuple_3( &testVariable_1, &testVariable_2 );

        // Invoke the method using the tuple
        testFunctionPointer_7( testTuple_3 );

        // Check that passing a reference to the variable worked
        Assert_Test( testVariable_1 == 888333 );
	
        // Check that passing a pointer to the variable worked
        Assert_Test( testVariable_2 == 7777 );
	}

)  //  End of debug tool



}  //  Namespace Universe