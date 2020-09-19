#ifndef LINUXDIRECTORYENTRY64_HPP
#define LINUXDIRECTORYENTRY64_HPP


#include "../../../../Root/Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../Root/ObjectBranch/Content/ObjectInfrastructure/ObjectInfrastructure.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../../../Root/FunctionalityBranch/Level_0/Level_1/Content/Memory/Operations/Operations.hpp"  //  Class Operations
#include "../../../../Root/FunctionalityBranch/Level_0/Level_1/Level_2/Level_3/Level_4/Content/Language/Ascii/AsciiString/AsciiString.hpp"  //  Class AsciiString
#include "../../../../Root/FunctionalityBranch/Level_0/Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../../../Root/FunctionalityBranch/Level_0/Level_1/Level_2/Content/BindObjects/Tuple/Tuple.hpp"  //  Class Tuple
#include "../../../../Root/FunctionalityBranch/Level_0/Level_1/Content/Random/Generator/Generator.hpp"  //  Class Generator


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



        // Flexible array members ( FAM ) in a structure in C :
        //
        // Flexible array members is a feature introduced in the C99 standard of the C programming language. A structure can be decalred with an array
        // without a dimension and whose size is flexible in nature. Such an array inside the structure should preferably be declared as the last
        // member of the structure and its size is variable ( can be changed at runtime ). The structure must contain at least one more named member 
        // in addition to the flexible array member. 
        //
        // For example, 
        //
        //		struct Lover
        //		{
        //			int onlyWantsMoney;
        //			char bitchName[];
        //		};
        //
        // A memory space for this structure is allocated as follows : 
        //
        //		struct FlexibleStructure* pointer = (struct FlexibleStructure*)malloc( sizeof( struct FlexibleStructure ) + sizeof( char [ strlen( stud_name ) ] ) )
        //
        // or,
        //
        //		struct FlexibleStructure* pointer = (struct FlexibleStructure*)malloc( offsetof( struct FlexibleStructure, bitchName[ BitchNameSize ] ) )
        //
        // C++ doesn't support flexible array members, either using an empty index notation or a 0 index notation
        //
        //		struct FuckThis
        //		{
        //			int size;
        //			char bitchName[];
        //		};
        //
        //		struct FuckThat
        //		{
        //			int size;
        //			char bitchName[0];
        //		};
        //
        // However, if you size the array element to 1, things are valid and work quite well.
        //
    	//		struct FuckMe
        //		{
        //			int size;
        //			char bitchName[1];
        //		};
        //
        // Store the actual size in the 'size' member, and then just reference to the entries as regualr array! 



        // This enumeration will be used to describe file types in a more human readable form
        enum class LinuxFileType : UnsignedInteger8bits
        {
        	Unknown = 0U,
        	RegularFile = 1U,
        	Directory = 2U,
        	CharacterDevice = 3U,
        	BlockDevice = 4U,
        	NamedPipe = 5U,
        	UnixDomainSocket = 6U,
        	SymbolicLink = 7U,
        	NumberOfFileTypes
        };



		// Class Information :
		//
		//  Purpose :
		//
		//		The purpose of the object is to wrap the Linux structure 'linux_dirent', and allow to get information from it easily. The system call
		//		'getdents' reads several of this structures from the directory referred to by the open file directory into a buffer. The structure is
		//		defined as follows :
		//
		//          struct linux_dirent64
		//			{
		//              ino64_t        d_ino;    	/* 64-bit inode number */
		//              off64_t        d_off;    	/* 64-bit offset to next structure */
		//              unsigned short d_reclen; 	/* Size of this dirent */
		//              unsigned char  d_type;   	/* File type */
		//              char           d_name[]; 	/* Filename (null-terminated) */
		//          };
		//
		//  Description :
		//
		//		1. This object contains an instance of the object "InstanceState" to allow each instance of this object to have a defined state
		//
		// 		2. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
		//		   providing 3 keywords :
		//
		//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
		//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
		//						member is public all the encapsulation is lost, so it should be avoided in most cases
		//
		//			2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will
		//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few
		//						   data members
		//
		//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
		//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this
		//						 part will end with the suffix __Private
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		Too many to count
		//
		class LinuxDirectoryEntry64 NotForInheritance
		{
		public:


			// Create a type definition for this object
			using SelfType = LinuxDirectoryEntry64;


			// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
			// the compiler generates a basic behavior for them if possible :


			// Method Information :
			//
			//  Description :
			//
			//		Default Constructor,
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
			//		NONE
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline LinuxDirectoryEntry64();


			// Method Information :
			//
			//  Description :
			//
			//		Constructor,
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. inode - the inode number of the current directory entry
			//			2. fileType - the current directory entry file type
			//			3. fileName - the name of the current directory entry
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
			//		1. The file type is one of the supported types
			//		2. The file name instance is ready
			//		3. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline LinuxDirectoryEntry64( UnsignedInteger64bits inode, LinuxFileType fileType, const Language::AsciiString< Memory::HeapArray >& fileName );


			// Method Information :
			//
			//  Description :
			//
			//		Constructor, to allow creating an instance with the same arguments as the parameterized constructor, just that the arguments will be
			//		wrapped in a tuple, to allow more automatic creation of instances. Each parameterized constructor will have an equivalent constructor
			//		to inokve with a tuple, which will only call the required constructor and unpack the tuple to the arguments inisde
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			arguments - the arguments needed to construct an instance, only wrapped in a tuple. The arguments are :
			//
			//				1. inode - the inode number of the current directory entry
			//				2. fileType - the current directory entry file type
			//				3. fileName - the name of the current directory entry
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
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			explicit inline LinuxDirectoryEntry64( const Tuple< UnsignedInteger64bits, LinuxFileType, const Language::AsciiString< Memory::HeapArray >& >& arguments );


			// Method Information :
			//
			//  Description :
			//
			//		Copy constructor, will operate correctly even if the other instance is in default state or self assignment
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//		    other - a reference to the instance that should be copied
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
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline LinuxDirectoryEntry64( const SelfType& other );


			// This macro will be used to add all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
			// simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
			// any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
			// be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
			// macro will be used to add the following methods to each object :
			//
			//		1. Assigenment operator
			//		2. Move constructor
			//		3. Move assigenment operator
			//		4. Reset
			//		5. State
			//
			ObjectInfrastructure_MACRO( LinuxDirectoryEntry64 )


			// Method Information :
			//
			//  Description :
			//
			//		This method is used to swap the content between this instance and the other one
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//		    other - a reference to the instance that should be swapped
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
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline void Swap( SelfType& other );


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
			//			1. inode - the inode number of the current directory entry
			//			2. fileType - the current directory entry file type
			//			3. fileName - the name of the current directory entry
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
			//		1. The file type is one of the supported types
			//		2. The file name instance is ready
			//		3. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline void Initiate( UnsignedInteger64bits inode, LinuxFileType fileType, const Language::AsciiString< Memory::HeapArray >& fileName );


			// Method Information :
			//
			//  Description :
			//
			//		Destructor, does not throw
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
			//		NONE
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline ~LinuxDirectoryEntry64() = default;


			// The following methods give access and manipulate the data inside this object :


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get the inode of the directory entry
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
			//		The inode of the directory entry
			//
			//  Expectations :
			//
			//		1. The instance is ready
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline UnsignedInteger64bits Inoode() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get the file type of the directory entry
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
			//		The file type of the directory entry
			//
			//  Expectations :
			//
			//		1. The instance is ready
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline LinuxFileType FileType() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get the file name of the directory entry
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
			//		The file name of the directory entry
			//
			//  Expectations :
			//
			//		1. The instance is ready
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline const Language::AsciiString< Memory::HeapArray >& FileName() const;


			// The following methods declare the overloaded operators for the object :


			// Method Information :
			//
			//  Description :
			//
			//		Use this operator to check if the this instance match the other
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//		    other - a reference to the instance that should be compared with this object
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		1. true - if the 2 instances are the same
			//		2. false - otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline Boolean operator==( const SelfType& other ) const;


			// Method Information :
			//
			//  Description :
			//
			//		Use this operator to check if the this instance does not match the other
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//		    other - a reference to the instance that should be compared with this object
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		1. true - if the 2 instances are not the same
			//		2. false - otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline Boolean operator!=( const SelfType& other ) const;


			// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have
			// access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring
			// a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to generate a random instance of this object
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. rangeForInode - this will be used to limit the possible values of the inode in the random instance
			//			2. rangeForFileType - this will be used to limit the possible values of the inode in the random instance
			//			3. fileName - a file name for the random instance, if not provided a file name will be randomly created
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		A random generated instance
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			static inline LinuxDirectoryEntry64 GenerateRandomInstance( NumericRange< UnsignedInteger64bits > rangeForInode = NumericRange< UnsignedInteger64bits >( 3UL, 30000UL ), NumericRange< UnsignedInteger8bits > rangeForFileType = NumericRange< UnsignedInteger8bits >( 0U, static_cast< UnsignedInteger8bits >( LinuxFileType::NumberOfFileTypes ) ), const Language::AsciiString< Memory::HeapArray >& fileName = Language::AsciiString< Memory::HeapArray >() );


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
				static void Test() __attribute__ (( __unused__ ));

			)  //  End of debug tool


		private:


			// This object will store the inode number of the directory
			UnsignedInteger64bits member_inode;

			// This object will store the type of the entry
			LinuxFileType member_entryType;

			// This object will store the file name. It will contain a NULL terminator. In Linux which is written in C, this member is a flexible array member.
			// Flexible array member in C++ is not allowed, and therefore it is has a size of 1
			Language::AsciiString< Memory::HeapArray > member_fileName;


		};  //  Class LinuxDirectoryEntry64




































