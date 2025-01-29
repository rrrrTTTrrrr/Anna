namespace Universe
{


    namespace CentralProcessingUnit
    {



// Addressing modes :
//
// Wrapping brackets around an operand means that operand is to be dereferenced, as if it were a pointer in C. In other words, the brackets mean take the value in the register and use it
// as an address to the memory, rather than reading that value directly.
//
// So, this :
//
//			mov  eax, ebx
//
// Simply copies the value in ebx into eax.
//
// Whereas this :
//
//			mov  eax, [ ebx ]
//
// Dereferences the contents of ebx and stores the pointed-to value in eax.
//
// Finally, this :
//
// 			mov  [ eax ], ebx
//
// Stores the value in ebx into the memory location pointed to by eax.
//
// The registers here could also be replaced with memory operands, such as symbolic variable names. So this :
//
//			mov  eax, [myVar]
//
// Dereferences the address of the variable myVar and stores the contents of that variable in eax.
//
// By contrast, this :
//
//			mov  eax, myVar
//
// Stores the address of the variable myVar into eax.
//
// From the documentation for the MOV instruction, there are essentially five possibilities ( ignoring alternate encodings and segments ):
//
// 			mov  register, register     ; copy one register to another
// 			
//			mov  register, memory       ; load value from memory into register
// 			
//			mov  memory,   register     ; store value from register into memory
// 			
//			mov  register, immediate    ; move immediate value (constant) into register
// 			
//			mov  memory,   immediate    ; store immediate value (constant) in memory
//
// There is no :
//
// 			mov  memory, memory



// Memory addressing :
//
// The most general form of memory addressing :
//
//			BaseAddressRegister + ( IndexRegister * Width ) + Displacment
//
//	1. BaseAddressRegister - any general purpose register
//	2. IndexRegister - any general purpose register
//	3. Width - or scale, value to multiply the index register
//	4. Displacment - or offset, simple integer
//
// Mode :
//
//			Absolute ( using only displacnment )  ->  MOV RAX, [ 0100 ]
//
//			Register  ->  MOV RAX, [ RBX ]
//
//			Register + offset  ->  MOV RAX, [ RBX - 8 ]
//
//			( Register * Width ) + offset  ->  MOVE RAX, [ RBX * 4 + 0100 ]
//
//			BaseRegister + ( Register * Width ) + offset  ->  MOV RAX, [ RCX + RBX * 4 + 0100 ]
//
//
// Note that, given the definition of a label X in the global data section ( .data ) of an assembly program, using X
// to indicate the memory location, as in :
//
//			MOV RAX, X
//
// Is just absolute addressing ( using just a displacment ), where the assembler essentially replaces the name X with
// the address corresponding to X



// This file will be used to contain macros to allow inlint assembly more easy. In assembly an instruction
// can have very few forms :
//
//		1. instruction + arbitrary number of arguments - in reality 5 arguments cover almost all options
//		2. prefix + instruction + arbitrary number of arguments - the same as above
//
// A macro will be created for each type of instruction, but to make the use even clearer and simple to use
// the type of arguments will be taken into account also. The options are :
//
//		1. register
//		2. Memory address ( can be in register, or as immediate value )



// The following macros are for instructions that requires 1 argument. The following macros should not be used as they are in C code, they are only the 
// base macros for adding inline assembly into the code more easily. The argument can either be register, memory address or immediate value. When a 
// register is provided the content inside it acts as a value, but if the content represent a memory address of a value square brackets "[]" are added 
// around it, to notify the assembler to treat it as a memory address. The same goes for immediate value. So they both can act as values or memory 
// addresses. Until now 2 ways of accessing the memory were shown, here is a full list :
//
//			Absolute ( using only displacnment )  ->  MOV RAX, [ 0100 ]
//
//			Register  ->  MOV RAX, [ RBX ]
//
//			Register + offset  ->  MOV RAX, [ RBX - 8 ]
//
//			( Register * Width ) + offset  ->  MOVE RAX, [ RBX * 4 + 0100 ]
//
//			BaseRegister + ( Register * Width ) + offset  ->  MOV RAX, [ RCX + RBX * 4 + 0100 ]
//
// As can be seen there are actual more arguments required for more complex memory addressing calculations, but eventually it can be still seen in total 
// that the instruction has 1 argument!
//	
// Most instructions in assembly have this format, which is a set of 12 possibilites. The possible arguments are :
//
//			1. Register Label     ( RAX, RBX ... )
//
//			2. Immediate Value    ( 100, 0x0376 ... )
//
//			3. Offset ( which is also immediate value )
//
//			4. Width ( which is also immediate value ) - it can be 1,2,4,8
//
//			5. Base Register Label
//
// The possible ways of using the arguments :
//
//			1. Instruction RegisterLabel
//
//			2. Instruction [ RegisterLabel ]
	//
//			3. Instruction ImmediateValue
//
//			4. Instruction [ ImmediateValue ]
//
//			5. Instruction [ RegisterLabel + Offset ]
//
//			6. Instruction [ ( RegisterLabel * Width ) + Offset ]
//
//			7. Instruction [ BaseRegisterLabel + ( RegisterLabel * Width ) + Offset ]
//
// A macro will be created for each option. In each case only a register label and immediate values should be passed to the macro. To make the naming 
// more clear :
//
//		1. Register - when the content of the register will be used as a value
//		2. MemoryAddressInRegister - when the content of the register will be used as a memory address
//		3. Value - when an immediate value is required
//		4. MemoryAddressValue - when an immediate value is required, and it will be used us a memory address
//
// In the name of the macro will appear the above to describe what is needed and how it will be used
//
// Instruction prefixes are used to modify the following instruction. They are used to repeat string instructions, to provide section overrides, to
// perform bus lock operations, and to change operand and address sizes. Instruction prefixes are best written on the same line as the instruction
// they act upon
//
// The instruction prefix argument should be the assembly keyword!



// Use this macro to perform an assembly instruction on a register
#define Instruction_1argument_Register( InstructionPrefix, InstructionName, Register ) #InstructionPrefix #InstructionName #Register


// Use this macro to perform an assembly instruction on a memory address inside the source register and a destination register
#define Instruction_1argument_MemoryAddressInRegister( InstructionPrefix, InstructionName, MemoryAddressInRegister ) #InstructionPrefix #InstructionName #MemoryAddressInRegister


// Use this macro to perform an assembly instruction on a source immediate value and destination register
#define Instruction_1argument_ImmedaiteValue( InstructionPrefix, InstructionName, ImmediateValue ) #InstructionPrefix #InstructionName ImmediateValue


// Use this macro to perform an assembly instruction on a source absolute memory address value and a destination register
#define Instruction_1argument_MemoryAddressValue( InstructionPrefix, InstructionName, MemoryAddressValue ) #InstructionPrefix #InstructionName [ MemoryAddressValue ]


// Use this macro to perform an assembly instruction on a source register and destination memory address calculated using the content of the register added with the offset
#define Instruction_1argument_MemoryAddressInRegisterPlusOffset( InstructionPrefix, InstructionName, MemoryAddressInRegister, Offset ) #InstructionPrefix #InstructionName [ #MemoryAddressInRegister + Offset ]


// Use this macro to perform an assembly instruction on a source register and destination memory address calculated using the content of the register to multiply with the
// width and then add with offset
#define Instruction_1argument_MemoryAddressInRegisterMultipliedByWidthPlusOffset( InstructionPrefix, InstructionName, MemoryAddressInRegister, Width, Offset ) #InstructionPrefix #InstructionName [ #MemoryAddressInRegister * Width + Offset ]


// Use this macro to perform an assembly instruction on a source register and destination memory address calculated using the content of the register to multiply with the
// width and then add with offset and finally add the content of the base register
#define Instruction_1argument_BaseRegisterPlusMemoryAddressInRegisterMultipliedByWidthPlusOffset( InstructionPrefix, InstructionName, BaseRegister, MemoryAddressInRegister, Width, Offset ) #InstructionPrefix #InstructionName [ #BaseRegister + #MemoryAddressInRegister * Width + Offset ]



    }  //  Namespace CentralProcessingUnit

}  //  Namespace Universe