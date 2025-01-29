// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *******************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = Built In   ***************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //




//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< Concepts::BuiltIn BuiltInType >
inline SharedResource< BuiltInType >::SharedResource() :
	member_resource( 0 ),
	member_viewAndEditSynchronization()
{}


template< Concepts::BuiltIn BuiltInType >
inline SharedResource< BuiltInType >::SharedResource( const BuiltInType& value ) :
	member_resource( value ),
	member_viewAndEditSynchronization()
{}


template< Concepts::BuiltIn BuiltInType >
template< typename ReturnType, typename... AdditionalArgumentTypes >
inline ReturnType SharedResource< BuiltInType >::View( const Callable< ReturnType ( const BuiltInType&, AdditionalArgumentTypes... ) >& callable, AdditionalArgumentTypes... additionalArguments )
{
	// Use the view and edit synchronization tool, to wait until the resource will be available for viewing
	ScopedViewAndEditSynchronization ensureResourceWillNotBeEditedDuringCopyConstruction( member_viewAndEditSynchronization );

	// Now the resource will not be changed, and it is safe to activate the task provided on the resource
	return ( callable( member_resource, ForwardUniversalReference< AdditionalArgumentTypes >( additionalArguments )... ) );
}


template< Concepts::BuiltIn BuiltInType >
template< typename ReturnType, typename... AdditionalArgumentTypes >
inline ReturnType SharedResource< BuiltInType >::Edit( const Callable< ReturnType ( BuiltInType&, AdditionalArgumentTypes... ) >& callable, AdditionalArgumentTypes... additionalArguments )
{
	// Use the view and edit synchronization tool, to wait until the resource will be available for viewing
	ScopedViewAndEditSynchronization ensureResourceWillNotBeEditedDuringCopyConstruction( member_viewAndEditSynchronization, AccessType::Edit );

	// Now the resource will not be changed, and it is safe to activate the task provided on the resource
	return ( callable( member_resource, ForwardUniversalReference< AdditionalArgumentTypes >( additionalArguments )... ) );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< Concepts::BuiltIn BuiltInType >
inline Boolean SharedResource< BuiltInType >::operator==( const SelfType& other ) const
{
	// The first stage of the method is to ensure both resources in the instance will not be changed during the comparison

	// Use the view and edit synchronization tool, to wait until the resource in this instance will be available for comparison
	ScopedViewAndEditSynchronization ensureResourceWillNotBeEditedDuringCopyConstruction( member_viewAndEditSynchronization );

	// Use the view and edit synchronization tool, to wait until the resource in the other instance will be available for comparison
	ScopedViewAndEditSynchronization ensureResourceInOtherInstanceWillNotBeEditedDuringCopyConstruction( other.member_viewAndEditSynchronization );

	// Now the resources will not be changed during the comparison

	// Compare the resource, and return the result
	return ( member_resource == other.member_resource );
}


template< Concepts::BuiltIn BuiltInType >
inline Boolean SharedResource< BuiltInType >::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = Not built int   ************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //




//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< Concepts::NotBuiltIn ObjectType >
inline SharedResource< ObjectType >::SharedResource() :
	member_resource(),
	member_viewAndEditSynchronization()
{}


template< Concepts::NotBuiltIn ObjectType >
template< typename... ArgumentNeededToConstructTheResourceTypes >
inline SharedResource< ObjectType >::SharedResource( BuildResourceFromArguments, ArgumentNeededToConstructTheResourceTypes&&... argumentsNeededToConstructTheResource ) :
	member_resource( ForwardUniversalReference< ArgumentNeededToConstructTheResourceTypes >( argumentsNeededToConstructTheResource )... ),
	member_viewAndEditSynchronization()
{}


template< Concepts::NotBuiltIn ObjectType >
inline SharedResource< ObjectType >::SharedResource( const ObjectType& resource ) :
	member_resource( resource ),
	member_viewAndEditSynchronization()
{}


template< Concepts::NotBuiltIn ObjectType >
inline SharedResource< ObjectType >::SharedResource( ObjectType&& resource ) :
	member_resource( TakeResourcesAndLeaveInstanceInDefaultState( resource ) ),
	member_viewAndEditSynchronization()
{}


template< Concepts::NotBuiltIn ObjectType >
template< typename ReturnType, typename... AdditionalArgumentTypes >
inline ReturnType SharedResource< ObjectType >::View( const Callable< ReturnType ( const ObjectType&, AdditionalArgumentTypes... ) >& callable, AdditionalArgumentTypes... additionalArguments )
{
	// Use the view and edit synchronization tool, to wait until the resource will be available for viewing
	ScopedViewAndEditSynchronization ensureResourceWillNotBeEditedDuringViewing( &member_viewAndEditSynchronization );

	// Now the resource will not be changed, and it is safe to activate the task provided on the resource
	return ( callable( member_resource, ForwardUniversalReference< AdditionalArgumentTypes >( additionalArguments )... ) );
}


template< Concepts::NotBuiltIn ObjectType >
template< typename ReturnType, typename... AdditionalArgumentTypes >
inline ReturnType SharedResource< ObjectType >::Edit( const Callable< ReturnType ( ObjectType&, AdditionalArgumentTypes... ) >& callable, AdditionalArgumentTypes... additionalArguments )
{
	// Use the view and edit synchronization tool, to wait until the resource will be available for viewing
	ScopedViewAndEditSynchronization ensureResourceWillNotBeViewedDuringEditing( &member_viewAndEditSynchronization, AccessType::Edit );

	// Now the resource will not be changed, and it is safe to activate the task provided on the resource
	return ( callable( member_resource, ForwardUniversalReference< AdditionalArgumentTypes >( additionalArguments )... ) );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< Concepts::NotBuiltIn ObjectType >
inline Boolean SharedResource< ObjectType >::operator==( const SelfType& other ) const
{
	// The first stage of the method is to ensure both resources in the instance will not be changed during the comparison

	// Use the view and edit synchronization tool, to wait until the resource in this instance will be available for comparison
	ScopedViewAndEditSynchronization ensureResourceWillNotBeEditedDuringCopyConstruction( member_viewAndEditSynchronization );

	// Use the view and edit synchronization tool, to wait until the resource in the other instance will be available for comparison
	ScopedViewAndEditSynchronization ensureResourceInOtherInstanceWillNotBeEditedDuringCopyConstruction( other.member_viewAndEditSynchronization );

	// Now the resources will not be changed during the comparison

	// Compare the resource, and return the result
	return ( member_resource == other.member_resource );
}


template< Concepts::NotBuiltIn ObjectType >
inline Boolean SharedResource< ObjectType >::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< Concepts::BuiltIn BuiltInType >
	inline void SharedResource< BuiltInType >::UnitTest()
	{}

)  //  End of debug tool



}  //  Namespace MultiThread


}  //  Namespace Universe