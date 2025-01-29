// namespace Universe
// {


// namespace FileSystem
// {


// // Class Information :
// //
// //  Purpose :
// //
// //		Artifical Inteligence
// //
// //  Description :
// //
// // 		1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
// //		   providing 3 keywords :
// //
// //			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
// //						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
// //						member is public all the encapsulation is lost, so it should be avoided in most cases
// //
// //			2. Protected - this part is for developing purposes, inheritance. A developer can inherit from this object and it will
// //						   be able to access all the data and methods inside this part. This part will usually containt some methods and few
// //						   data members
// //
// //			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
// //						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this
// //						 part will end with the suffix __Private
// //
// //  Expectations :
// //
// //		NONE
// //
// //  Possible errors :
// //
// //		Too many to count
// //
// class DateAndTimeTrack NotForInheritance
// {
// public:


// 	// Create a type definition for this object
// 	using SelfType = DateAndTimeTrack;


// 	// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
// 	// the compiler generates a basic behavior for them if possible :


// 	// Method Information :
// 	//
// 	//  Description :
// 	//
// 	//		Default Constructor,
// 	//
// 	//  Required arguments :
// 	//
// 	//		User information needed :
// 	//
// 	//			NONE
// 	//
// 	//		Information returned to the user :
// 	//
// 	//			NONE
// 	//
// 	//  Return value :
// 	//
// 	//		NONE
// 	//
// 	//  Expectations :
// 	//
// 	//		NONE
// 	//
// 	//  Possible errors :
// 	//
// 	//		They will come
// 	//
// 	inline DateAndTimeTrack();


// 	// Method Information :
// 	//
// 	//  Description :
// 	//
// 	//		Copy constructor, will operate correctly even if the other instance is in default state or self assignment
// 	//
// 	//  Required arguments :
// 	//
// 	//		User information needed :
// 	//
// 	//		    other - a reference to the instance that should be copied
// 	//
// 	//		Information returned to the user :
// 	//
// 	//			NONE
// 	//
// 	//  Return value :
// 	//
// 	//		NONE
// 	//
// 	//  Expectations :
// 	//
// 	//		NONE
// 	//
// 	//  Possible errors :
// 	//
// 	//		They will come
// 	//
// 	inline DateAndTimeTrack( const SelfType& other );


// 	// Add the following infrastructure to the object :
// 	//
// 	//		1. Assigenment operator
// 	//		2. Move constructor
// 	//		3. Move assigenment operator
// 	//		4. Swap
// 	//		5. Reset
// 	//
// 	ObjectInfrastructure( DateAndTimeTrack )


// 	// Method Information :
// 	//
// 	//  Description :
// 	//
// 	//		Destructor, does not throw
// 	//
// 	//  Required arguments :
// 	//
// 	//		User information needed :
// 	//
// 	//			NONE
// 	//
// 	//		Information returned to the user :
// 	//
// 	//			NONE
// 	//
// 	//  Return value :
// 	//
// 	//		NONE
// 	//
// 	//  Expectations :
// 	//
// 	//		NONE
// 	//
// 	//  Possible errors :
// 	//
// 	//		They will come
// 	//
// 	inline ~DateAndTimeTrack() = default;


// 	// This part will contain all the get and set methods for the members of the object :


// 	GetByConstantReference_Creator( /* GetMethodName */ CreationDateAndTimeStamp, /* MemberName */ member_creationDateAndTimeStamp, /* MemberType */ DateAndTimeStamp )
// 	GetByConstantReference_Creator( /* GetMethodName */ ViewDateAndTimeStamp, /* MemberName */ member_lastViewDateAndTimeStamp,  MemberType  DateAndTimeStamp )
// 	GetByConstantReference_Creator( /* GetMethodName */ EditDateAndTimeStamp, /* MemberName */ member_editViewDateAndTimeStamp, /* MemberType */ DateAndTimeStamp )


// 	// The following methods give access and manipulate the data inside this object :


