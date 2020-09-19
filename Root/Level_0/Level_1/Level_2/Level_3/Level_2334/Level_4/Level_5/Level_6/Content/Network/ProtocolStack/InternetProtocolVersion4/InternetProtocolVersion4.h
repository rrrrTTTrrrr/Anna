#ifndef  __INTERNETPROTOCOLVERSION4_H__
#define  __INTERNETPROTOCOLVERSION4_H__


#include <new>  //  Class std::bad_alloc


#include "../Utilities/Definitions/VariableTypesDefinitions.h"  //  Typedef UnsignedInteger8bits, Typedef UnsignedInteger16bits, Typedef UnsignedInteger32bits
#include "../DesignPatterns/AutomaticPointer.h"  //  Class AutomaticPointer




// When a function name ends with the suffix IMP, the function is not part
// of the object interface ( capabilities ), it only used as aid to the
// function that it is, implementing only spsecific part

 

namespace Universe
{


	// INTERNET PROTOCOL ( IP ) :
	//
	// The internet protocol is designed for use in interconnected systems of packet-switched computer
	// communication networks. The internet protocol provides for transmitting blocks of data called datagrams
	// from sources to destinations, where sources and destinations are hosts identified by fixed length
	// addresses. The internet protocol also provides for fragmentation and reassembly of long datagrams, if
	// necessary, for transmission through "small packet" networks. Basically the internet protocol implements
	// two basic functionalities - addressing and fragmentation
	//
	// The internet protocol treats each internet datagram as an independent entity unrelated to any other
	// internet datagram. There are no connections or logical circuits ( virtual or otherwise )
	//
	// The internet protocol uses four key mechanisms in providing its service: Type of Service, Time to Live,
	// Options, and Header Checksum
	//
	// Errors detected may be reported via the Internet Control Message Protocol ( ICMP )
	//
	// Assigned network numbers :
	//
	// The Internet Protocol ( IP ) uses a 32 bit address and divides that address into a network part and a
	// "rest" or local address part. The division takes 3 forms or classes :
	//
	// 1. The first type ( named class A ) of address has a 7 bit network number and a 24 bit local address.
	// This allows 128 class A networks :
	//
	//                   0                   1                   2                   3
	//                   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
	//                  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//                  |0|  NETWORK    |                LOCAL ADDRESS                  |
	//                  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//
	// Note - the 1,2 and 3 above used to note that from this location the number is more then one digit and
	// the first digit is 1,2 or 3
	//
	// 2. The second type ( named class B ) of address has a 14 bit network number and a 16 bit local address.
	// This allows 16,384 class B networks :
	//
	//                   0                   1                   2                   3
	//                   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
	//                  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//                  |1 0 |        NETWORK           |        LOCAL ADDRESS          |
	//                  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//
	// 3. The third type ( named class C ) of address has a 21 bit network number and a 8 bit local address.
	// This allows 2,097,152 class C networks :
	//
	//                   0                   1                   2                   3
	//                   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
	//                  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//                  |1 1 0 |               NETWORK                  | LOCAL ADDRESS |
	//                  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//
	// One notation for Internet host addresses commonly used divides the 32 bit address into four 8 bit fields
	// and specifies the value of each field as a decimal number with the fields seperated by periods. For
	// example - 010.020.000.052
	//
	//
	// Internet header contents :
	//
	//                   0                   1                   2                   3
	//                   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
	//                  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//                  |Version|  IHL  |Type of Service|          Total Length         |
	//                  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//                  |         Identification        |Flags|      Fragment Offset    |
	//                  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//                  | Time to Live  |    Protocol   |        Header Checksum        |
	//                  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//                  |                           Source Address                      |
	//                  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//                  |                         Destination Address                   |
	//                  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//                  |                    Options                    |    Padding    |
	//                  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//
	// Description and size of each content :
	//
	// 1. Version - 4 bits - the version field indicates the format of the internet header ( current version is 4 )
	// 2. IHL ( Internet Header Length ) - 4 bits - is the length of the internet header in 32 bit words, and thus
	// points to the begining of the data. The minimum value for a correct header is 5
	// 3. Type of service - 8 bits - provides an indication of the abstract parameters of the quality of Service
	// desired. These parameters are to be used to guide the selection of the actual service parameters when
	// transmitting a datagram through a particular network. Several networks offer service precedence, which
	// somehow treats high precedence traffic as more important than other traffic ( generally by accepting
	// only traffic above a certain precedence at time of high load ). The major choice is a three way tradeoff
	// between low delay, high reliability and high throughput :
	//
	//                  Bits 0,1,2  ->   precedence
	//                  Bits 3      ->   0 = Normal Delay, 1 = Low Delay
	//                  Bits 4      ->   0 = Normal Throughput, 1 = High Throughput
	//                  Bits 5      ->   0 = Normal Relibility, 1 = High Relibility
	//                  Bits 6,7    ->   Reserved for future use
	//
	//                             0     1     2     3     4     5     6     7
	//                          +-----+-----+-----+-----+-----+-----+-----+-----+
	//                          |                 |     |     |     |     |     |
	//                          |   PRECEDENCE    |  D  |  T  |  R  |  0  |  0  |
	//                          |                 |     |     |     |     |     |
	//                          +-----+-----+-----+-----+-----+-----+-----+-----+
	//
	//                  Precedence options :
	//                      111 - Network Control
	//                      110 - Internetwork Control
	//                      101 - CRITIC/ECP
	//                      100 - Flash Override
	//                      011 - Flash
	//                      010 - Immediate
	//                      001 - Priorit
	//                      000 - Routine
	//
	// 4. Total Length - 16 bits - is the length of the datagram, measured in bytes, including internet header
	// and data. This field allows the length of a datagram to be up to 65,535 bytes
	// 5. Identification - 16 bits - an identifying value assigned by the sender to aid in assembling the
	// fragments of a datagram
	// 6. Flags - 3 bits - various control flags :
	//
	//                  Bit 0   ->   reserved, must be zero
	//                  Bit 1   ->   ( DF )  0 = May Fragment, 1 = Don't Fragment
	//                  Bit 2   ->   ( MF )  0 = Last Fragment, 1 = More Fragments
	//
	//                                  +---+---+---+
	//                                  |   | D | M |
	//                                  | 0 | F | F |
	//                                  +---+---+---+
	//
	//  7. Fragment offset - 13 bits - this field indicates where in the datagram this fragment belongs. The
	// fragment offset is measured in units of 8 bytes ( 64 bits ). The first fragment has offset of 0
	// 8. Time To Live - 8 bits - this field indicates the maximum time the datagram is allowed to remain in the
	// internet system. If this field contains the value 0, then the datagram must be destroyed. This field is
	// modified in internet processing. The time is measured in units of seconds, but since every module that
	// processes a datagram must decrease the Time To Live  by at least one even if it process the datagram
	// in less than a second, the Time To Live must be thought of only as an upper bound on the time a datagram
	// may exist. The intentio is to cause undeliverable datagrams to be discarded, and to bound the maximum
	// datagram lifetime
	// 9. Protocol - 8 bits - this field indicates the next level protocol used in the data portion of the i
	// internet datagram
	// 10. Header Checksum - 16 bits - a checksum on the header only. Since some header fields change, this
	// is recomputed and verified at each point that the internet header is processed.
	//
	//          The checksum algorithm is :
	//              The checksum field is the 16 bit one's complement of the one's complement
	//              sum of all 16 bit words in the header. For purposes of computing the
	//              checksum, the value of the checksum field is 0
	//
	// 11. Source address - 32 bits
	// 12. Destination address - 32 bits
	// 13. Options - not constant - The options may appear or not in datagrams. There may be 0 or more options.
	// There are 2 cases for the format of an option :
	//
	//          case 1 - a single byte option type
	//          case 2 - an option type byte, an option length byte and the actual option data bytes
	//
	// The option length byte counts the option type byte, the option length byte as well as the option data bytes.
	// The option type byte is viewed as having 3 fields :
	//
	//          1 bit    ->   copied flag
	//          2 bits   ->   option class
	//          5 bits   ->   option number
	//
	// The copied flag indicates that this option is copied into all fragments on fragmentation :
	//
	//          0  =  not copied
	//          1  =  copied
	//
	// The option classes are :
	//
	//          0  =  control
	//          1  =  reserved for future use
	//          2  =  debugging and measurement
	//          3  =  reserved for future use
	//
	// The following internet options are defined :
	//
	//            |  CLASS  |  NUMBER |  LENGTH  |                     DESCRIPTION                |
	//            +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//            |    0    |    0    |     -    |  End of option list ( occupies only 1 byte )   |
	//            ---------------------------------------------------------------------------------
	//            |    0    |    1    |     -    |  No operation ( occupies only 1 byte )         |
	//            ---------------------------------------------------------------------------------
	//            |    0    |    2    |    11    |  Security                                      |
	//            ---------------------------------------------------------------------------------
	//            |    0    |    3    | changing |  Loose source routing                          |
	//            ---------------------------------------------------------------------------------
	//            |    0    |    9    | changing |  Strict source routing                         |
	//            ---------------------------------------------------------------------------------
	//            |    0    |    7    | changing |  Record Route                                  |
	//            ---------------------------------------------------------------------------------
	//            |    0    |    8    |     4    |  Stream identifier                             |
	//            ---------------------------------------------------------------------------------
	//            |    2    |    4    | changing |  Internet timestamp                            |
	//            ---------------------------------------------------------------------------------
	// Options description :
    //
    // 1. End of option lost - this option indicates the end of the option list. This is used at the end of
    // all options, not the end of each option, and need only be used if the end of the options would not
    // otherwise coincide with the end of the internet header
    //
    //                                             +----------+
    //                                             | 00000000 |
    //                                             +----------+
    //                                               type = 0
    //
    // 2. No operation - this option may be used between options, for example, to align the begining of a
    // subsequent option on a 32 bit boundary
    //
    //                                             +----------+
    //                                             | 00000001 |
    //                                             +----------+
    //                                               type = 1
    //
    // 3. Security - this option provides a way for hosts to send security, compartmentation, handling
    // restrictions, and TCC ( closed user group ) parameters. The format is as follows :
    //
    //                       +--------+--------+---//---+---//---+---//---+---//---+
    //                       |10000010|00001011|SSS  SSS|CCC  CCC|HHH  HHH|  TCC   |
    //                       +--------+--------+---//---+---//---+---//---+---//---+
    //                                      Type = 130 Length = 11
    //
    // The S field - 16 bits - specifies one of 16 levels of security :
	//
    //          00000000 00000000 - Unclassified
    //          11110001 00110101 - Confidential
    //          01111000 10011010 - EFTO
    //          10111100 01001101 - MMMM
    //          01011110 00100110 - PROG
    //          10101111 00010011 - Restricted
    //          11010111 10001000 - Secret
    //          01101011 11000101 - Top secret
    //          00110101 11100010 - Reserved for future use
    //          10011010 11110001 - Reserved for future use
    //          01001101 01111000 - Reserved for future use
    //          00100100 10111101 - Reserved for future use
    //          00010011 01011110 - Reserved for future use
    //          10001001 10101111 - Reserved for future use
    //          11000100 11010110 - Reserved for future use
    //          11100010 01101011 - Reserved for future use
	//
	// The C field - 16 bits - specifies the compartments part. An all 0 value is used when the information
	// transmitted is not compartmented
	//
	// The H field - 16 bits - specifies how to handle restrictions. The values for the control and release
	// markings are alphanumeric digraphs
	//
	// The TCC field - 24 bits - the transmission control code. Provides a means to segregate traffic and
	// define controlled communities of interest among subscribers. The TCC values are trigraphs
	//
	// 4. Loose source and record route ( LSRR ) - provides a means for the source of an internet datagram
	// to supply routing information to be used by the gateways in forwarding the datagram to the destination,
	// and to record the route information
	//
	//  						+--------+--------+--------+---------//--------+
	//							|10000011| length | pointer|     route data    |
	//							+--------+--------+--------+---------//--------+
	//	 										  Type = 131
	//
	// A route data is composed of a series of internet addresses. Each internet address is 2 bits or 4 bytes.
	// If the pointer is greater then the length, the source route is empty ( and the recorded route full )
	// and the routing is to be based on the destination address field. If the address in destination address
	// field has been reached and the pointer is not greater than the length, the next address in the source
	// route replaces the address in the destination address field, and the recorded route address replaces
	// the source address just used, and the pointer is increased by 4
	//
	// This options is a loose route becuase the gateway or host IP is allowed to use any route of any number
	// of other intermediate gateways to reach the next address in the route
	//
	// 5. Strict source and record route ( SSRR ) - similar to loose source and record data, but the gateway
	// or host IP must send the datagram directly to the next address in the source route through only the
	// directly connected network indicated in the next address to reach the next gateway or host specified
	// in the route
	//
	//  						+--------+--------+--------+---------//--------+
	//							|10001001| length | pointer|     route data    |
	//							+--------+--------+--------+---------//--------+
	//	 										  Type = 137
	//
	// 6. Record route - provides a means to record the route of an internet datagram
	//
	//  						+--------+--------+--------+---------//--------+
	//							|0000111 | length | pointer|     route data    |
	//							+--------+--------+--------+---------//--------+
	//	 										  Type = 7
	//
	// When an internet module routes a datagran it checks to see if the record route option is present. If
	// it is, it inserts it's own internet address as known in the environment into which this datagram is
	// being forwarded into the recorded route begining at the byte indicated by the pointer, and increments
	// the pointer by 4. If the route data area is already full, the data gram is forwarded without inserting
	// the address into the recorded route. If there is some room but not enough room for a full address to
	// be inserted, the original datagram is considered to be in error and is discarded
	//
	// 7. Internet timestamp - the timestamp is a right justified, 32 bit timestamp in milliseconds since
	// midnight UT. If the time is not available in milliseconds or cannot be provided with respect to
	// midnight UT then any time may be inserted as a timestamp provided the high order bit of the timestamp
	// field is set to 1 to indicate the use of a non standard value. The initial contents of the timestamp
	// data area must be 0. If there is some room but not enough room for a full timestamp to be inserted, or
	// the overflow count itself overflows, the original datagram is considered to be in error and is discarded
	//
	//  						     +--------+--------+--------+--------+
	//							     |01000100| length | pointer|oflw|flg|
	//							     +--------+--------+--------+--------+
	//								 |			Internet address		 |
	//							     +--------+--------+--------+--------+
	//								 |             Timestamp             |
	//							     +--------+--------+--------+--------+
	//								 |				   .				 |
	//												   .
	//												   .
	//
	//	 										  Type = 68
	//
	// The option length is the number of bytes in the option counting the type, length, pointer, and
	// overflow/flag bytes ( maximum length 40 ). The pointer is the number of bytes from the begining of
	// this option to the end of timestamps plus 1 ( it points to the byte begining the space for next
	// timestamp ). The snallest value is 5.
	//
	// The overflow ( oflw ) - 4 bits - represent the number of IP modules that cannot register timestamps
	// due to lack of space
	// The flag ( flg ) - 4 bits - the possible values are :
	//
	//				0   --   timestamps only, store in consecutive 32 bit words
	//				1   --   each timestamp is preceded with internet address of the registering entity
	//				3   --   the internet address fields are predpecified. An IP module only registers its
	//						 timestamp if it matches it's own address with the next specified internet address


