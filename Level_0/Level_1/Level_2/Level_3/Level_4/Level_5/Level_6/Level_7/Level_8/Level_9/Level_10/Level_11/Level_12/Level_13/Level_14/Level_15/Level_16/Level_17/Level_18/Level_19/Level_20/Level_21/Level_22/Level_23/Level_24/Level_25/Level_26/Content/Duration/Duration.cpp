namespace Universe 
{



//	********************************************************************   PRIVATE METHODS IMPLEMENTATION   *********************************************************************



void Duration::CalculateNumberOfSecondsBetweenTheTwoMeasurementsWhenTheyWereMadeInTheSameYear__Private() const
{
	// Check if the start and end measurement were made in the same month
	if ( member_startingPointDateAndTimeStamp.Month() != member_endingPointDateAndTimeStamp.Month() )
	{
		// The start and end measurement were not made in the same month

		// Add the number of seconds until the end of the month of the start measurement
		CalculateNumberOfSecondsUntilTheEndOfTheMonthOfTheStartPoint__Private();

		// Calculate the number of days passed in the full months
		const LargestUnsignedInteger numberOfDaysPassedInTheFullMonths = CalculateNumberOfDaysBetweenTwoMonthsInTheSameYear__Private( member_startingPointDateAndTimeStamp.Month() + 1U, member_endingPointDateAndTimeStamp.Month(), member_startingPointDateAndTimeStamp.Year() );

		// Add the number of seconds spent in the full months
		member_durationInSeconds += numberOfDaysPassedInTheFullMonths * DateAndTimeInformation::numberOfSecondsInDay;

		// Add the number of seconds passed in the month of the end measurement
		CalculateNumberOfSecondsPassedInTheMonthOfTheEndPoint__Private();
	}

	// The start and end measurement were made in the same month

	// Check if the start and end measurement were made in the same day
	else if ( member_startingPointDateAndTimeStamp.DayOfMonth() != member_endingPointDateAndTimeStamp.DayOfMonth() )
	{
		// The start and end measurement were not made in the same day

		// Add the number of seconds until the end of the day of the start measurement
		CalculateNumberOfSecondsUntilTheEndOfTheDayOfTheStartPoint__Private();

		// Add the number of seconds spent in the full days
		member_durationInSeconds += ( member_endingPointDateAndTimeStamp.DayOfMonth() - member_startingPointDateAndTimeStamp.DayOfMonth() ) * DateAndTimeInformation::numberOfSecondsInDay;

		// Add the number of seconds passed in the day of the end measurement
		CalculateNumberOfSecondsPassedInTheDayOfTheEndPoint__Private();
	}

	// The start and end measurement were made in the same day

	// Check if the start and end measurement were made in the same hour
	else if ( member_startingPointDateAndTimeStamp.Hour() != member_endingPointDateAndTimeStamp.Hour() )
	{
		// The start and end measurement were not made in the same hour

		// Add the number of seconds until the end of the day of the start measurement
		CalculateNumberOfSecondsUntilTheEndOfTheHourOfTheStartPoint__Private();

		// Add the number of seconds spent in the full days
		member_durationInSeconds += ( member_endingPointDateAndTimeStamp.DayOfMonth() - member_startingPointDateAndTimeStamp.DayOfMonth() ) * DateAndTimeInformation::numberOfSecondsInDay;

		// Add the number of seconds passed in the day of the end measurement
		CalculateNumberOfSecondsPassedInTheHourOfTheEndPoint__Private();
	}

	// The start and end measurement were made in the same hour

	// Check if the start and end measurement were made in the same minute
	else if ( member_startingPointDateAndTimeStamp.Minute() != member_endingPointDateAndTimeStamp.Minute() )
	{
		// The start and end measurement were not made in the same minute

		// Add the number of seconds until the end of the minute the start measurement was made from
		member_durationInSeconds += DateAndTimeInformation::numberOfSecondsInMinute - member_startingPointDateAndTimeStamp.Second();

		// Add the number of seconds in the full minutes
		member_durationInSeconds += DateAndTimeInformation::numberOfSecondsInMinute * ( member_endingPointDateAndTimeStamp.Minute() - ( member_startingPointDateAndTimeStamp.Minute() + 1U ) );

		// Add the number of seconds passed in the minute the end measurement was made from
		member_durationInSeconds += member_endingPointDateAndTimeStamp.Second();
	}

	// The start and end measurement were made in the same minute

	else
	{
		// Subtract the number of seconds measured in start from the end and store the result
		member_durationInSeconds += static_cast< LargestUnsignedInteger >( member_endingPointDateAndTimeStamp.Second() - member_startingPointDateAndTimeStamp.Second() );
	}
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	void Duration::UnitTest()
	{
		Duration testDuration;

		testDuration.End();

		while ( testDuration.DidEnoughSecondsPassed( 3 ) == false )
		{
			std::cout << testDuration.Seconds() << std::endl;
		}

	}

)  //  End of debug tool



}  //  Namespace Universe
