#ifndef  __SHAREDMEMORY_H__
#define  __SHAREDMEMORY_H__


#include <sys/shm.h>  //  Function shmget, Function shmat, Function shmdt, Function shmctl
#include <errno.h>  //  Macro errno


#include "../ErrorHandling/Exception.h"  //  Class Exception
#include "../Array/ArrayOperations.h"  //  Function SetAllEntriesOfArrayToValue
#include "../BasicUtilities/cpp_BasicUtilities.h"  //  Function ThrowExceptionWithErrnoIfOperationFailed, Function ThrowExceptionWithErrnoIfExpressionIsTrue
#include "../../Containers/AsciiString.h"  //  Class AsciiString



// When a function name ends with the suffix IMP, the function is not part
// of the object interface ( capabilities ), it only used as aid to the
// function that it is, implementing only spsecific part



namespace Universe 
{ 


	// Shared Memory is an efficeint means of passing data between programs. One program will create a memory portion 
	// which other processes ( if permitted ) can access.  A process creates a shared memory segment using shmget system call.
	// The original owner of a shared memory segment can assign ownership to another user with shmctl system call. Other 
	// processes with proper permission can perform various control functions on the shared memory segment using shmctl. 
	// Once created, a shared segment can be attached to a process address space using shmat system call. It can be detached
	// using shmdt system call. The attaching process must have the appropriate permissions. Once attached, the process can 
	// read or write to the segment, as allowed by the permission requested in the attach operation. A shared segment can be
	// attached multiple times by the same process. A shared memory segment is described by a control structure with a unique 
	// ID that points to an area of physical memory. The identifier of the segment is called the shmid. The structure definition 
	// for the shared memory segment control structures and prototypews can be found in <sys/shm.h>


	// System call - shmget - returns the identifier of the System V shared memory segment associated with the value of the 
	// argument key, syntax :
	//
	// 		int shmget( key_t key, size_t size, int shmflg );
	//
	// 		Arguments purpose :
	// 		1. key - is generated with the function ftok, The ftok function will return the same key every time the same parameters are used, syntax :
	//
	//          	key_t ftok( const char* pathname, int proj_id )
	//
	// 				Arguments purpose :
	// 				1. pathname - is an existing file path
	// 				2. ptoj_id - is some integer
	//
	//		2. size - the required size of the shared memory in bytes, the actual size will be rounded up to the system page size
	//	    3. semflg - the first 9 bits are used to set the permissions ( write permissions in this case
	//      only mean that the semaphore can be changed ) :
    // 			00600 - user ( file owner ) has read and write permission
	// 			00400 - user has read permission
	// 			00200 - user has write permission
	// 			00060 - group has read and write permission
	// 			00040 - group has read permission
	// 			00020 - group has write permission
	// 			00006 - others have read and write permission
	// 			00004 - others have read permission
	// 			00002 - others have write permission
	//		the rest of the flag is compose of :
	//			IPC_CREAT - create a new segment. If this flag is not used, then shmget will find the segment associated with key 
	//			and check to see if the user has permission to access the segment
	// 			IPC_EXCL - this flag is used with IPC_CREAT to ensure that this call creates the segment. If the segment already 
	//			exists, the call fails


