//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< Concepts::Integer IntegerType >
inline Bit< IntegerType >::Bit() :
    member_memoryAddress( 0UL ),
    member_bitIndex( 0UL )
{}


template< Concepts::Integer IntegerType >
inline Bit< IntegerType >::Bit( IntegerType* const pointer, const UnsignedInteger64bits bitIndex ) :
    member_memoryAddress( AssignOnlyIfPointerIsNotNULL( pointer ) ),
    member_bitIndex( AssignOnlyIfValueIsBelowCertainLimit( bitIndex, ( sizeof( IntegerType ) * 8 ) ) )
{}


template< Concepts::Integer IntegerType >
inline Bit< IntegerType >::Bit( const SelfType& other ) :
    member_memoryAddress( other.member_memoryAddress ),
    member_bitIndex( other.member_bitIndex )
{}


template< Concepts::Integer IntegerType >
inline UnsignedInteger64bits Bit< IntegerType >::BitIndexInItsByte() const
{
    // Return the result of the bit index modulo 8
    return ( member_bitIndex % 8 );
}


template< Concepts::Integer IntegerType >
inline void Bit< IntegerType >::SetBitIndex( const UnsignedInteger8bits bitIndex )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsBelowCertainLimit( bitIndex, ( sizeof( IntegerType ) * 8 ) );

    // Set the new index of the bit that the instance should point too
    member_bitIndex = bitIndex;
}


template< Concepts::Integer IntegerType >
inline BitState Bit< IntegerType >::State() const
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_memoryAddress );

    const BitState state = ( ( GetReferenceToTheByteThatContainsTheBit__Private() & GetByteWithOnebitOnInTheRequiredIndex__Private() ) == 0 ) ? BitState::OFF : BitState::ON;

    // Perform the AND operation between the bit in this instance and another bit in state ON, and return the result
    return ( state );
}


template< Concepts::Integer IntegerType >
inline void Bit< IntegerType >::SetState( const BitState State )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_memoryAddress );

    // Check if the bit needs to be on or off
    if ( State == BitState::ON )
    {
        // The bit needs to be set on
        TurnOn();
    }
    else
    {
        // The bit needs to be set off
        TurnOff();
    }
}


template< Concepts::Integer IntegerType >
inline Boolean Bit< IntegerType >::IsOn() const
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_memoryAddress );

    // Check if the bit is on, and return the result
    return ( State() == BitState::ON );
}


template< Concepts::Integer IntegerType >
inline Boolean Bit< IntegerType >::IsOff() const
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_memoryAddress );

    // Check if the bit is on, and return the result
    return ( State() == BitState::OFF );
}


template< Concepts::Integer IntegerType >
inline void Bit< IntegerType >::TurnOn()
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_memoryAddress );

    // The bit needs to be set on

    // Create a byte with only 1 bit on in the required index, and perform the or ( | ) operation with the current byte. This way no matter if the bit is on or off
    // it will be on
    GetReferenceToTheByteThatContainsTheBit__Private() |= GetByteWithOnebitOnInTheRequiredIndex__Private();
}


template< Concepts::Integer IntegerType >
inline void Bit< IntegerType >::TurnOff()
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_memoryAddress );

    // The bit needs to be set off

    // Create an object with only 1 bit off in the required index, and perform the and ( & ) operation with the current byte. This way no matter if the bit is on or
    // off it will be off
    GetReferenceToTheByteThatContainsTheBit__Private() &= GetByteWithOnebitOffInTheRequiredIndex__Private();
}


template< Concepts::Integer IntegerType >
inline void Bit< IntegerType >::SetOppositeState()
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_memoryAddress );

    // Set the bit to the required state. To acheive this goal the xor ( ^ ) operation is performed on the byte that the bit is in, with a byte that is all set to 
    // state off ( 0 ), except one bit in the required location set to state on ( 1 )
    GetReferenceToTheByteThatContainsTheBit__Private() ^= GetByteWithOnebitOnInTheRequiredIndex__Private();
}


template< Concepts::Integer IntegerType >
inline Language::String Bit< IntegerType >::ToString()
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_memoryAddress );

    // Check if the bit is on
    if ( IsOff() == true )
    {
        // The bit is off

        // Return a string with the word "OFF"
        return ( Language::String( "OFF" ) );
    }

    // The bit is on
    
    // Return a string with the word "ON"
    return ( Language::String( "ON" ) );
}


