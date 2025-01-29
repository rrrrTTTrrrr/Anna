//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline Duration::Duration( const Boolean start ) :
	member_startingPointDateAndTimeStamp( start ),
	member_endingPointDateAndTimeStamp( false ),
	member_durationInSeconds( 0UL ),
	member_wasDurationInSecondsCalculated( false )
{}



inline Duration::Duration( const SelfType& other ) :
	member_startingPointDateAndTimeStamp( other.member_startingPointDateAndTimeStamp ),
	member_endingPointDateAndTimeStamp( other.member_endingPointDateAndTimeStamp ),
	member_durationInSeconds( other.member_durationInSeconds ),
	member_wasDurationInSecondsCalculated( other.member_wasDurationInSecondsCalculated )
{}


inline void Duration::Start()
{
	// Query for the current date and time stamp and store it as the starting point
	member_startingPointDateAndTimeStamp.Update();

	// Set that the duration in seconds needs to be recalculated
	member_wasDurationInSecondsCalculated = false;
}


inline void Duration::End()
{
	// Query for the current date and time stamp and store it as the ending point
	member_endingPointDateAndTimeStamp.Update();

	// Set that the duration in seconds needs to be recalculated
	member_wasDurationInSecondsCalculated = false;
}


EnsureRetrunValueIsUsed inline LargestUnsignedInteger Duration::Seconds() const
{
	// Set the number of seconds to zero
	member_durationInSeconds = 0UL;

	// Check if the start and end measurement were made in the same year
	if ( member_startingPointDateAndTimeStamp.Year() == member_endingPointDateAndTimeStamp.Year() )
	{
		// The start and end measurement were made in the same year
		CalculateNumberOfSecondsBetweenTheTwoMeasurementsWhenTheyWereMadeInTheSameYear__Private();
	}
	else
	{
		// The start and end measurement were not made in the same year
		CalculateNumberOfSecondsBetweenTheTwoMeasurementsWhenTheyWereMadeInDifferentYears__Private();
	}

	// Set that the duration in seconds was calculated
	member_wasDurationInSecondsCalculated = true;

	// Return the nubmer of seconds passed between the start and end measurement
	return ( member_durationInSeconds );
}


EnsureRetrunValueIsUsed inline LargestUnsignedInteger Duration::DidEnoughSecondsPassed( const LargestUnsignedInteger numberOfSeconds )
{
	// Query the current date and time
	End();

	// Calculate the number of seconds passed so far, and check if they are larger then the given value, and return the result
	return ( Seconds() > numberOfSeconds );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



EnsureRetrunValueIsUsed inline Boolean Duration::operator==( const SelfType& other ) const
{	
	// Check if the duration in seconds is the same for both instances
	return ( Seconds() == other.Seconds() );
}


EnsureRetrunValueIsUsed inline Boolean Duration::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}


EnsureRetrunValueIsUsed inline Boolean Duration::operator<( const SelfType& other ) const
{	
	// Check if the duration in seconds is the same for both instances
	return ( Seconds() < other.Seconds() );
}


EnsureRetrunValueIsUsed inline Boolean Duration::operator>( const SelfType& other ) const
{	
	// Check if the duration in seconds is the same for both instances
	return ( Seconds() > other.Seconds() );
}


EnsureRetrunValueIsUsed inline Boolean Duration::operator>=( const SelfType& other ) const
{	
	// Check if the duration in seconds is the same for both instances
	return ( Seconds() >= other.Seconds() );
}


