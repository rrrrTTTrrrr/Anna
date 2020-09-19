#ifndef  __WORKINGWITHPIPES_H__
#define  __WORKINGWITHPIPES__H_

#include <unistd.h>  //  Function pipe
#include <errno.h>  //  errno
#include <new>  //  std::bad_alloc

#include "../ErrorHandling/Exception.h"  //  Class Exception
#include "../BasicUtilities/cpp_BasicUtilities.h"  //  Function ThrowIfErrnoIsNotSetToEINTR(

// When a function name ends with the suffix IMP, the function is not part 
// of the object interface ( capabilities ), it only used as aid to the 
// function that it is, implementing only spsecific part 	


namespace Universe 
{ 

	// A pipe is a mechanism for interprocess communication. Data written to the pipe by one process can be read 
	// by another process. The primitive for creating a pipe is the pipe function. This creates both the reading 
	// and writing ends of the pipe. It is not very useful for a single process to use a pipe to talk to itself. 
	// In typical use, a process creates a pipe just before it forks one or more child processes. The pipe is 
	// then used for communication either between the parent or child processes, or between two sibling processes

	// In order for an operation to be considered ``atomic'', it must not be interrupted for any reason at all. 
	// The entire operation occurs at once. The POSIX standard dictates in /usr/include/posix1_lim.h that the 
	// maximum buffer size for an atomic operation on a pipe is:

    //    #define _POSIX_PIPE_BUF         512

	// Up to 512 bytes can be written or retrieved from a pipe atomically. Anything that crosses this threshold will be split, 
	// and not atomic. Under Linux, however, the atomic operational limit is defined in ``linux/limits.h'' as:

    //    #define PIPE_BUF        4096

	// The system call for creating a pipe ->  int pipe( int fileDescriptors[2] )

	// Pipe is one direction proccess communication tool, therfore it is considered good
	// practice to close the unsed file descriptor

	// Used to actually perform the duplication operation
	void DuplicateOpeartionIMP( int* duplicateTo, const int* const duplicateFrom ) throw( Exception );

	// This class is used to work with pipes, and can be used as base class to improve capabilities
	class Pipe
	{ 
	public: 

		// Constructor
		inline Pipe() throw( Exception );

		// Copy constructor
		inline Pipe( const Pipe& other ) throw( Exception );

		// Assignment operator
		inline Pipe& operator=( const Pipe& other ) throw( Exception );

		// Destructor, the method is declared virtual, in order for using
		// the virtual table when determning the destructor, in a case were a base
		// class pointer set to derived class object
		virtual inline ~Pipe() throw();

		// Use to close the input file descriptor 
		void CloseInputFileDescriptor( bool throwOrNot ) throw( Exception );

		// Use to close the output file descriptor 
		void CloseOutputFileDescriptor( bool throwOrNot ) throw( Exception );

		// Get copy of file descriptors, on the user to release the allocated space
		int* GetFileDescriptorsCopy() const throw( std::bad_alloc, Exception );

		// Check which file descriptors were closed and return :
		// -1 -> none were closed
		// 0 -> input file descriptor was closed
		// 1 -> output file descriptor was closed
		// 2 -> both file descriptors were closed
		inline int WhichFileDescriptorsWereClosed() const throw();

		// Use to write into pipe, returns the number of written bytes
		int WriteToPipe( const char* writeThis, int writeThisLength ) throw( Exception );

		// Use to write into pipe, closes the input file descriptor, and returns the number
		// of written bytes
		int WriteToPipeAndCloseInputFileDescriptor( const char* writeThis, int writeThisLength ) throw( Exception );

		// Use to read from pipe, and returns the address of the information from 
		// pipe in readThis and the number of bytes that were read, on the user to
		// delete the resource
		int ReadFromPipe( char* readToThisLocation, int readToThisLocationLength ) throw( Exception );

		// Use to read from pipe, closes the input file descriptor, and returns
		// the address of the information from pipe in readThis and the number of
		// bytes that were read, on the user to delete the resource
		int ReadFromPipeAndCloseOutputFileDescriptor( char* readToThisLocation, int readToThisLocationLength ) throw( Exception );

		// Receive file descriptors and sets them inside m_fileDescriptors of current object
		inline void DuplicateFileDescriptorsIMP( const int* fileDescriptorsToCopy ) throw( Exception );

	private: 

		// An array of integers to store the two file descriptors :
		// 1. m_fileDescriptors[0] - use for read operations
		// 2. m_fileDescriptors[1] - use for write operations
		int m_fileDescriptors[2] = {0};

		// An object to store which file descriptors were closed :
		// -1 -> none were closed
		// 0 -> input file descriptor was closed
		// 1 -> output file descriptor was closed
		// 2 -> both file descriptors were closed
		int m_closedFileDescriptors = -1;

		// Used to actually perform the duplication operation
		void DuplicateOpeartionIMP( int* duplicateTo, const int* const duplicateFrom ) throw( Exception );


	};  //  Class Pipe


	// Constructor
	inline Pipe::Pipe() throw( Exception )
	{

		// Create the pipes using the pipe system call which creates two
		// new file descriptors one for standard input and one for standard ouput
		if ( -1 == pipe( m_fileDescriptors ) )
		{
			// If pipes creation failed throw an Exception
			throw( Exception( CreateErrorMessage( "Pipe construction - pipe failed", errno ) ) );
		}

	}

	// Copy constructor
	inline Pipe::Pipe( const Pipe& other ) throw( Exception )
	{
		// Copy the file descriptors
		DuplicateFileDescriptorsIMP( other.GetFileDescriptorsCopy() );

		// Set m_closedFileDescriptors to the state of the file descriptors
		m_closedFileDescriptors = WhichFileDescriptorsWereClosed();
	}

	// Assignment operator
	inline Pipe& Pipe::operator=( const Pipe& other ) throw( Exception )
	{
		// Copy the file descriptors
		DuplicateFileDescriptorsIMP( other.GetFileDescriptorsCopy() );

		// Set m_closedFileDescriptors to the state of the file descriptors
		m_closedFileDescriptors = WhichFileDescriptorsWereClosed();

		return ( *this );
	}

	// Destructor, the method is declared virtual, in order for using
	// the virtual table when determning the destructor, in a case were a base
	// class pointer set to derived class object
	inline Pipe::~Pipe() throw()
	{
		// Close input file descriptor
		CloseInputFileDescriptor( false );

		// Close output file descriptor
		CloseOutputFileDescriptor( false );
	}


	// Check which file descriptors were closed and return :
	// -1 -> none were closed
	// 0 -> input file descriptor was closed
	// 1 -> output file descriptor was closed
	// 2 -> both file descriptors were closed
	inline int Pipe::WhichFileDescriptorsWereClosed() const throw()
	{
		// Return m_closedFileDescriptors which holds the current state
		// of the file descriptors
		return ( m_closedFileDescriptors );
	}

	// Receive file descriptors and sets them inside m_fileDescriptors of current object
	inline void Pipe::DuplicateFileDescriptorsIMP( const int* fileDescriptorsToCopy ) throw( Exception )
	{
		// Duplicate the file descriptors
		DuplicateOpeartionIMP( m_fileDescriptors, fileDescriptorsToCopy );
	}


}  //  namespace Universe

#endif  // __WORKINGWITHPIPES__H_
