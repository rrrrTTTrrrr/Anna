#ifndef  WORKINGDIRECTORY_H
#define  WORKINGDIRECTORY_H


#include <dirent.h>  //  Function opendir, Function fdopendir, Function closedir, Function readdir


#include "../../../Definitions/VariableTypesDefinitions.hpp"  //  Typedef SignedInteger32bits
#include "../../../BasicUtilities/cpp_BasicUtilities.hpp"  // Macro DEBUG_TOOL
#include "../../../Encoding/Ascii/AsciiString/AsciiString.hpp"  //  Class AsciiString
#include "../DirectoryOperations/DirectoryOperations.hpp"  //  Function OpenDirectory, Function CloseDirectory
#include "../../../GeneralPurposeContainers/Array/Objects/ObjectsArray/ObjectsArray.hpp"  //  Class GeneralPurposeContainers::ObjectsArray


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


        // This is used when only declaring the object in this source file will be enough to
        // pass compilation. The implementation is given to the compiler through the cpp source
        // file that the object is nested within
        //
        // Forward declarations :
        //
        //      NONE
        //


        // Give proper treatment, by dealing with big and little endian encoding systems
        // where it is required. The big or little endian encoding appear when dealing
        // with byte order in memory. In the byte itself the bit the is closest to the 
        // address of the byte, is the high order bit
        //
        //    The closest bit to the    The farest bit from the 
        //     address of the byte        address of the byte
        //                        |      |
        //      Byte address ->   00000000
        //                        |      |
        //            High order bit    Low order bit
        //
        // Then the value 1 will be stored this way :
        //
        //      Byte address ->   00000001
        //                        |      |
        //            High order bit    Low order bit
        //
        // Then in 1 byte this is always the case. But when dealing with more then 1 byte
        // it is up to the system to decide whether the address of the first byte will 
        // contain the high order bits or the low order bits. For example for 2 bytes,
        // store the value 1 in the 2 ways of endian encoding :
        //
        //    Big endian encoding :
        //
        //      First address of data type ->   00000000 00000001
        //
        //    Big endian encoding :
        //
        //      First address of data type ->   00000001 00000000


        // To support move semantics every object must provide a default state. There are 
        // how ever few exceptions, as objects that their members stay exactly the same along
        // the run of the program, objects that don't have members at all, and objects with 
        // undefined state. This default state will be used to notify that the object should
        // not be used :
        //
        //
        // When the object is in this state it should not be used ( the object is empty )


        // Constructor of derived object, when called, all the base class constructors are executed first, according to
        // the order they appear in the class declaration, and only then the user code is executed

        // Destructor of derived object, when it is called, the user code existing in the destructor itself is executed first and then all the destructors
        // of the base objects, in an opposite way from which they were constructed


        // Hard links and Unix file system nodes (inodes) :
        //
        //  Files and directories are inodes :
        //
        //      On Unix, the collection of data that makes up the contents of a directory or a file isn't stored under a name; the data is stored as part of 
        //      a data structure called an "inode". In the inode, Unix stores information about which disk blocks belong to the contents of the directory or
        //      file, as well as information about who owns the directory or file and what access permissions it has. Every directory or file on Unix has its
        //      storage managed by its own inode. Unix doesn't store the name of the directory or file in the inode. Every inode in the file system has a 
        //      unique number, and the file system locates the contents of a directory or file strictly by its inode number
        //
        //  Directories give names to inodes :
        //
        //      Unix directories are very simple - they are just tables that map directory and file names to inode numbers. Given a name, the data in the 
        //      directory will tell you the inode number that corresponds to that name, and that is all. To read the data that corresponds to that name, 
        //      Unix still has to look in the file system to find the inode (by number), and then use the disk block numbers contained in the inode to 
        //      locate the data.
        //
        //      The inodes that make up directories and files look quite similar; directories are simply special kinds of files whose data blocks are tables
        //      of name-to-inode mappings. On some versions of Unix (e.g. ACADUNIX) you can even open a directory as if it were a regular file and read the 
        //      name-inode tables directly!
        //
        //  Hard links - new names for the same inode :
        //
        //      An existing file name, can have multiple names that maps to the same inode number. This is called "making a hard link" to a file.
        //
        //      For each inode, no matter whether the inode is a directory or a file inode, a link count in the inode keeps track of how many directories 
        //      contain a name-number mapping for that inode


        // In each directory there are 2 hard links built in - "." ( dot ) and ".." ( 2 dots ). The dot represnt the current directory, and 2 dots
        // represnt the directory the current directory is in


        // Structure dirent :
        //
        //      1. char d_name[] - a NULL terminated file name
        //      2. ino_t d_fileno - the file serial number
        //      3. unsigned char d_namlen - the file name length
        //      4. unsigned char d_type - the type of the file 
        //
        // The following constants are defined for the type of the file :
        //
        //      DT_UNKNOWN - the type is unknown
        //      DT_REG - regular file
        //      DT_DIR - directory
        //      DT_FIFO - named pipe
        //      DT_CHR - character device
        //      DT_BLK - block device
        //      DT_LNK - symbolic link
        


    	// Class Information :
        //
        //  Purpose :
        //
        //      The purpose of the class is to wrap the low level functions deal with the directories
        //
        //  Description :
        //
        //
        //
        //  Possible errors :
        //
        //
        //
        class WorkingDirectory 
    	{ 
    	public:


    		// Method Information :
        	//
        	//  Description :
        	//
        	//   	Default Constructor, used to support move semantics
        	//
        	//  Required arguments :
        	//
        	//   	User information needed :
        	//
            //          NONE
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
        	//		They will come
        	//
        	explicit inline WorkingDirectory() throw();


    		// Method Information :
        	//
        	//  Description :
        	//
        	//   	Constructor,
        	//
        	//  Required arguments :
        	//
            //		User information needed :
        	//
            //          directory - the path including the name of the directory itself of the working directory
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
            //
            //      1. There is no more free memory space - class std::bad_alloc is thrown
            //      2. 
        	//
        	explicit inline WorkingDirectory( const Encoding::AsciiString& directory ) throw( std::bad_alloc );


            // Method Information :
            //
            //  Description :
            //
            //      Copy constructor. Important note - it will only copy the required directory from the other object 
            //      and not the all state of the other object. The purpose then of copying in this class is to work 
            //      on the same directory
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          other - a reference to the object that should be copied
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
            //      They will come
            //
        	WorkingDirectory( const WorkingDirectory& other ) throw();


            // Method Information :
            //
            //  Description :
            //
            //      Assignment operator, handle self assignment correctly. . Important note - it will only copy the required
            //      directory from the other object and not the all state of the other object. The purpose then of copying in this
            //      class is to work on the same directory
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          other - a reference to the object that should be copied
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      A reference to this object 
            //
            //  Possible errors :
            //
            //      1. There is no more free memory space - class std::bad_alloc is thrown
            //      2. 
            //
            WorkingDirectory& operator=( const WorkingDirectory& other ) throw( std::bad_alloc );


        	// Method Information :
        	//
        	//  Description :
        	//
        	//   	Move constructor, takes the resources from the instance given in the rvalue reference, and set it to the default state.
          	//		Will operate correctly even if the other object is in default state. Important note - if the current object has a pointer
            //      memebers, they must be set manually to 0 before using the method set to default state, or else the resources will be deleted
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
        	//   	NONE
        	//
    		//  Possible errors :
        	//
            //
            //      1. There is no more free memory space - class std::bad_alloc is thrown
            //      2. 
        	//
        	WorkingDirectory( WorkingDirectory&& other ) throw();


    		// Method Information :
        	//
        	//  Description :
        	//
        	//   	Move Assignment operator, handle self assignment correctly. take the resources from the
        	//    	instance given in the rvalue reference,	and set it to the default state.
        	//      will operate correctly even if the other object is in default state. Important note - if the current object
            //      has a pointer memebers, they must be set manually to 0 before using the method set to default state, or else
            //      the resources will be deleted
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
        	//		They will come
        	//
        	WorkingDirectory& operator=( WorkingDirectory&& other ) throw( std::bad_alloc );


    		// Method Information :
        	//
        	//  Description :
        	//
        	//   	Destructor,
        	//
        	//  Required arguments :
        	//
            //   	User information needed :
        	//
            //          NONE
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
        	//		They will come
        	//
        	~WorkingDirectory() throw();


            // To support Move semantics, the following 3 methods are added to every object. One method to set
            // the object into the default state, another to check if the object is in the default state,
            // and the last method to delete all the object resources and set the object to default state :


            // Method Information :
            //
            //  Description :
            //
            //      Use to set the object into his default state. Note - this method does not delete the resources inside, it
            //      only set the data members inside the object to the default value
            //
            //  Required arguments :
            //
            //   	User information needed :
            //
            //          NONE
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
            //	    They will come
            //
            void SetToDefaultState() throw();


            // Method Information :
        	//
        	//  Description :
        	//
        	//   	Use to check if the object is in default state, it will return true if it does, and false otherwise
        	//
        	//  Required arguments :
        	//
            //   	User information needed :
        	//
            //          NONE
        	//
        	//      Information returned to the user :
        	//
            //          NONE
        	//
        	//  Return value :
        	//
        	//      1. true, if instance is at default state
        	//      2. false, if instance is not at default state
        	//
    		//  Possible errors :
        	//
        	//		They will come
        	//
        	bool DefaultState() const throw(); 


            // Method Information :
            //
            //  Description :
            //
            //      Use to delete the object resources and set the object to default state. Note - if the object is in default
            //      state the method do nothing
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
            //      1. Deleting the object resources failed
            //      2.
            //
            void DeleteResourcesAndSetToDefaultState() throw();


            // The following methods are the interface of the object. This methods implement the
            // capabilities of the object : 


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
            bool Empty() const throw( ErrorHandling::ErrnoException );


            // Method Information :
            //
            //  Description :
            //
            //      Use to change the working directory
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //           
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
            //      1. There is no more free memory space - class std::bad_alloc is thrown
            //      2. 
            //
            inline void SetNewWorkingDirectory( const Encoding::AsciiString& newWorkingDirectory ) throw( std::bad_alloc );


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
            void RemoveFile( const Encoding::AsciiString& fileToRemove ) throw( ErrorHandling::ErrnoException );


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
            void CreateNewFile( const Encoding::AsciiString& fileToCreate ) throw( ErrorHandling::ErrnoException );


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
            SignedInteger32bits CreateNewFileAndOpenIt( const Encoding::AsciiString& fileToCreate ) const throw( ErrorHandling::ErrnoException );


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
            void DeleteAllFiles() throw( ErrorHandling::ErrnoException );


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
            void RemoveDirectory( const Encoding::AsciiString& directoryToRemove ) throw( ErrorHandling::ErrnoException );


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
            void RemoveWorkingDirectory() throw( ErrorHandling::ErrnoException );


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
            bool DoesFileExist( const Encoding::AsciiString& file ) const throw( ErrorHandling::ErrnoException );


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
            bool DoesFileExistAndItIsDirectory( const Encoding::AsciiString& file ) const throw( ErrorHandling::ErrnoException );


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
            bool DoesSubdirectoriesExist( const Encoding::AsciiString& file ) const throw( ErrorHandling::ErrnoException );


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
            GeneralPurposeContainers::ObjectsArray< Encoding::AsciiString >* GetListOfFilesAndDirectories() const throw( std::bad_alloc, ErrorHandling::ErrnoException );


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
            GeneralPurposeContainers::ObjectsArray< Encoding::AsciiString >* GetListOfFiles() const throw( std::bad_alloc, ErrorHandling::ErrnoException );


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
            GeneralPurposeContainers::ObjectsArray< Encoding::AsciiString >* GetListOfDirectories() const throw( std::bad_alloc, ErrorHandling::ErrnoException );


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
                //      1. A method does not work correctly
                //      2. There is no more free memory space - class std::bad_alloc is thrown
                //      3. 
                //
                static void Test() throw( std::bad_alloc );


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
                void DisplayWorkingDirectory() const throw();


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
                void DisplayFilesAndDirectories() const throw( ErrorHandling::ErrnoException );


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
                void DisplayFiles() const throw( ErrorHandling::ErrnoException );


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
                void DisplayDirectories() const throw( ErrorHandling::ErrnoException );


            )  //  End of debug tool


    	private: 


            // This object will store the full path of the working directory
            Encoding::AsciiString m_workingDirectory;

            // This object will store the address of the directory stream
            mutable DIR* m_workingDirectoryStream;

            // This object will store the current entry in the working directory
            mutable struct dirent* m_currentEntryInWorkingDirectory;


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
            void AddSlashToTheBeginningAndEndOfWorkingDirectoryIfDontExistIMP() throw( std::bad_alloc );


            // Method Information :
            //
            //  Description :
            //
            //      Use to close the working directory and set the pointers inside the object that help work with the working directory to NULL
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
            //      1. Failed to close the working directory
            //      2.     
            //
            inline void CloseTheWorkingDirectoryAndSetThePointersToNULLIMP() const throw( ErrorHandling::ErrnoException );


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
            void SetNextEntryIMP() const throw( ErrorHandling::ErrnoException );


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
            bool DoesCurrentFileNameIsDotOr2Dots( const char* fileName ) throw();


    	};  //  Class WorkingDirectory


























