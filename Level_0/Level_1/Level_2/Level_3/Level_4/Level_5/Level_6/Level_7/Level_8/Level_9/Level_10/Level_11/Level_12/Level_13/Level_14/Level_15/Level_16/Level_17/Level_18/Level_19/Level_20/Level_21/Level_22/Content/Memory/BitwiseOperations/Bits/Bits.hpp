namespace Universe
{


namespace Memory
{



// Using the comparison operator "==" to compare a signed integer 8 bits with an hexadecimal value :
//
// For example :
//
// 		char byte = 0x80;
//
//		if ( byte == 0x80 )
//		{
//			// This code will never be reached if 'char' is implemented as signed integer 8 bits
//		}
//
// The problem is that 'char' is, in the C/C++ standards, defined that it can be either a signed or an unsigned value, and tha a 'char'
// must have at least 8 bits. If 'char' is implemented as signed, this means that any value with the most significant bit will be a
// negative value. So 0x80 as a 'char' becomes -128 decimal.
//
// The constant '0x80' is not a 'char' value, it is an 'int' value. So when comparing -128 with 0x80 which is 128 in int they are not the
// same. There are a variety of ways to achieve this, the most simple is casting one into the other type, for example :
//
//		if ( byte == sataic_cast< char >( 0x80 ) )
//		{
//		}
//
// The second is writing the hexadecimal value so that the compiler will know it is a 'char' :
//
//		'\x80'



// A type conversion can :
//
//	1. Keep the conceptual value
//	2. Keep the bitpattern
//
// The only C++ cast guaranteeed always to keep the bitpattern is 'const_cast'. A 'reinterpret_cast' is, as its name suggests, intended
// to keep the bitpattern and simply reinterpret it. But the standard allows an implementation very much leeway in how to implement it.
// In some cases a 'reinterpret_cast' may change the bitpattern. A 'dynamic_cast' generally changes both bitpattern and value, since it
// generally delves into an object and returns a pointer/reference to a sub-object or requested type. A 'static_cast' may change the
// bitpattern both for integers and pointers, but, nearly all extant computeres use a representation of signed integers ( called two's 
// complement ) where 'static_cast' will not change the bitpattern. Regarding pointers, suffice to say that, for example, whan a base
// class is non polymorphic and a derived class is polymorphic, using 'static_cast' to go from pointer to derived to pointer to base, 
// or vice versa, may change the bitpattern. Now integers, with n value bits, an unsigned integer type has 2 to the power of n values,
// in the range [0, 2^n-1]. The C++ standard guarantees that any result of the type is wrapped into that range by adding or subtracting
// a suitable multiple of 2 to power of n. Actually that's how the C standard describes it, the C++ standard just says that operations 
// are modulo 2 to the power of n, which means the same. With two's complement form a signed value '-x' has the same bitpattern as the 
// unsgiend value 'x+2^n'. That is, the same bitpattern as the C++ standard guarantees that you get by converting '-x' to unsigned type
// of the same size



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
class Bits NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = Bits;


	// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object.
	// Satic functions only have access to static data members, which also don't belong to any instance, this means all other data members
	// can not be used. The only purpose then of declaring a static function is when a private static data member needs to be manipulated,
	// or some functionality needed that does not involve the non static data members


    // Method Information :
    //
    //  Description :
    //  
    //      Use to get the an integer with all the most significant bits on from the given index and above. for example :
    //
    //           index = 3		-> 	  	11111000
    //
    //		Note - in case there is more than one byte the endianess of the system matters :
    //
    //           index = 11 on little endian		->		00000000 11111000
    //
    //           index = 11 on big endian			->		11111000 00000000   
    //
    //  Required arguments :
    //
    //      User information needed :
    //      
    //          bitIndex - this will be used to determine the first bit to set on
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      An integer with all the most significant bits on from the given index and above
    //
	//  Expectations :
	//
	//		1. The given template type should be an integer
	//		2. The given bit index should be in the possible range of the integer type [0, number_of_bits - 1]
	//		3.
	//
    //  Possible errors :
    //
    //      They will come
    //
    template< Concepts::Integer IntegerType >
    EnsureRetrunValueIsUsed static inline IntegerType GetIntegerWithAllMostSignificantBitsOnFromIndexAndAbove( const UnsignedInteger64bits bitIndex );


    // Method Information :
    //
    //  Description :
    //  
    //      Use to get the an integer with all the most significant bits on above the index. for example :
    //
    //           index = 3		-> 	  	11110000
    //
    //		Note - in case there is more than one byte the endianess of the system matters :
    //
    //           index = 11 on little endian		->		00000000 11110000
    //
    //           index = 11 on big endian			->		11110000 00000000
    //
    //  Required arguments :
    //
    //      User information needed :
    //      
    //          bitIndex - this will be used to determine the bit that after it will be the first bit to set on
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      An integer with all the most significant bits on above the index
    //
	//  Expectations :
	//
	//		1. The given template type should be an integer
	//		2. The given bit index should be in the possible range of the integer type [0, number_of_bits - 1]
	//		3.
	//
    //  Possible errors :
    //
    //      They will come
    //
    template< Concepts::Integer IntegerType >
    EnsureRetrunValueIsUsed static inline IntegerType GetIntegerWithAllMostSignificantBitsOnAboveIndex( const UnsignedInteger64bits bitIndex );


    // Method Information :
    //
    //  Description :
    //  
    //      Use to get the an integer with all the most significant bits off from the given index and above. for example :
    //
    //           index = 3		-> 	  	00000111
    //
    //		Note - in case there is more than one byte the endianess of the system matters :
    //
    //           index = 11 on little endian		->		11111111 00000111
    //
    //           index = 11 on big endian			->		00000111 11111111
    //
    //  Required arguments :
    //
    //      User information needed :
    //      
    //          bitIndex - this will be used to determine the first bit to set off
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      An integer with all the most significant bits off from the given index and above
    //
	//  Expectations :
	//
	//		1. The given template type should be an integer
	//		2. The given bit index should be in the possible range of the integer type [0, number_of_bits - 1]
	//		3.
	//
    //  Possible errors :
    //
    //      They will come
    //
    template< Concepts::Integer IntegerType >
    EnsureRetrunValueIsUsed static inline IntegerType GetIntegerWithAllMostSignificantBitsOffFromIndexAndAbove( const UnsignedInteger64bits bitIndex );


    // Method Information :
    //
    //  Description :
    //  
    //      Use to get the an integer with all the most significant bits off above the index. for example :
    //
    //           index = 3		-> 	  	00001111
    //
    //		Note - in case there is more than one byte the endianess of the system matters :
    //
    //           index = 11 on little endian		->		11111111 00001111
    //
    //           index = 11 on big endian			->		00001111 11111111
    //
    //  Required arguments :
    //
    //      User information needed :
    //      
    //          bitIndex - this will be used to determine the bit that after it will be the first bit to set off
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      An integer with all the most significant bits off above the index
    //
	//  Expectations :
	//
	//		1. The given template type should be an integer
	//		2. The given bit index should be in the possible range of the integer type [0, number_of_bits - 1]
	//		3.
	//
    //  Possible errors :
    //
    //      They will come
    //
    template< Concepts::Integer IntegerType >
    EnsureRetrunValueIsUsed static inline IntegerType GetIntegerWithAllMostSignificantBitsOffAboveIndex( const UnsignedInteger64bits bitIndex );


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
	NoInstances( Bits );


	// Static data members do not belong to any instance, they belong to the object. Like every global variable it is created with the
	// start of the program and only destroyed when the program ends. The access to the static member is bound to this object of course


	// This array will act as a look up table. It will store the apperance of each byte according to the given index. This array is for
	// bytes that all the bits from the index and above, meaning the more significant bits, needs to be on
	static constexpr UnsignedInteger8bits member_lookupTable_convertIndexToByteWithAllBitsFromTheIndexAndAboveOn[8] = { 0xFF, 0xFE, 0xFC, 0xF8, 0xF0, 0xE0, 0xC0, 0x80 };

	// This array will act as a look up table. It will store the apperance of each byte according to the given index. This array is for
	// bytes that all the bits from the index and above, meaning the more significant bits, needs to be off
	static constexpr UnsignedInteger8bits member_lookupTable_convertIndexToByteWithAllBitsFromTheIndexAndAboveOff[8] = { 0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F };


};  //  Class Bits