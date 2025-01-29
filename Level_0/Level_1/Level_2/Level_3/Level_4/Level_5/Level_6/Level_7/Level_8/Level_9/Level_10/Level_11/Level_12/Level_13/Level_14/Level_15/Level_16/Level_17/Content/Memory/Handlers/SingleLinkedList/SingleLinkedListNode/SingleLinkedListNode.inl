//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< Concepts::RawButPointerIsAllowed DataType >
inline SingleLinkedListNode< DataType >::SingleLinkedListNode( const DataType& data, SelfType* const nextNode ) :
	member_data( data ),
	member_nextNode( nextNode )
{}


template< Concepts::RawButPointerIsAllowed DataType >
inline SingleLinkedListNode< DataType >::SingleLinkedListNode( DataType&& data, SelfType* const nextNode ) :
	member_data( TakeResourcesAndLeaveInstanceInDefaultState( data ) ),
	member_nextNode( nextNode )
{}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< Concepts::RawButPointerIsAllowed DataType >
	inline void SingleLinkedListNode< DataType >::UnitTest()
	{}

)  //  End of debug tool



}  //  Namespace Memory


}  //  Namespace Universe