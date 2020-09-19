#include "Pipe.h"



namespace Universe 
{


//	************************************** PUBLIC INTERFACE FUNCTIONS IMPLEMENTATION ************************************


	// Get copy of file descriptors, if the file descriptors were closed,
	// sets them to -1 and they should not be used, on the user to release 
	// the allocated space
	int* Pipe::GetFileDescriptorsCopy() const throw( std::bad_alloc, Exception )
	{
		// Allocate new memory space for the file descriptors
		int* fileDescriptorsCopy = new int[2];

		// Duplicate the file descriptors
		DuplicateOpeartionIMP( fileDescriptorsCopy, m_fileDescriptors );

		// Return the copy of file descriptors
		return ( fileDescriptorsCopy );
	}

	// Use to close the input file descriptor, receive a bollean describing
	// if throwing an Eception on error encounter or not, this way also the
	// destrcutor can use it, destructors must not throw exceptions to prevent
	// the case of throwing an exception while an other exception is active
	// which would cause the program to end
	void Pipe::CloseInputFileDescriptor( bool throwOrNot ) throw( Exception )
	{

		// Check the value of m_closedFileDescriptors
		if ( ( 0 == m_closedFileDescriptors ) || ( 2 == m_closedFileDescriptors ) )
		{
			// The input file descriptor was closed already, or Both file descriptors were closed
			return;
		}

		// Loop until the return value from closing the input file
		// descriptor is other then -1
		while ( -1 == close( 0 ) )
		{

			// Check if the reauired action on error is throwing an Exception
			if ( true == throwOrNot )
			{
				// If the operation failed and the reason is not a signal interrupt
				// throw an exception
				ThrowIfErrnoIsNotSetToEINTR( "CloseInputFileDescriptor", errno );
			}

		}

		if ( -1 == m_closedFileDescriptors )
		{
			// Set that the input file descriptor is closed
			m_closedFileDescriptors = 0;
		}
		else if ( 1 == m_closedFileDescriptors )
		{
			// Set that the input and output file descriptors were closed
			m_closedFileDescriptors = 2;
		}

	}

	// Use to close the output file descriptor, receive a bollean describing
	// if throwing an Eception on error encounter or not, this way also the
	// destrcutor can use it, destructors must not throw exceptions to prevent
	// the case of throwing an exception while an other exception is active
	// which would cause the program to end
	void Pipe::CloseOutputFileDescriptor( bool throwOrNot ) throw( Exception )
	{

		// Check the value of m_closedFileDescriptors
		if ( ( 1 == m_closedFileDescriptors ) || ( 2 == m_closedFileDescriptors ) )
		{
			// The output file descriptor was closed already, or Both file descriptors were closed
			return;
		}

		// Loop until the return value from closing the input file
		// descriptor is other then -1
		while ( -1 == close( 1 ) )
		{

			// Check if the reauired action on error is throwing an Exception
			if ( true == throwOrNot )
			{
				// If the operation failed and the reason is not a signal interrupt
				// throw an exception
				ThrowIfErrnoIsNotSetToEINTR( "CloseOutputFileDescriptor", errno );
			}

		}

		if ( -1 == m_closedFileDescriptors )
		{
			// Set that the input file descriptor is closed
			m_closedFileDescriptors = 1;
		}
		else if ( 0 == m_closedFileDescriptors )
		{
			// Set that the input and output file descriptors were closed
			m_closedFileDescriptors = 2;
		}

	}

	// Use to write into pipe, returns the number of written bytes
	int Pipe::WriteToPipe( const char* writeThis, int writeThisLength ) throw( Exception )
	{
		// Create an object to store write system call return value
		int writeReturnValue = 0;

		// Loop until the return value of the write opration is not -1
		while ( -1 == ( writeReturnValue = write( m_fileDescriptors[1], writeThis, writeThisLength )  ) )
		{
			// If the operation failed and the reason is not a signal interrupt
			// throw an exception
			ThrowIfErrnoIsNotSetToEINTR( "WriteToPipe", errno );
		}

		// Return the number of bytes written to pipe
		return ( writeReturnValue );

	}

