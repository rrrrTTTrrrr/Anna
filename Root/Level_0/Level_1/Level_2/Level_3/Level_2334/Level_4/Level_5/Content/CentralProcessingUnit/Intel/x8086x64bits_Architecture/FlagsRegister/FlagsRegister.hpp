#ifndef  INTEL_CENTRALPROCESSINGUNITFLAGS_HPP
#define  INTEL_CENTRALPROCESSINGUNITFLAGS_HPP


#include "../Definitions/VariableTypesDefinitions.hpp"  //  Typedef
#include "../BasicUtilities/C++/cpp_BasicUtilities.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../Memory/MemoryOperations/Swap/Swap.hpp"  //  Class Swap
#include "../Abilities/State/State.hpp"  //  Class State
#include "../../../../DataTypes/Bit/Bit.hpp"  //  Class Bit


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../ErrorHandling/Assert/Assert.hpp"  //  Class Assert
#endif


namespace Universe
{

    namespace CentralProcessingUnit
    {


    	// This is used when only declaring the object in this source file will be enough to pass compilation. The implementation is given to the compiler through the
    	// cpp source file that the object is nested within
    	//
    	// Forward declarations :
    	//
    	//  NONE
    	//



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
#    1. CLAC - Clear AC flag in RFLAGS register
#    2. STAC - Set AC flag in RFLAGS register


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
    	//		1. This object inherits from the object "State" to allow each instance of this object to have a defined state
    	//
    	// 		2. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by providing 3 keywords :
    	//
    	//				1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the obejct using the tools
    	//							presented here. This part will usually contain only methods and not data members. If a data member is public all the encapsulation is
    	//							lost, so it should be avoided in most cases
    	//
    	//				2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will be able to access
    	//							   all the data and methods inside this part. This part will usually containt some methods and few data members
    	//
    	//				3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object and all the
    	//							 methods the developer needed to implement the interface presented in the public part. Every method in this part will end with the
    	//							 suffix _IMP
    	//
    	//  Expectations :
    	//
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//		Too many to count
    	//
    	class Intel_CentralProcessingUnitFlags NotForInheritance : public Abilities::State
    	{
    	public:


            // The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler
            // generates a basic behavior for them :


            // Method Information :
    	    //
    	    //  Description :
            //
    		//   	Default Constructor,
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
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
    		//
    		//		They will come
    		//
    		inline Intel_CentralProcessingUnitFlags();


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
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
    		//
    		//		They will come
    		//
    		explicit inline Intel_CentralProcessingUnitFlags();


			// Method Information :
    		//
    		//  Description :
    		//
    		//   	Copy constructor, will operate correctly even if the other instance is in default state or self assignment
    		//
    		//  Required arguments :
    		//
    	    //   	User information needed :
    		//
    		//          other - a reference to the instance that should be copied
    		//
    		//		Information returned to the user :
    		//
    		//          NONE
    		//
    		//  Return value :
    		//
    		//   	NONE
    		//
    		//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
    		//
    		//		They will come
    		//
    		inline Intel_CentralProcessingUnitFlags( const Intel_CentralProcessingUnitFlags& other );


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
    		//			other - a reference to the instance that should be copied
    		//
    		//		Information returned to the user :
    		//
    		//          NONE
    		//
    		//  Return value :
    		//
    		//   	A reference to this instance
    		//
    		//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
    		//
    		//		They will come
    		//
    		inline Intel_CentralProcessingUnitFlags& operator=( const Intel_CentralProcessingUnitFlags& other );


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
    		//          other - a reference to the instance that should be moved
    		//
    		//      Information returned to the user :
    		//
    		//          NONE
    		//
    		//  Return value :
    		//
    		//   	NONE
    		//
    		//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
    		//
    		//		They will come
    		//
    		inline Intel_CentralProcessingUnitFlags( Intel_CentralProcessingUnitFlags&& other );


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
    		//          other - a reference to the instance that should be moved
    		//
    		//      Information returned to the user :
    		//
    		//          NONE
    		//
    		//  Return value :
    		//
    		//   	A reference to this instance
    		//
    		//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
    		//
    		//		They will come
    		//
    		inline Intel_CentralProcessingUnitFlags& operator=( Intel_CentralProcessingUnitFlags&& other );


