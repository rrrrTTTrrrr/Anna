#ifndef  UTF8_CPP
#define  UTF8_CPP


#include "UTF8.h"


#include "../../../SmartPointers/ExceptionSafePointer/ExceptionSafePointer.h"  //  Class ExceptionSafePointer



namespace Universe 
{

	namespace Encoding
	{


	    // Forward declarations :
		//
		//		NONE
		//











//  ******************************************************   PUBLIC METHODS IMPLEMENTATION - INTERFACE   *******************************************************














	    // The following methods deal with one unicode scalar value :


		// Method Information :
		//
		//  Description :
		//
		// 		Use this method to encode a unicode character as UTF-8, and store the result in the given location
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
	    //         	1. unicodeScalarValue - a unicode character, which consists of 4 bytes
		//			2. UTF8_encoding - the address where the UTF-8 encoded character will be stored   
		//
		//      Information returned to the user :
		//
		//            NONE
		//
		//  Return value :
		//
		//   	The number of bytes that the UTF-8 encoding needed
		//
		//  Possible errors :
		//
		//		1. If the given value of the unicde character is higher then 1114111 the UTF-8 cant encode it - an Exception is thrown 
		//		2. If the given pointer is NULL - class Exception is thrown
		//		3. 
		//
		UnsignedInteger8bits UTF8::StoreTheUnicodeScalarValueAsUTF8_encoding( UnicodeCharacter unicodeScalarValue, UnsignedInteger8bits* UTF8_encoding ) const
		{
	        // Verify that the given pointer to the memory is not NULL
	        ThrowExceptionIfPointerIsNULL( UTF8_encoding, "UTF8::StoreTheUnicodeScalarValueAsUTF8_encoding failed - the given pointer is NULL" );

			// Get the number of bytes required to encode the unicode character as UTF-8
			UnsignedInteger8bits numberOfBytesToEncodeAs_UTF8 = GetTheAmountOfBytesToEncodeUnicodeScalarValueIntoUTF8IMP( unicodeScalarValue );

			// Set the bytes of the UTF-8 encoding to 0
			*( reinterpret_cast< UnicodeCharacter* >( UTF8_encoding ) ) = 0;

			// Set the UTF-8 template
		 	SetUTF8templateIMP( UTF8_encoding, numberOfBytesToEncodeAs_UTF8 );

		 	// Set the unicode character bits into the template
		 	SetTheBitsOfTheUnicodeScalarValueIntoTheUTF8templateIMP( unicodeScalarValue, UTF8_encoding, numberOfBytesToEncodeAs_UTF8 );

		 	// Return the number of bytes needed to encode as UTF-8 the unicode character
		 	return ( numberOfBytesToEncodeAs_UTF8 );
		}


