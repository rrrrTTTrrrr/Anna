#ifndef NUMERICLIMITS_HPP
#define NUMERICLIMITS_HPP


#include "../../CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../Types/TypeCheck/Integers/TypeCheck_Integer/TypeCheck_Integer.hpp"  //  Class TypeCheck_Integer


// This additional headers are only needed in test mode
#ifdef TEST_MODE
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
	template< typename NumericType >
	class NumericLimits
	{
	private:


		// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
		NoInstances_MACRO( NumericLimits )


		// Assert all the requirements on the template arguments provided to the object. To perform a compile time assert the C++ language provides
		// the keyword 'static_assert', which receives an expression and an error message to display if the expression result is false. The important
		// thing is that the expression is evaluted during compile time, and therefore if the expression is false the compilation will be terminated
		// and the error message will be displayed. This method should not be used, because it does nothing during run time
		CompileTimeAssert( ( TypeCheck_Integer< NumericType >::Result() == true ), "NumericLimits failed - the given template type should be primitive" );


	};  //  Class NumericLimits





























// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - UnsignedInteger8bits   ************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































	// Class Information :
	//
	//  Purpose :
	//
	//		Artifical Inteligence
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
	//			1. Numeric type - any numeric type
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	template<>
	class NumericLimits< UnsignedInteger8bits >
	{
	public:


        // The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions
		// only have access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only
		// purpose then of declaring a static function is when a private static data member needs to be manipulated, or some functionality needed that
		// does not involve the non static data members


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the lowest value in the range
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
		//      The lowest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr UnsignedInteger8bits Minimum();


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest value in the range
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
		//      The highest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr UnsignedInteger8bits Maximum();


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest possible number of digits in this type of integer
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
		//      The highest possible number of digits in this type of integer
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr UnsignedInteger8bits MaximumNumberOfDigits();


	private:


		// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
		NoInstances_MACRO( NumericLimits )


	};  //  Class NumericLimits




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



































		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the lowest value in the range
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
		//      The lowest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr UnsignedInteger8bits NumericLimits< UnsignedInteger8bits >::Minimum()
		{
			// Return the minimum value for unsigned integer of 8 bits
			return ( 0 );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest value in the range
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
		//      The highest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr UnsignedInteger8bits NumericLimits< UnsignedInteger8bits >::Maximum()
		{
			// Return the maximum value for unsigned integer of 8 bits
			return ( 255U );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest possible number of digits in this type of integer
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
		//      The highest possible number of digits in this type of integer
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr UnsignedInteger8bits NumericLimits< UnsignedInteger8bits >::MaximumNumberOfDigits()
		{
			// Return the maximum value for unsigned integer of 8 bits
			return ( 3U );
		}




























// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - UnsignedInteger16bits   ************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































	// Class Information :
	//
	//  Purpose :
	//
	//		Artifical Inteligence
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
	//			1. Numeric type - any numeric type
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	template<>
	class NumericLimits< UnsignedInteger16bits >
	{
	public:


        // The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions
		// only have access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only
		// purpose then of declaring a static function is when a private static data member needs to be manipulated, or some functionality needed that
		// does not involve the non static data members


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the lowest value in the range
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
		//      The lowest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr UnsignedInteger16bits Minimum();


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest value in the range
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
		//      The highest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr UnsignedInteger16bits Maximum();


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest possible number of digits in this type of integer
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
		//      The highest possible number of digits in this type of integer
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr UnsignedInteger8bits MaximumNumberOfDigits();


	private:


		// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
		NoInstances_MACRO( NumericLimits )


	};  //  Class NumericLimits




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



































		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the lowest value in the range
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
		//      The lowest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr UnsignedInteger16bits NumericLimits< UnsignedInteger16bits >::Minimum()
		{
			// Return the minimum value for unsigned integer of 8 bits
			return ( 0 );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest value in the range
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
		//      The highest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr UnsignedInteger16bits NumericLimits< UnsignedInteger16bits >::Maximum()
		{
			// Return the maximum value for unsigned integer of 8 bits
			return ( 65535U );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest possible number of digits in this type of integer
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
		//      The highest possible number of digits in this type of integer
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr UnsignedInteger8bits NumericLimits< UnsignedInteger16bits >::MaximumNumberOfDigits()
		{
			// Return the maximum value for unsigned integer of 16 bits
			return ( 5U );
		}































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - UnsignedInteger32bits   ************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































	// Class Information :
	//
	//  Purpose :
	//
	//		Artifical Inteligence
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
	//			1. Numeric type - any numeric type
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	template<>
	class NumericLimits< UnsignedInteger32bits >
	{
	public:


        // The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions
		// only have access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only
		// purpose then of declaring a static function is when a private static data member needs to be manipulated, or some functionality needed that
		// does not involve the non static data members


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the lowest value in the range
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
		//      The lowest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr UnsignedInteger32bits Minimum();


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest value in the range
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
		//      The highest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr UnsignedInteger32bits Maximum();


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest possible number of digits in this type of integer
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
		//      The highest possible number of digits in this type of integer
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr UnsignedInteger8bits MaximumNumberOfDigits();


	private:


		// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
		NoInstances_MACRO( NumericLimits )


	};  //  Class NumericLimits




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



































		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the lowest value in the range
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
		//      The lowest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr UnsignedInteger32bits NumericLimits< UnsignedInteger32bits >::Minimum()
		{
			// Return the maximum value for unsigned integer of 8 bits
			return ( 0 );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest value in the range
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
		//      The highest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr UnsignedInteger32bits NumericLimits< UnsignedInteger32bits >::Maximum()
		{
			// Return the maximum value for unsigned integer of 8 bits
			return ( 4294967295U );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest possible number of digits in this type of integer
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
		//      The highest possible number of digits in this type of integer
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr UnsignedInteger8bits NumericLimits< UnsignedInteger32bits >::MaximumNumberOfDigits()
		{
			// Return the maximum value for unsigned integer of 32 bits
			return ( 10U );
		}





























// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - UnsignedInteger64bits   ************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































	// Class Information :
	//
	//  Purpose :
	//
	//		Artifical Inteligence
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
	//			1. Numeric type - any numeric type
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	template<>
	class NumericLimits< UnsignedInteger64bits >
	{
	public:


        // The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions
		// only have access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only
		// purpose then of declaring a static function is when a private static data member needs to be manipulated, or some functionality needed that
		// does not involve the non static data members


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the lowest value in the range
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
		//      The lowest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr UnsignedInteger64bits Minimum();


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest value in the range
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
		//      The highest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr UnsignedInteger64bits Maximum();


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest possible number of digits in this type of integer
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
		//      The highest possible number of digits in this type of integer
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr UnsignedInteger8bits MaximumNumberOfDigits();


	private:


		// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
		NoInstances_MACRO( NumericLimits )


	};  //  Class NumericLimits




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



































		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the lowest value in the range
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
		//      The lowest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr UnsignedInteger64bits NumericLimits< UnsignedInteger64bits >::Minimum()
		{
			// Return the minimum value for unsigned integer of 8 bits
			return ( 0 );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest value in the range
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
		//      The highest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr UnsignedInteger64bits NumericLimits< UnsignedInteger64bits >::Maximum()
		{
			// Return the maximum value for unsigned integer of 8 bits
			return ( 18446744073709551615U );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest possible number of digits in this type of integer
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
		//      The highest possible number of digits in this type of integer
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr UnsignedInteger8bits NumericLimits< UnsignedInteger64bits >::MaximumNumberOfDigits()
		{
			// Return the maximum value for unsigned integer of 64 bits
			return ( 20U );
		}





























// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - SignedInteger8bits   ************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































	// Class Information :
	//
	//  Purpose :
	//
	//		Artifical Inteligence
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
	//			1. Numeric type - any numeric type
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	template<>
	class NumericLimits< SignedInteger8bits >
	{
	public:


        // The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions
		// only have access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only
		// purpose then of declaring a static function is when a private static data member needs to be manipulated, or some functionality needed that
		// does not involve the non static data members


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the lowest value in the range
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
		//      The lowest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr SignedInteger8bits Minimum();


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest value in the range
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
		//      The highest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr SignedInteger8bits Maximum();


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest possible number of digits in this type of integer
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
		//      The highest possible number of digits in this type of integer
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr UnsignedInteger8bits MaximumNumberOfDigits();


	private:


		// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
		NoInstances_MACRO( NumericLimits )


	};  //  Class NumericLimits




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



































		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the lowest value in the range
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
		//      The lowest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr SignedInteger8bits NumericLimits< SignedInteger8bits >::Minimum()
		{
			// Return the minimum value for signed integer of 8 bits
			return ( -128 );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest value in the range
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
		//      The highest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr SignedInteger8bits NumericLimits< SignedInteger8bits >::Maximum()
		{
			// Return the maximum value for signed integer of 8 bits
			return ( 127 );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest possible number of digits in this type of integer
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
		//      The highest possible number of digits in this type of integer
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr UnsignedInteger8bits NumericLimits< SignedInteger8bits >::MaximumNumberOfDigits()
		{
			// Return the maximum value for signed integer of 8 bits
			return ( 3U );
		}





























// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - SignedInteger16bits   ************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































	// Class Information :
	//
	//  Purpose :
	//
	//		Artifical Inteligence
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
	//			1. Numeric type - any numeric type
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	template<>
	class NumericLimits< SignedInteger16bits >
	{
	public:


        // The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions
		// only have access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only
		// purpose then of declaring a static function is when a private static data member needs to be manipulated, or some functionality needed that
		// does not involve the non static data members


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the lowest value in the range
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
		//      The lowest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr SignedInteger16bits Minimum();


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest value in the range
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
		//      The highest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr SignedInteger16bits Maximum();


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest possible number of digits in this type of integer
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
		//      The highest possible number of digits in this type of integer
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr UnsignedInteger8bits MaximumNumberOfDigits();


	private:


		// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
		NoInstances_MACRO( NumericLimits )


	};  //  Class NumericLimits




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



































		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the lowest value in the range
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
		//      The lowest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr SignedInteger16bits NumericLimits< SignedInteger16bits >::Minimum()
		{
			// Return the minimum value for signed integer of 16 bits
			return ( -32768 );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest value in the range
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
		//      The highest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr SignedInteger16bits NumericLimits< SignedInteger16bits >::Maximum()
		{
			// Return the maximum value for signed integer of 16 bits
			return ( 32767 );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest possible number of digits in this type of integer
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
		//      The highest possible number of digits in this type of integer
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr UnsignedInteger8bits NumericLimits< SignedInteger16bits >::MaximumNumberOfDigits()
		{
			// Return the maximum value for unsigned integer of 16 bits
			return ( 5U );
		}





























// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - SignedInteger32bits   ************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































	// Class Information :
	//
	//  Purpose :
	//
	//		Artifical Inteligence
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
	//			1. Numeric type - any numeric type
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	template<>
	class NumericLimits< SignedInteger32bits >
	{
	public:


        // The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions
		// only have access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only
		// purpose then of declaring a static function is when a private static data member needs to be manipulated, or some functionality needed that
		// does not involve the non static data members


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the lowest value in the range
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
		//      The lowest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr SignedInteger32bits Minimum();


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest value in the range
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
		//      The highest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr SignedInteger32bits Maximum();


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest possible number of digits in this type of integer
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
		//      The highest possible number of digits in this type of integer
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr UnsignedInteger8bits MaximumNumberOfDigits();


	private:


		// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
		NoInstances_MACRO( NumericLimits )


	};  //  Class NumericLimits




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



































		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the lowest value in the range
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
		//      The lowest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr SignedInteger32bits NumericLimits< SignedInteger32bits >::Minimum()
		{
			// Return the minimum value for signed integer of 32 bits
			return ( -2147483648 );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest value in the range
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
		//      The highest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr SignedInteger32bits NumericLimits< SignedInteger32bits >::Maximum()
		{
			// Return the maximum value for signed integer of 32 bits
			return ( 2147483647 );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest possible number of digits in this type of integer
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
		//      The highest possible number of digits in this type of integer
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr UnsignedInteger8bits NumericLimits< SignedInteger32bits >::MaximumNumberOfDigits()
		{
			// Return the maximum value for unsigned integer of 32 bits
			return ( 10U );
		}





























// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - SignedInteger64bits   ************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































	// Class Information :
	//
	//  Purpose :
	//
	//		Artifical Inteligence
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
	//			1. Numeric type - any numeric type
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	template<>
	class NumericLimits< SignedInteger64bits >
	{
	public:


        // The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions
		// only have access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only
		// purpose then of declaring a static function is when a private static data member needs to be manipulated, or some functionality needed that
		// does not involve the non static data members


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the lowest value in the range
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
		//      The lowest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr SignedInteger64bits Minimum();


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest value in the range
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
		//      The highest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr SignedInteger64bits Maximum();


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest possible number of digits in this type of integer
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
		//      The highest possible number of digits in this type of integer
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr UnsignedInteger8bits MaximumNumberOfDigits();


	private:


		// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
		NoInstances_MACRO( NumericLimits )


	};  //  Class NumericLimits




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



































		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the lowest value in the range
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
		//      The lowest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr SignedInteger64bits NumericLimits< SignedInteger64bits >::Minimum()
		{
			// Return the minimum value for signed integer of 64 bits
			return ( -9223372036854775807 );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest value in the range
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
		//      The highest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr SignedInteger64bits NumericLimits< SignedInteger64bits >::Maximum()
		{
			// Return the maximum value for signed integer of 64 bits
			return ( 9223372036854775807 );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest possible number of digits in this type of integer
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
		//      The highest possible number of digits in this type of integer
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr UnsignedInteger8bits NumericLimits< SignedInteger64bits >::MaximumNumberOfDigits()
		{
			// Return the maximum value for unsigned integer of 64 bits
			return ( 19U );
		}





























// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ***********************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Boolean   ********************************************************* //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































	// Class Information :
	//
	//  Purpose :
	//
	//		Artifical Inteligence
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
	//			1. Numeric type - any numeric type
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	template<>
	class NumericLimits< Boolean >
	{
	public:


        // The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions
		// only have access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only
		// purpose then of declaring a static function is when a private static data member needs to be manipulated, or some functionality needed that
		// does not involve the non static data members


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the lowest value in the range
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
		//      The lowest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr Boolean Minimum();


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest value in the range
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
		//      The highest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr Boolean Maximum();


	private:


		// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
		NoInstances_MACRO( NumericLimits )


	};  //  Class NumericLimits




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



































		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the lowest value in the range
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
		//      The lowest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr Boolean NumericLimits< Boolean >::Minimum()
		{
			// Return the minimum value for unsigned integer of 8 bits
			return ( false );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest value in the range
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
		//      The highest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr Boolean NumericLimits< Boolean >::Maximum()
		{
			// Return the maximum value for unsigned integer of 8 bits
			return ( true );
		}






































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - FloatingPoint   ************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //

































	// Class Information :
	//
	//  Purpose :
	//
	//		Artifical Inteligence
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
	//			1. Numeric type - any numeric type
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	template<>
	class NumericLimits< FloatingPoint >
	{
	public:


        // The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions
		// only have access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only
		// purpose then of declaring a static function is when a private static data member needs to be manipulated, or some functionality needed that
		// does not involve the non static data members


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the lowest value in the range
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
		//      The lowest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr FloatingPoint Minimum();


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest value in the range
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
		//      The highest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr FloatingPoint Maximum();


	private:


		// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
		NoInstances_MACRO( NumericLimits )


	};  //  Class NumericLimits




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



































		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the lowest value in the range
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
		//      The lowest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr FloatingPoint NumericLimits< FloatingPoint >::Minimum()
		{
			// Return the minimum value for floating point
			return ( 1.17549e-38 );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest value in the range
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
		//      The highest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr FloatingPoint NumericLimits< FloatingPoint >::Maximum()
		{
			// Return the maximum value for floating point
			return ( 3.40282e+38 );
		}































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - DoublePrecisionFloatingPoint   ************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































	// Class Information :
	//
	//  Purpose :
	//
	//		Artifical Inteligence
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
	//			1. Numeric type - any numeric type
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	template<>
	class NumericLimits< DoublePrecisionFloatingPoint >
	{
	public:


        // The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions
		// only have access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only
		// purpose then of declaring a static function is when a private static data member needs to be manipulated, or some functionality needed that
		// does not involve the non static data members


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the lowest value in the range
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
		//      The lowest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr DoublePrecisionFloatingPoint Minimum();


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest value in the range
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
		//      The highest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static constexpr DoublePrecisionFloatingPoint Maximum();


	private:


		// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
		NoInstances_MACRO( NumericLimits )


	};  //  Class NumericLimits




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



































		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the lowest value in the range
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
		//      The lowest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr DoublePrecisionFloatingPoint NumericLimits< DoublePrecisionFloatingPoint >::Minimum()
		{
			// Return the minimum value for double precision floating point
			return ( 2.22507e-308 );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the highest value in the range
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
		//      The highest value in the range
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		constexpr DoublePrecisionFloatingPoint NumericLimits< DoublePrecisionFloatingPoint >::Maximum()
		{
			// Return the maximum value for double precision floating point
			return ( 1.79769e+308 );
		}






}  //  Namespace Universe


#endif  // NUMERICLIMITS_HPP