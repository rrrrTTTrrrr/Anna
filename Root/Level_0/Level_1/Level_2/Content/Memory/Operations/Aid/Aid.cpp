#ifndef  AID_CPP
#define  AID_CPP


#include "Aid.hpp"


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

			void Aid::Test()
			{
                // Push to the stack 1 byte and set some value to it
                UnsignedInteger8bits testValue_1 = 1;

                // Invoke the method for types with size of 1 byte
                UnsignedInteger64bits testResult_1 = DuplicateValueToFillEightBytes< UnsignedInteger8bits >( testValue_1 );

                // Check that the result is correct
                Assert_Test_MACRO( testResult_1 == 0x0101010101010101 );

                // Push to the stack 2 bytes and set some value to it
                UnsignedInteger16bits testValue_2 = 255;

                // Invoke the method for types with size of 2 bytes
                UnsignedInteger64bits testResult_2 = DuplicateValueToFillEightBytes< UnsignedInteger16bits >( testValue_2 );

                // Check that the result is correct
                Assert_Test_MACRO( testResult_2 == 0x00FF00FF00FF00FF );

                // Push to the stack 4 bytes and set some value to it
                UnsignedInteger32bits testValue_3 = 255;

                // Invoke the method for types with size of 4 bytes
                UnsignedInteger64bits testResult_3 = DuplicateValueToFillEightBytes< UnsignedInteger32bits >( testValue_3 );

                // Check that the result is correct
                Assert_Test_MACRO( testResult_3 == 0x000000FF000000FF );
			}

		)  //  End of debug tool



    }  //  Namespace Memory


}  //  Namespace Universe


#endif  //  AID_CPP





