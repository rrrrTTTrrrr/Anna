#ifndef  TCPSOCKETIPV6SERVER_HPP
#define  TCPSOCKETIPV6SERVER_HPP


#include <vector>  //  Class std::vector
#include <thread>  //  Class std::thread


#include "../TCPsocketIPv6/TCPsocketIPv6.hpp"  //  Class TCPsocketIPv6
#include "../Pollfd/Pollfd.hpp"  //  Class Pollfd
#include "../../ErrnoException/ErrnoException.hpp"  //  Class ErrnoException


namespace Network
{




    // Class Information :
    //
    //  Purpose :
    //
    //
    //
    //  Description :
    //
    //         
    //
    //  Possible errors :
    //
    //
    //
    class TCPsocketIPv6server : public TCPsocketIPv6
    {
    public:


        // The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler
        // generates a basic behavior for them :


        // Method Information :
        //
        //  Description :
        //
        //      Default Constructor, used to support move semantics
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
        inline TCPsocketIPv6server() throw();


        // Method Information :
        //
        //  Description :
        //
        //      Constructor,
        //
        //      Non explicit on purpose, to allow literals - > "10.0.0.1.8.9" to be implicitly converted to std::string
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. serverIPv6address - a string object containing the IP address for this server
        //          2. portNumber - the port that the server need to work with
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
        //      They will come
        //
        inline TCPsocketIPv6server( std::string serverIPv6address, int serverPortNumber, unsigned int flowInfo, unsigned int scopeID ) throw();


        // Method Information :
        //
        //  Description :
        //
        //      This method is used to swap the content between 2 instances of this object
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          firstObject - a reference to the first object to swap
        //          secondObject - a reference to the second object to swap
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
        inline void Swap( TCPsocketIPv6server& firstObject, TCPsocketIPv6server& secondObject ) throw();


        // Method Information :
        //
        //  Description :
        //
        //      Use this method is used to delete the resources of the instance
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
        virtual void Delete() throw();


        // Method Information :
        //
        //  Description :
        //
        //      Destructor, does not throw
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
        virtual inline ~TCPsocketIPv6server() throw();


        // To support Move semantics, the following 3 methods are added to every object. One method to set the object into the default state, another to check if the
        // object is in the default state, and the last method to delete all the object resources and set the object to default state :


        // Method Information :
        //
        //  Description :
        //
        //      Use to set the object into his default state. It does not delete the resources, if the method is used all the information inside will be lost and
        //      a memory leak will occuer
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
        virtual inline void SetToDefaultState() throw();


        // Method Information :
        //
        //  Description :
        //
        //      Use to check if the object is in default state
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
        //      1. true, if instance is at default state
        //      2. false, if instance is not at default state
        //
        //  Possible errors :
        //
        //      They will come
        //
        virtual inline bool DefaultState() const throw();


        // Method Information :
        //
        //  Description :
        //
        //      Use to delete the instance resources and set it to default state
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
        virtual inline void DeleteResourcesAndSetToDefaultState() throw();


        // The following methods are the interface of the object. This methods implement the capabilities of the object :


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
        //          2. portNumber - the port that the server need to work with
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
        inline void Initiate( std::string serverIPv6address, int serverPortNumber, unsigned int flowInfo, unsigned int scopeID ) throw( ErrorHandling::ErrnoException );


    private:


        // This vector will store the list of open connections
        std::vector< Pollfd > m_openConnections;

        // A standard thread object to initiate the poll and accept connections method
        std::thread m_pollAndAcceptConnections;

        // This object will be used to end the poll and accept connections thread
        bool m_keepRunning;


        // The following methods will be deleted to ensure that the socket instance is not copied or moved :

        // Delete the copy constructor
        TCPsocketIPv6server( const TCPsocketIPv6server& other ) = delete;

        // Delete the assignment operator
        TCPsocketIPv6server& operator=( const TCPsocketIPv6server& other ) = delete;

        // Delete the move constructor
        TCPsocketIPv6server( TCPsocketIPv6server&& other ) = delete;

        // Delete the move assignment operator
        TCPsocketIPv6server& operator=( TCPsocketIPv6server&& other ) = delete;


        // The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
        // rather help implement it :


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to bind a port number and IPv6 address in the socket
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
        //      1. The server did not respond - class ErrnoException is thrown
        //      2. 
        //
        inline void BindIMP() throw( ErrorHandling::ErrnoException );


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
        inline void ListenIMP() throw( ErrorHandling::ErrnoException );


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
        inline int AcceptIMP() throw( ErrorHandling::ErrnoException );


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
        inline void PollAndAcceptConnectionsIMP() throw( ErrorHandling::ErrnoException );


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
        std::vector< int > PollOpenConnectionsIMP() throw( ErrorHandling::ErrnoException );


    };  //  Class TCPsocketIPv6server








































//  *******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************















































