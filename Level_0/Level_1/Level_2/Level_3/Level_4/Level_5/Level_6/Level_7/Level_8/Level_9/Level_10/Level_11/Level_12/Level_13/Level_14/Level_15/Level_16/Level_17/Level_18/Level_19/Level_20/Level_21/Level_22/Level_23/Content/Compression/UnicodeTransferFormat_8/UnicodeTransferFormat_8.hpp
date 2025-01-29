namespace Universe
{


namespace Compression
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
// U+10FFFF ( 0 - 118480 ) range are compressed using sequences of 1 to 4 octets, the next table summarize the encoding :
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



// Rvalue references :
//
// Rvalue references are a new category of reference variables that can bind to rvalues. Rvalues are slippery entities, such as temporaries
// and literal values. up until now, there were no way of binding these safely to reference variables. Technically, an rvalue is an unnamed
// value that exists only during the evaluation of an expression. For example, the following expression produces an rvalue :
//
//      x + ( y * z );  A C++ expression that produces a temporary 
//
// C++ creates a temporary ( an rvalue ) that stores the result of y * z, and then adds it to x. Conceptually, this rvalue evaporates by 
// the time the semicolon is reached, at the end of the full expression. Declaration of an rvalue reference :
//
//      int&& rvalue;   C++11 rvalue reference variable
//
// The traditional reference variables of C++ :
//
//      int& lvalue;
//
// are now called lvalue references. Rvalue references occur almost anywhere, even if they are not used directly in the code. They affect
// the semantics and lifetime of objects in C++11. To see how exactly, it’s time to understand move semantics.
//
//
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



// Class Information :
//
//  Purpose :
//
//		Artifical Inteligence
//
//  Description :
//
//		1. This object is used only to wrap some static methods, which can be used without any instance of the object
//
//		2. This object has all the methods to create, destory, copy and move disabled to ensure that no instances of it will be created
//
// 		3. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
//		   providing 3 keywords :
//
//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
//						member is public all the encapsulation is lost, so it should be avoided in most cases
//
//			2. Protected - this part is for developing purposes, inheritance. A developer can inherit from this object and it will
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
class UnicodeTransferFormat_8 NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = UnicodeTransferFormat_8;


	// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object.
	// Satic functions only have access to static data members, which also don't belong to any instance, this means all other data members
	// can not be used. The only purpose then of declaring a static function is when a private static data member needs to be manipulated,
	// or some functionality needed that does not involve the non static data members


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to compress the given string
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          1. string - a constant reference to the string to compress
	//			2. sizeFromStringToCompress - the size from the string to compress
	//			3. startCompressingFromThisIndexOnString - the compressing of the string will start from this index
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      NONE
	//
	//  Expectations :
	//
	//		1. The given string size should be larger then 0
	//		2. The given index to start the compression from plus the size should be equal or smaller then the string size
	//		3. The given string should contain valid unicode scalar values in the range [0, 1114111)
	//		4. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	EnsureRetrunValueIsUsed static inline Memory::Vector< UnsignedInteger8bits > Compress( const Language::String& string, const UnsignedInteger64bits sizeFromStringToCompress, const UnsignedInteger64bits startCompressingFromThisIndexOnString = 0UL );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to uncompress the given string
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          1. compressedString - a constant reference to the compressed string
    //          2. memoryHandlerName - the enumeration of the memory handler to use
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      NONE
	//
	//  Expectations :
	//
	//		1. The given compressed string size should be larger then 0
	//		2. The given string should be compressed correctly
	//		3. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	EnsureRetrunValueIsUsed static inline Language::String Expand( const Memory::Vector< UnsignedInteger8bits >& compressedString, const MemoryHandlerName memoryHandlerName = MemoryHandlerName::Vector );


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
		static void UnitTest() __attribute__ (( __unused__ ));

	)  //  End of debug tool


