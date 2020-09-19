#ifndef SYSTEMCALLS_HPP
#define SYSTEMCALLS_HPP


#include "/usr/include/asm-generic/fcntl.h"  //  Flags and modes
#include "/usr/include/x86_64-linux-gnu/sys/stat.h"  //  Defines the structure of the data returned by the functions 'fstat', 'lstat' and 'stat', and symbolic names for the st_mode
#include "/usr/include/x86_64-linux-gnu/asm/unistd.h"  //  Macro __NR_SystemCallName


#include "../../../Root/Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../Root/FunctionalityBranch/Level_0/Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../SystemCall/SystemCall.hpp"  //  Class SystemCall


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe
{



	// When a type is forward declared, all the compiler knows is that this type exists. It does not know its size, members or methods. This is why its
	// called incomplete type. Therefore, it can not be used to declare a variable, member or base class since the compiler would need the layout of the
	// type. In other words, it can not be used for anything that requires information on the specific type. What can be done is declaring pointer and
	// reference to the incomplete type. The pointer and refernce can act as a variable, argument to a method or as the return type.
	//
	// Forward declarations :
	//
	//  NONE
	//



    namespace Linux
    {


    	// This is the Linux structure to hold information on a specific directory entry
		struct linux_dirent64
		{
		   UnsignedInteger64bits member_inode;    					// 64-bit inode number
		   UnsignedInteger64bits member_offsetToNextStructure;    	// 64-bit offset to next structure
		   UnsignedInteger64bits member_size; 						// Size of this directory entry
		   UnsignedInteger64bits member_fileType;   				// File type
		   SignedInteger8bits member_fileName[1]; 					// Filename ( NULL terminated )
		};



		// The signatures of all the Linux system calls are in the file :
		//
		//	/usr/src/linux-headers-4.15.0-65/include/linux/syscalls.h
		//



		// For ubuntu distribution of Linux, the correct 'unistd.h' file to include is located at :
		//
		//	/usr/include/x86_64-linux-gnu/asm/unistd.h
		//



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
			//			1. memoryAddress_fileNameAndPath - the memory address that contains the file name with the path ( relative or absolute ) to open
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
			//		3. The given flag should one of the supported flags
			//		4. 
			//
			//  Possible errors :
			//
			//		1. The system call failed - Class ErrnoException is thrown
			//		2.
			//
			static inline SignedInteger32bits OpenFile( const SignedInteger8bits* memoryAddress_fileNameAndPath, SignedInteger64bits flags );


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
			//			1. memoryAddress_directoryNameAndPath - the memory address that contains the directory name with the path ( relative or absolute ) to open
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
			static inline SignedInteger32bits OpenDirectory( const SignedInteger8bits* memoryAddress_directoryNameAndPath, SignedInteger64bits flags );


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
			//			1. memoryAddress_fileNameAndPath - the memory address that contains the file name with the path ( relative or absolute ) to create
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
			static inline void CreateFile( const SignedInteger8bits* memoryAddress_fileNameAndPath, UnsignedInteger64bits mode );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to invoke the 'open' system call to create a new directory. In x86_64 architecture the system call number is '2'
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. memoryAddress_directoryNameAndPath - the memory address that contains the directory name with the path ( relative or absolute ) to create
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
			//		3. The given flag should one of the supported flags
			//		4. 
			//
			//  Possible errors :
			//
			//		1. The system call failed - Class ErrnoException is thrown
			//		2.
			//
			static inline void CreateDirectory( const SignedInteger8bits* memoryAddress_directoryNameAndPath, UnsignedInteger64bits mode );


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
			static inline void Close( UnsignedInteger32bits fileDescriptor );


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
			//			2. memoryAddress_ReadFrom - the memory address to read the time from the file to
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
			static inline SignedInteger64bits Read( UnsignedInteger32bits fileDescriptor, SignedInteger8bits* memoryAddress_ReadFrom, UnsignedInteger64bits numberOfBytesToRead );


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
			//			2. memoryAddress_WriteTo - the memory address that contains the data to write to the file
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
			static inline SignedInteger64bits Write( UnsignedInteger32bits fileDescriptor, const SignedInteger8bits* memoryAddress_WriteTo, UnsignedInteger64bits numberOfBytesToWrite );


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
			//			3. relativeStartingLocationToCountOffsetFrom - the new offset will be counted from this relative location, which can be the beginning of the file ( SEEK_SET ),
			//														   the current offset for read and write ( SEEK_CUR ) and the last is from the end of the file ( SEEK_END )
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		The resulting offset location as measured in bytes from the beginning of the file is returned
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
			static inline SignedInteger64bits SetReadAndWriteMarkerOffsetForFile( UnsignedInteger32bits fileDescriptor, SignedInteger64bits newOffset, UnsignedInteger32bits relativeStartingLocationToCountOffsetFrom );


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
			//			2. memoryAddress_linux_dirent64 - a pointer to the memory address of a 'linux_dirent64' structure
			//			3. size - the size of the memory address provided to the system call
			//
			//		Information returned to the user :
			//
			//			NONE
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
			static inline SignedInteger64bits GetDirectoryEntry( UnsignedInteger32bits fileDescriptor, linux_dirent64* linuxDirectoryEntry64, UnsignedInteger32bits size );
			

			// DEBUG_TOOL(

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
				static void Test() __attribute__ (( __unused__ ));

			// )  //  End of debug tool


		private:


			// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
			NoInstances_MACRO( SystemCalls )


		};  //  Class SystemCalls


































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************

















		

















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
		//			1. memoryAddress_fileNameAndPath - the memory address that contains the file name with the path ( relative or absolute ) to open
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
		//		3. The given flag should one of the supported flags
		//		4. 
		//
		//  Possible errors :
		//
		//		1. The system call failed - Class ErrnoException is thrown
		//		2.
		//
		inline SignedInteger32bits SystemCalls::OpenFile( const SignedInteger8bits* memoryAddress_fileNameAndPath, SignedInteger64bits flags )
		{
            // This will be added only in test mode, to ensure that the given data to the method is valid
            AssertPointer_MACRO( memoryAddress_fileNameAndPath )

			// Invoke the system call using the required arguments, and return the file descriptor
			return ( SystemCall< 2, const SignedInteger8bits*, SignedInteger64bits >::Invoke( __NR_open, Tuple< const SignedInteger8bits*, SignedInteger64bits >( memoryAddress_fileNameAndPath, flags ) ) );
		}


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
		//			1. memoryAddress_directoryNameAndPath - the memory address that contains the directory name with the path ( relative or absolute ) to open
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
		inline SignedInteger32bits SystemCalls::OpenDirectory( const SignedInteger8bits* memoryAddress_directoryNameAndPath, SignedInteger64bits flags )
		{
            // This will be added only in test mode, to ensure that the given data to the method is valid
            AssertPointer_MACRO( memoryAddress_directoryNameAndPath )

			// Invoke the system call using the required arguments, and return the directory descriptor
			return ( SystemCall< 2, const SignedInteger8bits*, SignedInteger64bits >::Invoke( __NR_open, Tuple< const SignedInteger8bits*, SignedInteger64bits >( memoryAddress_directoryNameAndPath, ( flags | O_DIRECTORY ) ) ) );
		}


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
		//			1. memoryAddress_fileNameAndPath - the memory address that contains the file name with the path ( relative or absolute ) to create
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
		inline void SystemCalls::CreateFile( const SignedInteger8bits* memoryAddress_fileNameAndPath, UnsignedInteger64bits mode )
		{
            // This will be added only in test mode, to ensure that the given data to the method is valid
            AssertPointer_MACRO( memoryAddress_fileNameAndPath )

			// Invoke the system call using the required arguments, the system call will return a descriptor for the newly created file, but this
			// descriptor can have read and write permissions or not, it is known. Then the descriptor will be used to close the file, and let the
			// user later open the file with the required flags
			Close( SystemCall< 3, const SignedInteger8bits*, SignedInteger64bits, UnsignedInteger64bits >::Invoke( __NR_open, Tuple< const SignedInteger8bits*, SignedInteger64bits, UnsignedInteger64bits >( memoryAddress_fileNameAndPath, O_CREAT, mode ) ) );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to invoke the 'open' system call to create a new directory. In x86_64 architecture the system call number is '2'
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. memoryAddress_directoryNameAndPath - the memory address that contains the directory name with the path ( relative or absolute ) to create
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
		//		3. The given flag should one of the supported flags
		//		4. 
		//
		//  Possible errors :
		//
		//		1. The system call failed - Class ErrnoException is thrown
		//		2.
		//
		inline void SystemCalls::CreateDirectory( const SignedInteger8bits* memoryAddress_directoryNameAndPath, UnsignedInteger64bits mode )
		{
            // This will be added only in test mode, to ensure that the given data to the method is valid
            AssertPointer_MACRO( memoryAddress_directoryNameAndPath )

			// Invoke the system call using the required arguments, the system call will return a descriptor for the newly created directory, but this
			// descriptor can have read and write permissions or not, it is known. Then the descriptor will be used to close the directory, and let the
			// user later open the directory with the required flags
			Close( SystemCall< 3, const SignedInteger8bits*, SignedInteger64bits, UnsignedInteger64bits >::Invoke( __NR_open, Tuple< const SignedInteger8bits*, SignedInteger64bits, UnsignedInteger64bits >( memoryAddress_directoryNameAndPath, ( O_CREAT | O_DIRECTORY ), mode ) ) );
		}


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
		inline void SystemCalls::Close( UnsignedInteger32bits fileDescriptor )
		{
			// Invoke the system call using the required arguments
			SystemCall< 1, UnsignedInteger64bits >::Invoke( __NR_close, Tuple< UnsignedInteger64bits >( fileDescriptor ) );
		}


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
		//			2. memoryAddress_ReadFrom - the memory address to read the time from the file to
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
		inline SignedInteger64bits SystemCalls::Read( UnsignedInteger32bits fileDescriptor, SignedInteger8bits* memoryAddress_ReadFrom, UnsignedInteger64bits numberOfBytesToRead )
		{
            // This will be added only in test mode, to ensure that the given data to the method is valid
            AssertPointer_MACRO( memoryAddress_ReadFrom )
            AssertSizeIsLargerThenZero_MACRO( numberOfBytesToRead )

			// Invoke the system call using the required arguments, and return the number of bytes actually read from the file
			return ( SystemCall< 3, UnsignedInteger64bits, const SignedInteger8bits*, UnsignedInteger64bits >::Invoke( __NR_read, Tuple< UnsignedInteger64bits, const SignedInteger8bits*, UnsignedInteger64bits >( fileDescriptor, memoryAddress_ReadFrom, numberOfBytesToRead ) ) );
		}


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
		//			2. memoryAddress_WriteTo - the memory address that contains the data to write to the file
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
		inline SignedInteger64bits SystemCalls::Write( UnsignedInteger32bits fileDescriptor, const SignedInteger8bits* memoryAddress_WriteTo, UnsignedInteger64bits numberOfBytesToWrite )
		{
            // This will be added only in test mode, to ensure that the given data to the method is valid
            AssertPointer_MACRO( memoryAddress_WriteTo )
            AssertSizeIsLargerThenZero_MACRO( numberOfBytesToWrite )

			// Invoke the system call using the required arguments, and return the number of bytes actually written to the file
			return ( SystemCall< 3, UnsignedInteger64bits, const SignedInteger8bits*, UnsignedInteger64bits >::Invoke( __NR_write, Tuple< UnsignedInteger64bits, const SignedInteger8bits*, UnsignedInteger64bits >( fileDescriptor, memoryAddress_WriteTo, numberOfBytesToWrite ) ) );
		}


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
		//			3. relativeStartingLocationToCountOffsetFrom - the new offset will be counted from this relative location, which can be the beginning of the file ( SEEK_SET ),
		//														   the current offset for read and write ( SEEK_CUR ) and the last is from the end of the file ( SEEK_END )
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		The resulting offset location as measured in bytes from the beginning of the file is returned
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
		inline SignedInteger64bits SystemCalls::SetReadAndWriteMarkerOffsetForFile( UnsignedInteger32bits fileDescriptor, SignedInteger64bits newOffset, UnsignedInteger32bits relativeStartingLocationToCountOffsetFrom )
		{
            // This will be added only in test mode, to ensure that the given data to the method is valid
            Assert_MACRO( ( ( relativeStartingLocationToCountOffsetFrom == SEEK_SET ) || ( relativeStartingLocationToCountOffsetFrom == SEEK_CUR ) || ( relativeStartingLocationToCountOffsetFrom == SEEK_END ) ), "The relative starting location to set the offset from should be - SEEK_SET, SEEK_CUR or SEEK_END" )

			// Invoke the system call using the required arguments, and return the number of bytes actually written to the file
			return ( SystemCall< 3, UnsignedInteger64bits, SignedInteger64bits, UnsignedInteger64bits >::Invoke( __NR_lseek, Tuple< UnsignedInteger64bits, SignedInteger64bits, UnsignedInteger64bits >( fileDescriptor, newOffset, relativeStartingLocationToCountOffsetFrom ) ) );
		}


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
		//			2. memoryAddress_linux_dirent64 - a pointer to the memory address of a 'linux_dirent64' structure
		//			3. size - the size of the memory address provided to the system call
		//
		//		Information returned to the user :
		//
		//			NONE
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
		inline SignedInteger64bits SystemCalls::GetDirectoryEntry( UnsignedInteger32bits fileDescriptor, linux_dirent64* linuxDirectoryEntry64, UnsignedInteger32bits size )
		{
            // This will be added only in test mode, to ensure that the given data to the method is valid
            AssertPointer_MACRO( linuxDirectoryEntry64 )
            Assert_MACRO( ( size > 0UL ), "The size of the memory address should be larger then 0" )

			// Invoke the system call using the required arguments, and return the number of bytes actually read
			return ( SystemCall< 3, UnsignedInteger64bits, linux_dirent64*, UnsignedInteger64bits >::Invoke( __NR_getdents64, Tuple< UnsignedInteger64bits, linux_dirent64*, UnsignedInteger64bits >( fileDescriptor, linuxDirectoryEntry64, size ) ) );
		}































//	**********************************************************   TEMPLATE OR INLINE PROTECTED METHODS IMPLEMENTATION   **********************************************************




































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************




































    }  //  Namespace Linux

}  //  Namespace Universe


#endif  // SYSTEMCALLS_HPP