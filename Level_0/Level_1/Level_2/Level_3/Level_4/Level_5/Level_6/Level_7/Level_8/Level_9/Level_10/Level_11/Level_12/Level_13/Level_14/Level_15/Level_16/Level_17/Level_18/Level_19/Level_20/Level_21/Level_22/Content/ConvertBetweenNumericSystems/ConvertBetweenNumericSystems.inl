//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



template< Concepts::Integer IntegerReturnType >
EnsureRetrunValueIsUsed inline IntegerReturnType ConvertBetweenNumericSystems::HexadecimalToBinary( const Language::String& hexadecimal )
{
	// This object will act as a lookup table to convert from hexadecimal character into the decimal value. The only relevant characters are
	// all the digits '0-9' and the letters in lower and capital form 'a-e' and 'A-E'. For all the rest a value of zero will be stored
	// in the location 
	static const UnsignedInteger8bits convertFromHexadecimalCharacterToDecimalValue[104] = { 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
																					         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
																					         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
																					         0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  0,  0,  0,  0,  0,
																					         0, 10, 11, 12, 13, 14, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,
																					         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
																					         0,  0, 10, 11, 12, 13, 14, 15 };

	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsNotZero( hexadecimal.Size() );
	Assert( ( ( hexadecimal[0] == 'L' || hexadecimal[0] == 'B' ) && ( hexadecimal[1] == '0' ) && ( hexadecimal[2] == 'x' ) ), "The given hexadecimal does not start with the required \'L0x\' or \'B0x\'" );

    // This object will store the binary representation of the value
    IntegerReturnType binary = 0;

    // This pointer will be used to point to the binary representation
    UnsignedInteger8bits* binaryBytePointer= reinterpret_cast< UnsignedInteger8bits* >( &binary );

    // This byte will be stored temporarly the binary representation of the two hexadecimal characters
    UnsignedInteger8bits byte = 0;

    // Loop on all the bytes starting from the fourth byte right after the "L0x" or "B0x"
    for ( LargestUnsignedInteger index = 3UL ; index < hexadecimal.Size() ; index += 2UL )
    {
    	// Assert that the current and next hexadecimal characters are either digits or legal letters
    	Assert( ( hexadecimal[ index ].IsDigit() == true ) || ( hexadecimal[ index ].IsEnglishLetter() == true ), "Hxadecimal representation can only contain digits or letters between A to F" );
        Assert( ( hexadecimal[ index + 1UL ].IsDigit() == true ) || ( hexadecimal[ index + 1UL ].IsEnglishLetter() == true ), "Hxadecimal representation can only contain digits or letters between A to F" );

    	// The hexadecimal represent the state of the bits

    	// The hexadecimal character will be used as index to the lookup table, and the resulting value will be stored in the lower 
    	// significant 4 bits of the byte
		byte = convertFromHexadecimalCharacterToDecimalValue[ static_cast< UnsignedInteger8bits >( hexadecimal[ index ].GetAsAsciiCharacter() ) ];

		// Left shift the bits of the byte 4 times, to move the lower significant 4 bits to the 4 most significant bits
		byte <<= 4;

    	// The hexadecimal character will be used as index to the lookup table, and the resulting value will be stored in the lower
    	// significant 4 bits of the byte
		byte |= convertFromHexadecimalCharacterToDecimalValue[ static_cast< UnsignedInteger8bits >( hexadecimal[ index + 1UL ].GetAsAsciiCharacter() ) ];

		// Store the processed byte, into the binary representation
		*binaryBytePointer = byte;

		// Advance the pointer to the next byte of the binary representation
		binaryBytePointer += 1UL;
    }

    // Return the number in binary representation
    return ( binary );
}


