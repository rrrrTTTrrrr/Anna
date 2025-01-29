#ifndef  SOCKETADDRESSIPV6_CPP
#define  SOCKETADDRESSIPV6_CPP


#include "SocketAddressIPv6.hpp"


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif



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
    void SocketAddressIPv6::Swap( SocketAddressIPv6& firstObject, SocketAddressIPv6& secondObject ) throw()
    {
        // Move the contents of the second object to a temporary
        SocketAddressIPv6 temporaryObject( std::move( secondObject ) );

        // Move the contents of the first object to the second object
        secondObject = std::move( firstObject );

        // Move the contents of the temporary object to the first object
        firstObject = std::move( temporaryObject );
    }
















}  //  Namespace Network



#endif  //  SOCKETADDRESSIPV6_CPP





