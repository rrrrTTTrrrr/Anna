#ifndef BASERAISEDBYTHEPOWER_HPP
#define BASERAISEDBYTHEPOWER_HPP


#include "../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe
{



	// When a type is forward declared, all the compiler knows is that this type exists. It does not know its size, members or methods. This is why its
	// called incomplete type. Therefore, it can not be used to declare a variable, member or base class since the compiler would need the layout of the
	// type. In other words, it can not be used for anything that requires information on the specific type. What can be done is declaring pointer and
	// reference to the incomplete type. The pointer and refernce can act as a variable, argument to a method or as the return type.
	//
	// Forward declarations :
	//
	//  NONE
	//



	// Class Information :
	//
	//  Purpose :
	//
	//		Use this object to calculate the base raised by the power 
	//
    //  Description :
    //
	//		1. This object is used only to wrap some static methods, which can be used without any instance of the object. Then this object is
	//		   an interface which conatins only static methods, and does not need to never be instantied
	//
	//		2. This object has all the methods to create, destory, copy and move disabled to ensure that no instances of it will be created
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	class BaseRaisedByThePower
	{
	public:


		// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions
		// only have access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only
		// purpose then of declaring a static function is when a private static data member needs to be manipulated, or some functionality needed that
		// does not involve the non static data members


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to multiply, the power will determine the number of times, by itself
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. base - the value that will be multiplied by itself
		//			2. power - this will determine the number of times the base will be multiplied by itself
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		The base multiplied by itself the number of times the power determines
		//
		//  Expectations :
		//
		//		1. The result should be in the range of the template numeric type, or an overflow will occuer
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename NumericType >
		static inline NumericType Calculate( NumericType base, NumericType power );


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
			static void Test() __attribute__ (( __unused__ ));

		)  //  End of debug tool


	private:


		// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
		NoInstances_MACRO( BaseRaisedByThePower )


	};  //  Class BaseRaisedByThePower




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



































	// Method Information :
	//
	//  Description :
	//
	//		Use this method to multiply, the power will determine the number of times, by itself
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. base - the value that will be multiplied by itself
	//			2. power - this will determine the number of times the base will be multiplied by itself
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The base multiplied by itself the number of times the power determines
	//
	//  Expectations :
	//
	//		1. The result should be in the range of the template numeric type, or an overflow will occuer
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename NumericType >
	inline NumericType BaseRaisedByThePower::Calculate( NumericType base, NumericType power )
	{
		// Check if the base is 0
		if ( base == 0 )
		{
			// The base is 0

			// Return the result - 0
			return ( 0 );
		}
		// Check if the power is 0
		else if ( power == 0 )
		{
			// The power is 0

			// Each number to the power of 0, the result is 1
			return ( 1 );
		}

		// This object will store the result of the base raised to the power
		NumericType result = base;

		// The power provided will determine the number of iterations for the loop
		while ( power > 1 )
		{
			// Multiply the base by the result
			result *= base;

			// Decrement the power by 1
			power -= 1;
		}

		// Return the result
		return ( result );
	}












}  //  Namespace Universe


#endif  // BASERAISEDBYTHEPOWER_HPP