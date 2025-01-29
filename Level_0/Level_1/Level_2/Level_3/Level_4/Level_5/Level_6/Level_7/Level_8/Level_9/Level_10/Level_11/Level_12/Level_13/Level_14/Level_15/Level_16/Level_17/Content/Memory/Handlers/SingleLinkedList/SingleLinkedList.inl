//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline SingleLinkedList< DataType, MemoryManagerType >::SingleLinkedList() :
	member_root( nullptr ),
	member_lastNode( nullptr ),
	member_size( 0UL ),
	member_activeNode( nullptr ),
	member_activeNodeIndex( 0UL )
{}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline SingleLinkedList< DataType, MemoryManagerType >::SingleLinkedList( const LargestUnsignedInteger size, const DataType& data ) :
	SelfType()
{
	// Allocate the required memory space and initialize it with the given data
	InsertMultipleTimesTheSameElement( 0UL, size, data );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< template< typename, typename > class OtherMemoryHandlerType, typename OtherMemoryHandlerMemoryManagerType >
inline SingleLinkedList< DataType, MemoryManagerType >::SingleLinkedList( const OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >& other, const LargestUnsignedInteger startingIndexOnOtherInstance, const LargestUnsignedInteger sizeFromOther ) :
    SelfType()
{
    // Insert the required data into this instance
    InsertElementsFromOtherInstance< OtherMemoryHandlerType >( other, 0UL, startingIndexOnOtherInstance, sizeFromOther );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< template< typename, typename > class OtherMemoryHandlerType, typename OtherMemoryHandlerMemoryManagerType >
inline SingleLinkedList< DataType, MemoryManagerType >::SingleLinkedList( OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >&& other, const LargestUnsignedInteger startingIndexOnOtherInstance, const LargestUnsignedInteger sizeFromOther ) :
    SelfType()
{
    // Insert the required data into this instance
    InsertElementsFromOtherInstance< OtherMemoryHandlerType >( TakeResourcesAndLeaveInstanceInDefaultState( other ), 0UL, startingIndexOnOtherInstance, sizeFromOther );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline SingleLinkedList< DataType, MemoryManagerType >::SingleLinkedList( const SelfType& other ) :
	SelfType()
{
	// Check if the other instance is empty
	if ( other.Size() > 0UL )
	{
		// The other instance is not empty

		// Insert the data from the other instance to this instance
		InsertElementsFromOtherInstance< SingleLinkedList >( other, 0UL, 0UL, other.Size() );
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline SingleLinkedList< DataType, MemoryManagerType >::~SingleLinkedList()
{
    // Check if the object is in default state, then noting needs to be done
    ReturnIfExpressionIsTrue( member_root == nullptr );

    // Delete all the nodes
    DeleteNodes__Private( member_root );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline LargestUnsignedInteger SingleLinkedList< DataType, MemoryManagerType >::SizeInBytes() const
{
    // Multiply the size of the instance by the size in bytes of the data type, and return the result
    return ( member_size * sizeof( DataType ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline LargestUnsignedInteger SingleLinkedList< DataType, MemoryManagerType >::DataTypeSizeInBytes() const
{
    // Return the size in bytes of the data type
    return ( sizeof( DataType ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename UniversalReferenceDataType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceDataType, DataType >::Result == true )
inline void SingleLinkedList< DataType, MemoryManagerType >::InsertSingleElement( const LargestUnsignedInteger addTheDataAtThisIndex, UniversalReferenceDataType&& data )
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
inline void SingleLinkedList< DataType, MemoryManagerType >::InsertSingleElementCreateFromArguments( LargestUnsignedInteger addTheDataAtThisIndex, AnyArgumentNeededToConstructDataInstanceTypes&&... anyArgumentNeededToConstructDataIstance )
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
inline void SingleLinkedList< DataType, MemoryManagerType >::InsertMultipleTimesTheSameElement( const LargestUnsignedInteger addTheDataAtThisIndex, const LargestUnsignedInteger sizeToAdd, const DataType& data )
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
		firstNewNodePointer = MainMemoryManager::template AllocateAndConstruct< NodeType >( data );

		// Set the first node into the current node
		currentNewNodePointer = firstNewNodePointer;

		// Loop until all the nodes were allocated
		for ( LargestUnsignedInteger numberOfNewNodesCreated = 1UL ; numberOfNewNodesCreated < sizeToAdd ; ++numberOfNewNodesCreated )
		{
			// Allocate a new node, and connect it with the previous node in the string of nodes
			currentNewNodePointer->SetNextNode( MainMemoryManager::template AllocateAndConstruct< NodeType >( data ) );

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
inline void SingleLinkedList< DataType, MemoryManagerType >::InsertElementsFromOtherInstance( const OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >& other, const LargestUnsignedInteger firstIndexInThisInstance, const LargestUnsignedInteger firstIndexOnOtherInstance, const LargestUnsignedInteger sizeToAdd )
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
			currentNewNodePointer->SetNextNode( MainMemoryManager::template AllocateAndConstruct< NodeType >( other[ otherIndex ] ) );

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
inline void SingleLinkedList< DataType, MemoryManagerType >::InsertElementsFromOtherInstance( OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >&& other, const LargestUnsignedInteger firstIndexInThisInstance, const LargestUnsignedInteger firstIndexOnOtherInstance, const LargestUnsignedInteger sizeToAdd )
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
			currentNewNodePointer->SetNextNode( MainMemoryManager::template AllocateAndConstruct< NodeType >( TakeResourcesAndLeaveInstanceInDefaultState( other[ otherIndex ] ) ) );

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
inline void SingleLinkedList< DataType, MemoryManagerType >::InsertElementsFromRawData( const DataType* const dataPointer, const LargestUnsignedInteger addTheDataAtThisIndex, const LargestUnsignedInteger dataSize )
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
			currentNewNodePointer->SetNextNode( MainMemoryManager::template AllocateAndConstruct< NodeType >( dataPointer[ dataIndex ] ) );

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
inline void SingleLinkedList< DataType, MemoryManagerType >::Remove( const LargestUnsignedInteger indexOfFirstDataToRemove, const LargestUnsignedInteger sizeToRemove )
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
		// The data in the last node of the single linked list needs to be removed

		// Find the node before the first node that needs to be removed
		TakeShortestPathToNodeAndSetItAsTheActiveNode__Private( indexOfFirstDataToRemove - 1UL );

		// Set the first node that needs to be removed, which is the next node after the active node
		firstNodeThatNeedsToBeRemoved = member_activeNode->NextNode();

		// Set the last node that needs to be removed, which is the last node of the single linked list
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
		// The removed nodes does not include the first or last node of the single linked list

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

		// Set the next pointer of the node before the first node that needs to be removed, to point to the first node after the last
		// node that needs to be removed
		nodeBeforeFirstNodeThatNeedsToBeRemoved->SetNextNode( member_activeNode->NextNode() );

		// Set the active node to point to next node
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
inline Boolean SingleLinkedList< DataType, MemoryManagerType >::operator==( const SelfType& other ) const
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
inline Boolean SingleLinkedList< DataType, MemoryManagerType >::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline DataType& SingleLinkedList< DataType, MemoryManagerType >::operator[]( const LargestUnsignedInteger index )
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
inline const DataType& SingleLinkedList< DataType, MemoryManagerType >::operator[]( const LargestUnsignedInteger index ) const
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
inline SingleLinkedList< DataType, MemoryManagerType >& SingleLinkedList< DataType, MemoryManagerType >::operator+=( const SelfType& other )
{
    // Add the data to the end of the instance
    InsertElementsFromOtherInstance< SingleLinkedList >( other, member_size, 0UL, other.Size() );

    // Return a reference to this instance
    return ( *this );
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void SingleLinkedList< DataType, MemoryManagerType >::InsertTheNewNodesToTheRequiredLocation__Private( NodeType* const firstNodePointer, NodeType* const lastNodePointer, const LargestUnsignedInteger addNodesStartingFromThisIndex, const LargestUnsignedInteger size )
{
	// Check if the single linked list instance is empty
	if ( member_root == nullptr )
	{
		// The single linked list instance is empty

		// Set the root of the single linked list instance to the memory address of the first allocated node
		member_root = firstNodePointer;

		// Set the last node of the single linked list instance to the memory address of the last allocated node
		member_lastNode = lastNodePointer;

		// Set the last used node to point to the memory address of the first allocated node
		member_activeNode = member_root;

		// Set the index of the last used node to be 0
		member_activeNodeIndex = 0UL;
	}
	// Check if the new nodes needs to be added to the beginning of the instance
	else if ( addNodesStartingFromThisIndex == 0UL )
	{
		// The new nodes needs to be added to the beginning of the instance

		// Set the next node pointer of new last node allocated to point to the current root node 
		lastNodePointer->SetNextNode( member_root );

		// Set the root of the single linked list instance to the memory address of the first allocated node
		member_root = firstNodePointer;

		// Increment the index of the last used node by the amount of new nodes that were added
		member_activeNodeIndex += size;
	}
	// Check if the new nodes needs to be added to the end of the instance
	else if ( addNodesStartingFromThisIndex == member_size )
	{
		// The new nodes needs to be added to the end of the instance

		// Set the memory address of the first new node as the next node of the current last node of the instance
		member_lastNode->SetNextNode( firstNodePointer );

		// Set the last node of the single linked list instance to the memory address of the last node allocated
		member_lastNode = lastNodePointer;
	}
	else
	{
        // Take the shortest path to the node previous to the node associated with the index
        TakeShortestPathToNodeAndSetItAsTheActiveNode__Private( addNodesStartingFromThisIndex - 1UL );

        // Set the next node pointer of the last new node, to point to the node associated with the index larger by 1
        lastNodePointer->SetNextNode( member_activeNode->NextNode() );

        // Set the next node pointer of the first node before the node associated with index, to point to the first new node
        member_activeNode->SetNextNode( firstNodePointer );
	}

	// Increment the size of the instance by the size of the sequential platfrom
	member_size += size;
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void SingleLinkedList< DataType, MemoryManagerType >::TakeShortestPathToNodeAndSetItAsTheActiveNode__Private( const LargestUnsignedInteger index ) const
{
	// Check if the active node already points to the required node
	if ( index == member_activeNodeIndex )
	{
		// The active node is needed

		// Nothing else needs to be done
		return;			
	}

	// This object will store the number of nodes to advance until the required node
	LargestUnsignedInteger numberOfNodesToTargetNode = 0UL;

	// Check if the index associated with the required node, is smaller then the active node index
	if ( index < member_activeNodeIndex )
	{
		// The index associated with the required node, is smaller then the active node index, this means that the search will start from
		// the beginning of the instance

		// Set the active node to the root node
		member_activeNode = member_root;

		// Set the number of nodes to advance until the required node to the index
		numberOfNodesToTargetNode = index;
	}
	else
	{
		// The index associated with the required node, is larger then the active node index, this means that the search will start from
		// the active node

		// Set the number of nodes to advance
		numberOfNodesToTargetNode = index - member_activeNodeIndex;			
	}

	// Set the active node index to be as the given index
	member_activeNodeIndex = index;
	
	// Check if the required node is the last node
	if ( index == ( member_size - 1UL ) )
	{
		// The last node is needed

		// Set the active node to the root node
		member_activeNode = member_lastNode;

		// Nothing else needs to be done
		return;			
	}

	// Loop until the required amount of nodes to pass has reached
	for ( LargestUnsignedInteger numberOfNodesPassed = 0UL ; numberOfNodesPassed < numberOfNodesToTargetNode ; ++numberOfNodesPassed )
	{
		// Advance to the next node
		member_activeNode = member_activeNode->NextNode();
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void SingleLinkedList< DataType, MemoryManagerType >::DeleteNodes__Private( NodeType* const firstNodeToDelete )
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
	inline void SingleLinkedList< DataType COMMA MemoryManagerType >::UnitTest()
	{}

)  //  End of debug tool



}  //  Namespace Memory


}  //  Namespace Universe