#ifndef DIGITS_HPP
#define DIGITS_HPP


#include "../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../../../../../../../Content/Metaprogramming/CommonFunctionality/SubstitutionFailureIsNotAnError/ProvideTypeOnlyIfAssertionIsTrue/ProvideTypeOnlyIfAssertionIsTrue.hpp"  //  Class ProvideTypeOnlyIfAssertionIsTrue
#include "../../../../../../../../Content/Metaprogramming/Types/TypeCheck/Integers/TypeCheck_Integer/TypeCheck_Integer.hpp"  //  Class TypeCheck_Integer
#include "../../../../../../../../Content/Metaprogramming/Types/TypeCheck/FloatingPoint/TypeCheck_FloatingPoint/TypeCheck_FloatingPoint.hpp"  //  Class TypeCheck_FloatingPoint
#include "../../../../../../../../Content/Metaprogramming/Types/CompareTypes/CompareTypes.hpp"  // Class CompareTypes
#include "../../../../../Content/BuiltInTypesWrapper/Bit/Bit.hpp"  //  Class Bit
#include "../Language/Ascii/HeapAsciiString/HeapAsciiString.hpp"  //  Class HeapAsciiString


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../Display/Display.hpp"
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



    // In the C programming language, data types are declarations for memory locations or variables that determine the characteristics of the data 
    // that may be stored and the methods ( operations ) of processing that are permitted involving them.
    //
    // The C language provides basic arithmetic types, such as integer and real number types, and syntax to build array and compound types. Several
    // headers in the C standard library contain definitions of support types, that have additional properties, such as providing storage with an 
    // exact size, independent of the implementation



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
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	class Digits
	{
	public:


		// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions
		// only have access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only
		// purpose then of declaring a static function is when a private static data member needs to be manipulated, or some functionality needed that
		// does not involve the non static data members


	    // Template method Information :
	    //
	    //  Description :
	    //
	    //      Use to get the number of digits of an integer
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
	    //          number - the number to calculate the number of digits for
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //      The number of digits
	    //
		//  Expectations :
		//
		//		NONE
		//
	    //  Possible errors :
	    //
	    //      They will come
	    //
	    template< typename NumericType >
	    static inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_Integer< NumericType >::Result(), UnsignedInteger64bits >::Type NumberOfDigits( NumericType number );


	    // Template method Information :
	    //
	    //  Description :
	    //
	    //      Use to get the number of digits of a floating point
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
	    //          floatingPoint - the floating point to calculate the number of digits for
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //      The number of digits
	    //
		//  Expectations :
		//
		//		NONE
		//
	    //  Possible errors :
	    //
	    //      They will come
	    //
	    template< typename NumericType >
	    static inline typename ProvideTypeOnlyIfAssertionIsTrue< CompareTypes< FloatingPoint, NumericType >::Result() == true, UnsignedInteger64bits >::Type NumberOfDigits( NumericType floatingPoint );


        // Template Function Information :
	    //
	    //  Description :
	    //
	    //      Transform an array containing only the ascii values for digits into a number
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
	    //          asciiString - a constant refernce to an ascii string implementation type instance
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //      An integer 
	    //
		//  Expectations :
		//
		//		1. The given ascii string should be ready
		//		2. The given ascii string size should be larger then 0
		//		3. The given ascii string should contain only ascii values that represents digits - [48,57]
		//		4. 
		//
	    //  Possible errors :
	    //
	    //		NONE
	    //
	    template< typename NumericType, typename AsciiStringImplementationType >
	    static inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_Integer< NumericType >::Result(), NumericType >::Type AsciiStringOfDigitsToInteger( const AsciiStringImplementationType& asciiString );


	    // Template method Information :
	    //
	    //  Description :
	    //
	    //      Transform an integer into an ascii string containing the digits of the integer
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
	    //          integer - the integer that should be stored as an ascii string
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //      A copy of the ascii string with the integer digits
	    //
		//  Expectations :
		//
		//		NONE
		//
	    //  Possible errors :
	    //
	    //      1. There is no more free space - class std::bad_alloc is thrown
	    //      2.
	    //
	    template< typename NumericType >
	    static inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_Integer< NumericType >::Result(), Language::HeapAsciiString >::Type IntegerToArrayOfDigits( NumericType integer );


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
			static void Test() __attribute__ (( __unused__ ));

		)  //  End of debug tool


	private:


		// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
		NoInstances_MACRO( Digits )


	};  //  Class Digits




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



































    // Template method Information :
    //
    //  Description :
    //
    //      Use to get the number of digits of an integer
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          integer - the integer to calculate the number of digits for
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      The number of digits
    //
	//  Expectations :
	//
	//		NONE
	//
    //  Possible errors :
    //
    //      They will come
    //
    template< typename NumericType >
    inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_Integer< NumericType >::Result(), UnsignedInteger64bits >::Type Digits::NumberOfDigits( NumericType integer ) 
    {
        // Space for the number of digits
        UnsignedInteger64bits numberOfDigits = 0UL;

        // Loop as long as the number is not 0
        while ( integer != 0 )
        {
            // Divide the integer by 10 to strip the first digit
            integer /= 10;

            // Increase the number of digits by 1
            numberOfDigits += 1UL;
        }

        // Return the number of digits in the integer
        return ( numberOfDigits );
    }


    // Template method Information :
    //
    //  Description :
    //
    //      Transform an ascii string containing only the ascii values for digits into a number
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          asciiString - a constant refernce to an ascii string implementation type instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      An integer 
    //
	//  Expectations :
	//
	//		1. The given ascii string should be ready
	//		2. The given ascii string size should be larger then 0
	//		3. The given ascii string should contain only ascii values that represents digits - [48,57]
	//		4. 
	//
    //  Possible errors :
    //
    //		NONE
    //
    template< typename NumericType, typename AsciiStringImplementationType >
    inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_Integer< NumericType >::Result(), NumericType >::Type Digits::AsciiStringOfDigitsToInteger( const AsciiStringImplementationType& asciiString )
    {
        // Space to contain the integer
        NumericType integer = 0;

        // This object will be used to pass on the ascii string of digits
        UnsignedInteger64bits asciiStringIndex = 0UL;

        // Check if the first entry contains the ascii value for the sign +/-
        if ( asciiString[ asciiStringIndex ] == '+' || asciiString[ asciiStringIndex ] == '-' )
        {
        	// The first entry contains the +/- sign

        	// Increment the ascii string index by 1
        	asciiStringIndex += 1UL;
        }

        // Loop until the ascii string is exhausted
        while ( asciiStringIndex < asciiString.Size() )
        {
            // Every character in order to turn into decimal number needs to by multiplied by 10 in the power of his distance from the last element.
            // And every character needs to be subtracted by 48 to get its real value and not ascii value
            integer = integer * 10 + ( asciiString[ asciiStringIndex ] - '0' );

            // Increment the ascii string index by 1
            asciiStringIndex += 1UL;
        }

        // Check if the first entry contains the ascii value for '-'
        if ( asciiString[ asciiStringIndex ] == '-' )
        {
        	// The first entry contains the '-' sign

        	// Multiply the integer by -1
        	integer *= -1; 
        }

        // Return the integer 
        return ( integer );
    }


    // Template method Information :
    //
    //  Description :
    //
    //      Transform an integer into an ascii string containing the digits of the integer
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          integer - the integer that should be stored as an ascii string
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      A copy of the ascii string with the integer digits
    //
	//  Expectations :
	//
	//		NONE
	//
    //  Possible errors :
    //
    //      1. There is no more free space - class std::bad_alloc is thrown
    //      2.
    //
    template< typename NumericType >
    inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_Integer< NumericType >::Result(), Language::HeapAsciiString >::Type Digits::IntegerToArrayOfDigits( NumericType integer )
    {
        // Calculate the number of digits in the integer
        UnsignedInteger64bits numberOfDigitsInInteger = NumberOfDigits( integer );

        // This object will store the ascii string representation of the integer
        Language::HeapAsciiString digitsOfInteger;

        // Space for index to run on ascii string
        UnsignedInteger64bits asciiStringIndex = ( numberOfDigitsInInteger - 1 );

        // Check if the integer is negative
        if ( integer < 0 )
        {
        	// The integer is negative

        	// Increment the number of digits by 1, to allocate another entry in the ascii string for the '-' sign
        	digitsOfInteger.Initiate( numberOfDigitsInInteger + 1UL );

        	// Set the first entry of the ascii string with the sign '-'
        	digitsOfInteger[0] = '-';

        	// Set the index
        	asciiStringIndex = numberOfDigitsInInteger;

        	// Set the integer from negative to positive
        	integer *= -1;
        }
        else
        {
        	// The integer is positive

	        // Allocate space to contain the ascii string
        	digitsOfInteger.Initiate( numberOfDigitsInInteger );
        }

        // Loop on all the digits of the integer
        while ( integer != 0 )
        {
            // Set the string with the current digit by adding '0' to make it the ascii value
            digitsOfInteger[ asciiStringIndex ] = ( ( integer % 10 ) + '0' );

            // Divide the integer by 10, to remove the currently added digit, and expose the next digit
            integer /= 10;

            // Decrement the string index by 1
            asciiStringIndex -= 1UL;
        }

        // Return the integer as an ascii string
        return ( MOVE( digitsOfInteger ) );
    }


    // Template method Information :
    //
    //  Description :
    //
    //      Transform an ascii string containing only the ascii values for digits into a floating point
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          asciiString - a constant refernce to an ascii string implementation type instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      An integer 
    //
	//  Expectations :
	//
	//		1. The given ascii string should be ready
	//		2. The given ascii string size should be larger then 0
	//		3. The given ascii string should contain only ascii values that represents digits - [48,57], and a decimal point
	//		4. 
	//
    //  Possible errors :
    //
    //		NONE
    //
    template< typename NumericType, typename AsciiStringImplementationType >
    inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_Integer< NumericType >::Result(), NumericType >::Type Digits::AsciiStringOfDigitsToInteger( const AsciiStringImplementationType& asciiString )
    {
    	
    }


    // Template method Information :
    //
    //  Description :
    //
    //      Transform an integer into an ascii string containing the digits of the integer
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          integer - the integer that should be stored as an ascii string
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      A copy of the ascii string with the integer digits
    //
	//  Expectations :
	//
	//		NONE
	//
    //  Possible errors :
    //
    //      1. There is no more free space - class std::bad_alloc is thrown
    //      2.
    //
    template< typename NumericType >
    inline typename ProvideTypeOnlyIfAssertionIsTrue< CompareTypes< FloatingPoint, NumericType >::Result() == true, Language::HeapAsciiString >::Type Digits::IntegerToArrayOfDigits( NumericType floatingPoint )
    {
        // Allocate space to contain the ascii string
        Language::HeapAsciiString digitsOfInteger( 1 );

        // Space for index to run on ascii string
        UnsignedInteger64bits asciiStringIndex = ( numberOfDigitsInInteger - 1 );

        // Loop on all the digits of the integer
        while ( integer != 0 )
        {
            // Set the string with the current digit by adding '0' to make it the ascii value
            digitsOfInteger[ asciiStringIndex ] = ( ( integer % 10 ) + '0' );

            // Decrement the string index by 1
            asciiStringIndex -= 1UL;
        }

        // Return the integer as an ascii string
        return ( MOVE( digitsOfInteger ) );
    }


































//	**********************************************************   TEMPLATE OR INLINE PROTECTED METHODS IMPLEMENTATION   **********************************************************




































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************





































}  //  Namespace Universe


#endif  // DIGITS_HPP