//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



template< typename MemoryHandlerButNotVectorType > requires ( CompareRegardlessOfTemplateArguments< MemoryHandlerButNotVectorType, Memory::Vector< LargestUnsignedInteger > >::Result == false )
inline void Loop::Set( MemoryHandlerButNotVectorType& instance, const LargestUnsignedInteger startingIndex, const LargestUnsignedInteger size, const typename MemoryHandlerButNotVectorType::MemoryHandlerButNotVectorType& data )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsLargerThenZero( instance.Size() );
    AssertValueIsLargerThenZero( size );
    AssertValueIsBelowCertainLimit( startingIndex, instance.Size() );
    AssertValueIsEqualOrBelowCertainLimit( size, ( instance.Size() - startingIndex ) );

    // This object will store the index at which the loop should stop
    const LargestUnsignedInteger stopAtThisIndex = startingIndex + size;

    // Loop on all the required entries
    for ( LargestUnsignedInteger index = startingIndex ; index < stopAtThisIndex ; ++index )
    {
        // Set the current entry with the data
        instance[ index ] = data;
    }
}


template< typename VectorType > requires ( CompareRegardlessOfTemplateArguments< VectorType, Memory::Vector< LargestUnsignedInteger > >::Result == true )
inline void Loop::Set( VectorType& instance, const LargestUnsignedInteger startingIndex, const LargestUnsignedInteger size, const typename VectorType::SelfDataType& data )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsLargerThenZero( instance.Size() );
    AssertValueIsLargerThenZero( size );
    AssertValueIsBelowCertainLimit( startingIndex, instance.Size() );
    AssertValueIsEqualOrBelowCertainLimit( size, ( instance.Size() - startingIndex ) );

    // Use the operations set for contiguous memory, as it does the operation of copying much faster
    Memory::Operations::Set< typename VectorType::SelfDataType >( &instance[ startingIndex ], size, data );
}


template< typename DestinationMemoryHandlerButNotVectorType, typename SourceMemoryHandlerButNotVectorType > requires ( CompareRegardlessOfTemplateArguments< DestinationMemoryHandlerButNotVectorType, Memory::Vector< LargestUnsignedInteger > >::Result == false && CompareRegardlessOfTemplateArguments< SourceMemoryHandlerButNotVectorType, Memory::Vector< LargestUnsignedInteger > >::Result == false && CompareTypes< typename DestinationMemoryHandlerButNotVectorType::SelfDataType, typename SourceMemoryHandlerButNotVectorType::SelfDataType >::Result == true )
inline void Loop::Copy( DestinationMemoryHandlerButNotVectorType& destination, const SourceMemoryHandlerButNotVectorType& source, const LargestUnsignedInteger destinationStartingIndex, const LargestUnsignedInteger sourceStartingIndex, const LargestUnsignedInteger size )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsLargerThenZero( destination.Size() );
    AssertValueIsLargerThenZero( source.Size() );
    AssertValueIsLargerThenZero( size );
    AssertValueIsBelowCertainLimit( destinationStartingIndex, destination.Size() );
    AssertValueIsBelowCertainLimit( sourceStartingIndex, source.Size() );
    AssertValueIsEqualOrBelowCertainLimit( size, ( destination.Size() - destinationStartingIndex ) );
    AssertValueIsEqualOrBelowCertainLimit( size, ( source.Size() - sourceStartingIndex ) );

    // This object will store the index on the assignment target
    LargestUnsignedInteger destinationIndex = destinationStartingIndex;

    // This object will store the index on the assignment source
    LargestUnsignedInteger sourceIndex = sourceStartingIndex;

    // This object will store the index at which the loop should stop
    const LargestUnsignedInteger stopAtThisIndex = destinationStartingIndex + size;

    // Loop on all the required entries
    while ( destinationIndex < stopAtThisIndex )
    {
    	// Copy the current entry from the source to the target
    	destination[ destinationIndex ] = source[ sourceIndex ];

    	// Increment the index on the assignment target
    	destinationIndex += 1UL;

    	// Increment the index on the assignment source
    	sourceIndex += 1UL;
    }
}


