#ifndef  SEARCH_CPP
#define  SEARCH_CPP


#include "Search.hpp"


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../DynamicArray/DynamicArray.hpp"  //  Class DynamicArray
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
			void Search::Test()
			{
				// Create a test instance
				DynamicArray< UnsignedInteger32bits > testArray_Data_1( 8, 9 );

				// Try the find single element method
				Pair< Boolean COMMA UnsignedInteger64bits > result_1 = SingleElementInTheData< UnsignedInteger32bits >( testArray_Data_1, 9, 3 );

				// Check the results
				Assert_Test_MACRO( result_1.First() == true )
				Assert_Test_MACRO( result_1.Second() == 2UL )

				// Create a pattern instance
				DynamicArray< UnsignedInteger32bits > testArray_Pattern_1( 2, 9 );

				// Try the find pattern in the data
				Pair< Boolean COMMA UnsignedInteger64bits > result_2 = PatternInTheData< UnsignedInteger32bits >( testArray_Data_1, testArray_Pattern_1, 1 );

				// Check the results
				Assert_Test_MACRO( result_2.First() == true )
				Assert_Test_MACRO( result_2.Second() == 0UL )

				// Create a pattern instance
				DynamicArray< UnsignedInteger32bits > testArray_Pattern_3( 15, 9 );
				testArray_Pattern_3[0] = 8;
				testArray_Pattern_3[1] = 5;
				testArray_Pattern_3[2] = 3;
				testArray_Pattern_3[3] = 7;
				testArray_Pattern_3[4] = 1;
				testArray_Pattern_3[5] = 0;
				testArray_Pattern_3[6] = 8;
				testArray_Pattern_3[7] = 5;
				testArray_Pattern_3[8] = 3;
				testArray_Pattern_3[9] = 7;
				testArray_Pattern_3[10] = 1;
				testArray_Pattern_3[11] = 0;
				testArray_Pattern_3[12] = 8;
				testArray_Pattern_3[13] = 5;
				testArray_Pattern_3[14] = 3;

				// Process the pattern
				auto patternProcessingResult_1 = ProcessPatternToFindTheStartingPointForTheNextSearchIfMismatchWasFoundBetweenThePatternAndTheData__Private( testArray_Pattern_3 );

				// Assert that pattern was processed correctly
				Assert_Test_MACRO( patternProcessingResult_1.Second()[0] == 1 )
				Assert_Test_MACRO( patternProcessingResult_1.Second()[1] == 1 )
				Assert_Test_MACRO( patternProcessingResult_1.Second()[2] == 2 )
				Assert_Test_MACRO( patternProcessingResult_1.Second()[3] == 3 )
				Assert_Test_MACRO( patternProcessingResult_1.Second()[4] == 4 )
				Assert_Test_MACRO( patternProcessingResult_1.Second()[5] == 5 )
				Assert_Test_MACRO( patternProcessingResult_1.Second()[6] == 6 )
				Assert_Test_MACRO( patternProcessingResult_1.Second()[7] == 6 )
				Assert_Test_MACRO( patternProcessingResult_1.Second()[8] == 6 )
				Assert_Test_MACRO( patternProcessingResult_1.Second()[9] == 6 )
				Assert_Test_MACRO( patternProcessingResult_1.Second()[10] == 6 )
				Assert_Test_MACRO( patternProcessingResult_1.Second()[11] == 6 )
				Assert_Test_MACRO( patternProcessingResult_1.Second()[12] == 6 )
				Assert_Test_MACRO( patternProcessingResult_1.Second()[13] == 6 )
				Assert_Test_MACRO( patternProcessingResult_1.Second()[14] == 6 )

				// Create a pattern instance
				DynamicArray< UnsignedInteger32bits > testArray_Pattern_4( 27, 9 );
				testArray_Pattern_4[0] = 8;
				testArray_Pattern_4[1] = 5;
				testArray_Pattern_4[2] = 3;
				testArray_Pattern_4[3] = 7;
				testArray_Pattern_4[4] = 1;
				testArray_Pattern_4[5] = 0;
				testArray_Pattern_4[6] = 8;
				testArray_Pattern_4[7] = 5;
				testArray_Pattern_4[8] = 3;
				testArray_Pattern_4[9] = 7;
				testArray_Pattern_4[10] = 1;
				testArray_Pattern_4[11] = 0;
				testArray_Pattern_4[12] = 8;
				testArray_Pattern_4[13] = 5;
				testArray_Pattern_4[14] = 3;
				testArray_Pattern_4[15] = 5;
				testArray_Pattern_4[16] = 3;
				testArray_Pattern_4[17] = 7;
				testArray_Pattern_4[18] = 1;
				testArray_Pattern_4[19] = 55;
				testArray_Pattern_4[20] = 8;
				testArray_Pattern_4[21] = 5;
				testArray_Pattern_4[22] = 8;
				testArray_Pattern_4[23] = 2;
				testArray_Pattern_4[24] = 49;
				testArray_Pattern_4[25] = 34;
				testArray_Pattern_4[26] = 5;

				// Process the pattern
				auto patternProcessingResult_2 = ProcessPatternToFindTheStartingPointForTheNextSearchIfMismatchWasFoundBetweenThePatternAndTheData__Private( testArray_Pattern_4 );

				// Assert that pattern was processed correctly
				Assert_Test_MACRO( patternProcessingResult_2.Second()[0] == 1 )
				Assert_Test_MACRO( patternProcessingResult_2.Second()[1] == 1 )
				Assert_Test_MACRO( patternProcessingResult_2.Second()[2] == 2 )
				Assert_Test_MACRO( patternProcessingResult_2.Second()[3] == 3 )
				Assert_Test_MACRO( patternProcessingResult_2.Second()[4] == 4 )
				Assert_Test_MACRO( patternProcessingResult_2.Second()[5] == 5 )
				Assert_Test_MACRO( patternProcessingResult_2.Second()[6] == 6 )
				Assert_Test_MACRO( patternProcessingResult_2.Second()[7] == 6 )
				Assert_Test_MACRO( patternProcessingResult_2.Second()[8] == 6 )
				Assert_Test_MACRO( patternProcessingResult_2.Second()[9] == 6 )
				Assert_Test_MACRO( patternProcessingResult_2.Second()[10] == 6 )
				Assert_Test_MACRO( patternProcessingResult_2.Second()[11] == 6 )
				Assert_Test_MACRO( patternProcessingResult_2.Second()[12] == 6 )
				Assert_Test_MACRO( patternProcessingResult_2.Second()[13] == 6 )
				Assert_Test_MACRO( patternProcessingResult_2.Second()[14] == 6 )


				// Create a pattern instance
				DynamicArray< UnsignedInteger32bits > testArray_Pattern_2( 6, 9 );
				testArray_Pattern_2[0] = 3;
				testArray_Pattern_2[1] = 5;
				testArray_Pattern_2[2] = 3;
				testArray_Pattern_2[3] = 7;
				testArray_Pattern_2[4] = 1;
				testArray_Pattern_2[5] = 0;

				// Try the find pattern in the data
				Pair< Boolean COMMA UnsignedInteger64bits > result_3 = PatternInTheData< UnsignedInteger32bits >( testArray_Data_1, testArray_Pattern_2, 1 );

				// Assert that pattern was not found in the data
				Assert_Test_MACRO( result_3.First() == false )
			}

		)  //  End of debug tool











    }  //  Namespace Memory


}  //  Namespace Universe


#endif  //  SEARCH_CPP