    // Give proper treatment, by dealing with big and little endian encoding systems
    // where it is required. The big or little endian encoding appear when dealing
    // with byte order in memory


    // To support move semantics every class must provide a default state. This state
    // will be used to notify that the current instance resources was taken by a move
    // operation :
    //
    //
   	// When this state is indicated the object should not be used as it is ( the object is empty )


	// In internet protocol version 4 the transmission unit can be at least 68 bytes, and can go up
	// to 64KB. The layer 2 protocols can deal with around 1400 - 10000 bytes at the same time,
	// therefore the size of the datagram will be the least so that it would be compatible with
	// the most networks


	class InternetProtocolVersion4 
	{ 
	public:

		// Default constructor, used to support move semantics
		explicit InternetProtocolVersion4() throw();

		// This enum will be used to determine the required option from the user 
		enum Option
		{
			NO_OPTION = 0,     // Used internally to check if an option is required
		
			// The variables area assigned in way that they can be operated with OR ( | )
			// to choose multiple options. This combination is not allow -  RECORD_ROUTE | TIME_STAMP
			// becuase this 2 options do the same thing, only the time stamp option adds the time
		
			RECORD_ROUTE = 1,  // The gateways and hosts along the path will set thier own address
			TIME_STAMP = 2,    // The gateways and the hosts along the path will set thier own address and the time
			SECURITY = 4,      // Choose one among multiple security options
		};

