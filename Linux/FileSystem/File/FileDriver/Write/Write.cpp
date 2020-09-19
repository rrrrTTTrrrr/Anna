#ifndef  WRITE_CPP
#define  WRITE_CPP



#include "WRITE.hpp"




// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../ErrorHandling/Assert/Assert.hpp"  //  Class Assert
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
        //      Use this method to write to the file
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. data - a pointer to the required data to write to disk
        //          2. startingOffset - this will be used to determine where to start reading
        //          3. dataSizeInBytes - the number of bytes to read from the file
        //
        //      Information returned to the user :
        //
        //          NONE        
        //
        //  Return value :
        //
        //          The number of bytes actually written to the file. There are  situations where the number of bytes written
        //          was smaller then the required but it is not consider as error. For example, the disk is full
        //
        //  Possible errors :
        //
        //      1. The file does not exist - class ErrnoException is thrown
        //      2. There is no more free memory space - class std::bad_alloc is thrown
        //      3. The object is in default state - class Exception is thrown
        //      4. 
        //
        UnsignedInteger64bits Set( const UnsignedInteger8bits* data, UnsignedInteger64bits startingOffset, UnsignedInteger64bits dataSizeInBytes ) throw()
        {
            // Set the offset of the file to the required location
            SetOffset( startingOffset );

            // Create an object to store the amount of bytes already written to the file
            UnsignedInteger64bits numberOfBytesWrittenToFile = 0;

            // Create an object to store the return status from the read system call
            UnsignedInteger64bits writeSystemCallReturnStatus = 0;

            // Loop until all the data was written
            while ( numberOfBytesWrittenToFile < dataSizeInBytes )
            {
                // Try to write the data from the file and store the number of bytes actually read in the call
                writeSystemCallReturnStatus = write( m_fileDescriptor, ( data + numberOfBytesWrittenToFile ), ( dataSizeInBytes - numberOfBytesWrittenToFile ) );

                // Check if the end of the file reached
                if ( writeSystemCallReturnStatus == 0 )
                {
                    // The file has ended, there are no more bytes to read
                    throw( ErrorHandling::Exception( 'Read::Get - read returned 0 check the fuck way, it can only be if a read that starts behind the end of the file was done' ) );
                }
                // Check if the call failed
                else if ( writeSystemCallReturnStatus == -1 )
                {
                    // Check the reason for the failure, and if it is not signal interrupt throw an exception
                    ErrorHandling::Assert< ErrnoException >::True( errno == EINTR, "Read::Get" );
                }
                else
                {
                    // Increment the number of bytes read from the file by the current amount read
                    numberOfBytesWrittenToFile += writeSystemCallReturnStatus;
                }

            }

            // Return the number of bytes actually written
            return ( numberOfBytesWrittenToFile );
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
    		void Write::Test() throw( std::bad_alloc, Exception )
    		{
    		}


    	)  //  End of debug tool











    }  //  Namespace FileSystem


}  //  Namespace Universe

#endif  //  WRITE_CPP





