//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline Character::Character( const UnsignedInteger32bits character ) :
	member_character( AssignOnlyIfValueIsBelowCertainLimit( character, 1114111U ) )
{}


inline Character::Character( const AsciiCharacter asciiCharacter ) :
	member_character( AssignOnlyIfValueIsWithinRange( static_cast< UnsignedInteger32bits >( asciiCharacter ), static_cast< AsciiCharacter >( 1 ), static_cast< AsciiCharacter >( 127 ) ) )
{}


inline Character::Character( const SelfType& other ) :
	member_character( other.member_character )
{}


inline Boolean Character::IsAsciiCharacter() const
{
	// Check if the current value is within the ascii characters range of [0-127], and return the result
	return ( member_character < 128U );
}


inline AsciiCharacter Character::GetAsAsciiCharacter() const
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	Assert( ( IsAsciiCharacter() == true ), "The value does not represent an ascii character" );

	// Cast the 32 bits character to one byte ascii character, and return the result
	return ( static_cast< AsciiCharacter >( member_character ) );
}


inline Boolean Character::IsDigit() const
{
	// Check if the current ascii character value represent a digit, and return the result
	//
	//		'0' - 48 Decimal
	//		'9' - 57 Decimal
	//
	return ( ( member_character >= '0' ) && ( member_character <= '9' ) );
}


inline Boolean Character::IsEnglishCapitalLetter() const
{
	// Check if the current ascii character value represent an English alphabet letter in the capital form, and return the result
	//
	//		Capital A - 65 Decimal
	//		Capital Z - 90 Decimal
	//
	return ( ( member_character >= 'A' ) && ( member_character <= 'Z' ) );
}


inline Boolean Character::IsEnglishSmallLetter() const
{
	// Check if the current ascii character value represent an English alphabet letter in the small form, and return the result
	//
	//		Small a - 97 Decimal
	//		Small z - 122 Decimal
	//
	return ( ( member_character >= 'a' ) && ( member_character <= 'z' ) );
}


inline Boolean Character::IsEnglishLetter() const
{
	// Check if the current value represent one of the English alphabet letters, and return the result. The English alphabet letters has the following
	// values :
	//
	//		Capital A - 65 Decimal
	//		Capital Z - 90 Decimal
	//
	//		Small a - 97 Decimal
	//		Small z - 122 Decimal
	//
	return ( IsEnglishCapitalLetter() || IsEnglishSmallLetter() );		
}


inline void Character::ConvertToEnglishCapitalLetter()
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	Assert( ( IsEnglishLetter() == true ), "The current character value does not represent an English alphabet letter" );

	// Check if the current English alphabet letter is in the capital or small form, if it is in the capital form then there is nothing to do
	if ( IsEnglishSmallLetter() == true )
	{
		// The current English alphabet letter is in the small form

		// Subtract 32 from the current value, to convert the small form into the capital form of the letter
		member_character -= 32U;
	}		
}


inline void Character::ConvertToEnglishSmallLetter()
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	Assert( ( IsEnglishLetter() == true ), "The current ascii character value does not represent an English alphabet letter" );

	// Check if the current English alphabet letter is in the capital or small form, if it is in the small form then there is nothing to do
	if ( IsEnglishCapitalLetter() == true )
	{
		// The current English alphabet letter is in the capital form

		// Add 32 to the current value, to convert the capital form into the small form of the letter
		member_character += 32U;
	}
}


inline UnsignedInteger32bits* Character::GetMemoryAddressOfUnsignedIntegerThatRepresentsTheCharacter()
{
	// Return the memory addres of the unsigned integer inside this instance
	return ( &member_character );
}


inline const UnsignedInteger32bits* Character::GetMemoryAddressOfUnsignedIntegerThatRepresentsTheCharacter() const
{
	// Return the memory addres of the unsigned integer inside this instance
	return ( &member_character );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



inline Boolean Character::operator==( const SelfType& other ) const
{
	// Compare the characters, and return the result
	return ( member_character == other.member_character );
}


inline Boolean Character::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}


inline void Character::operator=( const AsciiCharacter asciiCharacter )
{
	// Set the value
	member_character = static_cast< UnsignedInteger32bits >( asciiCharacter );
}



//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



inline Character Character::Minimum()
{
	// Create an instance that represents the minimum of the object. In this object the minimum possible valid value is 1
	return ( Character( 1U ) );
}


inline Character Character::Maximum()
{
	// Create an instance that represents the maximum of the object. In this object the maximum possible valid value is 1114111
	return ( Character( 1114110U ) );
}




}  //  Namespace Language


}  //  Namespace Universe