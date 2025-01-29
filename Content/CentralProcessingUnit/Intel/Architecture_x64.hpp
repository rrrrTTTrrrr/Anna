


















//							Intel 64 bit architecture - this file is used to describe the environment for writing assembly code on the intel proccesors



















// ************************************************************************************************************************************************************************** //
// ************************************************************************************************************************************************************************** //
// **														   			    BASIC EXECUTION ENVIRONMENT                                                                    ** //
// ************************************************************************************************************************************************************************** //
// ************************************************************************************************************************************************************************** //




// ************************************************************************************************************************************************************************** //
// **														   			  		       OVERVIEW                                                                            ** //
// ************************************************************************************************************************************************************************** //



	// This part describes the basic execution environment of an Intel 64 processor as seen by assembly language programmers. It describes how the processor executes instructions
	// and how it stores and manipulates data. The execution environment described here includes memory ( the address space ), general purpose data registers, segment registers,
	// the flag register abd the instruction pointer register
	// 
	// Any program or task running on an Intel architectures 64 bits processor is given a set of resources for executing instructions and for storing code, data, and state
	// information. These resources make up the basic execution environment!
	// 
	// The basic execution environment is used jointly by the application pograms and the operating system or executive running on the processor :
	// 
	// 	1. Address space - any program running can address linear address space of up to 2 to power of 64 bytes, and physical address space of up to 2 to power of 46 bytes.
	// 					   Software can query CPUID for the physical address size supported by a processor
	// 
	// 	2. Basic program execution registers - the number of general purpose registers ( GPR ) available is 16. They are 64 bits wide and they support operations on byte, word, 
	// 										   doubleword and quadword integers. The RFLAGS and instruction pointer are 64 bit wide
	// 
	// 	3. x87 Floating point registers ( FPU ) - this 8 registers ( control, status, instruction pointer, operand/data pointer, tag, opcode ), provide an execution
	// 											  environment for operating on single precision, double precision, and double extended precision floating point, as
	// 											  well as integer arithmetics and binary coded decimal ( BCD )
	// 
	// 	4. MMX registers - the 8 MMX registers support execution of single instruction, multiple data ( SIMD ) operations on 64 bit packed byte, word and doubleword integers
	// 
	// 	5. XMM registers - the 16 XMM data registers and the MXCSR register support execution of SIMD operations on 128 bit packed single precision and double precision 
	// 					   floating point values as well as packed integers
	// 
	// 	6. YMM registers - the YMM data registers do the same only with  256 bit SIMD operations
	// 
	// 	7. Bounds registers - each of the BND0 - BND3 register stores the lower and upper bounds associated with the pointer to a memory buffer. They support execution of the
	// 						  Intel MPX instructions
	// 
	// 	8. BNDCFGU and BNDSTATUS - the first configures user mode MPX operations on bounds checking, the latter provides additional information on the //BR caused by an MPX 
	// 							   operation
	// 
	// 	9. Stack - to support procedure or subroutine calls and the passing of parameters between procedures or subroutines, a stack and stack managment resources are included
	// 			   in the execution environment
	// 
	// 	10. I/O ports - the IA-32 architecture support transfers of data to and from input/output ports
	// 
	// 	11. Control registers - the 5 control registers ( CR0 through CR4 ) determine the operating mode of the processor and the characteristics of the currently ecevuting task
	// 
	// 	12. Memory managment registers - the GDTR, IDTR, task and LDTR specify the locations of data structures used in protected mode memory
	// 
	// 	13. Debug registers - DR0 through DR7 control and allow monitoring of the processor's debugging operations
	// 
	// 	14. Memory type range registers ( MTRR ) - are used to assign memory types to regions of memory
	// 
	// 	15. Machine specific registers ( MSR ) - the processor provides a variety of machine specific registers that are used to control and report on processor performance.
	// 											 Virtually all MSRs handle system related functions and are not accessible to an application program. One exception to this
	// 											 rule is the time stamp counter
	// 
	// 	16. Machine chekc registers - consist of a set of control, status and error reporting MSRs that are used to detect and report on hardware errors
	// 
	// 	17. Descriptor table registers - the global table register ( GDTR ) and interrupt descriptor table register ( IDTR ) expand to 10 bytes so that they can hold a full
	// 									 64 bit base address. The local descriptor table register ( LDTR ) and the task register ( TR ) also can hold 64 bit address
	// 
	// 
	// In most cases, 64 bit mode uses flat address space for code, data and stacks. In 64 bit mode, the size of effective address calculations is 64 bits. In the flat address
	// space of 64 bit mode, linear addresses are equal to effective addresses because the base address is 0. In the event that FS or GS segments are used with a non zero base,
	// this rule does not hold! The FS and GS point to data segments. The availability of 2 data segments permits efficient and secure access to different types of data 
	// structures
	// 
	// In 64 bit mode, an address is considered to be in canonical form if address bits 63 through to the most significant implemented bit bt the microarchitecture are set
	// to either all ones or all zeros ( depending on whether the last used bit is 0 or 1 ). Intel 64 architecture defines a 64 bit linear address. Implementations can support
	// less



// ************************************************************************************************************************************************************************** //
// **														   			  		        REGISTERS                                                                          ** //
// ************************************************************************************************************************************************************************** //



// ******************************************************************   General purpose registers ( GPR )   ***************************************************************** //


	// This registers are provided for holding the follwing items :
	// 
	// 	1. Operands for logical and arithmetic operations
	// 	2. Operands for address calculations
	// 	3. Memory pointers
	// 
	// In 64 bit mode, there are 16 general purpose registers and the default operans size is 32 bit.
	// 
	// For 32 bit operand :
	// 
	// 	EAX, EBX, ECX, EDX, EDI, ESI, EBP, ESP, R8D - R15D
	// 
	// For 64 bit operand :
	// 
	// 	RAX, RBX, RCX, RDX, RDI, RSI, RBP, RSP, R8D - R15D
	// 
	// One execption is the ESP register, it holds the stack pointer and as a general rule should not be used for another purpose!
	// 
	// In 64 bit mode, operand size determines the number of valid bits in the destination general purpose register :
	// 
	// 	1. 64 bit operand - uses all the bits
	// 	2. 32 bit operand - uses only 32 bits, zero extended to 64 bit result
	// 	3. 8 or 16 bit operand - uses only 8 or 16 bits, the upper bits are not modified by the operation


// *****************************************************************   Instruction pointer register ( RIP )   *************************************************************** //


	// Contains the offest in the current code segment for the next instruction to be executed. It is advanced from one instruction boundary to the next in straight line code or
	// it is moved ahead or backwards by a number of instructions when executing JMP, Jcc, CALL, RET and IRET instructions. The instruction pointer cannot be accessed directly
	// by software. It is controlled implicitly by control transfer instructions ( such as JMP, Jcc and RET ), interrupts, and exceptions. The only way to read the content is to
	// execute a CALL instruction and then read the value of the return instruction pointer from the procedure stack. The instruction pointer can be loaded indirectly by modifying
	// the value of a return instruction pointer on the procedure stack and executing a return instruction ( RET or IRET )



// ************************************************************************************************************************************************************************** //
// **														   			OPERAND SIZE AND ADDRESS SIZE IN 64 BIT MODE                                                       ** //
// ************************************************************************************************************************************************************************** //



	// In 64 bit mode, the default address size is 64 bits and the default operand size is 32 bits. Defaults can be overridden using prefixes. Address size and operand size prefixes.
	// Address size and operand size prefixes allow mixing of 32/64 bit data and 32/64 bit addresses on an instruction by instruction basis. REX prefixes consist of 4 bit fields that
	// form 16 different values. The W bit field is referred to as REX.W, if this field is properly set, the prefix specifies an operand size override to 64 bits



// ************************************************************************************************************************************************************************** //
// **														   			  		     OPERAND ADDRESSING                                                                    ** //
// ************************************************************************************************************************************************************************** //



	// Machine instructions act on zero or more operands. Some operands are specified explicitly and others are implicit. The data for a source operand can be located in :
	//
	//    1. The instruction itself ( an immediate operand )
	//    2. A register
	//    3. A memory location
	//    4. An I/O port
	//
	// When an instruction returns data to a destination operand, it can be returned to :
	//
	//    1. A register
	//    2. A memory location
	//    3. An I/O port
	//
	// Immediate operands :
	//
	// Some instructions use data encoded in the instruction itself as a source operand. These operands are called immediate operands. For example :
	//
	//      ADD RAX, 14
	//
	// All arithmetic instructions allow the source operand to be an immediate value. The maximum value allowed for an immediate operand varies among instructions, but can never be greater
	// then the maximum value of an unsigned doubleword integer ( 2 to the power of 32 )
	//
	// Memory operands :
	//
	// A memory operand can be referenced by a segment selector and an offset. The offset can be 16, 32 or 64 bits :
	//
	//      15                0   63                            0
	//        Segment Selector      Offset ( or linear address )
	//
	// In 64 bit mode, segmentation is generally disabled, creating a flat 64 bit linear address space. The exceptions are the FS and GS segments, whose segment register can be used as
	// additional base registers in some linear address calculations


// *************************************************************************   Specifying an offset   *********************************************************************** //


	// The offset part of a memory address in 64 bit mode can be specified directly as a static value or through an address computation made up of one or more of the following
	// components :
	//
	//    1. Displacement - an 8,16 or 32 bit value
	//    2. Base - value in a 64 bit general purpose register
	//    3. Index - value in a 63 bit general purpose register
	//    4. Scale factor - value of 2,4 or 8 that is multiplied by the index value
	//
	// The offset which results from adding these components is called an effective address. Each of these components can have either a positive or negative ( 2's complement )
	// value, with the exception of the scaling factor
	//
	//                                          Base             Index              Scale                 Displacement
	//
	//                                       64 bit GPR   +    64 bit GPR    *     1/2/4/8    +      None or 8/16/32 bit value
	//
	//                                             OFFSET / EFFECTIVE ADDRESS = Base + ( Index * Scale ) + Displacement
	//
	// The base, index and displacement components can be used in any combination, and any of these components can be NULL. A scale factor may be used only when an index also is used.
	// The base and index value can be specified on one if 16 available general purpose registers in most cases
	//
	// The following addressing modes suggest used for common combinations of address components :
	//
	//      1. Displacement - alone represents a direct offset to the operand. Because the displacement is encoded in the instruction, this form of an address is sometimes called an
	//                        absolute or static address. It is commonly used to access a statically allocated scalar operand
	//
	//      2. Base - alone represents an indirect offset to the operand. Since the value in the base register can change, it can be used for dynamic storage of variables and data
	//                structures
	//
	//      3. Base + Displacement - can be used for 2 distinct purposes :
	//
	//              1. As an index into an array when the element size is not 2,4 or 8 bytes - the displacement component encodes the static offset to the beginning of the array. The
	//                 base register holds the results of a calculation to determine the offset to a specific element within the array
	//              2. To access a field of a record - the base register holds the address of the beginning of the record, while the displacement is a static offset to the field
	//
	//      4. ( Index * Scale ) + Displacement - this mode offers an efficient way to index into a static array when the element size is 2,4, or 8 bytes. The displacement locates
	//                                            the beginning of the array, the index register holds the subscript of the desired array element, and the processor automatically
	//                                            converts the subscript into an index by applying the scaling factor
	//
	//      5. Base + Index + Displacement - Using two registers together supports either a two dimensional array ( the displacement holds the address of the beginning of the array )
	//                                       or one of several instances of an array of records ( the displacement is an offset to a field within the record )
	//
	//      6. Base + ( Index * Scale ) + Displacement - allows efficient indexing of a two dimensional array when the elements of the array are 2,4 or 8 bytes in size
	//
	//      7. RIP + Displacement - uses a signed 32 bit displacement to calculate the effective address of the next instruction by sign extend the 32 bit value and add to the 64 bit
	//                              value in RIP




