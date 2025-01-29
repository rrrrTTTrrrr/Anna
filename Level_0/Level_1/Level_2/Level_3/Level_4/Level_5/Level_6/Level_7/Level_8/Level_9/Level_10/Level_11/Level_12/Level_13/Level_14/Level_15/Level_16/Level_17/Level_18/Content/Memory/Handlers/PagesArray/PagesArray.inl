//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline PagesArray< DataType, MemoryManagerType >::PagesArray() :
	member_pageSize( member_defaultPageSizeInBytes ),
	member_indexOfFirstEntryUsedInFirstPageIndex( 0UL ),
	member_size( 0UL ),
    member_pages()
{}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline PagesArray< DataType, MemoryManagerType >::PagesArray( const LargestUnsignedInteger size, const DataType& data ) :
    SelfType()
{
    // Allocate the required memory space and initialize it with the given data
    InsertMultipleTimesTheSameElement( 0UL, size, data );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< template< typename, typename > class OtherMemoryHandlerType, typename OtherMemoryHandlerMemoryManagerType >
inline PagesArray< DataType, MemoryManagerType >::PagesArray( const OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >& other, const LargestUnsignedInteger otherInstanceStartingIndex, const LargestUnsignedInteger size ) :
    SelfType()
{
    // Insert the required data into this instance
    InsertElementsFromOtherInstance< OtherMemoryHandlerType >( other, 0UL, otherInstanceStartingIndex, size );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename OtherMemoryHandlerMemoryManagerType >
inline PagesArray< DataType, MemoryManagerType >::PagesArray( const PagesArray< DataType, OtherMemoryHandlerMemoryManagerType >& other, const LargestUnsignedInteger otherInstanceStartingIndex, const LargestUnsignedInteger size ) :
    SelfType()
{
    // Insert the required data into this instance
    InsertElementsFromOtherInstance< PagesArray >( other, 0UL, otherInstanceStartingIndex, size );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< template< typename, typename > class OtherMemoryHandlerType, typename OtherMemoryHandlerMemoryManagerType >
inline PagesArray< DataType, MemoryManagerType >::PagesArray( OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >&& other, const LargestUnsignedInteger otherInstanceStartingIndex, const LargestUnsignedInteger size ) :
    SelfType()
{
    // Insert the required data into this instance
    InsertElementsFromOtherInstance< OtherMemoryHandlerType >( TakeResourcesAndLeaveInstanceInDefaultState( other ), 0UL, otherInstanceStartingIndex, size );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename OtherMemoryHandlerMemoryManagerType >
inline PagesArray< DataType, MemoryManagerType >::PagesArray( PagesArray< DataType, OtherMemoryHandlerMemoryManagerType >&& other, const LargestUnsignedInteger otherInstanceStartingIndex, const LargestUnsignedInteger size ) :
    SelfType()
{
    // Insert the required data into this instance
    InsertElementsFromOtherInstance< PagesArray >( TakeResourcesAndLeaveInstanceInDefaultState( other ), 0UL, otherInstanceStartingIndex, size );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline PagesArray< DataType, MemoryManagerType >::PagesArray( const SelfType& other ) :
    SelfType()
{
    // Check if the other instance is empty
    if ( other.Size() > 0UL )
    {
        // The other instance is not empty

        // Insert the data from the other instance to this instance
        InsertElementsFromOtherInstance< PagesArray >( other, 0UL, 0UL, other.Size() );
    }
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
PagesArray< DataType, MemoryManagerType >::~PagesArray()
{
    // Check if the object is in default state, then noting needs to be done
    ReturnIfExpressionIsTrue( member_size == 0UL );

    // Delete the memory space allocated for the pages array
    RemovePages__Private( 0UL, member_pages.Size() );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline LargestUnsignedInteger PagesArray< DataType, MemoryManagerType >::PageSize() const
{
    // Return the page size
    return ( member_pageSize );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline LargestUnsignedInteger PagesArray< DataType, MemoryManagerType >::PageSizeInBytes() const
{
    // Multiply the page size by the data type size in bytes, and return the result
    return ( member_pageSize * sizeof( DataType ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline const Vector< DataType* >& PagesArray< DataType, MemoryManagerType >::PointersToPages() const
{
    // Return a constant reference of the pointers to pages container
    return ( member_pages );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline LargestUnsignedInteger PagesArray< DataType, MemoryManagerType >::IndexOfFirstEntryUsedInFirstPageIndex() const
{
    // Return the index of the first used entry in the first page
    return ( member_indexOfFirstEntryUsedInFirstPageIndex );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline LargestUnsignedInteger PagesArray< DataType, MemoryManagerType >::SizeUsedInLastPage() const
{
    // Return a constant reference of the pointers to pages container
    return ( ( member_size + member_indexOfFirstEntryUsedInFirstPageIndex ) % member_pageSize );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline LargestUnsignedInteger PagesArray< DataType, MemoryManagerType >::SizeInBytes() const
{
    // Multiply the size of the instance by the size in bytes of the data type, and return the result
    return ( member_size * sizeof( DataType ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline LargestUnsignedInteger PagesArray< DataType, MemoryManagerType >::DataTypeSizeInBytes() const
{
    // Return the size in bytes of the data type
    return ( sizeof( DataType ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename UniversalReferenceDataType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceDataType, DataType >::Result == true )
inline void PagesArray< DataType, MemoryManagerType >::InsertSingleElement( const LargestUnsignedInteger index, UniversalReferenceDataType&& data )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsEqualOrBelowCertainLimit( index, member_size );

    // Check if the pages array contains enough memory space to contain the additional data, if it does not allocate a larger array to contain
    // the additional data, and move the existing data into it
    AllocateLargerMemorySpaceAndCopyTheCurrentDataToTheNewLocation__Private( index, 1UL );

    // This object will store the index of the page, and the index of the entry in that page
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits quotientIsPageIndex_remainderIsIndexOfEntryInPage = GetPageIndexAndEntryIndexInPage__Private( index );

    // Set the entry with the new data
    member_pages[ quotientIsPageIndex_remainderIsIndexOfEntryInPage.Quotient() ][ quotientIsPageIndex_remainderIsIndexOfEntryInPage.Remainder() ] = ForwardUniversalReference< UniversalReferenceDataType >( data );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename... AnyArgumentNeededToConstructDataInstanceTypes >
inline void PagesArray< DataType, MemoryManagerType >::InsertSingleElementCreateFromArguments( const LargestUnsignedInteger index, AnyArgumentNeededToConstructDataInstanceTypes&&... anyArgumentNeededToConstructDataIstance )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsEqualOrBelowCertainLimit( index, member_size );

    // Allocate a larger array to contain the additional data, and move the existing data into it
    AllocateLargerMemorySpaceAndCopyTheCurrentDataToTheNewLocation__Private( index, 1UL );

    // This object will store the index of the page, and the index of the entry in that page
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits quotientIsPageIndex_remainderIsIndexOfEntryInPage = GetPageIndexAndEntryIndexInPage__Private( index );

    // Set the entry with the new data
    member_pages[ quotientIsPageIndex_remainderIsIndexOfEntryInPage.Quotient() ][ quotientIsPageIndex_remainderIsIndexOfEntryInPage.Remainder() ] = TakeResourcesAndLeaveInstanceInDefaultState( DataType( ForwardUniversalReference< AnyArgumentNeededToConstructDataInstanceTypes >( anyArgumentNeededToConstructDataIstance )... ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void PagesArray< DataType, MemoryManagerType >::InsertMultipleTimesTheSameElement( const LargestUnsignedInteger index, const LargestUnsignedInteger size, const DataType& data )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsEqualOrBelowCertainLimit( index, member_size );

    // Allocate a larger array to contain the additional data, and move the existing data into it
    AllocateLargerMemorySpaceAndCopyTheCurrentDataToTheNewLocation__Private( index, size );

    // This object will store the index of the first page that needs to be set, and the index of the first entry in that page that needs
    // to be set
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet = CentralProcessingUnit::Arithmetics::Divison( ( member_indexOfFirstEntryUsedInFirstPageIndex + index ), member_pageSize );

    // This object will store the number of entries that needs to be set in the first page
    const LargestUnsignedInteger numberOfEntriesToSetInFirstPage = member_pageSize - quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Remainder();

    // Set all the required entries in the first page with the given data
    Memory::Operations::Set< DataType >( member_pages[ quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Quotient() ] + quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Remainder(), numberOfEntriesToSetInFirstPage, data );

    // This object will store the index of the last page that needs to be set, and the index of the first entry in that page that does not
    // need to be set
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet = CentralProcessingUnit::Arithmetics::Divison( ( index + size ), member_pageSize );

    // Loop on the pages that all of their entries needs to be set
    for ( LargestUnsignedInteger pageIndex = quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Quotient() + 1UL ; pageIndex < quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ; ++pageIndex )
    {
    	// Set the entries of the current page with the data
    	Memory::Operations::Set< DataType >( member_pages[ pageIndex ], member_pageSize, data );
    }

    // Set all the required entires in the last page that needs to be set
	Memory::Operations::Set< DataType >( member_pages[ quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ], quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Remainder(), data );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< template< typename, typename > class OtherMemoryHandlerType, typename OtherMemoryHandlerMemoryManagerType >
inline void PagesArray< DataType, MemoryManagerType >::InsertElementsFromOtherInstance( const OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >& other, const LargestUnsignedInteger thisInstanceFirstIndex, const LargestUnsignedInteger otherInstanceFirstIndex, const LargestUnsignedInteger size )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsLargerThenZero( other.Size() );
    AssertValueIsEqualOrBelowCertainLimit( thisInstanceFirstIndex, member_size );
    AssertValueIsEqualOrBelowCertainLimit( otherInstanceFirstIndex, other.Size() );
    AssertValueIsEqualOrBelowCertainLimit( size, ( other.Size() - otherInstanceFirstIndex ) );

    // Allocate a larger array to contain the additional data, and move the existing data into it
    AllocateLargerMemorySpaceAndCopyTheCurrentDataToTheNewLocation__Private( thisInstanceFirstIndex, size );

    // Copy the data from the other instance to the new allocated memory space in this instance
    CopyDataFromOtherInstanceToThisInstance__Private< OtherMemoryHandlerType >( other, thisInstanceFirstIndex, otherInstanceFirstIndex, size );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< template< typename, typename > class OtherMemoryHandlerType, typename OtherMemoryHandlerMemoryManagerType >
inline void PagesArray< DataType, MemoryManagerType >::InsertElementsFromOtherInstance( OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >&& other, const LargestUnsignedInteger thisInstanceFirstIndex, const LargestUnsignedInteger otherInstanceFirstIndex, const LargestUnsignedInteger size )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsLargerThenZero( other.Size() );
    AssertValueIsEqualOrBelowCertainLimit( thisInstanceFirstIndex, member_size );
    AssertValueIsEqualOrBelowCertainLimit( otherInstanceFirstIndex, other.Size() );
    AssertValueIsEqualOrBelowCertainLimit( size, ( other.Size() - otherInstanceFirstIndex ) );

    // Allocate a larger array to contain the additional data, and move the existing data into it
    AllocateLargerMemorySpaceAndCopyTheCurrentDataToTheNewLocation__Private( thisInstanceFirstIndex, size );

    // Copy the data from the other instance to the new allocated memory space in this instance
    CopyDataFromOtherInstanceToThisInstance__Private< OtherMemoryHandlerType >( TakeResourcesAndLeaveInstanceInDefaultState( other ), thisInstanceFirstIndex, otherInstanceFirstIndex, size );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void PagesArray< DataType, MemoryManagerType >::InsertElementsFromRawData( const DataType* dataPointer, const LargestUnsignedInteger index, const LargestUnsignedInteger size )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( dataPointer );
    AssertValueIsEqualOrBelowCertainLimit( index, member_size );
    AssertValueIsLargerThenZero( size );

    // Allocate a larger array to contain the additional data, and move the existing data into it
    AllocateLargerMemorySpaceAndCopyTheCurrentDataToTheNewLocation__Private( index, size );

    // This object will store the index of the first page that needs to be set, and the index of the first entry in that page that needs
    // to be set. All the properties will belong to this instance
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet = GetPageIndexAndEntryIndexInPage__Private( index );

    // This object will store the number of entries that needs to be set in the first page
    const LargestUnsignedInteger thisInstance_numberOfEntriesToSetInFirstPage = member_pageSize - thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Remainder();

    // This object will store the index of the first page that needs to be set, and the index of the first entry in that page that needs
    // to be set. All the properties will belong to this instance
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet = GetPageIndexAndEntryIndexInPage__Private( index + size );

    // Copy all the required entries from the other instance to the first page that needs to be copied to in this instance
    Memory::Operations::Copy< DataType >( dataPointer, member_pages[ thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Quotient() ] + thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Remainder(), thisInstance_numberOfEntriesToSetInFirstPage );

    // This object will store the index on the other instance
    LargestUnsignedInteger dataIndex = thisInstance_numberOfEntriesToSetInFirstPage;

    // Loop on all the pages that needs to be copied to in this instance
	for ( LargestUnsignedInteger thisInstance_pageIndex = thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Quotient() + 1UL ; thisInstance_pageIndex < thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ; ++thisInstance_pageIndex, dataIndex += member_pageSize )
	{
		// Copy the current page from the other instance to this instance
		Memory::Operations::Copy< DataType >( dataPointer + dataIndex, member_pages[ thisInstance_pageIndex ], member_pageSize );
	}

	// Copy all the required entries from the other instance to the last page that needs to be copied to in this instance
	Memory::Operations::Copy< DataType >( dataPointer + dataIndex, member_pages[ thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ], thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Remainder() );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void PagesArray< DataType, MemoryManagerType >::Remove( const LargestUnsignedInteger indexOfFirstDataToRemove, const LargestUnsignedInteger sizeToRemove )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsLargerThenZero( sizeToRemove );
    AssertSumOfTheValuesIsEqualOrBelowCertainLimit( indexOfFirstDataToRemove, sizeToRemove, member_size );

    // Check if the size to remove is equal to the size of the instance
    if ( member_size == sizeToRemove )
    {
    	// The size to remove is equal to the size of the instance

    	// Reset the instance
    	Reset();

    	// Nothing else needs to be done
    	return;
    }

    // Check if the data needs to be removed from the beginning
    if ( indexOfFirstDataToRemove == 0UL )
    {
    	// The data needs to be removed from the beginning

        // This object will store the index of the first page that does not need to be removed, and the index of the first entry that does 
        // not need to be removed in that page
        const CentralProcessingUnit::DivisonResultUnsignedInteger64bits quotientIsFirstPageIndexThatNeedsToStay_remainderIsFirstEntryIndexThatNeedsToStayInFirstPageThatNeedsToStay = GetPageIndexAndEntryIndexInPage__Private( sizeToRemove );

        // Check if at least one page needs to be removed
        if ( quotientIsFirstPageIndexThatNeedsToStay_remainderIsFirstEntryIndexThatNeedsToStayInFirstPageThatNeedsToStay.Quotient() > 0UL )
        {
	        // Remove all the pages at the beginning
	        RemovePages__Private( 0UL, quotientIsFirstPageIndexThatNeedsToStay_remainderIsFirstEntryIndexThatNeedsToStayInFirstPageThatNeedsToStay.Quotient() );
	    }

        // Set the first used entry in the new first page
        member_indexOfFirstEntryUsedInFirstPageIndex = quotientIsFirstPageIndexThatNeedsToStay_remainderIsFirstEntryIndexThatNeedsToStayInFirstPageThatNeedsToStay.Remainder();

        // Decrement the size of the instance by the size removed
        member_size -= sizeToRemove;

		 	// Nothing else needs to be done
    	return;
	}

    // Check if the data needs to be removed from the ending
    if ( indexOfFirstDataToRemove + sizeToRemove == member_size )
    {
    	// The data needs to be removed from the ending

        // This object will store the index of the new last page after the removal, and the index of the first entry that needs to be removed
        // in that page
        const CentralProcessingUnit::DivisonResultUnsignedInteger64bits quotientIsLastNewPageIndex_remainderIsFirstEntryIndexThatNeedsToBeRemoved = GetPageIndexAndEntryIndexInPage__Private( indexOfFirstDataToRemove );

        // This object will store the first page index that needs to be removed
        const LargestUnsignedInteger firstPageIndexThatNeedsToBeRemoved = quotientIsLastNewPageIndex_remainderIsFirstEntryIndexThatNeedsToBeRemoved.Quotient() + 1UL;

        // This object will store the number of pages at the ending that needs to be removed
        const LargestUnsignedInteger numberOfPagesThatNeedsToBeRemoved = member_pages.Size() - firstPageIndexThatNeedsToBeRemoved;

        // Check if at least one page needs to be removed
        if ( numberOfPagesThatNeedsToBeRemoved > 0UL )
        {
	        // Remove all the pages at the ending
	        RemovePages__Private( firstPageIndexThatNeedsToBeRemoved, numberOfPagesThatNeedsToBeRemoved );
	    }

        // Decrement the size of the instance by the size removed
        member_size -= sizeToRemove;

		 	// Nothing else needs to be done
    	return;
	}

	// The entries needs to be removed from the middle of the pages array

	// This object will store the number of entries before the first entry that needs to be removed
	const LargestUnsignedInteger numberOfEntriesBeforeFirstEntryThatNeedsToBeRemoved = indexOfFirstDataToRemove;

	// This object will store the number of entries after the last entry that needs to be removed
	const LargestUnsignedInteger numberOfEntriesAfterLastEntryThatNeedsToBeRemoved = member_size - numberOfEntriesBeforeFirstEntryThatNeedsToBeRemoved - sizeToRemove;

	// Check if the number of entries before the segment that needs to be removed is larger then the number of entries after
	if ( numberOfEntriesBeforeFirstEntryThatNeedsToBeRemoved > numberOfEntriesAfterLastEntryThatNeedsToBeRemoved )
	{
		// The number of entries before the segment that needs to be removed is larger then the number of entries after

		// This object will store the destination index that the entries from the beginning needs to be moved to
		const LargestUnsignedInteger absoluteDestinationIndexToMoveEntriesFromBeginning = member_indexOfFirstEntryUsedInFirstPageIndex + sizeToRemove;

		// Move all the entries before the segment that needs to be removed towrds the end
		MoveEntriesTowardsTheEnding__Private( member_indexOfFirstEntryUsedInFirstPageIndex, absoluteDestinationIndexToMoveEntriesFromBeginning, numberOfEntriesBeforeFirstEntryThatNeedsToBeRemoved );

		// This object will store the number of pages that needs to be removed
		const LargestUnsignedInteger numberOfPagesThatNeedsToBeRemoved = absoluteDestinationIndexToMoveEntriesFromBeginning / member_pageSize;

		// Check if at least one page needs to be removed
		if ( numberOfPagesThatNeedsToBeRemoved > 0UL )
		{
	        // Remove all the pages at the ending
	        RemovePages__Private( 0UL, numberOfPagesThatNeedsToBeRemoved );				
		}
	}
	else
	{
		// The number of entries before the segment that needs to be removed is smaller or equal then the number of entries after

		// Move all the entries after the segment that needs to be removed towards the beginning
		MoveEntriesTowardsTheBeginning__Private( member_indexOfFirstEntryUsedInFirstPageIndex + indexOfFirstDataToRemove + sizeToRemove, member_indexOfFirstEntryUsedInFirstPageIndex + indexOfFirstDataToRemove, sizeToRemove );

		// This object will store the index of the first page that needs to be removed
		const LargestUnsignedInteger firstPageIndexThatNeedsToBeRemoved = ( ( member_indexOfFirstEntryUsedInFirstPageIndex + indexOfFirstDataToRemove + numberOfEntriesAfterLastEntryThatNeedsToBeRemoved ) / member_pageSize ) + 1UL;

		// This object will store the number of pages that needs to be removed
		const LargestUnsignedInteger numberOfPagesThatNeedsToBeRemoved = member_pages.Size() - firstPageIndexThatNeedsToBeRemoved;

		// Check if at least one page needs to be removed
		if ( numberOfPagesThatNeedsToBeRemoved > 0UL )
		{
	        // Remove all the pages at the ending
	        RemovePages__Private( firstPageIndexThatNeedsToBeRemoved, numberOfPagesThatNeedsToBeRemoved );				
		}
	}
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline Boolean PagesArray< DataType, MemoryManagerType >::operator==( const SelfType& other ) const
{
	// Check if the page size in both instances is different
	ReturnValueIfExpressionIsTrue( ( member_pageSize != other.member_pageSize ), false );

	// Check if the size in both instances is different
	ReturnValueIfExpressionIsTrue( ( member_size != other.member_size ), false );

	// Check if the size in both instances is zero, which means they are both empty
	ReturnValueIfExpressionIsTrue( ( member_size == 0UL ), true );

	// Compare the content of the two instance and return the result
	return ( CompareWithOtherInstance__Private( other ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline Boolean PagesArray< DataType, MemoryManagerType >::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline DataType& PagesArray< DataType, MemoryManagerType >::operator[]( const LargestUnsignedInteger index )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsBelowCertainLimit( index, member_size );

    // This object will store the page index, and the index in the page of the entry
	const CentralProcessingUnit::DivisonResultUnsignedInteger64bits quotientIsPageIndex_remainderIsIndexOfEntryInPage = GetPageIndexAndEntryIndexInPage__Private( index );

    // Return a reference to the required entry
    return ( member_pages[ quotientIsPageIndex_remainderIsIndexOfEntryInPage.Quotient() ][ quotientIsPageIndex_remainderIsIndexOfEntryInPage.Remainder() ] );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline const DataType& PagesArray< DataType, MemoryManagerType >::operator[]( const LargestUnsignedInteger index ) const
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsBelowCertainLimit( index, member_size );
    
    // This object will store the page index, and the index in the page of the entry
	const CentralProcessingUnit::DivisonResultUnsignedInteger64bits quotientIsPageIndex_remainderIsIndexOfEntryInPage = GetPageIndexAndEntryIndexInPage__Private( index );

    // Return a reference to the required entry
    return ( member_pages[ quotientIsPageIndex_remainderIsIndexOfEntryInPage.Quotient() ][ quotientIsPageIndex_remainderIsIndexOfEntryInPage.Remainder() ] );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline PagesArray< DataType, MemoryManagerType >& PagesArray< DataType, MemoryManagerType >::operator+=( const SelfType& other )
{
    // Add the data to the end of the instance
    Insert< PagesArray >( other, member_size, 0UL, other.Size() );

    // Return a reference to this instance
    return ( *this );
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline CentralProcessingUnit::DivisonResultUnsignedInteger64bits PagesArray< DataType, MemoryManagerType >::GetPageIndexAndEntryIndexInPage__Private( const LargestUnsignedInteger index ) const
{
	// Add the index of the first used entry to the index, to calculate the absolute index. Then divide the absoulte index by the page size.
	// The quotient is the page index, and the remainder is the index of the entry in the page. Return the result
	return ( CentralProcessingUnit::Arithmetics::Divison( member_indexOfFirstEntryUsedInFirstPageIndex + index, member_pageSize ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void PagesArray< DataType, MemoryManagerType >::RemovePages__Private( const LargestUnsignedInteger firstPageIndexThatNeedsToBeRemoved, const LargestUnsignedInteger numberOfPagesThatNeedsToBeRemoved )
{
	// This object will store the page index at which the loop needs to stop. This page index is the first one that does not need to be
	// removed after the pages that needs to be removed
	const LargestUnsignedInteger stopLoopAtThisPageIndex = firstPageIndexThatNeedsToBeRemoved + numberOfPagesThatNeedsToBeRemoved;

	// Loop on all the required pointers and delete the memory they point to
	for ( LargestUnsignedInteger pageIndex = firstPageIndexThatNeedsToBeRemoved ; pageIndex < stopLoopAtThisPageIndex ; ++pageIndex )
	{
		// Delete the memory space the pointer points to
        MemoryManagerType::template Done< DataType >( member_pages[ pageIndex ], false );
	}

    // Remove all the pages at the ending
    member_pages.Remove( firstPageIndexThatNeedsToBeRemoved, numberOfPagesThatNeedsToBeRemoved );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void PagesArray< DataType, MemoryManagerType >::AllocateLargerMemorySpaceAndCopyTheCurrentDataToTheNewLocation__Private( const LargestUnsignedInteger index, const LargestUnsignedInteger size )
{
    // Check if the size of the instance is 0
    if ( member_size == 0UL )
    {
    	// The instance does not has any memory currently

    	// Divide the additional size needed by the page size, and store the quotient and remainder
    	const CentralProcessingUnit::DivisonResultUnsignedInteger64bits divisionResult = CentralProcessingUnit::Arithmetics::Divison( size, member_pageSize );

    	// This object will store the number of pages that needs to be allocated
    	LargestUnsignedInteger numberOfPagesToAllocate = divisionResult.Quotient();

    	// Check if the data size does not divide by the page size with no remainder
    	if ( divisionResult.Remainder() > 0UL )
    	{
    		// The data size does not divide by the page size with no remainder

    		// Increment the number of pages to allocate by 1
    		numberOfPagesToAllocate += 1UL;
    	}

		// Allocate the pointers that will store the additional pages
		member_pages.InsertMultipleTimesTheSameElement( 0UL, numberOfPagesToAllocate, nullptr );

    	// Loop the required number of pages needed to be allocated
    	for ( LargestUnsignedInteger pageIndex = 0UL ; pageIndex < numberOfPagesToAllocate ; ++pageIndex )
    	{
    		// Allocate another page, and store the memory address of it in the required pointer
    		member_pages[ pageIndex ] = MemoryManagerType::template AllocateAndDefaultConstruct< DataType >( member_pageSize );
    	}

        // Set the size of the new memory allocated
        member_size = size;

    	// Nothing else needs to be done
    	return;
    }

	// Check if the data needs to be inserted at the beginning of the pages array
	if ( index == 0UL )
	{
		// The data needs to be inserted at the beginning of the pages array

		// Check if there is enough unused memory space at the beginning of the pages array to contain the additional data
		if ( member_indexOfFirstEntryUsedInFirstPageIndex >= size )
		{
			// There is enough unused memory space at the beginning of the pages array to contain the additional data

			// Decrement the index of the first entry used in the first page by the additional data size
			member_indexOfFirstEntryUsedInFirstPageIndex -= size;

			// Increment the size of the pages array by the additional data size
			member_size += size;

			// Nothing else needs to be done
			return;
		}

		// There is not enough unused memory space at the beginning of the pages array to contain the additional data

		// Allocate additional pages at the beginning to contain the new data
		AllocateAdditionalPagesAtTheBeginning__Private( size );

		// Nothing else needs to be done
		return;
	}

	// Check if the data needs to be inserted at the ending of the pages array
	if ( index == member_size )
	{
		// The data needs to be inserted at the ending of the pages array

		// This object will store the size left to use at the ending of the pages array
		const LargestUnsignedInteger sizeLeftToUseInTheEnding = ( member_pages.Size() * member_pageSize ) - ( member_indexOfFirstEntryUsedInFirstPageIndex + member_size );

		// Check if there is enough unused memory space at the ending of the pages array to contain the additional data
		if ( sizeLeftToUseInTheEnding >= size )
		{
			// There is enough unused memory space at the ending of the pages array to contain the additional data

			// Increment the size of the pages array by the additional data size
			member_size += size;

			// Nothing else needs to be done
			return;
		}

		// There is not enough unused memory space at the ending of the pages array to contain the additional data

		// Allocate additional pages at the ending to contain the new data
		AllocateAdditionalPagesAtTheEnding__Private( size, sizeLeftToUseInTheEnding );

		// Nothing else needs to be done
		return;
	}

	// The data needs to be added to the middle of the pages array

	// Divide the additional size to by the page size, and store the quotient and remainder
	const CentralProcessingUnit::DivisonResultUnsignedInteger64bits additionalSizeDividedByPageSizeResult = CentralProcessingUnit::Arithmetics::Divison( size, member_pageSize );

	// Check if the additional size divides by the page size with no remainder
	if ( additionalSizeDividedByPageSizeResult.Remainder() == 0UL )
	{
		// The additional size divides by the page size with no remainder. This is a special case that allows, allocating another pages 
		// below the page that the data needs to be inserted to, and just moving all the current existing data at the beginning of the 
		// page to the beginning of the new first allocated page. This allowed only in this case, because it does not leave any unused 
		// entries

    	// Divide the actual index at which the data needs to be inserted to by the page size, and store the quotient and remainder
    	const CentralProcessingUnit::DivisonResultUnsignedInteger64bits absoluteIndexToAddDataAtDividedByPageSizeResult = CentralProcessingUnit::Arithmetics::Divison( ( member_indexOfFirstEntryUsedInFirstPageIndex + index ), member_pageSize );

    	// Allocate all the pointers to store the new pages
    	member_pages.InsertMultipleTimesTheSameElement( absoluteIndexToAddDataAtDividedByPageSizeResult.Quotient(), additionalSizeDividedByPageSizeResult.Quotient(), nullptr );

    	// This object will store the index that points to the pointer that will store the memory address of the new page
    	LargestUnsignedInteger newPageIndex = absoluteIndexToAddDataAtDividedByPageSizeResult.Quotient();

    	// Loop until all the required additional pages are allocated
    	for ( LargestUnsignedInteger numberOfPagesAllocatedSoFar = 0UL ; numberOfPagesAllocatedSoFar < additionalSizeDividedByPageSizeResult.Quotient() ; ++numberOfPagesAllocatedSoFar )
    	{
			// Allocate a new page below the page that the data needs to be inserted to
			member_pages[ newPageIndex ] = MemoryManagerType::template AllocateAndDefaultConstruct< DataType >( member_pageSize );
    	}

    	// This object will store the index of the page that the data needs to move from it to the beginning of the first new allocated page
    	const LargestUnsignedInteger pageIndexThatTheDataNeedsToBeMovedFromToTheNewFirstPageAllocated = absoluteIndexToAddDataAtDividedByPageSizeResult.Quotient() + additionalSizeDividedByPageSizeResult.Quotient();

		// Move the entries from the beginning of the page that the data needs to be inserted to the beginning of the prior new allocated
		// page
		Memory::Operations::Move< DataType >( member_pages[ pageIndexThatTheDataNeedsToBeMovedFromToTheNewFirstPageAllocated ], member_pages[ absoluteIndexToAddDataAtDividedByPageSizeResult.Quotient() ], absoluteIndexToAddDataAtDividedByPageSizeResult.Remainder() );

		// Increment the size of the pages array by the additional data size
		member_size += size;

		// Nothing else needs to be done
		return;
	}

	// This object will store half of the current size of the pages array
	const LargestUnsignedInteger halfOfCurrentSize = DivideByTwo( member_size );

	// Check if there are more entries above the index at which the new data needs to be inserted
	if ( index < halfOfCurrentSize )
	{
		// There are more entries above the index at which the new data needs to be inserted. Then the prefered operation is to move
		// the entries below the index, towards the beginning, to insert the new data

		// This object will store the additional size needed plus one. The reason for the plus one, is because the current entry
		// that the index to add the data points to needs to be above the last entry of the new data. This way all the entries below
		// the index will move an additional entry, which will then allow the data to fit entirly before that entry
		const LargestUnsignedInteger sizePlusOne = size + 1UL;

		// Check if there is enough unused memory space at the beginning of the pages array to contain the additional data
		if ( member_indexOfFirstEntryUsedInFirstPageIndex >= sizePlusOne )
		{
			// There is enough unused memory space at the beginning of the pages array to contain the additional data. In this case there
			// is no need to allocate more memory space

			// Move all the entries below the index to insert the data the size to insert plus one towards the beginning
			MoveEntriesTowardsTheBeginning__Private( member_indexOfFirstEntryUsedInFirstPageIndex, member_indexOfFirstEntryUsedInFirstPageIndex - sizePlusOne, index - member_indexOfFirstEntryUsedInFirstPageIndex );

			// Set the new index of the first used entry at the first page
			member_indexOfFirstEntryUsedInFirstPageIndex -= sizePlusOne;

			// Increment the size of the pages array by the additional data size
			member_size += size;

			// Nothing else needs to be done
			return;
		}

		// There is not enough unused memory space at the beginning of the pages array to contain the additional data. This means more memory
		// space needs to be allocated

		// This object will store the old index of first used entry in the first page
		const LargestUnsignedInteger oldFirstEntryUsedInFirstPageIndex = member_indexOfFirstEntryUsedInFirstPageIndex;

		// Allocate additional pages at the beginning to contain the new data, and store the number of additional pages allocated. This 
		// will allow to store the index of the old first page
		const LargestUnsignedInteger oldFirstPageIndex = AllocateAdditionalPagesAtTheBeginning__Private( sizePlusOne );

		// Move all the entries below the index to insert the data the size to insert plus one towards the beginning
		MoveEntriesTowardsTheBeginning__Private( member_indexOfFirstEntryUsedInFirstPageIndex, oldFirstPageIndex * member_pageSize + oldFirstEntryUsedInFirstPageIndex, index - member_indexOfFirstEntryUsedInFirstPageIndex );
	}
	else
	{
		// There are more entries below the index at which the new data needs to be inserted. Then the prefered operation is to move
		// the entries above the index, towards the ending, to insert the new data

		// This object will store the size left to use at the ending of the pages array
		const LargestUnsignedInteger sizeLeftToUseInTheEnding = ( member_pages.Size() * member_pageSize ) - ( member_indexOfFirstEntryUsedInFirstPageIndex + member_size );

		// Check if there is enough unused memory space at the ending of the pages array to contain the additional data
		if ( sizeLeftToUseInTheEnding >= size )
		{
			// There is enough unused memory space at the ending of the pages array to contain the additional data

			// Move all the entries above the index where the data needs to be inserted towards the ending of the pages array
			MoveEntriesTowardsTheEnding__Private( index, index + size, size );

			// Increment the size of the pages array by the additional data size
			member_size += size;

			// Nothing else needs to be done
			return;
		}

		// There is not enough unused memory space at the ending of the pages array to contain the additional data. This means more memory
		// space needs to be allocated

		// Allocate additional pages at the ending to contain the new data
		AllocateAdditionalPagesAtTheEnding__Private( size, sizeLeftToUseInTheEnding );

		// Move all the entries above the index where the data needs to be inserted towards the ending of the pages array
		MoveEntriesTowardsTheEnding__Private( index, index + size, size );
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline LargestUnsignedInteger PagesArray< DataType, MemoryManagerType >::AllocateAdditionalPagesAtTheBeginning__Private( const LargestUnsignedInteger size )
{
	// This object will store the additional size needed to allocate at the beginning of the pages array
	const LargestUnsignedInteger additionalSizeNeededToBeAllocatedAtTheBeginning = size - member_indexOfFirstEntryUsedInFirstPageIndex;

	// This object will store the result of dividing the additional size by the page size. The quotient will be the number of additional pages
	// needed to be allocate, and the remainder will contain if the additional size divides by the page size with no remainder, which means there
	// is no need to add one to the number of additional pages to allocate
	const CentralProcessingUnit::DivisonResultUnsignedInteger64bits quotientIsNumberOfAdditionalPages_remainderIsDoesAdditionalSizeNeededDividesByPageSize = CentralProcessingUnit::Arithmetics::Divison( additionalSizeNeededToBeAllocatedAtTheBeginning, member_pageSize );
	
	// Store the number of additional pages to allocate at the beginning
	LargestUnsignedInteger numberOfAdditionalPagesToAllocateAtTheBeginning = quotientIsNumberOfAdditionalPages_remainderIsDoesAdditionalSizeNeededDividesByPageSize.Quotient();

	// Check if the additional size divides by the page size with no remainder
	if ( quotientIsNumberOfAdditionalPages_remainderIsDoesAdditionalSizeNeededDividesByPageSize.Remainder() != 0UL )
	{
		// The additional size does not divide by the page size with no remainder

		// Increment the number of pages to allocate by one
		numberOfAdditionalPagesToAllocateAtTheBeginning += 1UL;

		// Set the new first entry used in the new first page, by decrementing the remainder from the page size
		member_indexOfFirstEntryUsedInFirstPageIndex = member_pageSize - quotientIsNumberOfAdditionalPages_remainderIsDoesAdditionalSizeNeededDividesByPageSize.Remainder();
	}
	else
	{
		// The additional size divides by the page size with no remainder. This means that all of the entries of the new first page will
		// be used

		// Set the new first entry used in the new first page to zero
		member_indexOfFirstEntryUsedInFirstPageIndex = 0UL;
	}

	// Allocate at the beginning the pointers that will store the additional pages
	member_pages.InsertMultipleTimesTheSameElement( 0UL, numberOfAdditionalPagesToAllocateAtTheBeginning, nullptr );

	// Loop the required number of pages needed to be allocated
	for ( LargestUnsignedInteger pageIndex = 0UL ; pageIndex < numberOfAdditionalPagesToAllocateAtTheBeginning ; ++pageIndex )
	{
		// Allocate another page, and store the memory address of it in the required pointer
		member_pages[ pageIndex ] = MemoryManagerType::template AllocateAndDefaultConstruct< DataType >( member_pageSize );
	}

	// Increment the size of the pages array by the additional data size
	member_size += size;

	// Return the page index of the old first page
	return ( numberOfAdditionalPagesToAllocateAtTheBeginning );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void PagesArray< DataType, MemoryManagerType >::AllocateAdditionalPagesAtTheEnding__Private( const LargestUnsignedInteger size, const LargestUnsignedInteger sizeLeftToUseInTheEnding )
{
	// This object will store the additional size needed to allocate at the beginning of the pages array
	const LargestUnsignedInteger additionalSizeNeededToBeAllocatedAtTheEnding = size - sizeLeftToUseInTheEnding;

	// Calculate the number of pages to allocate
	const LargestUnsignedInteger numberOfAdditionalPagesToAllocateAtTheEnding = ( additionalSizeNeededToBeAllocatedAtTheEnding / member_pageSize ) + 1UL;

	// This object will store the current index at which the new page allocated memory address will be stored
	LargestUnsignedInteger index = member_pages.Size();

	// Allocate at the beginning the pointers that will store the additional pages
	member_pages.InsertMultipleTimesTheSameElement( member_pages.Size(), numberOfAdditionalPagesToAllocateAtTheEnding, nullptr );

	// Loop the required number of pages needed to be allocated
	for ( LargestUnsignedInteger numberOfPagesAllocatedSoFar = 0UL ; numberOfPagesAllocatedSoFar < numberOfAdditionalPagesToAllocateAtTheEnding ; ++numberOfPagesAllocatedSoFar, ++index )
	{
		// Allocate another page, and store the memory address of it in the required pointer
		member_pages[ index ] = MemoryManagerType::template AllocateAndDefaultConstruct< DataType >( member_pageSize );
	}

	// Increment the size of the pages array by the additional data size
	member_size += size;
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void PagesArray< DataType, MemoryManagerType >::MoveEntriesTowardsTheBeginning__Private( const LargestUnsignedInteger absoluteSourceIndex, const LargestUnsignedInteger absoluteDestinationIndex, const LargestUnsignedInteger sizeToMove )
{
	// FIRST PAGE INFORMATION :

    // This object will store the page index at which the first entry that needs be moved is located, and the index of the first entry in
    // that page that needs to be moved
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage = CentralProcessingUnit::Arithmetics::Divison( absoluteSourceIndex, member_pageSize );

    // This object will store the number of entries that needs to be moved from the first page that entries needs to be moved from
    const LargestUnsignedInteger numberOfEntriesToMoveFromFirstSourcePage = member_pageSize - quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Remainder();

    // This object will store the page index to which the first entry needs to be moved to, and the index of the first entry in
    // that page that needs to be set
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits quotientIsFirstDestinationPageIndex_remainderIsIndexOfFirstEntryInFirstDestinationPage = CentralProcessingUnit::Arithmetics::Divison( absoluteDestinationIndex, member_pageSize );

    // This object will store the number of entries that needs to be set in the first page that entries needs to be moved to
    const LargestUnsignedInteger numberOfEntriesToSetInFirstDestinationPage = member_pageSize - quotientIsFirstDestinationPageIndex_remainderIsIndexOfFirstEntryInFirstDestinationPage.Remainder();

    // LAST PAGE INFORMATION :

    // This object will store the page index at which the last entry that needs be moved is located, and the index of the first entry in
    // that page that does not need to be moved
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits quotientIsLastSourcePageIndex_remainderIsIndexOfFirstEntryThatDoesNotNeedToBeMovedInLastSourcePage = CentralProcessingUnit::Arithmetics::Divison( ( absoluteSourceIndex + sizeToMove ), member_pageSize );

    // This object will store the number of entries that needs to be moved from the last page that entries needs to be moved from
    const LargestUnsignedInteger numberOfEntriesToMoveFromLastSourcePage = member_pageSize - quotientIsLastSourcePageIndex_remainderIsIndexOfFirstEntryThatDoesNotNeedToBeMovedInLastSourcePage.Remainder();

    // This object will store the page index to which the last entry needs to be moved to, and the index of the first entry in
    // that page that does not need to be set
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits quotientIsLastDestinationPageIndex_remainderIsIndexOfFirstEntryThatDoesNotNeedToBeSetInLastDestinationPage = CentralProcessingUnit::Arithmetics::Divison( ( absoluteDestinationIndex + sizeToMove ), member_pageSize );

	// Divide the actual index at which the data needs to be inserted to by the page size, and store the quotient and remainder
	const CentralProcessingUnit::DivisonResultUnsignedInteger64bits quotientIsNumberOfPagesThatNeedsToBeMoved_remainderMeansDoesSizeToMoveDivideByPagesSizeWithNoRemainder = CentralProcessingUnit::Arithmetics::Divison( sizeToMove, member_pageSize );

	// Check if the source and destination index are the same
	if ( quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Remainder() == quotientIsFirstDestinationPageIndex_remainderIsIndexOfFirstEntryInFirstDestinationPage.Remainder() )
	{
		// The source and destination index are the same. This means that only the last and first pages needs special care, and all the
		// pages in the middle can be moved as they are

		// Move the entries from the source first page to the destination first page
		Memory::Operations::Move< DataType >( member_pages[ quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Quotient() ] + quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Remainder(), member_pages[ quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Quotient() ] + quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Remainder(), numberOfEntriesToMoveFromFirstSourcePage );

		// This object will store the current destination index
		LargestUnsignedInteger currentDestinationPageIndex = quotientIsFirstDestinationPageIndex_remainderIsIndexOfFirstEntryInFirstDestinationPage.Quotient() + 1UL;

		// This obejct will store the number of full pages that needs to be moved
		LargestUnsignedInteger lastSourcePageIndexToMoveFullPage = quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Quotient() + quotientIsNumberOfPagesThatNeedsToBeMoved_remainderMeansDoesSizeToMoveDivideByPagesSizeWithNoRemainder.Quotient() - 1UL;

		// Move all the pages to their required location
		for ( LargestUnsignedInteger currentSourcePageIndex = quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Quotient() + 1UL ; currentSourcePageIndex < lastSourcePageIndexToMoveFullPage ; ++currentSourcePageIndex, ++currentDestinationPageIndex )
		{
			// Swap between the current source and destination pointers to the pages
			Memory::Operations::Swap< DataType* >( member_pages[ currentSourcePageIndex ], member_pages[ currentDestinationPageIndex ] );
		}

		// Move the entries from the source last page to the destination last page
		Memory::Operations::Move< DataType >( member_pages[ quotientIsLastSourcePageIndex_remainderIsIndexOfFirstEntryThatDoesNotNeedToBeMovedInLastSourcePage.Quotient() ], member_pages[ quotientIsLastDestinationPageIndex_remainderIsIndexOfFirstEntryThatDoesNotNeedToBeSetInLastDestinationPage.Quotient() ], numberOfEntriesToMoveFromLastSourcePage );

		// Nothing else needs to be done
		return;
	}

	// Check if the size to move divides by the page size with no remainder
	if ( quotientIsNumberOfPagesThatNeedsToBeMoved_remainderMeansDoesSizeToMoveDivideByPagesSizeWithNoRemainder.Remainder() == 0UL )
	{
		// The size to move divides by the page size with no remainder

		// Check if the source and destination index all point to a start of a page
		if ( quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Remainder() == 0UL && quotientIsFirstDestinationPageIndex_remainderIsIndexOfFirstEntryInFirstDestinationPage.Remainder() == 0UL )
		{
			// The source and destination index all point to a start of a page. This means that there is no need to move entries in the page,
			// and all the pages can be moved as they are from the source to the destination

    		// This object will store the current destination index
    		LargestUnsignedInteger currentDestinationPageIndex = quotientIsFirstDestinationPageIndex_remainderIsIndexOfFirstEntryInFirstDestinationPage.Quotient();

    		// This obejct will store the number of full pages that needs to be moved
    		const LargestUnsignedInteger lastSourcePageIndexToMoveFullPage = quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Quotient() + quotientIsNumberOfPagesThatNeedsToBeMoved_remainderMeansDoesSizeToMoveDivideByPagesSizeWithNoRemainder.Quotient();

    		// Move all the pages to their required location
    		for ( LargestUnsignedInteger currentSourcePageIndex = quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Quotient() ; currentSourcePageIndex < lastSourcePageIndexToMoveFullPage ; ++currentSourcePageIndex, ++currentDestinationPageIndex )
    		{
    			// Swap between the current source and destination pointers to the pages
    			Memory::Operations::Swap< DataType* >( member_pages[ currentSourcePageIndex ], member_pages[ currentDestinationPageIndex ] );
    		}

    		// Nothing else needs to be done
    		return;
    	}
	}

	// Check if the number of entreis in the source first page is smaller then the number of entries in the destination first page
	if ( numberOfEntriesToMoveFromFirstSourcePage < numberOfEntriesToSetInFirstDestinationPage )
	{
		// The number of entreis in the source first page is smaller then the number of entries in the destination first page

		// Move all the entries from the source first page to the destination first page
		Memory::Operations::Move< DataType >( member_pages[ quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Quotient() ] + quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Remainder(), member_pages[ quotientIsFirstDestinationPageIndex_remainderIsIndexOfFirstEntryInFirstDestinationPage.Quotient() ] + quotientIsFirstDestinationPageIndex_remainderIsIndexOfFirstEntryInFirstDestinationPage.Remainder(), numberOfEntriesToMoveFromFirstSourcePage );

		// This object will store the current destination index
		LargestUnsignedInteger currentDestinationPageIndex = quotientIsFirstDestinationPageIndex_remainderIsIndexOfFirstEntryInFirstDestinationPage.Quotient();

		// This object will store the index on the current destination page, that the entries from the beginning of the current source
		// page needs to be moved to
		const LargestUnsignedInteger currentDestinationEntryIndexToMoveEntriesTo = quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Remainder() + numberOfEntriesToMoveFromFirstSourcePage;

		// This object will store the number of entries that can still fit in the end of each destination page
		const LargestUnsignedInteger numberOfEntriesToMoveFromBeginningOfCurrentSourcePageToEndOfCurrentDestinationPage = numberOfEntriesToSetInFirstDestinationPage - numberOfEntriesToMoveFromFirstSourcePage;

		// This object will store the index on the current source page, that entries need to be copied from to the beginning of the next
		// destination page
		const LargestUnsignedInteger currentSourceEntryIndexToMoveEntriesFrom = numberOfEntriesToMoveFromBeginningOfCurrentSourcePageToEndOfCurrentDestinationPage;

		// This object will store the number of entries that needs to be moved from the end of the current source page to the beginning of the 
		// next destination page
		const LargestUnsignedInteger numberOfEntriesToMoveFromEndingOfCurrentSourcePageToBeginningOfNextDestinationPage = member_pageSize - numberOfEntriesToMoveFromBeginningOfCurrentSourcePageToEndOfCurrentDestinationPage;

		// Loop on all the pages that needs to be moved
		for ( LargestUnsignedInteger currentSourcePageIndex = quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Quotient() + 1UL ; currentSourcePageIndex < quotientIsLastSourcePageIndex_remainderIsIndexOfFirstEntryThatDoesNotNeedToBeMovedInLastSourcePage.Quotient() ; ++currentSourcePageIndex )
		{
			// Move the entries from the beginning of the current source page, to the ending of the current destination page
			Memory::Operations::Move< DataType >( member_pages[ currentSourcePageIndex ], member_pages[ currentDestinationPageIndex ] + currentDestinationEntryIndexToMoveEntriesTo, numberOfEntriesToMoveFromBeginningOfCurrentSourcePageToEndOfCurrentDestinationPage );
		    			
			// Move the entries from the ending of the current source page, to the beginning of the next destination page
			Memory::Operations::Move< DataType >( member_pages[ currentSourcePageIndex ] + currentSourceEntryIndexToMoveEntriesFrom, member_pages[ currentDestinationPageIndex + 1UL ], numberOfEntriesToMoveFromEndingOfCurrentSourcePageToBeginningOfNextDestinationPage );
		}

		// Only the last page that data needs to be moved from, needs be handled now

		// Move the entries that can fit from the beginning of the last source page, to the end of the one before last destination page
		Memory::Operations::Move< DataType >( member_pages[ quotientIsLastSourcePageIndex_remainderIsIndexOfFirstEntryThatDoesNotNeedToBeMovedInLastSourcePage.Quotient() ], member_pages[ quotientIsLastDestinationPageIndex_remainderIsIndexOfFirstEntryThatDoesNotNeedToBeSetInLastDestinationPage.Quotient() - 1UL ] + currentDestinationEntryIndexToMoveEntriesTo, numberOfEntriesToMoveFromBeginningOfCurrentSourcePageToEndOfCurrentDestinationPage );

		// This object will store the number of entries left to move from the last source page to the beginning of the last destination page
		const LargestUnsignedInteger numberOfEntriesLeftToMoveFromLastSourcePage = numberOfEntriesToMoveFromLastSourcePage - numberOfEntriesToMoveFromBeginningOfCurrentSourcePageToEndOfCurrentDestinationPage;

		// Move the entries left from the last source page, to the beginning of the last destination page
		Memory::Operations::Move< DataType >( member_pages[ quotientIsLastSourcePageIndex_remainderIsIndexOfFirstEntryThatDoesNotNeedToBeMovedInLastSourcePage.Quotient() ] + numberOfEntriesToMoveFromBeginningOfCurrentSourcePageToEndOfCurrentDestinationPage, member_pages[ quotientIsLastDestinationPageIndex_remainderIsIndexOfFirstEntryThatDoesNotNeedToBeSetInLastDestinationPage.Quotient() ], numberOfEntriesLeftToMoveFromLastSourcePage );
	}
	else if ( numberOfEntriesToMoveFromFirstSourcePage > numberOfEntriesToSetInFirstDestinationPage )
	{
		// The number of entreis in the source first page is larger then the number of entries in the destination first page

		// Move all the entries from the source first page to the destination first page
		Memory::Operations::Move< DataType >( member_pages[ quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Quotient() ] + quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Remainder(), member_pages[ quotientIsFirstDestinationPageIndex_remainderIsIndexOfFirstEntryInFirstDestinationPage.Quotient() ] + quotientIsFirstDestinationPageIndex_remainderIsIndexOfFirstEntryInFirstDestinationPage.Remainder(), numberOfEntriesToSetInFirstDestinationPage );

		// This object will store the current destination index
		LargestUnsignedInteger currentDestinationPageIndex = quotientIsFirstDestinationPageIndex_remainderIsIndexOfFirstEntryInFirstDestinationPage.Quotient() + 1UL;

		// This object will store the index on the current destination page, that the entries from the beginning of the current source
		// page needs to be moved to
		const LargestUnsignedInteger currentSourceEntryIndexToMoveEntriesFrom = quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Remainder() + numberOfEntriesToSetInFirstDestinationPage;

		// This object will store the number of entries that can still fit in the end of each destination page
		const LargestUnsignedInteger numberOfEntriesToMoveFromEndingOfCurrentSourcePageToBeginningOfCurrentDestinationPage = numberOfEntriesToMoveFromFirstSourcePage - numberOfEntriesToSetInFirstDestinationPage;

		// This object will store the index on the current source page, that entries need to be copied from to the beginning of the next
		// destination page
		const LargestUnsignedInteger currentDestinationEntryIndexToMoveEntriesTo = numberOfEntriesToMoveFromEndingOfCurrentSourcePageToBeginningOfCurrentDestinationPage;

		// This object will store the number of entries that needs to be moved from the end of the current source page to the beginning of the 
		// next destination page
		const LargestUnsignedInteger numberOfEntriesToMoveFromBeginningOfNextSourcePageToEndingOfCurrentDestinationPage = member_pageSize - numberOfEntriesToMoveFromEndingOfCurrentSourcePageToBeginningOfCurrentDestinationPage;

		// This object will store the source page index at which the loop needs to stop at
		const LargestUnsignedInteger stopAtThisSourcePageIndex = quotientIsLastSourcePageIndex_remainderIsIndexOfFirstEntryThatDoesNotNeedToBeMovedInLastSourcePage.Quotient() - 1UL;

		// Loop on all the pages that needs to be moved
		for ( LargestUnsignedInteger currentSourcePageIndex = quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Quotient() ; currentSourcePageIndex < stopAtThisSourcePageIndex ; ++currentSourcePageIndex )
		{
			// Move the entries from the ending of the current source page, to the beginning of the current destination page
			Memory::Operations::Move< DataType >( member_pages[ currentSourcePageIndex ] + currentSourceEntryIndexToMoveEntriesFrom, member_pages[ currentDestinationPageIndex ], numberOfEntriesToMoveFromEndingOfCurrentSourcePageToBeginningOfCurrentDestinationPage );
		    			
			// Move the entries from the beginning of the next source page, to the ending of the next destination page
			Memory::Operations::Move< DataType >( member_pages[ currentSourcePageIndex + 1UL ], member_pages[ currentDestinationPageIndex ] + currentDestinationEntryIndexToMoveEntriesTo, numberOfEntriesToMoveFromBeginningOfNextSourcePageToEndingOfCurrentDestinationPage );
		}

		// Move the entries from the ending of the one before last source page, to the beginning of the last destination page
		Memory::Operations::Move< DataType >( member_pages[ quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Quotient() - 1UL ] + currentSourceEntryIndexToMoveEntriesFrom, member_pages[ quotientIsFirstDestinationPageIndex_remainderIsIndexOfFirstEntryInFirstDestinationPage.Quotient() ], numberOfEntriesToMoveFromEndingOfCurrentSourcePageToBeginningOfCurrentDestinationPage );

		// Move the entries from the beginning last source page, to the required location in the last destination page
		Memory::Operations::Move< DataType >( member_pages[ quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Quotient() ], member_pages[ quotientIsFirstDestinationPageIndex_remainderIsIndexOfFirstEntryInFirstDestinationPage.Quotient() ] + currentDestinationEntryIndexToMoveEntriesTo, numberOfEntriesToMoveFromLastSourcePage );
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void PagesArray< DataType, MemoryManagerType >::MoveEntriesTowardsTheEnding__Private( const LargestUnsignedInteger absoluteSourceIndex, const LargestUnsignedInteger absoluteDestinationIndex, const LargestUnsignedInteger sizeToMove )
{
	// FIRST PAGE INFORMATION :

    // This object will store the page index at which the first entry that needs be moved is located, and the index of the first entry in
    // that page that needs to be moved
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage = CentralProcessingUnit::Arithmetics::Divison( absoluteSourceIndex, member_pageSize );

    // This object will store the number of entries that needs to be moved from the first page that entries needs to be moved from
    const LargestUnsignedInteger numberOfEntriesToMoveFromFirstSourcePage = member_pageSize - quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Remainder();

    // This object will store the page index to which the first entry needs to be moved to, and the index of the first entry in
    // that page that needs to be set
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits quotientIsFirstDestinationPageIndex_remainderIsIndexOfFirstEntryInFirstDestinationPage = CentralProcessingUnit::Arithmetics::Divison( absoluteDestinationIndex, member_pageSize );

    // This object will store the number of entries that needs to be set in the first page that entries needs to be moved to
    const LargestUnsignedInteger numberOfEntriesToSetInFirstDestinationPage = member_pageSize - quotientIsFirstDestinationPageIndex_remainderIsIndexOfFirstEntryInFirstDestinationPage.Remainder();

    // LAST PAGE INFORMATION :

    // This object will store the page index at which the last entry that needs be moved is located, and the index of the first entry in
    // that page that does not need to be moved
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits quotientIsLastSourcePageIndex_remainderIsIndexOfFirstEntryThatDoesNotNeedToBeMovedInLastSourcePage = CentralProcessingUnit::Arithmetics::Divison( ( absoluteSourceIndex + sizeToMove ), member_pageSize );

    // This object will store the number of entries that needs to be moved from the last page that entries needs to be moved from
    const LargestUnsignedInteger numberOfEntriesToMoveFromLastSourcePage = member_pageSize - quotientIsLastSourcePageIndex_remainderIsIndexOfFirstEntryThatDoesNotNeedToBeMovedInLastSourcePage.Remainder();

    // This object will store the page index to which the last entry needs to be moved to, and the index of the first entry in
    // that page that does not need to be set
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits quotientIsLastDestinationPageIndex_remainderIsIndexOfFirstEntryThatDoesNotNeedToBeSetInLastDestinationPage = CentralProcessingUnit::Arithmetics::Divison( ( absoluteDestinationIndex + sizeToMove ), member_pageSize );

	// Divide the actual index at which the data needs to be inserted to by the page size, and store the quotient and remainder
	const CentralProcessingUnit::DivisonResultUnsignedInteger64bits quotientIsNumberOfPagesThatNeedsToBeMoved_remainderMeansDoesSizeToMoveDivideByPagesSizeWithNoRemainder = CentralProcessingUnit::Arithmetics::Divison( sizeToMove, member_pageSize );

	// Check if the source and destination index are the same
	if ( quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Remainder() == quotientIsFirstDestinationPageIndex_remainderIsIndexOfFirstEntryInFirstDestinationPage.Remainder() )
	{
		// The source and destination index are the same. This means that only the last and first pages needs special care, and all the
		// pages in the middle can be moved as they are

		// Move the entries from the source last page to the destination last page
		Memory::Operations::Move< DataType >( member_pages[ quotientIsLastSourcePageIndex_remainderIsIndexOfFirstEntryThatDoesNotNeedToBeMovedInLastSourcePage.Quotient() ], member_pages[ quotientIsLastDestinationPageIndex_remainderIsIndexOfFirstEntryThatDoesNotNeedToBeSetInLastDestinationPage.Quotient() ], numberOfEntriesToMoveFromLastSourcePage );

		// This object will store the current destination index
		LargestUnsignedInteger currentDestinationPageIndex = quotientIsLastDestinationPageIndex_remainderIsIndexOfFirstEntryThatDoesNotNeedToBeSetInLastDestinationPage.Quotient() - 1UL;

		// This obejct will store the index of the source page that the loop should stop at
		const LargestUnsignedInteger lastSourcePageIndexToMoveFullPage = quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Quotient() + 1UL;

		// Move all the pages to their required location
		for ( LargestUnsignedInteger currentSourcePageIndex = quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Quotient() + quotientIsNumberOfPagesThatNeedsToBeMoved_remainderMeansDoesSizeToMoveDivideByPagesSizeWithNoRemainder.Quotient() - 1UL ; currentSourcePageIndex > lastSourcePageIndexToMoveFullPage ; --currentSourcePageIndex, --currentDestinationPageIndex )
		{
			// Swap between the current source and destination pointers to the pages
			Memory::Operations::Swap< DataType* >( member_pages[ currentSourcePageIndex ], member_pages[ currentDestinationPageIndex ] );
		}

		// Move the entries from the source first page to the destination first page
		Memory::Operations::Move< DataType >( member_pages[ quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Quotient() ] + quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Remainder(), member_pages[ quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Quotient() ] + quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Remainder(), numberOfEntriesToMoveFromFirstSourcePage );

		// Nothing else needs to be done
		return;
	}

	// Check if the size to move divides by the page size with no remainder
	if ( quotientIsNumberOfPagesThatNeedsToBeMoved_remainderMeansDoesSizeToMoveDivideByPagesSizeWithNoRemainder.Remainder() == 0UL )
	{
		// The size to move divides by the page size with no remainder

		// Check if the source and destination index all point to a start of a page
		if ( quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Remainder() == 0UL && quotientIsFirstDestinationPageIndex_remainderIsIndexOfFirstEntryInFirstDestinationPage.Remainder() == 0UL )
		{
			// The source and destination index all point to a start of a page. This means that there is no need to move entries in the page,
			// and all the pages can be moved as they are from the source to the destination

    		// This object will store the current destination index
    		LargestUnsignedInteger currentDestinationPageIndex = quotientIsLastDestinationPageIndex_remainderIsIndexOfFirstEntryThatDoesNotNeedToBeSetInLastDestinationPage.Quotient() - 1UL;

    		// This obejct will store the index of the source page that the loop should stop at
    		const LargestUnsignedInteger lastSourcePageIndexToMoveFullPage = quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Quotient() + 1UL;

    		// Move all the pages to their required location
    		for ( LargestUnsignedInteger currentSourcePageIndex = quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Quotient() + quotientIsNumberOfPagesThatNeedsToBeMoved_remainderMeansDoesSizeToMoveDivideByPagesSizeWithNoRemainder.Quotient() - 1UL ; currentSourcePageIndex > lastSourcePageIndexToMoveFullPage ; --currentSourcePageIndex, --currentDestinationPageIndex )
    		{
    			// Swap between the current source and destination pointers to the pages
    			Memory::Operations::Swap< DataType* >( member_pages[ currentSourcePageIndex ], member_pages[ currentDestinationPageIndex ] );
    		}

    		// Nothing else needs to be done
    		return;
    	}
	}

	// Check if the number of entreis in the source first page is smaller then the number of entries in the destination first page
	if ( numberOfEntriesToMoveFromFirstSourcePage < numberOfEntriesToSetInFirstDestinationPage )
	{
		// The number of entreis in the source first page is smaller then the number of entries in the destination first page

		// This object will store the current destination index
		LargestUnsignedInteger currentDestinationPageIndex = quotientIsFirstDestinationPageIndex_remainderIsIndexOfFirstEntryInFirstDestinationPage.Quotient();

		// This object will store the index on the current destination page, that the entries from the beginning of the current source
		// page needs to be moved to
		const LargestUnsignedInteger currentDestinationEntryIndexToMoveEntriesTo = quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Remainder() + numberOfEntriesToMoveFromFirstSourcePage;

		// This object will store the number of entries that can still fit in the end of each destination page
		const LargestUnsignedInteger numberOfEntriesToMoveFromBeginningOfCurrentSourcePageToEndOfCurrentDestinationPage = numberOfEntriesToSetInFirstDestinationPage - numberOfEntriesToMoveFromFirstSourcePage;

		// This object will store the index on the current source page, that entries need to be copied from to the beginning of the next
		// destination page
		const LargestUnsignedInteger currentSourceEntryIndexToMoveEntriesFrom = numberOfEntriesToMoveFromBeginningOfCurrentSourcePageToEndOfCurrentDestinationPage;

		// This object will store the number of entries that needs to be moved from the end of the current source page to the beginning of the 
		// next destination page
		const LargestUnsignedInteger numberOfEntriesToMoveFromEndingOfCurrentSourcePageToBeginningOfNextDestinationPage = member_pageSize - numberOfEntriesToMoveFromBeginningOfCurrentSourcePageToEndOfCurrentDestinationPage;

		// This object will store the number of entries left to move from the last source page to the beginning of the last destination page
		const LargestUnsignedInteger numberOfEntriesLeftToMoveFromLastSourcePage = numberOfEntriesToMoveFromLastSourcePage - numberOfEntriesToMoveFromBeginningOfCurrentSourcePageToEndOfCurrentDestinationPage;

		// Move the entries left from the last source page, to the beginning of the last destination page
		Memory::Operations::Move< DataType >( member_pages[ quotientIsLastSourcePageIndex_remainderIsIndexOfFirstEntryThatDoesNotNeedToBeMovedInLastSourcePage.Quotient() ] + numberOfEntriesToMoveFromBeginningOfCurrentSourcePageToEndOfCurrentDestinationPage, member_pages[ quotientIsLastDestinationPageIndex_remainderIsIndexOfFirstEntryThatDoesNotNeedToBeSetInLastDestinationPage.Quotient() ], numberOfEntriesLeftToMoveFromLastSourcePage );

		// Move the entries that can fit from the beginning of the last source page, to the end of the one before last destination page
		Memory::Operations::Move< DataType >( member_pages[ quotientIsLastSourcePageIndex_remainderIsIndexOfFirstEntryThatDoesNotNeedToBeMovedInLastSourcePage.Quotient() ], member_pages[ quotientIsLastDestinationPageIndex_remainderIsIndexOfFirstEntryThatDoesNotNeedToBeSetInLastDestinationPage.Quotient() - 1UL ] + currentDestinationEntryIndexToMoveEntriesTo, numberOfEntriesToMoveFromBeginningOfCurrentSourcePageToEndOfCurrentDestinationPage );

		// This object will store the index on the source at which the loop should stop at
		const LargestUnsignedInteger stopLoopAtThisSourcePageIndex = quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Quotient() + 1UL;

		// Loop on all the pages that needs to be moved
		for ( LargestUnsignedInteger currentSourcePageIndex = quotientIsLastSourcePageIndex_remainderIsIndexOfFirstEntryThatDoesNotNeedToBeMovedInLastSourcePage.Quotient() ; currentSourcePageIndex > stopLoopAtThisSourcePageIndex ; --currentSourcePageIndex )
		{
			// Move the entries from the ending of the current source page, to the beginning of the next destination page
			Memory::Operations::Move< DataType >( member_pages[ currentSourcePageIndex ] + currentSourceEntryIndexToMoveEntriesFrom, member_pages[ currentDestinationPageIndex + 1UL ], numberOfEntriesToMoveFromEndingOfCurrentSourcePageToBeginningOfNextDestinationPage );

			// Move the entries from the beginning of the current source page, to the ending of the current destination page
			Memory::Operations::Move< DataType >( member_pages[ currentSourcePageIndex ], member_pages[ currentDestinationPageIndex ] + currentDestinationEntryIndexToMoveEntriesTo, numberOfEntriesToMoveFromBeginningOfCurrentSourcePageToEndOfCurrentDestinationPage );
		}

		// Only the first page that data needs to be moved from, needs be handled now

		// Move all the entries from the source first page to the destination first page
		Memory::Operations::Move< DataType >( member_pages[ quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Quotient() ] + quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Remainder(), member_pages[ quotientIsFirstDestinationPageIndex_remainderIsIndexOfFirstEntryInFirstDestinationPage.Quotient() ] + quotientIsFirstDestinationPageIndex_remainderIsIndexOfFirstEntryInFirstDestinationPage.Remainder(), numberOfEntriesToMoveFromFirstSourcePage );
	}
	else if ( numberOfEntriesToMoveFromFirstSourcePage > numberOfEntriesToSetInFirstDestinationPage )
	{
		// The number of entreis in the source first page is larger then the number of entries in the destination first page

		// This object will store the current destination index
		LargestUnsignedInteger currentDestinationPageIndex = quotientIsFirstDestinationPageIndex_remainderIsIndexOfFirstEntryInFirstDestinationPage.Quotient() + 1UL;

		// This object will store the index on the current destination page, that the entries from the beginning of the current source
		// page needs to be moved to
		const LargestUnsignedInteger currentSourceEntryIndexToMoveEntriesFrom = quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Remainder() + numberOfEntriesToSetInFirstDestinationPage;

		// This object will store the number of entries that can still fit in the end of each destination page
		const LargestUnsignedInteger numberOfEntriesToMoveFromEndingOfCurrentSourcePageToBeginningOfCurrentDestinationPage = numberOfEntriesToMoveFromFirstSourcePage - numberOfEntriesToSetInFirstDestinationPage;

		// This object will store the index on the current source page, that entries need to be copied from to the beginning of the next
		// destination page
		const LargestUnsignedInteger currentDestinationEntryIndexToMoveEntriesTo = numberOfEntriesToMoveFromEndingOfCurrentSourcePageToBeginningOfCurrentDestinationPage;

		// This object will store the number of entries that needs to be moved from the end of the current source page to the beginning of the 
		// next destination page
		const LargestUnsignedInteger numberOfEntriesToMoveFromBeginningOfNextSourcePageToEndingOfCurrentDestinationPage = member_pageSize - numberOfEntriesToMoveFromEndingOfCurrentSourcePageToBeginningOfCurrentDestinationPage;

		// Move the entries from the beginning last source page, to the required location in the last destination page
		Memory::Operations::Move< DataType >( member_pages[ quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Quotient() ], member_pages[ quotientIsFirstDestinationPageIndex_remainderIsIndexOfFirstEntryInFirstDestinationPage.Quotient() ] + currentDestinationEntryIndexToMoveEntriesTo, numberOfEntriesToMoveFromLastSourcePage );

		// Move the entries from the ending of the one before last source page, to the beginning of the last destination page
		Memory::Operations::Move< DataType >( member_pages[ quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Quotient() - 1UL ] + currentSourceEntryIndexToMoveEntriesFrom, member_pages[ quotientIsFirstDestinationPageIndex_remainderIsIndexOfFirstEntryInFirstDestinationPage.Quotient() ], numberOfEntriesToMoveFromEndingOfCurrentSourcePageToBeginningOfCurrentDestinationPage );

		// Loop on all the pages that needs to be moved
		for ( LargestUnsignedInteger currentSourcePageIndex = quotientIsLastSourcePageIndex_remainderIsIndexOfFirstEntryThatDoesNotNeedToBeMovedInLastSourcePage.Quotient() - 1UL ; currentSourcePageIndex > quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Quotient() ; --currentSourcePageIndex )
		{
			// Move the entries from the beginning of the next source page, to the ending of the next destination page
			Memory::Operations::Move< DataType >( member_pages[ currentSourcePageIndex + 1UL ], member_pages[ currentDestinationPageIndex ] + currentDestinationEntryIndexToMoveEntriesTo, numberOfEntriesToMoveFromBeginningOfNextSourcePageToEndingOfCurrentDestinationPage );

			// Move the entries from the ending of the current source page, to the beginning of the current destination page
			Memory::Operations::Move< DataType >( member_pages[ currentSourcePageIndex ] + currentSourceEntryIndexToMoveEntriesFrom, member_pages[ currentDestinationPageIndex ], numberOfEntriesToMoveFromEndingOfCurrentSourcePageToBeginningOfCurrentDestinationPage );
		}

		// Move all the entries from the source first page to the destination first page
		Memory::Operations::Move< DataType >( member_pages[ quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Quotient() ] + quotientIsFirstSourcePageIndex_remainderIsIndexOfFirstEntryInFirstSourcePage.Remainder(), member_pages[ quotientIsFirstDestinationPageIndex_remainderIsIndexOfFirstEntryInFirstDestinationPage.Quotient() ] + quotientIsFirstDestinationPageIndex_remainderIsIndexOfFirstEntryInFirstDestinationPage.Remainder(), numberOfEntriesToSetInFirstDestinationPage );
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< template< typename, typename > class OtherMemoryHandlerType, typename OtherMemoryHandlerMemoryManagerType >
void PagesArray< DataType, MemoryManagerType >::CopyDataFromOtherInstanceToThisInstance__Private( const OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >& other, const LargestUnsignedInteger thisInstanceFirstIndex, const LargestUnsignedInteger otherInstanceFirstIndex, const LargestUnsignedInteger size )
{
    // This object will store the index at which the loop should stop
    const LargestUnsignedInteger stopAtThisIndex = otherInstanceFirstIndex + size;

    // This object will store the current page index
    LargestUnsignedInteger thisInstancePageIndex = thisInstanceFirstIndex / member_pageSize;

    // This object will store the current entry index in the current page
    LargestUnsignedInteger thisInstanceCurrentEntryIndexInPage = thisInstanceFirstIndex % member_pageSize;

    // Loop on the required entries and assign the data from the other instance into this instance
    for ( LargestUnsignedInteger otherInstanceIndex = otherInstanceFirstIndex ; otherInstanceIndex < stopAtThisIndex ; ++otherInstanceIndex )
    {
        // Copy the value from the other instance to this instance
        member_pages[ thisInstancePageIndex ][ thisInstanceCurrentEntryIndexInPage ] = other[ otherInstanceIndex ];

        // Check if all the current page entries were set
        if ( member_pageSize == thisInstanceCurrentEntryIndexInPage + 1UL )
        {
        	// All the entries of the current page were set. This means that the page index needs be incremnted by 1, and the entry index
        	// in the page set back to zero

        	// Increment the page index by 1
        	thisInstancePageIndex += 1UL;

        	// Set the index of the entry in the page to 0
        	thisInstanceCurrentEntryIndexInPage = 0UL;
        }
    }
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename OtherPagesArrayMemoryManagerType >
void PagesArray< DataType, MemoryManagerType >::CopyDataFromOtherInstanceToThisInstance__Private( const PagesArray< DataType, OtherPagesArrayMemoryManagerType >& other, const LargestUnsignedInteger thisInstanceFirstIndex, const LargestUnsignedInteger otherInstanceFirstIndex, const LargestUnsignedInteger size )
{
    // This object will store the index of the first page that needs to be set, and the index of the first entry in that page that needs
    // to be set. All the properties will belong to this instance
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet = GetPageIndexAndEntryIndexInPage__Private( thisInstanceFirstIndex );

    // This object will store the index of the first page that needs to be set, and the index of the first entry in that page that needs
    // to be set. All the properties will belong to the other instance
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy = other.GetPageIndexAndEntryIndexInPage__Private( otherInstanceFirstIndex );

    // This object will store the number of entries that needs to be set in the first page
    const LargestUnsignedInteger thisInstance_numberOfEntriesToSetInFirstPage = member_pageSize - thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Remainder();

    // This object will store the number of entries that needs to be set in the first page
    const LargestUnsignedInteger otherInstance_numberOfEntriesToCopyFromFirstPage = member_pageSize - otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Remainder();

    // This object will store the index of the first page that needs to be set, and the index of the first entry in that page that needs
    // to be set. All the properties will belong to this instance
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet = GetPageIndexAndEntryIndexInPage__Private( thisInstanceFirstIndex + size );

    // This object will store the index of the first page that needs to be set, and the index of the first entry in that page that needs
    // to be set. All the properties will belong to the other instance
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits otherInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet = other.GetPageIndexAndEntryIndexInPage__Private( otherInstanceFirstIndex + size );

    // Check if the number of entries in the first page of this instance is larger then in the other instance
    if ( thisInstance_numberOfEntriesToSetInFirstPage > otherInstance_numberOfEntriesToCopyFromFirstPage )
    {
    	// The number of entries in the first page of this instance is larger then in the other instance

    	// Copy the entries that can fit into the first page of this instance from the other instance first page
    	Memory::Operations::Copy< DataType >( other.member_pages[ otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Quotient() ] + otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Remainder(), member_pages[ thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Quotient() ] + thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Remainder(), otherInstance_numberOfEntriesToCopyFromFirstPage );

    	// This object will store the index of the current page copied from the other instance
    	LargestUnsignedInteger otherInstance_pageIndex = otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Quotient() + 1UL;

    	// This object will store the number of entries that needs to be copied from the beginning of a page in the other instance, to the ending
    	// of the current page in this instance
    	const LargestUnsignedInteger numberOfEntriesToCopyToEndOfCurrentPageInThisInstance = thisInstance_numberOfEntriesToSetInFirstPage - otherInstance_numberOfEntriesToCopyFromFirstPage;

    	// This object will store the index at the ending of the current page in this instance, to which the entries from the beginning of
    	// the current page at the other instance needs to be copied to
    	const LargestUnsignedInteger thisInstance_endEntryIndex = member_pageSize - numberOfEntriesToCopyToEndOfCurrentPageInThisInstance;

    	// This object will store the number of entries that needs to be copied from the ending of a page in the other instance, to the beginning
    	// of the next page in this instance
    	const LargestUnsignedInteger numberOfEntriesToCopyToBeginningOfNextPageInThisInstance = thisInstance_endEntryIndex;

    	// This object will store the index at the ending of the current page in the other instance, from which entries need to be copied to the
    	// next page in this instance
    	const LargestUnsignedInteger otherInstance_endEntryIndex = member_pageSize - numberOfEntriesToCopyToBeginningOfNextPageInThisInstance;

    	// Loop on all the rest of the pages that needs to be copied
    	for ( LargestUnsignedInteger thisInstance_pageIndex = thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Quotient() ; thisInstance_pageIndex < thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ; ++thisInstance_pageIndex, ++otherInstance_pageIndex )
    	{
    		// Copy the required number of entries from the beginning of the page in the other instance, into the required place at the end
    		// of the page in this instance
			Memory::Operations::Copy< DataType >( other.member_pages[ otherInstance_pageIndex ], member_pages[ thisInstance_pageIndex ] + thisInstance_endEntryIndex, numberOfEntriesToCopyToEndOfCurrentPageInThisInstance );
    	
			// Copy the entries left at the end of the current page in the other instance, to the beginning of the next page in this instance
			Memory::Operations::Copy< DataType >( other.member_pages[ otherInstance_pageIndex ] + otherInstance_endEntryIndex, member_pages[ thisInstance_pageIndex + 1UL ], numberOfEntriesToCopyToBeginningOfNextPageInThisInstance );
    	}

		// Copy the requied entries from the last page that needs to be copied from in the other instance, to the beginning of the of one 
		// before the last page that data needs to be copied to in this instance
		Memory::Operations::Copy< DataType >( other.member_pages[ otherInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ], member_pages[ thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() - 1UL ] + thisInstance_endEntryIndex, numberOfEntriesToCopyToEndOfCurrentPageInThisInstance );

    	// Copy all the required entries from the last page that needs to be copied from in the other instance, to the beginning of
    	// the last page that needs to be copied to in this instance
    	Memory::Operations::Copy< DataType >( other.member_pages[ otherInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ] + numberOfEntriesToCopyToEndOfCurrentPageInThisInstance, member_pages[ thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ], thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Remainder() );
    }
    else if ( thisInstance_numberOfEntriesToSetInFirstPage < otherInstance_numberOfEntriesToCopyFromFirstPage )
    {
    	// The number of entries in the first page of this instance is smaller then in the other instance

    	// Copy the entries that can fit into the first page of this instance from the other instance first page
    	Memory::Operations::Copy< DataType >( other.member_pages[ otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Quotient() ] + otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Remainder(), member_pages[ thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Quotient() ] + thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Remainder(), thisInstance_numberOfEntriesToSetInFirstPage );

    	// This object will store the index of the current page copied from the other instance
    	LargestUnsignedInteger otherInstance_pageIndex = otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Quotient();

    	// This object will store the number of entries that needs to be copied from the ending of a page in the other instance, to the beginning
    	// of the current page in this instance
    	const LargestUnsignedInteger numberOfEntriesToCopyToBeginningOfCurrentPageInThisInstance = otherInstance_numberOfEntriesToCopyFromFirstPage - thisInstance_numberOfEntriesToSetInFirstPage;

    	// This object will store the index at the ending of the current page in this instance, to which the entries from the beginning of
    	// the current page at the other instance needs to be copied to
    	const LargestUnsignedInteger thisInstance_endEntryIndex = member_pageSize - numberOfEntriesToCopyToBeginningOfCurrentPageInThisInstance;

    	// This object will store the number of entries that needs to be copied from the ending of a page in the other instance, to the beginning
    	// of the next page in this instance
    	const LargestUnsignedInteger numberOfEntriesToCopyToEndingOfCurrentPageInThisInstance = thisInstance_endEntryIndex;

    	// This object will store the index at the ending of the current page in the other instance, from which entries need to be copied to the
    	// next page in this instance
    	const LargestUnsignedInteger otherInstance_endEntryIndex = member_pageSize - numberOfEntriesToCopyToEndingOfCurrentPageInThisInstance;

    	// Loop on all the rest of the pages that needs to be copied
    	for ( LargestUnsignedInteger thisInstance_pageIndex = thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Quotient() + 1UL ; thisInstance_pageIndex < thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ; ++thisInstance_pageIndex, ++otherInstance_pageIndex )
    	{
    		// Copy the required number of entries from the ending of the page in the other instance, into the required place at the beginning
    		// of the page in this instance
			Memory::Operations::Copy< DataType >( other.member_pages[ otherInstance_pageIndex ] + otherInstance_endEntryIndex, member_pages[ thisInstance_pageIndex ], numberOfEntriesToCopyToBeginningOfCurrentPageInThisInstance );
    	
			// Copy the entries from the beginning of the next page in the other instance, to the ending of the current page in this instance
			Memory::Operations::Copy< DataType >( other.member_pages[ otherInstance_pageIndex + 1UL ], member_pages[ thisInstance_pageIndex ] + thisInstance_endEntryIndex, numberOfEntriesToCopyToEndingOfCurrentPageInThisInstance );
    	}

		// Copy the last entries from one page before the last that needs to be copied from in the other instance, to the beginning of the 
		// last page that data needs to be copied to in this instance
		Memory::Operations::Copy< DataType >( other.member_pages[ otherInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() - 1UL ] + otherInstance_endEntryIndex, member_pages[ thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ], numberOfEntriesToCopyToBeginningOfCurrentPageInThisInstance );

    	// Copy all the required entries from the last page that needs to be copied from in the other instance, to the required location in
    	// the last page that needs to be copied to in this instance
    	Memory::Operations::Copy< DataType >( other.member_pages[ otherInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ], member_pages[ thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ] + numberOfEntriesToCopyToBeginningOfCurrentPageInThisInstance, otherInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Remainder() );
    }
    else
    {
		// The number of entries in the first page of this instance is equal to the other instance

    	// Copy all the entries from the first page that needs to be copied in the other instance to the required page in this instance
    	Memory::Operations::Copy< DataType >( other.member_pages[ otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Quotient() ] + otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Remainder(), member_pages[ thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Quotient() ] + thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Remainder(), thisInstance_numberOfEntriesToSetInFirstPage );

    	// This object will store the index of the current page copied from the other instance
    	LargestUnsignedInteger otherInstance_pageIndex = otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Quotient() + 1UL;

    	// Loop on all the rest of the pages that needs to be copied
    	for ( LargestUnsignedInteger thisInstance_pageIndex = thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Quotient() + 1UL ; thisInstance_pageIndex < thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ; ++thisInstance_pageIndex, ++otherInstance_pageIndex )
    	{
    		// Copy the current page from the other instance to this instance
			Memory::Operations::Copy< DataType >( other.member_pages[ otherInstance_pageIndex ], member_pages[ thisInstance_pageIndex ], member_pageSize );
    	}

    	// Copy all the entries from the last page that needs to be copied in the other instance to the required page in this instance
    	Memory::Operations::Copy< DataType >( other.member_pages[ otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Quotient() ], member_pages[ thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ], thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Remainder() );
    }
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename OtherVectorMemoryManagerType >
void PagesArray< DataType, MemoryManagerType >::CopyDataFromOtherInstanceToThisInstance__Private( const Vector< DataType, OtherVectorMemoryManagerType >& other, const LargestUnsignedInteger thisInstanceFirstIndex, const LargestUnsignedInteger otherInstanceFirstIndex, const LargestUnsignedInteger size )
{
    // This object will store the index of the first page that needs to be set, and the index of the first entry in that page that needs
    // to be set. All the properties will belong to this instance
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet = GetPageIndexAndEntryIndexInPage__Private( thisInstanceFirstIndex );

    // This object will store the number of entries that needs to be set in the first page
    const LargestUnsignedInteger thisInstance_numberOfEntriesToSetInFirstPage = member_pageSize - thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Remainder();

    // This object will store the index of the first page that needs to be set, and the index of the first entry in that page that needs
    // to be set. All the properties will belong to this instance
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet = GetPageIndexAndEntryIndexInPage__Private( thisInstanceFirstIndex + size );

    // This object will store the index on the other instance
    LargestUnsignedInteger otherInstance_Index = otherInstanceFirstIndex;

    // Copy all the required entries from the other instance to the first page that needs to be copied to in this instance
    Memory::Operations::Copy< DataType >( &other[ otherInstance_Index ], member_pages[ thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Quotient() ] + thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Remainder(), thisInstance_numberOfEntriesToSetInFirstPage );

    // Increment the index on the other instance by the number of entries copied already
    otherInstance_Index += thisInstance_numberOfEntriesToSetInFirstPage;

    // Loop on all the pages that needs to be copied to in this instance
	for ( LargestUnsignedInteger thisInstance_pageIndex = thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Quotient() + 1UL ; thisInstance_pageIndex < thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ; ++thisInstance_pageIndex, otherInstance_Index += member_pageSize )
	{
		// Copy the current page from the other instance to this instance
		Memory::Operations::Copy< DataType >( &other[ otherInstance_Index ], member_pages[ thisInstance_pageIndex ], member_pageSize );
	}

	// Copy all the required entries from the other instance to the last page that needs to be copied to in this instance
	Memory::Operations::Copy< DataType >( &other[ otherInstance_Index ], member_pages[ thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ], thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Remainder() );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< template< typename, typename > class OtherMemoryHandlerType, typename OtherMemoryHandlerMemoryManagerType >
void PagesArray< DataType, MemoryManagerType >::CopyDataFromOtherInstanceToThisInstance__Private( OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >&& other, const LargestUnsignedInteger thisInstanceFirstIndex, const LargestUnsignedInteger otherInstanceFirstIndex, const LargestUnsignedInteger size )
{
    // This object will store the index of the first page that needs to be set, and the index of the first entry in that page that needs
    // to be set. All the properties will belong to this instance
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet = GetPageIndexAndEntryIndexInPage__Private( thisInstanceFirstIndex );

    // This object will store the index at which the loop should stop
    const LargestUnsignedInteger stopAtThisIndex = otherInstanceFirstIndex + size;

    // This object will store the current page index
    LargestUnsignedInteger thisInstancePageIndex = thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Quotient();

    // This object will store the current entry index in the current page
    LargestUnsignedInteger thisInstanceCurrentEntryIndexInPage = thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Remainder();

    // Loop on the required entries and assign the data from the other instance into this instance
    for ( LargestUnsignedInteger otherInstanceIndex = otherInstanceFirstIndex ; otherInstanceIndex < stopAtThisIndex ; ++otherInstanceIndex, ++thisInstanceCurrentEntryIndexInPage )
    {
        // Copy the value from the other instance to this instance
        member_pages[ thisInstancePageIndex ][ thisInstanceCurrentEntryIndexInPage ] = TakeResourcesAndLeaveInstanceInDefaultState( other[ otherInstanceIndex ] );

        // Check if all the entries in the current page were set
        if ( member_pageSize == thisInstanceCurrentEntryIndexInPage + 1UL )
        {
        	// All the entries of the current page were set. This means that the page index needs be incremnted by 1, and the entry index
        	// in the page set back to zero

        	// Increment the page index by 1
        	thisInstancePageIndex += 1UL;

        	// Set the index of the entry in the page to 0
        	thisInstanceCurrentEntryIndexInPage = 0UL;
        }
    } 
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename OtherPagesArrayMemoryManagerType >
void PagesArray< DataType, MemoryManagerType >::CopyDataFromOtherInstanceToThisInstance__Private( PagesArray< DataType, OtherPagesArrayMemoryManagerType >&& other, const LargestUnsignedInteger thisInstanceFirstIndex, const LargestUnsignedInteger otherInstanceFirstIndex, const LargestUnsignedInteger size )
{
    // This object will store the index of the first page that needs to be set, and the index of the first entry in that page that needs
    // to be set. All the properties will belong to this instance
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet = GetPageIndexAndEntryIndexInPage__Private( thisInstanceFirstIndex );

    // This object will store the index of the first page that needs to be set, and the index of the first entry in that page that needs
    // to be set. All the properties will belong to the other instance
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy = other.GetPageIndexAndEntryIndexInPage__Private( otherInstanceFirstIndex );

    // This object will store the number of entries that needs to be set in the first page
    const LargestUnsignedInteger thisInstance_numberOfEntriesToSetInFirstPage = member_pageSize - thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Remainder();

    // This object will store the number of entries that needs to be set in the first page
    const LargestUnsignedInteger otherInstance_numberOfEntriesToCopyFromFirstPage = member_pageSize - otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Remainder();

    // This object will store the index of the first page that needs to be set, and the index of the first entry in that page that needs
    // to be set. All the properties will belong to this instance
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet = GetPageIndexAndEntryIndexInPage__Private( thisInstanceFirstIndex + size );

    // This object will store the index of the first page that needs to be set, and the index of the first entry in that page that needs
    // to be set. All the properties will belong to the other instance
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits otherInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet = other.GetPageIndexAndEntryIndexInPage__Private( otherInstanceFirstIndex + size );

    // Check if the number of entries in the first page of this instance is larger then in the other instance
    if ( thisInstance_numberOfEntriesToSetInFirstPage > otherInstance_numberOfEntriesToCopyFromFirstPage )
    {
    	// The number of entries in the first page of this instance is larger then in the other instance

    	// Copy the entries that can fit into the first page of this instance from the other instance first page
    	Memory::Operations::Move< DataType >( other.member_pages[ otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Quotient() ] + otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Remainder(), member_pages[ thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Quotient() ] + thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Remainder(), otherInstance_numberOfEntriesToCopyFromFirstPage );

    	// This object will store the index of the current page copied from the other instance
    	LargestUnsignedInteger otherInstance_pageIndex = otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Quotient() + 1UL;

    	// This object will store the number of entries that needs to be copied from the beginning of a page in the other instance, to the ending
    	// of the current page in this instance
    	const LargestUnsignedInteger numberOfEntriesToCopyToEndOfCurrentPageInThisInstance = thisInstance_numberOfEntriesToSetInFirstPage - otherInstance_numberOfEntriesToCopyFromFirstPage;

    	// This object will store the index at the ending of the current page in this instance, to which the entries from the beginning of
    	// the current page at the other instance needs to be copied to
    	const LargestUnsignedInteger thisInstance_endEntryIndex = member_pageSize - numberOfEntriesToCopyToEndOfCurrentPageInThisInstance;

    	// This object will store the number of entries that needs to be copied from the ending of a page in the other instance, to the beginning
    	// of the next page in this instance
    	const LargestUnsignedInteger numberOfEntriesToCopyToBeginningOfNextPageInThisInstance = thisInstance_endEntryIndex;

    	// This object will store the index at the ending of the current page in the other instance, from which entries need to be copied to the
    	// next page in this instance
    	const LargestUnsignedInteger otherInstance_endEntryIndex = member_pageSize - numberOfEntriesToCopyToBeginningOfNextPageInThisInstance;

    	// Loop on all the rest of the pages that needs to be copied
    	for ( LargestUnsignedInteger thisInstance_pageIndex = thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Quotient() ; thisInstance_pageIndex < thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ; ++thisInstance_pageIndex, ++otherInstance_pageIndex )
    	{
    		// Copy the required number of entries from the beginning of the page in the other instance, into the required place at the end
    		// of the page in this instance
			Memory::Operations::Move< DataType >( other.member_pages[ otherInstance_pageIndex ], member_pages[ thisInstance_pageIndex ] + thisInstance_endEntryIndex, numberOfEntriesToCopyToEndOfCurrentPageInThisInstance );
    	
			// Copy the entries left at the end of the current page in the other instance, to the beginning of the next page in this instance
			Memory::Operations::Move< DataType >( other.member_pages[ otherInstance_pageIndex ] + otherInstance_endEntryIndex, member_pages[ thisInstance_pageIndex + 1UL ], numberOfEntriesToCopyToBeginningOfNextPageInThisInstance );
    	}

		// Copy the requied entries from the last page that needs to be copied from in the other instance, to the beginning of the of one 
		// before the last page that data needs to be copied to in this instance
		Memory::Operations::Move< DataType >( other.member_pages[ otherInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ], member_pages[ thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() - 1UL ] + thisInstance_endEntryIndex, numberOfEntriesToCopyToEndOfCurrentPageInThisInstance );

    	// Copy all the required entries from the last page that needs to be copied from in the other instance, to the beginning of
    	// the last page that needs to be copied to in this instance
    	Memory::Operations::Move< DataType >( other.member_pages[ otherInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ] + numberOfEntriesToCopyToEndOfCurrentPageInThisInstance, member_pages[ thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ], thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Remainder() );
    }
    else if ( thisInstance_numberOfEntriesToSetInFirstPage < otherInstance_numberOfEntriesToCopyFromFirstPage )
    {
    	// The number of entries in the first page of this instance is smaller then in the other instance

    	// Copy the entries that can fit into the first page of this instance from the other instance first page
    	Memory::Operations::Move< DataType >( other.member_pages[ otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Quotient() ] + otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Remainder(), member_pages[ thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Quotient() ] + thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Remainder(), thisInstance_numberOfEntriesToSetInFirstPage );

    	// This object will store the index of the current page copied from the other instance
    	LargestUnsignedInteger otherInstance_pageIndex = otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Quotient();

    	// This object will store the number of entries that needs to be copied from the ending of a page in the other instance, to the beginning
    	// of the current page in this instance
    	const LargestUnsignedInteger numberOfEntriesToCopyToBeginningOfCurrentPageInThisInstance = otherInstance_numberOfEntriesToCopyFromFirstPage - thisInstance_numberOfEntriesToSetInFirstPage;

    	// This object will store the index at the ending of the current page in this instance, to which the entries from the beginning of
    	// the current page at the other instance needs to be copied to
    	const LargestUnsignedInteger thisInstance_endEntryIndex = member_pageSize - numberOfEntriesToCopyToBeginningOfCurrentPageInThisInstance;

    	// This object will store the number of entries that needs to be copied from the ending of a page in the other instance, to the beginning
    	// of the next page in this instance
    	const LargestUnsignedInteger numberOfEntriesToCopyToEndingOfCurrentPageInThisInstance = thisInstance_endEntryIndex;

    	// This object will store the index at the ending of the current page in the other instance, from which entries need to be copied to the
    	// next page in this instance
    	const LargestUnsignedInteger otherInstance_endEntryIndex = member_pageSize - numberOfEntriesToCopyToEndingOfCurrentPageInThisInstance;

    	// Loop on all the rest of the pages that needs to be copied
    	for ( LargestUnsignedInteger thisInstance_pageIndex = thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Quotient() + 1UL ; thisInstance_pageIndex < thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ; ++thisInstance_pageIndex, ++otherInstance_pageIndex )
    	{
    		// Copy the required number of entries from the ending of the page in the other instance, into the required place at the beginning
    		// of the page in this instance
			Memory::Operations::Move< DataType >( other.member_pages[ otherInstance_pageIndex ] + otherInstance_endEntryIndex, member_pages[ thisInstance_pageIndex ], numberOfEntriesToCopyToBeginningOfCurrentPageInThisInstance );
    	
			// Copy the entries from the beginning of the next page in the other instance, to the ending of the current page in this instance
			Memory::Operations::Move< DataType >( other.member_pages[ otherInstance_pageIndex + 1UL ], member_pages[ thisInstance_pageIndex ] + thisInstance_endEntryIndex, numberOfEntriesToCopyToEndingOfCurrentPageInThisInstance );
    	}

		// Copy the last entries from one page before the last that needs to be copied from in the other instance, to the beginning of the 
		// last page that data needs to be copied to in this instance
		Memory::Operations::Move< DataType >( other.member_pages[ otherInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() - 1UL ] + otherInstance_endEntryIndex, member_pages[ thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ], numberOfEntriesToCopyToBeginningOfCurrentPageInThisInstance );

    	// Copy all the required entries from the last page that needs to be copied from in the other instance, to the required location in
    	// the last page that needs to be copied to in this instance
    	Memory::Operations::Move< DataType >( other.member_pages[ otherInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ], member_pages[ thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ] + numberOfEntriesToCopyToBeginningOfCurrentPageInThisInstance, otherInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Remainder() );
    }
    else
    {
		// The number of entries in the first page of this instance is equal to the other instance

    	// Copy all the entries from the first page that needs to be copied in the other instance to the required page in this instance
    	Memory::Operations::Move< DataType >( other.member_pages[ otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Quotient() ] + otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Remainder(), member_pages[ thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Quotient() ] + thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Remainder(), thisInstance_numberOfEntriesToSetInFirstPage );

    	// This object will store the index of the current page copied from the other instance
    	LargestUnsignedInteger otherInstance_pageIndex = otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Quotient() + 1UL;

    	// Loop on all the rest of the pages that needs to be copied
    	for ( LargestUnsignedInteger thisInstance_pageIndex = thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Quotient() + 1UL ; thisInstance_pageIndex < thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ; ++thisInstance_pageIndex, ++otherInstance_pageIndex )
    	{
    		// Copy the current page from the other instance to this instance
			Memory::Operations::Move< DataType >( other.member_pages[ otherInstance_pageIndex ], member_pages[ thisInstance_pageIndex ], member_pageSize );
    	}

    	// Copy all the entries from the last page that needs to be copied in the other instance to the required page in this instance
    	Memory::Operations::Move< DataType >( other.member_pages[ otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Quotient() ], member_pages[ thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ], thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Remainder() );
    } 
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename OtherVectorMemoryManagerType >
void PagesArray< DataType, MemoryManagerType >::CopyDataFromOtherInstanceToThisInstance__Private( Vector< DataType, OtherVectorMemoryManagerType >&& other, const LargestUnsignedInteger thisInstanceFirstIndex, const LargestUnsignedInteger otherInstanceFirstIndex, const LargestUnsignedInteger size )
{
    // This object will store the index of the first page that needs to be set, and the index of the first entry in that page that needs
    // to be set. All the properties will belong to this instance
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet = GetPageIndexAndEntryIndexInPage__Private( thisInstanceFirstIndex );

    // This object will store the number of entries that needs to be set in the first page
    const LargestUnsignedInteger thisInstance_numberOfEntriesToSetInFirstPage = member_pageSize - thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Remainder();

    // This object will store the index of the first page that needs to be set, and the index of the first entry in that page that needs
    // to be set. All the properties will belong to this instance
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet = GetPageIndexAndEntryIndexInPage__Private( thisInstanceFirstIndex + size );

    // This object will store the index on the other instance
    LargestUnsignedInteger otherInstance_Index = otherInstanceFirstIndex;

    // Copy all the required entries from the other instance to the first page that needs to be copied to in this instance
    Memory::Operations::Move< DataType >( &other[ otherInstance_Index ], member_pages[ thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Quotient() ] + thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Remainder(), thisInstance_numberOfEntriesToSetInFirstPage );

    // Increment the index on the other instance by the number of entries copied already
    otherInstance_Index += thisInstance_numberOfEntriesToSetInFirstPage;

    // Loop on all the pages that needs to be copied to in this instance
	for ( LargestUnsignedInteger thisInstance_pageIndex = thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Quotient() + 1UL ; thisInstance_pageIndex < thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ; ++thisInstance_pageIndex, otherInstance_Index += member_pageSize )
	{
		// Copy the current page from the other instance to this instance
		Memory::Operations::Move< DataType >( &other[ otherInstance_Index ], member_pages[ thisInstance_pageIndex ], member_pageSize );
	}

	// Copy all the required entries from the other instance to the last page that needs to be copied to in this instance
	Memory::Operations::Move< DataType >( &other[ otherInstance_Index ], member_pages[ thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ], thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Remainder() );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename OtherPagesArrayMemoryManagerType >
inline Boolean PagesArray< DataType, MemoryManagerType >::CompareWithOtherInstance__Private( const PagesArray< DataType, OtherPagesArrayMemoryManagerType >& other ) const
{
    // This object will store the index of the first page that needs to be set, and the index of the first entry in that page that needs
    // to be set. All the properties will belong to this instance
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet = GetPageIndexAndEntryIndexInPage__Private( 0UL );

    // This object will store the index of the first page that needs to be set, and the index of the first entry in that page that needs
    // to be set. All the properties will belong to the other instance
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy = other.GetPageIndexAndEntryIndexInPage__Private( 0UL );

    // This object will store the number of entries that needs to be set in the first page
    const LargestUnsignedInteger thisInstance_numberOfEntriesToSetInFirstPage = member_pageSize - thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Remainder();

    // This object will store the number of entries that needs to be set in the first page
    const LargestUnsignedInteger otherInstance_numberOfEntriesToCopyFromFirstPage = member_pageSize - otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Remainder();

    // This object will store the index of the first page that needs to be set, and the index of the first entry in that page that needs
    // to be set. All the properties will belong to this instance
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet = GetPageIndexAndEntryIndexInPage__Private( member_size );

    // This object will store the index of the first page that needs to be set, and the index of the first entry in that page that needs
    // to be set. All the properties will belong to the other instance
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits otherInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet = other.GetPageIndexAndEntryIndexInPage__Private( other.member_size );

    // Check if the number of entries in the first page of this instance is larger then in the other instance
    if ( thisInstance_numberOfEntriesToSetInFirstPage > otherInstance_numberOfEntriesToCopyFromFirstPage )
    {
    	// The number of entries in the first page of this instance is larger then in the other instance

    	// Copy the entries that can fit into the first page of this instance from the other instance first page
    	ReturnValueIfExpressionIsTrue( Memory::Operations::Compare< DataType >( other.member_pages[ otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Quotient() ] + otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Remainder(), member_pages[ thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Quotient() ] + thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Remainder(), otherInstance_numberOfEntriesToCopyFromFirstPage ) == false, false );

    	// This object will store the index of the current page copied from the other instance
    	LargestUnsignedInteger otherInstance_pageIndex = otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Quotient() + 1UL;

    	// This object will store the number of entries that needs to be copied from the beginning of a page in the other instance, to the ending
    	// of the current page in this instance
    	const LargestUnsignedInteger numberOfEntriesToCopyToEndOfCurrentPageInThisInstance = thisInstance_numberOfEntriesToSetInFirstPage - otherInstance_numberOfEntriesToCopyFromFirstPage;

    	// This object will store the index at the ending of the current page in this instance, to which the entries from the beginning of
    	// the current page at the other instance needs to be copied to
    	const LargestUnsignedInteger thisInstance_endEntryIndex = member_pageSize - numberOfEntriesToCopyToEndOfCurrentPageInThisInstance;

    	// This object will store the number of entries that needs to be copied from the ending of a page in the other instance, to the beginning
    	// of the next page in this instance
    	const LargestUnsignedInteger numberOfEntriesToCopyToBeginningOfNextPageInThisInstance = thisInstance_endEntryIndex;

    	// This object will store the index at the ending of the current page in the other instance, from which entries need to be copied to the
    	// next page in this instance
    	const LargestUnsignedInteger otherInstance_endEntryIndex = member_pageSize - numberOfEntriesToCopyToBeginningOfNextPageInThisInstance;

    	// Loop on all the rest of the pages that needs to be copied
    	for ( LargestUnsignedInteger thisInstance_pageIndex = thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Quotient() ; thisInstance_pageIndex < thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ; ++thisInstance_pageIndex, ++otherInstance_pageIndex )
    	{
    		// Copy the required number of entries from the beginning of the page in the other instance, into the required place at the end
    		// of the page in this instance
			ReturnValueIfExpressionIsTrue( Memory::Operations::Compare< DataType >( other.member_pages[ otherInstance_pageIndex ], member_pages[ thisInstance_pageIndex ] + thisInstance_endEntryIndex, numberOfEntriesToCopyToEndOfCurrentPageInThisInstance ) == false, false );
    	
			// Copy the entries left at the end of the current page in the other instance, to the beginning of the next page in this instance
			ReturnValueIfExpressionIsTrue( Memory::Operations::Compare< DataType >( other.member_pages[ otherInstance_pageIndex ] + otherInstance_endEntryIndex, member_pages[ thisInstance_pageIndex + 1UL ], numberOfEntriesToCopyToBeginningOfNextPageInThisInstance ) == false, false );
    	}

		// Copy the requied entries from the last page that needs to be copied from in the other instance, to the beginning of the of one 
		// before the last page that data needs to be copied to in this instance
		ReturnValueIfExpressionIsTrue( Memory::Operations::Compare< DataType >( other.member_pages[ otherInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ], member_pages[ thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() - 1UL ] + thisInstance_endEntryIndex, numberOfEntriesToCopyToEndOfCurrentPageInThisInstance ) == false, false );

    	// Copy all the required entries from the last page that needs to be copied from in the other instance, to the beginning of
    	// the last page that needs to be copied to in this instance
    	ReturnValueIfExpressionIsTrue( Memory::Operations::Compare< DataType >( other.member_pages[ otherInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ] + numberOfEntriesToCopyToEndOfCurrentPageInThisInstance, member_pages[ thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ], thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Remainder() ) == false, false );
    }
    else if ( thisInstance_numberOfEntriesToSetInFirstPage < otherInstance_numberOfEntriesToCopyFromFirstPage )
    {
    	// The number of entries in the first page of this instance is smaller then in the other instance

    	// Copy the entries that can fit into the first page of this instance from the other instance first page
    	ReturnValueIfExpressionIsTrue( Memory::Operations::Compare< DataType >( other.member_pages[ otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Quotient() ] + otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Remainder(), member_pages[ thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Quotient() ] + thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Remainder(), thisInstance_numberOfEntriesToSetInFirstPage ) == false, false );

    	// This object will store the index of the current page copied from the other instance
    	LargestUnsignedInteger otherInstance_pageIndex = otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Quotient();

    	// This object will store the number of entries that needs to be copied from the ending of a page in the other instance, to the beginning
    	// of the current page in this instance
    	const LargestUnsignedInteger numberOfEntriesToCopyToBeginningOfCurrentPageInThisInstance = otherInstance_numberOfEntriesToCopyFromFirstPage - thisInstance_numberOfEntriesToSetInFirstPage;

    	// This object will store the index at the ending of the current page in this instance, to which the entries from the beginning of
    	// the current page at the other instance needs to be copied to
    	const LargestUnsignedInteger thisInstance_endEntryIndex = member_pageSize - numberOfEntriesToCopyToBeginningOfCurrentPageInThisInstance;

    	// This object will store the number of entries that needs to be copied from the ending of a page in the other instance, to the beginning
    	// of the next page in this instance
    	const LargestUnsignedInteger numberOfEntriesToCopyToEndingOfCurrentPageInThisInstance = thisInstance_endEntryIndex;

    	// This object will store the index at the ending of the current page in the other instance, from which entries need to be copied to the
    	// next page in this instance
    	const LargestUnsignedInteger otherInstance_endEntryIndex = member_pageSize - numberOfEntriesToCopyToEndingOfCurrentPageInThisInstance;

    	// Loop on all the rest of the pages that needs to be copied
    	for ( LargestUnsignedInteger thisInstance_pageIndex = thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Quotient() + 1UL ; thisInstance_pageIndex < thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ; ++thisInstance_pageIndex, ++otherInstance_pageIndex )
    	{
    		// Copy the required number of entries from the ending of the page in the other instance, into the required place at the beginning
    		// of the page in this instance
			ReturnValueIfExpressionIsTrue( Memory::Operations::Compare< DataType >( other.member_pages[ otherInstance_pageIndex ] + otherInstance_endEntryIndex, member_pages[ thisInstance_pageIndex ], numberOfEntriesToCopyToBeginningOfCurrentPageInThisInstance ) == false, false );
    	
			// Copy the entries from the beginning of the next page in the other instance, to the ending of the current page in this instance
			ReturnValueIfExpressionIsTrue( Memory::Operations::Compare< DataType >( other.member_pages[ otherInstance_pageIndex + 1UL ], member_pages[ thisInstance_pageIndex ] + thisInstance_endEntryIndex, numberOfEntriesToCopyToEndingOfCurrentPageInThisInstance ) == false, false );
    	}

		// Copy the last entries from one page before the last that needs to be copied from in the other instance, to the beginning of the 
		// last page that data needs to be copied to in this instance
		ReturnValueIfExpressionIsTrue( Memory::Operations::Compare< DataType >( other.member_pages[ otherInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() - 1UL ] + otherInstance_endEntryIndex, member_pages[ thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ], numberOfEntriesToCopyToBeginningOfCurrentPageInThisInstance ) == false, false );

    	// Copy all the required entries from the last page that needs to be copied from in the other instance, to the required location in
    	// the last page that needs to be copied to in this instance
    	ReturnValueIfExpressionIsTrue( Memory::Operations::Compare< DataType >( other.member_pages[ otherInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ], member_pages[ thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ] + numberOfEntriesToCopyToBeginningOfCurrentPageInThisInstance, otherInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Remainder() ) == false, false );
    }
    else
    {
		// The number of entries in the first page of this instance is equal to the other instance

    	// Copy all the entries from the first page that needs to be copied in the other instance to the required page in this instance
    	ReturnValueIfExpressionIsTrue( Memory::Operations::Compare< DataType >( other.member_pages[ otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Quotient() ] + otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Remainder(), member_pages[ thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Quotient() ] + thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Remainder(), thisInstance_numberOfEntriesToSetInFirstPage ) == false, false );

    	// This object will store the index of the current page copied from the other instance
    	LargestUnsignedInteger otherInstance_pageIndex = otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Quotient() + 1UL;

    	// Loop on all the rest of the pages that needs to be copied
    	for ( LargestUnsignedInteger thisInstance_pageIndex = thisInstance_quotientIsFirstPageToSetIndex_remainderIsIndexOfFirstEntryInFirstPageToSet.Quotient() + 1UL ; thisInstance_pageIndex < thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ; ++thisInstance_pageIndex, ++otherInstance_pageIndex )
    	{
    		// Copy the current page from the other instance to this instance
			ReturnValueIfExpressionIsTrue( Memory::Operations::Compare< DataType >( other.member_pages[ otherInstance_pageIndex ], member_pages[ thisInstance_pageIndex ], member_pageSize ) == false, false );
    	}

    	// Copy all the entries from the last page that needs to be copied in the other instance to the required page in this instance
    	ReturnValueIfExpressionIsTrue( Memory::Operations::Compare< DataType >( other.member_pages[ otherInstance_quotientIsFirstPageToCopyIndex_remainderIsIndexOfFirstEntryInFirstPageToCopy.Quotient() ], member_pages[ thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Quotient() ], thisInstance_quotientIsLastPageToSetIndex_remainderIsIndexOfFirstEntryInLastPageThatDoesNotNeedToBeSet.Remainder() ) == false, false );
    }

    // The content of the two instance is the same, return true
    return ( true );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< Concepts::RawButPointerIsAllowed DataType COMMA typename MemoryManagerType >
	void PagesArray< DataType COMMA MemoryManagerType >::Display()
	{
		std::cout << "Number of pages is - " << member_pages.Size() << std::endl;
		std::cout << "First entry index - " << member_indexOfFirstEntryUsedInFirstPageIndex << std::endl << std::endl;

		for ( LargestUnsignedInteger index = 0UL ; index < member_indexOfFirstEntryUsedInFirstPageIndex ; ++index )
		{
			std::cout << "X" << " ";
		}

		for ( LargestUnsignedInteger index = 0UL ; index < member_pageSize - member_indexOfFirstEntryUsedInFirstPageIndex ; ++index )
		{
			std::cout << (*this)[ index ] << " ";
		}

		std::cout << std::endl;

		LargestUnsignedInteger mm = 0;
		LargestUnsignedInteger index = member_pageSize - member_indexOfFirstEntryUsedInFirstPageIndex;

		while ( index < member_size )
		{
			if ( index != 0UL && index % ( member_pageSize + ( member_pageSize - member_indexOfFirstEntryUsedInFirstPageIndex ) ) == 0UL )
			{
				break;
			}

			std::cout << (*this)[ index ] << " ";

			++index;
		}

		std::cout << std::endl;

		while ( index < member_size )
		{
			std::cout << (*this)[ index ] << " ";

			++index;
			++mm;

			if ( mm == 8 )
			{
				std::cout << std::endl;

				mm = 0;
			}
		}

		for ( LargestUnsignedInteger inde = 0UL ; inde < member_pages.Size() * member_pageSize - member_indexOfFirstEntryUsedInFirstPageIndex - member_size ; ++inde )
		{
			std::cout << "X" << " ";
		}
	}

	template< Concepts::RawButPointerIsAllowed DataType COMMA typename MemoryManagerType >
	void ComparePagesArrayWithVector( const PagesArray< DataType COMMA MemoryManagerType >& pagesArray, const Vector< DataType >& vector )
	{
		Assert_Test( pagesArray.Size() == vector.Size() );

		for ( LargestUnsignedInteger index = 0UL ; index < pagesArray.Size() ; ++index )
		{
			Assert_Test( pagesArray[ index ] == vector[ index ] );
		}
	}

	template< Concepts::RawButPointerIsAllowed DataType COMMA typename MemoryManagerType >
	inline void PagesArray< DataType COMMA MemoryManagerType >::UnitTest()
	{
		// Create an heap array test instance to check the correctness of the pages array functionality
		Vector< LargestUnsignedInteger > testVector_0( 14UL, 1UL );

		// Create a test instance
		PagesArray< LargestUnsignedInteger > testPagesArray_0( 14UL, 1UL );

		// Compare the instances
		ComparePagesArrayWithVector< LargestUnsignedInteger >( testPagesArray_0, testVector_0 );

		// Ensure the size is correct
		Assert_Test( testPagesArray_0.Size() == 14UL );

		// Insert single element
		testVector_0.InsertSingleElement( 0UL, 2UL );
		testPagesArray_0.InsertSingleElement( 0UL, 2UL );

		// Compare the instances
		ComparePagesArrayWithVector< LargestUnsignedInteger >( testPagesArray_0, testVector_0 );

		// Insert single element
		testVector_0.InsertSingleElement( 0UL, 4UL );
		testPagesArray_0.InsertSingleElement( 0UL, 4UL );

		// Compare the instances
		ComparePagesArrayWithVector< LargestUnsignedInteger >( testPagesArray_0, testVector_0 );

		// Insert single element
		testVector_0.InsertSingleElement( testVector_0.Size(), 4UL );
		testPagesArray_0.InsertSingleElement( testPagesArray_0.Size(), 4UL );

		// Compare the instances
		ComparePagesArrayWithVector< LargestUnsignedInteger >( testPagesArray_0, testVector_0 );

		// Insert single element
		testVector_0.InsertSingleElement( testVector_0.Size(), 5UL );
		testPagesArray_0.InsertSingleElement( testPagesArray_0.Size(), 5UL );

		// Compare the instances
		ComparePagesArrayWithVector< LargestUnsignedInteger >( testPagesArray_0, testVector_0 );

		// Insert single element
		testVector_0.InsertSingleElement( testVector_0.Size(), 6UL );
		testPagesArray_0.InsertSingleElement( testPagesArray_0.Size(), 6UL );

		// Compare the instances
		ComparePagesArrayWithVector< LargestUnsignedInteger >( testPagesArray_0, testVector_0 );
	}

)  //  End of debug tool



}  //  Namespace Memory


}  //  Namespace Universe