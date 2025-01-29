//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline Memory::Vector< UnsignedInteger8bits > UnicodeTransferFormat_8::Compress( const Language::String& string, const LargestUnsignedInteger sizeFromStringToCompress, const LargestUnsignedInteger startCompressingFromThisIndexOnString )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsLargerThenZero( sizeFromStringToCompress );
    AssertSumOfTheValuesIsEqualOrBelowCertainLimit( startCompressingFromThisIndexOnString, sizeFromStringToCompress, string.Size() );

	// This object will store the compressed string
	Memory::Vector< UnsignedInteger8bits > compressedString( GetNumberOfBytesRequiredToStoreCompressedString__Private( string, sizeFromStringToCompress, startCompressingFromThisIndexOnString ) + 3UL );

	// Set the byte order mark at the beginning of the compressed string
	compressedString[0] = 0xEF;
	compressedString[1] = 0xBB;
	compressedString[2] = 0xBF;

	// This object will be used as the index on the compressed string
	LargestUnsignedInteger compressedStringIndex = 3UL;

	// This object will store the value of the entry after the last entry in the string that needs to be processed
	const LargestUnsignedInteger stopLoopAtThisIndex = startCompressingFromThisIndexOnString + sizeFromStringToCompress;

	// Loop on all the required entries of the string
	for ( LargestUnsignedInteger index = startCompressingFromThisIndexOnString ; index < stopLoopAtThisIndex ; ++index )
	{
		// Compress the current character, and store it
		compressedStringIndex += CompressCharacter__Private( string[ index ], &compressedString[ compressedStringIndex ] );
	}

	// Return the compressed string
	return ( compressedString );
}


inline Language::String UnicodeTransferFormat_8::Expand( const Memory::Vector< UnsignedInteger8bits >& compressedString, const MemoryHandlerName memoryHandlerName )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsLargerThenZero( compressedString.Size() );

    // Assert that the compressed string starts with the byte order mark
    Assert( ( ( compressedString[0] == 0xEF ) && ( compressedString[1] == 0xBB ) && ( compressedString[2] == 0xBF ) ), "The given compressed string has no byte order maek at the beginning" );

	// This object will store the uncompressed string
	Language::String string( memoryHandlerName, GetNumberOfCharactersCompressed__Private( compressedString ) );

	// This object will be used as the index on the compressed string
	LargestUnsignedInteger compressedStringIndex = 3UL;

	// Loop on all the compressed string
	for ( LargestUnsignedInteger index = 0UL ; compressedStringIndex < compressedString.Size() ; ++index )
	{
		// Uncompress the current character, and store it
		compressedStringIndex += ExpandCharacter__Private( &compressedString[ compressedStringIndex ], string[ index ] ); 
	}

	// Return the uncompressed string
	return ( string );
}



}  //  Namespace Compression


}  //  Namespace Universe