// ************************************************************************************************************************************************************************** //
// ************************************************************************************************************************************************************************** //
// **														   				   FUNDAMENTAL DATA TYPES                                                                      ** //
// ************************************************************************************************************************************************************************** //
// ************************************************************************************************************************************************************************** //




// ************************************************************************************************************************************************************************** //
// **													 ALIGNMENT OF WORDS, DOUBLEWORDS, QUADWORDS AND DOUBLE QUADWORDS                                                   ** //
// ************************************************************************************************************************************************************************** //



	// Words, doublewords and quadwords do not need to be aligned in memory on natural boundaries. The natural boundaries are even addresses, which divide with no remainder 
	// by 2,4, or 8. However, to improve the performance of programs, data structures ( especially stacks ) should be aligned on natural boundaries whenever possible. The 
	// reason for this is that the processor requires two memory accesses to make an unaligned memory access, aligned accesses require only one memory access.
	//
	// Some instructions that operate on double quadwords require memory operands to be aligned on a natural boundary. These instructions generate a general protection 
	// exception ( // GP ) if an unaligned operand is specified!



// ************************************************************************************************************************************************************************** //
// **														   			  		      POINTER                                                                              ** //
// ************************************************************************************************************************************************************************** //



	// Pointers are addresses of locations in memory!!
	//
	// In 64 bit mode, a near pointer is 64 bits. This equates to an effective address. Far pointers in 64 bit mode can be one of three forms :
	//
	//  1. 16 bit segment selector, 16 bit offset if the operand size is 32 bits
	//  2. 16 bit segment selector, 32 bit offset if the operand size is 32 bits
	//  3. 16 bit segment selector, 64 bit offset if the operand size is 64 bits



// ************************************************************************************************************************************************************************** //
// **														   			  		BIT FIELD DATA TYPE                                                                        ** //
// ************************************************************************************************************************************************************************** //



	// A bit field is a contiguous sequence of bits. It can begin at any position of any byte in memory and can contain up to 32 bits!
	//
	//                                                                                                  Bit Field
	//                                                                            ----------------------------------------------------
	//                                                                            |               |                    |             |
	//                                                                            ----------------------------------------------------
	//                                                                                            | <- Field Length -> |
	//                                                                                                                 |
	//                                                                                                       Least Significant Bit



// ************************************************************************************************************************************************************************** //
// **														   			  		  STRING DATA TYPE                                                                         ** //
// ************************************************************************************************************************************************************************** //



	// Strings are continuous sequences of bits, bytes, words or doublewords. A bit string can begin at any bit position of any byte and can contain up to ( 2^32 - 1 ) bits.
	// A byte string can contain bytes, words or doublewords and can range from zero to ( 2^32 - 1 ) bytes, which is 4GB!



// ************************************************************************************************************************************************************************** //
// **														   			  		PACKED SIMD DATA TYPE                                                                      ** //
// ************************************************************************************************************************************************************************** //



	// The 64 bit packed SIMD data types were introduced in the Intel MMX technology. They are operated on in MMX registers. The fundamental 64 bit packed data types are packed bytes, packed words
	// and doublewords. When performing numeric SIMD operations on these data types, these data types are interpreted as containing byte, word or doubleword!
	//
	//
	//                                                                                      ------------------------------------
	//                                                   Packed bytes -->                   |    |    |    |    |    |    |    |
	//                                                                                      ------------------------------------
	//                                                                                     63                                  0
	//
	//                                                                                      ------------------------------------
	//                                                   Packed Words -->                   |        |        |        |       |
	//                                                                                      ------------------------------------
	//                                                                                     63                                  0
	//
	//                                                                                      ------------------------------------
	//                                             Packed DoubleWords -->                   |                 |                |
	//                                                                                      ------------------------------------
	//                                                                                     63                                  0
	//
	// The 128 bit packed SIMD data types were introduced in the SSE extensions and used with SSE2, SSE3 AND SSSE3 extensions. They are operated on primarily in the 128 bit XMM registers and memory.
	// The fundamental 128 bit packed data types are packed bytes, words, doublewords and quadwords. When performing numeric SIMD operations on these data types in XMM registers, these data types
	// are interpreted as containing packed or scalar single precision floating point or double precision floating points values, or as containing packed byte, word, doubleword or quadwords!



// ************************************************************************************************************************************************************************** //
// **														   		 REAL NUMBERS AND FLOATING POINT FORMATS                                                               ** //
// ************************************************************************************************************************************************************************** //



	// This section describes how real numbers are represented in floating point format in x87 FPU and SSE/SSE2/SSE3/SSE4.1 and Intel AVX floating point instructions. The real number system
	// comprises the continuum of real numbers from minus infinity to plus infinity!
	//
	// Because the size and number of registers that any computer can have is limited, only a subset of the real number continuum can be used in real number calculations. The range and precision
	// of this real number subset is determined by the IEEE standard 754 floating point formats.
	//
	// Floating point format :
	//
	// To increase the speed and efficiency of real number computations, computers and microprocessors typically represent real numbers in binary floating point format. In this format, a real
	// number has three parts - a sign, a significand and an exponent. The sign




// ************************************************************************************************************************************************************************** //
// ************************************************************************************************************************************************************************** //
// **														   				    INSTRUCTION SET                                                                            ** //
// ************************************************************************************************************************************************************************** //
// ************************************************************************************************************************************************************************** //




// ************************************************************************************************************************************************************************** //
// **														   			  GENERAL PURPOSE INSTRUCTIONS                                                                     ** //
// ************************************************************************************************************************************************************************** //



	// The general purpose instructions perform basic data movement, arithmetic, logic, program flow and string operations that are commonly used to create applications!!


// **********************************************************************   Data Transfer Instructions   ******************************************************************** //


	// 	 1. MOV - Move data
	// 	 2. CMOVE - Conditional move, will move only if equal to 0
	// 	 3. CMOVNE - Conditional move, will move only if not equal to 0
	// 	 4. CMOVA - Conditional move, will move only if above
	// 	 5. CMOVAE - Conditional move, will move only if above or equal
	//	 6. CMOVB - Conditional move, will move only if below
	// 	 7. CMOVBE - Conditional move, will move only if below or equal
	//	 8. CMOVG - Conditional move, will move only if greater
	//	 9. CMOVGE - Conditional move, will move only if greater or equal
	// 	 10. CMOVL - Conditional move, will move only if less
	// 	 11. CMOVLE - Conditional move, will move only if less or equal
	// 	 12. CMOVC - Conditional move, will move only if carry
	// 	 13. CMOVNC - Conditional move, will move only if no carry
	// 	 14. CMOVO - Conditional move, will move only if overflow
	// 	 15. CMOVNO - Conditional move, will move only if no overflow
	// 	 16. CMOVS - Conditional move, will move only if sign ( negative )
	// 	 17. CMOVNS - Conditional move, will move only if no sign ( non-negative )
	// 	 18. CMOVP - Conditional move, will move only if parity even
	// 	 19. CMOVNP - Conditional move, will move only if parity odd
	// 	 20. XCHG - Exchange
	//	 21. BSWAP - Byte swap
	//    22. XADD - Exchange and add
	// 	 23. CMPXCHG - Compare and exchange
	// 	 24. CMPXCHG8B - Compare and exchange 8 bytes
	// 	 25. PUSH - Push onto the stack
	// 	 26. POP - Pop off the stack
	// 	 27. PUSHA - Push general purpose registers onto the stack
	// 	 28. POPA - Pop general purpose registers onto the stack
	// 	 29. CWD - Convert word to doubleword
	//	 30. CWQ - Convert doubleword to quadword
	// 	 31. CBW - Convert byte to word
	// 	 32 CWDE - Convert word to doubleword in EAX register
	// 	 33. MOVSX - Move and sign extend
	//    34. MOVZX - Move and zero extend


// ********************************************************************   Binary Arithmetic Instructions   ****************************************************************** //


	// The binary arithmetic instructions perform basic binary integer computations on byte, word, doubleword and quadword integers located in memory and/or the general purpose registers :
	//
	//    1. ADCX - Unsigned integer add with
	//    2. ADOX - Unsigned integer add with overflow
	//    3. ADD - Integer add
	//    4. ADC - Add with carry
	//    5. SUB - Subtract
	//    6. SBB - Subtract with borrow
	//    7. IMUL - signed multiply
	//    8. MUL - Unsigned multiply
	//    9. IDIV - Signed divide
	//    10. DIV - Unsigned divide
	//    11. INC - Increment
	//    12. DEC - Decrement
	//    13. NEG - Negate
	//    14. CMP - Compare


// ********************************************************************   Decimal Arithmetic Instructions   ***************************************************************** //


	// The decimal arithmetic instructions perform decimal arithmetic on binary coded decimal ( BCD ) data :
	//
	//    1. DAA - Decimal adjust after addition
	//    2. DAS - Decimal adjust after subtraction
	//    3. AAA - ASCII adjust after addition
	//    4. AAS - ASCII adjust after subtraction
	//    5. AAM - ASCII adjust after multiplication
	//    6. AAD - ASCII adjust before division


// *************************************************************************   Logical Instructions   *********************************************************************** //


	// The logical instructions perform basic AND, OR, XOR and NOT logical operations on byte, word, doubleword and quadword values :
	//
	//    1. AND - Perform bitwise logical AND
	//    2. OR - Perform bitwise logical OR
	//    3. XOR - Perform bitwise logical exclusive OR
	//    4. NOT - Perform bitwise logical NOT


// *********************************************************************   Shift And Rotate Instructions   ****************************************************************** //


	// The shift and rotate instructions shift and rotate the bits in byte, word, doubleword and quadword arguments :
	//
	//    1. SAR - Shift arithmetic right
	//    2. SHR - Shift logical right
	//    3. SAL - Shift arithmetic left
	//    4. SHL - Shift logical left
	//    5. SHRD - Shift right double
	//    6. SHLD - Shift left double
	//    7. ROR - Rotate right
	//    8. ROL - Rotate left
	//    9. RCR - Rotate through carry right
	//    10. RCL - Rotate through carry left


// **********************************************************************   Bit And Byte Instructions   ********************************************************************* //


	// Bit instructions test and modify individual bits in byte, word, doubleword and quadword arguments. Byte instructions set the value of a byte argument to indicate the status of flags
	// in the RFLAGS register :
	//
	//    1. BT - Bit test
	//    2. BTS - Bit test and set
	//    3. BTR - Bit test and reset
	//    4. BTC - Bit test and complement
	//    5. BSF - Bit scan forward
	//    6. BSR - Bit scan reverse
	//    7. SETE - Set byte if equal
	//    8. SETZ - Set byte if zero
	//    9. SETNE - Set byte if not equal
	//    10. SETNZ - Set byte if not zero
	//    11. SETA - Set byte if above
	//    12. SETNBE - Set byte if not below or equal
	//    13. SETAE - Set byte if above or equal
	//    14. SETNB - Set byte if not below
	//    15. SETNC - Set byte if not carry
	//    16. SETB - Set byte if below
	//    17. SETNAE - Set byte if not above or equal
	//    18. SETC - Set byte if carry
	//    19. SETBE - Set byte if below or equal
	//    20. SETNA - Set byte if not above
	//    21. SETG - Set byte if greater
	//    22. SETNLE - Set byte if not less or equal
	//    23. SETGE - Set byte if greater or equal
	//    24. SETNL - Set byte if not less
	//    25. SETL - Set byte if less
	//    26. SETNGE - Set byte if not greater or equal
	//    27. SETLE - Set byte if less or equal
	//    28. SETNG - Set byte if not greater
	//    29. SETS - Set byte if sign ( negative )
	//    30. SETNS - Set byte if not sign ( non negative )
	//    31. SETO - Set byte if overflow
	//    32. SETNO - Set byte if not overflow
	//    33. SETPE - Set byte if parity even
	//    34. SETP - Set byte if parity
	//    35. TEST - Logical compare


