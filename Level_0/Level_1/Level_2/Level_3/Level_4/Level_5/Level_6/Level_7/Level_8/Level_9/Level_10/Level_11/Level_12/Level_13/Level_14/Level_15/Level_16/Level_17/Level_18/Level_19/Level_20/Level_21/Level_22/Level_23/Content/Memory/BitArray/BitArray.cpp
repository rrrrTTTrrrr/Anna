namespace Universe 
{


namespace Memory
{



// Initialize the static lookup table to optimize the search for bits with state off
const Vector< Vector< UnsignedInteger8bits > > BitArray::member_lookupTableToOptimizeSearchForBitsWithStateOff = BitArray::CreateLookupTableToOptimizeSearchForBitsWithStateOff__Private();



//	********************************************************************   PRIVATE METHODS IMPLEMENTATION   *********************************************************************



Vector< Vector< UnsignedInteger8bits > > BitArray::CreateLookupTableToOptimizeSearchForBitsWithStateOff__Private()
{
    // This object will store the lookup table for searching bits with state off
    Vector< Vector< UnsignedInteger8bits > > lookupTableToOptimizeSearchForBitsWithStateOff( 256UL );

    // Loop on 256 possible values for a byte
    for ( UnsignedInteger8bits byte = 0 ; byte < NumericLimits< UnsignedInteger8bits >::Maximum ; ++byte )
    {
        // This object will be used to point to single bits of the current byte
        Bit bits( &byte );

        // Loop on all the bits of the byte
        for ( UnsignedInteger8bits bitIndex = 0 ; bitIndex < 8 ; ++bitIndex )
        {
            // Point to the current bit in the byte
            bits.SetBitIndex( bitIndex );

            // Check if the current bit if off
            if ( bits.State() == BitState::OFF )
            {
                // The current bit is off

                // Add the offset to the current bit to the array
                lookupTableToOptimizeSearchForBitsWithStateOff[ byte ].InsertSingleElement( lookupTableToOptimizeSearchForBitsWithStateOff[ byte ].Size(), bitIndex );
            }
        }
    }

    // Return the lookup table result
    return ( lookupTableToOptimizeSearchForBitsWithStateOff );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	void BitArray::UnitTest()
	{
        // Create an instance of the object using the default constructor
        BitArray testBitArray_1( 89UL );

        // Loop and check that all the bits are off
        for ( UnsignedInteger64bits bitIndex = 0UL ; bitIndex < 89UL ; ++bitIndex )
        {
            // Check that the current bit is off
            Assert_Test( testBitArray_1[ bitIndex ].State() == BitState::OFF );
        }

        // Create an instnace of the object using the parameterized constructor
        BitArray testBitArray_2( 873UL );
        testBitArray_2.SetAllBitsOn();

        // Loop and check that all the bits are ON
        for ( UnsignedInteger64bits bitIndex = 0UL ; bitIndex < 873UL ; ++bitIndex )
        {
            // Check that the current bit is ON
            Assert_Test( testBitArray_2[ bitIndex ].State() == BitState::ON );
        }

        // Check the size of the array
        Assert_Test( testBitArray_2.Size() == 873UL );

        // Create an instnace of the object using the parameterized constructor
        BitArray testBitArray_3( 49UL );

        // Check the size of the array
        Assert_Test( testBitArray_3.Size() == 49UL );  
        Assert_Test( testBitArray_3[13].State() == BitState::OFF );  

        // Create an instnace of the object using the parameterized constructor
        BitArray testBitArray_4( 49UL );
        testBitArray_4.SetAllBitsOn();

        // Check that the 2 instnaces are different
        Assert_Test( testBitArray_3 != testBitArray_4 );  

        // Set all the entries
        testBitArray_4 = TakeResourcesAndLeaveInstanceInDefaultState( BitArray( 49UL ) );

        // Check that the 2 instnaces are the same
        Assert_Test( testBitArray_3 == testBitArray_4 );

        // A write operation is performed, to check that the object uses the copy on write method before
        testBitArray_4[5] = BitState::ON;

        // Check that the 2 instnaces point to the same address
        Assert_Test( testBitArray_3 != testBitArray_4 );                                  

        // Check if the and 
        Assert_Test( testBitArray_4[5].State() == BitState::ON );

        // Create an instnace of the object using the parameterized constructor
        BitArray testBitArray_5( 10UL );
        testBitArray_5.SetAllBitsOn();

        // Search for the offsets to all the bits with state off
        auto offsetsToBitsWithStateOff_0 = testBitArray_5.SearchForBitsWithStateOff< Vector >( 2 );

        // Assert that nothing was found
        Assert_Test( offsetsToBitsWithStateOff_0.Size() == 0UL );

        // Set a bit off
        testBitArray_5[4] = BitState::OFF;

        // Search for the offsets to all the bits with state off
        auto offsetsToBitsWithStateOff_1 = testBitArray_5.SearchForBitsWithStateOff< Vector >( 2 );

        // Assert that only one bit was located, and it was located at offset 4
        Assert_Test( offsetsToBitsWithStateOff_1.Size() == 1UL );
        Assert_Test( offsetsToBitsWithStateOff_1[0] == 4UL );

        // Set another bit off
        testBitArray_5[6] = BitState::OFF;

        // Search for the offsets to all the bits with state off
        auto offsetsToBitsWithStateOff_2 = testBitArray_5.SearchForBitsWithStateOff< SingleLinkedList >( 2 );

        // Assert that only one bit was located, and it was located at offset 4
        Assert_Test( offsetsToBitsWithStateOff_2.Size() == 2UL );
        Assert_Test( offsetsToBitsWithStateOff_2[0] == 4UL );
        Assert_Test( offsetsToBitsWithStateOff_2[1] == 6UL );

        // Create an instnace of the object using the parameterized constructor
        BitArray testBitArray_6( 4UL );
        testBitArray_6.SetAllBitsOn();

        // Search for the offsets to all the bits with state off
        auto offsetsToBitsWithStateOff_3 = testBitArray_6.SearchForAllBitsWithStateOff< SingleLinkedList >();

        // Assert that all bits are on
        Assert_Test( offsetsToBitsWithStateOff_3.Size() == 0UL );

        // Set all bits off
        testBitArray_6.SetAllBitsOff();

        // Search for the offsets to all the bits with state off
        auto offsetsToBitsWithStateOff_4 = testBitArray_6.SearchForAllBitsWithStateOff< SingleLinkedList >();

        // Assert that all bits were found
        Assert_Test( offsetsToBitsWithStateOff_4.Size() == 4UL );

        // Set three bits on
        testBitArray_6[0] = BitState::ON;
        testBitArray_6[1] = BitState::ON;
        testBitArray_6[2] = BitState::ON;

        // Search for the offsets to all the bits with state off
        auto offsetsToBitsWithStateOff_5 = testBitArray_6.SearchForAllBitsWithStateOff< SingleLinkedList >();

        // Assert that all bits were found
        Assert_Test( offsetsToBitsWithStateOff_5.Size() == 1UL );
	}

)  //  End of debug tool



}  //  Namespace Memory


}  //  Namespace Universe