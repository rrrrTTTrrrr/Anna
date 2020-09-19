#ifndef  UTF16_CPP
#define  UTF16_CPP


#include "UTF16.h"


#include "../../../DesignPatterns/SmartPointers/ExceptionSafePointer.h"  //  Class ExceptionSafePointer
#include "../../../BasicUtilities/BasicOperations/Bits/BitsOperations.h"  //  Function ReverseBytesOrder



using namespace std;


namespace Universe 
{

    namespace Encoding
    {

        // Forward declarations :
        //
        //  NONE
        //













//	************************************   PUBLIC METHODS IMPLEMENTATION - INTERFACE   ************************************













        // The following methods deal with one unicode scalar value :


        // Method Information :
        //
        //  Description :
        //
        //      Use to store the unicode scalar value as UTF-16 into the given location
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. unicodeScalarValue - the unicdoe scalar value
        //          2. UTF16encoding - the location to store the UTF-16 encoding, there must be 4 bytes to contain the largest possibility
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		1. 1 - if only 2 bytes were needed to encode as UTF-16
        //		2. 2 - if 4 bytes were needed to encode as UTF-16
        //
        //  Possible errors :
        //
        //      1. The given pointer is NULL - class Exception is thrown
        //		2. The given unicode scalar value is higher then 1114111 - class Exception is thrown
        //		3. 
        //
        UnsignedInteger8bits UTF16::SetTheGivenUnicodeScalarValueEncodedAsUTF16( UnicodeScalarValue unicodeScalarValue, UnsignedInteger16bits* UTF16encoding ) const throw( Exception )
        {
    		// Check that given pointer to store the UTF-16 encoding is not NULL
    		ThrowExceptionIfPointerIsNULL( UTF16encoding, "UTF16::SetTheGivenUnicodeScalarValueEncodedAsUTF16 failed - the given pointer is NULL" );

    		// Check that the given unicode scalar value is in permitted range [ 0 - 1114111 ]
    		ThrowExceptionIfValueOneIsBiggerThenValueTwo< UnicodeScalarValue >( unicodeScalarValue, 1114111, "UTF16::SetTheGivenUnicodeScalarValueEncodedIntoUTF16 failed - the given unicode scalar value is out of range [ 0 - 1114111 ]" );

    		// Check if the required unicode scalar value requires 2 or 4 bytes to be encoded as UTF-16
    		if ( unicodeScalarValue < 65536 )
    		{
    			// Only 2 bytes are required to encode as UTF-16

    			// Set the unicode scalar value as it is into the given location
    			*UTF16encoding = unicodeScalarValue;

    			// Return that only 2 bytes were needed to encode as UTF-16
    			return ( 1 );
    		}

    		// If control reached here this means that the given unicode saclar value is equal or above 65536.
    		// Therefore 4 bytes are required

    		// Set the UTF-16 template first

    		// Set the first pair of 2 bytes into 55296
    		UTF16encoding[0] = 0xD800;  // In bits ->   11011000 00000000   10 bits free to set

    		// Set the second pair of 2 bytes into 56320
    		UTF16encoding[1] = 0xDC00;  // In bits ->   11011100 00000000   10 bits free to set

    		// Now there are 20 bits from the character scalar value that needs to be set into the UTF-16 encoding.
    		// Each 2 bytes has, after setting the template, 10 bits to store. Where the pair of bytes with the value
            // 0xD800 should contain the most significant 10 bits, and the pair with value 0xDC00 should contain the
            // less significant bits

    		// Set the UTF-16 template and store the required value inside the UTF-16 template, the operation 
    		// is correct for little or big endian
    		EncodeTheUnicodeScalarValueIntoTheUTF16templateIMP( unicodeScalarValue, reinterpret_cast< UnsignedInteger8bits* >( UTF16encoding ) );

    		// Return that 2 sets of 2 bytes were needed to encode as UTF-16
    		return ( 2 );
    	}


