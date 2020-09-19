#ifndef  ASCIISTRINGANDINTEGERS_CPP
#define  ASCIISTRINGANDINTEGERS_CPP


#include "AsciiStringAndIntegers.hpp"


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe 
{



	// Forward declarations :
	//
	//  NONE
	//



//	***************************************************************   PUBLIC METHODS IMPLEMENTATION - INTERFACE   ***************************************************************



	UnsignedInteger64bits AsciiStringAndIntegers::AsciiStringSize( const char* asciiString )
	{
		// Check if the given pointer is NULL
		if ( asciiString == 0UL )
		{
			// The given pointer is NULL 

			// Notify the user of the error
			return ( 0UL );
		}

	    // Create an object to store the length of the string
	    UnsignedInteger64bits asciiStringSize = 0UL;

	    // Loop until the error message is exhausted to find the size, use the error message size as index to the error message string
	    while ( *asciiString != 0UL )
	    {
	        // Increase the error message size by 1
	        asciiStringSize += 1UL;

	        // Check that the string size is not larger then 1 million
	        if ( asciiStringSize > 1000000UL )
	        {
	        	// The string might be without a null terminator

 				// Notify the user of the error
				return ( 0UL );   	
	        }

	        // Advance the pointer to the next entry
	        asciiString += 1UL;
	    }

	    // Return the size of the string
	    return ( asciiStringSize );
	}


	Boolean AsciiStringAndIntegers::CopyAsciiString( const char* sourceAsciiString, char* destinationAsciiString )
	{	
		// Check if any of the given pointers are NULL
		if ( ( sourceAsciiString == 0UL ) || ( destinationAsciiString == 0UL ) )
		{
			// At least of the given pointers is NULL 

			// Notify the user of the error
			return ( false );
		}

	    // Create an object to store the length of the string
	    UnsignedInteger64bits asciiStringSize = 0UL;

		// Loop on the source ascii string until the null terminator is encountered
		while ( *sourceAsciiString != 0UL )
		{
	        // Increase the error message size by 1
	        asciiStringSize += 1UL;

	        // Check that the string size is not larger then 1 million
	        if ( asciiStringSize > 1000000UL )
	        {
	        	// The string might be without a null terminator

 				// Notify the user of the error
				return ( false );   	
	        }

			// Copy the current ascii character from source to destination
			*destinationAsciiString = *sourceAsciiString;

			// Advance the pointers to the next location
			destinationAsciiString += 1UL;
			sourceAsciiString += 1UL;
		}

		// The method was successful
		return ( true );
	}



// *********************************************************************************   TESTING   ********************************************************************************



	DEBUG_TOOL(

		void AsciiStringAndIntegers::Test()
		{}

	)  //  End of debug tool



}  //  Namespace Universe


#endif  //  ASCIISTRINGANDINTEGERS_CPP





