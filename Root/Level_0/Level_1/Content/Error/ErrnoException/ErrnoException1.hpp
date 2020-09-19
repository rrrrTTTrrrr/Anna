#ifndef  ERRNOEXCEPTION_HPP
#define  ERRNOEXCEPTION_HPP


#include <new>   //  Class std::bad_alloc
#include <iostream>  //  Class std::cout, Class std::endl
#include <cerrno>  //  Macro errno
#include <cstring>  //  Function strerror


#include "../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  // Macro DEBUG_TOOL, Macro COMMA
#include "../Exception/Exception.hpp"  //  Class Exception


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe
{

    namespace ErrorHandling
    {


        // This is used when only declaring the object in this source file will be enough to pass compilation. The implementation is given to the compiler through the
        // cpp source file that the object is nested within
        //
        // Forward declarations :
        //
        //  NONE
        //



        // There are 2 function provided by the C programming language to display the text message associated with errno :
        //
        //  1. perror - displays the string passed to it, followed by a colon and space, and then the textual representation of the current errno value
        //
        //  2. strerror - returns a pointer to the textual representation of the current error value



        // Class Information :
        //
        //  Purpose :
        //
        //      This object is a package sent up in the function stack to describe an exception from known behavior. This object should be used when dealing with linux system
        //      calls that write their error codes to errno. Every function that can deal with the condition should catch it, and deal with it. If non of the functions will 
        //      catch the exception the executing will terminate. The termination method can be set to ensure clean up and such
        //
        //  Description :
        //
        //      1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by providing 3 keywords :
        //
        //              1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the obejct using the tools
        //                          presented here. This part will usually contain only methods and not data members. If a data member is public all the encapsulation is
        //                          lost, so it should be avoided in most cases
        //
        //              2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will be able to access
        //                             all the data and methods inside this part. This part will usually containt some methods and few data members
        //
        //              3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object and all the
        //                           methods the developer needed to implement the interface presented in the public part. Every method in this part will end with the
        //                           suffix __Private
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      Too many to count
        //
    	class ErrnoException : public Exception
        {
        public:


            // The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler
            // generates a basic behavior for them :


            // Method Information :
            //
            //  Description :
            //
            //      Default Constructor,
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
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline ErrnoException();

            // Method Information :
            //
            //  Description :
            //
            //      Constructor, sets the current errno value into the instance
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          throwingFunctionInformation - the name of the throwing function, better with the function scope
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
            //      1. The given pointer to the error message is not NULL
            //      2. 
            //
            //  Possible errors :
            //
            //      1. There is no more free memory space - class std::bad_alloc is thrown
            //      2.
            //
            explicit inline ErrnoException( const char* throwingFunctionInformation );


            // Method Information :
            //
            //  Description :
            //
            //      Copy constructor, will operate correctly even if the other instance is in default state or self assignment
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          other - a reference to the instance that should be copied
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
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline ErrnoException( const ErrnoException& other );


            // Method Information :
            //
            //  Description :
            //
            //      Assignment operator, can handle with self assignment and instances in default state
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          other - a reference to the instance that should be copied
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      A reference to this instance
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline ErrnoException& operator=( const ErrnoException& other );


            // Method Information :
            //
            //  Description :
            //
            //      Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances in default state
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          other - a reference to the instance that should be moved
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
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline ErrnoException( ErrnoException&& other );


            // Method Information :
            //
            //  Description :
            //
            //      Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          other - a reference to the instance that should be moved
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      A reference to this instance
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline ErrnoException& operator=( ErrnoException&& other );


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to initate the instance
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          throwingFunctionInformation - the name of the throwing function, better with the function scope
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
            //      1. The given pointer to the error message is not NULL
            //      2. 
            //
            //  Possible errors :
            //
            //      1. There is no more free memory space - class std::bad_alloc is thrown
            //      2.
            //
            void Initiate( const char* throwingFunctionInformation );


            // Method Information :
            //
            //  Description :
            //
            //      Destructor, does not throw any exceptions
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
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
    		virtual ~ErrnoException() = default;


            DEBUG_TOOL(


        	    // This part of the class is dedicated for testing :


        		// Method Information :
        		//
        		//  Description :
        		//
        		//      This method is used to test the object
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
        		//  Possible errors :
        		//
        		//      They will come
        		//
        		static void Test();


            )  //  End of debug tool


        private:


            // The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
            // rather help implement it :


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to create the error message with the text describing the current errno
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          throwingFunctionInformation - the name of the throwing function, better with the function scope
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      The address of the new copy of the error message
            //
            //  Expectations :
            //
            //      1. The given pointer to the error message is not NULL
            //      2. 
            //
            //  Possible errors :
            //
            //      1. There is no more free memory space - class std::bad_alloc is thrown
            //      2.
            //
            const char* CreateErrorMessageWithErrno_Private( const char* throwingFunctionInformation );


    	};  //  Class ErrnoException











































//	****************************************************************   END PART OF DECLRATIONS, IMPLMENTATION TIME   ************************************************************












































        // Method Information :
        //
        //  Description :
        //
        //      Default Constructor,
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
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
    	inline ErrnoException::ErrnoException() :
        Exception()
        {}


    	// Method Information :
    	//
    	//  Description :
    	//
    	//   	Constructor, sets the current errno value into the instance
    	//
    	//  Required arguments :
    	//
    	//		User information needed :
    	//
        //          throwingFunctionInformation - the name of the throwing function, better with the function scope
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
        //      1. The given pointer to the error message is not NULL
        //      2. 
        //
        //  Possible errors :
        //
        //      1. There is no more free memory space - class std::bad_alloc is thrown
        //      2.
        //
    	inline ErrnoException::ErrnoException( const char* throwingFunctionInformation ) :
        Exception( CreateErrorMessageWithErrno_Private( throwingFunctionInformation ) )
        {}


        // Method Information :
        //
        //  Description :
        //
        //      Copy constructor, will operate correctly even if the other instance is in default state or self assignment
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          other - a reference to the instance that should be copied
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
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
    	inline ErrnoException::ErrnoException( const ErrnoException& other ) :
        Exception( other )
        {}


        // Method Information :
        //
        //  Description :
        //
        //      Assignment operator, can handle with self assignment and instances in default state
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          other - a reference to the instance that should be copied
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A reference to this instance
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline ErrnoException& ErrnoException::operator=( const ErrnoException& other )
        {
            // Create a copy of the other instance
            ErrnoException copyOfOther( other );

            // Swap between this instance and the copy of the other one, this will leave the copy instance with the old data, and it will be deleted
            Swap( copyOfOther );

            // Return a reference to this instance
            return ( *this );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances in default state
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          other - a reference to the instance that should be moved
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
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline ErrnoException::ErrnoException( ErrnoException&& other ) :
        ErrnoException()
        {
            // Swap between this instance, which is in default state, and the other one
            Swap( other );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          other - a reference to the instance that should be moved
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A reference to this instance
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline ErrnoException& ErrnoException::operator=( ErrnoException&& other )
        {
            // Create a default constructed instance
            ErrnoException defaultConstructedInstance;

            // Swap between the temporary instance, which is in default state, and the other instance, this will leave the other instance in default state
            defaultConstructedInstance.Swap( other );

            // Swap between this instance and the temporary one
            Swap( defaultConstructedInstance );

            // Return a reference to this instance
            return ( *this );
        }














    }  //  Namespace ErrorHandling

}  //  Namespace Universe



#endif  // ERRNOEXCEPTION_HPP