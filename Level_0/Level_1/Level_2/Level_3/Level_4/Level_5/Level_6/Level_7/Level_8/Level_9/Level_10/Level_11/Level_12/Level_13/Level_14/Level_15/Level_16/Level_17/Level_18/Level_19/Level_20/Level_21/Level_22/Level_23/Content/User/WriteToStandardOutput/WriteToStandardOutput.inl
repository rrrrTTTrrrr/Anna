//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline WriteToStandardOutput::WriteToStandardOutput()
{}


template< Concepts::BuiltIn BuiltInType >
inline const WriteToStandardOutput& WriteToStandardOutput::Bits( const BuiltInType value ) const
{
    // This object will be used to address the bytes of the value
    const UnsignedInteger8bits* const bytePointer = reinterpret_cast< const UnsignedInteger8bits* >( &value );

    // This object will store the current bit state
   	Boolean bitState = false;

    // Loop on all the bytes
    for ( LargestUnsignedInteger byteIndex = 0UL ; byteIndex < sizeof( BuiltInType ) ; ++byteIndex )
    {
        // Loop on all the bits
        for ( SignedInteger8bits bitIndex = 7 ; bitIndex > -1 ; --bitIndex )
        {
            // Check if the bit state is on or off, and display '1' or '0' accordingly
            bitState = bytePointer[ byteIndex ] & ( 1 << bitIndex );

            // Check if the bit is on or not
	        if ( bitState == 1 ) 
	        {
	            // The bit is on

	            // Display - '1'
	            *this << 1 << " ";
	        }
	        else
	        {
	            // The bit is off, everybody home

	            // Display - '0'
	            *this << 0 << " ";
	        }
        }

        // Create spaces between bytes
		MoveCursorLineDown__Private();

        // Check if the dividend divides by the divisor with no remainder
        if ( ( ( byteIndex + 1 ) % 8 ) == 0UL )
        {
            // The dividend divides by the divisor with no remainder

			// Move the cursor on the screen one line down
			MoveCursorLineDown__Private();
        }   
    }

	// Return a reference to this insance, to allow chaining calls
	return ( *this );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< Concepts::ConvertibleToString ConvertibleToStringType > requires ( !Concepts::SameAs< ConvertibleToStringType, AsciiCharacter* > )
inline const WriteToStandardOutput& WriteToStandardOutput::operator<<( const ConvertibleToStringType& value ) const
{
	// Convert the value from binary to decimal
	const Language::String valueAsString( value );

	// Convert the string from unicode to ascii
	const Memory::Vector< AsciiCharacter, Memory::MainMemoryManager > valueAsAsciiString = valueAsString.ToAsciiString();

	// Write the content of the copy to standard output
	Assert( Linux::SystemCalls::Write( 1U, valueAsAsciiString.DataPointer(), valueAsAsciiString.Size() ) == ( valueAsString.Size() + 1UL ), "Failed to write to standard output" );

	// Move the cursor one line down
	MoveCursorLineDown__Private();

	// Return a reference to this insance, to allow chaining calls
	return ( *this );
}


inline const WriteToStandardOutput& WriteToStandardOutput::operator<<( const Boolean value ) const
{
	// Check if the value is true
	if ( value == true )
	{
		// The value is true

		// Write the content of the copy to standard output
		Assert( Linux::SystemCalls::Write( 1U, "true", 4UL ) == 4UL, "Failed to write to standard output" );
	}
	else
	{
		// The value is false

		// Write the content of the copy to standard output
		Assert( Linux::SystemCalls::Write( 1U, "false", 5UL ) == 5UL, "Failed to write to standard output" );
	}

	// Move the cursor one line down
	MoveCursorLineDown__Private();

	// Return a reference to this insance, to allow chaining calls
	return ( *this );
}


inline const WriteToStandardOutput& WriteToStandardOutput::operator<<( const AsciiCharacter* const asciiLiteral ) const
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertPointerIsNotNull( asciiLiteral );

	// Calculate the ascii literal size
	const LargestUnsignedInteger asciiLiteralSize = AsciiStringSize( asciiLiteral );

	// Assert that the size of the ascii literal is larger then 0
	AssertValueIsLargerThenZero( asciiLiteralSize );

	// Write the content of the copy to standard output
	Assert( Linux::SystemCalls::Write( 1U, asciiLiteral, asciiLiteralSize ) == asciiLiteralSize, "Failed to write to standard output" );

	// Move the cursor one line down
	MoveCursorLineDown__Private();

	// Return a reference to this insance, to allow chaining calls
	return ( *this );
}


