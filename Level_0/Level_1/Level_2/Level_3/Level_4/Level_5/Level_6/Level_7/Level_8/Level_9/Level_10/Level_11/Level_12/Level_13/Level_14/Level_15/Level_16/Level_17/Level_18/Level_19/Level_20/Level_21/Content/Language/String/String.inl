//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< typename MemoryManagerType >
template< typename... AnyArgumentsNeededToConstructMemoryHandlerTypes >
inline StringImplementation< MemoryManagerType >::StringImplementation( const MemoryHandlerName memoryHandlerName, AnyArgumentsNeededToConstructMemoryHandlerTypes... anyArgumentsNeededToConstructMemoryHandler ) :
	SelfSequentialDataStructureType( memoryHandlerName, ForwardUniversalReference< AnyArgumentsNeededToConstructMemoryHandlerTypes >( anyArgumentsNeededToConstructMemoryHandler )... ),
	member_languageName( LanguageName::English )
{}


template< typename MemoryManagerType >
template< typename... AnyArgumentsNeededToConstructMemoryHandlerTypes >
inline StringImplementation< MemoryManagerType >::StringImplementation( const LanguageName languageName, const MemoryHandlerName memoryHandlerName, AnyArgumentsNeededToConstructMemoryHandlerTypes... anyArgumentsNeededToConstructMemoryHandler ) :
	SelfSequentialDataStructureType( memoryHandlerName, ForwardUniversalReference< AnyArgumentsNeededToConstructMemoryHandlerTypes >( anyArgumentsNeededToConstructMemoryHandler )... ),
	member_languageName( languageName )
{}


template< typename MemoryManagerType >
inline StringImplementation< MemoryManagerType >::StringImplementation( const SelfType& other, const LargestUnsignedInteger startingIndexOnOtherInstance, const LargestUnsignedInteger sizeFromOther, const MemoryHandlerName memoryHandlerName ) :
	SelfSequentialDataStructureType( other, startingIndexOnOtherInstance, sizeFromOther, memoryHandlerName ),
	member_languageName( other.member_languageName )
{}


template< typename MemoryManagerType >
inline StringImplementation< MemoryManagerType >::StringImplementation( const AsciiLiteral& asciiLiteral, const MemoryHandlerName memoryHandlerName ) :
	StringImplementation( LanguageName::English, memoryHandlerName, asciiLiteral.Size(), Character() )
{
	// Copy the content of the ascii literal into this instance
	for ( LargestUnsignedInteger index = 0UL ; index < asciiLiteral.Size() ; ++index )
	{
		// Set the current ascii charcter
		(*this)[ index ] = static_cast< Character >( asciiLiteral[ index ] );
	}
}


template< typename MemoryManagerType >
inline StringImplementation< MemoryManagerType >::StringImplementation( const AsciiLiteral& asciiLiteral, const LargestUnsignedInteger startingIndexOnAsciiLiteral, const LargestUnsignedInteger sizeFromAsciiLiteral, const MemoryHandlerName memoryHandlerName ) :
	StringImplementation( LanguageName::English, memoryHandlerName, sizeFromAsciiLiteral, Character() )
{
	// This object will store the index on this string
	LargestUnsignedInteger stringIndex = 0UL;

	// This object will store the index at which the copying of the ascii literal needs to finish
	const LargestUnsignedInteger lastIndex = startingIndexOnAsciiLiteral + sizeFromAsciiLiteral;

	// Copy the content of the ascii literal into this instance
	for ( LargestUnsignedInteger asciiLiteralIndex = startingIndexOnAsciiLiteral ; asciiLiteralIndex < lastIndex ; ++asciiLiteralIndex )
	{
		// Set the current ascii charcter
		SelfSequentialDataStructureType::operator[]( stringIndex ) = static_cast< Character >( asciiLiteral[ asciiLiteralIndex ] );

		// Increment the index on this string by 1
		stringIndex += 1UL;
	}
}