	// System call - shmctl - performs the control operation specified by cmd on the System V shared memory segment whose 
	// identifier is given in shmid, syntax :
	//
	//		int shmctl( int shmid, int cmd, struct shmid_ds *buf );
	//
	// 		Arguments purpose :
	//		1. shmid - shared memory identifer
	// 		2. cmd - is the required operation on the shared memory, the list of possible commands :
	// 			  IPC_INFO - return information about system-wide shared memory limits and parameters in the structure pointed to by buf,
	//            this structure is of type shminfo ( thus, a cast is required ). Structure shminfo syntax :
	// 
	//		        	 struct shminfo 
	//					 {
    //                     	unsigned long shmmax;  //  Maximum segment size 
    //                     	unsigned long shmmin;  //  Minimum segment size is always 1 
    //                     	unsigned long shmmni;  //  Maximum number of segments 
    //                     	unsigned long shmseg;  //  Maximum number of segments that a process can attach; 
    //                     	unsigned long shmall;  //  Maximum number of pages of shared memory, system-wide 
    //                  };
    //
    //		3. buf - a pointer to a shmid_ds structure, defined in <sys/shm.h>, syntax :
    //		
	//	           		struct shmid_ds 
	//	           		{
	//	               		struct ipc_perm shm_perm;    //  Ownership and permissions 
	//	               		size_t          shm_segsz;   //  Size of segment ( bytes ) 
	//	               		time_t          shm_atime;   //  Last attach time 
	//	               		time_t          shm_dtime;   //  Last detach time
	//	               		time_t          shm_ctime;   //  Last change time 
	//	               		pid_t           shm_cpid;    //  PID of creator 
	//	               		pid_t           shm_lpid;    //  PID of last shmat/shmdt 
	//	               		shmatt_t        shm_nattch;  //  No. of current attaches 
	//	               		...
	//	           	    };



	// System call - shmat - attaches  the System V shared memory segment identified by shmid to the address space of the 
	// calling process, syntax :
	//
	//		void* shmat( int shmid, const void* shmaddr, int shmflg )
	//
	//		Arguments purpose :
	//		1. shmid - shared memory identifer
	//		2. shmaddr - The attaching address is specified by shmaddr with one of the following criteria :
	//		    1. If shmaddr is NULL, the system chooses a suitable ( unused ) address at which to attach the segment
	//			2. If shmaddr isn't NULL and SHM_RND is specified in shmflg, the attach occurs at the address equal to 
	//			shmaddr rounded down to the nearest multiple of SHMLBA
	// 			3. Otherwise, shmaddr must be a page-aligned address at which the attach occurs
	//		3. shmflg - can be one of the following :
	//			1. SHM_RND - use to make sure the given address is aligned with SHMLBA
	//			2. SHM_EXEC - allow the contents of the segment to be executed, The caller must have execute permission on the segment
	//			3. SHM_RDONLY - attach the segment for read-only access. The process must have read permission for the segment.  If 
	//			this flag is not specified, the segment is attached for read and write access, and the process must have read and write
	//		    permission for the segment. There is no notion of a write-only shared memory segment
	//	
	// SHMLBA - Segment low boundary address multiple. When explicitly specifying an attach address in a call to shmat, the caller should 
	// ensure that the address is a multiple of this value. This is necessary on some architectures, in order either to ensure good CPU 
	// cache performance or to ensure that different attaches of the same segment have consistent views within the CPU cache. SHMLBA is 
	// normally some multiple of the system page size ( on many Linux architectures, it is the same as the system page size )


	// System call - shmdt - detaches the shared memory segment located at the address specified by shmaddr from the address space of 
	// the calling process,The to-be-detached segment must be currently attached with shmaddr equal to the value returned by the 
	// attaching shmat call, syntax :
	//
	//		int shmdt( const void* shmaddr )


	// Overloaded functions are determind according the signature of the function, meaning the function name, the
	// arguments to that function and cv qualifiers affect, becuase the this argument is also part of the signature. When the function
	// is choosen first of all a perfect matching function is searched once, this wasn't found the function with the less
	// implicit conversions is choosen


	// This class purpose is to create a memory segment that different proccess can attach to, and pass information easily.
	// In the constructor a shared memory segment is created or attached to, and from there the work with the class is
	// identical to working with pointers. On important note is on the deletion of the shared memory, when the current 
	// instance creating the shared memory, there is of course no problem if the user when to delete it after the use,
	// in case another process created that shared memory segment, the user should be certain when setting that location
	// for deletion, becuase there might processes counting on the information inside
	template< typename T >
	class SharedMemory 
	{ 
	public: 

