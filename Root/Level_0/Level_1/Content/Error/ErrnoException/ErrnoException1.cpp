#ifndef  ERRNOEXCEPTION_CPP
#define  ERRNOEXCEPTION_CPP


#include "ErrnoException.hpp"


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include <iostream>  //  Class std::cout, Class std::endl
#endif


namespace Universe 
{

    namespace ErrorHandling
    {


    	// Forward declarations :
    	//
    	//  NONE
    	//


























//  ***************************************************************   PUBLIC METHODS IMPLEMENTATION - INTERFACE   ***************************************************************


































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
        void ErrnoException::Initiate( const char* throwingFunctionInformation )
        {
            // Create a temporary instance of the this object
            ErrnoException temporary( throwingFunctionInformation );

            // Swap between this instance and the temporary one
            Swap( temporary );
        }
































//	**************************************************************   PRIVATE METHODS IMPLEMENTATION   **********************************************************






































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
        const char* ErrnoException::CreateErrorMessageWithErrno_Private( const char* throwingFunctionInformation )
        {
            // This object will store the address of the error message
            char* errorMessage = 0;

            // This object will store the total size of the error message
            UnsignedInteger64bits errorMessageSize = 0;

            // Create an object to store the length of the throwing function information
            UnsignedInteger64bits throwingFunctionInformationSize = 0;

            // Create an object to store the length of the errno error message
            UnsignedInteger64bits errnoErrorMessageSize = 0;

            // This object will be used to determine the current character that needs to be set in the error message
            UnsignedInteger64bits errorMessageIndex = 0;

            // Get a pointer to the text describing the current error
            const char* errnoErrorMessage = strerror( errno );

            // Loop until the errno error message is exhausted to find the size, use the errno error message size as index to the errno error message string
            while ( errnoErrorMessage[ errnoErrorMessageSize ] != 0 )
            {
                // Increase the errno error message size by 1
                errnoErrorMessageSize += 1;
            }
            
            // Verify that the pointer to the throwing function information is not NULL
            if ( throwingFunctionInformation != 0 )
            {

                // Loop until the throwing function information is exhausted to find the size of it
                while ( throwingFunctionInformation[ throwingFunctionInformationSize ] != 0 )
                {
                    // Increase the throwing function information size by 1
                    throwingFunctionInformationSize += 1;
                }

                // Set the error message size don't forget to add 1 to the size for the NULL terminator. Additional 3 are for the text " - " between the throwing function 
                // information and the errno error message
                errorMessageSize = ( throwingFunctionInformationSize + errnoErrorMessageSize + 4 );

                // Allocate memory space for the error message 
                errorMessage = new char[ errorMessageSize ];

                // Loop until the throwing function information is exhausted
                while ( errorMessageIndex < throwingFunctionInformationSize )
                {
                    // Copy current ascii charcter
                    errorMessage[ errorMessageIndex ] = throwingFunctionInformation[ errorMessageIndex ];        

                    // Increase the error message index by 1
                    errorMessageIndex += 1;
                }

            }
            else
            {
                // Set the error message size don't forget to add 1 to the size for the NULL terminator. Additional 3 are for the text " - " between the throwing function 
                // information and the errno error message
                errorMessageSize = ( 46 + errnoErrorMessageSize + 4 );

                // Allocate memory space for the error message 
                errorMessage = new char[ errorMessageSize ];

                // There is no information on the throwing function, therefore the following text will be sdded instead
                const char* noThrowingFunctionInformation = "THROWING FUNCTION INFORMATION WAS NOT SUPPLIED";

                // Loop until the throwing function information is exhausted
                while ( errorMessageIndex < 46 )
                {
                    // Set current ascii charcter
                    errorMessage[ errorMessageIndex ] = noThrowingFunctionInformation[ errorMessageIndex ];

                    // Increase the error message index by 1
                    errorMessageIndex += 1;      
                }

            }

            // Set the text " - " between the throwing function information and the errno error message
            errorMessage[ errorMessageIndex++ ] = ' ';
            errorMessage[ errorMessageIndex++ ] = '-';
            errorMessage[ errorMessageIndex++ ] = ' ';

            // Loop until the error message is exhausted to find the size, use the error message size as index to the error message string
            for ( UnsignedInteger64bits errnoErrorMessageIndex = 0 ; errnoErrorMessageIndex < errnoErrorMessageSize ; ++errnoErrorMessageIndex )
            {
                // Set current ascii charcter
                errorMessage[ errorMessageIndex ] = errnoErrorMessage[ errnoErrorMessageIndex ];

                // Increase the error message index by 1
                errorMessageIndex += 1;
            }

            // Set the last entry of the error message copy string to NULL terminator
            errorMessage[ errorMessageSize ] = 0;

            // Return the address of the error message copy
            return ( errorMessage );
        }


































// ****************************************************************************************   TESTING   *************************************************************************
































        // All the following methods will be added only in test mode, they are not part of the implementation, their purpose is to
        // help locate problems in the code


        DEBUG_TOOL(


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
    		void ErrnoException::Test()
            {
                // Create an instance using the default constructor
                ErrnoException testErrnoException_1;
                
                // Set new value to errno
                errno = 13;

                // Set new error message
                testErrnoException_1.Initiate( "Wow this week was harddddd!!!!!!" );

                // Create an instance
                ErrnoException testErrnoException_2( "Lilipotsss" );

                // Check if both instances match
                if ( testErrnoException_1 == testErrnoException_2 )
                {
                    std::cout << "ErrnoException::Test failed - the comparison operator does not work well" << std::endl; 
                }

                // Create an instance
                ErrnoException testErrnoException_3( "Wow this week was harddddd!!!!!!" );

                // Check if both instances match
                if ( testErrnoException_1 != testErrnoException_3 )
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

            }


        )  //  End of debug tool
















    }  //  Namespace ErrorHandling

}  //  Namespace Universe

#endif  //  ERRNOEXCEPTION_CPP