template< typename MemoryManagerType >
inline StringImplementation< MemoryManagerType >::StringImplementation( const AsciiCharacter* const rawString, const MemoryHandlerName memoryHandlerName ) :
	SelfType( AsciiLiteral( rawString ), memoryHandlerName )
{}


template< typename MemoryManagerType >
template< Concepts::Integer IntegerType >
inline StringImplementation< MemoryManagerType >::StringImplementation( const IntegerType integer ) :
	SelfSequentialDataStructureType( MemoryHandlerName::Vector, NumberOfDigits< IntegerType >( integer ) ),
	member_languageName( LanguageName::English )
{
	// Convert the integer into its digits and store it
	ConvertArgumentToStringAndStoreIt__Private< IntegerType >( &( SelfSequentialDataStructureType::operator[]( 0UL ) ), integer );
}


template< typename MemoryManagerType >
template< Concepts::FloatingPoint FloatingPointType >
inline StringImplementation< MemoryManagerType >::StringImplementation( const FloatingPointType floatingPoint ) :
	SelfSequentialDataStructureType(),
	member_languageName( LanguageName::English )
{
	Assert( false, "Needs to be implemented" );
}


template< typename MemoryManagerType >
template< Concepts::ConvertibleToStringObject ConvertibleToStringObjectTypeType >
inline StringImplementation< MemoryManagerType >::StringImplementation( const ConvertibleToStringObjectTypeType& instance ) :
	SelfType()
{
	*this = TakeResourcesAndLeaveInstanceInDefaultState( instance.ToString() );
}


template< typename MemoryManagerType >
template< Concepts::ConvertibleToString... ConvertibleToStringTypes >
inline StringImplementation< MemoryManagerType >::StringImplementation( const SelfType& format, const ConvertibleToStringTypes&... argumentsToFormat ) :
	SelfSequentialDataStructureType( MemoryHandlerName::Vector, CalculateFormattedStringSize__Private< ConvertibleToStringTypes... >( format, argumentsToFormat... ) ),
	member_languageName( LanguageName::English )
{
	// This object will store the string index
	LargestUnsignedInteger stringIndex = 0UL;

	// This object will store the format index
	LargestUnsignedInteger formatIndex = 0UL ;

	// Perform a recursive call to expose one at a time the arguments to format, convert them to string and store the result. Finally move on
	// to the next argument until the formatted result is ready
	ConvertArgumentToStringAndStoreIt__Private< ConvertibleToStringTypes... >( format, formatIndex, stringIndex, argumentsToFormat... );
}


template< typename MemoryManagerType >
inline StringImplementation< MemoryManagerType >::StringImplementation( const SelfType& other ) :
	SelfSequentialDataStructureType( other ),
	member_languageName( other.member_languageName )
{}


template< typename MemoryManagerType >
inline Memory::Vector< AsciiCharacter, MemoryManagerType > StringImplementation< MemoryManagerType >::ToAsciiString() const
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	Assert( ( member_languageName == Language::LanguageName::English ), "The language must be english" );

	// This object will store the size of the ascii string
	const LargestUnsignedInteger asciiStringSize = SelfSequentialDataStructureType::Size();

	// This object will store the string as an ascii string, the allocations is larger by one then the string size to store also the NULL terminator
	Memory::Vector< AsciiCharacter, MemoryManagerType > asciiString( asciiStringSize + 1UL );

	// Loop on all the characters of the string
	for ( LargestUnsignedInteger index = 0UL ; index < asciiStringSize ; ++index )
	{
		// Copy the current character into the ascii string
		asciiString[ index ] = SelfSequentialDataStructureType::operator[]( index ).GetAsAsciiCharacter();
	}

	// Set the NULL terminator
	asciiString[ asciiStringSize ] = 0;

	// Return the ascii string
	return ( asciiString );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< typename MemoryManagerType >
