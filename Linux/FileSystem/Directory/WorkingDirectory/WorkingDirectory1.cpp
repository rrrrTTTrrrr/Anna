#ifndef  WORKINGDIRECTORY_CPP
#define  WORKINGDIRECTORY_CPP


#include "WorkingDirectory.hpp"


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../ErrorHandling/Assert/Assert.hpp"  //  Class Assert
#endif


namespace Universe 
{

    namespace FileSystem
    {


        // Forward declarations :
        //
        //  NONE
        //




















//  **************************************************************   PUBLIC METHODS IMPLEMENTATION - INTERFACE   ****************************************************************






















    	// Method Information :
        //
        //  Description :
        //
        //   	Assignment operator, handle self assignment correctly. . Important note - it will only copy the required
        //		directory from the other object and not the all state of the other object. The purpose then of copying in this
        //      class is to work on the same directory
        //
        //  Required arguments :
        //
        //   	User information needed :
        //
        //          other - a reference to the object that should be copied
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //   	A reference to this object 
        //
    	//  Possible errors :
        //
        //      1. There is no more free memory space - class std::bad_alloc is thrown
        //      2. 
        //
        WorkingDirectory& WorkingDirectory::operator=( const WorkingDirectory& other ) throw( std::bad_alloc )
        {

            // Check that this is not self assignment
            if ( this != &other )
            {
                // This is not self assignment

                // Check if the other object is in default state
                if ( true == other.DefaultState() )
                {
                    // The other object is in default state

                    // Release all the resources of this object
                    DeleteResourcesAndSetToDefaultState();

                    // Nothing else needs to be done, return a reference to this object
                    return ( *this );
                }

                // Copy the other object resources

                // Copy the directory name
                m_workingDirectory = other.m_workingDirectory;
            }

            // Return a reference to this object
            return ( *this );
        }


