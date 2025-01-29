namespace Universe
{

	namespace Error
    {



//  ************************************************************************   OPERATORS IMPLEMENTATION   ***********************************************************************



EnsureRetrunValueIsUsed bool Exception::operator==( const Exception& other ) const
{
    // Create an object to store the index on the error message
    UnsignedInteger64bits errorMessageIndex = 0;

    // Check if the 2 error messages are the same
    while ( ( member_formattedErrorMessage[ errorMessageIndex ] != 0 ) || ( other.member_formattedErrorMessage[ errorMessageIndex ] != 0 ) )
    {
        // Check if the character is the same in both of the objects
        if ( member_formattedErrorMessage[ errorMessageIndex ] != other.member_formattedErrorMessage[ errorMessageIndex ] )
        {
            // The error messages are not the same
            return ( false );
        }

        // Increase the index on the error message by 1
        errorMessageIndex += 1;
    }

    // Check the reason for the end of the loop

    // Check if both of the error messages reached the end, which means they are the same
    if ( ( member_formattedErrorMessage[ errorMessageIndex ] != 0 ) || ( other.member_formattedErrorMessage[ errorMessageIndex ] != 0 ) )
    {
        // The error messages are not the same
        return ( false );
    }

    // If control reached here then the error messages are the same
    return ( true );
}



//	********************************************************************   PRIVATE METHODS IMPLEMENTATION   *********************************************************************



template< Concepts::Integer IntegerType >
EnsureRetrunValueIsUsed LargestUnsignedInteger Exception::NumberOfDigits__Private( const IntegerType integer ) 
{
    // Check if the value is zero, then there is one digit, return 1
    ReturnValueIfExpressionIsTrue( ( integer == 0 ), 1 );

    // Store a copy of the integer
    IntegerType integerCopy = integer;

    // Space for the number of digits
    LargestUnsignedInteger numberOfDigits = 0UL;

    // Loop as long as the number is larger then 0
    while ( integerCopy != 0 )
    {
        // Divide the integer by 10 to strip the first digit
        integerCopy /= 10;

        // Increase the number of digits by 1
        numberOfDigits += 1UL;
    }

    // Return the number of digits in the integer
    return ( numberOfDigits );
}


EnsureRetrunValueIsUsed Boolean Exception::IntegerToStringOfDigits__Private( AsciiCharacter* const destinationStringPointer, const SignedInteger32bits integer )
{
    // Check if the given pointer is NULL
    if ( destinationStringPointer == nullptr )
    {
        // The given pointer is NULL

        // Return false to notify that the pointer was NULL
        return ( false );
    }

    // Check if the integer value is 0
    if ( integer == 0 )
    {
        // The integer value is 0

        // Set the first entry with the ascii value for 0
        destinationStringPointer[0] = '0';

        // Set the end of the string to NULL
        destinationStringPointer[1] = static_cast< AsciiCharacter >( 0 );

        // Nothing else needs to be done
        return ( true );
    }

    // This object will store the number digits in the integer
    LargestUnsignedInteger numberOfDigitsInInteger = NumberOfDigits__Private( integer );

    // Store a copy of the integer
    SignedInteger32bits integerCopy = integer;

    // Check if the integer is negative
    if ( integerCopy < 0 )
    {
        // The integer is negative

        // Set the first entry with the ascii value for '-'
        destinationStringPointer[0] = '-';

        // Set the integer to the absolue value by multiplying with -1
        integerCopy *= -1;

        // Increase the location of the last digit by 1 to account for the additional '-' character
        numberOfDigitsInInteger += 1UL;
    }

    // Loop on all the digits of the integer
    for ( LargestUnsignedInteger digitsAsciiStringIndex = ( numberOfDigitsInInteger - 1UL ) ; integerCopy != 0 ; --digitsAsciiStringIndex )
    {
        // Set the string with the current digit by adding '0' to make it the ascii value
        destinationStringPointer[ digitsAsciiStringIndex ] = static_cast< AsciiCharacter >( static_cast< AsciiCharacter >( integerCopy % 10 ) + '0' );

        // Divide the integer by 10
        integerCopy /= 10;
    }

    // Set the end of the string to NULL
    destinationStringPointer[ numberOfDigitsInInteger ] = static_cast< AsciiCharacter >( 0 );

    // Return that the operation was successful
    return ( true );
}


EnsureRetrunValueIsUsed Boolean Exception::CopyAsciiString__Private( const AsciiCharacter* const sourceAsciiStringPointer, AsciiCharacter* const destinationAsciiStringPointer )
{   
    // Check if any of the given pointers are NULL
    if ( ( sourceAsciiStringPointer == nullptr ) || ( destinationAsciiStringPointer == nullptr ) )
    {
        // At least one of the given pointers is NULL

        // Notify the user of the error
        return ( false );
    }

    // Create an object to store the length of the string
    LargestUnsignedInteger asciiStringSize = 0UL;

    // Store the a copy of the pointer
    const AsciiCharacter* sourceAsciiStringPointerCopy = sourceAsciiStringPointer;

    // Store the a copy of the pointer
    AsciiCharacter* destinationAsciiStringPointerCopy = destinationAsciiStringPointer;

    // Loop on the source ascii string until the null terminator is encountered
    while ( *sourceAsciiStringPointerCopy != 0 )
    {
        // Increase the error message size by 1
        asciiStringSize += 1UL;

        // Check that the string size is not larger then 1 million
        if ( asciiStringSize > 1000000UL )
        {
            // The string might be without a null terminator

            // Notify the user of the error
            return ( false );       
        }

        // Copy the current ascii character from source to destination
        *destinationAsciiStringPointerCopy = *sourceAsciiStringPointerCopy;

        // Advance the pointers to the next location
        destinationAsciiStringPointerCopy += 1UL;
        sourceAsciiStringPointerCopy += 1UL;
    }

    // The method was successful
    return ( true );
}


void Exception::FormatErrorMessage__Private( const AsciiCharacter* fileName, const AsciiCharacter* functionName, SignedInteger32bits lineNumber, const AsciiCharacter* errorMessage )
{
    // Check that the pointers to the file name and function name are not NULL
    if ( ( fileName == 0UL ) || ( functionName == 0UL ) )
    {
        // At least one of the pointers is NULL

        // Return without doing nothing
        return;
    }

    // This object will store the line number digits as a string
    AsciiCharacter lineNumberAsString[64] = {0};

    // Convert the line number integer into a string of digits, and check if the operation succeeded
    if ( IntegerToStringOfDigits__Private( lineNumberAsString, lineNumber ) == false )
    {
        // Failed to calculate the integer digits
        return;        
    }

    // Calculate the size of the given ascii strings
    UnsignedInteger64bits fileNameSize = AsciiStringSize( fileName );
    UnsignedInteger64bits functionNameSize = AsciiStringSize( functionName );
    UnsignedInteger64bits lineNumberSize = AsciiStringSize( lineNumberAsString );

    // Copy the file name to the beginning of the error message, and check if the operation succeeded
    if ( CopyAsciiString__Private( fileName, member_formattedErrorMessage ) == false )
    {
        // Copying the ascii string failed
        return;
    }

    // Add the charcters ' : ' after the file name
    member_formattedErrorMessage[ fileNameSize ] = ' ';
    member_formattedErrorMessage[ fileNameSize + 1UL ] = ':';
    member_formattedErrorMessage[ fileNameSize + 2UL ] = ' ';

    // Next copy the function name into the error message, and check if the operation succeeded
    if ( CopyAsciiString__Private( functionName, ( member_formattedErrorMessage + fileNameSize + 3UL ) ) == false )
    {
        // Copying the ascii string failed
        return;
    }

    // Add the charcters ' : ' after the function name
    member_formattedErrorMessage[ fileNameSize + functionNameSize + 3UL ] = ' ';
    member_formattedErrorMessage[ fileNameSize + functionNameSize + 4UL ] = ':';
    member_formattedErrorMessage[ fileNameSize + functionNameSize + 5UL ] = ' ';

    // Next copy the line number into the error message, and check if the operation succeeded
    if ( CopyAsciiString__Private( lineNumberAsString, ( member_formattedErrorMessage + fileNameSize + functionNameSize + 6UL ) ) == false )
    {
        // Copying the ascii string failed
        return;
    }

    // Add the charcters ' - ' after the line number
    member_formattedErrorMessage[ fileNameSize + functionNameSize + lineNumberSize + 6UL ] = ' ';
    member_formattedErrorMessage[ fileNameSize + functionNameSize + lineNumberSize + 7UL ] = '-';
    member_formattedErrorMessage[ fileNameSize + functionNameSize + lineNumberSize + 8UL ] = ' ';
    
    // Verify that the pointer to the user error message is not NULL
    if ( errorMessage == 0UL )
    {
        // The given pointer is NULL 

        // Set that there is no error message, and check if the operation succeeded
        if ( CopyAsciiString__Private( "No error message was provided", ( member_formattedErrorMessage + fileNameSize + functionNameSize + lineNumberSize + 9UL ) ) == false )
        {
            // Copying the ascii string failed
            return;
        }
    }
    else
    {
        // There is a user error message

        // Add user error message, and check if the operation succeeded
        if ( CopyAsciiString__Private( errorMessage, ( member_formattedErrorMessage + fileNameSize + functionNameSize + lineNumberSize + 9UL ) ) == false )
        {
            // Copying the ascii string failed
            return;
        }
    }
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	void Exception::UnitTest()
	{
        // Check the method that calculates the number of digits
        auto testResult = NumberOfDigits__Private< UnsignedInteger64bits >( 56UL );
        testResult = NumberOfDigits__Private< UnsignedInteger64bits >( 561UL );
        testResult = NumberOfDigits__Private< UnsignedInteger64bits >( 5621UL );
        testResult = NumberOfDigits__Private< UnsignedInteger64bits >( 56321UL );
        testResult = NumberOfDigits__Private< UnsignedInteger64bits >( 564321UL );
        testResult = NumberOfDigits__Private< UnsignedInteger64bits >( 5654321UL );
        testResult = NumberOfDigits__Private< UnsignedInteger64bits >( 56654321UL );
        testResult = NumberOfDigits__Private< UnsignedInteger64bits >( 567654313UL );
        testResult = NumberOfDigits__Private< UnsignedInteger64bits >( 897 );
        testResult = NumberOfDigits__Private< UnsignedInteger64bits >( 8298239 );
        testResult = NumberOfDigits__Private< UnsignedInteger64bits >( 838398309 );
        testResult = NumberOfDigits__Private< UnsignedInteger64bits >( 8 );
        testResult = NumberOfDigits__Private< UnsignedInteger64bits >( 0 );
        testResult = NumberOfDigits__Private< UnsignedInteger64bits >( 3422 );
        testResult = NumberOfDigits__Private< UnsignedInteger64bits >( 89754 );
        testResult = NumberOfDigits__Private< UnsignedInteger64bits >( 987589392 );
        testResult = NumberOfDigits__Private< SignedInteger64bits >( -897 );
        testResult = NumberOfDigits__Private< SignedInteger64bits >( -8298239 );
        testResult = NumberOfDigits__Private< SignedInteger64bits >( -838398309 );
        testResult = NumberOfDigits__Private< SignedInteger64bits >( -8 );
        testResult = NumberOfDigits__Private< SignedInteger64bits >( -0 );
        testResult = NumberOfDigits__Private< SignedInteger64bits >( -3422 );
        testResult = NumberOfDigits__Private< SignedInteger64bits >( -89754 );
        testResult = NumberOfDigits__Private< SignedInteger64bits >( -987589392 );
        testResult += 1;

        // Create an instance using the default constructor
        Exception testException_1( __FILE__, __FUNCTION__, __LINE__, "Wow this week was harddddd!!!!!!" );

        // Throw the exception and catch it
        try
        {
            throw( testException_1 );
        }
        catch ( const Exception& exception )
        {}

        // Create an instance
        Exception testException_2( __FILE__, __FUNCTION__, __LINE__, "Wow this week was harddddd!!!!!!" );

        // Throw the exception and catch it
        try
        {
            throw( testException_2 );
        }
        catch ( const Exception& exception )
        {}
	}

)  //  End of debug tool



	}  //  Namespace Error


}  //  Namespace Universe