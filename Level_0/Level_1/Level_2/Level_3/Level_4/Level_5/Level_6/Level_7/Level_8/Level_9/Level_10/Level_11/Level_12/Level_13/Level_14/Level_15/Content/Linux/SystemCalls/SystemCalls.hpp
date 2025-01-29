#include "/usr/include/asm-generic/fcntl.h"  //  Flags and modes
#include "/usr/include/x86_64-linux-gnu/sys/stat.h"  //  Defines the structure of the data returned by the functions 'fstat', 'lstat' and 'stat', and symbolic names for the st_mode
#include "/usr/include/x86_64-linux-gnu/asm/unistd.h"  //  Macros __NR_'SystemCallName'
#include "/usr/include/dirent.h"  //  Mcros DT_'FileType'


namespace Universe
{


namespace Linux
{


// This is the Linux structure to hold information on a specific directory entry. Defined in the file '/usr/src/linux-headers-5.4.0-74/include/linux/dirent.h'
struct linux_dirent64
{
   UnsignedInteger64bits member_inode;    					// 64-bit inode number
   UnsignedInteger64bits member_offsetToNextStructure;    	// 64-bit offset to next structure
   UnsignedInteger16bits member_size; 						// Size of this directory entry
   UnsignedInteger8bits member_fileType;   					// File type
   SignedInteger8bits member_fileName[1]; 					// Filename ( NULL terminated )
};



// This is the Linux structure that holds the file information
//
// 	struct stat64 {
// 		dev_t st_dev;				// ID of device containing the file
// 		ino64_t st_ino;				// Serial number for the file
// 		mode_t st_mode;				// Access mode and file type for the file
// 		nlink_t st_nlink;			// Number of links to the file
// 		uid_t st_uid;				// User ID of file owner
// 		gid_t st_gid;				// Group ID of group owner
// 		dev_t st_rdev;				// Device ID ( tells if the file is a character or block devices )
// 		off64_t st_size;			// File size in bytes ( if the file is a regular file )
// 		time_t st_atime;			// Time of last access
// 		time_t st_mtime;			// Time of last data modification
// 		time_t st_ctime;			// Time of last file status change
// 		blksize_t st_blksize; 		// A file system specific prefered I/O block size for this object
// 		blkcnt64_t st_blocks;		// Number of blocks allocated for this file
// 		mode_t st_attr;				// The DOS-style attributes for this file
// 	}; 



// The signatures of all the Linux system calls are in the file :
//
//	/usr/src/linux-headers-5.15.0-56/include/linux/syscalls.h
//



// For ubuntu distribution of Linux, the correct 'unistd.h' file to include is located at :
//
//	/usr/include/x86_64-linux-gnu/asm/unistd.h
//
// The file with the actual system calls number identifiers is for 64 bits systems :
//
//	/usr/include/x86_64-linux-gnu/asm/unistd_64.h



// Class Information :
//
//  Purpose :
//
//		Artifical Inteligence
//
    //  Description :
    //
//		1. This object is used only to wrap some static methods, which can be used without any instance of the object. Then this object is
//		   an interface which conatins only static methods, and does not need to never be instantied
//
//		2. This object has all the methods to create, destory, copy and move disabled to ensure that no instances of it will be created
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
class SystemCalls
{
public:


	// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions
	// only have access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only
	// purpose then of declaring a static function is when a private static data member needs to be manipulated, or some functionality needed that
	// does not involve the non static data members


