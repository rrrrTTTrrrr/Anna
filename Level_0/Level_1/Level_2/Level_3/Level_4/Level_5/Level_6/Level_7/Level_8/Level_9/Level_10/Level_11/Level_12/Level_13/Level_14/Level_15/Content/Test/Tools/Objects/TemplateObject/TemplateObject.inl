//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< typename AnyType >
inline TemplateObject< AnyType >::TemplateObject() :
	member_memoryAddress( 0UL ),
	member_size( 0U )
{}


template< typename AnyType >
inline TemplateObject< AnyType >::TemplateObject( UnsignedInteger64bits size, AnyType value ) :
	member_memoryAddress( new AnyType[ size ] ),
	member_size( size )
{
	// Set all the entries to the given value
	for ( UnsignedInteger64bits index = 0U ; index < size ; ++index )
	{
		member_memoryAddress[ index ] = value;
	}
}


template< typename AnyType >
inline TemplateObject< AnyType >::TemplateObject( const SelfType& other ) :
	member_memoryAddress( 0UL ),
	member_size( other.member_size )
{
	// Check if the size of the other instance is not 0
	if ( other.member_size > 0UL )
	{
		// Allocate space 
		member_memoryAddress = new AnyType[ other.member_size ];

		// Set all the entries to the given value
		for ( UnsignedInteger64bits index = 0UL ; index < member_size ; ++index )
		{
			member_memoryAddress[ index ] = other.member_memoryAddress[ index ];
		}
	}
}


template< typename AnyType >
inline TemplateObject< AnyType >& TemplateObject< AnyType >::operator=( const SelfType& other )
{
    // Create a copy of the other instance
    SelfType temporary( other );

    // Swap between this instance and the temporary one, this will leave the temporary instance with the old data, and he will delete it
    Swap( temporary );

    // Return a reference to this object
    return ( *this );
}


template< typename AnyType >
inline TemplateObject< AnyType >::TemplateObject( TemplateObject&& other ) :
	SelfType()
{
    // Swap between this instance and the other one
    Swap( other );
}


template< typename AnyType >
inline TemplateObject< AnyType >& TemplateObject< AnyType >::operator=( SelfType&& other )
{
    // Create a default constructed instance
    SelfType defaultConstructedInstance;

    // Swap between the default constructed instance, which is in default state, and the other instance
    defaultConstructedInstance.Swap( other );

    // Swap between this instance and the default constructed instance one
    Swap( defaultConstructedInstance );

    // Return a reference to this object
    return ( *this );
}


template< typename AnyType >
inline void TemplateObject< AnyType >::Reset()
{    																																			
    // Create a default constructed instance. Swap it with this instance, which will be left in default state. When control leaves this method it
	// will delete the old resources																					
    SelfType defaultConstructedInstance;																			
																																				
    // Swap between this instance and the default constructed instance
    Swap( defaultConstructedInstance );    																										
}


template< typename AnyType >
inline void TemplateObject< AnyType >::Swap( SelfType& other )
{
	// Swap the memory address
	AnyType* otherMemoryAddressCopy = other.member_memoryAddress;
	other.member_memoryAddress = member_memoryAddress;
	member_memoryAddress = otherMemoryAddressCopy; 

	// Swap the size
	UnsignedInteger64bits otherSizeCopy = other.member_size;
	other.member_size = member_size;
	member_size = otherSizeCopy; 
}


template< typename AnyType >
inline TemplateObject< AnyType >::~TemplateObject()
{
	delete[] member_memoryAddress;
}


template< typename AnyType >
inline UnsignedInteger64bits TemplateObject< AnyType >::Size() const
{
    // Return the size of the instance
    return ( member_size );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< typename AnyType >
inline AnyType& TemplateObject< AnyType >::operator[]( UnsignedInteger64bits index ) const
{
	// Return a reference to the entry
	return ( member_memoryAddress[ index ] );
}


template< typename AnyType >
inline bool TemplateObject< AnyType >::operator==( const SelfType& other ) const
{
	// Compare the size
	if ( member_size != other.member_size )
	{
		return ( false );
	}

	// Compare the entries
	for ( UnsignedInteger64bits index = 0U ; index < member_size ; ++index )
	{
		if ( member_memoryAddress[ index ] != other.member_memoryAddress[ index ] )
		{
			return ( false );
		}
	}

	return ( true );
}


template< typename AnyType >
inline bool TemplateObject< AnyType >::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}



}  //  Namespace Test


}  //  Namespace Universe