		// Constructor, a file name and positive integer are required to create the key for the
		// semaphore set, to attach to the same set of semaphores use the same file and integer,
		// furthermore the size, in bytes, of the shared memory segment and permissions are required,
		// and information on what to do if the shared memory already exist is needed ( fail or attach ),
		// finally the user needs to choose if the shared memory segment should be deleted or not at
		// the end of use, if the shared memory was created all the elements inside will be set to 0 
		explicit inline SharedMemory( const AsciiString& FileNameWithPathForKey, int IntegerForKey, unsigned int numberOfEntriesRequired, bool destoryAtEndOfUse, bool failIfSharedMemoryAlreadyExist = false, int permissions = 00666 ) throw( Exception );

		// Constructor, a key is needed to create the shared memory, furthermore the size, in bytes, of 
		// the shared memory segment and permissions are required, and information on what to do if the 
		// shared memory already exist is needed ( fail or attach ), finally the user needs to choose if
		// the shared memory segment should be deleted or not at the end of use, if the shared memory was 
		// created all the elements inside will be set to 0 
		explicit inline SharedMemory( int sharedMemoryKey, unsigned int numberOfEntriesRequired, bool destoryAtEndOfUse, bool failIfSharedMemoryAlreadyExist = false, int permissions = 00666 ) throw( Exception );

		// Copy constructor, 
		inline SharedMemory( const SharedMemory& other ) throw( Exception );

		// Assignment operator,
		SharedMemory& operator=( const SharedMemory& other ) throw( Exception );

		// Destructor,
		~SharedMemory() throw();

		// Use to get shared memory system information
		inline struct shminfo GetSystemInformationOnSharedMemory() const throw( Exception );

		// Use to get the key that was used to create the shared memory
		inline key_t GetKey() const throw();

		// Use to check if the pointer on the shared memory reached the end, returns true if it does,
		// and false otherwise
		inline bool EndOfSharedMemory() const throw();

		// Read current object form shared memory and return it
		inline T GetCurrentObject() const throw( Exception );

		// Write to current location in shared memory
		inline void SetCurrentObject( T newValueToSet ) throw( Exception );

		// Use to set all entries in the shared memory to the required value
		inline void SetAllEntriesToRequiredValue( T newValueToSet ) throw();

		// Use to get reference to an entry in the shared memory, this function can be used either
		// to get the required object and to change it, if te entry required is behind the end
		// of the shared memory the function will throw an Exception
		inline T& operator[]( unsigned int entryIndex ) throw( Exception );  //  Overloaded function

		// Use to get the object in the required entry, if te entry required is behind the end
		// of the shared memory the function will throw an Exception
		inline T operator[]( unsigned int entryIndex ) const throw( Exception );  //  Overloaded function

		// Use to set the pointer moving on the shared memory to next entry, if the pointer is
		// at the end of the shared memory the function will throw an Exception
		template< typename O >
		friend inline void operator++( SharedMemory< O >& sharedMemoryObject ) throw( Exception );

		// Use to set the pointer moving on the shared memory to previous entry, if the pointer is
		// at the end of the shared memory the function will throw an Exception
		template< typename O >
		friend inline void operator--( SharedMemory< O >& sharedMemoryObject ) throw( Exception );

	private: 

		// This object will store the key used to create the shared memory
		int m_sharedMemoryKey;

		// This object will store the size of the shared memory
		unsigned int m_sharedMemorySize; 

		// This object will store the amount of entries of the template type are in the shared memory
		unsigned int m_sharedMemoryNumberOfEntries;

		// This object will store true if the shared memory segment needs to be deleted at
		// the end of use, and false if it should stay
		bool m_trueForDestroyAndFalseForNot;

		// This object will store true if the current instance created the shared memory, and false if
		// it only attached to it
		bool m_trueForCreateAndFalseForAttached;

		// This object will store the system V shared memory identifer
		int m_sharedMemoryIdentifier;

		// This object will store the beginging address of the shared memory segment
		T* m_sharedMemorySegmentBeginingAddress;

		// This object will be used to move on the shared memory
		T* m_moveOnSharedMemory;

		// Use to create a new key, required a path to an existing file and an integer, if the same
		// arguments are given the same key will be returned
		inline key_t CreateKeyForSharedMemoryIMP( const AsciiString& keyFileNameWithPath, int keyInteger ) throw( Exception );

