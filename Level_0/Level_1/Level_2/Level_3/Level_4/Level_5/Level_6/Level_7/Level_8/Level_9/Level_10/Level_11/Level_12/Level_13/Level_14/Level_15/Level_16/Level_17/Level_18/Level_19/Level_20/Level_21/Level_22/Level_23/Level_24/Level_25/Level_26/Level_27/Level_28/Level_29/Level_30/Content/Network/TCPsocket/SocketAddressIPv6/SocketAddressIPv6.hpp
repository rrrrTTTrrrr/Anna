#ifndef  SOCKETADDRESSIPv6_HPP
#define  SOCKETADDRESSIPv6_HPP


#include <netinet/in.h>  //  Structure sockaddr_in6
#include <string>  //  Class std::string
#include <cstring>  //  Function memcpy, Function bzero
#include <arpa/inet.h>  //  Function inet_pton


namespace Network
{


	// This is used when only declaring the object in this source file will be enough to pass compilation. The implementation is given to the compiler through the
	// cpp source file that the object is nested within
	//
	// Forward declarations :
	//
	//  NONE
	//


	// Give proper treatment, by dealing with big and little endian encoding systems where it is required. The big or little endian encoding appear when dealing
	// with byte order in memory. In the byte itself the bit the is closest to the address of the byte, is the high order bit
	//
	//    The closest bit to the    The farest bit from the
	//     address of the byte        address of the byte
	//                        |      |
	//      Byte address ->   00000000
	//                        |      |
	//            High order bit    Low order bit
	//
	// Then the value 1 will be stored this way :
	//
	//      Byte address ->   00000001
	//                        |      |
	//            High order bit    Low order bit
	//
	// Then in 1 byte this is always the case. But when dealing with more then 1 byte it is up to the system to decide whether the address of the first byte will
	// contain the high order bits or the low order bits. For example for 2 bytes, store the value 1 in the 2 ways of endian encoding :
	//
	//    Big endian encoding :
	//
	//      First address of data type ->   00000000 00000001
	//
	//    Big endian encoding :
	//
	//      First address of data type ->   00000001 00000000


	// To support move semantics every object must provide a default state. There are  how ever few exceptions, as objects that their members stay exactly the same along
	// the run of the program, objects that don't have members at all, and objects with undefined state. This default state will be used to notify that the object should
	// not be used


	// Class Information :
	//
	//  Purpose :
	//
	//     A wrapper for the c socket address structure for IPv6
	//
    //  Description :
    //
    //
	//
	//  Possible errors :
	//
	//
	//
	class SocketAddressIPv6
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
		inline SocketAddressIPv6() throw();


		// Method Information :
		//
		//  Description :
		//
		//   	Constructor, non explicit on purpose to allow converting literals "1.1.1.1" to strings
		//
		//  Required arguments :
		//
		//		User information needed :
		//
	    //          1. serverIPaddress - a string object containing the IP address for this server
	    //          2. portNumber - the port that the server need to work with
	    //			3. flowInfo - IPv6 flow information
	    //			4. scopeID - an ID depending on the scope of the address
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
		inline SocketAddressIPv6( std::string serverIPaddress, int portNumber, unsigned int flowInfo = 0, unsigned int scopeID = 0 ) throw();


		// Method Information :
		//
		//  Description :
		//
		//   	Copy constructor, will operate correctly even if the other object is in default state
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//          other - a reference to the object that should be copied
		//
		//		Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	A reference to the new copy is returned
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline SocketAddressIPv6( const SocketAddressIPv6& other ) throw();


		// Method Information :
		//
		//  Description :
		//
		//   	Assignment operator, can handle with self assignment and instances in default state
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			other - a reference to the object that should be copied
		//
		//		Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	A reference to this object
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline SocketAddressIPv6& operator=( const SocketAddressIPv6& other ) throw();


		// Method Information :
		//
		//  Description :
		//
		//   	Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances in default state
		//
		//  Required arguments :
		//
		//   	User information needed :
		//
		//          other - a reference to the object that should be moved
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
		inline SocketAddressIPv6( SocketAddressIPv6&& other ) throw();


		// Method Information :
		//
		//  Description :
		//
		//   	Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state
		//
		//  Required arguments :
		//
		//   	User information needed :
		//
		//          other - a reference to the object that should be moved
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	A reference to this object
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline SocketAddressIPv6& operator=( SocketAddressIPv6&& other ) throw();


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
		static void Swap( SocketAddressIPv6& firstObject, SocketAddressIPv6& secondObject ) throw();


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
		inline ~SocketAddressIPv6() throw() = default;


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
		inline void SetToDefaultState() throw();


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
		inline bool DefaultState() const throw();


