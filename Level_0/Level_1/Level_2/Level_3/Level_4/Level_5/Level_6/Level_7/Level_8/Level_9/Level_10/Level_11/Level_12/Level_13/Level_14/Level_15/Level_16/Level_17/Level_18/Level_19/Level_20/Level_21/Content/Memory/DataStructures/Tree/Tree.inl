//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >
inline Tree< DataType, IdentifierType, MemoryManagerType >::Tree() :
	member_root( nullptr ),
	member_numberOfNodesWithData( 0UL )
{}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >
inline Tree< DataType, IdentifierType, MemoryManagerType >::Tree( const SelfType& other ) :
	member_root( nullptr ),
	member_numberOfNodesWithData( other.member_numberOfNodesWithData )
{
	// Try catch block to ensure that all the memory space allocated is deleted before rethrowing the exception, because the instance is
	// not yet fully constructed, which means the destructor of it won't be called 
	try
	{
		// Check if the other instance has nodes that needs to be copied
		if ( other.member_root != nullptr )
		{
			// The other instance has nodes that needs to be copied

			// Allocate the root node
			member_root = MemoryManagerType::template AllocateAndDefaultConstruct< NodeType >();

			// Recursively pass on the other instance nodes and copy them into this instance
			CopyNodesRecursively__Private( other.member_root, member_root );
		}
	}
	catch ( const std::bad_alloc& exception )
	{
		// Delete all the nodes allocated so far recursively
		DeleteAllNodes__Private();

		// Rethrow the exception to notify the caller that the operation failed
		throw;
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >
inline Tree< DataType, IdentifierType, MemoryManagerType >::~Tree()
{
    // Delete all the instance nodes recursively
    DeleteAllNodes__Private();
}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >
template< typename KeyType >	
inline Boolean Tree< DataType, IdentifierType, MemoryManagerType >::DoesKeyExist( const KeyType& key ) const
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsLargerThenZero( key.Size() );

	// Check if the instance is empty, which means the key does not exist
	ReturnValueIfExpressionIsTrue( ( member_numberOfNodesWithData == 0UL ), false );

	// Pass on the key to check of much of the path it represent already exist in the tree instance
	const Memory::Tuple< NodeType*, LargestUnsignedInteger > pointerToLastNodeThatCurrentlyExistInThePathRepresentedByTheKey = GetPointerToLastNodeThatCurrentlyExistInThePathRepresentedByTheKeyAndIndexForTheLocationOnTheKey__Private( key );

	// If all the path that the key represent does not exist, or the node itself does not contain data return false
	ReturnValueIfExpressionIsTrue( ( ( pointerToLastNodeThatCurrentlyExistInThePathRepresentedByTheKey.template Entry< 1UL >() != key.Size() ) || ( pointerToLastNodeThatCurrentlyExistInThePathRepresentedByTheKey.template Entry< 0UL >()->DoesContainData() == false ) ), false );

	// The key exist return true
	return ( true );
}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >
template< typename KeyType, typename UniversalReferenceDataType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceDataType, DataType >::Result == true )
inline void Tree< DataType, IdentifierType, MemoryManagerType >::Insert( const KeyType& key, UniversalReferenceDataType&& data )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsLargerThenZero( key.Size() );

	// Check if the instance is in default state
	if ( member_root == nullptr )
	{
		// The instance is in default state

		// Allocate the root node
		member_root = MemoryManagerType::template AllocateAndDefaultConstruct< NodeType >();
	}

	// This pointer will store the current node
	NodeType* currentNode = member_root;

	// This pointer will store the memory address of the child node with the required identifier
	NodeType* childNodeWithTheRequiredIdentifier = nullptr;

	// Loop on all the entries of the key
	for ( LargestUnsignedInteger keyIndex = 0UL ; keyIndex < key.Size() ; ++keyIndex )
	{
		// Try to get the the child node with the required identifier
		childNodeWithTheRequiredIdentifier = GetChildNodeWithTheRequiredIdentifier__Private( currentNode, key[ keyIndex ] );

		// Check if a child node with the required identifier exist
		if ( childNodeWithTheRequiredIdentifier == nullptr )
		{
			// A child node with the required identifier does not exist

			// Allocate a new node and initialize it using the identifier
			childNodeWithTheRequiredIdentifier = MemoryManagerType::template AllocateAndConstruct< NodeType >( key[ keyIndex ], currentNode );

			// Add the child node
			currentNode->AddChildNode( childNodeWithTheRequiredIdentifier );
		}

		// Set the current node to the child node with the required identifier
		currentNode = childNodeWithTheRequiredIdentifier;
	}

	// Check if data in the current node is already associated with the key, then throw an exception
	Assert( ( currentNode->DoesContainData() == false ), "The key is already associated with data" );

	// Store the data in the node
	currentNode->AddData( ForwardUniversalReference< UniversalReferenceDataType >( data ) );

	// Increment the number of nodes with data in the instance by 1
	member_numberOfNodesWithData += 1UL;
}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >
template< typename KeyType >
inline void Tree< DataType, IdentifierType, MemoryManagerType >::Remove( const KeyType& key )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertPointerIsNotNull( member_root );
	AssertValueIsLargerThenZero( member_numberOfNodesWithData );
	AssertValueIsLargerThenZero( key.Size() );

	// Get node associated with the key
	NodeType* const nodeAssociatedWithTheKey = GetNodeAssociatedWithTheKey__Private( key );

	// Now that the required node was located, check if the instance will be empty after the removal, or in other words there is only 
	// one node with data
	if ( member_numberOfNodesWithData == 1UL ) 
	{
		// There is only one node with data

		// Reset the instance
		Reset();

		// Nothing else needs to be done
		return;
	}

	// Decrement the number of nodes with data in the instance by 1
	member_numberOfNodesWithData -= 1UL;

	// Check if the node contains child nodes
	if ( nodeAssociatedWithTheKey->NumberOfChildNodes() > 0UL )
	{
		// The node contains child nodes

		// The node can not be deleted, its part of the path for other data as well, just remove the data from it
		nodeAssociatedWithTheKey->RemoveData();

		// Nothing else needs to be done
		return;
	}

	// This pointer will store the current node that needs to be deleted
	NodeType* nodeToDelete = nodeAssociatedWithTheKey;

	// This pointer will store the parent node of the current node that needs to be deleted
	NodeType* nodeToDeleteParentNode = nodeToDelete->ParentNode();

	// Move up the path and delete all the nodes that does not have data and no child nodes
	do
	{
		// Remove the node to delete from the parent node
		nodeToDeleteParentNode->RemoveChildNode( nodeToDelete );

		// Delete the node
		delete nodeToDelete;

		// Set the current node to delete as the parent of the node who was just deleted
		nodeToDelete = nodeToDeleteParentNode;

		// Advance the pointer to the parent node
		nodeToDeleteParentNode = nodeToDeleteParentNode->ParentNode();

	} while ( ( nodeToDelete->DoesContainData() == false ) && ( nodeToDelete->NumberOfChildNodes() == 0UL ) && ( nodeToDeleteParentNode != nullptr ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >	
template< typename InvokableObject >
inline void Tree< DataType, IdentifierType, MemoryManagerType >::ForEachElementDo( InvokableObject&& action )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsLargerThenZero( member_numberOfNodesWithData );

	// This object will store the key for each data passed to the action to execute
	SequentialDataStructure< IdentifierType > key( MemoryHandlerName::SingleLinkedList );

	// This object will store the number of child nodes in the root node
	const LargestUnsignedInteger numberOfChildNodesForRoot = member_root->NumberOfChildNodes();

	// Loop on all the child nodes of the tree root
	for ( LargestUnsignedInteger childNodeIndex = 0UL ; childNodeIndex < numberOfChildNodesForRoot ; ++childNodeIndex )
	{
		// Pass the function to execute on each data in the instance to the recursice method
		PassRecursivelyOnAllTheNodesAndExecuteTheRequiredAction__Private( member_root->GetChildNode( childNodeIndex ), key, action );
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >	
template< typename InvokableObject >
inline void Tree< DataType, IdentifierType, MemoryManagerType >::ForEachElementDo( InvokableObject&& action ) const
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsLargerThenZero( member_numberOfNodesWithData );

	// This object will store the key for each data passed to the action to execute
	SequentialDataStructure< IdentifierType > key( MemoryHandlerName::SingleLinkedList );

	// This object will store the number of child nodes in the root node
	const LargestUnsignedInteger numberOfChildNodesForRoot = member_root->NumberOfChildNodes();

	// Loop on all the child nodes of the tree root
	for ( LargestUnsignedInteger childNodeIndex = 0UL ; childNodeIndex < numberOfChildNodesForRoot ; ++childNodeIndex )
	{
		// Pass the function to execute on each data in the instance to the recursice method
		PassRecursivelyOnAllTheNodesAndExecuteTheRequiredAction__Private( member_root->GetChildNode( childNodeIndex ), key, action );
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >	
inline SequentialDataStructure< SequentialDataStructure< IdentifierType > > Tree< DataType, IdentifierType, MemoryManagerType >::Search( const DataType& data ) const
{
	// This object will store the keys associated with the data, if the data exist in the instance
	SequentialDataStructure< SequentialDataStructure< IdentifierType > > keysAssociatedWithData( MemoryHandlerName::SingleLinkedList );
	
	// Pass on all the nodes with data in the instance, check if the data inside them match the given data, and if it does add the key to
	// search result
	ForEachElementDo( [ &data, &keysAssociatedWithData ]( const DataType& nodeData, const SequentialDataStructure< IdentifierType >& key ) -> Boolean
	{
		// Check if the data in the current node match the given data
		if ( data == nodeData )
		{
			// The data match

			// Add the key
			keysAssociatedWithData.InsertSingleElementAtTheEnd( key );
		}

		// Return false to continue the search on the instance, in case the data exist more than once
		return ( false );
	});

	// Return the search result
	return ( keysAssociatedWithData );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >
inline Boolean Tree< DataType, IdentifierType, MemoryManagerType >::operator==( const SelfType& other ) const
{
	// Compare the instances and return the result
	return ( ( member_numberOfNodesWithData == other.member_numberOfNodesWithData ) && CompareNodesRecursively__Private( member_root, other.member_root ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >
inline Boolean Tree< DataType, IdentifierType, MemoryManagerType >::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >
template< typename KeyType >
inline DataType& Tree< DataType, IdentifierType, MemoryManagerType >::operator[]( const KeyType& key )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertPointerIsNotNull( member_root );
	AssertValueIsLargerThenZero( key.Size() );

	// Get the node associated with the key
	NodeType* const nodeAssociatedWithTheKey = GetNodeAssociatedWithTheKey__Private( key );

	// Return a constant reference to the data inside the node
	return ( nodeAssociatedWithTheKey->Data() );
}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >
template< typename KeyType >
inline const DataType& Tree< DataType, IdentifierType, MemoryManagerType >::operator[]( const KeyType& key ) const
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertPointerIsNotNull( member_root );
	AssertValueIsLargerThenZero( key.Size() );

	// Get the node associated with the key
	NodeType* const nodeAssociatedWithTheKey = GetNodeAssociatedWithTheKey__Private( key );

	// Return a constant reference to the data inside the node
	return ( nodeAssociatedWithTheKey->Data() );
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >
inline void Tree< DataType, IdentifierType, MemoryManagerType >::CopyNodesRecursively__Private( const NodeType* const nodeInOtherInstancePointer, NodeType* const parentNodeInThisInstancePointer )
{
	// Check if the node in the other instance has child nodes
	if ( nodeInOtherInstancePointer->NumberOfChildNodes() == 0UL )
	{
		// The node in the other instance has no chile nodes

		// Nothing else needs to be done in this branch
		return;
	}

	// This pointer will store the memory address of the child node pointer in the other instance
	NodeType* childNodeInOtherInstancePointer = nullptr;

	// This pointer will store the current allocated chile node
	NodeType* newNode = nullptr;

	// Pass on each child node
	for ( LargestUnsignedInteger childNodeIndex = 0UL ; childNodeIndex < nodeInOtherInstancePointer->NumberOfChildNodes() ; ++childNodeIndex )
	{
		// Set the current child node in the other instance
		childNodeInOtherInstancePointer = nodeInOtherInstancePointer->GetChildNode( childNodeIndex );

		// Allocate a new node and store the memory address of it
		newNode = MemoryManagerType::template AllocateAndConstruct< NodeType >( childNodeInOtherInstancePointer->Identify(), parentNodeInThisInstancePointer );

		// Check if the node has data
		if ( childNodeInOtherInstancePointer->DoesContainData() == true )
		{
			// The node has data

			// Copy the data into the new node
			newNode->AddData( childNodeInOtherInstancePointer->Data() );
		}

		// Add the pointer to the new node to the child node pointers of the parent node
		parentNodeInThisInstancePointer->AddChildNode( newNode );

		// Recursively call this method on it, to copy it as well
		CopyNodesRecursively__Private( childNodeInOtherInstancePointer, newNode );
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >
inline void Tree< DataType, IdentifierType, MemoryManagerType >::DeleteAllNodes__Private()
{
	// Check if the instance has no nodes that needs to be deleted, than just return
    ReturnIfExpressionIsTrue( member_root == nullptr );

    // Delete all the instance nodes recursively
    DeleteNodesRecursively__Private( member_root );
}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >
inline void Tree< DataType, IdentifierType, MemoryManagerType >::DeleteNodesRecursively__Private( NodeType* const nodePointer )
{
	// Pass on all the child nodes
	for ( LargestUnsignedInteger childNodeIndex = 0UL ; childNodeIndex < nodePointer->NumberOfChildNodes() ; ++childNodeIndex )
	{
		// Recursively call this method on the current child node
		DeleteNodesRecursively__Private( nodePointer->GetChildNode( childNodeIndex ) );
	}

	// Delete the node
	MemoryManagerType::template Done< NodeType >( nodePointer );
}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >
inline TreeNode< DataType, IdentifierType, MemoryManagerType >* Tree< DataType, IdentifierType, MemoryManagerType >::GetChildNodeWithTheRequiredIdentifier__Private( const NodeType* const nodePointer, const IdentifierType& identifier ) const
{
	// This pointer will store the current child node
	NodeType* currentChildNodePointer = nullptr;

	// Pass on all the child nodes
	for ( LargestUnsignedInteger childNodeIndex = 0UL ; childNodeIndex < nodePointer->NumberOfChildNodes() ; ++childNodeIndex )
	{
		// Get the current child node pointer
		currentChildNodePointer = nodePointer->GetChildNode( childNodeIndex );

		// Check if the current child node identifer match the required one
		ReturnValueIfExpressionIsTrue( ( currentChildNodePointer->Identify() == identifier ), currentChildNodePointer );
	}

	// The node does not contain a child node with the requied identifier
	return ( nullptr );
}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >
template< typename KeyType >
inline Memory::Tuple< TreeNode< DataType, IdentifierType, MemoryManagerType >*, LargestUnsignedInteger > Tree< DataType, IdentifierType, MemoryManagerType >::GetPointerToLastNodeThatCurrentlyExistInThePathRepresentedByTheKeyAndIndexForTheLocationOnTheKey__Private( const KeyType& key ) const
{
	// This object will store the memory addres of the current node
	NodeType* currentNode = member_root;

	// This object will store the memory address of the child node with the required identifier if exist
	NodeType* currentChildNodePointer = nullptr;		

	// Loop on the key entries
	for ( LargestUnsignedInteger keyIndex = 0UL ; keyIndex < key.Size() ; ++keyIndex )
	{
		// Try to get the child node with the current identifier in the key
		currentChildNodePointer = GetChildNodeWithTheRequiredIdentifier__Private( currentNode, key[ keyIndex ] );

		// Check if a child node with the required identifier was found
		if ( currentChildNodePointer == nullptr )
		{
			// A child node with the required identifier was not found 

			// Return a pointer to the current node, and set the current key index, which is smaller than the key size to notify that not
			// all the path that the key represent exist
			return ( Memory::Tuple< NodeType*, LargestUnsignedInteger >( currentNode, keyIndex ) );
		}

		// Set the current node to child node found
		currentNode = currentChildNodePointer;
	}

	// A node that match the key was found, return a pointer to it, and set the size of the key to notify that all the path that the key
	// represent exist
	return ( Memory::Tuple< NodeType*, LargestUnsignedInteger >( currentNode, key.Size() ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >	
template< typename KeyType >
inline TreeNode< DataType, IdentifierType, MemoryManagerType >* Tree< DataType, IdentifierType, MemoryManagerType >::GetNodeAssociatedWithTheKey__Private( const KeyType& key )
{
	// Pass on the key to check of much of the path it represent already exist in the tree instance
	const Memory::Tuple< NodeType*, LargestUnsignedInteger > pointerToLastNodeThatCurrentlyExistInThePathRepresentedByTheKey = GetPointerToLastNodeThatCurrentlyExistInThePathRepresentedByTheKeyAndIndexForTheLocationOnTheKey__Private( key );

	// Ensure that all the path that the key represent already exist
	Assert( ( pointerToLastNodeThatCurrentlyExistInThePathRepresentedByTheKey.template Entry< 1UL >() == key.Size() ), "A node associated with the key does not exist" );

	// Ensure that the node contains data
	Assert( ( pointerToLastNodeThatCurrentlyExistInThePathRepresentedByTheKey.template Entry< 0UL >()->DoesContainData() == true ), "The node associated with the key does not contain data" );

	// Return the pointer to the node associated with the key
	return ( pointerToLastNodeThatCurrentlyExistInThePathRepresentedByTheKey.template Entry< 0UL >() );
}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >	
template< typename InvokableObject >
inline Boolean Tree< DataType, IdentifierType, MemoryManagerType >::PassRecursivelyOnAllTheNodesAndExecuteTheRequiredAction__Private( NodeType* const nodePointer, SequentialDataStructure< IdentifierType >& key, InvokableObject&& action )
{
	// Add the identifer of the current node to the key
	key.InsertSingleElementAtTheEnd( nodePointer->Identify() );

	// Check if the current node contains data
	if ( nodePointer->DoesContainData() == true )
	{
		// The current node contains data

		// Execute the required action on the data in the node, and check the return value, if the passing on the nodes should stop
		if ( action( nodePointer->Data(), key ) == true )
		{
			// The passing on the node should be stopped

			// Return true
			return ( true );
		}
	}

	// This object will store the number of child nodes in the node
	const LargestUnsignedInteger numberOfChildNodes = nodePointer->NumberOfChildNodes();

	// Pass on all the child nodes of the current node, and recursively execute this method on them
	for ( LargestUnsignedInteger childNodeIndex = 0UL ; childNodeIndex < numberOfChildNodes ; ++childNodeIndex )
	{
		// Perform the recursive call on the current child node, and check the return value, if the passing on the nodes should stop
		if ( PassRecursivelyOnAllTheNodesAndExecuteTheRequiredAction__Private( nodePointer->GetChildNode( childNodeIndex ), key, action ) == true )
		{
			// The passing on the node should be stopped

			// Return true
			return ( true );
		}
	}

	// Remove the identifer of the current node from the key
	key.RemoveLast();

	// Return false to continue the recurssion
	return ( false );
}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >	
template< typename InvokableObject >
inline Boolean Tree< DataType, IdentifierType, MemoryManagerType >::PassRecursivelyOnAllTheNodesAndExecuteTheRequiredAction__Private( NodeType* const nodePointer, SequentialDataStructure< IdentifierType >& key, InvokableObject&& action ) const
{
	// Add the identifer of the current node to the key
	key.InsertSingleElementAtTheEnd( nodePointer->Identify() );

	// Check if the current node contains data
	if ( nodePointer->DoesContainData() == true )
	{
		// The current node contains data

		// Execute the required action on the data in the node, and check the return value, if the passing on the nodes should stop
		if ( action( nodePointer->Data(), key ) == true )
		{
			// The passing on the node should be stopped

			// Return true
			return ( true );
		}
	}

	// This object will store the number of child nodes in the node
	const LargestUnsignedInteger numberOfChildNodes = nodePointer->NumberOfChildNodes();

	// Pass on all the child nodes of the current node, and recursively execute this method on them
	for ( LargestUnsignedInteger childNodeIndex = 0UL ; childNodeIndex < numberOfChildNodes ; ++childNodeIndex )
	{
		// Perform the recursive call on the current child node, and check the return value, if the passing on the nodes should stop
		if ( PassRecursivelyOnAllTheNodesAndExecuteTheRequiredAction__Private( nodePointer->GetChildNode( childNodeIndex ), key, action ) == true )
		{
			// The passing on the node should be stopped

			// Return true
			return ( true );
		}
	}

	// Remove the identifer of the current node from the key
	key.RemoveLast();

	// Return false to continue the recurssion
	return ( false );
}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >
inline Boolean Tree< DataType, IdentifierType, MemoryManagerType >::CompareNodesRecursively__Private( const NodeType* const nodeInThisInstancePointer, const NodeType* const nodeInOtherInstancePointer ) const
{
	// Compare the nodes identifier, and if it mismatch return false
	ReturnValueIfExpressionIsTrue( ( nodeInThisInstancePointer->Identify() != nodeInOtherInstancePointer->Identify() ), false );

	// This object will store the number of child nodes in the node in this instance
	const LargestUnsignedInteger numberOfChildNodesForTheNodeInThisInstance = nodeInThisInstancePointer->NumberOfChildNodes();

	// Check that the number of child nodes is the same for both nodes, and if not return false
	ReturnValueIfExpressionIsTrue( ( numberOfChildNodesForTheNodeInThisInstance != nodeInOtherInstancePointer->NumberOfChildNodes() ), false );

	// Check that both nodes either have data or not, and if not return false
	ReturnValueIfExpressionIsTrue( ( nodeInThisInstancePointer->DoesContainData() != nodeInOtherInstancePointer->DoesContainData() ), false );

	// Check if both nodes have data
	if ( nodeInThisInstancePointer->DoesContainData() == true )
	{
		// Both nodes have data

		// Check that both nodes contain the same data, if not return false
		ReturnValueIfExpressionIsTrue( ( nodeInThisInstancePointer->Data() != nodeInOtherInstancePointer->Data() ), false );
	}

	// Loop on all the child nodes in the node of this instance
	for ( LargestUnsignedInteger childNodeIndex = 0UL ; childNodeIndex < numberOfChildNodesForTheNodeInThisInstance ; ++childNodeIndex )
	{
		// Recursively call this method on the nodes, to keep the comparing process
		ReturnValueIfExpressionIsTrue( ( CompareNodesRecursively__Private( nodeInThisInstancePointer->GetChildNode( childNodeIndex ), nodeInOtherInstancePointer->GetChildNode( childNodeIndex ) ) == false ), false );
	}

	// The node match, return true
	return ( true );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< Concepts::RawButPointerIsAllowed DataType COMMA typename IdentifierType COMMA typename MemoryManagerType  >
	inline void Tree< DataType COMMA IdentifierType COMMA MemoryManagerType >::UnitTest()
	{
		// Create a test instane
		Tree< LargestUnsignedInteger COMMA LargestUnsignedInteger > testTreeInstance_0;

		// Create 2 keys
		SequentialDataStructure< LargestUnsignedInteger > testKey_0( MemoryHandlerName::Vector, Random::RunTimeGenerator::Numeric::Next< LargestUnsignedInteger >( Range< LargestUnsignedInteger >( 1UL, 3UL ) ) );
		SequentialDataStructure< LargestUnsignedInteger > testKey_1( MemoryHandlerName::Vector, Random::RunTimeGenerator::Numeric::Next< LargestUnsignedInteger >( Range< LargestUnsignedInteger >( 1UL, 3UL ) ) );

		Random::RunTimeGenerator::Numeric::SetMultipleNext< LargestUnsignedInteger COMMA SequentialDataStructure< LargestUnsignedInteger > >( testKey_0 );
		Random::RunTimeGenerator::Numeric::SetMultipleNext< LargestUnsignedInteger COMMA SequentialDataStructure< LargestUnsignedInteger > >( testKey_1 );

		// Check that the keys does not exist
		Assert_Test( testTreeInstance_0.DoesKeyExist( testKey_0 ) == false );
		Assert_Test( testTreeInstance_0.DoesKeyExist( testKey_1 ) == false );

		// Insert data into the instance
		testTreeInstance_0.Insert( testKey_0, 8UL );
		testTreeInstance_0.Insert( testKey_1, 10UL );

		// Check that the keys does not exist
		Assert_Test( testTreeInstance_0.DoesKeyExist( testKey_0 ) == true );
		Assert_Test( testTreeInstance_0.DoesKeyExist( testKey_1 ) == true );

		// Assert that the key retrieves the correct data
		Assert_Test( testTreeInstance_0[ testKey_0 ] == 8UL );
		Assert_Test( testTreeInstance_0[ testKey_1 ] == 10UL );

		// Set other values
		testTreeInstance_0[ testKey_0 ] = 88UL;
		testTreeInstance_0[ testKey_1 ] = 108UL;

		// Assert that the key retrieves the correct data
		Assert_Test( testTreeInstance_0[ testKey_0 ] == 88UL );
		Assert_Test( testTreeInstance_0[ testKey_1 ] == 108UL );			

		// Create an instance using the copy constructor
		Tree< LargestUnsignedInteger COMMA LargestUnsignedInteger > testTreeInstance_1( testTreeInstance_0 );

		// Assert that both instance are the same
		Assert_Test( testTreeInstance_0 == testTreeInstance_1 );
		Assert_Test( ( testTreeInstance_0 != testTreeInstance_1 ) == false );

		// Create a varibel to use as capture in a lambda
		LargestUnsignedInteger testVariableToCapture_0 = 4564UL;

		// Try the for each element do method, with lambda
		testTreeInstance_0.ForEachElementDo( []( const LargestUnsignedInteger& data, const SequentialDataStructure< LargestUnsignedInteger >& key ) -> Boolean
		{

			Assert_Test( ( data == 88UL ) || ( data == 108UL ) );

			return false;

		} );

		// Try the for each element do method, with lambda
		testTreeInstance_0.ForEachElementDo( [ testVariableToCapture_0 ]( const LargestUnsignedInteger& data, const SequentialDataStructure< LargestUnsignedInteger >& key ) -> Boolean
		{

			Assert_Test( ( data == 88UL ) || ( data == 108UL ) );
			Assert_Test( testVariableToCapture_0 == 4564UL );

			return false;

		} );


		// Search for the data
		const auto searchResult_0 = testTreeInstance_0.Search( 88UL );

		// Assert that the search result is not empty and contains the correct key
		Assert_Test( searchResult_0.Size() != 0UL );
		Assert_Test( searchResult_0[0].Compare( testKey_0, 0UL, 0UL, testKey_0.Size() ) == true );

		// Search for the data
		const auto searchResult_1 = testTreeInstance_0.Search( 54UL );

		// Assert that the search result is empty
		Assert_Test( searchResult_1.Size() == 0UL );

		// Remove all the data from the instance
		testTreeInstance_0.Remove( testKey_0 );
		testTreeInstance_0.Remove( testKey_1 );

		// Check that the keys does not exist
		Assert_Test( testTreeInstance_0.DoesKeyExist( testKey_0 ) == false );
		Assert_Test( testTreeInstance_0.DoesKeyExist( testKey_1 ) == false );
	}

)  //  End of debug tool




}  //  Namespace Memory


}  //  Namespace Universe