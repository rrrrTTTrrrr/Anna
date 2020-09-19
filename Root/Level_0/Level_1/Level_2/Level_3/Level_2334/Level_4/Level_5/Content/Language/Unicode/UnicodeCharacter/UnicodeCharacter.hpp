#ifndef UNICODECHARACTER_HPP
#define UNICODECHARACTER_HPP


#include "../../../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../../../../../Content/Metaprogramming/NumericLimits/NumericLimits.hpp"  //  Class NumericLimits
#include "../../../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../../../../../../Content/Memory/Operations/Operations.hpp"  //  Class Operations 
#include "../../../../../../Content/BindObjects/Tuple/Tuple.hpp"  //  Class Tuple
#include "../../../../../../../Content/Random/Generator/Generator.hpp"  //  Class Generator
#include "../../../../../../../Content/NumericRange/NumericRange.hpp"  //  Class NumericRange


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../Display/Display.hpp"  //  Class Display
#endif


namespace Universe
{



	// When a type is forward declared, all the compiler knows is that this type exists. It does not know its size, members or methods. This is why its
	// called incomplete type. Therefore, it can not be used to declare a variable, member or base class since the compiler would need the layout of the
	// type. In other words, it can not be used for anything that requires information on the specific type. What can be done is declaring pointer and
	// reference to the incomplete type. The pointer and refernce can act as a variable, argument to a method or as the return type.
	//
	// Forward declarations :
	//
	//  NONE
	//



	namespace Language
	{



		// Fundamentally, computers just deal with numbers. They store letters and other characters by assigning a number for each one. Before Unicode was
		// invented, there were hundreds of different encoding systems for assigning these numbers. No single encoding could contain enough characters.
		// For example, the European Union alone requires several different encodings to cover all its languages. Even for a single language like English
		// no single encoding was adequate for all the letters, punctuation, and technical symbols in common use. These encoding systems also conflict
		// with one another. That is, two encodings can use the same number for two different characters, or use different numbers for the same character.
		// Any given computer ( especially servers ) needs to support many different encodings, yet whenever data is passed between different encodings or
		// platforms, that data always runs the risk of corruption.
		//
		// Unicode is changing all that!
		//
		// Unicode provides a unique number for every character, no matter what the platform, no matter what the program, no matter what the language. 
		// Every character holds an enumerated position from 0 to 1,114,111 ( 0x10FFFF ) called code point. An encoding form maps a code point to a 
		// code unit sequence. A code unit is the way characters are organized in memory, 8-bit units, 16-bit units and so on. This is important becuase
		// to represent every character in the Unicode requires 4 bytes, but it will be a memory waste becuase the english language for example can store
		// characters only with one byte, and therefore came the encoding as UTF-8, UTF-16 and more



	    // The Universal Character Set ( UCS ) encompasses most of the world's writing systems, however the originally proposed encodings of the UCS, 
	    // were not compatible with many current applications and protocols. This has led to the development of UTF-8. UTF-8 compresss UCS characters as
	    // a varying number of octets, where the number of octets, and the value of each, depend on the integer value assigned to the character. UTF-8 
	    // has a one-octet encoding unit, and therefore has the quality of preserving the full US-ASCII range. In UTF-8, characters from the U+0000 - 
	    // U+10FFFF ( 0 - 118480 ) range are compressd using sequences of 1 to 4 octets, the next table summarize the encoding :
	    //
	    //          character number range                         UTF-8 octet sequence
	    //
	    //          0000 0000 - 0000 007F            ->            0xxxxxxx
	    //          0000 0080 - 0000 07FF            ->            110xxxxx 10xxxxxx
	    //          0000 0800 - 0000 FFFF            ->            1110xxxx 10xxxxxx 10xxxxxx
	    //          0001 0000 - 0010 FFFF            ->            11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
	    //
	    // IMPORTANT NOTE - UTF-8 is just a way to stroe bits that represent value, which then needs to be looked up in a specific look up table, to 
	    // translate it to human readable form. Also the UNICODE is just a system for assigning values to each character that exist!



	    // Move semantics :
	    //
	    // Copying has been the only means for transferring a state from one object to another ( an object’s state is the collective set of its non-
	    // static data members’ values ). Formally, copying causes a target object to end up with the same state as the source object, without
	    // modifying the source object. Move semantics enables to write code that transfers resources ( such as dynamically allocated memory ) from 
	    // one object to another. Move semantics works because it enables resources to be transferred from temporary objects that cannot be referenced
	    // elsewhere in the program. Move operations tend to be faster than copying because they transfer an existing resource to a new destination, 
	    // whereas copying requires the creation of a new resource from scratch. Move semantics also helps when the compiler cannot use Return Value 
	    // Optimization ( RVO ) or Named Return Value Optimization ( NRVO ). In these cases, the compiler calls the move constructor if the type defines it.
	    //
	    // What happens to a moved-from object? The state of a moved-from object is unspecified. Therefore, always assume that a moved-from object no 
	    // longer owns any resources, and that its state is similar to that of an empty ( as if default-constructed ) object. 
	    //
	    // To implement move semantics, a move constructor, and optionally a move assignment operator, are typically provided for the object. A move 
	    // constructor :
	    //
	    //      Object( Object&& other );   C++11 move constructor
	    //
	    // It doesn’t allocate new resources. Instead, it pilfers other‘s resources and then sets other to its default-constructed state. A move 
	    // assignment operator :
	    //
	    //      Object& operator=( Object&& other );    C++11 move assignment operator
	    //
	    // A move assignment operator is similar to a copy constructor except that before pilfering the source object, it releases any resources that
	    // its object may own



	    // C++11 adds the following rules, which are also true for C++14 :
	    //
	    // The compiler generates the move constructor if :
	    //
	    //    1. There is no user-declared copy constructor
	    //    2. There is no user-declared copy assignment operator
	    //    3. There is no user-declared move assignment operator
	    //    4. There is no user-declared destructor
	    //    5. It is not marked as deleted
	    //    6. All members and bases are moveable.
	    //
	    // Similar for the move assignment operator, it is generated if there is no user defined :
	    //
	    //    1. There is no user-declared copy constructor
	    //    2. There is no user-declared copy assignment operator
	    //    3. There is no user-declared move constructor
	    //    4. There is no user-declared destructor
	    //    5. It is not marked as deleted
	    //    6. All members and bases are moveable



        // Give proper treatment, by dealing with big and little endian encoding systems where it is required. The big or little endian encoding appear
        // when dealing with byte order in memory. In little endian encoding it is important to remember that most system set the most significant bit 
        // inside a byte to be the right most, which means that the shifting results are a bit different :
        //
        //      11110000 00000000  <<  2  
        //      
        // will give :
        //
        //      11000000 00000011
        //
        // Therefore the bits are not contigous anymore in memory!



