//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



inline UnsignedInteger64bits ModelSpecificRegisters::Read( const UnsignedInteger32bits modelSpecificRegisterIndex )
{
	// This object will store the content of the model specific register
	UnsignedInteger64bits modelSpecificRegisterContent = 0UL;

	// This object will store the 32 high order bits of the model specific register returned in the EDX part of thje RDX register
	UnsignedInteger32bits modelSpecificRegister32highOrderBits = 0UL;

	// This object will store the 32 low order bits of the model specific register returned in the EAX part of thje RAX register
	UnsignedInteger32bits modelSpecificRegister32lowOrderBits = 0UL;

    // The following is an extended inline assembly statement. It will be used to read the content of the model specific register. This is not 
    // possible only using C++
    __asm__ volatile ( "MOVD ECX, %[modelSpecificRegisterIndex];"                                       																									/* Assembly code */
    				   "RDMSR;"
    				   "MOVD %[modelSpecificRegister32highOrderBits], EDX;"
    				   "MOVD %[modelSpecificRegister32lowOrderBits], EAX;"
                        : [modelSpecificRegister32highOrderBits] "=m" ( modelSpecificRegister32highOrderBits ), [modelSpecificRegister32lowOrderBits] "=m" ( modelSpecificRegister32lowOrderBits )          /* Output arguments */
                        : [modelSpecificRegisterIndex] "r" ( modelSpecificRegisterIndex )       																											/* Input arguments */
                        : "memory", "%rax", "%rcx", "rdx" );                                                                 																				/* Clobbers and scratch registers */

    // Set the 32 high order bits of the model specific register into the 32 low order bits of the 64 bits object that will store the all content
	modelSpecificRegisterContent = modelSpecificRegister32highOrderBits;

	// Left shift the bits 32 times, to move the bits to the high order bits
	modelSpecificRegisterContent <<= 32;

    // Set the 32 low order bits of the model specific register into the 32 low order bits of the 64 bits object that will store the all content
	modelSpecificRegisterContent |= modelSpecificRegister32lowOrderBits;

	// Return the content of the model specific register
	return ( modelSpecificRegisterContent );
}


inline void ModelSpecificRegisters::Write( const UnsignedInteger32bits modelSpecificRegisterIndex, const UnsignedInteger64bits contentToWrite )
{
	// This object will store the 32 high order bits of the value to store in the model specific register
	const UnsignedInteger32bits contentToWrite_32highOrderBits = *( reinterpret_cast< const UnsignedInteger32bits* >( &contentToWrite ) + 1UL );

	// This object will store the 32 low order bits of the value to store in the model specific register
	const UnsignedInteger32bits contentToWrite_32lowOrderBits = *reinterpret_cast< const UnsignedInteger32bits* >( &contentToWrite );

    // The following is an extended inline assembly statement. It will be used to read the content of the model specific register. This is not
    // possible only using C++
    __asm__ volatile ( "MOVD ECX, %[modelSpecificRegisterIndex];"                                       																																		/* Assembly code */
    				   "MOVD EDX, %[contentToWrite_32highOrderBits];"
    				   "MOVD EAX, %[contentToWrite_32lowOrderBits];"
       				   "WRMSR;"
                        : 																																																						/* Output arguments */
                        : [modelSpecificRegisterIndex] "r" ( modelSpecificRegisterIndex ), [contentToWrite_32highOrderBits] "r" ( contentToWrite_32highOrderBits ), [contentToWrite_32lowOrderBits] "r" ( contentToWrite_32lowOrderBits )       	/* Input arguments */
                        : "memory", "%rax", "%rcx", "rdx" );                                                                 																													/* Clobbers and scratch registers */
}



    }  //  Namespace CentralProcessingUnit

}  //  Namespace Universe