#ifndef  DIRECTORYOPERATIONS_H
#define  DIRECTORYOPERATIONS_H


#include <unistd.h>  //  Function unlink, Function rmdir, Function close
#include <dirent.h>  //  Function opendir, Function fdopendir, Function closedir
#include <fcntl.h>  //  Function open
#include <sys/stat.h>  //  Function mkdir


#include "../../../BasicUtilities/cpp_BasicUtilities.hpp"  //  Macro DEBUG_TOOL
#include "../../../Encoding/Ascii/AsciiString/AsciiString.hpp"  //  Class AsciiString


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../ErrorHandling/Exception/Exception.hpp"  //  Class Exception
#include "../../../ErrorHandling/ErrnoException/ErrnoException.hpp"  //  Class ErrnoException
#endif



// When a function name ends with the suffix IMP, the function is not part
// of the object interface ( capabilities ), it only used as aid to the
// function that it is, implementing only spsecific part

 

namespace Universe
{

    namespace FileSystem
    {


        // System call - unlink :
        //
        // The system call unlink deletes a name from the file system. If that name was the last link to a file and no process have 
        // the file open, the file is deleted and the space it was using is made available for reuse
        //
        // Syntax :
        //
        //      int unlink( const char* fileNameIncludingFullPath )
        //
        // On success, 0 is returned. On error, -1 is returned, and errno is set appropriately


        // System call - rmdir :
        //
        // The system call rmdir delets a directory, which must be empty
        //
        // Syntax :
        //
        //		int rmdir( const char* directoryNameIncludingFullPath )
        //
        // On success, 0 is returned. On error, -1 is returned, and errno is set appropriately.


        // System call - mkdir :
        //
        // The system call mkdir creates a new directory
        //
        // Syntax :
        //
        //		int mkdir( const char *newDirectoryNameIncludingFullPath, mode_t mode );
        //
        // On success, 0 is returned. On error, -1 is returned, and errno is set appropriately.



























//	******************************************************************************   DECLARATIONS   *****************************************************************************





























        
    	// Method Information :
    	//
    	//  Description :
    	//
    	// 		Use to open a directory stream
    	//
    	//  Required arguments :
    	//
        //		User information needed :
    	//
        //          directory - the directory name including the full path to it
    	//
    	//      Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//   	An handle to the open directory stream
    	//
    	//  Possible errors :
    	//
    	//		1. Opening the directory failed - class ErrnoException is thrown
    	//		2. The directory name and path is wrong
    	//		3.
    	//
    	inline DIR* OpenDirectory( const Encoding::AsciiString& directory ) throw( ErrorHandling::ErrnoException );


    	// Method Information :
    	//
    	//  Description :
    	//
    	// 		Use to open a directory stream, from a file descriptor
    	//
    	//  Required arguments :
    	//
        //		User information needed :
    	//
        //          fileDescriptor - the file descriptor for the required directory to open
    	//
    	//      Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//   	An handle to the open directory stream
    	//
    	//  Possible errors :
    	//
    	//		1. Opening the directory failed - class ErrnoException is thrown
    	//		2. The file descriptor is invalid
    	//		3.
    	//
    	inline DIR* OpenDirectoryFromFileDescriptor( int fileDescriptor ) throw( ErrorHandling::ErrnoException );


    	// Method Information :
    	//
    	//  Description :
    	//
    	// 		Use to close a directory stream
    	//
    	//  Required arguments :
    	//
        //		User information needed :
    	//
        //          directoryStream - the pointer given from the opendir system call
    	//
    	//      Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//   	NONE
    	//
    	//  Possible errors :
    	//
    	//		1. Closing the directory failed - class ErrnoException is thrown
    	//		2. The given pointer to the directory stream is NULL
    	//		3.
    	//
    	inline void CloseDirectory( DIR* directoryStream ) throw( ErrorHandling::ErrnoException );


        // Method Information :
        //
        //  Description :
        //
        //      Use to delete the given file
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
        //      1. The unlink system call failed - class ErrnoException is thrown
        //      2.     
        //
    	inline void RemoveFile( const Encoding::AsciiString& fileNameIncludingFullPath ) throw( ErrorHandling::ErrnoException );


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
        //      3. 
        //
        void CreateNewFile( const Encoding::AsciiString& fileNameIncludingFullPath ) throw( ErrorHandling::ErrnoException );


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
        //      2.
        //
        SignedInteger32bits CreateNewFileAndOpenIt( const Encoding::AsciiString& fileNameIncludingFullPath ) throw( ErrorHandling::ErrnoException );
      

        // Method Information :
        //
        //  Description :
        //
        //      Use to delete the given directory. Note - the directory must be empty
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //           directoryNameIncludingFullPath - a reference to an ascii string object containing the path to the directory ending with the directory name
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
        //      1. The rmdir system call failed - class ErrnoException is thrown
        //      2.     
        //
        inline void RemoveDirectory( const Encoding::AsciiString& directoryNameIncludingFullPath ) throw( ErrorHandling::ErrnoException );


        // Method Information :
        //
        //  Description :
        //
        //      Use to create a new directory
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //           directoryNameIncludingFullPath - a reference to an ascii string object containing the path to the directory ending with the directory name
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
        //      1. The mkdir system call failed - class ErrnoException is thrown
        //      2.     
        //
        inline void CreateNewDirectory( const Encoding::AsciiString& directoryNameIncludingFullPath ) throw( ErrorHandling::ErrnoException );































//	*************************************************************   IMPLEMENTATION   **************************************************************



































