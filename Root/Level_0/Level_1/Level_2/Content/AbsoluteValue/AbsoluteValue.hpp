#ifndef ABSOLUTEVALUE_HPP
#define ABSOLUTEVALUE_HPP


#include "../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../../../Content/Metaprogramming/CommonFunctionality/SubstitutionFailureIsNotAnError/ProvideTypeOnlyIfAssertionIsTrue/ProvideTypeOnlyIfAssertionIsTrue.hpp"  //  Class ProvideTypeOnlyIfAssertionIsTrue
#include "../../../../Content/Metaprogramming/Types/TypeCheck/Integers/TypeCheck_SignedInteger/TypeCheck_SignedInteger.hpp"  //  Class TypeCheck_SignedInteger
#include "../../../../Content/Metaprogramming/Types/TypeCheck/Integers/TypeCheck_UnsignedInteger/TypeCheck_UnsignedInteger.hpp"  //  Class TypeCheck_UnsignedInteger
#include "../../../../Content/Metaprogramming/Types/ConvertBetweenSignedAndUnsignedIntegerTypes/SignedToUnsigned/SignedToUnsigned.hpp"  //  Class SignedToUnsigned
#include "../../../../Content/Metaprogramming/NumericLimits/NumericLimits.hpp"  //  Class NumericLimits


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
	//		Use this object to get the absolute value
	//
    //  Description :
    //
	//		1. This object is used only to wrap some static methods, which can be used without any instance of the object. Then this object is
	//		   an interface which conatins only static methods, and does not need to never be instantied
	//
	//		2. This object has all the methods to create, destory, copy and move disabled to ensure that no instances of it will be created
	//
	//		3. Template arguments :
	//
	//			1. Type -
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	class AbsoluteValue
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
		//		Use this method to get the absolute value. The abosulte value, is the absolute 'distance' from zero, which means the sign does not matter
		//		and it will always be positive :
		//
		//			 8   ->   8
		//			-8   ->   8
		//
		//		The method only works with signed numeric types.
		//
		//		Note - in case the value is negative minimum value in integers, the absolute value can not be represented using the same signed integer size
		//		in bytes. This is because on the positive side, an extra number is added which is '0' while the negative side does not have this unique
		//		number, and therefore can store one more number. For example :
		//
		//			SignedInteger8bits - positive maximum value  ->   127
		//			SignedInteger8bits - negative minimum value  ->  -128
		//
		//		As can be seen there is no way to store the absolute value '128' with a signed integer of size 1 byte
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          number - the number to extract the absolute value from
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      The absolute value of the given number
		//
		//  Expectations :
		//
		//		1. The given number is not the negative minimum value, if the numeric type is signed integer
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename NumericType >
		static inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_UnsignedInteger< NumericType >::Result() == false, NumericType >::Type Calculate( NumericType number );


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the absolute value in an unsigned integer type with the same size as the template type. The abosulte value, is the
		//		absolute 'distance' from zero, which means the sign does not matter and it will always be positive :
		//
		//			 8   ->   8
		//			-8   ->   8
		//
		//		The method only works with signed numeric types.
		//
		//		Note - in case the value is negative minimum value in integers, the absolute value can not be represented using the same signed integer size
		//		in bytes. This is because on the positive side, an extra number is added which is '0' while the negative side does not have this unique
		//		number, and therefore can store one more number. For example :
		//
		//			SignedInteger8bits - positive maximum value  ->   127
		//			SignedInteger8bits - negative minimum value  ->  -128
		//
		//		As can be seen there is no way to store the absolute value '128' with a signed integer of size 1 byte. This method purpose is to solve 
		//		this problem
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          number - the number to extract the absolute value from
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      The absolute value of the given number
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename SignedIntegerType >
		static inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_SignedInteger< SignedIntegerType >::Result() == true, typename SignedToUnsigned< SignedIntegerType >::Type >::Type CalculateAndReturnAbsoluteValueAsUnsignedIntegerWithTheSameSize( SignedIntegerType number );


		DEBUG_TOOL(

			// This part of the object is dedicated for testing :


			// Method Information :
			//
			//  Description :
			//
			//      This method is used to test the object. It is not part of the implementation, it is only used to find problems with the code
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
			static inline void Test() __attribute__ (( __unused__ ));

		)  //  End of debug tool


	private:


		// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
		NoInstances_MACRO( AbsoluteValue )


	};  //  Class AbsoluteValue



#include "AbsoluteValue.inl"



}  //  Namespace Universe


#endif  // ABSOLUTEVALUE_HPP