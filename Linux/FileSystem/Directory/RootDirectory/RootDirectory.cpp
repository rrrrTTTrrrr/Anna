#ifndef  ROOTDIRECTORY_CPP
#define  ROOTDIRECTORY_CPP



#include "RootDirectory.h"




namespace Universe 
{


    // Forward declarations :
    //
    //  NONE
    //










//	************************************   PUBLIC METHODS IMPLEMENTATION - INTERFACE   ************************************











	// Method Information :
    //
    //  Description :
    //
    //   	Assignment operator, can handle with self assignment. Will operate correctly even if the other object is in default state
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
    //	  They will come
    //
    RootDirectory& RootDirectory::operator=( const RootDirectory& other ) throw( Exception )
    {

        // Check that this is not self assignment
        if ( this != &other )
        {
            // This is not self assignment

            // Release all the resources of this object
            DeleteResources();

            // Check if the other object is in default state
            if ( true == other.DefaultState() )
            {
                // The other object is in default state
                
                // Set this object to default state
                SetToDefaultState();

                // Nothing else needs to be done, return a reference to this object
                return ( *this );
            }

            // Copy the other object resources

            // Copy the root directory
            m_rootDirectory = other.m_rootDirectory;
        }

        // Return a reference to this object
        return ( *this );
    }



