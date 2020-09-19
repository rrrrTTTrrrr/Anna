#ifndef  SYSTEMCALLS_CPP
#define  SYSTEMCALLS_CPP


#include "SystemCalls.hpp"


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe 
{

    namespace Linux
    {


		// Forward declarations :
		//
		//  NONE
		//




































//  ********************************************************************   STATIC FUNCTIONS IMPLEMENTATION   ********************************************************************




































//	********************************************************************   PRIVATE METHODS IMPLEMENTATION   *********************************************************************




































// *********************************************************************************   TESTING   ********************************************************************************




































		// DEBUG_TOOL(

			// Method Information :
			//
			//  Description :
			//
			//		This method is used to test the object. It is not part of the implementation, it is only used to find problem with the code that does implement
			//		the functionality
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			NONE
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		1. true - if the object passed the test
			//		2. false - otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		1. An assertion failed - class Exception or ErrnoException is thrown
			//		2. There is no more free memory space - class std::bad_alloc is thrown
			//		3. 
			//
			void SystemCalls::Test()
			{
				// Create a place to store the content from read
				SignedInteger8bits testCharacter_1 = 0;

				// Display to the user to enter a character
				std::cout << "Please enter a character :" << std::endl;

				// Read the input from the user
				Read( 0, &testCharacter_1, 1UL );

				// Write thank you to the user!!!!
				Write( 1UL, "Thank you for the character", 27UL );

				std::cout << std::endl;

				// Create a place to store the content from read
				SignedInteger8bits testString_1[20] = {0};

				// Create the file
				CreateFile( "/tmp/lllk.txt", S_IRWXU );

				// Open the file for read and write
				UnsignedInteger32bits fileDescriptor_1 = OpenFile( "/tmp/lllk.txt", O_RDWR );

				// Write the content read from the file
				Write( fileDescriptor_1, "sHizzbala12345678913", 20UL );

				SetReadAndWriteMarkerOffsetForFile( fileDescriptor_1, 0, SEEK_SET );

				// Read the input from the user
				Read( fileDescriptor_1, testString_1, 20UL );

				// Write the content read from the file
				Write( 1UL, testString_1, 20UL );

				std::cout << std::endl;

				// Close the file
				Close( fileDescriptor_1 );

				// Create a buffer to store the directory entry
				UnsignedInteger8bits directoryEntry[5000] = {0};

				// Open the file for read and write
				UnsignedInteger32bits directoryDescriptor_2 = OpenDirectory( "/home/rrrrtttrrrr/Anna/AnnaVersions/Anna_1094/Linux/SystemCalls/SystemCalls", O_RDONLY );

				// Read the directory entry
				UnsignedInteger64bits numberOfBytesRead = GetDirectoryEntry( directoryDescriptor_2, (linux_dirent64*)directoryEntry, 5000 );

				std::cout << numberOfBytesRead << std::endl;

				// Close the directory
				Close( directoryDescriptor_2 );
			}

		// )  //  End of debug tool











    }  //  Namespace Linux


}  //  Namespace Universe


#endif  //  SYSTEMCALLS_CPP





