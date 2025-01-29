//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



inline UnsignedInteger8bits RealTimeClock::SetRegistersByteFormat__Private()
{
	// Enable access to the required input and output ports for the real time clock device. As long as Linux kernel is the base this 
	// must be done
	Linux::SystemCalls::EnableAccessToInputAndOutputPorts( 0x70, 2UL );

	// This object will the real time clock hardware device registers byte format. This information is stored in the second and third less
	// significant bits of the status register B
	UnsignedInteger8bits statusRegisterB_content = 0;

    // The following is an extended inline assembly statement. It will be used to read the status register B content from the time
    // clock hardware device, to determine the registers byte format. This is not possible using only C++

    __asm__ volatile (  "XOR AL, AL;"												/* Set all the bits of the AL part of the RAX register off */
	                    "MOV AL, 0x8B;"												/* Set the value to disable non maskable interrupts and read the value of the seconds register in the real time clock */
	                    "OUT 0x70, AL;"												/* Write to the output port 0x70 of the real time clock the value in the AL part of the RAX register. This will disable the non maskable interrupts until the next time value is written to this port, and set that the required register is the seconds register */
	                    "IN AL, 0x71;" 												/* Read the current value for the seconds from the port 0x71 */
	                    "MOV %[statusRegisterB_content], AL;" 						/* Store the seconds value */

			        : [statusRegisterB_content] "=r" ( statusRegisterB_content )   	/* Output arguments */
			        : 																/* Input arguments */
			        : "memory", "%rax" );											/* Clobbers and scratch registers */

	// Return the state of the B status register
	return ( statusRegisterB_content );
}


inline void RealTimeClock::ConvertIfNeededToBinaryFormatAndTwentyFourHourFormat__Private( UnsignedInteger8bits& second, UnsignedInteger8bits& minute, UnsignedInteger8bits& hour )
{
	// Check if the real time clock hardware device format the bytes as binary coded decimal
	if ( ( member_statusRegisters_B & 0x04 ) == 0 )
	{
		// The real time clock hardware device format the bytes as binary coded decimal

		// Convert from binary coded decimal to binary format the second and minute
		second = ConvertBetweenNumericSystems::BinaryCodedDecimalToBinary< UnsignedInteger8bits >( second );
		minute = ConvertBetweenNumericSystems::BinaryCodedDecimalToBinary< UnsignedInteger8bits >( minute );

		// Convert from binary coded decimal to binary the hour. This case is different due to the fact that the most significant bit
		// of the byte represents if the hour is AM or PM. It will convert only the hour, and leave the most significant bit as it is
		hour = static_cast< UnsignedInteger8bits >( ( ( hour & 0x0F ) + ( ( ( hour & 0x70 ) >> 3 ) * 5 ) ) | ( hour & 0x80 ) );
	}

	// Check if the real time clock hardware device hour register is 12 hour format
	if ( ( ( member_statusRegisters_B & 0x02 ) == 0 ) && ( ( hour & 0x80 ) == 0x80 ) )
	{
		// The real time clock hardware device hour register is 12 hour format

		// Convert the hour to 24 hour format
		hour = ( hour & 0x7F ) + 12;
	}
}


void RealTimeClock::ConvertIfNeededToBinaryFormatAndSetAbsoluteYearSinceThenBirthOfJisus__Private( UnsignedInteger8bits& dayOfMonth, UnsignedInteger8bits& month, UnsignedInteger16bits& absoluteYearSinceTheBirthOfJisus, UnsignedInteger8bits& century )
{
	// Check if the real time clock hardware device format the bytes as binary coded decimal
	if ( ( member_statusRegisters_B & 0x04 ) == 0 )
	{
		// The real time clock hardware device format the bytes as binary coded decimal

		// Convert from binary coded decimal to binary format the second and minute
		dayOfMonth = ConvertBetweenNumericSystems::BinaryCodedDecimalToBinary< UnsignedInteger8bits >( dayOfMonth );
		month = ConvertBetweenNumericSystems::BinaryCodedDecimalToBinary< UnsignedInteger8bits >( month );
		absoluteYearSinceTheBirthOfJisus = ConvertBetweenNumericSystems::BinaryCodedDecimalToBinary< UnsignedInteger16bits >( absoluteYearSinceTheBirthOfJisus );
		century = ConvertBetweenNumericSystems::BinaryCodedDecimalToBinary< UnsignedInteger8bits >( century );
	}

	// Check if the real time clock hardware device contains a value for the century
	if ( century != 0 )
	{
		// The real time clock hardware device contains a value for the century

		// Use the century information to determine the absolute year, from the birth of Jisus
		absoluteYearSinceTheBirthOfJisus = static_cast< UnsignedInteger8bits >( ( century * 100 ) ) + absoluteYearSinceTheBirthOfJisus;
	}
	else
	{
		// The real time clock hardware device does not contain a value for the century

		// Use the fixed century information to determine the absolute year, from the birth of Jisus
		absoluteYearSinceTheBirthOfJisus = member_century + absoluteYearSinceTheBirthOfJisus;				
	}
}



}  //  Namespace HardwareDevices


}  //  Namespace Universe