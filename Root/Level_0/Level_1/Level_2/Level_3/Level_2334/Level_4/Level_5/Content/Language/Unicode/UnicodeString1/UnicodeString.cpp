#ifndef  UNICODESTRING_CPP
#define  UNICODESTRING_CPP


#include "UnicodeString.h"


#include "../../../BasicUtilities/BasicOperations/Bits/BitsOperations.h"  //  Function ReverseBytesOrder



namespace Universe 
{

    namespace Encoding
    {


        // Forward declarations :
        //
        //  NONE
        //















//	************************************   PUBLIC METHODS IMPLEMENTATION - INTERFACE   ************************************
















        // Method Information :
        //
        //  Description :
        //
        //      Use to change the unicode string
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. UTFencoding - the address of the UTF encoding
        //          2. encodingType - this will be used to determine the UTF encoding
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      1. The given pointer is NULL - class Exception is thrown
        //      2. There is no more free memory space - class std::bad_alloc is thrown
        //      3. 
        //
        inline void UnicodeString::SetNewUnicodeString( const void* newUTFencoding, Encoding::EncodingType newEncodingType ) throw( std::bad_alloc, Exception )
        {
            // Check that the pointer is not NULL
            ThrowExceptionIfPointerIsNULL( newUTFencoding, "UnicodeString::SetNewUnicodeString failed - the given pointer is NULL" );

            // Delete the old unicode string
            DeleteResourcesAndSetToDefaultState();

            // The UTF encoding options are : Ascii, UTF-8, UTF-16 little and big endian, UTF-32 little and big endian

            // Get the unicode scalar values string from the UTF encdoing
            AddUTFencodingToTheEndIMP( newUTFencoding, newEncodingType );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to change the unicode string with size given ( instead of NULL at the end )
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. UTFencoding - the address of the UTF encoding
        //          2. UTFencodingNumberOfBytes - the number of bytes in the UTF encoding
        //          3. encodingType - this will be used to determine the UTF encoding
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      1. The given pointer is NULL - class Exception is thrown
        //      2. There is no more free memory space - class std::bad_alloc is thrown
        //      3. The given size of the UTF encoding is 0 - class Exception is thrown
        //      4. 
        //
        inline void UnicodeString::SetNewUnicodeStringWithSize( const void* newUTFencoding, UnsignedInteger64bits newUTFencodingNumberOfBytes, Encoding::EncodingType newEncodingType ) throw( std::bad_alloc, Exception )
        {
            // Check that the pointer is not NULL
            ThrowExceptionIfPointerIsNULL( newUTFencoding, "UnicodeString::SetNewUnicodeString failed - the given pointer is NULL" );

            // Check that the given number of bytes in the UTF encoding is not 0
            ThrowExceptionIfValueOneIsEqualToValueTwo< UnsignedInteger64bits >( newUTFencodingNumberOfBytes, 0, "UnicodeString::SetNewUnicodeStringWithSize failed - the given size of the UTF encoding is 0" );

            // Check that the number of bytes in the UTF encoding divides by the encoding type with no remainder
            ThrowExceptionIfNumberOfBytesDoesNotDivideByEncodingTypeWithNoRemainderIMP( newUTFencodingNumberOfBytes, newEncodingType );

            // Delete the old unicode string
            DeleteResourcesAndSetToDefaultState();

            // The UTF encoding options are : Ascii, UTF-8, UTF-16 little and big endian, UTF-32 little and big endian

            // Get the unicode scalar values string from the UTF encdoing
            AddUTFencodingWithGivenSizeToTheEndIMP( newUTFencoding, newUTFencodingNumberOfBytes, newEncodingType );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to get the unicode string encoded as UTF-32
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
        //      The address of the unicode string encoded as UTF-32
        //
        //      Note - the responsibility for deleting the memory space is on the user
        //
        //  Possible errors :
        //
        //      1. The object is in default state - class Exception is thrown
        //      2. 
        //
        inline UnicodeCharacter* UnicodeString::GetUnicodeStringEncodedAsUTF32() const throw( std::bad_alloc, Exception )
        {
            // Check that this object is not in default state
            ThrowExceptionIfExpressionIsTrue( DefaultState(), "UnicodeString::GetUnicodeStringEncodedAsUTF32 failed - the object is in default state" );

            // Create an object to store the number of unicode scalar values encoded in the unicode string
            UnsignedInteger64bits numberOfUnicodeCharacters = ( m_unicodeString.GetSize() - 1 );

            // Allocate memory space to contain the UTF-32 encoding
            UnicodeCharacter* UTF32encoding = new UnicodeCharacter[ numberOfUnicodeCharacters + 2 ];

            // Check if the system uses little or big endian
            if ( true == LittleOrBigEndian() )
            {
                // The system used little endian

                // Set the byte order mark into the beginning of the little endian UTF-32 encoding
                UTF32encoding[0] = 0xFFFE0000;   
            }
            else
            {
                // The system used big endian
                
                // Set the byte order mark into the beginning of the big endian UTF-32 encoding
                UTF32encoding[0] = 0x0000FEFF;   
            }

            // Loop on the unicode string
            for ( UnsignedInteger64bits unicodeStringIndex = 0 ; m_unicodeString[ unicodeStringIndex ] != 0 ; ++unicodeStringIndex )
            {
                // Set current unicode scalar value into the UTF-32 encoding
                UTF32encoding[ unicodeStringIndex + 1 ] = m_unicodeString[ unicodeStringIndex ];
            }

            // Set the end of the UTF-32 encdoing with NULL
            UTF32encoding[ numberOfUnicodeCharacters + 1 ] = 0;

            // Return the UTF-32 encoding
            return ( UTF32encoding );
        }




















//  ******************************************************************   OPERATORS IMPLEMENTATION   ******************************************************************************






























//	***************************************************************   PRIVATE METHODS IMPLEMENTATION   ***************************************************************************




















        // Method Information :
        //
        //  Description :
        //
        //      Use this method to transform the UTF encoding into unicdoe scalar values string   
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. UTFencoding - the address of the UTF encoding
        //          2. encodingType - this will be used to determine the UTF encoding
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      1. There is no more free memory space - class std::bad_alloc is thrown
        //      2.
        //
        void UnicodeString::AddUTFencodingToTheEndIMP( const void* UTFencoding, Encoding::EncodingType encodingType ) throw( std::bad_alloc, Exception )
        {

            // Switch case structure to choose among the UTF encoding options :
            switch ( encodingType )
            {

                // Check if the encoding is UTF-8 or Ascii
                case Ascii :
                case UnicodeTransferFormat_8 :
                {
                    // Create an object to point to the UTF-8
                    const UnsignedInteger8bits* UTF8encoding = reinterpret_cast< const UnsignedInteger8bits* >( UTFencoding );

                    // Create an object to store the current unicode scalar value 
                    UnicodeCharacter unicodeScalarValue = 0;

                    // Loop on all the UTF-8 encoding
                    for ( UnsignedInteger64bits UTF8encodingIndex = 0 ; UTF8encoding[ UTF8encodingIndex ] != 0 ; UTF8encodingIndex += m_UTF8.GetUnicodeScalarValueFromUTF8encoding( ( UTF8encoding + UTF8encodingIndex ), unicodeScalarValue ) )
                    {
                        // Push the unicode scalar value to the end of the array
                        m_unicodeString.PushTail( unicodeScalarValue );
                    }

                    // Break, all the shit has been taken care of
                    break;
                }

                // Check if the encoding is UTF-16 big endian
                case UnicodeTransferFormat_16BigEndian :
                {
                    // Create an object to point to the UTF-16
                    const UnsignedInteger16bits* UTF16encoding = reinterpret_cast< const UnsignedInteger16bits* >( UTFencoding );

                    // Create an object to store the current unicode scalar value 
                    UnicodeCharacter unicodeScalarValue = 0;

                    // Loop on all the UTF-16 encoding
                    for ( UnsignedInteger64bits UTF16encodingIndex = 0 ; UTF16encoding[ UTF16encodingIndex ] != 0 ; UTF16encodingIndex += m_UTF16.GetTheUnicodeScalarValueFromUTF16encoding( ( UTF16encoding + UTF16encodingIndex ), unicodeScalarValue, false ) )
                    {
                        // Push the unicode scalar value to the end of the array
                        m_unicodeString.PushTail( unicodeScalarValue );
                    }

                    // Break, all the shit has been taken care of
                    break;
                }

                // Check if the encoding is UTF-16 little endian
                case UnicodeTransferFormat_16LittleEndian :
                {
                    // Create an object to point to the UTF-16
                    const UnsignedInteger16bits* UTF16encoding = reinterpret_cast< const UnsignedInteger16bits* >( UTFencoding );

                    // Create an object to store the current unicode scalar value 
                    UnicodeCharacter unicodeScalarValue = 0;

                    // Loop on all the UTF-16 encoding
                    for ( UnsignedInteger64bits UTF16encodingIndex = 0 ; UTF16encoding[ UTF16encodingIndex ] != 0 ; UTF16encodingIndex += m_UTF16.GetTheUnicodeScalarValueFromUTF16encoding( ( UTF16encoding + UTF16encodingIndex ), unicodeScalarValue, true ) )
                    {
                        // Push the unicode scalar value to the end of the array
                        m_unicodeString.PushTail( unicodeScalarValue );
                    }

                    // Break, all the shit has been taken care of
                    break;
                }

                // Check if the encoding is UTF-32 little endian
                case UnicodeTransferFormat_32LittleEndian :
                {
                    // Create an object to point to the UTF-32 little endian
                    const UnicodeCharacter* UTF32LittleEndianEncoding = reinterpret_cast< const UnicodeCharacter* >( UTFencoding );

                    // Loop on all the UTF-32 little endian encoding
                    for ( UnsignedInteger64bits UTF32LittleEndianEncodingIndex = 0 ; UTF32LittleEndianEncoding[ UTF32LittleEndianEncodingIndex ] != 0 ; ++UTF32LittleEndianEncodingIndex )
                    {
                        // Push the unicode scalar value to the end of the array
                        m_unicodeString.PushTail( UTF32LittleEndianEncoding[ UTF32LittleEndianEncodingIndex ] );

                        // Check if the system uses little or big endian encoding
                        if ( false == LittleOrBigEndian() )
                        {
                            // The system uses different endian encoding, reverse the unicode scalar value
                            ReverseBytesOrder( ( m_unicodeString.GetHandleToBasicTypesArray() + UTF32LittleEndianEncodingIndex ), 4 );
                        }

                    }

                    // Break, all the shit has been taken care of
                    break;
                }

                // Check if the encoding is UTF-32 big endian
                case UnicodeTransferFormat_32BigEndian :
                {
                    // Create an object to point to the UTF-32
                    const UnicodeCharacter* UTF32BigEndianEncoding = reinterpret_cast< const UnicodeCharacter* >( UTFencoding );

                    // Loop on all the UTF-32 encoding
                    for ( UnsignedInteger64bits UTF32BigEndianEncodingIndex = 0 ; UTF32BigEndianEncoding[ UTF32BigEndianEncodingIndex ] != 0 ; ++UTF32BigEndianEncodingIndex )
                    {
                        // Push the unicode scalar value to the end of the array
                        m_unicodeString.PushTail( UTF32BigEndianEncoding[ UTF32BigEndianEncodingIndex ] );

                        // Check if the system uses big or big endian encoding
                        if ( true == LittleOrBigEndian() )
                        {
                            // The system uses different endian encoding, reverse the unicode scalar value
                            ReverseBytesOrder( ( m_unicodeString.GetHandleToBasicTypesArray() + UTF32BigEndianEncodingIndex ), 4 );
                        }

                    }

                    // Break, all the shit has been taken care of
                    break;
                }

                default :
                {
                    // The given encoding type is invalid
                    throw( Exception( "UnicodeString::AddUTFencodingToTheEndIMP failed - the given encoding type is invalid" ) );
                }

            }

            // Add NULL to the end of the array
            m_unicodeString.PushTail( 0 );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to throw an exception if the given size in bytes of the UTF encoding divides by the encoding type with no remainder
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. UTFencodingNumberOfBytes - the size of the UTF encoding
        //          2. encodingType - this will be used to determine the UTF encoding
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      1. If the given size in bytes of the UTF encoding divides by the encoding type with no remainder - class Exception is thrown
        //      2.
        //
        void UnicodeString::ThrowExceptionIfNumberOfBytesDoesNotDivideByEncodingTypeWithNoRemainderIMP( UnsignedInteger64bits UTFencodingNumberOfBytes, Encoding::EncodingType encodingType ) throw( Exception )
        {

            // Switch case structure to choose among the UTF encoding options :
            switch ( encodingType )
            {

                // Check if the encoding is UTF-8 or Ascii
                case Ascii :
                case UnicodeTransferFormat_8 :
                {   
                    // Ascii characters consist of 1 byte which divides with no remainder

                    // UTF-8 has a size that can be from 1 to 4 bytes, therefore this check has no meaning in this point

                    // Break, all the shit has been taken care of
                    break;
                }

                // Check if the encoding is UTF-16 big or little endian
                case UnicodeTransferFormat_16BigEndian :
                case UnicodeTransferFormat_16LittleEndian :
                {
                    // The size of the UTF-16 can be be 2 or 4 bytes, then check if the number of bytes is even
                    ThrowExceptionIfExpressionIsFalse( ( 0 == ( UTFencodingNumberOfBytes % 2 ) ), "UnicodeString::ThrowExceptionIfNumberOfBytesDoesNotDivideByEncodingTypeWithNoRemainderIMP failed - the encoding type is UTF-16 and the given size in bytes of the UTF encoding is not even" );

                    // Break, all the shit has been taken care of
                    break;
                }


                // Check if the encoding is UTF-32 little or big endian
                case UnicodeTransferFormat_32LittleEndian :
                case UnicodeTransferFormat_32BigEndian :
                {
                    // The size of the UTF-32 is 4 bytes, then check if the number of bytes divides by 4 with no remainder
                    ThrowExceptionIfExpressionIsFalse( ( 0 == ( UTFencodingNumberOfBytes % 4 ) ), "UnicodeString::ThrowExceptionIfNumberOfBytesDoesNotDivideByEncodingTypeWithNoRemainderIMP failed - the encoding type is UTF-32 and the given size in bytes of the UTF encoding does not divide by 4 with no remainder" );

                    // Break, all the shit has been taken care of
                    break;
                }

                default :
                {
                    // The given encoding type is invalid
                    throw( Exception( "UnicodeString::ThrowExceptionIfNumberOfBytesDoesNotDivideByEncodingTypeWithNoRemainderIMP failed - the given encoding type is invalid" ) );
                }

            }

        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to transform the UTF endoing into unicdoe scalar values string   
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. UTFencoding - the address of the UTF encoding
        //          2. UTFencodingNumberOfBytes - the number of bytes in the UTF encoding
        //          3. encodingType - this will be used to determine the UTF encoding
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      1. There is no more free memory space - class std::bad_alloc is thrown
        //      2.
        //
        void UnicodeString::AddUTFencodingWithGivenSizeToTheEndIMP( const void* UTFencoding, UnsignedInteger64bits UTFencodingNumberOfBytes, Encoding::EncodingType encodingType ) throw( std::bad_alloc, Exception )
        {

            // Switch case structure to choose among the UTF encoding options :
            switch ( encodingType )
            {

                // Check if the encoding is UTF-8 or Ascii
                case Ascii :
                case UnicodeTransferFormat_8 :
                {
                    // Create an object to point to the UTF-8
                    const UnsignedInteger8bits* UTF8encoding = reinterpret_cast< const UnsignedInteger8bits* >( UTFencoding );

                    // Create an object to store the current unicode scalar value 
                    UnicodeCharacter unicodeScalarValue = 0;

                    // Loop on all the UTF-8 encoding
                    for ( UnsignedInteger64bits UTF8encodingIndex = 0 ; UTF8encodingIndex < UTFencodingNumberOfBytes ; UTF8encodingIndex += m_UTF8.GetUnicodeScalarValueFromUTF8encoding( ( UTF8encoding + UTF8encodingIndex ), unicodeScalarValue ) )
                    {
                        // Push the unicode scalar value to the end of the array
                        m_unicodeString.PushTail( unicodeScalarValue );
                    }

                    // Break, all the shit has been taken care of
                    break;
                }

                // Check if the encoding is UTF-16 big endian
                case UnicodeTransferFormat_16BigEndian :
                {
                    // Create an object to point to the UTF-16
                    const UnsignedInteger16bits* UTF16encoding = reinterpret_cast< const UnsignedInteger16bits* >( UTFencoding );

                    // Create an object to store the current unicode scalar value 
                    UnicodeCharacter unicodeScalarValue = 0;

                    // Create an object to store the number of 2 bytes entries in the UTF encoding
                    UnsignedInteger64bits numberOfTwoBytesEntries = ( UTFencodingNumberOfBytes / 2 );

                    // Loop on all the UTF-16 encoding
                    for ( UnsignedInteger64bits UTF16encodingIndex = 0 ; UTF16encodingIndex < numberOfTwoBytesEntries ; UTF16encodingIndex += m_UTF16.GetTheUnicodeScalarValueFromUTF16encoding( ( UTF16encoding + UTF16encodingIndex ), unicodeScalarValue, false ) )
                    {
                        // Push the unicode scalar value to the end of the array
                        m_unicodeString.PushTail( unicodeScalarValue );
                    }

                    // Break, all the shit has been taken care of
                    break;
                }

                // Check if the encoding is UTF-16 little endian
                case UnicodeTransferFormat_16LittleEndian :
                {
                    // Create an object to point to the UTF-16
                    const UnsignedInteger16bits* UTF16encoding = reinterpret_cast< const UnsignedInteger16bits* >( UTFencoding );

                    // Create an object to store the current unicode scalar value 
                    UnicodeCharacter unicodeScalarValue = 0;

                    // Create an object to store the number of 2 bytes entries in the UTF encoding
                    UnsignedInteger64bits numberOfTwoBytesEntries = ( UTFencodingNumberOfBytes / 2 );

                    // Loop on all the UTF-16 encoding
                    for ( UnsignedInteger64bits UTF16encodingIndex = 0 ; UTF16encodingIndex < numberOfTwoBytesEntries ; UTF16encodingIndex += m_UTF16.GetTheUnicodeScalarValueFromUTF16encoding( ( UTF16encoding + UTF16encodingIndex ), unicodeScalarValue, true ) )
                    {
                        // Push the unicode scalar value to the end of the array
                        m_unicodeString.PushTail( unicodeScalarValue );
                    }

                    // Break, all the shit has been taken care of
                    break;
                }

                // Check if the encoding is UTF-32 little endian
                case UnicodeTransferFormat_32LittleEndian :
                {
                    // Create an object to point to the UTF-32 little endian
                    const UnicodeCharacter* UTF32LittleEndianEncoding = reinterpret_cast< const UnicodeCharacter* >( UTFencoding );

                    // Create an object to store the number of 4 bytes entries in the UTF encoding
                    UnsignedInteger64bits numberOfFourBytesEntries = ( UTFencodingNumberOfBytes / 4 );

                    // Loop on all the UTF-32 little endian encoding
                    for ( UnsignedInteger64bits UTF32LittleEndianEncodingIndex = 0 ; UTF32LittleEndianEncodingIndex < numberOfFourBytesEntries ; ++UTF32LittleEndianEncodingIndex )
                    {
                        // Push the unicode scalar value to the end of the array
                        m_unicodeString.PushTail( UTF32LittleEndianEncoding[ UTF32LittleEndianEncodingIndex ] );

                        // Check if the system uses little or big endian encoding
                        if ( false == LittleOrBigEndian() )
                        {
                            // The system uses different endian encoding, reverse the unicode scalar value
                            ReverseBytesOrder( ( m_unicodeString.GetHandleToBasicTypesArray() + UTF32LittleEndianEncodingIndex ), 4 );
                        }

                    }

                    // Break, all the shit has been taken care of
                    break;
                }

                // Check if the encoding is UTF-32 big endian
                case UnicodeTransferFormat_32BigEndian :
                {
                    // Create an object to point to the UTF-32
                    const UnicodeCharacter* UTF32BigEndianEncoding = reinterpret_cast< const UnicodeCharacter* >( UTFencoding );

                    // Create an object to store the number of 4 bytes entries in the UTF encoding
                    UnsignedInteger64bits numberOfFourBytesEntries = ( UTFencodingNumberOfBytes / 4 );

                    // Loop on all the UTF-32 encoding
                    for ( UnsignedInteger64bits UTF32BigEndianEncodingIndex = 0 ; UTF32BigEndianEncodingIndex < numberOfFourBytesEntries ; ++UTF32BigEndianEncodingIndex )
                    {
                        // Push the unicode scalar value to the end of the array
                        m_unicodeString.PushTail( UTF32BigEndianEncoding[ UTF32BigEndianEncodingIndex ] );

                        // Check if the system uses big or big endian encoding
                        if ( true == LittleOrBigEndian() )
                        {
                            // The system uses different endian encoding, reverse the unicode scalar value
                            ReverseBytesOrder( ( m_unicodeString.GetHandleToBasicTypesArray() + UTF32BigEndianEncodingIndex ), 4 );
                        }

                    }

                    // Break, all the shit has been taken care of
                    break;
                }

                default :
                {
                    // The given encoding type is invalid
                    throw( Exception( "UnicodeString::AddUTFencodingWithGivenSizeToTheEndIMP failed - the given encoding type is invalid" ) );
                }

            }

            // Add NULL to the end of the array
            m_unicodeString.PushTail( 0 );
        }





    }  //  Namespace Encoding

}  //  Namespace Universe

#endif  //  UNICODESTRING_CPP





