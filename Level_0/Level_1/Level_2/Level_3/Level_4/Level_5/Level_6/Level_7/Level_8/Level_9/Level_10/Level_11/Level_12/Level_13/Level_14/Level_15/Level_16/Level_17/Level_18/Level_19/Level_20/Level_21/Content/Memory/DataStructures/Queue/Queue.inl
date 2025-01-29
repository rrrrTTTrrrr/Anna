//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline Queue< DataType, MemoryManagerType >::Queue( const MemoryHandlerName memoryHandlerName ) :
	member_queue( memoryHandlerName )
{}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline Queue< DataType, MemoryManagerType >::Queue( const SelfType& other ) :
	member_queue( other.member_queue )
{}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void Queue< DataType, MemoryManagerType >::SwitchMemoryHandler( const MemoryHandlerName newMemoryHandlerName )
{
	// Switch to the required memory handler
	member_queue.SwitchMemoryHandler( newMemoryHandlerName );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline LargestUnsignedInteger Queue< DataType, MemoryManagerType >::Size() const
{
	// Return the size of the queue
	return ( member_queue.Size() );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename UniversalReferenceDataType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceDataType, DataType >::Result == true )
inline void Queue< DataType, MemoryManagerType >::PushIn( UniversalReferenceDataType&& data )
{
	// Add the data at the end of the memory handler that stores the queue
	member_queue.InsertSingleElement( 0UL, ForwardUniversalReference< UniversalReferenceDataType >( data ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline DataType Queue< DataType, MemoryManagerType >::PopOut()
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsNotZero( member_queue.Size() );

	// Store the data in the entry that is about to be removed
	const DataType removedData = TakeResourcesAndLeaveInstanceInDefaultState( member_queue[ member_queue.Size() - 1UL ] );

	// Remove the data from the queue
	member_queue.Remove( ( member_queue.Size() - 1UL ), 1UL );

	// Return the data that was stored in the entry that was removed
	return ( removedData );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline const DataType& Queue< DataType, MemoryManagerType >::PeakTop() const
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsNotZero( member_queue.Size() );

	// Return a constant reference to the data at the peak
	return ( member_queue[ member_queue.Size() - 1UL ] );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline Boolean Queue< DataType, MemoryManagerType >::operator==( const SelfType& other ) const
{
	// Compare the Queues, and return the result
	return ( member_queue == other.member_queue );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline Boolean Queue< DataType, MemoryManagerType >::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< Concepts::RawButPointerIsAllowed DataType COMMA typename MemoryManagerType >
	inline void Queue< DataType COMMA MemoryManagerType >::UnitTest()
	{
		// Create a test instance
		Queue< LargestUnsignedInteger > testQueue_1;

		// Add elements to the queue
		for ( LargestUnsignedInteger index = 0UL ; index < 512UL ; ++index )
		{
			// Add an element to the top of the queue
			testQueue_1.PushIn( index );
		}

		// This object will be used to check that the value of the entries popped out is correct
		LargestUnsignedInteger value = 0UL;

		// Pop elements from the queue
		for ( LargestUnsignedInteger index = 512UL ; index > 0UL ; --index )
		{
			// Add an element to the top of the queue
			Assert_Test( testQueue_1.PopOut() == value );

			// Increment the value by one
			++value;
		}

		// Add elements to the queue
		for ( LargestUnsignedInteger index = 0UL ; index < 122UL ; ++index )
		{
			// Add an element to the top of the queue
			testQueue_1.PushIn( 34UL );
		}

		// Store the current size of the test queue
		LargestUnsignedInteger size = testQueue_1.Size();

		// Pop all the elements from the queue
		for ( LargestUnsignedInteger index = 0UL ; index < size ; ++index )
		{
			// Add an element to the top of the queue
			Assert_Test( testQueue_1.PopOut() == 34UL );
		}

		// Add elements to the queue
		for ( LargestUnsignedInteger index = 0UL ; index < 122UL ; ++index )
		{
			// Add an element to the top of the queue
			testQueue_1.PushIn( 34UL );
		}

		// Create a test instance
		const Queue< LargestUnsignedInteger > testQueue_2( testQueue_1 );

		// Check the current memory handler, and switch to a different memory handler
		if ( testQueue_1.UsedMemoryHandlerName() == MemoryHandlerName::Vector )
		{
			testQueue_1.SwitchMemoryHandler( MemoryHandlerName::DoubleLinkedList );
		}
		else if ( testQueue_1.UsedMemoryHandlerName() == MemoryHandlerName::SingleLinkedList )
		{
			testQueue_1.SwitchMemoryHandler( MemoryHandlerName::DoubleLinkedList );
		}
		else
		{
			testQueue_1.SwitchMemoryHandler( MemoryHandlerName::Vector );
		}

		// Check that the instances match
		Assert_Test( testQueue_1 == testQueue_2 );
	}

)  //  End of debug tool



}  //  Namespace Memory


}  //  Namespace Universe