		// Security - this option provides a way for hosts to send security. If the user
		// requires the security option, this is the structure used to provide the specific details

		typedef struct Security
		{
		public:

			// This enum will be used to represent the 16 levels of security ( 8 of them are reserved for 
			// future use ). The values are in hexadecimal form, becuase the great thing about hexadecimal
			// is that all there is to do is to look at each 4 bits seperatly and determine the value which
			// is only between 0 - 15 ( F in hexadecimal )  
			enum SecurityLevel
			{
				UNCLASSIFIED = 0x0000,  			//  In decimal - 0
				CONFIDENTIAL = 0xF135,  			//  In decimal - 
				EFTO = 0x789A,  					//  In decimal - 
				MMMM = 0xBC4D,  					//  In decimal - 
				PROG = 0x5E26,  					//  In decimal - 
				RESTRICTED = 0xAF13,  				//  In decimal - 
				SECRET = 0xD788,  					//  In decimal - 
				TOP_SECRET = 0x6BC5,  				//  In decimal - 
				NOT_CURRENTLY_USED_1 = 0x35D2,      //  In decimal - 
				NOT_CURRENTLY_USED_2 = 0x9AF1,      //  In decimal -
				NOT_CURRENTLY_USED_3 = 0x4D78,      //  In decimal -
				NOT_CURRENTLY_USED_4 = 0x24BD,      //  In decimal -
				NOT_CURRENTLY_USED_5 = 0x135E,      //  In decimal -
				NOT_CURRENTLY_USED_6 = 0x89AF,      //  In decimal -
				NOT_CURRENTLY_USED_7 = 0xC4D6,      //  In decimal -
				NOT_CURRENTLY_USED_8 = 0xE26B,      //  In decimal -
			};

			// Constrcutor, receive all the required information to initialize the security option
			explicit inline Securtiy( SecurityLevel securitLevel, 
				      UnsignedInteger16bits m_compartments, 
				      UnsignedInteger16bits m_handlingRestrictions,
				      UnsignedInteger32bits m_transmissionControlCode ) throw();

			// Destructor, 
			inline ~Securtiy() throw();

		private:

			// This object will store the security level
			SecurityLevel m_securityLevel;

			// This object will store the compartments which is 16 bits. An all zero value is used when the 
			// information transmitted is not compartmented
			UnsignedInteger16bits m_compartments;

			// This object will store the handling restrictions information which is 16 bits
			UnsignedInteger16bits m_handlingRestrictions;

			// This object will store the transmission control code ( TCC ) which is 24 bits. It Provides a means to 
			// segregate traffic and define controlled communities of interest among subscribers 
			UnsignedInteger32bits m_transmissionControlCode;

		}Security;