template< Concepts::Integer IntegerType >
inline LargestUnsignedInteger Bit< IntegerType >::NumberOfCharactersRequiredToStoreAsString() const
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_memoryAddress );

    // Check if the bit is on
    if ( IsOff() == true )
    {
        // The bit is off

        // Return the length of the string "OFF", which is 3
        return ( 3UL );
    }

    // The bit is on
    
    // Return the length of the string "ON", which is 2
    return ( 2UL );
}


template< Concepts::Integer IntegerType >
inline LargestUnsignedInteger Bit< IntegerType >::SetAsString( Language::Character* const stringPointer ) const
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_memoryAddress );
    AssertPointerIsNotNull( stringPointer );

    // Check if the bit is on
    if ( IsOff() == true )
    {
        // The bit is off

        // Set into the string the letters of the word "OFF"
        stringPointer[0] = 'O';
        stringPointer[1] = 'F';
        stringPointer[2] = 'F';

        return ( 3UL );
    }

    // The bit is on
    
    // Set into the string the letters of the word "ON"
    stringPointer[0] = 'O';
    stringPointer[1] = 'N';

    return ( 2UL );
}




//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< Concepts::Integer IntegerType >
inline Bit< IntegerType >& Bit< IntegerType >::operator=( const BitState state )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_memoryAddress );

    // Set the state of the bit
    SetState( state );

    // Return a reference to this object
    return ( *this );
}


template< Concepts::Integer IntegerType >
inline Boolean Bit< IntegerType >::operator==( const SelfType& other ) const
{
    // Check if the bit in the other instance has the same state as the bit in this instance, and return the result
    return ( State() == other.State() );
}


template< Concepts::Integer IntegerType >
inline Boolean Bit< IntegerType >::operator==( const BitState state ) const
{
    // Check if the bit in the other instance has the same state as the bit in this instance, and return the result
    return ( State() == state );
}


template< Concepts::Integer IntegerType >
inline Boolean Bit< IntegerType >::operator!=( const SelfType& other ) const
{        
    // Return the negotiated value from the equal operator
    return ( !( *this == other ) );
}


template< Concepts::Integer IntegerType >
inline Boolean Bit< IntegerType >::operator!=( const BitState state ) const
{        
    // Return the negotiated value from the equal operator
    return ( !( *this == state ) );
}


template< Concepts::Integer IntegerType >
inline BitState Bit< IntegerType >::operator&( const SelfType& other ) const
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_memoryAddress );
    AssertPointerIsNotNull( other.member_memoryAddress );
    
    // Check if both bits are ON, and only if that is case return the result ON, otherwise return OFF
    const BitState result = ( ( State() == BitState::ON ) && ( other.State() == BitState::ON ) ) ? BitState::ON : BitState::OFF;
    
    // Return the result
    return ( result );
}


template< Concepts::Integer IntegerType >
inline BitState Bit< IntegerType >::operator&( const BitState state ) const
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_memoryAddress );

    // Check if both bits are ON, and only if that is case return the result ON, otherwise return OFF
    const BitState result = ( ( State() == BitState::ON ) && ( state == BitState::ON ) ) ? BitState::ON : BitState::OFF;
    
    // Return the result
    return ( result );
}


template< Concepts::Integer IntegerType >
inline BitState Bit< IntegerType >::operator|( const SelfType& other ) const
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_memoryAddress );
    AssertPointerIsNotNull( other.member_memoryAddress );
    
    // Check if one of the bits is ON, and only if that is case return the result ON, otherwise return OFF
    const BitState result = ( ( State() == BitState::ON ) || ( other.State() == BitState::ON ) ) ? BitState::ON : BitState::OFF;
    
    // Return the result
    return ( result );
}


template< Concepts::Integer IntegerType >
inline BitState Bit< IntegerType >::operator|( const BitState state ) const
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_memoryAddress );

    // Check if one of the bits is ON, and only if that is case return the result ON, otherwise return OFF
    const BitState result = ( ( State() == BitState::ON ) || ( state == BitState::ON ) ) ? BitState::ON : BitState::OFF;
    
    // Return the result
    return ( result );
}


template< Concepts::Integer IntegerType >
inline BitState Bit< IntegerType >::operator^( const SelfType& other ) const
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_memoryAddress );
    AssertPointerIsNotNull( other.member_memoryAddress );
    
    // Check if the state of the bits is different, and only if that is case return the result ON, otherwise return OFF
    const BitState result = ( State() != other.State() ) ? BitState::ON : BitState::OFF;
    
    // Return the result
    return ( result );
}


