//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< typename Type >
inline Type* MemoryManagerForConstantSizeAllocations::AllocateAndDefaultConstruct( const LargestUnsignedInteger )
{
	// Check if there is free memory space to allocate
	if ( DoesFreeMemorySpaceExist__Private() == false )
	{
		// There is no more free memory space to allocate

		// Execute the handle
		member_allMemoryIsUsedHandler();
	}

	// Ensure that there is memory space to allocate
    Assert( DoesFreeMemorySpaceExist__Private() == true, "There is no more free memory space" );

	// This object will store the offset in the memory manager to the last memory to provide to the user currently stored
	LargestUnsignedInteger currentLocationInMemoryManagerToProvideToUser = 0UL;

	// Check if the next memory location to allocate index has reached the beginning of the array
	if ( member_nextMemoryLocationsToAllocateLookupTableIndex == 0UL )
	{
		// Store the offset to the last memory to provide to the user currently stored
		currentLocationInMemoryManagerToProvideToUser = member_nextMemoryLocationsToAllocateLookupTable[0];

		// Set the bit on for the location that will provieded in the memory manager, to notify that it is used
		member_memoryManager[ currentLocationInMemoryManagerToProvideToUser ] = BitState::ON;

		// Search the memory manager for the next memory location that can be provided to the user
		SearchForNextFreeLocations__Private();
	}
	else
	{
		// Store the offset to the last memory to provide to the user currently stored
		currentLocationInMemoryManagerToProvideToUser = member_nextMemoryLocationsToAllocateLookupTable[ member_nextMemoryLocationsToAllocateLookupTableIndex ];

		// Set the bit on for the location that will provieded in the memory manager, to notify that it is used
		member_memoryManager[ currentLocationInMemoryManagerToProvideToUser ] = BitState::ON;

		// Decrement the index to next location by 1
		member_nextMemoryLocationsToAllocateLookupTableIndex -= 1UL;
	}


	// Add the offset to the base memory address, and stroe the result memory address casted to the required type
	Type* const resultPointer( reinterpret_cast< Type* >( member_memory.DataPointer() + ( currentLocationInMemoryManagerToProvideToUser * member_constantSizeToAllocateInBytes ) ) );

	// Return the result
	return ( resultPointer );
}


template< typename Type, typename... ConstructorArgumentTypes >
inline Type* MemoryManagerForConstantSizeAllocations::AllocateAndConstruct( ConstructorArgumentTypes&&... constructorArguments )
{
	// Use the main memory manager for this operation, and return the result
	return ( MainMemoryManager::AllocateAndConstruct< Type, ConstructorArgumentTypes ... >( ForwardUniversalReference< ConstructorArgumentTypes >( constructorArguments )... ) );
}



template< typename Type >
inline void MemoryManagerForConstantSizeAllocations::Done( const void* const pointerToMemoryToRelease, const Boolean )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( pointerToMemoryToRelease );
    AssertValueIsInRangeWhenMaximumValueOfTheRangeIsExcluded( reinterpret_cast< const UnsignedInteger8bits* >( pointerToMemoryToRelease ), member_memory.DataPointer(), member_memory.DataPointer() + member_sizeInBytes );
    Assert( ( static_cast< LargestUnsignedInteger >( reinterpret_cast< const UnsignedInteger8bits* >( pointerToMemoryToRelease ) - member_memory.DataPointer() ) % member_constantSizeToAllocateInBytes ) == 0UL, "The given memory address is not valid" );

	// This object will store the result of converting the memory addres in the pointer to the location in the memory manager
	const LargestUnsignedInteger locationInMemoryManager = ( reinterpret_cast< LargestUnsignedInteger >( pointerToMemoryToRelease ) - reinterpret_cast< LargestUnsignedInteger >( member_memory.DataPointer() ) ) / member_constantSizeToAllocateInBytes;

	// Ensure that the location was provided to the user
	Assert( member_memoryManager[ locationInMemoryManager ] == BitState::ON, "The given memory address is not marked as used" );

	// Set that the memory address is free to be provided again
	member_memoryManager[ locationInMemoryManager ] = BitState::OFF;

	// Check if there was no free memory space left before the call to this method
	if ( member_nextMemoryLocationsToAllocateLookupTableIndex != NumericLimits< LargestUnsignedInteger >::Maximum )
	{
		// There was no free memory space

		// Store the offset to the memory space just freed in the array
		member_nextMemoryLocationsToAllocateLookupTable[0] = locationInMemoryManager;

		// Set the next memory location to allocate index to 0
		member_nextMemoryLocationsToAllocateLookupTableIndex = 0UL;
	}
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



inline Boolean MemoryManagerForConstantSizeAllocations::DoesFreeMemorySpaceExist__Private()
{
	// Check if the next memory locations to allocate index, is set to the maximum value possible, which means all the memory space is used, 
	// and return the result
	return ( member_nextMemoryLocationsToAllocateLookupTableIndex != NumericLimits< LargestUnsignedInteger >::Maximum );
}


inline void MemoryManagerForConstantSizeAllocations::SearchForNextFreeLocations__Private()
{
	// This object will store the number of next entries to store from the memory manager. The default value will be picked as long as
	// the number of parts to manage is equal or larger then the default value, otherwise the number of parts will be picked
	const LargestUnsignedInteger numberOfNextMemoryLocationsToStore = member_numberOfPartsThatCanBeAllocated >= member_maximumNumberOfNextMemoryLocationsToStoreInLookupTable ? member_maximumNumberOfNextMemoryLocationsToStoreInLookupTable : member_numberOfPartsThatCanBeAllocated;

	// Search for the required amount of first bits with state off, and store the actual number found
	const LargestUnsignedInteger numberOfFreeLocationsFound = member_memoryManager.SearchForBitsWithStateOff( numberOfNextMemoryLocationsToStore, member_nextMemoryLocationsToAllocateLookupTable );

	// Check if there is no more free memory space to provide
	if ( numberOfFreeLocationsFound == 0UL )
	{
		// There is no more free memory space to provide

		// Set the next memory locations to allocate index to the maximum possible value, to notify that all the memory is currently used
		member_nextMemoryLocationsToAllocateLookupTableIndex = NumericLimits< LargestUnsignedInteger >::Maximum;
	}
	else
	{
		// There is more memory space available

		// Set the index for the next location to allocate
		member_nextMemoryLocationsToAllocateLookupTableIndex = numberOfFreeLocationsFound - 1UL;
	}
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	void MemoryManagerForConstantSizeAllocations::UnitTest()
	{
		// Try to allocate
		HeapPointer< UnsignedInteger8bits COMMA MemoryManagerForConstantSizeAllocations > allocatedMemoryPointer_0;

		// Try to 3 more times allocate
		HeapPointer< UnsignedInteger8bits COMMA MemoryManagerForConstantSizeAllocations > allocatedMemoryPointer_1;
		HeapPointer< UnsignedInteger8bits COMMA MemoryManagerForConstantSizeAllocations > allocatedMemoryPointer_2;
		HeapPointer< UnsignedInteger8bits COMMA MemoryManagerForConstantSizeAllocations > allocatedMemoryPointer_3;

		PagesArray< LargestUnsignedInteger COMMA MemoryManagerForConstantSizeAllocations > pagesArrayTestInstance_0;
	}

)  //  End of debug tool



}  //  Namespace Memory


}  //  Namespace Universe