	// Directory :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to invoke the 'mkdir' system call to create a new directory. In x86_64 architecture the system call number is '83'
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. directoryPathPointer - the memory address that contains the directory name with the path ( relative or absolute ) to create
	//			2. mode - the read and write permissions for the new created file. Needs to be one of the following :
	//
	//					S_IRWXU - 00700 - user ( directory owner ) has read, write, and execute permission
	//              	S_IRUSR - 00400 - user has read permission
	//              	S_IWUSR - 00200 - user has write permission
	//              	S_IXUSR - 00100 - user has execute permission
	//             		S_IRWXG - 00070 - group has read, write, and execute permission
	//              	S_IRGRP - 00040 - group has read permission
	//              	S_IWGRP - 00020 - group has write permission
	//              	S_IXGRP - 00010 - group has execute permission
	//              	S_IRWXO - 00007 - others have read, write, and execute permission
	//             		S_IROTH - 00004 - others have read permission
	//              	S_IWOTH - 00002 - others have write permission
	//              	S_IXOTH - 00001 - others have execute permission
	//              	
	//                According to POSIX, the effect when other bits are set in mode is unspecified. On Linux, the following bits are also honored in mode :
	//
	//              	S_ISUID - 0004000 - set-user-ID bit
	//              	S_ISGID - 0002000 - set-group-ID bit
	//              	S_ISVTX - 0001000 - sticky bit
	//		
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		1. The given pointer to the memory address is not NULL
	//		2. The given pointer to the memory address contains a NULL terminated ascii string
	//		3. 
	//
	//  Possible errors :
	//
	//		1. The system call failed - Class ErrnoException is thrown
	//		2.
	//
	static inline void CreateDirectory( const AsciiCharacter* const directoryPathPointer, const UnsignedInteger64bits mode = S_IRUSR | S_IWUSR );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to invoke the 'rmdir' system call to delete a file. In x86_64 architecture the system call number is '84'
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			directoryPathPointer - the memory address that contains the directory name with the path ( relative or absolute ) to delete
	//		
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		1. The given pointer to the memory address is not NULL
	//		2. The given pointer to the memory address contains a NULL terminated ascii string
	//		3. The given directory path exist in the file system
	//		4. The directory is empty ( no files or directories )
	//		5.
	//
	//  Possible errors :
	//
	//		1. The system call failed - Class ErrnoException is thrown
	//		2.
	//
	static inline void DeleteEmptyDirectory( const AsciiCharacter* const directoryPathPointer );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to invoke the 'open' system call to open a directory to work with. In x86_64 architecture the system call number is '2'
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. directoryPathPointer - the memory address that contains the directory name with the path ( relative or absolute ) to open
	//			2. flags - needs to be one of the following :
	//
	//				For reading only - O_RDONLY
	//				For writing only - O_WRONLY
	//				For reading and writing - O_RDWR
	//		
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The descriptor of the direcotoy
	//
	//  Expectations :
	//
	//		1. The given pointer to the memory address is not NULL
	//		2. The given pointer to the memory address contains a NULL terminated ascii string
	//		3. The given flag should one of the supported flags
	//		4. 
	//
	//  Possible errors :
	//
	//		1. The system call failed - Class ErrnoException is thrown
	//		2.
	//
	EnsureRetrunValueIsUsed static inline SignedInteger32bits OpenDirectory( const AsciiCharacter* const directoryPathPointer, const SignedInteger64bits flags );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to invoke the 'getdents64' system call. In x86_64 architecture the system call number is '217'
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. fileDescriptor - a number representing the directory to read information from
	//			2. linuxDirectoryEntries64 - a pointer to the memory address that will contain the directory entries written be the system call
	//			3. size - the size of the memory address provided to the system call
	//
	//		Information returned to the user :
	//
	//			1. linuxDirectoryEntries64 - will store the directory entries information
	//
	//  Return value :
	//
	//		The number of bytes read. On end of directory, 0 is returned
	//
	//  Expectations :
	//
	//		1. The given file descriptor is valid
	//		2. The given pointer to the memory addres is not NULL
	//		3. 
	//
	//  Possible errors :
	//
	//		1. The system call failed - Class ErrnoException is thrown
	//		2.
	//
	EnsureRetrunValueIsUsed static inline UnsignedInteger64bits GetDirectoryEntry( const SignedInteger32bits fileDescriptor, UnsignedInteger8bits* const linuxDirectoryEntries64, const UnsignedInteger32bits size );


