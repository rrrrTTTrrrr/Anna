//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



template< typename ExceptionType >
inline void Assert< ExceptionType >::True( const Boolean expressionResult, const AsciiCharacter* const fileName, const AsciiCharacter* const functionName, const SignedInteger32bits lineNumber, const AsciiCharacter* const errorMessage )
{
    // Assert that the expression result is true, and if not throw an exception
    if ( expressionResult == false )
    {
        throw( ExceptionType( fileName, functionName, lineNumber, errorMessage ) );
    }
}


template< typename ExceptionType >
template< typename AnyType >
inline AnyType Assert< ExceptionType >::AssignOnlyIfTrue( AnyType instanceToAssignInCaseAssertionPassed, const Boolean expressionResult, const AsciiCharacter* const fileName, const AsciiCharacter* const functionName, const SignedInteger32bits lineNumber, const AsciiCharacter* const errorMessage )
{
    // Assert that the expression result is true, and if not throw an exception
    if ( expressionResult == false )
    {
        throw( ExceptionType( fileName, functionName, lineNumber, errorMessage ) );
    }

    // The expression result is true, return the instance
    return ( ForwardUniversalReference< AnyType >( instanceToAssignInCaseAssertionPassed ) );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< typename ExceptionType >
	void Assert< ExceptionType >::UnitTest()
	{
		// Create a test pointer
		Boolean* pointer = nullptr;

        // This boolean will be used to ensure an exception was thrown
        Boolean wasExceptionThrown = false;

        try
        {
            // Throw an exception
            AssertPointerIsNotNull( pointer );
        }
        catch ( const Exception& exception )
        {
            wasExceptionThrown = true;
        }

        // Assert that an exception was thrown
        if ( wasExceptionThrown == false )
        {
            ThrowException( "Test failed - 1" );
        }

        // Set the variable to false again for the next testing
        wasExceptionThrown = false;

        try
        {
            // Throw an exception
            Assert( false, "Fuckkkkkkkkk" );
        }
        catch ( const Exception& exception )
        {
            wasExceptionThrown = true;
        }

        // Assert that an exception was thrown
        if ( wasExceptionThrown == false )
        {
            ThrowException( "Test failed - 2" );
        }

        // Set the variable to false again for the next testing
        wasExceptionThrown = false;

        // This variable will be assigned in case the expression is true
        UnsignedInteger64bits variableToAssign = 0UL;

        try
        {
            // Throw an exception
            variableToAssign = AssignOnlyIfAssertionPassed( 8UL, false, "Fuckkkkkkkkk" );
        }
        catch ( const Exception& exception )
        {
            wasExceptionThrown = true;
        }

        // Assert that an exception was thrown
        if ( ( wasExceptionThrown == false ) || ( variableToAssign == 8UL ) )
        {
            ThrowException( "Test failed - 3" );
        }

        // Set the variable to false again for the next testing
        wasExceptionThrown = false;

        try
        {
            // Throw an exception
            variableToAssign = AssignOnlyIfAssertionPassed( 8UL, true, "Fuckkkkkkkkk" );
        }
        catch ( const Exception& exception )
        {
            wasExceptionThrown = true;
        }

        // Assert that an exception was thrown
        if ( ( wasExceptionThrown == true ) || ( variableToAssign != 8UL ) )
        {
            ThrowException( "Test failed - 4" );
        }

        // Set the variable to false again for the next testing
        wasExceptionThrown = false;

        // This pointer will be assigned in case the expression is true
        UnsignedInteger64bits* testPointer = nullptr;

        try
        {
            // Throw an exception
            testPointer = AssignOnlyIfAssertionPassed( &variableToAssign, true, "Fuckkkkkkkkk" );
        }
        catch ( const Exception& exception )
        {
            wasExceptionThrown = true;
        }

        // Assert that an exception was thrown
        if ( ( wasExceptionThrown == true ) || ( testPointer != &variableToAssign ) )
        {
            ThrowException( "Test failed - 5" );
        }
	}

)  //  End of debug tool



}  //  Namespace Error


}  //  Namespace Universe