inline Boolean StringImplementation< MemoryManagerType >::operator==( const SelfType& other ) const
{
	// Compare the two sequential data structures inside the instance, and return the result
	return ( SelfSequentialDataStructureType::operator==( other ) );
}


template< typename MemoryManagerType >
inline Boolean StringImplementation< MemoryManagerType >::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}


template< typename MemoryManagerType >
inline StringImplementation< MemoryManagerType >& StringImplementation< MemoryManagerType >::operator+=( const SelfType& other )
{
	// Append the content of the other string to the end of this string
	SelfSequentialDataStructureType::operator+=( other );

    // Return a reference to this instance
    return ( *this );
}


template< typename MemoryManagerType >
inline StringImplementation< MemoryManagerType >& StringImplementation< MemoryManagerType >::operator+=( const AsciiLiteral& asciiLiteral )
{
	// This object will store the current size of the string
	const LargestUnsignedInteger oldSize = SelfSequentialDataStructureType::Size();

	// Insert the ascii literal content to the end of this string
	SelfSequentialDataStructureType::InsertMultipleTimesTheSameElement( oldSize, asciiLiteral.Size(), Character() );

	// Copy the content of the ascii literal into this instance
	for ( LargestUnsignedInteger asciiLiteralIndex = 0 ; asciiLiteralIndex < asciiLiteral.Size() ; ++asciiLiteralIndex )
	{
		// Set the current ascii charcter
		SelfSequentialDataStructureType::operator[]( asciiLiteralIndex + oldSize ) = asciiLiteral[ asciiLiteralIndex ];
	}

    // Return a reference to this instance
    return ( *this );
}




//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



template< typename MemoryManagerType >
template< Concepts::Integer IntegerType >
EnsureRetrunValueIsUsed inline LargestUnsignedInteger StringImplementation< MemoryManagerType >::NumberOfDigits( const IntegerType integer ) 
{
    // Check if the value is zero, then there is one digit, return 1
    ReturnValueIfExpressionIsTrue( ( integer == 0 ), 1 );

    // Store a copy of the integer
    IntegerType integerCopy = integer;

    // Space for the number of digits, initialize it with 1 if the value is negative which means that the '-' sign needs to be stroed as well
    LargestUnsignedInteger numberOfDigits = integer < 0 ? 1UL : 0UL;

    // Loop as long as the number is larger then 0
    while ( integerCopy != 0 )
    {
        // Divide the integer by 10 to strip the first digit
        integerCopy /= 10;

        // Increase the number of digits by 1
        numberOfDigits += 1UL;
    }

    // Return the number of digits in the integer
    return ( numberOfDigits );
}


template< typename MemoryManagerType >
template< Concepts::SignedInteger SignedIntegerType >
EnsureRetrunValueIsUsed inline LargestUnsignedInteger StringImplementation< MemoryManagerType >::IntegerToString( Character* const destinationStringPointer, const SignedIntegerType integer )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertPointerIsNotNull( destinationStringPointer );

    // Check if the integer value is 0
    if ( integer == 0 )
    {
        // The integer value is 0

        // Set the first entry with the ascii value for 0
        destinationStringPointer[0] = '0';

        // Nothing else needs to be done, return that only one character was needed to store the string
        return ( 1UL );
    }

    // This object will store the number digits in the integer
    LargestUnsignedInteger numberOfDigitsInInteger = NumberOfDigits< SignedIntegerType >( integer );

    // Store a copy of the integer
    SignedIntegerType integerCopy = integer;

    // Check if the integer is negative
    if ( integerCopy < 0 )
    {
        // The integer is negative

        // Set the first entry with the ascii value for '-'
        destinationStringPointer[0] = '-';

        // Set the integer to the absolue value by multiplying with -1
        integerCopy *= -1;
    }

    // Loop on all the digits of the integer
    for ( LargestUnsignedInteger index = ( numberOfDigitsInInteger - 1UL ) ; integerCopy != 0 ; --index )
    {
        // Set the string with the current digit by adding '0' to make it the ascii value
        destinationStringPointer[ index ] = static_cast< AsciiCharacter >( static_cast< AsciiCharacter >( integerCopy % 10 ) + '0' );

        // Divide the integer by 10
        integerCopy /= 10;
    }

    // Return the number of character needed to store the integer
    return ( numberOfDigitsInInteger );
}


