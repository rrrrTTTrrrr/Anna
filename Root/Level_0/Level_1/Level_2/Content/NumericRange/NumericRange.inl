//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



	template< typename IntegerType >
	inline NumericRange< IntegerType >::NumericRange() :
		member_minimum( NumericLimits< IntegerType >::Minimum() ),
		member_maximum( NumericLimits< IntegerType >::Maximum() )
	{}


	template< typename IntegerType >
	inline NumericRange< IntegerType >::NumericRange( IntegerType minimum, IntegerType maximum ) :
		member_minimum( minimum ),
		member_maximum( maximum )
	{
		// This will be added only in test mode, to ensure that the given data to the method is valid
		Assert_MACRO( ( maximum > minimum ), "The given maximum should be larger then the minimum" );		
	}


	template< typename IntegerType >
	inline NumericRange< IntegerType >::NumericRange( RandomInstance ) :
		SelfType( ( NumericLimits< IntegerType >::Maximum() / 17 ), ( NumericLimits< IntegerType >::Maximum() / 7 ) )
	{}


	template< typename IntegerType >
	inline NumericRange< IntegerType >::NumericRange( const SelfType& other ) :
		member_minimum( other.member_minimum ),
		member_maximum( other.member_maximum )
	{}


	template< typename IntegerType >
	inline IntegerType NumericRange< IntegerType >::Size() const
	{

		// Check if the minimum of the range is the lowest possible value for the type, which means that the positive value of it can not be represented
		// by this type
		if ( NumericLimits< IntegerType >::Minimum() == member_minimum )
		{
			// Subtract the minimum of the range, plus one to avoid overflow, from the maximum of the range, and then add one to the result
			return ( member_maximum - ( member_minimum + 1 ) );
		}

		// Subtract the minimum of the range from the maximum of the range
		return ( member_maximum - member_minimum );
	}


	template< typename IntegerType >
	inline IntegerType NumericRange< IntegerType >::Minimum() const
	{
		// Return the minimum value for range
		return ( member_minimum );
	}


	template< typename IntegerType >
	inline void NumericRange< IntegerType >::SetMinimum( IntegerType minimum )
	{
		// This will be added only in test mode, to ensure that the given data to the method is valid
		Assert_MACRO( ( member_maximum > member_minimum ), "The given minimum should be smaller then the maximum" );		

		// Set the new minimum
		member_minimum = minimum;
	}


	template< typename IntegerType >
	inline IntegerType NumericRange< IntegerType >::Maximum() const
	{
		// Return the maximum value for the range
		return ( member_maximum );
	}


	template< typename IntegerType >
	inline void NumericRange< IntegerType >::SetMaximum( IntegerType maximum )
	{
		// This will be added only in test mode, to ensure that the given data to the method is valid
		Assert_MACRO( ( member_maximum > member_minimum ), "The given maximum should be larger then the minimum" );		

		// Set the new maximum
		member_minimum = maximum;
	}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



	template< typename IntegerType >
	inline Boolean NumericRange< IntegerType >::operator==( const SelfType& other ) const
	{
		// Check if the minimum and maximum of both instances are the same and return the result
		return ( ( member_minimum == other.member_minimum ) && ( member_maximum == other.member_maximum ) );
	}


	template< typename IntegerType >
	inline Boolean NumericRange< IntegerType >::operator!=( const SelfType& other ) const
	{
		// Return the negotiated value from the equal operator
		return ( !( *this == other ) );
	}



// *********************************************************************************   TESTING   ********************************************************************************



	DEBUG_TOOL(

		template< typename IntegerType >
		inline void NumericRange< IntegerType >::Test()
		{
			// Create a range
			NumericRange< UnsignedInteger8bits > testNumericRange_1( 32, 45 );

			// Check the minimum and maximum
			Assert_Test_MACRO( testNumericRange_1.Minimum() == 32 );
			Assert_Test_MACRO( testNumericRange_1.Maximum() == 45 );
		}

	)  //  End of debug tool