		// Use to create a new shared memory or attach to an exisitng shared memory, on failure throws an Exception
		int CreateSharedMemoryIMP( key_t sharedMemoryKey, unsigned int numberOfBytesRequired, bool failIfSharedMemoryAlreadyExist, int permissions ) throw( Exception );

		// Use this to attach to an exisiting shared memory, if the attach failed the function
		// will check if current instance created the shared memory and will set it for destruction
		void AttachToExisitngSharedMemoryAndIfFailedDeleteSharedMemoryIfNeededIMP() throw( Exception );

		// Use this to attach to an exisiting shared memory, if the attach failed the function
		// will throw an Exception
		void AttachToExisitngSharedMemoryIMP() throw( Exception );

		// Use to detach from shared memory segment
		inline void DetachFromSharedMemoryIMP() throw( Exception );

		// Use to set the shared memory for deletion after all process detach form it
		inline void DeleteSharedMemoryIMP() throw( Exception );

	};  //  Class SharedMemory


	// Use to set the pointer moving on the shared memory to next entry, if the pointer is
	// at the end of the shared memory the function will throw an Exception
	template< typename O >
	inline void operator++( SharedMemory< O >& sharedMemoryObject ) throw( Exception );

	// Use to set the pointer moving on the shared memory to previous entry, if the pointer is
	// at the end of the shared memory the function will throw an Exception
	template< typename O >
	inline void operator--( SharedMemory< O >& sharedMemoryObject ) throw( Exception );






//	**************************************   END PART OF DECLRATIONS, IMPLMENTAION TIME   ************************************






	// Constructor, a file name and positive integer are required to create the key for the
	// semaphore set, to attach to the same set of semaphores use the same file and integer,
	// furthermore the size, in bytes, of the shared memory segment and permissions are required,
	// and information on what to do if the shared memory already exist is needed ( fail or attach ),
	// finally the user needs to choose if the shared memory segment should be deleted or not at
	// the end of use, if the shared memory was created all the elements inside will be set to 0 
	template< typename T >
	inline SharedMemory< T >::SharedMemory( const AsciiString& FileNameWithPathForKey, int IntegerForKey, unsigned int numberOfEntriesRequired, bool destoryAtEndOfUse, bool failIfSharedMemoryAlreadyExist, int permissions ) throw( Exception ) :
	m_sharedMemoryKey( CreateKeyForSharedMemoryIMP( FileNameWithPathForKey, IntegerForKey ) ),
	m_sharedMemorySize( numberOfEntriesRequired * sizeof( T ) ),
	m_sharedMemoryNumberOfEntries( numberOfEntriesRequired ),
	m_trueForDestroyAndFalseForNot( destoryAtEndOfUse ),
	m_trueForCreateAndFalseForAttached( false ),
	m_sharedMemoryIdentifier( CreateSharedMemoryIMP( m_sharedMemoryKey, numberOfEntriesRequired * sizeof( T ), failIfSharedMemoryAlreadyExist, permissions ) ),
	m_sharedMemorySegmentBeginingAddress( NULL ),
	m_moveOnSharedMemory( NULL )
	{
		// Try to attach to the shared memory segment
		AttachToExisitngSharedMemoryIMP();

		// Check if the shared memory was created then set all entries to 0
		if ( true == m_trueForCreateAndFalseForAttached )
		{
			// The shared memory was created, set all entries to 0
			SetAllEntriesOfArrayToValue< char >( (char*)m_sharedMemorySegmentBeginingAddress, 0, numberOfEntriesRequired );
		}

		// Set m_moveOnSharedMemory to the begining of the shared memory segment
		m_moveOnSharedMemory = m_sharedMemorySegmentBeginingAddress;
	} 

