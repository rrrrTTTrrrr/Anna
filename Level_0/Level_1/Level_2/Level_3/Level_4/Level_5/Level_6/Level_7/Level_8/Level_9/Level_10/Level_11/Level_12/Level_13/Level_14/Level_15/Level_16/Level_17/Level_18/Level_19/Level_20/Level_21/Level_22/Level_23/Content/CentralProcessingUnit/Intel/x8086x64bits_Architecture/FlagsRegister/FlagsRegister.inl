//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline FlagsRegister::FlagsRegister() :
	member_flagsRegister( 0UL )
{
    // The following is an extended inline assembly statement. It will be used to load the current RFLAGS register content so it can be examined. 
    // This is not possible using only C++
    __asm__ volatile ( "PUSHFQ\n\t"                             					/* Assembly code */
                       "POPQ RAX\n\t" 
                       "MOV QWORD PTR %[RFLAGS], RAX\n\t"
                       	
                       	: [RFLAGS] "=m" ( member_flagsRegister )      				/* Output arguments */
                       	:                                        					/* Input arguments */
                       	: "memory", "%rax" );                            			/* Clobbers and scratch registers */
}


inline FlagsRegister::FlagsRegister( const SelfType& other ) :
	member_flagsRegister( other.member_flagsRegister )
{}


inline Boolean FlagsRegister::IsEnabled_Carry() const
{
	// Return the if the carry bit is on in the flag ( bit 0 )
	return ( Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 0UL ).IsOn() );
}


inline Memory::Bit< UnsignedInteger64bits > FlagsRegister::Carry()
{
	// Return the carry bit in the flag ( bit 0 )
	return ( Memory::Bit< UnsignedInteger64bits >( &member_flagsRegister, 0UL ) );
}


inline Boolean FlagsRegister::IsEnabled_Parity() const
{
	// Return the if the parity bit is on in the flag ( bit 2 )
	return ( Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 2UL ).IsOn() );
}


inline Memory::Bit< UnsignedInteger64bits > FlagsRegister::Parity()
{
	// Return the parity bit in the flag ( bit 2 )
	return ( Memory::Bit< UnsignedInteger64bits >( &member_flagsRegister, 2UL ) );
}


inline Boolean FlagsRegister::IsEnabled_Auxiliary() const
{
	// Return the if the auxiliary bit is on in the flag ( bit 4 )
	return ( Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 4UL ).IsOn() );
}


inline Memory::Bit< UnsignedInteger64bits > FlagsRegister::Auxiliary()
{
	// Return the auxiliary bit in the flag ( bit 4 )
	return ( Memory::Bit< UnsignedInteger64bits >( &member_flagsRegister, 4UL ) );
}


inline Boolean FlagsRegister::IsEnabled_Zero() const
{
	// Return the if the zero bit is on in the flag ( bit 6 )
	return ( Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 6UL ).IsOn() );
}


inline Memory::Bit< UnsignedInteger64bits > FlagsRegister::Zero()
{
	// Return the zero bit in the flag ( bit 6 )
	return ( Memory::Bit< UnsignedInteger64bits >( &member_flagsRegister, 6UL ) );
}


inline Boolean FlagsRegister::IsEnabled_Sign() const
{
	// Return the if the sign bit is on in the flag ( bit 7 )
	return ( Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 7UL ).IsOn() );
}


inline Memory::Bit< UnsignedInteger64bits > FlagsRegister::Sign()
{
	// Return the sign bit in the flag ( bit 7 )
	return ( Memory::Bit< UnsignedInteger64bits >( &member_flagsRegister, 7UL ) );
}


inline Boolean FlagsRegister::IsEnabled_Overflow() const
{
	// Return the if the overflow bit is on in the flag ( bit 11 )
	return ( Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 11UL ).IsOn() );
}


inline Memory::Bit< UnsignedInteger64bits > FlagsRegister::Overflow()
{
	// Return the overflow bit in the flag ( bit 11 )
	return ( Memory::Bit< UnsignedInteger64bits >( &member_flagsRegister, 11UL ) );
}


