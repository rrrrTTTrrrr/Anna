namespace Universe
{


namespace CentralProcessingUnit
{



// Class Information :
//
//  Purpose :
//
//      Use this object to perform operations with no interruption on a memory address, which is shared by multiple central processing units!
//
//      In loading and storing, computer hardware carries out writing and reading to a word-sized memory. To fetch, add or subtract, value augmentation 
//      takes place through uninterrupted operations. During an uninterrupted operation, a central processing unit can read and write a location during 
//      the same data transmission. In this way, another input/output mechanism or central processing unit cannot perform memory reading or writing tasks 
//      until the operation has finished!
//
//      In it's simplest form a bus helps 2 entities talk directly to each other. And in the not so simple case, a bus may have three or more devices 
//      connected. In this case bus addresses are needed to identify each entity!
//
//      Now if multiple entities are connected on a single bus, generally they can not all communicate at the same time. There must be a mechanism to allow
//      this. Therefore, the entities should be able to know who is communicating with who at the moment. Bus locking as a broad term means any deviation
//      from the usual pattern, where two entities reserve the bus for their mutual communication. The things get more complex with DMA
//
//      To conclude, this object allows to read and write to a memory address, while no other central processing unit can also access it!
//
//      The central processing unit support this functionality using the LOCK# signal!
//
//      The LOCK prefix causes the processor's LOCK# signal during execution of the accompanying instruction. In a multiprocessor environment the LOCK#
//      signal ensures that the processor has exclusive use of any shared memory while the signal is asserted. The LOCK prefix can be prepended only to
//      the following instructions and only to those forms of the instructions where the destination operand is a memory operand :
//
//              1. ADD
//              2. ADC
//              3. AND
//              4. BTC
//              5. BTR
//              6. BTS
//              7. CMPXCHG
//              8. CMPXCH8B
//              9. CMPXCHG16B
//              10. DEC
//              11. INC
//              12. NEG
//              13. NOT
//              14. OR
//              15. SBB
//              16. SUB
//              17. XOR
//              18. XADD
//              19. XCHG
//
//      If the LOCK prefix is used with one of these instructions and the source operand is a memory operand, an undefined opcode exception ( #UD ) may be
//      generated. An undefined opcode exception will also be generated if the LOCK prefix is used with any instruction not in the above list. The XCHG 
//      instruction always asserts the LOCK# signal regardless of the presence or absence of the LOCK prefix
//
//      The LOCK prefix is typically used with the BTS instruction to perform a read-modify-write operation on a memory location in shared memory environment.
//
//      On x86 64 bits system the LOCK prefix has an added feature that a full memory barrier for the CPU is added. In other words all locked operations serialize 
//      all outstanding load and store operations, they wait for all the previous reads and writes to complete!
//
//      The destination memory address alignment does not affect the integrity of the LOCK prefix.
//
//      The following are guaranteed to be performed as one unit, without the possible interruption from other CPU's, and do not require the LOCK prefix :
//
//          1. Reading or writing a byte
//          2. Reading or writing a word aligned on a 16 bit boundary
//          3. Reading or writing a doubleword aligned on a 32 bit boundary
//          4. Reading or writing a quadword aligned on a 64 bit boundary
//          5. 16 bit accesses to uncached memory locations that fit within a 32 bit data bus
//          6. Unaligned 16,32,64 bit accesses to cached memory that fit within a cache line
//
//      Accesses to cacheable memory that are split across cahce lines and page boundaries are not guaranteed to be performed as one unit!
//
//  Description :
//
//		1. This object is used only to wrap some static methods, which can be used without any instance of the object. Then this object is
//		   an interface which conatins only static methods, and does not need to never be instantied
//
//		2. This object has all the methods to create, destory, copy and move disabled to ensure that no instances of it will be created
//
//  Possible errors :
//
//		Too many to count
//
class CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits
{
public:


    // The following are type definitions of the object and all the provided template arguments :


	// Create a type definition for the object itself
	using SelfType = CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits;


	// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions
	// only have access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only
	// purpose then of declaring a static function is when a private static data member needs to be manipulated, or some functionality needed that
	// does not involve the non static data members


	// The following methods will provide the arithmetic operations addition and subtraction. The instructions are ADD, ADC, XADD, SUB, SBB, INC and DEC :


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to read and write to a memory address without other central proccesing units interfering. In this case :
    //
    //          Read  ->   the current value from the memory address
    //
    //          Central processing unit operation  ->   add the given value to the current value
    //
    //          Write  ->   the result to the memory address  
    //
    //      The operations will be done in this order!
    //
    //      The assembly instruction that will be used to achieve this is 'XADD' ( Exchange and Add ). It exchanges the first arguments ( destination ) 
    //      with the second argument ( source ), then loads the sum of the two values into the destination argument. The destination argument must be
    //      memory location. The source argument must be a register. To illustrate XADD operation :
    //
    //          1. Source + Destination  ->  Temporary
    //          2. Destination  ->  Source
    //          3. Temporary  ->  Destination
    //
    //      Combined with the "LOCK" prefix it will perform all this manipulations while the LOCK# signal is up, which will prevent from other central
    //      processing units to access the shared memory
    //
    //      Flags affected :
    //
    //          Carry flag ( OF ), parity flag ( PF ), auxilary flag ( AF ), sign flag ( SF ), zero flag ( ZF ) and the overflow flag ( OF ) are set
    //          according to the result
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          value - this will be added to the value currently in the memory address
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      The current value in the memory address before the given value was added to it
    //
    //  Expectations :
    //
	// 		NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
	template< Concepts::Integer IntegerType >
    EnsureRetrunValueIsUsed static inline IntegerType Read_Add_Write_ReturnOldValue( volatile IntegerType* const integerPointer, const IntegerType valueToAdd );


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to read and write to a memory address without other central proccesing units interfering. In this case :
    //
    //          Read  ->   the current value from the memory address
    //
    //          Central processing unit operation  ->  add the given value to the current value
    //
    //          Write  ->   the result to the memory address
    //
    //      The assembly instruction that will be used to achieve this is 'ADD'. It performs addition between the 2 given arguments and store the result. 
    //      The destination argument must be a memory location. The source argument can be immediate or register. To illustrate ADD 
    //      operation :
    //
    //          1. Destination  ->  Temporary
    //          2. Temporary ADD Source  ->  Temporary
    //          3. Temporary  ->  Destination
    //
    //      Combined with the "LOCK" prefix it will perform all this manipulations while the LOCK# signal is up, which will prevent from other central
    //      processing units to access the shared memory
    //
    //      Flags affected :
    //
    //          Carry flag ( OF ), parity flag ( PF ), auxilary flag ( AF ), sign flag ( SF ), zero flag ( ZF ) and the overflow flag ( OF ) are set
    //          according to the result
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          valueToAdd - this will be added to the value in the memory address
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
    //		1. The given pointer to the memory address should not be NULL
    //		2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
	template< Concepts::Integer IntegerType >
    static inline void Read_Add_Write( volatile IntegerType* const integerPointer, const IntegerType valueToAdd );


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to read and write to a memory address without other central proccesing units interfering. In this case :
    //
    //          Read  ->   the current value from the memory address
    //
    //          Central processing unit operation  ->  add the given value and the carry flag to the current value
    //
    //          Write  ->   the result to the memory address
    //
    //      The assembly instruction that will be used to achieve this is 'ADC'. It performs addition between 2 given arguments, adds also the carry
    //      flag and stores the result. The destination argument must be a memory location. The source argument can be immediate or register. To 
    //      illustrate ADC operation :
    //
    //          1. Destination  ->  Temporary
    //          2. Temporary ADD Source  ->  Temporary
    //          3. Temporary ADD CarryFlag   ->   Temporary
    //          3. Temporary  ->  Destination
    //
    //      Combined with the "LOCK" prefix it will perform all this manipulations while the LOCK# signal is up, which will prevent from other central
    //      processing units to access the shared memory
    //
    //      Flags affected :
    //
    //          Carry flag ( OF ), parity flag ( PF ), auxilary flag ( AF ), sign flag ( SF ), zero flag ( ZF ) and the overflow flag ( OF ) are set
    //          according to the result
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          valueToAdd - this will be added to the value in the memory address
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
    //		1. The given pointer to the memory address should not be NULL
    //		2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
	template< Concepts::Integer IntegerType >
    static inline void Read_Add_AddCarryFlag_Write( volatile IntegerType* const integerPointer, const IntegerType valueToAdd );


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to read and write to a memory address without other central proccesing units interfering. In this case :
    //
    //          Read  ->   the current value from the memory address
    //
    //          Central processing unit operation  ->  subtract the given value from the current value
    //
    //          Write  ->   the result to the memory address
    //
    //      The assembly instruction that will be used to achieve this is 'SUB'. It performs subtraction between the 2 given arguments and store the result. 
    //      The destination argument must be a memory location. The source argument can be immediate or register. To illustrate SUB 
    //      operation :
    //
    //          1. Destination  ->  Temporary
    //          2. Temporary SUB Source  ->  Temporary
    //          3. Temporary  ->  Destination
    //
    //      Combined with the "LOCK" prefix it will perform all this manipulations while the LOCK# signal is up, which will prevent from other central
    //      processing units to access the shared memory
    //
    //      Flags affected :
    //
    //          Zero flag ( ZF ) and Carry flag ( CF ) are set according to the result
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          valueToSubtract - this will be subtracted from the value in the memory address
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
    //		1. The given pointer to the memory address should not be NULL
    //		2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
	template< Concepts::Integer IntegerType >
    static inline void Read_Subtract_Write( volatile IntegerType* const integerPointer, const IntegerType valueToSubtract );


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to read and write to a memory address without other central proccesing units interfering. In this case :
    //
    //          Read  ->   the current value from the memory address
    //
    //          Central processing unit operation  ->  subtract the given value from the current value, and and extra 1 if the carry flag ( CF ) is on
    //
    //          Write  ->   the result to the memory address
    //
    //      The assembly instruction that will be used to achieve this is 'SBB'. It performs subtraction between the 2 given arguments, and subtracts an additional
    //      one if the carry flag ( CF ) is on, and store the result. The destination argument must be a memory location. The source argument can be immediate, 
    //      or register. To illustrate SBB operation :
    //
    //          1. Destination  ->  Temporary
    //          2. Temporary subtract Source  ->  Temporary
    //          3. If carry flag is on   ->   Temporary subtract 1   ->   Temporary
    //          3. Temporary  ->  Destination
    //
    //      Combined with the "LOCK" prefix it will perform all this manipulations while the LOCK# signal is up, which will prevent from other central
    //      processing units to access the shared memory
    //
    //      Flags affected :
    //
    //          Carry flag ( OF ), parity flag ( PF ), auxilary flag ( AF ), sign flag ( SF ), zero flag ( ZF ) and the overflow flag ( OF ) are set
    //          according to the result
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          valueToSubtract - this will be subtracted from the value in the memory address
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
    //		1. The given pointer to the memory address should not be NULL
    //		2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
	template< Concepts::Integer IntegerType >
    static inline void Read_Subtract_SubtractOneMoreIfCarryFlagIsON_Write( volatile IntegerType* const integerPointer, const IntegerType valueToSubtract );


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to read and write to a memory address without other central proccesing units interfering. In this case :
    //
    //          Read  ->   the current value from the memory address
    //
    //          Central processing unit operation  ->  add 1 to the current value
    //
    //          Write  ->    the result to the memory address
    //
    //      The assembly instruction that will be used to achieve this is 'INC'. This operation adds 1 to the current value and store the result. The 
    //      argument must be a memory location. To illustrate INC operation :
    //
    //          1. Destination  ->  Temporary
    //          2. INC Temporary  ->  Temporary  
    //          3. Temporary  ->  Destination
    //
    //      Combined with the "LOCK" prefix it will perform all this manipulations while the LOCK# signal is up, which will prevent from other central
    //      processing units to access the shared memory
    //
    //      Flags affected :
    //
    //          The sign flag ( SF ), zero flag ( ZF ), parity flag ( PF ), overflow flag ( OF ) and auxilary flag ( AF ) flags are set according 
    //          to the result
    //
    //      Hardware Exceptions :
    //
    //          1. #SS(0) - if a memory address referencing the SS segment is in a non canonical form
    //          2. #GP(0) - if the memory address is in a non canonical form
    //          3. #PF(fault-code) - if a page fault occurs
    //          4. #AC(0) - if alignment checking is enabled and an unaligned memory reference is made while the current privilege is 3
    //          5. #UD - if the LOCK prefix is used but the destination is not a memory operand
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
    //  Expectations :
    //
    //		1. The given pointer to the memory address should not be NULL
    //		2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
	template< Concepts::Integer IntegerType >
    static inline void Read_AddOne_Write( volatile IntegerType* const integerPointer );


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to read and write to a memory address without other central proccesing units interfering. In this case :
    //
    //          Read  ->   the current value from the memory address
    //
    //          Central processing unit operation  ->  subtract 1 from the current value
    //
    //          Write  ->    the result to the memory address
    //
    //      The assembly instruction that will be used to achieve this is 'DEC'. This operation subtracts 1 from the current value and store the result. The 
    //      argument must be a memory location. To illustrate DEC operation :
    //
    //          1. Destination  ->  Temporary
    //          2. DEC Temporary  ->  Temporary  
    //          3. Temporary  ->  Destination
    //
    //      Combined with the "LOCK" prefix it will perform all this manipulations while the LOCK# signal is up, which will prevent from other central
    //      processing units to access the shared memory
    //
    //      Flags affected :
    //
    //          The sign flag ( SF ), zero flag ( ZF ), parity flag ( PF ), overflow flag ( OF ) and auxilary flag ( AF ) flags are set according 
    //          to the result
    //
    //      Hardware Exceptions :
    //
    //          1. #SS(0) - if a memory address referencing the SS segment is in a non canonical form
    //          2. #GP(0) - if the memory address is in a non canonical form
    //          3. #PF(fault-code) - if a page fault occurs
    //          4. #AC(0) - if alignment checking is enabled and an unaligned memory reference is made while the current privilege is 3
    //          5. #UD - if the LOCK prefix is used but the destination is not a memory operand
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
    //  Expectations :
    //
    //		1. The given pointer to the memory address should not be NULL
    //		2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
	template< Concepts::Integer IntegerType >
    static inline void Read_SubtractOne_Write( volatile IntegerType* const integerPointer );



    // The following methods will provide the exchange and compare and exchange functionality. The instructions are XCHG, CMPXCHG, CMPXCHG8B AND CMPXCHG16B :



    // Method Information :
    //
    //  Description :
    //
    //      Use this method to read and write to a memory address without other central proccesing units interfering. In this case :
    //
    //          Read  ->   the current value from the memory address
    //
    //          Central processing unit operation  ->   NONE
    //
    //          Write  ->   write the given value to the memory address
    //
    //      It is basically doing a swap between the source and destination operand!
    //
    //      The assembly instruction that will be used to achieve this is 'XCHG' ( Exchange ). The destination argument must be a memory location. 
    //      The source argument must be a register. 'XCHG' does not accept immediate arguments. To illustrate XCHG operation :
    //
    //          1. Source  ->  Temporary
    //          2. Destination  ->  Source
    //          3. Temporary  ->  Destination
    //
    //      Combined with the "LOCK" prefix it will perform all this manipulations while the LOCK# signal is up, which will prevent from other central
    //      processing units to access the shared memory
    //
    //      Flags affected :
    //
    //          NONE
    //
    //      Hardware Exceptions :
    //
    //          1. #SS(0) - if a memory address referencing the SS segment is in a non canonical form
    //          2. #GP(0) - if the memory address is in a non canonical form
    //          3. #PF(fault-code) - if a page fault occurs
    //          4. #AC(0) - if alignment checking is enabled and an unaligned memory reference is made while the current privilege is 3
    //          5. #UD - if the LOCK prefix is used but the destination is not a memory operand
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          valueToSet - this will be set instead of to the value currently in the memory address
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      The current value in the memory address before the given value was set instead of it
    //
    //  Expectations :
    //
    //		1. The given pointer to the memory address should not be NULL
    //		2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
	template< Concepts::Integer IntegerType >
    EnsureRetrunValueIsUsed static inline IntegerType Read_WriteOtherValue_ReturnOldValue( volatile IntegerType* const integerPointer, const IntegerType valueToSet );


    // Method Information :
    //
    //  Description :
    //
    //		This method is one of four methods that perform the same operations only for different integer sizes. This overload is for integrs
    //		that has size of 1 byte.
    //
    //      Use this method to read and write to a memory address without other central proccesing units interfering. In this case :
    //
    //          Read  ->   the current value from the memory address
    //
    //          Central processing unit operation  ->   compare AX, EAX or RAX with first operand
    //
    //          Write  ->   if the the comparison is true write the given value to the memory address, if it is false the destination will be stored
    //                      in the register AX, EAX or RAX
    //
    //      It is basically doing a swap between the source and destination operand!
    //
    //      The assembly instruction that will be used to achieve this is 'CMPXCHG' ( Compare Exchange ). It will compare the value read from the
    //      memory address with the required register AX, EAX or RAX and if the value match, the given value will be stored insted. If not the 
    //      read value will be stored in the register the comparison was made with. The destination argument must be a memory location. 
    //      The source argument must be a register. 'CMPXCHG' does not accept immediate arguments. To illustrate XCHG operation :
    //
    //          1. Source  ->  Temporary
    //          2. Compare Temporary and AX, EAX or RAX :
    //
    //             if true :
    //
    //             	3. Source   ->    Destination
    //	
    //             if false :
    //	
    //             	3. Destination    ->    AX, EAX or RAX
    //
    //      Combined with the "LOCK" prefix it will perform all this manipulations while the LOCK# signal is up, which will prevent from other central
    //      processing units to access the shared memory
    //
    //      Flags affected :
    //
    //          The zero flag ( ZF ) is set if the values in the destination operand and accmulator register content are equal, otherwise it is cleared.
    //          The carry flag ( CF ), parity flag ( PF ), auxilary flag ( AF ), sign flag ( SF ) and overflow sign ( OF ) will be set according to the
    //          results of the comparison operation
    //
    //      Hardware Exceptions :
    //
    //          1. #SS(0) - if a memory address referencing the SS segment is in a non canonical form
    //          2. #GP(0) - if the memory address is in a non canonical form
    //          3. #PF(fault-code) - if a page fault occurs
    //          4. #AC(0) - if alignment checking is enabled and an unaligned memory reference is made while the current privilege is 3
    //          5. #UD - if the LOCK prefix is used but the destination is not a memory operand
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. integerPointer - a pointer to the memory address to work on
    //          2. expectedValue - the value to compare with the actual value stored in the memory
    //          3. desiredValue - this value will be stored in the memory address if the comparison is true
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      A boolean with the value true in case the comparison result was true, and false otherwise
    //
    //  Expectations :
    //
    //		1. The given pointer to the memory address should not be NULL
    //		2. 
    //
    //  Possible errors :
    //
    //      They will come
    // 
    template< Concepts::Integer IntegerType > requires ( sizeof( IntegerType ) == 1 )
    EnsureRetrunValueIsUsed static inline Boolean Read_Compare_IfTrueStoreTheDesiredValueInstead( volatile IntegerType* const integerPointer, IntegerType& expectedValue, const IntegerType desiredValue );


    // Method Information :
    //
    //  Description :
    //
    //		This method is one of four methods that perform the same operations only for different integer sizes. This overload is for integrs
    //		that has size of 2 bytes.
    //
    //      Use this method to read and write to a memory address without other central proccesing units interfering. In this case :
    //
    //          Read  ->   the current value from the memory address
    //
    //          Central processing unit operation  ->   compare AX, EAX or RAX with first operand
    //
    //          Write  ->   if the the comparison is true write the given value to the memory address, if it is false the destination will be stored
    //                      in the register AX, EAX or RAX
    //
    //      It is basically doing a swap between the source and destination operand!
    //
    //      The assembly instruction that will be used to achieve this is 'CMPXCHG' ( Compare Exchange ). It will compare the value read from the
    //      memory address with the required register AX, EAX or RAX and if the value match, the given value will be stored insted. If not the 
    //      read value will be stored in the register the comparison was made with. The destination argument must be a memory location. 
    //      The source argument must be a register. 'CMPXCHG' does not accept immediate arguments. To illustrate XCHG operation :
    //
    //          1. Source  ->  Temporary
    //          2. Compare Temporary and AX, EAX or RAX :
    //
    //             if true :
    //
    //             	3. Source   ->    Destination
    //	
    //             if false :
    //	
    //             	3. Destination    ->    AX, EAX or RAX
    //
    //      Combined with the "LOCK" prefix it will perform all this manipulations while the LOCK# signal is up, which will prevent from other central
    //      processing units to access the shared memory
    //
    //      Flags affected :
    //
    //          The zero flag ( ZF ) is set if the values in the destination operand and accmulator register content are equal, otherwise it is cleared.
    //          The carry flag ( CF ), parity flag ( PF ), auxilary flag ( AF ), sign flag ( SF ) and overflow sign ( OF ) will be set according to the
    //          results of the comparison operation
    //
    //      Hardware Exceptions :
    //
    //          1. #SS(0) - if a memory address referencing the SS segment is in a non canonical form
    //          2. #GP(0) - if the memory address is in a non canonical form
    //          3. #PF(fault-code) - if a page fault occurs
    //          4. #AC(0) - if alignment checking is enabled and an unaligned memory reference is made while the current privilege is 3
    //          5. #UD - if the LOCK prefix is used but the destination is not a memory operand
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. integerPointer - a pointer to the memory address to work on
    //          2. expectedValue - the value to compare with the actual value stored in the memory
    //          3. desiredValue - this value will be stored in the memory address if the comparison is true
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      A boolean with the value true in case the comparison result was true, and false otherwise
    //
    //  Expectations :
    //
    //		1. The given pointer to the memory address should not be NULL
    //		2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< Concepts::Integer IntegerType > requires ( sizeof( IntegerType ) == 2 )
    EnsureRetrunValueIsUsed static inline Boolean Read_Compare_IfTrueStoreTheDesiredValueInstead( volatile IntegerType* const integerPointer, IntegerType& expectedValue, const IntegerType desiredValue );


    // Method Information :
    //
    //  Description :
    //
    //		This method is one of four methods that perform the same operations only for different integer sizes. This overload is for integrs
    //		that has size of 4 bytes.
    //
    //      Use this method to read and write to a memory address without other central proccesing units interfering. In this case :
    //
    //          Read  ->   the current value from the memory address
    //
    //          Central processing unit operation  ->   compare AX, EAX or RAX with first operand
    //
    //          Write  ->   if the the comparison is true write the given value to the memory address, if it is false the destination will be stored
    //                      in the register AX, EAX or RAX
    //
    //      It is basically doing a swap between the source and destination operand!
    //
    //      The assembly instruction that will be used to achieve this is 'CMPXCHG' ( Compare Exchange ). It will compare the value read from the
    //      memory address with the required register AX, EAX or RAX and if the value match, the given value will be stored insted. If not the 
    //      read value will be stored in the register the comparison was made with. The destination argument must be a memory location. 
    //      The source argument must be a register. 'CMPXCHG' does not accept immediate arguments. To illustrate XCHG operation :
    //
    //          1. Source  ->  Temporary
    //          2. Compare Temporary and AX, EAX or RAX :
    //
    //             if true :
    //
    //             	3. Source   ->    Destination
    //	
    //             if false :
    //	
    //             	3. Destination    ->    AX, EAX or RAX
    //
    //      Combined with the "LOCK" prefix it will perform all this manipulations while the LOCK# signal is up, which will prevent from other central
    //      processing units to access the shared memory
    //
    //      Flags affected :
    //
    //          The zero flag ( ZF ) is set if the values in the destination operand and accmulator register content are equal, otherwise it is cleared.
    //          The carry flag ( CF ), parity flag ( PF ), auxilary flag ( AF ), sign flag ( SF ) and overflow sign ( OF ) will be set according to the
    //          results of the comparison operation
    //
    //      Hardware Exceptions :
    //
    //          1. #SS(0) - if a memory address referencing the SS segment is in a non canonical form
    //          2. #GP(0) - if the memory address is in a non canonical form
    //          3. #PF(fault-code) - if a page fault occurs
    //          4. #AC(0) - if alignment checking is enabled and an unaligned memory reference is made while the current privilege is 3
    //          5. #UD - if the LOCK prefix is used but the destination is not a memory operand
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. integerPointer - a pointer to the memory address to work on
    //          2. expectedValue - the value to compare with the actual value stored in the memory
    //          3. desiredValue - this value will be stored in the memory address if the comparison is true
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      A boolean with the value true in case the comparison result was true, and false otherwise
    //
    //  Expectations :
    //
    //		1. The given pointer to the memory address should not be NULL
    //		2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< Concepts::Integer IntegerType > requires ( sizeof( IntegerType ) == 4 )
    EnsureRetrunValueIsUsed static inline Boolean Read_Compare_IfTrueStoreTheDesiredValueInstead( volatile IntegerType* const integerPointer, IntegerType& expectedValue, const IntegerType desiredValue );


    // Method Information :
    //
    //  Description :
    //
    //		This method is one of four methods that perform the same operations only for different integer sizes. This overload is for integrs
    //		that has size of 8 bytes.
    //
    //      Use this method to read and write to a memory address without other central proccesing units interfering. In this case :
    //
    //          Read  ->   the current value from the memory address
    //
    //          Central processing unit operation  ->   compare AX, EAX or RAX with first operand
    //
    //          Write  ->   if the the comparison is true write the given value to the memory address, if it is false the destination will be stored
    //                      in the register AX, EAX or RAX
    //
    //      It is basically doing a swap between the source and destination operand!
    //
    //      The assembly instruction that will be used to achieve this is 'CMPXCHG' ( Compare Exchange ). It will compare the value read from the
    //      memory address with the required register AX, EAX or RAX and if the value match, the given value will be stored insted. If not the 
    //      read value will be stored in the register the comparison was made with. The destination argument must be a memory location. 
    //      The source argument must be a register. 'CMPXCHG' does not accept immediate arguments. To illustrate XCHG operation :
    //
    //          1. Source  ->  Temporary
    //          2. Compare Temporary and AX, EAX or RAX :
    //
    //             if true :
    //
    //             	3. Source   ->    Destination
    //	
    //             if false :
    //	
    //             	3. Destination    ->    AX, EAX or RAX
    //
    //      Combined with the "LOCK" prefix it will perform all this manipulations while the LOCK# signal is up, which will prevent from other central
    //      processing units to access the shared memory
    //
    //      Flags affected :
    //
    //          The zero flag ( ZF ) is set if the values in the destination operand and accmulator register content are equal, otherwise it is cleared.
    //          The carry flag ( CF ), parity flag ( PF ), auxilary flag ( AF ), sign flag ( SF ) and overflow sign ( OF ) will be set according to the
    //          results of the comparison operation
    //
    //      Hardware Exceptions :
    //
    //          1. #SS(0) - if a memory address referencing the SS segment is in a non canonical form
    //          2. #GP(0) - if the memory address is in a non canonical form
    //          3. #PF(fault-code) - if a page fault occurs
    //          4. #AC(0) - if alignment checking is enabled and an unaligned memory reference is made while the current privilege is 3
    //          5. #UD - if the LOCK prefix is used but the destination is not a memory operand
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. integerPointer - a pointer to the memory address to work on
    //          2. expectedValue - the value to compare with the actual value stored in the memory
    //          3. desiredValue - this value will be stored in the memory address if the comparison is true
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      A boolean with the value true in case the comparison result was true, and false otherwise
    //
    //  Expectations :
    //
    //		1. The given pointer to the memory address should not be NULL
    //		2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< Concepts::Integer IntegerType > requires ( sizeof( IntegerType ) == 8 )
    EnsureRetrunValueIsUsed static inline Boolean Read_Compare_IfTrueStoreTheDesiredValueInstead( volatile IntegerType* const integerPointer, IntegerType& expectedValue, const IntegerType desiredValue );


    // The following methods will provide the bitwise logical operations AND, OR, XOR and Negate :


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to read and write to a memory address without other central proccesing units interfering. In this case :
    //
    //          Read  ->   the current value from the memory address
    //
    //          Central processing unit operation  ->  perform XOR between the values
    //
    //          Write  ->    the result to the memory address
    //
    //      The assembly instruction that will be used to achieve this is 'XOR'. It takes the same bit in the 2 arguments, and sets the bit in the 
    //      result according to ON only if the bits are in different state, one ON and one OFF. The destination argument must be a memory location. 
    //      The source argument must be an immediate or a register. To illustrate XOR operation :
    //
    //          1. Destination  ->  Temporary
    //          2. Temporary XOR Source  ->  Temporary  
    //          3. Temporary  ->  Destination
    //
    //      Combined with the "LOCK" prefix it will perform all this manipulations while the LOCK# signal is up, which will prevent from other central
    //      processing units to access the shared memory
    //
    //      Flags affected :
    //
    //          1. The overflow flag ( OF ) and carry flag ( CF ) flags are cleared
    //          2. The sign flag ( SF ), zero flag ( ZF ) and parity flag ( PF ) flags are set according to the result
    //          3. The state of the auxilary flag ( AF ) flag is undefined          
    //
    //      Hardware Exceptions :
    //
    //          1. #SS(0) - if a memory address referencing the SS segment is in a non canonical form
    //          2. #GP(0) - if the memory address is in a non canonical form
    //          3. #PF(fault-code) - if a page fault occurs
    //          4. #AC(0) - if alignment checking is enabled and an unaligned memory reference is made while the current privilege is 3
    //          5. #UD - if the LOCK prefix is used but the destination is not a memory operand
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          valueToXORwith - this will be used to XOR with the value in the memory address
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
    //		1. The given pointer to the memory address should not be NULL
    //		2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
	template< Concepts::Integer IntegerType >
    static inline void Read_XOR_Write( volatile IntegerType* const integerPointer, const IntegerType valueToXORwith );


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to read and write to a memory address without other central proccesing units interfering. In this case :
    //
    //          Read  ->   the current value from the memory address
    //
    //          Central processing unit operation  ->  perform OR between the values
    //
    //          Write  ->    the result to the memory address
    //
    //      The assembly instruction that will be used to achieve this is 'OR'. It takes the same bit in the 2 arguments, and sets the bit in the 
    //      result to OFF only if the 2 bits are OFF. The destination argument must be a memory location. The source argument must be an immediate
    //      or a register. To illustrate OR operation :
    //
    //          1. Destination  ->  Temporary
    //          2. Temporary OR Source  ->  Temporary  
    //          3. Temporary  ->  Destination
    //
    //      Combined with the "LOCK" prefix it will perform all this manipulations while the LOCK# signal is up, which will prevent from other central
    //      processing units to access the shared memory
    //
    //      Flags affected :
    //
    //          1. The overflow flag ( OF ) and carry flag ( CF ) flags are cleared
    //          2. The sign flag ( SF ), zero flag ( ZF ) and parity flag ( PF ) flags are set according to the result
    //          3. The state of the auxilary flag ( AF ) flag is undefined
    //
    //      Hardware Exceptions :
    //
    //          1. #SS(0) - if a memory address referencing the SS segment is in a non canonical form
    //          2. #GP(0) - if the memory address is in a non canonical form
    //          3. #PF(fault-code) - if a page fault occurs
    //          4. #AC(0) - if alignment checking is enabled and an unaligned memory reference is made while the current privilege is 3
    //          5. #UD - if the LOCK prefix is used but the destination is not a memory operand
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          valueToORwith - this will be used to OR with the value in the memory address
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
    //		1. The given pointer to the memory address should not be NULL
    //		2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
	template< Concepts::Integer IntegerType >
    static inline void Read_OR_Write( volatile IntegerType* const integerPointer, const IntegerType valueToORwith );


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to read and write to a memory address without other central proccesing units interfering. In this case :
    //
    //          Read  ->   the current value from the memory address
    //
    //          Central processing unit operation  ->  perform AND between the values
    //
    //          Write  ->    the result to the memory address
    //
    //      The assembly instruction that will be used to achieve this is 'AND'. It takes the same bit in the 2 arguments, and sets the bit in the 
    //      result to ON only if the 2 bits are ON. The destination argument must be a memory location. The source argument must be an immediate
    //      or a register. To illustrate AND operation :
    //
    //          1. Destination  ->  Temporary
    //          2. Temporary AND Source  ->  Temporary  
    //          3. Temporary  ->  Destination
    //
    //      Combined with the "LOCK" prefix it will perform all this manipulations while the LOCK# signal is up, which will prevent from other central
    //      processing units to access the shared memory
    //
    //      Flags affected :
    //
    //          1. The overflow flag ( OF ) and carry flag ( CF ) flags are cleared
    //          2. The sign flag ( SF ), zero flag ( ZF ) and parity flag ( PF ) flags are set according to the result
    //          3. The state of the auxilary flag ( AF ) flag is undefined
    //
    //      Hardware Exceptions :
    //
    //          1. #SS(0) - if a memory address referencing the SS segment is in a non canonical form
    //          2. #GP(0) - if the memory address is in a non canonical form
    //          3. #PF(fault-code) - if a page fault occurs
    //          4. #AC(0) - if alignment checking is enabled and an unaligned memory reference is made while the current privilege is 3
    //          5. #UD - if the LOCK prefix is used but the destination is not a memory operand
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          valueToANDwith - this will be used to AND with the value in the memory address
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
    //		1. The given pointer to the memory address should not be NULL
    //		2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
	template< Concepts::Integer IntegerType >
    static inline void Read_AND_Write( volatile IntegerType* const integerPointer, const IntegerType valueToANDwith );


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to read and write to a memory address without other central proccesing units interfering. In this case :
    //
    //          Read  ->   the current value from the memory address
    //
    //          Central processing unit operation  ->  perform NOT on the current value
    //
    //          Write  ->    the result to the memory address
    //
    //      The assembly instruction that will be used to achieve this is 'NOT'. It set each bit to a different state then he is. The argument 
    //      must be a memory location. It is one's complement negation. To illustrate NOT operation :
    //
    //          1. Destination  ->  Temporary
    //          2. NOT Temporary  ->  Temporary  
    //          3. Temporary  ->  Destination
    //
    //      Combined with the "LOCK" prefix it will perform all this manipulations while the LOCK# signal is up, which will prevent from other central
    //      processing units to access the shared memory
    //
    //      Flags affected :
    //
    //          NONE
    //
    //      Hardware Exceptions :
    //
    //          1. #SS(0) - if a memory address referencing the SS segment is in a non canonical form
    //          2. #GP(0) - if the memory address is in a non canonical form
    //          3. #PF(fault-code) - if a page fault occurs
    //          4. #AC(0) - if alignment checking is enabled and an unaligned memory reference is made while the current privilege is 3
    //          5. #UD - if the LOCK prefix is used but the destination is not a memory operand
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
    //  Expectations :
    //
    //		1. The given pointer to the memory address should not be NULL
    //		2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
	template< Concepts::Integer IntegerType >
    static inline void Read_NOT_Write( volatile IntegerType* const integerPointer );


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to read and write to a memory address without other central proccesing units interfering. In this case :
    //
    //          Read  ->   the current value from the memory address
    //
    //          Central processing unit operation  ->  perform NEG on the current value
    //
    //          Write  ->    the result to the memory address
    //
    //      The assembly instruction that will be used to achieve this is 'NEG'. It set each bit to a different state then he is and add one. The 
    //      argument must be a memory location. It is two's complement negation. To illustrate NEG operation :
    //
    //          1. Destination  ->  Temporary
    //          2. NEG Temporary  ->  Temporary  
    //          3. Temporary  ->  Destination
    //
    //      Combined with the "LOCK" prefix it will perform all this manipulations while the LOCK# signal is up, which will prevent from other central
    //      processing units to access the shared memory
    //
    //      Flags affected :
    //
    //          1. The carry flag ( CF ) is set to 0 if the source operand is 0, otherwise it is set to 1
    //          2. The sign flag ( SF ), zero flag ( ZF ), parity flag ( PF ), overflow flag ( OF ) and auxilary flag ( AF ) flags are set according 
    //             to the result
    //
    //      Hardware Exceptions :
    //
    //          1. #SS(0) - if a memory address referencing the SS segment is in a non canonical form
    //          2. #GP(0) - if the memory address is in a non canonical form
    //          3. #PF(fault-code) - if a page fault occurs
    //          4. #AC(0) - if alignment checking is enabled and an unaligned memory reference is made while the current privilege is 3
    //          5. #UD - if the LOCK prefix is used but the destination is not a memory operand
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
    //  Expectations :
    //
    //		1. The given pointer to the memory address should not be NULL
    //		2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
	template< Concepts::Integer IntegerType >
    static inline void Read_NEG_Write( volatile IntegerType* const integerPointer );


    // The following methods will provide the bitwise operations BTC, BTR and BTS :


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to read and write to a memory address without other central proccesing units interfering. In this case :
    //
    //          Read  ->   the current state of the bit from the memory address and offset, and store it in the carry flag
    //
    //          Central processing unit operation  ->  NONE
    //
    //          Write  ->    the bit in the opposite state
    //
    //      The assembly instruction that will be used to achieve this is 'BTC'. It set the carry flag to the current state of the bit, and stores 
    //      instead the bit in the opposite state. The first argument must be a memory location. The second argument which is the offset from the
    //      memory address of the specific bit can be an immedaite or a register. To illustrate BTC operation :
    //
    //          1. Destination Bit  ->  Carry flag
    //          2. NEG Carry flag  ->  Destination Bit
    //
    //      Combined with the "LOCK" prefix it will perform all this manipulations while the LOCK# signal is up, which will prevent from other central
    //      processing units to access the shared memory
    //
    //      Flags affected :
    //
    //          1. The carry flag ( CF ) will contain the bit old state
    //          2. The sign flag ( SF ), parity flag ( PF ), overflow flag ( OF ) and auxilary flag ( AF ) flags are undefined
    //
    //      Hardware Exceptions :
    //
    //          1. #SS(0) - if a memory address referencing the SS segment is in a non canonical form
    //          2. #GP(0) - if the memory address is in a non canonical form
    //          3. #PF(fault-code) - if a page fault occurs
    //          4. #AC(0) - if alignment checking is enabled and an unaligned memory reference is made while the current privilege is 3
    //          5. #UD - if the LOCK prefix is used but the destination is not a memory operand
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          bitOffset - this will be used to determine the offset to the required bit from the memory address
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
    //		1. The given pointer to the memory address should not be NULL
    //		2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
	template< Concepts::Integer IntegerType >
    static inline void ReadBitIntoCarryFlag_WriteOppositeBitState( volatile IntegerType* const integerPointer, UnsignedInteger64bits bitOffset );


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to read and write to a memory address without other central proccesing units interfering. In this case :
    //
    //          Read  ->   the current state of the bit from the memory address and offset, and store it in the carry flag
    //
    //          Central processing unit operation  ->  NONE
    //
    //          Write  ->    the state 0 to the bit
    //
    //      The assembly instruction that will be used to achieve this is 'BTR'. It set the carry flag to the current state of the bit, and set 
    //      the bit OFF. The first argument must be a memory location. The second argument which is the offset from the memory address of the specific
    //      bit can be an immedaite or a register. To illustrate BTR operation :
    //
    //          1. Destination Bit  ->  Carry flag
    //          2. State 0  ->  Destination Bit
    //
    //      Combined with the "LOCK" prefix it will perform all this manipulations while the LOCK# signal is up, which will prevent from other central
    //      processing units to access the shared memory
    //
    //      Flags affected :
    //
    //          1. The carry flag ( CF ) will contain the bit old state
    //          2. The sign flag ( SF ), parity flag ( PF ), overflow flag ( OF ) and auxilary flag ( AF ) flags are undefined
    //
    //      Hardware Exceptions :
    //
    //          1. #SS(0) - if a memory address referencing the SS segment is in a non canonical form
    //          2. #GP(0) - if the memory address is in a non canonical form
    //          3. #PF(fault-code) - if a page fault occurs
    //          4. #AC(0) - if alignment checking is enabled and an unaligned memory reference is made while the current privilege is 3
    //          5. #UD - if the LOCK prefix is used but the destination is not a memory operand
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          bitOffset - this will be used to determine the offset to the required bit from the memory address
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
    //		1. The given pointer to the memory address should not be NULL
    //		2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
	template< Concepts::Integer IntegerType >
    static inline void ReadBitIntoCarryFlag_SetBitOFF( volatile IntegerType* const integerPointer, UnsignedInteger64bits bitOffset );


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to read and write to a memory address without other central proccesing units interfering. In this case :
    //
    //          Read  ->   the current state of the bit from the memory address and offset, and store it in the carry flag
    //
    //          Central processing unit operation  ->  NONE
    //
    //          Write  ->    the state 1 to the bit
    //
    //      The assembly instruction that will be used to achieve this is 'BTS'. It set the carry flag to the current state of the bit, and set 
    //      the bit ON. The first argument must be a memory location. The second argument which is the offset from the memory address of the specific
    //      bit can be an immedaite or a register. To illustrate BTS operation :
    //
    //          1. Destination Bit  ->  Carry flag
    //          2. State 1  ->  Destination Bit
    //
    //      Combined with the "LOCK" prefix it will perform all this manipulations while the LOCK# signal is up, which will prevent from other central
    //      processing units to access the shared memory
    //
    //      Flags affected :
    //
    //          1. The carry flag ( CF ) will contain the bit old state
    //          2. The sign flag ( SF ), parity flag ( PF ), overflow flag ( OF ) and auxilary flag ( AF ) flags are undefined
    //
    //      Hardware Exceptions :
    //
    //          1. #SS(0) - if a memory address referencing the SS segment is in a non canonical form
    //          2. #GP(0) - if the memory address is in a non canonical form
    //          3. #PF(fault-code) - if a page fault occurs
    //          4. #AC(0) - if alignment checking is enabled and an unaligned memory reference is made while the current privilege is 3
    //          5. #UD - if the LOCK prefix is used but the destination is not a memory operand
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          bitOffset - this will be used to determine the offset to the required bit from the memory address
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
    //		1. The given pointer to the memory address should not be NULL
    //		2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
	template< Concepts::Integer IntegerType >
    static inline void ReadBitIntoCarryFlag_SetBitON( volatile IntegerType* const integerPointer, UnsignedInteger64bits bitOffset );	


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
		inline static void UnitTest() __attribute__ (( __unused__ ));

	)  //  End of debug tool


private:


	// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
	NoInstances( CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits );


};  //  Class CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits