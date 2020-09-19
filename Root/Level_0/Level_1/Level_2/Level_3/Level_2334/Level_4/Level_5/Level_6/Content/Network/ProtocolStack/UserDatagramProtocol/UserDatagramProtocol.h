#ifndef  USERDATAGRAMPROTOCOL_H
#define  USERDATAGRAMPROTOCOL_H



// When a function name ends with the suffix IMP, the function is not part
// of the object interface ( capabilities ), it only used as aid to the
// function that it is, implementing only spsecific part

 

namespace Universe
{

    // This is used when only declaring the object in this source file will be enough to
    // pass compilation. The implementation is given to the compiler through the cpp source
    // file that the object is nested within
    //
    // Forward declarations :
    //
    //  NONE
    //


    // Give proper treatment, by dealing with big and little endian encoding systems
    // where it is required. The big or little endian encoding appear when dealing
    // with byte order in memory


    // To support move semantics every class must provide a default state. This state
    // will be used to notify that the current instance resources was taken by a move
    // operation :
    //
    //
   	// When this state is indicated the object should not be used as it is ( the object is empty )


    // Constructor of derived object, when called, all the base class constructors are executed first, according to
    // the order they appear in the class declaration, and only then the user code is executed

    // Destructor of derived object, when it is called, the user code existing in the destructor itself is executed first and then all the destructors
    // of the base objects, in an opposite way from which they were constructed


    // User Datagram Protocol ( UDP ) :
    //
    // Defined to make available a datagram mode of packet-switched computer communication in the environment of an interconnected set of 
    // computer networks. This protocol assumes that the Internet Protocol ( IP ) is used as the underlying protocol. This protocol provides
    // a procedure for application programs to send messages to other programs with a minimum of protocol mechanism. The protocol is transaction
    // oriented, and delivery and duplicate protection are not guaranteed
    //
    // Format :
    //        
    //        0       7 8     15 16    23 24    31
    //        +--------+--------+--------+--------+
    //        |      Source     |   Destination   |
    //        |       Port      |      Port       |
    //        +--------+--------+--------+--------+
    //        |                 |                 |
    //        |      Length     |    Checksum     |
    //        +--------+--------+--------+--------+
    //        |
    //        |           data octets ...
    //        +---------------- ...
    //
    //
    // 1. Source Port - an optional field, when meaningful, it indicates the port of the sending process, and may be assumed to be the port to which a
    // reply should be addressed in the absence of any other information. If not used, a value of zero is inserted
    // 2. Destination Port - has a meaning within the context of a particular internet destination address
    // 3. Length - is the length in bytes of the current header and the data. The minimum value is 8 bytes
    // 4. Checksum - is the 16-bit one’s complement of the one’s complement sum of a pseudo header of information from the IP header, the UDP header, 
    // and the data, padded with zero bytes at the end ( if necessary ) to make a multiple of two bytes. If the computed checksum is zero, it is 
    // transmitted as all ones ( the equivalent in one’s complement arithmetic ). An all zero transmitted checksum value means that the transmitter 
    // generated no checksum
    //


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
    class UserDatagramProtocol 
	{ 
	public:


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
    	explicit UserDatagramProtocol() throw();


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
    	explicit UserDatagramProtocol( UnsignedInteger16bits sourcePort, UnsignedInteger16bits destinationPort ) throw( Exception );


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
    	explicit UserDatagramProtocol( const UserDatagramProtocol& other ) throw( Exception );


		// Method Information :
    	//
    	//  Description :
    	//
    	//   	Assignment operator, handle with self assignment correctly. Will operate correctly even if the other object is in default state
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
    	UserDatagramProtocol& operator=( const UserDatagramProtocol& other ) throw( Exception );


    	// Method Information :
    	//
    	//  Description :
    	//
    	//   	Move constructor, takes the resources from the instance given in the rvalue reference, and set it to the default state.
      	//		Will operate correctly even if the other object is in default state. Important note - if the current object has a pointer
        //      memebers, they must be set manually to 0 before using the method set to default state, or else the resources will be deleted
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
    	explicit UserDatagramProtocol( UserDatagramProtocol&& other ) throw( Exception );


		// Method Information :
    	//
    	//  Description :
    	//
    	//   	Move Assignment operator, handle self assignment correctly. take the resources from the
    	//    	instance given in the rvalue reference,	and set it to the default state.
    	//      will operate correctly even if the other object is in default state. Important note - if the current object
        //      has a pointer memebers, they must be set manually to 0 before using the method set to default state, or else
        //      the resources will be deleted
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
    	UserDatagramProtocol& operator=( UserDatagramProtocol&& other ) throw( Exception );


		// Method Information :
    	//
    	//  Description :
    	//
    	//   	Destructor,
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
    	~UserDatagramProtocol() throw();


