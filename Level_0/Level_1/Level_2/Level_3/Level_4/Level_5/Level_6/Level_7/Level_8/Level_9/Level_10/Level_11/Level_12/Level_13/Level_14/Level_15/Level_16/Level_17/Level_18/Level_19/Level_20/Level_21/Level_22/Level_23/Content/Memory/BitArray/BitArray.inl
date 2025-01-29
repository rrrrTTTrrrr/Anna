//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline BitArray::BitArray() :
    member_size( 0UL ),
    member_numberOfBytes( 0UL ),
	member_bitArrayPointer( nullptr )
{}


inline BitArray::BitArray( const LargestUnsignedInteger size ) :
    member_size( AssignOnlyIfValueIsLargerThenZero( size ) ),
    member_numberOfBytes( ( size / 8UL ) + 1UL ),
    member_bitArrayPointer( new UnsignedInteger8bits[ member_numberOfBytes ] )
{
    // Ensure all the bits are initialized with state off
    SetAllBitsOff();
}


inline BitArray::BitArray( const SelfType& other ) :
    member_size( other.member_size ),
    member_numberOfBytes( other.member_numberOfBytes ),
    member_bitArrayPointer( new UnsignedInteger8bits[ other.member_numberOfBytes ] )
{
	// Copy the bits from the other instance to this instance
	Memory::Operations::Copy< UnsignedInteger8bits >( other.member_bitArrayPointer, member_bitArrayPointer, member_numberOfBytes );
}


inline BitArray::~BitArray()
{
    // Delete the memory space
    delete[] member_bitArrayPointer;
}


inline void BitArray::SetAllBitsOn()
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_bitArrayPointer );

	// Set on all the bits of the bytes
	Memory::Operations::Set< UnsignedInteger8bits >( member_bitArrayPointer, member_numberOfBytes, static_cast< UnsignedInteger8bits >( 0xFF ) );
}


inline void BitArray::SetAllBitsOff()
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_bitArrayPointer );

    // Set off all the bits of the bytes
    Memory::Operations::Set< UnsignedInteger8bits >( member_bitArrayPointer, member_numberOfBytes, static_cast< UnsignedInteger8bits >( 0x00 ) );
}


template< template< typename... > class ResultMemoryHandlerType >
inline ResultMemoryHandlerType< LargestUnsignedInteger > BitArray::SearchForAllBitsWithStateOff() const
{
    // Search for all the bits with state off and return the result
    return ( SearchForBitsWithStateOff< ResultMemoryHandlerType >( member_size ) );
}


template< template< typename... > class ResultMemoryHandlerType >
inline ResultMemoryHandlerType< LargestUnsignedInteger > BitArray::SearchForBitsWithStateOff( const LargestUnsignedInteger numberOfBitsToFind ) const
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_bitArrayPointer );
    AssertValueIsInRangeWhenMinimumValueOfTheRangeIsExcluded( numberOfBitsToFind, 0UL, member_size );

    // This object will store the locations of the bits with the state off
    ResultMemoryHandlerType< LargestUnsignedInteger > offsetsToBitsWithStateOff( numberOfBitsToFind );

    // Search for the bits with state off, and store the actual number of them found
    LargestUnsignedInteger numberOfBitsWithStateOffFound = SearchForBitsWithStateOff__Private< ResultMemoryHandlerType< LargestUnsignedInteger >& >( numberOfBitsToFind, offsetsToBitsWithStateOff );

    // Check if the number of bits found is less then the required amount
    if( numberOfBitsWithStateOffFound < numberOfBitsToFind )
    {
        // The number of bits found is less then the required amount

        // Resize the result memory handler to the actual number of bits found
        offsetsToBitsWithStateOff.Remove( numberOfBitsWithStateOffFound, numberOfBitsToFind - numberOfBitsWithStateOffFound );
    }

    // Return the result
    return ( offsetsToBitsWithStateOff );
}


inline LargestUnsignedInteger BitArray::SearchForBitsWithStateOff( const LargestUnsignedInteger numberOfBitsToFind, LargestUnsignedInteger* const storeOffsetToBitsWithStateOffPointer ) const
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_bitArrayPointer );
    AssertValueIsInRangeWhenMinimumValueOfTheRangeIsExcluded( numberOfBitsToFind, 0UL, member_size );
    AssertPointerIsNotNull( storeOffsetToBitsWithStateOffPointer );

    // Search for the bits with state off, and return the actual number of them found
    return ( SearchForBitsWithStateOff__Private< LargestUnsignedInteger* >( numberOfBitsToFind, storeOffsetToBitsWithStateOffPointer ) );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



inline Bit< UnsignedInteger8bits > BitArray::operator[]( const LargestUnsignedInteger index )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
    AssertPointerIsNotNull( member_bitArrayPointer );
	AssertValueIsBelowCertainLimit( index, member_size );
    
    // Return a reference to the required entry
    return ( TakeResourcesAndLeaveInstanceInDefaultState( Bit< UnsignedInteger8bits >( ( member_bitArrayPointer + ( index / 8UL ) ), ( index % 8UL ) ) ) );
}


