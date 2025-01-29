//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline AsciiLiteral::AsciiLiteral() :
	member_asciiLiteral( nullptr ),
	member_size( 0UL )
{}


inline AsciiLiteral::AsciiLiteral( const AsciiCharacter* asciiLiteral ) :
	member_asciiLiteral( AssignOnlyIfPointerIsNotNULL( asciiLiteral ) ),
	member_size( AssignOnlyIfValueIsLargerThenZero( AsciiStringSize( asciiLiteral ) ) )
{}


inline AsciiLiteral::AsciiLiteral( const SelfType& other ) :
	member_asciiLiteral( other.member_asciiLiteral ),
	member_size( other.member_size )
{}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



inline Boolean AsciiLiteral::operator==( const SelfType& other ) const
{
	// Compare the size, and if it is different return false, to notify the user that the ascii literal are different
	ReturnValueIfExpressionIsTrue( ( member_size != other.member_size ), false );

	// Compare the ascii literals, and return the result
	return ( Memory::Operations::Compare< AsciiCharacter >( member_asciiLiteral, other.member_asciiLiteral, member_size ) );
}


inline Boolean AsciiLiteral::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}


inline const AsciiCharacter& AsciiLiteral::operator[]( UnsignedInteger64bits index ) const
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertPointerIsNotNull( member_asciiLiteral );
	AssertValueIsBelowCertainLimit( index, member_size );
	
	// Return a reference to the required ascii character
	return ( member_asciiLiteral[ index ] );
}



}  //  Namespace Universe