// ********************************************************************   Control Transfer Instructions   ****************************************************************** //


	// The control transfer instructions provide jump, conditional jump, loop, and call and return operations to control program flow :
	//
	//    1. JMP - Jump
	//    2. JE - Jump if equal
	//    3. JZ - Jump if zero
	//    4. JNE - Jump if not equal
	//    5. JNZ - Jump if not zero
	//    6. JA - Jump if above
	//    7. JNBE - Jump if not below or equal
	//    8. JAE - Jump if above or equal
	//    9. JNB - Jump if not below
	//    10. JB - Jump if below
	//    11. JNAE - Jump if not above
	//    12  JBE - Jump if below or equal
	//    13. JNA - Jump if not above
	//    14. JG - Jump if greater
	//    15. JNLE - Jump if not less or equal
	//    16. JGE - Jump if greater or equal
	//    17. JNL - Jump if not less
	//    18. JL - Jump if less
	//    19. JNGE - Jump if not greater or equal
	//    20. JLE - Jump if less or equal
	//    21. JNG - Jump if not greater
	//    22. JC - Jump if carry
	//    23. JNC - Jump if not carry
	//    24. JO - Jump if overflow
	//    25. JNO - Jump if not overflow
	//    26. JS - Jump if sign ( negative )
	//    27. JNS - Jump if not sign ( non-negative )
	//    28. JPO - Jump if parity
	//    29. JNP - Jump if not parity
	//    30. JPE - Jump if parity even
	//    31. JP - Jump if parity
	//    32. JCXZ - Jump register CX zero
	//    33. JECXZ - Jump register ECX zero
	//    34. LOOP - Loop with ECX counter
	//    35. LOOPZ - Loop with ECX and zero
	//    36. LOOPE - Loop with ECX and equal
	//    37. LOOPNZ - Loop with ECX and not zero
	//    38. LOOPNE - Loop with ECX
	//    39. CALL - Call procedure
	//    40. RET - Return
	//    41. IRET - Return from interrupt
	//    42. INT - Software interrupt
	//    43. INTO - Interrupt on overflow
	//    44. BOUND - Detect value out of range
	//    45. ENTER - High level procedure entry
	//    46. LEAVE - High level procedure exit


// *************************************************************************   String Instructions   ************************************************************************ //


	// The string instructions operate on strings of bytes, allowing them to be moved to and from memory :
	//
	//    1. MOVS - Move string
	//    2. MOVSB - Move byte string
	//    3. MOVSW - Move word string
	//    4. MOVSD - Move doubleword string
	//    5. CMPS - Compare string
	//    6. CMPSB - Compare byte string
	//    7. CMPSW - Compare word string
	//    8. CMPSD - Compare doubleword string
	//    9. SCAS - Scan string
	//    10. SCASB - Scan byte string
	//    11. SCASW - Scan word string
	//    12. SCASD - Scan doubleword string
	//    13. LODS - Load string
	//    14. LODSB - Load byte string
	//    15. LODSW - Load word string
	//    16. LODSD - Load doubleword string
	//    17. STOS - Store string
	//    18. STOSB - Store byte string
	//    19. STOSW - Store word string
	//    20. STOSD - Store doubleword string
	//    21. REP - Repeat while ECX not zero
	//    22. REPE - Repeat while equal
	//    23. REPZ - Repeat while zero
	//    24. REPNE - Repeat while not equal
	//    25. REPNZ - Repeat while not zero


// **********************************************************************   Input/Output Instructions   ********************************************************************* //


	// These instructions move data between the processor's I/O ports and a register or memory :
	//
	//    1. IN - Read from a port
	//    2. OUT - Write to a port
	//    3. INS - Input string from port
	//    4. INSB - Input byte string from port
	//    5. INSW - Input word string from port
	//    6. INSD - Input doubleword string from port
	//    7. OUTS - Output string to port
	//    8. OUTSB - Output byte string to port
	//    9. OUTSW - Output word string to port
	//    10. OUTSD - Output doubleword string to port


// *********************************************************************   Enter And Leave Instructions   ******************************************************************* //


	// These instructions provide machine language support for procedure calls in block structured languages :
	//
	//    1. ENTER - High level procedure entry
	//    2. LEAVE - High level procedure exit


// **********************************************************************   Flag Control Instructions   ********************************************************************* //


	// The flag control instructions operate on the flags in the RFLAGS register :
	//
	//    1. STC - Set carry flag
	//    2. CLC - Clear the carry flag
	//    3. CMC - Complement the carry flag
	//    4. CLD - Clear the direction flag
	//    5. STD - Set direction flag
	//    6. LAHF - Load flags into AH register
	//    7. SAHF - Store AH register into flags
	//    8. PUSHF/PUSHFD - Push RFLAGS onto stack
	//    9. POPF/POPFD - Pop RFLAGS from stack
	//    10. STI - Set interrupt flag
	//    11. CLI - Clear the interrupt flag


// **********************************************************************   Miscellaneous Instructions   ******************************************************************** //


	// The miscellaneous instructions provide such functions as loading effective address, executing a "no-operation", and retrieving processor identification information :
	//
	//    1. LEA - Load effective address
	//    2. NOP - No operation
	//    3. UD2 - Undefined instruction
	//    4. XLAT/XLATB - Table lookup translation
	//    5. CPUID - Processor identification
	//    6. MOVBE - Move data after swapping data bytes
	//    7. PERFECTCHW - Prefetch data into cache in anticipation of write
	//    8. PERFECTCHWT1 - Prefetch data into cache in anticipation of write
	//    9. CLFLUSH - Flushes and invalidates a memory argument and its associated cache line from all levels of the processor's cache hierarchy
	//    10. CLFLUSHOPT - Flushes and invalidates a memory argument and its associated cache line from all levels of the processor's cache hierarchy with optimized memory system throughput


// **********************************************************   User Mode Extended State Save/Restore Instructions   ******************************************************** //


	//    1. XSAVE - Save processor extended states to memory
	//    2. XSAVEC - Save processor extended states with compaction to memory
	//    3. XSAVEOPT - Save processor extended states to memory, optimized
	//    4. XRSTOR - Restore processor extended states from memory
	//    5. XGETBV - Reads the state of an extended control register


// *****************************************************************   Random Number Generator Instructions   *************************************************************** //


	//    1. RDRAND - Retrieves a random number generated from hardware
	//    2. RDSEED - Retrieves a random number generated from hardware


// ******************************************************************************   BMI1, BMI2   **************************************************************************** //


	//    1. ANDN - Bitwise AND of first source with inverted 2nd source argument
	//    2. BEXTR - Contiguous bitwise extract
	//    3. BLSI - Extract lowest set bit
	//    4. BLSMSK - Set all lower bits below first set bit to 1
	//    5. BLSR - Reset lowest set bit
	//    6. BZHI - Zero high bits starting from specified bit position
	//    7. LZCNT - Count the number leading zero bits
	//    8. MULX - Unsigned multiply without affecting arithmetic flags
	//    9. PDEP - Parallel deposit of bits using a mask
	//    10. PEXT - Parallel extraction of bits using a mask
	//    11. RORX - Rotate right without affecting arithmetic flags
	//    12. SARX - Shift arithmetic right
	//    13. SHLX - Shift logic left
	//    14. SHRX - Shift logic right
	//    15. TZCNT - Count the number trailing zero bits


// **************************************************************************   System Instructions   *********************************************************************** //


	// The following system instructions are used to control those functions of the processor that are provided to support for operating systems and executives :
	//
	//    1. CLAC - Clear AC flag in RFLAGS register
	//    2. STAC - Set AC flag in RFLAGS register
	//    3. LGDT - Load global descriptor table ( GDT ) register
	//    4. SGDT - Store global descriptor table ( GDT ) register
	//    5. LLDT - Load local descriptor table ( LDT ) register
	//    6. SLDT - Store local descriptor table ( LDT ) register
	//    7. LTR - Load task register
	//    8. STR - Store task register
	//    9. LIDT - Load interrupt descriptor table ( IDT ) register
	//    10. SIDT - Store interrupt descriptor table ( IDT ) register
	//    11. LMSW - Load machine status word
	//    13. SMSW - Store machine status word
	//    14. CLTS - Clear the task switched flag
	//    15. ARPL - Adjust requested privilege level
	//    16. LAR - Load access rights
	//    17. LSL - Load segment limit
	//    18. VERR - Verify segment for reading
	//    19. VERW- Verify segment for writing
	//    20. INVD - Invalidate cache, no write back
	//    21. WBINVD - Invalidate cache, with write back
	//    22. INVLPG - Invalidate TLB entry
	//    23. INVPCID - Invalidate process context identifier
	//    24. HLT - Halt processor
	//    25. RSM - Return from system managment mode ( SMM )
	//    26. RDMSR - Read model specific register
	//    27. WRMSR - Write model specific register
	//    28. RDPMC - Read performance monitoring counters
	//    29. RDTSC - Read time stamp counter
	//    30. RDTSCP - Read time stamp counter and processor ID
	//    31. SYSENTER - Fast system call, transfers to a flat protected mode kernel at CPL = 0
	//    32. SYSEXIT - Fast system call, transfers to a flat protected mode kernel at CPL = 3
	//    33. XSAVE - Save processor extended states to memory
	//    34. XSAVEC - Save processor extended states with compaction to memory
	//    35. XSAVEOPT - Save processor extended states to memory, optimized
	//    36. XSAVES - Save processor supervisor-mode extended states to memory
	//    37. XRSTOR - Restore processor extended states from memory
	//    38. XRSTORS - Restore processor supervisor-mode extended states from memory
	//    39. XGETBV - Reads the state of an extended control register
	//    40. XSETBV - Writes the state of an extended control register


// ***********************************************************************   64 Bit Mode Instructions   ********************************************************************* //


	//  The following instructions are introduced in 64 bit mode :
	//
	//    1. CDQE - Convert doubleword to quadword
	//    2. CMPSQ - Compare string arguments
	//    3. CMPXCHG16B - Compare RDX:RAX with m128
	//    4. LODSQ - Load quadword from address RSI into RAX
	//    5. MOVSQ - Move quadword from address RSI to RDI
	//    6. MOVZX - Move bytes/words to doublewords/quadwords, zero extension
	//    7. STOSQ - Store RAX at address RDI
	//    8. SWAPGS - Exchanges current GS base register value in MSR address C0000102H
	//    9. SYSCALL - Fast call to privilege level 0 system procedures
	//    10. SYSRET - Return from fast system call


