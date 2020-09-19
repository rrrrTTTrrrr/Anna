#ifndef  GETENCODING_CPP
#define  GETENCODING_CPP


#include "GetEncoding.h"


#include "../Unicode/UnicodeTransferFormat_8/UTF8.h"  //  Class UTF8
#include "../../GeneralPurposeContainers/Array/ArrayForBasicTypes/FixedSizeArray.h"  //  Class FixedSizeArray



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
        //      Use this method to check what the encoding of the current text is
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. text - a pointer to the beginning of the text that the encoding is not known
        //          2. numberOfBytesInText - the number of bytes the text is stored on        
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      1. EncodingType enum - if the encoding of the text was found
        //      2. The EncodingType enum Unknown - if the encoding of the text was not found
        //
        //  Possible errors :
        //
        //      1. The given pointer is NULL - class Exception is thrown
        //      2. The given size of the text is 0 - class Exception is thrown
        //      3. 
        //
        EncodingType GetEncoding::WhatIsTheEncodingOfTheText( const UnsignedInteger8bits* text, UnsignedInteger64bits numberOfBytesInText ) throw( std::bad_alloc, Exception )
        {
            // Check that the pointer is not NULL
            ThrowExceptionIfPointerIsNULL( text, "GetEncoding::WhatIsTheEncodingOfTheText failed - the given pointer to the text is NULL" );

            // Check that the text size is not 0
            ThrowExceptionIfValueOneIsEqualToValueTwo< UnsignedInteger64bits >( numberOfBytesInText, 0, "GetEncoding::WhatIsTheEncodingOfTheText failed - the given text size is 0" );

            // Create an object to store the encoding type enum returned from the methods that used to get the encoding
            EncodingType encodingType = Unknown;

            // Try to check if a byte order mark exist
            encodingType = GetEncodingUsingByteOrderMarkIMP( text );

            // Check if the encoding was found
            if ( Unknown != encodingType )
            {
                // The encoding was found
                return ( encodingType );
            }

            // If control reached here there is no byte order mark

            // Try to guess the encoding of the text
            return ( GuessEncodingIMP( text, numberOfBytesInText ) );
        }



















