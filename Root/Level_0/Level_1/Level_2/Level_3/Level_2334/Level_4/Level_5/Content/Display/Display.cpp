#ifndef  DISPLAY_CPP
#define  DISPLAY_CPP


#include "Display.hpp"


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe 
{



	// Forward declarations :
	//
	//  NONE
	//





















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
		void Display::Test()
		{
            // Create an object and store the value 1
            UnsignedInteger64bits testInteger_1 = 1;

            // Display the bits
            Bits< UnsignedInteger64bits >( testInteger_1 );

            // Left shift the bit to the last bit 
            testInteger_1 <<= 63;

            // Display the bits
            Bits< UnsignedInteger64bits >( testInteger_1 );

            // Create an object with the value 8  -  00001000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
            UnsignedInteger64bits testObject_1 = 8;

            // Create an object with the value 1024  -  00000000 00000100 00000000 00000000 00000000 00000000 00000000 00000000
            UnsignedInteger64bits testObject_2 = 1024;

            // Create an object with the value 56  -  00111000
            UnsignedInteger64bits testObject_3 = 56;

            // Check the display bits method
            Bits< UnsignedInteger64bits >( testObject_1 );

            // Check the display bits method
            Bits< UnsignedInteger64bits >( testObject_2 );

            // Check the display bits method
            Bits< UnsignedInteger64bits >( testObject_3 );

            // Check the template method - 00001001
            Bits< UnsignedInteger8bits >( 9 );

            // Check the template method - 00000000 00000001
            Bits< UnsignedInteger16bits >( 256 );

            // Check the template method - 00000001 00000000 00000001 00000000
            Bits< UnsignedInteger32bits >( 65537 );

            // Check the template method
            Bits< UnsignedInteger64bits >( 50000000001UL );

            // Check the template method
            Bits< SignedInteger8bits >( -1 );

            // Check the template method
            Bits< SignedInteger16bits >( -256 );

            // Check the template method
            Bits< SignedInteger32bits >( -16000 );

            // Check the template method
            Bits< SignedInteger64bits >( ~0UL );

            // Check the template method
            Bits< FloatingPoint >( 2 );

            // Check the template method
            Bits< FloatingPoint >( -2 );

            // Check the template method
            Bits< DoublePrecisionFloatingPoint >( 2 );

            // Check the template method
            Bits< DoublePrecisionFloatingPoint >( -2 );

            Bits< SignedInteger8bits >( 127 );
            Bits< SignedInteger8bits >( -128 );
            Bits< SignedInteger8bits >( -127 );

		}

	)  //  End of debug tool











}  //  Namespace Universe


#endif  //  DISPLAY_CPP