        // When shifting with types that has less bits then the register has there is a thing important to notice when shifting left. Of course the endian
        // issue must be thought of, the following description will describe the case of little endian, while big endian workd just the opposite. If the 
        // type is shifted left, a temporary is created to store the result, in most cases it would be a register. Now if the type is used the value is 
        // correct, but the bits that were removed where just left shifted on the register, which has more space, and not set to 0. The problem only arises 
        // when using the right shift operation on the type, and expexting for the bits to be set off. To avoid the problem just use casting on the 
        // temporary created and it will be initialized with the free bits in the registers set to 0



        // The IETF policy on character sets and languages says that IETF protocols MUST be able to use the UTF-8 character encoding scheme



        // Background and motivation :
        //
        // The Unicode Standard and ISO/IEC 10646 defind together a coded character set, hereafter referred to as Unicode, which encompasses most of the
        // world’s writing systems. UTF-16 is one of the standard ways of encoding unicode scalar value data. It has the characteristics of encoding all
        // currently defined characters ( in plane 0, the BMP ) in exactly 2 bytes and of being able to compress all other characters likely to be defined
        // ( the next 16 planes ) in exactly four bytes.
		//
        // The rules for how characters are compressd in UTF-16 are :
        //
        //  1. Characters with values less than 0x10000 ( 65536 ) are represented as a single 16-bit integer with a value equal to that of the character
        //     number
        //
        //  2. Characters with values between 0x10000 ( 65536 ) and 0x10FFFF ( 1114111 ) are represented by a 16-bit integer with a value between 0xD800 
        //     ( 55296 ) and 0xDBFF ( 56319 ) followed by a 16-bit integer with a value between 0xDC00 ( 56320 ) and 0xDFFF ( 57343 )
        //
        //  3. Characters with values greater than 0x10FFFF ( 1114111 ) cannot be compressd in UTF-16
        //
        // Values between 0xD800 ( 55296 ) and 0xDFFF ( 57343 ) are specifically reserved for use with UTF-16, and  don’t have any characters assigned 
        // to them



        // The Unicode Standard and ISO 10646 define the character "ZERO WIDTH NON-BREAKING SPACE" - 65279 ( 0xFEFF ), which is also known informally 
        // as "BYTE ORDER MARK". This value is used also when transmitting UTF-16, it is stored as an additional 2 bytes at the begining. A receiver 
        // of such a serialized stream may then use the initial character both as a hint that the stream consists of unicode scalar values and as a
        // way to recognize the serialization order ( Big or Little endian ). In serialized UTF-16 prepended with such a signature, the order is 
        // big-endian if the first two octets are 0xFE followed by 0xFF. If they are 0xFF followed by 0xFE, the order is little-endian. Note that 
        // 65534 - ( 0xFFFE ) is not a unicode scalar value, precisely to preserve the usefulness of 0xFEFF as a byte-order mark :
        //
        //      big endian - 0xFEFF  ->  1111 1110   1111 1111 
        //
        //      little endian - 0xFFFE  ->  1111 1111   1111 1110
        //
        // It is important to understand that the character 0xFEFF appearing at any position other than the beginning of a stream will be interpreted
        // with the semantics for the zero-width non-breaking space, and not to be interpreted as a byte-order mark. The contrapositive of that statement
        // is not always true. The character 0xFEFF in the first position of a stream MAY be interpreted as a zero-width non-breaking space, and is not
        // always a byte-order mark. For example, if a process splits a UTF-16 string into many parts, a part might begin with 0xFEFF because there 
        // was a zero-width non-breaking space at the beginning of that substring. The Unicode standard further suggests than an initial 0xFEFF character
        // may be stripped before processing the text, the rationale being that such a character in initial position may be an artifact of the encoding 
        // ( an encoding signature ), not a genuine intended "ZERO WIDTH NON-BREAKING SPACE". Note that such stripping might affect an external process
        // at a different layer (such as a digital signature or a count of the characters) that is relying on the presence of all characters in the stream
		//
		// 
        // The process of encoding a unicode scalar value as UTF-16, when the value is higher then 65536 :
        //
        // The first step is to subtract 65536 from the given unicode scalar value. The rational is that now the entire value can be represented in 20 
        // bites. The second step is to set the UTF-16 template into the allocated space, at the first UnsignedInteger16bits store 56320, and at the 
        // second store 55296. Now every UnsignedInteger16bits has 10 empty bits to contain the actual value compressd, set the 10 high order bits into 
        // the UnsignedInteger16bits containing 56320, and the 10 low order bits into the UnsignedInteger16bits containing 55296



		// Class Information :
		//
		//  Purpose :
		//
		//		Artifical Inteligence
		//
		//  Description :
		//
		//		1. This object contains an instance of the object "State" to allow each instance of this object to have a defined state
		//
		// 		2. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
		//		   providing 3 keywords :
		//
		//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
		//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
		//						member is public all the encapsulation is lost, so it should be avoided in most cases
		//
		//			2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will
		//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few
		//						   data members
		//
		//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
		//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this
		//						 part will end with the suffix __Private
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		Too many to count
		//
		class UnicodeCharacter NotForInheritance
		{
		public:


			// Create a type definition of this object
			using SelfType = UnicodeCharacter;


			// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
			// the compiler generates a basic behavior for them if possible :


			// Method Information :
			//
			//  Description :
			//
			//		Constructor,
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			unicodeScalarValue - this value will be used to initialize the instance
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		NONE
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline UnicodeCharacter( UnsignedInteger32bits unicodeScalarValue = 0U );


			// Method Information :
			//
			//  Description :
			//
			//		Constructor, to allow creating an instance with the same arguments as the parameterized constructor, just that the arguments will be
			//		wrapped in a tuple, to allow more automatic creation of instances. Each parameterized constructor will have an equivalent constructor
			//		to inokve with a tuple, which will only call the required constructor and unpack the tuple to the arguments inisde
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			arguments - the arguments needed to construct an instance, only wrapped in a tuple. The arguments are :
			//
			//				1. unicodeScalarValue - this value will be used to initialize the instance
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		NONE
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			explicit inline UnicodeCharacter( const Tuple< UnsignedInteger32bits >& arguments );


			// Method Information :
			//
			//  Description :
			//
			//		Copy constructor, will operate correctly even if the other instance is in default state or self assignment
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//		    other - a reference to the instance that should be copied
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		NONE
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline UnicodeCharacter( const SelfType& other );


