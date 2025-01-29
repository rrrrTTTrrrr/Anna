#ifndef  TCPSOCKETIPV4SERVER_CPP
#define  TCPSOCKETIPV4SERVER_CPP


#include "TCPsocketIPv4server.hpp"


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
    //      Use his method is used to delete the resources of the instance
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
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    void TCPsocketIPv4server::Delete() throw()
    {

        // Check that the instance is not in default state
        if ( DefaultState() == true )
        {
            // Nothing needs to be done
            return;
        }

        // Set the keep running boolean to false
        m_keepRunning = false;

        // Wait for the poll and accept connections thread to end
        m_pollAndAcceptConnections.join();

        // Call the base delete 
        TCPsocketIPv4::Delete();

        // Clear the open connections
        m_openConnections.clear();
    }


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
    //          1. serverIPv4address - a string object containing the IP address for this server
    //          2. serverPortNumber - the port that the server need to work with
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
    void TCPsocketIPv4server::Initiate( std::string serverIPv4address, int serverPortNumber ) throw( ErrorHandling::ErrnoException )
    {
        // Set the keep running boolean to true
        m_keepRunning = true;

        // Call the base object initiate method
        TCPsocketIPv4::Initiate( serverIPv4address, serverPortNumber );

        // Bind the port number and the IPv4 address in the socket
        BindIMP();

        // Set the socket to accept connections
        ListenIMP();

        // Create a thread of execution that will be responsible for polling and accepting connections, and associate it with the standard thread instance inside
        m_pollAndAcceptConnections = std::thread( &TCPsocketIPv4server::PollAndAcceptConnectionsIMP, this );
    }










































