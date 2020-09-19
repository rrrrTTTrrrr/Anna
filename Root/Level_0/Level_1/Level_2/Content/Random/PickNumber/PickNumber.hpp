#ifndef PICKNUMBER_HPP
#define PICKNUMBER_HPP


#include "../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../Content/Object/ObjectInfrastructure/BasicObjectFunctionality/BasicObjectFunctionality.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "./PassOnRangeInConstantJumps/PassOnRangeInConstantJumps.hpp"  //  Class PassOnRangeInConstantJumps
#include "../../../../../Content/Metaprogramming/Types/TypeCheck/Integers/TypeCheck_Integer/TypeCheck_Integer.hpp"  //  Class TypeCheck_Integer
#include "../../../../../Content/Metaprogramming/NumericLimits/NumericLimits.hpp"  //  Class NumericLimits
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



		// Modulo :
		//
		//		positive % positive = positive
		//
		//		positive % negative = positive
		//
		//		negative % positive = negative
		//
		//		negative % negative = negative
		//
		// Totally fucked up!!!



		// Template Class Information :
		//
		//  Purpose :
		//
		//		Use this object to pick numbers from a certain range, determined by the template integer type. The rational is that each time
		//		a number is picked, it will be picked using a different jump from the previous number. The jumps in order to cover all the range
		//		will be powers of 2, this means :
		//
		//			1, 2, 4, 8, 16, 32, 64...
		//
		//		The number of jumps will be determined by the size of the range, larger range requires more and larger jumps. The hope is that
		//		this process will create a uniform distribution
		//
		//  Description :
		//
		//		1. This object contains an instance of the object "InstanceState" to allow each instance of this object to have a defined state
		//
		// 		2. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
		//		   providing 3 keywords :
		//
		//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
		//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
		//						member is public all the encapsulation is lost, so it should be avoided in most cases
		//
		//			2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will
		//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few
		//						   data members
		//
		//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
		//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this
		//						 part will end with the suffix __Private
		//
		//		3. Template arguments :
		//
		//			1. IntegerType - any integer type
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		Too many to count
		//
		template< typename IntegerType >
		class PickNumber NotForInheritance
		{
		public:


            // Create a type definition for this object
            using SelfType = PickNumber< IntegerType >;


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
 			//			NONE
			//
			//      Information returned to the user :
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
			inline PickNumber();


			// This macro will be used to all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
			// simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
			// any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
			// be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
			// macro will be used to add the following methods to each object :
			//
			//		1. Swap
			//		2. Reset
			//
			ObjectInfrastructure_OnlySwapAndReset_MACRO()


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
			//      Information returned to the user :
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
			inline ~PickNumber() = default;


			// The following methods give access and manipulate the data inside this object :


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to pick a number in the range of the template integer type
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
			//		A number in the range of the template integer type
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline IntegerType Get();


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to pick a number if the range of the template integer type is too large and should be narrowed down
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			range - this will be used to set the limits for the possible values used
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		A number between the minimum and maximum provided
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline IntegerType Get( NumericRange< IntegerType > range );


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
				static inline void Test() __attribute__ (( __unused__ ));

			)  //  End of debug tool


		private:


            // Disable all copy and move related methods
            DisableCopyAndMove_MACRO( PickNumber )


 			// This object will store the number of instances in the following array. The number of instances used dependes on the size of the range.
 			// For example the largest integer range is for 64 bits, the jumps will be in powers of 2, therefore the largest jump will be half of the 
 			// range which is 2 to the power of 63, and therefore 63 instances will be used
 			static constexpr UnsignedInteger64bits member_numberOfInstancesToPassOnRangeInConstantJumps = ( ( sizeof( IntegerType ) * 8 ) - 1 );

 			// This object will store the instances that used to pass on the range in constant jumps
 			PassOnRangeInConstantJumps< IntegerType > member_PassOnRangeInConstantJumpsInstances[ member_numberOfInstancesToPassOnRangeInConstantJumps ];

 			// This object will store the last used entry to get a number from the pass on the range in constant jumps instances
 			UnsignedInteger64bits member_lastUsedEntry;


			// Assert all the requirements on the template arguments provided to the object. To perform a compile time assert the C++ language provides
			// the keyword 'static_assert', which receives an expression and an error message to display if the expression result is false. The important
			// thing is that the expression is evaluted during compile time, and therefore if the expression is false the compilation will be terminated
			// and the error message will be displayed. This method should not be used, because it does nothing during run time
			CompileTimeAssert( ( TypeCheck_Integer< IntegerType >::Result() == true ), "Random::PickNumber failed - the given template type should be integer" );


		};  //  Class PickNumber




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - IntegerType = Boolean   ************************************************* //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //




		// Template Class Information :
		//
		//  Purpose :
		//
		//		Use this object to pick numbers from a certain range, determined by the template integer type. The rational is that each time
		//		a number is picked, it will be picked using a different jump from the previous number. The jumps in order to cover all the range
		//		will be powers of 2, this means :
		//
		//			1, 2, 4, 8, 16, 32, 64...
		//
		//		The number of jumps will be determined by the size of the range, larger range requires more and larger jumps. The hope is that
		//		this process will create a uniform distribution. This is a template specialization for booleans
		//
		//  Description :
		//
		//		1. This object contains an instance of the object "InstanceState" to allow each instance of this object to have a defined state
		//
		// 		2. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
		//		   providing 3 keywords :
		//
		//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
		//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
		//						member is public all the encapsulation is lost, so it should be avoided in most cases
		//
		//			2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will
		//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few
		//						   data members
		//
		//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
		//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this
		//						 part will end with the suffix __Private
		//
		//		3. Template arguments :
		//
		//			1. IntegerType - any integer type
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		Too many to count
		//
		template<>
		class PickNumber< Boolean > NotForInheritance
		{
		public:


            // Create a type definition for this object
            using SelfType = PickNumber< Boolean >;


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
 			//			NONE
			//
			//      Information returned to the user :
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
			inline PickNumber();


			// This macro will be used to all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
			// simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
			// any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
			// be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
			// macro will be used to add the following methods to each object :
			//
			//		1. Swap
			//		2. Reset
			//
			ObjectInfrastructure_OnlySwapAndReset_MACRO()


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
			//      Information returned to the user :
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
			inline ~PickNumber() = default;


			// The following methods give access and manipulate the data inside this object :


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to pick a number in the range of the template integer type
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
			//		A number in the range of the template integer type
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline Boolean Get();


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to pick a number if the range of the template integer type is too large and should be narrowed down
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			range - this will be used to set the limits for the possible values used
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		A number between the minimum and maximum provided
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline Boolean Get( NumericRange< Boolean > range = NumericRange< Boolean >( false, true ) );


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
				static inline void Test() __attribute__ (( __unused__ )) { PickNumber< UnsignedInteger8bits >::Test(); }

			)  //  End of debug tool


		private:


            // Disable all copy and move related methods
            DisableCopyAndMove_MACRO( PickNumber )


 			// This object will be used to pick the random value between true and false
 			PickNumber< UnsignedInteger8bits > member_pickNumber;


		};  //  Class PickNumber



#include "PickNumber.inl"



    }  //  Namespace Random

}  //  Namespace Universe



#endif  // PICKNUMBER_HPP