private:


	// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
	NoInstances( UnicodeTransferFormat_8 );


	// Static data members do not belong to any instance, they belong to the object. Like every global variable it is created with the
	// start of the program and only destroyed when the program ends. The access to the static member is bound to this object of course


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of
	// the interface, but rather help implement it :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method on a character, to check how much bytes are needed to store the compressed character
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          character - the character to perform the check on
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      The number of bytes needed to store the compressed character
	//
	//  Expectations :
	//
	//		1. The given character is within the valid unicode scalar value range [0, 1114111)
	//		2. 
	//
	//  Possible errors :
	//
	//      They will come
	//
    EnsureRetrunValueIsUsed static UnsignedInteger64bits GetNumberOfBytesRequiredToStoreCompressedCharacter__Private( const Language::Character& character );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method on a string, to check how much bytes are needed to store the compressed string
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          string - the string to perform the check on
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      The number of bytes needed to store the compressed string
	//
	//  Expectations :
	//
	//		1. The given string size should be larger then 0
	//		2. The given index to start the compression from plus the size should be equal or smaller then the string size
	//		3. The given string should contain valid unicode scalar values in the range [0, 1114111)
	//		4. 
	//
	//  Possible errors :
	//
	//      They will come
	//
	EnsureRetrunValueIsUsed static UnsignedInteger64bits GetNumberOfBytesRequiredToStoreCompressedString__Private( const Language::String& string, const UnsignedInteger64bits sizeFromStringToCompress, const UnsignedInteger64bits startCompressingFromThisIndexOnString );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to set the unicode transfer format 8 template according to the number of bytes needed to store the 
	//		compressed character
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          1. destinationToSetTemplate - the location at which the template will be set
	//			2. numberOfBytesRequiredToStoreCompressedCharacter - the number of bytes needed to store the compressed character
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      NONE
	//
	//  Expectations :
	//
	//		1. The given pointer to the destination is no NULL
	//		2. The pointer points to a preallocated memory large enough to store the template
	//		3. The number of bytes needed to store the compressed character is within the valid range [0-4]
	//		4.
	//
	//  Possible errors :
	//
	//      They will come
	//
    static void SetTemplate__Private( UnsignedInteger8bits* const destinationToSetTemplate, const UnsignedInteger64bits numberOfBytesRequiredToStoreCompressedCharacter );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to actually perform the compression of the character into the required destination. This method is for systems
	//		with little endian encoding
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          1. characterByte - a pointer that points to the first byte of the character
	//			2. destinationToSetCharacterBits - a pointer that point to the destination to store the compressed character
	//			3. numberOfBytesRequiredToStoreCompressedCharacter - the number of bytes needed to store the compressed character
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      NONE
	//
	//  Expectations :
	//
	//		1. The given pointer to bytes of the character is no NULL
	//		2. The given pointer to the destination is no NULL
	//		3. The pointer to the destination points to a preallocated memory large enough to store the compressed character
	//		4. The number of bytes needed to store the compressed character is within the valid range [0-4]
	//		5.
	//
	//  Possible errors :
	//
	//      They will come
	//
	static void SetTheBitsOfTheCharacterOnLittleEndianSystem__Private( const UnsignedInteger8bits* const characterByte, UnsignedInteger8bits* const destinationToSetCharacterBits, const UnsignedInteger64bits numberOfBytesRequiredToStoreCompressedCharacter );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to actually perform the compression of the character into the required destination. This method is for systems
	//		with big endian encoding
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          1. characterByte - a pointer that points to the first byte of the character
	//			2. destinationToSetCharacterBits - a pointer that point to the destination to store the compressed character
	//			3. numberOfBytesRequiredToStoreCompressedCharacter - the number of bytes needed to store the compressed character
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      NONE
	//
	//  Expectations :
	//
	//		1. The given pointer to bytes of the character is no NULL
	//		2. The given pointer to the destination is no NULL
	//		3. The pointer to the destination points to a preallocated memory large enough to store the compressed character
	//		4. The number of bytes needed to store the compressed character is within the valid range [0-4]
	//		5.
	//
	//  Possible errors :
	//
	//      They will come
	//
	static void SetTheBitsOfTheCharacterOnBigEndianSystem__Private( const UnsignedInteger8bits* const characterByte, UnsignedInteger8bits* const destinationToSetCharacterBits, const UnsignedInteger64bits numberOfBytesRequiredToStoreCompressedCharacter );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to actually perform the compression of the character into the required destination. It will perform correctly
	//		on little and big endian systems
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          1. character - the character to compress
	//			2. destinationToSetCharacterBits - a pointer that point to the destination to store the compressed character
	//			3. numberOfBytesRequiredToStoreCompressedCharacter - the number of bytes needed to store the compressed character
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      NONE
	//
	//  Expectations :
	//
	//		1. The given pointer to bytes of the character is no NULL
	//		2. The given pointer to the destination is no NULL
	//		3. The pointer to the destination points to a preallocated memory large enough to store the compressed character
	//		4. The number of bytes needed to store the compressed character is within the valid range [0-4]
	//		5.
	//
	//  Possible errors :
	//
	//      They will come
	//
	static void SetTheBitsOfTheCharacter__Private( const Language::Character& character, UnsignedInteger8bits* const destinationToSetCharacterBits, const UnsignedInteger64bits numberOfBytesRequiredToStoreCompressedCharacter );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to compress a character into the required destination
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          1. character - the character to compress
	//			2. destinationToSetCharacterBits - a pointer that point to the destination to store the compressed character
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      NONE
	//
	//  Expectations :
	//
	//		1. The given character is within the valid unicode scalar value range [0, 1114111)
	//		2. The given pointer to the destination is no NULL
	//		3. The pointer to the destination points to a preallocated memory large enough to store the compressed character
	//		4.
	//
	//  Possible errors :
	//
	//      They will come
	//
	EnsureRetrunValueIsUsed static UnsignedInteger64bits CompressCharacter__Private( const Language::Character& character, UnsignedInteger8bits* const destinationToStoreCompressesCharacter );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method on a compressed character, to ensure that it compressed correctly
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          compressedCharacterByte - a pointer that points to the bytes of the compressed character
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      True if the character is compressed correctly, and false otherwise
	//
	//  Expectations :
	//
	//		1. The given pointer to the compressed character is not NULL
	//		2. 
	//
	//  Possible errors :
	//
	//      They will come
	//
	EnsureRetrunValueIsUsed static Boolean IsCharacterCompressedCorrectly__Private( const UnsignedInteger8bits* const compressedCharacterByte );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method on a compressed character, to check how much bytes were needed to store the compressed character
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          commpressedCharacterFirstByte - the first byte of the compressed character
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      The number of bytes needed to store the compressed character
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//      They will come
	//
	EnsureRetrunValueIsUsed static UnsignedInteger64bits GetNumberOfBytesRequiredToStoreCompressedCharacter__Private( const UnsignedInteger8bits commpressedCharacterFirstByte );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method on a compressed string, to check how much bytes were needed to store the compressed string
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          compressedString - the compressed string to perform the check on
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      The number of bytes needed to store the compressed string
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//      They will come
	//
	EnsureRetrunValueIsUsed static UnsignedInteger64bits GetNumberOfCharactersCompressed__Private( const Memory::Vector< UnsignedInteger8bits >& compressedString );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method on a compressed character to extract the bits, without the template, and store it in the required destination.
	//		This method is for systems with little endian encoding
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          1. compressedCharacterByte - a pointer that points to the bytes of the compressed character
	//			2. characterByte - a pointer that points to the bytes of the destination to store the extracted character bits
	//			3. numberOfBytesRequiredToStoreCompressedCharacter - the number of bytes needed to store the compressed character
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      NONE
	//
	//  Expectations :
	//
	//		1. The given pointer to the bytes of the compressed character is not NULL
	//		2. The pointer points to a valid compressed character
	//		3. The pointer to the destination to store the extracted character bits is not NULL
	//		4. The pointer to the destination to store the extracted character bits points to a preallocated memory sufficient to store the bits
	//		5. The number of bytes needed to store the compressed character is within the valid range [0-4]
	//		6.
	//
	//  Possible errors :
	//
	//      They will come
	//
	static void ExtractTheBitsOfTheCharacterOnLittleEndianSystem__Private( const UnsignedInteger8bits* const compressedCharacterByte, UnsignedInteger8bits* const characterByte, const UnsignedInteger64bits numberOfBytesRequiredToStoreCompressedCharacter );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method on a compressed character to extract the bits, without the template, and store it in the required destination.
	//		This method is for systems with big endian encoding
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          1. compressedCharacterByte - a pointer that points to the bytes of the compressed character
	//			2. characterByte - a pointer that points to the bytes of the destination to store the extracted character bits
	//			3. numberOfBytesRequiredToStoreCompressedCharacter - the number of bytes needed to store the compressed character
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      NONE
	//
	//  Expectations :
	//
	//		1. The given pointer to the bytes of the compressed character is not NULL
	//		2. The pointer points to a valid compressed character
	//		3. The pointer to the destination to store the extracted character bits is not NULL
	//		4. The pointer to the destination to store the extracted character bits points to a preallocated memory sufficient to store the bits
	//		5. The number of bytes needed to store the compressed character is within the valid range [0-4]
	//		6.
	//
	//  Possible errors :
	//
	//      They will come
	//
	static void ExtractTheBitsOfTheCharacterOnBigEndianSystem__Private( const UnsignedInteger8bits* const compressedCharacterByte, UnsignedInteger8bits* const characterByte, const UnsignedInteger64bits numberOfBytesRequiredToStoreCompressedCharacter );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method on a compressed character to extract the bits, without the template, and store it in the required destination.
	//		It will perform correctly on little and big endian systems
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          1. compressedCharacterByte - a pointer that points to the bytes of the compressed character
	//			2. character - a reference to the memory destination to store the extracted character bits
	//			3. numberOfBytesRequiredToStoreCompressedCharacter - the number of bytes needed to store the compressed character
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      NONE
	//
	//  Expectations :
	//
	//		1. The given pointer to the bytes of the compressed character is not NULL
	//		2. The pointer points to a valid compressed character
	//		3. The number of bytes needed to store the compressed character is within the valid range [0-4]
	//		4.
	//
	//  Possible errors :
	//
	//      They will come
	//
    static void ExtractTheBitsOfTheCharacter__Private( const UnsignedInteger8bits* const compressedCharacterByte, Language::Character& character, const UnsignedInteger64bits numberOfBytesRequiredToStoreCompressedCharacter );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to uncompress a character into the required destination
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          1. compressedCharacterByte - a pointer that points to the bytes of the compressed character
	//			2. character - a reference to the memory destination to store the extracted character bits
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      NONE
	//
	//  Expectations :
	//
	//		1. The given pointer to the bytes of the compressed character is not NULL
	//		2. The pointer points to a valid compressed character
	//		3. 
	//
	//  Possible errors :
	//
	//      They will come
	//
	EnsureRetrunValueIsUsed static UnsignedInteger64bits ExpandCharacter__Private( const UnsignedInteger8bits* const compressedCharacter, Language::Character& character );


};  //  Class UnicodeTransferFormat_8