//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



    template< typename IntegerType >
    inline UnsignedInteger64bits AsciiStringAndIntegers::GetNumberOfDigitsInInteger( IntegerType integer ) 
    {
    	// This will be checked during compile time to ensure the template type has all the required attributes
		CompileTimeAssert( ( TypeCheck_Integer< IntegerType >::Result() == true ), "AsciiStringAndIntegers::GetNumberOfDigitsInInteger failed - the given template type is not integer" );

		// Check if the integer has the value 0
		if ( integer == 0 )
		{
			// The integer contains the value 0

			// Return that the integer contains one digit
			return ( 1UL );
		}

        // Space for the number of digits
        UnsignedInteger64bits numberOfDigitsInTheInteger = 0UL;

        // Loop as long as the integer is not 0
        while ( integer != 0 )
        {
            // Divide the integer by 10 to strip the first digit
            integer /= 10;

            // Increase the number of digits by 1
            numberOfDigitsInTheInteger += 1UL;
        }

        // Return the number of digits in the integer
        return ( numberOfDigitsInTheInteger );
    }


    template< typename UnsignedIntegerType >
    inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_UnsignedInteger< UnsignedIntegerType >::Result() == true, UnsignedIntegerType >::Type AsciiStringAndIntegers::AsciiStringOfDigitsToInteger( const char* asciiStringOfDigits, Boolean& methodSucceededOrNot )
    {
    	// This object will store the integer
		UnsignedIntegerType integer = 0;

        // This object will store the size of the ascii string of digits, to ensure that it does not contain more digits then the unsigned integer can contain
        UnsignedInteger64bits numberOfDigits = 0UL;

        // Loop until the ascii string is exhausted
        while ( *asciiStringOfDigits != 0UL )
        {

        	// Ensure that the current entry contains an ascii value that represents a digit, and ensure that the maximum number of digits that the unsigned integer
        	// was not passed
        	if ( ( *asciiStringOfDigits < 48 ) || ( *asciiStringOfDigits > 57 ) || ( numberOfDigits > NumericLimits< UnsignedIntegerType >::MaximumNumberOfDigits() ) )
        	{
        		// An error was encountered

        		// Set the boolean to false to notify the caller of the problem
        		methodSucceededOrNot = false;

        		// Return 0
        		return ( 0 );
        	}

            // Every character in order to turn into decimal number needs to by multiplied by 10 in the power of his distance from the last element.
            // And every character needs to be subtracted by 48 to get its real value and not ascii value
            integer = integer * 10 + ( *asciiStringOfDigits - '0' );

            // Advance the pointer to the next entry
            asciiStringOfDigits += 1UL;

            // Increment the number of digits by 1
			numberOfDigits += 1UL;
        }

        // If the control of the method reached here then the it succeeded, set the boolean to true 
        methodSucceededOrNot = true;

        // Return the result integer
        return ( integer );
    }


    template< typename SignedIntegerType >
    inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_SignedInteger< SignedIntegerType >::Result() == true, SignedIntegerType >::Type AsciiStringAndIntegers::AsciiStringOfDigitsToInteger( const char* asciiStringOfDigits, Boolean& methodSucceededOrNot )
    {
    	// This object will store the integer
		SignedIntegerType integer = 0;

        // This object will store the value '-1' if the first entry contains the '-' sign
		SignedIntegerType minusOrPlusOne = 1;

		// Check if the first entry contains the ascii character '-'
        if ( *asciiStringOfDigits == '-' )
        {
        	// The ascii character '-' exist in the first entry

        	// Set to -1
			minusOrPlusOne = -1;

            // Advance the pointer to the next entry
            asciiStringOfDigits += 1UL;
        }
        else if ( *asciiStringOfDigits == '+' )
        {
        	// The ascii character '+' exist in the first entry

            // Advance the pointer to the next entry
            asciiStringOfDigits += 1UL;
        }

        // This object will store the size of the ascii string of digits, to ensure that it does not contain more digits then the signed integer can contain
        UnsignedInteger64bits numberOfDigits = 0UL;

        // Loop until the ascii string is exhausted
        while ( *asciiStringOfDigits != 0UL )
        {

        	// Ensure that the current entry contains an ascii value that represents a digit, and ensure that the maximum number of digits that the unsigned integer
        	// was not passed
        	if ( ( *asciiStringOfDigits < 48 ) || ( *asciiStringOfDigits > 57 ) || ( numberOfDigits > NumericLimits< SignedIntegerType >::MaximumNumberOfDigits() ) )
        	{
        		// An error was encountered

        		// Set the boolean to false to notify the caller of the problem
        		methodSucceededOrNot = false;

        		// Return 0
        		return ( 0 );
        	}

            // Every character in order to turn into decimal number needs to by multiplied by 10 in the power of his distance from the last element.
            // And every character needs to be subtracted by 48 to get its real value and not ascii value
            integer = integer * 10 + ( *asciiStringOfDigits - '0' );

            // Advance the pointer to the next entry
            asciiStringOfDigits += 1UL;

            // Increment the number of digits by 1
			numberOfDigits += 1UL;
        }

        // Multiply the integer by minus one if the first entry of the ascii string contained '-'
        integer *= minusOrPlusOne;

        // If the control of the method reached here then the it succeeded, set the boolean to true 
        methodSucceededOrNot = true;

        // Return the pair with the boolean to tell if the method succeeded and the result integer 
        return ( integer );
    }


    template< typename IntegerType >
    inline Boolean AsciiStringAndIntegers::IntegerToStringOfDigits( char* destinationToStoreIntegerDigits, IntegerType integer )
    {
    	// This will be checked during compile time to ensure the template type has all the required attributes
		CompileTimeAssert( ( TypeCheck_Integer< IntegerType >::Result() == true ), "AsciiStringAndIntegers::IntegerToStringOfDigits failed - the given template type is not integer" );

		// Check if the given pointer is NULL
		if ( destinationToStoreIntegerDigits == 0UL )
		{
			// The given pointer is NULL

			// Return false
			return ( false );
		}

		// Check if the integer value is 0
		if ( integer == 0 )
		{
			// The integer value is 0

			// Set the first entry with the ascii value for 0
			destinationToStoreIntegerDigits[0] = '0';

			// Nothing else needs to be done
			return ( true );
		}

		// This object will store the number digits in the integer
		UnsignedInteger64bits numberOfDigitsInInteger = GetNumberOfDigitsInInteger( integer );

		// Check if the integer is negative
		if ( integer < 0 )
		{
			// The integer is negative

			// Set the first entry with the ascii value for '-'
			destinationToStoreIntegerDigits[0] = '-';

			// Set the integer to the absolue value by multiplying with -1
			integer *= -1;

			// Increase the location of the last digit by 1 to account for the additional '-' character
			numberOfDigitsInInteger += 1UL;
		}

        // Loop on all the digits of the integer
        for ( UnsignedInteger64bits digitsAsciiStringIndex = ( numberOfDigitsInInteger - 1UL ) ; integer != 0 ; --digitsAsciiStringIndex )
        {
            // Set the string with the current digit by adding '0' to make it the ascii value
            destinationToStoreIntegerDigits[ digitsAsciiStringIndex ] = ( ( integer % 10 ) + '0' );

            // Divide the integer by 10
            integer /= 10;
        }

        // Set the end of the ascii string to NULL
        destinationToStoreIntegerDigits[ numberOfDigitsInInteger ] = 0;

        // The method was successful
        return ( true );
    }
