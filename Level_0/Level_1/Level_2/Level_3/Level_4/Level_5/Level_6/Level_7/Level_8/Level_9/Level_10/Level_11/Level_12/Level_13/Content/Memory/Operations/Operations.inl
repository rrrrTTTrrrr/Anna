//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



template< Concepts::Movable Type >
inline void Operations::Swap( Type& firstInstance, Type& secondInstance )
{
    // Craete a temporary instance of the template type and move the content of the first instance to the temporary
    Type firstInstanceCopy( TakeResourcesAndLeaveInstanceInDefaultState( firstInstance ) );

    // Move the content of the second instance to the first one
    firstInstance = TakeResourcesAndLeaveInstanceInDefaultState( secondInstance );

    // Move the content of the temporary instance to the second instance
    secondInstance = TakeResourcesAndLeaveInstanceInDefaultState( firstInstanceCopy );
}


template< Concepts::Movable Type >
inline void Operations::Swap( Type* const firstMemoryAddress, Type* const secondMemoryAddress, UnsignedInteger64bits size )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid
    AssertPointerIsNotNull( firstMemoryAddress );
    AssertPointerIsNotNull( secondMemoryAddress );
    Assert( ( firstMemoryAddress != secondMemoryAddress ), "The pointers point to the same memory address" );
    AssertValueIsLargerThenZero( size );

    // This object will store the number of single bytes that needs to be swapped
    UnsignedInteger8bits numberOfBytesToSwapOneByOne = ( size * sizeof( Type ) ) % 8;

    // This object will store the number of eight bytes blocks needs to be swapped
    UnsignedInteger64bits numberOfEightBytesBlocksToSwap = ( ( size * sizeof( Type ) ) / 8 );

    // Check if the first array address is higher then the second array address, they will ensure correct swapping even for overlapping memory segments
    if ( firstMemoryAddress > secondMemoryAddress )
    {
        // The first memory address is higher then the second one

        // This object will be used to point to the first memory segment as single bytes
        UnsignedInteger8bits* firstMemoryAddressPointedAsSingleByte = reinterpret_cast< UnsignedInteger8bits* >( firstMemoryAddress );

        // This object will be used to point to destination as blocks of 8 bytes
        UnsignedInteger8bits* secondMemoryAddressPointedAsSingleByte = reinterpret_cast< UnsignedInteger8bits* >( secondMemoryAddress );

        // Loop on until there is no more single elements to swap
        for ( UnsignedInteger8bits currentSingleEntryIndex = 0UL ; currentSingleEntryIndex < numberOfBytesToSwapOneByOne ; ++currentSingleEntryIndex )
        {
            // Copy the current element
			Swap< UnsignedInteger8bits >( firstMemoryAddressPointedAsSingleByte[ currentSingleEntryIndex ], secondMemoryAddressPointedAsSingleByte[ currentSingleEntryIndex ] );
        }

        // This object will be used to point to the first memory segment as blocks of 8 bytes
        UnsignedInteger64bits* firstMemoryAddressPointedAsEightBytesBlock = reinterpret_cast< UnsignedInteger64bits* >( reinterpret_cast< UnsignedInteger8bits* >( firstMemoryAddress ) + numberOfBytesToSwapOneByOne );

        // This object will be used to point to second array as blocks of 8 bytes
        UnsignedInteger64bits* secondMemoryAddressPointedAsEightBytesBlock = reinterpret_cast< UnsignedInteger64bits* >( reinterpret_cast< UnsignedInteger8bits* >( secondMemoryAddress ) + numberOfBytesToSwapOneByOne );

        // Loop on until there is no more 8 bytes blocks to swap
        for ( UnsignedInteger64bits currentEightBytesBlockIndex = 0 ; currentEightBytesBlockIndex < numberOfEightBytesBlocksToSwap ; ++currentEightBytesBlockIndex )
        {
            // Copy the current 8 bytes block
			Swap< UnsignedInteger64bits >( firstMemoryAddressPointedAsEightBytesBlock[ currentEightBytesBlockIndex ], secondMemoryAddressPointedAsEightBytesBlock[ currentEightBytesBlockIndex ] );
        }
    }
    else
    {
        // The first memory address is lower then the second one

    	if ( numberOfEightBytesBlocksToSwap > 0UL )
    	{
            // This object will be used to point to the first memory address as blocks of 8 bytes
            UnsignedInteger64bits* firstMemoryAddressPointedAsEightBytesBlock = ( reinterpret_cast< UnsignedInteger64bits* >( reinterpret_cast< UnsignedInteger8bits* >( firstMemoryAddress ) + numberOfBytesToSwapOneByOne ) + ( numberOfEightBytesBlocksToSwap - 1UL ) );

            // This object will be used to point to second memory address as single bytes
            UnsignedInteger64bits* secondMemoryAddressPointedAsEightBytesBlock = ( reinterpret_cast< UnsignedInteger64bits* >( reinterpret_cast< UnsignedInteger8bits* >( secondMemoryAddress ) + numberOfBytesToSwapOneByOne ) + ( numberOfEightBytesBlocksToSwap - 1UL ) );

            // Loop on until there is no more 8 bytes blocks to swap
            for ( UnsignedInteger64bits numberOfEightBytesBlockSwapped = 0UL ; numberOfEightBytesBlockSwapped < numberOfEightBytesBlocksToSwap ; ++numberOfEightBytesBlockSwapped )
            {
                // Swap the current 8 bytes block
				Swap< UnsignedInteger64bits >( *firstMemoryAddressPointedAsEightBytesBlock, *secondMemoryAddressPointedAsEightBytesBlock );

                // Advance the pointer on the first segment to the next 8 bytes block
                firstMemoryAddressPointedAsEightBytesBlock -= 1UL;

                // Advance the pointer on the second segment to the next 8 bytes block
                secondMemoryAddressPointedAsEightBytesBlock -= 1UL;
            }
        }

        if ( numberOfBytesToSwapOneByOne > 0UL )
        {
            // This object will be used to point to the first memory segment as single bytes
            UnsignedInteger8bits* firstMemoryAddressPointedAsSingleByte = reinterpret_cast< UnsignedInteger8bits* >( firstMemoryAddress ) + ( numberOfBytesToSwapOneByOne - 1UL );

            // This object will be used to point to second memory address as single bytes
            UnsignedInteger8bits* secondMemoryAddressPointedAsSingleByte = reinterpret_cast< UnsignedInteger8bits* >( secondMemoryAddress ) + ( numberOfBytesToSwapOneByOne - 1UL );

            // Loop on until there is no more single bytes to swap
            for ( UnsignedInteger8bits numberOfSingleBytesSwapped = 0UL ; numberOfSingleBytesSwapped < numberOfBytesToSwapOneByOne ; ++numberOfSingleBytesSwapped )
            {
                // Swap the current byte
				Swap< UnsignedInteger8bits >( *firstMemoryAddressPointedAsSingleByte, *secondMemoryAddressPointedAsSingleByte );
            
                // Advance the pointer on the first segment to the previous byte
                firstMemoryAddressPointedAsSingleByte -= 1UL;

                // Advance the pointer on the second segment to the previous byte
                secondMemoryAddressPointedAsSingleByte -= 1UL;
            }
        }
    }
}


