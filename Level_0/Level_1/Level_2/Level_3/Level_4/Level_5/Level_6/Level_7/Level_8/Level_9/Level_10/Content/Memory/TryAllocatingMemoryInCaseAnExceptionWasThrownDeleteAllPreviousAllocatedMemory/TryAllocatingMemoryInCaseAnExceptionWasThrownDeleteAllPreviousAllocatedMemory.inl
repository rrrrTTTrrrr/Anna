//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< typename... PointerToDeleteInCaseAnExceptionWasThrownTypes >
inline TryAllocatingMemoryInCaseAnExceptionWasThrownDeleteAllPreviousAllocatedMemory< PointerToDeleteInCaseAnExceptionWasThrownTypes... >::TryAllocatingMemoryInCaseAnExceptionWasThrownDeleteAllPreviousAllocatedMemory( PointerToDeleteInCaseAnExceptionWasThrownTypes... pointerToDeleteInCaseAnExceptionWasThrown ) :
	member_pointersToDeleteInCaseAnExceptionWasThrown{ nullptr }
{
	// The following call will store all the given pointers into the array. It will perform a recursive calls, until there are no more pointers
	StorePointers__Private< PointerToDeleteInCaseAnExceptionWasThrownTypes... >( 0UL, pointerToDeleteInCaseAnExceptionWasThrown... );
}


