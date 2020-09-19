#ifndef UNICODECHARACTER_CPP
#define UNICODECHARACTER_CPP


#include "UnicodeCharacter.hpp"


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../../../../../../../../TestBranch/SanityCheck/SanityCheck.hpp"  //  Class SanityCheck
#endif


namespace Universe 
{


	namespace Language
	{


		// Forward declarations :
		//
		//  NONE
		//






















//	***************************************************************   PUBLIC METHODS IMPLEMENTATION - INTERFACE   ***************************************************************





























		// Method Information :
		//
		//  Description :
		//
		// 		Use to compress the unicode scalar value as UTF-8
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			destinationToStore_UTF8_compression - a pointer to the memory address where to store the unicode scalar value compressed as UTF-8
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	The number of bytes needed to compress the unicode scalar value as UTF-8
		//
		//	Expectations :
	    //
	    //		1. The given pointer is not NULL
	    //		2. The given pointer point to enough memory space to compress as UTF-8 ( there is no way to validate this at this level )
	    //		3. 
	    //
		//  Possible errors :
		//
		//		NONE
	    //
		UnsignedInteger64bits UnicodeCharacter::CompressAs_UTF8( void* destinationToStore_UTF8_compression ) const
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertPointer_MACRO( destinationToStore_UTF8_compression )

			// This object will point to the memory address bytes
			UnsignedInteger8bits* destinationToStore_UTF8_compression_Bytes = reinterpret_cast< UnsignedInteger8bits* >( destinationToStore_UTF8_compression );

			// This object will store the number of bytes the current unicode scalar value needs to be compressed as UTF-8
			UnsignedInteger64bits numberOfBytesNeededToCompressAs_UTF8 = GetNumberOfBytesNeededToStoreTheCompressedUnicodeCharacterAs_UTF8();

			// Set the UTF-8 template for the current unicode scalar value
			Set_UTF8_template__Private( destinationToStore_UTF8_compression_Bytes, numberOfBytesNeededToCompressAs_UTF8 );

	    	// Check if current system uses little or big endian encoding
	    	if ( true == LittleOrBigEndian() )
	    	{
	    		// Little endian encoding

	    		// Encode the UTF-8 
	    		CompressAs_UTF8_OnSystemsWithLittleEndianEncoding__Private( destinationToStore_UTF8_compression_Bytes, numberOfBytesNeededToCompressAs_UTF8 ); 
	    	}
	    	else
	    	{
				// Big endian encoding

				// Encode the UTF-8
	    		CompressAs_UTF8_OnSystemsWithBigEndianEncoding__Private( destinationToStore_UTF8_compression_Bytes, numberOfBytesNeededToCompressAs_UTF8 );
			}

			// Return the number of bytes to compress the unicode scalar value as UTF-8
			return ( numberOfBytesNeededToCompressAs_UTF8 );
		}


		// Method Information :
		//
		//  Description :
		//
		// 		Use to compress the unicode scalar value as UTF-16
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			destinationToStore_UTF16_compression - a pointer to the memory address where to store the unicode scalar value compressed as UTF-16
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	The number of pair bytes needed to compress the unicode scalar value as UTF-16
		//
		//	Expectations :
	    //
	    //		1. The given pointer is not NULL
	    //		2. The given pointer point to enough memory space to compress as UTF-16 ( there is no way to validate this at this level )
	    //		3. 
	    //
		//  Possible errors :
		//
		//		NONE
	    //
		UnsignedInteger64bits UnicodeCharacter::CompressAs_UTF16( void* destinationToStore_UTF16_compression ) const
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertPointer_MACRO( destinationToStore_UTF16_compression )

			// This object will point to the memory address bytes
			UnsignedInteger16bits* destinationToStore_UTF16_compression_PairBytes = reinterpret_cast< UnsignedInteger16bits* >( destinationToStore_UTF16_compression );

			// This object will store the number of bytes the current unicode scalar value needs to be compressed as UTF-16
			UnsignedInteger64bits numberOfBytesNeededToCompressAs_UTF16 = GetNumberOfPairBytesNeededToStoreTheCompressedUnicodeCharacterAs_UTF16();

			// Check if the value is in the range [55296, 57343], which means all there is to do is to set the unicode scalar value in the destination
			if ( member_unicodeScalarValue < 65536 )
			{
    			// Only 2 bytes are required to compress as UTF-16

    			// Set the unicode scalar value
    			*destinationToStore_UTF16_compression_PairBytes = member_unicodeScalarValue;
			}
			else
			{
    			// Only 2 bytes are required to compress as UTF-16

				// Set the UTF-16 template for the current unicode scalar value
				Set_UTF16_template__Private( destinationToStore_UTF16_compression_PairBytes );

		    	// Check if current system uses little or big endian encoding
		    	if ( true == LittleOrBigEndian() )
		    	{
		    		// Little endian encoding

		    		// Decode the UTF-16
		    		CompressAs_UTF16_OnSystemsWithLittleEndianEncoding__Private( destinationToStore_UTF16_compression_PairBytes ); 
		    	}
		    	else
		    	{
					// Big endian encoding

					// Decode the UTF-16
		    		CompressAs_UTF16_OnSystemsWithBigEndianEncoding__Private( destinationToStore_UTF16_compression_PairBytes );
				}

			}

