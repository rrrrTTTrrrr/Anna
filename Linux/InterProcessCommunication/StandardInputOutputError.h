#ifndef  STANDARDINPUTOUTPUTERROR_H
#define  STANDARDINPUTOUTPUTERROR_H


#include <iostream>  //  std::cout
#include <unistd.h>  //  Function read


#include "../BasicUtilities/BasicOperations/Array/ArrayOperations.h"  //  Function AllocateArrayOfArrays, FUnction DisplayArray, Function DisplayArrayOfArrays
#include "../BasicUtilities/BasicOperations/Ascii/AsciiStringOperations.h"  //  Function DisplayAsciiString, Function DisplayArrayOfAsciiStrings, Function SetAsciiStringToZero
#include "../BasicUtilities/cpp_BasicUtilities.h"  //  Function RETURN_IF_ERNNO_IS_NOT_SET_TO_EINTR
#include "../BasicUtilities/BasicOperations/Ascii/AsciiString.h"  //  Class AsciiString
#include "../Definitions/VariableTypesDefinitions.h"  //  Typedef UnsignedInteger64bits, Typedef SignedInteger8bits


// When using function template specialization, the specialized function has
// no more dependency on the template parameter, and there for the function
// must nest inside the implementation file ( .cpp ) and not in the header ( .h )
// otherwise it violates the one definition rule.


// The one definition rule :
// No translation unit shall contain more than one definition of any variable,
// function, class type, enumeration type or template. Every program shall
// contain exactly one definition of every non-inline function or object that
// is used in that program; no diagnostic required. The definition can appear
// explicitly in the program, it can be found in the standard or a user-defined
// library, or ( when appropriate ) it is implicitly defined. An inline function
// shall be defined in every translation unit in which it is used.



namespace Universe
{




	// Function Information :
    //
    //  Description :
    //
	// 		This function recieve information from standard input, and store it into an array.
	//		Use this function when there is no information on the amount that needs to be read.
	//		The number of objects read will be stored in the given reference
    //
    //  Required arguments :
    //
	//		amountOfObjectsRead - a reference to a location to store the amount of bytes that were received 
	//		from standard input
    //
    //  Return value :
    //
	//		The address of the array containing the information from standard input
    //
    //  Possible errors :
    //
    //		1. There is no more free space - class std::bad_alloc is thrown
    //		2. The read system call failed - class ErrnoException is thrown
    //		3.  
    //
	template< typename T >
	T* ReadFromStandardInput( UnsignedInteger64bits& amountOfObjectsRead );


	// Function Information :
    //
    //  Description :
    //
	// 		This function read the required amount of information from standard input, and store it into an array
    //
    //  Required arguments :
    //
    //		1. array - space to contain the information from standard input
    //		2. amountToRead - the number of objects to read from standard input
    //
    //  Return value :
    //
	//		1. The value 0 - if all the reads were successfully performed
	//		2. A positive value - the amount of succesful reads from the total reads
    //
    //  Possible errors :
    //
    //		1. The given pointer to the array is NULL - class Exception is thrown
    //		2. Not all the objects were successfuly read - the function will return the number of
    //		successful reads from the total reads
    //		3.
    //
	template< typename T >
	SignedInteger64bits ReadFromStandardInputTheRequiredAmount( T* array, UnsignedInteger64bits amountToRead );


	// Function Information :
    //
    //  Description :
    //
	// 		This function recieves information from standard input, and store it into an array.
	//		This is a specialized template function for ascii characters
    //
    //  Required arguments :
    //
    //		1. asciiCharacterArray - space to contain the information from standard input
    //		2. amountToRead - the number of ascii characters to read from standard input
    //
	//		Important Note - the array must have 1 more entry for the NULL terminator
	//
    //  Return value :
    //
	//		1. The value 0 - if all the reads were successfully performed
	//		2. A positive value - the amount of succesful reads from the total reads
    //
    //  Possible errors :
    //
    //		1. The given pointer to the array is NULL - class Exception is thrown
    //		2. Not all the objects were successfuly read - the function will return the number of
    //		successful reads from the total reads
	//		3. There is no more free space to allocate - class std::bad_alloc is thrown
	//		4.
    //
	template<>
	SignedInteger64bits ReadFromStandardInputTheRequiredAmount< char >( char* asciiCharacterArray, UnsignedInteger64bits amountToRead );