template< Concepts::BuiltIn BuiltInType >
inline void Operations::Copy( const BuiltInType* const source, BuiltInType* const destination, UnsignedInteger64bits size )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid
    AssertPointerIsNotNull( source );
    AssertPointerIsNotNull( destination );
    Assert( ( source != destination ), "The source and destination pointers point to same memory address" );
    AssertValueIsLargerThenZero( size );

    // This object will store the number of entries that will be compared one by one
    UnsignedInteger8bits numberOfEntriesToCopyOneByOne = ( ( ( size * sizeof( BuiltInType ) ) % 8 ) / sizeof( BuiltInType ) );

    // This object will store the number of eight bytes blocks needs to be copied
    UnsignedInteger64bits numberOfEightBytesBlocksToCopy = ( ( size * sizeof( BuiltInType ) ) / 8 );

    // Check if the source address is higher then the destination address, they will ensure correct copying even for overlapping memory segments
    if ( source > destination )
    {
        // The source address is higher then the destination

        // Loop on until there is no more single elements to copy
        for ( UnsignedInteger8bits currentSingleEntryIndex = 0UL ; currentSingleEntryIndex < numberOfEntriesToCopyOneByOne ; ++currentSingleEntryIndex )
        {
            // Copy the current element
            destination[ currentSingleEntryIndex ] = source[ currentSingleEntryIndex ];
        }

        // This object will be used to point to the first memory segment as blocks of 8 bytes
        const UnsignedInteger64bits* sourceEightBytesBlock = reinterpret_cast< const UnsignedInteger64bits* >( source + numberOfEntriesToCopyOneByOne );

        // This object will be used to point to destination as blocks of 8 bytes
        UnsignedInteger64bits* destinationEightBytesBlock = reinterpret_cast< UnsignedInteger64bits* >( destination + numberOfEntriesToCopyOneByOne );

        // Loop on until there is no more 8 bytes blocks to copy
        for ( UnsignedInteger64bits currentEightBytesBlockIndex = 0 ; currentEightBytesBlockIndex < numberOfEightBytesBlocksToCopy ; ++currentEightBytesBlockIndex )
        {
            // Copy the current 8 bytes block
            destinationEightBytesBlock[ currentEightBytesBlockIndex ] = sourceEightBytesBlock[ currentEightBytesBlockIndex ];
        }
    }
    else
    {
        // The source address is lower then the destination

        // Check if the size of the eight blocks to copy is not 0
        if ( numberOfEightBytesBlocksToCopy > 0U )
        {
            // This object will be used to point to the first memory segment as blocks of 8 bytes
            const UnsignedInteger64bits* sourceEightBytesBlock = ( reinterpret_cast< const UnsignedInteger64bits* >( source + numberOfEntriesToCopyOneByOne ) + ( numberOfEightBytesBlocksToCopy - 1UL ) );

            // This object will be used to point to destination as blocks of 8 bytes
            UnsignedInteger64bits* destinationEightBytesBlock = ( reinterpret_cast< UnsignedInteger64bits* >( destination + numberOfEntriesToCopyOneByOne ) + ( numberOfEightBytesBlocksToCopy - 1UL ) );

            // Loop on until there is no more 8 bytes blocks to copy
            for ( UnsignedInteger64bits numberOfEightBytesBlocksCopied = 0UL ; numberOfEightBytesBlocksCopied < numberOfEightBytesBlocksToCopy ; ++numberOfEightBytesBlocksCopied )
            {
                // Copy the current 8 bytes block
                *destinationEightBytesBlock = *sourceEightBytesBlock;

                // Advance the pointer on the first segment to the next 8 bytes block
                sourceEightBytesBlock -= 1UL;

                // Advance the pointer on the second segment to the next 8 bytes block
                destinationEightBytesBlock -= 1UL;
            }
        }

        // Check if the size of the entries to copy one by one is not 0
        if ( numberOfEntriesToCopyOneByOne > 0U )
        {
            // Loop on until there is only one element left ( the first ) the copy
            for ( UnsignedInteger8bits currentSingleEntryIndex = ( numberOfEntriesToCopyOneByOne - 1 ) ; currentSingleEntryIndex > 0UL ; --currentSingleEntryIndex )
            {
                // Copy the current element
                destination[ currentSingleEntryIndex ] = source[ currentSingleEntryIndex ];
            }

            // Copy the first element
            destination[0] = source[0];
        }
    }
}