			// Return the number of bytes to compress the unicode scalar value as UTF-16
			return ( numberOfBytesNeededToCompressAs_UTF16 );
		}


		// Method Information :
		//
		//  Description :
		//
		// 		Use to decode UTF-8 into a unicode scalar value and store inside this instance
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			UTF8_compression - a pointer to the memory address where the unicode scalar value compressed as UTF-8 is stored
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	The number of bytes the compressed unicode scalar value as UTF-8 contains
		//
		//	Expectations :
	    //
	    //		1. The given pointer is not NULL
	    //		2. The given UTF-8 is compressed correctly
	    //		3. 
	    //
		//  Possible errors :
		//
		//		NONE
	    //
		UnsignedInteger64bits UnicodeCharacter::DecompressFrom_UTF8( const void* UTF8_compression )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertPointer_MACRO( UTF8_compression )

			// Set all the bits OFF for the unicode scalar value in this istance
			member_unicodeScalarValue = 0U;

			// This object will point to the memory address bytes
			const UnsignedInteger8bits* UTF8_compression_Bytes = reinterpret_cast< const UnsignedInteger8bits* >( UTF8_compression );

			// This object will store the number of bytes needed for the current unicode scalar value to be compressed as UTF-8
			UnsignedInteger64bits numberOfBytesNeededToCompressAs_UTF8 = GetNumberOfBytesNeededToStoreTheCompressedUnicodeCharacterAs_UTF8( UTF8_compression_Bytes );

	    	// Check if current system uses little or big endian encoding
	    	if ( true == LittleOrBigEndian() )
	    	{
	    		// Little endian encoding

	    		// Decode the UTF-8 
	    		DecompressFrom_UTF8_OnSystemsWithLittleEndianEncoding__Private( UTF8_compression_Bytes, numberOfBytesNeededToCompressAs_UTF8 ); 
	    	}
	    	else
	    	{
				// Big endian encoding

				// Decode the UTF-8
	    		DecompressFrom_UTF8_OnSystemsWithBigEndianEncoding__Private( UTF8_compression_Bytes, numberOfBytesNeededToCompressAs_UTF8 );
			}

			// Return the number of bytes to compress the unicode scalar value as UTF-8
			return ( numberOfBytesNeededToCompressAs_UTF8 );
		}


		// Method Information :
		//
		//  Description :
		//
		// 		Use to decode UTF-16 into a unicode scalar value and store inside this instance
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			UTF16_compression - a pointer to the memory address where the unicode scalar value compressed as UTF-16 is stored
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	The number of pair bytes the compressed unicode scalar value as UTF-16 contains
		//
		//	Expectations :
	    //
	    //		1. The given pointer is not NULL
	    //		2. The given UTF-16 is compressed correctly
	    //		3. 
	    //
		//  Possible errors :
		//
		//		NONE
	    //
		UnsignedInteger64bits UnicodeCharacter::DecompressFrom_UTF16( const void* UTF16_compression )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertPointer_MACRO( UTF16_compression )

			// Set all the bits OFF for the unicode scalar value in this istance
			member_unicodeScalarValue = 0U;

			// This object will point to the memory address bytes
			const UnsignedInteger16bits* UTF16_compression_PairBytes = reinterpret_cast< const UnsignedInteger16bits* >( UTF16_compression );

			// This object will store the number of bytes needed for the current unicode scalar value to be compressed as UTF-16
			UnsignedInteger64bits numberOfBytesNeededToCompressAs_UTF16 = GetNumberOfPairBytesNeededToStoreTheCompressedUnicodeCharacterAs_UTF16( UTF16_compression_PairBytes );

    		// Check if only 2 bytes were needed to compress as UTF-16
    		if ( ( *UTF16_compression_PairBytes < 55296 ) || ( *UTF16_compression_PairBytes > 57343 ) )
    		{
    			// The UTF-16 encoding only needed 2 bytes

    			// Just set the first 2 bytes of the UTF-16 encoding
    			member_unicodeScalarValue = *UTF16_compression_PairBytes; 
    		}
    		else
    		{
    			// The UTF-16 bytes needed 4 bytes

		    	// Check if current system uses little or big endian encoding
		    	if ( true == LittleOrBigEndian() )
		    	{
		    		// Little endian encoding

		    		// Decode the UTF-16 
		    		DecompressFrom_UTF16_OnSystemsWithLittleEndianEncoding__Private( UTF16_compression_PairBytes ); 
		    	}
		    	else
		    	{
					// Big endian encoding

					// Decode the UTF-16
		    		DecompressFrom_UTF16_OnSystemsWithBigEndianEncoding__Private( UTF16_compression_PairBytes );
				}

				// Add 65536 to the decompressed unicode scalar value
				member_unicodeScalarValue += 65536U;
			}

			// Return the number of bytes to compress the unicode scalar value as UTF-16
			return ( numberOfBytesNeededToCompressAs_UTF16 );
		}
