// *********************************************************************   Virtual Machine Instructions   ******************************************************************* //


	// The behavior of the VMCS maintenance instructions is summarized below :
	//
	//    1. VMPTRLD - Takes a single 64 bit source argument in memory. It makes the referenced VMCS active and current
	//    2. VMPTRST - Takes a single 64 bit destination argument that is in memory. Current VMCS pointer is stored into the destination argument
	//    3. VMCLEAR - Takes a single 64 bit argument in memory. The instruction sets the launch state of the VMCS referenced by the operand to "clear", renders the VMCS inactive, and ensures
	//                 that data for the VMCS have been written to the VMCS data area in the referenced VMCS region
	//    4. VMREAD - Reads a component from the VMCS ( the encoding of that field is given in a register argument ) and stores it into a destination argument
	//    5. VMWRITE - Writes a component to the VMCS from a source argument
	//
	// The behavior of the VMX management instructions is summarized below :
	//
	//    1. VMLAUNCH - Launches a virtual machine managed by the VMCS. A VM entry occurs, transferring control to the VM
	//    2. VMXOFF - Causes the processor to leave VMX operation
	//    3. VMXON - Takes a single 64 bit source argument in memory. It causes a logical processor to enter VMX root operation and to use the memory referenced by the argument to support
	//               VMX operation
	//
	// The behavior of the VMX specific TLB management instructions is summarized below :
	//
	//    1. INVEPT - Invalidate cached extended page table ( EPT ) mappings in the processor to synchronize address translation in virtual machines with memory resident EPT pages
	//    2. INVVPID - Invalidate cached mappings of address translation based on the Virtual Processor ID ( VPID )
	//
	// The behavior of the guest available instructions is summarized below :
	//
	//    1. VMCALL - Allows a guest in VMX non root operation to call the VMM for service. A VM exit occurs, transferring control to the VMM
	//    2. VMFUNC - This instruction allows software in VMX non root operation to invoke a VM function, which is processor functionality enabled and configured by software in VMX root
	//                operation. No VM exit occurs


// ********************************************************************   Memory Protection Instructions   ****************************************************************** //


	// Memory protection extensions ( MPX ) provides a set of instructions to enable software to add robust bounds checking capability to memory references :
	//
	//    1. BNDMK - Create a lower bound and a upper bound in a register
	//    2. BNDCL - Check the address of a memory reference against a lower bound
	//    3. BNDCU - Check the address of a memory reference against an upper bound in 1's compliment form
	//    4. BNDCN - Check the address of a memory reference against an upper bound not in 1's compliment form
	//    5. BNDMOV - Copy or load from memory of the lower bound and upper bound to a register
	//    6. BNDMOV - Store to memory of the lower bound and upper bound from a register
	//    7. BNDLDX - Load bounds using address translation
	//    8. BNDSTX - Store bounds using address translation




// ************************************************************************************************************************************************************************** //
// ************************************************************************************************************************************************************************** //
// **														   				 INTERRUPT AND EXCEPTIONS                                                                      ** //
// ************************************************************************************************************************************************************************** //
// ************************************************************************************************************************************************************************** //




	// The processor provides two mechanisms for interrupting program execution, interrupts and exceptions!
	//
	//    1. An interrupt is an asynchronous event that is typically triggered by and I/O device
	//
	//    2. An exception is a synchronous event that is generated when the processor detects one or more predefined conditions while executing an instruction. There 
	//		are 3 types of exceptions :
	//
	//            1. Faults
	//            2. Traps
	//            3. Aborts
	//
	// The processor responds to interrupts and exceptions in essentially the same way. When an interrupt or exception is signaled, the processor halts execution of the 
	// current program or task and switches to a handler procedure that has been written specifically to handle the interrupt or exception condition. The processor accesses 
	// the handler procedure through an entry in the interrupt descriptor table ( IDT ). When the handler has completed handling the interrupt or exception, program control 
	// is returned to the interrupted program or task!
	//
	// There are 18 predefined interrupts and exceptions and 224 user defined interrupts, which are associated with entries in the IDT. Each interrupt and exception in the 
	// IDT is identified with a number. The numbers 0-8, 10-14 and 16-19 are the predefined interrupts and exceptions. The numbers 23-255 are for software defined interrupts, 
	// which are for wither software interrupts or maskable hardware interrupts
	//
	// When the processor detects an interrupt or exception, it does one of the following :
	//
	//    1. Executes an implicit call to a handler procedure
	//    2. Executes an impicit call to a handler task




// ************************************************************************************************************************************************************************** //
// ************************************************************************************************************************************************************************** //
// **														   				  MEMORY CACHE CONTROL                                                                         ** //
// ************************************************************************************************************************************************************************** //
// ************************************************************************************************************************************************************************** //




	// The Intel architectures support cache, translation look aside buffers ( TLB ) and a store buffer for temporary on chip ( and external ) storage of instructions and data. The
	// size and characteristics of these units are machine specific and may change in future versions of the processor. The 'CPUID' instruction returns the sizes and characteristics
	// of the caches and buffers for the processor on which the instruction is executed!
	//
	// In the 'Intel Core i' family of processors, the first layer of the cache ( L1 ) is divided into two sections, one section is dedicated to caching instructions ( pre decoded
	// instructions ) and the other caches data. The second layer of the cache ( L2 ) is a unified data and instruction cache. Each processor core has its own layer one and two. The
	// third layer ( L3 ) is an inclusive, unified data and instruction cache, shared by all processor cores inside a physical package. The cache lines for the first and second layers,
	// and also the third layer if supported, are 64 bytes wide. The processor always reads a cache line from system memory beginning on a 64 byte boundary. A cache line can be filled
	// from memory with a 8 transfer burst transaction. The caches do not support partially filled cache lines, so caching even a single byte required an entire line.
	//
	// The translation look aside buffers store the most recently used page directory and page table entries. They speed up memory accesses when paging is enabled by reducing the
	// number of memory accesses that are required to read the page tables stored in system memory. The translation look aside buffer are divided into four groups :
	//
	//    1. Instruction translation look aside buffer for 4KB pages
	//    2. Data translation look aside buffer for 4KB pages
	//    3. Instruction translation look aside buffer for large pages ( 2MB, 4MB or 1GB )
	//    4. Data translation look aside buffer for large pages ( 2MB, 4MB or 1GB )
	//
	// Processors based on Intel Core micro architectures implement one level of instruction translation look aside buffer and two levels of data translation look aside buffers. Intel Core
	// i7 processor provides a second level unified translation look aside buffers.
	//
	// The store buffer is associated with the processors instruction execution units. It allows writes to system memory and/or the internal caches to be saved and in some cases combined
	// to optimize the processor's bus accesses. The store buffer is always enabled in all execution modes!
	//
	// The processor's caches are for the most part transparent to software. When enabled, instructions and data flow through these caches without the need for explicit software control.
	// However, knowledge of the behavior of these caches may be useful optimizing software performance. For example, knowledge of cache dimensions and replacement algorithms gives an
	// indication of how large of data structure can be operated on at once without causing cache thrashing.
	//
	// In multiprocessor systems, maintenance of cache consistency may, in rare circumstances, require intervention by system software. For these rare cases, the processor provides
	// privileged cache control instructions for use in flushing caches and forcing memory ordering. There are several instructions that software can use to improve the performance
	// of the layer 1,2 and 3 caches.
	//
	// Intel 64 processors use the 'MESI' ( modified, exclusive, shared and invalid ) cache protocol to maintain consistency with internal caches and caches in other processors!
	// When the processor recognizes that an operand being read from memory is cache able, the processor reads an entire cache line into the appropriate cache or all. This operation
	// is called 'cache line fill'. If the memory location containing that operand is still cached the next time the processor attempts to access the operand, the processor can read
	// the operand from the cache instead of going back to memory. This operation is called a 'cache hit'.
	//
	// When the processor attempts to write to an operand to a cache able area of memory, it first checks if a cache line for that memory location exits in the cache. If a valid cache
	// line does exist, the processor ( depending on the write policy currently in use ) can write the operand into the cache instead of writing it out to system memory. This operation
	// is called a 'write hit'. If a valid cache line is not present for area of memory being written to, the processor performs a cache line fill, write allocation. Then it writes the
	// operand into the cache line and can also write it out to memory. If the operand is to be written out to memory, it is written first into the store buffer, and then written from
	// the store buffer to memory when the system bus is available. When operating in a multiprocessor system the processors have the ability to 'snoop' other processor's accesses to
	// system memory and to their internal caches. They use this snooping ability to keep their internal caches consistent both with system memory and with the caches in other
	// processors on the bus. If a processor detects through snooping that another processor is trying to access a memory location that is has modified in its cache, but has not yet
	// written back to system memory, the snooping processor will signal the other processor ( by means of the //HITM signal ) that the cache line is held in modified state and will
	// perform an implicit write back of the modified data. The implicit write back is transfered directly to the initial requesting processor with the valid data may pass the data
	// to the other processors without actually writing it to system memory, however, it is the responsibility of the memory controller to snoop this operation and update memory!



// ************************************************************************************************************************************************************************** //
// **														   			    METHODS OF CACHING AVAILABLE                                                                   ** //
// ************************************************************************************************************************************************************************** //



	// The processor allows any area of system memory to be cached in the layers 1,2 and 3 caches. In individual pages or regions of system memory, it allows the type of caching to be
	// specified. Current caching types supported are :
	//
	//    1. Strong Uncacheable ( UC ) - system memory locations are not cached. All reads and writes appear on the system bus and are executed in program order without reordering. No
	//                                   speculative memory accesses, page table walks or prefetches of speculated branch targets are made. This type of cache control is useful for
	//                                   memory mapped Input/Output devices. When used with normal RAM, it greatly reduces processor performance
	//
	//    2. Uncacheable ( UC- ) - has same characteristics as the strong uncacheable memory type, except that this memory type can be overridden by programming the MTRRs for the
	//                             write combining memory type. This memory type can only be selected through the PAT.
	//
	//    3. Write Combining ( WC ) - system memory locations are not cached and coherency is not enforced by the processor's bus coherency protocol. Speculative reads are allowed.
	//                                Writes may be delayed and combined in the write combining buffer to reduce memory accesses. If the write combining buffer is partially filled,
	//                                the writes may be delayed until the next occurrence of a serializing event, such as a memory barrier ( SFENCE, MFENCE ), CPUID instruction
	//                                execution, a read or write to uncached memory, an interrupt or a LOCK instruction execution. This type of cache control is appropriate for video
	//                                frame buffers, graphics display. This memory type can be selected through the PAT or programmed through the MTTRs
	//
	//    4. Wrtie Through ( WT ) - writes and reads to and from system memory are cached. Reads come from cache lines on cache hits, read misses cause cache fills. Speculative reads
	//                              are written to a cache line ( when possible ) and through to system memory. When writing through to memory, invalid cache lines are never filled,
	//                              and valid cache lines are either filled or invalidated. Write combining is allowed. This type of cache control is appropriate for frame buffers or
	//                              when there are devices on the system bus that access system memory. but do not perform snooping of memory accesses. It enforces coherency between
	//                              caches in the processors and system memory
	//
	//    5. Write Back ( WB ) - writes and reads to and from system memory are cached. Reads come from cache lines on cache hits, read misses cause cache fills. Speculative reads are
	//                           allowed. Write misses cause cache line fills, and writes are performed entirely in the cache, when possible. Write combining is allowed. The write back
	//                           memory type reduces bus traffic by eliminating many unnecessary writes to system memory. Writes to a cache line are not immediately forwarded to system
	//                           memory, instead they are accumulated in the cache. The modified cache lines are written to system memory later, when a write back operation is performed.
	//                           Write back operations are triggered when cache lines need to be deallocated, such as when new cache lines are being allocated in a cache that is already
	//                           full. They also are triggered by the mechanisms used to maintain cache consistency. This type of cache control provides the best performance, but it
	//                           requires that all devices that access system memory on the system bus be able to snoop memory accesses to ensure system memory and cache coherency
	//
	//    6. Write Protected ( WP ) - reads come from cache lines when possible, and read misses cause cache fills. Writes are propagated to the system bus and cause corresponding
	//                                cache lines on all processors on the bus to be invalidated. Speculative reads are allowed. This memory type is available by programming the MTRRs



