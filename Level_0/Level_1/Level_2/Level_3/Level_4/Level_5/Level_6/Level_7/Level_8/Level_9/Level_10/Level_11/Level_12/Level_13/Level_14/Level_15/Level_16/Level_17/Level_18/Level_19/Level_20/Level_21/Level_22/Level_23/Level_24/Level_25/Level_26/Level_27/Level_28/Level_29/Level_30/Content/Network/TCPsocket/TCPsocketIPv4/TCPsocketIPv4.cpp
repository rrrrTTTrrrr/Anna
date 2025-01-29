#ifndef  TCPSOCKETIPV4_CPP
#define  TCPSOCKETIPV4_CPP


#include "TCPsocketIPv4.hpp"



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
    //      Use this method to initate the socket
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. serverIPaddress - a string object containing the IP address for this server
    //          2. portNumber - the port that the server need to work with
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      1. The server did not respond - class ErrnoException is thrown
    //      2. 
    //
    void TCPsocketIPv4::Initiate( std::string serverIPv4address, int portNumber ) throw( ErrnoException )
    {
        // Try to open the socket
        m_socketFileDescriptor = socket( AF_INET, SOCK_STREAM, 0 );

        // Check if the creatin of the end point for communication failed
        if ( m_socketFileDescriptor == -1 )
        {
            // The creation failed, throw an exception describing the problem
            throw( ErrnoException( "TCPsocketIPv4::Initiate - failed to create the socket" ) );
        }

        // Set new socket address
        m_IPv4sockaddr.SetNewSocketAddressIPv4( serverIPaddress, portNumber );
    }






















}  //  Namespace Universe


#endif  //  TCPSOCKETIPV4_CPP