    // Method Information :
    //
    //  Description :
    //
    //   	Move Assignment operator, can handle with self assignment. Takes the resources from the
    //      other object ( rvalue reference ), and set it to the default state. Will operate correctly
    //      even if the other object is in default state
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
    RootDirectory& RootDirectory::operator=( RootDirectory&& other ) throw( Exception )
    {

        // Check that this is not self assignment
        if ( this != &other )
        {
            // This is not self assignment

            // Release all the resources of this object
            DeleteResources();

            // Check if the other object is in default state
            if ( true == other.DefaultState() )
            {
                // The other object is in default state
                
                // Set this object to default state
                SetToDefaultState();

                // Nothing else needs to be done, return a reference to this object
                return ( *this );
            }

            // Take the other object resources

            // Take the root directory
            m_rootDirectory = other.m_rootDirectory;

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
    //      Use to remove an empty directory, if it exist in the root directory or any of it's subdirectories
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          directoryName - a reference to an ascii string object containning the file name          
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      1. If the directory exist, it is empty, and was successfuly removed - true
    //      2. If the directory does not exist, or it is not empty - false            
    //
    //  Possible errors :
    //
    //      They will come
    //
    inline bool RootDirectory::RemoveEmptyDirectoryIfExist( const AsciiString& directoryName ) throw( std::bad_alloc, Exception, ErrnoException )
    {
        // Check that this object is not in default state
        ThrowExceptionIfExpressionIsTrue( DefaultState(), "RootDirectory::RemoveEmptyDirectoryIfExist failed - the object is in default state" );

        // Try to find the path to the directory
        AsciiString* pathToDirectory = GetPathToFileOrDirectoryIfExist( directoryName );

        // Check if the directory exist
        if ( 0 == pathToDirectory )
        {
            // The directory does not exist, return false
            return ( false );
        }

        // The directory exist

        // Add the directory name to the path
        *pathToDirectory += directoryName;

        // Create an object to work with the directory
        WorkingDirectory currentDirectory( pathToDirectory );

        // Check if the directory is empty
        if( true == currentDirectory.Empty() )
        {
        	// The directory is empty 

        	// Try to delete the required directory
        	currentDirectory.RemoveWorkingDirectory();

        	// Return true
        	return ( true );
        }

        // The directory is not empty 
        return ( false );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Use to remove a non empty directory, if it exist in the root directory or any of it's subdirectories
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          directoryName - a reference to an ascii string object containning the file name          
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      1. If the directory exist, and was successfuly removed - true
    //      2. If the directory does not exist - false            
    //
    //  Possible errors :
    //
    //      They will come
    //
    inline bool RootDirectory::RemoveNonEmptyDirectoryIfExist( const AsciiString& directoryName ) throw( std::bad_alloc, Exception, ErrnoException )
    {
        // Check that this object is not in default state
        ThrowExceptionIfExpressionIsTrue( DefaultState(), "RootDirectory::RemoveEmptyDirectoryIfExist failed - the object is in default state" );

        // Try to find the path to the directory
        AsciiString* pathToDirectory = GetPathToFileOrDirectoryIfExist( directoryName );

        // Check if the directory exist
        if ( 0 == pathToDirectory )
        {
            // The directory does not exist, return false
            return ( false );
        }

        // The directory exist

        // Add the directory name to the path
        *pathToDirectory += directoryName;

        // Recursively pass on all the subdirectories, delete all the files and directories inside them
        // and then delete them
        RecursivePassToRemoveSubdirectoriesIMP( pathToDirectory );
    }













//	*****************************************   PRIVATE METHODS IMPLEMENTATION   ******************************************














    // Method Information :
    //
    //  Description :
    //
    //      Use to pass recursively on all the subdirectories starting from the given one,
    //      and search for the given file
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. directory - a reference to an ascii string object containning the starting directory
    //          2. fileName - a reference to an ascii string object containning the file name          
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      1. If the file exist - the address of an ascii string object containning the path to the file
    //      2. If the file does not exist - a NULL pointer
    //
    //      Note - the responsibility for deleting the memory space is on the user
    //
    //  Possible errors :
    //
    //      1. The object is in default state - class Exception is thrown
    //      2. Failed to open the working directory - class ErrnoException is thrown
    //      3. Failed to close the working directory
    //      4. There is no more free memory space - class std::bad_alloc is thrown
    //      5. 
    //
    AsciiString* RootDirectory::RecursivePassOnSubdirectoriesToFindFileIMP( const AsciiString& directory, const AsciiString& fileName ) throw( std::bad_alloc, Exception, ErrnoException )
    {
        // Create an object to work with the directory
        WorkingDirectory currentDirectory( directory );

        // Check if the file exist in this directory
        if ( true == currentDirectory.DoesFileExist( fileName ) )
        {
            // Allocate new ascii string and set the path to current directory inside, and then return
            // an handle to it
            return ( new AsciiString( directory ) );
        }

        // The file does not exist in this directory

        // Get a list of all the subdirectories
        DefaultConstructedObjectsArray< AsciiString >* subdirectoriesList = currentDirectory.GetListOfDirectories();

        // Create an object to store the result from the recurisve call
        AsciiString* pathToFile = 0;

        // Loop on the list of subdirectories
        for ( UnsignedInteger64bits listIndex = 0 ; listIndex < subdirectoriesList.GetSize() ; ++listIndex )
        {
            // Make a recurisve call to this method with the current subdirectory
            pathToFile = RecursivePassOnSubdirectoriesIMP( subdirectoriesList[ listIndex ] );

            // Check if the file was found in the subdirectory
            if ( 0 != pathToFile )
            {
                // The file was found

                // Return the path to the file
                return ( pathToFile );
            }

        }

        // Delete the list of subdirectories
        delete subdirectoriesList;

        // The file was not found, return NULL
        return ( 0 );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Use to pass recursively on all the subdirectories starting from the given one,
    //      and search for the given file, if the file exist it will be removed
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. directory - a reference to an ascii string object containning the starting directory
    //          2. fileName - a reference to an ascii string object containning the file name          
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      1. If the file exist and was removed - true
    //      2. If the file does not exist - false
    //
    //  Possible errors :
    //
    //      1. The object is in default state - class Exception is thrown
    //      2. Failed to open the working directory - class ErrnoException is thrown
    //      3. Failed to close the working directory
    //      4. There is no more free memory space - class std::bad_alloc is thrown
    //      5. 
    //
    bool RootDirectory::RecursivePassOnSubdirectoriesToRemoveFileIMP( const AsciiString& directory, const AsciiString& fileName ) throw( std::bad_alloc, Exception, ErrnoException )
    {
        // Create an object to work with the directory
        WorkingDirectory currentDirectory( directory );

        // Check if the file exist in this directory
        if ( true == currentDirectory.DoesFileExist( fileName ) )
        {
        	// The file exist

        	// Remove the file
        	currentDirectory.RemoveFile( fileName );

        	// Return true
        	return ( true );
        }

        // The file does not exist in this directory

        // Get a list of all the subdirectories
        DefaultConstructedObjectsArray< AsciiString >* subdirectoriesList = currentDirectory.GetListOfDirectories();

        // Loop on the list of subdirectories
        for ( UnsignedInteger64bits listIndex = 0 ; listIndex < subdirectoriesList.GetSize() ; ++listIndex )
        {

            // Make a recurisve call to this method with the current subdirectory, and check if the file 
            // was found and deleted in the subdirectory
            if ( true == RecursivePassOnSubdirectoriesIMP( subdirectoriesList[ listIndex ] ) )
            {
                // The file was found and removed

                // Return true
                return ( true );
            }

        }

        // The file was not found, return false
        return ( false );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Use to pass recursively on all the subdirectories starting from the given one,
    //      and delete all the files and directories inside
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          directoryToRemove - a reference to an ascii string object containning the starting directory
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
    //      1. The object is in default state - class Exception is thrown
    //      2. Failed to open the working directory - class ErrnoException is thrown
    //      3. Failed to close the working directory
    //      4. There is no more free memory space - class std::bad_alloc is thrown
    //      5. 
    //
    void RootDirectory::RecursivePassToRemoveSubdirectoriesIMP( const AsciiString& directoryToRemove ) throw( std::bad_alloc, Exception, ErrnoException )
    {
        // Create an object to work with the directory
        WorkingDirectory currentDirectory( directoryToRemove );

        // Delete all the files that are not directories
        currentDirectory.DeleteAllFiles();

        // Get a list of all the subdirectories
        DefaultConstructedObjectsArray< AsciiString >* subdirectoriesList = currentDirectory.GetListOfDirectories();        

        // Loop on the list of subdirectories
        for ( UnsignedInteger64bits listIndex = 0 ; listIndex < subdirectoriesList.GetSize() ; ++listIndex )
        {
            // Make a recurisve call to this method with the current subdirectory
            RecursivePassOnSubdirectoriesToRemoveFileIMP( subdirectoriesList[ listIndex ] );
        }

        // Now all the files and subdirectories were deleted

        // Delete the empty working directory
        currentDirectory.RemoveWorkingDirectory();

        // Delete the list of subdirectories
        delete subdirectoriesList;
    }










}  //  Namespace Universe


#endif  //  ROOTDIRECTORY_CPP













