#ifndef ROOT_HPP
#define ROOT_HPP


#include "../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../../../Content/ArithmeticOperations/BaseRaisedByThePower/BaseRaisedByThePower.hpp"  //  Class BaseRaisedByThePower
#include "../../../../Content/BindObjects/Tuple/Tuple.hpp"  //  Class Tuple
#include "../../../../../../../Content/Metaprogramming/CommonFunctionality/SubstitutionFailureIsNotAnError/ProvideTypeOnlyIfAssertionIsTrue/ProvideTypeOnlyIfAssertionIsTrue.hpp"  //  Class ProvideTypeOnlyIfAssertionIsTrue
#include "../../../../../../../Content/Metaprogramming/Types/TypeCheck/Integers/TypeCheck_Integer/TypeCheck_Integer.hpp"  //  Class TypeCheck_Integer
#include "../../../../../../../Content/Metaprogramming/Types/TypeCheck/FloatingPoint/TypeCheck_FloatingPoint/TypeCheck_FloatingPoint.hpp"  //  Class TyeCheck_FloatingPoint
#include "../../../../../../../Content/Metaprogramming/NumericLimits/NumericLimits.hpp"  //  Class NumericLimits
#include "../../../../../Content/AbsoluteValue/AbsoluteValue.hpp"  //  Class AbsoluteValue


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
	//		Use this object to calculate the n'th root of a number. This means that the root is the answer to the equation :
	//
	//			( radicand ) power ( 1 / degree ) = root
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
	class Root
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
		//		Use this method to find the root, for the given radicand and degree. The root is the number that solves the equation :
		//
		//			( radicand ) power ( 1 / degree ) = root
		//
		//		This version of the root method is for integers, which can not have digits behind the decimal point
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. radicand - the value that the n'th root needs to be found for
		//			2. degree - represents the power of which the root needs to be raised by in order to get the radicand
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		A pair, the first entry of the pair will contain a boolean that will be used to notify if a root, without any digits behind the decimal
		//		point, for the given radicand and degree was found or not, and the second entry will contain the root itself
		//		
		//
		//  Expectations :
		//
		//		1. The given radicand should not be negative
		//		2. The given degree should not be negative
		//		3. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename NumericType >
		static inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_Integer< NumericType >::Result() == true, Tuple< Boolean, NumericType > >::Type Calculate( NumericType radicand, NumericType degree );


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to find the root, for the given radicand and degree. The root is the number that solves the equation :
		//
		//			( radicand ) power ( 1 / degree ) = root
		//
		//		This version of the root method is for floating points
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. radicand - the value that the n'th root needs to be found for
		//			2. degree - represents the power of which the root needs to be raised by in order to get the radicand
		//			3. maximumDifferenceBetweenRootCalculatedRaisedByThePowerOfTheDegreeAndRadicand - this value will be used to determine the required 
		//			   precision of the root result in case an exact match does not exist, the implementation will try to find the first root that raised 
		//			   by the power of the degree will give a result which its absolute value is not further then this value from the radicand :
		//
		//					AbsoluteValue( radicand - ( ROOT power degree ) ) < maximumDifferenceBetweenRootCalculatedRaisedByThePowerOfTheDegreeAndRadicand
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		The first root which raising to the power of the degree is close enough to the radicand
		//
		//  Expectations :
		//
		//		1. The given radicand should not be negative
		//		2. The given degree should not be negative
		//		3. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename NumericType >
		static inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_FloatingPoint< NumericType >::Result() == true, NumericType >::Type Calculate( NumericType radicand, NumericType degree, NumericType maximumDifferenceBetweenRootCalculatedRaisedByThePowerOfTheDegreeAndRadicand = NumericLimits< NumericType >::Minimum() );


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
		NoInstances( Root )


	};  //  Class Root



#include "Root.inl"



}  //  Namespace Universe


#endif  // ROOT_HPP