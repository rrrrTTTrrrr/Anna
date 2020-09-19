#ifndef ASCIILITERAL_CPP
#define ASCIILITERAL_CPP


#include "AsciiLiteral.hpp"


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe 
{

	namespace Memory
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
			//		1. An assertion failed - class Exception or ErrnoException is thrown
			//		2. There is no more free memory space - class std::bad_alloc is thrown
			//		3. 
			//
			void AsciiLiteral::Test()
			{
				// Create an instance
				AsciiLiteral testAsciiLiteral_1;

				// Initiate the instance
				testAsciiLiteral_1.Initiate( "Wolves" );

				// Check that ascii literal is correct
				Assert_MACRO( ( testAsciiLiteral_1[0] == 'W' ), "Test failed - 1" );
				Assert_MACRO( ( testAsciiLiteral_1[1] == 'o' ), "Test failed - 2" );
				Assert_MACRO( ( testAsciiLiteral_1[2] == 'l' ), "Test failed - 3" );
				Assert_MACRO( ( testAsciiLiteral_1[3] == 'v' ), "Test failed - 4" );
				Assert_MACRO( ( testAsciiLiteral_1[4] == 'e' ), "Test failed - 5" );
				Assert_MACRO( ( testAsciiLiteral_1[5] == 's' ), "Test failed - 6" );

				// Check that the size is correct
				Assert_MACRO( ( testAsciiLiteral_1.Size() == 6UL ), "Test failed - 7" );
			}

		)  //  End of debug tool











	}  //  Namespace Memory


}  //  Namespace Universe


#endif  //  ASCIILITERAL_CPP