template< Concepts::Integer IntegerType >
inline BitState Bit< IntegerType >::operator^( const BitState state ) const
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_memoryAddress );

    // Check if the state of the bits is different, and only if that is case return the result ON, otherwise return OFF
    const BitState result = ( State() != state ) ? BitState::ON : BitState::OFF;
    
    // Return the result
    return ( result );
}


template< Concepts::Integer IntegerType >
inline Bit< IntegerType >& Bit< IntegerType >::operator&=( const SelfType& other )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_memoryAddress );
    AssertPointerIsNotNull( other.member_memoryAddress );

    // There are 4 options :
    // 
    //      1 0  ->  0
    //      0 1  ->  0
    //      0 0  ->  0
    //      1 1  ->  1
    //
    // As can be seen only in the case that this bit is on and the other off an action needs to be taken to turn off this bit

    // Check if this bit is on and the other is off
    if ( ( State() == BitState::ON ) && ( other.State() == BitState::OFF ) )
    {
        // Set the state of the bit to off
        SetState( BitState::OFF );
    }

    // Return a reference to this instance
    return ( *this );
}


template< Concepts::Integer IntegerType >
inline Bit< IntegerType >& Bit< IntegerType >::operator&=( const BitState state )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_memoryAddress );

    // There are 4 options :
    // 
    //      1 0  ->  0
    //      0 1  ->  0
    //      0 0  ->  0
    //      1 1  ->  1
    //
    // As can be seen only in the case that this bit is on and the other off an action needs to be taken to turn off this bit

    // Check if this bit is on and the other is off
    if ( ( State() == BitState::ON ) && ( state == BitState::OFF ) )
    {
        // Set the state of the bit to off
        SetState( BitState::OFF );
    }

    // Return a reference to this instance
    return ( *this );
}


template< Concepts::Integer IntegerType >
inline Bit< IntegerType >& Bit< IntegerType >::operator|=( const SelfType& other )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_memoryAddress );
    AssertPointerIsNotNull( other.member_memoryAddress );
    
    // There are 4 options :
    // 
    //      1 0  ->  1
    //      0 1  ->  1
    //      0 0  ->  0
    //      1 1  ->  1
    //
    // As can be seen only in the case that this bit is off and the other on an action needs to be taken to turn on this bit

    // Check if this bit is off and the other is on
    if ( ( State() == BitState::OFF ) && ( other.State() == BitState::ON ) )
    {
        // Set the state of the bit to off
        SetState( BitState::ON );
    }

    // Return a reference to this instance
    return ( *this );
}


template< Concepts::Integer IntegerType >
inline Bit< IntegerType >& Bit< IntegerType >::operator|=( const BitState state )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_memoryAddress );
    
    // There are 4 options :
    // 
    //      1 0  ->  1
    //      0 1  ->  1
    //      0 0  ->  0
    //      1 1  ->  1
    //
    // As can be seen only in the case that this bit is off and the other on an action needs to be taken to turn on this bit

    // Check if this bit is off and the other is on
    if ( ( State() == BitState::OFF ) && ( state == BitState::ON ) )
    {
        // Set the state of the bit to off
        SetState( BitState::ON );
    }

    // Return a reference to this instance
    return ( *this );
}


template< Concepts::Integer IntegerType >
inline Bit< IntegerType >& Bit< IntegerType >::operator^=( const SelfType& other )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_memoryAddress );
    AssertPointerIsNotNull( other.member_memoryAddress );
    
    // There are 4 options :
    // 
    //      1 0  ->  1
    //      0 1  ->  1
    //      0 0  ->  0
    //      1 1  ->  0
    //
    // As can be seen only in 2 cases an action needs to be taken, in both the bit in the other instance should be ON

    // Check if the other bit is ON
    if ( other.State() == BitState::ON )
    {
        // The other bit is ON

        // Check the state of the bit in this instance
        if ( State() == BitState::ON )
        {
            // The bit in this instance is also ON

            // Set the state of the bit to OFF
            SetState( BitState::OFF );
        }
        else
        {
            // The bit in this instance is OFF

            // Set the state of the bit to ON
            SetState( BitState::ON );
        }
    }

    // Return a reference to this instance
    return ( *this );
}


template< Concepts::Integer IntegerType >
inline Bit< IntegerType >& Bit< IntegerType >::operator^=( const BitState state )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_memoryAddress );
    
    // There are 4 options :
    // 
    //      1 0  ->  1
    //      0 1  ->  1
    //      0 0  ->  0
    //      1 1  ->  0
    //
    // As can be seen only in 2 cases an action needs to be taken, in both the bit in the other instance should be ON

    // Check if the given state is ON
    if ( state == BitState::ON )
    {
        // The given state is ON

        // Check the state of the bit in this instance
        if ( State() == BitState::ON )
        {
            // The bit in this instance is also ON

            // Set the state of the bit to OFF
            SetState( BitState::OFF );
        }
        else
        {
            // The bit in this instance is OFF

            // Set the state of the bit to ON
            SetState( BitState::ON );
        }
    }

    // Return a reference to this instance
    return ( *this );
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



