namespace Universe 
{

namespace Memory
{



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

    // Create a function to test the copy functionality
    template< Concepts::BuiltIn BuiltInType >
    void Test_BuiltInTypes()
    {
        // Pick the size of the array
        UnsignedInteger64bits arraySize = Random::RunTimeGenerator::Numeric::Next< UnsignedInteger64bits >( Range< UnsignedInteger64bits >( 1UL, 1000UL ) );

        // Loop until the picked number is not 0
        while ( arraySize <= 0UL )
        {
            // Pick another number
            arraySize = Random::RunTimeGenerator::Numeric::Next< UnsignedInteger64bits >();
        }

        // Ensure that the size is not too large
        if ( arraySize > 30000UL )
        {
        	// Set the size to 30000
        	arraySize = 30000UL;	
        }

        // Allocate two arrays in the required size
        BuiltInType source[25000] = {0};
        BuiltInType destination[25000] = {0};

        BuiltInType source1[25000] = {0};
        BuiltInType destination1[25000] = {0};

        BuiltInType* const source2 = MainMemoryManager::template AllocateAndDefaultConstruct< BuiltInType >( arraySize );
        BuiltInType* const destination2 = MainMemoryManager::template AllocateAndDefaultConstruct< BuiltInType >( arraySize );

    	// Set the arrays
        Operations::Set< BuiltInType >( source, 25000, 1 );
        Operations::Set< BuiltInType >( destination, 25000, 1 );
        Operations::Set< BuiltInType >( source1, 25000, 2 );
        Operations::Set< BuiltInType >( destination1, 25000, 2 );
        Operations::Set< BuiltInType >( source2, arraySize, 3 );
        Operations::Set< BuiltInType >( destination2, arraySize, 3 );

        // Compare between the arrays using an outside well tested code
        Assert_Test( ( memcmp( source, destination, 25000 ) == 0 ) && ( Operations::Compare< BuiltInType >( source, destination, 25000 ) == true ) );
        Assert_Test( ( memcmp( source1, destination1, 25000 ) == 0 ) && ( Operations::Compare< BuiltInType >( source1, destination1, 25000 ) == true ) );
        Assert_Test( ( memcmp( source2, destination2, arraySize ) == 0 ) && ( Operations::Compare< BuiltInType >( source2, destination2, arraySize ) == true ) );

        // Set all the entries of the source array
        for ( UnsignedInteger64bits index = 0UL ; index < 25000 ; ++index )
        {
            // Set the current entry of the array
            source[ index ] = Random::RunTimeGenerator::Numeric::Next< BuiltInType >();
            source1[ index ] = Random::RunTimeGenerator::Numeric::Next< BuiltInType >();
        }

        // Set all the entries of the source array
        for ( UnsignedInteger64bits index = 0UL ; index < arraySize ; ++index )
        {
            // Set the current entry of the array
            source2[ index ] = Random::RunTimeGenerator::Numeric::Next< BuiltInType >();
        }

        // Copy the arrays
        Operations::Copy< BuiltInType >( source, destination, 25000 );
        Operations::Copy< BuiltInType >( source1, destination1, 25000 );
        Operations::Copy< BuiltInType >( source2, destination2, arraySize );

        // Compare between the arrays using an outside well tested code
        Assert_Test( ( memcmp( source, destination, 25000 ) == 0 ) && ( Operations::Compare< BuiltInType >( source, destination, 25000 ) == true ) );
        Assert_Test( ( memcmp( source1, destination1, 25000 ) == 0 ) && ( Operations::Compare< BuiltInType >( source1, destination1, 25000 ) == true ) );
        Assert_Test( ( memcmp( source2, destination2, arraySize ) == 0 ) && ( Operations::Compare< BuiltInType >( source2, destination2, arraySize ) == true ) );

        // Copy the arrays
        Operations::Move< BuiltInType >( source, destination, 25000 );
        Operations::Move< BuiltInType >( source1, destination1, 25000 );
        Operations::Move< BuiltInType >( source2, destination2, arraySize );

    	// Compare between the arrays using an outside well tested code
        Assert_Test( ( memcmp( source, destination, 25000 ) == 0 ) && ( Operations::Compare< BuiltInType >( source, destination, 25000 ) == true ) );
        Assert_Test( ( memcmp( source1, destination1, 25000 ) == 0 ) && ( Operations::Compare< BuiltInType >( source1, destination1, 25000 ) == true ) );
        Assert_Test( ( memcmp( source2, destination2, arraySize ) == 0 ) && ( Operations::Compare< BuiltInType >( source2, destination2, arraySize ) == true ) );

        MainMemoryManager::template Done< BuiltInType >( source2, false );
        MainMemoryManager::template Done< BuiltInType >( destination2, false );
    }

