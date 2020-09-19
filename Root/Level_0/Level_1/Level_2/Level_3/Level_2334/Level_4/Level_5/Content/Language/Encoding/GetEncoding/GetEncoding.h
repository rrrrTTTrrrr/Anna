#ifndef  GETENCODING_H
#define  GETENCODING_H


#include <new>  //  Class std::bad_alloc


#include "../EncodingDefinitions/EncodingDefinitions.h"  //  Enum EncodingType, Typedef UnicodeCharacter
#include "../../Definitions/VariableTypesDefinitions.h"  //  Typedef UnsignedInteger8bits, Typedef UnsignedInteger64bits, Typedef UnsignedInteger16bits
#include "../../BasicUtilities/cpp_BasicUtilities.h"  //  Macro IF_EXPRESSION_IS_FALSE_RETURN_VALUE, Function ThrowExceptionIfValueOneIsEqualToValueTwo, Function ThrowExceptionIfPointerIsNULL, Class AloneIstand
 



// When a function name ends with the suffix IMP, the function is not part
// of the object interface ( capabilities ), it only used as aid to the
// function that it is, implementing only spsecific part

 


namespace Universe
{

    namespace Encoding
    {


        // This is used when only declaring the object in this source file will be enough to
        // pass compilation. The implementation is given to the compiler through the cpp source
        // file that the object is nested within
        //
        // Forward declarations :
        //
        //  NONE
        //


        // Give proper treatment, by dealing with big and little endian encoding systems
        // where it is required. The big or little endian encoding appear when dealing
        // with byte order in memory


        // This class has no resources. Therefore there is no state the object is at, only an encoding
        // enters, and the class tries to find the type of the encoding, but the object does not
        // change. For this reason no move semantics are required, because there are no resources
        // to take


        // Constructor of derived object, when called, all the base class constructors are executed
        // first, according to the order they appear in the class declaration, and only then the
        // user code is executed

        // Destructor of derived object, when it is called, the user code existing in the destructor
        // itself is executed first and then all the destructors of the base objects, in an opposite
        // way from which they were constructed


        // The byte order mark ( BOM ) is a Unicode character, whose appearance as a magic number at 
        // the start of a text stream can signal several things to a program consuming the text :
        //
        //      1. What byte order, or endianness, the text stream is stored in
        //      2. The fact that the text stream is Unicode, to a high level of confidence
        //      3. Which of several Unicode encodings that text stream is encoded as
        //
        // Byte order mark use is optional, and, if used, should appear at the start of the text stream
        //
        // Unicode can be encoded in units of 8-bit, 16-bit, or 32-bit integers. For the 16- and 32-bit 
        // representations, a computer receiving text from arbitrary sources needs to know which byte order
        // the integers are encoded in. Because the BOM itself is encoded in the same scheme as the rest of
        // the document, but has a known value, the consumer of the text can examine these first few bytes 
        // to determine the encoding. The BOM thus gives the producer of the text a way to describe the text
        // endianness to the consumer of the text without requiring some contract or metadata outside of the 
        // text stream itself. Once the receiving computer has consumed the text stream, it is free to process
        // the characters in its own native byte order and no longer needs the BOM. Hence the need for a BOM
        // arises in the context of text interchange, rather than in text processing within a closed environment
        //
        // The byte sequence of the BOM character differs per Unicode encoding, and none of the sequences is 
        // likely to appear at the start of text stored in other encodings. Therefore, placing an encoded BOM 
        // at the start of a text stream can serve to indicate the text is Unicode and to identify the encoding 
        // scheme used, even for UTF-8, which has no endianness
        //
        // Byte order marks by encoding :
        //
        //  UTF-8           EF BB BF
        //  UTF-16BE        FE FF
        //  UTF-16LE        FF FE
        //  UTF-32BE        00 00 FE FF
        //  UTF-32LE        FF FE 00 00