//	********************************************************************   PRIVATE METHODS IMPLEMENTATION   *********************************************************************





































		// Method Information :
		//
		//  Description :
		//
		// 		Use to compress the unicode scalar value as UTF-8 on little endian encoding systems
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			1. destinationToStore_UTF8_compression - a location to store the unicode scalar value compressed as UTF-8
		//			2. numberOfBytesNeededToCompressAs_UTF8 - the number of bytes needed to compressed as UTF-8	
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	NONE
		//
		//	Expectations :
	    //
		//		1. The given pointer is not NULL
		//		2. 
	    //
		//  Possible errors :
		//
		//		NONE
	    //
		void UnicodeCharacter::CompressAs_UTF8_OnSystemsWithLittleEndianEncoding__Private( UnsignedInteger8bits* destinationToStore_UTF8_compression, UnsignedInteger8bits numberOfBytesNeededToCompressAs_UTF8 ) const
		{
			// Little endian encoding system, the required bits to compress as UTF-8 are located, in the first bytes of the unicode scalar value

			// This object will be used to point to the bytes of the unicode scalar value
			const UnsignedInteger8bits* unicodeScalarValueBytes = reinterpret_cast< const UnsignedInteger8bits* >( &member_unicodeScalarValue );

			// Switch case structure to pick the number of bytes to compress
			switch ( numberOfBytesNeededToCompressAs_UTF8  )
			{

				// 1 byte
				case 1 :
				{
					// There are 7 bits to compress from the unicode scalar value

					// There are no template elements in the current UTF-8 encoding, just copy the entire byte				
					destinationToStore_UTF8_compression[0] = unicodeScalarValueBytes[0];

					break;
				}
				// 2 bytes
				case 2 :
				{
					// There are 11 bits to compress from the unicode scalar value

					// The second byte of the UTF-8 encoding stores the less significant bits. Set the 6 less significant bits from the first byte of the 
					// unicode scalar value into the 6 less significant bits in the second byte of the UTF-8 encoding
					destinationToStore_UTF8_compression[1] |= ( unicodeScalarValueBytes[0] & 0x3F );

					// In the first byte of the unicode scalar value, only the 2 more significant bits are left to set into the UTF-8 encoding. Set them 
					// into the 2 less significant bits of the first byte of the UTF-8 encoding
					destinationToStore_UTF8_compression[0] |= ( unicodeScalarValueBytes[0] >> 6 );

					// The 3 most significant bits in the first byte of the UTF-8 encoding are used for the template, along with the 2 bits already set,
					// there are only 3 bits left to be set. Take those from the 2 less significant bits in the second byte of the unicode scalar value
					destinationToStore_UTF8_compression[0] |= ( ( unicodeScalarValueBytes[1] & 0x07 ) << 2 );

					break;
				}
				// 3 bytes
				case 3 :
				{
					// There are 16 bits to compress from the unicode scalar value

					// The third byte of the UTF-8 encoding stores the less significant bits. Set the 6 less significant bits from the first byte of the
					// unicode scalar value into the 6 less significant bits in the third byte of the UTF-8 encoding
					destinationToStore_UTF8_compression[2] |= ( unicodeScalarValueBytes[0] & 0x3F );

					// In the first byte of the unicode scalar value, only the 2 more significant bits are left to set into the UTF-8 encoding. Set them
					// into the 2 less significant bits of the second byte of the UTF-8 encoding
					destinationToStore_UTF8_compression[1] |= ( unicodeScalarValueBytes[0] >> 6 );

					// The second byte of the UTF-8 encoding has the 2 most significant bits used for the template and the 2 less significant bits already
					// set. Set the remainning 4 bits from the second byte in the unicode scalar value
					destinationToStore_UTF8_compression[1] |= ( ( unicodeScalarValueBytes[1] & 0x0F ) << 2 );

					// The first byte of the UTF-8 encoding has the 4 most significant bits used for the template. Set the 4 less significant bits from 
					// the 4 most significant bits of the second byte in the unicode scalar value
					destinationToStore_UTF8_compression[0] |= ( unicodeScalarValueBytes[1] >> 4 );

					break;
				}
				// 4 bytes
				default :
				{
					// There are 21 bits to compress from the unicode scalar value

					// The fourth byte of the UTF-8 encoding stores the less significant bits. Set the 6 less significant bits from the first byte of the 
					// unicode scalar value into the 6 less significant bits in the fourth byte of the UTF-8 encoding
					destinationToStore_UTF8_compression[3] |= ( unicodeScalarValueBytes[0] & 0x3F );

					// In the first byte of the unicode scalar value, only the 2 more significant bits are left to set into the UTF-8 encoding. Set them 
					// into the 2 less significant bits of the third byte of the UTF-8 encoding
					destinationToStore_UTF8_compression[2] |= ( unicodeScalarValueBytes[0] >> 6 );				

					// The third byte of the UTF-8 encoding has the 2 most significant bits used for the template and the 2 less significant bits already 
					// set. Set the remainning 4 bits from the second byte in the unicode scalar value
					destinationToStore_UTF8_compression[2] |= ( ( unicodeScalarValueBytes[1] & 0x0F ) << 2 );

					// The second byte of the UTF-8 encoding has the 2 most	significant bits used for the template. Set the 4 less significant bits of the
					// this byte with the most significant 4 bits left to set from the second byte of the unicode scalar value 
					destinationToStore_UTF8_compression[1] |= ( unicodeScalarValueBytes[1] >> 4 );

					// The second byte of the UTF-8 encoding only has 2 more bits to be set. Take those from the less significant bits of the third byte 
					// in the unicode scalar value
					destinationToStore_UTF8_compression[1] |= ( ( unicodeScalarValueBytes[2] & 0x03 ) << 4 );

					// The first byte of the UTF-8 encoding has the 5 most significant bits used for the template. Set the 3 less significant bits of this 
					// byte, from the third byte of the unicode scalar value
					destinationToStore_UTF8_compression[0] |= ( ( unicodeScalarValueBytes[2] & 0x1C ) >> 2 );
				}

			}

		}


		// Method Information :
		//
		//  Description :
		//
		// 		Use to compress the unicode scalar value as UTF-16 on little endian encoding systems
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			destinationToStore_UTF16_compression - a location to store the unicode scalar value compressed as UTF-16
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	NONE
		//
		//	Expectations :
	    //
		//		1. The given pointer is not NULL
		//		2. 
	    //
		//  Possible errors :
		//
		//		NONE
	    //
		void UnicodeCharacter::CompressAs_UTF16_OnSystemsWithLittleEndianEncoding__Private( UnsignedInteger16bits* destinationToStore_UTF16_compression ) const
		{
			// Little endian encoding system, the required bits to compress as UTF-16 are located, in the first bytes of the unicode scalar value

			// This object will store the unicode scalar value subtracted by 65536, to ensure that now all the number fit into 20 bits
			UnsignedInteger32bits subtractedUnicodeScalarValue = member_unicodeScalarValue - 65536U;

			// This object will be used to point to the subtracted unicode scalar value bytes
			UnsignedInteger8bits* subtractedUnicodeScalarValueBytes = reinterpret_cast< UnsignedInteger8bits* >( &subtractedUnicodeScalarValue );

			// This object will be used to point to the UTF-16 encoding destination bytes
			UnsignedInteger8bits* destinationToStore_UTF16_compressionBytes = reinterpret_cast< UnsignedInteger8bits* >( destinationToStore_UTF16_compression );

            // The first byte of the unicode subtracted scalar value contains the less significant bits, this 8 bits should be stored in the first 
            // byte of the UTF-16 encoding
            destinationToStore_UTF16_compressionBytes[2] |= subtractedUnicodeScalarValueBytes[0];

            // The second byte of the UTF-16 encoding, contains the 6 template bits, and therefore there are 2 bits left to set. This bits are 
            // located in the less significant bits of the second byte of the unicode subtracted scalar value
            destinationToStore_UTF16_compressionBytes[3] |= ( subtractedUnicodeScalarValueBytes[1] & 0x03 );

            // Now the second byte of the unicode subtracted scalar value contains the 6 more significant bits that are left to be set into the
            // less significant bits of the first byte in the UTF-16 encoding
            destinationToStore_UTF16_compressionBytes[0] |= ( subtractedUnicodeScalarValueBytes[1] >> 2 );

            // There are the 2 most significant bits left to set in the first byte of the UTF-16 encoding. They are located in the third byte of
            // the unicode subtracted scalar value
            destinationToStore_UTF16_compressionBytes[0] |= ( subtractedUnicodeScalarValueBytes[2] << 6 );

            // The 2 most signficant bits of the unicode subtracted scalar value are left to store in the second byte of the UTF-16 encoding 
            destinationToStore_UTF16_compressionBytes[1] |= ( subtractedUnicodeScalarValueBytes[2] >> 2 );
		}


		// Method Information :
		//
		//  Description :
		//
		// 		Use to compress the unicode scalar value as UTF-8 on big endian encoding systems
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			1. destinationToStore_UTF8_compression - a location to store the unicode scalar value compressed as UTF-8
		//			2. numberOfBytesNeededToCompressAs_UTF8 - the number of bytes needed to compress as UTF-8	
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	NONE
		//
		//	Expectations :
		//
		//		1. The given pointer is not NULL
		//		2. 
		//
		//  Possible errors :
		//
		//		NONE
	    //
		void UnicodeCharacter::CompressAs_UTF8_OnSystemsWithBigEndianEncoding__Private( UnsignedInteger8bits* destinationToStore_UTF8_compression, UnsignedInteger8bits numberOfBytesNeededToCompressAs_UTF8 ) const
		{
			// Big endian encoding system, the required bits to compress as UTF-8 are located, in the last bytes of the unicode scalar value

			// This object will be used to point to the bytes of the unicode scalar value
			const UnsignedInteger8bits* unicodeScalarValueBytes = reinterpret_cast< const UnsignedInteger8bits* >( &member_unicodeScalarValue );

			// Switch case structure to pick the number of bytes to compress
			switch ( numberOfBytesNeededToCompressAs_UTF8  )
			{

				// 1 byte
				case 1 :
				{
					// There are 7 bits to compress from the unicode scalar value

					// There are no template elements in the current UTF-8 encoding, just copy the entire
					// byte				
					destinationToStore_UTF8_compression[0] = unicodeScalarValueBytes[3];

					break;
				}
				// 2 bytes
				case 2 :
				{
					// There are 11 bits to compress from the unicode scalar value

					// The second byte of the UTF-8 encoding stores the less significant bits. Set the 6 less significant bits from the first byte of the 
					// unicode scalar value into the 6 less significant bits in the second byte of the UTF-8 encoding
					destinationToStore_UTF8_compression[1] |= ( unicodeScalarValueBytes[3] & 0x3F );

					// In the first byte of the unicode scalar value, only the 2 more significant bits are left to set into the UTF-8 encoding. Set them 
					// into the 2 less significant bits of the first byte of the UTF-8 encoding
					destinationToStore_UTF8_compression[0] |= ( unicodeScalarValueBytes[3] >> 6 );

					// The 3 most significant bits in the first byte of the UTF-8 encoding are used for the template, along with the 2 bits already set, 
					// there are only 3 bits left to be set. Take those from the 2 less significant bits in the second byte of the unicode scalar value
					destinationToStore_UTF8_compression[0] |= ( ( unicodeScalarValueBytes[2] & 0x07 ) << 2 );

					break;
				}
				// 3 bytes
				case 3 :
				{
					// There are 16 bits to compress from the unicode scalar value

					// The third byte of the UTF-8 encoding stores the less significant bits. Set the 6 less significant bits from the first byte of the 
					// unicode scalar value into the 6 less significant bits in the third byte of the UTF-8 encoding
					destinationToStore_UTF8_compression[2] |= ( unicodeScalarValueBytes[3] & 0x3F );

					// In the first byte of the unicode scalar value, only the 2 more significant bits are left to set into the UTF-8 encoding. Set them 
					// into the 2 less significant bits of the second byte of the UTF-8 encoding
					destinationToStore_UTF8_compression[1] |= ( unicodeScalarValueBytes[3] >> 6 );

					// The second byte of the UTF-8 encoding has the 2 most significant bits used for the template and the 2 less significant bits already
					// set. Set the remainning 4 bits from the second byte in the unicode scalar value
					destinationToStore_UTF8_compression[1] |= ( ( unicodeScalarValueBytes[2] & 0x0F ) << 2 );

					// The first byte of the UTF-8 encoding has the 4 most significant bits used for the template. Set the 4 less significant bits from 
					// the 4 most significant bits of the second byte in the unicode scalar value
					destinationToStore_UTF8_compression[0] |= ( unicodeScalarValueBytes[2] >> 4 );

					break;
				}
				// 4 bytes
				default :
				{
					// There are 21 bits to compress from the unicode scalar value

					// The fourth byte of the UTF-8 encoding stores the less significant bits. Set the 6 less significant bits from the first byte of the
					// unicode scalar value into the 6 less significant bits in the fourth byte of the UTF-8 encoding
					destinationToStore_UTF8_compression[3] |= ( unicodeScalarValueBytes[3] & 0x3F );

					// In the first byte of the unicode scalar value, only the 2 more significant bits are left to set into the UTF-8 encoding. Set them 
					// into the 2 less significant bits of the third byte of the UTF-8 encoding
					destinationToStore_UTF8_compression[2] |= ( unicodeScalarValueBytes[3] >> 6 );				

					// The third byte of the UTF-8 encoding has the 2 most significant bits used for the template and the 2 less significant bits already
					// set. Set the remainning 4 bits from the second byte in the unicode scalar value
					destinationToStore_UTF8_compression[2] |= ( ( unicodeScalarValueBytes[2] & 0x0F ) << 2 );

					// The second byte of the UTF-8 encoding has the 2 most	significant bits used for the template. Set the 4 less significant bits of the
					// this byte with the most significant 4 bits left to set from the second byte of the unicode scalar value 
					destinationToStore_UTF8_compression[1] |= ( unicodeScalarValueBytes[2] >> 4 );

					// The second byte of the UTF-8 encoding only has 2 more bits to be set. Take those from the less significant bits of the third byte
					// in the unicode scalar value
					destinationToStore_UTF8_compression[1] |= ( ( unicodeScalarValueBytes[1] & 0x03 ) << 4 );

					// The first byte of the UTF-8 encoding has the 5 most significant bits used for the template. Set the 3 less significant bits of this
					// byte, from the third byte of the unicode scalar value
					destinationToStore_UTF8_compression[0] |= ( unicodeScalarValueBytes[1] & 0x07 );
				}

			}

		}


		// Method Information :
		//
		//  Description :
		//
		// 		Use to compress the unicode scalar value as UTF-16 on big endian encoding systems
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			destinationToStore_UTF16_compression - a location to store the unicode scalar value compressed as UTF-16
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	NONE
		//
		//	Expectations :
		//
		//		1. The given pointer is not NULL
		//		2. 
		//
		//  Possible errors :
		//
		//		NONE
	    //
		void UnicodeCharacter::CompressAs_UTF16_OnSystemsWithBigEndianEncoding__Private( UnsignedInteger16bits* destinationToStore_UTF16_compression ) const
		{
			// Big endian encoding system, the required bits to compress as UTF-16 are located, in the last bytes of the unicode scalar value

			// This object will store the unicode scalar value subtracted by 65536, to ensure that now all the number fit into 20 bits
			UnsignedInteger32bits subtractedUnicodeScalarValue = member_unicodeScalarValue - 65536U;

			// This object will be used to point to the subtracted unicode scalar value bytes
			UnsignedInteger8bits* subtractedUnicodeScalarValueBytes = reinterpret_cast< UnsignedInteger8bits* >( &subtractedUnicodeScalarValue );

			// This object will be used to point to the UTF-16 encoding destination bytes
			UnsignedInteger8bits* destinationToStore_UTF16_compressionBytes = reinterpret_cast< UnsignedInteger8bits* >( destinationToStore_UTF16_compression );

            // The last byte of the unicode subtracted scalar value has the less significant 8 bits, which should be stored in the fourth byte of 
            // the UTF-16 encoding
            destinationToStore_UTF16_compressionBytes[3] = subtractedUnicodeScalarValueBytes[3];

            // The third byte of the UTF-16 encoding has 6 bits used for the UTF-16 template, and only the 2 less significant bits are left to be 
            // set. This bits are the 2 less significant bits in the third byte of the unicode subtracted scalar value
            destinationToStore_UTF16_compressionBytes[2] |= ( static_cast< UnsignedInteger8bits >( ( subtractedUnicodeScalarValueBytes[2] << 6 ) ) >> 6 );

            // The 6 more significant bits left in the third byte of the unicode subtracted scalar value, should be stored in the 6 less significant
            // bits of the second byte of the unicode subtracted scalar value
            destinationToStore_UTF16_compressionBytes[1] = ( subtractedUnicodeScalarValueBytes[2] >> 2 );

            // The 2 most significant bits of the second byte in the UTF-16 encoding are left to be set. Take them from the 2 less significant bits
            // of the second byte in the unicode subtracted scalar value
            destinationToStore_UTF16_compressionBytes[1] |= ( subtractedUnicodeScalarValueBytes[1] << 6 );

            // The first byte of the UTF-16 encoding has 6 bits used for the UTF-16 template, and only the 2 less significant bits are left to be set.
            // This bits are located in the second byte of the unicode subtracted scalar value
            destinationToStore_UTF16_compressionBytes[0] |= ( subtractedUnicodeScalarValueBytes[1] >> 2 );
        }


		// Method Information :
		//
		//  Description :
		//
		// 		Use to decode the UTF-8 into the unicode scalar value on little endian encoding systems
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			1. UTF8_compression - a unicode character compressed into UTF-8 
		//			2. numberOfBytesNeededToCompressAs_UTF8 - the number of bytes needed to compress as UTF-8	
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	NONE
		//
		//	Expectations :
		//
		//		1. The given pointer is not NULL
		//		2. 
		//
		//  Possible errors :
		//
		//		NONE
	    //
		void UnicodeCharacter::DecompressFrom_UTF8_OnSystemsWithLittleEndianEncoding__Private( const UnsignedInteger8bits* UTF8_compression, UnsignedInteger8bits numberOfBytesNeededToCompressAs_UTF8 )
		{
			// Little endian encoding system, so the given pointer to the unicode scalar value points to the byte that should have the less significant bits

			// This object will be used to point to the bytes of the unicode scalar value
			UnsignedInteger8bits* unicodeScalarValueBytes = reinterpret_cast< UnsignedInteger8bits* >( &member_unicodeScalarValue );

			// Check the amount of bytes used to compress as UTF-8
			switch ( numberOfBytesNeededToCompressAs_UTF8 )
			{

				// One byte
				case 1 :
				{
					// There are 7 bits to extract from the UTF-8 encoding

					// There are no template elements in the current UTF-8 encoding, just copy the entire byte
					unicodeScalarValueBytes[0] = UTF8_compression[0];

					break;
				}
				// Two bytes
				case 2 :
				{
					// There are 11 bits to extract from the UTF-8 encoding

					// The second byte of the UTF-8 encoding has the lowest significant bits. The 2 high order bits in the byte are used for the UTF-8 
					// template, and the 6 less significant bits are part of the unicode scalar value. Set this 6 bits into the less significant bits
					// of the first byte in the unicode scalar value
					unicodeScalarValueBytes[0] |= ( UTF8_compression[1] & 0x3F );

					// Set the 2 more significant bits in the first byte of the unicode scalar value to the less significant bits of the first byte in
					// the UTF-8 encoding
					unicodeScalarValueBytes[0] |= ( UTF8_compression[0] << 6 );

					// The first byte of the UTF-8 encoding has the 3 more significant bits for the template, and after setting the 2 less significant
					// bits already, there are left 3 bits to set into the second byte of the unicode scalar value
					unicodeScalarValueBytes[1] |= ( ( UTF8_compression[0] >> 2 ) & 0x0F );

					break;
				}
				// Three bytes
				case 3 :
				{
					// There are 16 bits to extract from the UTF-8 encoding

					// The third byte of the UTF-8 encoding has the less significant bits. The 2 most significant bits of the byte are used for the UTF-8
					// template. Set those into the 6 less significant bits of the first byte in the unicode scalar value
					unicodeScalarValueBytes[0] |= ( UTF8_compression[2] & 0x3F );

					// Set the 2 more significant bits left, of the first byte of the unicode scalar value, with the 2 less significant bits in the second
					// byte of the UTF-8 encoding
					unicodeScalarValueBytes[0] |= ( UTF8_compression[1] << 6 );

					// The second byte of the UTF-8 encoding has the 2 most significant bits part of the UTF-8 template. Therefore only 4 bits are left to
					// set, after the 2 less significant bits were already extracted. Set the 4 bits to less significant 4 bits in the second byte of the
					// unicode scalar value
					unicodeScalarValueBytes[1] |= ( ( UTF8_compression[1] >> 2 ) & 0x0F );

					// The first byte of the UTF-8 encoding has the 4 most significant bits used for the template. Set the 4 less significant bits into the
					// most significant 4 bits of the second byte in the unicode scalar value
					unicodeScalarValueBytes[1] |= ( UTF8_compression[0] << 4 );

					break;
				}
				// Four bytes
				default :
				{
					// There are 21 bits to extract from the UTF-8 encoding

					// The fourth byte of the UTF-8 encoding has the less significant bits. The 2 most significant bits of the byte are used for the UTF-8 
					// template. Set the 6 less significant bits to the 6 less significant bits of the first byte in the unicode scalar value
					unicodeScalarValueBytes[0] |= ( UTF8_compression[3] & 0x3F );

					// Set the 2 more significant bits left, of the first byte of the unicode scalar value, with the 2 less significant bits in the third 
					// byte of the UTF-8 encoding
					unicodeScalarValueBytes[0] |= ( UTF8_compression[2] << 6 );

					// The third byte of the UTF-8 encoding has the 2 most significant bits part of the UTF-8 template. Therefore only 4 bits are left to 
					// set, after the 2 less significant bits were already extracted. Set the 4 bits to less significant 4 bits in the second byte of the 
					// unicode scalar value
					unicodeScalarValueBytes[1] |= ( ( UTF8_compression[2] >> 2 ) & 0x0F );

					// The second byte of the UTF-8 encoding has the 2 most significant bits part of the UTF-8 template. Set the 4 less significant bits 
					// of this byte, to the 4 most significant bits in the second byte of the unicode scalar value 
					unicodeScalarValueBytes[1] |= ( UTF8_compression[1] << 4 );

					// There are 2 bits left to extract from the second byte of the UTF-8 encoding. Set those to the 2 less significant bits of the third
					// byte in the unicode scalar value
					unicodeScalarValueBytes[2] |= ( ( UTF8_compression[1] & 0x3F ) >> 4 );

					// The first byte of the UTF-8 encoding has the 5 more significant bits used for the template. Set the 3 less significant bits of this
					// byte, to the third byte of the unicode scalar value
					unicodeScalarValueBytes[2] |= ( ( UTF8_compression[0] & 0x07 ) << 2 );
				}

			}

		}


		// Method Information :
		//
		//  Description :
		//
		// 		Use to decode the UTF-16 into the unicode scalar value on little endian encoding systems
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			UTF16_compression - a unicode character compressed into UTF-16 
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	NONE
		//
		//	Expectations :
		//
		//		1. The given pointer is not NULL
		//		2. 
		//
		//  Possible errors :
		//
		//		NONE
	    //
		void UnicodeCharacter::DecompressFrom_UTF16_OnSystemsWithLittleEndianEncoding__Private( const UnsignedInteger16bits* UTF16_compression )
		{
			// Little endian encoding system, so the given pointer to the unicode scalar value points to the byte that should have the less significant bits

			// This object will be used to point to the unicode scalar value bytes
			UnsignedInteger8bits* unicodeScalarValueBytes = reinterpret_cast< UnsignedInteger8bits* >( &member_unicodeScalarValue );

			// This object will be used to point to the UTF-16 encoding destination bytes
			const UnsignedInteger8bits* UTF16_compressionBytes = reinterpret_cast< const UnsignedInteger8bits* >( UTF16_compression );

            // The third byte of the UTF-16 encoding has the less significant bits. Set this 8 bits into the first byte of the unicode scalar value
            unicodeScalarValueBytes[0] |= UTF16_compressionBytes[2];

            // The fourth byte of the UTF-16 encoding has only 2 bits that should be set into the unicode scalar value and they are the 2 less 
            // significant. Set them to the less significant bits of the second byte of the unicode subtracted scalar value
            unicodeScalarValueBytes[1] |= ( UTF16_compressionBytes[3] & 0x03 );

            // Set the 6 less significant bits in the first byte of the UTF-16 encoding, to the 6 most significant bits in the second byte of the
            // unicode scalar value
            unicodeScalarValueBytes[1] |= ( UTF16_compressionBytes[0] << 2 );

            // Set the 2 most significant bits in the first byte of the UTF-16 encoding, to the 2 less significant bits of the third byte in the
            // unicode scalar value
            unicodeScalarValueBytes[2] |= ( UTF16_compressionBytes[0] >> 6 );

            // Set the 2 less significant bits in the second byte of the UTF-16 encoding, to the third byte of the unicode scalar value
            unicodeScalarValueBytes[2] |= ( ( UTF16_compressionBytes[1] & 0x03 ) << 2 );
        }


		// Method Information :
		//
		//  Description :
		//
		// 		Use to decode the UTF-8 into the unicode scalar value on big endian encoding systems
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			1. UTF8_compression - a unicode character compressed into UTF-8 
		//			2. numberOfBytesNeededToCompressAs_UTF8 - the number of bytes needed to compress as UTF-8	
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	NONE
		//
		//	Expectations :
		//
		//		1. The given pointer is not NULL
		//		2. 
		//
		//  Possible errors :
		//
		//		NONE
	    //
		void UnicodeCharacter::DecompressFrom_UTF8_OnSystemsWithBigEndianEncoding__Private( const UnsignedInteger8bits* UTF8_compression, UnsignedInteger8bits numberOfBytesNeededToCompressAs_UTF8 )
		{
			// Big endian encoding system, so the given pointer to the unicode scalar value points to the byte that should have the most significant bits

			// This object will be used to point to the bytes of the unicode scalar value
			UnsignedInteger8bits* unicodeScalarValueBytes = reinterpret_cast< UnsignedInteger8bits* >( &member_unicodeScalarValue );

			// Check the amount of bytes used to compress as UTF-8
			switch ( numberOfBytesNeededToCompressAs_UTF8 )
			{

				// One byte
				case 1 :
				{
					// There are 7 bits to extract from the UTF-8 encoding

					// There are no template elements in the current UTF-8 encoding, just copy the entire byte
					unicodeScalarValueBytes[3] = UTF8_compression[0];

					break;
				}
				// Two bytes
				case 2 :
				{
					// There are 11 bits to extract from the UTF-8 encoding

					// The second byte of the UTF-8 encoding has the lowest significant bits. The 2 high order bits in the byte are used for the UTF-8 
					// template, and the 6 less significant bits are part of the unicode scalar value. Set this 6 bits into the less significant bits
					// of the fourth byte in the unicode scalar value
					unicodeScalarValueBytes[3] |= ( UTF8_compression[1] & 0x3F );

					// Set the 2 more significant bits in the fourth byte of the unicode scalar value to the less significant bits of the first byte
					// in the UTF-8 encoding
					unicodeScalarValueBytes[3] |= ( UTF8_compression[0] << 6 );

					// The first byte of the UTF-8 encoding has the 3 more significant bits for the template, and after setting the 2 less significant
					// bits already, there are left 3 bits to set into the third byte of the unicode scalar value
					unicodeScalarValueBytes[2] |= ( UTF8_compression[0] & 0x3F );

					break;
				}
				// Three bytes
				case 3 :
				{
					// There are 16 bits to extract from the UTF-8 encoding

					// The third byte of the UTF-8 encoding has the less significant bits. The 2 most significant bits of the byte are used for the 
					// UTF-8 template. Set those into the 6 less significant bits of the fourth byte in the unicode scalar value
					unicodeScalarValueBytes[3] |= ( ( static_cast< UnsignedInteger8bits >( UTF8_compression[2] << 2 ) ) >> 2 );

					// Set the 2 more significant bits left, of the fourth byte of the unicode scalar value, with the 2 less significant bits in the
					// second byte of the UTF-8 encoding
					unicodeScalarValueBytes[3] |= ( UTF8_compression[1] << 6 );

					// The second byte of the UTF-8 encoding has the 2 most significant bits part of the UTF-8 template. Therefore only 4 bits are left
					// to set, after the 2 less significant bits were already extracted. Set the 4 bits to less significant 4 bits in the third byte
					// of the unicode scalar value
					unicodeScalarValueBytes[2] |= ( ( static_cast< UnsignedInteger8bits >( UTF8_compression[1] << 2 ) ) >> 4 );

					// The first byte of the UTF-8 encoding has the 4 most significant bits used for the template. Set the 4 less significant bits into 
					// the most significant 4 bits of the third byte in the unicode scalar value
					unicodeScalarValueBytes[2] |= ( UTF8_compression[0] << 4 );

					break;
				}
				// Four bytes
				default :
				{
					// There are 21 bits to extract from the UTF-8 encoding

					// The fourth byte of the UTF-8 encoding has the less significant bits. The 2 most significant bits of the byte are used for the UTF-8
					// template. Set the 6 less significant bits to the 6 less significant bits of the fourth byte in the unicode scalar value
					unicodeScalarValueBytes[3] |= ( UTF8_compression[3] & 0x3F );

					// Set the 2 more significant bits left, of the fourth byte of the unicode scalar value, with the 2 less significant bits in the third
					// byte of the UTF-8 encoding
					unicodeScalarValueBytes[3] |= ( UTF8_compression[2] << 6 );

					// The third byte of the UTF-8 encoding has the 2 most significant bits part of the UTF-8 template. Therefore only 4 bits are left to 
					// set, after the 2 less significant bits were already extracted. Set the 4 bits to less significant 4 bits in the third byte of the 
					// unicode scalar value
					unicodeScalarValueBytes[2] |= ( ( static_cast< UnsignedInteger8bits >( UTF8_compression[2] << 2 ) ) >> 4 );

					// The second byte of the UTF-8 encoding has the 2 most significant bits part of the UTF-8 template. Set the 4 less significant bits 
					// of this byte, to the 4 most significant bits in the third byte of the unicode scalar value 
					unicodeScalarValueBytes[2] |= ( UTF8_compression[1] << 4 );

					// There are 2 bits left to extract from the second byte of the UTF-8 encoding. Set those to the 2 less significant bits of the second
					// byte in the unicode scalar value
					unicodeScalarValueBytes[1] |= ( ( static_cast< UnsignedInteger8bits >( UTF8_compression[1] << 2 ) ) >> 6 );

					// The first byte of the UTF-8 encoding has the 5 more significant bits used for the template. Set the 3 
					// less	significant bits of this byte, to the second byte of the unicode scalar value
					unicodeScalarValueBytes[1] |= ( ( UTF8_compression[0] & 0x07 ) << 2 );
				}

			}

		}


		// Method Information :
		//
		//  Description :
		//
		// 		Use to decode the UTF-16 into the unicode scalar value on big endian encoding systems
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			UTF16_compression - a unicode character compressed into UTF-16
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	NONE
		//
		//	Expectations :
		//
		//		1. The given pointer is not NULL
		//		2. 
		//
		//  Possible errors :
		//
		//		NONE
	    //
		void UnicodeCharacter::DecompressFrom_UTF16_OnSystemsWithBigEndianEncoding__Private( const UnsignedInteger16bits* UTF16_compression )
		{
			// Big endian encoding system, so the given pointer to the unicode scalar value points to the byte that should have the most significant bits

			// This object will be used to point to the unicode scalar value bytes
			UnsignedInteger8bits* unicodeScalarValueBytes = reinterpret_cast< UnsignedInteger8bits* >( &member_unicodeScalarValue );

			// This object will be used to point to the UTF-16 encoding destination bytes
			const UnsignedInteger8bits* UTF16_compressionBytes = reinterpret_cast< const UnsignedInteger8bits* >( UTF16_compression );

            // The fourth byte of the UTF-16 encoding contains the less significant bits. Set them to the fourth byte of the unicode scalar value
            unicodeScalarValueBytes[3] = UTF16_compressionBytes[3];

            // The 2 less significant bits of the third byte of in UTF-16 encoding needs to be stored, in the 2 less significant bits of the third
            // byte in the unicode scalar value
            unicodeScalarValueBytes[2] = ( ( static_cast< UnsignedInteger8bits >( UTF16_compressionBytes[2] << 6 ) ) >> 6 );

            // The most significant 6 bits left to set in the unicode scalar value, are stored in the 6 less significant bits n the second byte of
            // the UTF-16 encoding
            unicodeScalarValueBytes[2] |= ( UTF16_compressionBytes[1] << 2 );

            // The 2 most significant bits in the second byte of the UTF-16 encoding, should be stored in the 2 less significant bits of the second
            // byte in the unicode scalar value
            unicodeScalarValueBytes[1] = ( UTF16_compressionBytes[2] >> 6 );

            // The 2 less significant bits of the first byte in the UTF-16 encoding, needs to be stored in the second byte of the unicode scalar value
            unicodeScalarValueBytes[1] |= ( ( static_cast< UnsignedInteger8bits >( UTF16_compressionBytes[2] << 6 ) ) >> 4 );
        }






