template< Concepts::NotBuiltIn NotBuiltInType >
inline void Operations::Copy( const NotBuiltInType* const source, NotBuiltInType* const destination, UnsignedInteger64bits size )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid
    AssertPointerIsNotNull( source );
    AssertPointerIsNotNull( destination );
    Assert( ( source != destination ), "The source and destination pointers point to same memory address" );
    AssertValueIsLargerThenZero( size );
    
    // Check if the source address is higher then the destination address, they will ensure correct copying even for overlapping memory segments
    if ( source > destination )
    {
        // The source address is higher then the destination

        // Loop on all the elements
        for ( UnsignedInteger64bits index = 0UL ; index < size ; ++index )
        {
            // Copy the current element
            destination[ index ] = source[ index ];
        }
    }
    else
    {
        // The source address is lower then the destination

        // Loop on all the elements
        for ( UnsignedInteger64bits index = ( size - 1UL ) ; index > 0UL ; --index )
        {
            // Copy the current element
            destination[ index ] = source[ index ];
        }

        // Only the first element is now left to be copied
        destination[0] = source[0];
    }
}


template< Concepts::Movable Type >
inline void Operations::Move( Type* const source, Type* const destination, UnsignedInteger64bits size )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid
    AssertPointerIsNotNull( source );
    AssertPointerIsNotNull( destination );
    Assert( ( source != destination ), "The source and destination pointers point to same memory address" );
    AssertValueIsLargerThenZero( size );

    // Check if the type is a built in, which means it does not need to be left in default state after the moving, and should be just copied
    if constexpr ( IsBuiltIn< Type >::Result == true )
    {
    	// This is a built in type

    	// Copy then it is!
    	Copy< Type >( source, destination, size );

    	// Nothing else needs to be done
    	return;
    }

    // This is not a built in type
    
    // Check if the source address is higher then the destination address, they will ensure correct moving even for overlapping memory segments
    if ( source > destination )
    {
        // The source address is higher then the destination

        // Loop on all the elements
        for ( UnsignedInteger64bits index = 0UL ; index < size ; ++index )
        {
            // Move the current element
            destination[ index ] = TakeResourcesAndLeaveInstanceInDefaultState( source[ index ] );
        }
    }
    else
    {
        // The source address is lower then the destination

        // Loop on all the elements
        for ( UnsignedInteger64bits index = ( size - 1UL ) ; index > 0UL ; --index )
        {
            // Move the current element
            destination[ index ] = TakeResourcesAndLeaveInstanceInDefaultState( source[ index ] );
        }

        // Only the first element is now left to be moved
        destination[0] = TakeResourcesAndLeaveInstanceInDefaultState( source[0] );
    }
}