			// This macro will be used to add all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
			// simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
			// any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
			// be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
			// macro will be used to add the following methods to each object :
			//
			//		1. Assigenment operator
			//		2. Move constructor
			//		3. Move assigenment operator
			//		4. Reset
			//		5. State
			//
			ObjectInfrastructure_ForInheritance_WithStateAlwaysReady_MACRO( UnicodeCharacter )


			// Method Information :
			//
			//  Description :
			//
			//		This method is used to swap the content between this instance and the other one
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//		    other - a reference to the instance that should be swapped
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		NONE
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline void Swap( SelfType& other );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			unicodeScalarValue - this value will be used to initialize the instance
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		NONE
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline void Initiate( UnsignedInteger32bits unicodeScalarValue = 0U );


			// Method Information :
			//
			//  Description :
			//
			//		Destructor, does not throw
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
			//		NONE
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline ~UnicodeCharacter() = default;


			// The following methods give access and manipulate the data inside this object :


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get the unicode character inside to allow the standard output to recognize the type
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
			//		The unicode character inside
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline UnsignedInteger32bits Get() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to check if the current unicode character value represent a digit
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
			//		1. true - if the current value represent a digit
			//		2. false - otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline Boolean Digit() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to check if the current unicode character value represent an English alphabet letter in the capital form
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
			//		1. true - if the current value represent an English alphabet capital letter
			//		2. false - otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline Boolean EnglishAlphabetCapitalLetter() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to check if the current unicode character value represent an English alphabet letter in the small form
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
			//		1. true - if the current value represent an English alphabet small letter
			//		2. false - otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline Boolean EnglishAlphabetSmallLetter() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to check if the current value represent an English alphabet letter
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
			//		1. true - if the current value represent an English alphabet letter
			//		2. false - otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline Boolean EnglishAlphabetLetter() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to convert an english alphabet letter from the small form to capital form
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
			//		NONE
			//
			//  Expectations :
			//
			//		1. The current value in the instance describes one of the letters in the english alphabet
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline void ConvertToCapitalLetter();


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to convert an english alphabet letter from capital form to small form
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
			//		NONE
			//
			//  Expectations :
			//
			//		1. The current value in the instance describes one of the letters in the english alphabet
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline void ConvertToSmallLetter();


			// The following methods are to allow compress and decompress to the unicode transfer formats 8 and 6 ( UTF-8 and UTF-16 ) :


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
			UnsignedInteger64bits CompressAs_UTF8( void* destinationToStore_UTF8_compression ) const;


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
			//   	The number of bytes needed to compress the unicode scalar value as UTF-16
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
			UnsignedInteger64bits CompressAs_UTF16( void* destinationToStore_UTF16_compression ) const;


			// Method Information :
			//
			//  Description :
			//
			// 		Use to decompress UTF-8 into a unicode scalar value and store inside this instance
			//
			//  Required arguments :
			//
		    //   	User information needed :
			//
			//			UTF8_compression - a pointer to the memory address where the unicode scalar value compressd as UTF-8 is stored
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//   	The number of bytes the compressd unicode scalar value as UTF-8 contains
			//
			//	Expectations :
		    //
		    //		1. The given pointer is not NULL
		    //		2. The given UTF-8 is compressd correctly
		    //		3. 
		    //
			//  Possible errors :
			//
			//		NONE
		    //
			UnsignedInteger64bits DecompressFrom_UTF8( const void* UTF8_compression );


			// Method Information :
			//
			//  Description :
			//
			// 		Use to decompress UTF-16 into a unicode scalar value and store inside this instance
			//
			//  Required arguments :
			//
		    //   	User information needed :
			//
			//			UTF16_compression - a pointer to the memory address where the unicode scalar value compressd as UTF-16 is stored
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//   	The number of bytes the compressd unicode scalar value as UTF-16 contains
			//
			//	Expectations :
		    //
		    //		1. The given pointer is not NULL
		    //		2. The given UTF-16 is compressd correctly
		    //		3. 
		    //
			//  Possible errors :
			//
			//		NONE
		    //
			UnsignedInteger64bits DecompressFrom_UTF16( const void* UTF16_compression );


			// Method Information :
			//
			//  Description :
			//
		    // 		Use to check the amount of bytes would take to compress the unicode character as UTF-8    	
		    //
			//  Required arguments :
			//
		    //   	User information needed :
			//
			//			NONE
			//
			//      Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//   	The amount of bytes that would take to compress the unicode character into UTF-8
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		NONE
			//
		    inline UnsignedInteger64bits GetNumberOfBytesNeededToStoreTheCompressedUnicodeCharacterAs_UTF8() const;


			// Method Information :
			//
			//  Description :
			//
		    // 		Use to check the amount of pair bytes, each element in UTF-16 takes at least two bytes, would take to compress the unicode character as UTF-16
		    //
			//  Required arguments :
			//
		    //   	User information needed :
			//
			//			NONE
			//
			//      Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//   	The amount of pair bytes, each element in UTF-16 takes at least two bytes, would take to compress the unicode character as UTF-16
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		NONE
			//
		    inline UnsignedInteger64bits GetNumberOfPairBytesNeededToStoreTheCompressedUnicodeCharacterAs_UTF16() const;


			// The following methods declare the overloaded operators for the object :


			// Method Information :
			//
			//  Description :
			//
			//		Use this operator to check if the this instance match the other
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//		    other - a reference to the instance that should be compared with this object
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		1. true - if the 2 instances are the same
			//		2. false - otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline Boolean operator==( const SelfType& other ) const;


			// Method Information :
			//
			//  Description :
			//
			//		Use this operator to check if the this instance does not match the other
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//		    other - a reference to the instance that should be compared with this object
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		1. true - if the 2 instances are not the same
			//		2. false - otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline Boolean operator!=( const SelfType& other ) const;


			// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have
			// access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring
			// a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this method to generate a random instance of this object
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          rangeForUnicodeCharacter - this will be used to limit the possible size of the random instance
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //      A random generated instance
	        //
	        //  Expectations :
	        //
	        //      NONE
	        //
	        //  Possible errors :
	        //
	        //		They will come
	        //
	        static inline SelfType GenerateRandomInstance( NumericRange< UnsignedInteger32bits > rangeForUnicodeCharacter = NumericRange< UnsignedInteger32bits >( 1U, 118480U ) );


