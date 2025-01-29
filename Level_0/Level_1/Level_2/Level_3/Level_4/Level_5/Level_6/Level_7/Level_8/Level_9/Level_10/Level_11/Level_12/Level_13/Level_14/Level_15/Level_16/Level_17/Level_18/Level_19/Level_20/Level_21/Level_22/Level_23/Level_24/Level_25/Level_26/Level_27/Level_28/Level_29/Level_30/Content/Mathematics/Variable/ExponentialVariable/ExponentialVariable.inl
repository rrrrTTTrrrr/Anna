//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



	inline ExponentialVariable::ExponentialVariable() :
		member_coefficient(),
		member_power()
	{}


	inline ExponentialVariable::ExponentialVariable( FloatingPoint64bits coefficient, FloatingPoint64bits power ) :
		member_coefficient( coefficient ),
		member_power( power )
	{}


	inline ExponentialVariable::ExponentialVariable( RandomInstance, const Range< FloatingPoint64bits >& rangeForCoefficient, const Range< FloatingPoint64bits >& rangeForPower ) :
		member_coefficient( Random::Generator::Next< FloatingPoint64bits >( rangeForCoefficient ) ),
		member_power( Random::Generator::Next< FloatingPoint64bits >( rangeForPower ) )
	{}


	inline ExponentialVariable::ExponentialVariable( const SelfType& other ) :
		member_coefficient( other.member_coefficient ),
		member_power( other.member_power )
	{}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



	inline Boolean ExponentialVariable::operator==( const SelfType& other ) const
	{
		// Compare the coefficient and power, and return the result
		return ( ( member_coefficient == other.member_coefficient ) && ( member_power == other.member_power ) );
	}


	inline Boolean ExponentialVariable::operator!=( const SelfType& other ) const
	{
		// Return the negotiated value from the equal operator
		return ( !( *this == other ) );
	}