//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline DateAndTimeStamp::DateAndTimeStamp( const Boolean initializeDataAndTime ) :
	DateStamp( initializeDataAndTime ),
	TimeStamp( initializeDataAndTime )
{}


inline DateAndTimeStamp::DateAndTimeStamp( const SelfType& other ) :
	DateStamp( other ),
	TimeStamp( other )
{}


inline void DateAndTimeStamp::Update()
{
	// Use the real time clock to collect the date information, and validate that the date is reasonable
	UpdateDate();
	
	// Use the real time clock to collect the time information, and validate that the time is reasonable
	UpdateTime();
}


EnsureRetrunValueIsUsed inline Language::String DateAndTimeStamp::ToString( const Language::Character& dateStampDelimiter, const Language::Character& timeStampDelimiter, const Language::Character& dateAndTimeStampsSeperatorDelimiter ) const
{
	// Format the date and time and return the result
	return ( Language::String( "{}{}{}{}{}{}{}{}{}{}{}", DayOfMonth(), dateStampDelimiter, Month(), dateStampDelimiter, Year(), dateAndTimeStampsSeperatorDelimiter, Hour(), timeStampDelimiter, Minute(), timeStampDelimiter, Second() ) );
}


EnsureRetrunValueIsUsed inline LargestUnsignedInteger DateAndTimeStamp::NumberOfCharactersRequiredToStoreAsString() const
{
	// Start from 1, for the delimiter between the date and time, and then calculate the number of digits required and return the result
	return ( 1UL + DateStamp::NumberOfCharactersRequiredToStoreAsString() + TimeStamp::NumberOfCharactersRequiredToStoreAsString() );
}


EnsureRetrunValueIsUsed inline LargestUnsignedInteger DateAndTimeStamp::SetAsString( Language::Character* const stringPointer, const Language::Character& dateStampDelimiter, const Language::Character& timeStampDelimiter, const Language::Character& dateAndTimeStampsSeperatorDelimiter ) const
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertPointerIsNotNull( stringPointer );

	// This object will store the offset on the string where to store the next part
	LargestUnsignedInteger offset = 0UL;

	// Set the date
	offset = DateStamp::SetAsString( stringPointer, dateStampDelimiter );

	// Set the seperator delimiter between the date and time
	stringPointer[ offset ] = dateAndTimeStampsSeperatorDelimiter;

	// Increment the offset by one, to advance to the location where the month will be set
	offset += 1UL;

	// Set the time
	offset = TimeStamp::SetAsString( stringPointer + offset, timeStampDelimiter );

	// Return the number of characters required to store the instance as a string
	return ( offset );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



inline Boolean DateAndTimeStamp::operator==( const SelfType& other ) const
{
	// Check if the date and time stamps in both instance are identical and return the result
	return ( DateStamp::operator==( other ) && TimeStamp::operator==( other ) );
}


inline Boolean DateAndTimeStamp::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}


inline Boolean DateAndTimeStamp::operator>( const SelfType& other ) const
{
	// Check if the date stamp in this instance is larger then in the other instance, then return true
	ReturnValueIfExpressionIsTrue( ( DateStamp::operator>( other ) == true ), true );

	// Check if the date stamp in the other instance is larger then in this instance, then return false
	ReturnValueIfExpressionIsTrue( ( DateStamp::operator<( other ) == true ), false );

	// The date stamp in both instances is identical

	// Check if the time stamp in this instance is larger then in the other instance, then return true
	ReturnValueIfExpressionIsTrue( ( TimeStamp::operator>( other ) == true ), true );

	// Check if the time stamp in the other instance is larger then in this instance, then return false
	ReturnValueIfExpressionIsTrue( ( TimeStamp::operator<( other ) == true ), false );

	// The date and time stamps in both instance are identical, return false
	return ( false );
}


inline Boolean DateAndTimeStamp::operator<( const SelfType& other ) const
{
	// Return the negotiated value from the is larger operator
	return ( !( *this > other ) );
}


inline Boolean DateAndTimeStamp::operator>=( const SelfType& other ) const
{
	// Check if the date stamp in this instance is larger then in the other instance, then return true
	ReturnValueIfExpressionIsTrue( ( DateStamp::operator>( other ) == true ), true );

	// Check if the date stamp in the other instance is larger then in this instance, then return false
	ReturnValueIfExpressionIsTrue( ( DateStamp::operator<( other ) == true ), false );

	// The date stamp in both instances is identical

	// Check if the time stamp in this instance is larger then in the other instance, then return true
	ReturnValueIfExpressionIsTrue( ( TimeStamp::operator>( other ) == true ), true );

	// Check if the time stamp in the other instance is larger then in this instance, then return false
	ReturnValueIfExpressionIsTrue( ( TimeStamp::operator<( other ) == true ), false );

	// The date and time stamps in both instance are identical, return false
	return ( true );
}


inline Boolean DateAndTimeStamp::operator<=( const SelfType& other ) const
{
	// Return the negotiated value from the is larger or equal operator
	return ( !( *this >= other ) );
}



// *********************************************************************************   TESTING   ********************************************************************************



//DEBUG_TOOL(

	inline void DateAndTimeStamp::UnitTest()
	{
		DateAndTimeStamp testDateAndTimeStamp_0;

		testDateAndTimeStamp_0.UpdateTime();
		testDateAndTimeStamp_0.UpdateDate();
		testDateAndTimeStamp_0.Update();

		DateAndTimeStamp testDateAndTimeStamp_1;

		testDateAndTimeStamp_1.Update();

		const Language::String timeStampString_0 = TakeResourcesAndLeaveInstanceInDefaultState( testDateAndTimeStamp_1.ToString() );

		Assert_Test( timeStampString_0.Size() == testDateAndTimeStamp_1.NumberOfCharactersRequiredToStoreAsString() );

		Language::String memoryToStoreDataAndTimeStampAsString( testDateAndTimeStamp_1.NumberOfCharactersRequiredToStoreAsString() );

		Assert_Test( testDateAndTimeStamp_1.SetAsString( memoryToStoreDataAndTimeStampAsString.DataPointer() ) == testDateAndTimeStamp_1.NumberOfCharactersRequiredToStoreAsString() );

		for ( UnsignedInteger64bits index = 0UL ; index < timeStampString_0.Size() ; ++index )
		{
			Assert_Test( timeStampString_0[ index ] == memoryToStoreDataAndTimeStampAsString[ index ] );
		}
	}

//)  //  End of debug tool




}  //  Namespace Universe