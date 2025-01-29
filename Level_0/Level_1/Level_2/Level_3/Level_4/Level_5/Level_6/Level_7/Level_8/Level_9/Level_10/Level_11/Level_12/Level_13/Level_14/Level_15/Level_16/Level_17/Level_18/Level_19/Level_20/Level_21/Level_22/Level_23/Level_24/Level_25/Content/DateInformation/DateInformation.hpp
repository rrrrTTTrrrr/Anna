namespace Universe
{


namespace DateAndTimeInformation
{



// This lookup table will be used to convert from the month index to the number of days it has
static constexpr LargestUnsignedInteger monthToNumberOfDaysMapping[12] = {31UL, 28UL, 31UL, 30UL, 31UL, 30UL, 31UL, 31UL, 30UL, 31UL, 30UL, 31UL};

// This lookup table will be used to convert from the month index to the name of the month
//static const AsciiCharacter* monthToStringMapping[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

// This object will store the number of days in the month February for leap years
static constexpr LargestUnsignedInteger numberOfDaysInFebruaryInLeapYear = 29UL;


// This object will store the number of seconds in a minute
static constexpr LargestUnsignedInteger numberOfSecondsInMinute = 60UL;

// This object will store the number of seconds in an hour
static constexpr LargestUnsignedInteger numberOfSecondsInHour = 60UL * 60UL;

// This object will store the number of seconds in a day
static constexpr LargestUnsignedInteger numberOfSecondsInDay = 24UL * 60UL * 60UL;



// This object will store the number of minutes in an hour
static constexpr LargestUnsignedInteger numberOfMinutesInHour = 60UL;

// This object will store the number of minutes in a day
static constexpr LargestUnsignedInteger numberOfMinutesInDay = 24UL * 60UL;


// This object will store the number of hours in a day
static constexpr LargestUnsignedInteger numberOfHoursInDay = 24UL;


// This object will store the number of hours in a day
static constexpr LargestUnsignedInteger numberOfDaysInYear = 365UL;



}  //  Namespace DateAndTimeInformation


}  //  Namespace Universe