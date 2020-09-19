#ifndef ASCIISTRINGSANDINTEGERS_HPP
#define ASCIISTRINGSANDINTEGERS_HPP


#include "../CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../Metaprogramming/CommonFunctionality/SubstitutionFailureIsNotAnError/ProvideTypeOnlyIfAssertionIsTrue/ProvideTypeOnlyIfAssertionIsTrue.hpp"  //  Class ProvideTypeOnlyIfAssertionIsTrue
#include "../Metaprogramming/Types/TypeCheck/Integers/TypeCheck_Integer/TypeCheck_Integer.hpp"  //  Class TypeCheck_Integer
#include "../Metaprogramming/Types/TypeCheck/Integers/TypeCheck_UnsignedInteger/TypeCheck_UnsignedInteger.hpp"  //  Class TypeCheck_UnsignedInteger
#include "../Metaprogramming/Types/TypeCheck/Integers/TypeCheck_SignedInteger/TypeCheck_SignedInteger.hpp"  //  Class TypeCheck_SignedInteger
#include "../Metaprogramming/NumericLimits/NumericLimits.hpp"  //  Class NumericLimits


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



    // In the C programming language, data types are declarations for memory locations or variables that determine the characteristics of the data that 
    // may be stored and the methods ( operations ) of processing that are permitted involving them.
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
	class AsciiStringAndIntegers
	{
	public:


		// Create a type definition for the object itself
		using ObjectType = AsciiStringAndIntegers;


		// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions
		// only have access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only
		// purpose then of declaring a static function is when a private static data member needs to be manipulated, or some functionality needed that
		// does not involve the non static data members


	    // Method Information :
	    //
	    //  Description :
	    //
	    //      Use this method to find the size of an ascii string
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
		//			asciiString - a pointer to the memory address of the ascii string
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //		The size of the ascii string. If the given pointer is NULL or the size of the string is larger then 1 million characters it will 
	    //		return 0
	    //
	    //  Expectations :
	    //
	    //      1. The given pointer is not NULL	
	    //		2. The string ends with a null terminator ( 0 )
	    //		3.
	    //
	    //  Possible errors :
	    //
	    //      They will come
	    //
		static UnsignedInteger64bits AsciiStringSize( const char* asciiString );


	    // Method Information :
	    //
	    //  Description :
	    //
	    //      Use this method to copy the content of an ascii string to the required destination
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
		//			1. sourceAsciiString - a pointer to the memory address of the ascii string to copy
		//			2. destinationAsciiString - a pointer to the memory address to copy the ascii string to
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //      A boolean with the value true if the method was successful and false otherwise
	    //
	    //  Expectations :
	    //
	    //      1. The given source pointer is not NULL
	    //      2. The given destination pointer is not NULL
	    //		3. The source ascii string ends with a null terminator ( 0 )
	    //		4. The destination pointer points to a memory address with enough memory space to contain the ascii string ( this can not be checked )
	    //		5.
	    //
	    //  Possible errors :
	    //
	    //      They will come
	    //
		static Boolean CopyAsciiString( const char* sourceAsciiString, char* destinationAsciiString );


	    // Method Information :
	    //
	    //  Description :
	    //
	    //      Use this method to get the number of digits in the integer
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
	    //          integer - the integer that the number of digits of it should be found
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //      The number of digits in the integer
	    //
	    //  Expectations :
	    //
	    //		NONE
	    //
	    //  Possible errors :
	    //
	    //      They will come
	    //
	    template< typename IntegerType >
	    static inline UnsignedInteger64bits GetNumberOfDigitsInInteger( IntegerType integer );


	    // Template method Information :
	    //
	    //  Description :
	    //
	    //      Use this method to transform an ascii string of digits into an unsigned integer
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
	    //          1. asciiStringOfDigits - the address of the ascii string of digits
	    //			2. methodSucceededOrNot - a refernce to a boolean that will store true if the method was successful, and false otherwise
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //      The ascii string digits converted into an integer
	    //
		//  Expectations :
	    //
	    //      1. The given pointer is not NULL	
	    //		2. The string ends with a null terminator ( 0 )
	    //		3. The string contains only ascii values for digits 48 - 57
	    //		4. The size of the ascii string does not pass the maximum number of digits for the unsigned integer type
	    //		5. 
	    //
	    //  Possible errors :
	    //
	    //		NONE
	    //
	    template< typename UnsignedIntegerType >
	    static inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_UnsignedInteger< UnsignedIntegerType >::Result() == true, UnsignedIntegerType >::Type AsciiStringOfDigitsToInteger( const char* asciiStringOfDigits, Boolean& methodSucceededOrNot );


	    // Template method Information :
	    //
	    //  Description :
	    //
	    //      Use this method to transform an ascii string of digits into an signed integer
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
	    //          1. asciiStringOfDigits - the address of the ascii string of digits
	    //			2. methodSucceededOrNot - a refernce to a boolean that will store true if the method was successful, and false otherwise
		//
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //      The ascii string digits converted into an integer
	    //
		//  Expectations :
	    //
	    //      1. The given pointer is not NULL	
	    //		2. The string ends with a null terminator ( 0 )
	    //		3. The string contains only ascii values for digits 48 - 57
	    //		4. The size of the ascii string does not pass the maximum number of digits for the signed integer type
	    //		5. 
	    //
	    //  Possible errors :
	    //
	    //		NONE
	    //
	    template< typename SignedIntegerType >
	    static inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_SignedInteger< SignedIntegerType >::Result() == true, SignedIntegerType >::Type AsciiStringOfDigitsToInteger( const char* asciiStringOfDigits, Boolean& methodSucceededOrNot );


	    // Template method Information :
	    //
	    //  Description :
	    //
	    //      Use this method to convert the integer into an ascii string of digits
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
	    //			1. destinationToStoreIntegerDigits - the destination memory space to store the digits of the integer
	    //			2. integer - the integer that should be converted to an ascii string of digits
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //      A boolean with the value true if the method was successful and false otherwise
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
	    template< typename IntegerType >
	    static inline Boolean IntegerToStringOfDigits( char* destinationToStoreIntegerDigits, IntegerType integer );


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
		NoInstances_MACRO( AsciiStringAndIntegers )


	};  //  Class AsciiStringAndIntegers



#include "AsciiStringAndIntegers.inl"



}  //  Namespace Universe


#endif  // ASCIISTRINGSANDINTEGERS_HPP