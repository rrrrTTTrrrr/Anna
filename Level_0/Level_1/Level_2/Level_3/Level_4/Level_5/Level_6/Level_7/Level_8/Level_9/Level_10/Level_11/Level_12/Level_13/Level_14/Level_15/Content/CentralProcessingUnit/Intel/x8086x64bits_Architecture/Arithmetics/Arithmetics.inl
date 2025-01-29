//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



inline DivisonResultSignedInteger8bits Arithmetics::Divison( const SignedInteger8bits dividend, const SignedInteger8bits divisor )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsNotZero( divisor );

	// This object will store the quotient
	SignedInteger8bits quotient = 0;

	// This object will store the remainder
	SignedInteger8bits remainder = 0;

    // The following is an extended inline assembly statement. It will be used to perform a divison and return the quotient and remainder. 
    // This is not possible only using C++
    __asm__ volatile ( "MOVB AL, %[dividend];"                       						/* Move the content of the dividend to the AX register */
					   "IDIV %[divisor];"													/* Divide the value stored in the AX register by the divisor stored in the DL register */
					   "MOVB %[quotient], AL;"												/* The IDIV assembly instruction for byte stores the quotient in AL register, store the value into the quotient varaible */
					   "MOVB %[remainder], AH;"												/* The IDIV assembly instruction for byte stores the remainder in AH register, store the value into the remainder varaible */

                        : [quotient] "=r" ( quotient ), [remainder] "=r" ( remainder )      /* Output arguments */
                        : [dividend] "r" ( dividend ), [divisor] "r" ( divisor )       		/* Input arguments */
                        : "cc", "rax", "rdx" );                                   			/* Clobbers and scratch registers */

	// Store the quotient and remainder in a tuple and return the result to the user
	return ( DivisonResultSignedInteger8bits( quotient, remainder ) );
}


inline DivisonResultSignedInteger16bits Arithmetics::Divison( const SignedInteger16bits dividend, const SignedInteger16bits divisor )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsNotZero( divisor );

	// This object will store the quotient
	SignedInteger16bits quotient = 0;

	// This object will store the remainder
	SignedInteger16bits remainder = 0;

    // The following is an extended inline assembly statement. It will be used to perform a divison and return the quotient and remainder. 
    // This is not possible only using C++
    __asm__ volatile ( "MOV AX, %[dividend];"                       						/* Move the content of the dividend to the AX register, for the quotient result */
    				   "CWD;"																/* Sign extend of the register AX into the register DX, this takes the sign bit from AX and set the state of it into all the bits of the DX register */
					   "IDIV %[divisor];"													/* Divide the value stored in the AX register by the divisor stored on a register */
					   "MOV %[quotient], AX;"												/* The IDIV assembly instruction for word stores the quotient in AX register, store the value into the quotient varaible */
					   "MOV %[remainder], DX;"												/* The IDIV assembly instruction for word stores the remainder in DX register, store the value into the remainder varaible */

                        : [quotient] "=r" ( quotient ), [remainder] "=r" ( remainder )      /* Output arguments */
                        : [dividend] "r" ( dividend ), [divisor] "r" ( divisor )       		/* Input arguments */
                        : "cc", "rax", "rdx" );                                   			/* Clobbers and scratch registers */

	// Store the quotient and remainder in a tuple and return the result to the user
	return ( DivisonResultSignedInteger16bits( quotient, remainder ) );
}


inline DivisonResultSignedInteger32bits Arithmetics::Divison( const SignedInteger32bits dividend, const SignedInteger32bits divisor )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsNotZero( divisor );

	// This object will store the quotient
	SignedInteger32bits quotient = 0;

	// This object will store the remainder
	SignedInteger32bits remainder = 0;

    // The following is an extended inline assembly statement. It will be used to perform a divison and return the quotient and remainder. 
    // This is not possible only using C++
    __asm__ volatile ( "MOV EAX, %[dividend];"                       						/* Move the content of the dividend to the EAX register, for the quotient result */
    				   "CDQ;"																/* Sign extend of the register EAX into the register EDX, this takes the sign bit from EAX and set the state of it into all the bits of the EDX register */
					   "IDIV %[divisor];"													/* Divide the value stored in the EAX register by the divisor stored on a register */
					   "MOV %[quotient], EAX;"												/* The IDIV assembly instruction for double word stores the quotient in EAX register, store the value into the quotient varaible */
					   "MOV %[remainder], EDX;"												/* The IDIV assembly instruction for double word stores the remainder in EDX register, store the value into the remainder varaible */

                        : [quotient] "=r" ( quotient ), [remainder] "=r" ( remainder )      /* Output arguments */
                        : [dividend] "r" ( dividend ), [divisor] "r" ( divisor )       		/* Input arguments */
                        : "cc", "rax", "rdx" );                            					/* Clobbers and scratch registers */

	// Store the quotient and remainder in a tuple and return the result to the user
	return ( DivisonResultSignedInteger32bits( quotient, remainder ) );
}