    	// Method Information :
    	//
    	//  Description :
    	//
    	// 		Use to open a directory stream
    	//
    	//  Required arguments :
    	//
        //		User information needed :
    	//
        //          directory - the directory name including the full path to it
    	//
    	//      Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//   	An handle to the open directory stream
    	//
    	//  Possible errors :
    	//
    	//		1. Opening the directory failed - class ErrnoException is thrown
    	//		2. The directory name and path is wrong
    	//		3.
    	//
    	inline DIR* OpenDirectory( const Encoding::AsciiString& directory ) throw( ErrorHandling::ErrnoException )
    	{
    		// Try to open the given directory
    		DIR* directoryStream = opendir( directory.GetHandleToBasicTypesArray() );

    		// Check if the directory opening succeded
            if ( directoryStream == 0 )
            {
                // Throw an exception
                ErrorHandling::ErrnoException( "OpenDirectory failed - " );
            }

    		// Return an handle to the directory stream
    		return ( directoryStream );
    	}


    	// Method Information :
    	//
    	//  Description :
    	//
    	// 		Use to open a directory stream, from a file descriptor
    	//
    	//  Required arguments :
    	//
        //		User information needed :
    	//
        //          fileDescriptor - the file descriptor for the required directory to open
    	//
    	//      Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//   	An handle to the open directory stream
    	//
    	//  Possible errors :
    	//
    	//		1. Opening the directory failed - class ErrnoException is thrown
    	//		2. The file descriptor is invalid
    	//		3.
    	//
    	inline DIR* OpenDirectoryFromFileDescriptor( int fileDescriptor ) throw( ErrorHandling::ErrnoException )
    	{
    		// Try to open the given directory
    		DIR* directoryStream = fdopendir( fileDescriptor );

            // Check if the directory opening succeded
            if ( directoryStream == 0 )
            {
                // Throw an exception
                ErrorHandling::ErrnoException( "OpenDirectoryFromFileDescriptor failed - " );
            }

    		// Return an handle to the directory stream
    		return ( directoryStream );
    	}


    	// Method Information :
    	//
    	//  Description :
    	//
    	// 		Use to close a directory stream
    	//
    	//  Required arguments :
    	//
        //		User information needed :
    	//
        //          directoryStream - the pointer given from the opendir system call
    	//
    	//      Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//   	NONE
    	//
    	//  Possible errors :
    	//
    	//		1. Closing the directory failed - class ErrnoException is thrown
    	//		2. The given pointer to the directory stream is NULL
    	//		3.
    	//
    	inline void CloseDirectory( DIR* directoryStream ) throw( ErrorHandling::ErrnoException )
    	{

            // Try to close the directory
            if ( -1 == closedir( directoryStream ) )
            {
                // Throw an exception
                ErrorHandling::ErrnoException( "CloseDirectory failed - " );
            }

    	}


        // Method Information :
        //
        //  Description :
        //
        //      Use to delete the given file
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
        //      1. The unlink system call failed - class ErrnoException is thrown
        //      2. 
        //
        inline void RemoveFile( const Encoding::AsciiString& fileNameIncludingFullPath ) throw( ErrorHandling::ErrnoException )
        {
        	// To remove a file from the file system, the name should be removed from the containing directory
        	// and the memory space of the file should be set free

            // Try to remove the required file from the file system
            if ( -1 == unlink( fileNameIncludingFullPath.GetHandleToBasicTypesArray() ) )
            {
                // Throw an exception
                ErrorHandling::ErrnoException( "RemoveFile failed - " );
            }

        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to delete the given directory. Note - the directory must be empty
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //           directoryNameIncludingFullPath - a reference to an ascii string object containing the path to the directory ending with the directory name
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
        //      1. The rmdir system call failed - class ErrnoException is thrown
        //      2. 
        //
        inline void RemoveDirectory( const Encoding::AsciiString& directoryNameIncludingFullPath ) throw( ErrorHandling::ErrnoException )
        {

            // Try to remove the required directory from the file system
            if ( -1 == rmdir( directoryNameIncludingFullPath.GetHandleToBasicTypesArray() ) )
            {
                // Throw an exception
                ErrorHandling::ErrnoException( "RemoveDirectory failed - " );
            }

        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to create a new directory
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //           directoryNameIncludingFullPath - a reference to an ascii string object containing the path to the directory ending with the directory name
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
        //      1. The mkdir system call failed - class ErrnoException is thrown
        //      2.     
        //
        inline void CreateNewDirectory( const Encoding::AsciiString& directoryNameIncludingFullPath ) throw( ErrorHandling::ErrnoException )
        {

            // Try to create the new directory in the file system
            if ( -1 == mkdir( directoryNameIncludingFullPath.GetHandleToBasicTypesArray(), S_IRWXU ) )
            {
                // Throw an exception
                ErrorHandling::ErrnoException( "CreateNewDirectory failed - " );
            }

        }












    }  //   Namespace FileSystem

}  //   Namespace Universe

#endif  // DIRECTORYOPERATIONS_H