	// Constructor, a key is needed to create the shared memory, furthermore the size, in bytes, of 
	// the shared memory segment and permissions are required, and information on what to do if the 
	// shared memory already exist is needed ( fail or attach ), finally the user needs to choose if
	// the shared memory segment should be deleted or not at the end of use, if the shared memory was 
	// created all the elements inside will be set to 0 
	template< typename T >
	inline SharedMemory< T >::SharedMemory( int sharedMemoryKey, unsigned int numberOfEntriesRequired, bool destoryAtEndOfUse, bool failIfSharedMemoryAlreadyExist, int permissions ) throw( Exception ) :
	m_sharedMemoryKey( sharedMemoryKey ),
	m_sharedMemorySize( numberOfEntriesRequired * sizeof( T ) ),
	m_sharedMemoryNumberOfEntries( numberOfEntriesRequired ),
	m_trueForDestroyAndFalseForNot( destoryAtEndOfUse ),
	m_trueForCreateAndFalseForAttached( false ),
	m_sharedMemoryIdentifier( CreateSharedMemoryIMP( sharedMemoryKey, numberOfEntriesRequired * sizeof( T ), failIfSharedMemoryAlreadyExist, permissions ) ),
	m_sharedMemorySegmentBeginingAddress( NULL ),
	m_moveOnSharedMemory( NULL )
	{
		// Try to attach to the shared memory segment
		AttachToExisitngSharedMemoryIMP();

		// Check if the shared memory was created then set all entries to 0
		if ( true == m_trueForCreateAndFalseForAttached )
		{
			// The shared memory was created, set all entries to 0
			SetAllEntriesOfArrayToValue< char >( (char*)m_sharedMemorySegmentBeginingAddress, 0, numberOfEntriesRequired );
		}

		// Set m_moveOnSharedMemory to the begining of the shared memory segment
		m_moveOnSharedMemory = m_sharedMemorySegmentBeginingAddress;
	}

	// Copy constructor, 
	template< typename T >
	inline SharedMemory< T >::SharedMemory( const SharedMemory& other ) throw( Exception ) :
	m_sharedMemoryKey( other.m_sharedMemoryKey ),
	m_sharedMemorySize( other.m_sharedMemorySize ),
	m_sharedMemoryNumberOfEntries( other.m_sharedMemoryNumberOfEntries ),
	m_trueForDestroyAndFalseForNot( other.m_trueForDestroyAndFalseForNot ),
	m_trueForCreateAndFalseForAttached( other.m_trueForCreateAndFalseForAttached ),
	m_sharedMemoryIdentifier( other.m_sharedMemoryIdentifier ),
	m_sharedMemorySegmentBeginingAddress( other.m_sharedMemorySegmentBeginingAddress ),
	m_moveOnSharedMemory( other.m_moveOnSharedMemory )
	{}  

	// Assignment operator,
	template< typename T >
	SharedMemory< T >& SharedMemory< T >::operator=( const SharedMemory& other ) throw( Exception )
	{

		// Check if this is self assignment
		if ( this != &other )
		{
			// This is not self assignment 

			// Try to detach from current shared memory segment
			DetachFromSharedMemoryIMP();

			// Check if the user required that the shared memory will be deleted
			if ( true == m_trueForDestroyAndFalseForNot )
			{
				// Try to delete the shared memory
				DeleteSharedMemoryIMP();
			}

			// Copy all the required members from other object to current object
			m_sharedMemoryKey = other.m_sharedMemoryKey;
			m_sharedMemorySize = other.m_sharedMemorySize;
			m_sharedMemoryNumberOfEntries = other.m_sharedMemoryNumberOfEntries;
			m_trueForDestroyAndFalseForNot = other.m_trueForDestroyAndFalseForNot;
			m_trueForCreateAndFalseForAttached = other.m_trueForCreateAndFalseForAttached;
			m_sharedMemoryIdentifier = other.m_sharedMemoryIdentifier;
			m_moveOnSharedMemory = other.m_moveOnSharedMemory;

			// Try to attach to the shared memory segment
			AttachToExisitngSharedMemoryIMP();
		}

		// Return the changed object
		return ( *this );
	}