template< Concepts::Integer IntegerType >
EnsureRetrunValueIsUsed inline Language::String ConvertBetweenNumericSystems::BinaryToHexadecimal( const IntegerType binary, const MemoryHandlerName memoryHandlerName )
{
    // This object will store the transformation from the state of the 4 bits to the hexadecimal representation ( 0111 -> '7' )
    static const AsciiCharacter convertBetween4BitsStateToHexadecimal[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

    // Create a sequential data structure instance to contain the number in hexadecimal system
    Language::String hexadecimal( memoryHandlerName, ( ( sizeof( IntegerType ) * 2UL ) + 3UL ), Language::Character( 0U ) );

    // The hexadecimal convention prefix "0x" needs to be set

    // Set the first byte to "L" or "B" according to the endian encoding of the system
    if constexpr ( IsLittleEndian() == true )
    {
        // Little endian
        hexadecimal[0] = 'L';
    }
    else
    {
        // Big endian
        hexadecimal[0] = 'B';
    }

    // Set the second byte to "0"
    hexadecimal[1] = '0';

    // Set the third byte to "x"
    hexadecimal[2] = 'x';

    // Create an object to store the number of bytes used by the binary
    const UnsignedInteger16bits binaryNumberOfBytes = sizeof( IntegerType );

    // Create an object to point to the bytes of the binary
    const UnsignedInteger8bits* binaryBytePointer = reinterpret_cast< const UnsignedInteger8bits* >( &binary );

    // Create an object to store the current byte to be set in hexadecimal
    LargestUnsignedInteger hexadecimalIndex = 3UL;

    // Loop on all the bytes of the given object
    for ( UnsignedInteger16bits binaryByteIndex = 0 ; binaryByteIndex < binaryNumberOfBytes ; ++binaryByteIndex )
    {
        // First the 4 lower significant bits are handled. Set all the higher significant 4 bits to 0, and use the result as an index into
        // the lookup array that transform between the 4 bits state and the hexadecimal representation
        hexadecimal[ hexadecimalIndex + 1 ] = convertBetween4BitsStateToHexadecimal[ ( binaryBytePointer[ binaryByteIndex ] & static_cast< UnsignedInteger8bits >( 0x0F ) ) ];

        // Now the 4 higher significant bits. Right shift 4 times the byte, now the required bits are in the required location.
        // Use the result as an index into the lookup array that transoform between the 4 bits state and the hexadecimal representation
        hexadecimal[ hexadecimalIndex ] = convertBetween4BitsStateToHexadecimal[ ( binaryBytePointer[ binaryByteIndex ] >> 4 ) ];

        // Increase the hexadecimal index by 1
        hexadecimalIndex += 2UL;
    }

    // Return the number in hexadecimal representation
    return ( hexadecimal );
}


template< Concepts::Integer IntegerReturnType >
EnsureRetrunValueIsUsed inline IntegerReturnType ConvertBetweenNumericSystems::DecimalToBinary( const Language::String& decimal )
{
	// This object will act as a lookup table to convert from decimal digit into the decimal value. The only relevant characters are
	// all the digits '0-9'. For all the rest a value of zero will be stored in the location 
	static const UnsignedInteger8bits convertFromDecimalDigitToDecimalValue[58] = { 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 
																		         	0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL,
																		         	0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL,
																		         	0UL, 1UL, 2UL, 3UL, 4UL, 5UL, 6UL, 7UL, 8UL, 9UL };

	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsNotZero( decimal.Size() );
	Assert( ( ( decimal[0] != '-' ) || ( IsSignedInteger< IntegerReturnType >::Result == true ) ), "The given decimal describe negative number and the template type is an unsigned integer" );

    // This object will store the binary representation of the value
    IntegerReturnType binary = 0UL;

    // This object will be used to pass on the decimal of digits
    LargestUnsignedInteger decimalIndex = 0UL;

    // Check if the first entry contains the ascii value for the sign +/-
    if ( decimal[0] == '+' || decimal[0] == '-' )
    {
    	// The first entry contains the +/- sign

    	// Increment the ascii string index by 1
    	decimalIndex = 1UL;
    }

    // This object will store the current decimal ascii character
    AsciiCharacter decimalAsciiCharacter = 0;

    // This object will store the number of characters in the decimal format
    const LargestUnsignedInteger decimalSize = decimal.Size();

    // Loop on all the decimal digits
    while ( decimalIndex < decimalSize )
    {
        // Store the current decimal ascii character
        decimalAsciiCharacter = decimal[ decimalIndex ].GetAsAsciiCharacter();

    	// Assert that the current entry contains a digit
    	AssertValueIsDigit( decimalAsciiCharacter );

        // Every character in order to turn into decimal number needs to by multiplied by 10 in the power of his distance from the last element.
        // Then use value of the current decimal digit as an index to the lookup table to convert to the decimal value
        binary = ( binary * 10 ) + convertFromDecimalDigitToDecimalValue[ static_cast< UnsignedInteger8bits >( decimalAsciiCharacter) ];

        // Increment the index by 1
        decimalIndex += 1UL;
    }

    // Check if the first entry contains the character '-'
    if ( decimal[0] == '-' )
    {
    	// The first entry contains the '-' sign

    	// Multiply the binary by -1
    	binary *= -1; 
    }

    // Return the binary representation
    return ( binary );
}


template< Concepts::Integer IntegerType >
EnsureRetrunValueIsUsed inline Language::String ConvertBetweenNumericSystems::HexadecimalToDecimal( const Language::String& hexadecimal, const MemoryHandlerName memoryHandlerName )
{
	// Convert the hexadecimal representation to binary representation
	IntegerType binary = HexadecimalToBinary< IntegerType >( hexadecimal );

	// Convert the binary representation to decimal representation, and return the result
	return ( ConsiderAsOneArgument( BinaryToDecimal< IntegerType >( binary, memoryHandlerName ) ) );
}


template< Concepts::Integer IntegerType >
EnsureRetrunValueIsUsed inline Language::String ConvertBetweenNumericSystems::DecimalToHexadecimal( const Language::String& decimal, const MemoryHandlerName memoryHandlerName )
{
	// Convert the decimal representation to binary representation
	IntegerType binary = DecimalToBinary< IntegerType >( decimal );

	// Convert the binary representation to hexadecimal representation, and return the result
	return ( ConsiderAsOneArgument( BinaryToHexadecimal< IntegerType >( binary, memoryHandlerName ) ) );
}


template< Concepts::UnsignedInteger UnsignedIntegerType >
EnsureRetrunValueIsUsed inline UnsignedIntegerType ConvertBetweenNumericSystems::BinaryCodedDecimalToBinary( const UnsignedIntegerType binaryCodedDecimal )
{
    // This object will store the binary result of the binary coded decimal
    UnsignedIntegerType decimalValue = 0;

    // This pointer will store the address of the current byte to set
    const UnsignedInteger8bits* currentBinaryCodedDecimalBytePointer = reinterpret_cast< const UnsignedInteger8bits* >( &binaryCodedDecimal );

    // Check if the system is little or big endian
    if constexpr ( IsLittleEndian() == true )
    {
        // Little endian

        // Set the pointer to the byte with high significant bits
        currentBinaryCodedDecimalBytePointer = reinterpret_cast< const UnsignedInteger8bits* >( &binaryCodedDecimal ) + sizeof( UnsignedIntegerType ) - 1UL;

        // Loop on all the bytes of the unsigned integer
        for ( LargestUnsignedInteger index = 0UL ; index < sizeof( UnsignedIntegerType ) ; ++index )
        {
            // Multiply the decimal value by 10 to move the last digit one step up, and free the first place for the next digit
            decimalValue *= 10;

            // Add the digit in the high significant bits of this byte
            decimalValue += ( ( *currentBinaryCodedDecimalBytePointer & 0xF0 ) >> 4 );

            // Multiply the decimal value by 10 to move the last digit one step up, and free the first place for the next digit
            decimalValue *= 10;

            // Add the digit in the low significant bits of this byte
            decimalValue += *currentBinaryCodedDecimalBytePointer & 0x0F;

            // Advance the pointer to the previous byte
            currentBinaryCodedDecimalBytePointer -= 1UL;
        }
    }
    else
    {
        // Bit endian

        // Set the pointer to the byte with high significant bits
        currentBinaryCodedDecimalBytePointer = reinterpret_cast< const UnsignedInteger8bits* >( &binaryCodedDecimal );

        // Loop on all the bytes of the unsigned integer
        for ( LargestUnsignedInteger index = 0UL ; index < sizeof( UnsignedIntegerType ) ; ++index )
        {
            // Multiply the decimal value by 10 to move the last digit one step up, and free the first place for the next digit
            decimalValue *= 10;

            // Add the digit in the high significant bits of this byte
            decimalValue += ( ( *currentBinaryCodedDecimalBytePointer & 0xF0 ) >> 4 );

            // Multiply the decimal value by 10 to move the last digit one step up, and free the first place for the next digit
            decimalValue *= 10;

            // Add the digit in the low significant bits of this byte
            decimalValue += *currentBinaryCodedDecimalBytePointer & 0x0F;

            // Advance the pointer to the next byte
            currentBinaryCodedDecimalBytePointer += 1UL;
        }
    }

    // Return the result
    return ( decimalValue );
}



}  //  Namespace Universe