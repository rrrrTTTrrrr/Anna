#include <iostream>  //  Class std::bad_alloc
#include <errno.h>  //  Macro errno


#include "../Exception/Exception.h"  //  Class Exception
#include "../BasicUtilities/cpp_BasicUtilities.h"  //  Function ThrowIfErrnoIsNotSetToEINTR
#include "../InterProcessCommunication/StandardInputOutputError.h"  //  Function WriteToStandardError
#include "../FileSystem/Directory.h"  //  Class Directory


// This file is used as template when creating a new shell executable, becuase
// every program that the shell run should be able to deal with the special
// aspects. This includes :

// 1. Pipe - other programs should be able to send and receive data from current progarm,
// the character "|" ( pipe sign ) is used to initiate the communication

// 2. File - the progarm must be able to receive it's input from a file and write it's output
// to a file, the character "<" ( input from file redirection ) are used to notify that
// the input to the program should be read from the file, the characters ">",">>" ( output
// to file redirection ) are used to store the output of the progarm into a file, the difference
// between them is that, the character ">" will erase the current content of a file and replace it
// with the output, if the file with the required name doesn't exist creates it and then insert
// the data, while the character ">>" only append the data to a current existing file 

// 3.     

namespace Universe
{

	// Create a macro to store the required number of command line arguments
	#define NUMBER_OF_ARGUMENTS_REQUIRED_FROM_COMMAND_LINE 2

	// Check that the required amount of command line arguments was given, if the number 
	// of command line arguments given is lower then the required amount 
	// in NUMBER_OF_ARGUMENTS_REQUIRED_FROM_COMMAND_LINE, writes an error
	// message to Standard error, and return the ERROR_VALUE
	#define RETURN_ERROR_IF_NOT_ENOUGH_COMMAND_LINE_ARRGUMENTS( ARGC, ERROR_VALUE ) if ( ( ARGC < NUMBER_OF_ARGUMENTS_REQUIRED_FROM_COMMAND_LINE ) ) { WriteToStandardError( "Not enough command line arguments given" ); return ( ERROR_VALUE ); }
	

}  //  namespace Universe



using namespace Universe;



int main( int argc, const char** argv )
{

	try
	{

		// Check the number of command line arguments given, if it's only 1,
		// the working directory should be displayed, and in case of 2,
		// the second argument should contain a directory path
		if ( 1 == argc )
		{
			// 1 argument from command line 

			// Crate a Directory object with the working directory path
			Directory currentDirectoryToDisplay;

			// Display working directory files
			currentDirectoryToDisplay.DisplayListOfFilesInDirectory();	
		} 
		else if ( 2 == argc )
		{
			// 2 arguments from command line

			// Crate a Directory object with the required directory
			// path in the second argument from command line
			Directory currentDirectoryToDisplay( argv[1] );

			// Display the required directory files
			currentDirectoryToDisplay.DisplayListOfFilesInDirectory();			
		}



	}
	catch ( const Exception& e )
	{
		std::cout << e.What() << std::endl;
	}


	return ( 0 );
}



