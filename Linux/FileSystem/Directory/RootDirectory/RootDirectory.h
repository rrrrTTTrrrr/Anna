#ifndef  ROOTDIRECTORY_H
#define  ROOTDIRECTORY_H



// When a function name ends with the suffix IMP, the function is not part
// of the object interface ( capabilities ), it only used as aid to the
// function that it is, implementing only spsecific part

 

namespace Universe
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
    // with byte order in memory


    // To support move semantics every class must provide a default state. This state
    // will be used to notify that resources were taken from current instance by
    // a move operation :
    //
    //
   	// When the object is in this state it should not be used ( the object is empty )


    // Constructor of derived object, when called, all the base class constructors are executed
    // first, according to the order they appear in the class declaration, and only then the
    // user code is executed

    // Destructor of derived object, when it is called, the user code existing in the destructor
    // itself is executed first and then all the destructors of the base objects, in an opposite
    // way from which they were constructed


	// Class Information :
    //
    //  Purpose :
    //
    //      This class is used to work on the required directory and all of the subdirectories in it
    //
    //  Description :
    //
    //
    //
    //  Possible errors :
    //
    //
    //
    class RootDirectory 
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
    	explicit inline RootDirectory() throw();


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
    	explicit inline RootDirectory( const AsciiString& rootDirectory ) throw( std::bad_alloc, Exception );


        // Method Information :
        //
        //  Description :
        //
        //      Constructor, for raw ascii strings
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rootDirectory - the path including the name of the directory itself of the root directory
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
        explicit inline RootDirectory( const char* rootDirectory ) throw( std::bad_alloc, Exception );


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
    	explicit inline RootDirectory( const RootDirectory& other ) throw( std::bad_alloc, Exception );


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
    	RootDirectory& operator=( const RootDirectory& other ) throw( std::bad_alloc, Exception );


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
    	explicit RootDirectory( RootDirectory&& other ) throw();


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
    	RootDirectory& operator=( RootDirectory&& other ) throw();


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
    	~RootDirectory() throw();


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
    	bool DefaultState() const throw();


        // Method Information :
        //
        //  Description :
        //
        //      Use to delete the object resources
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
        void DeleteResources() throw();


        // The following methods are the interface of the object. This methods implement the
        // capabilities of the object :


        // Method Information :
        //
        //  Description :
        //
        //      Use to get the path to the file, if it exist in the root directory or any of it's subdirectories
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          fileName - a reference to an ascii string object containning the file name          
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
        //      Note - the responsibility for deleting the memoery space is on the user
        //
        //  Possible errors :
        //
        //      1. There is no more free memory space - class std::bad_alloc is thrown
        //      2.
        //
        inline AsciiString* GetPathToFileOrDirectoryIfExist( const AsciiString& fileName ) throw( std::bad_alloc, Exception, ErrnoException );


        // Method Information :
        //
        //  Description :
        //
        //      Use to remove the file, if it exist in the root directory or any of it's subdirectories. Note - the 
        //      file name must not represent a directory
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          fileName - a reference to an ascii string object containning the file name          
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
        //      They will come
        //
        inline bool RemoveFileIfExist( const AsciiString& fileName ) throw( std::bad_alloc, Exception, ErrnoException );


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
        inline bool RemoveEmptyDirectoryIfExist( const AsciiString& directoryName ) throw( std::bad_alloc, Exception, ErrnoException );


	private: 


        // This object will be used to store the root directory
        AsciiString m_rootDirectory;


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
        AsciiString* RecursivePassOnSubdirectoriesToFindFileIMP( const AsciiString& directory, const AsciiString& fileName ) throw( std::bad_alloc, Exception, ErrnoException );


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
        bool RecursivePassOnSubdirectoriesToRemoveFileIMP( const AsciiString& directory, const AsciiString& fileName ) throw( std::bad_alloc, Exception, ErrnoException );


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
        void RootDirectory::RecursivePassToRemoveSubdirectoriesIMP( const AsciiString& directoryToRemove ) throw( std::bad_alloc, Exception, ErrnoException );


	};  //  Class RootDirectory