        // Method Information :
        //
        //  Description :
        //
        //   	Move Assignment operator, handle self assignment correctly. take the resources from the instance given in the rvalue reference,
        //  	and set it to the default state. Will operate correctly even if the other object is in default state
        //
        //  Required arguments :
        //
        //   	User information needed :
        //
        //          other - a reference to the object that should be moved
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //   	A reference to this object
        //
    	//  Possible errors :
        //
        //      They will come
        //
        WorkingDirectory& WorkingDirectory::operator=( WorkingDirectory&& other ) throw( std::bad_alloc )
        {

            // Check that this is not self assignment
            if ( this != &other )
            {
                // This is not self assignment

                // Release all the resources of this object

                // Check if the other object is in default state
                if ( true == other.DefaultState() )
                {
                    // The other object is in default state

                    // Release all the resources of this object
                    DeleteResourcesAndSetToDefaultState();

                    // Nothing else needs to be done, return a reference to this object
                    return ( *this );
                }

                // Take the other object resources

                // Take the directory name
                m_workingDirectory = other.m_workingDirectory;

                // Set the other object to default state
                other.SetToDefaultState();
            }

            // Return a reference to this object
            return ( *this );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to check if the working directory is empty
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //           NONE
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
        //      1. The object is in default state
        //      2. Failed to open the working directory - class ErrnoException is thrown
        //      3. Failed to close the working directory
        //      4. 
        //
        bool WorkingDirectory::Empty() const throw( ErrorHandling::ErrnoException )
        {
            // Open the working directory
            m_workingDirectoryStream = OpenDirectory( m_workingDirectory );

            // Create an object to store the number of entries in the directory
            UnsignedInteger64bits numberOfEntriesInWorkingDirectroy = 0;

            // Loop until the directory has ended ( the function readdir will return NULL )
            for ( SetNextEntryIMP() ;  m_currentEntryInWorkingDirectory != 0 ; SetNextEntryIMP() )
            {
                // Increase the number of entries by 1
                numberOfEntriesInWorkingDirectroy += 1;
            }

            // Close the directory and set the pointers used to work with the working directory to NULL
            CloseTheWorkingDirectoryAndSetThePointersToNULLIMP();

            // Check the number of entries in the directory. If the number is larger then 2, then the 
            // directory is not empty. The reason for the number 2 is that in each directory when it 
            // is created 2 hard links are automatically added, and they are "." and "..". This means
            // that the minimum number of entries in a directory is 2
            return ( numberOfEntriesInWorkingDirectroy > 2 );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to delete the given file. Important note - the given file will be deleted only if it exist in the working directory
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //           fileToRemove - a reference to an ascii string object containing the name of the file that should be removed. Note - only the file name is required 
        //                          there is no neeed to add the path to the file
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
        //      1. The object is in default state
        //      2. Failed to remove the file - class ErrnoException is thrown
        //      3.
        //
        void WorkingDirectory::RemoveFile( const Encoding::AsciiString& fileToRemove ) throw( ErrorHandling::ErrnoException )
        {
            // Create an object to store the path and the working directory
            Encoding::AsciiString fileToRemoveWithPath( m_workingDirectory );

            // Add to the path the file name
            fileToRemoveWithPath += fileToRemove;

            // Try to remove the file from the working directory
            RemoveFile( fileToRemoveWithPath );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to create a new file in the working directory
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          fileToRemove - a reference to an ascii string object containing the name of the file that should be created. Note - only the file name is required 
        //                         there is no neeed to add the path to the file
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
        //      1. Creating the file failed - class ErrnoException is thrown
        //      2. 
        //
        void WorkingDirectory::CreateNewFile( const Encoding::AsciiString& fileToCreate ) throw( ErrorHandling::ErrnoException )
        {
            // Create an object to store the path and the working directory
            Encoding::AsciiString fileToCreateWithPath( m_workingDirectory );

            // Add to the path the new file name
            fileToCreateWithPath += fileToCreate;  

            // Try to create the new file
            CreateNewFile( fileToCreateWithPath );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to create a new file in the working directory, and open it
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          fileToRemove - a reference to an ascii string object containing the name of the file that should be created. Note - only the file name is required 
        //                         there is no neeed to add the path to the file
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
        //      1. Creating the file failed - class ErrnoException is thrown
        //      2. 
        //
        SignedInteger32bits WorkingDirectory::CreateNewFileAndOpenIt( const Encoding::AsciiString& fileToCreate ) const throw( ErrorHandling::ErrnoException )
        {
            // Create an object to store the path and the working directory
            Encoding::AsciiString fileToCreateWithPath( m_workingDirectory );

            // Add to the path the new file name
            fileToCreateWithPath += fileToCreate;  

            // Try to create the new file
            return ( CreateNewFileAndOpenIt( fileToCreateWithPath ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to delete all the files that are not directories in the working directory
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
        //  Possible errors :
        //
        //      1. The object is in default state
        //      2. Failed to remove the file - class ErrnoException is thrown
        //      3. Failed to open the working directory - class ErrnoException is thrown
        //      4. Failed to close the working directory
        //      5. 
        //
        void WorkingDirectory::DeleteAllFiles() throw( ErrorHandling::ErrnoException )
        {
            // Open the working directory
            m_workingDirectoryStream = OpenDirectory( m_workingDirectory );

            // Loop until the directory has ended ( the function readdir will return NULL )
            for ( SetNextEntryIMP() ;  m_currentEntryInWorkingDirectory != 0 ; SetNextEntryIMP() )
            {

                // Check if current file is a directory
                if ( DT_DIR != m_currentEntryInWorkingDirectory->d_type )
                {
                    // Current file is not a directory

                    // Try to remove the file from the working directory
                    RemoveFile( m_currentEntryInWorkingDirectory->d_name );
                }

            }

            // Close the directory and set the pointers used to work with the working directory to NULL
            CloseTheWorkingDirectoryAndSetThePointersToNULLIMP();
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to delete the given directory. Important note - the given directory will be deleted only if it exist in the working directory and it is an empty directory
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //           directoryToRemove - a reference to an ascii string object containing the name of the directory that should be removed. Note - only the directory name is required 
        //                          there is no neeed to add the path to the directory
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
        //      1. The object is in default state
        //      2. Failed to remove the directory - class ErrnoException is thrown
        //      3. There is no more free memory space - class std::bad_alloc is thrown
        //      4. 
        //
        void WorkingDirectory::RemoveDirectory( const Encoding::AsciiString& directoryToRemove ) throw( ErrorHandling::ErrnoException )
        {
            // Create an object to store the path and the working directory
            Encoding::AsciiString directoryToRemoveWithPath( m_workingDirectory );

            // Add to the path and the working directory the file name
            directoryToRemoveWithPath += directoryToRemove;

            // Try to remove the file from the working directory
            RemoveDirectory( directoryToRemoveWithPath );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to delete the working directory. Important note - it will only be deleted if it is empty, and
        //      after using this method the object will be set to default state
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
        //  Possible errors :
        //
        //      1. The object is in default state
        //      2. Failed to remove the directory - class ErrnoException is thrown
        //      3. 
        //
        void WorkingDirectory::RemoveWorkingDirectory() throw( ErrorHandling::ErrnoException )
        {
            // Try to remove the file from the working directory
            RemoveDirectory( m_workingDirectory );

            // Release all the resources of this object
            DeleteResourcesAndSetToDefaultState();
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to check if the file exist in the working directory
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          file - a reference to an ascii string object with the required file name
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
        //      1. The object is in default state
        //      2. Failed to open the working directory - class ErrnoException is thrown
        //      3. Failed to close the working directory
        //      4. 
        //
        bool WorkingDirectory::DoesFileExist( const Encoding::AsciiString& file ) const throw( ErrorHandling::ErrnoException )
        {
            // Open the working directory
            m_workingDirectoryStream = OpenDirectory( m_workingDirectory );

            // Create an object to store the size of the path and the working directory name itself
            UnsignedInteger64bits asciiStringSize = m_workingDirectory.GetSize();

            // Loop until the directory has ended ( the function readdir will return NULL )
            for ( SetNextEntryIMP() ;  m_currentEntryInWorkingDirectory != 0 ; SetNextEntryIMP() )
            {

                // Check if current file matches the given file name
                if ( file.Compare( m_currentEntryInWorkingDirectory->d_name + asciiStringSize ) == 0 )
                {
                    // The required file exist

                    // Close the directory and set the pointers used to work with the working directory to NULL
                    CloseTheWorkingDirectoryAndSetThePointersToNULLIMP();

                    // Return true
                    return ( true );
                }

            }

            // If control reached here the file does not exist in the working directory

            // Close the directory and set the pointers used to work with the working directory to NULL
            CloseTheWorkingDirectoryAndSetThePointersToNULLIMP();

            // Return false
            return ( false );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to check if the file exist in the working directory, and if it exist, then if it is a directory
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          file - a reference to an ascii string object with the required file name
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
        //      1. The object is in default state
        //      2. Failed to open the working directory - class ErrnoException is thrown
        //      3. Failed to close the working directory
        //      4. 
        //
        bool WorkingDirectory::DoesFileExistAndItIsDirectory( const Encoding::AsciiString& file ) const throw( ErrorHandling::ErrnoException )
        {
            // Open the working directory
            m_workingDirectoryStream = OpenDirectory( m_workingDirectory );

            // Create an object to store the size of the path and the working directory name itself
            UnsignedInteger64bits asciiStringSize = m_workingDirectory.GetSize();

            // Loop until the directory has ended ( the function readdir will return NULL )
            for ( SetNextEntryIMP() ; m_currentEntryInWorkingDirectory != 0 ; SetNextEntryIMP() )
            {

                // Check if current file matches the given file name
                if ( ( file.Compare( m_currentEntryInWorkingDirectory->d_name + asciiStringSize ) == 0 ) )
                {
                    // The required file exist

                    // Check if it is a directory
                    if ( DT_DIR == m_currentEntryInWorkingDirectory->d_type )
                    {
                        // The required file is a directory

                        // Close the directory and set the pointers used to work with the working directory to NULL
                        CloseTheWorkingDirectoryAndSetThePointersToNULLIMP();

                        // Return true
                        return ( true );
                    }

                }

            }

            // If control reached here the file does not exist or it exist but it is not a directory

            // Close the directory and set the pointers used to work with the working directory to NULL
            CloseTheWorkingDirectoryAndSetThePointersToNULLIMP();

            // Return false
            return ( false );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to check if the working directory contains subdirectories
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
        //      1. true - if the working directory contains subdirectories
        //      2. false - if the working directory does not contain subdirectories
        //
        //  Possible errors :
        //
        //      1. The object is in default state
        //      2. Failed to open the working directory - class ErrnoException is thrown
        //      3. Failed to close the working directory
        //      4. 
        //
        bool WorkingDirectory::DoesSubdirectoriesExist( const Encoding::AsciiString& file ) const throw( ErrorHandling::ErrnoException )
        {
            // Open the working directory
            m_workingDirectoryStream = OpenDirectory( m_workingDirectory );

            // Loop until the directory has ended ( the function readdir will return NULL )
            for ( SetNextEntryIMP() ; m_currentEntryInWorkingDirectory != 0 ; SetNextEntryIMP() )
            {

                // Check if current file matches the given file name
                if ( DT_DIR == m_currentEntryInWorkingDirectory->d_type )
                {
                    // The current entry is a directory

                    // Close the directory and set the pointers used to work with the working directory to NULL
                    CloseTheWorkingDirectoryAndSetThePointersToNULLIMP();

                    // Return true
                    return ( true );
                }

            }

            // If control reached here the working direcgtory does not have subdirectories

            // Close the directory and set the pointers used to work with the working directory to NULL
            CloseTheWorkingDirectoryAndSetThePointersToNULLIMP();

            // Return false
            return ( false );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to get a list with all the files and directories in the working directory
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
        //      A list with all the file and directory names inside the working directory. Note - the responsibility for 
        //      deleting the memoery space is on the user
        //
        //  Possible errors :
        //
        //      1. The object is in default state
        //      2. Failed to open the working directory - class ErrnoException is thrown
        //      3. Failed to close the working directory
        //      4. There is no more free memory space - class std::bad_alloc is thrown
        //      5. 
        //
        ObjectsArray< Encoding::AsciiString >* WorkingDirectory::GetListOfFilesAndDirectories() const throw( std::bad_alloc, ErrnoException )
        {
            // Open the working directory
            m_workingDirectoryStream = OpenDirectory( m_workingDirectory );

            // Allocate new array of ascii strings to contain the list of files
            ObjectsArray< Encoding::AsciiString >* listOfFilesAndDirectories = new Array< AsciiString* >;

            // Loop until the directory has ended ( the function readdir will return NULL )
            for ( SetNextEntryIMP() ; m_currentEntryInWorkingDirectory != 0 ; SetNextEntryIMP() )
            {
                // Add current entry to the list
                listOfFilesAndDirectories->PushHead( new AsciiString( m_currentEntryInWorkingDirectory->d_name ) );
            }

            // Close the directory and set the pointers used to work with the working directory to NULL
            CloseTheWorkingDirectoryAndSetThePointersToNULLIMP();

            // Return the list of files and directories
            return ( listOfFilesAndDirectories );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to get a list with all the files in the working directory
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
        //      A list with all the file names inside the working directory. Note - the responsibility for 
        //      deleting the memoery space is on the user
        //
        //  Possible errors :
        //
        //      1. The object is in default state
        //      2. Failed to open the working directory - class ErrnoException is thrown
        //      3. Failed to close the working directory
        //      4. There is no more free memory space - class std::bad_alloc is thrown
        //      5. 
        //
        ObjectsArray< Encoding::AsciiString >* WorkingDirectory::GetListOfFiles() const throw( std::bad_alloc, ErrorHandling::ErrnoException )
        {
            // Open the working directory
            m_workingDirectoryStream = OpenDirectory( m_workingDirectory );

            // Allocate new array of ascii strings to contain the list of files
            ObjectsArray< Encoding::AsciiString >* listOfFiles = new Array< AsciiString* >;

            // Loop until the directory has ended ( the function readdir will return NULL )
            for ( SetNextEntryIMP() ; m_currentEntryInWorkingDirectory != 0 ; SetNextEntryIMP() )
            {

                // Check if current entry is a file and not a directory
                if ( DT_REG == m_currentEntryInWorkingDirectory->d_type )
                {
                    // The current entry is not a directory

                    // Add current file to the list
                    listOfFiles->PushHead( new AsciiString( m_currentEntryInWorkingDirectory->d_name ) );
                }

            }

            // Close the directory and set the pointers used to work with the working directory to NULL
            CloseTheWorkingDirectoryAndSetThePointersToNULLIMP();

            // Return the list of files
            return ( listOfFiles );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to get a list with all the directories in the working directory
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
        //      A list with all the directory names inside the working directory. Note - the responsibility 
        //      for deleting the memoery space is on the user
        //
        //  Possible errors :
        //
        //      1. The object is in default state
        //      2. Failed to open the working directory - class ErrnoException is thrown
        //      3. Failed to close the working directory
        //      4. There is no more free memory space - class std::bad_alloc is thrown
        //      5. 
        //
        ObjectsArray< Encoding::AsciiString >* WorkingDirectory::GetListOfDirectories() const throw( std::bad_alloc, ErrorHandling::ErrnoException )
        {
            // Open the working directory
            m_workingDirectoryStream = OpenDirectory( m_workingDirectory );

            // Allocate new array of ascii strings to contain the list of files
            ObjectsArray< Encoding::AsciiString >* listOfDirectories = new Array< AsciiString* >;

            // Loop until the directory has ended ( the function readdir will return NULL )
            for ( SetNextEntryIMP() ; m_currentEntryInWorkingDirectory != 0 ; SetNextEntryIMP() )
            {

                // Check if current entry is a directory
                if ( DT_DIR == m_currentEntryInWorkingDirectory->d_type )
                {
                    // The current entry is a directory

                    // Add current directory to the list
                    listOfDirectories->PushHead( new AsciiString( m_currentEntryInWorkingDirectory->d_name ) );
                }

            }

            // Close the directory and set the pointers used to work with the working directory to NULL
            CloseTheWorkingDirectoryAndSetThePointersToNULLIMP();

            // Return the list of directories
            return ( listOfDirectories );
        }

























//  **************************************************************   PRIVATE METHODS IMPLEMENTATION   *********************************************************





























        // Method Information :
        //
        //  Description :
        //
        //      Use to check if the character slash "/" exist at the beginning and end of the ascii string describing the path and working directory, if the 
        //      character doesn't exist, it will add it
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
        //  Possible errors :
        //
        //      1. If there is no more free memory space - class std::bad_alloc is thrown
        //      2. 
        //
        void WorkingDirectory::AddSlashToTheBeginningAndEndOfWorkingDirectoryIfDontExistIMP() throw( std::bad_alloc )
        {
            // Create an object to store the size of the ascii string
            UnsignedInteger64bits asciiStringSize = m_workingDirectory.GetSize();

            // Check if the given path to the required directory starts with "/"
            if ( m_workingDirectory[0] != '/' )
            {
                // Add slash "/" to the beginning of the ascii string describing the path and working directory
                m_workingDirectory.PushHead( '/' );
            }

            // Check if the given path to the required directory ends with "/"
            if ( m_workingDirectory[ asciiStringSize - 1 ] != '/' )
            {
                // Add slash "/" to the end of the ascii string describing the path and working directory
                m_workingDirectory.PushTail( '/' );
            }

        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to set the pointer of the dirent structure to the next entry of the directory
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //           NONE
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
        //      1. The readdir system call failed - class ErrnoException is thrown
        //      2. 
        //
        void WorkingDirectory::SetNextEntryIMP() const throw( ErrorHandling::ErrnoException )
        {
            // To check if the the directory reached it's end, first of all errno must be
            // set to zero. The readdir returns NULL only if the end of directory is reached,
            // or a failure occured. To distinguish between the two, errno must be checked
            // becuase if the end of directory is the case, errno won't be changed
            errno = 0;

            // Try to get the next entry in the directory
            m_currentEntryInWorkingDirectory = readdir( m_workingDirectoryStream );

            // Check the value of the pointer returned from the system call readdir
            if ( ( 0 == m_currentEntryInWorkingDirectory ) && ( errno != 0 ) )
            {
                // Check if an error occured and then errno was changed
                ErrorHandling::ErrnoException( "WorkingDirectory::SetNextEntryIMP failed - " );
            }

        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to check if the given file name is "." or ".."
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //           fileName - the address of an ascii string containnning the file name
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      1. true - if the file name is "." or ".."
        //      2. false - otherwise
        //
        //  Possible errors :
        //
        //      They will come
        //
        bool WorkingDirectory::DoesCurrentFileNameIsDotOr2Dots( const char* fileName ) throw()
        {
            // Check if the current file name is "." or ".."

            // Check if the first character in the ascii string is "."
            if ( '.' == m_currentEntryInWorkingDirectory->d_name[0] )
            {
                // The first character is "."

                // Check if the second character is NULL
                if ( 0 == m_currentEntryInWorkingDirectory->d_name[1] )
                {
                    // The file name is ".", return true
                    return ( true );
                }
                else if ( '.' == m_currentEntryInWorkingDirectory->d_name[1] )
                {
                    // The second character is also "."

                    // Check if the third character is NULL
                    if ( 0 == m_currentEntryInWorkingDirectory->d_name[2] )
                    {
                        // The file name is "..", return true
                        return ( true );
                    }

                }

            }

            // If control reached here the file name is not "." or "..", return false
            return ( false );
        }
































// ***************************************************************************************   TESTING   **************************************************************************


























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
            //      NONE
            //
            //  Possible errors :
            //
            //      1. A method does not work correctly
            //      2. There is no more free memory space - class std::bad_alloc is thrown
            //      3. 
            //
            void WorkingDirectory::Test() throw( std::bad_alloc )
            {
                // Get an handle to the assert object
                ErrorHandling::Assert& assert = ErrorHandling::Assert::GetHandle();

                assert.True( false );
            }


            // Method Information :
            //
            //  Description :
            //
            //      Use to display the working directory
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //           NONE
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
            //      1. If the object is in default state
            //      2. 
            //
            void WorkingDirectory::DisplayWorkingDirectory() const throw()
            {
                // Display the working directory
                std::cout << m_workingDirectory.GetAsciiString() << std::endl;
            }


            // Method Information :
            //
            //  Description :
            //
            //      Use to display the file and directories in the working directory
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //           NONE
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
            //      1. The object is in default state
            //      2. Failed to open the working directory - class ErrnoException is thrown
            //      3. Failed to close the working directory
            //      4. 
            //
            void WorkingDirectory::DisplayFilesAndDirectories() const throw( ErrorHandling::ErrnoException )
            {
                // Open the working directory
                m_workingDirectoryStream = OpenDirectory( m_workingDirectory );

                // Loop until the directory has ended ( the function readdir will return NULL )
                for ( SetNextEntryIMP() ; m_currentEntryInWorkingDirectory != 0 ; SetNextEntryIMP() )
                {

                    // Check if current file name is "." or ".."
                    if ( true == DoesCurrentFileNameIsDotOr2Dots( m_currentEntryInWorkingDirectory->d_name ) )
                    {
                        // The current file name is "." or ".."

                        // There is no need to display this
                        continue;
                    }

                    // Display current file or directory
                    std::cout << m_currentEntryInWorkingDirectory->d_name << std::endl;
                }

                // Close the directory and set the pointers used to work with the working directory to NULL
                CloseTheWorkingDirectoryAndSetThePointersToNULLIMP();
            }


            // Method Information :
            //
            //  Description :
            //
            //      Use to display only the files that are not directories in the working directory
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //           NONE
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
            //      1. The object is in default state
            //      2. Failed to open the working directory - class ErrnoException is thrown
            //      3. Failed to close the working directory
            //      4.     
            //
            void WorkingDirectory::DisplayFiles() const throw( ErrorHandling::ErrnoException )
            {
                // Open the working directory
                m_workingDirectoryStream = OpenDirectory( m_workingDirectory );

                // Loop until the directory has ended ( the function readdir will return NULL )
                for ( SetNextEntryIMP() ;  0 != m_currentEntryInWorkingDirectory ; SetNextEntryIMP() )
                {

                    // Check if current file is a directory
                    if ( DT_DIR != m_currentEntryInWorkingDirectory->d_type )
                    {
                        // Current file is not a directory

                        // Display current file
                        std::cout << m_currentEntryInWorkingDirectory->d_name << std::endl;
                    }

                } 

                // Close the directory and set the pointers used to work with the working directory to NULL
                CloseTheWorkingDirectoryAndSetThePointersToNULLIMP();
            }


            // Method Information :
            //
            //  Description :
            //
            //      Use to display only the the directories in the working directory
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //           NONE
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
            //      1. The object is in default state
            //      2. Failed to open the working directory - class ErrnoException is thrown
            //      3. Failed to close the working directory
            //      4.     
            //
            void WorkingDirectory::DisplayDirectories() const throw( ErrorHandling::ErrnoException )
            {
                // Open the working directory
                m_workingDirectoryStream = OpenDirectory( m_workingDirectory );

                // Loop until the directory has ended ( the function readdir will return NULL )
                for ( SetNextEntryIMP() ; m_currentEntryInWorkingDirectory != 0 ; SetNextEntryIMP() )        
                {

                    // Check if current file is a directory
                    if ( DT_DIR == m_currentEntryInWorkingDirectory->d_type )
                    {
                        // Current file is a directory

                        // Check if current directory name is "." or ".."
                        if ( true == DoesCurrentFileNameIsDotOr2Dots( m_currentEntryInWorkingDirectory->d_name ) )
                        {
                            // The current directory name is "." or ".."

                            // There is no need to display this
                            continue;
                        }

                        // Display current directory
                        std::cout << m_currentEntryInWorkingDirectory->d_name << std::endl;
                    }

                }

                // Close the directory and set the pointers used to work with the working directory to NULL
                CloseTheWorkingDirectoryAndSetThePointersToNULLIMP();
            }


        )  //  End of debug tool












    }  //   Namespace FileSystem

}  //  Namespace Universe


#endif  //  WORKINGDIRECTORY_CPP




