	    	// Method Information :
			//
			//  Description :
			//
			//		Use to get the amount of bytes needed to compress the unicode scalar value as UTF-8
			//
			//  Required arguments :
			//
		    //   	User information needed :
			//
			//			  UTF8_compression - a pointr to the memory address with a unicode scalar value compressd into UTF-8
			//
			//      Information returned to the user :
			//
			//            NONE
			//
			//  Return value :
			//
			//   	The amount of bytes needed to compress the unicode scalar value as UTF-8
			//
			//  Expectations :
			//
			//		1. The given pointer is not NULL
			//		2. The given UTF-8 was compressd correctly
			//		3. 
			//
			//  Possible errors :
			//
			//		NONE
		    //
			static inline UnsignedInteger64bits GetNumberOfBytesNeededToStoreTheCompressedUnicodeCharacterAs_UTF8( const UnsignedInteger8bits* UTF8_compression );


			// Method Information :
			//
			//  Description :
			//
			//		Use to get the amount of pair bytes, each element in UTF-16 takes at least two bytes, needed to compress the unicode scalar value as UTF-16
			//
			//  Required arguments :
			//
		    //   	User information needed :
			//
			//			  UTF16_compression - a pointr to the memory address with a unicode scalar value compressd into UTF-16
			//
			//      Information returned to the user :
			//
			//            NONE
			//
			//  Return value :
			//
			//   	The amount of pair bytes, each element in UTF-16 takes at least two bytes, needed to compress the unicode scalar value as UTF-16
			//
			//  Expectations :
			//
			//		1. The given pointer is not NULL
			//		2. The given UTF-16 was compressd correctly
			//		3. 
			//
			//  Possible errors :
			//
			//		NONE
		    //
			static inline UnsignedInteger64bits GetNumberOfPairBytesNeededToStoreTheCompressedUnicodeCharacterAs_UTF16( const UnsignedInteger16bits* UTF16_compression );


			DEBUG_TOOL(

				// This part of the object is dedicated for testing :


				// Method Information :
				//
				//  Description :
				//
				//		This method is used to test the object. It is not part of the implementation, it is only used to find problems with the code
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
				//			NONE
				//
				//  Expectations :
				//
				//		Please let the test pass lord!!
				//
				//  Possible errors :
				//
				//		It says there are no problems, which is even scarier, did I just wrote a working code??
				//
				static void Test() __attribute__ ((unused));

			)  //  End of debug tool


		private:


			// This object will store the unicode character
			UnsignedInteger32bits member_unicodeScalarValue;


			// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
			// rather help implement it :


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to check if the UTF-8 was compressd correctly
			//
			//  Required arguments :
			//
		    //   	User information needed :
			//
			//			UTF8_compression - a unicode character compressd into UTF-8 
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//   	1. true - if the UTF-8 was compressd correctly 
			//		2. false - if the UTF-8 was not encoding correctly
			//
			//  Expectations :
			//
			//		1. The given pointer is not NULL
			//		2. 
			//
			//  Possible errors :
			//
			//		NONE
		    //
			static inline Boolean Verify_UTF8_Compression__Private( const UnsignedInteger8bits* UTF8_compression );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to check if the UTF-16 was compressd correctly
			//
			//  Required arguments :
			//
		    //   	User information needed :
			//
			//			UTF8_compression - a unicode character compressd into UTF-16
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//   	1. true - if the UTF-16 was compressd correctly 
			//		2. false - if the UTF-16 was not encoding correctly
			//
			//  Expectations :
			//
			//		1. The given pointer is not NULL
			//		2. 
			//
			//  Possible errors :
			//
			//		NONE
		    //
			static inline Boolean Verify_UTF16_Compression__Private( const UnsignedInteger16bits* UTF16_compression );


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
		    //      	1. UTF8_destinationToSetTemplate - the addrss to set the UTF-8 template in
		    //			2. numberOfBytesNeededToCompressAs_UTF8 - the number of bytes required to compress the unicode character into UTF-8 encoding  
			//
			//      Information returned to the user :
			//
			//            NONE
			//
			//  Return value :
			//
			//   	The amount of bytes that would take to compress the unicode character into UTF-8
			//
			//  Expectations :
			//
			//		1. The given pointer is not NULL
			//		2. 
			//
			//  Possible errors :
			//
		    //		NONE
		    //
		    inline void Set_UTF8_template__Private( UnsignedInteger8bits* UTF8_destinationToSetTemplate, UnsignedInteger8bits numberOfBytesNeededToCompressAs_UTF8 ) const;


    		// Method Information :
			//
			//  Description :
			//
			//		Use to set the required UTF-16 template into the given destination address
		    //
			//  Required arguments :
			//
		    //   	User information needed :
			//
		    //      	UTF8_destinationToSetTemplate - the addrss to set the UTF-16 template in
			//
			//      Information returned to the user :
			//
			//            NONE
			//
			//  Return value :
			//
		    //		NONE
			//
			//  Expectations :
			//
			//		1. The given pointer is not NULL
			//		2. 
			//
			//  Possible errors :
			//
		    //		NONE
		    //
		    inline void Set_UTF16_template__Private( UnsignedInteger16bits* UTF16_destinationToSetTemplate ) const;


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
			//			2. numberOfBytesNeededToCompressAs_UTF8 - the number of bytes needed to compressd as UTF-8	
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
			void CompressAs_UTF8_OnSystemsWithLittleEndianEncoding__Private( UnsignedInteger8bits* destinationToStore_UTF8_compression, UnsignedInteger8bits numberOfBytesNeededToCompressAs_UTF8 ) const;


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
			void CompressAs_UTF16_OnSystemsWithLittleEndianEncoding__Private( UnsignedInteger16bits* destinationToStore_UTF16_compression ) const;


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
			//			1. destinationToStore_UTF8_compression - a location to store the unicode scalar value compressd as UTF-8
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
			void CompressAs_UTF8_OnSystemsWithBigEndianEncoding__Private( UnsignedInteger8bits* destinationToStore_UTF8_compression, UnsignedInteger8bits numberOfBytesNeededToCompressAs_UTF8 ) const;


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
			//			destinationToStore_UTF16_compression - a location to store the unicode scalar value compressd as UTF-16
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
			void CompressAs_UTF16_OnSystemsWithBigEndianEncoding__Private( UnsignedInteger16bits* destinationToStore_UTF16_compression ) const;


			// Method Information :
			//
			//  Description :
			//
			// 		Use to decompress the UTF-8 into the unicode scalar value on little endian encoding systems
			//
			//  Required arguments :
			//
		    //   	User information needed :
			//
			//			1. UTF8_compression - a unicode character compressd into UTF-8 
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
			void DecompressFrom_UTF8_OnSystemsWithLittleEndianEncoding__Private( const UnsignedInteger8bits* UTF8_compression, UnsignedInteger8bits numberOfBytesNeededToCompressAs_UTF8 );


