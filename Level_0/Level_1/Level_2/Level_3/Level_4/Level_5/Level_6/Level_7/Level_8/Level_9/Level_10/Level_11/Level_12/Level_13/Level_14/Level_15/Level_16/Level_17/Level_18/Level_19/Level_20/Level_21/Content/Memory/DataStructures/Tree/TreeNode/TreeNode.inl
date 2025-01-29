//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >
inline TreeNode< DataType, IdentifierType, MemoryManagerType >::TreeNode( const MemoryHandlerName memoryHandlerName ) :
	member_identifier(),
	member_data( nullptr ),
	member_parentNode(),
	member_childNodes( memoryHandlerName )
{}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >
template< typename UniversalReferenceIdentifierType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceIdentifierType, IdentifierType >::Result == true )
inline TreeNode< DataType, IdentifierType, MemoryManagerType >::TreeNode( UniversalReferenceIdentifierType&& identifier, SelfType* const parentNode, const MemoryHandlerName memoryHandlerName ) :
	member_identifier( ForwardUniversalReference< UniversalReferenceIdentifierType >( identifier ) ),
	member_data( nullptr ),
	member_parentNode( AssignOnlyIfPointerIsNotNULL( parentNode ) ),
	member_childNodes( memoryHandlerName )
{}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >
template< typename UniversalReferenceIdentifierType, typename UniversalReferenceDataType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceIdentifierType, IdentifierType >::Result == true && CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceDataType, DataType >::Result == true )
inline TreeNode< DataType, IdentifierType, MemoryManagerType >::TreeNode( UniversalReferenceIdentifierType&& identifier, SelfType* const parentNode, UniversalReferenceDataType&& data, const MemoryHandlerName memoryHandlerName ) :
	member_identifier( ForwardUniversalReference< UniversalReferenceIdentifierType >( identifier ) ),
	member_data( nullptr ),
	member_parentNode( AssignOnlyIfPointerIsNotNULL( parentNode ) ),
	member_childNodes( memoryHandlerName )
{
    // Allocate memory space and intialize using the copy or move constructor according to the data type. Finally store the memory
    // address in the pointer
    member_data = MemoryManagerType::template AllocateAndConstruct< DataType >( ForwardUniversalReference< UniversalReferenceDataType >( data ) ).Acquire();
}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >
inline TreeNode< DataType, IdentifierType, MemoryManagerType >::~TreeNode() 
{
	// Check if the instance has no nodes that needs to be deleted, than just return
    ReturnIfExpressionIsTrue( DoesContainData() == true );

    // Free the memory space used for the data, and set the pointer to NULL
    MemoryManagerType::template Done< DataType >( member_data );
}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >
inline Boolean TreeNode< DataType, IdentifierType, MemoryManagerType >::DoesContainData() const
{
	// Check if the pointer used to store the memory address of the data is NULL or not, and return the result
	return ( member_data != nullptr );
}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >
inline DataType& TreeNode< DataType, IdentifierType, MemoryManagerType >::Data()
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertPointerIsNotNull( member_data );

	// Return a reference to the data
	return ( *member_data );
}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >
inline const DataType& TreeNode< DataType, IdentifierType, MemoryManagerType >::Data() const
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertPointerIsNotNull( member_data );

	// Return a constant reference to the data
	return ( *member_data );
}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >
template< typename UniversalReferenceDataType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceDataType, DataType >::Result == true )
inline void TreeNode< DataType, IdentifierType, MemoryManagerType >::AddData( UniversalReferenceDataType&& data )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertPointerIsNULL( member_data );

	// Allocate memory space for the data, and initialize using the memory space using the given data
	member_data = MemoryManagerType::template AllocateAndConstruct< DataType >( ForwardUniversalReference< UniversalReferenceDataType >( data ) ).Acquire();
}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >
inline void TreeNode< DataType, IdentifierType, MemoryManagerType >::RemoveData()
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertPointerIsNotNull( member_data );
	
	// Free the memory space used for the data, and set the pointer to NULL
	MemoryManagerType::template Done< DataType >( member_data );
}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >
inline void TreeNode< DataType, IdentifierType, MemoryManagerType >::AddChildNode( SelfType* const childNodePointer )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertPointerIsNotNull( childNodePointer );

	// Check that the given child node pointer identifier does not exist already in any other child node. Loop on all the childe node pointers
	for ( UnsignedInteger64bits index = 0UL ; index < member_childNodes.Size() ; ++index )
	{
		// Check that the given child node pointer identifier does not match the identifier in the current child node
		Assert( ( childNodePointer->Identify() != member_childNodes[ index ]->Identify() ), "The child node contains identifier that already exist in another childe node" );
	}

	// Add the child node pointer
	member_childNodes.InsertSingleElement( member_childNodes.Size(), childNodePointer );
}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >
inline void TreeNode< DataType, IdentifierType, MemoryManagerType >::RemoveChildNode( SelfType* const childNodePointer )
{
	// Search for the required index of the child node to remove
	const Tuple< Boolean, UnsignedInteger64bits > searchResult = member_childNodes.SearchSingleElement( childNodePointer, 1UL );

	// Check if the required child node exist
	if ( searchResult.template Entry< WAS_DATA_FOUND >() == true )
	{
		// The required child node exist

		// Remove the child node
		member_childNodes.Remove( searchResult.template Entry< DATA_LOCATION >(), 1UL );

		// Nothing else needs to be done
		return;
	}

	// A child node pointer that match the given pointer does not exist, throw an exception
	ThrowException( "There was no child node pointer that matched the given pointer" );
}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >
inline TreeNode< DataType, IdentifierType, MemoryManagerType >* TreeNode< DataType, IdentifierType, MemoryManagerType >::GetChildNode( const UnsignedInteger64bits index ) const
{
	// Use the index to return the pointer to required child node
	return ( member_childNodes[ index ] );
}


template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType >
inline void TreeNode< DataType, IdentifierType, MemoryManagerType >::SwitchMemoryHandlerUsedToStoreChildNodes( const MemoryHandlerName newMemoryHandlerName )
{
	// Switch the memory handler used to store the child nodes pointers
	member_childNodes.SwitchMemoryHandler( newMemoryHandlerName );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< Concepts::RawButPointerIsAllowed DataType COMMA typename IdentifierType COMMA typename MemoryManagerType >
	inline void TreeNode< DataType COMMA IdentifierType COMMA MemoryManagerType >::UnitTest()
	{
		// Create a test instance
		TreeNode< UnsignedInteger64bits COMMA UnsignedInteger64bits > testTreeNode_0;

		// Create a test instance
		TreeNode< UnsignedInteger64bits COMMA UnsignedInteger64bits > testTreeNode_1( 45UL, &testTreeNode_0 );

		// Add the child node
		testTreeNode_0.AddChildNode( &testTreeNode_1 );

		// Create a test instance
		TreeNode< UnsignedInteger64bits COMMA UnsignedInteger64bits > testTreeNode_5( 45UL, &testTreeNode_0 );
	}

)  //  End of debug tool



}  //  Namespace Memory


}  //  Namespace Universe