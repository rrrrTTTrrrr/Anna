//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



	template< typename AnyType >
	inline Bit< AnyType >::Bit() :
        member_memoryAddress( 0UL ),
        member_bitIndex( 0UL )
	{}


	template< typename AnyType >
	inline Bit< AnyType >::Bit( AnyType* pointer, UnsignedInteger64bits bitIndex ) :
        member_memoryAddress( pointer ),
        member_bitIndex( bitIndex )
	{
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertPointer_MACRO( pointer );
        Assert_MACRO( ( bitIndex < ( sizeof( AnyType ) * 8 ) ), "The given size is not in the possible range of the given temple type object size" );
	}


	template< typename AnyType >
	inline Bit< AnyType >::Bit( const Bit< AnyType >& other ) :
        member_memoryAddress( other.member_memoryAddress ),
        member_bitIndex( other.member_bitIndex )
	{}


    template< typename AnyType >
    inline UnsignedInteger64bits Bit< AnyType >::BitIndexInItsByte() const
    {
        // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
        // instance is ready to be used
        AssertPointer_MACRO( member_memoryAddress );

        // Return the result of the bit index modulo 8
        return ( member_bitIndex % 8 );
    }


    template< typename AnyType >
    inline void Bit< AnyType >::SetBitIndex( UnsignedInteger8bits bitIndex )
    {
        // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
        // instance is ready to be used
        AssertPointer_MACRO( member_memoryAddress );
        Assert_MACRO( ( bitIndex < ( sizeof( AnyType ) * 8 ) ), "The given size is not in the possible range of the given temple type object size" );

        // Set the new index of the bit that the instance should point too
        member_bitIndex = bitIndex;
    }


    template< typename AnyType >
    inline Boolean Bit< AnyType >::ONorOFF() const
    {
        // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
        // instance is ready to be used
        AssertPointer_MACRO( member_memoryAddress );

        // Perform the AND operation between the bit in this instance and another bit in state ON, and return the result
        return ( GetReferenceToTheByteThatContainsTheBit__Private() & GetByteWithOnebitOnInTheRequiredIndex__Private() );
    }


    template< typename AnyType >
    inline void Bit< AnyType >::SetONorOFF( Boolean ONorOFF )
    {
        // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
        // instance is ready to be used
        AssertPointer_MACRO( member_memoryAddress );

        // Check if the bit needs to be on or off
        if ( ONorOFF == 1 )
        {
            // The bit needs to be set on

            // Create a byte with only 1 bit on in the required index, and perform the or ( | ) operation with the current byte. This way no matter if the bit is on or off
            // it will be on
            GetReferenceToTheByteThatContainsTheBit__Private() |= GetByteWithOnebitOnInTheRequiredIndex__Private();
        }
        else
        {
            // The bit needs to be set off

            // Create an object with only 1 bit off in the required index, and perform the and ( & ) operation with the current byte. This way no matter if the bit is on or
            // off it will be off
            GetReferenceToTheByteThatContainsTheBit__Private() &= GetByteWithOnebitOffInTheRequiredIndex__Private();
        }

    }


    template< typename AnyType >
    inline void Bit< AnyType >::SetOppositeState()
    {
        // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
        // instance is ready to be used
        AssertPointer_MACRO( member_memoryAddress );

        // Set the bit to the required state. To acheive this goal the xor ( ^ ) operation is performed on the byte that the bit is in, with a byte that is all set to 
        // state off ( 0 ), except one bit in the required location set to state on ( 1 )
        GetReferenceToTheByteThatContainsTheBit__Private() ^= GetByteWithOnebitOnInTheRequiredIndex__Private();
    }




