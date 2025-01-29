//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< typename Type, typename ReturnType, typename... ArgumentsTypes >
inline FunctorObject< Type, ReturnType, ArgumentsTypes... >::FunctorObject( const UnsignedInteger64bits size ) :
	member_array( new Type[ size ] ),
	member_size( size )
{}


template< typename Type, typename ReturnType, typename... ArgumentsTypes >
inline FunctorObject< Type, ReturnType, ArgumentsTypes... >::FunctorObject( const FunctorObject< Type, ReturnType, ArgumentsTypes... >& other ) :
	member_array( new Type[ other.member_size ] ),
	member_size( other.member_size )
{
	for ( UnsignedInteger64bits index = 0UL ; index < member_size ; ++index )
	{
		member_array[ index ] = other.member_array[ index ];
	}
}


template< typename Type, typename ReturnType, typename... ArgumentsTypes >
inline void FunctorObject< Type, ReturnType, ArgumentsTypes... >::Swap( FunctorObject< Type, ReturnType, ArgumentsTypes... >& other )
{
	// Swap the memory address
	Type* otherMemoryAddressCopy = other.member_array;
	other.member_array = member_array;
	member_array = otherMemoryAddressCopy; 

	// Swap the size
	unsigned long otherSizeCopy = other.member_size;
	other.member_size = member_size;
	member_size = otherSizeCopy; 
}


template< typename Type, typename ReturnType, typename... ArgumentsTypes >
inline FunctorObject< Type, ReturnType, ArgumentsTypes... >::~FunctorObject()
{
	if ( member_array == 0UL )
	{
    	delete[] member_array;
    }
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< typename Type, typename ReturnType, typename... ArgumentsTypes >
inline ReturnType FunctorObject< Type, ReturnType, ArgumentsTypes... >::operator()( ReturnType value )
{
	return ( value );
}


template< typename Type, typename ReturnType, typename... ArgumentsTypes >
inline ReturnType FunctorObject< Type, ReturnType, ArgumentsTypes... >::operator()( ReturnType value ) const
{
	return ( value );
}


template< typename Type, typename ReturnType, typename... ArgumentsTypes >
inline Type& FunctorObject< Type, ReturnType, ArgumentsTypes... >::operator[]( unsigned long index ) const
{
	// Return a reference to the entry
	return ( member_array[ index ] );
}




}  //  Namespace Test


}  //  Namespace Universe