		// Method Information :
		//
		//  Description :
		//
		// 		Use to get the unicode scalar value from a UTF-8 encoding 
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			  UTF8_encoding - a unicode character encoded into UTF-8 
		//
		//      Information returned to the user :
		//
		//            unicodeScalarValue - the decoded unicode scalar value from the UTF-8 
		//
		//  Return value :
		//
		//   	The number of bytes the UTF-8 encoding needed
		//
		//  Possible errors :
		//
		//		1. The given pointer to the UTF-8 encoding is NULL - class Exception is thrown
		//		2. The UTF-8 encoding is broken
		//		3. 
	    //
		UnsignedInteger8bits UTF8::GetUnicodeScalarValueFromUTF8_encoding( const UnsignedInteger8bits* UTF8_encoding, UnicodeCharacter& unicodeScalarValue ) const
		{
			// Check that the given pointer of the UTF-8 encoding is not NULL
			ThrowExceptionIfPointerIsNULL( UTF8_encoding, "UTF8::GetUnicodeScalarValueFromUTF8_encoding failed - the given UTF-8 encoding pointer is NULL" );

			// Check if the UTF-8 encoding is correct
			ThrowExceptionIfExpressionIsFalse( IsUTF8encodedCorrectly( UTF8_encoding ), "UTF8::GetUnicodeScalarValueFromUTF8_encoding failed - the given UTF-8 encoding is not encoded correct" );

			// Create an object to store the begining address of unicodeScalarValue
			UnsignedInteger8bits* unicodeScalarValueBytes = (UnsignedInteger8bits*)&unicodeScalarValue;

			// Create an object to store the number of bytes the UTF-8 encoding needed
			UnsignedInteger8bits numberOfBytesToEncodeAs_UTF8 = GetTheNumberOfBytesUsedInUTF8_encodingIMP( UTF8_encoding );

	    	// Check if current system uses little or big endian encoding
	    	if ( true == m_trueForLittleEndianAndFalseForBigEndian )
	    	{
	    		// Little endian encoding

	    		// Decode the UTF-8 
	    		DecodeUTF8onSystemsWithLittleEndianIMP( UTF8_encoding, unicodeScalarValueBytes, numberOfBytesToEncodeAs_UTF8 ); 
	    	}
	    	else
	    	{
				// Big endian encoding

				// Decode the UTF-8
	    		DecodeUTF8onSystemsWithBigEndianIMP( UTF8_encoding, unicodeScalarValueBytes, numberOfBytesToEncodeAs_UTF8 );
			}

	        // Return the number of bytes the UTF-8 encoding needed
	        return ( numberOfBytesToEncodeAs_UTF8 );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use to check if the UTF-8 was encoded correctly
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			UTF8_encoding - a unicode character encoded into UTF-8 
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	1. true - if the UTF-8 was encoded correctly
		//		2. false - if the UTF-8 was not encoding correctly
		//
		//  Possible errors :
		//
		//		1. If the given UTF-8 encoding pointer is NULL - class Exception is thrown
		//		2.
	    //
		bool UTF8::IsUTF8encodedCorrectly( const UnsignedInteger8bits* UTF8_encoding ) const throw()
		{
			// First stage :

			// The first byte is used to determine the number of bytes the UTF-8 encoding needed

			// If only the first bit is on ( 1 ), the UTF-8 encoding is broken
			if ( ( 0x80 == ( 0x80 & UTF8_encoding[0] ) ) && ( 0 == ( 0x40 & UTF8_encoding[0] ) ) )
			{
				// The first bit is on but not the second, therefore the UTF-8 encoding is broken
				return ( false );
			}
			// If the 5 most significant bits of the first byte in the UTF-8 encoding are all on ( 1 ), 
			// the UTF-8 encoding is broken	
			else if ( 0xF8 == ( 0xF8 & UTF8_encoding[0] ) )
			{
				// The 5 most significant bits are on ( 1 ), the UTF-8 encoding is broken
				return ( false ); 
			}

			// Second stage :

			// Pass on all the following bytes and check if the start with the most significant bit on ( 1 )
			// and the next bit off ( 0 )

			// Create an object to store the number of bytes the UTF-8 encoding needed
			UnsignedInteger8bits numberOfBytesToEncodeAs_UTF8 = GetTheNumberOfBytesUsedInUTF8_encodingIMP( UTF8_encoding );

			// Loop on all the UTF-8 encoding
			for ( UnsignedInteger8bits UTF8_encodingIndex = 1 ; UTF8_encodingIndex < numberOfBytesToEncodeAs_UTF8 ; ++UTF8_encodingIndex )
			{

				// Check that the most significant bit is on ( 1 ), and the next one is off ( 0 )
				if ( ( 0x80 != ( 0x80 & UTF8_encoding[ UTF8_encodingIndex ] ) ) || ( 0 != ( 0x40 & UTF8_encoding[ UTF8_encodingIndex ] ) ) )
				{
					// The UTF-8 encoding is broken
					return ( false );
				}

			}

			// If the control reached here the UTF-8 encoding is correct
			return ( true );
		}


	    // The following methods deal with a string of unicode scalar values :


	    // Method Information :
	    //
	    //  Description :
	    //
	    //      Use this method to get the unicode scalar values string encoded as UTF-8
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
	    //          unicodeString - the address of a unicode scalar values string
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //      The address of the unicode string encoded as UTF-8
	    //
	    //		Note - the responsibility for deleting the memory space is on the user
	    //
	    //  Possible errors :
	    //
	    //      1. If the given pointer is NULL - class Exception is thrown
	    //      2. There is no more free memory space - class std::bad_alloc is thrown
	    //		3. The unicode scalar values string does not end with NULL
	    //		4. 
	    //
	    UnsignedInteger8bits* UTF8::GetUnicodeStringEncodedAsUTF8( UnicodeCharacter* unicodeString ) const throw( std::bad_alloc, Exception )
	    {
	    	// Check that the pointer is not NULL
			ThrowExceptionIfPointerIsNULL( unicodeString, "UTF8::StoreTheUnicodeScalarValueAsUTF8_encoding failed - the given pointer to the unicode string is NULL" );

			// Allocate memory space to contain the UTF-8 encoding. An Exception safe pointer is used to make sure
			// if an exception is thrown that the resource will be deleted
			DesignPatterns::SmartPointers::ExceptionSafePointer< UnsignedInteger8bits > UTF8_encoding( new UnsignedInteger8bits[ GetTheNumberOfBytesRequiredToEncodeUnicodeStringAsUTF8IMP( unicodeString ) + 4 ], DesignPatterns::SmartPointers::ARRAY_OF_OBJECTS );

			// Set the byte order mark at the beginning of the UTF-8 encoding
			UTF8_encoding[0] = 0xEF;
			UTF8_encoding[1] = 0xBB;
			UTF8_encoding[2] = 0xBF;

			// Create an object to store the current index in the UTF-8 encoding
			UnsignedInteger64bits UTF8_encodingIndex = 3;

			// Loop on the unicode scalar values string and encode them as UTF-8
			for ( UnsignedInteger64bits unicodeStringIndex = 0 ; unicodeString[ unicodeStringIndex ] != 0 ; ++unicodeStringIndex )
			{
				// Encode current unicode scalar value into UTF-8, and increase the index of the UTF-8 encoding according
				// to the number of bytes the current unicde scalar value needed to be encoding as UTF-8
				UTF8_encodingIndex += StoreTheUnicodeScalarValueAsUTF8_encoding( unicodeString[ unicodeStringIndex ], ( UTF8_encoding.GetResource() + UTF8_encodingIndex ) );
			}

			// Set the UTF-8 encoding end with NULL
			UTF8_encoding[ UTF8_encodingIndex ] = 0;

			// Return the UTF-8 encoding
			return ( UTF8_encoding.GetResource() );
	    }


	    // Method Information :
	    //
	    //  Description :
	    //
	    //      Use to decode the UTF-8 string back into the unicode scalar values
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
	    //       	UTF8_encoding - the address of the UTF-8 encoding   
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //      The address of the decoded unicode string
	    //
	    //      Note - the responsibility for deleting the memory space is on the user
	    //
	    //  Possible errors :
	    //
	    //      1. There is no more free space - class std::bad_alloc is thrown
	    //      2. The UTF-8 is not encoded correctly
	    //      3. The UTF-8 does not end with NULL
	    //      4. If the given pointer is NULL - class Exception is thrown
	    //		5.
	    //
	    UnicodeCharacter* UTF8::GetUnicodeString( const UnsignedInteger8bits* UTF8_encoding ) const throw( std::bad_alloc, Exception )
	    {
	    	// Check that the pointer is not NULL
			ThrowExceptionIfPointerIsNULL( UTF8_encoding, "UTF8::GetUnicodeString failed - the given pointer to the utf-8 encoding is NULL" );

			// Allocate memory space to contain the UTF-8 encoding. An Exception safe pointer is used to make sure
			// if an exception is thrown that the resource will be deleted
			DesignPatterns::SmartPointers::ExceptionSafePointer< UnicodeCharacter > unicodeString( new UnicodeCharacter[ GetNumberOfUnicodeScalarValuesInUTF8_encodingIMP( UTF8_encoding ) - 2 ], DesignPatterns::SmartPointers::ARRAY_OF_OBJECTS );

	        // Create an object to store the index in the unicode string
	        UnsignedInteger64bits unicodeStringIndex = 0;

	        // Loop on all of the UTF-8 encoded string. Decode the UTF-8 into the unicode scalar value, and store in the unicode string. Add
	        // the amount of bytes UTF-8 needed to encode the unicode scalar value to the UTF-8 string index everytime
	        for ( UnsignedInteger64bits UTF8stringIndex = 0 ; UTF8_encoding[ UTF8stringIndex ] != 0 ; UTF8stringIndex += GetUnicodeScalarValueFromUTF8_encoding( ( UTF8_encoding + UTF8stringIndex ), unicodeString[ unicodeStringIndex ] ) )
	        {
	        	// Increase the unicode string index by 1
	        	++unicodeStringIndex;
	        }

	        // Set the end of the unicode string to NULL
	        unicodeString[ unicodeStringIndex ] = 0;

	        // Return the handle to the unicode string
	        return ( unicodeString.GetResource() );
	    }


	    // Method Information :
	    //
	    //  Description :
	    //
	    //      Use to check if the UTF-8 was encoded correctly
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
	    //          UTF8_encoding - the address of a UTF-8 encoded string
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //      1. true - if the UTF-8 string was encoded correctly
	    //      2. false - if the UTF-8 string was not encoding correctly
	    //
	    //  Possible errors :
	    //
	    //      1. If the given UTF-8 encoding pointer is NULL - class Exception is thrown
	    //      2. The UTF-8 does not end with NULL
	    //		3.
	    //
	    bool UTF8::IsUTF8stringEncodedCorrectly( const UnsignedInteger8bits* UTF8_encoding ) const
	    {
	    	// Check that the pointer is not NULL
			ThrowExceptionIfPointerIsNULL( UTF8_encoding, "UTF8::GetUnicodeString failed - the given pointer to the utf-8 encoding is NULL" );

			// Check if there is a byte order mark at the beginning of the UTF-8 encoding
			if ( ( 0xEF != UTF8_encoding[0] ) || ( 0xBB != UTF8_encoding[1] ) || ( 0xBF != UTF8_encoding[2] ) )
			{
				// There is no byte order mark, the UTF-8 encoding is not correct
				return ( false );
			}

			// Loop on the UTF-8 encoding and check if there are errors
			for ( UnsignedInteger64bits UTF8_encodingIndex = 3 ; UTF8_encoding[ UTF8_encodingIndex ] != 0 ; UTF8_encodingIndex += GetTheNumberOfBytesUsedInUTF8_encodingIMP( UTF8_encoding + UTF8_encodingIndex ) )
	    	{

	    		// Check if current UTF-8 encoded unicode scalar value is encoded correctly
	    		if ( false == IsUTF8encodedCorrectly( UTF8_encoding + UTF8_encodingIndex ) )
	    		{
	    			// The UTF-8 encoded is not correct, return false
	    			return ( false );
	    		}

	    	}

	    	// If control reached here then the UTF-8 encoding is correct, return true
	    	return ( true );
	    }


	    // Method Information :
	    //
	    //  Description :
	    //
	    //      Use to check if the UTF-8 was encoded correctly. When the string does not end with NULL and only the size is known
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
	    //          1. UTF8_encoding - the address of a UTF-8 encoded string
	    //			2. UTF8_encodingSize - the size of the UTF-8 encoding
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //      1. true - if the UTF-8 string was encoded correctly
	    //      2. false - if the UTF-8 string was not encoding correctly
	    //
	    //  Possible errors :
	    //
	    //      1. If the given UTF-8 encoding pointer is NULL - class Exception is thrown
	    //		2. The given size of the UTF-8 encoding is 0 - class Exception is thrown
	    //		3. 
	    //
	    bool UTF8::IsUTF8stringWithSizeEncodedCorrectly( const UnsignedInteger8bits* UTF8_encoding, UnsignedInteger64bits UTF8_encodingSize ) const
	    {
	    	// Check that the pointer is not NULL
			ThrowExceptionIfPointerIsNULL( UTF8_encoding, "UTF8::GetUnicodeString failed - the given pointer to the utf-8 encoding is NULL" );

            // Check that the UTF-8 encoding size is not 0
            ThrowExceptionIfValueOneIsEqualToValueTwo< UnsignedInteger64bits >( UTF8_encodingSize, 0, "UTF8::IsUTF8stringEncodedCorrectly failed - the given UTF-8 encoding size is 0" );

			// Check if there is a byte order mark at the beginning of the UTF-8 encoding
			if ( ( 0xEF != UTF8_encoding[0] ) || ( 0xBB != UTF8_encoding[1] ) || ( 0xBF != UTF8_encoding[2] ) )
			{
				// There is no byte order mark, the UTF-8 encoding is not correct
				return ( false );
			}

			// Loop on the UTF-8 encoding and check if there are errors
			for ( UnsignedInteger64bits UTF8_encodingIndex = 3 ; UTF8_encodingIndex < UTF8_encodingSize ; UTF8_encodingIndex += GetTheNumberOfBytesUsedInUTF8_encodingIMP( UTF8_encoding + UTF8_encodingIndex ) )
	    	{

	    		// Check if current UTF-8 encoded unicode scalar value is encoded correctly
	    		if ( false == IsUTF8encodedCorrectly( UTF8_encoding + UTF8_encodingIndex ) )
	    		{
	    			// The UTF-8 encoded is not correct, return false
	    			return ( false );
	    		}

	    	}

	    	// If control reached here then the UTF-8 encoding is correct, return true
	    	return ( true );
	    }














//  ****************************************************************   OPERATORS IMPLEMENTATION   *************************************************************************
























//	**************************************************************   PRIVATE METHODS IMPLEMENTATION   **********************************************************
















		// Method Information :
		//
		//  Description :
		//
	    // 		Use to check the amount of bytes would take to encode the unicode character as UTF-8    	
	    //
		//  Required arguments :
		//
	    //   	User information needed :
		//
	    //            unicodeScalarValue - a unicode character, which consists of 4 bytes
		//
		//      Information returned to the user :
		//
		//            NONE
		//
		//  Return value :
		//
		//   	The amount of bytes that would take to encode the unicode character into UTF-8
		//
		//  Possible errors :
		//
		//		1. If the given value of the unicde character is higher then 1114111 the UTF-8 cant encode it - an Exception is thrown
		//		2. 
		//
	    UnsignedInteger8bits UTF8::GetTheAmountOfBytesToEncodeUnicodeScalarValueIntoUTF8IMP( UnicodeCharacter unicodeScalarValue ) const
	    {
	    	// Check that the given value is within the range that the UTF-8 can encode, which means lower then
	    	// the value 1114111
	    	ThrowExceptionIfValueOneIsBiggerThenValueTwo< UnicodeCharacter >( unicodeScalarValue, 1114111, "UTF8::GetTheRequiredAmountOfBytesToEncodeUnicodeCharacterIntoUTF_8IMP failed - the given value is equal or higher then 1114111" );

	        // If the value is between 0 - 127, 1 byte is required
	        if ( unicodeScalarValue < 128 )
	        {
	        	// 1 byte is required
	        	return ( 1 );
	        }
	        // If the value is between 128 - 2047, 2 bytes are required
	        else if ( ( unicodeScalarValue >= 128 ) && ( unicodeScalarValue < 2048 ) )
	        {
	        	// 2 bytes are required
	        	return ( 2 );
	        }
	        // If the value is between 2048 - 65535, 3 bytes are required
	        else if ( ( unicodeScalarValue >= 2048 ) && ( unicodeScalarValue < 65536 ) )
	        {
	        	// 3 bytes are required
	        	return ( 3 );
	        }

		    // If the control reached here the value is between 65535 - 1114111, 4 bytes are required
	    	return ( 4 );
	    }


		// Method Information :
		//
		//  Description :
		//
		//		Use to set the required UTF-8 template into the given destination address
	    //
		//  Required arguments :
		//
	    //   	User information needed :
		//
	    //      	1. UTF8templateDestination - the addrss to set the UTF-8 template in
	    //			2. numberOfBytesToEncodeAs_UTF8 - the number of bytes required to encode the unicode character into UTF-8 encoding  
		//
		//      Information returned to the user :
		//
		//            NONE
		//
		//  Return value :
		//
		//   	The amount of bytes that would take to encode the unicode character into UTF-8
		//
		//  Possible errors :
		//
		//		1. The given number of bytes is not in the range 1 - 4 - class Exception is thrown
		//		2. There is no more free space - class std::bad_alloc is thrown
		//		3. The given pointer is NULL - class Exception is thrown
		//		4. 
	    //
	    void UTF8::SetUTF8templateIMP( UnsignedInteger8bits* UTF8templateDestination, UnsignedInteger8bits numberOfBytesToEncodeAs_UTF8 ) const
	    {
			// Check that the given pointer of the UTF-8 encoding is not NULL
			ThrowExceptionIfPointerIsNULL( UTF8templateDestination, "UTF8::SetUTF8templateIMP failed - the given pointer is NULL" );
	    
	    	// Check that the given number of bytes is in the range 1 - 4
	    	ThrowExceptionIfValueIsOutOfRange< UnsignedInteger8bits >( numberOfBytesToEncodeAs_UTF8, 1, 4, "UTF8::SetUTF8templateIMP failed - the given number of bytes is not in the range [1-4]" ); 

	        // If only 1 byte is required, nothing needs to be done further

	        // Check if 2 bytes are required, set the matching pattern
	        if ( 2 == numberOfBytesToEncodeAs_UTF8 )
	        {
	            // Set the high-order byte to the two bytes pattern -> 110xxxxx
	            UTF8templateDestination[0] |= 0xC0;

	            // Set all the rest bytes to the pattern -> 10xxxxxx
	            UTF8templateDestination[1] |= 0x80;
	        }
	        // Check if 3 bytes are required, set the matching pattern
	        else if ( 3 == numberOfBytesToEncodeAs_UTF8 )
	        {
	            // Set the high-order byte to the three bytes pattern -> 1110xxxx
	            UTF8templateDestination[0] |= 0xE0;

	            // Set all the rest bytes to the pattern -> 10xxxxxx
	            UTF8templateDestination[1] |= 0x80;
	            UTF8templateDestination[2] |= 0x80;
	        }
	        // 4 bytes are required, set the matching pattern
	        else // 4 == numberOfBytesToEncodeAs_UTF8
	        {
	            // Set the high-order byte to the four bytes pattern -> 11110xxx
	            UTF8templateDestination[0] |= 0xF0;

	            // Set all the rest bytes to the pattern -> 10xxxxxx
	            UTF8templateDestination[1] |= 0x80;
	            UTF8templateDestination[2] |= 0x80;
	            UTF8templateDestination[3] |= 0x80;
	        }

	    }


		// Method Information :
		//
		//  Description :
		//
	    // 		Store the bits of the unicode character value into the UTF-8 template
	    //
		//  Required arguments :
		//
	    //   	User information needed :
		//
	    //          1. unicodeScalarValue - a unicode character, which consists of 4 bytes
	    //			2. UTF8_encoding - the address where the UTF-8 template is stored 
	    //		 	3. numberOfBytesToEncodeAs_UTF8 - the number of bytes required to contain the UTF-8 representation of the unicode character
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	The amount of bytes that would take to encode the unicode character into UTF-8
		//
		//  Possible errors :
		//
		//		They will come
	    //
	    void UTF8::SetTheBitsOfTheUnicodeScalarValueIntoTheUTF8templateIMP( UnicodeCharacter unicodeScalarValue, UnsignedInteger8bits* UTF8_encoding, UnsignedInteger8bits numberOfBytesToEncodeAs_UTF8 ) const throw()
	    {
	    	// Create a pointer to the addres of the first byte in unicodeScalarValue
	    	UnsignedInteger8bits* unicodeScalarValueBytes = (UnsignedInteger8bits*)&unicodeScalarValue;

	    	// Check if current system uses little or big endian encoding
	    	if ( true == m_trueForLittleEndianAndFalseForBigEndian )
	    	{
				// Little endian encoding

	    		// Encode the unicode scalar value as UTF-8
	    		EncodeUTF8onSystemsWithLittleEndianIMP( unicodeScalarValueBytes, UTF8_encoding, numberOfBytesToEncodeAs_UTF8 );
			}
			else
			{
				// Big endian encoding

	    		// Encode the unicode scalar value as UTF-8
	    		EncodeUTF8onSystemsWithBigEndianIMP( unicodeScalarValueBytes, UTF8_encoding, numberOfBytesToEncodeAs_UTF8 );
			}

	    }


		// Method Information :
		//
		//  Description :
		//
		//		Use to get the amount of bytes that were used in the given UTF-8 encoding
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			  UTF8_encoding - a unicode character encoded into UTF-8 
		//
		//      Information returned to the user :
		//
		//            NONE
		//
		//  Return value :
		//
		//   	The amount of bytes that was used to create the UTF-8 encoding
		//
		//  Possible errors :
		//
		//		1. If the given UTF-8 encoding pointer is NULL - class Exception is thrown
		//		2. If there are 5 bits on ( 1 ), before the first bit off ( 0 ), the UTF-8 encoding is broken - class Exception is thrown
		//		3. 
	    //
		UnsignedInteger8bits UTF8::GetTheNumberOfBytesUsedInUTF8_encodingIMP( const UnsignedInteger8bits* UTF8_encoding ) const
		{
			// Check that the given pointer of the UTF-8 encoding is not NULL
			ThrowExceptionIfPointerIsNULL( UTF8_encoding, "UTF8::GetTheNumberOfBytesUsedInUTF8_encodingIMPIMP failed - the given UTF-8 encoding pointer is NULL" );

			// The number of bits that are on ( 1 ) before the first bit that is off ( 0 ), represents the
			// number of bytes used to encode as UTF-8 

			// Check if the first bit is off ( 0 )
			if ( 0 == ( 0x80 & *UTF8_encoding ) )
			{
				// There are no bits on ( 1 ) before the first bit that is off, therefore the encoding needed 1 byte
				return ( 1 );
			}
			// Check if there are 2 bits on ( 1 ) before the first bit that is off ( 0 )
			else if ( 0 == ( 0x20 & *UTF8_encoding ) )
			{
				// There are 2 bits on ( 1 ) before the first bit that is off ( 0 )
				return ( 2 );
			}
			// Check if there are 3 bits on ( 1 ) before the first bit that is off ( 0 )
			else if ( 0 == ( 0x10 & *UTF8_encoding ) )
			{
				// There are 3 bits on ( 1 ) before the first bit that is off ( 0 )
				return ( 3 );
			}

			// If the control reached here there are 4 bits on ( 1 ) before the first bit that is off ( 0 )
			return ( 4 );
		}


	    // Method Information :
	    //
	    //  Description :
	    //
	    //      Use to get the number of bytes that will be needed to encode the unicode string as UTF-8
	    //
	    //  Required arguments :
	    //
	    //        User information needed :
	    //
	    //            unicodeString - the address of the unicode string that needs to be encoded into UTF-8
	    //
	    //        Information returned to the user :
	    //
	    //            NONE
	    //
	    //  Return value :
	    //
	    //      The number of bytes that will be needed to encode the unicode string as UTF-16
	    //
	    //  Possible errors :
	    //
	    //      1. There is no NULL at the end of the unicode string
	    //      2. The given pointer is NULL - class Exception is thrown
	    //		3. 
	    //
	    UnsignedInteger64bits UTF8::GetTheNumberOfBytesRequiredToEncodeUnicodeStringAsUTF8IMP( const UnicodeCharacter* unicodeString ) const throw()
	    {
	        // verify that the given unicode string pointer is not NULL
	        ThrowExceptionIfPointerIsNULL( unicodeString, "UTF8::GetTheNumberOfBytesRequiredToEncodeUnicodeStringAsUTF8IMPIMP failed - the given unicode string pointer is NULL" );

	        // Create an object to store the number of bytes required to encode the unicode string as UTF-8
	        UnsignedInteger64bits numberOfBytesToEncodeUnicodeStringAsUTF8 = 0;

	        // Loop on the string until the NULL is reached
	        for ( UnsignedInteger64bits unicodeStringIndex = 0 ; unicodeString[ unicodeStringIndex ] != 0 ; ++unicodeStringIndex )
	        {
	        	// Increase the number of unicode characters by 1
	        	numberOfBytesToEncodeUnicodeStringAsUTF8 += GetTheAmountOfBytesToEncodeUnicodeScalarValueIntoUTF8IMP( unicodeString[ unicodeStringIndex ] );
	        }
	    
	    	// Return the number of bytes required to encode the unicode string as UTF-8 
	    	return ( numberOfBytesToEncodeUnicodeStringAsUTF8 );
	    }


		// Method Information :
		//
		//  Description :
		//
		// 		Use to encode the unicode scalar value as UTF-8 on little endian systems
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			1. UTF8_encoding - a location to store the unicode scalar value encodeD as UTF-8
		//			2. unicodeScalarValueBytes - a pointer to the first byte of the unicode scalar value
		//			3. numberOfBytesToEncodeAs_UTF8 - the number of bytes needed to encode as UTF-8	
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	NONE
		//
		//  Possible errors :
		//
		//		1. The UTF-8 encoding is broken
		//		2. 
	    //
		void UTF8::EncodeUTF8onSystemsWithLittleEndianIMP( const UnsignedInteger8bits* unicodeScalarValueBytes, UnsignedInteger8bits* UTF8_encoding, UnsignedInteger8bits numberOfBytesToEncodeAs_UTF8 ) const throw()
		{
			// Little endian encoding system, the required bits to encode as UTF-8 are located, in the first bytes
			// of the unicode scalar value	

			// Switch case structure to pick the number of bytes to encode
			switch ( numberOfBytesToEncodeAs_UTF8  )
			{

				// 1 byte
				case 1 :
				{
					// There are 7 bits to encode from the unicode scalar value

					// There are no template elements in the current UTF-8 encoding, just copy the entire
					// byte				
					UTF8_encoding[0] = unicodeScalarValueBytes[0];

					break;
				}
				// 2 bytes
				case 2 :
				{
					// There are 11 bits to encode from the unicode scalar value

					// The second byte of the UTF-8 encoding stores the less significant bits. Set the 6
					// less significant bits from the first byte of the unicode scalar value into the
					// 6 less significant bits in the second byte of the UTF-8 encoding
					UTF8_encoding[1] |= ( ( static_cast< UnsignedInteger8bits >( unicodeScalarValueBytes[0] << 2 ) ) >> 2 );

					// In the first byte of the unicode scalar value, only the 2 more significant bits are left to
					// set into the UTF-8 encoding. Set them into the 2 less significant bits of the first byte of
					// the UTF-8 encoding
					UTF8_encoding[0] |= ( unicodeScalarValueBytes[0] >> 6 );

					// The 3 most significant bits in the first byte of the UTF-8 encoding are used for the template, 
					// along with the 2 bits already set, there are only 3 bits left to be set. Take those from the
					// 2 less significant bits in the second byte of the unicode scalar value
					UTF8_encoding[0] |= ( ( static_cast< UnsignedInteger8bits >( unicodeScalarValueBytes[1] << 5 ) ) >> 3 );

					break;
				}
				// 3 bytes
				case 3 :
				{
					// There are 16 bits to encode from the unicode scalar value

					// The third byte of the UTF-8 encoding stores the less significant bits. Set the 6
					// less significant bits from the first byte of the unicode scalar value into the
					// 6 less significant bits in the third byte of the UTF-8 encoding
					UTF8_encoding[2] |= ( ( static_cast< UnsignedInteger8bits >( unicodeScalarValueBytes[0] << 2 ) ) >> 2 );

					// In the first byte of the unicode scalar value, only the 2 more significant bits are left to
					// set into the UTF-8 encoding. Set them into the 2 less significant bits of the second byte of
					// the UTF-8 encoding
					UTF8_encoding[1] |= ( unicodeScalarValueBytes[0] >> 6 );

					// The second byte of the UTF-8 encoding has the 2 most significant bits used for the template
					// and the 2 less significant bits already set. Set the remainning 4 bits from the second byte
					// in the unicode scalar value
					UTF8_encoding[1] |= ( ( static_cast< UnsignedInteger8bits >( unicodeScalarValueBytes[1] << 4 ) ) >> 2 );

					// The first byte of the UTF-8 encoding has the 4 most significant bits used for the template.
					// Set the 4 less significant bits from the 4 most significant bits of the second byte in the
					// unicode scalar value
					UTF8_encoding[0] |= ( unicodeScalarValueBytes[1] >> 4 );

					break;
				}
				// 4 bytes
				default :
				{
					// There are 21 bits to encode from the unicode scalar value

					// The fourth byte of the UTF-8 encoding stores the less significant bits. Set the 6
					// less significant bits from the first byte of the unicode scalar value into the
					// 6 less significant bits in the fourth byte of the UTF-8 encoding
					UTF8_encoding[3] |= ( ( static_cast< UnsignedInteger8bits >( unicodeScalarValueBytes[0] << 2 ) ) >> 2 );				

					// In the first byte of the unicode scalar value, only the 2 more significant bits are left to
					// set into the UTF-8 encoding. Set them into the 2 less significant bits of the third byte of
					// the UTF-8 encoding
					UTF8_encoding[2] |= ( unicodeScalarValueBytes[0] >> 6 );				

					// The third byte of the UTF-8 encoding has the 2 most significant bits used for the template
					// and the 2 less significant bits already set. Set the remainning 4 bits from the second byte
					// in the unicode scalar value
					UTF8_encoding[2] |= ( ( static_cast< UnsignedInteger8bits >( unicodeScalarValueBytes[1] << 4 ) ) >> 2 );				

					// The second byte of the UTF-8 encoding has the 2 most	significant bits used for the template.
					// Set the 4 less significant bits of the this byte with the most significant 4 bits left to set
					// from the second byte of the unicode scalar value 
					UTF8_encoding[1] |= ( unicodeScalarValueBytes[1] >> 4 );

					// The second byte of the UTF-8 encoding only has 2 more bits to be set. Take those from the less
					// significant bits of the third byte in the unicode scalar value
					UTF8_encoding[1] |= ( ( static_cast< UnsignedInteger8bits >( unicodeScalarValueBytes[2] << 6 ) ) >> 2 );

					// The first byte of the UTF-8 encoding has the 5 most significant bits used for the template. Set the
					// 3 less significant bits of this byte, from the third byte of the unicode scalar value
					UTF8_encoding[0] |= ( ( static_cast< UnsignedInteger8bits >( unicodeScalarValueBytes[2] << 3 ) ) >> 5 );
				}

			}

		}


		// Method Information :
		//
		//  Description :
		//
		// 		Use to encode the unicode scalar value as UTF-8 on big endian systems
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			1. UTF8_encoding - a location to store the unicode scalar value encodeD as UTF-8
		//			2. unicodeScalarValueBytes - a pointer to the first byte of the unicode scalar value
		//			3. numberOfBytesToEncodeAs_UTF8 - the number of bytes needed to encode as UTF-8	
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	NONE
		//
		//  Possible errors :
		//
		//		1. The UTF-8 encoding is broken
		//		2. 
	    //
		void UTF8::EncodeUTF8onSystemsWithBigEndianIMP( const UnsignedInteger8bits* unicodeScalarValueBytes, UnsignedInteger8bits* UTF8_encoding, UnsignedInteger8bits numberOfBytesToEncodeAs_UTF8 ) const throw()
		{
			// Little endian encoding system, the required bits to encode as UTF-8 are located, in the first bytes
			// of the unicode scalar value	

			// Switch case structure to pick the number of bytes to encode
			switch ( numberOfBytesToEncodeAs_UTF8  )
			{

				// 1 byte
				case 1 :
				{
					// There are 7 bits to encode from the unicode scalar value

					// There are no template elements in the current UTF-8 encoding, just copy the entire
					// byte				
					UTF8_encoding[0] = unicodeScalarValueBytes[3];

					break;
				}
				// 2 bytes
				case 2 :
				{
					// There are 11 bits to encode from the unicode scalar value

					// The second byte of the UTF-8 encoding stores the less significant bits. Set the 6
					// less significant bits from the first byte of the unicode scalar value into the
					// 6 less significant bits in the second byte of the UTF-8 encoding
					UTF8_encoding[1] |= ( ( static_cast< UnsignedInteger8bits >( unicodeScalarValueBytes[3] << 2 ) ) >> 2 );

					// In the first byte of the unicode scalar value, only the 2 more significant bits are left to
					// set into the UTF-8 encoding. Set them into the 2 less significant bits of the first byte of
					// the UTF-8 encoding
					UTF8_encoding[0] |= ( unicodeScalarValueBytes[3] >> 6 );

					// The 3 most significant bits in the first byte of the UTF-8 encoding are used for the template, 
					// along with the 2 bits already set, there are only 3 bits left to be set. Take those from the
					// 2 less significant bits in the second byte of the unicode scalar value
					UTF8_encoding[0] |= ( ( static_cast< UnsignedInteger8bits >( unicodeScalarValueBytes[2] << 5 ) ) >> 3 );

					break;
				}
				// 3 bytes
				case 3 :
				{
					// There are 16 bits to encode from the unicode scalar value

					// The third byte of the UTF-8 encoding stores the less significant bits. Set the 6
					// less significant bits from the first byte of the unicode scalar value into the
					// 6 less significant bits in the third byte of the UTF-8 encoding
					UTF8_encoding[2] |= ( ( static_cast< UnsignedInteger8bits >( unicodeScalarValueBytes[3] << 2 ) ) >> 2 );

					// In the first byte of the unicode scalar value, only the 2 more significant bits are left to
					// set into the UTF-8 encoding. Set them into the 2 less significant bits of the second byte of
					// the UTF-8 encoding
					UTF8_encoding[1] |= ( unicodeScalarValueBytes[3] >> 6 );

					// The second byte of the UTF-8 encoding has the 2 most significant bits used for the template
					// and the 2 less significant bits already set. Set the remainning 4 bits from the second byte
					// in the unicode scalar value
					UTF8_encoding[1] |= ( ( static_cast< UnsignedInteger8bits >( unicodeScalarValueBytes[2] << 4 ) ) >> 2 );

					// The first byte of the UTF-8 encoding has the 4 most significant bits used for the template.
					// Set the 4 less significant bits from the 4 most significant bits of the second byte in the
					// unicode scalar value
					UTF8_encoding[0] |= ( unicodeScalarValueBytes[2] >> 4 );

					break;
				}
				// 4 bytes
				default :
				{
					// There are 21 bits to encode from the unicode scalar value

					// The fourth byte of the UTF-8 encoding stores the less significant bits. Set the 6
					// less significant bits from the first byte of the unicode scalar value into the
					// 6 less significant bits in the fourth byte of the UTF-8 encoding
					UTF8_encoding[3] |= ( ( static_cast< UnsignedInteger8bits >( unicodeScalarValueBytes[3] << 2 ) ) >> 2 );				

					// In the first byte of the unicode scalar value, only the 2 more significant bits are left to
					// set into the UTF-8 encoding. Set them into the 2 less significant bits of the third byte of
					// the UTF-8 encoding
					UTF8_encoding[2] |= ( unicodeScalarValueBytes[3] >> 6 );				

					// The third byte of the UTF-8 encoding has the 2 most significant bits used for the template
					// and the 2 less significant bits already set. Set the remainning 4 bits from the second byte
					// in the unicode scalar value
					UTF8_encoding[2] |= ( ( static_cast< UnsignedInteger8bits >( unicodeScalarValueBytes[2] << 4 ) ) >> 2 );				

					// The second byte of the UTF-8 encoding has the 2 most	significant bits used for the template.
					// Set the 4 less significant bits of the this byte with the most significant 4 bits left to set
					// from the second byte of the unicode scalar value 
					UTF8_encoding[1] |= ( unicodeScalarValueBytes[2] >> 4 );

					// The second byte of the UTF-8 encoding only has 2 more bits to be set. Take those from the less
					// significant bits of the third byte in the unicode scalar value
					UTF8_encoding[1] |= ( ( static_cast< UnsignedInteger8bits >( unicodeScalarValueBytes[1] << 6 ) ) >> 2 );

					// The first byte of the UTF-8 encoding has the 5 most significant bits used for the template. Set the
					// 3 less significant bits of this byte, from the third byte of the unicode scalar value
					UTF8_encoding[0] |= ( ( static_cast< UnsignedInteger8bits >( unicodeScalarValueBytes[1] << 3 ) ) >> 5 );
				}

			}

		}


		// Method Information :
		//
		//  Description :
		//
		// 		Use to decode the UTF-8 into the unicode scalar value on little endian systems
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			1. UTF8_encoding - a unicode character encoded into UTF-8 
		//			2. unicodeScalarValueBytes - a pointer to the first byte of the object that will store the unicode scalar value
		//			3. numberOfBytesToEncodeAs_UTF8 - the number of bytes needed to encode as UTF-8	
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	NONE
		//
		//  Possible errors :
		//
		//		1. The UTF-8 encoding is broken
		//		2. 
	    //
		void UTF8::DecodeUTF8onSystemsWithLittleEndianIMP( const UnsignedInteger8bits* UTF8_encoding, UnsignedInteger8bits* unicodeScalarValueBytes, UnsignedInteger8bits numberOfBytesToEncodeAs_UTF8 ) const throw()
		{
			// Little endian encoding system, so the given pointer to the unicode scalar value points to the byte that
			// should have the less significant bits

			// Check the amount of bytes used to encode as UTF-8
			switch ( numberOfBytesToEncodeAs_UTF8 )
			{

				// One byte
				case 1 :
				{
					// There are 7 bits to extract from the UTF-8 encoding

					// There are no template elements in the current UTF-8 encoding, just copy the entire
					// byte
					unicodeScalarValueBytes[0] = UTF8_encoding[0];

					break;
				}
				// Two bytes
				case 2 :
				{
					// There are 11 bits to extract from the UTF-8 encoding

					// The second byte of the UTF-8 encoding has the lowest significant bits. The 2 high order bits in the byte are used
					// for the UTF-8 template, and the 6 less significant bits are part of the unicode scalar value.
					// Set this 6 bits into the less significant bits of the first byte in the unicode scalar value
					unicodeScalarValueBytes[0] = ( ( static_cast< UnsignedInteger8bits >( UTF8_encoding[1] << 2 ) ) >> 2 );

					// Set the 2 more significant bits in the first byte of the unicode scalar value to the less significant
					// bits of the first byte in the UTF-8 encoding
					unicodeScalarValueBytes[0] |= ( UTF8_encoding[0] << 6 );

					// The first byte of the UTF-8 encoding has the 3 more significant bits for the template, and after setting
					// the 2 less significant bits already, there are left 3 bits to set into the second byte of the unicode scalar value
					unicodeScalarValueBytes[1] = ( ( static_cast< UnsignedInteger8bits >( UTF8_encoding[0] << 3 ) ) >> 5 );

					break;
				}
				// Three bytes
				case 3 :
				{
					// There are 16 bits to extract from the UTF-8 encoding

					// The third byte of the UTF-8 encoding has the less significant bits. The 2 most significant bits of the byte
					// are used for the UTF-8 template. Set those into the 6 less significant bits of the first byte in
					// the unicode scalar value
					unicodeScalarValueBytes[0] = ( ( static_cast< UnsignedInteger8bits >( UTF8_encoding[2] << 2 ) ) >> 2 );

					// Set the 2 more significant bits left, of the first byte of the unicode scalar value, with the 2 less
					// significant bits in the second byte of the UTF-8 encoding
					unicodeScalarValueBytes[0] |= ( UTF8_encoding[1] << 6 );

					// The second byte of the UTF-8 encoding has the 2 most significant bits part of the UTF-8 template. 
					// Therefore only 4 bits are left to set, after the 2 less significant bits were already extracted. Set 
					// the 4 bits to less significant 4 bits in the second byte of the unicode scalar value
					unicodeScalarValueBytes[1] = ( ( static_cast< UnsignedInteger8bits >( UTF8_encoding[1] << 2 ) ) >> 4 );

					// The first byte of the UTF-8 encoding has the 4 most significant bits used for the template. Set the 4
					// less significant bits into the most significant 4 bits of the second byte in the unicode scalar value
					unicodeScalarValueBytes[1] |= ( UTF8_encoding[0] << 4 );

					break;
				}
				// Four bytes
				default :
				{
					// There are 21 bits to extract from the UTF-8 encoding

					// The fourth byte of the UTF-8 encoding has the less significant bits. The 2 most significant bits of the
					// byte are used for the UTF-8 template. Set the 6 less significant bits to the 6 less significant bits
					// of the first byte in the unicode scalar value
					unicodeScalarValueBytes[0] = ( ( static_cast< UnsignedInteger8bits >( UTF8_encoding[3] << 2 ) ) >> 2 );

					// Set the 2 more significant bits left, of the first byte of the unicode scalar value, with the 2 less
					// significant bits in the third byte of the UTF-8 encoding
					unicodeScalarValueBytes[0] |= ( UTF8_encoding[2] << 6 );

					// The third byte of the UTF-8 encoding has the 2 most significant bits part of the UTF-8 template. 
					// Therefore only 4 bits are left to set, after the 2 less significant bits were already extracted. Set 
					// the 4 bits to less significant 4 bits in the second byte of the unicode scalar value
					unicodeScalarValueBytes[1] = ( ( static_cast< UnsignedInteger8bits >( UTF8_encoding[2] << 2 ) ) >> 4 );

					// The second byte of the UTF-8 encoding has the 2 most significant bits part of the UTF-8 template. 
					// Set the 4 less significant bits of this byte, to the 4 most significant bits in the second byte
					// of the unicode scalar value 
					unicodeScalarValueBytes[1] |= ( UTF8_encoding[1] << 4 );

					// There are 2 bits left to extract from the second byte of the UTF-8 encoding. Set those to the 2
					// less significant bits of the third byte in the unicode scalar value
					unicodeScalarValueBytes[2] = ( ( static_cast< UnsignedInteger8bits >( UTF8_encoding[1] << 2 ) ) >> 6 );

					// The first byte of the UTF-8 encoding has the 5 more significant bits used for the template. Set the 3 
					// less	significant bits of this byte, to the third byte of the unicode scalar value
					unicodeScalarValueBytes[2] |= ( ( static_cast< UnsignedInteger8bits >( UTF8_encoding[0] << 5 ) ) >> 3 );
				}

			}

		}


		// Method Information :
		//
		//  Description :
		//
		// 		Use to decode the UTF-8 into the unicode scalar value on big endian systems
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			1. UTF8_encoding - a unicode character encoded into UTF-8 
		//			2. unicodeScalarValueBytes - a pointer to the first byte of the object that will store the unicode scalar value
		//			3. numberOfBytesToEncodeAs_UTF8 - the number of bytes needed to encode as UTF-8	
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	NONE
		//
		//  Possible errors :
		//
		//		1. The UTF-8 encoding is broken
		//		2. 
	    //
		void UTF8::DecodeUTF8onSystemsWithBigEndianIMP( const UnsignedInteger8bits* UTF8_encoding, UnsignedInteger8bits* unicodeScalarValueBytes, UnsignedInteger8bits numberOfBytesToEncodeAs_UTF8 ) const throw()
		{
			// Big endian encoding system, so the given pointer to the unicode scalar value points to the byte that
			// should have the most significant bits

			// Check the amount of bytes used to encode as UTF-8
			switch ( numberOfBytesToEncodeAs_UTF8 )
			{

				// One byte
				case 1 :
				{
					// There are 7 bits to extract from the UTF-8 encoding

					// There are no template elements in the current UTF-8 encoding, just copy the entire
					// byte
					unicodeScalarValueBytes[3] = UTF8_encoding[0];

					break;
				}
				// Two bytes
				case 2 :
				{
					// There are 11 bits to extract from the UTF-8 encoding

					// The second byte of the UTF-8 encoding has the lowest significant bits. The 2 high order bits in the byte are used
					// for the UTF-8 template, and the 6 less significant bits are part of the unicode scalar value.
					// Set this 6 bits into the less significant bits of the fourth byte in the unicode scalar value
					unicodeScalarValueBytes[3] = ( ( static_cast< UnsignedInteger8bits >( UTF8_encoding[1] << 2 ) ) >> 2 );

					// Set the 2 more significant bits in the fourth byte of the unicode scalar value to the less significant
					// bits of the first byte in the UTF-8 encoding
					unicodeScalarValueBytes[3] |= ( UTF8_encoding[0] << 6 );

					// The first byte of the UTF-8 encoding has the 3 more significant bits for the template, and after setting
					// the 2 less significant bits already, there are left 3 bits to set into the third byte of the unicode scalar value
					unicodeScalarValueBytes[2] = ( ( static_cast< UnsignedInteger8bits >( UTF8_encoding[0] << 3 ) ) >> 5 );

					break;
				}
				// Three bytes
				case 3 :
				{
					// There are 16 bits to extract from the UTF-8 encoding

					// The third byte of the UTF-8 encoding has the less significant bits. The 2 most significant bits of the byte
					// are used for the UTF-8 template. Set those into the 6 less significant bits of the fourth byte in
					// the unicode scalar value
					unicodeScalarValueBytes[3] = ( ( static_cast< UnsignedInteger8bits >( UTF8_encoding[2] << 2 ) ) >> 2 );

					// Set the 2 more significant bits left, of the fourth byte of the unicode scalar value, with the 2 less
					// significant bits in the second byte of the UTF-8 encoding
					unicodeScalarValueBytes[3] |= ( UTF8_encoding[1] << 6 );

					// The second byte of the UTF-8 encoding has the 2 most significant bits part of the UTF-8 template. 
					// Therefore only 4 bits are left to set, after the 2 less significant bits were already extracted. Set 
					// the 4 bits to less significant 4 bits in the third byte of the unicode scalar value
					unicodeScalarValueBytes[2] = ( ( static_cast< UnsignedInteger8bits >( UTF8_encoding[1] << 2 ) ) >> 4 );

					// The first byte of the UTF-8 encoding has the 4 most significant bits used for the template. Set the 4
					// less significant bits into the most significant 4 bits of the third byte in the unicode scalar value
					unicodeScalarValueBytes[2] |= ( UTF8_encoding[0] << 4 );

					break;
				}
				// Four bytes
				default :
				{
					// There are 21 bits to extract from the UTF-8 encoding

					// The fourth byte of the UTF-8 encoding has the less significant bits. The 2 most significant bits of the
					// byte are used for the UTF-8 template. Set the 6 less significant bits to the 6 less significant bits
					// of the fourth byte in the unicode scalar value
					unicodeScalarValueBytes[3] = ( ( static_cast< UnsignedInteger8bits >( UTF8_encoding[3] << 2 ) ) >> 2 );

					// Set the 2 more significant bits left, of the fourth byte of the unicode scalar value, with the 2 less
					// significant bits in the third byte of the UTF-8 encoding
					unicodeScalarValueBytes[3] |= ( UTF8_encoding[2] << 6 );

					// The third byte of the UTF-8 encoding has the 2 most significant bits part of the UTF-8 template. 
					// Therefore only 4 bits are left to set, after the 2 less significant bits were already extracted. Set 
					// the 4 bits to less significant 4 bits in the third byte of the unicode scalar value
					unicodeScalarValueBytes[2] = ( ( static_cast< UnsignedInteger8bits >( UTF8_encoding[2] << 2 ) ) >> 4 );

					// The second byte of the UTF-8 encoding has the 2 most significant bits part of the UTF-8 template. 
					// Set the 4 less significant bits of this byte, to the 4 most significant bits in the third byte
					// of the unicode scalar value 
					unicodeScalarValueBytes[2] |= ( UTF8_encoding[1] << 4 );

					// There are 2 bits left to extract from the second byte of the UTF-8 encoding. Set those to the 2
					// less significant bits of the second byte in the unicode scalar value
					unicodeScalarValueBytes[1] = ( ( static_cast< UnsignedInteger8bits >( UTF8_encoding[1] << 2 ) ) >> 6 );

					// The first byte of the UTF-8 encoding has the 5 more significant bits used for the template. Set the 3 
					// less	significant bits of this byte, to the second byte of the unicode scalar value
					unicodeScalarValueBytes[1] |= ( ( static_cast< UnsignedInteger8bits >( UTF8_encoding[0] << 5 ) ) >> 3 );
				}

			}

		}


	    // Method Information :
	    //
	    //  Description :
	    //
	    //      Use to get the number of unicode scalar values encoded as UTF-8 in the string
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
	    //          NONE
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //      The amount of unicode scalar values encoded as UTF-8
	    //
	    //  Possible errors :
	    //
		//		1. The given pointer is NULL - class Exception is thrown
	    //      2. The UTF-8 encodeing is broken
	    //      3.  
	    //
	    UnsignedInteger64bits UTF8::GetNumberOfUnicodeScalarValuesInUTF8_encodingIMP( const UnsignedInteger8bits* UTF8_encoding ) const
	    {
			// Check that the given pointer of the UTF-8 encoding is not NULL
			ThrowExceptionIfPointerIsNULL( UTF8_encoding, "UTF8::GetNumberOfUnicodeScalarValuesInUTF8_encodingIMP failed - the given UTF-8 encoding pointer is NULL" );

	        // Create an object to store the number of unicode scalar values in the unicode string
	        UnsignedInteger64bits numberOfUnicodeScalarValuesInUnicodeString = 0;

	        // Loop on all the UTF-8 encoding and count the number of unicode scalar values
	        for ( UnsignedInteger64bits UTF8stringIndex = 0 ; UTF8_encoding[ UTF8stringIndex ] != 0 ; UTF8stringIndex += GetTheNumberOfBytesUsedInUTF8_encodingIMP( UTF8_encoding + UTF8stringIndex ) )
	        {
	            // Increase the number of unicode scalar values in the unicode string by 1
	            numberOfUnicodeScalarValuesInUnicodeString += 1;
	        }

	        // Return the number of unicode scalar values in the unicode string
	        return ( numberOfUnicodeScalarValuesInUnicodeString );
	    }
















// ***************************************************   NESTED CLASS PRIVATE METHODS IMPLEMENTATION -    *****************************************************



















// **************************************************************   FRIEND FUNCTIONS IMPLEMENTATION   *******************************************************












    	// This functions are declared outside the class scope, to enable the class to be the right side operand. This can not be for a method
        // within the class. When a method or operator of a class is used, the object the operator or method belongs to must be known, in order
        // to set the implicit this pointer to the method. Therefore the class must be presented first which means to be the left side operand,
        // this functions are needed to avoid just that

























// ***********************************************************************   TESTING   ***********************************************************************












    	// Method Information :
		//
		//  Description :
		//
		//      This method is used to test the object
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          NONE
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      1. true - if the object passed the test
		//      2. false - otherwise
		//
		//  Possible errors :
		//
		//      They will come
		//
		void UTF8::Test()
		{
			// Create an object to store the UTF-8 representation of a unicode scalar value
			UnsignedInteger32bits testUTF8_encoding_1 = 0;

			// Encode 
			UnsignedInteger8bits StoreTheUnicodeScalarValueAsUTF8_encoding( UnicodeScalarValue unicodeScalarValue, UnsignedInteger8bits* UTF8_encoding )
		}
















    }  //  namespace Encoding 

}  //  Namespace Universe


#endif  //  UTF8_CPP