	// File :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to invoke the 'open' system call to create a new file. In x86_64 architecture the system call number is '2'
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. filePathPointer - the memory address that contains the file name with the path ( relative or absolute ) to create
	//			2. mode - the read and write permissions for the new created file. Needs to be one of the following :
	//
	//					S_IRWXU - 00700 - user ( file owner ) has read, write, and execute permission
	//              	S_IRUSR - 00400 - user has read permission
	//              	S_IWUSR - 00200 - user has write permission
	//              	S_IXUSR - 00100 - user has execute permission
	//             		S_IRWXG - 00070 - group has read, write, and execute permission
	//              	S_IRGRP - 00040 - group has read permission
	//              	S_IWGRP - 00020 - group has write permission
	//              	S_IXGRP - 00010 - group has execute permission
	//              	S_IRWXO - 00007 - others have read, write, and execute permission
	//             		S_IROTH - 00004 - others have read permission
	//              	S_IWOTH - 00002 - others have write permission
	//              	S_IXOTH - 00001 - others have execute permission
	//              	
	//                According to POSIX, the effect when other bits are set in mode is unspecified. On Linux, the following bits are also honored in mode :
	//
	//              	S_ISUID - 0004000 - set-user-ID bit
	//              	S_ISGID - 0002000 - set-group-ID bit
	//              	S_ISVTX - 0001000 - sticky bit
	//		
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		1. The given pointer to the memory address is not NULL
	//		2. The given pointer to the memory address contains a NULL terminated ascii string
	//		3. The given flag should one of the supported flags
	//		4. 
	//
	//  Possible errors :
	//
	//		1. The system call failed - Class ErrnoException is thrown
	//		2.
	//
	static inline void CreateFile( const AsciiCharacter* const filePathPointer, const UnsignedInteger64bits mode = S_IRWXU );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to invoke the 'unlink' system call to delete a file. In x86_64 architecture the system call number is '87'
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			filePathPointer - the memory address that contains the file name with the path ( relative or absolute ) to delete
	//		
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		1. The given pointer to the memory address is not NULL
	//		2. The given pointer to the memory address contains a NULL terminated ascii string
	//		3. The given file path exist in the file system
	//		4. 
	//
	//  Possible errors :
	//
	//		1. The system call failed - Class ErrnoException is thrown
	//		2.
	//
	static inline void DeleteFile( const AsciiCharacter* const filePathPointer );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to invoke the 'open' system call to open a file to work with. In x86_64 architecture the system call number is '2'
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. filePathPointer - the memory address that contains the file name with the path ( relative or absolute ) to open
	//			2. flags - needs to be one of the following :
	//
	//				For reading only - O_RDONLY
	//				For writing only - O_WRONLY
	//				For reading and writing - O_RDWR
	//		
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The descriptor of the file
	//
	//  Expectations :
	//
	//		1. The given pointer to the memory address is not NULL
	//		2. The given pointer to the memory address contains a NULL terminated ascii string
	//		3. The given flag should be one of the supported flags
	//		4. 
	//
	//  Possible errors :
	//
	//		1. The system call failed - Class ErrnoException is thrown
	//		2.
	//
	EnsureRetrunValueIsUsed static inline SignedInteger32bits OpenFile( const AsciiCharacter* const filePathPointer, const SignedInteger64bits flags );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to delete the content of a file
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			filePathPointer - the memory address that contains the file name with the path ( relative or absolute )
	//		
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		1. The given pointer to the memory address is not NULL
	//		2. The given pointer to the memory address contains a NULL terminated ascii string
	//		3. The given file path exist in the file system
	//		4. 
	//
	//  Possible errors :
	//
	//		1. The system call failed - Class ErrnoException is thrown
	//		2.
	//
	static inline void DeleteFileContent( const AsciiCharacter* const filePathPointer );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to invoke the 'stat' system call to get information on the file. In x86_64 architecture the system call number is '5'
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. fileDescriptor - a number representing the file to obtain information on
	//			2. fileInformationPointer - a pointer with the memory address of a preallocated stat64 structure
	//		
	//		Information returned to the user :
	//
	//			1. The system call will store the file information in the location provided by the pointer to the 'stat64' structure
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		1. The given file descriptor is valid
	//		2. The given pointer to the memory address is not NULL
	//		3. 
	//
	//  Possible errors :
	//
	//		1. The system call failed - Class ErrnoException is thrown
	//		2.
	//
	static inline void GetFileInformation( const SignedInteger32bits fileDescriptor, struct stat64* const fileInformationPointer );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to invoke the 'stat' system call to get information on the file, and return the file size in bytes. In x86_64
	//		architecture the system call number is '5'
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			fileDescriptor - a number representing the file to obtain information on
	//		
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The file size in bytes
	//
	//  Expectations :
	//
	//		1. The given file descriptor is valid
	//		2. 
	//
	//  Possible errors :
	//
	//		1. The system call failed - Class ErrnoException is thrown
	//		2.
	//
	EnsureRetrunValueIsUsed static inline UnsignedInteger64bits GetFileSizeInBytes( const SignedInteger32bits fileDescriptor );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to invoke the 'close' system call. In x86_64 architecture the system call number is '3'
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			fileDescriptor - a number representing the file to close
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		1. The given file descriptor is valid
	//		2. 
	//
	//  Possible errors :
	//
	//		1. The system call failed - Class ErrnoException is thrown
	//		2.
	//
	static inline void Close( const SignedInteger32bits fileDescriptor );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to invoke the 'read' system call. In x86_64 architecture the system call number is '0'
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. fileDescriptor - a number representing the file to read from the data
	//			2. destinationPointer - the memory address to read the data from the file to
	//			3. numberOfBytesToRead - the number of bytes to read from the file
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The number of actual bytes read. This can be different then the provided number of bytes to read, if the end of file reached, for
	//		example before the required number of bytes were read
	//
	//  Expectations :
	//
	//		1. The given file descriptor is valid
	//		2. The given pointer to the memory address is not NULL
	//		3. The given pointer to the memory address contains a NULL terminated ascii string
	//		4. The given pointer to the memory address contains enough memory space for all the required bytes to read
	//		5. The given number of bytes to read should be larger then 0
	//		6. 
	//
	//  Possible errors :
	//
	//		1. The system call failed - Class ErrnoException is thrown
	//		2.
	//
	EnsureRetrunValueIsUsed static inline UnsignedInteger64bits Read( const SignedInteger32bits fileDescriptor, void* const destinationPointer, const UnsignedInteger64bits numberOfBytesToRead );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to invoke the 'write' system call. In x86_64 architecture the system call number is '1'
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. fileDescriptor - a number representing the file to wrtie to the data
	//			2. sourcePointer - the memory address that contains the data to write to the file
	//			3. numberOfBytesToWrite - the number of bytes to write to the file
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The number of actual bytes written. This can be different then the provided number of bytes to write, if an interrupt accord during
	//		the execution for example
	//
	//  Expectations :
	//
	//		1. The given file descriptor is valid
	//		2. The given pointer to the memory address is not NULL
	//		3. The given pointer to the memory address contains a NULL terminated ascii string
	//		4. The given pointer to the memory address contains memory space at least as the number of bytes to write
	//		5. The given number of bytes to read should be larger then 0
	//		6. 
	//
	//  Possible errors :
	//
	//		1. The system call failed - Class ErrnoException is thrown
	//		2.
	//
	EnsureRetrunValueIsUsed static inline UnsignedInteger64bits Write( const SignedInteger32bits fileDescriptor, const void* const sourcePointer, const UnsignedInteger64bits numberOfBytesToWrite );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to invoke the 'lseek' system call. In x86_64 architecture the system call number is '8'
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. fileDescriptor - a number representing the file to wrtie to the data
	//			2. newOffset - the new offset for the read and write operations on the file
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		1. The given file descriptor is valid
	//		2. The given relative starting location to count the offset from is one of the three possibilites
	//		3. 
	//
	//  Possible errors :
	//
	//		1. The system call failed - Class ErrnoException is thrown
	//		2.
	//
	static inline void SetReadAndWriteMarkerOffsetForFile( const SignedInteger32bits fileDescriptor, const SignedInteger64bits newOffset );
	

