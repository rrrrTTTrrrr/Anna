namespace Universe
{


namespace Language
{



// If a program could assign a pointer of type T** to a pointer of type const T**, a program could inadvertently modify a const object. 
// For example,
//
//      int main() 
//      {
//          const char c = 'c';
//          char* pc = 0;
//          const char** pcc = &pc;     // not allowed
//          *pcc = &c;
//          *pc = 'C';                  // modifies a const object
//      }
//
// The constant comes to state that the function will not modify the given object. The question then is how to achieve this without resolving
// to ugly casts. The correct way to achieve that is to change the type of the function parameter to 'const pointer* const*'. The additional
// constant between the stars assures the compiler that the method will not try to store pointers to constant objects in the array, since 
// this type declares that the pointer values are also constant



// The byte order mark ( BOM ) is a Unicode character, whose appearance as a magic number at the start of a text stream can signal several 
// things to a program consuming the text :
//
//      1. What byte order, or endianness, the text stream is stored in
//      2. The fact that the text stream is Unicode, to a high level of confidence
//      3. Which of several Unicode encodings that text stream is encoded as
//
// Byte order mark use is optional, and, if used, should appear at the start of the text stream
//
// Unicode can be encoded in units of 8-bit, 16-bit, or 32-bit integers. For the 16- and 32-bit representations, a computer receiving text 
// from arbitrary sources needs to know which byte order the integers are encoded in. Because the BOM itself is encoded in the same scheme 
// as the rest of the document, but has a known value, the consumer of the text can examine these first few bytes to determine the encoding.
// The BOM thus gives the producer of the text a way to describe the text endianness to the consumer of the text without requiring some 
// contract or metadata outside of the text stream itself. Once the receiving computer has consumed the text stream, it is free to process
// the characters in its own native byte order and no longer needs the BOM. Hence the need for a BOM arises in the context of text interchange,
// rather than in text processing within a closed environment
//
// The byte sequence of the BOM character differs per Unicode encoding, and none of the sequences is likely to appear at the start of text
// stored in other encodings. Therefore, placing an encoded BOM at the start of a text stream can serve to indicate the text is Unicode and
// to identify the encoding scheme used, even for UTF-8, which has no endianness
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
//  	1. Letters - a letter is given to each syllable that a human needs to make
//  	2. Words - number of letters that grouped toghter and given meaning
//  	3. Spaces - to distinguish between 2 words, space is used ( also to give the human pauses to breath )
//
// The algorithm used in this class will be using the assumption that each languange uses spaces to distinguish between words. It will
// search to see in which encoding the space appear the most, to decide what the encoding is.
//
// The second assumption of the algorithm is that text is usually written in one language. Now, in a language there is usually a relative
// small set of letters, following is a list of the languages with the most letters in on earth :
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
// As can be seen except for language which has 247 letters, all the languages has less then 128 letters. This can be used in the algorithm.
// If assuming that a text usually consist of 1 language and that language has no more then 128 letters, then for example if the text is 
// stored as UTF-16, the high significant byte will stay the same for the entire text ( except for panctuation ), because to get to all the
// letters of the language only the low significant byte should be changed. The same applies also to UTF-32, the only difference will be the 
// distance between the matching bytes. For example :
//
//      UTF-16 ->  00000011 00110111 00000011 00110100 
//
//      UTF-32 ->  00000000 00000001 00000011 00110100 00000000 00000001 00000011 00111100
//
// As can be seen in UTF-16 there is 1 byte between the matching bytes, and in UTF-32 there are 3 bytes.
//
// Then in unicode the higher significant bytes state the language used, and the low significant bytes state the required letter from 
// the language



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



// A virtual function or virtual method is a function or method whose behavior can be overridden within an inheriting class by a function with the 
// same signature, whereas..
//
// A pure virtual function or pure virtual method is a virtual function that is required to be implemented by a derived class that is not abstract!



// Abstract classes and construction of such
//
// An abstract class cannot be instantiated. He must be inherited in order to have it's constructor called, and since the derived class calls the 
// constructor of the abstract class it doesn't matter what is the protection level, as long as the Derived class can access it.
//
// So it doesn't matter if the constructor is public or protected. One reason that one could possibly have for making it protected is to serve as 
// a reminder that the class must be constructed through inheritance



// A pure virtual function must be implemented in a derived type that will be directly instantiated, however the base type can still define an 
// implementation. A derived class can explicitly call the base class implementation ( if access permissions allow it ) by using a fully-scoped 
// name.
//
// The use case is when there's a more-or-less reasonable default behavior, but the class designer wants that sort-of-default behavior be invoked
// only explicitly. It can also be the case what you want derived classes to always perform their own work but also be able to call a common set 
// of functionality



// The 3 dots function argument, for example :
//
//  void function( int index, ... )
//
// They usually mark the function as having a variable number of arguments. In a real system, however, a system call can’t actually have a variable
// number of arguments. System calls must have a well-defined prototype, because user programs can access them only through hardware “gates”. 
// Therefore, the dots in the prototype represent not a variable number of arguments but a single optional argument, traditionally identified as 
// char *argp. The dots are simply there to prevent type checking during compilation. Using a pointer is the way to pass arbitrary data to the function



// There are two ways to look at inline functios :
//
//  1. Inline functions are declared in the header because, in order to inline a function call, the compiler must be able to see the function body. 
//     For a naive compiler to do that, the function body must be in the same translation unit as the call. ( A modern compiler can optimize across 
// 	   translation units, and so a function call may be inlined even though the function definition is in a separate translation unit, but these 
//	   optimizations are expensive, aren't always enabled, and weren't always supported by the compiler )
//
//  2. Functions declared in the header must be marked inline because otherwise, every translation unit which includes the header will contain a 
//	   definition of the function, and the linker will complain about multiple definitions ( a violation of the One Definition Rule ). The inline 
//	   keyword suppresses this, allowing multiple translation units to contain ( identical ) definitions
//
// The two explanations really boil down to the fact that the inline keyword doesn't exactly do what you'd expect.
//
// A C++ compiler is free to apply the inlining optimization ( replace a function call with the body of the called function, saving the call 
// overhead ) any time it likes, as long as it doesn't alter the observable behavior of the program.
//
// The inline keyword makes it easier for the compiler to apply this optimization, by allowing the function definition to be visible in multiple
// translation units, but using the keyword doesn't mean the compiler has to inline the function, and not using the keyword doesn't forbid the 
// compiler from inlining the function



// When shifting with types that has less bits then the register has there is a thing important to notice when shifting left. Of course the endian
// issue must be thought of, the following description will describe the case of little endian, while big endian workd just the opposite. If the 
// type is shifted left, a temporary is created to store the result, in most cases it would be a register. Now if the type is used the value is 
// correct, but the bits that were removed where just also left shifted on the register which has more space, and not set to 0. The problem only
// arises when using the right shift operation on the type, and expexting for the bits to be set off. To avoid the problem just use casting on the
// temporary created and it will be initialized with the free bits in the registers set to 0



// The IETF policy on character sets and languages says that IETF protocols MUST be able to use the UTF-8 character encoding scheme



// Background and motivation :
//
// The Unicode Standard and ISO/IEC 10646 defind toghter a coded character set, hereafter referred to as Unicode, which encompasses most of the 
// world’s writing systems. UTF-16, the object of this class, is one of the standard ways of encoding unicode scalar value data. It has the 
// characteristics of encoding all currently defined characters ( in plane 0, the BMP ) in exactly 2 bytes and of being able to encode all other
// characters likely to be defined ( the next 16 planes ) in exactly four bytes



// The rules for how characters are encoded in UTF-16 are :
//
//  	1. Characters with values less than 0x10000 ( 65536 ) are represented as a single 16-bit integer with a value equal to that of the 
//		   character number
//	
//  	2. Characters with values between 0x10000 ( 65536 ) and 0x10FFFF ( 1114111 ) are represented by a 16-bit integer with a value between
// 		   0xD800 ( 55296 ) and 0xDBFF ( 56319 ) followed by a 16-bit integer with a value between 0xDC00 ( 56320 ) and 0xDFFF ( 57343 )
//	
//  	3. Characters with values greater than 0x10FFFF ( 1114111 ) cannot be encoded in UTF-16
//
// Values between 0xD800 ( 55296 ) and 0xDFFF ( 57343 ) are specifically reserved for use with UTF-16, and  don’t have any characters 
// assigned to them



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
// with the semantics for the zero-width non-breaking space, and not to be interpreted as a byte-order mark. The contrapositive of that
// statement is not always true. The character 0xFEFF in the first position of a stream MAY be interpreted as a zero-width non-breaking
// space, and is not always a byte-order mark. For example, if a process splits a UTF-16 string into many parts, a part might begin with
// 0xFEFF because there was a zero-width non-breaking space at the beginning of that substring. The Unicode standard further suggests
// than an initial 0xFEFF character may be stripped before processing the text, the rationale being that such a character in initial position
// may be an artifact of the encoding ( an encoding signature ), not a genuine intended "ZERO WIDTH NON-BREAKING SPACE". Note that such 
// stripping might affect an external process at a different layer (such as a digital signature or a count of the characters) that is relying 
// on the presence of all characters in the stream



// The process of encoding a unicode scalar value as UTF-16, when the value is higher then 65536 :
//
// The first step is to subtract 65536 from the given unicode scalar value. The rational is that now the entire value can be represented in
// 20 bites. The second step is to set the UTF-16 template into the allocated space, at the first UnsignedInteger16bits store 56320, and at 
// the second store 55296. Now every UnsignedInteger16bits has 10 empty bits to contain the actual value encoded, set the 10 high order bits
// into the UnsignedInteger16bits containing 56320, and the 10 low order bits into the UnsignedInteger16bits containing 55296



// This enumeration will be used to identify the language used
enum class LanguageName
{

    English

};



// Class Information :
//
//  Purpose :
//
//		Artifical Inteligence
//
//  Description :
//
//		1. This object is used as a base object in inheritance. Therefore it must have a few methods virtual. When an object has a virtual method, the
//		   C++ automatically creates a table with all the pointers to the virtual methods, where the pointer to the table is stored in the beginning of
//		   the object. The problem arises when a new method needs to be created with the same signature as one in the base object, and the use of pointers.
//		   Take a look at next example :
//
//				class Base
//				{
//				    void Display() { cout << "Lord" << endl; }
//				};
//
//				class Derived : public Base
//				{
//				    void Display(); { cout << "Help Me" << endl; }    -> Derived inherits Display from Base but needs another behavior
//				};
//
//         Now if a call is made :
//
//				Base* base = new Base;
//				Derived* derived = new Derived;
//
//				base->Display( 5 );   -> Outputs "Lord"
//				derived->Display();   -> Outputs "Help Me"
//
//         So far so good, a normal method is called by the static type of the pointer. This means no matter what the object the pointer is
//		   pointing to it will call the method of the type he was declared as. This is a problematic behavior in inheritance, we need to point
//		   to derived objects with base pointers and that the correct method will be called. But now :
//
//				void Do( Base* base ) { base->Display(); }
//
//				Base* base = new Base;
//				Derived* derived = new Derived;
//
//				Do( base );        -> Outputs "Lord"
//				Do( derived );     -> Outputs "Lord"
//
//         This is what virtual allow in C++, instead of calling the method by the static type in compilation, the call to the method is picked
//		   dynamically by the actual type of the object. This is done by the pointer in the beginning of the object that points to the virtual
//		   table of the type. Of course it can be overloaded to the derived, but then if there is a deep inheritance a method will be needed to
//		   be overloaded for each one
//
// 		2. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
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
//		3. Template arguments :
//
//			1.
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< typename MemoryManagerType = Memory::MainMemoryManager >
class StringImplementation : public SequentialDataStructure< Character, MemoryManagerType >
{
public:


	// Create a type definition for this object
	using SelfType = StringImplementation< MemoryManagerType >;

    // Create a type definition for the base sequential data structure
    using SelfSequentialDataStructureType = SequentialDataStructure< Character, MemoryManagerType >;


	// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
	// the compiler generates a basic behavior for them if possible :


	// Method Information :
	//
	//  Description :
	//
	//		Constructor, it will use the English language, with all due respect to all other languages
	//
	//  Required arguments :
	//
	//		User information needed :
	//
    //          1. memoryHandlerName - the enumeration of the memory handler to use
    //          2. anyArgumentsNeededToConstructMemoryHandler - any argument needed to construct an instance of the memory handler
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
    template< typename... AnyArgumentsNeededToConstructMemoryHandlerTypes >
	inline StringImplementation( const MemoryHandlerName memoryHandlerName = MemoryHandlerName::Vector, AnyArgumentsNeededToConstructMemoryHandlerTypes... anyArgumentsNeededToConstructMemoryHandler );


    // Method Information :
    //
    //  Description :
    //
    //      Constructor,
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. languageName - the enumeration of the language that will be used in the string
    //          2. memoryHandlerName - the enumeration of the memory handler to use
    //          3. anyArgumentsNeededToConstructMemoryHandler - any argument needed to construct an instance of the memory handler
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
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename... AnyArgumentsNeededToConstructMemoryHandlerTypes >
    inline StringImplementation( const LanguageName languageName, const MemoryHandlerName memoryHandlerName = MemoryHandlerName::Vector, AnyArgumentsNeededToConstructMemoryHandlerTypes... anyArgumentsNeededToConstructMemoryHandler );


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
    //          1. other - a constant reference to other string instance
    //          2. otherInstanceStartingIndex - the index of the first entry that should be copied from the other instance
    //          3. size - the size from the other instance to copy to this instance
    //          4. memoryHandlerName - the enumeration of the memory handler to use
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
    //      1. The size of the other instance should be larger then 0
    //      2. The index to start from on the other instance should be smaller then the size of the other instance
    //      3. The size from other to copy must be larger then 0
    //      4. The size of the other instance minus the index to start from should be larger or equal then the size to copy
    //      5.
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
    explicit inline StringImplementation( const SelfType& other, const LargestUnsignedInteger otherInstanceStartingIndex, const LargestUnsignedInteger size, const MemoryHandlerName memoryHandlerName = MemoryHandlerName::Vector );


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
	//			1. asciiLiteral - a constant reference to an ascii literal instance
    //          2. memoryHandlerName - the enumeration of the memory handler to use
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
	//		1. The ascii literal size should be larger then 0
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	inline StringImplementation( const AsciiLiteral& asciiLiteral, const MemoryHandlerName memoryHandlerName = MemoryHandlerName::Vector );


    // Method Information :
    //
    //  Description :
    //
    //      Constructor,
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. asciiLiteral - a constant reference to an ascii literal instance
    //          2. startingIndexOnAsciiLiteral - the copying of the ascii literal will start from this index
    //          3. size - the size to copy from the ascii literal
    //          4. memoryHandlerName - the enumeration of the memory handler to use
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
    //      1. The size to copy from the ascii literal instance should be larger then 0
    //      2. The starting index on the ascii literal plus the size to copy needs to be smaller or equal to the ascii literal size
    //      3. 
    //
    //  Possible errors :
    //
    //      1. There is no more free memory space - Class std::bad_alloc is thrown
    //      2. 
    //
    inline StringImplementation( const AsciiLiteral& asciiLiteral, const LargestUnsignedInteger startingIndexOnAsciiLiteral, const LargestUnsignedInteger size, const MemoryHandlerName memoryHandlerName = MemoryHandlerName::Vector );


    // Method Information :
    //
    //  Description :
    //
    //      Constructor,
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. rawString - a pointer to an ascii string
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
    //      1. The pointer to the raw string should not be NULL
    //      2. 
    //
    //  Possible errors :
    //
    //      1. There is no more free memory space - Class std::bad_alloc is thrown
    //      2. 
    //
    inline StringImplementation( const AsciiCharacter* const rawString, const MemoryHandlerName memoryHandlerName = MemoryHandlerName::Vector );


	// Method Information :
    //
    //  Description :
    //
    //      Constructor,
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          integer - an integer to convert to string
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
    //		NONE
    //
    //  Possible errors :
    //
    //      1. There is no more free memory space - Class std::bad_alloc is thrown
    //      2. 
    //
    template< Concepts::Integer IntegerType >
    explicit inline StringImplementation( const IntegerType integer );


	// Method Information :
    //
    //  Description :
    //
    //      Constructor,
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          integer - a floating point to convert to string
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
    //		NONE
    //
    //  Possible errors :
    //
    //      1. There is no more free memory space - Class std::bad_alloc is thrown
    //      2. 
    //
	template< Concepts::FloatingPoint FloatingPointType >
	explicit inline StringImplementation( const FloatingPointType floatingPoint );


	// Method Information :
    //
    //  Description :
    //
    //      Constructor,
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          instance -  a constant reference to an instance to convert to string
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
    //		NONE
    //
    //  Possible errors :
    //
    //      1. There is no more free memory space - Class std::bad_alloc is thrown
    //      2. 
    //
	template< Concepts::ConvertibleToStringObject ConvertibleToStringObjectType >
	explicit inline StringImplementation( const ConvertibleToStringObjectType& instance );


	// Method Information :
    //
    //  Description :
    //
    //      Constructor,
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. format - a constant reference to a string that controls where the given arguments, after converted to strings, needs to be 
    //						stored. For each argument that needs to be formatted a curly braces needs to appear "{}". For example :
    //
    //									"Love you all {}, but still need the amount {} of bitches!!!!"
   	//
    //			2. argumentsToFormat - the arguments to format and store in the resulting string
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
    //		1. The format is not empty
    //		2. The format contains amount of "{}" that is equal to the number of given arguments
    //		3. 
    //
    //  Possible errors :
    //
    //      1. There is no more free memory space - Class std::bad_alloc is thrown
    //      2. 
    //
	template< Concepts::ConvertibleToString... ConvertibleToStringTypes >
	explicit inline StringImplementation( const SelfType& format, const ConvertibleToStringTypes&... argumentsToFormat );


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
	inline StringImplementation( const SelfType& other );


	// This macro will be used to add all the functionality that is similiar in each object ( beside the name of the object ). It is done
	// as a macro to allow simple text manipulation, instead of inherting it through an object, which becomes a problem when an object
	// inherits from 2 objects, the first is any object, but the second is an object that also inhrits from the first object. This can be
	// solved through virtual inheritance but then can only be one instance of it. Furthermore, each object in the system will need to
	// inherit from it, which will cause inheritance 'chaos'. Therefore, this macro will be used to add the following methods to each object :
	//
	//		1. Assigenment operator
	//		2. Move constructor
	//		3. Move assigenment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure_ForInheritance( StringImplementation )


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
	virtual ~StringImplementation() = default;


    // This part will contain all the get and set methods for the members of the object :


    GetByValue_Creator( /* GetMethodName */ Language, /* MemberName */ member_languageName, /* MemberType */ LanguageName )


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to convert the string from unicode characters to ascii characters
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    NONE
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The string converted to ascii string
	//
	//  Expectations :
	//
	//		1. The language used in this instance is English
	//		2.
	//
	//  Possible errors :
	//
    //      1. There is no more free memory space - Class std::bad_alloc is thrown
    //      2.
	//
	inline Memory::Vector< AsciiCharacter, MemoryManagerType > ToAsciiString() const;


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
	EnsureRetrunValueIsUsed inline Boolean operator==( const SelfType& other ) const;


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
	EnsureRetrunValueIsUsed inline Boolean operator!=( const SelfType& other ) const;


    // Method Information :
    //
    //  Description :
    //
    //      Use this operator to add content from an other instance to end of this instance
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          other - a constant reference to the instance that should be appended to this instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      A referene to this instance
    //
    //  Expectations :
    //
    //      1. The other instance size should be larger then 0
    //      2. 
    //
    //  Possible errors :
    //
    //      1. There is no more free memory space - Class std::bad_alloc is thrown
    //      2. 
    //
    inline SelfType& operator+=( const SelfType& other );


    // Method Information :
    //
    //  Description :
    //
    //      Use this operator to add content from an ascii literal instance to end of this instance
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          asciiLiteral - a constant reference to an ascii literal instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      A referene to this instance
    //
    //  Expectations :
    //
    //      1. The ascii literal size should be larger then 0
    //      2. 
    //
    //  Possible errors :
    //
    //      1. There is no more free memory space - Class std::bad_alloc is thrown
    //      2. 
    //
    inline SelfType& operator+=( const AsciiLiteral& asciiLiteral );


	// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object.
	// Satic functions only have access to static data members, which also don't belong to any instance, this means all other data members
	// can not be used. The only purpose then of declaring a static function is when a private static data member needs to be manipulated,
	// or some functionality needed that does not involve the non static data members


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to count the number of digits in the given integer
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          integer - the integer to count the number of digits for
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      The number of digits in the given integer
	//
	//  Expectations :
	//
    //		1. The given template type should be integer type
    //		2. 
	//
	//  Possible errors :
	//
    //		They will come
	//
	template< Concepts::Integer IntegerType >
	EnsureRetrunValueIsUsed static inline LargestUnsignedInteger NumberOfDigits( const IntegerType integer );


    // Template method Information :
    //
    //  Description :
    //
    //      Use this method to convert the signed integer into a string
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //			1. destinationStringPointer - the destination memory space to store the digits of the integer
    //			2. integer - the signed integer that should be converted to string
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      True if the integer was converted to string successfully, and false otherwise
    //
	//  Expectations :
    //
    //      1. The given pointer is not NULL	
    //		2. The pointer points to a memory space sufficient to contain all the digits of the integer
    //		3.
    //
    //  Possible errors :
    //
    //		NONE
    //
	template< Concepts::SignedInteger SignedIntegerType >
	EnsureRetrunValueIsUsed static inline LargestUnsignedInteger IntegerToString( Character* const destinationStringPointer, const SignedIntegerType integer );


    // Template method Information :
    //
    //  Description :
    //
    //      Use this method to convert the unsigned integer into a string
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //			1. destinationStringPointer - the destination memory space to store the digits of the integer
    //			2. integer - the unsigned integer that should be converted to string
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      True if the integer was converted to string successfully, and false otherwise
    //
	//  Expectations :
    //
    //      1. The given pointer is not NULL	
    //		2. The pointer points to a memory space sufficient to contain all the digits of the integer
    //		3.
    //
    //  Possible errors :
    //
    //		NONE
    //
	template< Concepts::UnsignedInteger UnsignedIntegerType >
	EnsureRetrunValueIsUsed static inline LargestUnsignedInteger IntegerToString( Character* const destinationStringPointer, const UnsignedIntegerType integer );


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
		static inline void UnitTest() __attribute__ (( __unused__ ));

	)  //  End of debug tool


private:


    // This object will store the language name that used in this instance
    LanguageName member_languageName;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to calculate the number of characters required to store the formatted string
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. format - a constant reference to a string with the format
	//			2. argumentsToFormat - the arguments to format and store in the resulting string
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
	//		1. The format size is larger then 0
	//		2. 
	//
	//  Possible errors :
	//
	//		NONE
	//
	template< Concepts::ConvertibleToString... ConvertibleToStringTypes >
	EnsureRetrunValueIsUsed inline LargestUnsignedInteger CalculateFormattedStringSize__Private( const SelfType& format, const ConvertibleToStringTypes&... argumentsToFormat );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to calculate the number of characters required to store the formatted string. This overload will perform 
	//		recursive calls to expose a new argument each time. The recursion will end when there is only one argument left, and then
	//		the overload for that case will be called
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. firstArgumentToFormat - the first argument to format
	//			2. secondArgumentToFormat - the second argument to format
	//			3. restOfArgumentsToFormat - the rest of the arguments to format and store in the resulting string
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
	//		The number of characters required to store all of the argument as string
	//
	//  Possible errors :
	//
	//		NONE
	//
	template< Concepts::ConvertibleToString FirstExposedConvertibleToStringType, Concepts::ConvertibleToString SecondExposedConvertibleToStringType, Concepts::ConvertibleToString... RestOfConvertibleToStringTypes >
	EnsureRetrunValueIsUsed inline LargestUnsignedInteger CalculateSizeRequiredToStoreArgumentsAsString__Private( const FirstExposedConvertibleToStringType& firstArgumentToFormat, const SecondExposedConvertibleToStringType& secondArgumentToFormat, const RestOfConvertibleToStringTypes&... restOfArgumentsToFormat );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to calculate the number of characters required to store the formatted string. This overload is for the case
	//		that there is only one argument, or in case there were multiple arguments it will be used to finish the recursion
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			argumentToFormat - the argument to format and store in the resulting string
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The number of characters required to store the argument as string
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
	template< Concepts::ConvertibleToString ExposedConvertibleToStringType >
	EnsureRetrunValueIsUsed inline LargestUnsignedInteger CalculateSizeRequiredToStoreArgumentsAsString__Private( const ExposedConvertibleToStringType& argumentToFormat );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to calculate the number of characters required to store the given integer
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			integer - the integer to calculate the number of characters needed to store as string
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The number of characters required to store the integer
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
	template< Concepts::Integer IntegerType >
	EnsureRetrunValueIsUsed inline LargestUnsignedInteger CalculateSizeRequiredToStoreAsString__Private( const IntegerType integer );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to calculate the number of characters required to store the given floating point
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			floatingPoint - the floating point to calculate the number of characters needed to store as string
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The number of characters required to store the floating point
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
	template< Concepts::FloatingPoint FloatingPointType >
	EnsureRetrunValueIsUsed inline LargestUnsignedInteger CalculateSizeRequiredToStoreAsString__Private( const FloatingPointType floatingPoint );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to calculate the number of characters required to store the given pointer
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			pointer - the pointer to calculate the number of characters needed to store as string
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The number of characters required to store the pointer
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
	template< Concepts::Pointer PointerType >
	EnsureRetrunValueIsUsed inline LargestUnsignedInteger CalculateSizeRequiredToStoreAsString__Private( const PointerType pointer );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to calculate the number of characters required to store the given instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			instance - the instance to calculate the number of characters needed to store as string
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The number of characters required to store the instance
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
	template< Concepts::ConvertibleToStringObject ConvertibleToStringObjectType >
	EnsureRetrunValueIsUsed inline LargestUnsignedInteger CalculateSizeRequiredToStoreAsString__Private( const ConvertibleToStringObjectType& instance );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to calculate the number of characters required to store the given instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			A dummy variable to allow choosing this method in the correcto situation
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The value 1, as only 1 entry is needed to store a character
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
	template< typename CharacterType > requires ( Concepts::SameAs< CharacterType, Character > )
	EnsureRetrunValueIsUsed inline LargestUnsignedInteger CalculateSizeRequiredToStoreAsString__Private( const Character& );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to calculate the number of characters required to store the formatted string. This overload is for the case
	//		where there are multiple arguments to format. It will create a recursive calls to expose each time another argument and
	//		format it. The recursion will end when there is only one argument to format and then the overload for that case will be called
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. format - a constant reference to the format
	//			2. formatIndex - a refernce to the format index
	//			3. stringIndex - a reference to the string index
	//			4. firstArgumentToFormat - the first argument to format
	//			5. secondArgumentToFormat - the second argument to format
	//			6. restOfArgumentsToFormat - the rest of the arguments to format and store in the resulting string
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
	//		1. The format size is larger then 0
	//		2. The format contains amount of "{}" that is equal to the number of given arguments
	//		3. 
	//
	//  Possible errors :
	//
	//		NONE
	//
	template< Concepts::ConvertibleToString FirstExposedConvertibleToStringType, Concepts::ConvertibleToString SecondExposedConvertibleToStringType, Concepts::ConvertibleToString... RestOfConvertibleToStringTypes >
	inline void ConvertArgumentToStringAndStoreIt__Private( const SelfType& format, LargestUnsignedInteger& formatIndex, LargestUnsignedInteger& stringIndex, const FirstExposedConvertibleToStringType& firstArgumentToFormat, const SecondExposedConvertibleToStringType& secondArgumentToFormat, const RestOfConvertibleToStringTypes&... restOfArgumentsToFormat );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to calculate the number of characters required to store the formatted string. This overload is for the case
	//		that there is only one argument, or in case there were multiple arguments it will be used to finish the recursion
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			argumentToFormat - the argument to format and store in the resulting string
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
	//		NONE
	//
	template< Concepts::ConvertibleToString ExposedConvertibleToStringType >
	inline void ConvertArgumentToStringAndStoreIt__Private( const SelfType& format, LargestUnsignedInteger& formatIndex, LargestUnsignedInteger& stringIndex, const ExposedConvertibleToStringType& argumentToFormat );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to convert the given integer into a string and store it
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. destinationPoitner - a pointer with the memory address at which the integer needs to be stored as string
	//			2. integer - an integer to format and store as string
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
	//		NONE
	//
	template< Concepts::Integer IntegerType >
	inline LargestUnsignedInteger ConvertArgumentToStringAndStoreIt__Private( Character* const destinationPoitner, const IntegerType integer );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to convert the given floating point into a string and store it
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. destinationPoitner - a pointer with the memory address at which the integer needs to be stored as string
	//			2. floatingPoint - an floating point to format and store as string
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
	//		NONE
	//
	template< Concepts::FloatingPoint FloatingPointType >
	inline LargestUnsignedInteger ConvertArgumentToStringAndStoreIt__Private( Character* const destinationPoitner, const FloatingPointType floatingPoint );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to convert the given pointer into a string and store it
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. destinationPoitner - a pointer with the memory address at which the integer needs to be stored as string
	//			2. pointer - an pointer to format and store as string
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
	//		NONE
	//
	template< Concepts::Pointer PointerType >
	inline LargestUnsignedInteger ConvertArgumentToStringAndStoreIt__Private( Character* const destinationPoitner, const PointerType pointer );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to convert the given instance into a string and store it
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. destinationPoitner - a pointer with the memory address at which the integer needs to be stored as string
	//			2. instance - an instance to format and store as string
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
	//		NONE
	//
	template< Concepts::ConvertibleToStringObject ConvertibleToStringObjectType >
	inline LargestUnsignedInteger ConvertArgumentToStringAndStoreIt__Private( Character* const destinationPoitner, const ConvertibleToStringObjectType& instance );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to convert the given instance into a string and store it
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. destinationPoitner - a pointer with the memory address at which the integer needs to be stored as string
	//			2. character - a constant reference to a character to store in the format
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
	//		NONE
	//
	template< typename CharacterType > requires ( Concepts::SameAs< CharacterType, Character > )
	inline LargestUnsignedInteger ConvertArgumentToStringAndStoreIt__Private( Character* const destinationPoitner, const Character& character );



};  //  Class StringImplementation



// Create a type definition for the string object when using the main memory manager
using String = StringImplementation< Memory::MainMemoryManager >;


// Create a type definition for the string object when using the main memory manager
template< typename MemoryManagerType >
using StringWithSpecializedMemoryManager = StringImplementation< MemoryManagerType >;