    		// Method Information :
    		//
    		//  Description :
    		//
    		//      This method is used to swap the content between this instance and the other one
    		//
    		//  Required arguments :
    		//
    		//      User information needed :
    		//
    		//          other - a reference to the instance that should be swaped
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
			//		NONE
			//
			//  Possible errors :
    		//
    		//      They will come
    		//
    		inline void Swap( Intel_CentralProcessingUnitFlags& other );


    		// Method Information :
    		//
    		//  Description :
    		//
    		//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
    		//
    		//  Required arguments :
    		//
    		//      User information needed :
    		//
    		//			NONE
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
			//		NONE
			//
			//  Possible errors :
    		//
    		//		They will come
    		//
    		inline void Reset();


    		// Method Information :
    		//
    		//  Description :
    		//
    		//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
    		//
    		//  Required arguments :
    		//
    		//      User information needed :
    		//
    		//			NONE
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
    		//		NONE
    		//
    		//  Possible errors :
    		//
    		//		They will come
    		//
    		inline void Initiate();


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
    		//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
    		//
    		//		They will come
    		//
    		inline ~Intel_CentralProcessingUnitFlags() = default;


    		// The following methods give access and manipulate the data inside this object :











    		// The following methods declare the overloaded operators for the object :


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
    		//          other - a reference to the instance that should be compared with this object
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
    		//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
    		//
    		//		They will come
    		//
    		Boolean operator==( const Intel_CentralProcessingUnitFlags& other ) const;


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
    		//          other - a reference to the instance that should be compared with this object
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
    		//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
    		//
    		//		They will come
    		//
    		inline Boolean operator!=( const Intel_CentralProcessingUnitFlags& other ) const;


    		// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have
    		// access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring
    		// a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members


    		DEBUG_TOOL(

    			// This part of the object is dedicated for testing :


    			// Method Information :
    			//
    			//  Description :
    			//
    			//      This method is used to test the object. It is not part of the implementation, it is only used to find problems with the code
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
    			static void Test();

    		)  //  End of debug tool


    	private:


            // This object will store a copy the RFLAGS register content
            UnsignedInteger64bits member_RFLAGS; 


        	// Static data members do not belong to any instance, they belong to the object. Like every global variable it is created with the start of the program
    		// and only destroyed when the program ends. The access to the static member is bound to this object of course


    		// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
    		// rather help implement it :


    		// Friend class or friend function can access private and protected members of other object in which it is declared as friend. It is sometimes useful
    		// to allow a particular object to access private members of other object. The declration of such function is private, because these functions are part
    		// of the implemntation, which the user should not be aware of. The use of this functions is not limited to the object's scope. One of the problems that
    		// friend declaration solves is when the object needs to be as a right side operand in expressions. Every method in the object is implicitly added a pointer
    		// to the location of the object data with the name "this", and to enable this the method must be called from an existing instance. This means that the
    		// object can only be implemented as the left side operand of an expression with methods, and friend functions and objects does not have this limitation


    	};  //  Class Intel_CentralProcessingUnitFlags

























//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************
























    	// Method Information :
    	//
    	//  Description :
    	//
    	//   	Default Constructor, it will load the content of the RFLAGS register into a location it can be examined. The RFLAGS register will be changed
        //      afterwards in the flow of the program, therefore the value in this instance will not be updated. If the current content of the RFLAGS register
        //      is needed reload the value using the "Initiate" method
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
    	//  Expectations :
    	//
    	//		1. The current central processor unit is made by Intel, and therefore the RFLAGS register exist
        //      2. 
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	inline Intel_CentralProcessingUnitFlags::Intel_CentralProcessingUnitFlags() :
        State( State::States::Ready ),
        member_RFLAGS( 0 )
    	{

            // The following is an extended inline assembly statement. It will be used to load the current RFLAGS register content so it can be examined. 
            // This is not possible using only C++
            __asm__ volatile ( "PUSHFQ\n\t"                             /* Assembly code */
                               "POPQ RAX\n\t" 
                               "MOV %[RFLAGS], RAX\n\t"
                               : [RFLAGS] "=im" ( member_RFLAGS )       /* Output arguments */
                               :                                        /* Input arguments */
                               : "memory" );                            /* Clobbers and scratch registers */

        }


