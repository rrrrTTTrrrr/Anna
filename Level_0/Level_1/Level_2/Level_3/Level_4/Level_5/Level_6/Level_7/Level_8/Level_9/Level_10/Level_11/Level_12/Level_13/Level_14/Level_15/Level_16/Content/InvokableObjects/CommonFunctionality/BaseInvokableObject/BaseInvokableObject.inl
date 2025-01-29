//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< typename ReturnValueType, typename... ArgumentTypes >
constexpr Boolean BaseInvokableObject< ReturnValueType, ArgumentTypes... >::ArgumentsNeeded() const
{
	// Check the number of arguments provided, and if there is at least one argument return true, otherwise false
	return ( sizeof...( ArgumentTypes ) > 0 );
}


template< typename ReturnValueType, typename... ArgumentTypes >
constexpr UnsignedInteger64bits BaseInvokableObject< ReturnValueType, ArgumentTypes... >::ArgumentsNumber() const
{
	// Return the number of arguments required to invoke the function
	return ( sizeof...( ArgumentTypes ) );
}


template< typename ReturnValueType, typename... ArgumentTypes >
constexpr Boolean BaseInvokableObject< ReturnValueType, ArgumentTypes... >::ReturnValueExist() const
{
	// Check if the return value type is 'void'. If that is the case, then there is no return value, otherwise ther is
	return ( CompareTypes< void, ReturnValueType >::Result() == false );
}



}  //  Namespace Universe