template< typename DestinationVectorType, typename SourceVectorType > requires ( CompareRegardlessOfTemplateArguments< DestinationVectorType, Memory::Vector< LargestUnsignedInteger > >::Result == true && CompareRegardlessOfTemplateArguments< SourceVectorType, Memory::Vector< LargestUnsignedInteger > >::Result == true && CompareTypes< typename DestinationVectorType::SelfDataType, typename SourceVectorType::SelfDataType >::Result == true )
inline void Loop::Copy( DestinationVectorType& destination, const SourceVectorType& source, const LargestUnsignedInteger destinationStartingIndex, const LargestUnsignedInteger sourceStartingIndex, const LargestUnsignedInteger size )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsLargerThenZero( destination.Size() );
    AssertValueIsLargerThenZero( source.Size() );
    AssertValueIsLargerThenZero( size );
    AssertValueIsBelowCertainLimit( destinationStartingIndex, destination.Size() );
    AssertValueIsBelowCertainLimit( sourceStartingIndex, source.Size() );
    AssertValueIsEqualOrBelowCertainLimit( size, ( destination.Size() - destinationStartingIndex ) );
    AssertValueIsEqualOrBelowCertainLimit( size, ( source.Size() - sourceStartingIndex ) );

    // Use the operations copy for contiguous memory, as it does the operation of copying much faster
    Memory::Operations::Copy< typename DestinationVectorType::SelfDataType >( &destination[ destinationStartingIndex ], &source[ sourceStartingIndex ], size );
}


template< typename DestinationMemoryHandlerButNotVectorType, typename SourceMemoryHandlerButNotVectorType > requires ( CompareRegardlessOfTemplateArguments< DestinationMemoryHandlerButNotVectorType, Memory::Vector< LargestUnsignedInteger > >::Result == false && CompareRegardlessOfTemplateArguments< SourceMemoryHandlerButNotVectorType, Memory::Vector< LargestUnsignedInteger > >::Result == false && CompareTypes< typename DestinationMemoryHandlerButNotVectorType::SelfDataType, typename SourceMemoryHandlerButNotVectorType::SelfDataType >::Result == true )
inline void Loop::Move( DestinationMemoryHandlerButNotVectorType& destination, SourceMemoryHandlerButNotVectorType&& source, const LargestUnsignedInteger destinationStartingIndex, const LargestUnsignedInteger sourceStartingIndex, const LargestUnsignedInteger size )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsLargerThenZero( destination.Size() );
    AssertValueIsLargerThenZero( source.Size() );
    AssertValueIsLargerThenZero( size );
    AssertValueIsBelowCertainLimit( destinationStartingIndex, destination.Size() );
    AssertValueIsBelowCertainLimit( sourceStartingIndex, source.Size() );
    AssertValueIsEqualOrBelowCertainLimit( size, ( destination.Size() - destinationStartingIndex ) );
    AssertValueIsEqualOrBelowCertainLimit( size, ( source.Size() - sourceStartingIndex ) );

    // This object will store the index on the assignment target
    LargestUnsignedInteger destinationIndex = destinationStartingIndex;

    // This object will store the index on the assignment source
    LargestUnsignedInteger sourceIndex = sourceStartingIndex;

    // This object will store the index at which the loop should stop
    const LargestUnsignedInteger stopAtThisIndex = destinationStartingIndex + size;

    // Loop on all the required entries
    while ( destinationIndex < stopAtThisIndex )
    {
        // Move the current entry from the source to the target
        destination[ destinationIndex ] = TakeResourcesAndLeaveInstanceInDefaultState( source[ sourceIndex ] );

        // Increment the index on the assignment target
        destinationIndex += 1UL;

        // Increment the index on the assignment source
        sourceIndex += 1UL;
    }
}


template< typename DestinationVectorType, typename SourceVectorType > requires ( CompareRegardlessOfTemplateArguments< DestinationVectorType, Memory::Vector< LargestUnsignedInteger > >::Result == true && CompareRegardlessOfTemplateArguments< SourceVectorType, Memory::Vector< LargestUnsignedInteger > >::Result == true && CompareTypes< typename DestinationVectorType::SelfDataType, typename SourceVectorType::SelfDataType >::Result == true )
inline void Loop::Move( DestinationVectorType& destination, SourceVectorType&& source, const LargestUnsignedInteger destinationStartingIndex, const LargestUnsignedInteger sourceStartingIndex, const LargestUnsignedInteger size )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsLargerThenZero( destination.Size() );
    AssertValueIsLargerThenZero( source.Size() );
    AssertValueIsLargerThenZero( size );
    AssertValueIsBelowCertainLimit( destinationStartingIndex, destination.Size() );
    AssertValueIsBelowCertainLimit( sourceStartingIndex, source.Size() );
    AssertValueIsEqualOrBelowCertainLimit( size, ( destination.Size() - destinationStartingIndex ) );
    AssertValueIsEqualOrBelowCertainLimit( size, ( source.Size() - sourceStartingIndex ) );

    // Use the operations copy for contiguous memory, as it does the operation of copying much faster
    Memory::Operations::Move< typename DestinationVectorType::SelfDataType >( &destination[ destinationStartingIndex ], &source[ sourceStartingIndex ], size );
}