// ************************************************************************************************************************************************************************** //
// **														   	   BUFFERING OF WRITE COMBINING MEMORY LOCATIONS                                                           ** //
// ************************************************************************************************************************************************************************** //



	// Writes to the 'Write memory type are not cached in the typical sense of the word cached. They are retained in an internal write combining buffer that is separate from the internal
	// layer 1,2 and 3 caches and the store buffer. The write combining buffer is not snooped and thus does not provide data coherency. Buffering of writes to this memory is done to allow
	// software a small window of time to supply more modified data to the write combining buffer while remaining as non-intrusive to software as possible. The buffering of writes to the
	// write combining memory also causes data to be collapsed, that is, mutliple writes to the same memory location will leave the last data written in the location and the other writes
	// will be lost.
	//
	// The size and structure of the write combining buffer is not architecturally defined. In some architectures it is made up of several 64 byte buffers. When software begins writing to
	// write combining memory, the processor begins filling the write combining buffers one at a time. When one or more write combining buffers has been filled, the processor has the option
	// of evicting the buffers to system memory. The protocol for evicting the write combining buffers is implementation dependent and should not be relied on by software for system memory
	// coherency. When using the write combining memory type, software must be sensitive to the fact that the writing of data to system memory is being delayed and must deliberately empty
	// the write combining buffers when system memory coherency is required!
	//
	// Once the processor has started to evict data from the write combining buffer into system memory, it will make a bus transaction style decision based on how much of the buffer contains
	// valid data. If the buffer is full ( all bytes are valid ), the processor will execute a burst write transaction on the bus. This results in all 64 bytes being transmitted on  the data
	// bus in a single burst transaction. If one or more of the write combining buffer's bytes are invalid ( have not been written by software ), the processor will transmit the data to
	// memory using "partial write" transactions ( each time 8 bytes ), which will result in 8 partial transactions for one write combining buffer of data sent to memory. The write
	// combining memory type is weakly ordered by definition. Once the eviction of a write combining buffer has started, the data is subject to the weak ordering semantics of its
	// definitions. Ordering is not maintained between the successive allocation/deallocation of write combining buffers. For example, write to write combining buffer 1 followed by writes
	// to write combining buffer 2 may appear as buffer 2 followed by buffer 1 on the system bus. When a write combining buffer is evicted to memory as partial writes there is no
	// guaranteed ordering between successive partial writes. For example, a partial write for chunk 2 may appear on the bus before the partial write for chunk 1 or vice versa )



// ************************************************************************************************************************************************************************** //
// **														   			  		 CHOSSING A MEMORY TYPE                                                                    ** //
// ************************************************************************************************************************************************************************** //



	// The simplest system memory model does not use memory mapped input/output with read or write side effects, does not include a frame buffer, and uses the write back memory type for all
	// memory. An input/output agent can perform direct memory access ( DMA ) to write back memory and the cache protocol maintains cache coherency.
	//
	// A system can use stron uncacheable memory for other memory mapped input/output, and should always use strong uncacheable memory for memory mapped input/output with read side effects.
	//
	// Dual ported memory can be considered a write side effect, making relatively prompt writes desirable, because those wrties cannot be observed at the other port until they reach the
	// memory agent. A system can use strong uncacheable, uncacheable, write through or write combining memory for frame buffers or dual ported memory that contains pixel values displayed
	// on a screen. Frame buffer memory is typically large ( a few megabytes ) and is usually wriiten more than it is read by the processor. Using strong uncacheable memory for a frame
	// buffer generates very large amounts of bus traffic, because operations on the entire buffer can displace almost all other useful cached memory for frame buffers whenever possible.
	//
	// Software can use page level cache control, to assign appropriate effective memory types when software will not access data structures in ways that benefit from write back caching.
	// For example, software may read a large data structure once and not access the structure again until it is rewritten by another agent. Such a large data structure should be marked
	// as uncacheable, or reading it will evict cached lines that the processor will be referencing again.
	//
	// A similar example would be a write only data structure that is written to export the data to another location, but never read by software. Such a structure can be marked as uncacheable,
	// because software never reads the values that it writes  ( though as uncacheable memory, it will be written using parital writes, while as write back memory, it will be written using
	// line writes, which may not occur until the other agent reads the structure and triggers implicit write backs ).



// ************************************************************************************************************************************************************************** //
// **														   			   CACHE FETCHES IN UNCACHEABLE MEMORY                                                             ** //
// ************************************************************************************************************************************************************************** //



	// Programs may execute code from uncacheable ( UC ) memory, but the implications are different from accessing data in uncacheable memory. When doing code fetches, the processor never
	// transitions from cacheable code to uncacheable code speculatively. It also never speculatively fetches branch targets that result in uncacheable code.
	//
	// The prcoessor may fetch the same uncacheable cache line multiple times in order to decode an instruction once. It may decode consecutive uncacheable instructions in a cache line
	// without fetching between each instruction. It may also fetch additional cache lines from the same or a consecutive 4KB page in order to decode one non speculative uncacheable
	// instruction ( this can be true even when the instruction is contained fully in one line ).
	//
	// Because of the above and because cache line sizes may change in future processors, software should avoid placing memory mapped input/output with read side effects in the same
	// page or in a subsequent page used to execute uncacheable code!



// ************************************************************************************************************************************************************************** //
// **														   			  		  CACHE CONTROL PROTOCOL                                                                   ** //
// ************************************************************************************************************************************************************************** //



	// In the layer 1 data cache and in the layer 2 and 3 unified caches, the MESI ( modified, exclusive, shared, invalid ) cache protocol maintains consistency with caches of
	// other processors. The layer 1 data cache and the layer 2 and 3 unified caches have two MESI status flags per cache line. Each line can be marked as being in one of the
	// following states :
	//
	//      CACHE LINE STATE                                         MODIFIED ( M )                 EXCLUSIVE ( E )              Shared ( S )                   Invalid ( I )
	//    ---------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//
	//
	//    This cache line is valid?                                     Yes                              Yes                         Yes                             No
	//
	//    The memory copy is...                                     Out of data                         Valid                        Valid                           --
	//
	//    Copies exist in caches of other processors?                    No                               No                         Maybe                          Maybe
	//
	//    A write to this line                                    Does not go to the              Does not go to the       Causes the processor to gain       Goes directly to the
	//                                                                system bus                      system bus          exclusive ownership of the line          system bus
	//
	// In general the operations of the MESI protocol is transparent to programs!



// ************************************************************************************************************************************************************************** //
// **														   			  		     CACHE CONTROL                                                                         ** //
// ************************************************************************************************************************************************************************** //



	// The Intel architecture provide a variety of mechanisms for controlling the caching of data and instructions and for controlling the ordering of reads and writes between
	// the processor, the caches and memory. These mechanisms can be divided into two groups :
	//
	// 1. Cache control registers and bits :
	//
	//    The following cache control registers and bits are for use in enabling or restricting caching to various pages or regions in memory :
	//
	//      1. CD flag, bit 30 of control register CR0 - controls caching of system memory locations. If the CD flag is clear, caching is enabled for the whole system memory, but may be
	//         restricted for individual pages or regions of memory by other cache control mechanisms. When the CD flag is set, caching is restricted, although the caches will still respond
	//         to snoop traffic. Caches should be explicitly flushed to ensure memory coherency. For highest processor performance, both the CD and the NW flags in control register CR0 should
	//         be cleared.
	//      2. NW flag, bit 29 of control register CR0 - controls the write policy for system memory locations. If the NW and CD flags are clear, write back is enabled for the whole of
	//         system memory, but may be restricted for individual pages or regions of memory by other cache control mechanisms. Note - this flag for Intel XEON processor has no effect!
	//      3. PCS and PWT flags in paging structure entries - control the memory type used to access paging structures and pages
	//      4. PCD and PWT flags in control register CR3 - control the memory type used to access the first paging structure of the current paging structure hierarchy
	//      5. Global flag ( G ) in the page directory and page table entries - controls the flushing of TLB entries for individual pages
	//      6. Page Global Enable flag ( PGE ) in control register CR4 - enables the establishment of global pages with the G flag
	//      7. Memory type range registers ( MTRRs ) control the type of caching used in specific regions of physical memory
	//      8. Page Attribute Table ( PAT ) model specific register - extends the memory typing capabilities of the processor to permit memory types to be assigned on a page by page basis
	//      9. Third level cache disable flag, bit 6 of the IA32_MISC_ENABLE model specific register ( available only in processors based on the Intel NetBurst microarchitecture ) - allows the layer 3 cache
	//         to be disabled and enabled, independently of the layer 1 and 2 caches
	//      10. KEN// and WB/WT// pins



// ************************************************************************************************************************************************************************** //
// **														   			  	 PRECEDENCE OF CACHE CONTROLS                                                                  ** //
// ************************************************************************************************************************************************************************** //



	// The cache control flags and MTRRs operate hierarchically restricting caching. That is, if the CD flag is set, caching is prevented globally. If the CD flag is clear, the page level
	// cache control flags and/or the MTRRs can be used to restrict caching. If there is an overlap of page level and MTRR caching controls, the mechanism that prevents caching has
	// precedence. For example, if an MTRR makes a region of system memory uncacheable, a page level caching control cannot be used to enable caching for a page in that region. The converse
	// is also true, that is, if a page level caching control designates a page as uncacheable, an MTRR cannot be used to make the page cacheable.
	//
	// In cases where there is a overlap in the assigenment of the write back and write through caching policies to a page and a region of memory, the write through policy takes precedence.
	// The write combining policy takes precedence over either write through or write back.
	//
	// The selection of memory types at the page level varies depending on whether PAT is being used to select memory types for pages.



// ************************************************************************************************************************************************************************** //
// **														    WRITING VALUES ACROSS PAGES WITH DIFFERENT MEMORY TYPES                                                    ** //
// ************************************************************************************************************************************************************************** //



	// If two adjoining pages in memory have different memory types, and a word or longer operand is written to a memory location that crosses the page boundary between those two pages,
	// the operand might be written to memory twice. This action does not present a problem for writes to actual memory, however, if a device is mapped the memory space assigned to the
	// pages, the device might malfunction.



// ************************************************************************************************************************************************************************** //
// **														   			  		 PREVENTING CACHING                                                                        ** //
// ************************************************************************************************************************************************************************** //



	// To disable the layer 1, 2 and 3 caches after they have been enabled and have received cache fills, the following steps need to be performed :
	//
	//    1. Enter the no fill cache mode ( CD = 1, NW = 0 )
	//    2. Flush all caches using the 'WBINVD' instruction
	//    3. Disable the MTTRs and set the default memory type to uncached or set all MTRRs for the uncached memory type



