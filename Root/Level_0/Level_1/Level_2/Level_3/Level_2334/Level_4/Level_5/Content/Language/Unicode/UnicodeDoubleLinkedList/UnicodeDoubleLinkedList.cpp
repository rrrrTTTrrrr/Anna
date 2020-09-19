#ifndef  UNICODEDOUBLELINKEDLIST_CPP
#define  UNICODEDOUBLELINKEDLIST_CPP


#include "UnicodeDoubleLinkedList.h"


#include "../../../BasicUtilities/BasicOperations/Bits/BitsOperations.h"  //  Function ReverseBytesOrder



namespace Universe 
{

    namespace Encoding
    {


    	// Forward declarations :
    	//
    	//  NONE
    	//















//	************************************************************   PUBLIC METHODS IMPLEMENTATION - INTERFACE   *******************************************************************





































//  ******************************************************************   OPERATORS IMPLEMENTATION   ******************************************************************************


































//	**************************************************************   PRIVATE METHODS IMPLEMENTATION   ****************************************************************************
























        // Method Information :
        //
        //  Description :
        //
        //      Use this method to transform the UTF encoding ending with NULL into unicdoe scalar values double linked list
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
        void UnicodeDoubleLinkedList::AddUTFencodingToTheEndIMP( const void* UTFencoding, Encoding::EncodingType encodingType ) throw( std::bad_alloc, Exception )
        {
            // Create an object to store the current unicode scalar value 
            UnicodeCharacter unicodeScalarValue = 0;

            // Switch case structure to choose among the UTF encoding options :
            switch ( encodingType )
            {

                // Check if the encoding is UTF-8 or Ascii
                case Ascii :
                case UnicodeTransferFormat_8 :
                {
                    // Create an object to point to the UTF-8
                    const UnsignedInteger8bits* UTF8encoding = reinterpret_cast< const UnsignedInteger8bits* >( UTFencoding );

                    // Loop on all the UTF-8 encoding
                    for ( UnsignedInteger64bits UTF8encodingIndex = 0 ; UTF8encoding[ UTF8encodingIndex ] != 0 ; UTF8encodingIndex += m_UTF8.GetUnicodeScalarValueFromUTF8encoding( ( UTF8encoding + UTF8encodingIndex ), unicodeScalarValue ) )
                    {
                        // Push the unicode scalar value to the end of the array
                        PushTail( unicodeScalarValue );
                    }


                    Display();

                    // Break, all the shit has been taken care of
                    break;
                }

                // Check if the encoding is UTF-16 big endian
                case UnicodeTransferFormat_16BigEndian :
                {
                    // Create an object to point to the UTF-16
                    const UnsignedInteger16bits* UTF16encoding = reinterpret_cast< const UnsignedInteger16bits* >( UTFencoding );

                    // Loop on all the UTF-16 encoding
                    for ( UnsignedInteger64bits UTF16encodingIndex = 0 ; UTF16encoding[ UTF16encodingIndex ] != 0 ; UTF16encodingIndex += m_UTF16.GetTheUnicodeScalarValueFromUTF16encoding( ( UTF16encoding + UTF16encodingIndex ), unicodeScalarValue, false ) )
                    {
                        // Push the unicode scalar value to the end of the array
                        PushTail( unicodeScalarValue );
                    }

                    // Break, all the shit has been taken care of
                    break;
                }

                // Check if the encoding is UTF-16 little endian
                case UnicodeTransferFormat_16LittleEndian :
                {
                    // Create an object to point to the UTF-16
                    const UnsignedInteger16bits* UTF16encoding = reinterpret_cast< const UnsignedInteger16bits* >( UTFencoding );

                    // Loop on all the UTF-16 encoding
                    for ( UnsignedInteger64bits UTF16encodingIndex = 0 ; UTF16encoding[ UTF16encodingIndex ] != 0 ; UTF16encodingIndex += m_UTF16.GetTheUnicodeScalarValueFromUTF16encoding( ( UTF16encoding + UTF16encodingIndex ), unicodeScalarValue, true ) )
                    {
                        // Push the unicode scalar value to the end of the array
                        PushTail( unicodeScalarValue );
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

                        // Check if the system uses little or big endian encoding
                        if ( false == LittleOrBigEndian() )
                        {
                            // The system uses different endian encoding

                            // Set the current unicode scalar value
                            unicodeScalarValue = UTF32LittleEndianEncoding[ UTF32LittleEndianEncodingIndex ];

                            // Reverse the bytes of the unicode scalar value
                            ReverseBytesOrder( &unicodeScalarValue, 4 );
                        }

                        // Push the unicode scalar value to the end of the array
                        PushTail( unicodeScalarValue );
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

                        // Check if the system uses little or big endian encoding
                        if ( true == LittleOrBigEndian() )
                        {
                            // The system uses different endian encoding

                            // Set the current unicode scalar value
                            unicodeScalarValue = UTF32BigEndianEncoding[ UTF32BigEndianEncodingIndex ];

                            // Reverse the bytes of the unicode scalar value
                            ReverseBytesOrder( &unicodeScalarValue, 4 );
                        }

                        // Push the unicode scalar value to the end of the array
                        PushTail( unicodeScalarValue );
                    }

                    // Break, all the shit has been taken care of
                    break;
                }

                default :
                {
                    // The given encoding type is invalid
                    throw( Exception( "UnicodeDoubleLinkedList::AddUTFencodingToTheEndIMP failed - the given encoding type is invalid" ) );
                }

            }

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
        void UnicodeDoubleLinkedList::ThrowExceptionIfNumberOfBytesDoesNotDivideByEncodingTypeWithNoRemainderIMP( UnsignedInteger64bits UTFencodingNumberOfBytes, Encoding::EncodingType encodingType ) throw( Exception )
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
                    ThrowExceptionIfExpressionIsFalse( ( 0 == ( UTFencodingNumberOfBytes % 2 ) ), "UnicodeDoubleLinkedList::ThrowExceptionIfNumberOfBytesDoesNotDivideByEncodingTypeWithNoRemainderIMP failed - the encoding type is UTF-16 and the given size in bytes of the UTF encoding is not even" );

                    // Break, all the shit has been taken care of
                    break;
                }