template< typename... PointerToDeleteInCaseAnExceptionWasThrownTypes >
template< typename ResourceToAllocateMemorySpaceForType, typename... argumentNeedeToConstructResourceTypes >
inline ResourceToAllocateMemorySpaceForType* TryAllocatingMemoryInCaseAnExceptionWasThrownDeleteAllPreviousAllocatedMemory< PointerToDeleteInCaseAnExceptionWasThrownTypes... >::AllocateResource( argumentNeedeToConstructResourceTypes... argumentsNeedeToConstructResource )
{
	// Try catch block to ensure that all the memory space allocated is deleted before rethrowing the exception
	try
	{
		// Try allocating the resource using the given arguments
		return ( new ResourceToAllocateMemorySpaceForType( argumentsNeedeToConstructResource... ) );

	}
	catch ( const std::bad_alloc& exception )
	{
		// The allocation of the resource failed

		// Delete all the memory space pointed by the given pointers
		DeleteMemorySpacePointedByPointers__Private< PointerToDeleteInCaseAnExceptionWasThrownTypes... >( 0UL );

		// Rethrow the exception to notify the caller that the operation failed
		throw;
	}
	catch ( const Error::Exception& exception )
	{
		// The construction of the resource failed

		// Delete all the memory space pointed by the given pointers
		DeleteMemorySpacePointedByPointers__Private< PointerToDeleteInCaseAnExceptionWasThrownTypes... >( 0UL );

		// Rethrow the exception to notify the caller that the operation failed
		throw;
	}
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



template< typename... PointerToDeleteInCaseAnExceptionWasThrownTypes >
template< typename ExposedPointerToDeleteInCaseAnExceptionWasThrownType, typename AdditionalExposedPointerToDeleteInCaseAnExceptionWasThrownType, typename... RestOfPointerToDeleteInCaseAnExceptionWasThrownTypes > 
inline void TryAllocatingMemoryInCaseAnExceptionWasThrownDeleteAllPreviousAllocatedMemory< PointerToDeleteInCaseAnExceptionWasThrownTypes... >::StorePointers__Private( UnsignedInteger64bits storeAtThisIndex, ExposedPointerToDeleteInCaseAnExceptionWasThrownType exposedPointerToDeleteInCaseAnExceptionWasThrown, AdditionalExposedPointerToDeleteInCaseAnExceptionWasThrownType additionalExposedPointerToDeleteInCaseAnExceptionWasThrown, RestOfPointerToDeleteInCaseAnExceptionWasThrownTypes... restOfPointerToDeleteInCaseAnExceptionWasThrown )
{
	// Store the exposed pointer to delete in case an exception was thrown
	member_pointersToDeleteInCaseAnExceptionWasThrown[ storeAtThisIndex ] = exposedPointerToDeleteInCaseAnExceptionWasThrown;

	// Call recursievly to this method without the pointer that was just stored, and increment the index to store the pointer at by 1
	StorePointers__Private< AdditionalExposedPointerToDeleteInCaseAnExceptionWasThrownType, RestOfPointerToDeleteInCaseAnExceptionWasThrownTypes... >( storeAtThisIndex + 1UL, additionalExposedPointerToDeleteInCaseAnExceptionWasThrown, restOfPointerToDeleteInCaseAnExceptionWasThrown... );
}


template< typename... PointerToDeleteInCaseAnExceptionWasThrownTypes >
template< typename ExposedPointerToDeleteInCaseAnExceptionWasThrownType > 
inline void TryAllocatingMemoryInCaseAnExceptionWasThrownDeleteAllPreviousAllocatedMemory< PointerToDeleteInCaseAnExceptionWasThrownTypes... >::StorePointers__Private( UnsignedInteger64bits storeAtThisIndex, ExposedPointerToDeleteInCaseAnExceptionWasThrownType exposedPointerToDeleteInCaseAnExceptionWasThrown )
{
	// Store the first pointer to delete in case an exception was thrown
	member_pointersToDeleteInCaseAnExceptionWasThrown[ storeAtThisIndex ] = exposedPointerToDeleteInCaseAnExceptionWasThrown;
}


template< typename... PointerToDeleteInCaseAnExceptionWasThrownTypes >
template< typename ExposedPointerToDeleteInCaseAnExceptionWasThrownType, typename AdditionalExposedPointerToDeleteInCaseAnExceptionWasThrownType, typename... RestOfPointerToDeleteInCaseAnExceptionWasThrownTypes > 
inline void TryAllocatingMemoryInCaseAnExceptionWasThrownDeleteAllPreviousAllocatedMemory< PointerToDeleteInCaseAnExceptionWasThrownTypes... >::DeleteMemorySpacePointedByPointers__Private( UnsignedInteger64bits deleteAtThisIndex )
{
	// Use the given index to choose the entry in the array where the pointer is stored, cast it to the exposed type, and finally delete the
	// memory space pointed by the pointer
	delete reinterpret_cast< ExposedPointerToDeleteInCaseAnExceptionWasThrownType >( member_pointersToDeleteInCaseAnExceptionWasThrown[ deleteAtThisIndex ] );

	// Call recursievly to this method without the pointer that was just stored, and increment the index to store the pointer at by 1
	DeleteMemorySpacePointedByPointers__Private< AdditionalExposedPointerToDeleteInCaseAnExceptionWasThrownType, RestOfPointerToDeleteInCaseAnExceptionWasThrownTypes... >( deleteAtThisIndex + 1UL );
}


template< typename... PointerToDeleteInCaseAnExceptionWasThrownTypes >
template< typename ExposedPointerToDeleteInCaseAnExceptionWasThrownType > 
inline void TryAllocatingMemoryInCaseAnExceptionWasThrownDeleteAllPreviousAllocatedMemory< PointerToDeleteInCaseAnExceptionWasThrownTypes... >::DeleteMemorySpacePointedByPointers__Private( UnsignedInteger64bits deleteAtThisIndex )
{
	// Use the given index to choose the entry in the array where the pointer is stored, cast it to the exposed type, and finally delete the
	// memory space pointed by the pointer
	delete reinterpret_cast< ExposedPointerToDeleteInCaseAnExceptionWasThrownType >( member_pointersToDeleteInCaseAnExceptionWasThrown[ deleteAtThisIndex ] );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< typename... PointerToDeleteInCaseAnExceptionWasThrownTypes >
	inline void TryAllocatingMemoryInCaseAnExceptionWasThrownDeleteAllPreviousAllocatedMemory< PointerToDeleteInCaseAnExceptionWasThrownTypes... >::UnitTest()
	{
		// Create a test pointer
		UnsignedInteger64bits* testPointer_1 = new UnsignedInteger64bits( 8UL );

		// Create a test pointer
		SignedInteger32bits* testPointer_2 = new SignedInteger32bits( 99 );

		// Create a test pointer
		UnsignedInteger64bits* testPointer_3 = new UnsignedInteger64bits( 44UL );

		// Create a test pointer
		Boolean* testPointer_4 = new Boolean( true );

		// Create a test instance
		TryAllocatingMemoryInCaseAnExceptionWasThrownDeleteAllPreviousAllocatedMemory< UnsignedInteger64bits* COMMA SignedInteger32bits* COMMA UnsignedInteger64bits* COMMA Boolean* > testInstance_1( testPointer_1, testPointer_2, testPointer_3, testPointer_4 );

		UnsignedInteger64bits* testPointer_5 = testInstance_1.AllocateResource< UnsignedInteger64bits >();
		UnsignedInteger64bits* testPointer_6 = testInstance_1.AllocateResource< UnsignedInteger64bits >( 8UL );

		delete testPointer_1;
		delete testPointer_2;
		delete testPointer_3;
		delete testPointer_4;
		delete testPointer_5;
		delete testPointer_6;
	}

)  //  End of debug tool



}  //  Namespace Memory


}  //  Namespace Universe