inline const Bit< UnsignedInteger8bits > BitArray::operator[]( const LargestUnsignedInteger index ) const
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
    AssertPointerIsNotNull( member_bitArrayPointer );
	AssertValueIsBelowCertainLimit( index, member_size );

    // Return a reference to the required entry
    return ( TakeResourcesAndLeaveInstanceInDefaultState( Bit< UnsignedInteger8bits >( ( member_bitArrayPointer + ( index / 8UL ) ), ( index % 8UL ) ) ) );
}


inline Boolean BitArray::operator==( const BitArray& other ) const
{
    CompareInstancesPointers( member_bitArrayPointer, other.member_bitArrayPointer );

    // Compare between the bit arrays, and return the result
    return ( ( GetCopyOfTheLastByteWithTheBitsOffWhichAreOnlyForPadding__Private() == other.GetCopyOfTheLastByteWithTheBitsOffWhichAreOnlyForPadding__Private() ) && Memory::Operations::Compare< UnsignedInteger8bits >( member_bitArrayPointer, other.member_bitArrayPointer, member_numberOfBytes - 1UL ) );
}


inline Boolean BitArray::operator!=( const BitArray& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



template< typename ResultMemoryHandlerType >
inline LargestUnsignedInteger BitArray::SearchForBitsWithStateOff__Private( const LargestUnsignedInteger numberOfBitsToFind, ResultMemoryHandlerType storeOffsetToBitsWithStateOff ) const
{
    // This object will store the number of bits with state off located so far
    LargestUnsignedInteger numberOfBitsWithStateOffFoundSoFar = 0UL;

    // This object will store the offset of the bits for the current byte in the bit array
    LargestUnsignedInteger offsetToBitsInCurrentByte = 0UL;

    // Loop on all the bytes used to store the bit array
    for ( LargestUnsignedInteger byteIndex = 0UL ; byteIndex < member_numberOfBytes - 1UL ; ++byteIndex )
    {
        // This constant reference will store the entry at the lookup table used to optimize the search for bit with state off
        const Vector< UnsignedInteger8bits >& offsetsToBitsWithStateOffInTheByte = member_lookupTableToOptimizeSearchForBitsWithStateOff[ member_bitArrayPointer[ byteIndex ] ];

        // Loop on all the offsets for bits with state off in the current byte
        for ( LargestUnsignedInteger index = 0UL ; index < offsetsToBitsWithStateOffInTheByte.Size() ; ++index )
        {
            // Add the current offset
            storeOffsetToBitsWithStateOff[ numberOfBitsWithStateOffFoundSoFar ] = offsetToBitsInCurrentByte + offsetsToBitsWithStateOffInTheByte[ index ];

            // Increment the number of bits found so far by 1
            numberOfBitsWithStateOffFoundSoFar += 1UL;

            // Check if the number of bits required were located
            if ( numberOfBitsWithStateOffFoundSoFar == numberOfBitsToFind )
            {
                // The number of bits required were located

                // Return that the required amount of bits with state off were located
                return ( numberOfBitsWithStateOffFoundSoFar );
            }
        }

        // Increment the offset of the bits for the current byte in the bit array by 8, to point the first bit of the next byte
        offsetToBitsInCurrentByte += 8UL;
    }

    // This constant reference will store the entry at the lookup table used to optimize the search for bit with state off
    const Vector< UnsignedInteger8bits >& offsetsToBitsWithStateOffInTheLastByte = member_lookupTableToOptimizeSearchForBitsWithStateOff[ GetCopyOfTheLastByteWithTheBitsOnWhichAreOnlyForPadding__Private() ];

    // Loop on all the offsets for bits with state off in the last byte
    for ( LargestUnsignedInteger index = 0UL ; index < offsetsToBitsWithStateOffInTheLastByte.Size() ; ++index )
    {
        // Add the current offset
        storeOffsetToBitsWithStateOff[ numberOfBitsWithStateOffFoundSoFar ] = offsetToBitsInCurrentByte + offsetsToBitsWithStateOffInTheLastByte[ index ];

        // Increment the number of bits found so far by 1
        numberOfBitsWithStateOffFoundSoFar += 1UL;

        // Check if the number of bits required were located
        if ( numberOfBitsWithStateOffFoundSoFar == numberOfBitsToFind )
        {
            // The number of bits required were located

            // Return that the required amount of bits with state off were located
            return ( numberOfBitsWithStateOffFoundSoFar );
        }
    }

    // There were less bits with state off then requested, return the actual number found to the caller
    return ( numberOfBitsWithStateOffFoundSoFar );
}


inline UnsignedInteger8bits BitArray::GetCopyOfTheLastByteWithTheBitsOnWhichAreOnlyForPadding__Private() const
{
    // Set all the bits in the last byte that were added just as padding to meet the 8 bits boundary on
    return ( member_bitArrayPointer[ member_numberOfBytes - 1UL ] | Bits::GetIntegerWithAllMostSignificantBitsOnFromIndexAndAbove< UnsignedInteger8bits >( member_size % 8UL ) );
}


inline UnsignedInteger8bits BitArray::GetCopyOfTheLastByteWithTheBitsOffWhichAreOnlyForPadding__Private() const
{
    // Set all the bits in the last byte that were added just as padding to meet the 8 bits boundary off
    return ( member_bitArrayPointer[ member_numberOfBytes - 1UL ] & Bits::GetIntegerWithAllMostSignificantBitsOffFromIndexAndAbove< UnsignedInteger8bits >( member_size % 8UL ) );
}



}  //  Namespace Memory


}  //  Namespace Universe