			// Method Information :
			//
			//  Description :
			//
			// 		Use to decompress the UTF-16 into the unicode scalar value on little endian encoding systems
			//
			//  Required arguments :
			//
		    //   	User information needed :
			//
			//			UTF16_compression - a unicode character compressd into UTF-16 
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
			void DecompressFrom_UTF16_OnSystemsWithLittleEndianEncoding__Private( const UnsignedInteger16bits* UTF16_compression );


			// Method Information :
			//
			//  Description :
			//
			// 		Use to decompress the UTF-8 into the unicode scalar value on big endian encoding systems
			//
			//  Required arguments :
			//
		    //   	User information needed :
			//
			//			1. UTF8_compression - a unicode character compressd into UTF-8 
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
			void DecompressFrom_UTF8_OnSystemsWithBigEndianEncoding__Private( const UnsignedInteger8bits* UTF8_compression, UnsignedInteger8bits numberOfBytesNeededToCompressAs_UTF8 );


			// Method Information :
			//
			//  Description :
			//
			// 		Use to decompress the UTF-16 into the unicode scalar value on big endian encoding systems
			//
			//  Required arguments :
			//
		    //   	User information needed :
			//
			//			UTF16_compression - a unicode character compressd into UTF-16
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
			void DecompressFrom_UTF16_OnSystemsWithBigEndianEncoding__Private( const UnsignedInteger16bits* UTF16_compression );


			// Friend class or friend function can access private and protected members of other object in which it is declared as friend. It is sometimes useful
			// to allow a particular object to access private members of other object. The declration of such function is private, because these functions are part
			// of the implemntation, which the user should not be aware of. The use of this functions is not limited to the object's scope. One of the problems that
			// friend declaration solves is when the object needs to be as a right side operand in expressions. Every method in the object is implicitly added a pointer
			// to the location of the object data with the name "this", and to enable this the method must be called from an existing instance. This means that the
			// object can only be implemented as the left side operand of an expression with methods, and friend functions and objects does not have this limitation


			// Method Information :
			//
			//  Description :
			//
			//		Use this operator to check if the this instance match the other
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. unicodeScalarValue - the unicode character to compare with
			//		    2. instance - a reference to the instance that should be compared with the unicode character
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		1. true - if the 2 instances are the same
			//		2. false - otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			friend inline Boolean operator==( UnsignedInteger32bits unicodeScalarValue, const SelfType& instance );


			// Method Information :
			//
			//  Description :
			//
			//		Use this operator to check if the this instance does not match the other
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. unicodeScalarValue - the unicode character to compare with
			//		    2. instance - a reference to the instance that should be compared with the unicode character
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		1. true - if the 2 instances are not the same
			//		2. false - otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			friend inline Boolean operator!=( UnsignedInteger32bits unicodeScalarValue, const SelfType& instance );


		};  //  Class UnicodeCharacter




































//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************




































		// Method Information :
		//
		//  Description :
		//
		//		Constructor,
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			unicodeScalarValue - this value will be used to initialize the instance
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		1. The given value is not negative
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline UnicodeCharacter::UnicodeCharacter( UnsignedInteger32bits unicodeScalarValue ) :
		member_unicodeScalarValue( unicodeScalarValue )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			Assert_MACRO( ( unicodeScalarValue <= 1114111U ), "The given unicode scalar value is larger then the maximum value - 1114111" )
			Assert_MACRO( ( unicodeScalarValue < 55296U ) || ( unicodeScalarValue > 57343U ), "The given unicode scalar value is in the range [55296, 57343] which is no valid" )
		}


		// Method Information :
		//
		//  Description :
		//
		//		Constructor, to allow creating an instance with the same arguments as the parameterized constructor, just that the arguments will be
		//		wrapped in a tuple, to allow more automatic creation of instances. Each parameterized constructor will have an equivalent constructor
		//		to inokve with a tuple, which will only call the required constructor and unpack the tuple to the arguments inisde
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			arguments - the arguments needed to construct an instance, only wrapped in a tuple. The arguments are :
		//
		//				1. unicodeScalarValue - this value will be used to initialize the instance
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline UnicodeCharacter::UnicodeCharacter( const Tuple< UnsignedInteger32bits >& arguments ) :
		UnicodeCharacter( arguments.template Entry< 0 >() )
		{}


		// Method Information :
		//
		//  Description :
		//
		//		Copy constructor, will operate correctly even if the other instance is in default state or self assignment
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//		    other - a reference to the instance that should be copied
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline UnicodeCharacter::UnicodeCharacter( const SelfType& other ) :
		member_unicodeScalarValue( other.member_unicodeScalarValue )
		{}


