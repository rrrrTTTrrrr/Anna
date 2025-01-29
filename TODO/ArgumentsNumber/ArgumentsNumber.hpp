#ifndef ARGUMENTSNUMBER_HPP
#define ARGUMENTSNUMBER_HPP


#include "../../../../CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../IntegralConstant/IntegralConstant.hpp"  //  Class IntegralConstant


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../../ErrorHandling/Assert/Assert.hpp"  //  Class Assert
#endif


namespace Universe
{

    namespace Types
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
		//		Artifical Inteligence
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
		class ArgumentsNumber
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
			//		Use this method to get the number of arguments to the function. This method will not work if the required function is a templated function
			//		or the function is overloaded in the current context. The trick is to use the compiler ability to automatically the deduce the template
			//		arguments for template functions. This means that when using this function there is no need to provide the template arguments, because
			//		then the all point of the function will disapper, the user "does not know" the number of function arguments and their types, and wants
			//		to obtain information on the function. To conclude when using this function, there is no need to explicitly provide the template arguments
			//		and the compiler does it automatically
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			functionName - the name of the function that the number of arguments should be known
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//			The number of arguments to the function
			//
			//  Expectations :
			//
			//		1. The given function is not a template
			//		2. The given function was not overloaded in the same scope
			//		3. 
			//
			//  Possible errors :
			//
			//		NONE
			//
			template< typename ReturnValueType, typename... FunctionArgumentsTypes >
			static constexpr IntegralConstant< UnsignedInteger64bits, sizeof...( FunctionArgumentsTypes ) > Function( ReturnValueType (*)( FunctionArgumentsTypes... ) );


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
			NoInstances( ArgumentsNumber )


		};  //  Class ArgumentsNumber




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



































		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the number of arguments to the function. This method will not work if the required function is a templated function
		//		or the function is overloaded in the current context. The trick is to use the compiler ability to automatically the deduce the template
		//		arguments for template functions. This means that when using this function there is no need to provide the template arguments, because
		//		then the all point of the function will disapper, the user "does not know" the number of function arguments and their types, and wants
		//		to obtain information on the function. To conclude when using this function, there is no need to explicitly provide the template arguments
		//		and the compiler does it automatically
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			functionName - the name of the function that the number of arguments should be known
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//			The number of arguments to the function
		//
		//  Expectations :
		//
		//		1. The given function is not a template
		//		2. The given function was not overloaded in the same scope
		//		3. 
		//
		//  Possible errors :
		//
		//		NONE
		//
		template< typename ReturnValueType, typename... FunctionArgumentsTypes >
		constexpr IntegralConstant< UnsignedInteger64bits, sizeof...( FunctionArgumentsTypes ) > ArgumentsNumber::Function( ReturnValueType (*)( FunctionArgumentsTypes... ) )
		{
			// Return an integral constant instance containing the number of arguments to the function
			return ( IntegralConstant< UnsignedInteger64bits, sizeof...( FunctionArgumentsTypes ) >{} );
		}





































//	**********************************************************   TEMPLATE OR INLINE PROTECTED METHODS IMPLEMENTATION   **********************************************************




































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************




































    }  //  Namespace Types

}  //  Namespace Universe


#endif  // ARGUMENTSNUMBER_HPP