		// Constructor, the data length in bytes can only be between 1 - 64KB, if the length is 0
		// the method will do nothing
		explicit InternetProtocolVersion4( const void* dataToSend,
										   UnsignedInteger16bits dataLengthInBytes,
										   UnsignedInteger32bits destinationAddress,
										   UnsignedInteger8bits protocol,
										   UnsignedInteger8bits typeOfService,
										   Option option = NO_OPTION,
										   Security* security = 0 ) throw( Exception );

		// Copy constructor,
		explicit InternetProtocolVersion4( const InternetProtocolVersion4& other ) throw( Exception );

		// Assignment operator, handle correctly self assignment
		InternetProtocolVersion4& operator=( const InternetProtocolVersion4& other ) throw( Exception );

		// Move constructor,
		explicit InternetProtocolVersion4( InternetProtocolVersion4&& other ) throw( Exception );

		// Move Assignment operator,  handle correctly self assignment
		InternetProtocolVersion4& operator=( InternetProtocolVersion4&& other ) throw( Exception );

		// Destructor, when it is called, the user code existing in the destructor itself is executed first and then all the destructors
		// of the objects inside, in an opposite way from that they were constructed, in this case
		~InternetProtocolVersion4() throw();

        // To support Move semantics, the following 2 methods are added to every object. One function to set
        // the object into the default state, and the other to check if the object is in the default state

