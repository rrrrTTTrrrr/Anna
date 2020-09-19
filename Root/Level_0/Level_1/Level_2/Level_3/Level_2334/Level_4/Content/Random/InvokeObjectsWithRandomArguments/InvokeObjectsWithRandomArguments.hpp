#ifndef INVOKEOBJECTSWITHRANDOMARGUMENTS_HPP
#define INVOKEOBJECTSWITHRANDOMARGUMENTS_HPP


#include "../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../../../Content/InvokableObjects/InvokableObject/InvokableObject.hpp"  //  Class InvokableObject
#include "../../../../Content/InvokableObjects/FunctionAndMethodPointers/MethodPointers/MethodPointer/MethodPointer.hpp"  //  Class MethodPointer


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


	namespace Random
    {


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
		class InvokeObjectsWithRandomArguments
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
			//		Use this function to take a function pointer instance, generate random arguments, and use them to invoke the function
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			invokableObjectInstance - it can be any invokable object of the following :
			//
			//						1. Function pointer
			//						2. Functor
			//						3. Lambda expression
			//						4. Method pointer bound to specific instance
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		The return value from the object call, the return value can be void
			//
			//  Expectations :
			//
			//		1. The given invokable object instance should be ready
			//		2. 
			//
			//  Possible errors :
			//
			//		1. The invokation of the object failes and throws an exception
			//		2.
			//
			template< typename ReturnValueType, typename... ArgumentTypes >
			static inline ReturnValueType Execute( const InvokableObject< ReturnValueType, ArgumentTypes... >& invokableObjectInstance );


			// Method Information :
			//
			//  Description :
			//
			//		Use this function to take a method pointer instance, generate random arguments, and use them to invoke the method on the given instance
			//		of the object that owns the method inside the method pointer instance
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. methodPointerInstance - a method pointer instance
			//			2. instance - an instance of the object that owns the method inside the method pointer instance
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		The return value from the method call, the method can also return void
			//
			//  Expectations :
			//
			//		1. The given method pointer instance should be ready
			//		2. The given instance of the object that owns the method inside the method pointer instance should be ready
			//		3. 
			//
			//  Possible errors :
			//
			//		1. The invokation of the method failes and throws an exception
			//		2.
			//
			template< typename ObjectType, typename ReturnValueType, typename... ArgumentTypes >
			static inline ReturnValueType Execute( const MethodPointer< ObjectType, ReturnValueType,  ArgumentTypes... >& methodPointerInstance, const ObjectType& instance );


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
			NoInstances_MACRO( InvokeObjectsWithRandomArguments )


		};  //  Class InvokeObjectsWithRandomArguments




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************































		// Method Information :
		//
		//  Description :
		//
		//		Use this function to take a function pointer instance, generate random arguments, and use them to invoke the function
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			invokableObjectInstance - it can be any invokable object of the following :
		//
		//						1. Function pointer
		//						2. Functor
		//						3. Lambda expression
		//						4. Method pointer bound to specific instance
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		The return value from the object call, the return value can be void
		//
		//  Expectations :
		//
		//		1. The given invokable object instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		1. The invokation of the object failes and throws an exception
		//		2.
		//
		template< typename ReturnValueType, typename... ArgumentTypes >
		inline ReturnValueType InvokeObjectsWithRandomArguments::Execute( const InvokableObject< ReturnValueType, ArgumentTypes... >& invokableObjectInstance )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertInstanceIsReady_MACRO( invokableObjectInstance );

			// Randpmly generate all the required arguments for the function
			Tuple< ArgumentTypes... > randomlyGeneratedArgumentsToInvokeTheFunctionTuple( GenerateRandomInstance );

			// Invoke the function using the random generated arguments stored in the tuple, and return the result
			return ( invokableObjectInstance( randomlyGeneratedArgumentsToInvokeTheFunctionTuple ) );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this function to take a method pointer instance, generate random arguments, and use them to invoke the method on the given instance
		//		of the object that owns the method inside the method pointer instance
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. methodPointerInstance - a method pointer instance
		//			2. instance - an instance of the object that owns the method inside the method pointer instance
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		The return value from the method call, the method can also return void
		//
		//  Expectations :
		//
		//		1. The given method pointer instance should be ready
		//		2. The given instance of the object that owns the method inside the method pointer instance should be ready
		//		3. 
		//
		//  Possible errors :
		//
		//		1. The invokation of the method failes and throws an exception
		//		2.
		//
		template< typename ObjectType, typename ReturnValueType, typename... ArgumentTypes >
		inline ReturnValueType InvokeObjectsWithRandomArguments::Execute( const MethodPointer< ObjectType, ReturnValueType,  ArgumentTypes... >& methodPointerInstance, const ObjectType& instance )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertInstanceIsReady_MACRO( methodPointerInstance );
			AssertInstanceIsReady_MACRO( instance );

			// Randpmly generate all the required arguments for the function
			Tuple< ArgumentTypes... > randomlyGeneratedArgumentsToInvokeTheFunctionTuple( GenerateRandomInstance );

			// Invoke the function using the random generated arguments stored in the tuple, and return the result
			return ( methodPointerInstance( instance, randomlyGeneratedArgumentsToInvokeTheFunctionTuple ) );
		}







    }  //  Namespace Random

}  //  Namespace Universe


#endif  // INVOKEOBJECTSWITHRANDOMARGUMENTS_HPP