// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *******************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = Built In   ***************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //




//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< Concepts::BuiltIn BuiltInType >
inline CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource< BuiltInType >::CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource() :
	member_resource( 0 ),
	member_spinWaitLoop()
{}


template< Concepts::BuiltIn BuiltInType >
inline CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource< BuiltInType >::CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource( const BuiltInType& value ) :
	member_resource( value ),
	member_spinWaitLoop()
{}


template< Concepts::BuiltIn BuiltInType >
inline Boolean CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource< BuiltInType >::CompareTheActualValueWithTheExpectedAndIfEqualSetTheDesiredValue( const BuiltInType expectedValue, const BuiltInType desiredValue )
{
	// Try getting the value of the variable from cache. If the cache is invalidated, fetch the value from system memory. Now compare it 
	// with the given value. If the comparison is true write the required new value, instead of the old one, to system memory. Ensure that
	// all central processing are aware of the change, by invalidating the proper caches. Finally return the result of the comparison
	return ( CentralProcessingUnit::CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::Read_Compare_IfTrueStoreTheDesiredValueInstead( &member_resource, expectedValue, desiredValue ) );
}


template< Concepts::BuiltIn BuiltInType >
template< typename InvokableObjectType, typename ReturnType, typename... ArgumentTypes >
inline ReturnType CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource< BuiltInType >::View( InvokableObjectType&& invokableObject, ArgumentTypes&&... arguments )
{
	// Use the spin wait loop synchronization tool, to wait until only this thread of execution will be allowed to use the resource
	ScopedSpinWaitLoop ensureOnlyThisThreadOfExecutionWillUseTheResource( &member_spinWaitLoop );

	// Now the resource will not be changed, and it is safe to activate the task provided on the resource
	return ( invokableObject( member_resource, ForwardUniversalReference< ArgumentTypes >( arguments )... ) );
}


template< Concepts::BuiltIn BuiltInType >
template< typename InvokableObjectType, typename ReturnType, typename... ArgumentTypes >
inline ReturnType CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource< BuiltInType >::Edit( InvokableObjectType&& invokableObject, ArgumentTypes&&... arguments )
{
	// Use the spin wait loop synchronization tool, to wait until only this thread of execution will be allowed to use the resource
	ScopedSpinWaitLoop ensureOnlyThisThreadOfExecutionWillUseTheResource( &member_spinWaitLoop );

	// Now the resource will not be changed, and it is safe to activate the task provided on the resource
	return ( invokableObject( member_resource, ForwardUniversalReference< ArgumentTypes >( arguments )... ) );
}




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = Not built int   ************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //




//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< Concepts::NotBuiltIn ObjectType >
inline CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource< ObjectType >::CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource() :
	member_resource(),
	member_spinWaitLoop()
{}


template< Concepts::NotBuiltIn ObjectType >
template< typename... ArgumentNeededToConstructTheResourceTypes >
inline CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource< ObjectType >::CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource( BuildResourceFromArguments, ArgumentNeededToConstructTheResourceTypes&&... argumentsNeededToConstructTheResource ) :
	member_resource( ForwardUniversalReference< ArgumentNeededToConstructTheResourceTypes >( argumentsNeededToConstructTheResource )... ),
	member_spinWaitLoop()
{}


template< Concepts::NotBuiltIn ObjectType >
inline CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource< ObjectType >::CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource( const ObjectType& resource ) :
	member_resource( resource ),
	member_spinWaitLoop()
{}


template< Concepts::NotBuiltIn ObjectType >
inline CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource< ObjectType >::CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource( ObjectType&& resource ) :
	member_resource( TakeResourcesAndLeaveInstanceInDefaultState( resource ) ),
	member_spinWaitLoop()
{}


template< Concepts::NotBuiltIn ObjectType >
template< typename UniversalReferenceResourceObjectType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceResourceObjectType, ObjectType >::Result == true  )
inline Boolean CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource< ObjectType >::CompareTheActualValueWithTheExpectedAndIfEqualSetTheDesiredValue( const ObjectType& resourceToCompareWith, UniversalReferenceResourceObjectType&& resourceToSetIfComparisonTrue )
{
	// Use the spin wait loop synchronization tool, to wait until only this thread of execution will be allowed to use the resource
	ScopedSpinWaitLoop ensureOnlyThisThreadOfExecutionWillUseTheResource( &member_spinWaitLoop );

	// Compare the resource in this isntance with the required value
	Boolean comparisonResult = ( member_resource == resourceToCompareWith );

	// Check if the comparison result was true
	if ( comparisonResult == true )
	{
		// The resources are the same

		// Set the new resource into this instace
		member_resource = TakeResourcesAndLeaveInstanceInDefaultStateIfPossibleOtherwiseCopy< ObjectType >( ForwardUniversalReference< ObjectType >( resourceToSetIfComparisonTrue ) );
	}

	// Return the comparison result, this way the caller can know if the content of this instance changed or not
	return ( comparisonResult );
}


template< Concepts::NotBuiltIn ObjectType >
template< typename InvokableObjectType, typename ReturnType, typename... ArgumentTypes >
inline ReturnType CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource< ObjectType >::View( InvokableObjectType&& invokableObject, ArgumentTypes&&... arguments )
{
	// Use the spin wait loop synchronization tool, to wait until only this thread of execution will be allowed to use the resource
	ScopedSpinWaitLoop ensureOnlyThisThreadOfExecutionWillUseTheResource( &member_spinWaitLoop );

	// Now the resource will not be changed, and it is safe to activate the task provided on the resource
	return ( invokableObject( const_cast< ObjectType >( member_resource ), ForwardUniversalReference< ArgumentTypes >( arguments )... ) );
}


template< Concepts::NotBuiltIn ObjectType >
template< typename InvokableObjectType, typename ReturnType, typename... ArgumentTypes >
inline ReturnType CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource< ObjectType >::Edit( InvokableObjectType&& invokableObject, ArgumentTypes&&... arguments )
{
	// Use the spin wait loop synchronization tool, to wait until only this thread of execution will be allowed to use the resource
	ScopedSpinWaitLoop ensureOnlyThisThreadOfExecutionWillUseTheResource( &member_spinWaitLoop );

	// Now the resource will not be changed, and it is safe to activate the task provided on the resource
	return ( invokableObject( member_resource, ForwardUniversalReference< ArgumentTypes >( arguments )... ) );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< Concepts::BuiltIn BuiltInType >
	inline void CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource< BuiltInType >::UnitTest()
	{}

)  //  End of debug tool



}  //  Namespace MultiThread


}  //  Namespace Universe