template< typename MemoryManagerType >
template< Concepts::UnsignedInteger UnsignedIntegerType >
EnsureRetrunValueIsUsed inline LargestUnsignedInteger StringImplementation< MemoryManagerType >::IntegerToString( Character* const destinationStringPointer, const UnsignedIntegerType integer )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertPointerIsNotNull( destinationStringPointer );

    // Check if the integer value is 0
    if ( integer == 0 )
    {
        // The integer value is 0

        // Set the first entry with the ascii value for 0
        destinationStringPointer[0] = '0';

        // Nothing else needs to be done, return that only one character was needed to store the string
        return ( 1UL );
    }

    // This object will store the number digits in the integer
    LargestUnsignedInteger numberOfDigitsInInteger = NumberOfDigits< UnsignedIntegerType >( integer );

    // Store a copy of the integer
    UnsignedIntegerType integerCopy = integer;

    // Loop on all the digits of the integer
    for ( LargestUnsignedInteger index = ( numberOfDigitsInInteger - 1UL ) ; integerCopy != 0 ; --index )
    {
        // Set the string with the current digit by adding '0' to make it the ascii value
        destinationStringPointer[ index ] = static_cast< AsciiCharacter >( static_cast< AsciiCharacter >( integerCopy % 10 ) + '0' );

        // Divide the integer by 10
        integerCopy /= 10;
    }

    // Return the number of character needed to store the integer
    return ( numberOfDigitsInInteger );
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



template< typename MemoryManagerType >
template< Concepts::ConvertibleToString... ConvertibleToStringTypes >
EnsureRetrunValueIsUsed inline LargestUnsignedInteger StringImplementation< MemoryManagerType >::CalculateFormattedStringSize__Private( const SelfType& format, const ConvertibleToStringTypes&... argumentsToFormat )
{
	// For each argument that needs to be converted to string and put in the format, there are 2 characters in the format '{}'. Therefore, for each
	// argument 2 needs to be taken from the format size
	const LargestUnsignedInteger formatSize = format.Size() - ( sizeof...( argumentsToFormat ) * 2UL );

	// Calculate the required size to store the argument converted to string, sum all the components and return the result
	return ( formatSize + CalculateSizeRequiredToStoreArgumentsAsString__Private< ConvertibleToStringTypes... >( argumentsToFormat... ) );
}


template< typename MemoryManagerType >
template< Concepts::ConvertibleToString FirstExposedConvertibleToStringType, Concepts::ConvertibleToString SecondExposedConvertibleToStringType, Concepts::ConvertibleToString... RestOfConvertibleToStringTypes >
EnsureRetrunValueIsUsed inline LargestUnsignedInteger StringImplementation< MemoryManagerType >::CalculateSizeRequiredToStoreArgumentsAsString__Private( const FirstExposedConvertibleToStringType& firstArgumentToFormat, const SecondExposedConvertibleToStringType& secondArgumentToFormat, const RestOfConvertibleToStringTypes&... restOfArgumentsToFormat )
{
	// Calculate the required size to store the argument converted to string, sum all the components and return the result
	return ( CalculateSizeRequiredToStoreAsString__Private< FirstExposedConvertibleToStringType >( firstArgumentToFormat ) + CalculateSizeRequiredToStoreArgumentsAsString__Private< SecondExposedConvertibleToStringType, RestOfConvertibleToStringTypes... >( secondArgumentToFormat, restOfArgumentsToFormat... ) );
}


