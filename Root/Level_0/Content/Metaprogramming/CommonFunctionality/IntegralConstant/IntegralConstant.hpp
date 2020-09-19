#ifndef  INTEGRALCONSTANT_HPP
#define  INTEGRALCONSTANT_HPP


#include "../../../CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  // Macro DEBUG_TOOL, Macro COMMA


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



	// Template Class Information :
	//
	//  Purpose :
	//
	//		This object is a wrapper to a static constant integral value. There are a few cases where this object is very useful. One of them is tag dispatch.
    //      For example :
    //
    //      The first implementation is for primitive types :
    //
    //              template< typename TYPE >
    //              UnsignedInteger32bits SomeMethod( TYPE instance, IntegralConstant< true, TYPE > )
    //              {
    //                  Method body...
    //              }
    //
    //      The second implementation is for all others :
    //
    //              template< typename TYPE >
    //              UnsignedInteger32bits SomeMethod( TYPE instance, IntegralConstant< false, TYPE > )
    //              {   
    //                  Method body... ohhh youre so sexy
    //              }
    //
    //      And now it can be invoked for example :
    //
    //              template< typename TYPE >
    //              void DoSomethingElse()
    //              {
    //                  // Invoke the method o
    //                  SomeMethod< TYPE >( value, TypeCheck_Primitive< TYPE >{} );
    //              }
    //
    //		Basically this object is used as the interface to use the type check objects and many more
	//
	//  Description :
	//
	//		1. This object contains an instance of the object "State" to allow each instance of this object to have a defined state
	//
	// 		2. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by providing 3 keywords :
	//
	//				1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the obejct using the tools
	//							presented here. This part will usually contain only methods and not data members. If a data member is public all the encapsulation is
	//							lost, so it should be avoided in most cases
	//
	//				2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will be able to access
	//							   all the data and methods inside this part. This part will usually containt some methods and few data members
	//
	//				3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object and all the
	//							 methods the developer needed to implement the interface presented in the public part. Every method in this part will end with the
	//							 suffix __Private
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	template< typename IntegralType, IntegralType IntegralValue >
	class IntegralConstant
	{
	public:


		// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have
		// access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring
		// a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to get the static constant integral value inside it
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
        //      A copy of the static constant integral value inside this object will be returned
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        static constexpr IntegralType Result();


	private:


		// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
		NoInstances_MACRO( IntegralConstant )


    	// Static data members do not belong to any instance, they belong to the object. Like every global variable it is created with the start of the program
		// and only destroyed when the program ends. The access to the static member is bound to this object of course


        // This object will store the integral constant. The member is initialized inside the object due to use constant expression this needs to be used 
        constexpr static IntegralType member_integralValue = IntegralValue;


	};  //  Class IntegralConstant































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************






























    // Method Information :
    //
    //  Description :
    //
    //      Use this method to get the static constant integral value inside it
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
    //          A copy of the static constant integral value inside this object will be returned
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename IntegralType, IntegralType IntegralValue >
    constexpr IntegralType IntegralConstant< IntegralType, IntegralValue >::Result()
    {
        // Return a copy of the static constant integral value inside this object
        return ( member_integralValue );
    }











}  //  Namespace Universe



#endif  // INTEGRALCONSTANT_HPP