template< Concepts::BuiltInAndSizeLessThanEightBytes BuiltInAndSizeLessThanEightBytesType >
inline void Operations::Set( BuiltInAndSizeLessThanEightBytesType* const memoryAddress, UnsignedInteger64bits size, BuiltInAndSizeLessThanEightBytesType valueToSet )
{
    // Get the number of elements left to set, after the copying of all the 8 byte groups was done
    UnsignedInteger8bits numberOfSingleElementsToSet = ( ( ( size * sizeof( BuiltInAndSizeLessThanEightBytesType ) ) % 8 ) / sizeof( BuiltInAndSizeLessThanEightBytesType ) );

    // Loop on the single elements left to set
    for ( UnsignedInteger8bits singleElementsToSetIndex = 0 ; singleElementsToSetIndex < numberOfSingleElementsToSet ; ++singleElementsToSetIndex )
    {
        // Set the current element to the required value
        memoryAddress[ singleElementsToSetIndex ] = valueToSet;
    }

    // Store the 8 byte form of the current type and value
    UnsignedInteger64bits eightBytesRepresentationOfValue = DuplicateValueToFillEightBytes__Private< BuiltInAndSizeLessThanEightBytesType >( valueToSet );

      // Get the number of times the memory segment size divides by 8
      UnsignedInteger64bits numberOfEightByteGroupsToSet = ( ( size * sizeof( BuiltInAndSizeLessThanEightBytesType ) ) / 8 );

    // Create a pointer instance to point to the memory segment in terms of 8 bytes group starting behind the single elements to set
    UnsignedInteger64bits* pointToMemoryAddressInEightBytesGroups = reinterpret_cast< UnsignedInteger64bits* >( memoryAddress + numberOfSingleElementsToSet );

    // Loop on all the entries
    for ( UnsignedInteger64bits eightBytesGroupIndex = 0 ; eightBytesGroupIndex < numberOfEightByteGroupsToSet ; ++eightBytesGroupIndex )
    {
        // Set the current 8 byte group to the required value
        pointToMemoryAddressInEightBytesGroups[ eightBytesGroupIndex ] = eightBytesRepresentationOfValue;
    }
}