//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



    template< typename AnyType >
    inline Bit< AnyType >& Bit< AnyType >::operator=( Boolean state )
    {
        // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
        // instance is ready to be used
        AssertPointer_MACRO( member_memoryAddress );

        // Set the state of the bit
        SetONorOFF( state );

        // Return a reference to this object
        return ( *this );
    }


    template< typename AnyType >
    inline Boolean Bit< AnyType >::operator==( const Bit< AnyType >& other ) const
    {
        // Check if the bit in the other instance has the same state as the bit in this instance, and return the result
        return ( ONorOFF() == other.ONorOFF() );
    }


    template< typename AnyType >
    inline Boolean Bit< AnyType >::operator!=( const Bit< AnyType >& other ) const
    {        
        // Return the negotiated value from the equal operator
        return ( !( *this == other ) );
    }


    template< typename AnyType >
    inline Boolean Bit< AnyType >::operator&( const Bit< AnyType >& other ) const
    {
        // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
        // instance is ready to be used
        AssertPointer_MACRO( member_memoryAddress );
        AssertPointer_MACRO( other.member_memoryAddress );
        
        // Perform the and operation between the instances and return the result. This can be done because boolean types has 1 bit on for the true state and no bits on
        // for the false state, this means that all the bits operations will work the same
        return ( ONorOFF() & other.ONorOFF() );
    }


    template< typename AnyType >
    inline Boolean Bit< AnyType >::operator&( Boolean state ) const
    {
        // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
        // instance is ready to be used
        AssertPointer_MACRO( member_memoryAddress );

        // Perform the and operation between the instance and the boolean and return the result. This can be done because boolean types has 1 bit on for the true state and 
        // no bits on for the false state, this means that all the bits operations will work the same
        return ( ONorOFF() & state );
    }


    template< typename AnyType >
    inline Boolean Bit< AnyType >::operator|( const Bit< AnyType >& other ) const
    {
        // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
        // instance is ready to be used
        AssertPointer_MACRO( member_memoryAddress );
        AssertPointer_MACRO( other.member_memoryAddress );
        
        // Perform the or operation between the instances and return the result. This can be done because boolean types has 1 bit on for the true state and no bits on
        // for the false state, this means that all the bits operations will work the same
        return ( ONorOFF() | other.ONorOFF() );
    }


    template< typename AnyType >
    inline Boolean Bit< AnyType >::operator|( Boolean state ) const
    {
        // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
        // instance is ready to be used
        AssertPointer_MACRO( member_memoryAddress );

        // Perform the or operation between the instance and the boolean and return the result. This can be done because boolean types has 1 bit on for the true state and 
        // no bits on for the false state, this means that all the bits operations will work the same
        return ( ONorOFF() | state );
    }


    template< typename AnyType >
    inline Boolean Bit< AnyType >::operator^( const Bit< AnyType >& other ) const
    {
        // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
        // instance is ready to be used
        AssertPointer_MACRO( member_memoryAddress );
        AssertPointer_MACRO( other.member_memoryAddress );
        
        // Perform the xor operation between the instances and return the result, this can be done because boolean types has 1 bit on for the true state and no bits on
        // for the false state, this means that all the bits operations will work the same
        return ( ONorOFF() != other.ONorOFF() );
    }


    template< typename AnyType >
    inline Boolean Bit< AnyType >::operator^( Boolean state ) const
    {
        // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
        // instance is ready to be used
        AssertPointer_MACRO( member_memoryAddress );

        // Perform the xor operation between the instance and the boolean and return the result. This can be done because boolean types has 1 bit on for the true state and 
        // no bits on for the false state, this means that all the bits operations will work the same
        return ( ONorOFF() != state );
    }


    template< typename AnyType >
    inline Bit< AnyType >& Bit< AnyType >::operator&=( const Bit< AnyType >& other )
    {
        // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
        // instance is ready to be used
        AssertPointer_MACRO( member_memoryAddress );
        AssertPointer_MACRO( other.member_memoryAddress );

        // There are 4 options :
        // 
        //      1 0  ->  0
        //      0 1  ->  0
        //      0 0  ->  0
        //      1 1  ->  1
        //
        // As can be seen only in the case that this bit is on and the other off an action needs to be taken to turn off this bit

        // Check if this bit is on and the other is off
        if ( ( ONorOFF() == 1 ) && ( other.ONorOFF() == 0 ) )
        {
            // Set the state of the bit to off
            SetONorOFF( 0 );
        }

        // Return a reference to this instance
        return ( *this );
    }


    template< typename AnyType >
    inline Bit< AnyType >& Bit< AnyType >::operator&=( Boolean state )
    {
        // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
        // instance is ready to be used
        AssertPointer_MACRO( member_memoryAddress );

        // There are 4 options :
        // 
        //      1 0  ->  0
        //      0 1  ->  0
        //      0 0  ->  0
        //      1 1  ->  1
        //
        // As can be seen only in the case that this bit is on and the other off an action needs to be taken to turn off this bit

        // Check if this bit is on and the other is off
        if ( ( ONorOFF() == 1 ) && ( state == 0 ) )
        {
            // Set the state of the bit to off
            SetONorOFF( 0 );
        }

        // Return a reference to this instance
        return ( *this );
    }


    template< typename AnyType >
    inline Bit< AnyType >& Bit< AnyType >::operator|=( const Bit< AnyType >& other )
    {
        // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
        // instance is ready to be used
        AssertPointer_MACRO( member_memoryAddress );
        AssertPointer_MACRO( other.member_memoryAddress );
        
        // There are 4 options :
        // 
        //      1 0  ->  1
        //      0 1  ->  1
        //      0 0  ->  0
        //      1 1  ->  1
        //
        // As can be seen only in the case that this bit is off and the other on an action needs to be taken to turn on this bit

        // Check if this bit is off and the other is on
        if ( ( ONorOFF() == 0 ) && ( other.ONorOFF() == 1 ) )
        {
            // Set the state of the bit to off
            SetONorOFF( 1 );
        }

        // Return a reference to this instance
        return ( *this );
    }


    template< typename AnyType >
    inline Bit< AnyType >& Bit< AnyType >::operator|=( Boolean state )
    {
        // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
        // instance is ready to be used
        AssertPointer_MACRO( member_memoryAddress );
        
        // There are 4 options :
        // 
        //      1 0  ->  1
        //      0 1  ->  1
        //      0 0  ->  0
        //      1 1  ->  1
        //
        // As can be seen only in the case that this bit is off and the other on an action needs to be taken to turn on this bit

        // Check if this bit is off and the other is on
        if ( ( ONorOFF() == 0 ) && ( state == true ) )
        {
            // Set the state of the bit to off
            SetONorOFF( 1 );
        }

        // Return a reference to this instance
        return ( *this );
    }


    template< typename AnyType >
    inline Bit< AnyType >& Bit< AnyType >::operator^=( const Bit< AnyType >& other )
    {
        // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
        // instance is ready to be used
        AssertPointer_MACRO( member_memoryAddress );
        AssertPointer_MACRO( other.member_memoryAddress );
        
        // There are 4 options :
        // 
        //      1 0  ->  1
        //      0 1  ->  1
        //      0 0  ->  0
        //      1 1  ->  0
        //
        // As can be seen only in 2 cases an action needs to be taken, in both the bit in the other instance should be ON

        // Check if the other bit is ON
        if ( other.ONorOFF() == 1 )
        {
            // The other bit is ON

            // Check the state of the bit in this instance
            if ( ONorOFF() == 1 )
            {
                // The bit in this instance is also ON

                // Set the state of the bit to OFF
                SetONorOFF( 0 );
            }
            else
            {
                // The bit in this instance is OFF

                // Set the state of the bit to ON
                SetONorOFF( 1 );
            }

        }

        // Return a reference to this instance
        return ( *this );
    }


    template< typename AnyType >
    inline Bit< AnyType >& Bit< AnyType >::operator^=( Boolean state )
    {
        // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
        // instance is ready to be used
        AssertPointer_MACRO( member_memoryAddress );
        
        // There are 4 options :
        // 
        //      1 0  ->  1
        //      0 1  ->  1
        //      0 0  ->  0
        //      1 1  ->  0
        //
        // As can be seen only in 2 cases an action needs to be taken, in both the bit in the other instance should be ON

        // Check if the given state is ON
        if ( state == 1 )
        {
            // The given state is ON

            // Check the state of the bit in this instance
            if ( ONorOFF() == 1 )
            {
                // The bit in this instance is also ON

                // Set the state of the bit to OFF
                SetONorOFF( 0 );
            }
            else
            {
                // The bit in this instance is OFF

                // Set the state of the bit to ON
                SetONorOFF( 1 );
            }

        }

        // Return a reference to this instance
        return ( *this );
    }



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



    template< typename AnyType >
    inline UnsignedInteger8bits& Bit< AnyType >::GetReferenceToTheByteThatContainsTheBit__Private()
    {
        // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
        // instance is ready to be used
        AssertPointer_MACRO( member_memoryAddress );
        
        // Cast the pointer as unsigned integer 8 bits, add to it the required offset to the byte that contains the bit, and return a copy
        return ( *( reinterpret_cast< UnsignedInteger8bits* >( member_memoryAddress ) + ( member_bitIndex / 8UL ) ) );
    }


    template< typename AnyType >
    inline const UnsignedInteger8bits& Bit< AnyType >::GetReferenceToTheByteThatContainsTheBit__Private() const
    {
        // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
        // instance is ready to be used
        AssertPointer_MACRO( member_memoryAddress );
        
        // Cast the pointer as unsigned integer 8 bits, add to it the required offset to the byte that contains the bit, and return a copy
        return ( *( reinterpret_cast< const UnsignedInteger8bits* >( member_memoryAddress ) + ( member_bitIndex / 8UL ) ) );
    }


    template< typename AnyType >
    inline UnsignedInteger8bits Bit< AnyType >::GetByteWithOnebitOnInTheRequiredIndex__Private() const
    {
        // Allocate a byte, and turn the lowest significant bit ON
        UnsignedInteger8bits byte = 1;

        // Left shift the bit to the required location
        return ( byte << ( member_bitIndex % 8 ) );
    }


    template< typename AnyType >
    inline UnsignedInteger8bits Bit< AnyType >::GetByteWithOnebitOffInTheRequiredIndex__Private() const
    {
        // Allocate a byte, and turn the lowest significant bit ON
        UnsignedInteger8bits byte = 1;

        // Left shift the bit to the required location, and perform the negotiate opeartion ( it will leave all the bits ON beside 1 bit that will be OFF
        // at the required location )
        return ( ~( byte << ( member_bitIndex % 8 ) ) );
    }



