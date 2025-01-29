//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< Concepts::Raw Type, typename MemoryManagerType >
template< typename... ArgumentTypesNeededToConstruct >
inline CopyOnWriteResource< Type, MemoryManagerType >::CopyOnWriteResource( ArgumentTypesNeededToConstruct... argumentsNeededToConstruct ) :
	member_resourcePointer( nullptr ),
	member_usersCounterPointer( nullptr )
{
    // Allocate memory space for the instance and initialize it using the required constructor
    Memory::HeapPointer< Type > temporaryResourcePointer( ForwardUniversalReference< ArgumentTypesNeededToConstruct >( argumentsNeededToConstruct )... );

    // Allocate memory space for the users counter and initialize it to 1
    Memory::HeapPointer< Type > temporaryUsersCounterPointer( 1 );

    // Set the resource pointer
    member_resourcePointer = temporaryResourcePointer.Acquire();

    // Set the users counter pointer pointer
    member_resourcePointer = temporaryUsersCounterPointer.Acquire();
}


template< Concepts::Raw Type, typename MemoryManagerType >
inline CopyOnWriteResource< Type, MemoryManagerType >::CopyOnWriteResource( const SelfType& other ) :
	member_resourcePointer( other.member_resourcePointer ),
	member_usersCounterPointer( other.member_usersCounterPointer )
{
	// Increment the users counter by 1
	CentralProcessingUnit::CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::Read_Add_Write< SignedInteger64bits >( member_usersCounterPointer, 1 );
}


template< Concepts::Raw Type, typename MemoryManagerType >
inline CopyOnWriteResource< Type, MemoryManagerType >::~CopyOnWriteResource()
{
	// Decrement the users counter by 1, and store the old value
	const SignedInteger64bits usersCount = CentralProcessingUnit::CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::Read_Add_Write_ReturnOldValue< SignedInteger64bits >( member_usersCounterPointer, -1 );

	// Check if only this instance uses the resource
	if ( usersCount == 1 )
	{
		// Only this instance uses the resource

		// Delete the resource
    	MemoryManagerType::template Done< Type >( member_resourcePointer );

		// Delete the users counter
		MemoryManagerType::template Done< SignedInteger64bits >( member_usersCounterPointer );
	}
}


template< Concepts::Raw Type, typename MemoryManagerType >
inline const Type& CopyOnWriteResource< Type, MemoryManagerType >::View() const
{
	// Perform the action on the resource and return the result
	return ( *member_resourcePointer );
}


template< Concepts::Raw Type, typename MemoryManagerType >
inline Type& CopyOnWriteResource< Type, MemoryManagerType >::Edit()
{
	// Check if only this instance uses the resource
	ReturnValueIfExpressionIsTrue( ( *member_usersCounterPointer == 1 ), *member_resourcePointer );

	// Not only this instance uses the resource, create a copy of the resource
	member_resourcePointer = new Type( *member_resourcePointer );

	// Decrement the reference counter by 1
	*member_usersCounterPointer -= 1;

	// Allocate new reference counter and initialize it to 1
	member_usersCounterPointer = new SignedInteger64bits( 1 );

	// Return a reference to the instance
	return ( *member_resourcePointer );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< Concepts::Raw Type, typename MemoryManagerType >
inline Boolean CopyOnWriteResource< Type, MemoryManagerType >::operator==( const SelfType& other ) const
{
	// Check if the resource in both instance is the same
	return ( *member_resourcePointer == *other.member_resourcePointer );
}


template< Concepts::Raw Type, typename MemoryManagerType >
inline Boolean CopyOnWriteResource< Type, MemoryManagerType >::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< Concepts::Raw Type COMMA typename MemoryManagerType >
	inline void CopyOnWriteResource< Type COMMA MemoryManagerType >::UnitTest()
	{
		// CopyOnWriteResource< UnsignedInteger64bits > testCopyOnWriteResourceInstance_0;
		CopyOnWriteResource< UnsignedInteger64bits > testCopyOnWriteResourceInstance_0( 0UL );
		CopyOnWriteResource< UnsignedInteger64bits > testCopyOnWriteResourceInstance_1( testCopyOnWriteResourceInstance_0 );
		CopyOnWriteResource< UnsignedInteger64bits > testCopyOnWriteResourceInstance_2( testCopyOnWriteResourceInstance_0 );
		CopyOnWriteResource< UnsignedInteger64bits > testCopyOnWriteResourceInstance_3( testCopyOnWriteResourceInstance_0 );
		CopyOnWriteResource< UnsignedInteger64bits > testCopyOnWriteResourceInstance_4( testCopyOnWriteResourceInstance_0 );
		CopyOnWriteResource< UnsignedInteger64bits > testCopyOnWriteResourceInstance_5( testCopyOnWriteResourceInstance_0 );
		CopyOnWriteResource< UnsignedInteger64bits > testCopyOnWriteResourceInstance_6( testCopyOnWriteResourceInstance_0 );
		CopyOnWriteResource< UnsignedInteger64bits > testCopyOnWriteResourceInstance_7( testCopyOnWriteResourceInstance_0 );
		CopyOnWriteResource< UnsignedInteger64bits > testCopyOnWriteResourceInstance_8( testCopyOnWriteResourceInstance_0 );
		CopyOnWriteResource< UnsignedInteger64bits > testCopyOnWriteResourceInstance_9( testCopyOnWriteResourceInstance_0 );
		CopyOnWriteResource< UnsignedInteger64bits > testCopyOnWriteResourceInstance_10( testCopyOnWriteResourceInstance_0 );
		CopyOnWriteResource< UnsignedInteger64bits > testCopyOnWriteResourceInstance_11( testCopyOnWriteResourceInstance_0 );
		CopyOnWriteResource< UnsignedInteger64bits > testCopyOnWriteResourceInstance_12( testCopyOnWriteResourceInstance_0 );
		CopyOnWriteResource< UnsignedInteger64bits > testCopyOnWriteResourceInstance_13( testCopyOnWriteResourceInstance_0 );
		CopyOnWriteResource< UnsignedInteger64bits > testCopyOnWriteResourceInstance_14( testCopyOnWriteResourceInstance_0 );
		CopyOnWriteResource< UnsignedInteger64bits > testCopyOnWriteResourceInstance_15( testCopyOnWriteResourceInstance_0 );
		CopyOnWriteResource< UnsignedInteger64bits > testCopyOnWriteResourceInstance_16( testCopyOnWriteResourceInstance_0 );
		CopyOnWriteResource< UnsignedInteger64bits > testCopyOnWriteResourceInstance_17( testCopyOnWriteResourceInstance_0 );
		CopyOnWriteResource< UnsignedInteger64bits > testCopyOnWriteResourceInstance_18( testCopyOnWriteResourceInstance_0 );
		CopyOnWriteResource< UnsignedInteger64bits > testCopyOnWriteResourceInstance_19( testCopyOnWriteResourceInstance_0 );
	}

)  //  End of debug tool



}  //  Namespace Memory


}  //  Namespace Universe