//	**************************************   END PART OF DECLRATIONS, IMPLMENTATION TIME   ************************************












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
    inline RootDirectory::RootDirectory() throw() :
    m_rootDirectory()
    {}


    // Method Information :
    //
    //  Description :
    //
    //      Constructor, 
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          rootDirectory - the path including the name of the directory itself of the root directory
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
    inline RootDirectory::RootDirectory( const AsciiString& rootDirectory ) throw( std::bad_alloc, Exception ) :
    m_rootDirectory( rootDirectory )
    {}


    // Method Information :
    //
    //  Description :
    //
    //      Constructor, for raw ascii strings
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          rootDirectory - the path including the name of the directory itself of the root directory
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
    inline RootDirectory::RootDirectory( const char* rootDirectory ) throw( std::bad_alloc, Exception ) :
    m_rootDirectory( rootDirectory )
    {}


	// Method Information :
    //
    //  Description :
    //
    //   	Copy constructor,
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
    //        They will come
    //
    inline RootDirectory::RootDirectory( const RootDirectory& other ) throw( std::bad_alloc, Exception ) :
    m_rootDirectory( other.m_rootDirectory )
    {}


    // Method Information :
    //
    //  Description :
    //
    //      Move constructor, take the resources from the other object ( rvalue reference ), and set it to
    //      the default state. Will operate correctly even if the other object is in default state
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
    inline RootDirectory::RootDirectory( RootDirectory&& other ) throw() :
    m_rootDirectory( other.m_rootDirectory )
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
    inline RootDirectory::~RootDirectory() throw()
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
    inline void RootDirectory::SetToDefaultState() throw()
    {
        // Set the ascii string object containning the root directory to default state
        m_rootDirectory.SetToDefaultState();
    }


    // Method Information :
    //
    //  Description :
    //
    //		Use to check if the object is in default state
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
    inline bool RootDirectory::DefaultState() const throw()
    {

        // Check if the object is in default state
        if ( true == m_rootDirectory.DefaultState() )
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
    //      Use to delete the object resources
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
    void RootDirectory::DeleteResources() throw()
    {
        // Release the resources of this object

        // Delete the ascii string of the root directory
        m_rootDirectory.DeleteResources();
    }


    // Method Information :
    //
    //  Description :
    //
    //      Use to get the path to the file or directory, if it exist in the root directory or any of it's subdirectories
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          fileOrDirectoryName - a reference to an ascii string object containning the file name          
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
    //      Note - the responsibility for deleting the memoery space is on the user
    //
    //  Possible errors :
    //
    //      They will come
    //
    inline AsciiString* RootDirectory::GetPathToFileOrDirectoryIfExist( const AsciiString& fileOrDirectoryName ) throw( std::bad_alloc, Exception, ErrnoException )
    {
        // Check that this object is not in default state
        ThrowExceptionIfExpressionIsTrue( DefaultState(), "RootDirectory::GetPathToFileOrDirectoryIfExist failed - the object is in default state" );

        // Use a recursive method to pass on all the subdirectories, and search for the file
        return ( RecursivePassOnSubdirectoriesToFindFileIMP( m_rootDirectory, fileOrDirectoryName ) );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Use to remove the file, if it exist in the root directory or any of it's subdirectories. Note - the 
    //      file name must not represent a directory
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          fileName - a reference to an ascii string object containning the file name          
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
    //      They will come
    //
    inline bool RootDirectory::RemoveFileIfExist( const AsciiString& fileName ) throw( std::bad_alloc, Exception, ErrnoException )
    {
        // Check that this object is not in default state
        ThrowExceptionIfExpressionIsTrue( DefaultState(), "RootDirectory::RemoveFileIfExist failed - the object is in default state" );

        // Use a recursive method to pass on all the subdirectories, and search for the file, and if it exist delete it
        return ( RecursivePassOnSubdirectoriesToRemoveFileIMP( m_rootDirectory, fileName ) );    
    }
















//	*****************************************   PRIVATE METHODS IMPLEMENTATION   ******************************************  























// ******************************************   NESTED CLASS IMPLEMENTATION -    **************************************** 














}  //   Namespace Universe

#endif  // ROOTDIRECTORY_H























