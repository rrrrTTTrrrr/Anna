namespace Universe
{



// Hexadecimal : 
//
// In mathematics and computing, hexadecimal ( also base 16, or hex ) is a positional numeral system with a radix, or base, of 16.
// It uses sixteen distinct symbols, most often the symbols 0 – 9 to represent values zero to nine, and A, B, C, D, E, F ( or alternatively a, 
// b, c, d, e, f ) to represent values ten to fifteen. Hexadecimal numerals are widely used by computer system designers and programmers. As 
// each hexadecimal digit represents four binary digits ( bits ), it allows a more human-friendly representation of binary-coded values. One 
// hexadecimal digit represents a nibble ( 4 bits ), which is half of an octet or byte ( 8 bits )



// In the C programming language, data types are declarations for memory locations or variables that determine the characteristics of the data 
// that may be stored and the methods ( operations ) of processing that are permitted involving them.
//
// The C language provides basic arithmetic types, such as integer and real number types, and syntax to build array and compound types. Several
// headers in the C standard library contain definitions of support types, that have additional properties, such as providing storage with an 
// exact size, independent of the implementation



// When a templated static function inside a class needs a template specialization, it is does not require an additional declaration, only an
// implementation. For example :
//
//
//		Class Foo
//		{
//			template< typename Type >
//			static void Func( Type var );
//		};
//
//		template< typename Type >
//		void Foo::Func( Type var )
//		{
//			...
//		}
//
//
//		template<>
//		void Foo::Func( int var )
//		{
//			...
//		}



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
class ConvertBetweenNumericSystems NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = ConvertBetweenNumericSystems;


	// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object.
	// Satic functions only have access to static data members, which also don't belong to any instance, this means all other data members
	// can not be used. The only purpose then of declaring a static function is when a private static data member needs to be manipulated,
	// or some functionality needed that does not involve the non static data members


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to convert between hexadecimal representation to binary representation
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          1. hexadecimal - a constant reference to a sequential data structure instance that contains the hexadecimal characters
	//			2. memoryHandlerName - the enumeration of the memory handler to use
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      The binary representation of the hexadecimal
	//
	//  Expectations :
	//
	//		1. The sequential data structure instance size should not be zero
	//		2. The sequential data structure instance should contain valid hexadecimal characters
    //		3. The given template type should be integer type
    //		4. 
	//
	//  Possible errors :
	//
	//      They will come
	//
    template< Concepts::Integer IntegerReturnType >
    EnsureRetrunValueIsUsed static inline IntegerReturnType HexadecimalToBinary( const Language::String& hexadecimal );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to convert between binary representation to hexadecimal representation
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          1. binary - the binary representation of the number
	//			2. memoryHandlerName - the enumeration of the memory handler to use
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      A sequential data structure instance that contains the hexadecimal representation
	//
	//  Expectations :
	//
    //		1. The given template type should be integer type
    //		2. 
	//
	//  Possible errors :
	//
    //      1. There is no more free memory space - class std::bad_alloc is thrown
    //      2. 
	//
    template< Concepts::Integer IntegerType >
    EnsureRetrunValueIsUsed static inline Language::String BinaryToHexadecimal( const IntegerType binary, const MemoryHandlerName memoryHandlerName = MemoryHandlerName::Vector );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to convert between decimal representation to binary representation
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          decimal - a constant reference to a sequential data structure instance that contains the decimal digits
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      The binary representation of the decimal
	//
	//  Expectations :
	//
	//		1. The sequential data structure instance size should not be zero
	//		2. The sequential data structure instance should contain valid decimal digits
    //		3. The given template type should be integer type
    //		4. 
	//
	//  Possible errors :
	//
	//      They will come
	//
    template< Concepts::Integer IntegerReturnType >
    EnsureRetrunValueIsUsed static inline IntegerReturnType DecimalToBinary( const Language::String& decimal );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to convert between hexadecimal representation to decimal representation
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          1. hexadecimal - a constant reference to a sequential data structure instance that contains the hexadecimal characters
	//			2. memoryHandlerName - the enumeration of the memory handler to use
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      A sequential data structure instance that contains the decimal representation
	//
	//  Expectations :
	//
	//		1. The sequential data structure instance size should not be zero
	//		2. The sequential data structure instance should contain valid hexadecimal characters
    //		3. The given template type should be integer type
    //		4. 
	//
	//  Possible errors :
	//
    //      1. There is no more free memory space - class std::bad_alloc is thrown
    //      2. 
	//
	template< Concepts::Integer IntegerType >
    EnsureRetrunValueIsUsed static inline Language::String HexadecimalToDecimal( const Language::String& hexadecimal, const MemoryHandlerName memoryHandlerName = MemoryHandlerName::Vector );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to convert between decimal representation to hexadecimal representation
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          1. hexadecimal - a constant reference to a sequential data structure instance that contains the decimal digits
	//			2. memoryHandlerName - the enumeration of the memory handler to use
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      A sequential data structure instance that contains the decimal representation
	//
	//  Expectations :
	//
	//		1. The sequential data structure instance size should not be zero
	//		2. The sequential data structure instance should contain valid decimal digits
    //		3. The given template type should be integer type
    //		4. 
	//
	//  Possible errors :
	//
    //      1. There is no more free memory space - class std::bad_alloc is thrown
    //      2. 
	//
	template< Concepts::Integer IntegerType >
    EnsureRetrunValueIsUsed static inline Language::String DecimalToHexadecimal( const Language::String& decimal, const MemoryHandlerName memoryHandlerName = MemoryHandlerName::Vector );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to convert between binary coded decimal to binary
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          binaryCodedDecimal - an unsigned integer that contains binary coded decimal ( BCD ), in this format each of the two hex nibbles of each byte is
	//								 modified to display a decimal number. For example the value 59 will be stored as 0x59
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      An unsigned integer with the binary decimal value of the binrary coded decimal
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
    //		NONE
	//
	template< Concepts::UnsignedInteger UnsignedIntegerType >
	EnsureRetrunValueIsUsed static inline UnsignedIntegerType BinaryCodedDecimalToBinary( const UnsignedIntegerType binaryCodedDecimal );


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
	NoInstances( ConvertBetweenNumericSystems );


};  //  Class ConvertBetweenNumericSystems	