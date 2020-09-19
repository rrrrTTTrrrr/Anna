#ifndef DIRECTORY_HPP
#define DIRECTORY_HPP


//#include <dirent.h>  //  Function opendir, Function fdopendir, Function closedir, Function readdir


#include "../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../ObjectBranch/Content/ObjectInfrastructure/ObjectInfrastructure.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../FunctionalityBranch/Level_0/Level_1/Content/Memory/Operations/Operations.hpp"  //  Class Operations
#include "../FunctionalityBranch/Level_0/Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../Content/Metaprogramming/Tuple/Tuple.hpp"  //  Class Tuple
#include "../FunctionalityBranch/Level_0/Content/Random/Generator/Generator.hpp"  //  Class Generator


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
		//          }
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
		class Directory NotForInheritance
		{
		public:


			// Create a type definition for this object
			using SelfType = Directory;


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
			inline Directory();


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
			explicit inline Directory();


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
			//				1.
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
			explicit inline Directory( const Tuple< Type >& arguments );


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
			inline Directory( const SelfType& other );


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
			ObjectInfrastructure_MACRO( Directory )


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
			//		Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
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
			inline void Initiate();


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
			inline ~Directory();


			// The following methods give access and manipulate the data inside this object :











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
			Boolean operator==( const SelfType& other ) const;


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
			//			rangeFor - this will be used to limit the possible values of the {} in the random instance
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
			static inline SelfType GenerateRandomInstance( NumericRange< Type > rangeFor = NumericRange< Type >() );


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


			// This object will store the name and path of the directory
			Language::AsciiString< Memory::HeapArray > member_directoryNameAndPath;

			// This object will store the directory descriptor
			UnsignedInteger32bits member_directoryDescriptor;

			// This object will store all the Linux directory entries of the directory
			Memory::DynamicArray< LinuxDirectoryEntry64 > member_files;


			// Static data members do not belong to any instance, they belong to the object. Like every global variable it is created with the start of the program
			// and only destroyed when the program ends. The access to the static member is bound to this object of course


			// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
			// rather help implement it :


			// Friend class or friend function can access private and protected members of other object in which it is declared as friend. It is sometimes useful
			// to allow a particular object to access private members of other object. The declration of such function is private, because these functions are part
			// of the implemntation, which the user should not be aware of. The use of this functions is not limited to the object's scope. One of the problems that
			// friend declaration solves is when the object needs to be as a right side operand in expressions. Every method in the object is implicitly added a pointer
			// to the location of the object data with the name "this", and to enable this the method must be called from an existing instance. This means that the
			// object can only be implemented as the left side operand of an expression with methods, and friend functions and objects does not have this limitation


		};  //  Class Directory




































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
		inline Directory::Directory() :
		member_state(),
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
		//		1. The given ascii string with the directory name and path is ready
		//		2. The given ascii string with the directory name and path is larger then 0
		//		3. The directory exist
		//		4. 
		//
		//  Possible errors :
		//
		//		NONE
		//
		Directory::Directory( const Language::AsciiString< Memory::HeapArray >& directoryNameAndPath ) :
		member_state( InstanceState::Ready ),
		member_directoryNameAndPath( directoryNameAndPath ),
		member_directoryDescriptor( OpenDirectory( directoryNameAndPath.RawString(), O_RDWR ) ),
		member_directoryEntries()
		{
		    // Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertInstanceIsReady_MACRO( directoryNameAndPath )
			AssertInstanceSizeIsLargerThenZero_MACRO( directoryNameAndPath )

			// This object will store the size of the directory entries buffer
			constexpr UnsignedInteger64bits directoryEntriesBufferSize = 4096UL;

			// This buffer will store all the 'linux_dirent64' directory entries for the current directory
			UnsignedInteger8bits directoryEntries[ directoryEntriesBufferSize ] = {0};

			// This object will store the used size in bytes of the directory entries
			UnsignedInteger64bits member_directoryEntriesUsedSizeInBytes = GetDirectoryEntry( member_directoryDescriptor, reinterpret_cast< linux_dirent64* >( directoryEntries ), directoryEntriesBufferSize );

			// This object will be used to point to the directory entries as the Linux structure 'linux_dirent64'
			linux_dirent64* linuxDirectoryEntry = 0UL;

			// This object will be used as an offset to get the current memory address at the directory entries buffer to work on
			UnsignedInteger64bits offset = 0UL;

			// Loop on all the directory entries
			for ( offset < member_directoryEntriesUsedSizeInBytes )
			{
				// Cast the current memory address to a 'linux_dirent64'
				linuxDirectoryEntry = reinterpret_cast< linux_dirent64* >( directoryEntries + offset );

				// Check if the current entry is a directory
				if ( linuxDirectoryEntry->member_fileType != DT_DIR )
				{
					// The current entry is a regular file

					// Add the file
					member_directoryEntries.AddData( LinuxDirectoryEntry64( linuxDirectoryEntry->member_inode, linuxDirectoryEntry->member_fileType, linuxDirectoryEntry->member_fileName ) );
				}

				// Increment the offset to the next directory entry
				offset += linuxDirectoryEntry->member_offsetToNextStructure;
			}

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
		//				1.
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
		inline Directory::Directory( const Tuple< Type >& arguments ) :
		Directory( arguments.template Entry< 0 >(), arguments.template Entry< 1 >() )
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
		inline Directory::Directory( const SelfType& other ) :
		member_state( other.member_state ),
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
		void Directory::Swap( SelfType& other )
		{
		    // Swap betwen the state instances
		    member_state.Swap( other.member_state );
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
		inline void Directory::Initiate()
		{
		    // Use the required constructor to create an instance. It will be swaped with this instance, leaving this instance with the new data. When sequence control will
		    // leave this scope it delete the old data if exist
		    SelfType instanceCreatedUsingTheRequiredConstructor(  );

		    // Swap between this instance and the temporary instance
		    Swap( instanceCreatedUsingTheRequiredConstructor );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Destructor, does not throw any exceptions
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
		inline Directory::~Directory()
		{
       	    // Check if the object is in default state, then noting needs to be done
       	    ReturnIfExpressionIsTrue_MACRO( member_state.Get() == InstanceState::Default )
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
		Boolean Directory::operator==( const SelfType& other ) const
		{
			// Check if both or only one of the instances is in default state
			CompareInstances_BothInDefaultStateReturnTrue_OnlyOneInDefaultStateReturnFalse_OtherwiseContinue_MACRO
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
		inline Boolean Directory::operator!=( const SelfType& other ) const
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
		//			rangeFor - this will be used to limit the possible values of the {} in the random instance
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
		inline Directory Directory::GenerateRandomInstance( NumericRange< Type > rangeFor )
		{
			// Create an instance
			SelfType randomInstance;

			// Return a copy of the instance
			return ( MOVE( randomInstance ) );
		}




































//  ********************************************************   TEMPLATE OR INLINE PURE VIRTUAL METHODS IMPLEMENTATION   *********************************************************




































//	**********************************************************   TEMPLATE OR INLINE PROTECTED METHODS IMPLEMENTATION   **********************************************************




































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************




































// ***************************************************************   NESTED CLASS PUBLIC METHODS IMPLEMENTATION -    ************************************************************




































// **********************************************************   INLINE AND TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   ***********************************************************




































	}  //  Namespace Linux

}  //  Namespace Universe



#endif  // DIRECTORY_HPP