inline const WriteToStandardOutput& WriteToStandardOutput::operator<<( const Language::String& string ) const
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	Assert( ( string.Language() == Language::LanguageName::English ), "The language must be english, it is the only one currently supported" );

	// Check if the string is empty
	if ( string.Size() == 0UL )
	{
		// The string is empty, display it to the user
		Assert( Linux::SystemCalls::Write( 1U, "EMPTY STRING", 12UL ) == 12UL, "Failed to write to standard output" );

		// Move the cursor one line down
		MoveCursorLineDown__Private();

		// Return a reference to this insance, to allow chaining calls
		return ( *this );
	}

	// Convert the string from unicode to ascii
	Memory::Vector< AsciiCharacter, Memory::MainMemoryManager > asciiString = string.ToAsciiString();

	// Write the content of the copy to standard output
	Assert( Linux::SystemCalls::Write( 1U, asciiString.DataPointer(), asciiString.Size() ) == ( string.Size() + 1UL ), "Failed to write to standard output" );

	// Move the cursor one line down
	MoveCursorLineDown__Private();

	// Return a reference to this insance, to allow chaining calls
	return ( *this );
}


inline const WriteToStandardOutput& WriteToStandardOutput::operator<<( const SequentialDataStructure< Language::String >& strings ) const
{
	// This object will store the number of string to display
	const LargestUnsignedInteger numberOfStrings = strings.Size();

	// Check if the number of strings is zero
	if ( numberOfStrings == 0UL )
	{
		// The number of strings is zero, display it to the user
		Assert( Linux::SystemCalls::Write( 1U, "EMPTY CONTAINER", 15UL ) == 15UL, "Failed to write to standard output" );

		// Move the cursor one line down
		MoveCursorLineDown__Private();

		// Return a reference to this insance, to allow chaining calls
		return ( *this );
	}

	// Loop on all the entries of the string
	for ( LargestUnsignedInteger index = 0UL ; index < numberOfStrings ; ++index )
	{
		// Display the current string
		*this << strings[ index ];

        // Move the display one line down for better readability
		MoveCursorLineDown__Private();
	}

	// Return a reference to this insance, to allow chaining calls
	return ( *this );
}


template< Concepts::ConvertibleToString ConvertibleToStringType >
inline const WriteToStandardOutput& WriteToStandardOutput::operator<<( const SequentialDataStructure< ConvertibleToStringType >& contentToDisplay ) const
{
	// This object will store the results of converting the built in data content of the sequential data structure in decimal format
	Language::String valuesAsString;

	// Loop on all the entries of the sequential data structure
	for ( LargestUnsignedInteger index = 0UL ; index < contentToDisplay.Size() ; ++index )
	{
		// Convert the current entry from binary to decimal format, and add it
	 	valuesAsString += Language::String( contentToDisplay[ index ] );

		// Display to the user every 8 entries in a line, for that check if the index is no zero, and that there is no remainder from 
		// dividing the index by 8
		if ( index % 8UL == 7UL )
		{
			// Display the content to the user
			*this << valuesAsString;

			// Clear all the current line content from the sequential data structure
		 	valuesAsString.Reset();

 	        // Move the display one line down for better readability
			MoveCursorLineDown__Private();

			// Advance to the next iteration
			continue;
		}

		// Add space between this entry and the next one
		valuesAsString.InsertSingleElement( valuesAsString.Size(), Language::Character( ' ' ) );
	}

	// Check if the size of the sequential data structure divided by 8 has a remainder, which means that the another line needs to be written to the screen
	if ( contentToDisplay.Size() % 8UL != 0UL )
	{
		// Display the content to the user
		*this << valuesAsString;
	}

	// Move the cursor one line down
	MoveCursorLineDown__Private();

	// Return a reference to this insance, to allow chaining calls
	return ( *this );
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



inline const WriteToStandardOutput& WriteToStandardOutput::MoveCursorLineDown__Private() const
{
	// Move the cursor on the screen one line down
	Assert( Linux::SystemCalls::Write( 1U, "\n", 1UL ) == 1UL, "Failed to write to standard output" );

	// Return a reference to this insance, to allow chaining calls
	return ( *this );
}



}  //  Namespace User


}  //  Namespace Universe