// ************************************************************************************************************************************************************************** //
// **														   			   CACHE MANAGEMENT INSTRUCTIONS                                                                   ** //
// ************************************************************************************************************************************************************************** //



	// The 'INVD' and 'WBINVD' instructions are privileged instructions and operate on the layer 1, 2, and 3 caches as a whole. The 'PREFETCHh', 'CLFLUSH' and 'CFLUSHOPT' instructions
	// and the non temporal move instructions ( 'MOVNTI', 'MOVNTQ' 'MOVNTDQ', 'MOVNTPS' and MOVNTPD' ) offer more granular control over caching, and are available to all privileged levels.
	//
	// The 'INVD' and 'WBINVD' instructions are used to invalidate the contents of the layer 1, 2 and 3 caches. The 'INVD' instruction invalidates all internal cache entries, then generates
	// a special function bus cycle that indicates that external caches also should be invalidated. The 'INVD' instruction should be used with care. It does not force a write back of
	// modified cache lines, therefore, data stored in the caches and not written back to system memory will be lost. Unless there is a specific requirement or benefit to invalidating the
	// caches without writing back the modified lines, software should use the 'WBINVD' instruction.
	//
	// The 'WBINVD' instruction first writes back any modified lines in all the internal caches, then invalidates the contents of both the layer 1,2 and 3 caches. It ensures that cache
	// coherency with main memory is maintained regardless of the write back policy in effect. Following this operation, the 'WBINVD' instruction generates one special function bus
	// cycles to indicate to external cache controllers that write back of modified data followed by invalidation of external caches archies and other factors. A a consequence, the use
	// of the "WBINVD" instruction can have an impact on interrupt/event response time!
	//
	// The 'PREFECTHh' instructions allow a program to suggest to the processor that a cache line from a specified location in system memory by prefetched into the cache hierarchy.
	//
	// The 'CLFLUSH' and 'CLFLUSHOPT' instructions allow selected cache lines to be flushed from memory. These instructions give a program the ability to explicitly free up cache space,
	// when it is known that caches section of system memory will not be accessed in the near future.
	//
	// The non-temporal move instructions 'MOVNTI', 'MOVNTQ', 'MOVNTDQ', 'MOVNTPS' and 'MOVNTPD' allow data to be moved from the processor's registers directly into system memory without
	// being also written into the layer 1,2 OR 3 caches. These instructions cab be used to prevent cache pollution when operating on data that is going to be modified only once before
	// being stored back into system memory. These instructions operate on data in the general purpose, MMX and XMM registers.



// ************************************************************************************************************************************************************************** //
// **														   			  LAYER 1 DATA CACHE CONTEXT MODE                                                                  ** //
// ************************************************************************************************************************************************************************** //



	// Layer 1 data cache context mode is a feature of processors based on the Intel NetBurst micro architecture that support Intel hyper threading technology. When :
	//
	//      CPUID.1:ecx[BIT 10] = 1
	//
	// The processor supports setting layer 1 data cache context mode using the layer 1 data cache context mode flag, bit 24 of IA32_MISC_ENABLE. Selectable modes are adaptive mode ( default )
	// and shared mode. The BIOS is responsible for configuring the layer 1 data cache context mode
	//
	// Adaptive mode :
	//
	//  Adaptive mode facilitates layer 1 data cache sharing between logical processors. When running in adaptive mode, the layer 1 data cache is shared across logical processors in the
	//  same core if :
	//
	//    1. CR3 control register for logical processors sharing the cache are identical
	//    2. The same paging mode is used by logical processors sharing the cache
	//
	//  In this situation, the entire layer 1 data cache is available to each logical processor ( instead of being competitively shared ). If CR3 values are different for the logical processors
	//  sharing an layer 1 data cache or the logical processors use different paging modes, processors compete for cache resources. This reduces the effective size of the cache for each
	//  logical processor. Aliasing of the cache is not allowed ( which prevents data thrashing ).
	//
	// Shared mode :
	//
	//  In shared mode, the layer 1 data cache is competitively shared between logical processors. This is true even if the logical processors use identical CR3 registers and paging modes. In
	//  shared mode, linear addresses in the layer 1 data cache can be aliased, meaning that one linear address in the cache can point to different physical locations. The mechanism for
	//  resolving aliasing can lead to thrashing. For this reason :
	//
	//      IA32_MISC_ENABLE[bit 24] = 0
	//
	//  Is the preferred configuration for processors based on the Intel NetBurst micro architecture that support Intel hyper threading technology.



// ************************************************************************************************************************************************************************** //
// **														   			  		SELD MODIFYING CODE                                                                        ** //
// ************************************************************************************************************************************************************************** //



	// A write to a memory location in a code segment that is currently caches in the processor causes the associated cache line ( or lines ) to be invalidated. This check is based on the
	// physical address of the instruction. In addition, some processors ( P6 family and Pentium ) check whether a write to a code segment may modify an instruction that has been prefetched
	// for execution. If the write affects a prefetched instruction, the prefetch queue is invalidated. This latter check is based on the linear address of the instruction. For the Pentium
	// 4 and Intel Xeon processors, a write or a snoop of an instruction in a code segment, where the target instruction is already decoded and resident in the trace cache, invalidates the
	// entire trace cache. The latter behavior means that programs that self modify code can cause sever degradation of performance on this processors.
	//
	// Applications that include self modifying code use the same linear address for modifying and fetching the instruction. System software, such as debugger, the might possibly modify an
	// instruction using a different linear address than that used to fetch the instruction, will execute a serializing operation, such as 'CPUID' instruction, before the modified instruction
	// is executed, which will automatically resynchronize the instruction cache and prefetch queue



// ************************************************************************************************************************************************************************** //
// **														   			  		  IMPLICIT CACHING                                                                         ** //
// ************************************************************************************************************************************************************************** //



	// Implicit caching occures when a memory element is made potentially cacheable, although the element may never have been accessed in the normal von Neumann sequence. Implicit caching
	// occurs due to aggressive prefetching, branch prediction and TLB miss handling. To avoid problems related to implicit caching, the operating system must explicitly invalidate the
	// cache when changes are made to cacheable data that the cache coherency mechanism does not automatically handle. This includes writes to dual ported or physically aliased memory boards
	// that are not detected by the snooping mechanism of the processor, and changes to page table entries in memory



// ************************************************************************************************************************************************************************** //
// **														   			  		   EXPLICIT CACHING                                                                        ** //
// ************************************************************************************************************************************************************************** //



	// The 'PREFETCHh' instructions provide software with explicit control over the caching of data. These instructions provide "hints" to the processor that the data requested by this
	// instructions should be read into the cache hierarchy now or as soon as possible, in anticipation of its use. The instructions provide different variations of the 'hint' that allow
	// selection of the cache level into which data will be read.
	//
	// The 'PREFETCHh' instructions can help reduce the long latency typically associated with reading data from memory and thus help prevent processor "stalls". However, these instructions
	// should be used judiciously. Overuse can lead to resource conflicts and hence reduce the performance of an application. Also, these instructions should only be used to prefetch data
	// from memory, they should not be used to prefetch instructions



// ************************************************************************************************************************************************************************** //
// **														  INVALIDATING THE TRANSLATION LOOKASIDE BUFFER ( TLB )                                                        ** //
// ************************************************************************************************************************************************************************** //



	// The processor updates its address translation caches transparently to software. Several mechanisms are available, however, that allow software and hardware to invalidate this buffers
	// either explicitly or as a side effect of another operation. The following operations invalidate all translation lookaside buffers, irrespective of the setting of the G flag :
	//
	//  1.Asserting or deasserting the FLUSH// pin
	//  2. Writing to an MTRR, with a WRMSR instruction
	//  3. Writing to control register CR0 to modify the PG or PE flag
	//  4. Writing to control register CR4 to modify the PSE, PGE or PAE flag
	//  5. Writing to control register CR4 to change the PCIDE flag from 1 to 0



// ************************************************************************************************************************************************************************** //
// **														   			  		    STORE BUFFER                                                                           ** //
// ************************************************************************************************************************************************************************** //



	// Intel processors temporarily store each write to memory in a store buffer. The store buffer improves processor performance by allowing the processor to continue executing instructions
	// without having to wait until a write to memory and/or to a cache is complete. It also allows writes to be delayed for more efficient use of memory access bus cycles. In general, the
	// existence of the store buffer is transparent to software, even in systems that use multiple processors. The processor ensures that write operations are always carried out in program
	// order. It also insures that the contents of the store buffer are always drained to memory in the following situations :
	//
	//  1. When an exception or interrupt is generated
	//  2. When a serializng instruction is executed
	//  3. When an input/output instruction is executed
	//  4. When a LOCK prefix is used
	//  5. When a BINIT operation is performed
	//  6. When using an SFENCE instruction to order stores
	//  7. When using MFENCE instruction to order stores



// ************************************************************************************************************************************************************************** //
// **														   			 MEMORY TYPE RANGE REGISTERS ( MTRRs )                                                             ** //
// ************************************************************************************************************************************************************************** //



	// The memory type range registers provide a mechanism for associating the memory types with physical address ranges in system memory. They allow the processor to optimize operations for
	// different types of memory such as random access memory, read only memory, frame buffer memory and memory mapped input/output devices. They also simply system hardware design by eliminating
	// the memory control pins used for this function on earlier processors and the external logic needed to drive them.
	//
	// The memory type range registers mechanism allows up yo 96 memory ranges to ce defubed in physical memory, and iut defines a set of moidel specific registers ( model specific registers ) for specifying
	// the type of memory that is contained in each range.
	//
	// Following a hardware reset, the processor disable all the fixed and variable memory type range registers, which in effect makes all of physical memory uncacheable. Initialization
	// software should then set the memory type range registers to a specific, system defined memory map. Typically, the basic input/output system ( BIOS ) software configures this registers.
	// The operating system or executive is then free to modify the memory map using the normal page level cacheability attributes.
	//
	// In a multiprocessor system, each processor MUST use the identical memory map for the memory type range registers so that software will have a consistent view of memory! This consistency
	// is not implemented in hardware.
	//
	//                            Memory Type And Mnemonic                    Encoding In Memory type range registers
	//
	//                                    Uncacheable                                           0x00
	//                                  Write Combining                                         0x01
	//                                     Reserved                                             0x02
	//                                     Reserved                                             0x03
	//                               Write through ( WT )                                       0x04
	//                              Write protected ( WP )                                      0x05
	//                                 Writeback ( WB )                                         0x06
	//                                     Reserved                                          0x07 - 0xFF
	//
	// Use of the reserved encodings results in a general protection exception ( //GP )


// ****************************************************************************   Identification   ************************************************************************** //


	// The availability of the memory type range registers feature is model specific. Software can determine if the feature is supported on a processor using the 'CPUID' instruction and
	// reading the state of the memory range type registers flag in the feature information register ( EDX part of the RDX register bit 12 ).
	//
	// If the memory type range registers feature is supported, additional information can be obtained from the 64 bit IA32_MTRRCAP MSR. The IA32_MTRRCAP model specific register is a read only model specific register that can
	// be read with the 'RDMSR' instruction. The functions of the flags and fields in this register are as follows :
	//
	//  1. Variable range registers count ( VCNT ) bits 0-7 - indicates the number of variable ranges implemented on the processor
	//  2. Fixed range registers supported bit 8 - IA32_MTRR_FIX64K_00000 through IA32_MTRR_FIX64K_F8000, are supported when this bit is set ON
	//  3. Write combining ( WC ) bit 10 - the write combining memory type is supported when set
	//  4. System management range register ( SMRR ) bit 11 - the system management range register interface is supported when this bit is set ON
	//
	// Bit 9 and bits 12-63 are reserved. If software attempts to write to it, a general protection exception ( //GP ) is generated. Software must read IA32_MTRRCAP variable range registers
	// count to determine the number of variable memory type range registers and query other feature bits in IA32_MTRRCAP to determine additional capabilities that are supported in a
	// processor


