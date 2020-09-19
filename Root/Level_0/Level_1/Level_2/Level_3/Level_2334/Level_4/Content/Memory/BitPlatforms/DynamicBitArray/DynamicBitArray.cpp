#ifndef DYNAMICBITARRAY_CPP
#define DYNAMICBITARRAY_CPP


#include "DynamicBitArray.hpp"


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
			void DynamicBitArray::Test()
			{
                // Create an instance of the object using the default constructor
                DynamicBitArray testBitArray_1( 89UL );

                // Loop and check that all the bits are ON
                for ( UnsignedInteger64bits bitIndex = 0UL ; bitIndex < 89UL ; ++bitIndex )
                {
	                // Check that the current bit is ON
	                Assert_MACRO( ( testBitArray_1[ bitIndex ].ONorOFF() == 0 ), "Test failed - 1" );
                }

                // Create an instnace of the object using the parameterized constructor
                DynamicBitArray testBitArray_2( 873UL, 1 );

                // Loop and check that all the bits are ON
                for ( UnsignedInteger64bits bitIndex = 0UL ; bitIndex < 873UL ; ++bitIndex )
                {
	                // Check that the current bit is ON
	                Assert_MACRO( ( testBitArray_2[ bitIndex ].ONorOFF() == 1 ), "Test failed - 2" );
                }

                // Check the size of the array
                Assert_MACRO( ( testBitArray_2.Size() == 873UL ), "Test failed - 3" );

                // Create an instnace of the object using the parameterized constructor
                DynamicBitArray testBitArray_3( 49UL );

                // Check the size of the array
                Assert_MACRO( ( testBitArray_3.Size() == 49UL ), "Test failed - 4" );              
                Assert_MACRO( ( testBitArray_3[13].ONorOFF() == 0 ), "Test failed - 5" );              

                // Create an instnace of the object using the parameterized constructor
                DynamicBitArray testBitArray_4( 49UL, 1 );

                // Check that the 2 instnaces are different
                Assert_MACRO( ( testBitArray_3 != testBitArray_4 ), "Test failed - 6" );  

                // Set all the entries
                testBitArray_4.Initiate( 49UL );

                // Check that the 2 instnaces are the same
                Assert_MACRO( ( testBitArray_3 == testBitArray_4 ), "Test failed - 7" );

                // A write operation is performed, to check that the object uses the copy on write method before
                testBitArray_4[5] = 1;

                // Check that the 2 instnaces point to the same address
                Assert_MACRO( ( testBitArray_3 != testBitArray_4 ), "Test failed - 8" );                                              

                // Check if the addition works
                Assert_MACRO( ( testBitArray_4[5] & 1 ), "Test failed - 9" );

                // Test the generate random instance method
                GenerateRandomInstance( NumericRange( 456UL, 8796UL ) );
			}

		)  //  End of debug tool











	}  //  Namespace Memory


}  //  Namespace Universe


#endif  //  DYNAMICBITARRAY_CPP





