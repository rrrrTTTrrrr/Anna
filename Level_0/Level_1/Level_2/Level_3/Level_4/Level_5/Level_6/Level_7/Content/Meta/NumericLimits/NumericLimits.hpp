namespace Universe
{



// Operator typeid :
//
// A C++ language operator which returns type identification information at run time. It basically returns an object type_info, which has a method
// called "name", to get a string containning an identifier of the data type. Here is the list of options for GCC :
//
//  char - c
//  unsigned char - h
//  short - s
//  unsigned short - t
//  int - i
//	unsigned int - j
//  long - l
//  unsigned long - m
//  long long - x
//  float - f
//  double - d
//  long double - e
//
// This objects type_info instances can be compared with each other and they must come out equal if the type inside match, and false if they don't.
// The instances themselves can be different in bit comparison, but the comparison will come out true if they represent the same type!



// In the C programming language, data types are declarations for memory locations or variables that determine the characteristics of the data that 
// may be stored and the methods ( operations ) of processing that are permitted involving them.
//
// The C language provides basic arithmetic types, such as integer and real number types, and syntax to build array and compound types. Several headers
// in the C standard library contain definitions of support types, that have additional properties, such as providing storage with an exact size,
// independent of the implementation



// Hexadecimal - In mathematics and computing, hexadecimal ( also base 16, or hex ) is a positional numeral system with a radix, or base, of 16. It 
// uses sixteen distinct symbols, most often the symbols 0 – 9 to represent values zero to nine, and A, B, C, D, E, F ( or alternatively a, b, c, 
// d, e, f ) to represent values ten to fifteen. Hexadecimal numerals are widely used by computer system designers and programmers. As each hexadecimal
// digit represents four binary digits ( bits ), it allows a more human-friendly representation of binary-coded values. One hexadecimal digit 
// represents a nibble ( 4 bits ), which is half of an octet or byte ( 8 bits )



// Class Information :
//
//  Purpose :
//
//		This object will contain all the limits for the various integers. This is the declaration of the object, and each integer type will
//		have a template specialization to indicate the maximum and minimum of the possible range
//
//  Description :
//
//		1. This object is used only to wrap some static methods, which can be used without any instance of the object. Then this object is
//		   an interface which conatins only static methods, and does not need to never be instantied
//
//		2. This object has all the methods to create, destory, copy and move disabled to ensure that no instances of it will be created
//
//		3. Template arguments :
//
//			1. NumericType - any numeric type
//
//  Possible errors :
//
//		Too many to count
//
template< Concepts::Numeric NumericType >
class NumericLimits
{
private:


	// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
	NoInstances( NumericLimits );


};  //  Class NumericLimits



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ***************************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION   *************************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



// Use this macro to create a template specialization of the object 'NumericLimits' for integer types. Each 'NumericLimits' object will 
// contain the following functionality :
//
//		1. Minimum - a method that will provide the minimum value for the numeric type
//		2. Maximum - a method that will provide the maximum value for the numeric type
//		3. MaximumNumberOfDigits - a method that will provide the maximum digits the numeric type can contain
//
// The required arguments are :
//
//      1. IntegerType - the numeric input type that will be used as the return value
//		3. MinimumValue - the minimum value for the numeric type
//		4. MaximumValue - the maximum value for the numeric type
//		5. MaximumNumberOfDigitsValue - the maximum digits the numeric type can contain
//
#define CreateNumericLimitsTemplateSpecializationForIntegers( IntegerType, MinimumValue, MaximumValue, MaximumNumberOfDigitsValue )																			\
																																																					\
																																																					\
	template<>																																																		\
	class NumericLimits< IntegerType >																																												\
	{																																																				\
	public:																																																			\
																																																					\
																																																					\
		static constexpr IntegerType Minimum = MinimumValue;																																						\
																																																					\
																																																					\
		static constexpr IntegerType Maximum = MaximumValue;																																						\
																																																					\
																																																					\
		static constexpr LargestUnsignedInteger MaximumNumberOfDigits = MaximumNumberOfDigitsValue;																													\
																																																					\
																																																					\
	private:																																																		\
																																																					\
																																																					\
		/* Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator */ 												\
		NoInstances( NumericLimits );																																											\
																																																					\
																																																					\
	}  //  Class NumericLimits



// Create all the required template specializations, the types are :
//
//      SignedInteger8bits
//      SignedInteger16bits
//      SignedInteger32bits
//      SignedInteger64bits
//      UnsignedInteger8bits
//      UnsignedInteger16bits
//      UnsignedInteger32bits
//      UnsignedInteger64bits
//		Boolean
//
CreateNumericLimitsTemplateSpecializationForIntegers( SignedInteger8bits, -128, 127, 3UL );
CreateNumericLimitsTemplateSpecializationForIntegers( SignedInteger16bits, -32768, 32767, 5UL );
CreateNumericLimitsTemplateSpecializationForIntegers( SignedInteger32bits, -2147483648, 2147483647, 10UL );
CreateNumericLimitsTemplateSpecializationForIntegers( SignedInteger64bits, -9223372036854775807, 9223372036854775807, 19UL );
CreateNumericLimitsTemplateSpecializationForIntegers( UnsignedInteger8bits, 0U, 255U, 3UL );
CreateNumericLimitsTemplateSpecializationForIntegers( UnsignedInteger16bits, 0U, 65535U, 5UL );
CreateNumericLimitsTemplateSpecializationForIntegers( UnsignedInteger32bits, 0U, 4294967295U, 10UL );
CreateNumericLimitsTemplateSpecializationForIntegers( UnsignedInteger64bits, 0UL, 18446744073709551615UL, 20UL );
CreateNumericLimitsTemplateSpecializationForIntegers( Boolean, false, true, 1UL );




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ***************************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION   *************************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //




// Use this macro to create a template specialization of the object 'NumericLimits' for floating point types. Each 'NumericLimits' object 
// will contain the following functionality :
//
//		1. Minimum - a method that will provide the minimum value for the numeric type
//		2. Maximum - a method that will provide the maximum value for the numeric type
//		3. MaximumPercision - a method that will provide the maximum percision the floating point can represent
//
// The required arguments are :
//
//      1. FloatingPointType - the numeric input type that will be used as the return value
//		3. MinimumValue - the minimum value for the numeric type
//		4. MaximumValue - the maximum value for the numeric type
//		5. MaximumPercisionValue - the maximum percision the floating point type can represent
//
#define CreateNumericLimitsTemplateSpecializationForFloatingPoints( FloatingPointType, MinimumValue, MaximumValue, MaximumPercisionValue )																	\
																																																					\
																																																					\
	template<>																																																		\
	class NumericLimits< FloatingPointType >																																										\
	{																																																				\
	public:																																																			\
																																																					\
																																																					\
		static constexpr FloatingPointType Minimum = MinimumValue;																																					\
																																																					\
																																																					\
		static constexpr FloatingPointType Maximum = MaximumValue;																																					\
																																																					\
																																																					\
		static constexpr FloatingPointType MaximumPercision = MaximumPercisionValue;																																\
																																																					\
																																																					\
	private:																																																		\
																																																					\
																																																					\
		/* Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator */ 												\
		NoInstances( NumericLimits );																																											\
																																																					\
																																																					\
	}  //  Class NumericLimits



// Create all the required template specializations, the types are :
//
//		FloatingPoint32bits
//		FloatingPoint64bits
//
CreateNumericLimitsTemplateSpecializationForFloatingPoints( FloatingPoint32bits, -3.40282e+38f, 3.40282e+38f, 1.17549e-38f );
CreateNumericLimitsTemplateSpecializationForFloatingPoints( FloatingPoint64bits, -1.79769e+308, 1.79769e+308, 2.22507e-308 );



}  //  Namespace Universe