		// Method Information :
		//
		//  Description :
		//
		//		This method is used to swap the content between this instance and the other one
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//		other - a reference to the instance that should be swaped
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		void UnicodeCharacter::Swap( SelfType& other )
		{
			// Swap between the unicode characters
			Memory::Operations::Swap< UnsignedInteger32bits >( member_unicodeScalarValue, other.member_unicodeScalarValue );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			unicodeScalarValue - this value will be used to initialize the instance
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		1. The given value is not negative
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline void UnicodeCharacter::Initiate( UnsignedInteger32bits unicodeScalarValue )
		{
		    // Use the required constructor to create an instance. It will be swaped with this instance, leaving this instance with the new data. When sequence control will
		    // leave this scope it delete the old data if exist
		    SelfType instanceCreatedUsingTheRequiredConstructor( unicodeScalarValue );

		    // Swap between this instance and the temporary instance
		    Swap( instanceCreatedUsingTheRequiredConstructor );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the unicode character inside to allow the standard output to recognize the type
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
		//		The unicode character inside
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline UnsignedInteger32bits UnicodeCharacter::Get() const
		{
			// Return the the unicode character as 'UnsignedInteger32bits' type, to allow the standard output to recognize type
			return ( member_unicodeScalarValue );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to check if the current unicode character value represent a digit
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
		//		1. true - if the current value represent a digit
		//		2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline Boolean UnicodeCharacter::Digit() const
		{
			// Check if the current unicode character value represent a digit, and return the result
			//
			//		'0' - 48 Decimal
			//		'9' - 57 Decimal
			//
			return ( ( member_unicodeScalarValue >= '0' ) && ( member_unicodeScalarValue <= '9' ) );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to check if the current unicode character value represent an English alphabet letter in the capital form
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
		//		1. true - if the current value represent an English alphabet capital letter
		//		2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline Boolean UnicodeCharacter::EnglishAlphabetCapitalLetter() const
		{
			// Check if the current unicode character value represent an English alphabet letter in the capital form, and return the result
			//
			//		Capital A - 65 Decimal
			//		Capital Z - 90 Decimal
			//
			return ( ( member_unicodeScalarValue >= 'A' ) && ( member_unicodeScalarValue <= 'Z' ) );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to check if the current unicode character value represent an English alphabet letter in the small form
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
		//		1. true - if the current value represent an English alphabet small letter
		//		2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline Boolean UnicodeCharacter::EnglishAlphabetSmallLetter() const
		{
			// Check if the current unicode character value represent an English alphabet letter in the small form, and return the result
			//
			//		Small a - 97 Decimal
			//		Small z - 122 Decimal
			//
			return ( ( member_unicodeScalarValue >= 'a' ) && ( member_unicodeScalarValue <= 'z' ) );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to check if the current value represent an English alphabet letter
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
		//		1. true - if the current value represent an English alphabet letter
		//		2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline Boolean UnicodeCharacter::EnglishAlphabetLetter() const
		{
			// Check if the current value represent one of the English alphabet letters, and return the result. The English alphabet letters has the following
			// values :
			//
			//		Capital A - 65 Decimal
			//		Capital Z - 90 Decimal
			//
			//		Small a - 97 Decimal
			//		Small z - 122 Decimal
			//
			return ( EnglishAlphabetCapitalLetter() || EnglishAlphabetSmallLetter() );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to convert an english alphabet letter from the small form to capital form
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
		//		NONE
		//
		//  Expectations :
		//
		//		1. The current value in the instance describes one of the letters in the english alphabet
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline void UnicodeCharacter::ConvertToCapitalLetter()
		{
			// This will be added only in test mode, to ensure that the given data to the method is valid
			Assert_MACRO( ( EnglishAlphabetLetter() == true ), "The current unicode character value does not represent an English alphabet letter" )

			// Check if the current English alphabet letter is in the capital or small form, if it is in the capital form then there is nothing to do
			if ( EnglishAlphabetSmallLetter() == true )
			{
				// The current English alphabet letter is in the small form

				// Subtract 32 from the current value, to convert the small form into the capital form of the letter
				member_unicodeScalarValue -= 32;
			}

		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to convert an english alphabet letter from capital form to small form
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
		//		NONE
		//
		//  Expectations :
		//
		//		1. The current value in the instance describes one of the letters in the english alphabet
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline void UnicodeCharacter::ConvertToSmallLetter()
		{
			// This will be added only in test mode, to ensure that the given data to the method is valid
			Assert_MACRO( ( EnglishAlphabetLetter() == true ), "The current unicode character value does not represent an English alphabet letter" )

			// Check if the current English alphabet letter is in the capital or small form, if it is in the small form then there is nothing to do
			if ( EnglishAlphabetSmallLetter() == true )
			{
				// The current English alphabet letter is in the capital form

				// Add 32 to the current value, to convert the capital form into the small form of the letter
				member_unicodeScalarValue += 32;
			}

		}


		// Method Information :
		//
		//  Description :
		//
	    // 		Use to check the amount of bytes would take to compress the unicode character as UTF-8    	
	    //
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			NONE
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//   	The amount of bytes that would take to compress the unicode character into UTF-8
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		NONE
		//
	    inline UnsignedInteger64bits UnicodeCharacter::GetNumberOfBytesNeededToStoreTheCompressedUnicodeCharacterAs_UTF8() const
	    {

	        // If the value is between 0 - 127, 1 byte is required
	        if ( member_unicodeScalarValue < 128U )
	        {
	        	// 1 byte is required
	        	return ( 1UL );
	        }
	        // If the value is between 128 - 2047, 2 bytes are required
	        else if ( ( member_unicodeScalarValue >= 128U ) && ( member_unicodeScalarValue < 2048U ) )
	        {
	        	// 2 bytes are required
	        	return ( 2UL );
	        }
	        // If the value is between 2048 - 65535, 3 bytes are required
	        else if ( ( member_unicodeScalarValue >= 2048U ) && ( member_unicodeScalarValue < 65536U ) )
	        {
	        	// 3 bytes are required
	        	return ( 3UL );
	        }

		    // If the control reached here the value is between 65535 - 1114111, 4 bytes are required
	    	return ( 4UL );
	    }


		// Method Information :
		//
		//  Description :
		//
	    // 		Use to check the amount of pair bytes, each element in UTF-16 takes at least two bytes, would take to compress the unicode character as UTF-16
	    //
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			NONE
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//   	The amount of pair bytes, each element in UTF-16 takes at least two bytes, would take to compress the unicode character as UTF-16
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		NONE
		//
	    inline UnsignedInteger64bits UnicodeCharacter::GetNumberOfPairBytesNeededToStoreTheCompressedUnicodeCharacterAs_UTF16() const
	    {
			// The return value will not be the number of bytes, but rather the number of pair bytes, because the UTF-16 uses two bytes each time.
			// This is done to allow simpler pointer arithmetic

			// Check if the first byte contains a value not in the range [55296,57343], which means it needed only two bytes to compress as UTF-16,
			ReturnValueIfExpressionIsTrue_MACRO( ( member_unicodeScalarValue < 65536U ), 1UL )

            // If control reached here 4 bytes were needed to compress as UTF-16
            return ( 2UL );
        }


































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



































		// Method Information :
		//
		//  Description :
		//
		//		Use this operator to check if the this instance match the other
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//		    other - a reference to the instance that should be compared with this object
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		1. true - if the 2 instances are the same
		//		2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline Boolean UnicodeCharacter::operator==( const SelfType& other ) const
		{
			// Compare between the unicode characters and return the result
			return ( member_unicodeScalarValue == other.member_unicodeScalarValue );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this operator to check if the this instance does not match the other
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//		    other - a reference to the instance that should be compared with this object
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		1. true - if the 2 instances are not the same
		//		2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline Boolean UnicodeCharacter::operator!=( const SelfType& other ) const
		{
			// Return the negotiated value from the equal operator
			return ( !( *this == other ) );
		}




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************






































        // Method Information :
        //
        //  Description :
        //
        //      Use this method to generate a random instance of this object
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rangeForUnicodeCharacter - this will be used to limit the possible size of the random instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A random generated instance
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //		They will come
        //
        inline UnicodeCharacter UnicodeCharacter::GenerateRandomInstance( NumericRange< UnsignedInteger32bits > rangeForUnicodeCharacter )
        {
			// Create an instance
			SelfType randomInstance;

			// This object will store the random generate unicode scalar value
			UnsignedInteger32bits randomUnicodeScalarValue = 1114112U;

			// Loop until the value is in the unicode possible range which is, smaller then 1114111, and not in the range [55296, 57343]
			while ( ( randomUnicodeScalarValue > 1114111U ) || ( ( randomUnicodeScalarValue >= 55296 ) && ( randomUnicodeScalarValue <= 57343 ) ) )
			{
				// Generate random unicode character in the required range
				randomUnicodeScalarValue = Random::Generator::Get< UnsignedInteger32bits >( rangeForUnicodeCharacter );
			}

			// Initiate the instance using the random generate unicode scalar value
			randomInstance.Initiate( randomUnicodeScalarValue );

        	// Return a copy of the random instance
        	return ( randomInstance );
        }


		// Method Information :
		//
		//  Description :
		//
		//		Use to get the amount of bytes needed to compress the unicode scalar value as UTF-8
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			  UTF8_compression - a pointr to the memory address with a unicode scalar value compressd into UTF-8
		//
		//      Information returned to the user :
		//
		//            NONE
		//
		//  Return value :
		//
		//   	The amount of bytes needed to compress the unicode scalar value as UTF-8
		//
		//  Expectations :
		//
		//		1. The given pointer is not NULL
		//		2. The given UTF-8 was compressd correctly
		//		3. 
		//
		//  Possible errors :
		//
		//		NONE
	    //
		inline UnsignedInteger64bits UnicodeCharacter::GetNumberOfBytesNeededToStoreTheCompressedUnicodeCharacterAs_UTF8( const UnsignedInteger8bits* UTF8_compression )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertPointer_MACRO( UTF8_compression )
			Assert_MACRO( Verify_UTF8_Compression__Private( UTF8_compression ), "The given UTF-8 encoding is malformed" )

			// The number of bits that are on ( 1 ) before the first bit that is off ( 0 ), represents the number of bytes used to compress as UTF-8 

			// Check if the first bit is off ( 0 )
			if ( 0U == ( 0x80 & *UTF8_compression ) )
			{
				// There are no bits on ( 1 ) before the first bit that is off, therefore the encoding needed 1 byte
				return ( 1UL );
			}
			// Check if there are 2 bits on ( 1 ) before the first bit that is off ( 0 )
			else if ( 0xC0 == ( 0xE0 & *UTF8_compression ) )
			{
				// There are 2 bits on ( 1 ) before the first bit that is off ( 0 )
				return ( 2UL );
			}
			// Check if there are 3 bits on ( 1 ) before the first bit that is off ( 0 )
			else if ( 0xE0 == ( 0xF0 & *UTF8_compression ) )
			{
				// There are 3 bits on ( 1 ) before the first bit that is off ( 0 )
				return ( 3UL );
			}

			// If the control reached here there are 4 bits on ( 1 ) before the first bit that is off ( 0 )
			return ( 4UL );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use to get the amount of pair bytes, each element in UTF-16 takes at least two bytes, needed to compress the unicode scalar value as UTF-16
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			  UTF8_compression - a pointr to the memory address with a unicode scalar value compressd into UTF-16
		//
		//      Information returned to the user :
		//
		//            NONE
		//
		//  Return value :
		//
		//   	The amount of pair bytes, each element in UTF-16 takes at least two bytes, needed to compress the unicode scalar value as UTF-16
		//
		//  Expectations :
		//
		//		1. The given pointer is not NULL
		//		2. The given UTF-16 was compressd correctly
		//		3. 
		//
		//  Possible errors :
		//
		//		NONE
	    //
		inline UnsignedInteger64bits UnicodeCharacter::GetNumberOfPairBytesNeededToStoreTheCompressedUnicodeCharacterAs_UTF16( const UnsignedInteger16bits* UTF16_compression )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertPointer_MACRO( UTF16_compression )
			Assert_MACRO( Verify_UTF16_Compression__Private( UTF16_compression ), "The given UTF-16 encoding is malformed" )

			// The return value will not be the number of bytes, but rather the number of pair bytes, because the UTF-16 uses two bytes each time.
			// This is done to allow simpler pointer arithmetic

			// Check if the first byte contains a value not in the range [55296,57343], which means it needed only two bytes to compress as UTF-16,
			ReturnValueIfExpressionIsTrue_MACRO( ( ( UTF16_compression[0] < 55296U ) || ( UTF16_compression[0] > 57343U ) ), 1UL )

            // If control reached here 4 bytes were needed to compress as UTF-16
            return ( 2UL );
		}






































// **********************************************************   INLINE AND TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   ***********************************************************



































		// Method Information :
		//
		//  Description :
		//
		//		Use this operator to check if the this instance match the other
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. unicodeScalarValue - the unicode character to compare with
		//		    2. instance - a reference to the instance that should be compared with the unicode character
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		1. true - if the 2 instances are the same
		//		2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline Boolean operator==( UnsignedInteger32bits unicodeScalarValue, const UnicodeCharacter& instance )
		{
			// Compare between the unicode characters and return the result
			return ( unicodeScalarValue == instance.member_unicodeScalarValue );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this operator to check if the this instance does not match the other
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. unicodeScalarValue - the unicode character to compare with
		//		    2. instance - a reference to the instance that should be compared with the unicode character
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		1. true - if the 2 instances are not the same
		//		2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline Boolean operator!=( UnsignedInteger32bits unicodeScalarValue, const UnicodeCharacter& instance )
		{
			// Return the negotiated value from the equal operator
			return ( !( unicodeScalarValue == instance ) );
		}




































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************
































		// Method Information :
		//
		//  Description :
		//
		//		Use this method to check if the UTF-8 was compressd correctly
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			UTF8_compression - a unicode character compressd into UTF-8 
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	1. true - if the UTF-8 was compressd correctly 
		//		2. false - if the UTF-8 was not encoding correctly
		//
		//  Expectations :
		//
		//		1. The given pointer is not NULL
		//		2. 
		//
		//  Possible errors :
		//
		//		NONE
	    //
		inline Boolean UnicodeCharacter::Verify_UTF8_Compression__Private( const UnsignedInteger8bits* UTF8_compression )
		{
			// The first byte is used to determine the number of bytes the UTF-8 encoding needed 

			// Check if the first bit is OFF, then the encoding is correct
			ReturnValueIfExpressionIsTrue_MACRO( ( 0U == ( 0x80 & UTF8_compression[0] ) ), true )

			// Now it is known that the first bit is ON

			// Check if the second bit is OFF, then the encoding is not correct
			ReturnValueIfExpressionIsTrue_MACRO( ( 0x40 != ( 0x40 & UTF8_compression[0] ) ), false )

			// Now it is known that the first two bits are ON

			// Check if the third bit is OFF. If the third bit is OFF verify that the second byte of the UTF8 encoding 
			// starts with one bit ON and then one bit OFF
			ReturnValueIfExpressionIsTrue_MACRO( ( 0x00 == ( 0x20 & UTF8_compression[0] ) ), ( 0x80 == ( 0xC0 & UTF8_compression[1] ) ) )

			// Now it is known that the first three bits are ON

			// Check if the fourth bit is OFF. If the fourth bit is OFF verify that the second and third bytes of the UTF8 encoding 
			// starts with one bit ON and then one bit OFF
			ReturnValueIfExpressionIsTrue_MACRO( ( 0x00 == ( 0x10 & UTF8_compression[0] ) ), ( ( 0x80 == ( 0xC0 & UTF8_compression[1] ) ) && ( 0x80 == ( 0xC0 & UTF8_compression[2] ) ) ) )

			// Now it is known that the first four bits are ON

			// Check if the fifth bit is OFF. If the fifth bit is OFF verify that the second, third and fourth bytes of the UTF8 encoding 
			// starts with one bit ON and then one bit OFF
			ReturnValueIfExpressionIsTrue_MACRO( ( 0x00 == ( 0x08 & UTF8_compression[0] ) ), ( ( 0x80 == ( 0xC0 & UTF8_compression[1] ) ) && ( 0x80 == ( 0xC0 & UTF8_compression[2] ) ) && ( 0x80 == ( 0xC0 & UTF8_compression[3] ) ) ) )

			// If control of the method reached here then the UTF8 encoding is not correct, return false
			return ( false );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to check if the UTF-16 was compressd correctly
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			UTF8_compression - a unicode character compressd into UTF-16
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	1. true - if the UTF-16 was compressd correctly 
		//		2. false - if the UTF-16 was not encoding correctly
		//
		//  Expectations :
		//
		//		1. The given pointer is not NULL
		//		2. 
		//
		//  Possible errors :
		//
		//		NONE
	    //
		inline Boolean UnicodeCharacter::Verify_UTF16_Compression__Private( const UnsignedInteger16bits* UTF16_compression )
		{
			// Check if the first byte contains a value not in the range [55296,57343], which means it needed only two bytes to compress as UTF-16,
			// and the encoding in correct
			ReturnValueIfExpressionIsTrue_MACRO( ( ( UTF16_compression[0] < 55296U ) || ( UTF16_compression[0] > 57343U ) ), true )

            // If control reached here 4 bytes were needed to compress as UTF-16, and there is a template set in the bytes to check

            // Verify that the bytes value are in the permitted range 
            ReturnValueIfExpressionIsTrue_MACRO( ( ( ( UTF16_compression[0] >= 55296U ) && ( UTF16_compression[0] <= 56319U ) ) && ( ( UTF16_compression[1] >= 56320U ) && ( UTF16_compression[1] <= 57343U ) ) ), true )

            // If control reached here the UTF-16 is not compressd correctly, return false
            return ( false );
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
	    //      	1. UTF8_destinationToSetTemplate - the addrss to set the UTF-8 template in
	    //			2. numberOfBytesNeededToCompressAs_UTF8 - the number of bytes required to compress the unicode character into UTF-8 encoding  
		//
		//      Information returned to the user :
		//
		//            NONE
		//
		//  Return value :
		//
		//   	The amount of bytes that would take to compress the unicode character into UTF-8
		//
		//  Expectations :
		//
		//		1. The given pointer is not NULL
		//		2. 
		//
		//  Possible errors :
		//
	    //		NONE
	    //
	    inline void UnicodeCharacter::Set_UTF8_template__Private( UnsignedInteger8bits* UTF8_destinationToSetTemplate, UnsignedInteger8bits numberOfBytesNeededToCompressAs_UTF8 ) const
	    {
	        // If only 1 byte is required, nothing needs to be done further
	        ReturnIfExpressionIsTrue_MACRO( numberOfBytesNeededToCompressAs_UTF8 == 1 )

	        // Check if 2 bytes are required, set the matching pattern
	        if ( 2 == numberOfBytesNeededToCompressAs_UTF8 )
	        {
	            // Set the high-order byte to the two bytes pattern -> 110xxxxx
	            UTF8_destinationToSetTemplate[0] = 0xC0;

	            // Set all the rest bytes to the pattern -> 10xxxxxx
	            UTF8_destinationToSetTemplate[1] = 0x80;
	        }
	        // Check if 3 bytes are required, set the matching pattern
	        else if ( 3 == numberOfBytesNeededToCompressAs_UTF8 )
	        {
	            // Set the high-order byte to the three bytes pattern -> 1110xxxx
	            UTF8_destinationToSetTemplate[0] = 0xE0;

	            // Set all the rest bytes to the pattern -> 10xxxxxx
	            UTF8_destinationToSetTemplate[1] = 0x80;
	            UTF8_destinationToSetTemplate[2] = 0x80;
	        }
	        // 4 bytes are required, set the matching pattern
	        else // 4 == numberOfBytesNeededToCompressAs_UTF8
	        {
	            // Set the high-order byte to the four bytes pattern -> 11110xxx
	            UTF8_destinationToSetTemplate[0] = 0xF0;

	            // Set all the rest bytes to the pattern -> 10xxxxxx
	            UTF8_destinationToSetTemplate[1] = 0x80;
	            UTF8_destinationToSetTemplate[2] = 0x80;
	            UTF8_destinationToSetTemplate[3] = 0x80;
	        }

	    }


		// Method Information :
		//
		//  Description :
		//
		//		Use to set the required UTF-16 template into the given destination address
	    //
		//  Required arguments :
		//
	    //   	User information needed :
		//
	    //      	UTF8_destinationToSetTemplate - the addrss to set the UTF-16 template in
		//
		//      Information returned to the user :
		//
		//            NONE
		//
		//  Return value :
		//
	    //		NONE
		//
		//  Expectations :
		//
		//		1. The given pointer is not NULL
		//		2. 
		//
		//  Possible errors :
		//
	    //		NONE
	    //
	    inline void UnicodeCharacter::Set_UTF16_template__Private( UnsignedInteger16bits* UTF16_destinationToSetTemplate ) const
	    {
    		// The unicode saclar value is equal or above 65536. Therefore 4 bytes are required. Set the UTF-16 template first

    		// Set the first pair of 2 bytes into 55296
    		UTF16_destinationToSetTemplate[0] = 0xD800;  // In bits ->   11011000 00000000   10 bits free to set

    		// Set the second pair of 2 bytes into 56320
    		UTF16_destinationToSetTemplate[1] = 0xDC00;  // In bits ->   11011100 00000000   10 bits free to set

    		// Now there are 20 bits from the character scalar value that needs to be set into the UTF-16 encoding. Each 2 bytes has, after setting
    		// the template, 10 bits to store. Where the pair of bytes with the value 0xD800 should contain the most significant 10 bits, and the 
    		// pair with value 0xDC00 should contain the less significant bits
	    }







    }  //  Namespace Language

}  //  Namespace Universe



#endif  // UNICODECHARACTER_HPP