template< Concepts::Integer IntegerType >
inline UnsignedInteger8bits& Bit< IntegerType >::GetReferenceToTheByteThatContainsTheBit__Private()
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_memoryAddress );
    
    // Cast the pointer as unsigned integer 8 bits, add to it the required offset to the byte that contains the bit, and return a copy
    return ( *( reinterpret_cast< UnsignedInteger8bits* >( member_memoryAddress ) + ( member_bitIndex / 8UL ) ) );
}


template< Concepts::Integer IntegerType >
inline const UnsignedInteger8bits& Bit< IntegerType >::GetReferenceToTheByteThatContainsTheBit__Private() const
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( member_memoryAddress );
    
    // Cast the pointer as unsigned integer 8 bits, add to it the required offset to the byte that contains the bit, and return a copy
    return ( *( reinterpret_cast< const UnsignedInteger8bits* >( member_memoryAddress ) + ( member_bitIndex / 8UL ) ) );
}


template< Concepts::Integer IntegerType >
inline UnsignedInteger8bits Bit< IntegerType >::GetByteWithOnebitOnInTheRequiredIndex__Private() const
{
    // Left shift the bit to the required location
    return ( static_cast< UnsignedInteger8bits >( 1 << ( member_bitIndex % 8 ) ) );
}


template< Concepts::Integer IntegerType >
inline UnsignedInteger8bits Bit< IntegerType >::GetByteWithOnebitOffInTheRequiredIndex__Private() const
{
    // Left shift the bit to the required location, and perform the negotiate opeartion ( it will leave all the bits ON beside 1 bit that will be OFF
    // at the required location )
    return ( static_cast< UnsignedInteger8bits >( ~( 1 << ( member_bitIndex % 8 ) ) ) );
}



// **********************************************************   INLINE AND TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   ***********************************************************



template< Concepts::Integer INTEGER_TYPE >
EnsureRetrunValueIsUsed inline BitState operator~( const Bit< INTEGER_TYPE >& bit )
{
    // Determine the negotiated state of the bit
    const BitState negotiatedState = ( bit.State() == BitState::OFF ) ? BitState::ON : BitState::OFF;

    // Return the result
    return ( negotiatedState );
}


template< Concepts::Integer INTEGER_TYPE >
EnsureRetrunValueIsUsed inline Boolean operator==( const BitState state, const Bit< INTEGER_TYPE >& other )
{
    // Check if both or only one of the instances is in default state
    AssertPointerIsNotNull( other.member_memoryAddress );
    
    // Check if the bit in the other instance has the same state as the bit in this instance, and return the result
    return ( state == other.State() );
}


template< Concepts::Integer INTEGER_TYPE >
EnsureRetrunValueIsUsed inline Boolean operator!=( const BitState state, const Bit< INTEGER_TYPE >& other )
{        
    // Return the negotiated value from the equal operator
    return ( !( state == other ) );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< Concepts::Integer IntegerType >
	void Bit< IntegerType >::UnitTest()
	{
        // Create a default constructed instance
        Bit< UnsignedInteger8bits > test_0;

        // Create a byte
        UnsignedInteger8bits testInteger_1 = 0;

        // Create a test instance
        Bit< UnsignedInteger8bits > test_2( &testInteger_1, 3 );

        // Set the bit on
        test_2.SetState( BitState::ON );

        // Check that the bit was set on
        Assert_Test( testInteger_1 == 8 );

        // Set the bit on
        test_2.SetState( BitState::OFF );

        // Check that the bit was set off
        Assert_Test( testInteger_1 == 0 );

        // Check that the negotiated state is true
        Assert_Test( ~test_2 == BitState::ON );

        // Check that the bit state stayed false
        Assert_Test( BitState::OFF == test_2.State() );

        // Check that the bit state stayed false
        Assert_Test( test_2.State() == BitState::OFF );

        // Check that the bit state stayed false
        Assert_Test( test_2 == BitState::OFF );

        // Check that the bit state stayed false
        Assert_Test( BitState::OFF == test_2 );
	}

)  //  End of debug tool



}  //  Namespace Memory


}  //  Namespace Universe