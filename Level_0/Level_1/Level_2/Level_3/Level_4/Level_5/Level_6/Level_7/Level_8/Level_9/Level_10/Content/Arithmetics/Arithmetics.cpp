namespace Universe 
{



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	void Arithmetics::UnitTest()
	{
		// Tests for absolute value :

		Assert_Test( AbsoluteValueReturnAsUnsignedIntegerWithTheSameSize< SignedInteger64bits >( -8 ) == 8UL );
		Assert_Test( AbsoluteValueReturnAsUnsignedIntegerWithTheSameSize< SignedInteger64bits >( 8 ) == 8UL );

		Assert_Test( AbsoluteValue< SignedInteger64bits >( -8 ) == 8 );
		Assert_Test( AbsoluteValue< SignedInteger64bits >( 8 ) == 8 );

		Assert_Test( AbsoluteValue< UnsignedInteger64bits >( 8 ) == 8 );
		Assert_Test( AbsoluteValue< UnsignedInteger64bits >( 0 ) == 0 );

		Assert_Test( AbsoluteValue< FloatingPoint64bits >( -8.7874 ) - 8.7874 < 0.000001 );
		Assert_Test( AbsoluteValue< FloatingPoint64bits >( 820302 ) - 820302 < 0.000001 );

		Assert_Test( AbsoluteValue< Boolean >( true ) == true );
		Assert_Test( AbsoluteValue< Boolean >( false ) == false );

		Assert_Test( AbsoluteValueReturnAsUnsignedIntegerWithTheSameSize< SignedInteger64bits >( -8 ) == 8UL );
		Assert_Test( AbsoluteValueReturnAsUnsignedIntegerWithTheSameSize< SignedInteger64bits >( 8 ) == 8UL );

		Assert_Test( AbsoluteValue< SignedInteger64bits >( -8 ) == 8 );
		Assert_Test( AbsoluteValue< SignedInteger64bits >( 8 ) == 8 );

		Assert_Test( AbsoluteValue< UnsignedInteger64bits >( 8 ) == 8 );
		Assert_Test( AbsoluteValue< UnsignedInteger64bits >( 0 ) == 0 );

		Assert_Test( AbsoluteValue< FloatingPoint64bits >( -8.7874 ) - 8.7874 < 0.000001 );
		Assert_Test( AbsoluteValue< FloatingPoint64bits >( 820302 ) - 820302 < 0.000001 );

		Assert_Test( AbsoluteValue< Boolean >( true ) == true );
		Assert_Test( AbsoluteValue< Boolean >( false ) == false );


		// Tests for is power of 2 :

		// This array will store all the values which are power of 2 that needs to be checked
		UnsignedInteger64bits powerOfTwoValues[] = {2UL COMMA 4UL COMMA 8UL COMMA 16UL COMMA 32UL COMMA 64UL COMMA 128UL COMMA 256UL COMMA 512UL COMMA 1024UL COMMA 2048UL COMMA 4096UL COMMA 8192UL COMMA 16384UL COMMA 32768UL COMMA 65536UL};

		// This variable will check the number of times the function returned true
		UnsignedInteger64bits numberOfTrue = 0UL;

		// Loop until the value 70000
		for ( UnsignedInteger64bits value = 0UL ; value < 70000UL ; ++value )
		{
			// Check if the current value is a power of 2
			Boolean result = IsPowerOfTwo< UnsignedInteger64bits >( value );

			// Check if the result is true
			if ( result == true )
			{
				// Increase the number of true by 1
				numberOfTrue += 1UL;

				// Check if the current value appear in the array
				for ( UnsignedInteger64bits index = 0UL ; index < 17UL ; ++index )
				{

					// Check if the current value appear in the array
					if ( powerOfTwoValues[ index ] == value )
					{
						// The result seems correct
						break;
					}

					// Check that only 16 times true was returned
					Assert_Test( index != 16UL );
				}

			}

		}

		// Check that only 16 times true was returned
		Assert_Test( numberOfTrue == 16UL );


		// Test for get next number that divides with no remainder :

		Assert_Test( GetNextValueThatDividesWithNoRemainder< UnsignedInteger64bits >( 0UL COMMA 8UL ) == 0UL );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< UnsignedInteger64bits >( 1UL COMMA 8UL ) == 8UL );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< UnsignedInteger64bits >( 2UL COMMA 8UL ) == 8UL );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< UnsignedInteger64bits >( 3UL COMMA 8UL ) == 8UL );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< UnsignedInteger64bits >( 4UL COMMA 8UL ) == 8UL );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< UnsignedInteger64bits >( 5UL COMMA 8UL ) == 8UL );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< UnsignedInteger64bits >( 6UL COMMA 8UL ) == 8UL );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< UnsignedInteger64bits >( 7UL COMMA 8UL ) == 8UL );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< UnsignedInteger64bits >( 8UL COMMA 8UL ) == 8UL );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< UnsignedInteger64bits >( 9UL COMMA 8UL ) == 16UL );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< UnsignedInteger64bits >( 10UL COMMA 8UL ) == 16UL );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< UnsignedInteger64bits >( 11UL COMMA 8UL ) == 16UL );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< UnsignedInteger64bits >( 12UL COMMA 8UL ) == 16UL );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< UnsignedInteger64bits >( 13UL COMMA 8UL ) == 16UL );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< UnsignedInteger64bits >( 14UL COMMA 8UL ) == 16UL );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< UnsignedInteger64bits >( 15UL COMMA 8UL ) == 16UL );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< UnsignedInteger64bits >( 16UL COMMA 8UL ) == 16UL );

		Assert_Test( GetNextValueThatDividesWithNoRemainder< UnsignedInteger64bits >( 56UL COMMA 27UL ) == 81UL );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< UnsignedInteger64bits >( 335UL COMMA 33UL ) == 363UL );

		Assert_Test( GetNextValueThatDividesWithNoRemainder< SignedInteger64bits >( 0 COMMA 8 ) == 0 );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< SignedInteger64bits >( -1 COMMA 8 ) == 0 );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< SignedInteger64bits >( -2 COMMA 8 ) == 0 );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< SignedInteger64bits >( -3 COMMA 8 ) == 0 );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< SignedInteger64bits >( -4 COMMA 8 ) == 0 );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< SignedInteger64bits >( -5 COMMA 8 ) == 0 );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< SignedInteger64bits >( -6 COMMA 8 ) == 0 );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< SignedInteger64bits >( -7 COMMA 8 ) == 0 );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< SignedInteger64bits >( -8 COMMA 8 ) == -8 );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< SignedInteger64bits >( -9 COMMA 8 ) == -8 );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< SignedInteger64bits >( -10 COMMA 8 ) == -8 );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< SignedInteger64bits >( -11 COMMA 8 ) == -8 );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< SignedInteger64bits >( -12 COMMA 8 ) == -8 );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< SignedInteger64bits >( -13 COMMA 8 ) == -8 );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< SignedInteger64bits >( -14 COMMA 8 ) == -8 );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< SignedInteger64bits >( -15 COMMA 8 ) == -8 );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< SignedInteger64bits >( -16 COMMA 8 ) == -16 );

		Assert_Test( GetNextValueThatDividesWithNoRemainder< SignedInteger64bits >( -56 COMMA 27 ) == -54 );
		Assert_Test( GetNextValueThatDividesWithNoRemainder< SignedInteger64bits >( -335 COMMA 33 ) == -330 );


		// Test for get previous number that divides with no remainder :

		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( 0 COMMA 8 ) == 0 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( 1 COMMA 8 ) == 0 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( 2 COMMA 8 ) == 0 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( 3 COMMA 8 ) == 0 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( 4 COMMA 8 ) == 0 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( 5 COMMA 8 ) == 0 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( 6 COMMA 8 ) == 0 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( 7 COMMA 8 ) == 0 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( 8 COMMA 8 ) == 8 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( 9 COMMA 8 ) == 8 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( 10 COMMA 8 ) == 8 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( 11 COMMA 8 ) == 8 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( 12 COMMA 8 ) == 8 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( 13 COMMA 8 ) == 8 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( 14 COMMA 8 ) == 8 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( 15 COMMA 8 ) == 8 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( 16 COMMA 8 ) == 16 );

		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( 56 COMMA 27 ) == 54 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( 335 COMMA 33 ) == 330 );

		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( 0 COMMA 8 ) == 0 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( -1 COMMA 8 ) == -8 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( -2 COMMA 8 ) == -8 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( -3 COMMA 8 ) == -8 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( -4 COMMA 8 ) == -8 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( -5 COMMA 8 ) == -8 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( -6 COMMA 8 ) == -8 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( -7 COMMA 8 ) == -8 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( -8 COMMA 8 ) == -8 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( -9 COMMA 8 ) == -16 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( -10 COMMA 8 ) == -16 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( -11 COMMA 8 ) == -16 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( -12 COMMA 8 ) == -16 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( -13 COMMA 8 ) == -16 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( -14 COMMA 8 ) == -16 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( -15 COMMA 8 ) == -16 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( -16 COMMA 8 ) == -16 );

		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( -56 COMMA 27 ) == -81 );
		Assert_Test( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( -335 COMMA 33 ) == -363 );


		// Test does number divide by two with no remainder :

		Assert_Test( IsEven< UnsignedInteger64bits >( 8UL ) == true );
		Assert_Test( IsEven< UnsignedInteger64bits >( 0UL ) == true );
		Assert_Test( IsEven< UnsignedInteger64bits >( 11UL ) == false );
		Assert_Test( IsEven< UnsignedInteger64bits >( 45632UL ) == true );
		Assert_Test( IsEven< UnsignedInteger64bits >( 34343UL ) == false );
		Assert_Test( IsEven< UnsignedInteger64bits >( 99995UL ) == false );
		Assert_Test( IsEven< UnsignedInteger64bits >( 88888UL ) == true );
		Assert_Test( IsEven< UnsignedInteger64bits >( 84UL ) == true );
		Assert_Test( IsEven< UnsignedInteger64bits >( 1092019UL ) == false );
		Assert_Test( IsEven< SignedInteger64bits >( -8 ) == true );
		Assert_Test( IsEven< SignedInteger64bits >( -898879 ) == false );
		Assert_Test( IsEven< SignedInteger64bits >( -91932938 ) == true );
		Assert_Test( IsEven< SignedInteger64bits >( -1 ) == false );


		// Ensure all the results can be used also in constant expression context
		AssertCanBeUsedAsConstantExpression( IsEven< UnsignedInteger64bits >( 8UL ) );
		AssertCanBeUsedAsConstantExpression( AbsoluteValue< UnsignedInteger64bits >( 8UL ) );
		AssertCanBeUsedAsConstantExpression( AbsoluteValue< SignedInteger64bits >( -8 ) );
		AssertCanBeUsedAsConstantExpression( IsPowerOfTwo< UnsignedInteger64bits >( 875UL ) );
		AssertCanBeUsedAsConstantExpression( AbsoluteValueReturnAsUnsignedIntegerWithTheSameSize< SignedInteger64bits >( -8 ) );
		AssertCanBeUsedAsConstantExpression( Sign< SignedInteger64bits >( -8 ) );
		AssertCanBeUsedAsConstantExpression( Power< SignedInteger64bits >( 4, 9 ) );
		AssertCanBeUsedAsConstantExpression( GetNextValueThatDividesWithNoRemainder< SignedInteger64bits >( -15 COMMA 8 ) );
		AssertCanBeUsedAsConstantExpression( GetPreviousValueThatDividesWithNoRemainder< SignedInteger64bits >( -335 COMMA 33 ) );
	}

)  //  End of debug tool



}  //  Namespace Universe