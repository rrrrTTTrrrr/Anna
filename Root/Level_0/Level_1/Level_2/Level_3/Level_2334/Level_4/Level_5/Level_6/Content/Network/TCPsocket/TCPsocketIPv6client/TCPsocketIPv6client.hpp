#ifndef  TCPSOCKETIPV6CLIENT_HPP
#define  TCPSOCKETIPV6CLIENT_HPP


#include "../TCPsocketIPv6/TCPsocketIPv6.hpp"  //  Class TCPsocketIPv6


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
	class TCPsocketIPv6client : public TCPsocketIPv6
	{
	public:


        // The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler
        // generates a basic behavior for them :


        // Method Information :
	    //
	    //  Description :
        //
		//   	Default Constructor, used to support move semantics
		//
		//  Required arguments :
		//
		//   	User information needed :
		//
    	//          NONE
		//
		//      Information returned to the user :
		//
		//          NONE
    	//
    	//  Return value :
		//
		//   	NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline TCPsocketIPv6client() throw();


		// Method Information :
		//
		//  Description :
		//
		//   	Constructor,
		//
		//  Required arguments :
		//
		//		User information needed :
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
		//   	NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline TCPsocketIPv6client( std::string serverIPv6address, int serverPortNumber, unsigned int flowInfo, unsigned int scopeID ) throw( ErrorHandling::ErrnoException );


		// Method Information :
		//
		//  Description :
		//
		//   	Destructor, does not throw
		//
		//  Required arguments :
		//
		//   	User information needed :
		//
		//          NONE
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		virtual inline ~TCPsocketIPv6client() throw() = default;


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
	    inline void Initiate( std::string serverIPv6address, int serverPortNumber, unsigned int flowInfo, unsigned int scopeID ) throw( ErrorHandling::ErrnoException );


    private:


        // The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
        // rather help implement it :


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to connect a client to server
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
        //      A string object containning the data from the server
        //
        //  Possible errors :
        //
        //      1. The server did not respond - class ErrnoException is thrown
        //      2. 
        //
        inline void ConnectIMP() throw( ErrorHandling::ErrnoException );


	};  //  Class TCPsocketIPv6client








































//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************















































	// Method Information :
	//
	//  Description :
	//
	//   	Default Constructor, used to support move semantics
	//
	//  Required arguments :
	//
	//   	User information needed :
	//
	//          NONE
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//   	NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline TCPsocketIPv6client::TCPsocketIPv6client() throw() :
    TCPsocketIPv6()
	{}


	// Method Information :
	//
	//  Description :
	//
	//   	Constructor,
	//
	//  Required arguments :
	//
	//		User information needed :
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
	//   	NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline TCPsocketIPv6client::TCPsocketIPv6client( std::string serverIPv6address, int serverPortNumber, unsigned int flowInfo, unsigned int scopeID ) throw( ErrorHandling::ErrnoException ) :
    TCPsocketIPv6( serverIPv6address, serverPortNumber, flowInfo, scopeID )
	{
        // Connect to server
        ConnectIMP();
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
    inline void TCPsocketIPv6client::Initiate( std::string serverIPv6address, int serverPortNumber, unsigned int flowInfo, unsigned int scopeID ) throw( ErrorHandling::ErrnoException )
    {
        // Call the base object initiate method
        TCPsocketIPv6::Initiate( serverIPv6address, serverPortNumber, flowInfo, scopeID );

        // Connect to server
        ConnectIMP();
    }













































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************









































    // Method Information :
    //
    //  Description :
    //
    //      Use this method to connect a client to server
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
    inline void TCPsocketIPv6client::ConnectIMP() throw( ErrorHandling::ErrnoException )
    {

        // Try to connect, the loop is used to restart trying to connect if a signal interrupted
        while ( connect( m_socketFileDescriptor, ( struct sockaddr* )&m_IPv6sockaddr, sizeof( m_IPv6sockaddr ) ) == -1 )
        {

            // Check if it is not signal interrupt
            if ( errno != EINTR )
            {
                // The connect for IPv6 call failed
                throw( ErrorHandling::ErrnoException( "TCPsocketIPv6client::Connect - connection failed" ) );
            } 

        }
            
    }







}  //  Namespace Network





#endif  // TCPSOCKETIPV6CLIENT_HPP