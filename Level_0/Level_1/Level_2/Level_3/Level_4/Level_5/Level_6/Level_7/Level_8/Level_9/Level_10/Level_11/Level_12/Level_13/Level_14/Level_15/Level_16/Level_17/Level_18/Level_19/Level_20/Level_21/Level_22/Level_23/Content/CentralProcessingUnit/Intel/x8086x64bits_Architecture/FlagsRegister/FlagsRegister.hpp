namespace Universe
{


namespace CentralProcessingUnit
{



// 1. CLAC - Clear AC flag in RFLAGS register
// 2. STAC - Set AC flag in RFLAGS register



// It contains a group of status flags, a control flag, and a group of system flags. Following initialization of the processor ( either by asserting the RESET pin or the INIT
// pin ), the state of the RFLAGS is 0x000000000000002H. Bits 1,3,5,15 and 22-31 of this register are reserved. Software should not use or depend on the states of any of 
// these bits
// 
// Some of the flags in the RFLAGS register can be modified directly, using special purpose instructions. There are no instructions that allow the whole register to be examined
// or modified directly
// 
// The following instructions can be used to move groups of flags to and from the procedure stack or the RAX register :
// 
//       LAHF, SAHF, PUSHF, PUSHFD, POPF and POPFD
// 
// After the contents of the RFLAGS register have been transferred to the procedure stack or the RAX register, the flags can be examined and modified using the processor's bit
// manipulation instructions ( BT, BTS, BTR and BTC ).
// 
// When suspending a task, the processor automatically saves the state of the RFLAGS register in the trask state segment ( TSS ) for the task being suspended. When binding
// itself to a new task, the processor loads the RFLAGS register with data from the new task's TSS
// 
// When a call is made to an interrupt or exception handler procedure, the processor automatically saves the state of the RFLAGS register on the procedure stack. When an 
// interrupt or exception is handled with a task switch, the state of the RFLAGS register is saved in the TSS for the task been suspended
// 
// Status flags :
// 
// The status flags ( bits 0,2,4,6,7 and 11 ) of the RFLAGS register indicate the results of arithmetic instructions :
// 
//   CF ( bit 0 ) - carry flag - set if an arithmetic operations generated a carry or a borrow out of the most significant bit of the result
//   PF ( bit 2 ) - parity flag - set if the least significant byte of the result contains an even number of 1 bits
//   AF ( bit 4 ) - auxiliary carry flag - set if an arithmetic operation generates a carry or a borrow out of bit 3 of the result. Used in binary coded decimal ( BCD )
//   ZF ( bit 6 ) - zero flag - set it the result is zero
//   SF ( bit 7 ) - sign flag - set equal to the most signigicant bit of the result, which is the sign bit of a signed integer
//   OF ( bit 11 ) - overflow flag - set if the integer result is too large a positive number or too small a negative number to fit in the destination operand
// 
// Only the CF flag can be modified directly, using the STC, CLC and CMC instructions. Also the bit instructions ( BT, BTS, BTR and BTC ) copy a specified bit into the CF flag.
//
// The status flags allow a single arithmetic operation to produce results for three different data types - unsigned integers, signed integers and BCD integers. If the result
// of an arithmetic operations is treated as an unsigned integer, the CF flag indicates an out of range condition ( carry or a borrow ). If the result is treated as a signed
// integer ( two's complement number ), the OF flag indicates a carry or borrow. And if treated as a BCD digit, the AF flag indicates a carry or borrow. The SF flag indicates
// the sign of a signed integer. The ZF flag indicated either a signed or an unsigned integer is zero
//
// The condition instructions Jcc ( jump on condition code cc ), SETcc ( byte set on condition code cc ), LOOPcc, and CMOVcc ( conditional move ) use one or more of the status
// flags as condition codes and test them for branch, set-byte or end loop conditions
//
// The direction flag DF, controls string instructions ( MOVS, CMPS, SCAS, LODS and STOS ). Setting the DF flag causes the string instructions to auto decrement ( to process
// strings from high addresses to low addresses ). Clearing the DF flag causes the string instructions to auto increment ( to process strings from low addresses to high
// addresses ). The STD and CLD instructions set and clear the DF flag, respectively
//
// System flags and IOPL field :
//
// The system flags and IOPL field in the RFLAGS register control operating system or executive operations. They should not be modified by application programs!
//
//  TF ( bit 8 ) - Trap flag - set to enable single step mode for debugging, clear to disable single step mode
//  IF ( bit 9 ) - Interrupt enable flag - controls the response of the processor to maskable interrupt requests. Set to respond to maskable interrupts, cleared to inhibit interrupts
//  IOPL ( bits 12 and 13 ) - I/O privilege level field - indicates the I/O privilege level of the currently running program or task. The current privilege level ( CPL ) of the
//                            currently running program or task must be less than or equal to the I/O privilege level to access the I/O address space. The POPF and IRET instructions
//                            can modify this field only when operating at a CPL of 0
//  NT ( bit 14 ) - Nested task flag - controls the chaining of interrupted and called tasks. Set when the current task is linked to the previously executed task, cleared otherwise
//  RF ( bit 16 ) - Resume flag - controls the processor's response to debug exceptions
//  VM ( bit 17 ) - Virtual-8086 mode flag - set to enable virtual 8086 mode
//  AC ( bit 18 ) - Alignment check ( or access control ) flag -
//  VIF ( bit 19 ) - Virtual interrupt flag - virtual image of the IF flag. Used in conjunction with the VIP flag
//  VIP ( bit 20 ) - Virtual interrupt pending flag - set to indicate that an interrupt is pending, clear otherwise. Software sets and clears this flag, the processor only reads it
//  ID ( bit 21 ) - Identification flag - the ability of a program to set or clear this flag indicates support for the CPUID instruction



// Load status flags into AH part register ( LAHF ) :
//
//  The assembly instruction will load the following flags, into the AH part of the RAX register :
//
//      1. Sign flag
//      2. Zero flag
//      3. Auxiliary flag
//      4. Parity flag
//      5. Carry flag
//
// There are 3 remainning bits unused 3,5,7. The first 2 will have the value 0, and the last one will have the value 1. They will be located at bits 3,5,7.
//
//  The AH part of the register RAX will store each of this flags as follows :
//
//          Bit     ->        1               2               3               4               5                6                 7                8
//
//          Flag    ->    Sign flag       Zero flag       Unused 0    Auxiliary flag      Unsued 0        Parity flag         Unused 1        Carry flag
//
//  This instruction is valid in 64 bit mode only if :
//
//      CPUID.80000001H:ECX.LAHF-SAHF[bit 0] = 1
//
// Flags affected :
//
//  None!
//
// Exceptions :
//
//  #UD - if the lock prefix is used or if :
//
//      CPUID.80000001H:ECX.LAHF-SAHF[bit 0] = 0



// Store the AH part of the RAX register into the status flags register ( SAHF ) :
//
//  The assembly instruction will set the following flags :
//
//      1. Sign flag
//      2. Zero flag
//      3. Auxiliary flag
//      4. Parity flag
//      5. Carry flag
//
// There are 3 remainning bits unused 3,5,7. The first 2 will have the value 0, and the last one will have the value 1. They will be located at bits 3,5,7.
//
//  The AH part of the register RAX will store each of this flags as follows :
//
//          Bit     ->        1               2               3               4               5                6                 7                8
//
//          Flag    ->    Sign flag       Zero flag       Unused 0    Auxiliary flag      Unsued 0        Parity flag         Unused 1        Carry flag
//
//  This instruction is valid in 64 bit mode only if :
//
//      CPUID.80000001H:ECX.LAHF-SAHF[bit 0] = 1
//
// Flags affected :
//
//  None!
//
// Exceptions :
//
//  #UD - if the lock prefix is used or if :
//
//      CPUID.80000001H:ECX.LAHF-SAHF[bit 0] = 0



// Push RFLAGS onto the stack ( PUSHFQ ) :
//
//  Decrements the stack pointer ( RSP ) by 8 bytes and pushes the entire RFLAGS register onto the stack. The Virtual-8086 mode flag ( VM ) and resume 
//  flag ( RF ) are not copied, the bit state in their location will be off ( 0 ). 
//
// Flags affected :
//
//  None!
//
// Exceptions :
//
//  #GP(0) - if the memory address is in a non canonical form
//  #SS(0) - if the stack address is in a non canonical form
//  #PF(fault-code) - if a page faule occures
//  #AC(0) - if an unaligned memory reference is made while the current privilege level is 3 and alignment checking is enabled
//  #UD - if the lock prefix is used



// Set the RFLAGS from the last 8 byte of the stack ( POPFQ ) :
//
// The following diagram shows three things. The first is the flags that can be set using this instruction. The second is the flags that can not be set
// and their state will stay the same. And third one flag that will be cleared. Remember the 32 high significant bits are reserved and therefore will not
// appear in the diagram :
//
//	Mnemonic 			->		ID   VIP  VIF  AC    VM   RF  NT   IOPL    OF    DF    IF    TF    SF    ZF    AF    PF    CF
//  Bit                 ->      21   20   19   18    17   16  14   13:12   11    10    9     8     7     6     4     2     0
//
//  Can be set or not   ->     Yes   No   No   Yes   No   0   Yes   Yes   Yes   Yes   Yes   Yes   Yes   Yes   Yes   Yes   Yes
//
// Flags affected :
//
//  None!
//
// Exceptions :
//
//  #GP(0) - if the memory address is in a non canonical form
//  #SS(0) - if the stack address is in a non canonical form
//  #PF(fault-code) - if a page faule occures
//  #AC(0) - if an unaligned memory reference is made while the current privilege level is 3 and alignment checking is enabled
//  #UD - if the lock prefix is used



// Class Information :
//
//  Purpose :
//
//		Artifical Inteligence
//
//  Description :
//
// 		1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
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
class FlagsRegister NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = FlagsRegister;


	// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
	// the compiler generates a basic behavior for them if possible :


	// Method Information :
	//
	//  Description :
	//
	//		Default Constructor,
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
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline FlagsRegister();


	// Method Information :
	//
	//  Description :
	//
	//		Copy constructor, will operate correctly even if the other instance is in default state or self assignment
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a reference to the instance that should be copied
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline FlagsRegister( const SelfType& other );


	// This macro will be used to add all the functionality that is similiar in each object ( beside the name of the object ). It is done
	// as a macro to allow simple text manipulation, instead of inherting it through an object, which becomes a problem when an object
	// inherits from 2 objects, the first is any object, but the second is an object that also inhrits from the first object. This can be
	// solved through virtual inheritance but then can only be one instance of it. Furthermore, each object in the system will need to
	// inherit from it, which will cause inheritance 'chaos'. Therefore, this macro will be used to add the following methods to each object :
	//
	//		1. Assigenment operator
	//		2. Move constructor
	//		3. Move assigenment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure( FlagsRegister )


	// Method Information :
	//
	//  Description :
	//
	//		Destructor, does not throw
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
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline ~FlagsRegister() = default;


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to check if carry bit is ON in the flags register. Note - the method the returns the state of the
	//		bit from the last time the hardware flags register was loaded, for the most recent state reset the instance, so it would
	//		load the current hardware flags register content
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
	//		If the carry bit is ON in the flags register
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Boolean IsEnabled_Carry() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the carry bit in the flags register. Note - the method the returns the state of the
	//		bit from the last time the hardware flags register was loaded, for the most recent state reset the instance, so it would
	//		load the current hardware flags register content
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
	//		The carry bit in the flags register
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Memory::Bit< UnsignedInteger64bits > Carry();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to check if parity bit is ON in the flags register. Note - the method the returns the state of the
	//		bit from the last time the hardware flags register was loaded, for the most recent state reset the instance, so it would
	//		load the current hardware flags register content
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
	//		If the parity bit is ON in the flags register
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Boolean IsEnabled_Parity() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the parity bit in the flags register. Note - the method the returns the state of the
	//		bit from the last time the hardware flags register was loaded, for the most recent state reset the instance, so it would
	//		load the current hardware flags register content
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
	//		The parity bit in the flags register
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Memory::Bit< UnsignedInteger64bits > Parity();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to check if auxiliary bit is ON in the flags register. Note - the method the returns the state of the
	//		bit from the last time the hardware flags register was loaded, for the most recent state reset the instance, so it would
	//		load the current hardware flags register content
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
	//		If the	the auxiliary is ON bit in the flags register
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Boolean IsEnabled_Auxiliary() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the auxiliary bit in the flags register. Note - the method the returns the state of the
	//		bit from the last time the hardware flags register was loaded, for the most recent state reset the instance, so it would
	//		load the current hardware flags register content
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
	//		The auxiliary bit in the flags register
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Memory::Bit< UnsignedInteger64bits > Auxiliary();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to check if zero bit is ON in the flags register. Note - the method the returns the state of the
	//		bit from the last time the hardware flags register was loaded, for the most recent state reset the instance, so it would
	//		load the current hardware flags register content
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
	//		If the zero bit is ON in the flags register
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Boolean IsEnabled_Zero() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the zero bit in the flags register. Note - the method the returns the state of the
	//		bit from the last time the hardware flags register was loaded, for the most recent state reset the instance, so it would
	//		load the current hardware flags register content
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
	//		The zero bit in the flags register
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Memory::Bit< UnsignedInteger64bits > Zero();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to check if sign bit is ON in the flags register. Note - the method the returns the state of the
	//		bit from the last time the hardware flags register was loaded, for the most recent state reset the instance, so it would
	//		load the current hardware flags register content
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
	//		If the sign bit is ON in the flags register
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Boolean IsEnabled_Sign() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the sign bit in the flags register. Note - the method the returns the state of the
	//		bit from the last time the hardware flags register was loaded, for the most recent state reset the instance, so it would
	//		load the current hardware flags register content
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
	//		The sign bit in the flags register
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Memory::Bit< UnsignedInteger64bits > Sign();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to check if overflow bit is ON in the flags register. Note - the method the returns the state of the
	//		bit from the last time the hardware flags register was loaded, for the most recent state reset the instance, so it would
	//		load the current hardware flags register content
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
	//		If the overflow is ON bit in the flags register
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Boolean IsEnabled_Overflow() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the overflow bit in the flags register. Note - the method the returns the state of the
	//		bit from the last time the hardware flags register was loaded, for the most recent state reset the instance, so it would
	//		load the current hardware flags register content
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
	//		The overflow bit in the flags register
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Memory::Bit< UnsignedInteger64bits > Overflow();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to set the hardware flags register with the content of this instance. Note - only the following bits can be set :
	//
    //		Mnemonic 			->		ID   VIP  VIF  AC    VM   RF  NT   IOPL    OF    DF    IF    TF    SF    ZF    AF    PF    CF
    //  	Bit                 ->      21   20   19   18    17   16  14   13:12   11    10    9     8     7     6     4     2     0
    //
    //  	Can be set or not   ->     Yes   No   No   Yes   No   0   Yes   Yes   Yes   Yes   Yes   Yes   Yes   Yes   Yes   Yes   Yes
    //
    //		Note - Bit 16, RF, will be cleared, means it will be set off!
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
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void SetHardwareFlagsRegister() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to create a string with the state of the flags register
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
	//		A string with the state of the flags register
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline Language::String ToString() const;


	// The following methods declare the overloaded operators for the object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to check if the this instance match the other
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a reference to the instance that should be compared with this object
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		1. true - if the 2 instances are the same
	//		2. false - otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Boolean operator==( const SelfType& other ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to check if the this instance does not match the other
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a reference to the instance that should be compared with this object
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		1. true - if the 2 instances are not the same
	//		2. false - otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Boolean operator!=( const SelfType& other ) const;


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


    // This object will store a copy the RFLAGS register content
    UnsignedInteger64bits member_flagsRegister;


};  //  Class FlagsRegister