EnsureRetrunValueIsUsed inline Boolean Duration::operator<=( const SelfType& other ) const
{	
	// Check if the duration in seconds is the same for both instances
	return ( Seconds() <= other.Seconds() );
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



EnsureRetrunValueIsUsed inline Boolean Duration::IsLeapYear__Private( const LargestUnsignedInteger year ) const
{
	// A leap year can be any of the following :
	//
	// 	1. A year that divides by 4 and not by 100
	//	2. A year that divides by 400

	// Check if it is a leap year, and return the result
	return ( ( ( ( year % 4UL ) == 0UL ) && ( ( year % 100UL ) != 0UL ) ) || ( ( year % 400UL ) == 0UL ) );
}


EnsureRetrunValueIsUsed inline LargestUnsignedInteger Duration::CalculateNumberOfDaysBetweenTwoMonthsInTheSameYear__Private( const UnsignedInteger8bits startingMonth, const UnsignedInteger8bits endingMonth, const UnsignedInteger16bits year ) const
{
	// This object will store the number of days
	LargestUnsignedInteger numberOfDays = 0UL;

	// Check if the months were in a leap year
	const Boolean isLeapYear = IsLeapYear__Private( year );

	// Loop on all the months between the stamps
	for ( LargestUnsignedInteger monthIndex = startingMonth ; monthIndex < endingMonth ; ++monthIndex )
	{
		// Check if the month is February and this a leap year, then February has 29 days and not 28
		if ( ( monthIndex == 1UL ) && ( isLeapYear == true ) )
		{
			// It is a leap year, and the current month is February

			// Add the amount of days in the required month
			numberOfDays += DateAndTimeInformation::numberOfDaysInFebruaryInLeapYear;
		}

		// Add the amount of days in the required month
		numberOfDays += DateAndTimeInformation::monthToNumberOfDaysMapping[ monthIndex ];
	}

	// Return the number of days
	return ( numberOfDays );
}


inline void Duration::CalculateNumberOfSecondsUntilTheEndOfTheHourOfTheStartPoint__Private() const
{
	// This object will store the number seconds until the end of the day that the start measurement was made. Initialize it with the
	// number of seconds left until the next minute
	member_durationInSeconds += DateAndTimeInformation::numberOfSecondsInMinute - member_startingPointDateAndTimeStamp.Second();

	// Subtract the mintue of the start measurement from the possible minutes in a hour and multiply it be the number of seconds in a minute
	member_durationInSeconds += ( DateAndTimeInformation::numberOfMinutesInHour - ( member_startingPointDateAndTimeStamp.Minute() + 1UL ) ) * DateAndTimeInformation::numberOfSecondsInMinute;
}


inline void Duration::CalculateNumberOfSecondsUntilTheEndOfTheDayOfTheStartPoint__Private() const
{
	// This object will store the number seconds until the end of the day that the start measurement was made. Initialize it with the
	// number of seconds left until the next minute
	CalculateNumberOfSecondsUntilTheEndOfTheHourOfTheStartPoint__Private();

	// Subtract the hour of the start measurement from the possible hours in a day and multiply it be the number of seconds in an hour
	member_durationInSeconds += ( DateAndTimeInformation::numberOfHoursInDay - ( member_startingPointDateAndTimeStamp.Hour() + 1UL ) ) * DateAndTimeInformation::numberOfSecondsInHour;
}


inline void Duration::CalculateNumberOfSecondsUntilTheEndOfTheMonthOfTheStartPoint__Private() const
{
	// This object will store the number seconds until the end of the month that the start measurement was made. Initialize it with the
	// number of seconds left until the next minute
	CalculateNumberOfSecondsUntilTheEndOfTheDayOfTheStartPoint__Private();

	// Check if the day of the start measurement is the last of the month
	if ( member_startingPointDateAndTimeStamp.DayOfMonth() != DateAndTimeInformation::monthToNumberOfDaysMapping[ member_startingPointDateAndTimeStamp.DayOfMonth() ] )
	{
		// The day of the start measurement is not the last of the month

		// Subtract the day of the start measurement from the possible days in that month and multiply it be the number of seconds in a month
		member_durationInSeconds += ( DateAndTimeInformation::monthToNumberOfDaysMapping[ member_startingPointDateAndTimeStamp.DayOfMonth() ] - ( member_startingPointDateAndTimeStamp.DayOfMonth() + 1UL ) ) * DateAndTimeInformation::numberOfSecondsInDay;
	}
}


inline void Duration::CalculateNumberOfSecondsPassedInTheHourOfTheEndPoint__Private() const
{
	// This object will store the number seconds passed in the year that the ending measurement was made. Initialize it with the
	// number of seconds
	member_durationInSeconds += member_endingPointDateAndTimeStamp.Second();

	// Add the number of minutes multiplied by the number of seconds in a minute
	member_durationInSeconds += DateAndTimeInformation::numberOfSecondsInMinute * member_endingPointDateAndTimeStamp.Minute();
}


inline void Duration::CalculateNumberOfSecondsPassedInTheDayOfTheEndPoint__Private() const
{
	// This object will store the number seconds passed in the year that the ending measurement was made. Initialize it with the
	// number of seconds
	CalculateNumberOfSecondsPassedInTheHourOfTheEndPoint__Private();

	// Add the number of hours multiplied by the number of seconds in an hour
	member_durationInSeconds += DateAndTimeInformation::numberOfSecondsInHour * member_endingPointDateAndTimeStamp.Hour();
}


inline void Duration::CalculateNumberOfSecondsPassedInTheMonthOfTheEndPoint__Private() const
{
	// This object will store the number seconds passed in the year that the ending measurement was made. Initialize it with the
	// number of seconds
	CalculateNumberOfSecondsPassedInTheDayOfTheEndPoint__Private();

	// Check if the day of the ending measurement is the first of the month
	if ( member_endingPointDateAndTimeStamp.DayOfMonth() != 1U )
	{
		// The day of the end measurement is not the first of the month

		// Add the number of days multiplied by the number of seconds in a day
		member_durationInSeconds += DateAndTimeInformation::numberOfSecondsInDay * member_endingPointDateAndTimeStamp.DayOfMonth();
	}
}


inline void Duration::CalculateNumberOfSecondsBetweenTheTwoMeasurementsWhenTheyWereMadeInDifferentYears__Private() const
{
	// Calculate the number of seconds until the end of the start measurement year
	CalculateNumberOfSecondsUntilTheEndOfTheYearTheStartPointWasMade__Private();

	// Calculate the number of seconds passed in the year of the end measurement
	CalculateNumberOfSecondsPassedInTheYearTheEndPointWasMade__Private();

	// Check if the start measurement was made in the year previous to the end measurement
	if ( ( member_startingPointDateAndTimeStamp.Year() + 1U ) != member_endingPointDateAndTimeStamp.Year() )
	{
		// The start measurement was made in the year previous to the end measurement
		CalculateNumberOfSecondsInTheFullYearsBetweenTheStartAndEndPoint__Private();
	}
}



inline void Duration::CalculateNumberOfSecondsUntilTheEndOfTheYearTheStartPointWasMade__Private() const
{
	// This object will store the number seconds until the end of the year that the start measurement was made. Initialize it with the
	// number of seconds left until the next minute
	CalculateNumberOfSecondsUntilTheEndOfTheMonthOfTheStartPoint__Private();

	// Check if the month of the start measurement is December, the last one
	if ( member_startingPointDateAndTimeStamp.Month() != 11U )
	{
		// The month of the start measurement is not December

		// Calculate the number of days passed in the full months
		const LargestUnsignedInteger numberOfDaysPassedInTheFullMonths = CalculateNumberOfDaysBetweenTwoMonthsInTheSameYear__Private( member_startingPointDateAndTimeStamp.Month() + 1U, 12U, member_startingPointDateAndTimeStamp.Year() );

		// Add the number of seconds spent in the full months
		member_durationInSeconds += numberOfDaysPassedInTheFullMonths * DateAndTimeInformation::numberOfSecondsInDay;
	}
}


inline void Duration::CalculateNumberOfSecondsPassedInTheYearTheEndPointWasMade__Private() const
{
	// This object will store the number seconds passed in the year that the ending measurement was made. Initialize it with the
	// number of seconds
	CalculateNumberOfSecondsPassedInTheMonthOfTheEndPoint__Private();

	// Check if the month of the end measurement is January, the first one
	if ( member_endingPointDateAndTimeStamp.Month() != 0U )
	{
		// The month of the end measurement is not January

		// Calculate the number of days passed in the full months
		const LargestUnsignedInteger numberOfDaysPassedInTheFullMonths = CalculateNumberOfDaysBetweenTwoMonthsInTheSameYear__Private( 0U, member_endingPointDateAndTimeStamp.Month(), member_endingPointDateAndTimeStamp.Year() );

		// Add the number of seconds spent in the full months
		member_durationInSeconds += numberOfDaysPassedInTheFullMonths * DateAndTimeInformation::numberOfSecondsInDay;
	}
}


inline void Duration::CalculateNumberOfSecondsInTheFullYearsBetweenTheStartAndEndPoint__Private() const
{
	// Loop on all the months until the end of the year
	for ( LargestUnsignedInteger year = member_startingPointDateAndTimeStamp.Year() + 1UL ; year < member_endingPointDateAndTimeStamp.Year() ; ++year )
	{
		// Check if this is a leap year
		if ( IsLeapYear__Private( year ) == true )
		{
			// It is a leap year, it means that there is 366 days instead of 365

			// Add the number of seconds in a the current year
			member_durationInSeconds += ( DateAndTimeInformation::numberOfDaysInYear + 1UL ) * DateAndTimeInformation::numberOfSecondsInDay;
		}
		else
		{
			// Add the number of seconds in a the current year
			member_durationInSeconds += DateAndTimeInformation::numberOfDaysInYear * DateAndTimeInformation::numberOfSecondsInDay;
		}
	}
}



}  //  Namespace Universe