    // Method Information :
    //
    //  Description :
    //
    //      Default Constructor, used to support move semantics
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
    inline TCPsocketIPv6server::TCPsocketIPv6server() throw() :
    TCPsocketIPv6(),
    m_pollAndAcceptConnections(),
    m_keepRunning( false )
    {}


    // Method Information :
    //
    //  Description :
    //
    //      Constructor,
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. serverIPv6address - a string object containing the IP address for this server
    //          2. portNumber - the port that the server need to work with
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
    //      They will come
    //
    inline TCPsocketIPv6server::TCPsocketIPv6server( std::string serverIPv6address, int serverPortNumber, unsigned int flowInfo, unsigned int scopeID ) throw() :
    TCPsocketIPv6(),
    m_pollAndAcceptConnections(),
    m_keepRunning( false )
    {
        // Initiate the socket
        Initiate( serverIPv6address, serverPortNumber, flowInfo, scopeID );
    }



    // Method Information :
    //
    //  Description :
    //
    //      This method is used to swap the content between 2 instances of this object
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          firstObject - a reference to the first object to swap
    //          secondObject - a reference to the second object to swap
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
    inline void TCPsocketIPv6server::Swap( TCPsocketIPv6server& firstObject, TCPsocketIPv6server& secondObject ) throw()
    {
        // Swap the open connections
        firstObject.m_openConnections.swap( secondObject.m_openConnections );

        // Swap the information associated with the running threads to pull and accept new connections
        firstObject.m_pollAndAcceptConnections.swap( secondObject.m_pollAndAcceptConnections );

        // Swap the keep running boolean
        std::swap( firstObject.m_keepRunning, secondObject.m_keepRunning );
    }

    
    // Method Information :
    //
    //  Description :
    //
    //      Destructor, does not throw
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
    inline TCPsocketIPv6server::~TCPsocketIPv6server() throw()
    {
        // Delete the resources
        Delete();
    }


    // Method Information :
    //
    //  Description :
    //
    //      Use to set the object into his default state. It does not delete the resources, if the method is used all the information inside will be lost and
    //      a memory leak will occuer
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
    inline void TCPsocketIPv6server::SetToDefaultState() throw()
    {
        // Create a default constructed instance
        TCPsocketIPv6server temporaryObject;

        // Swap between this instance and the temporary one
        Swap( *this, temporaryObject );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Use to check if the object is in default state
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
    //      1. true, if instance is at default state
    //      2. false, if instance is not at default state
    //
    //  Possible errors :
    //
    //      They will come
    //
    inline bool TCPsocketIPv6server::DefaultState() const throw()
    {

        // Check if the object is in default state
        if ( ( TCPsocketIPv6server::DefaultState() == true ) && 
             ( m_pollAndAcceptConnections.get_id() == std::thread().get_id() ) &&
             ( m_keepRunning == false ) )
        {
            // The object is in default state
            return ( true );
        }

        // The object is not in default state
        return ( false );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Use to delete the instance resources and set it to default state
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
    inline void TCPsocketIPv6server::DeleteResourcesAndSetToDefaultState() throw()
    {
        // Delete the resources
        Delete();

        // Set the object to default state
        SetToDefaultState();
    }










































//  ***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************











































    // Method Information :
    //
    //  Description :
    //
    //      Use this method to bind a port number and IPv6 address in the socket
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
    //      1. The server did not respond - class ErrnoException is thrown
    //      2. 
    //
    inline void TCPsocketIPv6server::BindIMP() throw( ErrorHandling::ErrnoException )
    {

        // Try to connect, the loop is used to restart trying to connect if a signal interrupted
        while ( connect( m_socketFileDescriptor, reinterpret_cast< struct sockaddr* >( &m_IPv6sockaddr ), sizeof( m_IPv6sockaddr ) ) == -1 )
        {

            // Check if it is not signal interrupt
            if ( errno != EINTR )
            {
                // The bind for IPv6 call failed
                throw( ErrorHandling::ErrnoException( "TCPsocketIPv6server::BindIMP - binding failed" ) );
            } 

        }

    }












}  //  Namespace Network





#endif  // TCPSOCKETIPV6SERVER_HPP