//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************




































		// Method Information :
		//
		//  Description :
		//
		//		Default Constructor,
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
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline LinuxDirectoryEntry64::LinuxDirectoryEntry64() :
		member_state(),
		member_inode( 0UL ),
		member_fileType( LinuxFileType::Unknown ),
		member_fileName()
		{}


		// Method Information :
		//
		//  Description :
		//
		//		Constructor,
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. inode - the inode number of the current directory entry
		//			2. fileType - the current directory entry file type
		//			3. fileName - the name of the current directory entry
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
		//		1. The file type is one of the supported types
		//		2. The file name instance is ready
		//		3. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline LinuxDirectoryEntry64::LinuxDirectoryEntry64( UnsignedInteger64bits inode, LinuxFileType fileType, const Language::AsciiString< Memory::HeapArray >& fileName ) :
		member_state( InstanceState::Ready ),
		member_inode( inode ),
		member_fileType( fileType ),
		member_fileName( fileName )
		{
		    // Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertInstanceIsReady_MACRO( fileName )
		}


		// Method Information :
		//
		//  Description :
		//
		//		Constructor, to allow creating an instance with the same arguments as the parameterized constructor, just that the arguments will be
		//		wrapped in a tuple, to allow more automatic creation of instances. Each parameterized constructor will have an equivalent constructor
		//		to inokve with a tuple, which will only call the required constructor and unpack the tuple to the arguments inisde
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			arguments - the arguments needed to construct an instance, only wrapped in a tuple. The arguments are :
		//
		//				1. inode - the inode number of the current directory entry
		//				2. fileType - the current directory entry file type
		//				3. fileName - the name of the current directory entry
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
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline LinuxDirectoryEntry64::LinuxDirectoryEntry64( const Tuple< UnsignedInteger64bits, LinuxFileType, const Language::AsciiString< Memory::HeapArray >& >& arguments ) :
		LinuxDirectoryEntry64( arguments.template Entry< 0 >(), arguments.template Entry< 1 >(), arguments.template Entry< 2 >() )
		{}


		// Method Information :
		//
		//  Description :
		//
		//		Copy constructor, will operate correctly even if the other instance is in default state or self assignment
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//		    other - a reference to the instance that should be copied
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
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline LinuxDirectoryEntry64::LinuxDirectoryEntry64( const SelfType& other ) :
		member_state( other.member_state ),
		member_inode( other.member_inode ),
		member_fileType( other.member_fileType ),
		member_fileName( other.member_fileName )
		{}


		// Method Information :
		//
		//  Description :
		//
		//		This method is used to swap the content between this instance and the other one
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//		other - a reference to the instance that should be swaped
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
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		void LinuxDirectoryEntry64::Swap( SelfType& other )
		{
		    // Swap betwen the state instances
		    member_state.Swap( other.member_state );

			// Swap between the indoes
			Memory::Operations::Swap< UnsignedInteger64bits >( member_inode, other.member_inode );

			// Swap between the file types
			Memory::Operations::Swap< UnsignedInteger8bits >( member_fileType, other.member_fileType );

			// Swap between the file names
			member_fileName.Swap( other.member_fileName );
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
		//			1. inode - the inode number of the current directory entry
		//			2. fileType - the current directory entry file type
		//			3. fileName - the name of the current directory entry
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
		//		1. The file type is one of the supported types
		//		2. The file name instance is ready
		//		3. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline void LinuxDirectoryEntry64::Initiate( UnsignedInteger64bits inode, LinuxFileType fileType, const Language::AsciiString< Memory::HeapArray >& fileName )
		{
		    // Use the required constructor to create an instance. It will be swaped with this instance, leaving this instance with the new data. When sequence control will
		    // leave this scope it delete the old data if exist
		    SelfType instanceCreatedUsingTheRequiredConstructor( inode, fileType, fileName );

		    // Swap between this instance and the temporary instance
		    Swap( instanceCreatedUsingTheRequiredConstructor );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the inode of the directory entry
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
		//		The inode of the directory entry
		//
		//  Expectations :
		//
		//		1. The instance is ready
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline UnsignedInteger64bits LinuxDirectoryEntry64::Inoode() const
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertThisInstanceIsReady_MACRO

			// Return the inode number of this directory entry
			return ( member_inode );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the file type of the directory entry
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
		//		The file type of the directory entry
		//
		//  Expectations :
		//
		//		1. The instance is ready
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline LinuxFileType LinuxDirectoryEntry64::FileType() const
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertThisInstanceIsReady_MACRO

			// Return the file type of this directory entry
			return ( member_fileType );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the file name of the directory entry
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
		//		The file name of the directory entry
		//
		//  Expectations :
		//
		//		1. The instance is ready
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline const Language::AsciiString< Memory::HeapArray >& LinuxDirectoryEntry64::FileName() const
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertThisInstanceIsReady_MACRO

			// Return the file name of this directory entry
			return ( member_fileName );
		}

































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************




































		// Method Information :
		//
		//  Description :
		//
		//		Use this operator to check if the this instance match the other
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//		    other - a reference to the instance that should be compared with this object
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		1. true - if the 2 instances are the same
		//		2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline Boolean LinuxDirectoryEntry64::operator==( const SelfType& other ) const
		{
			// Check if both or only one of the instances is in default state
			CompareInstances_BothInDefaultStateReturnTrue_OnlyOneInDefaultStateReturnFalse_OtherwiseContinue_MACRO

			// Check if the inode, file type and file name match, and return the result
			return ( ( member_inode == other.member_inode ) && ( member_fileType == other.member_fileType ) && ( member_fileName == other.member_fileName ) );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this operator to check if the this instance does not match the other
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//		    other - a reference to the instance that should be compared with this object
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		1. true - if the 2 instances are not the same
		//		2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline Boolean LinuxDirectoryEntry64::operator!=( const SelfType& other ) const
		{
			// Return the negotiated value from the equal operator
			return ( !( *this == other ) );
		}




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************




































		// Method Information :
		//
		//  Description :
		//
		//      Use this method to generate a random instance of this object
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. rangeForInode - this will be used to limit the possible values of the inode in the random instance
		//			2. rangeForFileType - this will be used to limit the possible values of the inode in the random instance
		//			3. fileName - a file name for the random instance, if not provided a file name will be randomly created
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		A random generated instance
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline LinuxDirectoryEntry64 LinuxDirectoryEntry64::GenerateRandomInstance( NumericRange< UnsignedInteger64bits > rangeForInode, NumericRange< UnsignedInteger8bits > rangeForFileType, const Language::AsciiString< Memory::HeapArray >& fileName )
		{
			// Create an instance
			SelfType randomInstance;

			// Check if a file name was provided
			if ( fileName.State().Get() == InstanceState::Default )
			{
				// A file name was not provide, a random one will be created

				// This object will store the random file name
				Language::AsciiString< Memory::HeapArray > randomFileName = MOVE( Language::AsciiString< Memory::HeapArray >::GenerateRandomInstance( NumericRange< UnsignedInteger64bits >( 4UL, 128UL ), NumericRange< SignedInteger8bits >( 'a', '{' ) ) );

				// // Add one of the suffixes to the file
				// switch ( Random::Generator::Get< UnsignedInteger8bits >() % 4U )
				// {

				// 	case 0 :
				// 	{
				// 		randomFileName += ".hpp";

				// 		break;
				// 	}
				// 	case 1 :
				// 	{
				// 		randomFileName += ".cpp";

				// 		break;
				// 	}
				// 	case 2 :
				// 	{
				// 		randomFileName += ".txt";

				// 		break;
				// 	}
				// 	default :
				// 	{
				// 		randomFileName += ".jpg";

				// 		break;
				// 	}

				// }

				// Initiate the random instance
				randomInstance.Initiate( Random::Generator::Get< UnsignedInteger64bits >( rangeForInode ), Random::Generator::Get< UnsignedInteger8bits >( rangeForFileType ), randomFileName );
			}
			else
			{
				// Initiate the random instance
				randomInstance.Initiate( Random::Generator::Get< UnsignedInteger64bits >( rangeForInode ), Random::Generator::Get< UnsignedInteger8bits >( rangeForFileType ), fileName );	
			}

			// Return a copy of the instance
			return ( MOVE( randomInstance ) );
		}













	}  //  Namespace Linux

}  //  Namespace Universe



#endif  // LINUXDIRECTORYENTRY64_HPP