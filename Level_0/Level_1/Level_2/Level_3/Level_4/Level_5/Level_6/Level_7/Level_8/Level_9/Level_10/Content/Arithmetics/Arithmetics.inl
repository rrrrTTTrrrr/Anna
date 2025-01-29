//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



template< Concepts::Numeric NumericType >
EnsureRetrunValueIsUsed inline constexpr Boolean Arithmetics::Sign( const NumericType value )
{
	// Check if the value is negative or positive and return the result
	return ( value >= 0 );
}


template< Concepts::UnsignedNumeric UnsignedNumericType >
EnsureRetrunValueIsUsed inline constexpr UnsignedNumericType Arithmetics::AbsoluteValue( const UnsignedNumericType value )
{
	// The type is unsigned, which means the value is already positive. Return it
	return ( value );
}


template< Concepts::SignedNumeric SignedNumericType >
EnsureRetrunValueIsUsed inline constexpr SignedNumericType Arithmetics::AbsoluteValue( const SignedNumericType value )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsAboveCertainLimit_CompileTimeSupportedAsWell( value, NumericLimits< SignedNumericType >::Minimum );

	// The value should not be the minimum, taking the absolute value of it is undefined behavior. The reason is that in 2's
	// compliment the lowest negative value is always larger by one, than largest positive values

	// Create a copy of the value
	SignedNumericType valueCopy = value;

	// Check if the value is negative
	if ( valueCopy < 0 )
	{
		// The value is negative, multiply the value by minus one, to extract the absolute value
		valueCopy *= -1;
	}

	// Return the absolute value
	return ( valueCopy );
}


template< Concepts::UnsignedNumeric UnsignedNumericType >
EnsureRetrunValueIsUsed inline constexpr UnsignedNumericType Arithmetics::AbsoluteDifference( const UnsignedNumericType firstValue, const UnsignedNumericType secondValue )
{
	// The type is unsigned, which means the values can only be positive. This means that in order to return the absoulte value of the difference
	// between the values the smaller value needed to be subtracted from the larger number. By subtracting the larger number from the smalle number
	// the result value will cause the circualr behaciour of unsigned integers
	return ( firstValue >= secondValue ? ( firstValue - secondValue ) : ( secondValue - firstValue ) );
}


template< Concepts::SignedNumeric SignedNumericType >
EnsureRetrunValueIsUsed inline constexpr SignedNumericType Arithmetics::AbsoluteDifference( const SignedNumericType firstValue, const SignedNumericType secondValue )
{
	// Calculate the difference
	SignedNumericType difference = firstValue - secondValue;

	// Check if the difference is negative
	if ( difference < 0 )
	{
		// The difference is negative, multiply the difference by minus one, to extract the absolute difference
		difference *= -1;
	}

	// Return the absolute difference
	return ( difference );
}


template< Concepts::SignedInteger SignedIntegerType >
EnsureRetrunValueIsUsed inline constexpr typename ToUnsigned< SignedIntegerType >::Type Arithmetics::AbsoluteValueReturnAsUnsignedIntegerWithTheSameSize( const SignedIntegerType value )
{		
	// Create a copy of the value
	SignedIntegerType valueCopy = value;

	// Check if the value is negative
	if ( valueCopy < 0 )
	{
		// The value is negative, multiply the value by minus one, to extract the absolute value
		valueCopy *= -1;
	}

	// Return the absolute value in an unsigned integer type with the same size
	return ( static_cast< ToUnsigned< SignedIntegerType >::Type >( valueCopy ) );
}


template< Concepts::Integer IntegerType >
EnsureRetrunValueIsUsed inline constexpr Boolean Arithmetics::IsEven( const IntegerType value )
{
	// For integers if the value divides by 2 with no remainder, then the less significant bit will be off. Therefore, a temporary of
	// the integer type, with only the less significant bit on, and perform the and '&' bitwise operation, and return the negotaited
	// value. If the less significant bit is on, the and operation will produce the value 1, and the negotaited value will be false to
	// notify that the value does not divide by two with no remainder
	return ( ( value & 1 ) == 0 );
}


