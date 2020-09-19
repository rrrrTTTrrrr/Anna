#ifndef ERRNOEXCEPTION_CPP
#define ERRNOEXCEPTION_CPP


#include "ErrnoException.hpp"


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe 
{

	namespace Error
    {


		// Forward declarations :
		//
		//  NONE
		//










//	***************************************************************   PUBLIC METHODS IMPLEMENTATION - INTERFACE   ***************************************************************






























        // Method Information :
        //
        //  Description :
        //
        //      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
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
        void ErrnoException::Reset()
        {
        	// Call the base exception object reset method
        	Exception::Reset();
        }


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
		//
		//  Required arguments :
		//
		//		User information needed :
		//
        //          1. fileName - an ascii string with the file name from which the exception was thrown
        //          2. functionName - an ascii string with the function name from which the exception was thrown
        //          3. lineNumber - the number of line from which the exception was thrown
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
        //      1. The given pointer to the file name is not NULL
        //      2. The given pointer to the function name is not NULL
        //      3. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		void ErrnoException::Initiate( const char* fileName, const char* functionName, SignedInteger32bits lineNumber )
		{
		    // Use the required constructor to create an instance. It will be swaped with this instance, leaving this instance with the new data. When sequence control will
		    // leave this scope it delete the old data if exist
		    ErrnoException instanceCreatedUsingTheRequiredConstructor( fileName, functionName, lineNumber );

		    // Swap between this instance and the temporary instance
		    Swap( instanceCreatedUsingTheRequiredConstructor );
		}




































// *********************************************************************************   TESTING   ********************************************************************************




































		DEBUG_TOOL(

			// Method Information :
			//
			//  Description :
			//
			//		This method is used to test the object. It is not part of the implementation, it is only used to find problem with the code that does implement
			//		the functionality
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
			//		1. true - if the object passed the test
			//		2. false - otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		1. An assertion failed - class Exception or ErrnoException is thrown
			//		2. There is no more free memory space - class std::bad_alloc is thrown
			//		3. 
			//
			void ErrnoException::Test()
			{
                // Create an instance using the default constructor
                ErrnoException testErrnoException_1;
                
                // Set new value to errno
                errno = 13;

                // Set new error message
                testErrnoException_1.Initiate( __FILE__, __FUNCTION__, __LINE__ );

                // Create an instance
                ErrnoException testErrnoException_2( __FILE__, __FUNCTION__, __LINE__ );

                // Check if both instances match
                if ( testErrnoException_1 == testErrnoException_2 )
                {
                    std::cout << "ErrnoException::Test failed - the comparison operator does not work well" << std::endl; 
                }

                // Set new value to errno
                errno = 33;

                // Create an instance
                ErrnoException testErrnoException_3( __FILE__, __FUNCTION__, __LINE__ );

                // Check if both instances match
                if ( testErrnoException_1 == testErrnoException_3 )
                {
                    std::cout << "ErrnoException::Test failed - the not comparison operator does not work well" << std::endl; 
                }

                // Throw the Errnoexception and catch it
                try
                {
                    throw( testErrnoException_1 );
                }
                catch ( const ErrnoException& Errnoexception )
                {
                    Errnoexception.TellMe();
                }

                // Create an instance
                ErrnoException testErrnoException_4( testErrnoException_3 );

                // Check if both instances match
                if ( testErrnoException_4 != testErrnoException_3 )
                {
                    std::cout << "ErrnoException::Test failed - the not comparison operator does not work well" << std::endl; 
                }

                // Throw the Errnoexception and catch it
                try
                {
                    throw( testErrnoException_4 );
                }
                catch ( const ErrnoException& Errnoexception )
                {
                    Errnoexception.TellMe();
                }

			}

		)  //  End of debug tool











	}  //  Namespace Error


}  //  Namespace Universe


#endif  //  ERRNOEXCEPTION_CPP