template< typename FirstMemoryHandlerType, typename SecondMemoryHandlerType > requires ( ( CompareRegardlessOfTemplateArguments< FirstMemoryHandlerType, Memory::Vector< LargestUnsignedInteger > >::Result == false || CompareRegardlessOfTemplateArguments< SecondMemoryHandlerType, Memory::Vector< LargestUnsignedInteger > >::Result == false ) && CompareTypes< typename FirstMemoryHandlerType::SelfDataType, typename SecondMemoryHandlerType::SelfDataType >::Result == true )
inline Boolean Loop::Compare( const FirstMemoryHandlerType& firstInstance, const SecondMemoryHandlerType& secondInstance, const LargestUnsignedInteger firstInstanceStartingIndex, const LargestUnsignedInteger secondInstanceStartingIndex, const LargestUnsignedInteger size )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsLargerThenZero( firstInstance.Size() );
    AssertValueIsLargerThenZero( secondInstance.Size() );
    AssertValueIsLargerThenZero( size );
    AssertValueIsBelowCertainLimit( firstInstanceStartingIndex, firstInstance.Size() );
    AssertValueIsBelowCertainLimit( secondInstanceStartingIndex, secondInstance.Size() );
    AssertValueIsEqualOrBelowCertainLimit( size, ( firstInstance.Size() - firstInstanceStartingIndex ) );
    AssertValueIsEqualOrBelowCertainLimit( size, ( secondInstance.Size() - secondInstanceStartingIndex ) );

    // This object will store the index on the first instance
    LargestUnsignedInteger firstInstanceIndex = firstInstanceStartingIndex;

    // This object will store the index on the second instance
    LargestUnsignedInteger secondInstanceIndex = secondInstanceStartingIndex;

    // This object will store the index at which the loop should stop
    const LargestUnsignedInteger stopAtThisIndex = firstInstanceStartingIndex + size;

    // Loop on all the required entries
    while ( firstInstanceIndex < stopAtThisIndex )
    {
        // Compare the current entries in both instances, and return false if they mismatch
        ReturnValueIfExpressionIsTrue( ( firstInstance[ firstInstanceIndex ] != secondInstance[ secondInstanceIndex ] ), false );

    	// Increment the index on the first instance
    	firstInstanceIndex += 1UL;

    	// Increment the index on the second instance
    	secondInstanceIndex += 1UL;
    }

    // All the entires compared matched, return true
    return ( true );
}


template< typename FirstMemoryHandlerVectorType, typename SecondMemoryHandlerVectorType > requires ( CompareRegardlessOfTemplateArguments< FirstMemoryHandlerVectorType, Memory::Vector< LargestUnsignedInteger > >::Result == true && CompareRegardlessOfTemplateArguments< SecondMemoryHandlerVectorType, Memory::Vector< LargestUnsignedInteger > >::Result == true && CompareTypes< typename FirstMemoryHandlerVectorType::SelfDataType, typename SecondMemoryHandlerVectorType::SelfDataType >::Result == true )
inline Boolean Loop::Compare( const FirstMemoryHandlerVectorType& firstInstance, const SecondMemoryHandlerVectorType& secondInstance, const LargestUnsignedInteger firstInstanceStartingIndex, const LargestUnsignedInteger secondInstanceStartingIndex, const LargestUnsignedInteger size )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsLargerThenZero( firstInstance.Size() );
    AssertValueIsLargerThenZero( secondInstance.Size() );
    AssertValueIsLargerThenZero( size );
    AssertValueIsBelowCertainLimit( firstInstanceStartingIndex, firstInstance.Size() );
    AssertValueIsBelowCertainLimit( secondInstanceStartingIndex, secondInstance.Size() );
    AssertValueIsEqualOrBelowCertainLimit( size, ( firstInstance.Size() - firstInstanceStartingIndex ) );
    AssertValueIsEqualOrBelowCertainLimit( size, ( secondInstance.Size() - secondInstanceStartingIndex ) );

    // Use the operations copy for contiguous memory, as it does the operation of copying much faster
    return ( Memory::Operations::Compare< typename FirstMemoryHandlerVectorType::SelfDataType >( &firstInstance[ firstInstanceStartingIndex ], &secondInstance[ secondInstanceStartingIndex ], size ) );
}



}  //  Namespace Universe