	// Use to write into pipe, closes the input file descriptor, and returns the number
	// of written bytes
	int Pipe::WriteToPipeAndCloseInputFileDescriptor( const char* writeThis, int writeThisLength ) throw( Exception )
	{

		// Check if the input file descriptor needs to be closed
		if ( -1 == m_closedFileDescriptors )
		{
			
			// Loop until the return value from closing the input file
			// descriptor is other then -1
			while ( -1 == close( 0 ) )
			{
				// If the operation failed and the reason is not a signal interrupt
				// throw an exception
				ThrowIfErrnoIsNotSetToEINTR( "WriteToPipe", errno );
			}

			m_closedFileDescriptors = 0;

		}
		// Cehck that the output file descriptor is still open
		else if ( ( 1 == m_closedFileDescriptors ) || ( 2 == m_closedFileDescriptors ) )
		{
			throw( Exception( "WriteToPipe failed becuase the output file descriptor is closed" ) );
		}

		// Send writeThis through the pipe
		return( WriteToPipe( writeThis, writeThisLength ) );
	}

	// Use to read from pipe, and returns the address of the information from 
	// pipe in readToThisLocation and the number of bytes that were read, on the user to
	// delete the resource
	int Pipe::ReadFromPipe( char* readToThisLocation, int readToThisLocationLength ) throw( Exception )
	{
		// Create an object to store read system call return value
		int readReturnValue = 0;

		// Loop until the return value of the read opration is not -1
		while ( -1 == ( readReturnValue = read( m_fileDescriptors[0], readToThisLocation, readToThisLocationLength )  ) )
		{
			// If the operation failed and the reason is not a signal interrupt
			// throw an exception
			ThrowIfErrnoIsNotSetToEINTR( "ReadToPipe", errno );
		}

		// Return the number of bytes written to pipe
		return ( readReturnValue );

	}

	// Use to read from pipe, closes the input file descriptor, and returns
	// the address of the information from pipe in readToThisLocation and the number of
	// bytes that were read, on the user to delete the resource
	int Pipe::ReadFromPipeAndCloseOutputFileDescriptor( char* readToThisLocation, int readToThisLocationLength ) throw( Exception )
	{

		// Check if the output file descriptor needs to be closed
		if ( -1 == m_closedFileDescriptors )
		{
			
			// Loop until the return value from closing the output file
			// descriptor is other then -1
			while ( -1 == close( 1 ) )
			{
				// If the operation failed and the reason is not a signal interrupt
				// throw an exception
				ThrowIfErrnoIsNotSetToEINTR( "ReadFromPipe", errno );
			}

			m_closedFileDescriptors = 1;

		}
		// Cehck that the input file descriptor is still open
		else if ( ( 0 == m_closedFileDescriptors ) || ( 2 == m_closedFileDescriptors ) )
		{
			throw( Exception( "ReadToPipe failed becuase the input file descriptor is closed" ) );
		}

		// Read the information from pipe
		return ( ReadFromPipe( readToThisLocation, readToThisLocationLength ) );
	}



//	************************************** PRIVATE FUNCTIONS IMPLEMENTATION ************************************



	// Used to actually perform the duplication operation
	void DuplicateOpeartionIMP( int* duplicateTo, const int* const duplicateFrom ) throw( Exception )
	{
	
		// Loop until the return value from duplicating the input file
		// descriptor is other then -1
		while ( -1 == ( duplicateTo[0] = dup( duplicateFrom[0] ) ) )
		{
			// If the operation failed and the reason is not a signal interrupt
			// throw an exception
			ThrowIfErrnoIsNotSetToEINTR( "Pipe construction - dup input file descriptor failed", errno );
		}

		// Loop until the return value from duplicating the output file
		// descriptor is other then -1
		while ( -1 == ( duplicateTo[1] = dup( duplicateFrom[1] ) ) )
		{
			// If the operation failed and the reason is not a signal interrupt
			// throw an exception
			ThrowIfErrnoIsNotSetToEINTR( "Pipe construction - dup output file descriptor failed", errno );
		}

	}


}  //  namespace Universe
