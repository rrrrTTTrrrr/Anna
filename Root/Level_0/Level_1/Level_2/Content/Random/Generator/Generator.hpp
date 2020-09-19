#ifndef GENERATOR_HPP
#define GENERATOR_HPP


#include "../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../Content/Metaprogramming/MetaprogrammingMacros/MetaprogrammingMacros.hpp"  //  Macro MOVE
#include "../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../../../../Content/Metaprogramming/CommonFunctionality/SubstitutionFailureIsNotAnError/ProvideTypeOnlyIfAssertionIsTrue/ProvideTypeOnlyIfAssertionIsTrue.hpp"  //  Class ProvideTypeOnlyIfAssertionIsTrue
#include "../../../../../Content/Metaprogramming/Types/TypeCheck/Integers/TypeCheck_Integer/TypeCheck_Integer.hpp"  //  Class TypeCheck_Integer
#include "../../../../../Content/Metaprogramming/Types/TypeCheck/Reference/TypeCheck_Reference/TypeCheck_Reference.hpp"  //  Class TypeCheck_Reference
#include "../../../../../Content/Metaprogramming/Types/TypeCheck/Reference/TypeCheck_RvalueReference/TypeCheck_RvalueReference.hpp"  //  Class TypeCheck_RvalueReference
#include "../../../../../Content/Metaprogramming/Types/TypeCheck/Reference/TypeCheck_Constant_LvalueReference/TypeCheck_Constant_LvalueReference.hpp"  //  Class TypeCheck_Constant_LvalueReference
#include "../../../../../Content/Metaprogramming/Types/TypeRemoval/RemoveReferenceAndConstantVolatileQualifications/RemoveReferenceAndConstantVolatileQualifications.hpp"  //  Class RemoveReferenceAndConstantVolatileQualifications
#include "../../../../../Content/Metaprogramming/Types/CompareTypes/CompareTypes.hpp"  //  Class CompareTypes
#include "../PickNumber/PickNumber.hpp"  //  Class PickNumber
#include "../../NumericRange/NumericRange.hpp"  //  Class NumericRange


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe
{

    namespace Random
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



		// A non type template argument provided within a template argument list is an expression whose value can be determined at compile time. Such
		// arguments must be constant expressions, addresses of functions or objects with external linkage or addresses of static class members. String
		// literals are objects with internal linkage and can not be used, as well as global pointers and floating points literals due to the posibility
		// of rounding off errors. 
		//
		// Non constant expressions can't be parsed and substituted during compile time. They could change during run time which would required the
		// generation of a new template during run time, which isn't possible because templates are a compile time concept. Here is what the standard
		// allows for non type template parameters :
		//
		//	1. Integral or enumeration type
		//	2. Pointer to object or pointer to function
		//	3. lvalue reference to object or lvalue reference to function
		//	4. pointer to member
		//	5. std::nullptr_t



		// Class Information :
		//
		//  Purpose :
		//
		//		Use this object to generate a random instance. There are 2 possibilites, the first is that the required type for the random generator
		//		is integer, which means a number needs to be randomed. The second is for actual objects, that to create a random instance, the constructor
		//		the generate a random instance needs to be called. The point of this object is to make the choice between the two invisible to the user
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
		class Generator
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
			//		Use this method to generate a random number in the given range and return a copy of it, the method can only return values in the range :
			//
			//		 	[ minimum, maximum - 1 ] 
			//
			// 		This method will only be used for integer template types
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			range - this will be used to set the limits for the possible values used
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//		A random generated number between the minimum and maximum of the range
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			template< typename IntegerType >
			static inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_Integer< IntegerType >::Result() == true && CompareTypes< IntegerType, Boolean >::Result() == false && TypeCheck_Reference< IntegerType >::Result() == false, IntegerType >::Type Get( NumericRange< IntegerType > range = NumericRange< IntegerType >() );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to generate a random number in the given range and return a copy of it, the method can only return values in the range :
			//
			//		 	[ minimum, maximum - 1 ] 
			//
			// 		This method will only be used for boolean types!
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			NONE
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//		A random generated boolean value
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			template< typename IntegerType >
			static inline typename ProvideTypeOnlyIfAssertionIsTrue< CompareTypes< IntegerType, Boolean >::Result() == true, Boolean >::Type Get( NumericRange< Boolean > range = NumericRange< Boolean >( false, true ) );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to generate a random number in the given range and return a copy of it, the method can only return values in the range :
			//
			//		 	[ minimum, maximum - 1 ] 
			//
			// 		This method will only be used for integer template types. This overladed method is to allow using references also, it allows all references
			//		that can bind to a temporary, which means all references beside non constant lvalue references 'Type&' and 'volatile Type&'
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			range - this will be used to set the limits for the possible values used
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//		A random generated number between the minimum and maximum of the range
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			template< typename IntegerType, typename IntegerStrippedType = typename RemoveReferenceAndConstantVolatileQualifications< IntegerType >::Type >
			static inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_Integer< IntegerStrippedType >::Result() == true && TypeCheck_Reference< IntegerType >::Result() == true && ( TypeCheck_RvalueReference< IntegerType >::Result() == true || TypeCheck_Constant_LvalueReference< IntegerType >::Result() == true ), IntegerStrippedType >::Type Get( NumericRange< IntegerStrippedType > range = NumericRange< IntegerStrippedType >() );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to generate a random instance of the object type and return a copy of it. This method will only be used for non integer template types
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			objectTypeGenerateRandomInstanceArguments - any argument needed to generate a random instance of the template object type
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//		A random generated instance of the template type
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			template< typename ObjectType, typename... GenerateRandomInstanceArgumentTypes >
			static inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_Integer< ObjectType >::Result() == false && TypeCheck_Reference< ObjectType >::Result() == false, ObjectType >::Type Get( GenerateRandomInstanceArgumentTypes... objectTypeGenerateRandomInstanceArguments );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to generate a random instance of the object type and return a copy of it. This method will only be used for non integer template types.
			//		This overladed method is to allow using references also, it allows all references that can bind to a temporary, which means all references beside non 
			//		constant lvalue references 'Type&' and 'volatile Type&'	
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			objectTypeGenerateRandomInstanceArguments - any argument needed to generate a random instance of the template object type
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//		A random generated instance of the template type
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			template< typename ObjectType, typename ObjectStrippedType = typename RemoveReferenceAndConstantVolatileQualifications< ObjectType >::Type, typename... GenerateRandomInstanceArgumentTypes >
			static inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_Integer< ObjectStrippedType >::Result() == false && TypeCheck_Reference< ObjectType >::Result() == true && ( TypeCheck_RvalueReference< ObjectType >::Result() == true || TypeCheck_Constant_LvalueReference< ObjectType >::Result() == true ), ObjectStrippedType >::Type Get( GenerateRandomInstanceArgumentTypes... objectTypeGenerateRandomInstanceArguments );


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
			NoInstances_MACRO( Generator )


		};  //  Class Generator




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



































	// Method Information :
	//
	//  Description :
	//
	//		Use this method to generate a random number in the given range and return a copy of it, the method can only return values in the range :
	//
	//		 	[ minimum, maximum - 1 ] 
	//
	// 		This method will only be used for integer template types
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			range - this will be used to set the limits for the possible values used
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		A random generated number between the minimum and maximum of the range
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename IntegerType >
	inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_Integer< IntegerType >::Result() == true && CompareTypes< IntegerType, Boolean >::Result() == false && TypeCheck_Reference< IntegerType >::Result() == false, IntegerType >::Type Generator::Get( NumericRange< IntegerType > range )
	{
        // This object will be used to pick a random value for the type
        static PickNumber< IntegerType > pickNumber;

        // Pick a number and return a copy of it
        return ( pickNumber.Get( range ) );
	}


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to generate a random number in the given range and return a copy of it, the method can only return values in the range :
	//
	//		 	[ minimum, maximum - 1 ] 
	//
	// 		This method will only be used for boolean types!
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			NONE
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		A random generated boolean value
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename IntegerType >
	inline typename ProvideTypeOnlyIfAssertionIsTrue< CompareTypes< IntegerType, Boolean >::Result() == true , Boolean >::Type Generator::Get( NumericRange< Boolean > range )
	{
        // This object will be used to pick a random value for the boolean
        static PickNumber< Boolean > pickNumber;

        // Pick a number and return a copy of it
        return ( pickNumber.Get( range ) );
	}


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to generate a random number in the given range and return a copy of it, the method can only return values in the range :
	//
	//		 	[ minimum, maximum - 1 ] 
	//
	// 		This method will only be used for integer template types. This overladed method is to allow using references also, it allows all references
	//		that can bind to a temporary, which means all references beside non constant lvalue references 'Type&' and 'volatile Type&'
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			range - this will be used to set the limits for the possible values used
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		A random generated number between the minimum and maximum of the range
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename IntegerType, typename IntegerStrippedType >
	inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_Integer< IntegerStrippedType >::Result() == true && TypeCheck_Reference< IntegerType >::Result() == true && ( TypeCheck_RvalueReference< IntegerType >::Result() == true || TypeCheck_Constant_LvalueReference< IntegerType >::Result() == true ), IntegerStrippedType >::Type Generator::Get( NumericRange< IntegerStrippedType > range )
	{
        // This object will be used to pick a random value for the type
        static PickNumber< IntegerStrippedType > pickNumber;

        // Pick a number and return a copy of it
        return ( pickNumber.Get( range ) );
	}


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to generate a random instance of the object type and return a copy of it. This method will only be used for non integer template types
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			objectTypeGenerateRandomInstanceArguments - any argument needed to generate a random instance of the template object type
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		A random generated instance of the template type
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename ObjectType, typename... GenerateRandomInstanceArgumentTypes >
	inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_Integer< ObjectType >::Result() == false && TypeCheck_Reference< ObjectType >::Result() == false, ObjectType >::Type Generator::Get( GenerateRandomInstanceArgumentTypes... objectTypeGenerateRandomInstanceArguments )
	{
        // Generate a random instance of the object template type using the given arguments, and retrun a copy of it
        return ( MOVE( ObjectType( GenerateRandomInstance, objectTypeGenerateRandomInstanceArguments... ) ) );
	}


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to generate a random instance of the object type and return a copy of it. This method will only be used for non integer template types.
	//		This overladed method is to allow using references also, it allows all references that can bind to a temporary, which means all references beside non 
	//		constant lvalue references 'Type&' and 'volatile Type&'	
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			objectTypeGenerateRandomInstanceArguments - any argument needed to generate a random instance of the template object type
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		A random generated instance of the template type
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename ObjectType, typename ObjectStrippedType, typename... GenerateRandomInstanceArgumentTypes >
	inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_Integer< ObjectStrippedType >::Result() == false && TypeCheck_Reference< ObjectType >::Result() == true && ( TypeCheck_RvalueReference< ObjectType >::Result() == true || TypeCheck_Constant_LvalueReference< ObjectType >::Result() == true ), ObjectStrippedType >::Type Generator::Get( GenerateRandomInstanceArgumentTypes... objectTypeGenerateRandomInstanceArguments )
	{
        // Generate a random instance of the object template type using the given arguments, and retrun a copy of it
        return ( MOVE( ObjectStrippedType( GenerateRandomInstance, objectTypeGenerateRandomInstanceArguments... ) ) );
	}










    }  //  Namespace Random

}  //  Namespace Universe


#endif  // GENERATOR_HPP