inline void FlagsRegister::SetHardwareFlagsRegister() const
{
    // The following is an extended inline assembly statement. It will be used to set the RFLAGS register with the content of this instance. 
    // This is not possible using only C++
    __asm__ volatile ( "PUSH QWORD PTR %[RFLAGS]\n\t"					/* Assembly code */
    				   "POPFQ\n\t"                             		
                       
                       	:        										/* Output arguments */
                       	: [RFLAGS] "m" ( member_flagsRegister )        	/* Input arguments */
                       	: "cc" );                            			/* Clobbers and scratch registers */
}


inline Language::String FlagsRegister::ToString() const
{
	// Create the flags register state string format
	const AsciiCharacter* const formatPointer = "Flags register state:\n\n"
										  		"[bit:00 (CF)] Carry - {}\n"
										  		"[bit:01 (Reserved)] - {}\n"
										  		"[bit:02 (PF)] Parity - {}\n"
										  		"[bit:03 (Reserved)] - {}\n"
										  		"[bit:04 (AF)] Auxiliary - {}\n"
										  		"[bit:05 (Reserved)] - {}\n"
										  		"[bit:06 (ZF)] Zero - {}\n"
										  		"[bit:07 (SF)] Sign - {}\n"
										  		"[bit:08 (TF)] Trap - {}\n"
										  		"[bit:09 (IF)] Interrupt enable  - {}\n"
										  		"[bit:10 (DF)] Direction - {}\n"
										  		"[bit:11 (OF)] Overflow - {}\n"
										  		"[bit:12 (IOPL)] Input/Output priviliege level - {}\n"
										  		"[bit:13 (IOPL)] Input/Output priviliege level - {}\n"
										  		"[bit:14 (NT)] Nested task - {}\n"
										  		"[bit:15 (MD)] Mode - {}\n"
										  		"[bit:16 (RF)] Resume - {}\n"
										  		"[bit:17 (VM)] Virtual 8086 mode - {}\n"
										  		"[bit:18 (AC)] Alignment check  - {}\n"
										  		"[bit:19 (VIF)] Virtual interrupt - {}\n"
										  		"[bit:20 (VIP)] Virtual interrupt pending - {}\n"
										  		"[bit:21 (ID)] Able to use CPUID instruction - {}\n"
										  		"[bit:22 (Reserved)] - {}\n"
										  		"[bit:23 (Reserved)] - {}\n"
										  		"[bit:24 (Reserved)] - {}\n"
										  		"[bit:25 (Reserved)] - {}\n"
										  		"[bit:26 (Reserved)] - {}\n"
										  		"[bit:27 (Reserved)] - {}\n"
										  		"[bit:28 (Reserved)] - {}\n"
										  		"[bit:29 (Reserved)] - {}\n"
										  		"[bit:30] AES key schedule loaded - {}\n"
										  		"[bit:31 (AI)]  Alternate Instruction Set enabled - {}\n";

	// Initialize a string to contain the state of the flags register
	const Language::String flagsRegisterStateString( formatPointer, 
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 0UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 1UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 2UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 3UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 4UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 5UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 6UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 7UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 8UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 9UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 10UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 11UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 12UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 13UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 14UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 15UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 16UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 17UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 18UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 19UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 20UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 21UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 22UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 23UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 24UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 25UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 26UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 27UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 28UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 29UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 30UL ),
									 	   			 Memory::Bit< UnsignedInteger64bits >( const_cast< UnsignedInteger64bits* >( &member_flagsRegister ), 31UL ));

	// Return the string with the flags register state
	return ( flagsRegisterStateString );

}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



inline Boolean FlagsRegister::operator==( const SelfType& other ) const
{
	// Compare the content of the two instances and return the result
	return ( member_flagsRegister == other.member_flagsRegister );
}


inline Boolean FlagsRegister::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}



}  //  Namespace CentralProcessingUnit


}  //  Namespace Universe