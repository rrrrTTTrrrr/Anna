// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *******************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = Numeric   ****************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //




//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< Concepts::Numeric NumericType >
inline Range< NumericType >::Range() :
	member_minimum( NumericLimits< NumericType >::Minimum ),
	member_maximum( NumericLimits< NumericType >::Maximum )
{}


template< Concepts::Numeric NumericType >
inline Range< NumericType >::Range( const NumericType minimum, const NumericType maximum ) :
	member_minimum( minimum ),
	member_maximum( maximum )
{
	// This will be added only in test mode, to ensure that the given data to the method is valid
	Assert( ( maximum >= minimum ), "The given maximum should be larger then the minimum" );		
}


template< Concepts::Numeric NumericType >
inline Range< NumericType >::Range( const SelfType& other ) :
	member_minimum( other.member_minimum ),
	member_maximum( other.member_maximum )
{}


template< Concepts::Numeric NumericType >
inline NumericType Range< NumericType >::Size() const
{
	// Store the difference between the maximum and minimun of the range
	NumericType size = member_maximum - member_minimum;

	// Check during compile time if the numeric type is integer of floating point
	if constexpr ( IsFloatingPoint< NumericType >::Result == true )
	{
		// The type is a floating point

	    // Check if the range is too large to store the size of it into the type, which means the current value is infinity
	    if ( size > NumericLimits< NumericType >::Maximum )
	    {
	    	// The range size is to large for the type to store the value

	    	// Set the range size to the maximum value the floating point type can store
	    	size = NumericLimits< NumericType >::Maximum;
	    }		
	}

	// Return the size of the range
	return ( size );
}


template< Concepts::Numeric NumericType >
inline void Range< NumericType >::SetMinimum( NumericType minimum )
{
	// This will be added only in test mode, to ensure that the given data to the method is valid
	Assert( ( member_maximum >= minimum ), "The given minimum should be smaller then the maximum" );		

	// Set the new minimum
	member_minimum = minimum;
}


template< Concepts::Numeric NumericType >
inline void Range< NumericType >::SetMaximum( NumericType maximum )
{
	// This will be added only in test mode, to ensure that the given data to the method is valid
	Assert( ( maximum >= member_minimum ), "The given maximum should be larger then the minimum" );		

	// Set the new maximum
	member_minimum = maximum;
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< Concepts::Numeric NumericType >
inline Boolean Range< NumericType >::operator==( const SelfType& other ) const
{
	// Check if the minimum and maximum of both instances are the same and return the result
	return ( ( member_minimum == other.member_minimum ) && ( member_maximum == other.member_maximum ) );
}


template< Concepts::Numeric NumericType >
inline Boolean Range< NumericType >::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = Object ( Not numeric )   ********************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //




//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< typename ObjectType > requires ( !Concepts::Numeric< ObjectType > )
inline Range< ObjectType >::Range() :
	member_instanceThatRepresentsTheMinimum( ObjectType::Minimum() ),
	member_instanceThatRepresentsTheMaximum( ObjectType::Maximum() )
{}


template< typename ObjectType > requires ( !Concepts::Numeric< ObjectType > )
inline Range< ObjectType >::Range( const ObjectType& minimum, const ObjectType& maximum ) :
	member_instanceThatRepresentsTheMinimum( AssignOnlyIfAssertionPassed( ActAccordingToType::IsFirstInstanceEqualOrSmallerThenTheSecond( minimum, maximum ), minimum , "The maximum must be larger then the minimum" ) ),
	member_instanceThatRepresentsTheMaximum( maximum )
{}


template< typename ObjectType > requires ( !Concepts::Numeric< ObjectType > )
inline Range< ObjectType >::Range( const SelfType& other ) :
	member_instanceThatRepresentsTheMinimum( other.member_instanceThatRepresentsTheMinimum ),
	member_instanceThatRepresentsTheMaximum( other.member_instanceThatRepresentsTheMaximum )
{}


template< typename ObjectType > requires ( !Concepts::Numeric< ObjectType > )
inline void Range< ObjectType >::SetMinimum( const ObjectType& minimum )
{
	// This will be added only in test mode, to ensure that the given data to the method is valid
	Assert( ActAccordingToType::IsFirstInstanceEqualOrSmallerThenTheSecond( minimum, member_instanceThatRepresentsTheMaximum ), "The given minimum should be smaller then the maximum" );		

	// Set the new minimum
	member_instanceThatRepresentsTheMinimum = minimum;
}


template< typename ObjectType > requires ( !Concepts::Numeric< ObjectType > )
inline void Range< ObjectType >::SetMaximum( const ObjectType& maximum )
{
	// This will be added only in test mode, to ensure that the given data to the method is valid
	Assert( ActAccordingToType::IsFirstInstanceEqualOrSmallerThenTheSecond( member_instanceThatRepresentsTheMinimum, maximum ), "The given maximum should be larger then the minimum" );		

	// Set the new maximum
	member_instanceThatRepresentsTheMinimum = maximum;
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< typename ObjectType > requires ( !Concepts::Numeric< ObjectType > )
inline Boolean Range< ObjectType >::operator==( const SelfType& other ) const
{
	// Check if the minimum and maximum of both instances are the same and return the result
	return ( ( member_instanceThatRepresentsTheMinimum == other.member_instanceThatRepresentsTheMinimum ) && ( member_instanceThatRepresentsTheMaximum == other.member_instanceThatRepresentsTheMaximum ) );
}


template< typename ObjectType > requires ( !Concepts::Numeric< ObjectType > )
inline Boolean Range< ObjectType >::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< Concepts::Numeric NumericType >
	inline void Range< NumericType >::UnitTest()
	{
		// Create a range
		Range< UnsignedInteger8bits > testRange_1( 32, 45 );

		// Check the minimum and maximum
		Assert_Test( testRange_1.Minimum() == 32 );
		Assert_Test( testRange_1.Maximum() == 45 );
	}

)  //  End of debug tool



}  //  Namespace Universe