        // Use to set the object into his default state
        void SetToDefaultState() throw();

        // Use to check if the object is in default state, it will return true if it does, and false otherwise
        bool DefaultState() const throw();  


	private: 

		// These are all the required information from the user to create the datagram 

		// This object will store the address of the allocated space to contain the datagram ( header + data )
		UnsignedInteger32bits m_dataGram[ 1450 ];

		// Use to determine the amount of 32 bits required to contain the datagram
		DetermineTheAmountOf32bitsRequiredToContainTheDatagramIMP( dataLengthInBytes, option ) throw( std::bad_alloc, Exception );

	};  //  Class InternetProtocolVersion4








//	**************************************   END PART OF DECLRATIONS, IMPLMENTAION TIME   ************************************


			// Option number 1 - end of option list - when the options part does not use all of the last 32 bits 
			// ( the end of the internet header ), this will be used for padding the last bytes with 0 

			// Option number 2 - no operation - this option may be used between options, for example, to align
			// the beginning of a subsequent option on a 32 bits boundary

			// Option number 3 - security - this option provides a way for hosts to send security. If the user
			// requires the security option, this is the structure used to provide the specific details


			// Option number 4 - record route - this option provides a means to record the route of an internet datagram

			typedef struct RecordRoute
			{

				// This object will store the flag :
				// 0 - time stamps only 
				// 1 - each time stamp is preceded with internet address of the registering entity
				// 3 - the internet address fields are prespecified. An IP module only registers it's time stamp
				// if it matches it's own address with the next specified internet address
				UnsignedInteger8bits m_recordRouteOptionflag;

			}RecordRoute;

