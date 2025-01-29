#ifndef  TCPSOCKETIPV4_HPP
#define  TCPSOCKETIPV4_HPP


#include <sys/socket.h>  //  Function socket
#include <unistd.h>  //  Function close
#include <string>  //  Class std::string


#include "../../ErrnoException/ErrnoException.hpp"  //  Class ErrnoException
#include "../SocketAddressIPv4/SocketAddressIPv4.hpp"  //  Class SocketAddressIPv4
#include "../BaseTCPsocket/BaseTCPsocket.hpp"  //  Class BaseTCPsocket


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
    //       1. The flow is :
    //
    //          1. Create a socket  ->  int socket( int domain, int type, int protocol )
    //          2. Bind the socket to an IP address ( 4 or 6 )  ->  int bind( int sockfd, const struct sockaddr *addr, socklen_t addrlen )
    //          3. Now other sockets can connect  ->  int connect( int sockfd, const struct sockaddr *addr, socklen_t addrlen )
    //          4. A willingness to accept incoming connections and a queue limit for incoming connections  ->  int listen( int sockfd, int backlog )
    //          5. Accept connection  ->  int accept( int sockfd, struct sockaddr *addr, socklen_t *addrlen )
	//
	//  Possible errors :
	//
	//
	//
	class TCPsocketIPv4  : public BaseTCPsocket
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
		inline TCPsocketIPv4() throw();


        // Method Information :
        //
        //  Description :
        //
        //      Constructor,
        //
        //      Non explicit on purpose, to allow literals - > "10.0.0.1" to be implicitly converted to std::string
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
        //      They will come
        //
        inline TCPsocketIPv4( std::string serverIPv4address, int serverPortNumber ) throw( ErrorHandling::ErrnoException ); 


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
		virtual inline void Delete() throw();


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
		virtual inline ~TCPsocketIPv4() throw();


		// To support Move semantics, the following 3 methods are added to every object. One method to set the object into the default state, another to check if the
		// object is in the default state, and the last method to delete all the object resources and set the object to default state :


		// Method Information :
		//
		//  Description :
		//
    	//      Use to set the object into his default state. It does not delete the resources, if the method is used all the information inside will be lost and
		//		a memory leak will occuer
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
		//	    They will come
		//
		virtual inline void SetToDefaultState() throw();


		// Method Information :
		//
		//  Description :
		//
		//   	Use to check if the object is in default state
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
		//      1. true, if instance is at default state
		//      2. false, if instance is not at default state
		//
		//  Possible errors :
		//
		//		They will come
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
        void Initiate( std::string serverIPv4address, int serverPortNumber ) throw( ErrorHandling::ErrnoException );


    protected:


        // The protected part is used for inheritance. This means that only this object and the objects that will inherit from it can use the protected data
        // members or methods


        // This object will store the socket file descriptor
        int m_socketFileDescriptor;

        // For IPv4
        SocketAddressIPv4 m_IPv4sockaddr;


	private:


        // The following methods will be deleted to ensure that the socket instance is not copied or moved :

        // Delete the copy constructor
        TCPsocketIPv4( const TCPsocketIPv4& other ) = delete;

        // Delete the assignment operator
        TCPsocketIPv4& operator=( const TCPsocketIPv4& other ) = delete;

        // Delete the move constructor
        TCPsocketIPv4( TCPsocketIPv4&& other ) = delete;

        // Delete the move assignment operator
        TCPsocketIPv4& operator=( TCPsocketIPv4&& other ) = delete;


	};  //  Class TCPsocketIPv4
















































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
	inline TCPsocketIPv4::TCPsocketIPv4() throw() :
    m_socketFileDescriptor( -1 ),
    m_IPv4sockaddr()
	{}


    // Method Information :
    //
    //  Description :
    //
    //      Constructor,
    //
    //      Non explicit on purpose, to allow literals - > "10.0.0.1" to be implicitly converted to std::string
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
    //      They will come
    //
    inline TCPsocketIPv4::TCPsocketIPv4( std::string serverIPv4address, int serverPortNumber ) throw( ErrorHandling::ErrnoException ) :
    TCPsocketIPv4()
    {
        // Initiate the socket
        Initiate( serverIPv4address, serverPortNumber );  
    }

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
	void TCPsocketIPv4::Delete() throw()
	{
		// Close the socket 
		close( m_socketFileDescriptor );
	}


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
	inline TCPsocketIPv4::~TCPsocketIPv4() throw()
	{
        // Close the socket 
        close( m_socketFileDescriptor );
	}


	// Method Information :
	//
	//  Description :
	//
	//      Use to set the object into his default state. It does not delete the resources, if the method is used all the information inside will be lost and
	//		a memory leak will occuer
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
	//	    They will come
	//
	inline void TCPsocketIPv4::SetToDefaultState() throw()
	{
        // Set the file descriptor to -1
        m_socketFileDescriptor = -1;

        // Set the socket address instance to default state
        m_IPv4sockaddr.SetToDefaultState();
	}


	// Method Information :
	//
	//  Description :
	//
	//   	Use to check if the object is in default state
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
	//      1. true, if instance is at default state
	//      2. false, if instance is not at default state
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline bool TCPsocketIPv4::DefaultState() const throw()
	{

		// Check if the object is in default state
		if ( ( m_socketFileDescriptor == -1 ) &&
			 ( m_IPv4sockaddr.DefaultState() == true ) )
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
	inline void TCPsocketIPv4::DeleteResourcesAndSetToDefaultState() throw()
	{
        // Close the socket 
        close( m_socketFileDescriptor );

		// Set the object to default state
		SetToDefaultState();
	}




















}  //  Namespace Network




#endif  // TCPSOCKETIPV4_HPP