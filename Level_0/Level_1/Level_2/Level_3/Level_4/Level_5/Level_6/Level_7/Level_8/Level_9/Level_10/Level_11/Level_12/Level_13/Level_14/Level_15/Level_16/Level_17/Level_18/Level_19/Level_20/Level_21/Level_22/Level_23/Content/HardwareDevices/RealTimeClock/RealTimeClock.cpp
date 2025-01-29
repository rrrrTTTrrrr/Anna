namespace Universe
{


namespace HardwareDevices
{



// Initialize the real time clock hardware device registers byte format
UnsignedInteger8bits RealTimeClock::member_statusRegisters_B = RealTimeClock::SetRegistersByteFormat__Private();

// Initialize the century
UnsignedInteger16bits RealTimeClock::member_century = 2000;



//  ********************************************************************   STATIC FUNCTIONS IMPLEMENTATION   ********************************************************************



void RealTimeClock::TimeStamp( UnsignedInteger8bits& second, UnsignedInteger8bits& minute, UnsignedInteger8bits& hour )
{
	time_t my_time;
	struct tm * timeinfo; 
	time (&my_time);
	timeinfo = localtime (&my_time);

	second = static_cast< UnsignedInteger8bits >( timeinfo->tm_sec );
	minute = static_cast< UnsignedInteger8bits >( timeinfo->tm_min );
	hour = static_cast< UnsignedInteger8bits >( timeinfo->tm_hour );


	// // The real time clock have a slow update process compared to the abilities of the central processing unit. Therefore, in order to ensure
	// // that all the data read from the registers is valid, each register is read twice. If the content of the registers is identical in both
	// // reads, the data is valid. Otherwise, another time needs to be made

	// // This object will store the result of reading the second register the second time
	// UnsignedInteger8bits second_secondRead = 0;

	// // This object will store the result of reading the minute register the second time
	// UnsignedInteger8bits minute_secondRead = 0;

	// // This object will store the result of reading the hour register the second time
	// UnsignedInteger8bits hour_secondRead = 0;

	// // This object will store if the real time clock hardware device update process is in progress. This information is stored in the 7 most
	// // high significant bit of the status register A
	// UnsignedInteger8bits isUpdateInProgress = 0;

	// // This object will store if the real time clock hardware device update process is in progress. This information is stored in the 7 most
	// // high significant bit of the status register A
	// UnsignedInteger8bits isUpdateInProgress_secondRead = 0;

	// // Loop until the values read from the real time clock are valid. The problem is the update of the real time clock, which is slow
	// do
	// {
	// 	// Reset the variable that stores if an update is in progress
	// 	isUpdateInProgress_secondRead = 0;

	// 	// Loop as long as the real time clock hardware device update time process is in progress
	// 	do
	// 	{
	// 		// Reset the variable that stores if an update is in progress
	// 		isUpdateInProgress = 0;

	//         // The following is an extended inline assembly statement. It will be used to read the status register A content from the time
	//         // clock hardware device, to check if the update process is in progress. This is not possible using only C++

	// 	    __asm__ volatile (  "XOR AL, AL;"										/* Set all the bits of the AL part of the RAX register off */
	// 		                    "MOV AL, 0x8A;"										/* Set the value to disable non maskable interrupts and read the value of the second register in the real time clock */
	// 		                    "OUT 0x70, AL;"										/* Write to the output port 0x70 of the real time clock the value in the AL part of the RAX register. This will disable the non maskable interrupts until the next time value is written to this port, and set that the required register is the second register */
	// 		                    "IN AL, 0x71;" 										/* Read the current value for the second from the port 0x71 */
	// 		                    "MOV %[isUpdateInProgress], AL;" 					/* Store the second value */

	// 				        : [isUpdateInProgress] "=r" ( isUpdateInProgress )   	/* Output arguments */
	// 				        : 														/* Input arguments */
	// 				        : "%rax" );												/* Clobbers and scratch registers */

 //            // Delay the central processing unit for a finite time. The method uses the 'PAUSE' instruction which provides a hint to the processor
 //            // that a thread is trying to lock using a loop. It will improve performance and power consumption
 //            CentralPrcessingUnit_Pause();

	// 	} while ( ( isUpdateInProgress & 0x40 ) == 0x40 );

 //        // The following is an extended inline assembly statement. It will be used to read the second, minute and hour registers of the real
 //        // time clock hardware device for the first time. This is not possible using only C++

	//     __asm__ volatile (  /* Read the registers the first time */

	//     					"XOR AL, AL;"				/* Set the bits of the RAX register off */
	// 	                    "MOV AL, 0x80;"				/* Set the address of the required real time clock register in the RAX register */
	// 	                    "OUT 0x70, AL;"				/* Send to the real time clock the address of the required register */
	// 	                    "IN AL, 0x71;"				/* Read the value of the required real time clock register  */
	// 	                    "MOV %[second], AL;"		/* Store the value into the required variable */

	// 	                    "XOR AL, AL;"
	// 	                    "MOV AL, 0x82;"
	// 	                    "OUT 0x70, AL;"
	// 	                    "IN AL, 0x71;"
	// 	                    "MOV %[minute], AL;"

	// 	                    "XOR AL, AL;"
	// 	                    "MOV AL, 0x84;"
	// 	                    "OUT 0x70, AL;"
	// 	                    "IN AL, 0x71;"
	// 	                    "MOV %[hour], AL;"

	// 	                    /* Check if an update is taken place */

	// 	                    "XOR AL, AL;"
	// 						"MOV AL, 0x8A;"
	// 						"OUT 0x70, AL;"
	// 						"IN AL, 0x71;"
	// 						"MOV %[isUpdateInProgress_secondRead], AL;"

	// 						/* Read the registers the second time */

	// 						"XOR AL, AL;"
	// 	                    "MOV AL, 0x80;"
	// 	                    "OUT 0x70, AL;"
	// 	                    "IN AL, 0x71;"
	// 	                    "MOV %[second_secondRead], AL;"

	// 	                    "XOR AL, AL;"
	// 	                    "MOV AL, 0x82;"
	// 	                    "OUT 0x70, AL;"
	// 	                    "IN AL, 0x71;"
	// 	                    "MOV %[minute_secondRead], AL;"

	// 	                    "XOR AL, AL;"
	// 	                    "MOV AL, 0x84;"
	// 	                    "OUT 0x70, AL;"
	// 	                    "IN AL, 0x71;"
	// 	                    "MOV %[hour_secondRead], AL;"

	// 				        : [second] "=rm" ( second ), 												/* Output arguments */
	// 				          [minute] "=rm" ( minute ),
	// 				          [hour] "=rm" ( hour ),
	// 				          [second_secondRead] "=rm" ( second_secondRead ),
	// 				          [minute_secondRead] "=rm" ( minute_secondRead ),
	// 				          [hour_secondRead] "=rm" ( hour_secondRead ),
	// 				          [isUpdateInProgress_secondRead] "=r" ( isUpdateInProgress_secondRead )
	// 				        : 																			/* Input arguments */
	// 				        : "memory", "%rax" );														/* Clobbers and scratch registers */

	// 	std::cout << "second - " << (int)second << std::endl;
	// 	std::cout << "minute - " << (int)minute << std::endl;
	// 	std::cout << "hour - " << (int)hour << std::endl;

	// 	std::cout << "2- second - " << (int)second_secondRead << std::endl;
	// 	std::cout << "2- minute - " << (int)minute_secondRead << std::endl;
	// 	std::cout << "2- hour - " << (int)hour_secondRead << std::endl;

 //        // Delay the central processing unit for a finite time. The method uses the 'PAUSE' instruction which provides a hint to the processor
 //        // that a thread is trying to lock using a loop. It will improve performance and power consumption
 //        CentralPrcessingUnit_Pause();

	// } while ( ( ( isUpdateInProgress_secondRead & 0x40 ) == 0x40 ) ||
	// 		  ( second != second_secondRead ) ||
	// 		  ( minute != minute_secondRead ) ||
	// 		  ( hour != hour_secondRead ) );

	// // Convert the second, minute and hour into the required format, which is binary and 24 hour format
	// ConvertIfNeededToBinaryFormatAndTwentyFourHourFormat__Private( second, minute, hour );
}


void RealTimeClock::DateStamp( UnsignedInteger8bits& dayOfMonth, UnsignedInteger8bits& month, UnsignedInteger16bits& absoluteYearSinceTheBirthOfJisus )
{
	time_t my_time;
	struct tm * timeinfo;
	time (&my_time);
	timeinfo = localtime (&my_time);
	
	dayOfMonth = static_cast< UnsignedInteger8bits >( timeinfo->tm_mday );
	month = static_cast< UnsignedInteger8bits >( timeinfo->tm_mon + 1 );
	absoluteYearSinceTheBirthOfJisus = static_cast< UnsignedInteger16bits >( timeinfo->tm_year + 1900 );


	// // The real time clock have a slow update process compared to the abilities of the central processing unit. Therefore, in order to ensure
	// // that all the data read from the registers is valid, each register is read twice. If the content of the registers is identical in both
	// // reads, the data is valid. Otherwise, another time needs to be made

	// // This object will store the result of reading the year register
	// UnsignedInteger8bits year = 0;

	// // This object will store the result of reading the century register
	// UnsignedInteger8bits century = 0;

	// // This object will store the result of reading the dayOfMonth register the second time
	// UnsignedInteger8bits dayOfMonth_secondRead = 0;

	// // This object will store the result of reading the month register the second time
	// UnsignedInteger8bits month_secondRead = 0;

	// // This object will store the result of reading the year register the second time
	// UnsignedInteger8bits year_secondRead = 0;

	// // This object will store the result of reading the century register the second time
	// UnsignedInteger8bits century_secondRead = 0;

	// // This object will store if the real time clock hardware device update process is in progress. This information is stored in the 7 most
	// // high significant bit of the status register A
	// UnsignedInteger8bits isUpdateInProgress = 0;

	// // This object will store if the real time clock hardware device update process is in progress. This information is stored in the 7 most
	// // high significant bit of the status register A
	// UnsignedInteger8bits isUpdateInProgress_secondRead = 0;

	// // Loop until the time read from the real time clock registers is valid
	// do
	// {
	// 	// Reset the variable that stores if an update is in progress
	// 	isUpdateInProgress_secondRead = 0;

	// 	// Loop as long as the real time clock hardware device update time process is in progress
	// 	do
	// 	{
	// 		// Reset the variable that stores if an update is in progress
	// 		isUpdateInProgress = 0;

	//         // The following is an extended inline assembly statement. It will be used to read the status register A content from the time
	//         // clock hardware device, to check if the update process is in progress. This is not possible using only C++

	// 	    __asm__ volatile (  "XOR AL, AL;"										/* Set all the bits of the AL part of the RAX register off */
	// 		                    "MOV AL, 0x8A;"										/* Set the value to disable non maskable interrupts and read the value of the second register in the real time clock */
	// 		                    "OUT 0x70, AL;"										/* Write to the output port 0x70 of the real time clock the value in the AL part of the RAX register. This will disable the non maskable interrupts until the next time value is written to this port, and set that the required register is the second register */
	// 		                    "IN AL, 0x71;" 										/* Read the current value for the second from the port 0x71 */
	// 		                    "MOV %[isUpdateInProgress], AL;" 					/* Store the second value */

	// 				        : [isUpdateInProgress] "=r" ( isUpdateInProgress )   	/* Output arguments */
	// 				        : 														/* Input arguments */
	// 				        : "%rax" );												/* Clobbers and scratch registers */

 //            // Delay the central processing unit for a finite time. The method uses the 'PAUSE' instruction which provides a hint to the processor
 //            // that a thread is trying to lock using a loop. It will improve performance and power consumption
 //            CentralPrcessingUnit_Pause();

	// 	} while ( ( isUpdateInProgress & 0x40 ) == 0x40 );

 //        // The following is an extended inline assembly statement. It will be used to read the dayOfMonth, month and hour registers of the real
 //        // time clock hardware device for the first time. This is not possible using only C++

	//     __asm__ volatile (  /* Read the registers the first time */

	//     					"XOR AL, AL;"					/* Set the bits of the RAX register off */
	// 	                    "MOV AL, 0x87;"					/* Set the address of the required real time clock register in the RAX register */
	// 	                    "OUT 0x70, AL;"					/* Send to the real time clock the address of the required register */
	// 	                    "IN AL, 0x71;"					/* Read the value of the required real time clock register  */
	// 	                    "MOV %[dayOfMonth], AL;"		/* Store the value into the required variable */

	// 	                    "XOR AL, AL;"
	// 	                    "MOV AL, 0x88;"
	// 	                    "OUT 0x70, AL;"
	// 	                    "IN AL, 0x71;"
	// 	                    "MOV %[month], AL;"

	// 	                    "XOR AL, AL;"
	// 	                    "MOV AL, 0x89;"
	// 	                    "OUT 0x70, AL;"
	// 	                    "IN AL, 0x71;"
	// 	                    "MOV %[year], AL;"

	// 				        "XOR AL, AL;"
	// 	                    "MOV AL, 0xB2;"
	// 	                    "OUT 0x70, AL;"
	// 	                    "IN AL, 0x71;"
	// 	                    "MOV %[century], AL;"

	// 	                    /* Check if an update is taken place */

	// 	                    "XOR AL, AL;"
	// 						"MOV AL, 0x8A;"
	// 						"OUT 0x70, AL;"
	// 						"IN AL, 0x71;"
	// 						"MOV %[isUpdateInProgress_secondRead], AL;"

	// 						/* Read the registers the second time */

	// 						"XOR AL, AL;"
	// 	                    "MOV AL, 0x87;"
	// 	                    "OUT 0x70, AL;"
	// 	                    "IN AL, 0x71;"
	// 	                    "MOV %[dayOfMonth_secondRead], AL;"

	// 	                    "XOR AL, AL;"
	// 	                    "MOV AL, 0x88;"
	// 	                    "OUT 0x70, AL;"
	// 	                    "IN AL, 0x71;"
	// 	                    "MOV %[month_secondRead], AL;"

	// 	                    "XOR AL, AL;"
	// 	                    "MOV AL, 0x89;"
	// 	                    "OUT 0x70, AL;"
	// 	                    "IN AL, 0x71;"
	// 	                    "MOV %[year_secondRead], AL;"

	// 	                    "XOR AL, AL;"
	// 	                    "MOV AL, 0xB2;"
	// 	                    "OUT 0x70, AL;"
	// 	                    "IN AL, 0x71;"
	// 	                    "MOV %[century_secondRead], AL;"

	// 				        : [dayOfMonth] "=rm" ( dayOfMonth ),											/* Output arguments */
	// 				          [month] "=rm" ( month ), 
	// 				          [year] "=rm" ( year ), 
	// 				          [century] "=rm" ( century ), 
	// 				          [dayOfMonth_secondRead] "=rm" ( dayOfMonth_secondRead ), 
	// 				          [month_secondRead] "=rm" ( month_secondRead ), 
	// 				          [year_secondRead] "=rm" ( year_secondRead ), 
	// 				          [century_secondRead] "=rm" ( century_secondRead ),
	// 				          [isUpdateInProgress_secondRead] "=r" ( isUpdateInProgress_secondRead )
	// 				        : 																			/* Input arguments */
	// 				        : "memory", "%rax" );														/* Clobbers and scratch registers */

 //        // Delay the central processing unit for a finite time. The method uses the 'PAUSE' instruction which provides a hint to the processor
 //        // that a thread is trying to lock using a loop. It will improve performance and power consumption
 //        CentralPrcessingUnit_Pause();

	// } while ( ( ( isUpdateInProgress_secondRead & 0x40 ) == 0x40 ) || 
	//         ( dayOfMonth != dayOfMonth_secondRead ) ||
	//         ( month != month_secondRead ) ||
	//         ( year != year_secondRead ) ||
	//         ( century != century_secondRead ) );

	// // This object will store the absolute year, from the birth of Jisus
	// absoluteYearSinceTheBirthOfJisus = year;

	// // Convert the dayOfMonth, month and year into the required format, which is binary and 24 hour format
	// ConvertIfNeededToBinaryFormatAndSetAbsoluteYearSinceThenBirthOfJisus__Private( dayOfMonth, month, absoluteYearSinceTheBirthOfJisus, century );
}


void RealTimeClock::DateAndTimeStamp( UnsignedInteger8bits& dayOfMonth, UnsignedInteger8bits& month, UnsignedInteger16bits& absoluteYearSinceTheBirthOfJisus, UnsignedInteger8bits& second, UnsignedInteger8bits& minute, UnsignedInteger8bits& hour )
{
	time_t my_time;
	struct tm * timeinfo; 
	time (&my_time);
	timeinfo = localtime (&my_time);

	dayOfMonth = static_cast< UnsignedInteger8bits >( timeinfo->tm_mday );
	month = static_cast< UnsignedInteger8bits >( timeinfo->tm_mon + 1 );
	absoluteYearSinceTheBirthOfJisus = static_cast< UnsignedInteger16bits >( timeinfo->tm_year + 1900 );

	second = static_cast< UnsignedInteger8bits >( timeinfo->tm_sec );
	minute = static_cast< UnsignedInteger8bits >( timeinfo->tm_min );
	hour = static_cast< UnsignedInteger8bits >( timeinfo->tm_hour );

	// // The real time clock have a slow update process compared to the abilities of the central processing unit. Therefore, in order to ensure
	// // that all the data read from the registers is valid, each register is read twice. If the content of the registers is identical in both
	// // reads, the data is valid. Otherwise, another time needs to be made

	// // This object will store the result of reading the year register
	// UnsignedInteger8bits year = 0;

	// // This object will store the result of reading the century register
	// UnsignedInteger8bits century = 0;

	// // This object will store the result of reading the dayOfMonth register the second time
	// UnsignedInteger8bits dayOfMonth_secondRead = 0;

	// // This object will store the result of reading the month register the second time
	// UnsignedInteger8bits month_secondRead = 0;

	// // This object will store the result of reading the year register the second time
	// UnsignedInteger8bits year_secondRead = 0;

	// // This object will store the result of reading the century register the second time
	// UnsignedInteger8bits century_secondRead = 0;

	// // This object will store the result of reading the second register the second time
	// UnsignedInteger8bits second_secondRead = 0;

	// // This object will store the result of reading the minute register the second time
	// UnsignedInteger8bits minute_secondRead = 0;

	// // This object will store the result of reading the hour register the second time
	// UnsignedInteger8bits hour_secondRead = 0;

	// // This object will store if the real time clock hardware device update process is in progress. This information is stored in the 7 most
	// // high significant bit of the status register A
	// UnsignedInteger8bits isUpdateInProgress = 0;

	// // This object will store if the real time clock hardware device update process is in progress. This information is stored in the 7 most
	// // high significant bit of the status register A
	// UnsignedInteger8bits isUpdateInProgress_secondRead = 0;

	// // Loop until the time read from the real time clock registers is valid
	// do
	// {
	// 	// Reset the variable that stores if an update is in progress
	// 	isUpdateInProgress_secondRead = 0;

	// 	// Loop as long as the real time clock hardware device update time process is in progress
	// 	do
	// 	{
	// 		// Reset the variable that stores if an update is in progress
	// 		isUpdateInProgress = 0;

	//         // The following is an extended inline assembly statement. It will be used to read the status register A content from the time
	//         // clock hardware device, to check if the update process is in progress. This is not possible using only C++

	// 	    __asm__ volatile (  "XOR AL, AL;"										/* Set all the bits of the AL part of the RAX register off */
	// 		                    "MOV AL, 0x8A;"										/* Set the value to disable non maskable interrupts and read the value of the second register in the real time clock */
	// 		                    "OUT 0x70, AL;"										/* Write to the output port 0x70 of the real time clock the value in the AL part of the RAX register. This will disable the non maskable interrupts until the next time value is written to this port, and set that the required register is the second register */
	// 		                    "IN AL, 0x71;" 										/* Read the current value for the second from the port 0x71 */
	// 		                    "MOV %[isUpdateInProgress], AL;" 					/* Store the second value */

	// 				        : [isUpdateInProgress] "=r" ( isUpdateInProgress )   	/* Output arguments */
	// 				        : 														/* Input arguments */
	// 				        : "%rax" );												/* Clobbers and scratch registers */

 //            // Delay the central processing unit for a finite time. The method uses the 'PAUSE' instruction which provides a hint to the processor
 //            // that a thread is trying to lock using a loop. It will improve performance and power consumption
 //            CentralPrcessingUnit_Pause();

	// 	} while ( ( isUpdateInProgress & 0x40 ) == 0x40 );

 //        // The following is an extended inline assembly statement. It will be used to read the dayOfMonth, month and hour registers of the real
 //        // time clock hardware device for the first time. This is not possible using only C++

	//     __asm__ volatile (  /* Read the registers the first time */

	//     					"XOR AL, AL;"					/* Set the bits of the RAX register off */
	// 	                    "MOV AL, 0x87;"					/* Set the address of the required real time clock register in the RAX register */
	// 	                    "OUT 0x70, AL;"					/* Send to the real time clock the address of the required register */
	// 	                    "IN AL, 0x71;"					/* Read the value of the required real time clock register */
	// 	                    "MOV %[dayOfMonth], AL;"		/* Store the value into the required variable */

	// 	                    "XOR AL, AL;"
	// 	                    "MOV AL, 0x88;"
	// 	                    "OUT 0x70, AL;"
	// 	                    "IN AL, 0x71;"
	// 	                    "MOV %[month], AL;"

	// 	                    "XOR AL, AL;"
	// 	                    "MOV AL, 0x89;"
	// 	                    "OUT 0x70, AL;"
	// 	                    "IN AL, 0x71;"
	// 	                    "MOV %[year], AL;"

	// 				        "XOR AL, AL;"
	// 	                    "MOV AL, 0xB2;"
	// 	                    "OUT 0x70, AL;"
	// 	                    "IN AL, 0x71;"
	// 	                    "MOV %[century], AL;"

	//     					"XOR AL, AL;"
	// 	                    "MOV AL, 0x80;"
	// 	                    "OUT 0x70, AL;"
	// 	                    "IN AL, 0x71;"
	// 	                    "MOV %[second], AL;"

	// 	                    "XOR AL, AL;"
	// 	                    "MOV AL, 0x82;"
	// 	                    "OUT 0x70, AL;"
	// 	                    "IN AL, 0x71;"
	// 	                    "MOV %[minute], AL;"

	// 	                    "XOR AL, AL;"
	// 	                    "MOV AL, 0x84;"
	// 	                    "OUT 0x70, AL;"
	// 	                    "IN AL, 0x71;"
	// 	                    "MOV %[hour], AL;"

	// 	                    /* Check again if an update is taken place */

	// 	                    "XOR AL, AL;"
	// 						"MOV AL, 0x8A;"
	// 						"OUT 0x70, AL;"
	// 						"IN AL, 0x71;"
	// 						"MOV %[isUpdateInProgress_secondRead], AL;"

	// 						/* Read the registers the second time */

	// 						"XOR AL, AL;"
	// 	                    "MOV AL, 0x87;"
	// 	                    "OUT 0x70, AL;"
	// 	                    "IN AL, 0x71;"
	// 	                    "MOV %[dayOfMonth_secondRead], AL;"

	// 	                    "XOR AL, AL;"
	// 	                    "MOV AL, 0x88;"
	// 	                    "OUT 0x70, AL;"
	// 	                    "IN AL, 0x71;"
	// 	                    "MOV %[month_secondRead], AL;"

	// 	                    "XOR AL, AL;"
	// 	                    "MOV AL, 0x89;"
	// 	                    "OUT 0x70, AL;"
	// 	                    "IN AL, 0x71;"
	// 	                    "MOV %[year_secondRead], AL;"

	// 	                    "XOR AL, AL;"
	// 	                    "MOV AL, 0xB2;"
	// 	                    "OUT 0x70, AL;"
	// 	                    "IN AL, 0x71;"
	// 	                    "MOV %[century_secondRead], AL;"

	// 						"XOR AL, AL;"
	// 	                    "MOV AL, 0x80;"
	// 	                    "OUT 0x70, AL;"
	// 	                    "IN AL, 0x71;"
	// 	                    "MOV %[second_secondRead], AL;"

	// 	                    "XOR AL, AL;"
	// 	                    "MOV AL, 0x82;"
	// 	                    "OUT 0x70, AL;"
	// 	                    "IN AL, 0x71;"
	// 	                    "MOV %[minute_secondRead], AL;"

	// 	                    "XOR AL, AL;"
	// 	                    "MOV AL, 0x84;"
	// 	                    "OUT 0x70, AL;"
	// 	                    "IN AL, 0x71;"
	// 	                    "MOV %[hour_secondRead], AL;"		

	// 				        : [dayOfMonth] "=rm" ( dayOfMonth ),											/* Output arguments */
	// 				          [month] "=rm" ( month ),
	// 				          [year] "=rm" ( year ),
	// 				          [century] "=rm" ( century ),
	// 				          [second] "=rm" ( second ),
	// 				          [minute] "=rm" ( minute ),
	// 				          [hour] "=rm" ( hour ),
	// 				          [dayOfMonth_secondRead] "=rm" ( dayOfMonth_secondRead ),
	// 				          [month_secondRead] "=rm" ( month_secondRead ),
	// 				          [year_secondRead] "=rm" ( year_secondRead ),
	// 				          [century_secondRead] "=rm" ( century_secondRead ),
	// 				          [second_secondRead] "=rm" ( second_secondRead ),
	// 				          [minute_secondRead] "=rm" ( minute_secondRead ),
	// 				          [hour_secondRead] "=rm" ( hour_secondRead ),
	// 				          [isUpdateInProgress_secondRead] "=r" ( isUpdateInProgress_secondRead )
	// 				        : 																			/* Input arguments */
	// 				        : "memory", "%rax" );														/* Clobbers and scratch registers */

 //        // Delay the central processing unit for a finite time. The method uses the 'PAUSE' instruction which provides a hint to the processor
 //        // that a thread is trying to lock using a loop. It will improve performance and power consumption
 //        CentralPrcessingUnit_Pause();

	// } while ( ( ( isUpdateInProgress_secondRead & 0x40 ) == 0x40 ) || 
	// 		  ( second != second_secondRead ) ||
	// 		  ( minute != minute_secondRead ) ||
	// 		  ( hour != hour_secondRead ) ||
	// 	      ( dayOfMonth != dayOfMonth_secondRead ) ||
	// 	      ( month != month_secondRead ) ||
	// 	      ( year != year_secondRead ) ||
	// 	      ( century != century_secondRead ) );

	// // This object will store the absolute year, from the birth of Jisus
	// absoluteYearSinceTheBirthOfJisus = year;

	// // Convert the dayOfMonth, month and year into the required format, which is binary and 24 hour format
	// ConvertIfNeededToBinaryFormatAndSetAbsoluteYearSinceThenBirthOfJisus__Private( dayOfMonth, month, absoluteYearSinceTheBirthOfJisus, century );

	// // Convert the second, minute and hour into the required format, which is binary and 24 hour format
	// ConvertIfNeededToBinaryFormatAndTwentyFourHourFormat__Private( second, minute, hour );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	void RealTimeClock::UnitTest()
	{}

)  //  End of debug tool



}  //  Namespace HardwareDevices


}  //  Namespace Universe