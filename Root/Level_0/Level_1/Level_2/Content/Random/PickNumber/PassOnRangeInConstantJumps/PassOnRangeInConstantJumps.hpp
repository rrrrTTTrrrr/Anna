#ifndef PASSONRANGEINCONSTSNTJUMPS_HPP
#define IntegerGEINCONSTSNTJUMPS_HPP


#include "../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../Content/Object/ObjectInfrastructure/BasicObjectFunctionality/BasicObjectFunctionality.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../../Memory/Operations/Operations.hpp"
#include "../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../../../../../Content/Metaprogramming/Types/TypeCheck/Integers/TypeCheck_Integer/TypeCheck_Integer.hpp"  //  Class TypeCheck_Integer


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



		// Template Class Information :
		//
		//  Purpose :
		//
		//		Use this object to pass on the range of the provdied type, in a constant jumps
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
		class PassOnRangeInConstantJumps NotForInheritance
		{
		public:


            // Create a type definition for this object
            using SelfType = PassOnRangeInConstantJumps< IntegerType >;


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
			inline PassOnRangeInConstantJumps();


			// Method Information :
			//
			//  Description :
			//
			//		Constructor,
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. jumpSize - each time a next value will be used this will be the jump between the 2 values
			//			2. startingValue - the first value to will be returned when using the isntance
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
			explicit inline PassOnRangeInConstantJumps( IntegerType jumpSize, IntegerType startingValue = 0 );


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
			//			other - a reference to the instance that should be copied
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
			inline PassOnRangeInConstantJumps( const SelfType& other );


			// This macro will be used to all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
			// simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
			// any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
			// be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
			// macro will be used to add the following methods to each object :
			//
			//		1. Assignment operator
			//		2. Move constructor
			//		3. Move assignment operator
			//		4. Swap
			//		5. Reset
			//
			ObjectInfrastructure_MACRO( PassOnRangeInConstantJumps )


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
			inline ~PassOnRangeInConstantJumps() = default;


			// The following methods give access and manipulate the data inside this object :


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to perfrom the jump from the current value, and return a copy of the new value
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
			//		The next value in the range
			//
			//  Expectations :
			//
			//		1. The instance should be ready
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline IntegerType NextValue();


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


 			// This object will store the current value reached in the range
 			IntegerType member_currentValue;

 			// This value will store the size of the jumps between values. The largest possible jump that makes sense is half the size of the range
 			IntegerType member_jumpSize;


			// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
			// rather help implement it :


			// Method Information :
			//
			//  Description :
			//
			//      This method will be used to assert all the requirements on the template arguments provided to the object. To perform a compile time assert
			//		the C++ language provides the keyword 'static_assert', which receives an expression and an error message to display if the expression
			//		result is false. The important thing is that the expression is evaluted during compile time, and therefore if the expression is false
			//		the compilation will be terminated and the error message will be displayed. This method should not be used, because it does nothing during
			//		run time
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
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline void AssertTemplateArgumentsRequirementsDuringCompileTime__Private() const;


		};  //  Class PassOnRangeInConstantJumps



#include "PassOnRangeInConstantJumps.inl"



    }  //  Namespace Random

}  //  Namespace Universe



#endif  // PASSONRANGEINCONSTSNTJUMPS_HPP