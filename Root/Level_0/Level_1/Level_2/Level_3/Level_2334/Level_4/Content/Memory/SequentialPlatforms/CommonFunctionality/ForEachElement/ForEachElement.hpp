#ifndef FOREACHELEMENT_HPP
#define FOREACHELEMENT_HPP


#include "../../../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../Interfaces/GetAndSetDataUsingIndices_Interface/GetAndSetDataUsingIndices_Interface.hpp"  // Class GetAndSetDataUsingIndices_Interface
#include "../../../../../../Content/InvokableObjects/InvokableObject/InvokableObject.hpp"  //  Class InvokableObject


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


	namespace Memory
    {


		// Class Information :
		//
		//  Purpose :
		//
		//		Use this object to perform an action on each element of a sequential platform instance. The action should be supplied in the form
		//		of a function, method, functor or lambda expression. All must accept 2 arguments, the first one is a reference to the current entry
		//		of the sequential platform instance, and the second is the index of the current entry
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
		class ForEachElement
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
			//      Use this method to perform a certain action on all the entries of a sequential platform instance. The required action can be passed
			//		as any invokable object. This includes functions, methods, lambda expressions and functors. The invokable object will accept each time
			//		the data of one entry of the sequential platform instance, the index of it and will return a boolean, with the value true if the passing
			//		on all the entries should stop, and false if it should continue
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			1. data - a reference to a sequential platform
			//			2. action - a constant reference to an invokable object which can contain the action in any form required
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//		NONE
			//
			//  Expectations :
			//
			//		1. The sequential platform with the data should be ready 
			//		2. The sequential platform with the data should have a size larger then 0
			//		3. The invokable object instance should be ready
			//		4. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			template< typename DataType >
			static inline void Do( GetAndSetDataUsingIndices_Interface< DataType >& data, const InvokableObject< Boolean, DataType&, UnsignedInteger64bits >& action );


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to perform a certain action on all the entries of a sequential platform instance. The required action can be passed
			//		as any invokable object. This includes functions, methods, lambda expressions and functors. The invokable object will accept each time
			//		the data of one entry of the sequential platform instance, the index of it and will return a boolean, with the value true if the passing
			//		on all the entries should stop, and false if it should continue. This version is for constant sequential platform instances
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			1. data - a reference to a sequential platform
			//			2. action - a constant reference to an invokable object which can contain the action in any form required
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//		NONE
			//
			//  Expectations :
			//
			//		1. The sequential platform with the data should be ready 
			//		2. The sequential platform with the data should have a size larger then 0
			//		3. The invokable object instance should be ready
			//		4. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			template< typename DataType >
			static inline void Do( const GetAndSetDataUsingIndices_Interface< DataType >& data, const InvokableObject< Boolean, const DataType&, UnsignedInteger64bits >& action );


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
			NoInstances_MACRO( ForEachElement )


		};  //  Class ForEachElement




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************




























		// Method Information :
		//
		//  Description :
		//
		//      Use this method to perform a certain action on all the entries of a sequential platform instance. The required action can be passed
		//		as any invokable object. This includes functions, methods, lambda expressions and functors. The invokable object will accept each time
		//		the data of one entry of the sequential platform instance, the index of it and will return a boolean, with the value true if the passing
		//		on all the entries should stop, and false if it should continue
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			1. data - a reference to a sequential platform
		//			2. action - a constant reference to an invokable object which can contain the action in any form required
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		1. The sequential platform with the data should be ready 
		//		2. The sequential platform with the data should have a size larger then 0
		//		3. The invokable object instance should be ready
		//		4. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename DataType >
		inline void ForEachElement::Do( GetAndSetDataUsingIndices_Interface< DataType >& data, const InvokableObject< Boolean, DataType&, UnsignedInteger64bits >& action )
		{
            // Each method that interacts with the user directly needs to ensure that the given data is valid
            AssertInstanceIsReady_MACRO( data )
			AssertInstanceSizeIsLargerThenZero_MACRO( data )
	        AssertInstanceIsReady_MACRO( action )

			// Loop on all the entries of the sequential platform instance
			for ( UnsignedInteger64bits index = 0UL ; index < data.Size() ; ++index )
			{
				
				// Activate the invokable instance on the current entry, and check the return value, if the loop needs to stop
				if ( action( data[ index ], index ) == true )
				{
					// The loop needs to stop

					// Break the loop
					break;
				}

			}

		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to perform a certain action on all the entries of a sequential platform instance. The required action can be passed
		//		as any invokable object. This includes functions, methods, lambda expressions and functors. The invokable object will accept each time
		//		the data of one entry of the sequential platform instance, the index of it and will return a boolean, with the value true if the passing
		//		on all the entries should stop, and false if it should continue. This version is for constant sequential platform instances
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			1. data - a reference to a sequential platform
		//			2. action - a constant reference to an invokable object which can contain the action in any form required
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		1. The sequential platform with the data should be ready 
		//		2. The sequential platform with the data should have a size larger then 0
		//		3. The invokable object instance should be ready
		//		4. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename DataType >
		inline void ForEachElement::Do( const GetAndSetDataUsingIndices_Interface< DataType >& data, const InvokableObject< Boolean, const DataType&, UnsignedInteger64bits >& action )
		{
            // Each method that interacts with the user directly needs to ensure that the given data is valid
            AssertInstanceIsReady_MACRO( data )
			AssertInstanceSizeIsLargerThenZero_MACRO( data )
	        AssertInstanceIsReady_MACRO( action )

			// Loop on all the entries of the sequential platform instance
			for ( UnsignedInteger64bits index = 0UL ; index < data.Size() ; ++index )
			{
				
				// Activate the invokable instance on the current entry, and check the return value, if the loop needs to stop
				if ( action( data[ index ], index ) == true )
				{
					// The loop needs to stop

					// Break the loop
					break;
				}

			}

		}







    }  //  Namespace Memory

}  //  Namespace Universe


#endif  // FOREACHELEMENT_HPP