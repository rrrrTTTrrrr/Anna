namespace Universe
{


    namespace CentralProcessingUnit
    {



// The following macros are for instructions to be used in extended inline assembly. They would allow easy use of the assembly syntax, and access to 
// C++ variables. The following macros should not be used as they are 
// in C code, they are only the base macros for adding inline assembly into the code more easily. The argument can either be register, memory address or 
// immediate value. When a register is provided the content inside it acts as a value, but if the content represent a memory address of a value square 
// brackets "[]" are added around it, to notify the assembler to treat it as a memory address. The same goes for immediate value. So they both can act
// as values or memory addresses. Until now 2 ways of accessing the memory were shown, here is a full list :
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
// that the instruction has 2 arguments!
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
//			1. Instruction RegisterLabel, RegisterLabel
//
//			2. Instruction RegisterLabel, [ RegisterLabel ]
//
//			3. Instruction [ RegisterLabel ], RegisterLabel
//
//			4. Instruction RegisterLabel, ImmediateValue
//
//			5. Instruction RegisterLabel, [ ImmediateValue ]
//
//			6. Instruction RegisterLabel, [ RegisterLabel + Offset ]
//
//			7. Instruction RegisterLabel, [ ( RegisterLabel * Width ) + Offset ]
//
//			8. Instruction RegisterLabel, [ BaseRegisterLabel + ( RegisterLabel * Width ) + Offset ]
//
//			9. Instruction [ ImmediateValue ], RegisterLabel
//
//			10. Instruction [ RegisterLabel + Offset ], RegisterLabel
//
//			11. Instruction [ ( RegisterLabel * Width ) + Offset ], RegisterLabel
//
//			12. Instruction [ BaseRegisterLabel + ( RegisterLabel * Width ) + Offset ], RegisterLabel
//
// A macro will be created for each option. In each case only a register label and immediate values should be passed to the macro. To make the naming 
// more clear :
//
//		1. Register - when the content of the register will be used as a value
//		2. MemoryAddressInRegister - when the content of the register will be used as a memory address
//		3. Value - when an immediate value is required
//		4. MemoryAddressValue - when an immediate value is required, and it will be used us a memory address
//
// In the name of the macro will appear the above to describe what is needed and how it will be used, and in the arguments, an additional source or 
// destination will appear. The Intel 64 architecture sets the destination first and the source as second. It is more natural for me, and this is 
// important, the line "Take 'this' overthere" sounds better then "Take overthere this", therefore the macros will have the source first and the
// destination as second!
//
// Instruction prefixes are used to modify the following instruction. They are used to repeat string instructions, to provide section overrides, to
// perform bus lock operations, and to change operand and address sizes. Instruction prefixes are best written on the same line as the instruction
// they act upon



// Use this macro to perform an assembly instruction on 2 registers, when both the content of the registers will be used as a value
#define Instruction_ExtendedInlineAssembly_2arguments_Register_ImmediateValue1( InstructionName, SourceImmediateValue, DestinationRegister ) "\"" #InstructionName " " #DestinationRegister ", " "%[" #SourceImmediateValue "]\n\t" "\""


#define Instruction_ExtendedInlineAssembly_2arguments_Register_ImmediateValue( InstructionName, SourceImmediateValue, DestinationRegister ) Concatenate2piecesOfText( InstructionName, DestinationRegister )



    }  //  Namespace CentralProcessingUnit


}  //  Namespace Universe