	// Function Information :
    //
    //  Description :
    //
	// 		This function recieve information from standard input, and store it into an array
	//		of pointers
    //
    //  Required arguments :
    //
    //		1. arrayOfPointers - space to contain the information from standard input
    //		2. numberOfPointers - the number of entries in the array of pointers
    //		3. numberOfEntriesForEveryPointer - the number of entries each pointer points to
    //
    //  Return value :
    //
	//		An array containing information on the read operation :
	//		1. If the values are [0,0] - meaning success, all the information was read
	//		2. If the values are both positive integers [+,+] - something went wrong, the first entry of
	//		the returned array will contain the number of pointers that the space they point to were
	// 		fully set, the second entry will contain the number of entries that were set in this array
    //
	//		Important Note - the responsibility for deleting the returned array is on the user
	//
    //  Possible errors :
    //
    //		1. The given pointer to the array of pointers is NULL - class Exception is thrown
    //		2. Not all the objects were successfuly read - the function will return an array with
    //		the read information
	//		3. There is no more free space to allocate - class std::bad_alloc is thrown
	//		4.
    //
	template< typename T >
	SignedInteger64bits* ReadArrayOfArraysFromStandardInput( T** arrayOfPointers, UnsignedInteger64bits numberOfPointers, UnsignedInteger64bits numberOfEntriesForEveryPointer );


	// Function Information :
    //
    //  Description :
    //
	// 		This function recieve information from standard input, and store it into an array
	//		of pointers. This is a specialized template function for ascii characters
    //
    //  Required arguments :
    //
    //		1. arrayOfPointers - space to contain the information from standard input
    //		2. numberOfPointers - the number of entries in the array of pointers
    //		3. numberOfEntriesForEveryPointer - the number of entries each pointer points to
	//
	//		Important Note - each array pointed by one of the pointers must have 1 entry more
	//		then the required amount of reads, for the NULL terminator
    //
    //  Return value :
    //
	//		An array containing information on the read operation :
	//		1. If the values are [0,0] - meaning success, all the information was received
	//		2. If the values are both positive integers [+,+] - something went wrong, the first entry of
	//		the returned array will contain the number of pointers that the space they point to were
	// 		fully set, the second entry will contain the number of entries that were set in this array
    //
	//		Important Note - the responsibility for deleting the returned array is on the user
	//
    //  Possible errors :
    //
    //		1. The given pointer to the array of pointers is NULL - class Exception is thrown
    //		2. Not all the objects were successfuly read - the function will return an array with
    //		the read information
    //		3. There is no more free space to allocate - class std::bad_alloc is thrown
	//		4.
    //
	template<>
	SignedInteger64bits* ReadArrayOfArraysFromStandardInput< char >( char** arrayOfPointers, UnsignedInteger64bits numberOfPointers, UnsignedInteger64bits numberOfEntriesForEveryPointer );


	// Function Information :
	//
	//  Description :
	//
	// 		Use this function to write to standard error
	//
	//  Required arguments :
	//
	//		1. array - space to contain the information from standard input
	//		2. amountToRead - the number of objects to read from standard input
	//
	//  Return value :
	//
	//		1. The value 0 - if all the reads were successfully performed
	//		2. A positive value - the amount of succesful reads from the total reads
	//
	//  Possible errors :
	//
	//		1. The given pointer to the array is NULL - class Exception is thrown
	//		2. Not all the objects were successfuly read - the function will return the number of
	//		successful reads from the total reads
	//		3.
	//
	template< typename T >
	SignedInteger64bits WriteToStandardError( const T* array, UnsignedInteger64bits amountToWrite );











//************************************** END PART OF DECLRATIONS, IMPLMENTAION TIME ************************************












