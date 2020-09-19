#ifndef  DIGITS_CPP
#define  DIGITS_CPP


#include "Digits.hpp"


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe 
{



	// Forward declarations :
	//
	//  NONE
	//




































//  ********************************************************************   STATIC FUNCTIONS IMPLEMENTATION   ********************************************************************




































//	********************************************************************   PRIVATE METHODS IMPLEMENTATION   *********************************************************************




































// *********************************************************************************   TESTING   ********************************************************************************




































	DEBUG_TOOL(

		// Method Information :
		//
		//  Description :
		//
		//		This method is used to test the object. It is not part of the implementation, it is only used to find problem with the code that does implement
		//		the functionality
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
		//		1. true - if the object passed the test
		//		2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		1. An assertion failed - class Exception is thrown
		//		2. There is no more free memory space - class std::bad_alloc is thrown
		//		3. 
		//
		void Digits::Test()
		{
			// Check the method that calculates the number of digits
			Assert_Test_MACRO( NumberOfDigits< UnsignedInteger64bits >( 56UL ) == 2 )
			Assert_Test_MACRO( NumberOfDigits< UnsignedInteger64bits >( 561UL ) == 3 )
			Assert_Test_MACRO( NumberOfDigits< UnsignedInteger64bits >( 5621UL ) == 4 )
			Assert_Test_MACRO( NumberOfDigits< UnsignedInteger64bits >( 56321UL ) == 5 )
			Assert_Test_MACRO( NumberOfDigits< UnsignedInteger64bits >( 564321UL ) == 6 )
			Assert_Test_MACRO( NumberOfDigits< UnsignedInteger64bits >( 5654321UL ) == 7 )
			Assert_Test_MACRO( NumberOfDigits< UnsignedInteger64bits >( 56654321UL ) == 8 )
			Assert_Test_MACRO( NumberOfDigits< UnsignedInteger64bits >( 567654313UL ) == 9 )
			Assert_Test_MACRO( NumberOfDigits< UnsignedInteger64bits >( 897 ) == 3 )
			Assert_Test_MACRO( NumberOfDigits< UnsignedInteger64bits >( 8298239 ) == 7 )
			Assert_Test_MACRO( NumberOfDigits< UnsignedInteger64bits >( 838398309 ) == 9 )
			Assert_Test_MACRO( NumberOfDigits< UnsignedInteger64bits >( 8 ) == 1 )
			Assert_Test_MACRO( NumberOfDigits< UnsignedInteger64bits >( 0 ) == 1 )
			Assert_Test_MACRO( NumberOfDigits< UnsignedInteger64bits >( 3422 ) == 4 )
			Assert_Test_MACRO( NumberOfDigits< UnsignedInteger64bits >( 89754 ) == 5 )
			Assert_Test_MACRO( NumberOfDigits< UnsignedInteger64bits >( 987589392 ) == 9 )
			Assert_Test_MACRO( NumberOfDigits< SignedInteger64bits >( -897 ) == 3 )
			Assert_Test_MACRO( NumberOfDigits< SignedInteger64bits >( -8298239 ) == 7 )
			Assert_Test_MACRO( NumberOfDigits< SignedInteger64bits >( -838398309 ) == 9 )
			Assert_Test_MACRO( NumberOfDigits< SignedInteger64bits >( -8 ) == 1 )
			Assert_Test_MACRO( NumberOfDigits< SignedInteger64bits >( -0 ) == 1 )
			Assert_Test_MACRO( NumberOfDigits< SignedInteger64bits >( -3422 ) == 4 )
			Assert_Test_MACRO( NumberOfDigits< SignedInteger64bits >( -89754 ) == 5 )
			Assert_Test_MACRO( NumberOfDigits< SignedInteger64bits >( -987589392 ) == 9 )

			// Convert an integer to array of digits
			auto testArrayOfDigits_1 = IntegerToArrayOfDigits( -345 );

			// Check that the convertion was correct
			Assert_Test_MACRO( ( testArrayOfDigits_1[0] == '-' ) )
			Assert_Test_MACRO( ( testArrayOfDigits_1[1] == '3' ) )
			Assert_Test_MACRO( ( testArrayOfDigits_1[2] == '4' ) )
			Assert_Test_MACRO( ( testArrayOfDigits_1[3] == '5' ) )

			// Convert an integer to array of digits
			auto testArrayOfDigits_2 = IntegerToArrayOfDigits( 34543564324354 );

			// Check that the convertion was correct
			Assert_Test_MACRO( ( '3' == testArrayOfDigits_2[0] ) )
			Assert_Test_MACRO( ( testArrayOfDigits_2[1] == '4' ) )
			Assert_Test_MACRO( ( testArrayOfDigits_2[2] == '5' ) )
			Assert_Test_MACRO( ( testArrayOfDigits_2[3] == '4' ) )
			Assert_Test_MACRO( ( testArrayOfDigits_2[4] == '3' ) )
			Assert_Test_MACRO( ( testArrayOfDigits_2[5] == '5' ) )
			Assert_Test_MACRO( ( testArrayOfDigits_2[6] == '6' ) )
			Assert_Test_MACRO( ( testArrayOfDigits_2[7] == '4' ) )
			Assert_Test_MACRO( ( testArrayOfDigits_2[8] == '3' ) )
			Assert_Test_MACRO( ( testArrayOfDigits_2[9] == '2' ) )
			Assert_Test_MACRO( ( testArrayOfDigits_2[10] == '4' ) )
			Assert_Test_MACRO( ( testArrayOfDigits_2[11] == '3' ) )
			Assert_Test_MACRO( ( testArrayOfDigits_2[12] == '5' ) )
			Assert_Test_MACRO( ( testArrayOfDigits_2[13] == '4' ) )


			Assert_Test_MACRO( AsciiStringOfDigitsToInteger< UnsignedInteger64bits COMMA Language::HeapAsciiString >( Language::HeapAsciiString( "1234" ) ) == 1234UL );
			Assert_Test_MACRO( AsciiStringOfDigitsToInteger< UnsignedInteger64bits COMMA Language::HeapAsciiString >( Language::HeapAsciiString( "10234" ) ) == 10234UL );
			Assert_Test_MACRO( AsciiStringOfDigitsToInteger< UnsignedInteger64bits COMMA Language::HeapAsciiString >( Language::HeapAsciiString( "1233334" ) ) == 1233334UL );
			Assert_Test_MACRO( AsciiStringOfDigitsToInteger< UnsignedInteger64bits COMMA Language::HeapAsciiString >( Language::HeapAsciiString( "1245634" ) ) == 1245634UL );
			Assert_Test_MACRO( AsciiStringOfDigitsToInteger< UnsignedInteger64bits COMMA Language::HeapAsciiString >( Language::HeapAsciiString( "123124" ) ) == 123124UL );
			Assert_Test_MACRO( AsciiStringOfDigitsToInteger< UnsignedInteger64bits COMMA Language::HeapAsciiString >( Language::HeapAsciiString( "1234567894" ) ) == 1234567894UL );
			Assert_Test_MACRO( AsciiStringOfDigitsToInteger< UnsignedInteger64bits COMMA Language::HeapAsciiString >( Language::HeapAsciiString( "0" ) ) == 0UL );
			Assert_Test_MACRO( AsciiStringOfDigitsToInteger< SignedInteger64bits COMMA Language::HeapAsciiString >( Language::HeapAsciiString( "1234" ) ) == 1234 );
			Assert_Test_MACRO( AsciiStringOfDigitsToInteger< SignedInteger64bits COMMA Language::HeapAsciiString >( Language::HeapAsciiString( "-1233334" ) ) == -1233334 );
			Assert_Test_MACRO( AsciiStringOfDigitsToInteger< SignedInteger64bits COMMA Language::HeapAsciiString >( Language::HeapAsciiString( "+1245634" ) ) == 1245634 );
			Assert_Test_MACRO( AsciiStringOfDigitsToInteger< SignedInteger64bits COMMA Language::HeapAsciiString >( Language::HeapAsciiString( "-123124" ) ) == -123124 );
			Assert_Test_MACRO( AsciiStringOfDigitsToInteger< SignedInteger64bits COMMA Language::HeapAsciiString >( Language::HeapAsciiString( "1234567894" ) ) == 1234567894 );
			Assert_Test_MACRO( AsciiStringOfDigitsToInteger< UnsignedInteger64bits COMMA Language::HeapAsciiString >( Language::HeapAsciiString( "+0" ) ) == 0 );
			Assert_Test_MACRO( AsciiStringOfDigitsToInteger< UnsignedInteger64bits COMMA Language::HeapAsciiString >( Language::HeapAsciiString( "-0" ) ) == 0 );
		}

	)  //  End of debug tool













}  //  Namespace Universe


#endif  //  DIGITS_CPP





