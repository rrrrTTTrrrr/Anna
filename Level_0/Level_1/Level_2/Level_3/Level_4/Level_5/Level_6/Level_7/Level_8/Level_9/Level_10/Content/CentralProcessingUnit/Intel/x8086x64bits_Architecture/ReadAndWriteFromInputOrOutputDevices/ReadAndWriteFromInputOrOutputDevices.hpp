namespace Universe
{


namespace CentralProcessingUnit
{


// In memory addressing, there's an address bus, a data bus and some control lines. The central processing unit, puts the address of
// a byte ( or a beginning byte ) of memory on the address bus, then raises the READ signal, and some RAM chip hopefully returns the
// contents of memory at that address by raising or lowering individual lines on the data bus. This works for both RAM and ROM.
//
// But then there are also input or output devices. Serial and parallel ports, the driver for a PC's tiny internal speaker, disk 
// controllers, sound chips and so on. And those devices also get read from and written to. They also need to be addressed so the
// central processing unit accesses the correct device and the correct data location within a given device.
//
// For some central processing unit models including the x86 series as found in most "modern" PCs, input or output devices share 
// the address space with memory. RAM, ROM and input output devices are connected to the same address, data and control lines. For
// example, the serial port for COM1 is addressed starting at 0x3F8. But there's almost certainly memory at the same address.
//
// Clearly the central processing unit needs to talk to either memory or the input or output device, never both. To distinguis
// between the two, one of the control lines called "M/#IO" asserts whether the central processing unit wants to talk to memory
// ( line = high ) or an input or output device ( line = low ).
//
// The 'IN' instruction reads from and input or output device, 'OUT' writes. When the 'IN' or 'OUT' instructions are used, the
// "M/#IO" is not asserted ( held low ), so memory doesn't responed and the input or output chip does. For the memory oriented
// instructions, "M/#IO" is asserted so central processing unit talks to RAM, and input or output devices stay out of the
// communication.
//
// Under certain conditions the input or output devices can drive the data lines and the RAM can read then at the same time, and
// vice versa. It's called direct memory access ( DMA ).
//
// Traditionalyy, serial and printer ports, as well as keyboard, mouse, temperature sensors and so forth were input or output
// devices. Disks were sort of in between, data transfers would be initiated by input or output commands but the disk controller
// would usually direct deposit its data in system memory.
//
// In modern operating systems like Windows or Linux, access to input or output ports is hidden away from "normal" user programs,
// and there are layers of software, privileged instructions and drivers to deal with the hardware. So in this century, most
// programmers don't deal with those instructions.



// Class Information :
//
//  Purpose :
//
//		Artifical Inteligence
//
//  Description :
//
//		1. This object is used only to wrap some static methods, which can be used without any instance of the object
//
//		2. This object has all the methods to create, destory, copy and move disabled to ensure that no instances of it will be created
//
// 		3. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
//		   providing 3 keywords :
//
//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
//						member is public all the encapsulation is lost, so it should be avoided in most cases
//
//			2. Protected - this part is for developing purposes, inheritance. A developer can inherit from this object and it will
//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few
//						   data members
//
//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this
//						 part will end with the suffix __Private
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
class ReadAndWriteFromInputOrOutputDevices NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = ReadAndWriteFromInputOrOutputDevices;


	// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object.
	// Satic functions only have access to static data members, which also don't belong to any instance, this means all other data members
	// can not be used. The only purpose then of declaring a static function is when a private static data member needs to be manipulated,
	// or some functionality needed that does not involve the non static data members


	// Method Information :
	//
	//  Description :
	//
	//		'IN' instruction copies the value from the input or output port specified with the second operand ( source operand ) to the
	//		destination operand ( first operand ). The source operand can be a byte immediate or the DX register. The destination operand
	//		can be register AL, AX, or EAX depending on the size of the port being accessed ( 8, 16 or 32 bits, respectively ). Using
	//		the DX register as a source operand allows input or output port addresses from 0 to 65,535 to be accessed. Using a byte
	//		immediate allows input or output port addresses 0 to 255 to be accessed.
	//
	//		When accessing an 8 bit input or output port, the opcode determines the port size. When accessing a 16 and 32 bit input or 
	//		output port, the operand size attribute determines the port size. At the machine code level, input or output instructions 
	//		are shorter when accessing 8 bit input or output ports. Here, the upper eight bits of the port address will be 0.
	//
	//		This instruction is only useful for accessing input or output ports located in the processors input or output address space.
	//
    //      Flags affected :
    //
    //          NONE
    //
    //      Hardware Exceptions :
    //
    //          1. #GP(0) - if the CPL is greater then ( has less privilege ) the input or output privilege level ( IOPL ) and any of the
    //						corresponding input or output permission bits in TSS for the input or output port being accessed is 1
    //          2. #UD - if the LOCK prefix is used
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          port - the input or output port number [0, 65535]
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      A byte with the result of reading from the input or output port
	//
	//  Expectations :
	//
	//		1. The given port number is valid
	//		2.
	//
	//  Possible errors :
	//
	//      They will come
	//
	EnsureRetrunValueIsUsed static inline UnsignedInteger8bits ReadByteFromInputOrOutputPort( const UnsignedInteger16bits port );


	// Method Information :
	//
	//  Description :
	//
	//		'IN' instruction copies the value from the input or output port specified with the second operand ( source operand ) to the
	//		destination operand ( first operand ). The source operand can be a byte immediate or the DX register. The destination operand
	//		can be register AL, AX, or EAX depending on the size of the port being accessed ( 8, 16 or 32 bits, respectively ). Using
	//		the DX register as a source operand allows input or output port addresses from 0 to 65,535 to be accessed. Using a byte
	//		immediate allows input or output port addresses 0 to 255 to be accessed.
	//
	//		When accessing an 8 bit input or output port, the opcode determines the port size. When accessing a 16 and 32 bit input or 
	//		output port, the operand size attribute determines the port size. At the machine code level, input or output instructions 
	//		are shorter when accessing 8 bit input or output ports. Here, the upper eight bits of the port address will be 0.
	//
	//		This instruction is only useful for accessing input or output ports located in the processors input or output address space.
	//
    //      Flags affected :
    //
    //          NONE
    //
    //      Hardware Exceptions :
    //
    //          1. #GP(0) - if the CPL is greater then ( has less privilege ) the input or output privilege level ( IOPL ) and any of the
    //						corresponding input or output permission bits in TSS for the input or output port being accessed is 1
    //          2. #UD - if the LOCK prefix is used
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          port - the input or output port number [0, 65535]
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      Two bytes with the result of reading from the input or output port
	//
	//  Expectations :
	//
	//		1. The given port number is valid
	//		2.
	//
	//  Possible errors :
	//
	//      They will come
	//
	EnsureRetrunValueIsUsed static inline UnsignedInteger16bits ReadTwoBytesFromInputOrOutputPort( const UnsignedInteger16bits port );


	// Method Information :
	//
	//  Description :
	//
	//		'IN' instruction copies the value from the input or output port specified with the second operand ( source operand ) to the
	//		destination operand ( first operand ). The source operand can be a byte immediate or the DX register. The destination operand
	//		can be register AL, AX, or EAX depending on the size of the port being accessed ( 8, 16 or 32 bits, respectively ). Using
	//		the DX register as a source operand allows input or output port addresses from 0 to 65,535 to be accessed. Using a byte
	//		immediate allows input or output port addresses 0 to 255 to be accessed.
	//
	//		When accessing an 8 bit input or output port, the opcode determines the port size. When accessing a 16 and 32 bit input or 
	//		output port, the operand size attribute determines the port size. At the machine code level, input or output instructions 
	//		are shorter when accessing 8 bit input or output ports. Here, the upper eight bits of the port address will be 0.
	//
	//		This instruction is only useful for accessing input or output ports located in the processors input or output address space.
	//
    //      Flags affected :
    //
    //          NONE
    //
    //      Hardware Exceptions :
    //
    //          1. #GP(0) - if the CPL is greater then ( has less privilege ) the input or output privilege level ( IOPL ) and any of the
    //						corresponding input or output permission bits in TSS for the input or output port being accessed is 1
    //          2. #UD - if the LOCK prefix is used
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          port - the input or output port number [0, 65535]
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      Four bytes with the result of reading from the input or output port
	//
	//  Expectations :
	//
	//		1. The given port number is valid
	//		2.
	//
	//  Possible errors :
	//
	//      They will come
	//
	EnsureRetrunValueIsUsed static inline UnsignedInteger32bits ReadFourBytesFromInputOrOutputPort( const UnsignedInteger16bits port );


	// Method Information :
	//
	//  Description :
	//
	//		'OUT' instruction copies the value from the second operand ( source operand ) to the input or output port specified with the
	//		destination operand ( first operand ). The source operand can be register AL, AX, or EAX depending on the size of the 
	//		port being accessed ( 8, 16 or 32 bits, respectively ). The destination operand can be a byte immediate or the DX register. 
	//		Using the DX register as a source operand allows input or output port addresses from 0 to 65,535 to be accessed. Using a byte
	//		immediate allows input or output port addresses 0 to 255 to be accessed.
	//
	//		When accessing an 8 bit input or output port, the opcode determines the port size. When accessing a 16 and 32 bit input or 
	//		output port, the operand size attribute determines the port size. At the machine code level, input or output instructions 
	//		are shorter when accessing 8 bit input or output ports. Here, the upper eight bits of the port address will be 0.
	//
	//		This instruction is only useful for accessing input or output ports located in the processors input or output address space.
	//
    //      Flags affected :
    //
    //          NONE
    //
    //      Hardware Exceptions :
    //
    //          1. #GP(0) - if the CPL is greater then ( has less privilege ) the input or output privilege level ( IOPL ) and any of the
    //						corresponding input or output permission bits in TSS for the input or output port being accessed is 1
    //          2. #UD - if the LOCK prefix is used
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          1. port - the input or output port number [0, 65535]
	//			2. value - the value that will be written to the input or output port
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      NONE
	//
	//  Expectations :
	//
	//		1. The given port number is valid
	//		2.
	//
	//  Possible errors :
	//
	//      They will come
	//
	static inline void WriteByteToInputOrOutputPort( const UnsignedInteger16bits port, const UnsignedInteger8bits value );


	// Method Information :
	//
	//  Description :
	//
	//		'OUT' instruction copies the value from the second operand ( source operand ) to the input or output port specified with the
	//		destination operand ( first operand ). The source operand can be register AL, AX, or EAX depending on the size of the 
	//		port being accessed ( 8, 16 or 32 bits, respectively ). The destination operand can be a byte immediate or the DX register. 
	//		Using the DX register as a source operand allows input or output port addresses from 0 to 65,535 to be accessed. Using a byte
	//		immediate allows input or output port addresses 0 to 255 to be accessed.
	//
	//		When accessing an 8 bit input or output port, the opcode determines the port size. When accessing a 16 and 32 bit input or 
	//		output port, the operand size attribute determines the port size. At the machine code level, input or output instructions 
	//		are shorter when accessing 8 bit input or output ports. Here, the upper eight bits of the port address will be 0.
	//
	//		This instruction is only useful for accessing input or output ports located in the processors input or output address space.
	//
    //      Flags affected :
    //
    //          NONE
    //
    //      Hardware Exceptions :
    //
    //          1. #GP(0) - if the CPL is greater then ( has less privilege ) the input or output privilege level ( IOPL ) and any of the
    //						corresponding input or output permission bits in TSS for the input or output port being accessed is 1
    //          2. #UD - if the LOCK prefix is used
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          1. port - the input or output port number [0, 65535]
	//			2. value - the value that will be written to the input or output port
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      NONE
	//
	//  Expectations :
	//
	//		1. The given port number is valid
	//		2.
	//
	//  Possible errors :
	//
	//      They will come
	//
	static inline void WriteTwoBytesToInputOrOutputPort( const UnsignedInteger16bits port, const UnsignedInteger16bits value );


	// Method Information :
	//
	//  Description :
	//
	//		'OUT' instruction copies the value from the second operand ( source operand ) to the input or output port specified with the
	//		destination operand ( first operand ). The source operand can be register AL, AX, or EAX depending on the size of the 
	//		port being accessed ( 8, 16 or 32 bits, respectively ). The destination operand can be a byte immediate or the DX register. 
	//		Using the DX register as a source operand allows input or output port addresses from 0 to 65,535 to be accessed. Using a byte
	//		immediate allows input or output port addresses 0 to 255 to be accessed.
	//
	//		When accessing an 8 bit input or output port, the opcode determines the port size. When accessing a 16 and 32 bit input or 
	//		output port, the operand size attribute determines the port size. At the machine code level, input or output instructions 
	//		are shorter when accessing 8 bit input or output ports. Here, the upper eight bits of the port address will be 0.
	//
	//		This instruction is only useful for accessing input or output ports located in the processors input or output address space.
	//
    //      Flags affected :
    //
    //          NONE
    //
    //      Hardware Exceptions :
    //
    //          1. #GP(0) - if the CPL is greater then ( has less privilege ) the input or output privilege level ( IOPL ) and any of the
    //						corresponding input or output permission bits in TSS for the input or output port being accessed is 1
    //          2. #UD - if the LOCK prefix is used
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          1. port - the input or output port number [0, 65535]
	//			2. value - the value that will be written to the input or output port
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      NONE
	//
	//  Expectations :
	//
	//		1. The given port number is valid
	//		2.
	//
	//  Possible errors :
	//
	//      They will come
	//
	static inline void WriteFourBytesToInputOrOutputPort( const UnsignedInteger16bits port, const UnsignedInteger32bits value );


	DEBUG_TOOL(

		// This part of the object is dedicated for testing :


		// Method Information :
		//
		//  Description :
		//
		//		This method is used to test the object. It is not part of the implementation, it is only used to find problems with the code
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			NONE
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//			NONE
		//
		//  Expectations :
		//
		//		Please let the test pass lord!!
		//
		//  Possible errors :
		//
		//		It says there are no problems, which is even scarier, did I just wrote a working code??
		//
		static void UnitTest() __attribute__ (( __unused__ ));

	)  //  End of debug tool


private:


	// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
	NoInstances( ReadAndWriteFromInputOrOutputDevices );


};  //  Class ReadAndWriteFromInputOrOutputDevices