// 	// Method Information :
// 	//
// 	//  Description :
// 	//
// 	//		Use this method to update the view date and time stamp
// 	//
// 	//  Required arguments :
// 	//
// 	//		User information needed :
// 	//
// 	//		    NONE
// 	//
// 	//		Information returned to the user :
// 	//
// 	//			NONE
// 	//
// 	//  Return value :
// 	//
// 	//		NONE
// 	//
// 	//  Expectations :
// 	//
// 	//		NONE
// 	//
// 	//  Possible errors :
// 	//
// 	//		They will come
// 	//
// 	inline void UpdateViewDateAndTimeStamp();


// 	// Method Information :
// 	//
// 	//  Description :
// 	//
// 	//		Use this method to update the edit date and time stamp
// 	//
// 	//  Required arguments :
// 	//
// 	//		User information needed :
// 	//
// 	//		    NONE
// 	//
// 	//		Information returned to the user :
// 	//
// 	//			NONE
// 	//
// 	//  Return value :
// 	//
// 	//		NONE
// 	//
// 	//  Expectations :
// 	//
// 	//		NONE
// 	//
// 	//  Possible errors :
// 	//
// 	//		They will come
// 	//
// 	inline void UpdateEditDateAndTimeStamp();


// 	// The following methods declare the overloaded operators for the object :


// 	// Method Information :
// 	//
// 	//  Description :
// 	//
// 	//		Use this operator to check if the this instance match the other
// 	//
// 	//  Required arguments :
// 	//
// 	//		User information needed :
// 	//
// 	//		    other - a reference to the instance that should be compared with this object
// 	//
// 	//		Information returned to the user :
// 	//
// 	//			NONE
// 	//
// 	//  Return value :
// 	//
// 	//		1. true - if the 2 instances are the same
// 	//		2. false - otherwise
// 	//
// 	//  Expectations :
// 	//
// 	//		NONE
// 	//
// 	//  Possible errors :
// 	//
// 	//		They will come
// 	//
// 	EnsureRetrunValueIsUsed inline Boolean operator==( const SelfType& other ) const;


// 	// Method Information :
// 	//
// 	//  Description :
// 	//
// 	//		Use this operator to check if the this instance does not match the other
// 	//
// 	//  Required arguments :
// 	//
// 	//		User information needed :
// 	//
// 	//		    other - a reference to the instance that should be compared with this object
// 	//
// 	//		Information returned to the user :
// 	//
// 	//			NONE
// 	//
// 	//  Return value :
// 	//
// 	//		1. true - if the 2 instances are not the same
// 	//		2. false - otherwise
// 	//
// 	//  Expectations :
// 	//
// 	//		NONE
// 	//
// 	//  Possible errors :
// 	//
// 	//		They will come
// 	//
// 	EnsureRetrunValueIsUsed inline Boolean operator!=( const SelfType& other ) const;


// 	DEBUG_TOOL(

// 		// This part of the object is dedicated for testing :


// 		// Method Information :
// 		//
// 		//  Description :
// 		//
// 		//		This method is used to test the object. It is not part of the implementation, it is only used to find problems with the code
// 		//
// 		//  Required arguments :
// 		//
// 		//		User information needed :
// 		//
// 		//			NONE
// 		//
// 		//		Information returned to the user :
// 		//
// 		//			NONE
// 		//
// 		//  Return value :
// 		//
// 		//			NONE
// 		//
// 		//  Expectations :
// 		//
// 		//		Please let the test pass lord!!
// 		//
// 		//  Possible errors :
// 		//
// 		//		It says there are no problems, which is even scarier, did I just wrote a working code??
// 		//
// 		static void UnitTest() __attribute__ (( __unused__ ));

// 	)  //  End of debug tool


// private:


// 	// This object will store the creation date and time of the file
// 	DateAndTimeStamp member_creationDateAndTimeStamp;

// 	// This object will store the date and time of the last time the file was viewed
// 	DateAndTimeStamp member_lastViewDateAndTimeStamp;

// 	// This object will store the date and time of the last time the file was edited
// 	DateAndTimeStamp member_lastEditDateAndTimeStamp;


// };  //  Class DateAndTimeTrack