	// Input and output devices :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to invoke the 'ioperm' system call, to enable access to the required ports. In x86_64 architecture the system
	//		call number is '173'. This system call is only valid for x_86 architecture
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. startingPortIdentifier - the port identifier to start enable access to
	//			2. numberOfPorts - the number of ports to allow access to starting from the given port identifier
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		1. The given identifier of the starting port exist in the system
	//		2. The number of ports starting from the given port, exist in the system
	//		3. 
	//
	//  Possible errors :
	//
	//		1. The system call failed - Class ErrnoException is thrown
	//		2.
	//
	static inline void EnableAccessToInputAndOutputPorts( const UnsignedInteger64bits startingPortIdentifier, const UnsignedInteger64bits numberOfPorts );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to invoke the 'ioperm' system call, to disable access to the required ports. In x86_64 architecture the system
	//		call number is '173'. This system call is only valid for x_86 architecture
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. startingPortIdentifier - the port identifier to start enable access to
	//			2. numberOfPorts - the number of ports to allow access to starting from the given port identifier
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		1. The given identifier of the starting port exist in the system
	//		2. The number of ports starting from the given port, exist in the system
	//		3. 
	//
	//  Possible errors :
	//
	//		1. The system call failed - Class ErrnoException is thrown
	//		2.
	//
	static inline void DisableAccessToInputAndOutputPorts( const UnsignedInteger64bits startingPortIdentifier, const UnsignedInteger64bits numberOfPorts );


	DEBUG_TOOL(

		// This part of the object is dedicated for testing :


		// Method Information :
		//
		//  Description :
		//
		//		This method is used to test the object. It is not part of the implementation, it is only used to find problems with the code
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
		static void UnitTest() __attribute__ (( __unused__ ));

	)  //  End of debug tool


private:


	// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
	NoInstances( SystemCalls );


};  //  Class SystemCalls