    // Create a function to test the copy functionality
    template< Concepts::NotBuiltIn NotBuiltInType >
    void Test_NotBuiltInTypes()
    {              
        // Pick the size of the array
        UnsignedInteger64bits arraySize = Random::RunTimeGenerator::Numeric::Next< UnsignedInteger64bits >( Range< UnsignedInteger64bits >( 1UL, 1000UL ) );

        // Loop until the picked number is not 0
        while ( arraySize == 0UL )
        {
            // Pick another number
            arraySize = Random::RunTimeGenerator::Numeric::Next< UnsignedInteger64bits >();
        }

        // Allocate arrays in the required size
        NotBuiltInType source[25];
        NotBuiltInType destination[25];
        NotBuiltInType moveDestination[25];

        NotBuiltInType source1[25];
        NotBuiltInType destination1[25];
        NotBuiltInType moveDestination1[25];

        NotBuiltInType* const source2 =  MainMemoryManager::template AllocateAndDefaultConstruct< NotBuiltInType >( arraySize );
        NotBuiltInType* const destination2 = MainMemoryManager::template AllocateAndDefaultConstruct< NotBuiltInType >( arraySize );
        NotBuiltInType* const moveDestination2 = MainMemoryManager::template AllocateAndDefaultConstruct< NotBuiltInType >( arraySize );

        static typename NotBuiltInType::SelfDataType randomNumber = 0;

        // Create an instance
        NotBuiltInType Test_NotBuiltInType1[25];
        NotBuiltInType Test_NotBuiltInType2[25];
        NotBuiltInType Test_NotBuiltInType3[25];

        const NotBuiltInType test_NotBuiltInType( 25, randomNumber++ );

    	// Set the arrays
        Operations::Set< NotBuiltInType >( source, 25, test_NotBuiltInType );
        Operations::Set< NotBuiltInType >( destination, 25, test_NotBuiltInType );
        Operations::Set< NotBuiltInType >( source2, arraySize, test_NotBuiltInType );
        Operations::Set< NotBuiltInType >( destination2, arraySize, test_NotBuiltInType );

        // Compare between the arrays using an outside well tested code
        Assert_Test( Operations::Compare< NotBuiltInType >( source, destination, 25 ) == true );
        Assert_Test( Operations::Compare< NotBuiltInType >( source2, destination2, arraySize ) == true );

        // Set all the entries of the source array
        for ( UnsignedInteger64bits index = 0UL ; index < 25UL ; ++index )
        {
            // Set the current entry of the array
            source[ index ] = TakeResourcesAndLeaveInstanceInDefaultState( NotBuiltInType( 25, randomNumber++ ) );
            source1[ index ] = TakeResourcesAndLeaveInstanceInDefaultState( NotBuiltInType( 25, randomNumber++ ) );
        }

        // Set all the entries of the source array
        for ( UnsignedInteger64bits index = 0UL ; index < arraySize ; ++index )
        {
            // Set the current entry of the array
            source2[ index ] = TakeResourcesAndLeaveInstanceInDefaultState( NotBuiltInType( 25, randomNumber++ ) );
        }

        // Copy the array
        Operations::Copy< NotBuiltInType >( source, destination, 25UL );
        Operations::Copy< NotBuiltInType >( source1, destination1, 25UL );
        Operations::Copy< NotBuiltInType >( source2, destination2, arraySize );

        // Compare between the arrays using an outside well tested code
        for ( UnsignedInteger64bits index = 0UL ; index < 25UL ; ++index )
        {
        	Assert_Test( source[ index ] == destination[ index ] );
        	Assert_Test( source1[ index ] == destination1[ index ] );
        }

        // Compare between the arrays using an outside well tested code
        for ( UnsignedInteger64bits index = 0UL ; index < arraySize ; ++index )
        {
        	Assert_Test( source2[ index ] == destination2[ index ] );
        }

        // Compare between the arrays using an outside well tested code
        Assert_Test( Operations::Compare< NotBuiltInType >( source, destination, 25 ) == true );
        Assert_Test( Operations::Compare< NotBuiltInType >( source1, destination1, 25 ) == true );
        Assert_Test( Operations::Compare< NotBuiltInType >( source2, destination2, arraySize ) == true );

        // Move the array
        Operations::Move< NotBuiltInType >( source, moveDestination, 25UL );
        Operations::Move< NotBuiltInType >( source1, moveDestination1, 25UL );
        Operations::Move< NotBuiltInType >( source2, moveDestination2, arraySize );

        // Compare between the arrays using an outside well tested code
        Assert_Test( Operations::Compare< NotBuiltInType >( moveDestination, destination, 25 ) == true );
        Assert_Test( Operations::Compare< NotBuiltInType >( moveDestination1, destination1, 25 ) == true );
        Assert_Test( Operations::Compare< NotBuiltInType >( moveDestination2, destination2, arraySize ) == true );

        MainMemoryManager::template Done< NotBuiltInType >( source2, false );
        MainMemoryManager::template Done< NotBuiltInType >( destination2, false );
        MainMemoryManager::template Done< NotBuiltInType >( moveDestination2, false );
    }


