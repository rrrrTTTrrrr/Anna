#ifndef  STANDARDINPUTOUTPUTERROR_CPP
#define  STANDARDINPUTOUTPUTERROR_CPP



#include "StandardInputOutputError.h"



namespace Universe
{



//	************************************   PUBLIC FUNCTIONS IMPLEMENTATION - INTERFACE   ************************************







	// Usually template function definitions must be present in the same source file ( the header file ).  The special case
	// is when creating a spciealized template function, which must be moved to the cpp file to prevent multiple definitons


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
	SignedInteger64bits ReadFromStandardInputTheRequiredAmount< char >( char* asciiCharacterArray, UnsignedInteger64bits amountToRead )
	{
		// Check that the given pointer to the array is not NULL
		ThrowExceptionIfPointerIsNULL( asciiCharacterArray, "ReadFromStandardInput character version failed - the given pointer is NULL" );

		// Check that the amount to read is not 0
		ThrowExceptionIfValueOneIsEqualToValueTwo< UnsignedInteger64bits >( amountToRead, 0, "ReadFromStandardInput character version failed - the amount to read is 0" );

		// Create an object to store the return value from the read system call
		SignedInteger64bits returnValueFromRead = 0;

		// Read until the return value is not -1
		while ( -1 == ( returnValueFromRead = read( 0, asciiCharacterArray, ( sizeof( char ) * amountToRead ) ) ) )
		{
			// Check the reason for the read operation failure. If the reason is not
			// signal interrupt, return error
			RETURN_THE_GIVEN_NUMBER_IF_ERNNO_IS_NOT_SET_TO_EINTR( -1 )
		}

		// Set the entry after the last ascii character to NULL terminator
		asciiCharacterArray[ returnValueFromRead ] = 0;

		// Return the amount of read by the system call. If the value is 0 the end of file reached
		return ( returnValueFromRead );
	}


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
	SignedInteger64bits* ReadArrayOfArraysFromStandardInput< char >( char** arrayOfPointers, UnsignedInteger64bits numberOfPointers, UnsignedInteger64bits numberOfEntriesForEveryPointer )
	{
		// Check that the given pointer to the array of pointers is not NULL
		ThrowExceptionIfPointerIsNULL( arrayOfPointers, "ReadArrayOfArraysFromStandardInput character version failed - the given pointer is NULL" );

		// Check that the number of pointers is not 0
		ThrowExceptionIfValueOneIsEqualToValueTwo< UnsignedInteger64bits >( numberOfPointers, 0, "ReadArrayOfArraysFromStandardInput character version failed - the number of pointers is 0" );

		// Check that the number of entries for each pointer is not 0
		ThrowExceptionIfValueOneIsEqualToValueTwo< UnsignedInteger64bits >( numberOfEntriesForEveryPointer, 0, "ReadArrayOfArraysFromStandardInput character version failed - the number of entries for each pointer is 0" );

		// Create an object to store address of the array that the information from the read will be stored
		SignedInteger64bits* amountOfSuccessfulReads = new SignedInteger64bits[2];

		// Loop on rows of buffer
		for ( UnsignedInteger64bits arrayOfPointersIndex  = 0 ; arrayOfPointersIndex < numberOfPointers ; ++arrayOfPointersIndex )
		{

			// Loop on columns of buffer
			for ( UnsignedInteger64bits arrayIndex  = 0 ; arrayIndex < numberOfEntriesForEveryPointer ; ++arrayIndex )
			{

				// Read until the return value is not -1
				while ( -1 == read( 0, &arrayOfPointers[ arrayOfPointersIndex ][ arrayIndex ], sizeof( char ) ) )
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
						amountOfSuccessfulReads[1] = ( arrayIndex  + 1 );

						// Return the read information
						return ( amountOfSuccessfulReads );
					}

				}

			}

			// Set the end of current ascii characters array to the NULL terminator
			arrayOfPointers[ numberOfEntriesForEveryPointer ] = 0;
		}

		// Set the amount of successful reads entries to 0, to notify that all the
		// required information arrived
		amountOfSuccessfulReads[0] = 0;
		amountOfSuccessfulReads[1] = 0;

		// Return the read information
		return ( amountOfSuccessfulReads );
	}




}  //  namespace Universe




#endif  //  STANDARDINPUTOUTPUTERROR_CPP