namespace Universe
{



// Class Information :
//
//  Purpose :
//
//		Artifical Inteligence
//
//  Description :
//
// 		1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
//		   providing 3 keywords :
//
//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
//						member is public all the encapsulation is lost, so it should be avoided in most cases
//
//			2. Protected - this part is for developing purposes, inheritance. A developer can inherit from this object and it will
//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few
//						   data members
//
//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this
//						 part will end with the suffix __Private
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
class Duration NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = Duration;


	// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
	// the compiler generates a basic behavior for them if possible :


	// Method Information :
	//
	//  Description :
	//
	//		Default Constructor,
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			start - set true for taking the measurement of the start time stamp in the construction
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	explicit inline Duration( const Boolean start = true );


	// Method Information :
	//
	//  Description :
	//
	//		Copy constructor, will operate correctly even if the other instance is in default state or self assignment
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a reference to the instance that should be copied
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline Duration( const SelfType& other );


	// Add the following infrastructure to the object :
	//
	//		1. Assigenment operator
	//		2. Move constructor
	//		3. Move assigenment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure( Duration )


	// Method Information :
	//
	//  Description :
	//
	//		Destructor, does not throw
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline ~Duration() = default;


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to measure the date and time stamp for the starting point
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    NONE
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void Start();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to measure the date and time stamp for the ending point
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    NONE
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void End();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to calculate the number of seconds passed between the starting and ending point
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    NONE
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline LargestUnsignedInteger Seconds() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to check if a certain amount of seconds had passed. It will measure the current date and time stamp, and calculate
	//		the number of seconds passed since the starting point
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    numberOfSeconds - the required amount of seconds that needs to pass
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline LargestUnsignedInteger DidEnoughSecondsPassed( const LargestUnsignedInteger numberOfSeconds );


	// The following methods declare the overloaded operators for the object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to check if the this instance match the other
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a reference to the instance that should be compared with this object
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		1. true - if the 2 instances are the same
	//		2. false - otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed Boolean operator==( const SelfType& other ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to check if the this instance does not match the other
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a reference to the instance that should be compared with this object
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		1. true - if the 2 instances are not the same
	//		2. false - otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Boolean operator!=( const SelfType& other ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to check if the duration in this instance is smaller then in the other instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a reference to another instance
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		True if the duration in this instance is smaller then in the other instance
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Boolean operator<( const SelfType& other ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to check if the duration in this instance is larger then in the other instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a reference to another instance
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		True if the duration in this instance is larger then in the other instance
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Boolean operator>( const SelfType& other ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to check if the duration in this instance is smaller or equal to the other instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a reference to another instance
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		True if the duration in this instance is larger then in the other instance
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Boolean operator<=( const SelfType& other ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to check if the duration in this instance is larger or equal to the other instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a reference to another instance
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		True if the duration in this instance is larger then in the other instance
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Boolean operator>=( const SelfType& other ) const;


	DEBUG_TOOL(

		// This part of the object is dedicated for testing :


		// Method Information :
		//
		//  Description :
		//
		//		This method is used to test the object. It is not part of the implementation, it is only used to find problems with the code
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			NONE
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//			NONE
		//
		//  Expectations :
		//
		//		Please let the test pass lord!!
		//
		//  Possible errors :
		//
		//		It says there are no problems, which is even scarier, did I just wrote a working code??
		//
		static void UnitTest() __attribute__ (( __unused__ ));

	)  //  End of debug tool


private:


	// This date and time stamp will store information on the starting point
	DateAndTimeStamp member_startingPointDateAndTimeStamp;

	// This date and time stamp will store information on the last measurement point after the starting point
	DateAndTimeStamp member_endingPointDateAndTimeStamp;

	// This object will store the duration between the start and end measurements in seconds
	mutable LargestUnsignedInteger member_durationInSeconds;

	// This object will store if the duration between the start and end measurements in seconds was calculated
	mutable Boolean member_wasDurationInSecondsCalculated;


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of
	// the interface, but rather help implement it :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to check if the given year is a leap year ( February has 29 days instead of 28 )
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    year - the year which needs to be checked if it is a leap year
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		True if the given year is leap year, and false otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Boolean IsLeapYear__Private( const LargestUnsignedInteger year ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to calculate the number of days in the period between the given months for the specific year. Each month has
	//		different number of days, and there is also leap year to take into account
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. startingMonth - the numeric value of the starting month
	//			2. endingMonth - the numeric value of the ending month
	//		    3. year - the numeric value of the year
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The number of days in the period between the given months for the specific year
	//
	//  Expectations :
	//
	//		1. The starting month numeric value is smaller then the ending month
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline LargestUnsignedInteger CalculateNumberOfDaysBetweenTwoMonthsInTheSameYear__Private( const UnsignedInteger8bits startingMonth, const UnsignedInteger8bits endingMonth, const UnsignedInteger16bits year ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to calculate the number of seconds until the end of the hour of the start point
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void CalculateNumberOfSecondsUntilTheEndOfTheHourOfTheStartPoint__Private() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to calculate the number of seconds until the end of the day of the start point
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void CalculateNumberOfSecondsUntilTheEndOfTheDayOfTheStartPoint__Private() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to calculate the number of seconds until the end of the month of the start point
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void CalculateNumberOfSecondsUntilTheEndOfTheMonthOfTheStartPoint__Private() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to calculate the number of seconds passed in the hour of the end point
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void CalculateNumberOfSecondsPassedInTheHourOfTheEndPoint__Private() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to calculate the number of seconds passed in the day of the end point
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void CalculateNumberOfSecondsPassedInTheDayOfTheEndPoint__Private() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to calculate the number of seconds passed in the month of the end point
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void CalculateNumberOfSecondsPassedInTheMonthOfTheEndPoint__Private() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to calculate the number of seconds passed in the hour of the end point
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void CalculateNumberOfSecondsUntilTheEndOfTheYearTheStartPointWasMade__Private() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to calculate the number of seconds passed in the year of the end point
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void CalculateNumberOfSecondsPassedInTheYearTheEndPointWasMade__Private() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to calculate the number of seconds in the full years between the start and end point
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void CalculateNumberOfSecondsInTheFullYearsBetweenTheStartAndEndPoint__Private() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to calculate the number of seconds passed between the two measurements when they were made in different years
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void CalculateNumberOfSecondsBetweenTheTwoMeasurementsWhenTheyWereMadeInDifferentYears__Private() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to calculate the number of seconds passed between the two measurements when they were made in the same year
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	void CalculateNumberOfSecondsBetweenTheTwoMeasurementsWhenTheyWereMadeInTheSameYear__Private() const;


};  //  Class Duration