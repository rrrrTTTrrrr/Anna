//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



	inline InstanceState::InstanceState() :
    member_state( Default )
	{}


    inline InstanceState::InstanceState( UnsignedInteger64bits state ) :
    member_state( state )
    {}


	inline InstanceState::InstanceState( const InstanceState& other ) :
    member_state( other.member_state )
	{}


	inline InstanceState& InstanceState::operator=( const InstanceState& other )
	{
		// Create a copy of the other instance
		InstanceState temporary( other );

		// Swap between this instance and the temporary one, this will leave the temporary instance with the old data, and he will delete it
		Swap( temporary );

		// Return a reference to this object
		return ( *this );
	}


	inline InstanceState::InstanceState( InstanceState&& other ) :
	InstanceState()
	{
		// Swap between this instance, which is in default state, and the other one
		Swap( other );
	}


	inline InstanceState& InstanceState::operator=( InstanceState&& other )
	{
	    // Create a default constructed instance
	    InstanceState defaultConstructedInstance;

	    // Swap between the temporary instance, which is in default state, and the other instance
	    defaultConstructedInstance.Swap( other );

	    // Swap between this instance and the temporary one
	    Swap( defaultConstructedInstance );

	    // Return a reference to this object
	    return ( *this );
	}


	inline void InstanceState::Swap( InstanceState& other )
	{
        // This object will store a copy of the other instance state
        UnsignedInteger64bits otherInstanceStateCopy = other.member_state;

        // Store the state of this instance into the other instance
        other.member_state = member_state;

        // Store the other state into this instance
        member_state = otherInstanceStateCopy;
    }


    inline void InstanceState::Reset()
    {
        // Create a default constructed instance, it will be used to swap with this instance, leaving this instance in default state, and delete the old data
        InstanceState defaultConstructedInstance;

        // Swap between this instance and the default constructed instance
        Swap( defaultConstructedInstance );
    }


    inline void InstanceState::Initiate( UnsignedInteger64bits state )
    {
        // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
        // leave this scope it will delete the old data
        InstanceState temporary( state );

        // Swap between this instance and the temporary instance
        Swap( temporary );
    }


	inline UnsignedInteger64bits InstanceState::Get() const
	{
		// Check if the instance is in default state, and return the result
		return ( member_state );
    }


    inline void InstanceState::Set( UnsignedInteger64bits state )
    {
        // Set the instance to the new state
        member_state = state;
    }



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



	inline Boolean InstanceState::operator==( const InstanceState& other ) const
	{
        // Compare between the booleans, and return the result
        return ( member_state == other.member_state );
    }


	inline Boolean InstanceState::operator!=( const InstanceState& other ) const
	{
		// Return the negotiated value from the equal operator
		return ( !( *this == other ) );
	}