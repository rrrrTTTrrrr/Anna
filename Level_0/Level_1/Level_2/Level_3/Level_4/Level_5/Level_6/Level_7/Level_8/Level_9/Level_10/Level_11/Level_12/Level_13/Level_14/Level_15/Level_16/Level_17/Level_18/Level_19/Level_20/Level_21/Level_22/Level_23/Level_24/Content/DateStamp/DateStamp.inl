//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline DateStamp::DateStamp( const Boolean initializeDate ) :
	member_dayOfMonth( 0 ),
	member_month( 0 ),
	member_year( 0 )
{
	// Check if the date needs to be initialized
	if ( initializeDate == true )
	{
		// Use the real time clock to collect the date information, and validate that the date is reasonable
		CollectDateFromRealTimeClockHardwareDevice__Private();
	}
}


inline DateStamp::DateStamp( const SelfType& other ) :
	member_dayOfMonth( other.member_dayOfMonth ),
	member_month( other.member_month ),
	member_year( other.member_year )
{}


inline void DateStamp::UpdateDate()
{
	// Use the real time clock to collect the date information, and validate that the date is reasonable
	CollectDateFromRealTimeClockHardwareDevice__Private();
}


EnsureRetrunValueIsUsed inline Language::String DateStamp::ToString( const Language::Character& delimiter ) const
{
	// Format the date and return the result
	return ( Language::String( "{}{}{}{}{}", member_dayOfMonth, delimiter, member_month, delimiter, member_year ) );
}


EnsureRetrunValueIsUsed inline LargestUnsignedInteger DateStamp::NumberOfCharactersRequiredToStoreAsString() const
{
	// Start from 2, for the delimiters, and then calculate the number of digits required for the day of month, month and year, 
	// finally return the result
	return ( 2UL + Language::String::NumberOfDigits< UnsignedInteger8bits >( member_dayOfMonth ) + Language::String::NumberOfDigits< UnsignedInteger8bits >( member_month ) + Language::String::NumberOfDigits< UnsignedInteger16bits >( member_year ) );
}


EnsureRetrunValueIsUsed inline LargestUnsignedInteger DateStamp::SetAsString( Language::Character* const stringPointer, const Language::Character& delimiter ) const
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertPointerIsNotNull( stringPointer );

	// This object will store the offset on the string where to store the next part
	LargestUnsignedInteger offset = 0UL;

	// Set the day of month
	offset = Language::String::IntegerToString< UnsignedInteger8bits >( stringPointer, member_dayOfMonth );

	// Set the delimiter between the day of month and month
	stringPointer[ offset ] = delimiter;

	// Increment the offset by one, to advance to the location where the month will be set
	offset += 1UL;

	// Set the month
	offset += Language::String::IntegerToString< UnsignedInteger8bits >( stringPointer + offset, member_month );

	// Set the delimiter between the month and the year
	stringPointer[ offset ] = delimiter;

	// Increment the offset by one, to advance to the location where the year will be set
	offset += 1UL;	

	// Set the year
	offset += Language::String::IntegerToString< UnsignedInteger16bits >( stringPointer + offset, member_year );

	// Return the number of characters required to store the instance as a string
	return ( offset );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



inline Boolean DateStamp::operator==( const SelfType& other ) const
{
	// Compare the century, year, month and day of month and return the result
	return ( ( member_dayOfMonth == other.member_dayOfMonth ) && ( member_month == other.member_month ) && ( member_year == other.member_year ) );
}


inline Boolean DateStamp::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}


inline Boolean DateStamp::operator>( const SelfType& other ) const
{
	// Check if the year in the other instance is larger then the year in this instance, then return false
	ReturnValueIfExpressionIsTrue( ( other.member_year > member_year ), false );

	// Check if the year in this instance is larger then the year in the other instance, then return true
	ReturnValueIfExpressionIsTrue( ( member_year > other.member_year ), true );

	// The year in both instances is the same

	// Check if the month in the other instance is larger then the month in this instance, then return false
	ReturnValueIfExpressionIsTrue( ( other.member_month > member_month ), false );

	// Check if the month in this instance is larger then the month in the other instance, then return true
	ReturnValueIfExpressionIsTrue( ( member_month > other.member_month ), true );

	// The month in both instances is the same

	// Check if the day of month in the other instance is larger then the day of month in this instance, then return false
	ReturnValueIfExpressionIsTrue( ( other.member_dayOfMonth > member_dayOfMonth ), false );

	// Check if the day of month in this instance is larger then the day of month in the other instance, then return true
	ReturnValueIfExpressionIsTrue( ( member_dayOfMonth > other.member_dayOfMonth ), true );

	// The time in both instance is identical, return false
	return ( false );
}


inline Boolean DateStamp::operator<( const SelfType& other ) const
{
	// Return the negotiated value from the is larger operator
	return ( !( *this > other ) );
}


inline Boolean DateStamp::operator>=( const SelfType& other ) const
{
	// Check if the year in the other instance is larger then the year in this instance, then return false
	ReturnValueIfExpressionIsTrue( ( other.member_year > member_year ), false );

	// Check if the year in this instance is larger then the year in the other instance, then return true
	ReturnValueIfExpressionIsTrue( ( member_year > other.member_year ), true );

	// The year in both instances is the same

	// Check if the month in the other instance is larger then the month in this instance, then return false
	ReturnValueIfExpressionIsTrue( ( other.member_month > member_month ), false );

	// Check if the month in this instance is larger then the month in the other instance, then return true
	ReturnValueIfExpressionIsTrue( ( member_month > other.member_month ), true );

	// The month in both instances is the same

	// Check if the day of month in the other instance is larger then the day of month in this instance, then return false
	ReturnValueIfExpressionIsTrue( ( other.member_dayOfMonth > member_dayOfMonth ), false );

	// Check if the day of month in this instance is larger then the day of month in the other instance, then return true
	ReturnValueIfExpressionIsTrue( ( member_dayOfMonth > other.member_dayOfMonth ), true );

	// The time in both instance is identical, return true
	return ( true );
}


inline Boolean DateStamp::operator<=( const SelfType& other ) const
{
	// Return the negotiated value from the is larger or equal operator
	return ( !( *this >= other ) );
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



inline void DateStamp::CollectDateFromRealTimeClockHardwareDevice__Private()
{
	// Use the real time clock to collect the date information
	HardwareDevices::RealTimeClock::DateStamp( member_dayOfMonth, member_month, member_year );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	void DateStamp::UnitTest()
	{
		DateStamp testDateStamp_0;

		testDateStamp_0.UpdateDate();

		const Language::String dateStampString_0 = TakeResourcesAndLeaveInstanceInDefaultState( testDateStamp_0.ToString() );

		Assert_Test( dateStampString_0.Size() == testDateStamp_0.NumberOfCharactersRequiredToStoreAsString() );

		Language::String memoryToStoreDateStampAsString( testDateStamp_0.NumberOfCharactersRequiredToStoreAsString() );

		Assert_Test( testDateStamp_0.SetAsString( memoryToStoreDateStampAsString.DataPointer() ) == testDateStamp_0.NumberOfCharactersRequiredToStoreAsString() );

		for ( UnsignedInteger64bits index = 0UL ; index < dateStampString_0.Size() ; ++index )
		{
			Assert_Test( dateStampString_0[ index ] == memoryToStoreDateStampAsString[ index ] );
		}
	}

)  //  End of debug tool



}  //  Namespace Universe