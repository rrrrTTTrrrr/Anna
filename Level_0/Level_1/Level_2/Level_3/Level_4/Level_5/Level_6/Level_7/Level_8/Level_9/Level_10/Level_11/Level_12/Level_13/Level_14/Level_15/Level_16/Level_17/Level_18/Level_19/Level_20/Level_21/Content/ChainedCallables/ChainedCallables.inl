//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< typename FirstFunctionType, typename ChainedFunctionReturnType >
inline ChainedCallables< FirstFunctionType, ChainedFunctionReturnType >::ChainedCallables() :
	member_firstCallable(),
	member_chainedCallable()
{}


template< typename FirstFunctionType, typename ChainedFunctionReturnType >
inline ChainedCallables< FirstFunctionType, ChainedFunctionReturnType >::ChainedCallables( Callable< FirstFunctionType >&& firstCallable, Callable< ChainedFunctionReturnType ( typename InvokableObjectReturnType< FirstFunctionType >::Type ) >&& chainedCallable ) :
	member_firstCallable( TakeResourcesAndLeaveInstanceInDefaultState( firstCallable ) ),
	member_chainedCallable( TakeResourcesAndLeaveInstanceInDefaultState( chainedCallable ) )
{}


template< typename FirstFunctionType, typename ChainedFunctionReturnType >
inline void ChainedCallables< FirstFunctionType, ChainedFunctionReturnType >::SetFirstCallable( Callable< FirstFunctionType >&& firstCallable )
{
	// Set the first callable
	member_firstCallable = TakeResourcesAndLeaveInstanceInDefaultState( firstCallable );
}


template< typename FirstFunctionType, typename ChainedFunctionReturnType >
inline void ChainedCallables< FirstFunctionType, ChainedFunctionReturnType >::SetChainedCallable( Callable< ChainedFunctionReturnType ( typename InvokableObjectReturnType< FirstFunctionType >::Type ) >&& chainedCallable )
{
	// Set the chained callable
	member_chainedCallable = TakeResourcesAndLeaveInstanceInDefaultState( chainedCallable );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************


template< typename FirstFunctionType, typename ChainedFunctionReturnType >
template< typename... ArgumentTypes >
inline typename InvokableObjectReturnType< FirstFunctionType >::Type ChainedCallables< FirstFunctionType, ChainedFunctionReturnType >::operator()( ArgumentTypes... arguments )
{
	// This object will store the return value from the last call, and will be used to pass it to the chained call
	typename InvokableObjectReturnType< FirstFunctionType >::Type firstCallabelReturnValue;

	// The first execution of the callable should be with the given arguments, and each execution from there should use the return value
	// from the last execution
	firstCallabelReturnValue = member_firstCallable( ForwardUniversalReference< ArgumentTypes >( arguments )... );

	// Execute the chained callable and return the result
	return ( member_chainedCallable( firstCallabelReturnValue ) );
}


template< typename FirstFunctionType, typename ChainedFunctionReturnType >
template< typename... ArgumentTypes >
inline typename InvokableObjectReturnType< FirstFunctionType >::Type ChainedCallables< FirstFunctionType, ChainedFunctionReturnType >::operator()( ArgumentTypes... arguments ) const
{
	// This object will store the return value from the last call, and will be used to pass it to the chained call
	typename InvokableObjectReturnType< FirstFunctionType >::Type firstCallabelReturnValue;

	// The first execution of the callable should be with the given arguments, and each execution from there should use the return value
	// from the last execution
	firstCallabelReturnValue = member_firstCallable( ForwardUniversalReference< ArgumentTypes >( arguments )... );

	// Execute the chained callable and return the result
	return ( member_chainedCallable( firstCallabelReturnValue ) );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< typename FirstFunctionType COMMA typename ChainedFunctionReturnType >
	inline void ChainedCallables< FirstFunctionType COMMA ChainedFunctionReturnType >::UnitTest()
	{}

)  //  End of debug tool



}  //  Namespace Universe