template< typename MemoryManagerType >
template< Concepts::ConvertibleToString ExposedConvertibleToStringType >
EnsureRetrunValueIsUsed inline LargestUnsignedInteger StringImplementation< MemoryManagerType >::CalculateSizeRequiredToStoreArgumentsAsString__Private( const ExposedConvertibleToStringType& argumentToFormat )
{
	// Calculate the required size to store the argument converted to string, sum all the components and return the result
	return ( CalculateSizeRequiredToStoreAsString__Private< ExposedConvertibleToStringType >( argumentToFormat ) );
}


template< typename MemoryManagerType >
template< Concepts::Integer IntegerType >
EnsureRetrunValueIsUsed inline LargestUnsignedInteger StringImplementation< MemoryManagerType >::CalculateSizeRequiredToStoreAsString__Private( const IntegerType integer )
{
	// Calculate the required size to store the argument converted to string and return the result
	return ( NumberOfDigits< IntegerType >( integer ) );
}


template< typename MemoryManagerType >
template< Concepts::FloatingPoint FloatingPointType >
EnsureRetrunValueIsUsed inline LargestUnsignedInteger StringImplementation< MemoryManagerType >::CalculateSizeRequiredToStoreAsString__Private( const FloatingPointType floatingPoint )
{
	// Calculate the required size to store the argument converted to string and return the result
	return ( 6UL );
}


template< typename MemoryManagerType >
template< Concepts::Pointer PointerType >
EnsureRetrunValueIsUsed inline LargestUnsignedInteger StringImplementation< MemoryManagerType >::CalculateSizeRequiredToStoreAsString__Private( const PointerType pointer )
{
	// Calculate the required size to store the argument converted to string and return the result
	return ( NumberOfDigits< LargestUnsignedInteger >( *reinterpret_cast< const LargestUnsignedInteger* >( &pointer ) ) );
}


template< typename MemoryManagerType >
template< Concepts::ConvertibleToStringObject ConvertibleToStringObjectType >
EnsureRetrunValueIsUsed inline LargestUnsignedInteger StringImplementation< MemoryManagerType >::CalculateSizeRequiredToStoreAsString__Private( const ConvertibleToStringObjectType& instance )
{
	// Calculate the required size to store the argument converted to string and return the result
	return ( instance.NumberOfCharactersRequiredToStoreAsString() );
}


template< typename MemoryManagerType >
template< typename CharacterType > requires ( Concepts::SameAs< CharacterType, Character > )
EnsureRetrunValueIsUsed inline LargestUnsignedInteger StringImplementation< MemoryManagerType >::CalculateSizeRequiredToStoreAsString__Private( const Character& )
{
	// A charcter only requires one entry to be stored
	return ( 1UL );
}


template< typename MemoryManagerType >
template< Concepts::ConvertibleToString FirstExposedConvertibleToStringType, Concepts::ConvertibleToString SecondExposedConvertibleToStringType, Concepts::ConvertibleToString... RestOfConvertibleToStringTypes >
inline void StringImplementation< MemoryManagerType >::ConvertArgumentToStringAndStoreIt__Private( const SelfType& format, LargestUnsignedInteger& formatIndex, LargestUnsignedInteger& stringIndex, const FirstExposedConvertibleToStringType& firstArgumentToFormat, const SecondExposedConvertibleToStringType& secondArgumentToFormat, const RestOfConvertibleToStringTypes&... restOfArgumentsToFormat )
{
	// Loop on the format until the next 2 characters in the format are '{' and '}' which means the next argument needs to be converted to
	// string and stored here instead of "{}"
	while ( ( format[ formatIndex ] != '{' ) && ( format[ formatIndex + 1UL ] != '}' ) )
	{
		// This check comes the verify that the amount of "{}" arguments that needs to be set in the format, match the amount of arguments
		// passed to the function. If there are more "{}" in the format an exception will be thrown
		AssertValueIsBelowCertainLimit( formatIndex, ( format.Size() - 1UL ) );

		// Store the current character from the format into the formatted string
		SelfSequentialDataStructureType::operator[]( stringIndex ) = format[ formatIndex ];

		// Increment the format index by 1
		formatIndex += 1UL;

		// Increment the string index by 1
		stringIndex += 1UL;
	}

	// Create a string from the argument and store it, and then increment the string index appropriately
	stringIndex += ConvertArgumentToStringAndStoreIt__Private< FirstExposedConvertibleToStringType >( &SelfSequentialDataStructureType::operator[]( stringIndex ), firstArgumentToFormat );

	// Increment the format index by 2
	formatIndex += 2UL;

	// Perform a recursive to expsoe the next argument to foramt
	ConvertArgumentToStringAndStoreIt__Private< SecondExposedConvertibleToStringType, RestOfConvertibleToStringTypes... >( format, formatIndex, stringIndex, secondArgumentToFormat, restOfArgumentsToFormat... );
}