		// The following methods are the interface of the object. This methods implement the capabilities of the object :


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
	    //          1. serverIPaddress - a string object containing the IP address for this server
	    //          2. portNumber - the port that the server need to work with
	    //			3. flowInfo - IPv6 flow information
	    //			4. scopeID - an ID depending on the scope of the address
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
	    inline void SetNewSocketAddressIPv6( std::string serverIPaddress, int portNumber, unsigned int flowInfo, unsigned int scopeID ) throw();


		// The following methods declare the overloaded operators for the object :



        // Method Information :
        //
        //  Description :
        //
        //      This method will be used to allow explicit ( through static cast ) or implicit conversion of the instance to the structure inside it
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
        //      There is no written return type, but it will return a reference to the structure inside this instance
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline operator struct sockaddr_in6&() throw();


		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to check if the this instance match the other
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          other - a reference to the object that should be compared with this object
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      1. true - if the 2 objects are the same
		//      2. false - otherwise
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline bool operator==( const SocketAddressIPv6& other ) const throw();


		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to check if the this instance does not match the other
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          other - a reference to the object that should be compared with this object
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      1. true - if the 2 objects are not the same
		//      2. false - otherwise
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline bool operator!=( const SocketAddressIPv6& other ) const throw();


	private:


        // This structure will hold the socket address information
        struct sockaddr_in6 m_IPv6sockaddr; 


	};  //  Class SocketAddressIPv6













































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
	inline SocketAddressIPv6::SocketAddressIPv6() throw() :
    m_IPv6sockaddr()
	{
        // Set the members of the structure to 0
        bzero( &m_IPv6sockaddr, sizeof( m_IPv6sockaddr ) );
    }


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
    //          1. serverIPaddress - a string object containing the IP address for this server
    //          2. portNumber - the port that the server need to work with
    //			3. flowInfo - IPv6 flow information
    //			4. scopeID - an ID depending on the scope of the address
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
	inline SocketAddressIPv6::SocketAddressIPv6( std::string serverIPaddress, int portNumber, unsigned int flowInfo, unsigned int scopeID ) throw() :
    m_IPv6sockaddr()
	{
        // Set the members of the structure to 0
        bzero( &m_IPv6sockaddr, sizeof( m_IPv6sockaddr ) );

        // Set that this is IPv4
        m_IPv6sockaddr.sin6_family = AF_INET6;

        // Convert to network byte order
        m_IPv6sockaddr.sin6_port = htons( portNumber );

        // Set the flow information
        m_IPv6sockaddr.sin6_flowinfo = flowInfo;

        // Convert the IPv4 address from text to binary form
        inet_pton( AF_INET6, serverIPaddress.c_str(), &m_IPv6sockaddr.sin6_addr );

        // Set the scope ID
        m_IPv6sockaddr.sin6_scope_id = scopeID;
    }


	// Method Information :
	//
	//  Description :
	//
	//   	Copy constructor, will operate correctly even if the other object is in default state
	//
	//  Required arguments :
	//
	//   	User information needed :
	//
	//          other - a reference to the object that should be copied
	//
	//		Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//   	A reference to the new copy is returned
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline SocketAddressIPv6::SocketAddressIPv6( const SocketAddressIPv6& other ) throw() :
    m_IPv6sockaddr()
	{
        // Set the members of the structure to 0
        bzero( &m_IPv6sockaddr, sizeof( m_IPv6sockaddr ) );
        
        // Copy the socket address structure from the other instance to this one
        memcpy( &m_IPv6sockaddr, &other.m_IPv6sockaddr, sizeof( m_IPv6sockaddr ) );
    }


	// Method Information :
	//
	//  Description :
	//
	//   	Assignment operator, can handle with self assignment and instances in default state
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			other - a reference to the object that should be copied
	//
	//		Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//   	A reference to this object
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline SocketAddressIPv6& SocketAddressIPv6::operator=( const SocketAddressIPv6& other ) throw()
	{
		// Create a copy of the other instance
		SocketAddressIPv6 temporaryObject( other );

		// Swap between this instance and the temporary one, this will leave the temporary instance with the old data, and he will delete it
		Swap( *this, temporaryObject );

		// Return a reference to this object
		return ( *this );
	}


	// Method Information :
	//
	//  Description :
	//
	//   	Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances in default state
	//
	//  Required arguments :
	//
	//   	User information needed :
	//
	//          other - a reference to the object that should be moved
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
	inline SocketAddressIPv6::SocketAddressIPv6( SocketAddressIPv6&& other ) throw() :
	SocketAddressIPv6()
	{
		// Swap between this instance, which is in default state, and the other one
		Swap( *this, other );
	}


	// Method Information :
	//
	//  Description :
	//
	//   	Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state
	//
	//  Required arguments :
	//
	//   	User information needed :
	//
	//          other - a reference to the object that should be moved
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//   	A reference to this object
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline SocketAddressIPv6& SocketAddressIPv6::operator=( SocketAddressIPv6&& other ) throw()
	{
	    // Create a default constructed instance
	    SocketAddressIPv6 temporaryObject;

	    // Swap between the temporary instance, which is in default state, and the other instance
	    Swap( temporaryObject, other );

	    // Swap between this instance and the temporary one
	    Swap( *this, temporaryObject );

	    // Return a reference to this object
	    return ( *this );
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
	inline void SocketAddressIPv6::SetToDefaultState() throw()
	{
	    // Create a default constructed instance
	    SocketAddressIPv6 temporaryObject;

	    // Swap between this instance and the temporary one
	    Swap( *this, temporaryObject );
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
	inline bool SocketAddressIPv6::DefaultState() const throw()
	{

		// Check if the object is in default state
		if ( ( m_IPv6sockaddr.sin6_family == 0 ) &&
             ( m_IPv6sockaddr.sin6_port == 0 ) &&
             ( m_IPv6sockaddr.sin6_flowinfo == 0 ) &&
             ( m_IPv6sockaddr.sin6_addr.s6_addr == 0 ) &&
             ( m_IPv6sockaddr.sin6_scope_id == 0 ) )
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
    //      Constructor,
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. serverIPaddress - a string object containing the IP address for this server
    //          2. portNumber - the port that the server need to work with
    //			3. flowInfo - IPv6 flow information
    //			4. scopeID - an ID depending on the scope of the address
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
    inline void SocketAddressIPv6::SetNewSocketAddressIPv6( std::string serverIPaddress, int portNumber, unsigned int flowInfo, unsigned int scopeID ) throw() 
    {
        // Create a temporary
        SocketAddressIPv6 temporaryObject( serverIPaddress, portNumber, flowInfo, scopeID );

        // Swap between this instance and the temporary
        Swap( *this, temporaryObject );
    }







































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************









































    // Method Information :
    //
    //  Description :
    //
    //      This method will be used to allow explicit ( through static cast ) or implicit conversion of the instance to the structure inside it
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
    //      There is no written return type, but it will return a reference to the structure inside this instance
    //
    //  Possible errors :
    //
    //      They will come
    //
    inline SocketAddressIPv6::operator struct sockaddr_in6&() throw()
    {
        // Return a reference to the structure inside
        return ( m_IPv6sockaddr );
    }


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to check if the this instance match the other
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          other - a reference to the object that should be compared with this object
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      1. true - if the 2 objects are the same
	//      2. false - otherwise
	//
	//  Possible errors :
	//
	//      1. The template type object does not have the comparison operator ( == )
	//      2. 
	//
	inline bool SocketAddressIPv6::operator==( const SocketAddressIPv6& other ) const throw()
	{

        // Compare the 2 structures inside the instances
        if ( ( m_IPv6sockaddr.sin6_family != other.m_IPv6sockaddr.sin6_family ) || 
             ( m_IPv6sockaddr.sin6_port != other.m_IPv6sockaddr.sin6_port ) ||
             ( m_IPv6sockaddr.sin6_flowinfo != other.m_IPv6sockaddr.sin6_flowinfo ) ||
             ( m_IPv6sockaddr.sin6_addr.s6_addr != other.m_IPv6sockaddr.sin6_addr.s6_addr ) ||
             ( m_IPv6sockaddr.sin6_scope_id != other.m_IPv6sockaddr.sin6_scope_id ) )
        {
            // The 2 instances mismatch
            return ( false );
        }

        // If control reached here the 2 instances match
        return ( true );
    }


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to check if the this instance does not match the other
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          other - a reference to the object that should be compared with this object
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      1. true - if the 2 objects are not the same
	//      2. false - otherwise
	//
	//  Possible errors :
	//
	//      1. The template type object does not have the comparison operator ( == )
	//      2. 
	//
	inline bool SocketAddressIPv6::operator!=( const SocketAddressIPv6& other ) const throw()
	{
		// Return the negotiated value from the equal operator
		return ( !( *this == other ) );
	}

















}  //  Namespace Network




#endif  // SOCKETADDRESSIPv6_HPP