//	********************************************************************   PRIVATE METHODS IMPLEMENTATION   *********************************************************************













































    // Method Information :
    //
    //  Description :
    //
    //      Use this method to set the socket to be willing to accept connections
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
    //      NONE
    //
    //  Possible errors :
    //
    //      1. The listen call failed - Class ErrnoException is thrown
    //      2.
    //
    inline void TCPsocketIPv4server::ListenIMP() throw( ErrorHandling::ErrnoException )
    {

        // Set the socket to accept connections
        if ( listen( m_socketFileDescriptor, -1 ) == 0 )
        {
            // The listen call failed
            throw( ErrorHandling::ErrnoException( "TCPsocketIPv4server::ListenIMP - the listen call failed" ) );
        }

    }


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to accept new connections
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
    //      NONE
    //
    //  Possible errors :
    //
    //      1. The accept call failed - Class ErrnoException is thrown
    //      2.
    //
    inline int TCPsocketIPv4server::AcceptIMP() throw( ErrorHandling::ErrnoException )
    {
        // A new connection waiting

        // This object will store the new connection file descriptor
        int newConnection = 0;

        // This object will store the length of the IPv4 socket address structure
        unsigned int structureLength = sizeof( m_IPv4sockaddr );

        // Accept the connection
        newConnection = accept( m_socketFileDescriptor, reinterpret_cast< struct sockaddr* >( &m_IPv4sockaddr ), &structureLength );

        // Check the accept return status
        if ( newConnection == -1 )
        {
            // The accept call failed, throw an exception describing the problem
            throw( ErrorHandling::ErrnoException( "TCPsocketIPv4server::ListenIMP - the accept call failed" ) );
        }

        // Now that a connection has been established, add it to the open connection queue
        m_openConnections.push_back( std::move( Pollfd( newConnection, POLLIN ) ) );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to listen for new connections and add them to the queue of open connections
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
    //      NONE
    //
    //  Possible errors :
    //
    //      1. Deleting the object resources failed
    //      2.
    //
    inline void TCPsocketIPv4server::PollAndAcceptConnectionsIMP() throw( ErrorHandling::ErrnoException )
    {
        // This object will store the information on the socket to poll 
        Pollfd pollfd( m_socketFileDescriptor, POLLIN );

        // This object will store the poll call return status
        int pollReturnStatus = 0;

        // Loop as long as the server is up
        while ( m_keepRunning == true )
        {
            // Try to poll, and set the timeout to half of a second
            pollReturnStatus = poll( pollfd, 1, 500 );

            // Check if the keep running boolean is false
            if ( m_keepRunning == false )
            {
                // Stop running
                return;
            }

            // Check if the poll call failed
            if ( pollReturnStatus == -1 )
            {

                // Check if the reason the call failed was signal interrupt
                if ( errno != EINTR )
                {
                    // The poll call failed, thrown an exception describing the error
                    throw( ErrorHandling::ErrnoException( "TCPsocketIPv4server::PollAndDispatchIMP - the poll call failed" ) );
                }

            }
            else
            {
                // A new connection is waiting, accept it
                AcceptIMP();
            }

        }
    
    }


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to poll on the open connections, and return all the connections that has data to be processed
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
    //      A vector containing all the connections that need attention
    //
    //  Possible errors :
    //
    //      1. The poll call failed - Class ErrnoException is thrown
    //      2.
    //
    std::vector< int > TCPsocketIPv4server::PollOpenConnectionsIMP() throw( ErrorHandling::ErrnoException )
    {
        // This object will store the connections that need attention
        std::vector< int > connectionsRequireAttention;

        // This object will store the poll call return status   
        int pollReturnStatus = 0;

        // Loop as long as the server is up
        while ( m_keepRunning == true )
        {
            // Try to poll, and set the timeout to half of a second
            pollReturnStatus = poll( reinterpret_cast< struct pollfd* >( m_openConnections.data() ), m_openConnections.size(), 500 );

            // Check if the poll call failed
            if ( pollReturnStatus == -1 )
            {

                // Check if the reason the call failed was signal interrupt
                if ( errno != EINTR )
                {
                    // The poll call failed, thrown an exception describing the error
                    throw( ErrorHandling::ErrnoException( "TCPsocketIPv4server::PollOpenConnectionsIMP - the poll call failed" ) );
                }

            }

        }

        // Open connections require attention                

        // This object will be used to count the connections that were dealt with
        int numberOfConnectionsFinished = 0;

        // Loop on the open connections to check which required attention
        for ( unsigned long openConnectionsIndex = 0 ; openConnectionsIndex < m_openConnections.size() ; ++openConnectionsIndex )
        {

            // Check if the current connection has data that needs to be read
            if ( ( m_openConnections[ openConnectionsIndex ].GetReturnedEvents() & POLLIN ) == true )
            {
                // The current connection has data to process

                // Push the current connection to the queue
                connectionsRequireAttention.push_back( openConnectionsIndex );

                // Increase the number of connections that were dealt with by 1
                numberOfConnectionsFinished += 1;
            }
            // Check if the current connection is still valid
            else if ( ( m_openConnections[ openConnectionsIndex ].GetReturnedEvents() & POLLHUP ) == true )
            {
                // The connection was lost

                // Swap between the last connection and the connection that hung up in the array, this way no copying of the all higher part of the array one step
                // down is needed. This is possible because the order does not matter in the array
                Pollfd::Swap( m_openConnections[ openConnectionsIndex ], m_openConnections[ m_openConnections.size() - 1 ] );

                // Pop the last element
                m_openConnections.pop_back();

                // Increase the number of connections that were dealt with by 1
                numberOfConnectionsFinished += 1;
            }
            // Check if the current connection had error
            else if ( ( ( m_openConnections[ openConnectionsIndex ].GetReturnedEvents() & POLLERR ) == true ) && ( ( m_openConnections[ openConnectionsIndex ].GetReturnedEvents() & POLLNVAL ) == true ) )
            {
                // The connection has error
                throw( ErrorHandling::ErrnoException( "TCPsocketIPv4server::PollOpenConnectionsIMP - the connection had error" ) );
            }

        }

        // Check that all the connections were dealt with
        if ( pollReturnStatus != numberOfConnectionsFinished )
        {
            // The poll call returned a different number of connections then the number of connections that were dealt
            throw( ErrorHandling::ErrnoException( "TCPsocketIPv4server::PollOpenConnectionsIMP - the connection had error" ) );
        }

        // Return the open connections that has data to be proccessed
        return ( std::move( connectionsRequireAttention ) );
    }

















}  //  Namespace Network




#endif  //  TCPSOCKETIPV4SERVER_CPP