	// Destructor,
	template< typename T >
	SharedMemory< T >::~SharedMemory() throw()
	{
		// No error checking is made, becuase a destructor to be exception safe must not throw exceptions,

		// Check if the user requires that the shared memory will be deleted at the end of use
		if ( true == m_trueForDestroyAndFalseForNot )
		{
			// Set the shared memory for deletion
			shmctl( m_sharedMemoryIdentifier, IPC_RMID, 0 );
		}

		// Detach from shared memory segment
		shmdt( m_sharedMemorySegmentBeginingAddress );
	}

	// Use to get shared memory system information
	template< typename T >
	inline struct shminfo SharedMemory< T >::GetSystemInformationOnSharedMemory() const throw( Exception )
	{	
		// Create an object of type shminfo structure to contain the system information on shared memory
		struct shmid_ds sharedMemoryInformation;

		// Use the shmctl system call to get the system information
		ThrowExceptionWithErrnoIfOperationFailed( shmctl( 0, IPC_INFO, &sharedMemoryInformation ), -1, "Getting shared memory system information failed" );
		
		// Return the structure containing the information
		return ( (struct shminfo)sharedMemoryInformation );
	}

	// Use to get the key that was used to create the shared memory
	template< typename T >
	inline key_t SharedMemory< T >::GetKey() const throw()
	{
		// Return the key that was used to create the shared memory
		return ( m_sharedMemoryKey );
	}

	// Use to check if the pointer on the shared memory reached the end, returns true if it does,
	// and false otherwise
	template< typename T >
	inline bool SharedMemory< T >::EndOfSharedMemory() const throw()
	{
		// Check if the pointer m_moveOnSharedMemory pointing to the end of the shared 
		// memory segment, it will return true if the outcome of the subtraction between
		// the two pointers is equal to the size of the shared memory
		return ( ( m_moveOnSharedMemory - m_sharedMemorySegmentBeginingAddress ) ==  m_sharedMemorySize );
	}

	// Read current object form shared memory and return it
	template< typename T >
	inline T SharedMemory< T >::GetCurrentObject() const throw( Exception )
	{
		// Check that the pointer m_moveOnSharedMemory has not passed the end of shared memory size
		ThrowExceptionWithErrnoIfExpressionIsTrue( EndOfSharedMemory(), "Getting current character failed, becuase the pointer is behind the end of the shared memory" );

		// Return a copy of the current object pointed to by m_moveOnSharedMemory
		return ( *m_moveOnSharedMemory );
	}

	// Write to current location in shared memory
	template< typename T >
	inline void SharedMemory< T >::SetCurrentObject( T newValueToSet ) throw( Exception )
	{
		// Check that the pointer m_moveOnSharedMemory has not passed the end of shared memory size
		ThrowExceptionWithErrnoIfExpressionIsTrue( EndOfSharedMemory(), "Setting current character failed, becuase the pointer is behind the end of the shared memory" );

		// Set the current location pointed to by m_moveOnSharedMemory
		*m_moveOnSharedMemory = newValueToSet;
	}

	// Use to set all entries in the shared memory to the required value
	template< typename T >
	inline void SharedMemory< T >::SetAllEntriesToRequiredValue( T newValueToSet ) throw()
	{
		// The shared memory was created, set all entries to 0
		SetAllEntriesOfArrayToValue< T >( m_sharedMemorySegmentBeginingAddress, newValueToSet, m_sharedMemoryNumberOfEntries );
	}

	// Use to get reference to an entry in the shared memory, this function can be used either
	// to get the required object and to change it, if te entry required is behind the end
	// of the shared memory the function will throw an Exception
	template< typename T >
	inline T& SharedMemory< T >::operator[]( unsigned int entryIndex ) throw( Exception )  //  Overloaded function
	{

		// Check that the entryIndex is not behind the end of the shared memory
		if ( entryIndex > ( m_sharedMemorySize / sizeof( T ) ) )
		{
			// The entry required is behind the end of the shared memory, throw an Exception
			throw( Exception( CreateErrorMessage( "Operator [] failed, becuase required entry is behind the end of shared memory" ) ) );
		}

		// Return a reference to the required entry
		return ( m_sharedMemorySegmentBeginingAddress[ entryIndex ] );
	}

