//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline DoubleLinkedList< DataType, MemoryManagerType >::DoubleLinkedList() :
	member_root( nullptr ),
	member_lastNode( nullptr ),
	member_size( 0UL ),
	member_activeNode( nullptr ),
	member_activeNodeIndex( 0UL )
{}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline DoubleLinkedList< DataType, MemoryManagerType >::DoubleLinkedList( const LargestUnsignedInteger size, const DataType& data ) :
	SelfType()
{
	// Allocate the required memory space and initialize it with the given data
	InsertMultipleTimesTheSameElement( 0UL, size, data );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< template< typename, typename > class OtherMemoryHandlerType, typename OtherMemoryHandlerMemoryManagerType >
inline DoubleLinkedList< DataType, MemoryManagerType >::DoubleLinkedList( const OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >& other, LargestUnsignedInteger startingIndexOnOtherInstance, LargestUnsignedInteger sizeFromOther ) :
    SelfType()
{
    // Insert the required data into this instance
    InsertElementsFromOtherInstance< OtherMemoryHandlerType >( other, 0UL, startingIndexOnOtherInstance, sizeFromOther );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< template< typename, typename > class OtherMemoryHandlerType, typename OtherMemoryHandlerMemoryManagerType >
inline DoubleLinkedList< DataType, MemoryManagerType >::DoubleLinkedList( OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >&& other, LargestUnsignedInteger startingIndexOnOtherInstance, LargestUnsignedInteger sizeFromOther ) :
    SelfType()
{
    // Insert the required data into this instance
	InsertElementsFromOtherInstance< OtherMemoryHandlerType >( TakeResourcesAndLeaveInstanceInDefaultState( other ), 0UL, startingIndexOnOtherInstance, sizeFromOther );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline DoubleLinkedList< DataType, MemoryManagerType >::DoubleLinkedList( const SelfType& other ) :
	SelfType()
{
	// Check if the other instance is empty
	if ( other.Size() > 0UL )
	{
		// The other instance is not empty

		// Insert the data from the other instance to this instance
		InsertElementsFromOtherInstance< DoubleLinkedList >( other, 0UL, 0UL, other.Size() );
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline DoubleLinkedList< DataType, MemoryManagerType >::~DoubleLinkedList()
{
    // Check if the object is in default state, then noting needs to be done
    ReturnIfExpressionIsTrue( member_root == nullptr );

    // Delete all the nodes
    DeleteNodes__Private( member_root );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline LargestUnsignedInteger DoubleLinkedList< DataType, MemoryManagerType >::SizeInBytes() const
{
    // Multiply the size of the instance by the size in bytes of the data type, and return the result
    return ( member_size * sizeof( DataType ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline LargestUnsignedInteger DoubleLinkedList< DataType, MemoryManagerType >::DataTypeSizeInBytes() const
{
    // Return the size in bytes of the data type
    return ( sizeof( DataType ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename UniversalReferenceDataType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceDataType, DataType >::Result == true )
inline void DoubleLinkedList< DataType, MemoryManagerType >::InsertSingleElement( const LargestUnsignedInteger addTheDataAtThisIndex, UniversalReferenceDataType&& data )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertValueIsEqualOrBelowCertainLimit( addTheDataAtThisIndex, member_size );

	// Allocate the new node, and call the constructor that takes the resources from the data
	NodeType* const newNode = MainMemoryManager::template AllocateAndConstruct< NodeType >( ForwardUniversalReference< UniversalReferenceDataType >( data ) );

    // Set the string of allocated nodes into the required location
	InsertTheNewNodesToTheRequiredLocation__Private( newNode, newNode, addTheDataAtThisIndex, 1UL );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename... AnyArgumentNeededToConstructDataInstanceTypes >
inline void DoubleLinkedList< DataType, MemoryManagerType >::InsertSingleElementCreateFromArguments( const LargestUnsignedInteger addTheDataAtThisIndex, AnyArgumentNeededToConstructDataInstanceTypes&&... anyArgumentNeededToConstructDataIstance )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsEqualOrBelowCertainLimit( addTheDataAtThisIndex, member_size );

	// Allocate the new node, and call the constructor that takes the resources from the data
	NodeType* newNode = MainMemoryManager::template AllocateAndConstruct< NodeType >( TakeResourcesAndLeaveInstanceInDefaultState( DataType( ForwardUniversalReference< AnyArgumentNeededToConstructDataInstanceTypes >( anyArgumentNeededToConstructDataIstance )... ) ) );

    // Set the string of allocated nodes into the required location
	InsertTheNewNodesToTheRequiredLocation__Private( newNode, newNode, addTheDataAtThisIndex, 1UL );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void DoubleLinkedList< DataType, MemoryManagerType >::InsertMultipleTimesTheSameElement( const LargestUnsignedInteger addTheDataAtThisIndex, const LargestUnsignedInteger sizeToAdd, const DataType& data )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
    AssertValueIsEqualOrBelowCertainLimit( addTheDataAtThisIndex, member_size );

	// This pointer will store the memory address of the first allocated node
	NodeType* firstNewNodePointer = nullptr;

	// This object will store the memory address of the last allocated node in the string
	NodeType* currentNewNodePointer = nullptr;

	// Try catch block to ensure that all the memory space allocated is deleted before rethrowing the exception
	try
	{
		// Allocate the first node, and initialize it using the data
		firstNewNodePointer = new NodeType( data );

		// Set the first node into the current node
		currentNewNodePointer = firstNewNodePointer;

		// Loop until all the nodes were allocated
		for ( LargestUnsignedInteger numberOfNewNodesCreated = 1UL ; numberOfNewNodesCreated < sizeToAdd ; ++numberOfNewNodesCreated )
		{
			// Allocate a new node, and connect it with the previous node in the string of nodes
			ConnectTwoSubsequentNodes__Private( currentNewNodePointer, MainMemoryManager::template AllocateAndConstruct< NodeType >( data ) );

			// Advance the pointer to the new allocated node
			currentNewNodePointer = currentNewNodePointer->NextNode();
		}

	}
	catch ( const std::bad_alloc& exception )
	{
		// Check if at least one node was already allocated
		if ( firstNewNodePointer != nullptr )
		{
			// Delete all the nodes allocated so far
			DeleteNodes__Private( firstNewNodePointer );
		}

		// Rethrow the exception to notify the caller that the operation failed
		throw;
	}

	// Now that the nodes are allocated and set with the data, connect them to the linked list. The current new node pointer contains the
	// memory address of the last new node
	InsertTheNewNodesToTheRequiredLocation__Private( firstNewNodePointer, currentNewNodePointer, addTheDataAtThisIndex, sizeToAdd );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< template< typename, typename > class OtherMemoryHandlerType, typename OtherMemoryHandlerMemoryManagerType >
inline void DoubleLinkedList< DataType, MemoryManagerType >::InsertElementsFromOtherInstance( const OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >& other, const LargestUnsignedInteger firstIndexInThisInstance, const LargestUnsignedInteger firstIndexOnOtherInstance, const LargestUnsignedInteger sizeToAdd )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
    AssertValueIsLargerThenZero( other.Size() );
    AssertValueIsEqualOrBelowCertainLimit( firstIndexInThisInstance, member_size );
    AssertValueIsEqualOrBelowCertainLimit( firstIndexOnOtherInstance, other.Size() );
    AssertValueIsEqualOrBelowCertainLimit( sizeToAdd, ( other.Size() - firstIndexOnOtherInstance ) );

	// This pointer will store the memory address of the first allocated node
	NodeType* firstNewNodePointer = nullptr;

	// This object will store the memory address of the last allocated node in the string
	NodeType* currentNewNodePointer = nullptr;

	// Try catch block to ensure that all the memory space allocated is deleted before rethrowing the exception
	try
	{
		// Allocate the first node, and initialize it using the data
		firstNewNodePointer = MainMemoryManager::template AllocateAndConstruct< NodeType >( other[ firstIndexOnOtherInstance ] );

		// Set the first node into the current node
		currentNewNodePointer = firstNewNodePointer;

		// This object will store the index at which the loop should stop
		LargestUnsignedInteger stopAtThisIndex = firstIndexOnOtherInstance + sizeToAdd;

		// Loop until all the nodes were allocated
		for ( LargestUnsignedInteger otherIndex = firstIndexOnOtherInstance + 1UL ; otherIndex < stopAtThisIndex ; ++otherIndex )
		{
			// Allocate a new node, and connect it with the previous node in the string of nodes
			ConnectTwoSubsequentNodes__Private( currentNewNodePointer, MainMemoryManager::template AllocateAndConstruct< NodeType >( other[ otherIndex ] ) );

			// Advance the pointer to the new allocated node
			currentNewNodePointer = currentNewNodePointer->NextNode();
		}

	}
	catch ( const std::bad_alloc& exception )
	{
		// Check if at least one node was already allocated
		if ( firstNewNodePointer != nullptr )
		{
			// Delete all the nodes allocated so far
			DeleteNodes__Private( firstNewNodePointer );
		}

		// Rethrow the exception to notify the caller that the operation failed
		throw;
	}

	// Now that the nodes are allocated and set with the data, connect them to the linked list. The current new node pointer contains the
	// memory address of the last new node
	InsertTheNewNodesToTheRequiredLocation__Private( firstNewNodePointer, currentNewNodePointer, firstIndexInThisInstance, sizeToAdd );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< template< typename, typename > class OtherMemoryHandlerType, typename OtherMemoryHandlerMemoryManagerType >
inline void DoubleLinkedList< DataType, MemoryManagerType >::InsertElementsFromOtherInstance( OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >&& other, const LargestUnsignedInteger firstIndexInThisInstance, const LargestUnsignedInteger firstIndexOnOtherInstance, const LargestUnsignedInteger sizeToAdd )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
    AssertValueIsLargerThenZero( other.Size() );
    AssertValueIsEqualOrBelowCertainLimit( firstIndexInThisInstance, member_size );
    AssertValueIsEqualOrBelowCertainLimit( firstIndexOnOtherInstance, other.Size() );
    AssertValueIsEqualOrBelowCertainLimit( sizeToAdd, ( other.Size() - firstIndexOnOtherInstance ) );

	// This pointer will store the memory address of the first allocated node
	NodeType* firstNewNodePointer = nullptr;

	// This object will store the memory address of the last allocated node in the string
	NodeType* currentNewNodePointer = nullptr;

	// Try catch block to ensure that all the memory space allocated is deleted before rethrowing the exception
	try
	{
		// Allocate the first node, and initialize it using the data
		firstNewNodePointer = MainMemoryManager::template AllocateAndConstruct< NodeType >( TakeResourcesAndLeaveInstanceInDefaultState( other[ firstIndexOnOtherInstance ] ) );

		// Set the first node into the current node
		currentNewNodePointer = firstNewNodePointer;

		// This object will store the index at which the loop should stop
		LargestUnsignedInteger stopAtThisIndex = firstIndexOnOtherInstance + sizeToAdd;

		// Loop until all the nodes were allocated
		for ( LargestUnsignedInteger otherIndex = firstIndexOnOtherInstance + 1UL ; otherIndex < stopAtThisIndex ; ++otherIndex )
		{
			// Allocate a new node, and connect it with the previous node in the string of nodes
			ConnectTwoSubsequentNodes__Private( currentNewNodePointer, MainMemoryManager::template AllocateAndConstruct< NodeType >( TakeResourcesAndLeaveInstanceInDefaultState( other[ otherIndex ] ) ) );

			// Advance the pointer to the new allocated node
			currentNewNodePointer = currentNewNodePointer->NextNode();
		}

	}
	catch ( const std::bad_alloc& exception )
	{
		// Check if at least one node was already allocated
		if ( firstNewNodePointer != nullptr )
		{
			// Delete all the nodes allocated so far
			DeleteNodes__Private( firstNewNodePointer );
		}

		// Rethrow the exception to notify the caller that the operation failed
		throw;
	}

	// Now that the nodes are allocated and set with the data, connect them to the linked list. The current new node pointer contains the
	// memory address of the last new node
	InsertTheNewNodesToTheRequiredLocation__Private( firstNewNodePointer, currentNewNodePointer, firstIndexInThisInstance, sizeToAdd );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void DoubleLinkedList< DataType, MemoryManagerType >::InsertElementsFromRawData( const DataType* const dataPointer, const LargestUnsignedInteger addTheDataAtThisIndex, const LargestUnsignedInteger dataSize )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( dataPointer );
    AssertValueIsEqualOrBelowCertainLimit( addTheDataAtThisIndex, member_size );
    AssertValueIsLargerThenZero( dataSize );

	// This pointer will store the memory address of the first allocated node
	NodeType* firstNewNodePointer = nullptr;

	// This object will store the memory address of the last allocated node in the string
	NodeType* currentNewNodePointer = nullptr;

	// Try catch block to ensure that all the memory space allocated is deleted before rethrowing the exception
	try
	{
		// Allocate the first node, and initialize it using the data
		firstNewNodePointer = MainMemoryManager::template AllocateAndConstruct< NodeType >( dataPointer[ 0UL ] );

		// Set the first node into the current node
		currentNewNodePointer = firstNewNodePointer;

		// Loop until all the nodes were allocated
		for ( LargestUnsignedInteger dataIndex = addTheDataAtThisIndex + 1UL ; dataIndex < dataSize ; ++dataIndex )
		{
			// Allocate a new node, and connect it with the previous node in the string of nodes
			ConnectTwoSubsequentNodes__Private( currentNewNodePointer, MainMemoryManager::template AllocateAndConstruct< NodeType >( dataPointer[ dataIndex ] ) );

			// Advance the pointer to the new allocated node
			currentNewNodePointer = currentNewNodePointer->NextNode();
		}

	}
	catch ( const std::bad_alloc& exception )
	{
		// Check if at least one node was already allocated
		if ( firstNewNodePointer != nullptr )
		{
			// Delete all the nodes allocated so far
			DeleteNodes__Private( firstNewNodePointer );
		}

		// Rethrow the exception to notify the caller that the operation failed
		throw;
	}

	// Now that the nodes are allocated and set with the data, connect them to the linked list. The current new node pointer contains the
	// memory address of the last new node
	InsertTheNewNodesToTheRequiredLocation__Private( firstNewNodePointer, currentNewNodePointer, addTheDataAtThisIndex, dataSize );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void DoubleLinkedList< DataType, MemoryManagerType >::Remove( const LargestUnsignedInteger indexOfFirstDataToRemove, const LargestUnsignedInteger sizeToRemove )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_root );
	AssertValueIsLargerThenZero( sizeToRemove );
    AssertSumOfTheValuesIsEqualOrBelowCertainLimit( indexOfFirstDataToRemove, sizeToRemove, member_size );

	// Check if all the nodes needs to be removed
	if ( member_size == sizeToRemove )
	{
		// All the nodes needs to be removed

		// Reset the instance
		Reset();

		// Nothing else needs to be done
		return;
	}			

	// This object will store the first node that needs to be removed
	NodeType* firstNodeThatNeedsToBeRemoved = nullptr;

	// This object will store the last node that needs to be removed
	NodeType* lastNodeThatNeedsToBeRemoved = nullptr;

	// Check if the data in the first node needs to be removed
	if ( indexOfFirstDataToRemove == 0UL )
	{
		// The data in the first node of the single linked list needs to be removed

		// Set the first node that needs to be removed, which is the root node
		firstNodeThatNeedsToBeRemoved = member_root;

		// Find the last node that needs to be removed
		TakeShortestPathToNodeAndSetItAsTheActiveNode__Private( indexOfFirstDataToRemove + sizeToRemove - 1UL );

		// Set the last node that needs to be removed
		lastNodeThatNeedsToBeRemoved = member_activeNode;

		// Set the next node pointer of the root to the first node that does not need to be deleted
		member_root = member_activeNode->NextNode();

		// Set the active node to point to the new root
		member_activeNode = member_root;

		// Set the active node index to zero
		member_activeNodeIndex = 0UL;
	}
	// Check if the data in the last node also needs to be removed
	else if ( indexOfFirstDataToRemove + sizeToRemove == member_size )
	{
		// The data in the last node of the double linked list needs to be removed

		// Find the node before the first node that needs to be removed
		TakeShortestPathToNodeAndSetItAsTheActiveNode__Private( indexOfFirstDataToRemove - 1UL );

		// Set the first node that needs to be removed, which is the next node after the active node
		firstNodeThatNeedsToBeRemoved = member_activeNode->NextNode();

		// Set the last node that needs to be removed, which is the last node of the double linked list
		lastNodeThatNeedsToBeRemoved = member_lastNode;

        // Set the last node to the active node
        member_lastNode = member_activeNode;

        // Set the next node pointer of the last node to NULL
        member_lastNode->SetNextNode( nullptr );

		// Set the active node to point to the new root
		member_activeNode = member_root;

		// Set the active node index to zero
		member_activeNodeIndex = 0UL;
	}
	else
	{
		// The removed nodes does not include the first or last node of the double linked list

		// Find the node before the first node that needs to be removed
		TakeShortestPathToNodeAndSetItAsTheActiveNode__Private( indexOfFirstDataToRemove - 1UL );

		// Store the memory address of the node before the first node that needs to be removed
		NodeType* nodeBeforeFirstNodeThatNeedsToBeRemoved = member_activeNode;

		// Set the first node that needs to be removed, which is the next node after the active node
		firstNodeThatNeedsToBeRemoved = member_activeNode->NextNode();

		// Find the last node that needs to be removed
		TakeShortestPathToNodeAndSetItAsTheActiveNode__Private( indexOfFirstDataToRemove + ( sizeToRemove - 1UL ) );

		// Set the last node that needs to be removed, which is the active node
		lastNodeThatNeedsToBeRemoved = member_activeNode;

		// Connect the two nodes on the sides of the removed segment
		ConnectTwoSubsequentNodes__Private( nodeBeforeFirstNodeThatNeedsToBeRemoved, member_activeNode->NextNode() );

		// Set the active node to point to next node, because it currently points to the last node that needs to be removed. An by this
		// assignment it will point to the first node that will stay after the removal of the segment
		member_activeNode = member_activeNode->NextNode();

		// Increment the active node index by one
		member_activeNodeIndex += 1UL;						
	}

	// Set the next node pointer of the last node to remove to NULL to stop the deletion of nodes at this point
	lastNodeThatNeedsToBeRemoved->SetNextNode( nullptr );

	// Delete all the required nodes
	DeleteNodes__Private( firstNodeThatNeedsToBeRemoved );

	// Decrement the size of the instance by the number of the nodes removed
	member_size -= sizeToRemove;
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline Boolean DoubleLinkedList< DataType, MemoryManagerType >::operator==( const SelfType& other ) const
{
    // Check if the instances are ready
    ReturnValueIfExpressionIsTrue( ( ( other.member_root == nullptr ) && ( member_root == nullptr ) ), true );
    ReturnValueIfExpressionIsTrue( ( ( member_root != other.member_root ) && ( ( member_root == nullptr ) || ( other.member_root == nullptr ) ) ), false );
    ReturnValueIfExpressionIsTrue( ( member_size != other.member_size ), false );

    // Loop on all the entries of the instances
    for ( LargestUnsignedInteger index = 0UL ; index < member_size ; ++index )
    {
    	// Compare the data in the entry of both instances, and if it mismatch return the result
    	ReturnValueIfExpressionIsTrue( ( operator[]( index ) != other[ index ] ), false );
    }

	// The instances are identical, return true
	return ( true );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline Boolean DoubleLinkedList< DataType, MemoryManagerType >::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline DataType& DoubleLinkedList< DataType, MemoryManagerType >::operator[]( const LargestUnsignedInteger index )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertValueIsBelowCertainLimit( index, member_size );

	// Take the shortest path to the required node
	TakeShortestPathToNodeAndSetItAsTheActiveNode__Private( index );
	
	// Find the required node, and return a reference to it
	return ( member_activeNode->Data() );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline const DataType& DoubleLinkedList< DataType, MemoryManagerType >::operator[]( const LargestUnsignedInteger index ) const
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertValueIsBelowCertainLimit( index, member_size );
	
	// Take the shortest path to the required node
	TakeShortestPathToNodeAndSetItAsTheActiveNode__Private( index );
	
	// Find the required node, and return a constant reference to it
	return ( member_activeNode->Data() );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline DoubleLinkedList< DataType, MemoryManagerType >& DoubleLinkedList< DataType, MemoryManagerType >::operator+=( const SelfType& other )
{
    // Add the data to the end of the instance
    InsertElementsFromOtherInstance< DoubleLinkedList >( other, member_size, 0UL, other.Size() );

    // Return a reference to this instance
    return ( *this );
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void DoubleLinkedList< DataType, MemoryManagerType >::ConnectTwoSubsequentNodes__Private( NodeType* const previousNodePointer, NodeType* const nextNodePointer )
{
    // Set the next node pointer of the former node to point to the following node
    previousNodePointer->SetNextNode( nextNodePointer );

    // Set the previous node pointer of the latter node to point to the former node
    nextNodePointer->SetPreviousNode( previousNodePointer );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void DoubleLinkedList< DataType, MemoryManagerType >::InsertTheNewNodesToTheRequiredLocation__Private( NodeType* const firstNewNodePointer, NodeType* const lastNewNodePointer, const LargestUnsignedInteger addNodesStartingFromThisIndex, const LargestUnsignedInteger size )
{
	// Check if the double linked list instance is empty
	if ( member_root == nullptr )
	{
		// The double linked list instance is empty

		// Set the root of the double linked list instance to the memory address of the first allocated node
		member_root = firstNewNodePointer;

		// Set the last node of the double linked list instance to the memory address of the last allocated node
		member_lastNode = lastNewNodePointer;

		// Set the active node to point to the memory address of the first allocated node
		member_activeNode = member_root;

		// Set the index of the active node to be 0
		member_activeNodeIndex = 0UL;
	}
	// Check if the new nodes needs to be added to the beginning of the instance
	else if ( addNodesStartingFromThisIndex == 0UL )
	{
		// The new nodes needs to be added to the beginning of the instance

		// Connect between the last new node allocated and the current root of the instance
		ConnectTwoSubsequentNodes__Private( lastNewNodePointer, member_root );

		// Set the root of the double linked list instance to the memory address of the first allocated node
		member_root = firstNewNodePointer;

		// Increment the index of the active node by the amount of new nodes that were added
		member_activeNodeIndex += size;
	}
	// Check if the new nodes needs to be added to the end of the instance
	else if ( addNodesStartingFromThisIndex == member_size )
	{
		// The new nodes needs to be added to the end of the instance

		// Connect between the current last node of the instance and the first new node allocated
		ConnectTwoSubsequentNodes__Private( member_lastNode, firstNewNodePointer );

		// Set the last node of the double linked list instance to the memory address of the last node allocated
		member_lastNode = lastNewNodePointer;
	}
	else
	{
        // Take the shortest path to the node previous to the node associated with the index
        TakeShortestPathToNodeAndSetItAsTheActiveNode__Private( addNodesStartingFromThisIndex - 1UL );

		// Connect between the last new node allocated and the node associated with the index
		ConnectTwoSubsequentNodes__Private( member_activeNode->NextNode(), lastNewNodePointer );

		// Connect between the node previous to the node associated with the index and the first new node
		ConnectTwoSubsequentNodes__Private( member_activeNode, firstNewNodePointer );
	}

	// Increment the size of the instance by the size of the sequential platfrom
	member_size += size;
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void DoubleLinkedList< DataType, MemoryManagerType >::TakeShortestPathToNodeAndSetItAsTheActiveNode__Private( const LargestUnsignedInteger index ) const
{
	// Check if the active node already points to the required node
	if ( index == member_activeNodeIndex )
	{
		// The active node is needed

		// Nothing else needs to be done
		return;			
	}

    // Now, the point is to find the shortest path to take to the required node. There are 3 places from which the search can start, the 
    // beginning, ending or the active node

    // This object will store the distance from the beginning to the reuiqred index
    const LargestUnsignedInteger distanceFromBeginning = index;

    // This object will store the distance from the ending to the reuiqred index
    const LargestUnsignedInteger distanceFromEnding = ( member_size - 1UL ) - index;

    // This object will store the distance from the active node index to the reuiqred index
    const LargestUnsignedInteger distanceFromActiveNode = ( index > member_activeNodeIndex ) ? ( index - member_activeNodeIndex ) : ( member_activeNodeIndex - index );

    // Check if the required node is closer to the beginning
    if ( ( distanceFromBeginning <= distanceFromEnding ) && ( distanceFromBeginning <= distanceFromActiveNode ) )
    {
        // The search for the required node will start from the beginning

        // Advance from the root node to the required node and store it as the active node
        MoveForwardUntilRequiredNodeAndReturnTheMemoryAddress__Private( member_root, distanceFromBeginning );
    }
    // Check if the required node is closer to the end
    else if ( ( distanceFromEnding < distanceFromBeginning ) && ( distanceFromEnding < distanceFromActiveNode ) )
    {
        // The search for the required node will start from the ending

        // Backward from the last node to the required node and store it as the active node
        MoveBackwardUntilRequiredNodeAndReturnTheMemoryAddress__Private( member_lastNode, distanceFromEnding );
    }
    else
    {
        // The search for the required node will start from the active node

        // Check if the index is before or after the active node
        if ( member_activeNodeIndex > index )
        {
            // The required node is before the active node
    
            // Backward from the active node to the required node and store it as the active node
            MoveBackwardUntilRequiredNodeAndReturnTheMemoryAddress__Private( member_activeNode, distanceFromActiveNode );
        }
        else
        {
            // The required node is after the active node
            
            // Advance from the active node to the required node and store it as the active node
            MoveForwardUntilRequiredNodeAndReturnTheMemoryAddress__Private( member_activeNode, distanceFromActiveNode );
        }
    }

	// Set the active node index to be as the given index
	member_activeNodeIndex = index;
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void DoubleLinkedList< DataType, MemoryManagerType >::MoveForwardUntilRequiredNodeAndReturnTheMemoryAddress__Private( NodeType* const nodePointer, const LargestUnsignedInteger numberOfNodesToTargetNode ) const
{
	// This pointer will store the pointer of the current node
	NodeType* currentNodePointer = nodePointer;

    // Loop until the required amount of nodes to pass has reached
    for ( LargestUnsignedInteger numberOfNodesPassed = 0UL ; numberOfNodesPassed < numberOfNodesToTargetNode ; ++numberOfNodesPassed )
    {
        // Advance to the next node
        currentNodePointer = currentNodePointer->NextNode();
    }

    // Set the required node as the active node
    member_activeNode = currentNodePointer;
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void DoubleLinkedList< DataType, MemoryManagerType >::MoveBackwardUntilRequiredNodeAndReturnTheMemoryAddress__Private( NodeType* const nodePointer, const LargestUnsignedInteger numberOfNodesToTargetNode ) const
{
	// This pointer will store the pointer of the current node
	NodeType* currentNodePointer = nodePointer;

    // Loop until the required amount of nodes to pass has reached
    for ( LargestUnsignedInteger numberOfNodesPassed = 0UL ; numberOfNodesPassed < numberOfNodesToTargetNode ; ++numberOfNodesPassed )
    {
        // Advance to the next node
        currentNodePointer = currentNodePointer->PreviousNode();
    }

    // Set the required node as the active node
    member_activeNode = currentNodePointer;
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void DoubleLinkedList< DataType, MemoryManagerType >::DeleteNodes__Private( NodeType* const firstNodeToDelete )
{
	// This pointer will store the pointer of the node that needs to be deleted
	NodeType* currentNodeToDelete = firstNodeToDelete;

	// Loop on all the entries allocated so far and delete them
	for ( NodeType* nextNodeToDelete = currentNodeToDelete->NextNode() ; nextNodeToDelete != nullptr ; nextNodeToDelete = nextNodeToDelete->NextNode() )
	{
		// Delete the node
		MainMemoryManager::template Done< NodeType >( currentNodeToDelete );

		// Set the next node to delete
		currentNodeToDelete = nextNodeToDelete;
	}

	// Delete the last node
	MainMemoryManager::template Done< NodeType >( currentNodeToDelete );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< Concepts::RawButPointerIsAllowed DataType COMMA typename MemoryManagerType >
	inline void DoubleLinkedList< DataType COMMA MemoryManagerType >::UnitTest()
	{}

)  //  End of debug tool




}  //  Namespace Memory


}  //  Namespace Universe