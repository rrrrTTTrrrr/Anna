#ifndef  DIRECTORYOPERATIONS_CPP
#define  DIRECTORYOPERATIONS_CPP



#include "DirectoryOperations.hPP"




namespace Universe 
{

    namespace FileSystem
    {


        // Forward declarations :
        //
        //  NONE
        //

















//	*****************************************************************************   IMPLEMENTATION   **************************************************************************


























        // Method Information :
        //
        //  Description :
        //
        //      Use to create a new file
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //           fileNameIncludingFullPath - a reference to an ascii string object containing the path to the file ending with the file name
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      1. The open system call failed - class ErrnoException is thrown
        //      2. The close system call failed - class ErrnoException is thrown
        //		3. 
        //
        void CreateNewFile( const Encoding::AsciiString& fileNameIncludingFullPath ) throw( ErrorHandling::ErrnoException )
        {
            // Create an object to store the file descriptor of the new created file
            SignedInteger32bits fileDescriptor = 0;

            // Loop until the open system call succeeded or the error was not caused due to signal interrupt
            while ( -1 == ( fileDescriptor = open( fileNameIncludingFullPath.GetHandleToBasicTypesArray(), O_CREAT, S_IRWXU ) ) )
            {

                // Check the reason for the failure, and if it is not because a signal interrupt throw an Exception
                if ( errno != EINTR )
                {
                    // Throw an exception
                    ErrorHandling::ErrnoException( "CreateNewFile failed - " );
                }

            }

            // Now the file was created, but it is open, all there is to do is to close it

            // Loop until the close system call succeeded or the error was not caused due to signal interrupt
            while ( -1 == close( fileDescriptor ) )
            {

                // Check the reason for the failure, and if it is not because a signal interrupt throw an Exception
                if ( errno != EINTR )
                {
                    // Throw an exception
                    ErrorHandling::ErrnoException( "CreateNewFile failed - " );
                }

            }

        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to create a new file and open it
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //           fileNameIncludingFullPath - a reference to an ascii string object containing the path to the file ending with the file name
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      The file descriptor of the new created open file
        //
        //  Possible errors :
        //
        //      1. The open system call failed - class ErrnoException is thrown
        //		2.
        //
        SignedInteger32bits CreateNewFileAndOpenIt( const Encoding::AsciiString& fileNameIncludingFullPath ) throw( ErrorHandling::ErrnoException )
        {
            // Create an object to store the file descriptor of the new created file
            SignedInteger32bits fileDescriptor = 0;

            // Loop until the open system call succeeded or the error was not caused due to signal interrupt
            while ( -1 == ( fileDescriptor = open( fileNameIncludingFullPath.GetHandleToBasicTypesArray(), O_CREAT, S_IRWXU ) ) )
            {

                // Check the reason for the failure, and if it is not because a signal interrupt throw an Exception
                if ( errno != EINTR )
                {
                    // Throw an exception
                    ErrorHandling::ErrnoException( "CreateNewFileAndOpenIt failed - " );
                }

            }

            // Now the file was created, and it is open, return the file descriptor
            return ( fileDescriptor );
        }














    }  //  Namespace FileSystem

}  //  Namespace Universe


#endif  //  DIRECTORYOPERATIONS_CPP