//	*****************************************   PRIVATE METHODS IMPLEMENTATION   ******************************************



















        // Method Information :
        //
        //  Description :
        //
        //      This method uses the byte order mark for detecting the type of the encoding
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          byteOrderMark - a pointer to the beginning of the text that the encoding is not known
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      1. EncodingType enum - if a byte order mark exist, and the encoding of the text was found
        //      2. The EncodingType enum Unknown - if a byte order mark does not exist
        //
        //  Possible errors :
        //
        //      They will come
        //
        EncodingType GetEncoding::GetEncodingUsingByteOrderMarkIMP( const UnsignedInteger8bits* byteOrderMark ) throw()
        {

            // Switch case structure to choose among the various options for byte order mark in the first byte of the text
            switch( byteOrderMark[0] )
            {

                // Only UTF-32 big endian has the first byte with this value            
                case 0x00 :
                {

                    // Check if the ending 3 bytes also match the UTF-32 big endian byte order mark
                    if ( ( 0x00 == byteOrderMark[1] ) && ( 0xFE == byteOrderMark[2] ) && ( 0xFF == byteOrderMark[3] ) )
                    {
                        // The text is encoded as UTF-32 big endian

                        // Return the UTF-32 big endian enumeration
                        return( UnicodeTransferFormat_32BigEndian );
                    }

                    // Nothing else needs to be done, just break
                    break;
                }

                // Only UTF-8 has the first byte with this value
                case 0xEF :
                {

                    // Check that the second and third byte also match the UTF-8 byte order mark
                    if ( ( 0xBB == byteOrderMark[1] ) && ( 0xBF == byteOrderMark[2] ) )
                    {
                        // The text is encoded as UTF-8

                        // Return the UTF-8 enumeration
                        return ( UnicodeTransferFormat_8 );
                    }
                    else

                    // Nothing else needs to be done, just break
                    break;
                }

                // Only UTF-16 big endian has the first byte with this value
                case 0xFE :
                {

                    // Check that the second byte also match the UTF-16 big endian byte order mark
                    if ( 0xFF == byteOrderMark[1] )
                    {
                        // The text is encoded as UTF-16 big endian

                        // Return the UTF-16 big endian enumeration
                        return ( UnicodeTransferFormat_16BigEndian );
                    }

                    // Nothing else needs to be done, just break
                    break;
                }

                // UTF-16 little endian, and UTF-32 little endian can have this value in the first byte
                case 0xFF :
                {

                    // UTF-16 little endian and UTF-32 little endian, both has also the second byte with the same value
                    if ( 0xFE == byteOrderMark[1] )
                    {
                        // So far UTF-16 little endian and UTF-32 little endian match

                        // Check if the value in the third and fourth byte match the UTF-32 little endian byte order mark
                        if ( ( 0x00 == byteOrderMark[2] ) && ( 0x00 == byteOrderMark[3] ) )
                        {
                            // The text is encoded as UTF-32 little endian

                            // Return the UTF-32 little endian enumeration
                            return ( UnicodeTransferFormat_32LittleEndian );
                        }
                        else
                        {
                            // The text is encoded as UTF-16 little endian

                            // Return the UTF-16 little endian enumeration
                            return ( UnicodeTransferFormat_16LittleEndian );
                        }

                    }

                    // Nothing else needs to be done, just break
                    break;
                }

                default :
                {
                    // There is no byte order mark
                    break;
                }

            }

            // There is no byte order mark, and therefore the encoding is not known
            return ( Unknown );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to get the encoding when there is no byte order mark. The method does not
        //      guarantee that the encoding will be resolved, only best affort
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. text - a pointer to the beginning of the text that the encoding is not known
        //          2. numberOfBytesInText - the number of bytes the text is stored on
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //        
        //      1. EncodingType enum - if a byte order mark exist, and the encoding of the text was found
        //      2. The EncodingType enum Unknown - if the encoding is not known
        //
        //  Possible errors :
        //
        //      They will come
        //
        EncodingType GetEncoding::GuessEncodingIMP( const UnsignedInteger8bits* text, UnsignedInteger64bits numberOfBytesInText ) throw()
        {
            // In UTF-8 there can not be a byte with all the bits off ( 0 ), except for the NULL terminator. Then if a byte with all
            // the bits off ( 0 ) exist in the text, then the encoding of the text is not UTF-8. Furhtermore, if a byte with the most
            // significant bit on ( 1 ) exist in the text, for UTF-8 it means that the template exist, and then it can be certain if 
            // the encoding is UTF-8 or not. In UTF-32 there must be bytes with all the bits off ( 0 ), because otherwise every 4 bytes
            // will store a value larger then the unicode limit of 1114111

            // Check that number of bytes in the text divides by 2 with no remainder, if it doesn't then this is not UTF-16 or UTF-32,
            // and then the encoding of the text is UTF-8
            IF_EXPRESSION_IS_FALSE_RETURN_VALUE( ( 0 == ( numberOfBytesInText % 2 ) ), UnicodeTransferFormat_8 )

            // Create an object to store the encoding type enum returned from the methods that used to get the encoding
            EncodingType encodingType = Unknown;

            // Create a byte that has only the most significant bit on ( 1 )
            UnsignedInteger8bits byteWithMostSignificantBitOn = ( 1 << 7 );

            // Create an object to store if a byte with all bits off ( 0 ) exist in the text
            bool trueForByteWithAllBitsOffExistAndFalseForNotExist = false;

            // Create an object to store if a byte that has the most significant bit on ( 1 )
            bool trueForByteWithMostSignificantBitOnAndFalseForNot = false;

            // Create an object to store the address of the byte with the most significant bit on ( 1 )
            UnsignedInteger64bits byteWithMostSignificantBitOnIndex = 0;

            // Loop on all the bytes of the text
            for ( UnsignedInteger64bits textIndex = 0 ; textIndex < numberOfBytesInText ; ++textIndex )
            {

                // Check if the most significant bit of current byte is on ( 1 )
                if ( 1 == ( text[ textIndex ] & byteWithMostSignificantBitOn ) )
                {
                    // The most significant bit is on ( 1 ), then there is a chance that this is a UTF template

                    // Set that a byte with the most significant bit on ( 1 ) exist in the text
                    trueForByteWithMostSignificantBitOnAndFalseForNot = true;

                    // Store the index of this byte
                    byteWithMostSignificantBitOnIndex = textIndex;
                }
                // Check if the current byte has all the bits off ( 0 )
                else if ( 0 == text[ textIndex ] )
                {
                    // All the bits of this byte are off ( 0 )

                    // Set that a byte with all the bytes off ( 0 ) exist in the text
                    trueForByteWithAllBitsOffExistAndFalseForNotExist = true;
                }

            }

            // Check if a byte with all the bits off was found
            if ( true == trueForByteWithAllBitsOffExistAndFalseForNotExist )
            {
                // A byte with all the bits off ( 0 ) exist, then the text is not encoded as UTF-8

                // Check if the encoding is UTF-32
                encodingType = DoesTextEncodedInUTF32IMP( text, numberOfBytesInText );

                // Check the return value from checking the UTF-32 requirments on the text

                // Check if the encoding was found
                if ( ( UnicodeTransferFormat_32BigEndian == encodingType ) || ( UnicodeTransferFormat_32LittleEndian == encodingType ) )
                {
                    // The text encoding was resolved, return it
                    return ( encodingType );
                }

                // Check if the UTF-32 can be excluded
                if ( Unknown != encodingType )
                {
                    // The algorithm could not exclude the UTF-32 encoding, return that the encoding of the text is unknown
                    return ( Unknown );
                }

            }
            // Check if a byte with the most significant bit on ( 1 ) exist in the text, but not a byte with all the bits off ( 0 )
            else if ( true == trueForByteWithMostSignificantBitOnAndFalseForNot )
            {
                // A byte with the most significant bit on ( 1 ) exist in the text, but not a byte with all the bits off ( 0 ).
                // This means that the text can not be encoded in UTF-32, because UTF-32 must have bytes with all bits off ( 0 )
                // or otherwise the values inside will exceed the unicode limit of 1114111. Furthermore, in UTF-8 only if there
                // is the template, the most significant bit of a byte will be on ( 1 ), therefore it can be determined if the
                // encoding is UTF-8 or not for certain

                // Try to exclude UTF-8

                // Check if the text matches the UTF-8 requirements
                if ( true == UTF8().IsUTF8stringWithSizeEncodedCorrectly( ( text + byteWithMostSignificantBitOnIndex ), ( numberOfBytesInText - byteWithMostSignificantBitOnIndex ) ) )
                {
                    // The encoding of the text is UTF-8
                    return ( UnicodeTransferFormat_8 );
                }
 
            }
            else  //  false == trueForByteWithAllBitsOffExistAndFalseForNotExist
            {
                // A byte with the most significant bit on ( 1 ) exist in the text. This means that the text can not be encoded in UTF-32,
                // because UTF-32 must have bytes with all bits off ( 0 ) or otherwise the values inside will exceed the unicode limit of 
                // 1114111. There are left 2 options, UTF-8 with only ascii values, and UTF-16 with no template, which means only 2 bytes entries

                // TODO - Try to exclude UTF-8

                // The algorithm could not exclude the UTF-8 encoding, return that the encoding of the text is unknown
                return ( Unknown );
            }

            // If control reached here the encoding of the text is UTF-16

            // Check if little or big endian UTF-16 match the text
            encodingType = DoesEncodingIsUTF16littleOrBigEndianIMP( text, numberOfBytesInText );

            // Check the return value from the method used to determine little or big endian
            if ( ( UnicodeTransferFormat_16LittleEndian == encodingType ) || ( UnicodeTransferFormat_16BigEndian == encodingType ) )
            {
                // The text encoding was resolved, return it
                return ( encodingType );
            }

            // The algorithm did not manage to exclude big or little endian, return that the encoding is UTF-16
            return ( UnicodeTransferFormat_16 );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to check if the encoding of the text is UTF-32
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. text - a pointer to the beginning of the text that the encoding is not known
        //          2. numberOfBytesInText - the number of bytes entries in the text
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      1. The EncodingType enum UnicodeTransferFormat_32 - if the text is encoded as UTF-32 and the endian of the text can not be resolved
        //      2. The EncodingType enum UnicodeTransferFormat_32LittleEndian - if the text is encoded as UTF-32 little endian
        //      3. The EncodingType enum UnicodeTransferFormat_32BigEndian - if the text is encoded as UTF-32 big endian
        //      4. The EncodingType enum Unknown - if the text is not encoded as UTF-32
        //
        //  Possible errors :
        //
        //      They will come
        //
        EncodingType GetEncoding::DoesTextEncodedInUTF32IMP( const UnsignedInteger8bits* text, UnsignedInteger64bits numberOfBytesInText ) throw()
        {
            // In order to check if the encoding is UTF-32, every 4 bytes are taken and checked, as little and big endian, if
            // the value inside does not pass the unicode limit which is 1114111 ( In Hexa - 0x0010FFFF ). If it does pass
            // then it can not be UTF-32

            // Check that number of bytes in the text divides by 4 with no remainder, if it doesn't then this is not UTF-32
            IF_EXPRESSION_IS_FALSE_RETURN_VALUE( ( 0 == ( numberOfBytesInText % 4 ) ), Unknown )

            // Create an object to point to the text as units of 4 bytes
            const UnicodeCharacter* pointToTextAsUnitsOf4Bytes = reinterpret_cast< const UnicodeCharacter* >( text );

            // Create an object to store the number of 4 bytes entries in the text
            UnsignedInteger64bits numberOfFourBytesEntriesInText = ( numberOfBytesInText / 4 );

            // Create an object to store if the UTF-32 little endian is the text encoding
            bool trueForUTF32littleEndianIsNotTheTextEncodingAndFalseOtherwise = false;

            // Create an object to store if the UTF-32 big endian is the text encoding
            bool trueForUTF32bigEndianIsNotTheTextEncodingAndFalseOtherwise = false;

            // Loop on all the text
            for ( UnsignedInteger64bits textIndex = 0 ; textIndex < numberOfFourBytesEntriesInText ; ++textIndex ) 
            {
                // Check if the current 4 bytes stores value equal or greater then 1114111

                // Check as little endian
                if ( 0xFFFF1000 <= pointToTextAsUnitsOf4Bytes[ textIndex ] )
                {
                    // There is 4 bytes with value higher then the unicode limit

                    // Set that the text is not encoded as UTF-32 little endian
                    trueForUTF32littleEndianIsNotTheTextEncodingAndFalseOtherwise = true;
                }
                // Check as big endian
                if ( 0x0010FFFF <= pointToTextAsUnitsOf4Bytes[ textIndex ] )
                {
                    // There is 4 bytes with value higher then the unicode limit

                    // Set that the text is not encoded as UTF-32 big endian
                    trueForUTF32bigEndianIsNotTheTextEncodingAndFalseOtherwise = true;
                }

                // Check if both of the booleans are true, then there is no need to continue exploring the text
                if ( ( true == trueForUTF32littleEndianIsNotTheTextEncodingAndFalseOtherwise ) && ( true == trueForUTF32bigEndianIsNotTheTextEncodingAndFalseOtherwise ) )
                {
                    // If control reached here then the text is not encoded as UTF-32
                    return ( Unknown );
                }

            }

            // Check if only UTF-32 big endian match the text
            if ( ( true == trueForUTF32littleEndianIsNotTheTextEncodingAndFalseOtherwise ) && ( false == trueForUTF32bigEndianIsNotTheTextEncodingAndFalseOtherwise ) )
            {
                // The text encoding is UTF-32 little endian
                return ( UnicodeTransferFormat_32BigEndian );
            }
            
            // Check if only UTF-32 little endian match the text
            if ( ( false == trueForUTF32littleEndianIsNotTheTextEncodingAndFalseOtherwise ) && ( true == trueForUTF32bigEndianIsNotTheTextEncodingAndFalseOtherwise ) )
            {
                // The text encoding is UTF-32 little endian
                return ( UnicodeTransferFormat_32LittleEndian );
            }

            // UTF-32 can not be excluded, it can still be the text encoding
            return ( UnicodeTransferFormat_32 );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to check if the UTF-16 encoding is little or big endian
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. text - a pointer to the beginning of the text that the encoding is not known
        //          2. numberOfBytesInText - the number of bytes the text is stored on
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      1. The EncodingType enum UnicodeTransferFormat_16LittleEndian - if the UTF-16 encoding is little endian
        //      2. The EncodingType enum UnicodeTransferFormat_16BigEndian - if the UTF-16 encoding is big endian
        //      3. The EncodingType enum Unknown - if the method could not resolve the encoding
        //
        //  Possible errors :
        //
        //      They will come
        //
        EncodingType GetEncoding::DoesEncodingIsUTF16littleOrBigEndianIMP( const UnsignedInteger8bits* text, UnsignedInteger64bits numberOfBytesInText ) throw( std::bad_alloc, Exception )
        {
            // The major assumption in this method is that text usually involves 1 major language. In UTF-16 big or 
            // little endian, the most significant byte chooses the language and the less significant byte states the
            // letter. This usually true because the major part of the languages don't have more then 128 letters.
            // This can be used to determine if the encoding is little or big endian, by finding if the first or
            // second byte has value that returns in the text in constant distnaces

            // Create an object to store number of times each value between 1 - 127 appear in the text for odd entries
            GeneralPurposeContainers::FixedSizeArray< UnsignedInteger64bits > arrayForNumberOfApperancesOfEachValueInOddEntries( 127, 0 );

            // Create an object to store number of times each value between 1 - 127 appear in the text for even entries
            GeneralPurposeContainers::FixedSizeArray< UnsignedInteger64bits > arrayForNumberOfApperancesOfEachValueInEvenEntries( 127, 0 );
 
            // Loop on all the text
            for ( UnsignedInteger64bits textIndex = 0 ; textIndex < numberOfBytesInText ; ++textIndex ) 
            {

                // Check if the current index of the text is even or odd
                if ( 0 == ( textIndex % 2 ) )
                {
                    // The text index is even

                    // Use the byte value to get the index to the array for even entries, and increase the value there by 1
                    arrayForNumberOfApperancesOfEachValueInEvenEntries[ text[ textIndex ] ] += 1;
                }
                else
                {
                   // The text index is odd

                    // Use the byte value to get the index to the array for even entries, and increase the value there by 1
                    arrayForNumberOfApperancesOfEachValueInOddEntries[ text[ textIndex ] ] += 1;
                }

            }

            // Now, find the array which has the entry with the highest number of apperances in the text

            // Create an object to store the highest value found in the even array
            UnsignedInteger64bits evenArrayHighestValue = 0;

            // Create an object to store the highest value found in the odd array
            UnsignedInteger64bits oddArrayHighestValue = 0;

            // Loop on the arrays and extract the highest value for each one
            for ( UnsignedInteger64bits arrayIndex = 0 ; arrayIndex < 127 ; ++arrayIndex )
            {

                // Check if current entry has higher value in the even array
                if ( arrayForNumberOfApperancesOfEachValueInEvenEntries[ arrayIndex ] > evenArrayHighestValue )
                {
                    // The current entry has higher value, store it
                    evenArrayHighestValue = arrayForNumberOfApperancesOfEachValueInEvenEntries.GetEntryValue( arrayIndex );
                }

                // Check if current entry has higher value in the odd array
                if ( arrayForNumberOfApperancesOfEachValueInOddEntries[ arrayIndex ] > oddArrayHighestValue )
                {
                    // The current entry has higher value, store it
                    oddArrayHighestValue = arrayForNumberOfApperancesOfEachValueInOddEntries.GetEntryValue( arrayIndex );
                }

            }

            // Check if the even array has higher value then the odd array
            if ( evenArrayHighestValue > oddArrayHighestValue )
            {
                // The UTF-16 encoding is big endian
                return ( UnicodeTransferFormat_16BigEndian );
            }

            // Check if the odd array has higher value then the even array
            if ( oddArrayHighestValue > evenArrayHighestValue )
            {
                // The UTF-16 encoding is little endian
                return ( UnicodeTransferFormat_16LittleEndian );
            }

            // If control reached here the methos could not resolve if the encoding uses little or big endian
            return ( Unknown );
        }












    }  //  Namespace Encoding


}  //  Namespace Universe


#endif  //  GETENCODING_CPP