	// Use to get the object in the required entry, if te entry required is behind the end
	// of the shared memory the function will throw an Exceptio
	template< typename T >
	inline T SharedMemory< T >::operator[]( unsigned int entryIndex ) const throw( Exception )  //  Overloaded function
	{

		// Check that the entryIndex is not behind the end of the shared memory
		if ( entryIndex > ( m_sharedMemorySize / sizeof( T ) ) )
		{
			// The entry required is behind the end of the shared memory, throw an Exception
			throw( Exception( CreateErrorMessage( "Operator [] failed, becuase required entry is behind the end of shared memory" ) ) );
		}

		// Return a reference to the required entry
		return ( m_sharedMemorySegmentBeginingAddress[ entryIndex ] );
	}

	// Use to set the pointer moving on the shared memory to next entry, if the pointer is
	// at the end of the shared memory the function will throw an Exception
	template< typename O >
	inline void operator++( SharedMemory< O >& sharedMemoryObject ) throw( Exception )
	{	

		// Check that the pointer inside the object doesn't point after the end of the shared memory
		if ( ( sharedMemoryObject.m_sharedMemoryNumberOfEntries < ( sharedMemoryObject.m_moveOnSharedMemory - sharedMemoryObject.m_sharedMemorySegmentBeginingAddress ) ) )
		{
			// The entry required is behind the end of the shared memory, throw an Exception
			throw( Exception( CreateErrorMessage( "Operator ++ failed, becuase the object points to the end of shared memory" ) ) );
		}

		// Advance the pointer inside the object to next entry
		++sharedMemoryObject.m_moveOnSharedMemory;
	}

	// Use to set the pointer moving on the shared memory to previous entry, if the pointer is
	// at the end of the shared memory the function will throw an Exception
	template< typename O >
	inline void operator--( SharedMemory< O >& sharedMemoryObject ) throw( Exception )
	{

		// Check that the pointer inside the object is not pointing to the begining of the shared memory
		if ( sharedMemoryObject.m_moveOnSharedMemory <= sharedMemoryObject.m_sharedMemorySegmentBeginingAddress )
		{
			// The entry required is behind the end of the shared memory, throw an Exception
			throw( Exception( CreateErrorMessage( "Operator -- failed, becuase the object points to the begining of shared memory" ) ) );
		}

		// Advance the pointer inside the object to next entry
		--sharedMemoryObject.m_moveOnSharedMemory;
	}






//	*****************************************   PRIVATE FUNCTIONS IMPLEMENTATION   ******************************************






	// Use to create a new key, required a path to an existing file and an integer, if the same
	// arguments are given the same key will be returned
	template< typename T >
	inline key_t SharedMemory< T >::CreateKeyForSharedMemoryIMP( const AsciiString& keyFileNameWithPath, int keyInteger ) throw( Exception )
	{
	    // Create an object to store the key returned from the use of ftok
	    key_t sharedMemoryKey = ftok( keyFileNameWithPath.GetAsciiString(), keyInteger );

	    // Check if creating the key succedded
	    ThrowExceptionWithErrnoIfOperationFailed( sharedMemoryKey, -1, "Creating a key for the shared memory failed" );

	    // Return the new key
	    return ( sharedMemoryKey );
	}

