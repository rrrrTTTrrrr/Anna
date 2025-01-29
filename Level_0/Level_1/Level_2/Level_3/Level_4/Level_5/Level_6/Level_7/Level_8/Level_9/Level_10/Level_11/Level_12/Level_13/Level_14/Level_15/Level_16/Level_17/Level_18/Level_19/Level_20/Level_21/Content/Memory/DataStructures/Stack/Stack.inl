//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline Stack< DataType, MemoryManagerType >::Stack( const MemoryHandlerName memoryHandlerName ) :
	member_stack( memoryHandlerName )
{}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline Stack< DataType, MemoryManagerType >::Stack( const SelfType& other ) :
	member_stack( other.member_stack )
{}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void Stack< DataType, MemoryManagerType >::SwitchMemoryHandler( const MemoryHandlerName newMemoryHandlerName )
{
	// Switch to the required memory handler
	member_stack.SwitchMemoryHandler( newMemoryHandlerName );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline LargestUnsignedInteger Stack< DataType, MemoryManagerType >::Size() const
{
	// Return the size of the stack
	return ( member_stack.Size() );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename UniversalReferenceDataType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceDataType, DataType >::Result == true )
inline void Stack< DataType, MemoryManagerType >::PushIn( UniversalReferenceDataType&& data )
{
	// Add the data at the beginning of the memory handler that stores the stack
	member_stack.InsertSingleElement( 0UL, ForwardUniversalReference< UniversalReferenceDataType >( data ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline DataType Stack< DataType, MemoryManagerType >::PopOut()
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsNotZero( member_stack.Size() );

	// Store the data in the entry that is about to be removed
	const DataType removedData = TakeResourcesAndLeaveInstanceInDefaultState( member_stack[0] );

	// Remove the data from the stack
	member_stack.Remove( 0UL, 1UL );

	// Return the data that was stored in the entry that was removed
	return ( removedData );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline const DataType& Stack< DataType, MemoryManagerType >::PeakTop() const
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsNotZero( member_stack.Size() );

	// Return a constant reference to the data at the peak
	return ( member_stack[0] );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline Boolean Stack< DataType, MemoryManagerType >::operator==( const SelfType& other ) const
{
	// Compare the stacks, and return the result
	return ( member_stack == other.member_stack );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline Boolean Stack< DataType, MemoryManagerType >::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< Concepts::RawButPointerIsAllowed DataType COMMA typename MemoryManagerType >
	inline void Stack< DataType COMMA MemoryManagerType >::UnitTest()
	{
		// Create a test instance
		Stack< LargestUnsignedInteger > testStack_1;

		// Add elements to the stack
		for ( LargestUnsignedInteger index = 0UL ; index < 512UL ; ++index )
		{
			// Add an element to the top of the stack
			testStack_1.PushIn( index );
		}

		// Pop elements from the queue
		for ( LargestUnsignedInteger index = 512UL ; index > 1UL ; --index )
		{
			// Add an element to the top of the queue
			Assert_Test( testStack_1.PopOut() == ( index - 1UL ) );
		}

		// Add elements to the stack
		for ( LargestUnsignedInteger index = 0UL ; index < 122UL ; ++index )
		{
			// Add an element to the top of the stack
			testStack_1.PushIn( 34UL );
		}

		// Pop all the elements from the stack
		for ( LargestUnsignedInteger index = 0UL ; index < 122UL ; ++index )
		{
			// Add an element to the top of the stack
			Assert_Test( testStack_1.PopOut() == 34UL );
		}

		// Add elements to the stack
		for ( LargestUnsignedInteger index = 0UL ; index < 122UL ; ++index )
		{
			// Add an element to the top of the stack
			testStack_1.PushIn( 34UL );
		}
	}

)  //  End of debug tool



}  //  Namespace Memory


}  //  Namespace Universe