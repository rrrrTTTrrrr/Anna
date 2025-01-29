//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< Concepts::RawButPointerIsAllowed DataType >
inline DoubleLinkedListNode< DataType >::DoubleLinkedListNode( const DataType& data, SelfType* const nextNode, SelfType* const previousNode ) :
	member_data( data ),
	member_nextNode( nextNode ),
	member_previousNode( previousNode )
{}


template< Concepts::RawButPointerIsAllowed DataType >
inline DoubleLinkedListNode< DataType >::DoubleLinkedListNode( DataType&& data, SelfType* const nextNode, SelfType* const previousNode ) :
	member_data( TakeResourcesAndLeaveInstanceInDefaultState( data ) ),
	member_nextNode( nextNode ),
	member_previousNode( previousNode )
{}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< Concepts::RawButPointerIsAllowed DataType >
	inline void DoubleLinkedListNode< DataType >::UnitTest()
	{}

)  //  End of debug tool



}  //  Namespace Memory


}  //  Namespace Universe