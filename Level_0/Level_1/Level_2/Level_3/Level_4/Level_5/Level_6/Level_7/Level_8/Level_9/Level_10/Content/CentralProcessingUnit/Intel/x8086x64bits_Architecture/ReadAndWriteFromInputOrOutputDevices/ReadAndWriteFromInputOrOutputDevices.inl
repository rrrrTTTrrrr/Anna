//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



inline UnsignedInteger8bits ReadAndWriteFromInputOrOutputDevices::ReadByteFromInputOrOutputPort( const UnsignedInteger16bits port )
{
    // This object will store the byte read from the input or output port
    UnsignedInteger8bits value = 0;

    // The following is an extended inline assembly statement. It will be used to do the read and write of the memory address with no interference. This is not 
    // possible only using C++
    __asm__ volatile ( "MOV DX, %[port];"					/* Set the DX register with the port number */
    				   "IN AL, DX;"						    /* Read from the required input or output port, stored in the DX register, into the AL register */
    				   "MOV %[value], AL;"					/* Move the result from the AL register to the value variable */

                        : [value] "=m" ( value )            /* Output arguments */
                        : [port] "r" ( port )       		/* Input arguments */
                        : "memory", "%rax", "%rdx" );       /* Clobbers and scratch registers */

    // Return the value read from the memory address before the given value was added to it
    return ( value );
}


inline UnsignedInteger16bits ReadAndWriteFromInputOrOutputDevices::ReadTwoBytesFromInputOrOutputPort( const UnsignedInteger16bits port )
{
    // This object will store the byte read from the input or output port
    UnsignedInteger16bits value = 0;

    // The following is an extended inline assembly statement. It will be used to do the read and write of the memory address with no interference. This is not 
    // possible only using C++
    __asm__ volatile ( "MOV DX, %[port];"					/* Set the DX register with the port number */
    				   "IN AX, DX;"						    /* Read from the required input or output port, stored in the DX register, into the AX register */
    				   "MOV %[value], AX;"					/* Move the result from the AX register to the value variable */

                        : [value] "=m" ( value )            /* Output arguments */
                        : [port] "r" ( port )       		/* Input arguments */
                        : "memory", "%rax", "%rdx" );       /* Clobbers and scratch registers */

    // Return the value read from the memory address before the given value was added to it
    return ( value );
}


inline UnsignedInteger32bits ReadAndWriteFromInputOrOutputDevices::ReadFourBytesFromInputOrOutputPort( const UnsignedInteger16bits port )
{
    // This object will store the byte read from the input or output port
    UnsignedInteger32bits value = 0;

    // The following is an extended inline assembly statement. It will be used to do the read and write of the memory address with no interference. This is not 
    // possible only using C++
    __asm__ volatile ( "MOV DX, %[port];"					/* Set the DX register with the port number */
    				   "IN EAX, DX;"						/* Read from the required input or output port, stored in the DX register, into the EAX register */
    				   "MOV %[value], EAX;"				    /* Move the result from the EAX register to the value variable */

                        : [value] "=m" ( value )            /* Output arguments */
                        : [port] "r" ( port )       		/* Input arguments */
                        : "memory", "%rax", "%rdx" );       /* Clobbers and scratch registers */

    // Return the value read from the memory address before the given value was added to it
    return ( value );
}


inline void ReadAndWriteFromInputOrOutputDevices::WriteByteToInputOrOutputPort( const UnsignedInteger16bits port, const UnsignedInteger8bits value )
{
    // The following is an extended inline assembly statement. It will be used to do the read and write of the memory address with no interference. This is not 
    // possible only using C++
    __asm__ volatile ( "MOV DX, %[port];"								/* Set the DX register with the port number */
                       "MOV AL, %[value];"                              /* Store the value inside the AL register */
    				   "OUT DX, AL"								        /* Write to the required input or output port, stored in the DX register, the content of the register AL */

                        :             									/* Output arguments */
                        : [port] "r" ( port ), [value] "r" ( value )    /* Input arguments */
                        : "memory", "%rax", "%rdx" );       		    /* Clobbers and scratch registers */
}


inline void ReadAndWriteFromInputOrOutputDevices::WriteTwoBytesToInputOrOutputPort( const UnsignedInteger16bits port, const UnsignedInteger16bits value )
{
    // The following is an extended inline assembly statement. It will be used to do the read and write of the memory address with no interference. This is not 
    // possible only using C++
    __asm__ volatile ( "MOV DX, %[port];"								/* Set the DX register with the port number */
                       "MOV AX, %[value];"                              /* Store the value inside the AX register */
    				   "OUT DX, AX;"								    /* Write to the required input or output port, stored in the DX register, the content of the register AX */

                        :             									/* Output arguments */
                        : [port] "r" ( port ), [value] "r" ( value )    /* Input arguments */
                        : "memory", "%rax", "%rdx" );       		    /* Clobbers and scratch registers */
}


inline void ReadAndWriteFromInputOrOutputDevices::WriteFourBytesToInputOrOutputPort( const UnsignedInteger16bits port, const UnsignedInteger32bits value )
{
    // The following is an extended inline assembly statement. It will be used to do the read and write of the memory address with no interference. This is not 
    // possible only using C++
    __asm__ volatile ( "MOV DX, %[port];"								/* Set the DX register with the port number */
                       "MOV EAX, %[value];"                             /* Store the value inside the EAX register */
    				   "OUT DX, EAX;"								    /* Write to the required input or output port, stored in the DX register, the content of the register EAX */
    
                        :             									/* Output arguments */
                        : [port] "r" ( port ), [value] "r" ( value )    /* Input arguments */
                        : "memory", "%rax", "%rdx" );       		    /* Clobbers and scratch registers */
}



}  //  Namespace CentralProcessingUnit


}  //  Namespace Universe