	// Function Information :
    //
    //  Description :
    //
	// 		This function recieve information from standard input, and store it into an array.
	//		Use this function when there is no information on the amount that needs to be read.
	//		The number of objects read will be stored in the given reference
    //
    //  Required arguments :
    //
	//		amountOfObjectsRead - a reference to a location to store the amount of bytes that were received 
	//		from standard input
    //
    //  Return value :
    //
	//		The address of the array containing the information from standard input
    //
    //  Possible errors :
    //
    //		1. There is no more free space - class std::bad_alloc is thrown
    //		2. The read system call failed - class ErrnoException is thrown
    //		3.  
    //
	template< typename T >
	T* ReadFromStandardInput( UnsignedInteger64bits& amountOfObjectsRead )
	{
		// Create an object to store the addres of the new allocated space
		T* informationFromStandardInput = new T[16384];

		// Create an object to store the return value from the read system call
		SignedInteger64bits returnValueFromRead = 0;

		// Set the anount of objects read to 0
		amountOfObjectsRead = 0;

		// Read one byte at a time until the return value from the read system call is 0, meanning
		// there is nothing more to read
		for ( SignedInteger64bits informationFromStandardInputIndex = 0 ; 0 != ( returnValueFromRead = read( 0, &informationFromStandardInput[ informationFromStandardInputIndex ], sizeof( T ) ) ) ; ++informationFromStandardInputIndex )
		{

			// Check if the return value from the read operation signals error
			if ( -1 == returnValueFromRead )
			{
				// Check the reason for the read operation failure. If an
				// interrupt is not the reason ( EINTR ) return error 
				ThrowExceptionWithErrnoIfErrnoIsNotSetToEINTR( "ReadFromStandardInput" );
			}

			// Increase the number of objects read by 1
			amountOfObjectsRead += 1;

		}

		// Return the information from standard input
		return ( informationFromStandardInput );
	}


	// Function Information :
    //
    //  Description :
    //
	// 		This function read the required amount of information from standard input, and store it into an array
    //
    //  Required arguments :
    //
    //		1. array - space to contain the information from standard input
    //		2. amountToRead - the number of objects to read from standard input
    //
    //  Return value :
    //
	//		1. The value 0 - if the end of file reached 
	//		2. A positive value - the amount of succesful readings
    //
    //  Possible errors :
    //
    //		1. The given pointer to the array is NULL - class Exception is thrown
    //		2. Not all the objects were successfuly read - the function will return the number of
    //		successful reads from the total reads
    //		3.
    //
	template< typename T >
	SignedInteger64bits ReadFromStandardInputTheRequiredAmount( T* array, UnsignedInteger64bits amountToRead )
	{
		// Check that the given pointer to the array is not NULL
		ThrowExceptionIfPointerIsNULL( array, "ReadFromStandardInput failed - the given pointer is NULL" );

		// Check that the amount to read is not 0
		ThrowExceptionIfValueOneIsEqualToValueTwo< UnsignedInteger64bits >( amountToRead, 0, "ReadFromStandardInput character version failed - the amount to read is 0" );

		// Create an object to store the return value from the read system call
		SignedInteger64bits returnValueFromRead = 0;

		// Read until the system call return value is not error, meaning -1
		while ( -1 == ( returnValueFromRead = read( 0, array, ( sizeof( T ) * amountToRead ) ) ) )
		{
			// Check the reason for the read operation failure. If an
			// interrupt is not the reason ( EINTR ) return error 
			RETURN_THE_GIVEN_NUMBER_IF_ERNNO_IS_NOT_SET_TO_EINTR( -1 )
		}

		// Return the amount of read by the system call. If the value is 0 the end of file reached
		return ( returnValueFromRead );
	}


