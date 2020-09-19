#include <iostream>  //  Class std::bad_alloc
#include <errno.h>  //  Macro errno


#include "../ErrorHandling/Exception.h"  //  Class Exception
#include "../BasicUtilities/cpp_BasicUtilities.h"  //  Function ThrowIfErrnoIsNotSetToEINTR
#include "../ProccesInterCommunication/StandardInputOutputError.h"  //  Function WriteToStandardError


// This file is used as template when creating a new shell executable, becuase
// every program that the shell run should be able to deal with the special
// aspects. This includes :
//
// 1. Pipe - other programs should be able to send and receive data from current progarm,
// the character "|" ( pipe sign ) is used to initiate the communication
//
// 2. File - the progarm must be able to receive it's input from a file and write it's output
// to a file, the character "<" ( input from file redirection ) are used to notify that
// the input to the program should be read from the file, the characters ">",">>" ( output
// to file redirection ) are used to store the output of the progarm into a file, the difference
// between them is that, the character ">" will erase the current content of a file and replace it
// with the output, if the file with the required name doesn't exist creates it and then insert
// the data, while the character ">>" only append the data to a current existing file


namespace Universe
{


    // Create a macro to store the required number of command line arguments
    #define NUMBER_OF_ARGUMENTS_REQUIRED_FROM_COMMAND_LINE 2

    // Check that the required amount of command line arguments was given, if the number 
    // of command line arguments given is lower then the required amount
    // in NUMBER_OF_ARGUMENTS_REQUIRED_FROM_COMMAND_LINE, writes an error
    // message to Standard error, and return the ERROR_VALUE
    #define RETURN_ERROR_IF_NOT_ENOUGH_COMMAND_LINE_ARRGUMENTS( ARGC, ERROR_VALUE ) if ( ( ARGC < NUMBER_OF_ARGUMENTS_REQUIRED_FROM_COMMAND_LINE ) ) 
    																{ WriteToStandardError( "Not enough command line arguments given" ); return ( ERROR_VALUE ); }


    // To Check if parent process opened a pipe to current process, do it
    // by using the poll system call. It is used wait for some event on a file descriptor.
    // The poll system call receive an amount of pollfd structures, every one contain 
    // a file descritor and events which should be checked if they happened to the
    // file descriptor. The system call is also given the number of structures, and a 
    // time out value in miliseconds. The system call returns on success the number
    // of structures which have a non zero revents field, this field is set by
    // the system call and describe the events which have happend to each of the file
    // descriptors. The system call returns 0 if the time out has passed and
    // no file descriptor was ready. On failure -1 is returned and errno is set
    // accordingly, Syntax :
    //
    // 	  int poll( struct pollfd *fds, nfds_t nfds, int timeout )


    // Use to check if parent process opened a pipe to current process, it does
    // that by checking if standrd input has data to read, returns true in case
    // a data exist, and false otherwise, if the poll system call failed and it
    // wasn't due to signal interrupt throws an exception
    inline bool DoesDataWaitOnStandardInput() throw()
    {
    	// Create a pollfd structure
    	struct pollfd pollFileDescriptor;

    	// Set inside the file descriptor filed in pollfd structure the standard input
    	// file descriptor ( 0 )
    	pollFileDescriptor.fd = 0;

    	// Set inside the events filed in pollfd structure the POLLIN macro

    	// which stand for, check if there is data to read from file descriptor
    	pollFileDescriptor.events = POLLIN;

    	// Create an object to store the return value from the system call poll
    	int pollReturnValue = 0;

    	// Loop until the return value from poll is not -1
    	while ( -1 == ( pollReturnValue = poll( &pollFileDescriptor, 1, 0 ) ) )
    	{
    		// Check the reason for the failure and if it is not
    		// becuase of signal interrupt throw an Exception
    		ThrowIfErrnoIsNotSetToEINTR( "DoesDataWaitOnStandardInput failed becuase poll failed" );
    	}

    	// If a file descriptor is ready for reading the return value from poll
    	// would be one, and else zero, just return it
    	return ( pollReturnValue );
    }


}  //  namespace Universe


 using namespace Universe;


int main( int argc, const char** argv )
{

    try
    {

    	// check if parent process opened a pipe to current process
    	if ( true == DoesDataWaitOnStandardInput() )
    	{
    		// Read the data from standard input file descriptor ( 0 )
    		TODO dataFromStandradInput = ReadArrayOfArraysFromStandardInput(< TODO >( TODO, TODO ) );

    		// Check if the operation succeeded
    		ThrowExceptionWithErrnoIfPointerIsNULL( dataFromStandradInput, "Reading from standard input failed" );
    	}

    	// Check that the required amount of command line arguments was given
    	if ( argc < NUMBER_OF_ARGUMENTS_REQUIRED_FROM_COMMAND_LINE )
    	{
    		// There are not enough command line arguments

    		// Print error message to the user
    		WriteToStandardError( "Not enough command line arguments given" );

    		// Return the vlaue 1 to indicate that an error occurred
    		return ( 1 );
    	}

    }
    catch ( const Exception& exception )
    {
    	exception.What();
    }

    // The operation succeeded return 0
    return ( 0 );
}