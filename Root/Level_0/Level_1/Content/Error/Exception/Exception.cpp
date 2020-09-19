#ifndef EXCEPTION_CPP
#define EXCEPTION_CPP


#include "Exception.hpp"


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



        void Exception::Reset()
        {
            // Remove the formatted error message by setting all the entries to 0
            for ( UnsignedInteger64bits formattedErrorMessageIndex = 0UL ; ( member_formattedErrorMessage[ formattedErrorMessageIndex ] != 0 ) || ( formattedErrorMessageIndex < 512 ) ; ++formattedErrorMessageIndex )
            {
                // Set the current entry to 0
                member_formattedErrorMessage[ formattedErrorMessageIndex ] = 0;
            }
        }


        void Exception::Initiate( const char* fileName, const char* functionName, SignedInteger32bits lineNumber, const char* errorMessage )
        {
            // Create a temporary instance of the this object
            Exception temporary( fileName, functionName, lineNumber, errorMessage );

            // Swap between this instance and the temporary one
            Swap( temporary );
        }



//  ************************************************************************   OPERATORS IMPLEMENTATION   ***********************************************************************



        bool Exception::operator==( const Exception& other ) const
        {

            // Check if both of the instances are has no valid error messages
            if ( ( member_formattedErrorMessage == 0 ) && ( other.member_formattedErrorMessage == 0 ) )
            {
                // The 2 instances has no valid error message so they match
                return ( true );
            }

            // Check if only 1 of the instances has no valid error message which means that they don't match
            if ( ( member_formattedErrorMessage == 0 ) || ( other.member_formattedErrorMessage == 0 ) )
            {
                // One instance has no valid error message while the other doesn't which means the instances don't match
                return ( false );
            }

            // Create an object to store the index on the error message
            UnsignedInteger64bits errorMessageIndex = 0;

            // Check if the 2 error messages are the same
            while ( ( member_formattedErrorMessage[ errorMessageIndex ] != 0 ) || ( other.member_formattedErrorMessage[ errorMessageIndex ] != 0 ) )
            {

                // Check if the character is the same in both of the objects
                if ( member_formattedErrorMessage[ errorMessageIndex ] != other.member_formattedErrorMessage[ errorMessageIndex ] )
                {
                    // The error messages are not the same
                    return ( false );
                }

                // Increase the index on the error message by 1
                errorMessageIndex += 1;
            }

            // Check the reason for the end of the loop

            // Check if both of the error messages reached the end, which means they are the same
            if ( ( member_formattedErrorMessage[ errorMessageIndex ] != 0 ) || ( other.member_formattedErrorMessage[ errorMessageIndex ] != 0 ) )
            {
                // The error messages are not the same
                return ( false );
            }

            // If control reached here then the error messages are the same
            return ( true );
        }



//	********************************************************************   PRIVATE METHODS IMPLEMENTATION   *********************************************************************



        void Exception::FormatErrorMessage_Private( const char* fileName, const char* functionName, SignedInteger32bits lineNumber, const char* errorMessage )
        {

            // Check that the pointers to the file name and function name are not NULL
            if ( ( fileName == 0UL ) || ( functionName == 0UL ) )
            {
                // At least one of the pointers is NULL

                // Return without doing nothing
                return;
            }

            // This object will store the line number digits as a string
            char lineNumberString[5] = {0};

            // Convert the line number integer into a string of digits
            AsciiStringAndIntegers::IntegerToStringOfDigits< SignedInteger32bits >( lineNumberString, lineNumber );

            // Calculate the size of the given ascii strings
            UnsignedInteger64bits fileNameSize = AsciiStringAndIntegers::AsciiStringSize( fileName );
            UnsignedInteger64bits functionNameSize = AsciiStringAndIntegers::AsciiStringSize( functionName );
            UnsignedInteger64bits lineNumberSize = AsciiStringAndIntegers::AsciiStringSize( lineNumberString );

            // Copy the file name to the beginning of the error message
            AsciiStringAndIntegers::CopyAsciiString( fileName, member_formattedErrorMessage );

            // Add the charcters ' : ' after the file name
            member_formattedErrorMessage[ fileNameSize ] = ' ';
            member_formattedErrorMessage[ fileNameSize + 1UL ] = ':';
            member_formattedErrorMessage[ fileNameSize + 2UL ] = ' ';

            // Next copy the function name into the error message
            AsciiStringAndIntegers::CopyAsciiString( functionName, ( member_formattedErrorMessage + fileNameSize + 3UL ) );

            // Add the charcters ' : ' after the function name
            member_formattedErrorMessage[ fileNameSize + functionNameSize + 3UL ] = ' ';
            member_formattedErrorMessage[ fileNameSize + functionNameSize + 4UL ] = ':';
            member_formattedErrorMessage[ fileNameSize + functionNameSize + 5UL ] = ' ';

            // Next copy the line number into the error message
            AsciiStringAndIntegers::CopyAsciiString( lineNumberString, ( member_formattedErrorMessage + fileNameSize + functionNameSize + 6UL ) );

            // Add the charcters ' - ' after the line number
            member_formattedErrorMessage[ fileNameSize + functionNameSize + lineNumberSize + 6UL ] = ' ';
            member_formattedErrorMessage[ fileNameSize + functionNameSize + lineNumberSize + 7UL ] = '-';
            member_formattedErrorMessage[ fileNameSize + functionNameSize + lineNumberSize + 8UL ] = ' ';
            
            // Verify that the pointer to the user error message is not NULL
            if ( errorMessage == 0UL )
            {
                // The given pointer is NULL 

                // Set that there is no error message
                AsciiStringAndIntegers::CopyAsciiString( "No error message was provided", ( member_formattedErrorMessage + fileNameSize + functionNameSize + lineNumberSize + 9UL ) );
            }
            else
            {
                // There is a uasr error message

                // Add user error message
                AsciiStringAndIntegers::CopyAsciiString( errorMessage, ( member_formattedErrorMessage + fileNameSize + functionNameSize + lineNumberSize + 9UL ) );
            }

        }



// *********************************************************************************   TESTING   ********************************************************************************



		DEBUG_TOOL(

			void Exception::Test()
			{
                // Create an instance using the default constructor
                Exception testException_1;
            
                // Set new error message
                testException_1.Initiate( __FILE__, __FUNCTION__, __LINE__, "Wow this week was harddddd!!!!!!" );

                // Throw the exception and catch it
                try
                {
                    throw( testException_1 );
                }
                catch ( const Exception& exception )
                {
                    exception.TellMe();
                }

                // Create an instance
                Exception testException_2( __FILE__, __FUNCTION__, __LINE__, "Wow this week was harddddd!!!!!!" );

                // Throw the exception and catch it
                try
                {
                    throw( testException_2 );
                }
                catch ( const Exception& exception )
                {
                    exception.TellMe();
                }

			}

		)  //  End of debug tool



	}  //  Namespace Error


}  //  Namespace Universe


#endif  //  EXCEPTION_CPP





