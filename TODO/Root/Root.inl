//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



	template< typename NumericType >
	inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_Integer< NumericType >::Result() == true, Tuple< Boolean, NumericType > >::Type Root::Calculate( NumericType radicand, NumericType degree )
	{
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		Assert( ( radicand >= 0 ), "The given radicand should not be negative" );
		Assert( ( degree >= 0 ), "The given degree should not be negative" );

		// This will store the result of the calculation, the root and if the root is exact or not
		Tuple< Boolean, NumericType > root( true, 0 );

		// Check if the radicand is 0
		ReturnValueIfExpressionIsTrue( ( radicand == 0 ), root )

		// Set the root to 1
		root.template Entry< 1 >() = 1;

		// Check if the radicand is 1
		ReturnValueIfExpressionIsTrue( ( radicand == 1 ), root )

		// This object will store the current number checked to be the root in the power of the degree
		NumericType numberRaisedByThePowerOfTheDegree = 0;

		// Loop until the root is found or the result is bigger then the radicand
		while ( true )
		{
			// Set the next number that will be examined if it is the root
			root.template Entry< 1 >() += 1;

			// Raise the current number checked by the power of the degree
			numberRaisedByThePowerOfTheDegree = BaseRaisedByThePower::Calculate< NumericType >( root.template Entry< 1 >(), degree );

			// Check if the result match the radican, which means the root was found
			ReturnValueIfExpressionIsTrue( ( radicand == numberRaisedByThePowerOfTheDegree ), root )

			// Check if the result is larger then the radicand
			if ( radicand < numberRaisedByThePowerOfTheDegree )
			{
				// The result is larger then the radicand, which means that a root with no digits behind the decimal point does not exist

				// Decrement the root by 1, to return the last number raised by the power of the degree is smaller then the radicand
				root.template Entry< 1 >() -= 1;

				// break the loop
				break;
			}
		}

		// Set the boolean in the root to false, to notify that a root with no digits behind the decimal point does not exist
		root.template Entry< 0 >() = false;

		// Return the result of the calculation
		return ( root );
	}


	template< typename NumericType >
	inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_FloatingPoint< NumericType >::Result() == true, NumericType >::Type Root::Calculate( NumericType radicand, NumericType degree, NumericType maximumDifferenceBetweenRootCalculatedRaisedByThePowerOfTheDegreeAndRadicand )
	{
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		Assert( ( radicand >= 0 ), "The given radicand should not be negative" );
		Assert( ( degree >= 0 ), "The given degree should not be negative" );
		Assert( ( maximumDifferenceBetweenRootCalculatedRaisedByThePowerOfTheDegreeAndRadicand < 1 ), "The given difference between the root raised to the power of the degree should be less then 1" );

		// This will store the result of the calculation, the root and if the root is exact or not
		NumericType root = 0;

		// Check if the radicand is 0
		ReturnValueIfExpressionIsTrue( ( radicand == 0 ), root )

		// Set the root to 1
		root = 1;

		// Check if the radicand is 1
		ReturnValueIfExpressionIsTrue( ( radicand == 1 ), root )

		// This object will store the current number checked to be the root in the power of the degree
		NumericType numberRaisedByThePowerOfTheDegree = 0;

		// The first stage is to figure if a root with no digits behind the decimal point exist. If a root without digits behind the decimal point
		// does not exist, the next part is to try to find the most exact root with digits after the decimal point. The increment size so far 
		// between tries to find the root were 1, from now on the increment size will be decreased, until a root which stands in the requirements
		// is found or there is no smaller increment size

		// Loop until the increment size can not be smaller, each round the increment size will be divided by 10, to try with more precise smaller
		// values to find a suitable root
		for ( NumericType incrementSize = 1 ; incrementSize > 0.0000000000000000000000000000001 ; incrementSize /= 10 )
		{
			// Loop until the root is found or the result is bigger then the radicand
			while ( true )
			{
				// Set the next number that will be examined if it is the root
				root += incrementSize;

				// Raise the current number checked by the power of the degree
				numberRaisedByThePowerOfTheDegree = BaseRaisedByThePower::Calculate< NumericType >( root, degree );

				// Check if the result match the radican, which means the root was found
				ReturnValueIfExpressionIsTrue( ( AbsoluteValue::Calculate( radicand - numberRaisedByThePowerOfTheDegree ) < maximumDifferenceBetweenRootCalculatedRaisedByThePowerOfTheDegreeAndRadicand ), root )

				// Check if the result is larger then the radicand
				if ( radicand < numberRaisedByThePowerOfTheDegree )
				{
					// The result is larger then the radicand, which means that a root with no digits behind the decimal point does not exist

					// Decrement the root by 1, to return the last number raised by the power of the degree is smaller then the radicand
					root -= incrementSize;

					// break the loop
					break;
				}
			}

			// Check if the increment size is smaller then the required precision of the result, which means the most precisie root was found
			if ( incrementSize < maximumDifferenceBetweenRootCalculatedRaisedByThePowerOfTheDegreeAndRadicand )
			{
				// The required precision was reached

				// break the loop
				break;
			}
		}

		// Return the result of the calculation
		return ( root );
	}