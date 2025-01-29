#ifndef  POLLFD_HPP
#define  POLLFD_HPP


#include <poll.h>  //  function ppoll, struct pollfd 
#include <string.h>  //  function memset
#include <algorithm>  //  std::swap


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
	//
	//
    //  Description :
    //
    //          1. The possible events to request are :
    //
    //                  POLLIN - there is data to read
    //                  POLLOUT - writing is now possible
    //
    //          2. The possible returned events, are all of the above, and :
    //
    //                  POLLERR - error condition
    //                  POLLHUP - hang up
    //                  POLLNVAL - invalid request   
    //
	//  Possible errors :
	//
	//
	//
	class Pollfd
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
        inline Pollfd() throw();


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
        //          1. socketFileDescriptor - an integer representing the socket file descriptor in the kernel
        //          2. events - a short integer representing the required events the poll call should check for the current socket file descriptor
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
        inline Pollfd( int socketFileDescriptor, short events ) throw();


        // Method Information :
        //
        //  Description :
        //
        //      Copy constructor, will operate correctly even if the other object is in default state
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          other - a reference to the object that should be copied
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A reference to the new copy is returned
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline Pollfd( const Pollfd& other ) throw();


        // Method Information :
        //
        //  Description :
        //
        //      Assignment operator, can handle with self assignment and instances in default state
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          other - a reference to the object that should be copied
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A reference to this object
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline Pollfd& operator=( const Pollfd& other ) throw();


        // Method Information :
        //
        //  Description :
        //
        //      Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances in default state
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          other - a reference to the object that should be moved
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
        inline Pollfd( Pollfd&& other ) throw();


        // Method Information :
        //
        //  Description :
        //
        //      Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          other - a reference to the object that should be moved
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A reference to this object
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline Pollfd& operator=( Pollfd&& other ) throw();


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
        static inline void Swap( Pollfd& firstObject, Pollfd& secondObject ) throw();


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
        inline ~Pollfd() throw() = default;


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
        inline void SetToDefaultState() throw();


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
        inline bool DefaultState() const throw();


		// The following methods are the interface of the object. This methods implement the capabilities of the object :


        // Method Information :
        //
        //  Description :
        //
        //      Use to set new socket information
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. socketFileDescriptor - an integer representing the socket file descriptor in the kernel
        //          2. events - a short integer representing the required events the poll call should check for the current socket file descriptor
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
        inline void SetNewSocketAndEvents( int socketFileDescriptor, short events ) throw();


        // Method Information :
        //
        //  Description :
        //
        //      Use to get the socket file descriptor inside this instance
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
        inline int GetFileDescriptor() const throw();


        // Method Information :
        //
        //  Description :
        //
        //      Use to set the required socket file descriptor
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          socketFileDescriptor - an integer representing the socket file descriptor in the kernel
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
        inline void SetFileDescriptor( int socketFileDescriptor ) throw();


        // Method Information :
        //
        //  Description :
        //
        //      Use to set the required events to poll for the current socket file descriptor
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          events - a short integer representing the required events the poll call should check for the current socket file descriptor
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
        inline void SetEvents( short events ) throw();


        // Method Information :
        //
        //  Description :
        //
        //      Use to get the required events to poll for the current socket file descriptor
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
        //      A short integer with the required events
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline short GetEvents() throw();


        // Method Information :
        //
        //  Description :
        //
        //      Use to set the retunred events integer to 0
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
        inline void SetReturnedEventsToZero() throw();


        // Method Information :
        //
        //  Description :
        //
        //      Use to get returned events after polling for the current socket file descriptor
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
        //      A short integer with the returned events
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline short GetReturnedEvents() throw();


		// The following methods declare the overloaded operators for the object :


        // Method Information :
        //
        //  Description :
        //
        //      This method will be used to allow explicit ( through static cast ) or implicit conversion to the pollfd structure inside
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
        //      There is no written return type, but it will return a reference to the pollfd structure inside
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline operator struct pollfd*() throw();


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
		bool operator==( const Pollfd& other ) const throw();


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
		inline bool operator!=( const Pollfd& other ) const throw();


	private:


        struct pollfd m_pollfd;


	};  //  Class Pollfd












































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
	inline Pollfd::Pollfd() throw()
	{
        // Set the members of the structure to 0
        bzero( &m_pollfd, sizeof( m_pollfd ) );
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
    //          1. socketFileDescriptor - an integer representing the socket file descriptor in the kernel
    //          2. events - a short integer representing the required events the poll call should check for the current socket file descriptor
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
    inline Pollfd::Pollfd( int socketFileDescriptor, short events ) throw()
    {
        // Set the members of the structure to 0
        bzero( &m_pollfd, sizeof( m_pollfd ) );

        // Set socket file descriptor
        m_pollfd.fd = socketFileDescriptor;

        // Set the events
        m_pollfd.events = events;
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
	inline Pollfd::Pollfd( const Pollfd& other ) throw()
	{
        // Copy the pollfd structure members

        // Copy the file descriptor
        m_pollfd.fd = other.m_pollfd.fd;

        // Copy the events
        m_pollfd.events = other.m_pollfd.events;

        // Copy the returned events
        m_pollfd.revents = other.m_pollfd.revents;
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
	inline Pollfd& Pollfd::operator=( const Pollfd& other ) throw()
	{
		// Create a copy of the other instance
		Pollfd temporary( other );

		// Swap between this instance and the temporary one, this will leave the temporary instance with the old data, and he will delete it
		Swap( *this, temporary );

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
	inline Pollfd::Pollfd( Pollfd&& other ) throw() :
	Pollfd()
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
	inline Pollfd& Pollfd::operator=( Pollfd&& other ) throw()
	{
	    // Create a default constructed instance
	    Pollfd temporary;

	    // Swap between the temporary instance, which is in default state, and the other instance
	    Swap( temporary, other );

	    // Swap between this instance and the temporary one
	    Swap( *this, temporary );

	    // Return a reference to this object
	    return ( *this );
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
	inline void Pollfd::Swap( Pollfd& firstObject, Pollfd& secondObject ) throw()
	{
        // Swap the file descriptors
        std::swap( firstObject.m_pollfd.fd, secondObject.m_pollfd.fd );

        // Swap the events
        std::swap( firstObject.m_pollfd.events, secondObject.m_pollfd.events );

        // Swap the revents
        std::swap( firstObject.m_pollfd.revents, secondObject.m_pollfd.revents );
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
	inline void Pollfd::SetToDefaultState() throw()
	{
	    // Create a default constructed instance
	    Pollfd temporary;

	    // Swap between this instance and the temporary one
	    Swap( *this, temporary );
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
	inline bool Pollfd::DefaultState() const throw()
	{

		// Check if the object is in default state
		if ( ( m_pollfd.fd == 0 ) &&
             ( m_pollfd.events == 0 ) &&
             ( m_pollfd.revents == 0 ) )
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
    //      Use to set new socket information
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. socketFileDescriptor - an integer representing the socket file descriptor in the kernel
    //          2. events - a short integer representing the required events the poll call should check for the current socket file descriptor
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
    inline void Pollfd::SetNewSocketAndEvents( int socketFileDescriptor, short events ) throw()
    {
        // Create a temporary instance
        Pollfd temporary( socketFileDescriptor, events );

        // Swap bewteen the temporary and this instance
        Swap( *this, temporary );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Use to get the socket file descriptor inside this instance
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
    inline int Pollfd::GetFileDescriptor() const throw()
    {
        // Return a copy of the socket file descriptor
        return ( m_pollfd.fd );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Use to set the required socket file descriptor
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          socketFileDescriptor - an integer representing the socket file descriptor in the kernel
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
    inline void Pollfd::SetFileDescriptor( int socketFileDescriptor ) throw()
    {
        // Set the socket file descriptor
        m_pollfd.fd = socketFileDescriptor;
    }


    // Method Information :
    //
    //  Description :
    //
    //      Use to set the required events to poll for the current socket file descriptor
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          events - a short integer representing the required events the poll call should check for the current socket file descriptor
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
    inline void Pollfd::SetEvents( short events ) throw()
    {
        // Set the events
        m_pollfd.events = events;
    }


    // Method Information :
    //
    //  Description :
    //
    //      Use to get the required events to poll for the current socket file descriptor
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
    //      A short integer with the required events
    //
    //  Possible errors :
    //
    //      They will come
    //
    inline short Pollfd::GetEvents() throw()
    {
        // Return the events
        return ( m_pollfd.events );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Use to set the retunred events integer to 0
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
    inline void Pollfd::SetReturnedEventsToZero() throw()
    {
        // Set the events
        m_pollfd.events = 0;
    }


    // Method Information :
    //
    //  Description :
    //
    //      Use to get returned events after polling for the current socket file descriptor
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
    //      A short integer with the returned events
    //
    //  Possible errors :
    //
    //      They will come
    //
    inline short Pollfd::GetReturnedEvents() throw()
    {
        // Set the socket file descriptor
        return ( m_pollfd.revents );
    }


















































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************


















































    // Method Information :
    //
    //  Description :
    //
    //      This method will be used to allow explicit ( through static cast ) or implicit conversion to the pollfd structure inside
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
    //      There is no written return type, but it will return a reference to the pollfd structure inside
    //
    //  Possible errors :
    //
    //      They will come
    //
    inline Pollfd::operator struct pollfd*() throw()
    {
        // Return the pollfd structure inside
        return ( &m_pollfd );
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
	bool Pollfd::operator==( const Pollfd& other ) const throw()
	{

        // Check if the members of the 2 instances are the same
        if ( ( m_pollfd.fd != other.m_pollfd.fd ) || ( m_pollfd.events != other.m_pollfd.events ) || ( m_pollfd.revents != other.m_pollfd.revents ) )
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
	inline bool Pollfd::operator!=( const Pollfd& other ) const throw()
	{
		// Return the negotiated value from the equal operator
		return ( !( *this == other ) );
	}














}  //  Namespace Network




#endif  // POLLFD_HPP