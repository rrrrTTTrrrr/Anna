#ifndef  TCPSOCKETIPV6_CPP
#define  TCPSOCKETIPV6_CPP


#include "TCPsocketIPv6.hpp"



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
    //          1. serverIPv6address - a string object containing the IP address for this server
    //          2. serverPortNumber - the port that the server need to work with
    //          3. flowInfo - flow information
    //          4. scopeID - an ID depending on the scope of the address
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
    void TCPsocketIPv6::Initiate( std::string serverIPv6address, int serverPortNumber, unsigned int flowInfo, unsigned int scopeID ) throw( ErrnoException )
    {
        // Try to open the socket
        m_socketFileDescriptor = socket( domain, SOCK_STREAM, 0 );

        // Check if the creatin of the end point for communication failed
        if ( m_socketFileDescriptor == -1 )
        {
            // The creation failed, throw an exception describing the problem
            throw( ErrnoException( "TCPserver::constructor - failed to create the socket" ) );
        }

        // Set new socket address
        m_IPv6sockaddr.SetNewSocketAddressIPv6( serverIPv6address, serverPortNumber, flowInfo, scopeID );
    }















}  //  Namespace Universe


#endif  //  TCPSOCKETIPV6_CPP





