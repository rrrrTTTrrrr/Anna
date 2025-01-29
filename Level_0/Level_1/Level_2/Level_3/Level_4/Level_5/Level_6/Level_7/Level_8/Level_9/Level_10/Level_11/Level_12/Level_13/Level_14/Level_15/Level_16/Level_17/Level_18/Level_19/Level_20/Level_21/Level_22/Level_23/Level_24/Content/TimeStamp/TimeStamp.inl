//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline TimeStamp::TimeStamp( const Boolean initializeTime ) :
	member_second( 0 ),
	member_minute( 0 ),
	member_hour( 0 )
{
	// Check if the time needs to be initialized during construction
	if ( initializeTime == true )
	{
		// Use the real time clock to collect the time information, and validate that the time is reasonable
		CollectTimeFromRealTimeClockHardwareDevice__Private();
	}
}


inline TimeStamp::TimeStamp( const SelfType& other ) :
	member_second( other.member_second ),
	member_minute( other.member_minute ),
	member_hour( other.member_hour )
{}


inline void TimeStamp::UpdateTime()
{
	// Use the real time clock to collect the time information, and validate that the time is reasonable
	CollectTimeFromRealTimeClockHardwareDevice__Private();
}


EnsureRetrunValueIsUsed inline Language::String TimeStamp::ToString( const Language::Character& delimiter ) const
{
	// Format the time and return the result
	return ( Language::String( "{}{}{}{}{}", member_hour, delimiter, member_minute, delimiter, member_second ) );
}


EnsureRetrunValueIsUsed inline LargestUnsignedInteger TimeStamp::NumberOfCharactersRequiredToStoreAsString() const
{
	// Start from 2, for the delimiters, and then calculate the number of digits required for the hour, minute and seconds, finally return
	// the result
	return ( 2UL + Language::String::NumberOfDigits< UnsignedInteger8bits >( member_hour ) + Language::String::NumberOfDigits< UnsignedInteger8bits >( member_minute ) + Language::String::NumberOfDigits< UnsignedInteger8bits >( member_second ) );
}


EnsureRetrunValueIsUsed inline LargestUnsignedInteger TimeStamp::SetAsString( Language::Character* const stringPointer, const Language::Character& delimiter ) const
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertPointerIsNotNull( stringPointer );

	// This object will store the offset on the string where to store the next part
	LargestUnsignedInteger offset = 0UL;

	// Set the hour
	offset = Language::String::IntegerToString< UnsignedInteger8bits >( stringPointer, member_hour );

	// Set the delimiter between the hour and minute
	stringPointer[ offset ] = delimiter;

	// Increment the offset by one, to advance to the location where the minute will be set
	offset += 1UL;

	// Set the minute
	offset += Language::String::IntegerToString< UnsignedInteger8bits >( stringPointer + offset, member_minute );

	// Set the delimiter between the minute and the second
	stringPointer[ offset ] = delimiter;

	// Increment the offset by one, to advance to the location where the second will be set
	offset += 1UL;	

	// Set the second
	offset += Language::String::IntegerToString< UnsignedInteger8bits >( stringPointer + offset, member_second );

	// Return the number of characters required to store the instance as a string
	return ( offset );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



inline Boolean TimeStamp::operator==( const SelfType& other ) const
{
	// Compare the second, minute and hour and return the result
	return ( ( member_second == other.member_second ) && ( member_minute == other.member_minute ) && ( member_hour == other.member_hour ) );
}


inline Boolean TimeStamp::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}


inline Boolean TimeStamp::operator>( const SelfType& other ) const
{
	// Check if the hour in the other instance is larger then the hour in this instance, then return false
	ReturnValueIfExpressionIsTrue( ( other.member_hour > member_hour ), false );

	// Check if the hour in this instance is larger then the hour in the other instance, then return true
	ReturnValueIfExpressionIsTrue( ( member_hour > other.member_hour ), true );

	// The hour in both instances is the same

	// Check if the minute in the other instance is larger then the minute in this instance, then return false
	ReturnValueIfExpressionIsTrue( ( other.member_minute > member_minute ), false );

	// Check if the minute in this instance is larger then the minute in the other instance, then return true
	ReturnValueIfExpressionIsTrue( ( member_minute > other.member_minute ), true );

	// The minute in both instances is the same

	// Check if the second in the other instance is larger then the second in this instance, then return false
	ReturnValueIfExpressionIsTrue( ( other.member_second > member_second ), false );

	// Check if the second in this instance is larger then the second in the other instance, then return true
	ReturnValueIfExpressionIsTrue( ( member_second > other.member_second ), true );

	// The time in both instance is identical, return false
	return ( false );
}


inline Boolean TimeStamp::operator<( const SelfType& other ) const
{
	// Return the negotiated value from the is larger operator
	return ( !( *this > other ) );
}


inline Boolean TimeStamp::operator>=( const SelfType& other ) const
{
	// Check if the hour in the other instance is larger then the hour in this instance, then return false
	ReturnValueIfExpressionIsTrue( ( other.member_hour > member_hour ), false );

	// Check if the hour in this instance is larger then the hour in the other instance, then return true
	ReturnValueIfExpressionIsTrue( ( member_hour > other.member_hour ), true );

	// The hour in both instances is the same

	// Check if the minute in the other instance is larger then the minute in this instance, then return false
	ReturnValueIfExpressionIsTrue( ( other.member_minute > member_minute ), false );

	// Check if the minute in this instance is larger then the minute in the other instance, then return true
	ReturnValueIfExpressionIsTrue( ( member_minute > other.member_minute ), true );

	// The minute in both instances is the same

	// Check if the second in the other instance is larger then the second in this instance, then return false
	ReturnValueIfExpressionIsTrue( ( other.member_second > member_second ), false );

	// Check if the second in this instance is larger then the second in the other instance, then return true
	ReturnValueIfExpressionIsTrue( ( member_second > other.member_second ), true );

	// The time in both instance is identical, return true
	return ( true );
}


inline Boolean TimeStamp::operator<=( const SelfType& other ) const
{
	// Return the negotiated value from the is larger or equal operator
	return ( !( *this >= other ) );
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



inline void TimeStamp::CollectTimeFromRealTimeClockHardwareDevice__Private()
{
	// Use the real time clock to collect the time information
	HardwareDevices::RealTimeClock::TimeStamp( member_second, member_minute, member_hour );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	void TimeStamp::UnitTest()
	{
		TimeStamp testTimeStamp_0;

		testTimeStamp_0.UpdateTime();

		const Language::String timeStampString_0 = TakeResourcesAndLeaveInstanceInDefaultState( testTimeStamp_0.ToString() );

		Assert_Test( timeStampString_0.Size() == testTimeStamp_0.NumberOfCharactersRequiredToStoreAsString() );

		Language::String memoryToStoreTimeStampAsString( testTimeStamp_0.NumberOfCharactersRequiredToStoreAsString() );

		Assert_Test( testTimeStamp_0.SetAsString( memoryToStoreTimeStampAsString.DataPointer() ) == testTimeStamp_0.NumberOfCharactersRequiredToStoreAsString() );

		for ( UnsignedInteger64bits index = 0UL ; index < timeStampString_0.Size() ; ++index )
		{
			Assert_Test( timeStampString_0[ index ] == memoryToStoreTimeStampAsString[ index ] );
		}
	}

)  //  End of debug tool



}  //  Namespace Universe