                // Check if the encoding is UTF-32 little or big endian
                case UnicodeTransferFormat_32LittleEndian :
                case UnicodeTransferFormat_32BigEndian :
                {
                    // The size of the UTF-32 is 4 bytes, then check if the number of bytes divides by 4 with no remainder
                    ThrowExceptionIfExpressionIsFalse( ( 0 == ( UTFencodingNumberOfBytes % 4 ) ), "UnicodeDoubleLinkedList::ThrowExceptionIfNumberOfBytesDoesNotDivideByEncodingTypeWithNoRemainderIMP failed - the encoding type is UTF-32 and the given size in bytes of the UTF encoding does not divide by 4 with no remainder" );

                    // Break, all the shit has been taken care of
                    break;
                }

                default :
                {
                    // The given encoding type is invalid
                    throw( Exception( "UnicodeDoubleLinkedList::ThrowExceptionIfNumberOfBytesDoesNotDivideByEncodingTypeWithNoRemainderIMP failed - the given encoding type is invalid" ) );
                }

            }

        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to transform the UTF encoding with given size into unicdoe scalar values double linked list
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. UTFencoding - the address of the UTF encoding
        //          2. UTFencodingNumberOfBytes - the size of the UTF encoding
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
        void UnicodeDoubleLinkedList::AddUTFencodingWithGivenSizeToTheEndIMP( const void* UTFencoding, UnsignedInteger64bits UTFencodingNumberOfBytes, Encoding::EncodingType encodingType ) throw( std::bad_alloc, Exception )
        {
            // Create an object to store the current unicode scalar value 
            UnicodeCharacter unicodeScalarValue = 0;

            // Switch case structure to choose among the UTF encoding options :
            switch ( encodingType )
            {

                // Check if the encoding is UTF-8 or Ascii
                case Ascii :
                case UnicodeTransferFormat_8 :
                {
                    // Create an object to point to the UTF-8
                    const UnsignedInteger8bits* UTF8encoding = reinterpret_cast< const UnsignedInteger8bits* >( UTFencoding );

                    // Loop on all the UTF-8 encoding
                    for ( UnsignedInteger64bits UTF8encodingIndex = 0 ; UTF8encodingIndex < UTFencodingNumberOfBytes ; UTF8encodingIndex += m_UTF8.GetUnicodeScalarValueFromUTF8encoding( ( UTF8encoding + UTF8encodingIndex ), unicodeScalarValue ) )
                    {
                        // Push the unicode scalar value to the end of the array
                        PushTail( unicodeScalarValue );
                    }

                    Display();

                    // Break, all the shit has been taken care of
                    break;
                }

                // Check if the encoding is UTF-16 big endian
                case UnicodeTransferFormat_16BigEndian :
                {
                    // Create an object to point to the UTF-16
                    const UnsignedInteger16bits* UTF16encoding = reinterpret_cast< const UnsignedInteger16bits* >( UTFencoding );

                    // Create an object to store the number of 2 bytes entries in the UTF encoding
                    UnsignedInteger64bits numberOfTwoBytesEntries = ( UTFencodingNumberOfBytes / 2 );

                    // Loop on all the UTF-16 encoding
                    for ( UnsignedInteger64bits UTF16encodingIndex = 0 ; UTF16encodingIndex < numberOfTwoBytesEntries ; UTF16encodingIndex += m_UTF16.GetTheUnicodeScalarValueFromUTF16encoding( ( UTF16encoding + UTF16encodingIndex ), unicodeScalarValue, false ) )
                    {
                        // Push the unicode scalar value to the end of the array
                        PushTail( unicodeScalarValue );
                    }

                    // Break, all the shit has been taken care of
                    break;
                }

                // Check if the encoding is UTF-16 little endian
                case UnicodeTransferFormat_16LittleEndian :
                {
                    // Create an object to point to the UTF-16
                    const UnsignedInteger16bits* UTF16encoding = reinterpret_cast< const UnsignedInteger16bits* >( UTFencoding );

                    // Create an object to store the number of 2 bytes entries in the UTF encoding
                    UnsignedInteger64bits numberOfTwoBytesEntries = ( UTFencodingNumberOfBytes / 2 );

                    // Loop on all the UTF-16 encoding
                    for ( UnsignedInteger64bits UTF16encodingIndex = 0 ; UTF16encodingIndex < numberOfTwoBytesEntries ; UTF16encodingIndex += m_UTF16.GetTheUnicodeScalarValueFromUTF16encoding( ( UTF16encoding + UTF16encodingIndex ), unicodeScalarValue, true ) )
                    {
                        // Push the unicode scalar value to the end of the array
                        PushTail( unicodeScalarValue );
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

                        // Check if the system uses little or big endian encoding
                        if ( false == LittleOrBigEndian() )
                        {
                            // The system uses different endian encoding

                            // Set the current unicode scalar value
                            unicodeScalarValue = UTF32LittleEndianEncoding[ UTF32LittleEndianEncodingIndex ];

                            // Reverse the bytes of the unicode scalar value
                            ReverseBytesOrder( &unicodeScalarValue, 4 );
                        }

                        // Push the unicode scalar value to the end of the array
                        PushTail( unicodeScalarValue );
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

                        // Check if the system uses little or big endian encoding
                        if ( true == LittleOrBigEndian() )
                        {
                            // The system uses different endian encoding

                            // Set the current unicode scalar value
                            unicodeScalarValue = UTF32BigEndianEncoding[ UTF32BigEndianEncodingIndex ];

                            // Reverse the bytes of the unicode scalar value
                            ReverseBytesOrder( &unicodeScalarValue, 4 );
                        }

                        // Push the unicode scalar value to the end of the array
                        PushTail( unicodeScalarValue );
                    }

                    // Break, all the shit has been taken care of
                    break;
                }

                default :
                {
                    // The given encoding type is invalid
                    throw( Exception( "UnicodeDoubleLinkedList::AddUTFencodingWithGivenSizeToTheEndIMP failed - the given encoding type is invalid" ) );
                }

            }

        }





















// *************************************************   NESTED CLASS PRIVATE METHODS IMPLEMENTATION -  UnicodeDoubleLinkedListProxy  **********************************************




















    }  //  Namespace Encoding

}  //  Namespace Universe

#endif  //  UNICODEDOUBLELINKEDLIST_CPP





