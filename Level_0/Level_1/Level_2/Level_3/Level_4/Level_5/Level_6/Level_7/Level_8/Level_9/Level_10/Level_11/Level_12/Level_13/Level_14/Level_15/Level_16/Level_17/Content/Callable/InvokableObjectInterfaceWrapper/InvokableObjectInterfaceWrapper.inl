//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< typename FunctorType, typename ReturnType, typename... ArgumentTypes > requires( Concepts::FunctorWithSpecificReturnType< FunctorType, ReturnType, ArgumentTypes... > )
inline InvokableObjectInterfaceWrapper< FunctorType, ReturnType, ArgumentTypes... >::InvokableObjectInterfaceWrapper() :
	InvokableObjectInterface< ReturnType, ArgumentTypes... >(),
	member_functorPointer( nullptr ),
	member_constantFunctorPointer( nullptr )
{}


template< typename FunctorType, typename ReturnType, typename... ArgumentTypes > requires( Concepts::FunctorWithSpecificReturnType< FunctorType, ReturnType, ArgumentTypes... > )
inline InvokableObjectInterfaceWrapper< FunctorType, ReturnType, ArgumentTypes... >::InvokableObjectInterfaceWrapper( FunctorType& functor ) :
	InvokableObjectInterface< ReturnType, ArgumentTypes... >(),
	member_functorPointer( &functor ),
	member_constantFunctorPointer( nullptr )
{}


template< typename FunctorType, typename ReturnType, typename... ArgumentTypes > requires( Concepts::FunctorWithSpecificReturnType< FunctorType, ReturnType, ArgumentTypes... > )
inline InvokableObjectInterfaceWrapper< FunctorType, ReturnType, ArgumentTypes... >::InvokableObjectInterfaceWrapper( const FunctorType& functor ) :
	InvokableObjectInterface< ReturnType, ArgumentTypes... >(),
	member_functorPointer( nullptr ),
	member_constantFunctorPointer( &functor )
{}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< typename FunctorType, typename ReturnType, typename... ArgumentTypes > requires( Concepts::FunctorWithSpecificReturnType< FunctorType, ReturnType, ArgumentTypes... > )
ReturnType InvokableObjectInterfaceWrapper< FunctorType, ReturnType, ArgumentTypes... >::operator()( ArgumentTypes... arguments )
{
	// Check which one of the pointers is no NULL 
	if ( member_functorPointer != nullptr )
	{
		// Execute the functor using the arguments, and return the value
		return ( member_functorPointer->operator()( ForwardUniversalReference< ArgumentTypes >( arguments )... ) );
	}
	else if ( member_constantFunctorPointer != nullptr )
	{
		// Execute the constant functor using the arguments, and return the value
		return ( member_constantFunctorPointer->operator()( ForwardUniversalReference< ArgumentTypes >( arguments )... ) );	
	}

	// Both pointers are NULL, throw an exception
	ThrowException( "At least one of the pointers must not be NULL" );
}


template< typename FunctorType, typename ReturnType, typename... ArgumentTypes > requires( Concepts::FunctorWithSpecificReturnType< FunctorType, ReturnType, ArgumentTypes... > )
ReturnType InvokableObjectInterfaceWrapper< FunctorType, ReturnType, ArgumentTypes... >::operator()( ArgumentTypes... arguments ) const
{
	// Check which one of the pointers is no NULL 
	if ( member_functorPointer != nullptr )
	{
		// Execute the functor using the arguments, and return the value
		return ( member_functorPointer->operator()( ForwardUniversalReference< ArgumentTypes >( arguments )... ) );
	}
	else if ( member_constantFunctorPointer != nullptr )
	{
		// Execute the constant functor using the arguments, and return the value
		return ( member_constantFunctorPointer->operator()( ForwardUniversalReference< ArgumentTypes >( arguments )... ) );	
	}

	// Both pointers are NULL, throw an exception
	ThrowException( "At least one of the pointers must not be NULL" );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< typename FunctorType COMMA typename ReturnType COMMA typename... ArgumentTypes > requires( Concepts::FunctorWithSpecificReturnType< FunctorType COMMA ReturnType COMMA ArgumentTypes... > )
	void InvokableObjectInterfaceWrapper< FunctorType COMMA ReturnType COMMA ArgumentTypes... >::UnitTest()
	{}

)  //  End of debug tool



}  //  Namespace Universe