template< typename MemoryManagerType >
template< Concepts::ConvertibleToString ExposedConvertibleToStringType >
inline void StringImplementation< MemoryManagerType >::ConvertArgumentToStringAndStoreIt__Private( const SelfType& format, LargestUnsignedInteger& formatIndex, LargestUnsignedInteger& stringIndex, const ExposedConvertibleToStringType& argumentToFormat )
{
	// This object will store that at least one "{}" were encountered and the argument was formatted. In other words it is another
	// way to verify that the amount of arguments is equal to the amount of "{}" in the format
	Boolean wasCurlyBracesEncountered = false;

	// Loop on the format
	while ( formatIndex < format.Size() )
	{
		// Check if the next 2 characters in the format are '{' and '}' which means the next argument as string needs to be set here
		if ( ( format[ formatIndex ] == '{' ) && ( format[ formatIndex + 1UL ] == '}' ) )
		{
			// Create a string from the argument and store it, and then increment the string index appropriately
			stringIndex += ConvertArgumentToStringAndStoreIt__Private< ExposedConvertibleToStringType >( &SelfSequentialDataStructureType::operator[]( stringIndex ), argumentToFormat );

			// Increment the format index by 2
			formatIndex += 2UL;

			// Set that curly braces exist
			wasCurlyBracesEncountered = true;
		}
		else
		{
			// Store the current character from the format into the formatted string
			SelfSequentialDataStructureType::operator[]( stringIndex ) = format[ formatIndex ];

			// Increment the format index by 1
			formatIndex += 1UL;

			// Increment the string index by 1
			stringIndex += 1UL;
		}
	}

	Assert( ( wasCurlyBracesEncountered == true ), "There are more arguments, then curly braces {} in the format" );
}


template< typename MemoryManagerType >
template< Concepts::Integer IntegerType >
inline LargestUnsignedInteger StringImplementation< MemoryManagerType >::ConvertArgumentToStringAndStoreIt__Private( Character* const destinationPoitner, const IntegerType integer )
{
	// Convert the integer into its digits and store it
	const LargestUnsignedInteger numberOfCharactersRequiredToStoreAsString = IntegerToString< IntegerType >( destinationPoitner, integer );

	// Assert that the operation was successful
	AssertValueIsLargerThenZero( numberOfCharactersRequiredToStoreAsString );

	// Return the number of characters required to store as string
	return ( numberOfCharactersRequiredToStoreAsString );
}


template< typename MemoryManagerType >
template< Concepts::FloatingPoint FloatingPointType >
inline LargestUnsignedInteger StringImplementation< MemoryManagerType >::ConvertArgumentToStringAndStoreIt__Private( Character* const destinationPoitner, const FloatingPointType floatingPoint )
{
	Assert( false, "Needs to be implemented" );

	return ( 0 );
}


