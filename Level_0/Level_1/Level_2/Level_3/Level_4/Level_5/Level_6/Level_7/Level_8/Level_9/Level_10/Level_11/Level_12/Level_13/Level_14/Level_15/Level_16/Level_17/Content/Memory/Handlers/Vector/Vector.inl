//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline Vector< DataType, MemoryManagerType >::Vector() :
	member_vectorPointer( nullptr ),
	member_size( 0UL )
{}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline Vector< DataType, MemoryManagerType >::Vector( const LargestUnsignedInteger size, const DataType& data ) :
    SelfType()
{
    // Allocate the required memory space and initialize it with the given data
    InsertMultipleTimesTheSameElement( 0UL, size, data );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< template< typename, typename > class OtherMemoryHandlerType, typename OtherMemoryHandlerMemoryManagerType >
inline Vector< DataType, MemoryManagerType >::Vector( const OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >& other, const LargestUnsignedInteger startingIndexOnOtherInstance, const LargestUnsignedInteger sizeFromOther ) :
    SelfType()
{
    // Insert the required data into this instance
    InsertElementsFromOtherInstance< OtherMemoryHandlerType >( other, 0UL, startingIndexOnOtherInstance, sizeFromOther );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< template< typename, typename > class OtherMemoryHandlerType, typename OtherMemoryHandlerMemoryManagerType >
inline Vector< DataType, MemoryManagerType >::Vector( OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >&& other, const LargestUnsignedInteger startingIndexOnOtherInstance, const LargestUnsignedInteger sizeFromOther ) :
    SelfType()
{
    // Insert the required data into this instance
    InsertElementsFromOtherInstance< OtherMemoryHandlerType >( TakeResourcesAndLeaveInstanceInDefaultState( other ), 0UL, startingIndexOnOtherInstance, sizeFromOther );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline Vector< DataType, MemoryManagerType >::Vector( const SelfType& other ) :
    SelfType()
{
    // Check if the other instance is empty
    if ( other.Size() > 0UL )
    {
        // The other instance is not empty

        // Insert the data from the other instance to this instance
        InsertElementsFromOtherInstance< Vector >( other, 0UL, 0UL, other.Size() );
    }
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline Vector< DataType, MemoryManagerType >::~Vector()
{
    // Check if the object is in default state, then noting needs to be done
    ReturnIfExpressionIsTrue( member_vectorPointer == nullptr );
        
    // Delete the memory space allocated for the array
    MainMemoryManager::template Done< DataType >( member_vectorPointer, ( member_size > 1UL ? false : true ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline LargestUnsignedInteger Vector< DataType, MemoryManagerType >::SizeInBytes() const
{
    // Multiply the size of the instance by the size in bytes of the data type, and return the result
    return ( member_size * sizeof( DataType ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline LargestUnsignedInteger Vector< DataType, MemoryManagerType >::DataTypeSizeInBytes() const
{
    // Return the size in bytes of the data type
    return ( sizeof( DataType ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename UniversalReferenceDataType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceDataType, DataType >::Result == true )
inline void Vector< DataType, MemoryManagerType >::InsertSingleElement( const LargestUnsignedInteger addTheDataAtThisIndex, UniversalReferenceDataType&& dataToAdd )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsEqualOrBelowCertainLimit( addTheDataAtThisIndex, member_size );

    // Allocate a larger array to contain the additional data, and move the existing data into it
    AllocateLargerMemorySpaceAndCopyTheCurrentDataToTheNewLocation__Private( addTheDataAtThisIndex, 1UL );

    // Set the entry with the new data
    member_vectorPointer[ addTheDataAtThisIndex ] = ForwardUniversalReference< UniversalReferenceDataType >( dataToAdd );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename... AnyArgumentNeededToConstructDataInstanceTypes >
inline void Vector< DataType, MemoryManagerType >::InsertSingleElementCreateFromArguments( const LargestUnsignedInteger addTheDataAtThisIndex, AnyArgumentNeededToConstructDataInstanceTypes&&... anyArgumentNeededToConstructDataIstance )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsEqualOrBelowCertainLimit( addTheDataAtThisIndex, member_size );

    // Allocate a larger array to contain the additional data, and move the existing data into it
    AllocateLargerMemorySpaceAndCopyTheCurrentDataToTheNewLocation__Private( addTheDataAtThisIndex, 1UL );

    // Set the entry with the new data
    member_vectorPointer[ addTheDataAtThisIndex ] = TakeResourcesAndLeaveInstanceInDefaultState( DataType( ForwardUniversalReference< AnyArgumentNeededToConstructDataInstanceTypes >( anyArgumentNeededToConstructDataIstance )... ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void Vector< DataType, MemoryManagerType >::InsertMultipleTimesTheSameElement( const LargestUnsignedInteger addTheDataAtThisIndex, const LargestUnsignedInteger sizeToAdd, const DataType& data )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsEqualOrBelowCertainLimit( addTheDataAtThisIndex, member_size );

    // Allocate a larger array to contain the additional data, and move the existing data into it
    AllocateLargerMemorySpaceAndCopyTheCurrentDataToTheNewLocation__Private( addTheDataAtThisIndex, sizeToAdd );

    // This object will store the index at which the loop should stop
    const LargestUnsignedInteger stopAtThisIndex = addTheDataAtThisIndex + sizeToAdd;

    // Loop on the required entries and assign the data from the other instance into this instance
    for ( LargestUnsignedInteger index = addTheDataAtThisIndex ; index < stopAtThisIndex ; ++index )
    {
        // Copy the value from the other instance to this instance
        member_vectorPointer[ index ] = data;
    }
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< template< typename, typename > class OtherMemoryHandlerType, typename OtherMemoryHandlerMemoryManagerType >
inline void Vector< DataType, MemoryManagerType >::InsertElementsFromOtherInstance( const OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >& other, LargestUnsignedInteger firstIndexInThisInstance, LargestUnsignedInteger firstIndexOnOtherInstance, LargestUnsignedInteger sizeToAdd )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsLargerThenZero( other.Size() );
    AssertValueIsEqualOrBelowCertainLimit( firstIndexInThisInstance, member_size );
    AssertValueIsEqualOrBelowCertainLimit( firstIndexOnOtherInstance, other.Size() );
    AssertValueIsEqualOrBelowCertainLimit( sizeToAdd, ( other.Size() - firstIndexOnOtherInstance ) );

    // Allocate a larger array to contain the additional data, and move the existing data into it
    AllocateLargerMemorySpaceAndCopyTheCurrentDataToTheNewLocation__Private( firstIndexInThisInstance, sizeToAdd );

    // Copy the data from the other instance to the new allocated memory space in this instance
    CopyDataFromOtherInstanceToThisInstance__Private< OtherMemoryHandlerType, OtherMemoryHandlerMemoryManagerType >( other, firstIndexInThisInstance, firstIndexOnOtherInstance, sizeToAdd );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< template< typename, typename > class OtherMemoryHandlerType, typename OtherMemoryHandlerMemoryManagerType >
inline void Vector< DataType, MemoryManagerType >::InsertElementsFromOtherInstance( OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >&& other, const LargestUnsignedInteger firstIndexInThisInstance, const LargestUnsignedInteger firstIndexOnOtherInstance, const LargestUnsignedInteger sizeToAdd )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsLargerThenZero( other.Size() );
    AssertValueIsEqualOrBelowCertainLimit( firstIndexInThisInstance, member_size );
    AssertValueIsEqualOrBelowCertainLimit( firstIndexOnOtherInstance, other.Size() );
    AssertValueIsEqualOrBelowCertainLimit( sizeToAdd, ( other.Size() - firstIndexOnOtherInstance ) );

    // Allocate a larger array to contain the additional data, and move the existing data into it
    AllocateLargerMemorySpaceAndCopyTheCurrentDataToTheNewLocation__Private( firstIndexInThisInstance, sizeToAdd );

    // Copy the data from the other instance to the new allocated memory space in this instance
    CopyDataFromOtherInstanceToThisInstance__Private< OtherMemoryHandlerType, OtherMemoryHandlerMemoryManagerType >( TakeResourcesAndLeaveInstanceInDefaultState( other ), firstIndexInThisInstance, firstIndexOnOtherInstance, sizeToAdd );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void Vector< DataType, MemoryManagerType >::InsertElementsFromRawData( const DataType* const dataPointer, const LargestUnsignedInteger addTheDataAtThisIndex, const LargestUnsignedInteger dataSize )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( dataPointer );
    AssertValueIsEqualOrBelowCertainLimit( addTheDataAtThisIndex, member_size );
    AssertValueIsLargerThenZero( dataSize );

    // Allocate a larger array to contain the additional data, and move the existing data into it
    AllocateLargerMemorySpaceAndCopyTheCurrentDataToTheNewLocation__Private( addTheDataAtThisIndex, dataSize );

    // Copy the data into the new allocated memory space
    Memory::Operations::Copy< DataType >( dataPointer, member_vectorPointer, dataSize );
}    


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void Vector< DataType, MemoryManagerType >::Remove( const LargestUnsignedInteger indexOfFirstDataToRemove, const LargestUnsignedInteger sizeToRemove )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsLargerThenZero( sizeToRemove );
    AssertSumOfTheValuesIsEqualOrBelowCertainLimit( indexOfFirstDataToRemove, sizeToRemove, member_size );

    // Check if the size of the current instance is the same as the size that should be removed
    if ( member_size == sizeToRemove )
    {
    	// The current size is the same as the size that needs to be removed

    	// Reset the instance
    	Reset();

    	// Nothing else needs to be done
    	return;
    }

    // Allocate a smaller array to contain the additional data
    Vector< DataType, MemoryManagerType > smallerTemporaryInstanceToStoreTheArrayWithoutTheRemovedData( member_size - sizeToRemove );

    // Now there are 3 options, the first one is that the new data needs to be removed from the beginning of the array, which means that all the 
    // curren data needs to be copied one index down in the new array. The second is that the new data needs to be removed from the end of the array
    // which means that the current data needs to be copied to the same location just minus the last entry. And finally the new data needs to be 
    // removed from the middle, which means that the start of the current data up to the location to remove the data, needs to be copied to the
    // same location, and all the data from there needs be copied one index down, to clear the uneeded entry

    // Check if the data needs to be removed from the beginning of the array
    if ( indexOfFirstDataToRemove == 0UL )
    {
    	// The data needs to be removed from the beginning

    	// Move the data from the current instance, starting from the required index, to the temporary instance starting from the beginning
        // of it
    	Memory::Operations::Move< DataType >( ( member_vectorPointer + sizeToRemove ), smallerTemporaryInstanceToStoreTheArrayWithoutTheRemovedData.member_vectorPointer, ( member_size - sizeToRemove ) );
    }
    else if ( ( indexOfFirstDataToRemove + sizeToRemove ) == member_size )
    {
    	// The data needs to be removed from the end

        // Move the data from the current instance, starting from the beginning until the required index, to the temporary instance starting
        // from the beginning of it
    	Memory::Operations::Move< DataType >( member_vectorPointer, smallerTemporaryInstanceToStoreTheArrayWithoutTheRemovedData.member_vectorPointer, ( member_size - sizeToRemove ) );
    }
    else
    {
    	// The data needs to be removed from the middle of the array

        // Move the data from the current instance, starting from the beginning until the required index, to the temporary instance starting
        // from the beginning of it
    	Memory::Operations::Move< DataType >( member_vectorPointer, smallerTemporaryInstanceToStoreTheArrayWithoutTheRemovedData.member_vectorPointer, indexOfFirstDataToRemove );

    	// Copy all the entries in the current data after the required index after to one index down into the new array 
    	Memory::Operations::Move< DataType >( ( member_vectorPointer + ( indexOfFirstDataToRemove + sizeToRemove ) ), ( smallerTemporaryInstanceToStoreTheArrayWithoutTheRemovedData.member_vectorPointer + indexOfFirstDataToRemove ), ( member_size - indexOfFirstDataToRemove - sizeToRemove ) );
    }

    // Swap between this instance and the temporary that stores the data without the removed entries
    Swap( smallerTemporaryInstanceToStoreTheArrayWithoutTheRemovedData );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline Boolean Vector< DataType, MemoryManagerType >::operator==( const SelfType& other ) const
{
    // Check if the instances are ready
    ReturnValueIfExpressionIsTrue( ( ( other.member_vectorPointer == nullptr ) && ( member_vectorPointer == nullptr ) ), true );
    ReturnValueIfExpressionIsTrue( ( ( member_vectorPointer != other.member_vectorPointer ) && ( ( member_vectorPointer == nullptr ) || ( other.member_vectorPointer == nullptr ) ) ), false );

	// Check if the instances match, and return the result
	return ( ( member_size == other.member_size ) && Memory::Operations::Compare< DataType >( member_vectorPointer, other.member_vectorPointer, member_size ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline Boolean Vector< DataType, MemoryManagerType >::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline DataType& Vector< DataType, MemoryManagerType >::operator[]( const LargestUnsignedInteger index )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsBelowCertainLimit( index, member_size );
    
    // Return a reference to the required entry
    return ( member_vectorPointer[ index ] );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline const DataType& Vector< DataType, MemoryManagerType >::operator[]( const LargestUnsignedInteger index ) const
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsBelowCertainLimit( index, member_size );
    
    // Return a reference to the required entry
    return ( member_vectorPointer[ index ] );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline Vector< DataType, MemoryManagerType >& Vector< DataType, MemoryManagerType >::operator+=( const SelfType& other )
{
    // Add the data to the end of the instance
    InsertElementsFromOtherInstance< Vector >( other, member_size, 0UL, other.Size() );

    // Return a reference to this instance
    return ( *this );
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void Vector< DataType, MemoryManagerType >::AllocateLargerMemorySpaceAndCopyTheCurrentDataToTheNewLocation__Private( const LargestUnsignedInteger addMemorySpaceStartingFromThisIndex, const LargestUnsignedInteger sizeToAdd )
{
    // Check if the size of the instance is 0
    if ( member_size == 0UL )
    {
    	// The instance does not has any memory currently

    	// Allocate new memory space
        member_vectorPointer = MainMemoryManager::template AllocateAndDefaultConstruct< DataType >( sizeToAdd );

        // Set the size of the new memory allocated
        member_size = sizeToAdd;

    	// Nothing else needs to be done
    	return;
    }

    // Allocate a larger array to contain the additional data
    Vector< DataType, MemoryManagerType > largerTemporaryInstanceToContainTheAdditionalData( member_size + sizeToAdd );

    // Now there are 3 options, the first one is that the new data needs to be added at the beginning of the array, which means that all the 
    // curren data needs to be copied one index up in the new array. The second is that the new data needs to be added to the end of the array
    // which means that the current data needs to be copied to the same location. And finally the new data needs to be added to the middle,
    // which means that the start of the current data up to the location to add the new data, needs to be copied to the same location, and all
    // the data from there needs be copied one index up, to clear an entry to store the new data

    // Check if the data needs to be added at the beginning of the array
    if ( addMemorySpaceStartingFromThisIndex == 0UL )
    {
    	// The data needs to be added at the beginning

    	// Copy the current data one index up into the new array
    	Memory::Operations::Move< DataType >( member_vectorPointer, ( largerTemporaryInstanceToContainTheAdditionalData.member_vectorPointer + sizeToAdd ), member_size );
    }
    else if ( addMemorySpaceStartingFromThisIndex == member_size )
    {
    	// The data needs to be added at the end

    	// Copy the current data to the same location in the new array
    	Memory::Operations::Move< DataType >( member_vectorPointer, largerTemporaryInstanceToContainTheAdditionalData.member_vectorPointer, member_size );
    }
    else
    {
    	// The data needs to be added to the middle of the array

    	// Copy all the entries in the current data before the required index to the same location in the new array
    	Memory::Operations::Move< DataType >( member_vectorPointer, largerTemporaryInstanceToContainTheAdditionalData.member_vectorPointer, addMemorySpaceStartingFromThisIndex );

    	// Copy all the entries in the current data after the required index after to one index up into the new array 
    	Memory::Operations::Move< DataType >( ( member_vectorPointer + addMemorySpaceStartingFromThisIndex ), ( largerTemporaryInstanceToContainTheAdditionalData.member_vectorPointer + addMemorySpaceStartingFromThisIndex + sizeToAdd ), ( member_size - addMemorySpaceStartingFromThisIndex ) );
    }

    // Swap between this instance and the temporary that stores the new data
    Swap( largerTemporaryInstanceToContainTheAdditionalData );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< template< typename, typename > class OtherMemoryHandlerType, typename OtherMemoryHandlerMemoryManagerType >
void Vector< DataType, MemoryManagerType >::CopyDataFromOtherInstanceToThisInstance__Private( const OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >& other, const LargestUnsignedInteger firstIndexInThisInstance, const LargestUnsignedInteger firstIndexOnOtherInstance, const LargestUnsignedInteger sizeToAdd )
{
    // This object will store the index on this instance
    LargestUnsignedInteger thisInstanceIndex = firstIndexInThisInstance;

    // This object will store the index at which the loop should stop
    LargestUnsignedInteger stopAtThisIndex = firstIndexOnOtherInstance + sizeToAdd;

    // Loop on the required entries and assign the data from the other instance into this instance
    for ( LargestUnsignedInteger otherInstanceIndex = firstIndexOnOtherInstance ; otherInstanceIndex < stopAtThisIndex ; ++otherInstanceIndex, ++thisInstanceIndex )
    {
        // Copy the value from the other instance to this instance
        member_vectorPointer[ thisInstanceIndex ] = other[ otherInstanceIndex ];
    }       
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename OtherVectorMemoryManagerType >
void Vector< DataType, MemoryManagerType >::CopyDataFromOtherInstanceToThisInstance__Private( const Vector< DataType, OtherVectorMemoryManagerType >& other, const LargestUnsignedInteger firstIndexInThisInstance, const LargestUnsignedInteger firstIndexOnOtherInstance, const LargestUnsignedInteger sizeToAdd )
{
    // Copy the data into the new allocated memory space
    Memory::Operations::Copy< DataType >( other.member_vectorPointer + firstIndexOnOtherInstance, member_vectorPointer + firstIndexInThisInstance, sizeToAdd );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< template< typename, typename > class OtherMemoryHandlerType, typename OtherMemoryHandlerMemoryManagerType >
void Vector< DataType, MemoryManagerType >::CopyDataFromOtherInstanceToThisInstance__Private( OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >&& other, const LargestUnsignedInteger firstIndexInThisInstance, const LargestUnsignedInteger firstIndexOnOtherInstance, const LargestUnsignedInteger sizeToAdd )
{
    // This object will store the index on this instance
    LargestUnsignedInteger thisInstanceIndex = firstIndexInThisInstance;

    // This object will store the index at which the loop should stop
    LargestUnsignedInteger stopAtThisIndex = firstIndexOnOtherInstance + sizeToAdd;

    // Loop on the required entries and assign the data from the other instance into this instance
    for ( LargestUnsignedInteger otherInstanceIndex = firstIndexOnOtherInstance ; otherInstanceIndex < stopAtThisIndex ; ++otherInstanceIndex, ++thisInstanceIndex )
    {
        // Copy the value from the other instance to this instance
        member_vectorPointer[ thisInstanceIndex ] = other[ otherInstanceIndex ];
    }       
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename OtherVectorMemoryManagerType >
void Vector< DataType, MemoryManagerType >::CopyDataFromOtherInstanceToThisInstance__Private( Vector< DataType, OtherVectorMemoryManagerType >&& other, const LargestUnsignedInteger firstIndexInThisInstance, const LargestUnsignedInteger firstIndexOnOtherInstance, const LargestUnsignedInteger sizeToAdd )
{
    // Copy the data into the new allocated memory space
    Memory::Operations::Move< DataType >( other.member_vectorPointer + firstIndexOnOtherInstance, member_vectorPointer + firstIndexInThisInstance, sizeToAdd );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< Concepts::RawButPointerIsAllowed DataType COMMA typename MemoryManagerType >
	void Vector< DataType COMMA MemoryManagerType >::UnitTest()
	{}

)  //  End of debug tool



}  //  Namespace Memory


}  //  Namespace Universe