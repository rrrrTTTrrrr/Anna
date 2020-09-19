#ifndef INITIALIZECONSTANTARRAYUSINGMETHOD_HPP
#define INITIALIZECONSTANTARRAYUSINGMETHOD_HPP


#include "../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../../../../TestBranch/TestingTools/Functions/TestFunctions.hpp"  //  Class TestFunctions
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



	// Template Class Information :
	//
	//  Purpose :
	//
	//		This object comes to solve a problem. When variables are declared constant, they will be initialized once and can not be changed from that
	//		moment. This object allows to initialize an array of types in a more complex manner then initializion list, which allows using one
	//		instance to initialize all the entries, or to write the value for each entry, which is not practiacal with large arrays. To conclude, 
	//		use this object when a a constant array is used, for an object or inside a function if the initializion list behavior is not enough.
	//		It will act as any built in array, provides access to the entries, and the ability to take its address
	//
	//  Description :
	//
	// 		1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
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
	//			1. Type - any type
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	template< typename Type, UnsignedInteger64bits ArraySize >
	class InitializeConstantArrayUsingMethod NotForInheritance
	{
	public:


		// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
		// the compiler generates a basic behavior for them if possible :


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
		//          initializeMethodMemoryAddress - this method will be used to initialize the primitive types array inside this instance
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	NONE
		//
		//  Expectations :
		//
		//		1. The give pointer to the method is not NULL
	    //      2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		explicit inline InitializeConstantArrayUsingMethod( void (*initializeMethodMemoryAddress)( Type* memoryAddress, UnsignedInteger64bits arraySize ) );


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
		inline ~InitializeConstantArrayUsingMethod() = default;


		// The following methods give access and manipulate the data inside this object :


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to get the size of the array
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
        //      The size of the array 
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline UnsignedInteger64bits Size() const;


		// The following methods declare the overloaded operators for the object :


        // Method Information :
        //
        //  Description :
        //
        //      This method will be used to allow explicit ( through static cast ) or implicit conversion of the this instance to the memory address of the 
        //		array inside
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
        //      There is no written return type, but it will return a pointer to the array inside this instance
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
	    inline operator const Type*() const;


	    // Method Information :
	    //
	    //  Description :
	    //
	    //      Use this operator to get a constant refernce to a specific entry
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
	    //			index - this will be used to determine the required entry in the array
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //		A constant refernce to the instance in the entry
	    //
	    //  Expectations :
	    //
	    //      1. The given index is in the range of the array indexes
	    //		2.
	    //
	    //  Possible errors :
	    //
	    //      They will come
	    //
	    inline const Type& operator[]( UnsignedInteger64bits index ) const;


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


        // Disable all copy and move related methods
        DisableCopyAndMove_MACRO( InitializeConstantArrayUsingMethod )


        // This object will store the constant array of types
        Type member_array[ ArraySize ];


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


	};  //  Class InitializeConstantArrayUsingMethod




































