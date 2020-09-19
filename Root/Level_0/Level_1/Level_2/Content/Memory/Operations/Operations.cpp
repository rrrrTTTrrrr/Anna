#ifndef  OPERATIONS_CPP
#define  OPERATIONS_CPP


#include "Operations.hpp"


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include <cstring>

#include "../../../../../../../Test/TestingTools/Objects/TestObject_1/TestObject_1.hpp"
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

            // Create a function to test the copy functionality
            template< typename ShallowCopyType >
            void Test_ShallowCopyTypes()
            {
                // This object will be used to pick number from the required range
                static Random::PickNumber< ShallowCopyType > pickNumber;
                
                // Pick the size of the array
                UnsignedInteger64bits arraySize = pickNumber.Get();

                // Loop until the picked number is not 0
                while ( arraySize <= 0UL )
                {
                    // Pick another number
                    arraySize = pickNumber.Get();
                }

                // Ensure that the size is not too large
                if ( arraySize > 30000UL )
                {
                	// Set the size to 30000
                	arraySize = 30000UL;	
                }

                // Allocate two arrays in the required size
                ShallowCopyType source[25000] = {0};
                ShallowCopyType destination[25000] = {0};

                ShallowCopyType source1[25000] = {0};
                ShallowCopyType destination1[25000] = {0};

                ShallowCopyType* source2 = new ShallowCopyType[ arraySize ];
                ShallowCopyType* destination2 = new ShallowCopyType[ arraySize ];

            	// Set the arrays
                Operations::Set< ShallowCopyType >( source, 25000, 1 );
                Operations::Set< ShallowCopyType >( destination, 25000, 1 );
                Operations::Set< ShallowCopyType >( source1, 25000, 2 );
                Operations::Set< ShallowCopyType >( destination1, 25000, 2 );
                Operations::Set< ShallowCopyType >( source2, arraySize, 3 );
                Operations::Set< ShallowCopyType >( destination2, arraySize, 3 );

                // Compare between the arrays using an outside well tested code
                Assert_Test_MACRO( ( memcmp( source, destination, 25000 ) == 0 ) && ( Operations::Compare< ShallowCopyType >( source, destination, 25000 ) == true ) );
                Assert_Test_MACRO( ( memcmp( source1, destination1, 25000 ) == 0 ) && ( Operations::Compare< ShallowCopyType >( source1, destination1, 25000 ) == true ) );
                Assert_Test_MACRO( ( memcmp( source2, destination2, arraySize ) == 0 ) && ( Operations::Compare< ShallowCopyType >( source2, destination2, arraySize ) == true ) );

                // Set all the entries of the source array
                for ( UnsignedInteger64bits index = 0UL ; index < 25000 ; ++index )
                {
                    // Set the current entry of the array
                    source[ index ] = pickNumber.Get();
                    source1[ index ] = pickNumber.Get();
                }

                // Set all the entries of the source array
                for ( UnsignedInteger64bits index = 0UL ; index < arraySize ; ++index )
                {
                    // Set the current entry of the array
                    source2[ index ] = pickNumber.Get();
                }

                // Copy the arrays
                Operations::Copy< ShallowCopyType >( source, destination, 25000 );
                Operations::Copy< ShallowCopyType >( source1, destination1, 25000 );
                Operations::Copy< ShallowCopyType >( source2, destination2, arraySize );

                // Compare between the arrays using an outside well tested code
                Assert_Test_MACRO( ( memcmp( source, destination, 25000 ) == 0 ) && ( Operations::Compare< ShallowCopyType >( source, destination, 25000 ) == true ) );
                Assert_Test_MACRO( ( memcmp( source1, destination1, 25000 ) == 0 ) && ( Operations::Compare< ShallowCopyType >( source1, destination1, 25000 ) == true ) );
                Assert_Test_MACRO( ( memcmp( source2, destination2, arraySize ) == 0 ) && ( Operations::Compare< ShallowCopyType >( source2, destination2, arraySize ) == true ) );

                // Copy the arrays
                Operations::Move< ShallowCopyType >( source, destination, 25000 );
                Operations::Move< ShallowCopyType >( source1, destination1, 25000 );
                Operations::Move< ShallowCopyType >( source2, destination2, arraySize );

            	// Compare between the arrays using an outside well tested code
                Assert_Test_MACRO( ( memcmp( source, destination, 25000 ) == 0 ) && ( Operations::Compare< ShallowCopyType >( source, destination, 25000 ) == true ) );
                Assert_Test_MACRO( ( memcmp( source1, destination1, 25000 ) == 0 ) && ( Operations::Compare< ShallowCopyType >( source1, destination1, 25000 ) == true ) );
                Assert_Test_MACRO( ( memcmp( source2, destination2, arraySize ) == 0 ) && ( Operations::Compare< ShallowCopyType >( source2, destination2, arraySize ) == true ) );

                // Delete the memory space allocated
                delete[] source2;
                delete[] destination2;
            }

            // Create a function to test the copy functionality
            template< typename NonShallowCopyType >
            void Test_NonShallowCopyTypes()
            {
                // This object will be used to pick number from the required range
                static Random::PickNumber< UnsignedInteger64bits > pickNumber;
                
                // Pick the size of the array
                UnsignedInteger8bits arraySize = pickNumber.Get();

                // Loop until the picked number is not 0
                while ( arraySize == 0UL )
                {
                    // Pick another number
                    arraySize = pickNumber.Get();
                }

                // Allocate arrays in the required size
                NonShallowCopyType source[25];
                NonShallowCopyType destination[25];
                NonShallowCopyType moveDestination[25];

                NonShallowCopyType source1[25];
                NonShallowCopyType destination1[25];
                NonShallowCopyType moveDestination1[25];

                NonShallowCopyType* source2 = new NonShallowCopyType[ arraySize ];
                NonShallowCopyType* destination2 = new NonShallowCopyType[ arraySize ];
                NonShallowCopyType* moveDestination2 = new NonShallowCopyType[ arraySize ];

                // Create an instance
                NonShallowCopyType Test_NonShallowCopyType1( GenerateRandomInstance );
                NonShallowCopyType Test_NonShallowCopyType2( GenerateRandomInstance );
		        NonShallowCopyType Test_NonShallowCopyType3( GenerateRandomInstance );

            	// Set the arrays
                Operations::Set< NonShallowCopyType >( source, 25, Test_NonShallowCopyType1 );
                Operations::Set< NonShallowCopyType >( destination, 25, Test_NonShallowCopyType1 );
                Operations::Set< NonShallowCopyType >( source1, 25, Test_NonShallowCopyType2 );
                Operations::Set< NonShallowCopyType >( destination1, 25, Test_NonShallowCopyType2 );
                Operations::Set< NonShallowCopyType >( source2, arraySize, Test_NonShallowCopyType3 );
                Operations::Set< NonShallowCopyType >( destination2, arraySize, Test_NonShallowCopyType3 );

                // Compare between the arrays using an outside well tested code
                Assert_Test_MACRO( Operations::Compare< NonShallowCopyType >( source, destination, 25 ) == true );
                Assert_Test_MACRO( Operations::Compare< NonShallowCopyType >( source1, destination1, 25 ) == true );
                Assert_Test_MACRO( Operations::Compare< NonShallowCopyType >( source2, destination2, arraySize ) == true );

                // Set all the entries of the source array
                for ( UnsignedInteger64bits index = 0UL ; index < 25UL ; ++index )
                {
                    // Set the current entry of the array
                    source[ index ].Initiate( GenerateRandomInstance );
                    source1[ index ].Initiate( GenerateRandomInstance );
                }

                // Set all the entries of the source array
                for ( UnsignedInteger64bits index = 0UL ; index < arraySize ; ++index )
                {
                    // Set the current entry of the array
                    source2[ index ].Initiate( GenerateRandomInstance );
                }

                // Copy the array
                Operations::Copy< NonShallowCopyType >( source, destination, 25UL );
                Operations::Copy< NonShallowCopyType >( source1, destination1, 25UL );
                Operations::Copy< NonShallowCopyType >( source2, destination2, arraySize );

                // Compare between the arrays using an outside well tested code
                for ( UnsignedInteger64bits index = 0UL ; index < 25UL ; ++index )
                {
                	Assert_Test_MACRO( source[ index ] == destination[ index ] );
                	Assert_Test_MACRO( source1[ index ] == destination1[ index ] );
                }

	            // Compare between the arrays using an outside well tested code
                for ( UnsignedInteger64bits index = 0UL ; index < arraySize ; ++index )
                {
                	Assert_Test_MACRO( source2[ index ] == destination2[ index ] );
                }

                // Compare between the arrays using an outside well tested code
                Assert_Test_MACRO( Operations::Compare< NonShallowCopyType >( source, destination, 25 ) == true );
                Assert_Test_MACRO( Operations::Compare< NonShallowCopyType >( source1, destination1, 25 ) == true );
                Assert_Test_MACRO( Operations::Compare< NonShallowCopyType >( source2, destination2, arraySize ) == true );

                // Copy the array
                Operations::Move< NonShallowCopyType >( source, moveDestination, 25UL );
                Operations::Move< NonShallowCopyType >( source1, moveDestination1, 25UL );
                Operations::Move< NonShallowCopyType >( source2, moveDestination2, arraySize );

                // Compare between the arrays using an outside well tested code
                Assert_Test_MACRO( Operations::Compare< NonShallowCopyType >( moveDestination, destination, 25 ) == true );
                Assert_Test_MACRO( Operations::Compare< NonShallowCopyType >( moveDestination1, destination1, 25 ) == true );
                Assert_Test_MACRO( Operations::Compare< NonShallowCopyType >( moveDestination2, destination2, arraySize ) == true );

                // Delete the memory space allocated
                delete[] source2;
                delete[] destination2;
            }


			void Operations::Test()
			{
                // SWAP


                // Create 2 objects
                UnsignedInteger64bits testResource_1 = 8;
                UnsignedInteger64bits testResource_2 = 5;

                // Swap the 2
                Swap< UnsignedInteger64bits >( testResource_1, testResource_2 );

                // Assert that the swap was performed correctly
                Assert_Test_MACRO( ( testResource_1 == 5 ) && ( testResource_2 == 8 ) );

                // Create 2 instances of the test class
                Testing::TestObject_1< UnsignedInteger64bits > testResource_3( 8, 9, false );
                Testing::TestObject_1< UnsignedInteger64bits > testResource_4( 1, 4, false );

                // Swap the 2
                Swap< Testing::TestObject_1< UnsignedInteger64bits > >( testResource_3, testResource_4 );

                // Assert that the swap was performed correctly
                Assert_Test_MACRO( ( testResource_3[0] == 4 ) && ( testResource_4[0] == 9 ) );


                // SET


                // Test for types that has size of 1 byte

                // Create an array of bytes initiatied to 0
                UnsignedInteger16bits testBytesArray_1[40] = {0};

                // Set all the bytes to 1
                Set< UnsignedInteger16bits >( testBytesArray_1, 40, 1 );

                // Loop on the segment and check that is that it is correct
                for ( int index = 0 ; index < 40 ; ++index )
                {
                    // Check the current entry
                    Assert_Test_MACRO( testBytesArray_1[ index ] == 1);
                }

                // Set the 20 last bytes to 2
                Set< UnsignedInteger16bits >( ( testBytesArray_1 + 20 ), 20, 2 );

                // Loop on the segment and check that is that it is correct
                for ( int index = 0 ; index < 20 ; ++index )
                {
                    // Check the current entry
                    Assert_Test_MACRO( *( testBytesArray_1 + index ) == 1);
                }

                // Loop on the segment and check that is that it is correct
                for ( int index = 20 ; index < 40 ; ++index )
                {
                    // Check the current entry
                    Assert_Test_MACRO( *( testBytesArray_1 + index ) == 2);
                }

                // Set the 3 firat bytes to 3
                Set< UnsignedInteger16bits >( testBytesArray_1, 3, 3 );

                // Loop on the segment and check that is that it is correct
                for ( int index = 0 ; index < 3 ; ++index )
                {
                    // Check the current entry
                    Assert_Test_MACRO( *( testBytesArray_1 + index ) == 3);
                }

                // Loop on the segment and check that is that it is correct
                for ( int index = 3 ; index < 20 ; ++index )
                {
                    // Check the current entry
                    Assert_Test_MACRO( *( testBytesArray_1 + index ) == 1);
                }

                // Loop on the segment and check that is that it is correct
                for ( int index = 20 ; index < 40 ; ++index )
                {
                    // Check the current entry
                    Assert_Test_MACRO( *( testBytesArray_1 + index ) == 2);
                }

                // Test for types that has size of 4 byte

                // Create an array of bytes initiatied to 0
                UnsignedInteger32bits testBytesArray_2[40] = {0};

                // Set all the bytes to 1
                Set< UnsignedInteger32bits >( testBytesArray_2, 40, 1 );

                // Loop on the segment and check that is that it is correct
                for ( int index = 0 ; index < 40 ; ++index )
                {
                    // Check the current entry
                    Assert_Test_MACRO( *( testBytesArray_2 + index ) == 1);
                }

                // Set the 20 last bytes to 2
                Set< UnsignedInteger32bits >( ( testBytesArray_2 + 20 ), 20, 2 );

                // Loop on the segment and check that is that it is correct
                for ( int index = 0 ; index < 20 ; ++index )
                {
                    // Check the current entry
                    Assert_Test_MACRO( *( testBytesArray_2 + index ) == 1 );
                }

                // Loop on the segment and check that is that it is correct
                for ( int index = 20 ; index < 40 ; ++index )
                {
                    // Check the current entry
                    Assert_Test_MACRO( *( testBytesArray_2 + index ) == 2 );
                }

                // Set the 3 firat bytes to 3
                Set< UnsignedInteger32bits >( testBytesArray_2, 3, 3 );

                // Loop on the segment and check that is that it is correct
                for ( int index = 0 ; index < 3 ; ++index )
                {
                    // Check the current entry
                    Assert_Test_MACRO( *( testBytesArray_2 + index ) == 3 );
                }

                // Loop on the segment and check that is that it is correct
                for ( int index = 3 ; index < 20 ; ++index )
                {
                    // Check the current entry
                    Assert_Test_MACRO( *( testBytesArray_2 + index ) == 1 );
                }

                // Loop on the segment and check that is that it is correct
                for ( int index = 20 ; index < 40 ; ++index )
                {
                    // Check the current entry
                    Assert_Test_MACRO( *( testBytesArray_2 + index ) == 2 );
                }


                // COMPARE


                // Test for types that has size of 1 byte

                // Create an array of bytes initiatied to 0
                UnsignedInteger8bits testBytesArray_3[40] = {0};

                // Create an array of bytes initiatied to 0
                UnsignedInteger8bits testBytesArray_4[40] = {2};

                // Check that the compare result is false
                Assert_Test_MACRO( Compare< UnsignedInteger8bits >( testBytesArray_3, testBytesArray_4, 40 ) == false );

                // Create an array of bytes initiatied to 0
                UnsignedInteger8bits testBytesArray_5[4056] = {0};

                // Create an array of bytes initiatied to 0
                UnsignedInteger8bits testBytesArray_6[4056] = {0};

                // Loop and set some values in both the segments
                for ( UnsignedInteger64bits index = 0 ; index < 4056 ; index += 2 )
                {
                    // Set the first segment
                    testBytesArray_5[ index ] = 3;

                    // Set the first segment
                    testBytesArray_6[ index ] = 3;
                }

                // Compare the segments and verify that they match
                Assert_Test_MACRO( Compare< UnsignedInteger8bits >( testBytesArray_5, testBytesArray_6, 4056 ) );

                // Change one of them
                testBytesArray_6[5] = 8;

                // Check that the compare result is false
                Assert_Test_MACRO( Compare< UnsignedInteger8bits >( testBytesArray_5, testBytesArray_6, 8 ) == false );

                // Test for types that has size of 8 byte

                // Create an array of bytes initiatied to 0
                UnsignedInteger64bits testBytesArray_7[40] = {0};

                // Create an array of bytes initiatied to 0
                UnsignedInteger64bits testBytesArray_8[40] = {897};

                // Check that the compare result is false
                Assert_Test_MACRO( Compare< UnsignedInteger64bits >( testBytesArray_7, testBytesArray_8, 40 ) == false );

                // Create an array of bytes initiatied to 0
                UnsignedInteger64bits testBytesArray_9[4056] = {0};

                // Create an array of bytes initiatied to 0
                UnsignedInteger64bits testBytesArray_10[4056] = {0};

                // Loop and set some values in both the segments
                for ( UnsignedInteger64bits index = 0 ; index < 4056 ; index += 2 )
                {
                    // Set the first segment
                    testBytesArray_9[ index ] = 344;

                    // Set the first segment
                    testBytesArray_10[ index ] = 344;
                }

                // Compare the segments and verify that they match
                Assert_Test_MACRO( Compare< UnsignedInteger64bits >( testBytesArray_9, testBytesArray_10, 4056 ) );

                // Change one of them
                testBytesArray_10[5] = 86;

                // Check that the compare result is false
                Assert_Test_MACRO( Compare< UnsignedInteger64bits >( testBytesArray_9, testBytesArray_10, 8 ) == false );


                // BETTER TESTING :


                // This object will store the number of iterations to test each functionality
                UnsignedInteger64bits numberOfIterations = 10UL;

                // Loop to test the copy functionality
                for ( UnsignedInteger64bits iteration = 0 ; iteration < numberOfIterations ; ++iteration )
                {
                    // Activate the copy test
                    Test_ShallowCopyTypes< UnsignedInteger8bits >();
                    Test_ShallowCopyTypes< UnsignedInteger16bits >();
                    Test_ShallowCopyTypes< UnsignedInteger32bits >();
                    Test_ShallowCopyTypes< UnsignedInteger64bits >();
                    Test_ShallowCopyTypes< SignedInteger8bits >();
                    Test_ShallowCopyTypes< SignedInteger16bits >();
                    Test_ShallowCopyTypes< SignedInteger32bits >();
                    Test_ShallowCopyTypes< SignedInteger64bits >();
                }

                // Loop to test the copy functionality
                for ( UnsignedInteger64bits iteration = 0 ; iteration < numberOfIterations ; ++iteration )
                {
                    // Activate the copy test
                    Test_NonShallowCopyTypes< Testing::TestObject_1< UnsignedInteger8bits > >();
                    Test_NonShallowCopyTypes< Testing::TestObject_1< UnsignedInteger16bits > >();
                    Test_NonShallowCopyTypes< Testing::TestObject_1< UnsignedInteger32bits > >();
                    Test_NonShallowCopyTypes< Testing::TestObject_1< UnsignedInteger64bits > >();
                    Test_NonShallowCopyTypes< Testing::TestObject_1< SignedInteger8bits > >();
                    Test_NonShallowCopyTypes< Testing::TestObject_1< SignedInteger16bits > >();
                    Test_NonShallowCopyTypes< Testing::TestObject_1< SignedInteger32bits > >();
                    Test_NonShallowCopyTypes< Testing::TestObject_1< SignedInteger64bits > >();
                }
                
			}

		)  //  End of debug tool



    }  //  Namespace Memory


}  //  Namespace Universe


#endif  //  OPERATIONS_CPP