inline DivisonResultSignedInteger64bits Arithmetics::Divison( const SignedInteger64bits dividend, const SignedInteger64bits divisor )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsNotZero( divisor );

	// This object will store the quotient
	SignedInteger64bits quotient = 0;

	// This object will store the remainder
	SignedInteger64bits remainder = 0;

    // The following is an extended inline assembly statement. It will be used to perform a divison and return the quotient and remainder. 
    // This is not possible only using C++
    __asm__ volatile ( "MOVQ RAX, %[dividend];"                       						/* Move the content of the dividend to the RAX register, for the quotient result */
    				   "CQO;"																/* Sign extend of the register RAX into the register RDX, this takes the sign bit from RAX and set the state of it into all the bits of the RDX register */
					   "IDIV %[divisor];"													/* Divide the value stored in the RAX register by the divisor stored on a register */
					   "MOVQ %[quotient], RAX;"												/* The IDIV assembly instruction for quad word stores the quotient in RAX register, store the value into the quotient varaible */
					   "MOVQ %[remainder], RDX;"											/* The IDIV assembly instruction for quad word stores the remainder in RDX register, store the value into the remainder varaible */

                        : [quotient] "=r" ( quotient ), [remainder] "=r" ( remainder )      /* Output arguments */
                        : [dividend] "r" ( dividend ), [divisor] "r" ( divisor )       		/* Input arguments */
                        : "cc", "rax", "rdx" );                                   			/* Clobbers and scratch registers */

	// Store the quotient and remainder in a tuple and return the result to the user
	return ( DivisonResultSignedInteger64bits( quotient, remainder ) );
}


inline DivisonResultUnsignedInteger8bits Arithmetics::Divison( const UnsignedInteger8bits dividend, const UnsignedInteger8bits divisor )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsNotZero( divisor );

	// This object will store the quotient
	UnsignedInteger8bits quotient = 0;

	// This object will store the remainder
	UnsignedInteger8bits remainder = 0;

    // The following is an extended inline assembly statement. It will be used to perform a divison and return the quotient and remainder. 
    // This is not possible only using C++
    __asm__ volatile ( "MOVB AL, %[dividend];"                       						/* Move the content of the dividend to the AX register */
					   "DIV %[divisor];"													/* Divide the value stored in the AX register by the divisor stored in the DL register */
					   "MOVB %[quotient], AL;"												/* The DIV assembly instruction for byte stores the quotient in AL register, store the value into the quotient varaible */
					   "MOVB %[remainder], AH;"												/* The DIV assembly instruction for byte stores the remainder in AH register, store the value into the remainder varaible */

                        : [quotient] "=r" ( quotient ), [remainder] "=r" ( remainder )      /* Output arguments */
                        : [dividend] "r" ( dividend ), [divisor] "r" ( divisor )       		/* Input arguments */
                        : "cc", "rax", "rdx" );                                   			/* Clobbers and scratch registers */

	// Store the quotient and remainder in a tuple and return the result to the user
	return ( DivisonResultUnsignedInteger8bits( quotient, remainder ) );
}