        // There are a few characteristics that appear in most human languanges :
        //
        //  1. Letters - a letter is given to each syllable that a human needs to make
        //  2. Words - number of letters that grouped toghter and given meaning
        //  3. Spaces - to distinguish between 2 words, space is used ( also to give the human pauses to breath )
        //
        // The algorithm used in this class will be using the assumption that each languange uses
        // spaces to distinguish between words. It will search to see in which encoding the space
        // appear the most, to decide what the encoding is.
        //
        // The second assumption of the algorithm is that text is usually written in one language. Now, in a language
        // there is usually a relative small set of letters, following is a list of the languages with the most
        // letters in on earth :
        //
        //      tamil 247
        //      Thai- 70
        //      Malayalam- 58
        //      Sinhala- 54
        //      Bangla- 52
        //      Hindi- 44
        //      Hungarian- 44
        //      Abkhaz - 41
        //      Armenian- 39
        //      Albanian - 36
        //      Russian- 33
        //      Tamil- 30
        //      English- 26
        //      Greek- 24
        //      Hebrew- 22
        //
        // As can be seen except for language which has 247 letters, all the languages has less then 128 letters.
        // This can be used in the algorithm. If assuming that a text usually consist of 1 language and that language
        // has no more then 128 letters, then for example if the text is stored as UTF-16, the high significant byte
        // will stay the same for the entire text ( except for panctuation ), because to get to all the letters of the
        // language only the low significant byte should be changed. The same applies also to UTF-32, the only difference
        // will be the distance between the matching bytes. For example :
        //
        //      UTF-16 ->  00000011 00110111 00000011 00110100 
        //
        //      UTF-32 ->  00000000 00000001 00000011 00110100 00000000 00000001 00000011 00111100
        //
        // As can be seen in UTF-16 there is 1 byte between the matching bytes, and in UTF-32 there
        // are 3 bytes.
        //
        // Then in unicode the higher significant bytes state the language used, and the low significant bytes state the 
        // required letter from the language


    	// Class Information :
        //
        //  Purpose :
        //
        //
        //
        //  Description :
        //
        //
        //
        //  Possible errors :
        //
        //
        //
        class GetEncoding : private AloneIstand
    	{ 
    	public:


    		// The following methods are the basic methods for each object. How to create, destroy, copy
            // and move the object. This methods if not declared the compiler generates a basic behavior
            // for them :


            // Method Information :
        	//
        	//  Description :
        	//
        	//   	Default Constructor, used to support move semantics
        	//
        	//  Required arguments :
        	//
        	//   	User information needed :
        	//
            //          NONE
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
        	//		They will come
        	//
        	explicit inline GetEncoding() throw();


    		// Method Information :
        	//
        	//  Description :
        	//
        	//   	Destructor,
        	//
        	//  Required arguments :
        	//
            //   	User information needed :
        	//
            //          NONE
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
        	//		They will come
        	//
        	inline ~GetEncoding() throw();


            // The following methods are the interface of the object. This methods implement the
            // capabilities of the object :


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
            EncodingType WhatIsTheEncodingOfTheText( const UnsignedInteger8bits* text, UnsignedInteger64bits numberOfBytesInText ) throw( std::bad_alloc, Exception );


    	private: 


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
            EncodingType GetEncodingUsingByteOrderMarkIMP( const UnsignedInteger8bits* byteOrderMark ) throw();


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
            EncodingType GuessEncodingIMP( const UnsignedInteger8bits* text, UnsignedInteger64bits numberOfBytesInText ) throw();


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
            EncodingType DoesTextEncodedInUTF32IMP( const UnsignedInteger8bits* text, UnsignedInteger64bits numberOfBytesInText ) throw();


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
            EncodingType DoesEncodingIsUTF16littleOrBigEndianIMP( const UnsignedInteger8bits* text, UnsignedInteger64bits numberOfBytesInText ) throw( std::bad_alloc, Exception );


    	};  //  Class GetEncoding















//	**************************************   END PART OF DECLRATIONS, IMPLMENTATION TIME   ************************************
















    	// Method Information :
        //
        //  Description :
        //
        //   	Default Constructor,
        //
        //  Required arguments :
        //
        //   	User information needed :
        //
        //          NONE
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
        //	    They will come
        //
        inline GetEncoding::GetEncoding() throw()
        {}


        // Method Information :
        //
        //  Description :
        //
        //        Destructor,
        //
        //  Required arguments :
        //
        //   	  User information needed :
        //
        //            NONE
        //
        //        Information returned to the user :
        //
        //            NONE
        //
        //  Return value :
        //
        //   	NONE
        //
    	//  Possible errors :
        //
        //	    They will come
        //
        inline GetEncoding::~GetEncoding() throw()
        {}

















//	*****************************************   PRIVATE METHODS IMPLEMENTATION   ******************************************  

































// ******************************************   NESTED CLASS IMPLEMENTATION -    **************************************** 























    }  //   Namespace Encoding


}  //   Namespace Universe

#endif  // GETENCODING_H




