//  ****************************************************************   END PART OF DECLRATIONS, IMPLMENTATION TIME   ************************************************************


























    	// Method Information :
        //
        //  Description :
        //
        //   	Default Constructor, used to support move semantics
        //
        //  Required arguments :
        //
        //   	User information needed :
        //
        //          NONE
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
        //	    They will come
        //
        inline WorkingDirectory::WorkingDirectory() throw() :
        m_workingDirectory(),
        m_workingDirectoryStream( 0 ),
        m_currentEntryInWorkingDirectory( 0 )
        {}


        // Method Information :
        //
        //  Description :
        //
        //   	Constructor,
        //
        //  Required arguments :
        //
        //   	User information needed :
        //
        //          directory - the path including the name of the directory itself of the working directory
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        NONE
        //
        //  Possible errors :
        //
        //      1. There is no more free memory space - class std::bad_alloc is thrown
        //      2. 
        //
    	inline WorkingDirectory::WorkingDirectory( const Encoding::AsciiString& directory ) throw( std::bad_alloc ) :
        m_workingDirectory( directory ),
        m_workingDirectoryStream( 0 ),
        m_currentEntryInWorkingDirectory( 0 )
        {
            // Check if the character slash "/" exist at the beginning and end of the ascii string describing the path and working directory, if the 
            // character doesn't exist, add it
            AddSlashToTheBeginningAndEndOfWorkingDirectoryIfDontExistIMP();
        }


    	// Method Information :
        //
        //  Description :
        //
        //   	Copy constructor. Important note - it will only copy the required directory from the other object 
        //      and not the all state of the other object. The purpose then of copying in this class is to work 
        //      on the same directory
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
        //   	NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline WorkingDirectory::WorkingDirectory( const WorkingDirectory& other ) throw() :
        m_workingDirectory( other.m_workingDirectory ),
        m_workingDirectoryStream( 0 ),
        m_currentEntryInWorkingDirectory( 0 )
        {}


        // Method Information :
        //
        //  Description :
        //
        //      Move constructor, take the resources from the instance given in the rvalue reference, and set it to the default state.
        //      Will operate correctly even if the other object is in default state. Important note - if the current object has a pointer
        //      memebers, they must be set manually to 0 before using the method set to default state, or else the resources will be deleted
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
        //   	NONE
        //
    	//  Possible errors :
        //
        //	    They will come
        //
        inline WorkingDirectory::WorkingDirectory( WorkingDirectory&& other ) throw() :
        m_workingDirectory( other.m_workingDirectory ),
        m_workingDirectoryStream( 0 ),
        m_currentEntryInWorkingDirectory( 0 )
        {}


        // Method Information :
        //
        //  Description :
        //
        //        Destructor,
        //
        //  Required arguments :
        //
        //   	  User information needed :
        //
        //            NONE
        //
        //        Information returned to the user :
        //
        //            NONE
        //
        //  Return value :
        //
        //   	NONE
        //
    	//  Possible errors :
        //
        //	    They will come
        //
        inline WorkingDirectory::~WorkingDirectory() throw()
        {}


        // Method Information :
        //
        //  Description :
        //
        //      Use to set the object into his default state. Note - this method does not delete the resources inside, it
        //      only set the data members inside the object to the default value
        //
        //  Required arguments :
        //
        //   	User information needed :
        //
        //          NONE
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
        //	    They will come
        //
        inline void WorkingDirectory::SetToDefaultState() throw()
        {
            // Set the ascii string containing the directory name to default state
            m_workingDirectory.SetToDefaultState();

            // Set the directory stream pointer to NULL
            m_workingDirectoryStream = 0;

            // Set the directory current entry pointer to NULL
            m_currentEntryInWorkingDirectory = 0;
        }


        // Method Information :
        //
        //  Description :
        //
        //		Use to check if the object is in default state, it will return true if it does, and false otherwise
        //
        //  Required arguments :
        //
        //   	User information needed :
        //
        //           NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      1. true, if instance is at default state
        //      2. false, if instance is not at default state
        //
    	//  Possible errors :
        //
        //	    They will come
        //
        inline bool WorkingDirectory::DefaultState() const throw()
        {

            // Check if the object is in default state
            if ( true == m_workingDirectory.DefaultState() && 
                 0 == m_workingDirectoryStream && 
                 0 == m_currentEntryInWorkingDirectory )
            {
                // The object is in default state
                return ( true );
            }

            // The object is not in default state
            return ( false );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to delete the object resources and set the object to default state. The resource will only be 
        //      deleted if the reference count is 1, which means only current instance uses the resource. If the 
        //      current instance is at default state the method will do nothing
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
        //      1. Deleting the object resources failed
        //      2.
        //
        inline void WorkingDirectory::DeleteResourcesAndSetToDefaultState() throw()
        {
            // Check if the object is in default state, then noting needs to be done
            RETURN_IF_EXPRESSION_IS_TRUE( DefaultState() )

            // Release the resources of this object

            // Delete the ascii string of the working directory
            m_workingDirectory.DeleteResourcesAndSetToDefaultState();

            // Set the directory stream pointer to NULL
            m_workingDirectoryStream = 0;

            // Set the directory current entry pointer to NULL
            m_currentEntryInWorkingDirectory = 0;
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to change the working directory
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //           
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
        //      1. There is no more free memory space - class std::bad_alloc is thrown
        //      2. 
        //
        inline void WorkingDirectory::SetNewWorkingDirectory( const Encoding::AsciiString& newWorkingDirectory ) throw( std::bad_alloc )
        {
            // Set the ascii string inside this object to the new directory
            m_workingDirectory = newWorkingDirectory;

            // Check if the character slash "/" exist at the beginning and end of the ascii string describing the path and working directory, if the 
            // character doesn't exist, add it
            AddSlashToTheBeginningAndEndOfWorkingDirectoryIfDontExistIMP();
        }































//  *************************************************************************   PRIVATE METHODS IMPLEMENTATION   ****************************************************************






























        // Method Information :
        //
        //  Description :
        //
        //      Use to close the working directory and set the pointers inside the object that help work with the working directory to NULL
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
        //      1. Failed to close the working directory
        //      2.     
        //
        inline void WorkingDirectory::CloseTheWorkingDirectoryAndSetThePointersToNULLIMP() const throw( ErrorHandling::ErrnoException )
        {
            // Close the directory 
            CloseDirectory( m_workingDirectoryStream );

            // Set the directory stream pointer to NULL
            m_workingDirectoryStream = 0;

            // Set the current entry pointer to NULL
            m_currentEntryInWorkingDirectory = 0;
        }











    }  //   Namespace FileSystem

}  //   Namespace Universe

#endif  // WORKINGDIRECTORY_H