inline DivisonResultUnsignedInteger16bits Arithmetics::Divison( const UnsignedInteger16bits dividend, const UnsignedInteger16bits divisor )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsNotZero( divisor );

	// This object will store the quotient
	UnsignedInteger16bits quotient = 0;

	// This object will store the remainder
	UnsignedInteger16bits remainder = 0;

    // The following is an extended inline assembly statement. It will be used to perform a divison and return the quotient and remainder. 
    // This is not possible only using C++
    __asm__ volatile ( "MOV AX, %[dividend];"                       						/* Move the content of the dividend to the AX register, for the quotient result */
    				   "XOR DX, DX;"														/* Set all the bits of the DX register off */
					   "DIV %[divisor];"													/* Divide the value stored in the AX register by the divisor stored on a register */
					   "MOV %[quotient], AX;"												/* The DIV assembly instruction for word stores the quotient in AX register, store the value into the quotient varaible */
					   "MOV %[remainder], DX;"												/* The DIV assembly instruction for word stores the remainder in DX register, store the value into the remainder varaible */

                        : [quotient] "=r" ( quotient ), [remainder] "=r" ( remainder )      /* Output arguments */
                        : [dividend] "r" ( dividend ), [divisor] "r" ( divisor )       		/* Input arguments */
                        : "cc", "rax", "rdx" );                                   			/* Clobbers and scratch registers */

	// Store the quotient and remainder in a tuple and return the result to the user
	return ( DivisonResultUnsignedInteger16bits( quotient, remainder ) );
}


inline DivisonResultUnsignedInteger32bits Arithmetics::Divison( const UnsignedInteger32bits dividend, const UnsignedInteger32bits divisor )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsNotZero( divisor );

	// This object will store the quotient
	UnsignedInteger32bits quotient = 0;

	// This object will store the remainder
	UnsignedInteger32bits remainder = 0;

    // The following is an extended inline assembly statement. It will be used to perform a divison and return the quotient and remainder. 
    // This is not possible only using C++
    __asm__ volatile ( "MOV EAX, %[dividend];"                       						/* Move the content of the dividend to the EAX register, for the quotient result */
    				   "XOR EDX, EDX;"														/* Set all the bits of the EDX register off */
					   "DIV %[divisor];"													/* Divide the value stored in the EAX register by the divisor stored on a register */
					   "MOV %[quotient], EAX;"												/* The DIV assembly instruction for double word stores the quotient in EAX register, store the value into the quotient varaible */
					   "MOV %[remainder], EDX;"												/* The DIV assembly instruction for double word stores the remainder in EDX register, store the value into the remainder varaible */

                        : [quotient] "=r" ( quotient ), [remainder] "=r" ( remainder )      /* Output arguments */
                        : [dividend] "r" ( dividend ), [divisor] "r" ( divisor )       		/* Input arguments */
                        : "cc", "rax", "rdx" );                            					/* Clobbers and scratch registers */

	// Store the quotient and remainder in a tuple and return the result to the user
	return ( DivisonResultUnsignedInteger32bits( quotient, remainder ) );
}


inline DivisonResultUnsignedInteger64bits Arithmetics::Divison( const UnsignedInteger64bits dividend, const UnsignedInteger64bits divisor )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsNotZero( divisor );

	// This object will store the quotient
	UnsignedInteger64bits quotient = 0;

	// This object will store the remainder
	UnsignedInteger64bits remainder = 0;

    // The following is an extended inline assembly statement. It will be used to perform a divison and return the quotient and remainder. 
    // This is not possible only using C++
    __asm__ volatile ( "MOVQ RAX, %[dividend];"                       						/* Move the content of the dividend to the RAX register, for the quotient result */
    				   "XOR RDX, RDX;"														/* Set all the bits of the RDX register off */
					   "DIV %[divisor];"													/* Divide the value stored in the RAX register by the divisor stored on a register */
					   "MOVQ %[quotient], RAX;"												/* The DIV assembly instruction for quad word stores the quotient in RAX register, store the value into the quotient varaible */
					   "MOVQ %[remainder], RDX;"											/* The DIV assembly instruction for quad word stores the remainder in RDX register, store the value into the remainder varaible */

                        : [quotient] "=r" ( quotient ), [remainder] "=r" ( remainder )      /* Output arguments */
                        : [dividend] "r" ( dividend ), [divisor] "r" ( divisor )       		/* Input arguments */
                        : "cc", "rax", "rdx" );                                   			/* Clobbers and scratch registers */

	// Store the quotient and remainder in a tuple and return the result to the user
	return ( DivisonResultUnsignedInteger64bits( quotient, remainder ) );
}



}  //  Namespace CentralProcessingUnit


}  //  Namespace Universe