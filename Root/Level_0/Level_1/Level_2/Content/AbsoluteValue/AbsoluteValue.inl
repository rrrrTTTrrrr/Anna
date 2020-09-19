//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



	template< typename NumericType >
	inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_UnsignedInteger< NumericType >::Result() == false, NumericType >::Type AbsoluteValue::Calculate( NumericType number )
	{
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		Assert_MACRO( ( number != NumericLimits< NumericType >::Minimum() ), "The value should not be the minimum negative value of the signed integer type" );

		// Check if the number is negative
		if ( number < 0 )
		{
			// The number is negative, multiply the value by minus one, to extract the absolute value
			number *= -1;
		}

		// Return the absolute value
		return ( number );
	}


	template< typename SignedIntegerType >
	inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_SignedInteger< SignedIntegerType >::Result() == true, typename SignedToUnsigned< SignedIntegerType >::Type >::Type AbsoluteValue::CalculateAndReturnAbsoluteValueAsUnsignedIntegerWithTheSameSize( SignedIntegerType number )
	{
		// Check if the number is negative
		if ( number < 0 )
		{
			// The number is negative, multiply the value by minus one, to extract the absolute value
			number *= -1;
		}

		// Return the absolute value in an unsigned integer type with the same size
		return ( static_cast< SignedToUnsigned< SignedIntegerType >::Type >( number ) );
	}



// *********************************************************************************   TESTING   ********************************************************************************



	DEBUG_TOOL(

		inline void AbsoluteValue::Test()
		{
			Assert_Test_MACRO( CalculateAndReturnAbsoluteValueAsUnsignedIntegerWithTheSameSize< SignedInteger64bits >( -8 ) == 8UL );
			Assert_Test_MACRO( CalculateAndReturnAbsoluteValueAsUnsignedIntegerWithTheSameSize< SignedInteger64bits >( 8 ) == 8UL );

			Assert_Test_MACRO( Calculate< SignedInteger64bits >( -8 ) == 8 );
			Assert_Test_MACRO( Calculate< SignedInteger64bits >( 8 ) == 8 );
		}

	)  //  End of debug tool