template< Concepts::NotBuiltInOrBuiltInAndSizeOfEightBytes NotBuiltInOrBuiltInAndSizeOfEightBytesType >
inline void Operations::Set( NotBuiltInOrBuiltInAndSizeOfEightBytesType* const memoryAddress, UnsignedInteger64bits size, const NotBuiltInOrBuiltInAndSizeOfEightBytesType& instanceToSet )
{
    // Loop on all the elements that needs to be set in the memory address
    for ( UnsignedInteger64bits index = 0 ; index < size ; ++index )
    {
        // Set the current element
        memoryAddress[ index ] = instanceToSet;
    }
}


template< Concepts::BuiltIn BuiltInType >
inline Boolean Operations::Compare( const BuiltInType* const firstMemoryAddress, const BuiltInType* const secondMemoryAddress, UnsignedInteger64bits size )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid
    AssertPointerIsNotNull( firstMemoryAddress );
    AssertPointerIsNotNull( secondMemoryAddress );
    Assert( ( firstMemoryAddress != secondMemoryAddress ), "The two pointers point to same memory address" );
    AssertValueIsLargerThenZero( size );

    // This object will store the number of entries that will be compared one by one
    UnsignedInteger8bits numberOfEntriesToCompareOneByOne = ( ( ( size * sizeof( BuiltInType ) ) % 8 ) / sizeof( BuiltInType ) );

    // Loop on until there is no more single elements to compare
    for ( UnsignedInteger8bits currentSingleEntryIndex = 0 ; currentSingleEntryIndex < numberOfEntriesToCompareOneByOne ; ++currentSingleEntryIndex )
    {
        // Compare current byte in both both memory segments, and if they mismatch return false 
        ReturnValueIfExpressionIsTrue( ( firstMemoryAddress[ currentSingleEntryIndex ] != secondMemoryAddress[ currentSingleEntryIndex ] ), false );
    }

    // This object will be used to point to the first memory segment as blocks of 8 bytes
    const UnsignedInteger64bits* pointToFirstMemoryAddressAsGroupsOfEightBytes = reinterpret_cast< const UnsignedInteger64bits* >( firstMemoryAddress + numberOfEntriesToCompareOneByOne );

    // This object will be used to point to second memory address as blocks of 8 bytes
    const UnsignedInteger64bits* pointToSecondMemoryAddressAsGroupsOfEightBytes = reinterpret_cast< const UnsignedInteger64bits* >( secondMemoryAddress + numberOfEntriesToCompareOneByOne );

    // This object will store the number of eight bytes blocks needs to be compared
    UnsignedInteger64bits numberOfEightBytesBlocksToCompare = ( ( size * sizeof( BuiltInType ) ) / 8 );

    // Loop on until there is no more 8 bytes blocks to compare
    for ( UnsignedInteger64bits currentEightBytesBlockIndex = 0 ; currentEightBytesBlockIndex < numberOfEightBytesBlocksToCompare ; ++currentEightBytesBlockIndex )
    {
        // Compare current 8 bytes block in both memory segments, and if they mismatch return false
        ReturnValueIfExpressionIsTrue( ( pointToFirstMemoryAddressAsGroupsOfEightBytes[ currentEightBytesBlockIndex ] != pointToSecondMemoryAddressAsGroupsOfEightBytes[ currentEightBytesBlockIndex ] ), false );
    }

    // If control reached here the arrays match
    return ( true );
}


