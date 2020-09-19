#ifndef  INSTANCESTATE_HPP
#define  INSTANCESTATE_HPP


#include "../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  // Macro DEBUG_TOOL, Macro COMMA


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif



namespace Universe
{



	// This is used when only declaring the object in this source file will be enough to pass compilation. The implementation is given to the compiler through the
	// cpp source file that the object is nested within
	//
	// Forward declarations :
    //
    //  NONE
    //



    // When an object inherits from another object, all the base methods like constructor and assignment operator of the base object are hidden, and if needed
    // should be declared specific that the required method is in the scope :
    //
    //          using Base::operator=;



	// Class Information :
	//
	//  Purpose :
	//
	//     Use this object to allow other object, that inherit this object, have a well defined state. Each instance of any object should be able to notify, 
    //     most importantly, if it should be used or not ( in other words initialized or not ), and hopefully many more things
	//
	//  Description :
	//
    //      NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//      They will come
	//
	class InstanceState NotForInheritance
	{
	public:


        // The following enumeration will be used to describe the possible states any instance can be in :

        // The purpose of the "default" state is to notify that the instance should not be used in its current form
        static constexpr UnsignedInteger64bits Default = 0UL;

        // The purpose of the "ready" state is to notify that the instance can be used 
        static constexpr UnsignedInteger64bits Ready = 1UL;



        // The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler
        // generates a basic behavior for them :


        // Method Information :
        //
        //  Description :
        //
        //      Default Constructor,
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline InstanceState();


        // Method Information :
        //
        //  Description :
        //
        //      Constructor,
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          state - this will be used to initialize the instance state
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      1. The state should appear in the states enumeration
        //      2. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        explicit inline InstanceState( UnsignedInteger64bits state );


        // Method Information :
        //
        //  Description :
        //
        //      Copy constructor, will operate correctly even if the other object is in default state
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          other - a reference to the instance that should be copied
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline InstanceState( const InstanceState& other );


        // Method Information :
        //
        //  Description :
        //
        //      Assignment operator, can handle with self assignment and instances in default state
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          other - a reference to the instance that should be copied
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A reference to this object
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline InstanceState& operator=( const InstanceState& other );


        // Method Information :
        //
        //  Description :
        //
        //      Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances in default state
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          other - a reference to the instance that should be moved
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline InstanceState( InstanceState&& other );


        // Method Information :
        //
        //  Description :
        //
        //      Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          other - a reference to the instance that should be moved
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A reference to this object
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline InstanceState& operator=( InstanceState&& other );


        // Method Information :
        //
        //  Description :
        //
        //      This method is used to swap the content between this instance and the other one
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          other - a reference to the instance that should be swaped
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline void Swap( InstanceState& other );


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to take an instance in default state and prepare it for work
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline void Reset();


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          state - this will be used to initialize the instance state
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      1. The state should appear in the states enumeration
        //      2. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline void Initiate( UnsignedInteger64bits state );


		// Method Information :
		//
		//  Description :
		//
		//   	Destructor, does not throw
		//
		//  Required arguments :
		//
		//   	User information needed :
		//
		//          NONE
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline ~InstanceState() = default;


        // The following methods are the interface of the object. This methods implement the capabilities of the object :


        // Method Information :
        //
        //  Description :
        //
        //      Use to set the instance into a new state
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          state - this will be used to initialize the instance state
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      1. The state should appear in the states enumeration
        //      2. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline void Set( UnsignedInteger64bits state );


        // Method Information :
        //
        //  Description :
        //
        //      Use to get the current state of the instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      The current state of the instance
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline UnsignedInteger64bits Get() const;


		// The following methods declare the overloaded operators for the object :


		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to check if the this instance match the other
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          other - a reference to the instance that should be compared with this object
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      1. true - if the 2 instances are the same
		//      2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline Boolean operator==( const InstanceState& other ) const;


		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to check if the this instance does not match the other
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          other - a reference to the instance that should be compared with this object
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      1. true - if the 2 instances are not the same
		//      2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline Boolean operator!=( const InstanceState& other ) const;


		DEBUG_TOOL(

			// This part of the class is dedicated for testing :


			// Method Information :
			//
			//  Description :
			//
			//      This method is used to test the object. It is not part of the implementation, it is only used to find problem with the code that does implement
			//		the functionality
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//          NONE
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//      1. true - if the object passed the test
			//      2. false - otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//      1. A method does not work correctly - class Exception is thrown
			//		2. There is no more free memory space - class std::bad_alloc is thrown
			//		3. 
			//
			static void Test();

		)  //  End of debug tool


	private:


        // This object will be used to store the current state of the instance
        UnsignedInteger64bits member_state;


	};  //  Class InstanceState



#include "InstanceState.inl"



}  //  Namespace Universe



#endif  // INSTANCESTATE_HPP