	// Use to create a new shared memory or attach to an exisitng shared memory, on failure throws an Exception
	template< typename T >
	int SharedMemory< T >::CreateSharedMemoryIMP( key_t sharedMemoryKey, unsigned int numberOfBytesRequired, bool failIfSharedMemoryAlreadyExist, int permissions ) throw( Exception )
	{
		// Create an object to store the shared memory identifier
		int sharedMemoryIdentifier = 0;

		// Try to create the shared memory
		if ( -1 == ( sharedMemoryIdentifier = shmget( sharedMemoryKey, numberOfBytesRequired, permissions | IPC_CREAT | IPC_EXCL ) ) )
		{
			
			// Check the reason for the failure of the system call, if it becuase the shared memory already exist
			// check if the user requires to fail in this case or attach to it
			if ( EEXIST == errno )
			{
				// Check what the user requires to do in case the shared memory already exist, fail or attach to it
				ThrowExceptionWithErrnoIfExpressionIsTrue( failIfSharedMemoryAlreadyExist, "Shared memory for current key already exist and" );

				// Try to get to the shared memory identifier
				sharedMemoryIdentifier = shmget( sharedMemoryKey, numberOfBytesRequired, permissions );

				// Check if attaching to the shared memory succeeded
				ThrowExceptionWithErrnoIfOperationFailed( sharedMemoryKey, -1, "Attaching to exisitng shared memory failed" );
			}
			else
			{
				// The system call shmget failed, throw an Exception
				throw( Exception( CreateErrorMessage( "Creating shared memory failed" ) ) );
			}

		}
		// The shared memory was created
		else
		{
			// Set inside the instance that it created the shared memory
			m_trueForCreateAndFalseForAttached = true;
		}

		// Return the shared memory identifier
		return ( sharedMemoryIdentifier );
	}

	// Use this to attach to an exisiting shared memory, if the attach failed the function
	// will check if current instance created the shared memory and will set it for destruction
	template< typename T >
	void SharedMemory< T >::AttachToExisitngSharedMemoryAndIfFailedDeleteSharedMemoryIfNeededIMP() throw( Exception )
	{
		
		// Try to attach to the shared memory segment
		if ( (void*)-1 == ( m_sharedMemorySegmentBeginingAddress = (T*)shmat( m_sharedMemoryIdentifier, NULL, 0 ) ) )
		{

			// Check if current instance created the shared memory, and then the shared memory
			// needs to be cleaned, or just tried to attach to it
			if ( true == m_trueForCreateAndFalseForAttached )
			{

				// Try to set the shared memory for destruction
				if ( -1 == shmctl( m_sharedMemoryIdentifier, IPC_RMID, 0 ) )
				{
					// Setting the shared memory for destruction also failed, throw an Exception
					throw( Exception( CreateErrorMessage( "Attaching to shared memory, and deleting it all failed" ) ) );
				}

			}

			// Attaching to the shared memory segment failed, throw an Exception
			throw( Exception( CreateErrorMessage( "Attaching to shared memory failed" ) ) );
		}

		// Set also m_moveOnSharedMemory to the begining of the shared memory segment
		m_moveOnSharedMemory = m_sharedMemorySegmentBeginingAddress;
	}

	// Use this to attach to an exisiting shared memory, if the attach failed the function
	// will throw an Exception
	template< typename T >
	void SharedMemory< T >::AttachToExisitngSharedMemoryIMP() throw( Exception )
	{

		// Try to attach to the shared memory segment
		if ( (void*)-1 == ( m_sharedMemorySegmentBeginingAddress = (T*)shmat( m_sharedMemoryIdentifier, NULL, 0 ) ) )
		{
			// Attaching to the shared memory segment failed, throw an Exception
			throw( Exception( CreateErrorMessage( "Attaching to shared memory failed" ) ) );
		}

	}

	// Use to detach from shared memory segment
	template< typename T >
	inline void SharedMemory< T >::DetachFromSharedMemoryIMP() throw( Exception )
	{

		// Try to detach from the shared memory segment
		if ( -1 == shmdt( m_sharedMemorySegmentBeginingAddress ) )
		{
			// Detach failed, throw an Exception
			throw( Exception( CreateErrorMessage( "Detaching from shared memory segment failed" ) ) );			
		}

	}

	// Use to set the shared memory for deletion after all process detach form it
	template< typename T >
	inline void SharedMemory< T >::DeleteSharedMemoryIMP() throw( Exception )
	{

		// Try to set the shared memory for destruction
		if ( -1 == shmctl( m_sharedMemoryIdentifier, IPC_RMID, 0 ) )
		{
			// Setting the shared memory for destruction also failed, throw an Exception
			throw( Exception( CreateErrorMessage( "Deleting shared memory failed" ) ) );
		}

	}


} //  namespace Universe

#endif  // __SHAREDMEMORY_H__