template< typename MemoryManagerType >
template< Concepts::Pointer PointerType >
inline LargestUnsignedInteger StringImplementation< MemoryManagerType >::ConvertArgumentToStringAndStoreIt__Private( Character* const destinationPoitner, const PointerType pointer )
{
	// Cast the pointer to integer, and use the method to convert an integer into a string. Finally return the number of characters required to
	// store as string
	return ( ConvertArgumentToStringAndStoreIt__Private< LargestUnsignedInteger >( destinationPoitner, *reinterpret_cast< const LargestUnsignedInteger* >( &pointer ) ) );
}


template< typename MemoryManagerType >
template< Concepts::ConvertibleToStringObject ConvertibleToStringObjectType >
inline LargestUnsignedInteger StringImplementation< MemoryManagerType >::ConvertArgumentToStringAndStoreIt__Private( Character* const destinationPoitner, const ConvertibleToStringObjectType& instance )
{
	// Cast the pointer to integer, and use the method to convert an integer into a string. Finally return the number of characters required to
	// store as string
	return ( instance.SetAsString( destinationPoitner ) );
}


template< typename MemoryManagerType >
template< typename CharacterType > requires ( Concepts::SameAs< CharacterType, Character > )
inline LargestUnsignedInteger StringImplementation< MemoryManagerType >::ConvertArgumentToStringAndStoreIt__Private( Character* const destinationPoitner, const Character& character )
{
	// Store the character
	*destinationPoitner = character;

	// Return that a charcter only requires one entry to be stored
	return ( 1UL );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< typename MemoryManagerType >
	inline void StringImplementation< MemoryManagerType >::UnitTest()
	{
		const String testString_0( 134UL );
		const String expectedResultString_0( "134" );

		Assert_Test( testString_0 == expectedResultString_0 );

		const String testString_1( "{}", 134UL );
		const String expectedResultString_1( "134" );

		Assert_Test( testString_1 == expectedResultString_1 );

		const String testString_2( "{} Love", 134UL );
		const String expectedResultString_2( "134 Love" );

		Assert_Test( testString_2 == expectedResultString_2 );

		const String testString_3( "a{} Love", 134UL );
		const String expectedResultString_3( "a134 Love" );

		Assert_Test( testString_3 == expectedResultString_3 );

		// Check the error cases
		AssertExceptionWasThrown_Test( const String testString_4( "" ) );
		AssertExceptionWasThrown_Next_Test( const String testString_5( "{}a{} Love", 134UL, 145, 89999 ) );
		AssertExceptionWasThrown_Next_Test( const String testString_6( "{}a{} Love", 134UL ) );

		const String testString_7( "{}{}{}", 134UL, 134UL, 134UL );
		const String expectedResultString_7( "134134134" );

		Assert_Test( testString_7 == expectedResultString_7 );

		const UnsignedInteger64bits dummyVariable = 987UL;
		const UnsignedInteger64bits* const pointer = &dummyVariable;

		const String testString_8( "{}", pointer );
		const String testString_9( "{} I {} wANT {} LOVEE {}", 134UL, 134UL, 134UL, pointer );

		const String testString_10( "a Love" );
		const String expectedResultString_10( "a Love" );

		Assert_Test( testString_10 == expectedResultString_10 );
		
		const String testString_11( testString_10 );

		Assert_Test( testString_11 == expectedResultString_10 );

		const String testString_12( -134 );
		const String expectedResultString_12( "-134" );

		Assert_Test( testString_12 == expectedResultString_12 );

		const String testString_13( "{}", Character( 'E' ) );
		const String expectedResultString_13( "E" );

		Assert_Test( testString_13 == expectedResultString_13 );

		const String testString_14( "Love is all {} will {} get {}", Character( 'U' ), 8UL, -456 );
		const String expectedResultString_14( "Love is all U will 8 get -456" );

		Assert_Test( testString_14 == expectedResultString_14 );
	}

)  //  End of debug tool



}  //  Namespace Language


}  //  Namespace Universe