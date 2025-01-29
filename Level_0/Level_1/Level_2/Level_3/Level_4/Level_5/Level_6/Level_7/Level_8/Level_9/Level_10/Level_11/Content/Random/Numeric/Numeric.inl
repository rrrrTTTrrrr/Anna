//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



template< Concepts::Integer IntegerType >
inline IntegerType Numeric::Next( const Range< IntegerType >& range )
{
    // This object will store the multiplier for the seed
    static constexpr IntegerType multiplier = static_cast< IntegerType >( 16807 );

    // This object will store the maximum value minus one. It will be used to ensure that the value is always in the required range
    static constexpr IntegerType modulus = NumericLimits< IntegerType >::Maximum - static_cast< IntegerType >( 1 );

    // This object will store the maximum value minus one. It will be used to ensure that the value is always in the required range
    static constexpr IntegerType increment = static_cast< IntegerType >( 0 );

    // This object will be used as the seed for the random integer
    static IntegerType seed = 7;

    // Generate the next random number and store the result as the seed for the next operation
    seed = static_cast< IntegerType >( ( multiplier * seed + increment ) % modulus );

    // Check if the random number is 0, which means it can not be used as a divisor. The other problem is that once the seed is 0, the result
    // will always be zero, and therefore it need to be changed
    if ( seed == 0 )
    {
        // Increment the seed be one
        seed += 1;

        // Return the range minimum
        return ( range.Minimum() );
    }

    // Adjust the random number to be in the required range if needed and return the result
    return ( range.Minimum() + static_cast< IntegerType >( seed % range.Size() ) );
}


template< Concepts::FloatingPoint FloatingPointType >
inline FloatingPointType Numeric::Next( const Range< FloatingPointType >& range )
{
    // Generate a random unsigned integer
    LargestSignedInteger randomInteger = Next< LargestSignedInteger >();

    // Check if the random integer is 0, which means it can not be used as a divisor
    if ( randomInteger == 0UL )
    {
        // The random integer is 0

        // Return the minimum value for the range
        return ( range.Minimum() );
    }

    // The random integer is not 0, it can be used as divisor

    // Add to the minimum value of the range to the size of the range divided by the random integer
    return ( range.Minimum() + static_cast< FloatingPointType >( randomInteger ) + ( static_cast< FloatingPointType >( randomInteger ) / ( static_cast< FloatingPointType >( randomInteger ) * static_cast< FloatingPointType >( 2.0 ) ) ) );
}


template<>
inline Boolean Numeric::Next( const Range< Boolean >& )
{
    // Generate a random unsigned integer
    UnsignedInteger8bits randomInteger = Next< UnsignedInteger8bits >();

    // If the random integer is even return false, and true in case of an odd number
    return ( randomInteger & 0x01 );
}


template< Concepts::Numeric NumericType, typename ObjectThatImplementSquareBracketsOperatorAndSizeMethodType >
inline void Numeric::SetMultipleNext( ObjectThatImplementSquareBracketsOperatorAndSizeMethodType& objectThatImplementSquareBracketsOperatorAndSizeMethodInstance, const Range< NumericType >& rangeForValues )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsLargerThenZero( objectThatImplementSquareBracketsOperatorAndSizeMethodInstance.Size() );

    // Loop on all the entries
    for ( LargestUnsignedInteger index = 0UL ; index < objectThatImplementSquareBracketsOperatorAndSizeMethodInstance.Size() ; ++index )
    {
        // Generate the next random value
        objectThatImplementSquareBracketsOperatorAndSizeMethodInstance[ index ] = Next< NumericType >( rangeForValues );
    }
}


template< Concepts::Numeric NumericType >
inline void Numeric::SetMultipleNextRawPointer( NumericType* const pointerToArray, const LargestUnsignedInteger size, const Range< NumericType >& rangeForValues )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertPointerIsNotNull( pointerToArray );
    AssertValueIsLargerThenZero( size );

    // Loop on all the entries
    for ( LargestUnsignedInteger index = 0UL ; index < size ; ++index )
    {
        // Generate the next random value
        pointerToArray[ index ] = Next< NumericType >( rangeForValues );
    }
}



}  //  Namespace RunTimeGenerator


}  //  Namespace Random


}  //  Namespace Universe