// *******************************************************************************   Setting   ****************************************************************************** //


	// The memory ranges and the types of memory specified in each range are set by three groups of registers :
	//
	//  1. IA32_MTRR_DEF_TYPE MSR
	//  2. The fixed range memory type range registers
	//  3. The variable range memory type registers
	//
	// These registers can be read and written to using the 'RDMSR' and 'WRMSR' instuctions. The IA32_MTRRCAP model specific register indicates the availability of these registers on the processor


// **************************************************************   IA32_MTRR_DEF_TYPE Model specific register   ************************************************************ //


	// The IA32_MTRR_DEF_TYPE model specific register sets the default properties of the regions of physical memory that are not encompassed by memory type range registers. The functions of the
	// flags and field in this register are as follows :
	//
	//  1. Type field, bits 0 through 7 - indicates the default memory type used for those physical memory address ranges that do not have a memory type specified for them by an memory type
	//     range register. The legal values for this field are 0,1,4,5 and 6. All other values result in a general protection exception ( //GP ) being generated. Intel recommends the use of the
	//     uncached memory type for all physical memory addresses where memory does not exist. To assign the uncached type to nonexistent memory locations, it can either be specified as the
	//     default type in the type field or be explicitly assigned with the fixed and variable memory type range registers
	//
	//  2. Fixed memory type range registers flag ( FE ), bit 10 - fixed range memory type range registers are enabled when set and disabled when clear. When this is enabled it takes priority
	//     over the variable range memory type range registers when overlaps in ranges occur
	//
	//  3. Memory type range register flag ( E ), bit 11 - memory type range registers are enabled when set and disabled when clear. The uncached memory type is applied to all of physical
	//     memory. When this flag is set, the fixed range flag can disable the fixed range memory type range registers. When this flag is clear the fixed range flag has no meaning. When this
	//     flag is set, the type specified in the default memory type field is used for areas of memory not already mapped by either a fixed or variable memory type range register


// ****************************************************************   Fixed range memory type range registers   ************************************************************* //


	// The fixed memory ranges are mapped with 11 fices range registers of 64 bits each. Each of these registers is divided into 8 bit fields that are used to specify the memory type for
	// each of the sub ranges the register controls :
	//
	//  1. Register IA32_MTRR_FIX64K_00000 - maps the 512 KiloByte address range from 0x0 - 0x7FFFF. This range is divided into eight 64 KiloByte sub ranges
	//  2. Register IA32_MTRR_FIX16K_80000 and IA32_MTRR_FIX16K_A0000  - maps the two 128 KiloByte address ranges from 0x80000 - 0xBFFFF. This range is divided into sixteen 16 KiloByte sub
	//     ranges, 8 ranges per register register
	//  3. Register IA32_MTRR_FIX4K_C0000 and IA32_MTRR_FIX4K_F80000 - maps eight 32 KiloByte address ranges from 0xC0000 - 0xFFFFF. This range is divided into sixty four 4 KiloByte sub
	//     ranges, 8 ranges per register


// **********************************************************   System management range register ( SMRR ) interface   ******************************************************* //


	// If IA32_MTRRCAP[bit 11] is set, the processor supports the system management range register interface to restrict access to a specified memory address range used by system
	// management mode ( SMM ) software. If the system management range register interface is supported, system management mode software is strongly encouraged to use it to protect
	// the system management interrupt code and data stored by system management interrupt handler in the system management mode memory ( SMRAM ) region.
	//
	// The system management range registers consist of a pair of model specific registers. The IA32_SMRR_PHYSBASE model specific register defines the base address for the system
	// management mode memory range and the memory type used to access it in system management mode. The IA32_SMRR_PHYSMASK model specific register contains a valid bit and a mask
	// that determines the system management mode memory address range protected by the system management range register interface. These registers may be written only in system
	// management memory, an attempt to write them from other scope cause a general protection exception.
	//
	// The functions of these flags and fields are the following :
	//
	//  1. Type field, bits 0 through 7 - specifies the memory type for the range
	//  2. PhysBase field, bits 12 through 32 - specifies the base address of the address range. The address must be less then 4 GigaBytes and is automatically aligned on a 4 KiloByte boundary
	//  3. PhysMask field, bits 12 through 31 - specifies a mask that determines the range of the region being mapped, according to the following relationships :
	//      - Address_Within_Range AND PhysMask = PhysBase AND PhysMask
	//      - This value is extended by 12 bits at the low end to form the mask value
	//  4. Valid ( V ) flag, bit 11 - enables the register pair when set, and disables when clear
	//
	// Before attempting to access these system management range registers, software must test bit 11 in the IA32_MTRRCAP register. If it is not supported, reads or writes to that registers
	// cause general protection exceptions.
	//
	// When the valid flag in the IA32_SMRR_PHYSMASK model specific register is 1, accesses to the specified address range are treated as follows :
	//
	//  1. If the logical processor is in system management mode, accesses uses the memory type in the IA32_SMRR_PHYSBASE model specific register
	//  2. If the logical processor is not in system management mode, write accesses are ignored and read accesses return a fixed value for each byte. The uncachable memory type ( UC ) is
	//     used in this case
	//
	// The above itmes apply even if the address range specified overlaps with a range specified by the memory type range registers.


// *****************************************************************   Range size and alignment requirement   *************************************************************** //


	// A range that is to be mapped to a variable range memory type range register must meet the following "power of 2" size and alignment rules :
	//
	//  1. The minimum range size is 4 KiloByte and the base address of the range must be on at least a 4 KiloByte boundary
	//  2. For ranges greater than 4 KiloBytes, each range must be of legnth 2^n and its base address must be aligned on a 2^n boundary, where n is a value equal to or greater than 12. The
	//     base address alignment value cannot be less than its length. For example, an 8 KiloByte range cannot be aligned on a 4 KiloByte boundary, it must be aligned on at least an 8
	//     KiloByte boundary


// *****************************************************************************   Precedences   **************************************************************************** //


	// If the memory



// ************************************************************************************************************************************************************************************************** \\
// ************************************************************************************************************************************************************************************************** \\
// *                                                                                                                                                                                                * \\
// *                                                                               MULTIPLE PROCESSOR INITIALIZATION                                                                                * \\
// *                                                                                                                                                                                                * \\
// ************************************************************************************************************************************************************************************************** \\
// ************************************************************************************************************************************************************************************************** \\




	// The multiple processor ( MP ) initialization protocol called the 'Multiprocessor specification version 1.4'. This specification defines the boot protocol to be used by processors
	// in multiple processor systems. The initialization protocol has the following important features :
	//
	//  1. It supports controlled booting of multiple processors without requiring dedicated system hardware
	//  2. It allows hardware to initiate the booting of a system without the need for a dedicated signal or a predefined boot processor
	//  3. It allows all processors to be booted in the same manner, including those supporting Intel hyper threading technology
	//
	// The selection of the bootstrap processor ( BSP ) and the application processors ( AP ) in the system is handled by platform specific arrangement of the combination of hardware,
	// BIOS, and/or configuration input options.



// ************************************************************************************************************************************************************************************************** \\
// *                                                                         Board support package and application processors                                                                       * \\
// ************************************************************************************************************************************************************************************************** \\



	// The multiprocessor initialization protocol defines two classes of processors, the bootstrap processor and the application processors. Following a power up or RESET of an
	// multiprocessor system, system hardware dynamically selects one of the processors on the system bus as the bootstrap processor. The remaining processors are designated as
	// application processors.
	//
	// As part of the bootstrap processor selection mechanism, the bootstrap flag is set in the 'IA32_APIC_BASE' model specific register of the bootstrap, indicating that it is the
	// bootstrap processor. This flag is cleared for all other processors.
	//
	// The bootstrap processor executes the BIOS's boot-strap code to configure the APIC environment, sets up system wide data structures, and starts and initializes the application processors.
	// When the bootstrap processor and the application processors are initialized, the bootstrap processor begins executing the operating system initialization code!
	//
	// Following a power up or reset, the application processors complete a minimal self configuration, then wait for a startup signal ( SIPI message ) from the bootstrap processor
	// Upon receiving a SIPI message, an application processor executed the BIOS application processor configuration code, which ends with the application processor being placed in
	// halt state.
	//
	// For processors supporting the Intel hyper threading technology, the multiprocessor initialization protocol treats each of the logical processors on the system bus or coherent
	// link domain as a separate processor ( with a unique APIC ID ). During boot up, one of the logical processors is selected as the bootstrap and the remainder of the logical
	// processors are designated as application processors



// ************************************************************************************************************************************************************************************************** \\
// *                                                                Multiprocessor initialization protocol requirements and restrictions                                                            * \\
// ************************************************************************************************************************************************************************************************** \\



	// The multiprocessor protocol imposes the following requirements and restrictions on the system :
	//
	//  1. The multiprocessor protocol is executed only after a power up or RESET. If the multiprocessor protocol has completed and a bootstrap is chosen, subsequent INITs ( either
	//     to a specific processor or system wide ) do not cause the multiprocessor protocol to be repeated. Instead, each logical processor examines its bootstrap flag to determine
	//     whether it should execute the BIOS boot-strap code, if it is the bootstrap processor or enter a wait for SIPI state, if it is one of the application processorss
	//  2. All devices in the system that are capable of delivering interrupts to the processors must be inhibited from doing so for the duration of the multiprocessor initialization
	//     protocol. The time during which interrupts must be inhibited includes the window between when the bootstrap issues an INIT-SIPI-SIPI sequence to an application protocol
	//     and when the application processor responds to the last SIPI in the sequence



// ************************************************************************************************************************************************************************************************** \\
// *                                                                           Multiprocessor initialization protocol algorithm                                                                     * \\
// ************************************************************************************************************************************************************************************************** \\



	// Following a power up or RESET of an multiprocessor system, the processor in the system execute the multiprocessor initialization protocol algorithm to initialize each of the
	// logical processors on the system bus or coherent link domain. In the course of executing this algorithm, the following boot-up and initialization operations are carried out :
	//
	//  1.






// ************************************************************************************************************************************************************************************************** \\
// ************************************************************************************************************************************************************************************************** \\
// *                                                                                                                                                                                                * \\
// *                                                                                     MODEL SPECIFIC REGISTERS                                                                                   * \\
// *                                                                                                                                                                                                * \\
// ************************************************************************************************************************************************************************************************** \\
// ************************************************************************************************************************************************************************************************** \\




// ************************************************************************************************************************************************************************************************** \\
// *                                                                                 Read From Model Specific Register                                                                              * \\
// ************************************************************************************************************************************************************************************************** \\



	// Reads the contents of a 64 bit model specific register specified in the ECX part of the RCX register into the EDX:EAX parts of the RDX:RAX registers. The high order 32 bits of
	// RCX register are ignored. The EDX part of the RDX register is loaded with the high order








// ************************************************************************************************************************************************************************************************** \\
// ************************************************************************************************************************************************************************************************** \\
// *                                                                                                                                                                                                * \\
// *                                                                               PROCESSOR MANAGEMENT AND INITIALIZATION                                                                          * \\
// *                                                                                                                                                                                                * \\
// ************************************************************************************************************************************************************************************************** \\
// ************************************************************************************************************************************************************************************************** \\