			// This object will store the record route option
			const RecordRoute* m_recordRoute;
				// This object will store the time stamp option length in bytes
				UnsignedInteger8bits m_timeStampOptionLength = 40;
				// This object will store the time stamp option type
				UnsignedInteger8bits m_timeStampOptionType = 68;


			// This object will store the security option type
			UnsignedInteger8bits m_securityOptionType = 130;

			// This object will store the security option length in bytes
			UnsignedInteger8bits m_securityOptionLength = 11;
				








	// Constructor, the data length in bytes can only be between 1 - 64KB, if the length is 0
	// the method will do nothing
	explicit InternetProtocolVersion4( const void* dataToSend,
									   UnsignedInteger16bits dataLengthInBytes,
									   UnsignedInteger32bits destinationAddress,
									   UnsignedInteger8bits protocol,
									   UnsignedInteger8bits typeOfService,
									   Option option = NO_OPTION,
									   Security* security = 0 ) throw( Exception )
	{
		// Check that the data length is not 0
		ThrowExceptionIfValueOneIsEqualToValueTwo( dataLengthInBytes, 0, "Failed to create the datagram, becuase the given data size is 0" );

		// Check if 1 datagram is not enough for the size of the data, then fragmentation is needed
		if (  )

		// Set the header into the datagram. If the data needs to be fragmented this 
		// Loop until all the data was sent
		for ( UnsignedInteger16bits remainingBytesOfData = dataLengthInBytes ; remainingBytesOfData > 0 ; remainingBytesOfData -= 4 )
		{

			// Determine current fragment 




			// Increase the amount of 32 bits required by 1
			amountOf32bits += 1;
		}
		// Set the datagram header 

		SetDatagramHeaderIMP(  )

		// Determine the required amount of UnsignedInteger32bits required for the datagram ( Header + data )
		// and allocate space accordingly





	}

