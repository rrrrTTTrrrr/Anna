#ifndef ASSERT_HPP
#define ASSERT_HPP


#include "../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  // Macro DEBUG_TOOL, Macro COMMA
#include "../Exception/Exception.hpp"  //  Class Exception
#include "../../../../Content/Metaprogramming/Types/CompareTypes/CompareTypes.hpp"  //  Class CompareTypes


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe
{

    namespace Error
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



    	// The following macros wrap all the required functionality of the exceptions and assert to make as much things automtaic and they should be used to
    	// test for error situations :
        

        // Use this macro to assert that the result of the expression is true, and if it is false throw an exception
    	//
        #define Assert_MACRO( Expression, ErrorMessage ) Error::Assert< Error::Exception >::True( Expression, __FILE__, __FUNCTION__, __LINE__, ErrorMessage )


        // Use this macro to assert that the result of the expression is true, inside an object test method, and if it is false throw an exception
        //
        #define Assert_Test_MACRO( Expression ) Error::Assert< Error::Exception >::True( Expression, __FILE__, __FUNCTION__, __LINE__, "Test failed" )

        
        // Use this macro to assert that the pointer is not NULL, and if it is throw an exception
        //
        #define AssertPointer_MACRO( PointerToAssert ) Error::Assert< Error::Exception >::Pointer< decltype( PointerToAssert ) >( PointerToAssert, __FILE__, __FUNCTION__, __LINE__ )


        // Use this macro to assert that the given size is larger then 0, and if it is not throw an exception
        //
        #define AssertSizeIsLargerThenZero_MACRO( Size ) Error::Assert< Error::Exception >::True( ( Size > 0 ), __FILE__, __FUNCTION__, __LINE__, "This size should be larger then 0" )


        // Use this macro to assert that this instance which is an object with the method 'Size' has a size larger then 0, and if it is 0 or lower throw an exception
        //
        #define AssertThisInstanceSizeIsLargerThenZero_MACRO Error::Assert< Error::Exception >::True( ( this->Size() > 0 ), __FILE__, __FUNCTION__, __LINE__, "This instance should have a size larger then 0" )


        // Use this macro to assert that an instance of an object with the method 'Size' has a size larger then 0, and if it is 0 or lower throw an exception
        //
        #define AssertInstanceSizeIsLargerThenZero_MACRO( Instance ) Error::Assert< Error::Exception >::True( ( Instance.Size() > 0 ), __FILE__, __FUNCTION__, __LINE__, "The instance should have a size larger then 0" )


        // Use this macro to assert that the index is smaller then a certain limit, and if not throw an exception
        //
        #define AssertIndexIsBelowCertainLimit_MACRO( Index, Limit ) Error::Assert< Error::Exception >::True( ( Index < Limit ), __FILE__, __FUNCTION__, __LINE__, "The given index should be smaller then the limit" )


        // Use this macro to assert that the index is equal or smaller then a certain limit, and if not throw an exception
        //
        #define AssertIndexIsEqualOrBelowCertainLimit_MACRO( Index, Limit ) Error::Assert< Error::Exception >::True( ( Index <= Limit ), __FILE__, __FUNCTION__, __LINE__, "The given index should be equal or smaller then the limit" )


        // Use this macro to assert that the sum of an index plus some size is equal or smaller then a certain limit, and if not throw an exception
        //
        #define AssertThatTheSumOfTheIndexPlusTheSizeIsEqualOrBelowCertainLimit_MACRO( Index, Size, Limit ) Error::Assert< Error::Exception >::True( ( ( Index + Size ) <= Limit ), __FILE__, __FUNCTION__, __LINE__, "The sum of the given index plus the size should be equal or smaller then the limit" )



    	// Class Information :
    	//
    	//  Purpose :
    	//
    	//		This object purpose is to allow better interface for checking error conditions and reporting them. It should not be used directly but through the
    	//		macros provided above
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
    	template< typename ExceptionType >
    	class Assert
    	{
    	public:


            // The following are type definitions of the object and all the provided template arguments :


			// Create a type definition for the object itself
			using ObjectType = Assert< ExceptionType >;

			// Create a type definition for the first template argument
			using FirstTemplateArgumentType = ExceptionType;


			// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions
			// only have access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only
			// purpose then of declaring a static function is when a private static data member needs to be manipulated, or some functionality needed that
			// does not involve the non static data members


            // Method Information :
            //
            //  Description :
            //
            //      Use to check if the given pointer is NULL, then throw an exception
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. pointer - the pointer that needs to be checked
            //          2. fileName - an ascii string with the file name from which the exception was thrown
            //          3. functionName - an ascii string with the function name from which the exception was thrown
            //          4. lineNumber - the number of line from which the exception was thrown
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
            //      1. The given pointer to the file name should not be NULL
            //      2. The given pointer to the function name should not be NULL
            //      3. 
            //
            //  Possible errors :
            //
            //      They will come
            //
            template< typename PointerType >
            static inline void Pointer( PointerType pointer, const char* fileName, const char* functionName, SignedInteger32bits lineNumber );


            // Method Information :
            //
            //  Description :
            //
            //      Use to check if the expression result is true, then throw an exception
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. expressionResult - the result of the expression which could be true or false
            //          2. fileName - an ascii string with the file name from which the exception was thrown
            //          3. functionName - an ascii string with the function name from which the exception was thrown
            //          4. lineNumber - the number of line from which the exception was thrown
            //          4. errorMessage - the memory address of the user error message
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
            //      1. The given pointer to the file name should not be NULL
            //      2. The given pointer to the function name should not be NULL
            //      3. The given pointer to the error message should not be NULL
            //      4. 
            //
            //  Possible errors :
            //
            //      They will come
            //
            static inline void True( Boolean expressionResult, const char* fileName, const char* functionName, SignedInteger32bits lineNumber, const char* errorMessage );


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
			NoInstances_MACRO( Assert )


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


		};  //  Class Assert




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************


































        // Method Information :
        //
        //  Description :
        //
        //      Use to check if the given pointer is NULL, then throw an exception
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. pointer - the pointer that needs to be checked
        //          2. fileName - an ascii string with the file name from which the exception was thrown
        //          3. functionName - an ascii string with the function name from which the exception was thrown
        //          4. lineNumber - the number of line from which the exception was thrown
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
        //      1. The given pointer to the file name should not be NULL
        //      2. The given pointer to the function name should not be NULL
        //      3. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename ExceptionType >
        template< typename PointerType >
        inline void Assert< ExceptionType >::Pointer( PointerType pointer, const char* fileName, const char* functionName, SignedInteger32bits lineNumber )
        {

            // Assert that the pointer is not NULL, and if it does throw an exception
            if ( pointer == nullptr )
            {
                throw( ExceptionType( fileName, functionName, lineNumber, "The given pointer is NULL" ) );
            }

        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to check if the expression result is true, then throw an exception
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. expressionResult - the result of the expression which could be true or false
        //          2. fileName - an ascii string with the file name from which the exception was thrown
        //          3. functionName - an ascii string with the function name from which the exception was thrown
        //          4. lineNumber - the number of line from which the exception was thrown
        //          4. errorMessage - the memory address of the user error message
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
        //      1. The given pointer to the file name should not be NULL
        //      2. The given pointer to the function name should not be NULL
        //      3. The given pointer to the error message should not be NULL
        //      4. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename ExceptionType >
        inline void Assert< ExceptionType >::True( Boolean expressionResult, const char* fileName, const char* functionName, SignedInteger32bits lineNumber, const char* errorMessage )
        {

            // Assert that the expression result is true, and if not throw an exception
            if ( expressionResult == false )
            {
                throw( ExceptionType( fileName, functionName, lineNumber, errorMessage ) );
            }

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
		template< typename ExceptionType >
		inline void Assert< ExceptionType >::AssertTemplateArgumentsRequirementsDuringCompileTime__Private() const
		{
			// This method will contain as much as neccessary compile time assertions to check that the given template arguments pass the requirements
			CompileTimeAssert( ( CompareTypes< Exception, ExceptionType >::Value() == true ), "Error::Assert failed - the given type should not be used as an exception" );
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
    		//          NONE
    		//
    		//      Information returned to the user :
    		//
    		//          NONE
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
    		template< typename ExceptionType >
    		void Assert< ExceptionType >::Test()
    		{

    			// Create a test pointer
    			Boolean* pointer = 0UL;

                try
                {
                    // Throw an exception
                    AssertPointer_MACRO( pointer );
                }
                catch ( const Exception& exception )
                {
                    exception.TellMe();
                }

                try
                {
                    // Throw an exception
                    Assert_MACRO( false, "Fuckkkkkkkkk" );
                }
                catch ( const Exception& exception )
                {
                    exception.TellMe();
                }

    		}

    	)  //  End of debug tool







        // Checks ths current state of errno and if it not set to EINTR return with the given error value
        #define RETURN_THE_GIVEN_NUMBER_IF_ERNNO_IS_NOT_SET_TO_EINTR( NUMBER ) if ( ( EINTR != errno ) ) { return ( NUMBER ); }

        // Checks ths current state of errno and if it not set to EINTR returns
        #define RETURN_IF_ERNNO_IS_NOT_SET_TO_EINTR() if ( ( EINTR != errno ) ) { return; }

        // Checks ths current state of errno and if it not set to EINTR will break the loop
        #define BREAK_LOOP_IF_ERNNO_IS_NOT_SET_TO_EINTR() if ( ( EINTR != errno ) ) { break; }

        // Use this to check if the return status from an operation is not equal to 0. If it
        // returns a different value an error message is printed with errno, and return error 1
        #define DISPLAY_ERROR_MESSAGE_WITH_ERRNO_AND_RETURN_ERROR_IF_OPERATION_RETURN_STATUS_IS_NOT_0( RETURN_STATUS ) if ( ( 0 != RETURN_STATUS ) ) { perror( "Operation failed" ); return( 1 ); }




    }  //  Namespace Error

}  //  Namespace Universe


#endif  // ASSERT_HPP