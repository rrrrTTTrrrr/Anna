#ifndef  UTF8_H
#define  UTF8_H


#include <new>  //  std::bad_alloc


#include "../../../BasicUtilities/cpp_BasicUtilities.h"  //  Function LittleOrBigEndian, Function ThrowExceptionIfPointerIsNULL, Function ThrowExceptionIfValueOneIsBiggerThenValueTwo, Function ThrowExceptionIfValueIsOutOfRange, Function ThrowExceptionIfExpressionIsFalse
#include "../../../ErrorHandling/Exception/Exception.h"  //  Class Exception
#include "../../../Definitions/VariableTypesDefinitions.h"  //  Typedef UnsignedInteger8bits
#include "../../EncodingDefinitions/EncodingDefinitions.h"  //  Typedef UnicodeScalarValue





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
        //	NONE
        //


        // Give proper treatment, by dealing with big and little endian encoding systems
        // where it is required. The big or little endian encoding appear when dealing
        // with byte order in memory


        // This class functions as a tunnel. Therefore there is no state the object is at, unicde 
        // character enters and it is encoded into UTF-8 and vice versa, but the object does not
        // change. For this reason no move semantics are required, because there are no resources
        // to take


        // Constructor of derived object, when it is called, all the base class constructors are called according to
        // the order they appear in the class declaration, and only then the user code is executed


        // Destructor of derived object, when it is called, the user code existing in the destructor itself is executed first and then all the destructors
        // of the objects inside, in an opposite way from that they were constructed


    	// Fundamentally, computers just deal with numbers. They store letters and other characters by
    	// assigning a number for each one. Before Unicode was invented, there were hundreds of different
    	// encoding systems for assigning these numbers. No single encoding could contain enough characters.
    	// for example, the European Union alone requires several different encodings to cover all its
    	// languages. Even for a single language like English no single encoding was adequate for all the
    	// letters, punctuation, and technical symbols in common use. These encoding systems also conflict
    	// with one another. That is, two encodings can use the same number for two different characters, or
    	// use different numbers for the same character. Any given computer ( especially servers ) needs to
    	// support many different encodings, yet whenever data is passed between different encodings or
    	// platforms, that data always runs the risk of corruption.
    	//
    	// Unicode is changing all that!
    	//
    	// Unicode provides a unique number for every character, no matter what the platform, no matter what
    	// the program, no matter what the language. Every character holds an enumerated position from 0 to
    	// 1,114,111 (hex: 0-10FFFF) called code point. An encoding form maps a code point to a code unit
    	// sequence. A code unit is the way characters are organized in memory, 8-bit units, 16-bit units
    	// and so on. This is important becuase to represent every character in the Unicode requires 4 bytes,
    	// but it will be a memory waste becuase the english language for example can store characters only
    	// with one byte, and therefore came the encoding as UTF-8, UTF-16 and more


        // The Universal Character Set ( UCS ) encompasses most of the world's writing systems, however
        // the originally proposed encodings of the UCS, were not compatible with many current
        // applications and protocols. This has led to the development of UTF-8.
        // UTF-8 encodes UCS characters as a varying number of octets, where the number of octets,
        // and the value of each, depend on the integer value assigned to the character.
        // UTF-8 has a one-octet encoding unit, and therefore has the quality of preserving the full
        // US-ASCII range.
        // In UTF-8, characters from the U+0000 - U+10FFFF ( 0 - 118480 ) range are encoded using
        // sequences of 1 to 4 octets, the next table summarize the encoding:
        //
        //          character number range                         UTF-8 octet sequence
        //
        //          0000 0000 - 0000 007F            ->            0xxxxxxx
        //          0000 0080 - 0000 07FF            ->            110xxxxx 10xxxxxx
        //          0000 0800 - 0000 FFFF            ->            1110xxxx 10xxxxxx 10xxxxxx
        //          0001 0000 - 0010 FFFF            ->            11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
        //
        // IMPORTANT NOTE - UTF-8 is just a way to stroe bits that represent value, which then
        // needs to be looked up in a specific look up table, to translate it to human
        // readable form. Also the UNICODE systme for assigning values to each character is used


        // Rvalue references :
        //
        // Rvalue references are a new category of reference variables that can bind to rvalues.
        // Rvalues are slippery entities, such as temporaries and literal values. up until now,
        // there were no way of binding these safely to reference variables. Technically, an 
        // rvalue is an unnamed value that exists only during the evaluation of an expression.
        // For example, the following expression produces an rvalue :
        //
        //      x + ( y * z );  A C++ expression that produces a temporary 
        //
        // C++ creates a temporary ( an rvalue ) that stores the result of y * z, and then adds 
        // it to x. Conceptually, this rvalue evaporates by the time the semicolon is reached,
        // at the end of the full expression. Declaration of an rvalue reference :
        //
        //      int&& rvalue;   C++11 rvalue reference variable
        //
        // The traditional reference variables of C++ :
        //
        //      int& lvalue;
        //
        // are now called lvalue references. Rvalue references occur almost anywhere, even if they
        // are not used directly in the code. They affect the semantics and lifetime of objects in
        // C++11. To see how exactly, it’s time to understand move semantics


        // Move semantics :
        //
        // Copying has been the only means for transferring a state from one object to another ( an
        // object’s state is the collective set of its non-static data members’ values ). Formally,
        // copying causes a target object to end up with the same state as the source object, without
        // modifying the source object. Move semantics enables to write code that transfers resources
        // ( such as dynamically allocated memory ) from one object to another. Move semantics works 
        // because it enables resources to be transferred from temporary objects that cannot be 
        // referenced elsewhere in the program. Move operations tend to be faster than copying because
        // they transfer an existing resource to a new destination, whereas copying requires the creation
        // of a new resource from scratch. Move semantics also helps when the compiler cannot use Return
        // Value Optimization ( RVO ) or Named Return Value Optimization ( NRVO ). In these cases, the 
        // compiler calls the move constructor if the type defines it.
        //
        // What happens to a moved-from object? The state of a moved-from object is unspecified. Therefore,
        // always assume that a moved-from object no longer owns any resources, and that its state is similar
        // to that of an empty ( as if default-constructed ) object. 
        //
        // To implement move semantics, a move constructor, and optionally a move assignment operator, are
        // typically provided for the object. A move constructor :
        //
        //      Object( Object&& other );   C++11 move constructor
        //
        // It doesn’t allocate new resources. Instead, it pilfers other‘s resources and then sets other to 
        // its default-constructed state. A move assignment operator :
        //
        //      Object& operator=( Object&& other );    C++11 move assignment operator
        //
        // A move assignment operator is similar to a copy constructor except that before pilfering the source
        // object, it releases any resources that its object may own. 


        // C++11 adds the following rules, which are also true for C++14 :
        //
        // The compiler generates the move constructor if
        //    there is no user-declared copy constructor, and
        //    there is no user-declared copy assignment operator, and
        //    there is no user-declared move assignment operator and
        //    there is no user-declared destructor,
        //    it is not marked as deleted,
        //    and all members and bases are moveable.
        //
        // Similar for the move assignment operator, It is generated if there is no user defined
        //    there is no user-declared copy constructor, and
        //    there is no user-declared copy assignment operator, and
        //    there is no user-declared move constructor and
        //    there is no user-declared destructor,
        //    it is not marked as deleted,
        //    and all members and bases are moveable


        // Fundamentally, computers just deal with numbers. They store letters and other characters by
        // assigning a number for each one. Before Unicode was invented, there were hundreds of different
        // encoding systems for assigning these numbers. No single encoding could contain enough characters.
        // for example, the European Union alone requires several different encodings to cover all its
        // languages. Even for a single language like English no single encoding was adequate for all the
        // letters, punctuation, and technical symbols in common use. These encoding systems also conflict
        // with one another. That is, two encodings can use the same number for two different characters, or
        // use different numbers for the same character. Any given computer ( especially servers ) needs to
        // support many different encodings, yet whenever data is passed between different encodings or
        // platforms, that data always runs the risk of corruption.
        //
        // Unicode is changing all that!
        //
        // Unicode provides a unique number for every character, no matter what the platform, no matter what
        // the program, no matter what the language. Every character holds an enumerated position from 0 to
        // 1,114,111 (hex: 0-10FFFF) called code point. An encoding form maps a code point to a code unit
        // sequence. A code unit is the way characters are organized in memory, 8-bit units, 16-bit units
        // and so on. This is important becuase to represent every character in the Unicode requires 4 bytes,
        // but it will be a memory waste becuase the english language for example can store characters only
        // with one byte, and therefore came the encoding as UTF-8, UTF-16 and more


        // Class Information :
        //
        //  Purpose :
        //
        //      This class purpose is to include the basic capability of encoding and decoding between unicode
        //      character and UTF-8 encoding. All classes further deal with UTF-8 should inherit from this
        //      base class. The class acts as a tunnel between the unicode character and the way it is saved
        //      in memory ( the encoding ), if a unicode character enters the tunnel a UTF-8 encoding is
        //      returned, and the opposite. This class inherits from the class alone i stand to make sure
        //      that it won't be able to move or be copied
        //
        //  Description :
        //
        //
        //
        //  Possible errors :
        //
        //
        //
    	class UTF8 : private AloneIstand
    	{ 
    	public:


            // The following methods are the basic methods for each object. How to create, destroy, copy
            // and move the object. This methods if not declared the compiler generates a basic behavior
            // for them :


    		// Method Information :
        	//
        	//  Description :
        	//
        	//   	Default Constructor
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
        	//		They will come
        	//
        	explicit inline UTF8() throw();


    		// Method Information :
        	//
        	//  Description :
        	//
        	//   	Destructor,
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
        	//		They will come
        	//
        	inline ~UTF8() throw();


            // The following methods are the interface of the object. This methods implement the
            // capabilities of the object :


            // The following methods deal with one unicode scalar value :


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to encode a unicode character as UTF-8, and store the result in the given location
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. unicodeScalarValue - a unicode character, which consists of 4 bytes
            //          2. UTF8encoding - the address where the UTF-8 encoded character will be stored   
            //
            //      Information returned to the user :
            //
            //            NONE
            //
            //  Return value :
            //
            //      The number of bytes that the UTF-8 encoding needed
            //
            //  Possible errors :
            //
            //      1. If the given value of the unicde character is higher then 1114111 the UTF-8 cant encode it - an Exception is thrown 
            //      2. If the given pointer is NULL - class Exception is thrown
            //      3. 
            //
            UnsignedInteger8bits StoreTheUnicodeScalarValueAsUTF8encoding( UnicodeScalarValue unicodeScalarValue, UnsignedInteger8bits* UTF8encoding ) const throw( Exception );


            // Method Information :
            //
            //  Description :
            //
            //      Use to get the unicode scalar value from a UTF-8 encoding 
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //            UTF8encoding - a unicode character encoded into UTF-8 
            //
            //      Information returned to the user :
            //
            //            unicodeScalarValue - the decoded unicode scalar value from the UTF-8 
            //
            //  Return value :
            //
            //      The number of bytes the UTF-8 encoding needed
            //
            //  Possible errors :
            //
            //      1. The given pointer to the UTF-8 encoding is NULL - class Exception is thrown
            //      2. The UTF-8 encoding is broken
            //      3. 
            //
            UnsignedInteger8bits GetUnicodeScalarValueFromUTF8encoding( const UnsignedInteger8bits* UTF8encoding, UnicodeScalarValue& unicodeScalarValue ) const throw( Exception );


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
            //          UTF8encoding - a unicode character encoded into UTF-8 
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      1. true - if the UTF-8 was encoded correctly
            //      2. false - if the UTF-8 was not encoding correctly
            //
            //  Possible errors :
            //
            //      1. If the given UTF-8 encoding pointer is NULL - class Exception is thrown
            //      2.
            //
            bool IsUTF8encodedCorrectly( const UnsignedInteger8bits* UTF8encoding ) const throw();


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
            //      Note - the responsibility for deleting the memory space is on the user
            //
            //  Possible errors :
            //
            //      1. If the given pointer is NULL - class Exception is thrown
            //      2. There is no more free memory space - class std::bad_alloc is thrown
            //      3. The unicode scalar values string does not end with NULL
            //      4. 
            //
            UnsignedInteger8bits* GetUnicodeStringEncodedAsUTF8( UnicodeScalarValue* unicodeString ) const throw( std::bad_alloc, Exception );


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
            //          UTF8encoding - the address of the UTF-8 encoding   
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
            //      5.
            //
            UnicodeScalarValue* GetUnicodeString( const UnsignedInteger8bits* UTF8encoding ) const throw( std::bad_alloc, Exception );


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
            //          UTF8encoding - the address of a UTF-8 encoded string
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
            //      3.
            //
            bool IsUTF8stringEncodedCorrectly( const UnsignedInteger8bits* UTF8encoding ) const throw( Exception );


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
            //          1. UTF8encoding - the address of a UTF-8 encoded string
            //          2. UTF8encodingSize - the size of the UTF-8 encoding
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
            //      2. The given size of the UTF-8 encoding is 0 - class Exception is thrown
            //      3. 
            //
            bool IsUTF8stringWithSizeEncodedCorrectly( const UnsignedInteger8bits* UTF8encoding, UnsignedInteger64bits UTF8encodingSize ) const throw( Exception );


            // The following methods declare the overloaded operators for the object :


            // This part of the class is dedicated for testing :


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
            void Test();


    	private: 


    		// This object will store if the system uses little or big endian
    		bool m_trueForLittleEndianAndFalseForBigEndian;


            // Method Information :
            //
            //  Description :
            //
            //      Use to check the amount of bytes would take to encode the unicode character as UTF-8        
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          unicodeScalarValue - a unicode character, which consists of 4 bytes
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      The amount of bytes that would take to encode the unicode character into UTF-8
            //
            //  Possible errors :
            //
            //      1. If the given value of the unicde character is higher then 1114111 the UTF-8 cant encode it - an Exception is thrown
            //      2. 
            //
            UnsignedInteger8bits GetTheAmountOfBytesToEncodeUnicodeScalarValueIntoUTF8IMP( UnicodeScalarValue unicodeScalarValue ) const throw( Exception );


            // Method Information :
            //
            //  Description :
            //
            //      Use to get the amount of bytes that were used in the given UTF-8 encoding
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //            UTF8encoding - a unicode character encoded into UTF-8 
            //
            //      Information returned to the user :
            //
            //            NONE
            //
            //  Return value :
            //
            //      The amount of bytes that was used to create the UTF-8 encoding
            //
            //  Possible errors :
            //
            //      1. If the given UTF-8 encoding pointer is NULL - class Exception is thrown
            //      2. If there are 5 bits on ( 1 ), before the first bit off ( 0 ), the UTF-8 encoding is broken - class Exception is thrown
            //      3. 
            //
            UnsignedInteger8bits GetTheNumberOfBytesUsedInUTF8encodingIMP( const UnsignedInteger8bits* UTF8encoding ) const throw( Exception );


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
            //      3. 
            //
            UnsignedInteger64bits GetTheNumberOfBytesRequiredToEncodeUnicodeStringAsUTF8IMP( const UnicodeScalarValue* unicodeString ) const throw();


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
    	    //			2. numberOfBytesRequiredToEncodeAsUTF8 - the number of bytes required to encode the unicode character into UTF-8 encoding  
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
    	    void SetUTF8templateIMP( UnsignedInteger8bits* UTF8templateDestination, UnsignedInteger8bits numberOfbytesRequiredToEncodeAsUTF8 ) const throw( Exception );


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
    	    //		    2. UTF8encoding - the address where the UTF-8 template is stored 
    	    //		    3. numberOfbytesRequiredToEncodeAsUTF8 - the number of bytes required to contain the UTF-8 representation of the unicode character
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
    	    void SetTheBitsOfTheUnicodeScalarValueIntoTheUTF8templateIMP( UnicodeScalarValue unicodeScalarValue, UnsignedInteger8bits* UTF8encoding, UnsignedInteger8bits numberOfbytesRequiredToEncodeAsUTF8 ) const throw();


            // Method Information :
            //
            //  Description :
            //
            //      Use to encode the unicode scalar value as UTF-8 on little endian systems
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. UTF8encoding - a location to store the unicode scalar value encodeD as UTF-8
            //          2. unicodeScalarValueBytes - a pointer to the first byte of the unicode scalar value
            //          3. numberOfBytesToEncodeAsUTF8 - the number of bytes needed to encode as UTF-8  
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
            //      1. The UTF-8 encoding is broken
            //      2. 
            //
            void EncodeUTF8onSystemsWithLittleEndianIMP( const UnsignedInteger8bits* unicodeScalarValueBytes, UnsignedInteger8bits* UTF8encoding, UnsignedInteger8bits numberOfBytesToEncodeAsUTF8 ) const throw();


            // Method Information :
            //
            //  Description :
            //
            //      Use to encode the unicode scalar value as UTF-8 on big endian systems
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. UTF8encoding - a location to store the unicode scalar value encodeD as UTF-8
            //          2. unicodeScalarValueBytes - a pointer to the first byte of the unicode scalar value
            //          3. numberOfBytesToEncodeAsUTF8 - the number of bytes needed to encode as UTF-8  
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
            //      1. The UTF-8 encoding is broken
            //      2. 
            //
            void EncodeUTF8onSystemsWithBigEndianIMP( const UnsignedInteger8bits* unicodeScalarValueBytes, UnsignedInteger8bits* UTF8encoding, UnsignedInteger8bits numberOfBytesToEncodeAsUTF8 ) const throw();


            // Method Information :
            //
            //  Description :
            //
            //      Use to decode the UTF-8 into the unicode scalar value on little endian systems
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. UTF8encoding - a unicode character encoded into UTF-8 
            //          2. unicodeScalarValueBytes - a pointer to the first byte of the object that will store the unicode scalar value
            //          3. numberOfBytesToEncodeAsUTF8 - the number of bytes needed to encode as UTF-8  
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
            //      1. The UTF-8 encoding is broken
            //      2. 
            //
            void DecodeUTF8onSystemsWithLittleEndianIMP( const UnsignedInteger8bits* UTF8encoding, UnsignedInteger8bits* unicodeScalarValueBytes, UnsignedInteger8bits numberOfBytesToEncodeAsUTF8 ) const throw();


            // Method Information :
            //
            //  Description :
            //
            //      Use to decode the UTF-8 into the unicode scalar value on big endian systems
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. UTF8encoding - a unicode character encoded into UTF-8 
            //          2. unicodeScalarValueBytes - a pointer to the first byte of the object that will store the unicode scalar value
            //          3. numberOfBytesToEncodeAsUTF8 - the number of bytes needed to encode as UTF-8  
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
            //      1. The UTF-8 encoding is broken
            //      2. 
            //
            void DecodeUTF8onSystemsWithBigEndianIMP( const UnsignedInteger8bits* UTF8encoding, UnsignedInteger8bits* unicodeScalarValueBytes, UnsignedInteger8bits numberOfBytesToEncodeAsUTF8 ) const throw();


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
            //      1. The given pointer is NULL - class Exception is thrown
            //      2. The UTF-8 encodeing is broken
            //      3.  
            //
            UnsignedInteger64bits GetNumberOfUnicodeScalarValuesInUTF8encodingIMP( const UnsignedInteger8bits* UTF8encoding ) const throw( Exception );


    	};  //  Class UTF8














//  **************************************************************   END PART OF DECLRATIONS, IMPLMENTATION TIME   *************************************************************















    	// Method Information :
        //
        //  Description :
        //
        //   	Default Constructor, used to support move semantics
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
        inline UTF8::UTF8() throw() :
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
        inline UTF8::~UTF8() throw()
        {}

















//  ***************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************






















//  **************************************************************   PRIVATE METHODS IMPLEMENTATION   ****************************************************************************
























// ***********************************************************   NESTED CLASS IMPLEMENTATION -    ************************************************************
























// ******************************************************   INLINE AND TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   ****************************************************************










        // This functions are declared outside the class scope, to enable the class to be the right side operand. This can not be for a method
        // within the class. When a method or operator of a class is used, the object the operator or method belongs to must be known, in order
        // to set the implicit this pointer to the method. Therefore the class must be presented first which means to be the left side operand,
        // this functions are needed to avoid just that

















    }  //  namespace Encoding 

}  //   Namespace Universe

#endif  // UTF8_H