// *********************************************************************************   TESTING   ********************************************************************************




































		DEBUG_TOOL(

			// Method Information :
			//
			//  Description :
			//
			//		This method is used to test the object. It is not part of the implementation, it is only used to find problem with the code that does implement
			//		the functionality
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			NONE
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		1. true - if the object passed the test
			//		2. false - otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		1. An assertion failed - class Exception or ErrnoException is thrown
			//		2. There is no more free memory space - class std::bad_alloc is thrown
			//		3. 
			//
			void UnicodeCharacter::Test()
			{
				// Perform a sanity to ensure that all the methods that are common among all objects, for example defualt constructor, copy constructor,
				// destructor, swap and more, seem to work correctly
				Testing::SanityCheck::Full< SelfType COMMA UnsignedInteger32bits >( 1000UL, NumericRange< UnsignedInteger32bits >( 2U, 55295U ) );
				Testing::SanityCheck::Full< SelfType COMMA UnsignedInteger32bits >( 1000UL, NumericRange< UnsignedInteger32bits >( 57344U, 1114111U ) );

				// Create two test instances
				UnicodeCharacter testUnicodeCharacter_1;
				UnicodeCharacter testUnicodeCharacter_2;

				// This object will store the UTF-8 compression
				UnsignedInteger32bits UTF8_compression = 0U;

				// Loop on all the possible unicode characters and check the UTF-8 encoding
				for ( UnsignedInteger32bits unicodeScalarValue = 0UL ; unicodeScalarValue < 1114111UL ; ++unicodeScalarValue )
				{

					// Check that the value is valid
					if ( ( unicodeScalarValue >= 55296U ) && ( unicodeScalarValue <= 57343U ) )
					{
						continue;
					}

					// Initiate the test instance using the current unicode scalar value
					testUnicodeCharacter_1.Initiate( unicodeScalarValue );

					// Compress
					testUnicodeCharacter_1.CompressAs_UTF8( &UTF8_compression );

					// Decompress
					testUnicodeCharacter_2.DecompressFrom_UTF8( &UTF8_compression );

					// Assert that the 2 unicode characters are the same
					Assert_Test_MACRO( testUnicodeCharacter_1 == testUnicodeCharacter_2 )
				}

				// This object will store the UTF-16 compression
				UnsignedInteger32bits UTF16_compression = 0U;

				// Loop on all the possible unicode characters and check the UTF-16 encoding
				for ( UnsignedInteger32bits unicodeScalarValue = 0UL ; unicodeScalarValue < 1114111UL ; ++unicodeScalarValue )
				{

					// Check that the value is valid
					if ( ( unicodeScalarValue >= 55296U ) && ( unicodeScalarValue <= 57343U ) )
					{
						continue;
					}

					// Initiate the test instance using the current unicode scalar value
					testUnicodeCharacter_1.Initiate( unicodeScalarValue );

					// Compress
					testUnicodeCharacter_1.CompressAs_UTF16( &UTF16_compression );

					// Decompress
					testUnicodeCharacter_2.DecompressFrom_UTF16( &UTF16_compression );

					// Assert that the 2 unicode characters are the same
					Assert_Test_MACRO( testUnicodeCharacter_1 == testUnicodeCharacter_2 )
				}

			}

		)  //  End of debug tool










	}  //  Namespace Language

}  //  Namespace Universe


#endif  //  UNICODECHARACTER_CPP