// ************************************************************************************************************************************************************************************************** \\
// *                                                                                      INITIALIZATION OVERVIEW                                                                                   * \\
// ************************************************************************************************************************************************************************************************** \\



  // Following power up or an assertion of the RESET# pin, each processor on the system bus performs a hardware initialization of the processor ( known as
  // a hardware reset ) and an optional built in self test ( BIST ). A hardware reset sets each processor's registers to a known state and places the
  // processor in real address mode. It also invalidates the internal caches, translation lookaside buffers ( TLBs ) and the branch target buffer ( BTB ).
  // At this point, all the processors on the system bus ( including a single processor in a uniprocessor system ) execute the multiple processor ( MP )
  // initialization protocol. TYhe processor that is selected through this protocol as the bootstrap processor ( BSP ) then immediately starts executing
  // software initialization code in the current code segment beginning at the offset in the EIP register. The application ( non BSP ) processors ( APs )
  // go into a wait for startup IPI ( SIPI ) state while the boot starp processor is executing initialization code.
  //
  // The software initialization code performs all system specific initialization of the boot strap processor or primary processor and the system logic.
  // At this point, for multiple processor systems, the boot strap processor wakes up each processor to enable those processors to execute self configuration
  // code.
  //
  // When all processors are initialized, configured and synchronized, the boot strap processor begins executing an initial operating system or executive task.
  //
  // The x87 floating point unit ( FPU ) is also initialized to a known state during hardware reset. x87 floating point unit software initialization code
  // can then be executed to perform operations such as setting the precision of the x87 floating point unit and the exception masks. No special
  // initialization of the x87 floating point unit is required to switch operating modes.
  //
  // Asserting the INIT# pin on the processor invokes a similar response to a hardware reset. The major difference is that during an INIT, the internal caches,
  // MSRs, MTRRs, and x87 floating point unit state are left unchanged ( although, the translation look aside buffers and BTB are invalidated as with a
  // hardware reset ). An INIT provides a method for switching from protected to real address mode while maintaining the contents of the internal caches.



// ************************************************************************************************************************************************************************************************** \\
// *                                                                                     PROCESSOR STATE AFTER RESET                                                                                * \\
// ************************************************************************************************************************************************************************************************** \\



  // Following power up, the state of control register CR0 is 0x60000010. This places the processor in real address mode with paging disabled.


// ************************************************************************************   First instruction executed   ************************************************************************************


  // The first instruction that is fetched and executed following a hardware reset is located at physical address 0xFFFFFFF0. This address is 16 bytes
  // below the processor's uppermost physical address. The EPROM containing the software initialization code must be located at this address.
  //
  // The address 0xFFFFFFF0 is beyond the 1 mega byte addressable range of the processor while in real address mode. The processor is initialized to
  // this starting address as follows. The code segment ( CS ) register has two parts, the visible segment selector part and the hidden base address
  // part. In real address mode, the base address is normally formed by shifting the 16 bit segment selector value 4 bits to the left to produce a
  // 20 bit base address. However, during a hardware reset, the segment selector in the code segment register is loaded with 0xF000 and the base address
  // is loaded with 0xFFFF0000. The starting address is thus formed by adding the base address to the value in the instruction pointer ( EIP ) register,
  // that is :
  //
  //    0xFFFF0000 + 0xFFF0 = 0xFFFFFFF0
  //
  // The first time the code segment register is loaded with a new value after a hardware reset, the processor will follow the normal rule for address
  // translation in real address mode, that is :
  //
  //    code segment base address = code segment selector * 16
  //
  // To insure that the base address in the code segment register remains unchanged until the EPROM based software initialization code is completed, the
  // code must not contain a far jump or far call or allow an interrupt to occur ( which would cause the code segment selector value to be changed ).


// ******************************************************************************   x87 floating point unit initialization   ******************************************************************************


  // Software initialization code can determine whether the processor contains an x87 floating point unit by using the central processing unit identification
  // ( CPUID ) instruction. The code must then initialize the x87 floating point unit and set flags in control register CR0 to reflect the state of the
  // x87 floating point unit environment.
  //
  // A hardware reset places the x87 floating point unit in a certain state. This state is different from the state the x87 floating point unit is placed in
  // following the execution of an FINIT or FNINIT instruction. If the x87 floating point unit is to be used, the software initialization code should execute
  // an FINIT/FNINIT instruction following a hardware reset. These instructions, tag all data registers as empty, clear all the exception masks, set the top
  // of the stack value to 0 and select the default rounding and precision controls setting. If the processor is reset by asserting the INIT# pin, the x87
  // floating point unit state is not changed


// ***************************************************************************   configuring x87 floating point unit environment   ************************************************************************


  // Initialization code must load the appropriate values into the




















// ************************************************************************************************************************************************************************** //
// ************************************************************************************************************************************************************************** //
// **														   						  THE STACK                                                                            ** //
// ************************************************************************************************************************************************************************** //
// ************************************************************************************************************************************************************************** //




	// Typically, the stack is a memory region. It is possible to add data to the stack ( push ), or to retrieeve it and taje it out of the stack ( pop ). The last data
	// added to the stack is the first to be retrieved. Processors often hace instructioins to copy data from the registers to the stack and vise versa.
	//
	// In x86 assembly ( 32 bits ) :
	//
	//		MOV EAX, 20
	//		PUSH EAX     // Adds 20 to the stack
	//		POP EBX 	 // EBX will have the value 20, and the stack will be restored to its former state
	//
	// However, in most architectures, it is possivle to obtain data from the stack without actually popping it :
	//
	//		MOV EAX, [ESP+20]		// Will copy to EAX the contents od the stack 20 bytes before its current state




// ************************************************************************************************************************************************************************** //
// ************************************************************************************************************************************************************************** //
// **														   						  FUNCTIONS                                                                            ** //
// ************************************************************************************************************************************************************************** //
// ************************************************************************************************************************************************************************** //




// ************************************************************************************************************************************************************************** //
// **														   			  		FUNCTION CALL PROBLEMS                                                                     ** //
// ************************************************************************************************************************************************************************** //



	// Function call problems :
	//
	//		1. Calling and returning :
	//
	//			1. How does caller function jump to callee function?
	//
	//				Jump to the address of the calle's first instruction
	//
	//			2. How does callee function jump back to the right place in caller function?
	//
	//				Jump to the instruction immediately following the most recently executed call instruction
	//
	//		2. Passing parameters :
	//
	//			How does caller function pass parameters to callee function?
	//
	//		3. Storing local variables :
	//
	//			Where does callee function store its local variables?
	//
	//		4. Handling registers without interference :
	//
	//			How do caller and callee functons use same registers without interference?
	//
	//		5. Returning values
	//
	//			How does calleee function send return value back to caller function?
	//
	// To resolve this problems INTEL ARCHITECTURE 32 BITS ( IA-32 ) provided pertinent instructions and conventions, stay tunned!


// ************************************************************************   CALLING AND RETURNING   *********************************************************************** //


	// Attempted solution 1 - caller and callee use jmp instruction :
	//
	//
	//			FUNCTION_1:																		FUNCTION_2:
	//																	
	//					...				 	// Assembly code											...						// Assembly code
	//					jmp FUNCTION_2    	// Call FUNCTION_2 											jmp ReturnPoint_1		// Return to the next instruction in FUNCTION_1
	//
	//			ReturnPoint_1:				// Start the execution again from here
	//
	//					...
	//
	//
	// The problem with this approach is that a function might be called by many other functions :
	//
	//
	//			FUNCTION_1:																		FUNCTION_2:
	//																	
	//					...				 	// Assembly code											...						// Assembly code
	//					jmp FUNCTION_2    	// Call FUNCTION_2											jmp ??????				// Return to the next instruction in which function?
	//
	//			ReturnPoint_1:				// Start the execution again from here
	//
	//					...
	//
	//
	//
	//																	FUNCTION_3:																		
	//																	
	//																			...				 	// Assembly code												
	//																			jmp FUNCTION_2    	// Call FUNCTION_2											
	//
	//																	ReturnPoint_2:				// Start the execution again from here
	//
	//																			...
	//
	//
	// Attempted solution 2 - use register :
	//
	//
	//			FUNCTION_1:																					FUNCTION_2:
	//													
	//					movl $ReturnPoint_1, %eax		// Store the return point address		
	//					...				 				// Assembly code											...						// Assembly code
	//					jmp FUNCTION_2    				// Call FUNCTION_2											jmp *%eax				// Return to the address in eax
	//
	//			ReturnPoint_1:							// Start the execution again from here
	//
	//					...
	//
	//
	//
	//																	FUNCTION_3:																		
	//																	
	//																			movl $ReturnPoint_2, %eax		// Store the return point address
	//																			...				 				// Assembly code												
	//																			jmp FUNCTION_2    				// Call FUNCTION_2											
	//
	//																	ReturnPoint_2:							// Start the execution again from here
	//
	//																			...
	//
	//
	// The problem with this apprach is that it can not handle nested function calls :
	//
	//
	//			FUNCTION_1:																					FUNCTION_2:
	//													
	//					movl $ReturnPoint_1, %eax		// Store the return point address		
	//					...				 				// Assembly code											...						// Assembly code
	//					jmp FUNCTION_3    				// Call FUNCTION_3											jmp *%eax				// Return to the address in eax
	//
	//			ReturnPoint_1:							// Start the execution again from here
	//
	//					...
	//
	//
	//
	//																	FUNCTION_3:																		
	//																	
	//																			movl $ReturnPoint_2, %eax		// Store the return point address
	//																			...				 				// Assembly code												
	//																			jmp FUNCTION_2    				// Call FUNCTION_2											
	//
	//																	ReturnPoint_2:							// Start the execution again from here
	//
	//																			...
	//
	//																			jmp %eax 						// Return to the address in eax
	//
	//
	// This illustrates that if FUNCTION_1 calls FUNCTION_3 which then call FUNCTION_2, the content of ReturnPoint_2 will be there and ReturnPoint_1 will be lost
	//
	// INTEL ARCHITECTURE 32 BITS solution is to use the stack :
	//
	//		1. May need to store many return addresses :
	//
	//			1. The number of nesterd fuinction is not known in advance
	//			2. A return address must be saved for as long as the function invocation continues, and discarded thereafter
	//
	//		2. Adresses used in reverse order :
	//
	//			The stack is growing from the last address in the program memory and allocated more space towards lower memory addresses :
	//
	//
	//														_________________________
	//														|						|
	//														|	   Stack start		|   <-  Last memory address ( bigger value )
	//														|			|			|
	//														|			|			|
	//														|			|			|
	//														|			|			|
	//														|			|			|
	//														|		Stack end		|   <-  Lower memory address ( smaller value )
	//														|						|
	//														|						|
	//														|						|
	//
	//
	//		3. Last in first out ( LIFO ) data structure ( STACK ), caller pushes return address on the stack, and callee pops return address of  the stack
	//
	//		4. 2 functions are provided for this mission -> call and ret
	//
	//
	//			FUNCTION_1:																					FUNCTION_2:
	//													
	//					...				 				// Assembly code											...						// Assembly code
	//
	//					call FUNCTION_2    				// Call FUNCTION_2											ret 					// Use the ret function 
	//					call FUNCTION_3    				// Call FUNCTION_3											
	//
	//					... 							// Assembly code
	//
	//
	//																	FUNCTION_3:																		
	//																	
	//																			...				 				// Assembly code	
	//											
	//																			call FUNCTION_2    				// Call FUNCTION_2	
	//
	//																			ret								// Use the ret function



