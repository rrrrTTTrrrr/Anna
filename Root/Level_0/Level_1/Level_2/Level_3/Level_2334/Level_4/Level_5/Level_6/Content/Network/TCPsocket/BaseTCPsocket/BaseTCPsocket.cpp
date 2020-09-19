#ifndef  BASETCPSOCKET_CPP
#define  BASETCPSOCKET_CPP


#include "BaseTCPsocket.hpp"


#include <unistd.h>  //  Function read, Function write


namespace Network
{


	// Forward declarations :
	//
	//  NONE
	//

























//	***************************************************************   PUBLIC METHODS IMPLEMENTATION - INTERFACE   ***************************************************************




























    // Method Information :
    //
    //  Description :
    //
    //      Use this method to send data to the server
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. socketFileDescriptor - an open socket file descriptor 
    //          2. asciiString - the ascii string that needs to be sent to the server
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      The number bytes successfully sent
    //
    //  Possible errors :
    //
    //      1. The server did not respond - class ErrnoException is thrown
    //      2. 
    //
    ssize_t BaseTCPsocket::Send( int socketFileDescriptor, const std::string& asciiString ) throw( ErrorHandling::ErrnoException )
    {
        // This object will store the amount of bytes already written
        size_t amountOfBytesAlreadyWritten = 0;

        // Loop to restart the call in cases signal interrupted, or the current amount already read is smaller then count
        for ( ssize_t writeReturnStatus = 0 ; amountOfBytesAlreadyWritten < asciiString.size() ; amountOfBytesAlreadyWritten += writeReturnStatus )
        {
            // Try to write
            writeReturnStatus = write( socketFileDescriptor, asciiString.c_str(), asciiString.size() );

            // Check if the call failed
            if ( writeReturnStatus == -1 )
            {

                // Check if the write was interrupted by a signal
                if ( errno != EINTR )
                {
                    // No signal interrupted, throw an exception describing the problem
                    throw( ErrorHandling::ErrnoException( "BaseTCPsocket::Send - write call failed" ) );
                }

            }
            // Check if the return status is 0, which should not happen


        }

        // Return the amount of bytes written
        return ( amountOfBytesAlreadyWritten );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to receive data from the server
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          socketFileDescriptor - an open socket file descriptor 
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      A string object containning the data from the server
    //
    //  Possible errors :
    //
    //      1. The server did not respond - class ErrnoException is thrown
    //      2. 
    //
    std::string BaseTCPsocket::Receive( int socketFileDescriptor ) throw( ErrorHandling::ErrnoException )
    {
        // This object will store the information read from the connection
        char readData[1501] = {0};

        // This object will store the return status from the read call
        ssize_t readReturnStatus = 0;

        // Loop until all the required data was read
        for ( size_t amountOfBytesAlreadyRead = 0 ; amountOfBytesAlreadyRead < 1501 ; amountOfBytesAlreadyRead += readReturnStatus )
        {
            // Try to read the data from the connection to the buffer
            readReturnStatus = read( socketFileDescriptor, readData, ( sizeof( readData ) - amountOfBytesAlreadyRead ) );

            // Check if the read call failed
            if ( readReturnStatus == -1 )
            {
                // The read call failed

                // Check if the reason is not signal interrupt then 
                if ( errno != EINTR )
                {
                    // No signal interrupted
                    
                    // Throw an exception describing the problem
                    throw( ErrorHandling::ErrnoException( "BaseTCPsocket::Receive - read call failed" ) );
                }

            }
            // Check if the reading reached the "end" of file
            else if ( readReturnStatus == 0 )
            {
                // There is no more data to read, break the loop
                break;
            }

        }

        // Return the data
        return ( std::move( std::string( readData ) ) );
    }













}  //  Namespace Network


#endif  //  BASETCPSOCKET_CPP