	void Operations::UnitTest()
	{
        // SWAP


        // Create 2 objects
        UnsignedInteger64bits testResource_1 = 8;
        UnsignedInteger64bits testResource_2 = 5;

        // Swap the 2
        Swap< UnsignedInteger64bits >( testResource_1, testResource_2 );

        // Assert that the swap was performed correctly
        Assert_Test( ( testResource_1 == 5 ) && ( testResource_2 == 8 ) );

        // Create 2 instances of the test class
        Test::TemplateObjectBuiltUsingOnlyCppFeatures< UnsignedInteger64bits > testResource_3( 8, 9 );
        Test::TemplateObjectBuiltUsingOnlyCppFeatures< UnsignedInteger64bits > testResource_4( 1, 4 );

        // Swap the 2
        Swap< Test::TemplateObjectBuiltUsingOnlyCppFeatures< UnsignedInteger64bits > >( testResource_3, testResource_4 );

        // Assert that the swap was performed correctly
        Assert_Test( ( testResource_3[0] == 4 ) && ( testResource_4[0] == 9 ) );


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
            Assert_Test( testBytesArray_1[ index ] == 1);
        }

        // Set the 20 last bytes to 2
        Set< UnsignedInteger16bits >( ( testBytesArray_1 + 20 ), 20, 2 );

        // Loop on the segment and check that is that it is correct
        for ( int index = 0 ; index < 20 ; ++index )
        {
            // Check the current entry
            Assert_Test( *( testBytesArray_1 + index ) == 1);
        }

        // Loop on the segment and check that is that it is correct
        for ( int index = 20 ; index < 40 ; ++index )
        {
            // Check the current entry
            Assert_Test( *( testBytesArray_1 + index ) == 2);
        }

        // Set the 3 firat bytes to 3
        Set< UnsignedInteger16bits >( testBytesArray_1, 3, 3 );

        // Loop on the segment and check that is that it is correct
        for ( int index = 0 ; index < 3 ; ++index )
        {
            // Check the current entry
            Assert_Test( *( testBytesArray_1 + index ) == 3);
        }

        // Loop on the segment and check that is that it is correct
        for ( int index = 3 ; index < 20 ; ++index )
        {
            // Check the current entry
            Assert_Test( *( testBytesArray_1 + index ) == 1);
        }

        // Loop on the segment and check that is that it is correct
        for ( int index = 20 ; index < 40 ; ++index )
        {
            // Check the current entry
            Assert_Test( *( testBytesArray_1 + index ) == 2);
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
            Assert_Test( *( testBytesArray_2 + index ) == 1);
        }

        // Set the 20 last bytes to 2
        Set< UnsignedInteger32bits >( ( testBytesArray_2 + 20 ), 20, 2 );

        // Loop on the segment and check that is that it is correct
        for ( int index = 0 ; index < 20 ; ++index )
        {
            // Check the current entry
            Assert_Test( *( testBytesArray_2 + index ) == 1 );
        }

        // Loop on the segment and check that is that it is correct
        for ( int index = 20 ; index < 40 ; ++index )
        {
            // Check the current entry
            Assert_Test( *( testBytesArray_2 + index ) == 2 );
        }

        // Set the 3 firat bytes to 3
        Set< UnsignedInteger32bits >( testBytesArray_2, 3, 3 );

        // Loop on the segment and check that is that it is correct
        for ( int index = 0 ; index < 3 ; ++index )
        {
            // Check the current entry
            Assert_Test( *( testBytesArray_2 + index ) == 3 );
        }

        // Loop on the segment and check that is that it is correct
        for ( int index = 3 ; index < 20 ; ++index )
        {
            // Check the current entry
            Assert_Test( *( testBytesArray_2 + index ) == 1 );
        }

