#ifndef NEXTALIGNEDMEMORYADDRESS_HPP
#define NEXTALIGNEDMEMORYADDRESS_HPP


#include "../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../ArithmeticOperations/IsPowerOfTwo/IsPowerOfTwo.hpp"  //  Class IsPowerOfTwo


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
	//		Use this object to get the next memory address aligned to the required value, which must be a power of 2, and casted to the required
	//		pointer type
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
	//			1. PointerType - any type
	//			2. Alignment - the value the memory addres needs to be aligned to, must be a power of 2
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	template< typename PointerType, UnsignedInteger64bits Alignment >
	class NextAlignedMemoryAddress
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
		//		Use this method to get the previous memory address which is aligned to the required alignment
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          memoryAddress - the memory addres to start from
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      The next memory address from the given memory address which is aligned to the required alignment
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static inline PointerType* Get( void* memoryAddress );


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
			static void Test() __attribute__ (( __unused__ ));

		)  //  End of debug tool


	private:


		// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
		NoInstances_MACRO( NextAlignedMemoryAddress )


		// Assert all the requirements on the template arguments provided to the object. To perform a compile time assert the C++ language provides
		// the keyword 'static_assert', which receives an expression and an error message to display if the expression result is false. The important
		// thing is that the expression is evaluted during compile time, and therefore if the expression is false the compilation will be terminated
		// and the error message will be displayed. This method should not be used, because it does nothing during run time
		CompileTimeAssert( ( IsPowerOfTwo< UnsignedInteger64bits >::Check( Alignment ) == true ), "NextAlignedMemoryAddress failed - the given alignment should be a power of 2" );


	};  //  Class NextAlignedMemoryAddress



#include "NextAlignedMemoryAddress.inl"



}  //  Namespace Universe


#endif  // NEXTALIGNEDMEMORYADDRESS_HPP