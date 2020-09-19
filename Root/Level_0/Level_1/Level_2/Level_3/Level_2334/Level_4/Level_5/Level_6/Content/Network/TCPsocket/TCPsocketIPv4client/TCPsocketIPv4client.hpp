#ifndef  TCPSOCKETIPV4CLIENT_HPP
#define  TCPSOCKETIPV4CLIENT_HPP


#include "../TCPsocketIPv4/TCPsocketIPv4.hpp"  //  Class TCPsocketIPv4


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
	class TCPsocketIPv4client : public TCPsocketIPv4
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
		inline TCPsocketIPv4client() throw();


		// Method Information :
		//
		//  Description :
		//
		//   	Constructor,
        //
        //      Non explicit on purpose, to allow literals - > "10.0.0.1" to be implicitly converted to std::string
		//
		//  Required arguments :
		//
    	//		User information needed :
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
		//   	NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline TCPsocketIPv4client( std::string serverIPv4address, int serverPortNumber ) throw();


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
		virtual inline ~TCPsocketIPv4client() throw() = default;


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
        //          1. serverIPaddress - a string object containing the IP address for this server
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
        inline void Initiate( std::string serverIPaddress, int serverPortNumber ) throw( ErrorHandling::ErrnoException );


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
        void ConnectIMP() throw( ErrorHandling::ErrnoException );


	};  //  Class TCPsocketIPv4client








































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
	inline TCPsocketIPv4client::TCPsocketIPv4client() throw() :
    TCPsocketIPv4()
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
    //          1. serverIPv4address - a string object containing the IP address for this server
    //          2. serverPortNumber - the port that the server need to work with
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
	inline TCPsocketIPv4client::TCPsocketIPv4client( std::string serverIPv4address, int serverPortNumber ) throw() :
    TCPsocketIPv4( serverIPv4address, serverPortNumber )
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
    //          1. serverIPaddress - a string object containing the IP address for this server
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
    inline void TCPsocketIPv4client::Initiate( std::string serverIPaddress, int serverPortNumber ) throw( ErrorHandling::ErrnoException )
    {
        // Call the base object initiate method
        TCPsocketIPv4::Initiate( serverIPaddress, serverPortNumber );

        // Connect to server
        ConnectIMP();
    }







































//  ***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************







































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
    void TCPsocketIPv4client::ConnectIMP() throw( ErrorHandling::ErrnoException )
    {

        // Try to connect, the loop is used to restart trying to connect if a signal interrupted
        while ( connect( m_socketFileDescriptor, ( struct sockaddr* )&m_IPv4sockaddr, sizeof( m_IPv4sockaddr ) ) == -1 )
        {

            // Check if it is not signal interrupt
            if ( errno != EINTR )
            {
                // The connect for IPv4 call failed
                throw( ErrorHandling::ErrnoException( "TCPsocketIPv4client::Connect - connection failed" ) );
            } 

        }

    }
















}  //  Namespace Network





#endif  // TCPSOCKETIPV4CLIENT_HPP