        // Loop on the segment and check that is that it is correct
        for ( int index = 20 ; index < 40 ; ++index )
        {
            // Check the current entry
            Assert_Test( *( testBytesArray_2 + index ) == 2 );
        }


        // COMPARE


        // Test for types that has size of 1 byte

        // Create an array of bytes initiatied to 0
        UnsignedInteger8bits testBytesArray_3[40] = {0};

        // Create an array of bytes initiatied to 0
        UnsignedInteger8bits testBytesArray_4[40] = {2};

        // Check that the compare result is false
        Assert_Test( Compare< UnsignedInteger8bits >( testBytesArray_3, testBytesArray_4, 40 ) == false );

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
        Assert_Test( Compare< UnsignedInteger8bits >( testBytesArray_5, testBytesArray_6, 4056 ) );

        // Change one of them
        testBytesArray_6[5] = 8;

        // Check that the compare result is false
        Assert_Test( Compare< UnsignedInteger8bits >( testBytesArray_5, testBytesArray_6, 8 ) == false );

        // Test for types that has size of 8 byte

        // Create an array of bytes initiatied to 0
        UnsignedInteger64bits testBytesArray_7[40] = {0};

        // Create an array of bytes initiatied to 0
        UnsignedInteger64bits testBytesArray_8[40] = {897};

        // Check that the compare result is false
        Assert_Test( Compare< UnsignedInteger64bits >( testBytesArray_7, testBytesArray_8, 40 ) == false );

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
        Assert_Test( Compare< UnsignedInteger64bits >( testBytesArray_9, testBytesArray_10, 4056 ) );

        // Change one of them
        testBytesArray_10[5] = 86;

        // Check that the compare result is false
        Assert_Test( Compare< UnsignedInteger64bits >( testBytesArray_9, testBytesArray_10, 8 ) == false );


        // BETTER TESTING :


        // This object will store the number of iterations to test each functionality
        UnsignedInteger64bits numberOfIterations = 10UL;

        // Loop to test the copy functionality
        for ( UnsignedInteger64bits iteration = 0 ; iteration < numberOfIterations ; ++iteration )
        {
            // Activate the copy test
            Test_BuiltInTypes< UnsignedInteger8bits >();
            Test_BuiltInTypes< UnsignedInteger16bits >();
            Test_BuiltInTypes< UnsignedInteger32bits >();
            Test_BuiltInTypes< UnsignedInteger64bits >();
            Test_BuiltInTypes< SignedInteger8bits >();
            Test_BuiltInTypes< SignedInteger16bits >();
            Test_BuiltInTypes< SignedInteger32bits >();
            Test_BuiltInTypes< SignedInteger64bits >();
            Test_BuiltInTypes< FloatingPoint32bits >();
            Test_BuiltInTypes< FloatingPoint64bits >();
        }

        // Loop to test the copy functionality
        for ( UnsignedInteger64bits iteration = 0 ; iteration < numberOfIterations ; ++iteration )
        {
            // Activate the copy test
            Test_NotBuiltInTypes< Test::TemplateObjectBuiltUsingOnlyCppFeatures< UnsignedInteger8bits > >();
            Test_NotBuiltInTypes< Test::TemplateObjectBuiltUsingOnlyCppFeatures< UnsignedInteger16bits > >();
            Test_NotBuiltInTypes< Test::TemplateObjectBuiltUsingOnlyCppFeatures< UnsignedInteger32bits > >();
            Test_NotBuiltInTypes< Test::TemplateObjectBuiltUsingOnlyCppFeatures< UnsignedInteger64bits > >();
            Test_NotBuiltInTypes< Test::TemplateObjectBuiltUsingOnlyCppFeatures< SignedInteger8bits > >();
            Test_NotBuiltInTypes< Test::TemplateObjectBuiltUsingOnlyCppFeatures< SignedInteger16bits > >();
            Test_NotBuiltInTypes< Test::TemplateObjectBuiltUsingOnlyCppFeatures< SignedInteger32bits > >();
            Test_NotBuiltInTypes< Test::TemplateObjectBuiltUsingOnlyCppFeatures< SignedInteger64bits > >();
            Test_NotBuiltInTypes< Test::TemplateObjectBuiltUsingOnlyCppFeatures< FloatingPoint32bits > >();
            Test_NotBuiltInTypes< Test::TemplateObjectBuiltUsingOnlyCppFeatures< FloatingPoint64bits > >();
        }
	}

)  //  End of debug tool



}  //  Namespace Memory


}  //  Namespace Universe