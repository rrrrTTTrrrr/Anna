#ifndef  BASETCPSOCKET_HPP
#define  BASETCPSOCKET_HPP


#include <string>  //  Class std::string


#include "../../ErrnoException/ErrnoException.hpp"  //  Class ErrnoException


namespace Network
{





	// Class Information :
	//
	//  Purpose :
	//
	//     This object contains C++ wrappers for socket realted funtionality
	//
    //  Description :
    //
    //
	//
	//  Possible errors :
	//
	//
	//
	class BaseTCPsocket
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
		inline BaseTCPsocket() throw() = default;


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
		inline BaseTCPsocket( const BaseTCPsocket& other ) throw() = default;


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
		inline BaseTCPsocket& operator=( const BaseTCPsocket& other ) throw() = default;


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
		inline BaseTCPsocket( BaseTCPsocket&& other ) throw() = default;


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
		inline BaseTCPsocket& operator=( BaseTCPsocket&& other ) throw() = default;


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
		inline ~BaseTCPsocket() throw() = default;


		// The following methods are the interface of the object. This methods implement the capabilities of the object :


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to send data to the server
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. socketFileDescriptor - an open socket file descriptor 
        //          2. asciiString - the ascii string that needs to be sent to the server
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      The number bytes successfully sent
        //
        //  Possible errors :
        //
        //      1. The server did not respond - class ErrnoException is thrown
        //      2. 
        //
        ssize_t Send( int socketFileDescriptor, const std::string& asciiString ) throw( ErrorHandling::ErrnoException );


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to receive data from the server
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
        std::string Receive( int socketFileDescriptor ) throw( ErrorHandling::ErrnoException );


	};  //  Class BaseTCPsocket















































//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************





















































}  //  Namespace Universe



#endif  // BASETCPSOCKET_HPP