        // To support Move semantics, the following 2 methods are added to every object. One function to set
        // the object into the default state, and the other to check if the object is in the default state

        // Method Information :
    	//
    	//  Description :
    	//
    	//   	Use to set the object into his default state
    	//
    	//  Required arguments :
    	//
    	//		User information needed :
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
    	void SetToDefaultState() throw();


        // Method Information :
    	//
    	//  Description :
    	//
    	//   	Use to check if the object is in default state, it will return true if it does, and false otherwise
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
    	bool DefaultState() const throw();  


	private: 


	};  //  Class UserDatagramProtocol




//	**************************************   END PART OF DECLRATIONS, IMPLMENTATION TIME   ************************************




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
    //	    They will come
    //
    UserDatagramProtocol::UserDatagramProtocol() throw()


    // Method Information :
    //
    //  Description :
    //
    //   	Constructor,
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
    //        NONE
    //
    //  Possible errors :
    //
    //	    They will come
    //
	UserDatagramProtocol::UserDatagramProtocol() throw( Exception )


	// Method Information :
    //
    //  Description :
    //
    //   	Copy constructor,
    //
    //  Required arguments :
    //
    //   	User information needed :
    //
    //          other - a reference to the object that should be copied
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
    //        They will come
    //
    UserDatagramProtocol::UserDatagramProtocol( const UserDatagramProtocol& other ) throw( Exception )


	// Method Information :
    //
    //  Description :
    //
    //   	Assignment operator, handle self assignment correctly,
    //
    //  Required arguments :
    //
    //   	User information needed :
    //
    //          other - a reference to the object that should be copied
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
    //	    They will come
    //
    UserDatagramProtocol& UserDatagramProtocol::operator=( const UserDatagramProtocol& other ) throw( Exception )
    {

        // Check that this is not self assignment
        if ( this != &other )
        {
            // This is not self assignment

            // Release all the resources of this object
            SetToDefaultState();

            // Check if the other object is in default state
            if ( true == other.DefaultState() )
            {
                // The other object is in default state

                // Nothing else needs to be done, return a reference to this object
                return ( *this );
            }

            // Copy the other object resources

        }

        // Return a reference to this object
        return ( *this );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Move constructor, take the resources from the instance given in the rvalue reference, and set it to the default state.
    //      Will operate correctly even if the other object is in default state. Important note - if the current object has a pointer
    //      memebers, they must be set manually to 0 before using the method set to default state, or else the resources will be deleted
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
    //	    They will come
    //
    UserDatagramProtocol::UserDatagramProtocol( UserDatagramProtocol&& other ) throw( Exception )


    // Method Information :
    //
    //  Description :
    //
    //   	Move Assignment operator, handle self assignment correctly. take the resources from the instance given in the rvalue reference,
    //  	and set it to the default state. Will operate correctly even if the other object is in default state. Important note - if the
    //      current object has pointer memebers, they must be set manually to 0 before using the method set to default state, or else
    //      the resources will be deleted
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
    //	They will come
    //
    UserDatagramProtocol& UserDatagramProtocol::operator=( UserDatagramProtocol&& other ) throw( Exception )
    {

        // Check that this is not self assignment
        if ( this != &other )
        {
            // This is not self assignment

            // Release all the resources of this object
            SetToDefaultState();

            // Check if the other object is in default state
            if ( true == other.DefaultState() )
            {
                // The other object is in default state

                // Nothing else needs to be done, return a reference to this object
                return ( *this );
            }

            // Take the other object resources

        }

        // Return a reference to this object
        return ( *this );
    }


    // Method Information :
    //
    //  Description :
    //
    //        Destructor,
    //
    //  Required arguments :
    //
    //   	  User information needed :
    //
    //            NONE
    //
    //        Information returned to the user :
    //
    //            NONE
    //
    //  Return value :
    //
    //   	NONE
    //
	//  Possible errors :
    //
    //	    They will come
    //
    UserDatagramProtocol::~UserDatagramProtocol() throw()


    // Method Information :
    //
    //  Description :
    //
    //      Use to set the object into his default state
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
    void UserDatagramProtocol::SetToDefaultState() throw()


    // Method Information :
    //
    //  Description :
    //
    //		Use to check if the object is in default state, it will return true if it does, and false otherwise
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
    //	    They will come
    //
    bool UserDatagramProtocol::DefaultState() const throw()
    {

        // Check if the object is in default state
        if ()
        {
            // The object is in default state
            return ( true );
        }

        // The object is not in default state
        return ( false );
    }











//	*****************************************   PRIVATE METHODS IMPLEMENTATION   ******************************************  














// ******************************************   NESTED CLASS IMPLEMENTATION -    **************************************** 












}  //   Namespace Universe

#endif  // USERDATAGRAMPROTOCOL_H