	// Function Information :
    //
    //  Description :
    //
	// 		This function recieve information from standard input, and store it into an array
	//		of pointers
    //
    //  Required arguments :
    //
    //		1. arrayOfPointers - space to contain the information from standard input
    //		2. numberOfPointers - the number of entries in the array of pointers
    //		3. numberOfEntriesForEveryPointer - the number of entries each pointer points to
    //
    //  Return value :
    //
	//		An array containing information on the read operation :
	//		1. If the values are [0,0] - meaning success, all the information was read
	//		2. If the values are both positive integers [+,+] - something went wrong, the first entry of
	//		the returned array will contain the number of pointers that the space they point to were
	// 		fully set, the second entry will contain the number of entries that were set in this array
    //
	//		Important Note - the responsibility for deleting the returned array is on the user
	//
    //  Possible errors :
    //
    //		1. The given pointer to the array of pointers is NULL - class Exception is thrown
    //		2. Not all the objects were successfuly read - the function will return an array with
    //		the read information
	//		3. There is no more free space to allocate - class std::bad_alloc is thrown
	//		4.
    //
	template< typename T >
	SignedInteger64bits* ReadArrayOfArraysFromStandardInput( T** arrayOfPointers, UnsignedInteger64bits numberOfPointers, UnsignedInteger64bits numberOfEntriesForEveryPointer )
	{
		// Check that the given pointer to the array of pointers is not NULL
		ThrowExceptionIfPointerIsNULL( arrayOfPointers, "ReadArrayOfArraysFromStandardInput failed - the given pointer is NULL" );

		// Check that the number of pointers is not 0
		ThrowExceptionIfValueOneIsEqualToValueTwo< UnsignedInteger64bits >( numberOfPointers, 0, "ReadArrayOfArraysFromStandardInput failed - the number of pointers is 0" );

		// Check that the number of entries for each pointer is not 0
		ThrowExceptionIfValueOneIsEqualToValueTwo< UnsignedInteger64bits >( numberOfEntriesForEveryPointer, 0, "ReadArrayOfArraysFromStandardInput failed - the number of entries for each pointer is 0" );

		// Create an object to store address of the array that the information from the read will be stored
		SignedInteger64bits* amountOfSuccessfulReads = new UnsignedInteger64bits[2];

		// Create an object to store the return value from the read system call
		SignedInteger64bits returnValueFromRead = 0;

		// Loop on all the pointers
		for ( UnsignedInteger64bits arrayOfPointersIndex = 0 ; arrayOfPointersIndex < numberOfPointers ; ++arrayOfPointersIndex )
		{

			// Read until the return value is not -1
			while ( -1 == ( returnValueFromRead = read( 0, arrayOfPointers[ arrayOfPointersIndex ], ( sizeof( T ) * numberOfEntriesForEveryPointer ) ) ) )
			{

				// Check the reason for the read operation failure. If an
				// interrupt is not the reason ( EINTR ) return the read
				//	information
				if ( EINTR != errno )
				{
					// Set the successful amount of reads

					// The first entry will contain the number of arrays that were successfully read
					amountOfSuccessfulReads[0] = arrayOfPointersIndex;

					// The second entry will contain the number of entries in current array that were successfully read
					amountOfSuccessfulReads[1] = returnValueFromRead;
				}

			}

			// Check if the end of file reached 
			if ( 0 == returnValueFromRead )
			{
				// The end of file reached

				// Set the number of pointers that were read until this point
				amountOfSuccessfulReads[0] = arrayOfPointersIndex;

				// Set the number of entries were read in current array to 0, to notify end of file 
				amountOfSuccessfulReads[1] = 0;
			}

		}

		// Set the amount of successful reads entries to 0, to notify that all the
		// required information arrived
		amountOfSuccessfulReads[0] = 0;
		amountOfSuccessfulReads[1] = 0;

		// Return the read information
		return ( amountOfSuccessfulReads );
	}


	// Function Information :
	//
	//  Description :
	//
	// 		Use this function to write to standard error
	//
	//  Required arguments :
	//
	//		1. array - space to contain the information from standard input
	//		2. amountToRead - the number of objects to read from standard input
	//
	//  Return value :
	//
	//		1. The value 0 - if all the reads were successfully performed
	//		2. A positive value - the amount of succesful reads from the total reads
	//
	//  Possible errors :
	//
	//		1. The given pointer to the array is NULL - class Exception is thrown
	//		2. Not all the objects were successfuly read - the function will return the number of
	//		successful reads from the total reads
	//		3.
	//
	template< typename T >
	SignedInteger64bits WriteToStandardError( const T* array, UnsignedInteger64bits amountToWrite )
	{
		// Check that the given pointer to the array of pointers is not NULL
		ThrowExceptionIfPointerIsNULL( array, "WriteToStandardError failed - the given pointer is NULL" );

		// Loop unti the error message is exhausted
		for ( unsigned int arrayIndex = 0 ; arrayIndex < amountToWrite ; ++arrayIndex )
		{

			// Write the required character to standard error
			while ( -1 == write( 2, &array[ arrayIndex ], sizeof( T ) ) )
			{
				// Check the reason for the write operation failure. If an
				// interrupt is not the reason ( EINTR ) return the number
				// of successful writes
				RETURN_THE_GIVEN_NUMBER_IF_ERNNO_IS_NOT_SET_TO_EINTR( arrayIndex + 1 )
			}

		}

		// All the information was successfully written to standard error
		return ( 0 );
	}





}  //  namespace Universe


#endif  // STANDARDINPUTOUTPUTERROR_H
