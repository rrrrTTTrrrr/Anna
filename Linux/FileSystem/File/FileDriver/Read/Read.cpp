#ifndef  READ_CPP
#define  READ_CPP

#include "Read.hpp"


#include "../../../../ErrorHandling/Assert/Assert.hpp"  //  Class Assert


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe 
{

    namespace FileSystem
    {


    	// Forward declarations :
    	//
    	//  NONE
    	//



















//	********************************************************   PUBLIC METHODS IMPLEMENTATION - INTERFACE   ****************************************************























        // Method Information :
        //
        //  Description :
        //
        //      Use this method to read from the file
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. startingOffset - this will be used to determine where to start reading
        //          2. numberOfBytesToReadFromFile - the number of bytes to read from the file
        //
        //      Information returned to the user :
        //
        //          numberOfBytesActuallyRead - a reference to an object to store the actual number of bytes read. There are
        //          situations where the number of bytes read was smaller then the required but it is not consider as error.
        //          For example, if the end of the file reached or a signal interrupted the call        
        //
        //  Return value :
        //
        //      The address of the uploaded file
        //
        //  Possible errors :
        //
        //      1. The file does not exist - class ErrnoException is thrown
        //      2. There is no more free memory space - class std::bad_alloc is thrown
        //      3. The object is in default state - class Exception is thrown
        //      4. 
        //
        UnsignedInteger8bits* Get( UnsignedInteger64bits startingOffset, UnsignedInteger64bits numberOfBytesToReadFromFile, UnsignedInteger64bits& numberOfBytesActuallyRead ) throw()
        {
            // Set the offset of the file to the required location
            SetOffset( startingOffset );
            
            // Allocate memory space to contain the file contents. An exception safe pointer is used, becasue if
            // an exception is thrown the resource will not be released, and it will not release the resource
            // when goes out of scope        
            ExceptionSafePointer< UnsignedInteger8bits > file( new UnsignedInteger8bits[ numberOfBytesToReadFromFile ], ExceptionSafePointer< UnsignedInteger8bits >::ARRAY_OF_OBJECTS );

            // Create an object to store the return status from the read system call
            UnsignedInteger64bits readSystemCallReturnStatus = 0;

            // Loop until all the bytes of the file are in main memory
            while ( numberOfBytesActuallyRead < numberOfBytesToReadFromFile )
            {
                // Try to read the data from the file and store the number of bytes actually read in the call
                readSystemCallReturnStatus = read( m_fileDescriptor, ( file + numberOfBytesActuallyRead ), ( numberOfBytesToReadFromFile - numberOfBytesActuallyRead ) );

                // Check if the end of the file reached
                if ( readSystemCallReturnStatus == 0 )
                {
                    // The file has ended, there are no more bytes to read
                    throw( ErrorHandling::Exception( 'Read::Get - read returned 0 check the fuck way, it can only be if a read that starts behind the end of the file was done' ) );
                }
                // Check if the call failed
                else if ( readSystemCallReturnStatus == -1 )
                {
                    // Check the reason for the failure, and if it is not signal interrupt throw an exception
                    ErrorHandling::Assert< ErrnoException >::True( errno == EINTR, "Read::Get" );
                }

                // Increment the number of bytes read from the file by the current amount read
                numberOfBytesActuallyRead += readSystemCallReturnStatus;
            }

            // Return an handle to the file
            return ( file.GetResource() );
        }























//  ***************************************************************************   OPERATORS IMPLEMENTATION   ********************************************************************











//  ************************************************************************   STATIC FUNCTIONS IMPLEMENTATION   ****************************************************************











//	*************************************************************************   PRIVATE METHODS IMPLEMENTATION   ****************************************************************








// **************************************************************   NESTED CLASS PRIVATE METHODS IMPLEMENTATION -    ************************************************************











// *************************************************************************   FRIEND FUNCTIONS IMPLEMENTATION   ****************************************************************












    	// This functions are declared outside the class scope, to enable the class to be the right side operand. This can not be for a method
    	// within the class. When a method or operator of a class is used, the object the operator or method belongs to must be known, in order
    	// to set the implicit this pointer to the method. Therefore the class must be presented first which means to be the left side operand,
    	// this functions are needed to avoid just that








// **************************************************************************************   TESTING   ***************************************************************************






















    	// All the following methods will be added only in test mode, they are not part of the implementation, their purpose is to
    	// help locate problems in the code


    	DEBUG_TOOL(


    		// Method Information :
    		//
    		//  Description :
    		//
    		//      This method is used to test the object
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
    		//      1. true - if the object passed the test
    		//      2. false - otherwise
    		//
    		//  Possible errors :
    		//
    		//      1. A method does not work correctly - class Exception is thrown
    		//		2. There is no more free memory space - class std::bad_alloc is thrown
    		//		3. 
    		//
    		void Read::Test() throw( std::bad_alloc, Exception )
    		{
    		}


    	)  //  End of debug tool











    }  //  Namespace FileSystem


}  //  Namespace Universe

#endif  //  READ_CPP