template< Concepts::Integer IntegerType >
EnsureRetrunValueIsUsed inline constexpr Boolean Arithmetics::IsPowerOfTwo( const IntegerType value )
{
	// The rational is that each integer value which is a power of 2, there will be only 1 bit on. Then in this case minus 1 of this value, will have
	// all the bits before ON, and then the AND operation between the given value and the value minus 1 will give 0. For example :
	//
	//		The value            ->    00001101
	//		The value minus 1    ->	   00001100
	//		The AND operation 	 ->    00001101 & 00001100 != 0
	//
	// In the first example the value is not a power of 2, and therefore the process does not give 0. But now :
	//
	//		The value            ->    00001000
	//		The value minus 1    ->	   00000111
	//		The AND operation 	 ->    00001000 & 00000111 == 0
	//
	// Note - the value 0 which is not a power of 2, will give also the same result and therefore will be excluded

	// Check if the value is 0 or 1 then the result is false
	ReturnValueIfExpressionIsTrue( ( value == 0 ), false );
	ReturnValueIfExpressionIsTrue( ( value == 1 ), false );

	// Check if the integer type is signed
	if constexpr ( IsSignedInteger< IntegerType >::Result == true )
	{
		// The integer type is signed, 

		// Check if the value is the minimum possible value for the type
		if ( value == NumericLimits< IntegerType >::Minimum )
		{
			// The value is the minimum possible value for the type

			// This means that the value is a power of 2
			return ( true );
		}
	}

	// It is safe to take the absoulte value, because even if the type is signed, the value stored is not the minimum value for the type

	// Take the absoulte value
	const IntegerType absoluteValue = AbsoluteValue< IntegerType >( value );

	// Perform the process on the value and return the result
	return ( ( absoluteValue & ( absoluteValue - 1 ) ) == 0 );
}


template< Concepts::Numeric NumericType >
EnsureRetrunValueIsUsed inline constexpr NumericType Arithmetics::Power( const NumericType base, const NumericType exponent )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	if constexpr ( IsInteger< NumericType >::Result == true )
	{
		// The type is integer

		// Assert that the exponent is not negative
		AssertValueIsEqualOrAboveCertainLimit_CompileTimeSupportedAsWell( exponent, 0 );
	}

	// Check if the base is 0, then return 0
	ReturnValueIfExpressionIsTrue( ( base == 0 ), 0 );

	// This object will store the result of the base raised to the exponent
	NumericType result = 1;

	// Store the absolute value of the exponent
	const NumericType exponentAbsoluteValue = AbsoluteValue< NumericType >( exponent );

	// The exponent provided will determine the number of iterations for the loop
	for ( NumericType iteration = 0 ; iteration < exponentAbsoluteValue ; ++iteration )
	{
		// Multiply the base by the result
		result *= base;
	}

	// Check if the type not an integer
	if constexpr ( IsInteger< NumericType >::Result == false )
	{
		// The type is not an integer

		// Check if the exponent is negative, in this case the numerator should be 1, and the denominator is the result. This part is only for
		// cases where the numeric type is a floating point
		ReturnValueIfExpressionIsTrue( ( exponent < 0 ), ( 1 / result ) );
	}

	// Return the result
	return ( result );
}


template< Concepts::Integer IntegerType >
EnsureRetrunValueIsUsed inline constexpr IntegerType Arithmetics::GetNextValueThatDividesWithNoRemainder( const IntegerType startingValue, const IntegerType divisor )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsNotZero_CompileTimeSupportedAsWell( divisor );

	// Store the absolute value of the divisor, which the sign of it has no effect on the result
	const IntegerType divisorAbsoluteValue = AbsoluteValue< IntegerType >( divisor );

	// Divide the starting value by the divisor and store the remainder
	const IntegerType remainder = AbsoluteValue< IntegerType >( startingValue % divisorAbsoluteValue );

	// Check if there is no remainder left from the division, then just return the starting value
	ReturnValueIfExpressionIsTrue( ( remainder == 0 ), startingValue );

	// Check if the starting number is negative, which means the result absolute value should be smaller. And all there is to do is to add
	// the remainder to the starting value
	ReturnValueIfExpressionIsTrue( ( startingValue < 0 ), ( startingValue + remainder ) );

	// Now, the remainder is known and the starting number is positive. In order to get to the next number that divides with no remainder, 
	// the remainder needs to be subtracted from the divisor, and the result needs to be added to the starting number. Finally return the result
	return ( startingValue + ( divisorAbsoluteValue - remainder ) );
}


template< Concepts::Integer IntegerType >
EnsureRetrunValueIsUsed inline constexpr IntegerType Arithmetics::GetPreviousValueThatDividesWithNoRemainder( const IntegerType startingValue, const IntegerType divisor )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsNotZero_CompileTimeSupportedAsWell( divisor );

	// Store the absolute value of the divisor, which the sign of it has no effect on the result
	IntegerType divisorAbsoluteValue = AbsoluteValue< IntegerType >( divisor );

	// Divide the starting value by the divisor and store the remainder
	IntegerType remainder = AbsoluteValue< IntegerType >( startingValue % divisorAbsoluteValue );

	// Check if there is no remainder left from the division, then just return the starting value
	ReturnValueIfExpressionIsTrue( ( remainder == 0 ), startingValue );

	// Check if the starting number is positive, which means the result absolute value should be smaller. And all there is to do is to
	// subtract the remainder from the starting value
	ReturnValueIfExpressionIsTrue( ( startingValue > 0 ), ( startingValue - remainder ) );

	// Now, the remainder is known and the starting number is negative. In order to get to the previous number that divides with no 
	// remainder, the remainder needs to be subtracted from the divisor, and the result needs to be subtracted from the starting number. 
	// Finally return the result
	return ( startingValue - ( divisorAbsoluteValue - remainder ) );
}



}  //  Namespace Universe