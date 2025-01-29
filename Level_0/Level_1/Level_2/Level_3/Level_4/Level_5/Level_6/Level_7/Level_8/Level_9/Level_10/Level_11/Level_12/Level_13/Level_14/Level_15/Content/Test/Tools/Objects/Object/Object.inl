//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline Object::Object() :
	member_memoryAddress( 0UL ),
	member_size( 0U ),
	member_key( 0UL )
{}


inline Object::Object( UnsignedInteger64bits size, UnsignedInteger32bits value, UnsignedInteger64bits key ) :
	member_memoryAddress( new UnsignedInteger32bits[ size ] ),
	member_size( size ),
	member_key( key )
{
	// Set all the entries to the given value
	for ( UnsignedInteger32bits index = 0U ; index < size ; ++index )
	{
		member_memoryAddress[ index ] = value;
	}
}


inline Object::Object( const Object& other ) :
	member_memoryAddress( new UnsignedInteger32bits[ other.member_size ] ),
	member_size( other.member_size ),
	member_key( other.member_key )
{
	// Set all the entries to the given value
	for ( UnsignedInteger32bits index = 0U ; index < member_size ; ++index )
	{
		member_memoryAddress[ index ] = other.member_memoryAddress[ index ];
	}
}


inline Object& Object::operator=( const Object& other )
{
    // Create a copy of the other instance
    Object temporary( other );

    // Swap between this instance and the temporary one, this will leave the temporary instance with the old data, and he will delete it
    Swap( temporary );

    // Return a reference to this object
    return ( *this );
}


inline Object::Object( Object&& other ) :
	SelfType()
{
    // Swap between this instance and the other one
    Swap( other );
}


inline Object& Object::operator=( Object&& other )
{
    // Create a default constructed instance
    Object defaultConstructedInstance;

    // Swap between the default constructed instance, which is in default state, and the other instance
    defaultConstructedInstance.Swap( other );

    // Swap between this instance and the default constructed instance one
    Swap( defaultConstructedInstance );

    // Return a reference to this object
    return ( *this );
}


inline void Object::Reset()
{    																																			
    // Create a default constructed instance. Swap it with this instance, which will be left in default state. When control leaves this method it
	// will delete the old resources																					
    Object defaultConstructedInstance;																			
																																				
    // Swap between this instance and the default constructed instance
    Swap( defaultConstructedInstance );    																										
}


inline void Object::Swap( Object& other )
{
	// Swap the memory address
	UnsignedInteger32bits* otherMemoryAddressCopy = other.member_memoryAddress;
	other.member_memoryAddress = member_memoryAddress;
	member_memoryAddress = otherMemoryAddressCopy; 

	// Swap the size
	UnsignedInteger64bits otherSizeCopy = other.member_size;
	other.member_size = member_size;
	member_size = otherSizeCopy;

	// Swap the keys
	UnsignedInteger64bits otherKeyCopy = other.member_key;
	other.member_key = member_key;
	member_key = otherKeyCopy;
}


inline Object::~Object()
{
	delete[] member_memoryAddress;
}


inline UnsignedInteger32bits Object::Method_1( UnsignedInteger32bits rr, UnsignedInteger64bits )
{
	rr += 1;
	return ( 9 );
}


inline UnsignedInteger32bits Object::Method_2( UnsignedInteger32bits, UnsignedInteger64bits, UnsignedInteger64bits )
{
	return ( 99 );
}


inline void Object::Method_3()
{}


inline UnsignedInteger32bits Object::Method_4()
{
	return ( 999 );
}


inline void Object::Method_5( UnsignedInteger32bits, UnsignedInteger64bits )
{}


inline void Object::Method_6( UnsignedInteger32bits* pointer_1, UnsignedInteger64bits* pointer_2 )
{
	*pointer_1 = 888333;
	*pointer_2 = 7777;
}


inline UnsignedInteger32bits Object::Method_1_Constant( UnsignedInteger32bits rr, UnsignedInteger64bits ) const 
{
	rr += 1;
	return ( 9 );
}


inline UnsignedInteger32bits Object::Method_2_Constant( UnsignedInteger32bits, UnsignedInteger64bits, UnsignedInteger64bits ) const
{
	return ( 99 );
}


inline void Object::Method_3_Constant() const
{}


inline UnsignedInteger32bits Object::Method_4_Constant() const
{
	return ( 999 );
}


inline void Object::Method_5_Constant( UnsignedInteger32bits, UnsignedInteger64bits ) const
{}


inline void Object::Method_6_Constant( UnsignedInteger32bits* pointer_1, UnsignedInteger64bits* pointer_2 ) const
{
	*pointer_1 = 888333;
	*pointer_2 = 7777;
}


inline const UnsignedInteger64bits& Object::GetKey( const Object& instance )
{
	return ( instance.member_key );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



inline UnsignedInteger32bits& Object::operator[]( UnsignedInteger32bits index ) const
{
	// Return a reference to the entry
	return ( member_memoryAddress[ index ] );
}


inline bool Object::operator==( const Object& other ) const
{
	// Compare the size
	if ( member_size != other.member_size )
	{
		return ( false );
	}

	// Compare the entries
	for ( UnsignedInteger32bits index = 0U ; index < member_size ; ++index )
	{

		if ( member_memoryAddress[ index ] != other.member_memoryAddress[ index ] )
		{
			return ( false );
		}

	}

	return ( true );
}


inline bool Object::operator!=( const Object& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}



}  //  Namespace Test


}  //  Namespace Universe