    	// Method Information :
    	//
    	//  Description :
    	//
    	//   	Copy constructor, will operate correctly even if the other instance is in default state or self assignment
    	//
    	//  Required arguments :
    	//
    	//   	User information needed :
    	//
    	//          other - a reference to the instance that should be copied
    	//
    	//		Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//   	NONE
    	//
    	//  Expectations :
    	//
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	inline Intel_CentralProcessingUnitFlags::Intel_CentralProcessingUnitFlags( const Intel_CentralProcessingUnitFlags& other ) :
        State( other ),
    	member_RFLAGS( other.member_RFLAGS )
    	{}


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
    	//			other - a reference to the instance that should be copied
    	//
    	//		Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//   	A reference to this instance
    	//
    	//  Expectations :
    	//
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	inline Intel_CentralProcessingUnitFlags& Intel_CentralProcessingUnitFlags::operator=( const Intel_CentralProcessingUnitFlags& other )
    	{
    		// Create a copy of the other instance
    		Intel_CentralProcessingUnitFlags copyOfOther( other );

    		// Swap between this instance and the copy of the other one, this will leave the copy instance with the old data, and it will be deleted
    		Swap( copyOfOther );

    		// Return a reference to this instance
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
    	//          other - a reference to the instance that should be moved
    	//
    	//      Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//   	NONE
    	//
    	//  Expectations :
    	//
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	inline Intel_CentralProcessingUnitFlags::Intel_CentralProcessingUnitFlags( Intel_CentralProcessingUnitFlags&& other ) :
    	Intel_CentralProcessingUnitFlags()
    	{
    		// Swap between this instance, which is in default state, and the other one
    		Swap( other );
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
    	//          other - a reference to the instance that should be moved
    	//
    	//      Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//   	A reference to this instance
    	//
    	//  Expectations :
    	//
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	inline Intel_CentralProcessingUnitFlags& Intel_CentralProcessingUnitFlags::operator=( Intel_CentralProcessingUnitFlags&& other )
    	{
    	    // Create a default constructed instance
    	    Intel_CentralProcessingUnitFlags defaultConstructedInstance;

    	    // Swap between the temporary instance, which is in default state, and the other instance, this will leave the other instance in default state
    	    defaultConstructedInstance.Swap( other );

    	    // Swap between this instance and the temporary one
    	    Swap( defaultConstructedInstance );

    	    // Return a reference to this instance
    	    return ( *this );
    	}


    	// Method Information :
    	//
    	//  Description :
    	//
    	//      This method is used to swap the content between this instance and the other one
    	//
    	//  Required arguments :
    	//
    	//      User information needed :
    	//
    	//		other - a reference to the instance that should be swaped
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
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//      They will come
    	//
    	void Intel_CentralProcessingUnitFlags::Swap( Intel_CentralProcessingUnitFlags& other )
    	{
    	    // Swap betwen the state instances
    	    Abilities::State::Swap( other );

            // Swap between the RFLAGS content
            Memory::Swap< UnsignedInteger64bits >( member_RFLAGS, other.member_RFLAGS );
    	}


    	// Method Information :
    	//
    	//  Description :
    	//
    	//      Use this method to take an instance already initialized, delete the current resources and set it to default state
    	//
    	//  Required arguments :
    	//
    	//      User information needed :
    	//
    	//			NONE
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
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	inline void Intel_CentralProcessingUnitFlags::Reset()
    	{
    	    // Create a default constructed instance. Swap it with this instance, which will be left in default state. When control leaves this method it will delete the
    	    // old resources
    	    Intel_CentralProcessingUnitFlags defaultConstructedInstance;

    	    // Swap between this instance and the default constructed instance
    	    Swap( defaultConstructedInstance );
        }


    	// Method Information :
    	//
    	//  Description :
    	//
    	//      Use this method to take an instance in default state and prepare it for work. The method will have the same effect on instances already initialized. Each
    	//		constructor except for the default constructor, should have a corresponding "Initiate" method. This will provide the functionality to take the instance out
    	//		of default state, into the options presented by the constructors. The constructor that will be used is the default constructor.
    	//
    	//  Required arguments :
    	//
    	//      User information needed :
    	//
    	//			NONE
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
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	inline void Intel_CentralProcessingUnitFlags::Initiate()
    	{
    	    // Use the required constructor to create an instance. It will be swaped with this instance, leaving this instance with the new data. When sequence control will
    	    // leave this scope it delete the old data if exist
    	    Intel_CentralProcessingUnitFlags instanceCreatedUsingTheRequiredConstructor();

    	    // Swap between this instance and the temporary instance
    	    Swap( instanceCreatedUsingTheRequiredConstructor );
        }



        //   CF ( bit 0 ) - carry flag - set if an arithmetic operations generated a carry or a borrow out of the most significant bit of the result
        //   PF ( bit 2 ) - parity flag - set if the least significant byte of the result contains an even number of 1 bits
        //   AF ( bit 4 ) - auxiliary carry flag - set if an arithmetic operation generates a carry or a borrow out of bit 3 of the result. Used in binary coded decimal ( BCD )
        //   ZF ( bit 6 ) - zero flag - set it the result is zero
        //   SF ( bit 7 ) - sign flag - set equal to the most signigicant bit of the result, which is the sign bit of a signed integer
        //   OF ( bit 11 ) - overflow flag - set if the integer result is too large a positive number or too small a negative number to fit in the destination operand


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to get the state of the carry flag ( bit 0 )
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
        //      A boolean describing the carry flag state
        //
        //  Expectations :
        //
        //      1. The instance should not be in default state
        //      2.
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline Boolean Intel_CentralProcessingUnitFlags::Carry() const
        {
            // This will be added only in test mode, to ensure that the given data to the method is valid
            ASSERT( ( GetState() != State::States::Default ), "Intel_CentralProcessingUnitFlags::Carry failed - the instance is in default state" )

        	// Return the state of the carry flag ( bit 0 ) 
            return ( DataTypes::Bit( &member_RFLAGS, 0 ).State() );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to get the state of the parity flag ( bit 2 )
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
        //      A boolean describing the parity flag state
        //
        //  Expectations :
        //
        //      1. The instance should not be in default state
        //      2.
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline Boolean Intel_CentralProcessingUnitFlags::Parity() const
        {
            // This will be added only in test mode, to ensure that the given data to the method is valid
            ASSERT( ( GetState() != State::States::Default ), "Intel_CentralProcessingUnitFlags::Parity failed - the instance is in default state" )

        	// Return the state of the parity flag ( bit 2 ) 
            return ( DataTypes::Bit( &member_RFLAGS ), 2 ).State() );
        }


























//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************
































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
    	//          other - a reference to the instance that should be compared with this object
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
    	//  Expectations :
    	//
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//      1. The template type object does not have the comparison operator ( == )
    	//      2. 
    	//
    	Boolean Intel_CentralProcessingUnitFlags::operator==( const Intel_CentralProcessingUnitFlags& other ) const
    	{
            // Check if the content of the RFLAGS member match in both instances
            return ( member_RFLAGS == other.member_RFLAGS );
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
    	//          other - a reference to the instance that should be compared with this object
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
    	//  Expectations :
    	//
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//      1. The template type object does not have the comparison operator ( == )
    	//      2. 
    	//
    	inline Boolean Intel_CentralProcessingUnitFlags::operator!=( const Intel_CentralProcessingUnitFlags& other ) const
    	{
    		// Return the negotiated value from the equal operator
    		return ( !( *this == other ) );
    	}






































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



















































































//  ********************************************************   TEMPLATE OR INLINE PURE VIRTUAL METHODS IMPLEMENTATION   *********************************************************



















































































//	**********************************************************   TEMPLATE OR INLINE PROTECTED METHODS IMPLEMENTATION   **********************************************************



















































































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



















































































// ***************************************************************   NESTED CLASS PUBLIC METHODS IMPLEMENTATION -    ************************************************************



















































































// **********************************************************   INLINE AND TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   ***********************************************************



















































































    }  //  Namespace CentralProcessingUnit

}  //  Namespace Universe



#endif  // INTEL_CENTRALPROCESSINGUNITFLAGS_HPP