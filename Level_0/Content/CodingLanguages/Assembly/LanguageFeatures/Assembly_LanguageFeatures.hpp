namespace Universe
{


// The following file is realted to the x86 assembly!!










// ************************************************************************************************************************************************************************** //
// ************************************************************************************************************************************************************************** //
// **														   					   ASSEMBLY LANGUAGE                                                                       ** //
// ************************************************************************************************************************************************************************** //
// ************************************************************************************************************************************************************************** //




// Intel and AMD processors are generally x86 architecture where as ARM processors are RISC processors based on ARM architecture. ARM processors
// offer lower performance than Intel and AMD, but they also consume lower power. For a desktop Intel or AMD are almost a must. ARM processors
// are generally used in mobile phones, smart watches and other low power devices!
//
// The two most widely used Instruction Set Architecture ( ISA ) are the Intel x86 and ARM architectures :
//
//  1. All of Intel and AMD processors ( across desktop, laptops, servers, etc... ) uses x86 instruction set architecture
//  2. ARM instruction set architecture is used by most of the mobile processors
//
// If 64 bit is called 'x64' then why 32 bit is called 'x86' instead of 'x32' in terms of computer architecture?
//
// 32-bit Intel processors are often referred to as x86, and 64-bit Intel processors are often referred to as x86-64. The reason is historical,
// but the popular line of Intel processors started with a model that they had designated as the 8086. Later models had designations like 80286
// and 80386 and collectively were referred to as 80x86 processors, or x86 for short. The x86 architecture evolved but the core instruction set
// remained the same, allowing backwards compatibility with software built for earlier x86 processors.
//
// Eventually, an Intel competitor named AMD started developing processors that used the same instruction sets as Intel processors so that they
// could use the same software and support the same peripheral hardware. When companies like Sun and DEC were delivering 64-bit processors for
// their RISC platforms, AMD designed a 64-bit chip instruction set with 64-bit instructions and left the 32 bit ones in place, allowing it to
// run both 32-bit and 64-bit programs. For a while, people were calling this the AMD64 family processors, but when Intel followed up with
// their own x86 family processors with 64-bit instructions, most started calling x86-64. Shortly thereafter, Intel released a new family of
// CPUs with a very different architecture and different instruction set called IA64, which never gained the traction of the x86-64 processors!



// ************************************************************************************************************************************************************************** //
// **														   			    HARDWARE AND SOFTWARE CONNECTION                                                               ** //
// ************************************************************************************************************************************************************************** //



// A system resource is a tool used by either hardware or software to communicate with each other. When software wants to send data to a device ( save file 
// to hard drive etc... ), or when the hardware needs attention ( a key was pressed on the keyboard etc... ), the hardware and software uses system resources 
// to communicate. There are 4 types of system resources :
//
// 		1. Memory addresses
// 		2. Input/Output addresses
// 		3. Interrupt request numbers ( IRQ )
// 		4. Direct memory access
//
// When a key is pressed on the keyboard, it should be notified to the CPU. But the CPU is usually busy doing something else, so the keyboard places a voltage 
// on the interrupt request line assigned to it. This voltage serves as a signal to the CPU that the device has a request which needs processing. Input/Output 
// addresses, which are simply called ports, are numbers that the CPU use to access hardware, in much the same way it uses memory address to access physical 
// memory. The address bus on the motherboard sometimes carries memory addresses and sometimes carries input/output addresses. If the address has been set to 
// carry input/output addresses, then each hardware device listens to the bus. Each hardware device is assigned input/output address. This way the CPU sets the 
// input/output address on the bus, notify all the devices that they should listen, and then send the required address. Every device check if this is his 
// address, and this way the CPU can communicate only with the required device
//
// To conclude, hardware devices notify the CPU using interrupt request. Software calls hardware using Input/Output addresses. Software treat memory as an 
// hardware device, and calls it using memory addresses. And finally direct memory channels move data back and forth between hardware device and memory



// ************************************************************************************************************************************************************************** //
// **														   			     CENTRAL PROCESSING UNIT RELAX                                                                 ** //
// ************************************************************************************************************************************************************************** //



// The instructions :
//
//		"REP; NOP" and "PAUSE;"
//
// Are equal. On previous processors, this simply did nothing, just like 'nop' but in two bytes. On new processors 
// which support hyperthreading, it is used as a hint to the processor that a busy waiting loop is in action to increase performance!
//
// Improves the performance of spin wait loops. When executing a "spin wait loop", a Pentium 4 or Xeon processor suffers a severe performance penalty
// when exiting the loop because it detects a possible memory order violation. The 'PAUSE' instruction provides a hint to the processor that the code
// sequence is a spin wait loop. The processor uses this hint to avoid the memory order violation in most situations, which greatly improves processor 
// performance. For this reason, it is recommended that a 'PAUSE' instruction be placed in all spin wait loops.
//
// An additional function of the 'PAUSE' instruction is to reduce the poser consumed by a processor while busy waiting loop!


// The following function will allow the central processing unit to postpond ( pause ) for a few colock ticks before moving on. This is useful when 
// creating loop busy waiting
inline void CentralPrcessingUnit_Pause()
{  
    // The following is an extended inline assembly statement. It will be used to delay the processing unit for a finite time. This is not 
    // possible only using C++

	__asm__ volatile ( 	"PAUSE;"			/* Delay the central processing unit for a finite time */
					   : 					/* Output arguments */
					   :					/* Input arguments */
					   : "memory" );		/* Clobbers and scratch registers */
}




// ************************************************************************************************************************************************************************** //
// **														   			           TEXT MANIPULATION                                                                       ** //
// ************************************************************************************************************************************************************************** //




// Use this macro to add the mark for the end of the assembly line "\n\t" after the text and quation marks "" around it :
//
//		TEXT = DEVIL  -->  after MACRO  -->   "DEVIL\n\t"
//		
#define AddToAssemblyInstructionLineEndMarkAndSurroundWithQuationMarks( TEXT ) "\"" #TEXT ";"




// ************************************************************************************************************************************************************************** //
// **														   			         		SHIFT BITS                                                                         ** //
// ************************************************************************************************************************************************************************** //



// The assembly instructions to shift bits are : 
//
//		1. SAL - shift arithmetic left for signed - multiply of the given operand by 2 the amounts of times provieded
//		2. SAR - shift arithmetic right for signed - divide of the given operand by 2 the amounts of times provieded
//		3. SHL - shift arithmetic left for unsigned - multiply the given operand by 2 the amounts of times provieded
//		4. SHR - shift arithmetic right for unsigned - divide of the given operand by 2 the amounts of times provieded
//
// Shifts the bits in the destination argument to the left or right by the number of bits specified in the second argument. Bits shifted beyond 
// the destination argument are first shifted into the CG FLAG, THEN DISCARDED. At the end of the shift operation, the CF flag contains the last
// bits shidted out of the destination argument. The second argument can be an immediate value or the content of the CL part of the RAX register,
// and must be in the range of the register number of bits ( in this case 63 shifts is the most shifts possible in 64 bits system )
//
// The shift arithmetic left for signed and unsigned instructions perform the same operation, they shift the bits in the destination argument
// to the left ( towrads more significant bits ). For each shift count, the most significant bit of the destination argument is shifted into the
// carry flag ( CF ), and the least significant bit is cleard.
//
// The shift arithemetic right for signed and unsigned shifts the bits of the destination argument to the right ( towards less significant bits ).
// For each shift count, the least significant of the destination argument is shifted into the carry flag ( CF ), and the most significant bit
// is ether set or clreaded depending on the instruction type. The unsigned right shift ( SHR ) instruction clears the most significant bit. The
// signed right shift ( SAR ) instruction sets or clears the most significant bit to correspond to the sign ( most significant bit ) of the original
// value in the destination argument.
//
// The overflow flag ( OF ) is affected only on 1 bit shifts. For left shifts, the overflow flag is set OFF ( 0 ), if the most significant bit of
// the result us the same as the carry flag ( CF ). In other words, the 2 most significant bits had the same state. Otherwise it is set ON ( 1 )
// For the signed right arithmetic shift instruction, the overflow flag is cleared for all 1 bit shifts. For unsigned right arithmetic shift
// instruction, the overflow flag is set to the most significant bit of the original argument
//
// Flags affected :
//
// The carry flag contains the value of the last bit shifted out of the destination argument. It is undefined for unsigned arithmetic right and left
// shift instructions where the number of bits to shift is greater than or equal to the number of bits in the destination argument. The overflow flag
// is affected only for 1 bit shifts, otherwise it is undefined. The sign flag, zero flag and parity flag are set according to the result. If the 
// number of bits to shift is 0 the flags are not affected, and for a non zero the auxilary flag is undefined
//
//      Hardware Exceptions :
//
//          1. #SS(0) - if a memory address referencing the SS segment is in a non canonical form
//          2. #GP(0) - if the memory address is in a non canonical form
//          3. #PF(fault-code) - if a page fault occurs
//          4. #AC(0) - if alignment checking is enabled and an unaligned memory reference is made while the current privilege is 3
//          5. #UD - if the LOCK prefix is used but the destination is not a memory operand


// The following macro will be used to left shift the bits of the given signed integer. In other words, it will multiply the signed integer by 2 the 
// number of bits that should be shifted
// #define LeftShiftSignedInteger( SignedInteger, NumberOfTimesToShift ) __asm__ volatile ( "SignedInteger" )



// ************************************************************************************************************************************************************************** //
// **														   			         REGISTER ABSOLUTE VALUE                                                                   ** //
// ************************************************************************************************************************************************************************** //



// The absolute value will be calculated as follows :
//
//	AbsoluteValue( X ) = ( X ^ ( X >> 31 ) ) - ( X >> 31 )
//
// The 'SAR' instruction will be used which pushes bits at the most signficant place each shift at a state that matched the state of the most
// significant bit at the beginning, to maintain the sign of the integer negative if necessary.
//
// This is for a signed integer of course. Then only in the case that it is negative and it is stored as the 2's complement form of the positive 
// value, the operation should take place. The point is to reverse the 2'x complement back to the positive number, then :
//
//		( X >> 31 )  -  0xFFFFFFFF...  -  if X is negative
//		
//		( X >> 31 )  -  0x00000000...  -  if X is positive
//
// Now an integer XOR zero does not affect the integer, and when the integer is XOR'ed with 0xFFFFFF... the result is the 1's complement, and all 
// there is left to do it to add 1 to get the 2's complement!


// The following macro will store the absolute value of a signed integer instead the current value. Two register lables must be provided. The 
// first for the register that contains the signed integer, and the other one to use for the computation
#define Assembly_AbsoluteValue( RegisterLabelWithSignedInteger_AfterTheCallWillContainTheResultAbsolutevalue, RegisterLabelToUseForTheComputation ) CreateStringBySurroundWithQuatationMarks( CMP RegisterLabelWithSignedInteger_AfterTheCallWillContainTheResultAbsolutevalue, 0; )												\
																																					CreateStringBySurroundWithQuatationMarks( JGE POSITIVE%=; )  																													\
																																					CreateStringBySurroundWithQuatationMarks( MOV RegisterLabelToUseForTheComputation, RegisterLabelWithSignedInteger_AfterTheCallWillContainTheResultAbsolutevalue; )			\
																																					CreateStringBySurroundWithQuatationMarks( SAR RegisterLabelToUseForTheComputation, 31; )																						\
																																					CreateStringBySurroundWithQuatationMarks( XOR RegisterLabelWithSignedInteger_AfterTheCallWillContainTheResultAbsolutevalue, RegisterLabelToUseForTheComputation; )			\
																																					CreateStringBySurroundWithQuatationMarks( ADD RegisterLabelWithSignedInteger_AfterTheCallWillContainTheResultAbsolutevalue, 1; )												\
																																					"POSITIVE%=:;"




// ************************************************************************************************************************************************************************** //
// ************************************************************************************************************************************************************************** //
// **														   					   GNU ASSEMBLY                                                                            ** //
// ************************************************************************************************************************************************************************** //
// ************************************************************************************************************************************************************************** //




// ************************************************************************************************************************************************************************** //
// **														   			          GNU ASSEMBLER                                                                            ** //
// ************************************************************************************************************************************************************************** //



// *******************************************************************************   SYNTAX   ******************************************************************************* //


// This section describes the machine-independent syntax allowed in a source file!


// To create a comment use  ->  /* comment */


// The last character of any input file should be a newline!!


// The GNU assembler internal preprocessor :
// 
// Capabilities :
// 
//  1. Adjusts and removes exta whitespace. It leaves one spcae or tab before the keywords on a line, and turns any other whitespace on the line into a single space
//  2. Removes all commetns, replacing them with a single space, or an appropriate number of newlines
//  3. Converts character constants into the appropriate numeric values 


// Symbols :
// 
// A symbol is one or more characters chosen from the set of all letters ( both upper and lower case ), digits and the three characters '_' '.' '$'. Case is significant.
// No symbol may start with a digit!


// Statements :
// 
// A statement ends at a new line character ( '\n' ) or line seperator ( ';' ). In both cases the characters are considered part of the preceding statement. An empty 
// statement is allowed, and may include whitespace, it is just ignored. A statement begins with zero or more labels, optionally followed by a key symbol which 
// determines what kind of statement it is. The key symbol determines the syntax of the rest of the statement. If the symbol begins with a dot '.' the the statement
// is an assembler directive ( typically valid for any computer ). If the symbol begins with a letter the statement is an assembly language instruction, it assembels
// into a machine language instruction
// 
// A label is a symbol immediately followed bt a colon ':'. Whitespace before a lavel or after a colon is permittes, but you may not have whitespace between a label's
// symbol and its colon


// Integers :
// 
// 	1. Binary - '0b' or '0B' - OB01110101
// 	2. Octal - '0' - 01234567
// 	3. Decimal - starts with a non zero digit - 1234567890
// 	4. Hexadecimal - '0x' or '0X' - 0X0123456789ABCDEF


// Floating point number :
// 
// Represented as Flonum
// 
// The GNU assembler does all processing using integers. Meaning they are computed independently of any floating point hardware in the computer running it


// GNU assembler was invented to support a 32-bit unix compiler, it uses standard AT&T syntax, and is standard in the UNIX world. 
// 
// Here are the major caveats about the syntax :
// 
// 	1. Register names are prefixed with %, so that registers are %eax, %dl and so on, instead of just eax, dl, etc. This makes it possible to include external C symbols 
// 	   directly in assembly source, without any risk of confusion, or any need for ugly underscore prefixes
// 
// 	2. The order of operands is source first, and destination last, as opposed to the Intel convention of destination first and sources last
// 
// 	3. The operand size is specified as a suffix to the instruction name. The suffix is b for ( 8-bit ) byte, w for ( 16-bit ) word, and l for ( 32-bit ) long. The default
// 	   is 32-bit ( with a warning )
// 
// 	4. Immediate operands are marked with a $ prefix, as in addl $5,%eax ( add immediate long value 5 to register %eax )
// 
// 	5. Missing operand prefix indicates that it is memory-contents. Hence movl $foo,%eax puts the address of variable foo into register %eax, but movl foo,%eax puts the 
// 	   contents of variable foo into register %eax.
// 
// 	6. Indexing or indirection is done by enclosing the index register or indirection memory cell address in parentheses, as in testb $0x80,17(%ebp) ( test the high bit 
// 	   of the byte value at offset 17 from the cell pointed to by %ebp )




// ***********************************************************************   SECTIONS AND RELOCATION   ********************************************************************** //


// Roughly, a section is a range of addresses, with no gaps. All the data in those addresses is treated the same for some particular purpose. For example there may be a
// "read only" section. The GNU linker ( ld ) reads mant object files ( partial programs ) and combines their contents to form a runnable program. When the assembler
// emits an object file, the partial program is assumed to start at address 0. The linker addigns the final addresses for the partial program, so the different
// partial programs do not overlap
// 
// The linker moves blocks of bytes of the program to their run time addresses. These blocks slide to their run time addresses as rigid units. Their length does not change
// and neither does the order of bytes within them. Such a rigid unit is called a section. Assigning run time addresses to sections is called relocation. It includes the
// task of adjusting mentions of object file addresses so they refer to the proper run time addresses. 
// 
// An object file written by the assembler has at least three sections, any of which may by empty. These are named text, data and bss sections. When it generates ELF 
// output, the assembler can also generate whatever other named sections specified using the '.section' directive. Within the object file, the text section starts at
// address 0, the data section followes, and the bss section after it. To let the linker know which data changes when the sections are relocated, and how to change
// the data, the assembler also writes to the object file details of the relocation needed. To perform relocation the linker must know each time an address in the
// object file is mentioned :
// 
// 	1. Where in the object files is the beginning of this reference to an address?
// 	2. How long in bytes is this reference?
// 	3. Which section does the address refer to? What is the numeric value of  ->  { section starting address, offset into section }
// 	4. Is the reference to an address "Program Counter relative"?
// 
// Absolute section is another section. When the linker mixes partial programs, addresses in the absolute section remain unchanged. For example, address { absolute, 0 }
// is relocated to run time address 0 by the linker
// 
// The idea of section is extended to the undefined section. Any address whose section is unknown at assembly time is br definition rendered undefined, where it will
// be filled in later. Since numbers are always defined, the only wat to generate an undefined address is to mention an undefined symbol. 
// 
// By analogy the word section is used to describe groups of sections in the linked program. The linker puts all partial programs text sections on contiguous addresses
// in the linked program, and so it is for the data and bss
// 
// Linker sections :
// 
// 	1. named, text and data sections - these sections hold the program. The assembler and linker treat them as separate but equal sections. Anything you can say of 
// one sections is trie pf amptjer.


// ********************************************************************   CALL ASSEMBLY FUNCTION FROM C   ******************************************************************* //


// The following main C function is passing two parameters to the asm function. The first being a pointer to the start of an integer array; the second parameter being 
// the size of that array
// 
// Here is the code :
// 
//  		// include <stdio.h>
//  
//  		// prototype for asm function
//  		int* asm_mod_array( int* pointer,int size );
//  
//  		int main() 
// 		{
//  			int lopl[5]={ 1, 2, 3, 4, 5 };
//  
//  			// call the asm function
//  			asm_mod_array( lopl, 5 );
//  
//  			return 0;
//  		}
// 
// Note prototyping and calling an asm function is the same as with a regular C function.
// 
// Now here is the code for the assembly function:
// 
// 
// 		Description - this function takes an int array and multiplies every element by 2 and adds 5
// 
// 		Variables - the registers have the following uses :
// 
//  		%edi - Holds the index of the data item being examined
//  		%ecx - size of the array
//  		%eax - pointer to first item in array
//  		%edx - used for scratch space
// 
//  		.section .text
// 
//  			.globl asm_mod_array
//  			.type asm_mod_array, @function
// 
//  			asm_mod_array:
// 
//  				pushl %ebp
//  				movl %esp, %ebp
//  				movl 8(%ebp),%eax          //  get pointer to start of array passed from C
//  				movl 12(%ebp),%ecx         //  get size of array
//  				xorl %edi, %edi            //  zero out our array index
// 
//  			start_loop:                //  start loop
// 
//  				cmpl %edi, %ecx            //  check to see if we’ve hit the end
//  				je loop_exit
//  				movl (%eax,%edi,4), %edx   //  store the element in %edx for calculations
//  				leal 5(,%edx,2), %edx      //  multiply array element by 2 and add 5
//  				movl %edx, (%eax,%edi,4)   //  overwrite old element with new value
//  				incl %edi                  //  increment the index, moving through the array.
//  				jmp start_loop             //  jump to loop beginning
// 
//  			loop_exit:                 //  function epilogue
// 
//  				movl %ebp, %esp
//  				popl %ebp
//  				ret                        //  pop the return address and jmp to it
// 
// Do not modify the eax register after the pointer has been copied into it, so the return value of the asssembly function ( in accordance with the C function calling 
// convention ) will be the pointer.
// 
// These programs both compile on a 32 bit linux system using ‘as’ and ‘gcc’. To use simply compile each program to a .o ( object file ) and then link them together 
// using gcc -o


// The following assembly command :
//
//		 mov QWORD PTR -184[rbp], rax
//
// Means treat the value inside the register RAX as a pointer and stroe it in the memory address -> value in register RBP - 184



// ************************************************************************************************************************************************************************** //
// **														   			           EXTENDED INLINE ASSEMBLY                                                                ** //
// ************************************************************************************************************************************************************************** //



// Extended inline assembly, means assembler instructions with C expression arguments!
//
// With extended inline assembly C variables can be read and written from assembly and perform jumps from assembler code to C labels. Syntax :
//
//      asm asm_qualifiers ( AssemblerTemplate : OutputArguments : InputArguments : Clobbers )
//
//  Or,
//
//      asm asm_qualifiers ( AssemblerTemplate : : InputArguments : Clobbers : GotoLables )
//
// In the second form the asm-qualifier must be "goto", when in the first one it must not be!
//
// The extended inline assembly allows to include assembly instructions directly within C code. This may help to maximize performance in time sensitive code or to 
// access assembly  instructions that are not readily available to C programs. Extended inline assembly must appear inside a function!! Only basic assembly may be 
// outside functions.
//
// Special format strings :
//
//  The following tokens have special meanings in the assembler template :
//
//    1. '%%' - outputs a single '%' into the assembler code
//
//    2. '%=' - outputs a number that is unique to each instance of the extended inline assembly statement in the entire compilation. This options is useful when 
//			   creating local labels  and referring to them multiple times in a single template that generated multiple assembler instructions
//
//    3. '%{', '%|', '%}' - outputs the characters '{', '|', '}' respectively into the assembler code. When unescaped, these characters have special meaning to 
//						   indicate multiple assembler  dialects



// *************************************************   Difference between __asm__, __asm__ volatile, and the clobber memory   *************************************************//
 

// The keyword volatile is used after the __asm__ keyword to ensure the assembly statement will not be deleted. The volatile keyword indicates that the 
// instruction has important side effects. GCC will not delete an assembly statement with volatile if it is reachable. An extended inline assembly without 
// output arguments will be treated identically to declaring it volatile!
//
// Then :
//
//    __asm__ ("");
//
//    __asm__ volatile ("");
//
// This 2 forms create a point in the code which may not be deleted ( unless it is proved to be unreachable )
//
// Now :
//
//    __asm__ ( "" ::: "memory" );
//
//    __asm__ volatile ( "" ::: "memory" );
//
// The "memory" clobber makes GCC assume that any memory may be arbitrarily read or written by the assembly block, so it will prevent the compiler from 
// reordering loads or stores across it. This will cause GCC to not keep memory values cached in registers across the assembler instruction and not optimize 
// stores or loads to that memory. This does not prevent a central processing unit from reordering loads and stores with respect to another central processing unit!


// *****************************************************************************   Qualifiers   ***************************************************************************** //


// The possible qualifiers are :
//
//    1. volatile - the typical use of inline assembly statements is to manipulate input arguments values to produce output values. However, if the assembly 
//					statement has side effects, the volatile qualifier needs to be used to disable certain optimizations
//
//    2. inline - if this qualifier is used, then for inlining purposes the size of the assembly statement is taken as the smallest size possible
//
//    3. goto - this qualifier informs the compiler that the assembly statement may perform a jump tp one of the C lables


// **************************************************************************   Output Arguments   ************************************************************************** //


// Any extended inline assembly has zero or more output operands indicating the names of C variables modified by the assembler code. Arguments are separated 
// by commas. Each argument has  the following format :
//
//          [ [ asmSymbolicName ] ] constraint ( cvariablename )
//
//  1. asmSymbolicName - specifies a symbolic name for the operand. Reference the name in the assembler template by enclosing it in square brackets. The 
//						 scope of the name is the current  statement that contains the definition. Any valid C variable name is acceptable, including names 
//						 already defined in the surrounding code
//
//  2. Constraint - a string constant specifying constraints on the placement of the operand. Output constraints must begin with either '=' ( a variable 
//					overwriting an existing value ) or '+' ( when reading and writing ). When using "=", it is wrong to assume the location contains the 
//					existing value on entry to the extended inline assembly, except when the argument is tied to an input. After the prefix, there must be 
//					one or more additional constraints that describe where the value resides. Common constraints  include 'r' for register and 'm' for memory. 
//					When more than one possible location, the compiler chooses the most efficient one based on the current context. Listing  as many alternates 
//					as the extended inline assembly statement  allows, permits the optimizers o produce the best possible code
//
//  3. cvariablename - specifies a C lvalue expression to hold the output, typically a variable name. The enclosing parentheses are a required part of the syntax
//
// The total number of input + output + goto arguemtns is limited to 30!!
//
// When the compiler selects the registers to use to represent the output arguments, it does not use any of the clobbered registers. Output operand expressions 
// must be lvalues. The compiler cannot check whether the arguments have data types that are reasonable for the instruction being executed. For output 
// expressions that are not directly addressable ( for  example a bit field ), the constraint must allow a register.
//
// Arguments using the '+' constraint modifier count as two arguments ( input and output argument ) towards the total maximum of 30 arguments per statement.
//
// The '&' constraint modifier should be added on all output arguments that must not overlap an input. Otherwise, GCC may allocate the output operand in the 
// same register as an unrealted input argument, on the assumption that the assembler code consumes its inputs before producing outputs. This assumption may 
// be false if the assembler code actually consists of more than one instruction
//
// The 'i' constraint tells the compiler that it should treat the argument as an integer
//
// The same problem can occur if one output parameter ( a ) allows a register constraint and another output parameter ( b ) allows a memory constraint. The 
// code generated by the GCC to access the memory address in b can contain registers which might be shared by a, and considers those to be inputs to the 
// extended inline assembly. GCC assumes that such input registers are consumed before any outputs. The assumption may result in incorrect behavior if the 
// statement write to a before using b. Combining the '&' modifier with the register constraint on a ensures that modifying a does not affect the address 
// referenced by b. Otherwise, the location of b is undefined if a is modified before using b
//
// If the C code that follows the extended inline assembly makes no use of any of the output arguments, use volatile to prevent the optimizers discarding 
// the statement as unneeded!
//
// This code makes no use of the optional assmelby symbolic name. Therefore it references the first output operand as %0 (were there a second, it would be 
// %1, etc). The number of the first input operand is one greater than that of the last output operand. In this example, that makes Mask referenced as %1 :
//
//			int Mask = 666;
//			int Index = 0;
//
//			__asm__ ( "bsfl %1, %0"
//					  : "=r" ( Index )
//					  : "r" ( Mask )
//					  : "cc" );
//
// That code overwrites the variable Index ( ‘=’ ), placing the value in a register ( ‘r’ ). Using the generic ‘r’ constraint instead of a constraint for 
// a specific register allows the compiler to pick the register to use, which can result in more efficient code. This may not be possible if an assembler 
// instruction requires a specific register.
//
// The following example uses the assmelby symbolic name syntax. It produces the same result as the code above, but some may consider it more readable or 
// more maintainable since reordering index numbers is not necessary when adding or removing operands. The names Index and Mask are only used in this example 
// to emphasize which names get used where. It is acceptable to reuse the names Index and Mask :
//
//			int Mask = 666;
//			int Index = 0;
//
//			__asm__ ( "bsfl %[ Mask ], %[ Index ]"
//					  : [ Index ] "=r" ( Index )
//					  : [ Mask ] "r" ( Mask )
//					  : "cc" );


// There was no way to tell GCC that the inline assembly produces useful information in the RFLAGS register. To work around this, programs must either copy
// the data from the RFLAGS register to a general register, or retest whatever condition was contained within the flags. 
//
// For example,
//
//			long TestBit( voltaile unsigned long* address, long bitNumber )													
// 			{
//				long bitCurrentState = 0;			
//				
//				__asm__ volatile ( 	"bt %[BitNumber], %[Address];"
//									"sbb %[BitCurrentState], %[BitCurrentState];"
//								   : [BitCurrentState] "=r" ( bitCurrentState )
//								   : [BitNumber] "Ir" ( bitNumber ), [Address] "m" ( address )
//								   : "cc" );
//				
//				return ( bitCurrentState );
//			}
//
// Here, the instruction tests the bit state and stores it in the carry flag. The second instruction then moves the carry bit to the a variable, so it can 
// returned to the calling function.
//
// The inefficiency comes when the surrounding code goes to use that result!
//
// For example,
//
//			if ( TestBit( address, bitNumber ) == true )
//			{
//				DoSomethingWithYourself();
//			} 			
//
// Compiles to :
//
//			BT [RDX], RAX
//			SBB RCX, RCX
//			TEST RCX, RCX
//			JZ .L1
//			CALL DoSomethingWithYourself
//			.L1
//
// Which is two more instructions than is ideal.
//
// With this extended inline assembly feature, the function can be written as :
//
//			long TestBit( voltaile unsigned long* address, long bitNumber )													
// 			{
//				long bitCurrentState = 0;			
//				
//				__asm__ volatile ( 	"bt %[BitNumber], %[Address];"
//								   : [BitCurrentState] "=rc" ( bitCurrentState )
//								   : [BitNumber] "Ir" ( bitNumber ), [Address] "m" ( address )
//								   : "cc" );
//				
//				return ( bitCurrentState );
//			}
//
// This tells GCC that the bit current state is a boolean value that can be formed by testing the carry bit of the RFLAGS register. Now GCC can 
// optimize the it to :
//
//			BT [RDX], RAX
//			JNC .L1
//			CALL DoSomethingWithYourself
//			.L1
//
// All the following conditions are supported :
//
//		1. 'a' - “above” or unsigned greater than ( The inverted is - 'na' )
// 		2. 'ae' - “above or equal” or unsigned greater than or equal ( The inverted is - 'nae' )
// 		3. 'b' - “below” or unsigned less than ( The inverted is - 'nb' )
// 		4. 'be' - “below or equal” or unsigned less than or equal ( The inverted is - 'nbe' )
// 		5. 'c' - carry flag set ( The inverted is - 'nc' )
// 		6. 'e','z' - “equal” or zero flag set ( The inverted is - 'ne', 'nz' )
// 		7. 'g' - signed greater than ( The inverted is - 'ng' )
// 		8. 'ge' - signed greater than or equal ( The inverted is - 'nge' )
// 		9. 'l' - signed less than ( The inverted is - 'nl' )
// 		10. 'le' - signed less than or equal ( The inverted is - 'nle' )
// 		11. 'o' - overflow flag set ( The inverted is - 'no' )
// 		12. 'p' - parity flag set ( The inverted is - 'np' )
// 		13. 's' - sign flag set ( The inverted is - 'ns' )
//
// The presence of the extended inline assembly feature may be detected by the built in preprocessor define '__GCC_ASM_FLAGS_OUTPUTS__'


// **************************************************************************   Input Arguments   ************************************************************************** //


// Input arguments make values from C variable and expressions available to the assembly code. Arguments are separated by comma. Each argument has the format :
//
//          [ [ asmSymbolicName ] ] constraint ( cvariablename )
//
// When the compiler selects the registers to use to represent the input arguments, it does not use any of the clobbered registers!
//
// If there are no output arguments but there are input arguments, use the syntax :
//
//			int Mask = 666;
//			int Index = 0;
//
//			__asm__ ( "bsfl %[ Mask ], %[ Index ]"
//					  : /* No output arguments */
//					  : [ Mask ] "r" ( Mask ) );
//
// Modification of the contents of input-only arguments ( except for inputs tied to outputs ) must not be changed. The compiler assumes that on exit from 
// the extended inline assembly statement these arguments contain the same values as they had before executing the statement. It is not possible to use 
// clobbers to inform the compiler that the values in these inputs are changing. One common work-around is to tie the changing input variable to an output 
// variable that never gets used. Note, however, that if the code that follows the statement makes no use of any of the output arguments, the GCC optimizers 
// may discard the asm statement as unneeded
//
// In this example, the constraint "0" for input argument 1 says that it must occupy the same location as output argument 0. Only input arguments may use 
// numbers in constraints, and they must each refer to an output argument. Only a number ( or the symbolic assembler name ) in the constraint can guarantee 
// that one operand is in the same place as another. The mere fact that the name of both arguments is the same is not enough to guarantee that they are in 
// the same place in the generated assembler code.
//
//			__asm__ ( "bsfl %2, %0"
//					  : "=r" ( god )
//					  : "0" ( god ), "g" ( Camel ) );


// *******************************************************************   Clobbers And Scratch Registers   ******************************************************************* //


// While the compiler is aware of changes to entries listed in the output arguments, the assembly code may modify more than just the output arguments. For 
// example, calculations may require additional registers, or the processor may overwrite a register as a side effect of a particular assembler instruction. 
// In order to indform the compiler of these changes, the clobber list exist. Clobber list items are either register name or special clobbers keywords. Each 
// clobber list item is a string constant enclosed in double quotes and separated by commas.
//
// Clobber descriptions may not in any way overlap with an input or output argument!
//
// When the compiler selects which registers to use to represent input and output arguments, it does not use any of the clobbered registers. As a result, 
// clobbered registers are available for any use in the assembler code.
//
// Example :
//
//			__asm__ ( "movc3 %0, %1, %2"
//					  : /* No outputs */
//					  : "g" ( from ), "g" ( to ), "g" ( count )
//					  : "r0", "r1", "r2", "r3", "memory" );
//
// Also, there are two special clobber arguments :
//
//	1. "cc" - indicates that the assembler code modifies the flags register
//
//	2. "memory" - tells the compiler that the assembly code performs memory reads or writes to items other than those listed in the input and output 
//				  arguments ( for example, accessing the memory pointed to by one of the input registers ). To ensure memory contains correct values, 
//				  GCC may need to flush specific register values to memory before executing the assembly code. Further, the compiler does not assume 
//				  that any values read from memory before the assembly code remain unchanged after, it reloads them as needed. Using the "memory" clobber 
//				  effectively forms a read/write memory barrier for the compiler. Note, this clobber does not prevent the processor from doing speculative 
//				  reads past the extended inline assembly. To prevent that, processor specific fence instructions are needed
//
// Flushing registers to memory has performance implications and may be an issue for time sensitive code. Better information to GCC can be provided to avoid 
// this. At a minimum aliasing rules allow GCC to know what memory doesn't need to be flushed!



// ******************************************************************   Variables In Specified Registers   ****************************************************************** //



// It is possible to associate specific hardware registers with C variables. In almost all cases, allowing the compiler to assign registers produce the 
// best code. However under certain unusual circumstances, more precise control over the variable storage is required!
//
// A local register variable in C can be associated with a specified register using the syntax :
//
//      register int* Slim __asm__ ( "RegisterLabel" );
//
// The register keyword can not be combined with the static keyword. Also, the type qualifiers such as const and volatile should not be used, as the outcome 
// may be contrary to expectations. It is recommended to choose a register that is normally saved and restored by function calls on the machine, so that calls 
// to library routines will not clobber it!
//
// The only supported use for this feature is to specify registers for input and output arguments when calling extended inline assembly. This may be necessary 
// if the constraints for a particular machine don't provide sufficient control to select the desired register
//
// Defining a register variable does not reserve the register. Other than when invoking the extended inline assembly, the contents of the specified register 
// are not guaranteed!



// *******************************************************************************   Labels   ******************************************************************************* //



// With GCC inline assembly, there is a problem regarding labels and inlined code.
//
// Consider the following simple jump:
//
// 		__asm__
// 		(
//     		"jmp out;"
//     		"out:;"
//     		:
//     		:
// 		);
//
// This does nothing except jump to the out label. As is, this code compiles fine. But if you place it inside a function, and then compile with optimization 
// flags, the compiler complains : 
//
//		"Error: symbol 'out' is already defined"
//
// What seems to be happening is that the compiler is repeating this assembly code every time it inlines the function. This causes the label out to get 
// duplicated, leading to multiple out labels.
//
// To work around this exist - '%='. '%=' in an assembler template is replaced with a number that is unique to each insn in the entire compilation. This 
// is useful for making local labels that are referred to more than once in a given insn. Note that to use %=, it must have at least one input ( although
// ther is no need to  actually use it ). For example :
//
// 		int a = 3;
//
// 		asm ( "test %0\n\t"
//     		  "jnz to_here%=\n\t"
//     		  "jz to_there%=\n\t"
//     		  "to_here%=:\n\t"
//     		  "to_there%=:"
//             :
//			   : "r" (a)
//			);
//
// This outputs :
//
// 		test %eax
// 		jnz to_here14
// 		jz to_there14
// 		to_here14:
// 		to_there14:
//
// Alternately, the asm goto can be used. This allow also to jump to c labels instead of just asm labels :
//
// 		asm goto ( "jmp %l0\n\t"
//  				: /* no output */
//  				: /* no input */
//  				: /* no clobber */
//  				: gofurther );
//
//
// 		printf("Didn't jump\n");
//
// 		/* c label : */
// 		gofurther:
//
// 		printf("Jumped\n");



// ************************************************************************************************************************************************************************** //
// **														   			ERRORS AND HOW TO DEAL WITH THEM                                                                   ** //
// ************************************************************************************************************************************************************************** //



// ***************************************************************   ERROR - operand type mismatch for `cmp'   *************************************************************** //


// When using the 'CMP' assembly instruction in the following way :
//
//		CMP 0xFFFFF000, EAX;
//
// The above error will be displayed. The solution is to add the character '%' before the hexadecimal :
//
//		CMP %0xFFFFF000, EAX;




}  //  namespace Universe
