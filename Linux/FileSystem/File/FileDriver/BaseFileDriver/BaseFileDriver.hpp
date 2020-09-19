#ifndef  BASEFILEDRIVER_HPP
#define  BASEFILEDRIVER_HPP



// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../ErrorHandling/Exception/Exception.hpp"  //  Class Exception
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
    	//  NONE
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
    	// not be used


        // The keyword "explicit" before constructors, is used to prevent situations
        // where a given argument to a function does not match, but this argument can
        // be used to create an instance of a class that does match the required argument
        // to the function, for example the next function :
        //
        //      void PrintObject( Object& object )
        //
        // and the Object's constructor :
        //
        //      Object( const OtherObject& otherObject )
        //
        // if the keyword explicit is not used for the constructor, the next call will pass :
        //
        //      PrintObject( otherObject )
        //
        // Becuase the compiler check the current type and see the mismatch, now he moves on to
        // check if there is a type conversion that can be performed to make the arguments match,
        // and well there is a conversion to Object which is the required argument.
        // This causes unwanted conversions sometimes, and to prevent it, constructors must always
        // be declared with the keyword "explicit". If those conversions are wanted, an explanation
        // must be added, and the comment must be added -> //  Non explicit on purpose


        // In unix the file permissions ( read, write and execute ) are distincit, meaning current user
        // can have all of them, can have only 1, only 2 and at last the user can have none of them.
        // This implies that sometimes a user can have write permission but not read. Shell scripts
        // must have both execute and read permission to execute, becuase the shell interpreter needs
        // to read the file


        // System call - open - syntax :
        //
        // int open( const char *pathname, int flags, mode_t mode )
        //
        // The argument flags must include one of the following access modes :
        //
        // 		1. O_RDONLY - read only
        // 		2. O_WRONLY - write only
        // 		3. O_RDWR - read and write
        //
        // In  addition, zero or more file creation flags and file status flags can be bitwise-or'd in flags :
        //
        // 		O_CREAT - if the file does not exist, it will be created
        //
        // The argument mode must be included when using the O_CREAT flag, the mode options are :
        //
        //	 	1. S_IRWXU - 00700 - user (file owner) has read, write, and execute permission
        // 		2. S_IRUSR - 00400 - user has read permission
        // 		3. S_IWUSR - 00200 - user has write permission
        // 		4. S_IXUSR - 00100 - user has execute permission
        // 		5. S_IRWXG - 00070 - group has read, write, and execute permission
        // 		6. S_IRGRP - 00040 - group has read permission
        // 		7. S_IWGRP - 00020 - group has write permission
        // 		8. S_IXGRP - 00010 - group has execute permission
        // 		9. S_IRWXO - 00007 - others have read, write, and execute permission
        // 		10. S_IROTH - 00004 - others have read permission
        // 		11. S_IWOTH - 00002 - others have write permission
        // 		12. S_IXOTH - 00001 - others have execute permission
        //
        // The term open file description is the one used by POSIX to refer to the entries in the system-wide table of open files.
        //  In other contexts, this object is variously also called an "open file object", a "file handle", an "open file table entry",
        // or—in kernel-developer parlance—a struct file. When a file descriptor is duplicated ( using dup or similar ), the duplicate
        // refers to the same open file description as the original file descriptor, and the  two  file  descriptors  consequently
        // share the file offset and file status flags.  Such sharing can also occur between processes: a child process created via
        // fork inherits duplicates of its parent's file descriptors, and those duplicates refer to the same open file descriptions.
        // Each open of a file creates a new open file description; thus, there may be multiple open file descriptions corresponding
        // to a file inode


        // Systme call - fcntl - syntx :
        //
        // int fcntl(int fd, int cmd, ... /* arg */ )
        //
        // The required capability of this system call is to duplicate new file descriptor from
        // existing one, the syntax :
        //
        // int fcntl( oldFileDescriptor, F_DUPFD, 0 )


        // System call - access - syntax :
        //
        // int access( const char *pathname, int mode )
        //
        // The mode specifies the accessibility checks to be performed, and is either the value F_OK, or a mask consisting of the bitwise 
        // OR of one or more of R_OK, W_OK, and X_OK. F_OK tests for the existence of the file.  R_OK, W_OK, and X_OK test whether the file 
        // exists and grants read, write, and execute permissions, respectively


        // The file size limit of a filesystem is generally decided by the size of the variable containing
        // its file size. In a filesystem where the size is defined as a 32 bit unsigned integer you will not
        // be able to store a file larger than 2^32-1 ( 4294967295 ) bytes in size. On many modern filesystems
        // file size is commonly stored as 64 bits which gives a maximum file size of 2^64-1, a very large number.
        // The maximum size of the filesystem itself is generally limited by the size of the addresses of the
        // filesystem blocks times the filesystem block size. On old FAT16 filesystems the addresses were limited
        // to 16 bits ( 65536 unique addresses ) and block ( or cluster ) size were limited to maximum 64kB, this
        // led to the limit of 4GB maximum filesystem size, this was the reason that a larger variant, FAT32, was
        // developed. On modern filesystems such as NTFS, ext4, btrfs, and many others the maximum filesystem size
        // is very large and not likely to be hit in a long time. However, because of limitations in the implementations,
        // there are some artificial limits that are lower than the actual format limit in some cases, for example
        // NTFS has a filesystem size limit of 256TB


        // File descriptors that come from a dup call, share file offset and status, so doing a write
        // on one will affect the position of the other also. If, on the other hand, they come from two
        // separate open calls, each will have their own file offset and status. A file descriptor is
        // mostly just a reference to a kernel file structure, and it is that kernel structure that contains
        // most of the state. When opening a file, a new kernel file structure is created and a new file
        // descriptor that refers to it. When duplicating a file descriptor ( or pass a file descriptor
        // through sendmsg ), a new reference to the same kernel file structure is received


		// Class Information :
    	//
    	//  Purpose :
    	//
    	//
    	//
   	    //  Description :
   	    //
  	    //      This object is used as a base object in inheritance. Therefore it must have a few methods
  	    //      virtual. When an object has a virtual method, the C++ automatically creates a table with
  	    //      all the pointers to the virtual methods, where the pointer to the table is stored in the
  	    //      beginning of the object. The problem arises when a new method needs to be created with the
  	    //      same signature as one in the base object, and the use of pointers. Take a look at next example :
  	    //
  	    //          class Base
  	    //          {
        //              void Display() { cout << "Lord" << endl; }
  	    //          };
  	    //
  	    //          class Derived : public Base
  	    //          {
  	    //              void Display(); { cout << "Help Me" << endl; }    -> Derived inherits Display from Base but needs another behavior
  	    //          };
  	    //
  	    //      Now if a call is made :
  	    //
  	    //          Base* base = new Base;
  	    //          Derived* derived = new Derived;
  	    //
  	    //          base->Display( 5 );   -> Outputs "Lord"
  	    //          derived->Display();   -> Outputs "Help Me"
  	    //
  	    //      So far so good, a normal method is called by the static type of the pointer. This means no matter what the object the pointer
  	    //      is pointing to it will call the method of the type he was declared as. This is a problematic behavior in inheritance, we need
  	    //      to point to derived objects with base pointers and that the correct method will be called. But now :
  	    //
  	    //          void Do( Base* base ) { base->Display(); }
  	    //
  	    //          Base* base = new Base;
  	    //          Derived* derived = new Derived;
  	    //
  	    //          Do( base );        -> Outputs "Lord"
  	    //          Do( derived );     -> Outputs "Lord"
  	    //
  	    //      This is what virtual allow in C++, instead of calling the method by the static type in compilation, the call to the method is
  	    //      picked dynamically by the actual type of the object. This is done by the pointer in the beginning of the object that points to
  	    //      the virtual table of the type. Of course it can be overloaded to the derived, but then if there is a deep inheritance a method
  	    //      will be needed to be overloaded for each one
  	    //
    	//  Possible errors :
    	//
    	//
    	//
    	class BaseFileDriver
        {
        public:


            // The following methods are the basic methods for each object. How to create, destroy, copy
            // and move the object. This methods if not declared the compiler generates a basic behavior
            // for them :


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
    		inline BaseFileDriver() throw();


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
	    	//          1. fileAbsolutePath - the absoulte path to the file
	    	//			2. requiredOperation - the type of operation, it can be to read from file or write to the file
	    	//			3. permissions - the file will be opened with the given permissions, it can be read, write and execute
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
    		explicit BaseFileDriver( const Encoding::UnicodeString& fileAbsolutePath, SignedInteger32bits requiredOperation, SignedInteger32bits permissions ) throw( Exception );


			// Method Information :
    		//
    		//  Description :
    		//
    		//   	Copy constructor, will operate correctly even if the other object is in default state
    		//
    		//  Required arguments :
    		//
    	    //   	User information needed :
    		//
    		//          other - a reference to the object that should be copied
    		//
    		//		Information returned to the user :
    		//
    		//          NONE
    		//
    		//  Return value :
    		//
    		//   	A reference to the new copy is returned
    		//
    		//  Possible errors :
    		//
    		//		They will come
    		//
    		BaseFileDriver( const BaseFileDriver& other ) throw( Exception );


    		// Method Information :
    		//
    		//  Description :
    		//
    		//   	Assignment operator, can handle with self assignment. Will operate correctly even if the other object is in default state
    		//
    		//  Required arguments :
    		//
    		//		User information needed :
    		//
    		//			other - a reference to the object that should be copied
    		//
    		//		Information returned to the user :
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
    		BaseFileDriver& operator=( const BaseFileDriver& other ) throw( Exception );


    		// Method Information :
    		//
    		//  Description :
    		//
    		//   	Move constructor, takes the resources from the other object ( rvalue reference ), and set it to
    		//		the default state. Will operate correctly even if the other object is in default state
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
    		//		They will come
    		//
    		BaseFileDriver( BaseFileDriver&& other ) throw( Exception );


    		// Method Information :
    		//
    		//  Description :
    		//
    		//   	Move Assignment operator, can handle with self assignment. takes the resources from the
    		//    	other object ( rvalue reference ), and set it to the default state. will operate correctly
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
    		//		They will come
    		//
    		HeaderFileNameFirstLetterUpperCase& operator=( BaseFileDriver&& other ) throw( Exception );


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
    		virtual inline ~BaseFileDriver() throw();


    		// To support Move semantics, the following 3 methods are added to every object. One method to set
    		// the object into the default state, another to check if the object is in the default state,
    		// and the last method to delete all the object resources and set the object to default state :


    		// Method Information :
    		//
    		//  Description :
    		//
        	//      Use to set the object into his default state. This method does not delete the resources inside, it
    		//      only set the data members inside the object to the default value. Note - if this method is used
    		//      and there are still resources used, all those resources will not be accessable anymore, and therefore
    		//      can not be deleted
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
    		virtual void SetToDefaultState() throw();


    		// Method Information :
    		//
    		//  Description :
    		//
    		//   	Use to check if the object is in default state
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
    		virtual bool DefaultState() const  throw();


    		// Method Information :
    		//
    		//  Description :
    		//
    		//      Use to delete the object resources and set the object to default state. Note - if the object is in default
    		//		state the method do nothing
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
    		virtual void DeleteResourcesAndSetToDefaultState()  throw();


    		// The following methods are the interface of the object. This methods implement the capabilities of the object :


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use to change the file the object is working on
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	    	//          1. fileAbsolutePath - the absoulte path to the file
	    	//			2. requiredOperation - the type of operation, it can be to read from file or write to the file
	    	//			3. permissions - the file will be opened with the given permissions, it can be read, write and execute
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
	        //      1. The file does not exist
	        //      2.
	        //
	        void SetNewFile( const Encoding::UnicodeString& fileAbsolutePath ) throw( std::bad_alloc, Exception, ErrnoException );


            // Method Information :
            //
            //  Description :
            //
            //      Use to get the file size in bytes
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
            //      The number of bytes the file is stored on
            //
            //  Possible errors :
            //
            //      1. The object is in default state - class Exception is thrown
            //      2.
            //
            inline UnsignedInteger64bits GetFileSize() throw( Exception );
    

            // Method Information :
            //
            //  Description :
            //
            //      Use this to get current offset for read/write operations in the file
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
            //      The offset in bytes for read/write operations in the file
            //
            //  Possible errors :
            //
            //      1. The lseek system call failed - class ErrnoException is thrown
            //      2. The given file descriptor is invalid
            //      3. 
            //
            inline UnsignedInteger32bits GetOffset() throw( ErrnoException );


            // Method Information :
            //
            //  Description :
            //
            //      Use this to set the offset for read/write operations in the file
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          newOffset - the new offset for the read/write operation in the file
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
            //      1. The lseek system call failed - class ErrnoException is thrown
            //      2. The given file descriptor is invalid
            //      3. 
            //
            inline void SetOffset( UnsignedInteger32bits newOffset ) throw( ErrnoException );


            // Method Information :
            //
            //  Description :
            //
            //      Use to move a given file description offset for read/write operations, from it's current position,
            //      the required amount. To advance use positive integers, and to move backward use negative   
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          amountToMove - the amount to move the read/write operations offset from it's current position
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
            //      1. The lseek system call failed - class ErrnoException is thrown
            //      2. The given file descriptor is invalid
            //      3. 
            //
            inline void MoveOffsetFromCurrentPosition( UnsignedInteger32bits amountToMove ) throw( ErrnoException );


    		// The following methods declare the overloaded operators for the object :


    		// Method Information :
    		//
    		//  Description :
    		//
    		//      Use this operator to check if the this object matches the other object. Important note - if both objects
    		//      are in default state, then the objects still match and false will be returned
    		//
    		//  Required arguments :
    		//
    		//      User information needed :
    		//
    		//          other - a reference to the object that should be compared with this object
    		//
    		//      Information returned to the user :
    		//
    		//          NONE
    		//
    		//  Return value :
    		//
    		//      1. true - if the 2 objects are the same
    		//      2. false - otherwise
    		//
    		//  Possible errors :
    		//
    		//      1. Both of the objects are in default state - class Exception is thrown
    		//      2. The template type object does not have the comparison operator ( == )
    		//      3. 
    		//
    		virtual bool operator==( const BaseFileDriver& other ) const throw( Exception );


    		// Method Information :
    		//
    		//  Description :
    		//
    		//      Use this operator to check if the this object does not match the other object. Important note - if both objects
    		//      are in default state, then the objects still match and false will be returned
    		//
    		//  Required arguments :
    		//
    		//      User information needed :
    		//
    		//          other - a reference to the object that should be compared with this object
    		//
    		//      Information returned to the user :
    		//
    		//          NONE
    		//
    		//  Return value :
    		//
    		//      1. true - if the 2 objects are not the same
    		//      2. false - otherwise
    		//
    		//  Possible errors :
    		//
    		//      1. Both of the objects are in default state - class Exception is thrown
    		//      2. The template type object does not have the comparison operator ( != )
    		//      3. 
    		//
    		virtual bool operator!=( const BaseFileDriver& other ) const throw( Exception );


    		// The following functions are declared static. Static functions do not belong to any of
    		// the instances, but rather to the class. Satic functions only have access to static
    		// data members, which means all other data members can not be used. The only purpose
    		// then of declaring a static function is when a private static data member needs to be
    		// manipulated, or some functionality needed that does not involve the non static data members


    		// All the following methods will be added only in test mode, they are not part of the implementation, their purpose is to
    		// help locate problems in the code


    		DEBUG_TOOL(


    			// This part of the class is dedicated for testing :


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
    			//      1. A method does not work correctly - class Exception is thrown
    			//		2. There is no more free memory space - class std::bad_alloc is thrown
    			//		3. 
    			//
    			static void Test() throw( std::bad_alloc, Exception );


    		)  //  End of debug tool


    	protected:


            // This object will store the path and the file name
            Encoding::UnicodeString m_fileAbsolutePath;

            // This object will store the file descriptor of the opened file
            SignedInteger32bits m_fileDescriptor;

            // This object will store the size of the file
            UnsignedInteger64bits m_fileSize;


    	private:


        	// Static data members do not belong to any instnace, it belongs to the class. Like every global variable
    		// it is created with the start of the program and only destroyed when the program ends. This means that
    		// each member method can use the static data members, but not functions outside the object's scope. It
    		// restricts the access to this object use only, but rather then that acts as global variable


    		// The following methods are private. This means that only public or protected methods can use them, in other
    		// words they not part of the interface, but rather help implement it :


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use to open a file with the required access mode ( read, write or both ), and permissions
	        //      in case a file needs to be created    
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          1. requiredOperation - sets the reason for opening the file - to read, to write or both
	        //          2. permissions - the file can be opened for this operations - read, write, execute or a combination of them
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //      The file descriptor of the opened file
	        //
	        //  Possible errors :
	        //
	        //      1. The open system call failed - class ErrnoException is thrown
	        //      2. The given pointer is NULL - class Exception is thrown
	        //      3. 
	        //
	        inline SignedInteger32bits OpenFileIMP( SignedInteger32bits requiredOperation, SignedInteger32bits permissions ) throw( Exception, ErrnoException );


	        // Function Information :
	        //
	        //  Description :
	        //
	        //      Use this method to get the file size in bytes
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
	        //      The size of the file in bytes
	        //
	        //  Possible errors :
	        //
	        //      1. The lseek system call failed - class ErrnoException is thrown
	        //      2. The file descriptor is invalid - class ErrnoException is thrown
	        //      3. 
	        //
	        inline UnsignedInteger64bits SetFileSizeInBytesIMP() throw( ErrnoException );


            // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this to close the file description in the kernel represented by the given file descriptor 
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
	        //      1. The close system call failed
	        //      2. 
	        //
	        inline void CloseFileIMP() throw();


    		// Friend class or friend function can access private and protected members of other class in which it is declared as friend.
    		// It is sometimes useful to allow a particular class to access private members of other class. The declration of such function
    		// is private, because these functions are part of the implemntation, which the user should not be aware of. Furthermore the
    		// use of this functions is not limited to the class's scope. The following declarations are for all the function that should
    		// be friends with this class :




    	};  //  Class BaseFileDriver































