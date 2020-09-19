#ifndef  UTF16_H
#define  UTF16_H


#include "../../../Definitions/VariableTypesDefinitions.h"  //  Typedef UnsignedInteger8bits, Typedef UnsignedInteger16bits
#include "../../EncodingDefinitions/EncodingDefinitions.h"  //  Typedef UnicodeScalarValue
#include "../../../ErrorHandling/Exception.h"  //  Class Exception
#include "../../../BasicUtilities/cpp_BasicUtilities.h"  //  Function ThrowExceptionIfPointerIsNULL, Function ThrowExceptionIfValueOneIsBiggerThenValueTwo, Function ThrowExceptionIfExpressionIsFalse



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
        //
        // In little endian encoding it is important to remember that most system set the 
        // most significant bit inside a byte to be the right most, which means that the 
        // shifting results are a bit different :
        //
        //      11110000 00000000  <<  2  
        //      
        // will give :
        //
        //      11000000 00000011
        //
        // Therefore the bits are not contigous anymore in memory


        // When shifting with types that has less bits then the register has there is a thing important to notice  
        // when shifting left. Of course the endian issue must be thought of, the following description will describe
        // the case of little endian, while big endian workd just the opposite. If the type is shifted left, a temporary
        // is created to store the result, in most cases it would be a register. Now if the type is used the value is 
        // correct, but the bits that were removed where just also left shifted on the register which has more space, 
        // and not set to 0. The problem only arises when using the right shift operation on the type, and expexting 
        // for the bits to be set off. To avoid the problem just use casting on the temporary created and it will be 
        // initialized with the free bits in the registers set to 0


        // To support move semantics every class must provide a default state. This state
        // will be used to notify that the current instance resources was taken by a move
        // operation :
        //
        //
       	// When this state is indicated the object should not be used as it is ( the object is empty )


        // Constructor of derived object, when called, all the base class constructors are executed first, according to
        // the order they appear in the class declaration, and only then the user code is executed

        // Destructor of derived object, when it is called, the user code existing in the destructor itself is executed first and then all the destructors
        // of the base objects, in an opposite way from which they were constructed


        // The IETF policy on character sets and languages says that IETF protocols MUST be able to
        // use the UTF-8 character encoding scheme


        // Background and motivation :
        //
        // The Unicode Standard and ISO/IEC 10646 defind toghter a coded character set, hereafter
        // referred to as Unicode, which encompasses most of the world’s writing systems. UTF-16,
        // the object of this class, is one of the standard ways of encoding unicode scalar value data.
        // It has the characteristics of encoding all currently defined characters ( in plane 0, the BMP )
        // in exactly 2 bytes and of being able to encode all other characters likely to be defined
        // ( the next 16 planes ) in exactly four bytes


        // The rules for how characters are encoded in UTF-16 are :
        //
        //  1. Characters with values less than 0x10000 ( 65536 ) are represented as a
        //  single 16-bit integer with a value equal to that of the character
        //  number
        //  2. Characters with values between 0x10000 ( 65536 ) and 0x10FFFF ( 1114111 ) are
        //  represented by a 16-bit integer with a value between 0xD800 ( 55296 ) and
        //  0xDBFF ( 56319 ) followed by a 16-bit integer with a value between 0xDC00 ( 56320 ) and
        //  0xDFFF ( 57343 )
        //  3. Characters with values greater than 0x10FFFF ( 1114111 ) cannot be encoded in
        //  UTF-16
        //
        // Values between 0xD800 ( 55296 ) and 0xDFFF ( 57343 ) are specifically reserved for use with
        // UTF-16, and  don’t have any characters assigned to them


        // The Unicode Standard and ISO 10646 define the character "ZERO WIDTH NON-BREAKING SPACE" - 65279 ( 0xFEFF ),
        // which is also known informally as "BYTE ORDER MARK". This value is used also when transmitting
        // UTF-16, it is stored as an additional 2 bytes at the begining. A receiver of such a 
        // serialized stream may then use the initial character both as a hint that the stream consists of
        // unicode scalar values and as a way to recognize the serialization order ( Big or Little endian ).
        // In serialized UTF-16 prepended with such a signature, the order is big-endian if the first two
        // octets are 0xFE followed by 0xFF. If they are 0xFF followed by 0xFE, the order is little-endian.
        // Note that 65534 - ( 0xFFFE ) is not a unicode scalar value, precisely to preserve the usefulness of 0xFEFF as
        // a byte-order mark :
        //
        //      big endian - 0xFEFF  ->  1111 1110   1111 1111 
        //
        //      little endian - 0xFFFE  ->  1111 1111   1111 1110
        //
        // It is important to understand that the character 0xFEFF appearing at
        // any position other than the beginning of a stream will be interpreted
        // with the semantics for the zero-width non-breaking space, and not to
        // be interpreted as a byte-order mark. The contrapositive of that
        // statement is not always true. The character 0xFEFF in the first
        // position of a stream MAY be interpreted as a zero-width non-breaking
        // space, and is not always a byte-order mark. For example, if a process
        // splits a UTF-16 string into many parts, a part might begin with
        // 0xFEFF because there was a zero-width non-breaking space at the
        // beginning of that substring. The Unicode standard further suggests
        // than an initial 0xFEFF character may be stripped before processing
        // the text, the rationale being that such a character in initial position
        // may be an artifact of the encoding ( an encoding signature ), not a 
        // genuine intended "ZERO WIDTH NON-BREAKING SPACE". Note that such stripping
        // might affect an external process at a different layer (such as a digital
        // signature or a count of the characters) that is relying on the presence 
        // of all characters in the stream


        // The process of encoding a unicode scalar value as UTF-16, when the value is higher
        // then 65536 :
        //
        // The first step is to subtract 65536 from the given unicode scalar value. The rational is that now the entire value
        // can be represented in 20 bites. The second step is to set the UTF-16 template into the
        // allocated space, at the first UnsignedInteger16bits store 56320, and at the second store
        // 55296. Now every UnsignedInteger16bits has 10 empty bits to contain the actual value
        // encoded, set the 10 high order bits into the UnsignedInteger16bits containing 56320, and
        // the 10 low order bits into the UnsignedInteger16bits containing 55296


    	class UTF16 : private AloneIstand
    	{ 
    	public:


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
        	explicit inline UTF16() throw();


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
        	inline ~UTF16() throw();


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
            //      1. 1 - if only 2 bytes were needed to encode as UTF-16
            //      2. 2 - if 4 bytes were needed to encode as UTF-16
            //
            //  Possible errors :
            //
            //      1. The given pointer is NULL - class Exception is thrown
            //      2. The given unicode scalar value is higher then 1114111 - class Exception is thrown
            //      3. 
            //
            UnsignedInteger8bits SetTheGivenUnicodeScalarValueEncodedAsUTF16( UnicodeScalarValue unicodeScalarValue, UnsignedInteger16bits* UTF16encoding ) const throw( Exception );


            // Method Information :
            //
            //  Description :
            //
            //      Use to store the unicode scalar value extracted from the UTF-16 encoding to the given location      
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. UTF16encoding - the address of the UTF-16 encoding
            //          2. unicodeScalarValue - a reference to the location where the decoded unicode scalar value will be stored
            //          3. trueForLittleEndianAndFalseForBigEndian - this boolean will be used to determine if the UTF-16 encoding is little or big endian
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      The amount of bytes the UTF-16 encoding needed :
            //      1. 0 - 2 bytes were needed
            //      2. 1 - 4 bytes were needed
            //
            //  Possible errors :
            //
            //      1. The given UTF-16 encoding pointer is NULL - class Exception is thrown
            //      2. The given bytes are not encoded as UTF-16 correctly - class Exception is thrown
            //      3. 
            //
            UnsignedInteger8bits GetTheUnicodeScalarValueFromUTF16encoding( const UnsignedInteger16bits* UTF16encoding, UnicodeScalarValue& unicodeScalarValue, bool trueForLittleEndianAndFalseForBigEndian ) const throw( Exception );


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
            bool IsUTF16encodedCorrectly( const UnsignedInteger16bits* UTF16encoding ) const throw( Exception );


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
            UnsignedInteger16bits* GetUnicodeStringEncodedAsUTF16( UnicodeScalarValue* unicodeString ) const throw( std::bad_alloc, Exception );


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
            UnicodeScalarValue* GetUnicodeString( const UnsignedInteger16bits* UTF16encoding, bool trueForLittleEndianAndFalseForBigEndian ) const throw( std::bad_alloc, Exception );


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
            bool IsUTF16stringEncodedCorrectly( const UnsignedInteger16bits* UTF16encoding ) const throw( Exception );


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
            bool IsUTF16stringWithSizeEncodedCorrectly( const UnsignedInteger16bits* UTF16encoding, UnsignedInteger64bits UTF16encodingSize ) const throw( Exception );


    	private: 


            // This static object will store true if the system using little or big endian encoding
            bool m_trueForLittleEndianAndFalseForBigEndian;


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
            UnsignedInteger8bits GetTheAmountOfBytesToEncodeUnicodeScalarValueIntoUTF16IMP( UnicodeScalarValue unicodeScalarValue ) const throw();


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
            UnsignedInteger8bits GetTheAmountOfBytesThatWereUsedToEncodeUnicodeScalarValueIntoUTF16IMP( const UnsignedInteger16bits* UTF16encoding ) const throw();


            // Method Information :
            //
            //  Description :
            //
            //      Use to store the given unicode scalar value bits into the UTF-16 template. 
            //      To encode as UTF-16 the given unicode scalar value is subtracted by 65536.
            //      The reason for the subtraction is that now the value is stored only in 20 bits.
            //      This only true because the highest unicode scalar value possible is 1114111    
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. unicodeScalarValue - the unicode scalar value
            //          2. UTF16encoding - the location in memory that the unicode scalar value will be stored as UTF-16
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
            //      They will come
            //
            void EncodeTheUnicodeScalarValueIntoTheUTF16templateIMP( UnicodeScalarValue unicodeScalarValue, UnsignedInteger8bits* UTF16encoding ) const throw();


            // Method Information :
            //
            //  Description :
            //
            //      Use to get the unicode scalar value out of the UTF-16 encoding
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. UTF16encoding - the address of the UTF-16 encoding
            //          2. unicodeScalarValue - a reference to the location the decoded unicde scalr value should be stored
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
            //      They will come
            //
            void DecodeTheUTF16encodingIntoUnicodeScalarValueIMP( const UnsignedInteger8bits* UTF16encoding, UnicodeScalarValue& unicodeScalarValue ) const throw();


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
            UnsignedInteger64bits GetTheNumberOfBytesRequiredToEncodeUnicodeStringAsUTF16IMP( const UnicodeScalarValue* unicodeString ) const throw( Exception );


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
            UnsignedInteger64bits GetNumberOfUnicodeScalarValuesInUTF16encodingIMP( const UnsignedInteger16bits* UTF16encoding ) const throw( Exception );


    	};  //  Class UTF16










//	**************************************   END PART OF DECLRATIONS, IMPLMENTATION TIME   ************************************














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
        //	    They will come
        //
        inline UTF16::UTF16() throw() :
        m_trueForLittleEndianAndFalseForBigEndian( LittleOrBigEndian() )
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
        inline UTF16::~UTF16() throw()
        {}













//	*****************************************   PRIVATE METHODS IMPLEMENTATION   ******************************************  










// ******************************************   NESTED CLASS IMPLEMENTATION -    **************************************** 








    }  //  namespace Encoding 

}  //   Namespace Universe

#endif  // UTF16_H