//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************




































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
	//          initializeMethodMemoryAddress - this method will be used to initialize the primitive types array inside this instance
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//   	NONE
	//
	//  Expectations :
	//
	//		1. The give pointer to the method is not NULL
    //      2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename Type, UnsignedInteger64bits ArraySize >
	inline InitializeConstantArrayUsingMethod< Type, ArraySize >::InitializeConstantArrayUsingMethod( void (*initializeMethodMemoryAddress)( Type* memoryAddress, UnsignedInteger64bits arraySize ) ) :
	member_array{ Type() }	
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid
		Assert_MACRO( ( initializeMethodMemoryAddress != 0UL ), "The given pointer to the method is 0" )

        // Invoke the given method, and provide it with memort address of the array
        (*initializeMethodMemoryAddress)( member_array, ArraySize );
	}


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to get the size of the array
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
    //      The size of the array 
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename Type, UnsignedInteger64bits ArraySize >
    inline UnsignedInteger64bits InitializeConstantArrayUsingMethod< Type, ArraySize >::Size() const
    {
        // Return the size of the array
        return ( ArraySize );
    }




































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************





































    // Method Information :
    //
    //  Description :
    //
    //      This method will be used to allow explicit ( through static cast ) or implicit conversion of the this instance to the memory address of the 
    //		array inside
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
    //      There is no written return type, but it will return a pointer to the array inside this instance
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename Type, UnsignedInteger64bits ArraySize >
    inline InitializeConstantArrayUsingMethod< Type, ArraySize >::operator const Type*() const
    {
        // Return a pointer to the array inside this instance
        return ( member_array );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Use this operator to get a constant refernce to a specific entry
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //			index - this will be used to determine the required entry in the array
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //		A constant refernce to the instance in the entry
    //
    //  Expectations :
    //
    //      1. The given index is in the range of the array indexes
    //		2.
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename Type, UnsignedInteger64bits ArraySize >
    inline const Type& InitializeConstantArrayUsingMethod< Type, ArraySize >::operator[]( UnsignedInteger64bits index ) const
    {
		// Each method that interacts with the user directly needs to ensure that the given data is valid
        Assert_MACRO( ( index < ArraySize ), "	The given index is not in the range of the array" )

        // Check if the bit in the other instance has the same state as the bit in this instance, and return the result
        return ( member_array[ index ] );
    }



































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************




































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
	template< typename Type, UnsignedInteger64bits ArraySize >
	inline void InitializeConstantArrayUsingMethod< Type, ArraySize >::AssertTemplateArgumentsRequirementsDuringCompileTime__Private() const
	{
		// This method will contain as much as neccessary compile time assertions to check that the given template arguments pass the requirements
		CompileTimeAssert( ( ArraySize > 1UL ), "Abilities::InitializeConstantArrayUsingMethod::CompileTimeAssert - The given array size should be larger then 1" );
	}

































// *********************************************************************************   TESTING   ********************************************************************************




































	DEBUG_TOOL(

		// Method Information :
		//
		//  Description :
		//
		//      This method is used to test the object. It is not part of the implementation, it is only used to find problem with the code that does implement
		//		the functionality
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			NONE
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//      1. true - if the object passed the test
		//      2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		1. An assertion failed - class Exception is thrown
		//		2. There is no more free memory space - class std::bad_alloc is thrown
		//		3. 
		//
		template< typename Type COMMA UnsignedInteger64bits ArraySize >
		void InitializeConstantArrayUsingMethod< Type COMMA ArraySize >::Test()
		{
            // Create an instance and provide it with the function to initialize the array
            static InitializeConstantArrayUsingMethod< UnsignedInteger64bits COMMA 87 > test_1( Testing::TestFunctions::TestFunction_7 );

            //Assert that the indexes were set correctly
            Assert_MACRO( ( test_1[0] == 0 ), "Test failed - 1" );
            Assert_MACRO( ( test_1[65] == 65 ), "Test failed - 2" );

            // Create another instance but now make it constant
            static const InitializeConstantArrayUsingMethod< UnsignedInteger64bits COMMA 87 > test_2( Testing::TestFunctions::TestFunction_7 );

            //Assert that the indexes were set correctly
            Assert_MACRO( ( test_2[0] == 0 ), "Test failed - 4" );
            Assert_MACRO( ( test_2[65] == 65 ), "Test failed - 5" );

            // Create another instance but now make it constant
            static const InitializeConstantArrayUsingMethod< UnsignedInteger64bits COMMA 3 > test_3( []( UnsignedInteger64bits* array, UnsignedInteger64bits size ) -> void
	        {

	        	array[0] = 89;
	        	array[1] = 99;
	        	array[2] = 109;

	        	std::cout << size << std::endl;

	        } );

            //Assert that the indexes were set correctly
            Assert_MACRO( ( test_3[0] == 89 ), "Test failed - 6" );
            Assert_MACRO( ( test_3[1] == 99 ), "Test failed - 7" );
            Assert_MACRO( ( test_3[2] == 109 ), "Test failed - 8" );
		}

	)  //  End of debug tool












}  //  Namespace Universe



#endif  // INITIALIZECONSTANTARRAYUSINGMETHOD_HPP