//	****************************************************************   END PART OF DECLRATIONS, IMPLMENTATION TIME   ************************************************************































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
    	inline BaseFileDriver::BaseFileDriver() throw() :
        m_fileAbsolutePath(),
        m_fileDescriptor( -1 ),
        m_fileSize( 0 )
        {}


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
    	//          1. fileAbsolutePath - the absoulte path to the file
    	//			2. requiredOperation - the type of operation, it can be to read from file or write to the file
    	//			3. permissions - the file will be opened with the given permissions, it can be read, write and execute
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
    	//		1. The open system call failed
    	//		2. The lseek system call failed
    	//		3. 
    	//
    	BaseFileDriver::BaseFileDriver( const Encoding::UnicodeString& fileAbsolutePath, SignedInteger32bits requiredOperation, SignedInteger32bits permissions ) throw( Exception ) :
        m_fileAbsolutePath( fileAbsolutePath ),
        m_fileDescriptor( OpenFileIMP( requiredOperation, permissions ) ),
        m_fileSize( SetFileSizeInBytesIMP() )
        {}


    	// Method Information :
    	//
    	//  Description :
    	//
    	//   	Copy constructor, will operate correctly even if the other object is in default state
    	//
    	//  Required arguments :
    	//
    	//   	User information needed :
    	//
    	//          other - a reference to the object that should be copied
    	//
    	//		Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//   	A reference to the new copy is returned
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	BaseFileDriver::BaseFileDriver( const BaseFileDriver& other ) throw( Exception ) :
        m_fileAbsolutePath( other.m_fileAbsolutePath ),
        m_fileDescriptor( OpenFileIMP() ),
        m_fileSize( other.m_fileSize )
        {}


    	// Method Information :
    	//
    	//  Description :
    	//
    	//   	Move constructor, takes the resources from the other object ( rvalue reference ), and set it to
    	//		the default state. Will operate correctly even if the other object is in default state
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
    	//		They will come
    	//
    	BaseFileDriver::BaseFileDriver( BaseFileDriver&& other ) throw( Exception ) :
        m_fileAbsolutePath( other.m_fileAbsolutePath ),
        m_fileDescriptor( other.m_fileDescriptor ),
        m_fileSize( other.m_fileSize )
    	{
    		// Set the other object to default state, this way it can't be used
    		other.SetToDefaultState();
    	}


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
    	inline BaseFileDriver::~BaseFileDriver() throw()
        {
            // Close the file
            CloseFileIMP();
        }


        // Method Information :
    	//
    	//  Description :
    	//
        //      Use to set the object into his default state. This method does not delete the resources inside, it
    	//      only set the data members inside the object to the default value. Note - if this method is used
    	//      and there are still resources used, all those resources will not be accessable anymore, and therefore
    	//      can not be deleted
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
    	void BaseFileDriver::SetToDefaultState() throw()
        {
            // Set the UTF-8 string string the file name and path to default state
            m_fileAbsolutePath.SetToDefaultState();

            // Set the file descriptor member to -1
            m_readFileDescriptor = -1;

            // Set the size of the file to 0
            m_fileSize = 0;
        }


    	// Method Information :
    	//
    	//  Description :
    	//
    	//   	Use to check if the object is in default state
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
    	bool BaseFileDriver::DefaultState() throw() const
    	{

            // Check if the object is in default state
            if ( ( m_fileAbsolutePath.DefaultState() == true ) &&
                 ( m_fileDescriptor == -1 ) &&
                 ( m_fileSize == 0 ) )
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
    	//      Use to delete the object resources and set the object to default state. Note - if the object is in default
    	//		state the method do nothing
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
    	void BaseFileDriver::DeleteResourcesAndSetToDefaultState() throw()
    	{
    		// Check if the object is in default state, then noting needs to be done
    		RETURN_IF_EXPRESSION_IS_TRUE( DefaultState() )

    		// Release the resources of this object

            // Delete the resources of the UTF-8 string
            m_fileAbsolutePath.DeleteResourcesAndSetToDefaultState();

            // Set the object file descriptor to -1
            m_readFileDescriptor = -1;

            // Set the size of the file to 0
            m_fileSize = 0;
    	}


        // Method Information :
        //
        //  Description :
        //
        //      Use to get the file size in bytes
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
        //      The number of bytes the file is stored on
        //
        //  Possible errors :
        //
        //      1. The object is in default state - class Exception is thrown
        //      2.
        //
        inline UnsignedInteger64bits BaseFileDriver::GetFileSize() throw( Exception )
        {
            // Return the size of the file
            return ( m_fileSize );
        }




























//  ***************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ************************************************






























    	// Method Information :
    	//
    	//  Description :
    	//
    	//      Use this operator to check if the this object matches the other object. Important note - if both objects
    	//      are in default state, then the objects still match and false will be returned
    	//
    	//  Required arguments :
    	//
    	//      User information needed :
    	//
    	//          other - a reference to the object that should be compared with this object
    	//
    	//      Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//      1. true - if the 2 objects are the same
    	//      2. false - otherwise
    	//
    	//  Possible errors :
    	//
    	//      1. Both of the objects are in default state - class Exception is thrown
    	//      2. The template type object does not have the comparison operator ( == )
    	//      3. 
    	//
    	bool BaseFileDriver::operator==( const BaseFileDriver& other ) const throw( Exception )
    	{

            // Check if both instnaces point to the the same file and has the same file size, the file descriptor
            // is not checked because there are no 2 instances with the same file descriptor on purpose
            if ( ( m_fileAbsolutePath == other.m_fileAbsolutePath ) && ( m_fileSize == other.m_fileSize ) )
            {
                // The 2 instances match
                return ( true );
            }

            // The 2 instances do not match
            return ( false );
    	}


    	// Method Information :
    	//
    	//  Description :
    	//
    	//      Use this operator to check if the this object does not match the other object. Important note - if both objects
    	//      are in default state, then the objects still match and false will be returned
    	//
    	//  Required arguments :
    	//
    	//      User information needed :
    	//
    	//          other - a reference to the object that should be compared with this object
    	//
    	//      Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//      1. true - if the 2 objects are not the same
    	//      2. false - otherwise
    	//
    	//  Possible errors :
    	//
    	//      1. Both of the objects are in default state - class Exception is thrown
    	//      2. The template type object does not have the comparison operator ( != )
    	//      3. 
    	//
    	bool BaseFileDriver::operator!=( const BaseFileDriver& other ) const throw( Exception )
        {
            // Return the negotatied result of the match operator
            return ( !( *this == other ) );
        }

























//  ****************************************************   TEMPLATE OR INLINE STATIC FUNCTIONS IMPLEMENTATION   ***********************************************

























//	*****************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************


























        // Method Information :
        //
        //  Description :
        //
        //      Use to open a file with the required access mode ( read, write or both ), and permissions
        //      in case a file needs to be created    
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. requiredOperation - sets the reason for opening the file - to read, to write or both
        //          2. permissions - the file can be opened for this operations - read, write, execute or a combination of them
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      The file descriptor of the opened file
        //
        //  Possible errors :
        //
        //      1. The open system call failed - class ErrnoException is thrown
        //      2. The given pointer is NULL - class Exception is thrown
        //      3. 
        //
        inline SignedInteger32bits BaseFileDriver::OpenFileIMP( SignedInteger32bits requiredOperation, SignedInteger32bits permissions ) throw( Exception, ErrnoException )
        {
            // Create an object to store the file descriptor
            SignedInteger32bits fileDescriptor = 0;

            // Try to Open the file with the required access and permissions. If open failed, and it was not due to 
            // signal interrupt, throw an Exception describing the error
            while ( -1 == ( fileDescriptor = open( reinterpret_cast< char* >( m_fileAbsolutePath.GetUnicodeStringEncodedAsUTF8() ), requiredOperation, permissions ) ) )
            {
                // Check the reason for the failure, and if it not a signal interrupt throw an exception
                ErrorHandling::Assert< ErrnoException >::True( errno == EINTR, "BaseFileDriver::OpenFileIMP" );
            }

            // Return the new file descriptor of the file
            return ( fileDescriptor );
        }


        // Function Information :
        //
        //  Description :
        //
        //      Use this method to get the file size in bytes
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
        //      The size of the file in bytes
        //
        //  Possible errors :
        //
        //      1. The lseek system call failed - class ErrnoException is thrown
        //      2. The file descriptor is invalid - class ErrnoException is thrown
        //      3. 
        //
        inline UnsignedInteger64bits BaseFileDriver::SetFileSizeInBytesIMP() throw( ErrnoException )
        {
            // Create an object to store the number of bytes of the file. For this the lseek system call is used. This system call return the 
            // offset of the read/write operations on the file. All there is to do is to set the lseek to the end of the file, and it will 
            // return the offset to that point
            UnsignedInteger64bits numberOfBytesOfFile = lseek( m_fileDescriptor, 0, SEEK_END );

            // Try to get the number of bytes of the file using the lseek system call. 
            ErrorHandling::Assert< ErrnoException >::True( ( numberOfBytesOfFile == -1 ), "BaseFileDriver::SetFileSizeInBytesIMP" );        

            // Return the number of bytes used by the file
            return ( numberOfBytesOfFile );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this to close the file description in the kernel represented by the given file descriptor 
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
        //      1. The close system call failed
        //      2. 
        //
        inline void CommunicateWithDisk::CloseFileIMP() throw()
        {

            // Try to close the read file description
            while ( -1 == close( m_fileDescriptor ) )
            {
                // Check the reason for the failure, and if it is not signal interrupt, break the loop
                BREAK_LOOP_IF_ERNNO_IS_NOT_SET_TO_EINTR();
            }


        }


























// *********************************************************   INLINE OR TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   *******************************************












    	// This functions are declared outside the class scope, to enable the class to be the right side operand. This can not be for a method
    	// within the class. When a method or operator of a class is used, the object the operator or method belongs to must be known, in order
    	// to set the implicit this pointer to the method. Therefore the class must be presented first which means to be the left side operand,
    	// this functions are needed to avoid just that








    }  //  Namespace FileSystem

}  //  Namespace Universe



#endif  // BASEFILEDRIVER_HPP