	InternetProtocolVersion4DestanitionAddress

	// Copy constructor,
	InternetProtocolVersion4::InternetProtocolVersion4( const InternetProtocolVersion4& other ) throw( Exception );

	// Assignment operator, handle correctly self assignment
	InternetProtocolVersion4& InternetProtocolVersion4::operator=( const InternetProtocolVersion4& other ) throw( Exception );

	// Move constructor,
	InternetProtocolVersion4::InternetProtocolVersion4( InternetProtocolVersion4&& other ) throw( Exception );

	// Move Assignment operator,  handle correctly self assignment
    InternetProtocolVersion4& InternetProtocolVersion4::operator=( InternetProtocolVersion4&& other ) throw( Exception );

	// Destructor, when it is called, the user code existing in the destructor itself is executed first and then all the destructors
	// of the objects inside, in an opposite way from that they were constructed, in this case
	InternetProtocolVersion4::~InternetProtocolVersion4() throw();

    // Use to set the object into his default state
    void InternetProtocolVersion4::SetToDefaultState() throw();

    // Use to check if the object is in default state, it will return true if it does, and false otherwise
    bool InternetProtocolVersion4::DefaultState() const throw();




//	*****************************************   PRIVATE FUNCTIONS IMPLEMENTATION   ******************************************  









	// Use to determine the amount of 32 bits required for the datagram ( header + data )
	InternetProtocolVersion4::DetermineTheAmountOf32bitsRequiredForTheDatagramIMP( UnsignedInteger16bits dataLengthInBytes, Option option ) 
																														throw( std::bad_alloc, Exception )
	{
		// Check that the data length in bytes in not 0
		ThrowExceptionIfValueOneIsNotEqualToValueTwo( dataLengthInBytes, 0, "Determning the required amount of 32 bits failed, becuase the given length is 0" );

		// Create an object to store the required amount of 32 bits for the datagram.
		// The object is initialized to 5, becuase that is the minimum value for the
		// header 
		UnsignedInteger16bits amountOf32bits = 5;

		// Check if the security option is required
		if ( 0 != ( SECURITY & option ) )
		{
			// The security option is required

			// Set the amount of 32 bits to 16, becuase the security option required 11 bytes
			amountOf32bits = 16;
		}

		// Check if the record route or time stamp option is required
		if ( ( 0 != ( RECORD_ROUTE & option ) ) || ( 0 != ( TIME_STAMP & option ) ) )
		{
			// In either case the header legnth will be set to the maximum available

			// Set the amount of bits to the maximum available which is 256 bytes
			amountOf32bits = 256;
		}

		// Loop until there only 4 or less bytes left, this is the last 32 bit required
		for ( UnsignedInteger16bits remainingBytesOfData = dataLengthInBytes ; remainingBytesOfData <= 4 ; remainingBytesOfData -= 4 )
		{
			// Increase the amount of 32 bits required by 1
			amountOf32bits += 1;
		}

		// Return the required amount of 32 bits
		return ( amountOf32bits );
	}










// ******************************************   NESTED CLASS IMPLEMENTATION - SECURITY   ****************************************









	// Constrcutor, receive all the required information to initialize the security option
	inline Security::Securtiy( SecurityLevel securitLevel, 
		      UnsignedInteger16bits compartments, 
		      UnsignedInteger16bits handlingRestrictions,
		      UnsignedInteger32bits transmissionControlCode ) throw() :
	m_securityLevel( securitLevel ),
	m_compartments( compartments ),
	m_handlingRestrictions( handlingRestrictions ),
	m_transmissionControlCode( transmissionControlCode )
	{}

	// Destructor, all members of the class are automatically allocated and freed, nothing needs to be done
	inline Security::~Securtiy() throw()
	{}




\}  //   Namespace Universe

#endif  // __INTERNETPROTOCOLVERSION4_H__