// **********************************************************   INLINE AND TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   ***********************************************************



    template< typename AnyTYPE >
    inline Boolean operator~( const Bit< AnyTYPE >& bit )
    {      
        // Return the negotiated state of the bit. If the bit is ON then the cimparison will result in 0, and if the bit is OFF the comparison will
        // result in 1
        return ( bit.ONorOFF() == 0 );
    }


    template< typename AnyTYPE >
    inline Boolean operator==( Boolean state, const Bit< AnyTYPE >& other )
    {
        // Check if both or only one of the instances is in default state
        AssertPointer_MACRO( other.member_memoryAddress );
        
        // Check if the bit in the other instance has the same state as the bit in this instance, and return the result
        return ( state == other.ONorOFF() );
    }


    template< typename AnyTYPE >
    inline Boolean operator!=( Boolean state, const Bit< AnyTYPE >& other )
    {        
        // Return the negotiated value from the equal operator
        return ( !( state == other ) );
    }



// *********************************************************************************   TESTING   ********************************************************************************



	DEBUG_TOOL(

		template< typename AnyType >
		void Bit< AnyType >::Test()
		{
            // Create a default constructed instance
            Bit< UnsignedInteger8bits > test_0;

            // Create a byte
            UnsignedInteger8bits test_1 = 0;

            // Create a test instance
            Bit< UnsignedInteger8bits > test_2( &test_1, 3 );

            // Set the bit on
            test_2.SetONorOFF( true );

            // Check that the bit was set on
            Assert_Test_MACRO( test_1 == 8 );

            // Set the bit on
            test_2.SetONorOFF( false );

            // Check that the bit was set off
            Assert_Test_MACRO( test_1 == 0 );

            // Check that the bit was set off
            Assert_Test_MACRO( test_1 == false );

            // Check that the negotiated state is true
            Assert_Test_MACRO( ~test_2 == true );

            // Check that the bit state stayed false
            Assert_Test_MACRO( false == test_2.ONorOFF() );

            // Check that the bit state stayed false
            Assert_Test_MACRO( test_2.ONorOFF() == 0 );
		}

	)  //  End of debug tool