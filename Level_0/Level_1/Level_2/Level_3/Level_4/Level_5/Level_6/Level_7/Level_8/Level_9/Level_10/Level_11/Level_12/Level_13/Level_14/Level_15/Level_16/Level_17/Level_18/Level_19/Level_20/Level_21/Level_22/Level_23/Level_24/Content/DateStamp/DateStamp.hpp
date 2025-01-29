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
//      1. The real time clock hardware device exist
//      2.
//
//  Possible errors :
//
//		Too many to count
//
class DateStamp
{
public:


	// Create a type definition for this object
	using SelfType = DateStamp;


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
	//			initializeDate - a boolean to notify if the date needs to be collected from the real time clock hardware device in construction
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
	inline DateStamp( const Boolean initializeDate = true );


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
	inline DateStamp( const SelfType& other );


	// Add the following infrastructure to the object :
	//
	//		1. Assigenment operator
	//		2. Move constructor
	//		3. Move assigenment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure( DateStamp )


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
	virtual ~DateStamp() = default;


	// This part will contain all the get and set methods for the members of the object :


	GetByValue_Creator( /* GetMethodName */ DayOfMonth, /* MemberName */ member_dayOfMonth, /* MemberType */ UnsignedInteger8bits )
	GetByValue_Creator( /* GetMethodName */ Month, /* MemberName */ member_month, /* MemberType */ UnsignedInteger8bits )
	GetByValue_Creator( /* GetMethodName */ Year, /* MemberName */ member_year, /* MemberType */ UnsignedInteger16bits )


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to update the date inside this instance
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
	inline void UpdateDate();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to convert the date stamp to string. The delimiter between the day of the month, month and year can be configured
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    delimiter - the character that will separate the day of the month, month and year
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A string containning the date stamp
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	EnsureRetrunValueIsUsed inline Language::String ToString( const Language::Character& delimiter = '.' ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the number of characters that are needed to store the date stamp in this instance as string
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
	//		The number of characters that are needed to store the date stamp in this instance as string
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE 
	//
	EnsureRetrunValueIsUsed inline LargestUnsignedInteger NumberOfCharactersRequiredToStoreAsString() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to convert the date stamp to string. The delimiter between the day of the month, month and year can be configured
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. stringPointer - a pointer with the memory address to which to store the date stamp as string
	//		    2. delimiter - the character that will separate the day of the month, month and year
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The number of characters that are needed to store the date stamp in this instance as string
	//
	//  Expectations :
	//
	//		1. The given string pointer is not NULL
	//		2.
	//
	//  Possible errors :
	//
	//
	//
	EnsureRetrunValueIsUsed inline LargestUnsignedInteger SetAsString( Language::Character* const stringPointer, const Language::Character& delimiter = '.' ) const;


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
	EnsureRetrunValueIsUsed inline Boolean operator==( const SelfType& other ) const;


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
	//		Use this operator to check if the this instance contains date stamp that is larger then the other instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a constant reference to anothr instance
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		1. true - if this instance contains date stamp that is larger then the other instance
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
	EnsureRetrunValueIsUsed inline Boolean operator>( const SelfType& other ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to check if the this instance contains date stamp that is smaller then the other instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a constant reference to anothr instance
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		1. true - if this instance contains date stamp that is smaller then the other instance
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
	EnsureRetrunValueIsUsed inline Boolean operator<( const SelfType& other ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to check if the this instance contains date stamp that is larger or equal to the other instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a constant reference to anothr instance
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		1. true - if this instance contains date stamp that is larger or equal to the other instance
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
	EnsureRetrunValueIsUsed inline Boolean operator>=( const SelfType& other ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to check if the this instance contains date stamp that is smaller or equal to the other instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a constant reference to anothr instance
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		1. true - if this instance contains date stamp that is smaller or equal to the other instance
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
	EnsureRetrunValueIsUsed inline Boolean operator<=( const SelfType& other ) const;


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


	// This object will store the day of month
	UnsignedInteger8bits member_dayOfMonth;

	// This object will store the month
	UnsignedInteger8bits member_month;

	// This object will store the year
	UnsignedInteger16bits member_year;


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of
	// the interface, but rather help implement it :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to update the date inside this instance, and validate that it is reasonable
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
	inline void CollectDateFromRealTimeClockHardwareDevice__Private();


};  //  Class DateStamp