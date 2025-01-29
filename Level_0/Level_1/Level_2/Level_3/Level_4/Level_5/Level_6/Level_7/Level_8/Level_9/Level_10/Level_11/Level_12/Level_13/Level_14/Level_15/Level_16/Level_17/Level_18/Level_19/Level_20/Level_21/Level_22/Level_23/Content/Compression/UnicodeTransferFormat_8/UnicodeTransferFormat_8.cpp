namespace Universe 
{


namespace Compression
{



//	********************************************************************   PRIVATE METHODS IMPLEMENTATION   *********************************************************************



LargestUnsignedInteger UnicodeTransferFormat_8::GetNumberOfBytesRequiredToStoreCompressedCharacter__Private( const Language::Character& character )
{
    // If the value is between 0 - 127, 1 byte is required
    if ( character < 128U )
    {
    	// 1 byte is required
    	return ( 1UL );
    }
    // If the value is between 128 - 2047, 2 bytes are required
    else if ( ( character >= 128U ) && ( character < 2048U ) )
    {
    	// 2 bytes are required
    	return ( 2UL );
    }
    // If the value is between 2048 - 65535, 3 bytes are required
    else if ( ( character >= 2048U ) && ( character < 65536U ) )
    {
    	// 3 bytes are required
    	return ( 3UL );
    }

    // The value is between 65535 - 1114111, 4 bytes are required
	return ( 4UL );
}


LargestUnsignedInteger UnicodeTransferFormat_8::GetNumberOfBytesRequiredToStoreCompressedString__Private( const Language::String& string, const LargestUnsignedInteger sizeFromStringToCompress, const LargestUnsignedInteger startCompressingFromThisIndexOnString )
{
	// This object will store the number of bytes required to store the compressed string
	LargestUnsignedInteger numberOfBytesRequiredToStoreCompressedString = 0UL;

	// This object will store the value of the entry after the last entry in the string that needs to be processed
	const LargestUnsignedInteger stopLoopAtThisIndex = startCompressingFromThisIndexOnString + sizeFromStringToCompress;

	// Loop on all the required entries of the string
	for ( LargestUnsignedInteger index = startCompressingFromThisIndexOnString ; index < stopLoopAtThisIndex ; ++index )
	{
		// Assert that the current character value is within the valid range
    	AssertValueIsBelowCertainLimit( string[ index ], 1114111U );

		// Get the number of bytes required to store the current character compressed, and it to the total size
		numberOfBytesRequiredToStoreCompressedString += GetNumberOfBytesRequiredToStoreCompressedCharacter__Private( string[ index ] );
	}

	// Return the number of bytes required to store the compressed string
	return ( numberOfBytesRequiredToStoreCompressedString );
}


void UnicodeTransferFormat_8::SetTemplate__Private( UnsignedInteger8bits* const destinationToSetTemplate, const LargestUnsignedInteger numberOfBytesRequiredToStoreCompressedCharacter )
{
    // Check if 1 bytes are required, set the matching pattern
    if ( numberOfBytesRequiredToStoreCompressedCharacter == 1UL )
    {
        // If only 1 byte is required, nothing needs to be done further
        return;
    }
    // Check if 2 bytes are required, set the matching pattern
    else if ( numberOfBytesRequiredToStoreCompressedCharacter == 2UL )
    {
        // Set the high-order byte to the two bytes pattern -> 110xxxxx
        destinationToSetTemplate[0] |= 0xC0;

        // Set all the rest bytes to the pattern -> 10xxxxxx
        destinationToSetTemplate[1] |= 0x80;
    }
    // Check if 3 bytes are required, set the matching pattern
    else if ( numberOfBytesRequiredToStoreCompressedCharacter == 3UL )
    {
        // Set the high-order byte to the three bytes pattern -> 1110xxxx
        destinationToSetTemplate[0] |= 0xE0;

        // Set all the rest bytes to the pattern -> 10xxxxxx
        destinationToSetTemplate[1] |= 0x80;
        destinationToSetTemplate[2] |= 0x80;
    }
    // 4 bytes are required, set the matching pattern
    else
    {
        // Set the high-order byte to the four bytes pattern -> 11110xxx
        destinationToSetTemplate[0] |= 0xF0;

        // Set all the rest bytes to the pattern -> 10xxxxxx
        destinationToSetTemplate[1] |= 0x80;
        destinationToSetTemplate[2] |= 0x80;
        destinationToSetTemplate[3] |= 0x80;
    }
}


void UnicodeTransferFormat_8::SetTheBitsOfTheCharacterOnLittleEndianSystem__Private( const UnsignedInteger8bits* const characterByte, UnsignedInteger8bits* const destinationToSetCharacterBits, const LargestUnsignedInteger numberOfBytesRequiredToStoreCompressedCharacter )
{
	// Little endian encoding system, the required bits to encode as unicode transfer format 8 are located, in the first bytes of the unicode scalar value	

	// Switch case structure to pick the number of bytes to encode
	switch ( numberOfBytesRequiredToStoreCompressedCharacter  )
	{
		// 1 byte
		case 1 :
		{
			// There are 7 bits to encode from the unicode scalar value

			// There are no template elements in the current unicode transfer format 8 encoding, just copy the entire
			// byte				
			destinationToSetCharacterBits[0] = characterByte[0];

			break;
		}
		// 2 bytes
		case 2 :
		{
			// There are 11 bits to encode from the unicode scalar value

			// The second byte of the unicode transfer format 8 encoding stores the less significant bits. Set the 6
			// less significant bits from the first byte of the unicode scalar value into the
			// 6 less significant bits in the second byte of the unicode transfer format 8 encoding
			destinationToSetCharacterBits[1] |= ( ( static_cast< UnsignedInteger8bits >( characterByte[0] << 2 ) ) >> 2 );

			// In the first byte of the unicode scalar value, only the 2 more significant bits are left to
			// set into the unicode transfer format 8 encoding. Set them into the 2 less significant bits of the first byte of
			// the unicode transfer format 8 encoding
			destinationToSetCharacterBits[0] |= ( characterByte[0] >> 6 );

			// The 3 most significant bits in the first byte of the unicode transfer format 8 encoding are used for the template, 
			// along with the 2 bits already set, there are only 3 bits left to be set. Take those from the
			// 2 less significant bits in the second byte of the unicode scalar value
			destinationToSetCharacterBits[0] |= ( ( static_cast< UnsignedInteger8bits >( characterByte[1] << 5 ) ) >> 3 );

			break;
		}
		// 3 bytes
		case 3 :
		{
			// There are 16 bits to encode from the unicode scalar value

			// The third byte of the unicode transfer format 8 encoding stores the less significant bits. Set the 6
			// less significant bits from the first byte of the unicode scalar value into the
			// 6 less significant bits in the third byte of the unicode transfer format 8 encoding
			destinationToSetCharacterBits[2] |= ( ( static_cast< UnsignedInteger8bits >( characterByte[0] << 2 ) ) >> 2 );

			// In the first byte of the unicode scalar value, only the 2 more significant bits are left to
			// set into the unicode transfer format 8 encoding. Set them into the 2 less significant bits of the second byte of
			// the unicode transfer format 8 encoding
			destinationToSetCharacterBits[1] |= ( characterByte[0] >> 6 );

			// The second byte of the unicode transfer format 8 encoding has the 2 most significant bits used for the template
			// and the 2 less significant bits already set. Set the remainning 4 bits from the second byte
			// in the unicode scalar value
			destinationToSetCharacterBits[1] |= ( ( static_cast< UnsignedInteger8bits >( characterByte[1] << 4 ) ) >> 2 );

			// The first byte of the unicode transfer format 8 encoding has the 4 most significant bits used for the template.
			// Set the 4 less significant bits from the 4 most significant bits of the second byte in the
			// unicode scalar value
			destinationToSetCharacterBits[0] |= ( characterByte[1] >> 4 );

			break;
		}
		// 4 bytes
		default :
		{
			// There are 21 bits to encode from the unicode scalar value

			// The fourth byte of the unicode transfer format 8 encoding stores the less significant bits. Set the 6
			// less significant bits from the first byte of the unicode scalar value into the
			// 6 less significant bits in the fourth byte of the unicode transfer format 8 encoding
			destinationToSetCharacterBits[3] |= ( ( static_cast< UnsignedInteger8bits >( characterByte[0] << 2 ) ) >> 2 );				

			// In the first byte of the unicode scalar value, only the 2 more significant bits are left to
			// set into the unicode transfer format 8 encoding. Set them into the 2 less significant bits of the third byte of
			// the unicode transfer format 8 encoding
			destinationToSetCharacterBits[2] |= ( characterByte[0] >> 6 );				

			// The third byte of the unicode transfer format 8 encoding has the 2 most significant bits used for the template
			// and the 2 less significant bits already set. Set the remainning 4 bits from the second byte
			// in the unicode scalar value
			destinationToSetCharacterBits[2] |= ( ( static_cast< UnsignedInteger8bits >( characterByte[1] << 4 ) ) >> 2 );				

			// The second byte of the unicode transfer format 8 encoding has the 2 most	significant bits used for the template.
			// Set the 4 less significant bits of the this byte with the most significant 4 bits left to set
			// from the second byte of the unicode scalar value 
			destinationToSetCharacterBits[1] |= ( characterByte[1] >> 4 );

			// The second byte of the unicode transfer format 8 encoding only has 2 more bits to be set. Take those from the less
			// significant bits of the third byte in the unicode scalar value
			destinationToSetCharacterBits[1] |= ( ( static_cast< UnsignedInteger8bits >( characterByte[2] << 6 ) ) >> 2 );

			// The first byte of the unicode transfer format 8 encoding has the 5 most significant bits used for the template. Set the
			// 3 less significant bits of this byte, from the third byte of the unicode scalar value
			destinationToSetCharacterBits[0] |= ( ( static_cast< UnsignedInteger8bits >( characterByte[2] << 3 ) ) >> 5 );
		}
	}
}


void UnicodeTransferFormat_8::SetTheBitsOfTheCharacterOnBigEndianSystem__Private( const UnsignedInteger8bits* const characterByte, UnsignedInteger8bits* const destinationToSetCharacterBits, const LargestUnsignedInteger numberOfBytesRequiredToStoreCompressedCharacter )
{
	// Little endian encoding system, the required bits to encode as unicode transfer format 8 are located, in the first bytes of the unicode scalar value	

	// Switch case structure to pick the number of bytes to encode
	switch ( numberOfBytesRequiredToStoreCompressedCharacter  )
	{
		// 1 byte
		case 1 :
		{
			// There are 7 bits to encode from the unicode scalar value

			// There are no template elements in the current unicode transfer format 8 encoding, just copy the entire
			// byte				
			destinationToSetCharacterBits[0] = characterByte[3];

			break;
		}
		// 2 bytes
		case 2 :
		{
			// There are 11 bits to encode from the unicode scalar value

			// The second byte of the unicode transfer format 8 encoding stores the less significant bits. Set the 6
			// less significant bits from the first byte of the unicode scalar value into the
			// 6 less significant bits in the second byte of the unicode transfer format 8 encoding
			destinationToSetCharacterBits[1] |= ( ( static_cast< UnsignedInteger8bits >( characterByte[3] << 2 ) ) >> 2 );

			// In the first byte of the unicode scalar value, only the 2 more significant bits are left to
			// set into the unicode transfer format 8 encoding. Set them into the 2 less significant bits of the first byte of
			// the unicode transfer format 8 encoding
			destinationToSetCharacterBits[0] |= ( characterByte[3] >> 6 );

			// The 3 most significant bits in the first byte of the unicode transfer format 8 encoding are used for the template, 
			// along with the 2 bits already set, there are only 3 bits left to be set. Take those from the
			// 2 less significant bits in the second byte of the unicode scalar value
			destinationToSetCharacterBits[0] |= ( ( static_cast< UnsignedInteger8bits >( characterByte[2] << 5 ) ) >> 3 );

			break;
		}
		// 3 bytes
		case 3 :
		{
			// There are 16 bits to encode from the unicode scalar value

			// The third byte of the unicode transfer format 8 encoding stores the less significant bits. Set the 6
			// less significant bits from the first byte of the unicode scalar value into the
			// 6 less significant bits in the third byte of the unicode transfer format 8 encoding
			destinationToSetCharacterBits[2] |= ( ( static_cast< UnsignedInteger8bits >( characterByte[3] << 2 ) ) >> 2 );

			// In the first byte of the unicode scalar value, only the 2 more significant bits are left to
			// set into the unicode transfer format 8 encoding. Set them into the 2 less significant bits of the second byte of
			// the unicode transfer format 8 encoding
			destinationToSetCharacterBits[1] |= ( characterByte[3] >> 6 );

			// The second byte of the unicode transfer format 8 encoding has the 2 most significant bits used for the template
			// and the 2 less significant bits already set. Set the remainning 4 bits from the second byte
			// in the unicode scalar value
			destinationToSetCharacterBits[1] |= ( ( static_cast< UnsignedInteger8bits >( characterByte[2] << 4 ) ) >> 2 );

			// The first byte of the unicode transfer format 8 encoding has the 4 most significant bits used for the template.
			// Set the 4 less significant bits from the 4 most significant bits of the second byte in the
			// unicode scalar value
			destinationToSetCharacterBits[0] |= ( characterByte[2] >> 4 );

			break;
		}
		// 4 bytes
		default :
		{
			// There are 21 bits to encode from the unicode scalar value

			// The fourth byte of the unicode transfer format 8 encoding stores the less significant bits. Set the 6
			// less significant bits from the first byte of the unicode scalar value into the
			// 6 less significant bits in the fourth byte of the unicode transfer format 8 encoding
			destinationToSetCharacterBits[3] |= ( ( static_cast< UnsignedInteger8bits >( characterByte[3] << 2 ) ) >> 2 );				

			// In the first byte of the unicode scalar value, only the 2 more significant bits are left to
			// set into the unicode transfer format 8 encoding. Set them into the 2 less significant bits of the third byte of
			// the unicode transfer format 8 encoding
			destinationToSetCharacterBits[2] |= ( characterByte[3] >> 6 );				

			// The third byte of the unicode transfer format 8 encoding has the 2 most significant bits used for the template
			// and the 2 less significant bits already set. Set the remainning 4 bits from the second byte
			// in the unicode scalar value
			destinationToSetCharacterBits[2] |= ( ( static_cast< UnsignedInteger8bits >( characterByte[2] << 4 ) ) >> 2 );				

			// The second byte of the unicode transfer format 8 encoding has the 2 most	significant bits used for the template.
			// Set the 4 less significant bits of the this byte with the most significant 4 bits left to set
			// from the second byte of the unicode scalar value 
			destinationToSetCharacterBits[1] |= ( characterByte[2] >> 4 );

			// The second byte of the unicode transfer format 8 encoding only has 2 more bits to be set. Take those from the less
			// significant bits of the third byte in the unicode scalar value
			destinationToSetCharacterBits[1] |= ( ( static_cast< UnsignedInteger8bits >( characterByte[1] << 6 ) ) >> 2 );

			// The first byte of the unicode transfer format 8 encoding has the 5 most significant bits used for the template. Set the
			// 3 less significant bits of this byte, from the third byte of the unicode scalar value
			destinationToSetCharacterBits[0] |= ( ( static_cast< UnsignedInteger8bits >( characterByte[1] << 3 ) ) >> 5 );
		}
	}
}


void UnicodeTransferFormat_8::SetTheBitsOfTheCharacter__Private( const Language::Character& character, UnsignedInteger8bits* const destinationToSetCharacterBits, const LargestUnsignedInteger numberOfBytesRequiredToStoreCompressedCharacter )
{
	// Create a pointer to point to the bytes of the character
	const UnsignedInteger8bits* characterByte = reinterpret_cast< const UnsignedInteger8bits* >( character.GetMemoryAddressOfUnsignedIntegerThatRepresentsTheCharacter() );

	// Check if current system uses little or big endian encoding
	if constexpr ( IsLittleEndian() == true )
	{
		// Little endian encoding

		// Set the unicode scalar value
		SetTheBitsOfTheCharacterOnLittleEndianSystem__Private( characterByte, destinationToSetCharacterBits, numberOfBytesRequiredToStoreCompressedCharacter );
	}
	else
	{
		// Big endian encoding

		// Set the unicode scalar value
		SetTheBitsOfTheCharacterOnBigEndianSystem__Private( characterByte, destinationToSetCharacterBits, numberOfBytesRequiredToStoreCompressedCharacter );
	}
}


LargestUnsignedInteger UnicodeTransferFormat_8::CompressCharacter__Private( const Language::Character& character, UnsignedInteger8bits* const destinationToStoreCompressesCharacter )
{
	// This object will store the number of bytes required to store the compressed character
	const LargestUnsignedInteger numberOfBytesRequiredToStoreCompressedCharacter = GetNumberOfBytesRequiredToStoreCompressedCharacter__Private( character );

	// Set the unicode transfer format 8 template according to the number of bytes required to store the compressed character
	SetTemplate__Private( destinationToStoreCompressesCharacter, numberOfBytesRequiredToStoreCompressedCharacter );

	// Set the actual bits of the character
	SetTheBitsOfTheCharacter__Private( character, destinationToStoreCompressesCharacter, numberOfBytesRequiredToStoreCompressedCharacter );

	// Return the number of bytes required to store the compressed character
	return ( numberOfBytesRequiredToStoreCompressedCharacter );
}


Boolean UnicodeTransferFormat_8::IsCharacterCompressedCorrectly__Private( const UnsignedInteger8bits* const compressedCharacterByte )
{
	// First stage :

	// The first byte is used to determine the number of bytes the unicode transfer format 8 encoding needed

	// If only the first bit is on, the compressed character is invalid
	ReturnValueIfExpressionIsTrue( ( ( compressedCharacterByte[0] & 0xC0 ) == 0x80 ), false );
	
	// If the 5 most significant bits of the first byte in the unicode transfer format 8 encoding are all on, the unicode transfer
	// format 8 encoding is broken	
	ReturnValueIfExpressionIsTrue( ( ( compressedCharacterByte[0] & 0xF8 ) == 0xF8 ), false );

	// Second stage :

	// Pass on all the following bytes and check if the start with the most significant bit on and the next bit off

	// Create an object to store the number of bytes the unicode transfer format 8 encoding needed
	const LargestUnsignedInteger numberOfBytesRequiredToStoreCompressedString = GetNumberOfBytesRequiredToStoreCompressedCharacter__Private( *compressedCharacterByte );

	// Loop on all the bytes of the compressed character
	for ( LargestUnsignedInteger byteIndex = 1UL ; byteIndex < numberOfBytesRequiredToStoreCompressedString ; ++byteIndex )
	{
		// Check that the most significant bit is on, and the next one is off
		ReturnValueIfExpressionIsTrue( ( ( compressedCharacterByte[ byteIndex ] & 0xC0 ) != 0x80 ), false );
	}

	// The unicode transfer format 8 encoding is correct
	return ( true );
}


LargestUnsignedInteger UnicodeTransferFormat_8::GetNumberOfBytesRequiredToStoreCompressedCharacter__Private( const UnsignedInteger8bits commpressedCharacterFirstByte )
{
	// The number of bits that are on before the first bit that is off, represents the number of bytes used to encode as unicode transfer format 8 

	// Check if the first bit is off
	if ( ( commpressedCharacterFirstByte & 0x80 ) == 0 )
	{
		// There are no bits on before the first bit that is off, therefore the encoding needed 1 byte
		return ( 1UL );
	}
	// Check if there are 2 bits on before the first bit that is off
	else if ( ( commpressedCharacterFirstByte & 0x20 ) == 0 )
	{
		// There are 2 bits on before the first bit that is off
		return ( 2UL );
	}
	// Check if there are 3 bits on before the first bit that is off
	else if ( ( commpressedCharacterFirstByte & 0x10 ) == 0 )
	{
		// There are 3 bits on before the first bit that is off
		return ( 3UL );
	}

	// There are 4 bits on before the first bit that is off
	return ( 4UL );
}


LargestUnsignedInteger UnicodeTransferFormat_8::GetNumberOfCharactersCompressed__Private( const Memory::Vector< UnsignedInteger8bits >& compressedString )
{
	// This object will store the number of characters compressed
	LargestUnsignedInteger numberOfCharactersCompressed = 0UL;

	// Loop on all the bytes of the compressed string
	for ( LargestUnsignedInteger index = 3UL ; index < compressedString.Size() ; index += GetNumberOfBytesRequiredToStoreCompressedCharacter__Private( compressedString[ index ] ) )
	{
		// Assert that the current character is compressed correctly
    	Assert( ( IsCharacterCompressedCorrectly__Private( &compressedString[ index ] ) == true ), "The character is not compressed correctly" );

		// Increment the number of characters compressed by 1
		numberOfCharactersCompressed += 1UL;
	}

	// Return the number of compressed characters
	return ( numberOfCharactersCompressed );
}


void UnicodeTransferFormat_8::ExtractTheBitsOfTheCharacterOnLittleEndianSystem__Private( const UnsignedInteger8bits* const compressedCharacterByte, UnsignedInteger8bits* const characterByte, const LargestUnsignedInteger numberOfBytesRequiredToStoreCompressedCharacter )
{
	// Little endian encoding system, so the given pointer to the unicode scalar value points to the byte that should have the less significant bits

	// Check the amount of bytes used to encode as unicode transfer format 8
	switch ( numberOfBytesRequiredToStoreCompressedCharacter )
	{
		// One byte
		case 1 :
		{
			// There are 7 bits to extract from the unicode transfer format 8 encoding

			// There are no template elements in the current unicode transfer format 8 encoding, just copy the entire
			// byte
			characterByte[0] = compressedCharacterByte[0];

			break;
		}
		// Two bytes
		case 2 :
		{
			// There are 11 bits to extract from the unicode transfer format 8 encoding

			// The second byte of the unicode transfer format 8 encoding has the lowest significant bits. The 2 high order bits in the byte are used
			// for the unicode transfer format 8 template, and the 6 less significant bits are part of the unicode scalar value.
			// Set this 6 bits into the less significant bits of the first byte in the unicode scalar value
			characterByte[0] = ( ( static_cast< UnsignedInteger8bits >( compressedCharacterByte[1] << 2 ) ) >> 2 );

			// Set the 2 more significant bits in the first byte of the unicode scalar value to the less significant
			// bits of the first byte in the unicode transfer format 8 encoding
			characterByte[0] |= static_cast< UnsignedInteger8bits >( compressedCharacterByte[0] << 6 );

			// The first byte of the unicode transfer format 8 encoding has the 3 more significant bits for the template, and after setting
			// the 2 less significant bits already, there are left 3 bits to set into the second byte of the unicode scalar value
			characterByte[1] = ( ( static_cast< UnsignedInteger8bits >( compressedCharacterByte[0] << 3 ) ) >> 5 );

			break;
		}
		// Three bytes
		case 3 :
		{
			// There are 16 bits to extract from the unicode transfer format 8 encoding

			// The third byte of the unicode transfer format 8 encoding has the less significant bits. The 2 most significant bits of the byte
			// are used for the unicode transfer format 8 template. Set those into the 6 less significant bits of the first byte in
			// the unicode scalar value
			characterByte[0] = ( ( static_cast< UnsignedInteger8bits >( compressedCharacterByte[2] << 2 ) ) >> 2 );

			// Set the 2 more significant bits left, of the first byte of the unicode scalar value, with the 2 less
			// significant bits in the second byte of the unicode transfer format 8 encoding
			characterByte[0] |= static_cast< UnsignedInteger8bits >( compressedCharacterByte[1] << 6 );

			// The second byte of the unicode transfer format 8 encoding has the 2 most significant bits part of the unicode transfer format 8 template. 
			// Therefore only 4 bits are left to set, after the 2 less significant bits were already extracted. Set 
			// the 4 bits to less significant 4 bits in the second byte of the unicode scalar value
			characterByte[1] = ( ( static_cast< UnsignedInteger8bits >( compressedCharacterByte[1] << 2 ) ) >> 4 );

			// The first byte of the unicode transfer format 8 encoding has the 4 most significant bits used for the template. Set the 4
			// less significant bits into the most significant 4 bits of the second byte in the unicode scalar value
			characterByte[1] |= static_cast< UnsignedInteger8bits >( compressedCharacterByte[0] << 4 );

			break;
		}
		// Four bytes
		default :
		{
			// There are 21 bits to extract from the unicode transfer format 8 encoding

			// The fourth byte of the unicode transfer format 8 encoding has the less significant bits. The 2 most significant bits of the
			// byte are used for the unicode transfer format 8 template. Set the 6 less significant bits to the 6 less significant bits
			// of the first byte in the unicode scalar value
			characterByte[0] = ( ( static_cast< UnsignedInteger8bits >( compressedCharacterByte[3] << 2 ) ) >> 2 );

			// Set the 2 more significant bits left, of the first byte of the unicode scalar value, with the 2 less
			// significant bits in the third byte of the unicode transfer format 8 encoding
			characterByte[0] |= static_cast< UnsignedInteger8bits >( compressedCharacterByte[2] << 6 );

			// The third byte of the unicode transfer format 8 encoding has the 2 most significant bits part of the unicode transfer format 8 template. 
			// Therefore only 4 bits are left to set, after the 2 less significant bits were already extracted. Set 
			// the 4 bits to less significant 4 bits in the second byte of the unicode scalar value
			characterByte[1] = ( ( static_cast< UnsignedInteger8bits >( compressedCharacterByte[2] << 2 ) ) >> 4 );

			// The second byte of the unicode transfer format 8 encoding has the 2 most significant bits part of the unicode transfer format 8 template. 
			// Set the 4 less significant bits of this byte, to the 4 most significant bits in the second byte
			// of the unicode scalar value 
			characterByte[1] |= static_cast< UnsignedInteger8bits >( compressedCharacterByte[1] << 4 );

			// There are 2 bits left to extract from the second byte of the unicode transfer format 8 encoding. Set those to the 2
			// less significant bits of the third byte in the unicode scalar value
			characterByte[2] = ( ( static_cast< UnsignedInteger8bits >( compressedCharacterByte[1] << 2 ) ) >> 6 );

			// The first byte of the unicode transfer format 8 encoding has the 5 more significant bits used for the template. Set the 3 
			// less	significant bits of this byte, to the third byte of the unicode scalar value
			characterByte[2] |= ( ( static_cast< UnsignedInteger8bits >( compressedCharacterByte[0] << 5 ) ) >> 3 );
		}
	}
}


void UnicodeTransferFormat_8::ExtractTheBitsOfTheCharacterOnBigEndianSystem__Private( const UnsignedInteger8bits* const compressedCharacterByte, UnsignedInteger8bits* const characterByte, const LargestUnsignedInteger numberOfBytesRequiredToStoreCompressedCharacter )
{
	// Big endian encoding system, so the given pointer to the unicode scalar value points to the byte that should have the most significant bits

	// Check the amount of bytes used to encode as unicode transfer format 8
	switch ( numberOfBytesRequiredToStoreCompressedCharacter )
	{
		// One byte
		case 1 :
		{
			// There are 7 bits to extract from the unicode transfer format 8 encoding

			// There are no template elements in the current unicode transfer format 8 encoding, just copy the entire
			// byte
			characterByte[3] = compressedCharacterByte[0];

			break;
		}
		// Two bytes
		case 2 :
		{
			// There are 11 bits to extract from the unicode transfer format 8 encoding

			// The second byte of the unicode transfer format 8 encoding has the lowest significant bits. The 2 high order bits in the byte are used
			// for the unicode transfer format 8 template, and the 6 less significant bits are part of the unicode scalar value.
			// Set this 6 bits into the less significant bits of the fourth byte in the unicode scalar value
			characterByte[3] = ( ( static_cast< UnsignedInteger8bits >( compressedCharacterByte[1] << 2 ) ) >> 2 );

			// Set the 2 more significant bits in the fourth byte of the unicode scalar value to the less significant
			// bits of the first byte in the unicode transfer format 8 encoding
			characterByte[3] |= static_cast< UnsignedInteger8bits >( compressedCharacterByte[0] << 6 );

			// The first byte of the unicode transfer format 8 encoding has the 3 more significant bits for the template, and after setting
			// the 2 less significant bits already, there are left 3 bits to set into the third byte of the unicode scalar value
			characterByte[2] = ( ( static_cast< UnsignedInteger8bits >( compressedCharacterByte[0] << 3 ) ) >> 5 );

			break;
		}
		// Three bytes
		case 3 :
		{
			// There are 16 bits to extract from the unicode transfer format 8 encoding

			// The third byte of the unicode transfer format 8 encoding has the less significant bits. The 2 most significant bits of the byte
			// are used for the unicode transfer format 8 template. Set those into the 6 less significant bits of the fourth byte in
			// the unicode scalar value
			characterByte[3] = ( ( static_cast< UnsignedInteger8bits >( compressedCharacterByte[2] << 2 ) ) >> 2 );

			// Set the 2 more significant bits left, of the fourth byte of the unicode scalar value, with the 2 less
			// significant bits in the second byte of the unicode transfer format 8 encoding
			characterByte[3] |= static_cast< UnsignedInteger8bits >( compressedCharacterByte[1] << 6 );

			// The second byte of the unicode transfer format 8 encoding has the 2 most significant bits part of the unicode transfer format 8 template. 
			// Therefore only 4 bits are left to set, after the 2 less significant bits were already extracted. Set 
			// the 4 bits to less significant 4 bits in the third byte of the unicode scalar value
			characterByte[2] = ( ( static_cast< UnsignedInteger8bits >( compressedCharacterByte[1] << 2 ) ) >> 4 );

			// The first byte of the unicode transfer format 8 encoding has the 4 most significant bits used for the template. Set the 4
			// less significant bits into the most significant 4 bits of the third byte in the unicode scalar value
			characterByte[2] |= static_cast< UnsignedInteger8bits >( compressedCharacterByte[0] << 4 );

			break;
		}
		// Four bytes
		default :
		{
			// There are 21 bits to extract from the unicode transfer format 8 encoding

			// The fourth byte of the unicode transfer format 8 encoding has the less significant bits. The 2 most significant bits of the
			// byte are used for the unicode transfer format 8 template. Set the 6 less significant bits to the 6 less significant bits
			// of the fourth byte in the unicode scalar value
			characterByte[3] = ( ( static_cast< UnsignedInteger8bits >( compressedCharacterByte[3] << 2 ) ) >> 2 );

			// Set the 2 more significant bits left, of the fourth byte of the unicode scalar value, with the 2 less
			// significant bits in the third byte of the unicode transfer format 8 encoding
			characterByte[3] |= static_cast< UnsignedInteger8bits >( compressedCharacterByte[2] << 6 );

			// The third byte of the unicode transfer format 8 encoding has the 2 most significant bits part of the unicode transfer format 8 template. 
			// Therefore only 4 bits are left to set, after the 2 less significant bits were already extracted. Set 
			// the 4 bits to less significant 4 bits in the third byte of the unicode scalar value
			characterByte[2] = ( ( static_cast< UnsignedInteger8bits >( compressedCharacterByte[2] << 2 ) ) >> 4 );

			// The second byte of the unicode transfer format 8 encoding has the 2 most significant bits part of the unicode transfer format 8 template. 
			// Set the 4 less significant bits of this byte, to the 4 most significant bits in the third byte
			// of the unicode scalar value 
			characterByte[2] |= static_cast< UnsignedInteger8bits >( compressedCharacterByte[1] << 4 );

			// There are 2 bits left to extract from the second byte of the unicode transfer format 8 encoding. Set those to the 2
			// less significant bits of the second byte in the unicode scalar value
			characterByte[1] = ( ( static_cast< UnsignedInteger8bits >( compressedCharacterByte[1] << 2 ) ) >> 6 );

			// The first byte of the unicode transfer format 8 encoding has the 5 more significant bits used for the template. Set the 3 
			// less	significant bits of this byte, to the second byte of the unicode scalar value
			characterByte[1] |= ( ( static_cast< UnsignedInteger8bits >( compressedCharacterByte[0] << 5 ) ) >> 3 );
		}
	}
}


void UnicodeTransferFormat_8::ExtractTheBitsOfTheCharacter__Private( const UnsignedInteger8bits* const compressedCharacterByte, Language::Character& character, const LargestUnsignedInteger numberOfBytesRequiredToStoreCompressedCharacter )
{
	// Create a pointer to point to the bytes of the character
	UnsignedInteger8bits* const characterByte = reinterpret_cast< UnsignedInteger8bits* >( character.GetMemoryAddressOfUnsignedIntegerThatRepresentsTheCharacter() );

	// Check if current system uses little or big endian encoding
	if constexpr ( IsLittleEndian() == true )
	{
		// Little endian encoding

		// Set the unicode scalar value
		ExtractTheBitsOfTheCharacterOnLittleEndianSystem__Private( compressedCharacterByte, characterByte, numberOfBytesRequiredToStoreCompressedCharacter );
	}
	else
	{
		// Big endian encoding

		// Set the unicode scalar value
		ExtractTheBitsOfTheCharacterOnBigEndianSystem__Private( compressedCharacterByte, characterByte, numberOfBytesRequiredToStoreCompressedCharacter );
	}
}


LargestUnsignedInteger UnicodeTransferFormat_8::ExpandCharacter__Private( const UnsignedInteger8bits* const compressedCharacter, Language::Character& character )
{
	// This object will store the number of bytes required to store the compressed character
	const LargestUnsignedInteger numberOfBytesRequiredToStoreCompressedCharacter = GetNumberOfBytesRequiredToStoreCompressedCharacter__Private( *compressedCharacter );

	// Expand the character
	ExtractTheBitsOfTheCharacter__Private( compressedCharacter, character, numberOfBytesRequiredToStoreCompressedCharacter );

	// Return the number of bytes required to store the compressed character
	return ( numberOfBytesRequiredToStoreCompressedCharacter );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	void UnicodeTransferFormat_8::UnitTest()
	{
		// Loop the required number of iterations
		for ( LargestUnsignedInteger iteration = 0UL ; iteration < 1000 ; ++iteration )
		{
			// Create a string instance
			Language::String randomGenerateString( MemoryHandlerName::Vector, 100UL );

			// Fill the string instance with random generated characters
			for ( LargestUnsignedInteger index = 0UL ; index < 100UL ; ++index )
			{
				randomGenerateString[ index ] = Language::Character( Random::RunTimeGenerator::Numeric::Next< UnsignedInteger32bits >( Range< UnsignedInteger32bits > ( 97, 122 ) ) );
			}

			// Compress the string
			Memory::Vector< UnsignedInteger8bits > compressedString = TakeResourcesAndLeaveInstanceInDefaultState( Compress( randomGenerateString, randomGenerateString.Size() ) );

			// Expand the string
			Language::String uncompressedString = TakeResourcesAndLeaveInstanceInDefaultState( Expand( compressedString ) );

			// Assert that the random generated string and the uncompressed string are the same
			Assert_Test( randomGenerateString == uncompressedString );
		}
	}

)  //  End of debug tool



}  //  Namespace Compression


}  //  Namespace Universe