        // Method Information :
        //
        //  Description :
        //
        //		Use to store the unicode scalar value extracted from the UTF-16 encoding to the given location      
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. UTF16encoding - the address of the UTF-16 encoding
        //			2. unicodeScalarValue - a reference to the location where the decoded unicode scalar value will be stored
        //          3. trueForLittleEndianAndFalseForBigEndian - this boolean will be used to determine if the UTF-16 encoding is little or big endian
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		The amount of bytes the UTF-16 encoding needed :
        //		1. 0 - 2 bytes were needed
        //		2. 1 - 4 bytes were needed
        //
        //  Possible errors :
        //
        //      1. The given UTF-16 encoding pointer is NULL - class Exception is thrown
        //		2. The given bytes are not encoded as UTF-16 correctly - class Exception is thrown
        //		3. 
        //
        UnsignedInteger8bits UTF16::GetTheUnicodeScalarValueFromUTF16encoding( const UnsignedInteger16bits* UTF16encoding, UnicodeScalarValue& unicodeScalarValue, bool trueForLittleEndianAndFalseForBigEndian ) const throw( Exception )
        {
    		// Check that given pointer to the UTF-16 encoding is not NULL
    		ThrowExceptionIfPointerIsNULL( UTF16encoding, "UTF16::GetTheUnicodeScalarValueFromTheUTF16encoding failed - the given UTF-16 encoding pointer is NULL" );

            // Create an object to store the first 2 bytes of the UTF-16 encoding
            UnsignedInteger16bits UTF16encodingFirstTwoBytes = *UTF16encoding;

            // Check if the system uses little or big endian encoding
            if ( trueForLittleEndianAndFalseForBigEndian != m_trueForLittleEndianAndFalseForBigEndian )
            {
                // The system uses different endian encoding, reverse the order of the 2 bytes
                ReverseBytesOrder( &UTF16encodingFirstTwoBytes, 2 );
            }

    		// Check if only 2 bytes were needed to encode as UTF-16
    		if ( ( UTF16encoding[0] < 55296 ) || ( UTF16encoding[0] > 57343 ) )
    		{
    			// The UTF-16 encoding only needed 2 bytes. The unicode scalar value is
    			// the same as the value stored
    			unicodeScalarValue = UTF16encodingFirstTwoBytes; 

    			// Only 2 bytes were needed, return 1
    			return ( 1 );
    		}

    		// If control reached here 4 bytes were needed to encode as UTF-16

    		// Verify that the first 2 bytes value are in the permitted range 
    		ThrowExceptionIfExpressionIsFalse( ( ( UTF16encoding[0] >= 55296 ) && ( UTF16encoding[0] <= 56319 ) ), "GetTheUnicodeScalarValueFromTheUTF16encoding failed - the 2 first bytes have a value that violates the UTF-16 encoding" );

    		// Verify that the last 2 bytes value are in the permitted range
    		ThrowExceptionIfExpressionIsFalse( ( ( UTF16encoding[1] >= 56320 ) && ( UTF16encoding[1] <= 57343 ) ), "GetTheUnicodeScalarValueFromTheUTF16encoding failed - the 2 last bytes have a value that violates the UTF-16 encoding" );

    		// The bytes are encoded as UTF-16 correctly

    		// Decode the UTF-16 and set the unicode scalar value reference
    		DecodeTheUTF16encodingIntoUnicodeScalarValueIMP( reinterpret_cast< const UnsignedInteger8bits* >( UTF16encoding ), unicodeScalarValue );

            // Check if the system uses little or big endian encoding
            if ( trueForLittleEndianAndFalseForBigEndian != m_trueForLittleEndianAndFalseForBigEndian )
            {
                // The system uses different endian encoding, reverse the order of the unicode scalar value
                ReverseBytesOrder( &unicodeScalarValue, 4 );
            }

    		// 4 bytes were needed, return 2
    		return ( 2 );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to check if the UTF-16 was encoded correctly
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          UTF16encoding - a unicode scalar value encoded into UTF-16 
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      1. true - if the UTF-16 was encoded correctly
        //      2. false - if the UTF-16 was not encoding correctly
        //
        //  Possible errors :
        //
        //      1. If the given UTF-16 encoding pointer is NULL - class Exception is thrown
        //      2.
        //
        bool UTF16::IsUTF16encodedCorrectly( const UnsignedInteger16bits* UTF16encoding ) const throw( Exception )
        {
            // Check that given pointer to the UTF-16 encoding is not NULL
            ThrowExceptionIfPointerIsNULL( UTF16encoding, "UTF16::IsUTF16encodedCorrectly failed - the given UTF-16 encoding pointer is NULL" );
         
            // Check if only 2 bytes were needed to encode as UTF-16
            if ( ( UTF16encoding[0] < 55296 ) || ( UTF16encoding[0] > 57343 ) )
            {
                // The UTF-16 encoding only needed 2 bytes

                // In this case there is no template set into the bytes, it is just the value as it is
                return ( true );
            }

            // If control reached here 4 bytes were needed to encode as UTF-16, and there is a template set in the bytes to check

            // Verify that the the bytes value are in the permitted range 
            if ( ( ( UTF16encoding[0] >= 55296 ) && ( UTF16encoding[0] <= 56319 ) ) && ( ( UTF16encoding[1] >= 56320 ) && ( UTF16encoding[1] <= 57343 ) ) )
            {
                // The UTF-16 is encoded correctly
                return ( true );
            }                

            // If control reached here the UTF-16 is not encoded correctly, return false
            return ( false );
        }


        // The following methods deal with a string of unicode scalar values :


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to get the unicode scalar values string encoded as UTF-16
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
        //      The address of the unicode string encoded as UTF-16
        //
        //      Note - the responsibility for deleting the memory space is on the user
        //
        //  Possible errors :
        //
        //      1. If the given pointer is NULL - class Exception is thrown
        //      2. There is no more free memory space - class std::bad_alloc is thrown
        //      3. The unicode scalar values string does not end with NULL
        //      4. 
        //
        UnsignedInteger16bits* UTF16::GetUnicodeStringEncodedAsUTF16( UnicodeScalarValue* unicodeString ) const throw( std::bad_alloc, Exception )
        {
            // Check that the pointer is not NULL
            ThrowExceptionIfPointerIsNULL( unicodeString, "UTF16::GetUnicodeStringEncodedAsUTF8 failed - the given pointer to the unicode string is NULL" );

            // Allocate memory space to contain the UTF-16 encoding. An Exception safe pointer is used to make sure
            // if an exception is thrown that the resource will be deleted
            DesignPatterns::SmartPointers::ExceptionSafePointer< UnsignedInteger16bits > UTF16encoding( new UnsignedInteger16bits[ GetTheNumberOfBytesRequiredToEncodeUnicodeStringAsUTF16IMP( unicodeString ) + 2 ], DesignPatterns::SmartPointers::ARRAY_OF_OBJECTS );

            // Check if the system used little or big endian
            if ( true == m_trueForLittleEndianAndFalseForBigEndian )
            {
                // The system uses little endian

                // Set the byte order mark at the beginning of the UTF-16 encoding
                UTF16encoding[0] = 0xFFFE;
            }
            else
            {
                // The system uses big endian

                // Set the byte order mark at the beginning of the UTF-16 encoding
                UTF16encoding[0] = 0xFEFF;
            }

            // Create an object to store the current index in the UTF-16 encoding
            UnsignedInteger64bits UTF16encodingIndex = 1;

            // Loop on the unicode scalar values string and encode them as UTF-16
            for ( UnsignedInteger64bits unicodeStringIndex = 0 ; unicodeString[ unicodeStringIndex ] != 0 ; ++unicodeStringIndex )
            {
                // Encode current unicode scalar value into UTF-16, and increase the index of the UTF-16 encoding according
                // to the number of bytes the current unicde scalar value needed to be encoding as UTF-16
                UTF16encodingIndex += SetTheGivenUnicodeScalarValueEncodedAsUTF16( unicodeString[ unicodeStringIndex ], ( UTF16encoding.GetResource() + UTF16encodingIndex ) );
            }

            // Set the UTF-16 encoding end with NULL
            UTF16encoding[ UTF16encodingIndex ] = 0;

            // Return the UTF-16 encoding
            return ( UTF16encoding.GetResource() );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to decode the UTF-16 string back into the unicode scalar values
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          UTF16encoding - the address of the UTF-16 encoding   
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
        //      2. The UTF-16 is not encoded correctly
        //      3. The UTF-16 does not end with NULL
        //      4. If the given pointer is NULL - class Exception is thrown
        //      5.
        //
        UnicodeScalarValue* UTF16::GetUnicodeString( const UnsignedInteger16bits* UTF16encoding, bool trueForLittleEndianAndFalseForBigEndian ) const throw( std::bad_alloc, Exception )
        {
            // Check that the pointer is not NULL
            ThrowExceptionIfPointerIsNULL( UTF16encoding, "UTF16::GetUnicodeString failed - the given pointer to the utf-16 encoding is NULL" );

            // Allocate memory space to contain the UTF-16 encoding. An Exception safe pointer is used to make sure
            // if an exception is thrown that the resource will be deleted
            DesignPatterns::SmartPointers::ExceptionSafePointer< UnicodeScalarValue > unicodeString( new UnicodeScalarValue[ GetNumberOfUnicodeScalarValuesInUTF16encodingIMP( UTF16encoding ) ], DesignPatterns::SmartPointers::ARRAY_OF_OBJECTS );

            // Create an object to store the index in the unicode string
            UnsignedInteger64bits unicodeStringIndex = 0;

            // Loop on all of the UTF-16 encoded string. Decode the UTF-16 into the unicode scalar value, and store in the unicode string. Add
            // the amount of bytes UTF-16 needed to encode the unicode scalar value to the UTF-16 string index everytime
            for ( UnsignedInteger64bits UTF16stringIndex = 0 ; UTF16encoding[ UTF16stringIndex ] != 0 ; UTF16stringIndex += GetTheUnicodeScalarValueFromUTF16encoding( ( UTF16encoding + UTF16stringIndex ), unicodeString[ unicodeStringIndex ], trueForLittleEndianAndFalseForBigEndian ) )
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
        //      Use to check if the UTF-16 was encoded correctly
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          UTF16encoding - the address of a UTF-16 encoded string
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      1. true - if the UTF-16 string was encoded correctly
        //      2. false - if the UTF-16 string was not encoding correctly
        //
        //  Possible errors :
        //
        //      1. If the given UTF-16 encoding pointer is NULL - class Exception is thrown
        //      2. The UTF-16 does not end with NULL
        //      3.
        //
        bool UTF16::IsUTF16stringEncodedCorrectly( const UnsignedInteger16bits* UTF16encoding ) const throw( Exception )
        {
            // Check that the pointer is not NULL
            ThrowExceptionIfPointerIsNULL( UTF16encoding, "UTF16::IsUTF16stringEncodedCorrectly failed - the given pointer to the utf-16 encoding is NULL" );

            // Check if there is a byte order mark at the beginning of the UTF-16 encoding
            if ( ( 0xFFFE != UTF16encoding[0] ) && ( 0xFEFF != UTF16encoding[0] ) )
            {
                // There is no byte order mark, the UTF-16 is not correctly encoded
                return ( false );
            }

            // Loop on the UTF-16 encoding and check if there are errors
            for ( UnsignedInteger64bits UTF16encodingIndex = 1 ; UTF16encoding[ UTF16encodingIndex ] != 0 ; UTF16encodingIndex += GetTheAmountOfBytesThatWereUsedToEncodeUnicodeScalarValueIntoUTF16IMP( UTF16encoding + UTF16encodingIndex ) )
            {

                // Check if current UTF-16 encoded unicode scalar value is encoded correctly
                if ( false == IsUTF16encodedCorrectly( UTF16encoding + UTF16encodingIndex ) )
                {
                    // The UTF-16 encoded is not correct, return false
                    return ( false );
                }

            }

            // If control reached here the UTF-16 string is encoded correctly
            return ( true );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to check if the UTF-16 was encoded correctly. When the string does not end with NULL and only the size is known
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. UTF16encoding - the address of a UTF-16 encoded string
        //          2. UTF16encodingSize - the size of the UTF-16 encoding
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      1. true - if the UTF-16 string was encoded correctly
        //      2. false - if the UTF-16 string was not encoding correctly
        //
        //  Possible errors :
        //
        //      1. If the given UTF-16 encoding pointer is NULL - class Exception is thrown
        //      2. The given size of the UTF-8 encoding is 0 - class Exception is thrown
        //      3.
        //
        bool UTF16::IsUTF16stringWithSizeEncodedCorrectly( const UnsignedInteger16bits* UTF16encoding, UnsignedInteger64bits UTF16encodingSize ) const throw( Exception )
        {
            // Check that the pointer is not NULL
            ThrowExceptionIfPointerIsNULL( UTF16encoding, "UTF16::IsUTF16stringEncodedCorrectly failed - the given pointer to the utf-16 encoding is NULL" );

            // Check that the UTF-16 encoding size is not 0
            ThrowExceptionIfValueOneIsEqualToValueTwo< UnsignedInteger64bits >( UTF16encodingSize, 0, "UTF16::IsUTF16stringWithSizeEncodedCorrectly failed - the given UTF-16 encoding size is 0" );

            // Check if there is a byte order mark at the beginning of the UTF-16 encoding
            if ( ( 0xFFFE != UTF16encoding[0] ) && ( 0xFEFF != UTF16encoding[0] ) )
            {
                // There is no byte order mark, the UTF-16 is not correctly encoded
                return ( false );
            }

            // Loop on the UTF-16 encoding and check if there are errors
            for ( UnsignedInteger64bits UTF16encodingIndex = 1 ; UTF16encodingIndex < UTF16encodingSize ; UTF16encodingIndex += GetTheAmountOfBytesThatWereUsedToEncodeUnicodeScalarValueIntoUTF16IMP( UTF16encoding + UTF16encodingIndex ) )
            {

                // Check if current UTF-16 encoded unicode scalar value is encoded correctly
                if ( false == IsUTF16encodedCorrectly( UTF16encoding + UTF16encodingIndex ) )
                {
                    // The UTF-16 encoded is not correct, return false
                    return ( false );
                }

            }

            // If control reached here the UTF-16 string is encoded correctly
            return ( true );
        }











//	*****************************************   PRIVATE METHODS IMPLEMENTATION   ******************************************















        // Method Information :
        //
        //  Description :
        //
        //      Use to get the number of bytes the UTF-16 will need to encode the unicode scalar value
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          unicodeScalarValue - the unicdoe scalar value
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      1. 2 - if only 2 bytes were needed to encode as UTF-16
        //      2. 4 - if 4 bytes were needed to encode as UTF-16
        //
        //  Possible errors :
        //
        //      1. The given unicode scalar value is higher then 1114111 - class Exception is thrown
        //      2. 
        //
        UnsignedInteger8bits UTF16::GetTheAmountOfBytesToEncodeUnicodeScalarValueIntoUTF16IMP( UnicodeScalarValue unicodeScalarValue ) const throw()
        {

            // Check the value of the unicode scalar value is less then 65536
            if ( unicodeScalarValue < 65536 )
            {
                // The value is less then 65536 then only 2 bytes are needed
                return ( 2 );
            }

            // The value is higher or equal to 65536, 4 bytes are needed
            return ( 4 );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to get the number of bytes the UTF-16 needed to encode the unicode scalar value
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          UTF16encoding - a pointer to a unicode scalar value encoded as UTF-16
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      1. 1 - if only 2 bytes were needed to encode as UTF-16
        //      2. 2 - if 4 bytes were needed to encode as UTF-16
        //
        //  Possible errors :
        //
        //      1. The given UTF-16 encoding is broken
        //      2. 
        //
        UnsignedInteger8bits UTF16::GetTheAmountOfBytesThatWereUsedToEncodeUnicodeScalarValueIntoUTF16IMP( const UnsignedInteger16bits* UTF16encoding ) const throw()
        {
            // Check that given pointer to the UTF-16 encoding is not NULL
            ThrowExceptionIfPointerIsNULL( UTF16encoding, "UTF16::GetTheAmountOfBytesThatWereUsedToEncodeUnicodeScalarValueIntoUTF16 failed - the given UTF-16 encoding pointer is NULL" );

            // Check if only 2 bytes were needed
            if ( ( UTF16encoding[0] < 55296 ) || ( UTF16encoding[0] > 57343 ) )
            {
                // only 2 bytes were needed
                return ( 1 );
            }

            // 4 bytes were needed
            return ( 2 );
        }


        // Method Information :
        //
        //  Description :
        //
    	// 		Use to store the given unicode scalar value bits into the UTF-16 template. 
    	//		To encode as UTF-16 the given unicode scalar value is subtracted by 65536.
    	//		The reason for the subtraction is that now the value is stored only in 20 bits.
    	//		This only true because the highest unicode scalar value possible is 1114111    
    	//
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. unicodeScalarValue - the unicode scalar value
        //			2. UTF16encoding - the location in memory that the unicode scalar value will be stored as UTF-16
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
    	void UTF16::EncodeTheUnicodeScalarValueIntoTheUTF16templateIMP( UnicodeScalarValue unicodeScalarValue, UnsignedInteger8bits* UTF16encoding ) const throw()
    	{		
    		// Create an object to store the result of subtracting 65536 ( 0x10000 ) from the given unicode scalar value
    		UnicodeScalarValue subtractedUnicodeScalarValue = ( unicodeScalarValue - 65536 );

    		// Create a pointer to help address only 1 of the 2 sets of 2 bytes
    		UnsignedInteger8bits* unicodeScalarValueBytes = reinterpret_cast< UnsignedInteger8bits* >( &subtractedUnicodeScalarValue );

        	// Check if current system uses little or big endian encoding
        	if ( true == m_trueForLittleEndianAndFalseForBigEndian )
        	{
    			// Little endian encoding

    			// Because this is little endian the unicode scalar bytes pointer is pointing to the less significant bits            

                // The first byte of the unicode subtracted scalar value contains the less significant bits, this 8 bits should 
                // be stored in the first byte of the UTF-16 encoding
                UTF16encoding[2] = unicodeScalarValueBytes[0];

                // The second byte of the UTF-16 encoding, contains the 6 template bits, and therefore
                // there are 2 bits left to set. This bits are located in the less significant bits of
                // the second byte of the unicode subtracted scalar value
                UTF16encoding[3] |= ( ( static_cast< UnsignedInteger8bits >( unicodeScalarValueBytes[1] << 6 ) ) >> 6 );

                // Now the second byte of the unicode subtracted scalar value contains the 6 more significant bits that are left
                // to be set into the less significant bits of the first byte in the UTF-16 encoding
                UTF16encoding[0] = ( unicodeScalarValueBytes[1] >> 2 );

                // There are the 2 most significant bits left to set in the first byte of the UTF-16 encoding. 
                // They are located in the third byte of the unicode subtracted scalar value
                UTF16encoding[0] |= ( unicodeScalarValueBytes[2] << 6 );

                // The 2 most signficant bits of the unicode subtracted scalar value are left to store in the
                // second byte of the UTF-16 encoding 
                UTF16encoding[1] |= ( unicodeScalarValueBytes[2] >> 2 );
    		}
    		else
    		{
    			// Big endian encoding

    			// Because this is big endian encoding the unicode scalar bytes pointer is pointing to the most significant bits

                // The last byte of the unicode subtracted scalar value has the less significant 8 bits, which should be stored
                // in the fourth byte of the UTF-16 encoding
                UTF16encoding[3] = unicodeScalarValueBytes[3];

                // The third byte of the UTF-16 encoding has 6 bits used for the UTF-16 template, and only the 2
                // less significant bits are left to be set. This bits are the 2 less significant bits in the third
                // byte of the unicode subtracted scalar value
                UTF16encoding[2] |= ( static_cast< UnsignedInteger8bits >( ( unicodeScalarValueBytes[2] << 6 ) ) >> 6 );

                // The 6 more significant bits left in the third byte of the unicode subtracted scalar value, should be stored
                // in the 6 less significant bits of the second byte of the unicode subtracted scalar value
                UTF16encoding[1] = ( unicodeScalarValueBytes[2] >> 2 );

                // The 2 most significant bits of the second byte in the UTF-16 encoding are left to be set. Take
                // them from the 2 less significant bits of the second byte in the unicode subtracted scalar value
                UTF16encoding[1] |= ( unicodeScalarValueBytes[1] << 6 );

                // The first byte of the UTF-16 encoding has 6 bits used for the UTF-16 template, and only the 2
                // less significant bits are left to be set. This bits are located in the second byte of the 
                // unicode subtracted scalar value
                UTF16encoding[0] |= ( unicodeScalarValueBytes[1] >> 2 );
    		}

    	}


        // Method Information :
        //
        //  Description :
        //
        //		Use to get the unicode scalar value out of the UTF-16 encoding
    	//
        //  Required arguments :
        //
        //      User information needed :
        //
        //			1. UTF16encoding - the address of the UTF-16 encoding
        //			2. unicodeScalarValue - a reference to the location the decoded unicde scalr value should be
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
    	void UTF16::DecodeTheUTF16encodingIntoUnicodeScalarValueIMP( const UnsignedInteger8bits* UTF16encoding, UnicodeScalarValue& unicodeScalarValue ) const throw()
    	{
    		// Create an object to point to the required bytes of the unicode scalar value
    		UnsignedInteger8bits* unicodeScalarValueBytes = reinterpret_cast< UnsignedInteger8bits* >( &unicodeScalarValue );

            // Set the unicode scalar bits off
            unicodeScalarValue = 0;

        	// Check if current system uses little or big endian encoding
        	if ( true == m_trueForLittleEndianAndFalseForBigEndian )
    		{
    			// Little endian encoding

                // Because this is little endian the unicode scalar bytes pointer is pointing to the less significant bits

                // The third byte of the UTF-16 encoding has the less significant bits. Set this 8 bits into
                // the first byte of the unicode scalar value
                unicodeScalarValueBytes[0] = UTF16encoding[2];

                // The fourth byte of the UTF-16 encoding has only 2 bits that should be set into the unicode scalar value
                // and they are the 2 less significant. Set them to the less significant bits of the second byte of the unicode 
                // subtracted scalar value
                unicodeScalarValueBytes[1] = ( ( static_cast< UnsignedInteger8bits >( UTF16encoding[3] << 6 ) ) >> 6 );

                // Set the 6 less significant bits in the first byte of the UTF-16 encoding, to the 6 most significant bits
                // in the second byte of the unicode scalar value
                unicodeScalarValueBytes[1] |= ( UTF16encoding[0] << 2 );

                // Set the 2 most significant bits in the first byte of the UTF-16 encoding, to the 2 less significant bits
                // of the third byte in the unicode scalar value
                unicodeScalarValueBytes[2] = ( UTF16encoding[0] >> 6 );

                // Set the 2 less significant bits in the second byte of the UTF-16 encoding, to the third byte of the
                // unicode scalar value
                unicodeScalarValueBytes[2] |= ( ( static_cast< UnsignedInteger8bits >( UTF16encoding[1] << 6 ) ) >> 4 );
    		}
    		else
    		{
    			// Big endian encoding

                // Because this is big endian encoding the unicode scalar bytes pointer is pointing to the most significant bits

                // The fourth byte of the UTF-16 encoding contains the less significant bits. Set them to the fourth byte of the
                // unicode scalar value
                unicodeScalarValueBytes[3] = UTF16encoding[3];

                // The 2 less significant bits of the third byte of in UTF-16 encoding needs to be stored, in the 2 less significant
                // bits of the third byte in the unicode scalar value
                unicodeScalarValueBytes[2] = ( ( static_cast< UnsignedInteger8bits >( UTF16encoding[2] << 6 ) ) >> 6 );

                // The most significant 6 bits left to set in the unicode scalar value, are stored in the 6 less significant bits
                // in the second byte of the UTF-16 encoding
                unicodeScalarValueBytes[2] |= ( UTF16encoding[1] << 2 );

                // The 2 most significant bits in the second byte of the UTF-16 encoding, should be stored in the 2 less significant
                // bits of the second byte in the unicode scalar value
                unicodeScalarValueBytes[1] = ( UTF16encoding[2] >> 6 );

                // The 2 less significant bits of the first byte in the UTF-16 encoding, needs to be stored in the second byte
                // of the unicode scalar value
                unicodeScalarValueBytes[1] |= ( ( static_cast< UnsignedInteger8bits >( UTF16encoding[2] << 6 ) ) >> 4 );
    		}

    		// Add 65536 to the unicode scalar value
    		unicodeScalarValue += 65536;
    	}


        // Method Information :
        //
        //  Description :
        //
        //      Use to get the number of bytes that will be needed to encode the unicode string as UTF-16
        //
        //  Required arguments :
        //
        //        User information needed :
        //
        //            unicodeString - the address of the unicode string that needs to be encoded into UTF-16
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
        //      3.
        //
        UnsignedInteger64bits UTF16::GetTheNumberOfBytesRequiredToEncodeUnicodeStringAsUTF16IMP( const UnicodeScalarValue* unicodeString ) const throw( Exception )
        {
            // verify that the given unicode string pointer is not NULL
            ThrowExceptionIfPointerIsNULL( unicodeString, "UTF16::GetTheNumberOfBytesRequiredToEncodeUnicodeStringAsUTF16IMP failed - the given unicode string pointer is NULL" );
         
            // Create an object to store the number of bytes required to encode the unicode string as UTF-16
            UnsignedInteger64bits numberOfBytesToEncodeUnicodeStringAsUTF16 = 0;

            // Loop on the string until the NULL is reached
            for ( UnsignedInteger64bits unicodeStringIndex = 0 ; unicodeString[ unicodeStringIndex ] != 0 ; ++unicodeStringIndex )
            {
                // Increase the number of unicode characters by 1
                numberOfBytesToEncodeUnicodeStringAsUTF16 += GetTheAmountOfBytesToEncodeUnicodeScalarValueIntoUTF16IMP( unicodeString[ unicodeStringIndex ] );
            }
        
            // Return the number of bytes required to encode the unicode string as UTF-16 
            return ( numberOfBytesToEncodeUnicodeStringAsUTF16 );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to get the number of unicode scalar values encoded as UTF-16 in the string
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          UTF16encoding - the address of the UTF-16 encoding
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      The amount of unicode scalar values encoded as UTF-16
        //
        //  Possible errors :
        //
        //      1. The object is in default state - class Exception is thrown
        //      2. The UTF-16 encodeing is broken
        //      3. The given pointer is NULL - class Exception is thrown
        //      4. 
        //
        UnsignedInteger64bits UTF16::GetNumberOfUnicodeScalarValuesInUTF16encodingIMP( const UnsignedInteger16bits* UTF16encoding ) const throw( Exception )  
        {
            // verify that the given unicode string pointer is not NULL
            ThrowExceptionIfPointerIsNULL( UTF16encoding, "UTF16::GetNumberOfUnicodeScalarValuesInUTF16encodingIMP failed - the given unicode string pointer is NULL" );
         
            // Create an object to store the number of unicode scalar values encoded as UTF-16
            UnsignedInteger64bits numberOfUnicodeScalarValuesInUnicodeString = 0;

            // Loop on the UTF-16 string and count the number of unicode scalar values encoded
            for ( UnsignedInteger64bits UTF16stringIndex = 0 ; UTF16encoding[ UTF16stringIndex ] != 0 ; UTF16stringIndex += GetTheAmountOfBytesThatWereUsedToEncodeUnicodeScalarValueIntoUTF16IMP( UTF16encoding + UTF16stringIndex ) )
            {
                // Increase the number of unicode scalar values in the unicode string by 1
                numberOfUnicodeScalarValuesInUnicodeString += 1;
            }

            // Return the number of unicode scalar values in the unicode string
            return ( numberOfUnicodeScalarValuesInUnicodeString );
        }      







    }  //  namespace Encoding 

}  //  Namespace Universe


#endif  // DecodeTheUTF16encodingIntoUnicodeScalarValue