template< Concepts::NotBuiltIn NotBuiltInType >
inline Boolean Operations::Compare( const NotBuiltInType* const firstMemoryAddress, const NotBuiltInType* const secondMemoryAddress, UnsignedInteger64bits size )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid
    AssertPointerIsNotNull( firstMemoryAddress );
    AssertPointerIsNotNull( secondMemoryAddress );
    Assert( ( firstMemoryAddress != secondMemoryAddress ), "The two pointers point to same memory address" );
    AssertValueIsLargerThenZero( size );

    // Loop on all the elements
    for ( UnsignedInteger64bits currentEntryIndex = 0 ; currentEntryIndex < size ; ++currentEntryIndex )
    {
        // Compare current entry in both both memory segments, and if they mismatch return false 
        ReturnValueIfExpressionIsTrue( ( firstMemoryAddress[ currentEntryIndex ] != secondMemoryAddress[ currentEntryIndex ] ), false );
    }

    // If control reached here the memory segments match
    return ( true );
}


template< Concepts::BuiltIn BuiltInType >
inline void Operations::Reverse( BuiltInType* const memoryAddress, UnsignedInteger64bits size )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid
    AssertPointerIsNotNull( memoryAddress );
    AssertValueIsLargerThenZero( size );

    // Loop until the middle of the given segment. This operation works for even and non even segment sizes becuase if the given size is non 
    // even the middle byte is already at the correct location
    for ( UnsignedInteger64bits currentEntryIndex = 0 ; currentEntryIndex < ( size / 2 ) ; ++currentEntryIndex )
    {
        // Swap between the entries from the opposite sides
        Swap< BuiltInType >( memoryAddress[ currentEntryIndex ], memoryAddress[ size - currentEntryIndex - 1 ] );
    }
}


template< Concepts::NotBuiltIn NotBuiltInType >
inline void Operations::Reverse( NotBuiltInType* const memoryAddress, UnsignedInteger64bits size )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid
    AssertPointerIsNotNull( memoryAddress );
    AssertValueIsLargerThenZero( size );

    // Loop until the middle of the given segment. This operation works for even and non even segment sizes becuase if the given size is non 
    // even the middle byte is already at the correct location
    for ( UnsignedInteger64bits currentEntryIndex = 0 ; currentEntryIndex < ( size / 2 ) ; ++currentEntryIndex )
    {
        // Swap between the entries from the opposite sides
        Swap< NotBuiltInType >( memoryAddress[ currentEntryIndex ], memoryAddress[ size - currentEntryIndex - 1 ] );
    }
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



template< Concepts::BuiltIn BuiltInType >
inline UnsignedInteger64bits Operations::DuplicateValueToFillEightBytes__Private( const BuiltInType value )
{
    // This object will store the 8 bytes block
    UnsignedInteger64bits eightBytesRepresentation = 0UL;

    // This object will store the number of times the value will fit in eight bytes
    UnsignedInteger64bits numberOfTimesValueNeedsToBeCopiedToFillEightBytes = 8UL / sizeof( BuiltInType );

    // Loop on all the places that needs to be set
    for ( UnsignedInteger64bits numberOfTimesValueWasCopied = 0UL ; numberOfTimesValueWasCopied < numberOfTimesValueNeedsToBeCopiedToFillEightBytes ; ++numberOfTimesValueWasCopied )
    {
        // Set the next bytes with the value
        *( reinterpret_cast< BuiltInType* >( &eightBytesRepresentation ) + numberOfTimesValueWasCopied ) = value;
    }

    // Return the eight bytes form of the built in type value
    return ( eightBytesRepresentation );
}



}  //  Namespace Memory


}  //  Namespace Universe