//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



// The following methods will provide the arithmetic operations addition and subtraction. The instructions are ADD, ADC, XADD, SUB, SBB, INC and DEC :


template< Concepts::Integer IntegerType >
inline IntegerType CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::Read_Add_Write_ReturnOldValue( volatile IntegerType* const integerPointer, const IntegerType valueToAdd )
{
    // This will be added only in test mode, to ensure that the given data to the method is valid   
    AssertPointerIsNotNull( integerPointer );

    // This object will store the current value in the memory address, which is the required return value, 
    IntegerType oldValue = 0;

    // The following is an extended inline assembly statement. It will be used to do the read and write of the memory address with no interference. This is not 
    // possible only using C++
    __asm__ volatile ( "LOCK XADD %[memoryAddress], %[valueToAdd];"                                         /* Assembly code */

                        : "=r" ( oldValue ), "+m" ( *integerPointer )                 						/* Output arguments */
                        : [valueToAdd] "r0" ( valueToAdd ), [memoryAddress] "m" ( *integerPointer )       	/* Input arguments */
                        : "memory", "cc" );                                                                 /* Clobbers and scratch registers */

    // Return the value read from the memory address before the given value was added to it
    return ( oldValue );
}


template< Concepts::Integer IntegerType >
inline void CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::Read_Add_Write( volatile IntegerType* const integerPointer, const IntegerType valueToAdd )
{
    // This will be added only in test mode, to ensure that the given data to the method is valid   
    AssertPointerIsNotNull( integerPointer );

    // The following is an extended inline assembly statement. It will be used to do the read and write of the memory address with no interference. This is not 
    // possible only using C++
    __asm__ volatile ( "LOCK ADD %[memoryAddress], %[valueToAdd];"                                          /* Assembly code */

                        : "+m" ( *integerPointer )                                                        	/* Output arguments */
                        : [valueToAdd] "r" ( valueToAdd ), [memoryAddress] "m" ( *integerPointer )       	/* Input arguments */
                        : "memory", "cc" );                                                                 /* Clobbers and scratch registers */
}


template< Concepts::Integer IntegerType >
inline void CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::Read_Add_AddCarryFlag_Write( volatile IntegerType* const integerPointer, const IntegerType valueToAdd )
{
    // This will be added only in test mode, to ensure that the given data to the method is valid   
    AssertPointerIsNotNull( integerPointer );

    // The following is an extended inline assembly statement. It will be used to do the read and write of the memory address with no interference. This is not 
    // possible only using C++
    __asm__ volatile ( "LOCK ADC %[memoryAddress], %[valueToAdd];"                                          /* Assembly code */

                        : "+m" ( *integerPointer )                                                        	/* Output arguments */
                        : [valueToAdd] "r" ( valueToAdd ), [memoryAddress] "m" ( *integerPointer )       	/* Input arguments */
                        : "memory", "cc" );                                                                 /* Clobbers and scratch registers */
}


template< Concepts::Integer IntegerType >
inline void CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::Read_Subtract_Write( volatile IntegerType* const integerPointer, const IntegerType valueToSubtract )
{
    // This will be added only in test mode, to ensure that the given data to the method is valid   
    AssertPointerIsNotNull( integerPointer );

    // The following is an extended inline assembly statement. It will be used to do the read and write of the memory address with no interference. This is not 
    // possible only using C++
    __asm__ volatile ( "LOCK SUB %[memoryAddress], %[valueToSubtract];"                                             /* Assembly code */

                        : "+m" ( *integerPointer )                                                                	/* Output arguments */
                        : [valueToSubtract] "r" ( valueToSubtract ), [memoryAddress] "m" ( *integerPointer )     	/* Input arguments */
                        : "memory", "cc" );                                                                         /* Clobbers and scratch registers */
}


template< Concepts::Integer IntegerType >
inline void CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::Read_Subtract_SubtractOneMoreIfCarryFlagIsON_Write( volatile IntegerType* const integerPointer, const IntegerType valueToSubtract )
{
    // This will be added only in test mode, to ensure that the given data to the method is valid   
    AssertPointerIsNotNull( integerPointer );

    // The following is an extended inline assembly statement. It will be used to do the read and write of the memory address with no interference. This is not 
    // possible only using C++
    __asm__ volatile ( "LOCK SBB %[memoryAddress], %[valueToSubtract];"                                             /* Assembly code */

                        : "+m" ( *integerPointer )                                                                	/* Output arguments */
                        : [valueToSubtract] "r" ( valueToSubtract ), [memoryAddress] "m" ( *integerPointer )     	/* Input arguments */
                        : "memory", "cc" );                                                                         /* Clobbers and scratch registers */
}


template< Concepts::Integer IntegerType >
inline void CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::Read_AddOne_Write( volatile IntegerType* const integerPointer )
{
    // This will be added only in test mode, to ensure that the given data to the method is valid   
    AssertPointerIsNotNull( integerPointer );

    // The following is an extended inline assembly statement. It will be used to do the read and write of the memory address with no interference. This is not 
    // possible only using C++
    __asm__ volatile ( "LOCK INC %[memoryAddress];"                     /* Assembly code */

                        : "+m" ( *integerPointer )                    	/* Output arguments */
                        : [memoryAddress] "m" ( *integerPointer )     	/* Input arguments */
                        : "memory", "cc" );                             /* Clobbers and scratch registers */
}


template< Concepts::Integer IntegerType >
inline void CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::Read_SubtractOne_Write( volatile IntegerType* const integerPointer )
{
    // This will be added only in test mode, to ensure that the given data to the method is valid   
    AssertPointerIsNotNull( integerPointer );

    // The following is an extended inline assembly statement. It will be used to do the read and write of the memory address with no interference. This is not 
    // possible only using C++
    __asm__ volatile ( "LOCK DEC %[memoryAddress];"                     /* Assembly code */

                        : "+m" ( *integerPointer )                    	/* Output arguments */
                        : [memoryAddress] "m" ( *integerPointer )     	/* Input arguments */
                        : "memory", "cc" );                             /* Clobbers and scratch registers */
}



// The following methods will provide the exchange and compare and exchange functionality. The instructions are XCHG, CMPXCHG, CMPXCHG8B AND CMPXCHG16B :



template< Concepts::Integer IntegerType >
inline IntegerType CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::Read_WriteOtherValue_ReturnOldValue( volatile IntegerType* const integerPointer, const IntegerType valueToSet )
{
    // This will be added only in test mode, to ensure that the given data to the method is valid   
    AssertPointerIsNotNull( integerPointer );

    // This object will store the current value in the memory address, which is the required return value, 
    IntegerType oldValue = 0;

    // The following is an extended inline assembly statement. It will be used to do the read and write of the memory address with no interference. This is not 
    // possible only using C++
    __asm__ volatile ( "LOCK XCHG %[memoryAddress], %[valueToSet];"                                         /* Assembly code */

                        : "+m" ( *integerPointer ), "=r" ( oldValue )                 						/* Output arguments */
                        : [valueToSet] "r" ( valueToSet ), [memoryAddress] "m" ( *integerPointer )       	/* Input arguments */
                        : "memory" );                                                                       /* Clobbers and scratch registers */

    // Return the value read from the memory address before the given value was set
    return ( oldValue );
}       


template< Concepts::Integer IntegerType > requires ( sizeof( IntegerType ) == 1 )
inline Boolean CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::Read_Compare_IfTrueStoreTheDesiredValueInstead( volatile IntegerType* const integerPointer, IntegerType& expectedValue, const IntegerType desiredValue )
{
    // This will be added only in test mode, to ensure that the given data to the method is valid   
    AssertPointerIsNotNull( integerPointer );

    // This object will store the current value in the memory address, which is the required return value, in case the 2 arguments match
    IntegerType actualValue = 0;

    // This boolean will store if the arguments of the comparison are equal ( true ) or not ( false )
    Boolean doActualAndExpectedValuesMatch = true;

    // The following is an extended inline assembly statement. It will be used to do the read and write of the memory address with no interference. This is not 
    // possible only using C++
    __asm__ volatile ( "MOV AL, %[expectedValue];"
    				   "LOCK CMPXCHG %[memoryAddress], %[desiredValue];"                                                               						/* Assembly code */
                       "JE EQUAL%=;"
                       "MOV %[actualValue], AL;"
                       "MOV %[doActualAndExpectedValuesMatch], 0;"
                       "EQUAL%=:;"

                        : [actualValue] "=m" ( actualValue ), [memoryAddress] "+m" ( *integerPointer ), [doActualAndExpectedValuesMatch] "=m" ( doActualAndExpectedValuesMatch )    											/* Output arguments */
                        : [expectedValue] "r" ( expectedValue ), [desiredValue] "r" ( desiredValue ), "m" ( *integerPointer )		/* Input arguments */
                        : "memory", "cc", "%rax" );                                                                                                                 			/* Clobbers and scratch registers */

    // Check if the actual and expected values were the same
    if ( doActualAndExpectedValuesMatch == false )
    {
        // The actual and expected values were not the same

        // Set the actual value
        expectedValue = actualValue;
    }

    // Return if the arguments were equal and the memory was set with the required value
    return ( doActualAndExpectedValuesMatch );
}


template< Concepts::Integer IntegerType > requires ( sizeof( IntegerType ) == 2 )
inline Boolean CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::Read_Compare_IfTrueStoreTheDesiredValueInstead( volatile IntegerType* const integerPointer, IntegerType& expectedValue, const IntegerType desiredValue )
{
    // This will be added only in test mode, to ensure that the given data to the method is valid   
    AssertPointerIsNotNull( integerPointer );

    // This object will store the current value in the memory address, which is the required return value, in case the 2 arguments match
    IntegerType actualValue = 0;

    // This boolean will store if the arguments of the comparison are equal ( true ) or not ( false )
    Boolean doActualAndExpectedValuesMatch = true;

    // The following is an extended inline assembly statement. It will be used to do the read and write of the memory address with no interference. This is not 
    // possible only using C++
    __asm__ volatile ( "MOV AX, %[expectedValue];"
    				   "LOCK CMPXCHG %[memoryAddress], %[desiredValue];"                                                               						/* Assembly code */
                       "JE EQUAL%=;"
                       "MOV %[actualValue], AX;"
                       "MOV %[doActualAndExpectedValuesMatch], 0;"
                       "EQUAL%=:;"

                        : [actualValue] "=m" ( actualValue ), [memoryAddress] "+m" ( *integerPointer ), [doActualAndExpectedValuesMatch] "=m" ( doActualAndExpectedValuesMatch )    											/* Output arguments */
                        : [expectedValue] "r" ( expectedValue ), [desiredValue] "r" ( desiredValue ), "m" ( *integerPointer )		/* Input arguments */
                        : "memory", "cc", "%rax" );                                                                                                                 			/* Clobbers and scratch registers */

    // Check if the actual and expected values were the same
    if ( doActualAndExpectedValuesMatch == false )
    {
        // The actual and expected values were not the same

        // Set the actual value
        expectedValue = actualValue;
    }

    // Return if the arguments were equal and the memory was set with the required value
    return ( doActualAndExpectedValuesMatch );
}


template< Concepts::Integer IntegerType > requires ( sizeof( IntegerType ) == 4 )
inline Boolean CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::Read_Compare_IfTrueStoreTheDesiredValueInstead( volatile IntegerType* const integerPointer, IntegerType& expectedValue, const IntegerType desiredValue )
{
    // This will be added only in test mode, to ensure that the given data to the method is valid   
    AssertPointerIsNotNull( integerPointer );

    // This object will store the current value in the memory address, which is the required return value, in case the 2 arguments match
    IntegerType actualValue = 0;

    // This boolean will store if the arguments of the comparison are equal ( true ) or not ( false )
    Boolean doActualAndExpectedValuesMatch = true;

    // The following is an extended inline assembly statement. It will be used to do the read and write of the memory address with no interference. This is not 
    // possible only using C++
    __asm__ volatile ( "MOV EAX, %[expectedValue];"
    				   "LOCK CMPXCHG %[memoryAddress], %[desiredValue];"                                                               						/* Assembly code */
                       "JE EQUAL%=;"
                       "MOV %[actualValue], EAX;"
                       "MOV %[doActualAndExpectedValuesMatch], 0;"
                       "EQUAL%=:;"

                        : [actualValue] "=m" ( actualValue ), [memoryAddress] "+m" ( *integerPointer ), [doActualAndExpectedValuesMatch] "=m" ( doActualAndExpectedValuesMatch )    											/* Output arguments */
                        : [expectedValue] "r" ( expectedValue ), [desiredValue] "r" ( desiredValue ), "m" ( *integerPointer )		/* Input arguments */
                        : "memory", "cc", "%rax" );                                                                                                                 			/* Clobbers and scratch registers */

    // Check if the actual and expected values were the same
    if ( doActualAndExpectedValuesMatch == false )
    {
        // The actual and expected values were not the same

        // Set the actual value
        expectedValue = actualValue;
    }

    // Return if the arguments were equal and the memory was set with the required value
    return ( doActualAndExpectedValuesMatch );
}


template< Concepts::Integer IntegerType > requires ( sizeof( IntegerType ) == 8 )
inline Boolean CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::Read_Compare_IfTrueStoreTheDesiredValueInstead( volatile IntegerType* const integerPointer, IntegerType& expectedValue, const IntegerType desiredValue )
{
    // This will be added only in test mode, to ensure that the given data to the method is valid   
    AssertPointerIsNotNull( integerPointer );

    // This object will store the current value in the memory address, which is the required return value, in case the 2 arguments match
    IntegerType actualValue = 0;

    // This boolean will store if the arguments of the comparison are equal ( true ) or not ( false )
    Boolean doActualAndExpectedValuesMatch = true;

    // The following is an extended inline assembly statement. It will be used to do the read and write of the memory address with no interference. This is not 
    // possible only using C++
    __asm__ volatile ( "MOV RAX, %[expectedValue];"
    				   "LOCK CMPXCHG %[memoryAddress], %[desiredValue];"                                                               						/* Assembly code */
                       "JE EQUAL%=;"
                       "MOV %[actualValue], RAX;"
                       "MOV %[doActualAndExpectedValuesMatch], 0;"
                       "EQUAL%=:;"

                        : [actualValue] "=m" ( actualValue ), [memoryAddress] "+m" ( *integerPointer ), [doActualAndExpectedValuesMatch] "=m" ( doActualAndExpectedValuesMatch )    											/* Output arguments */
                        : [expectedValue] "r" ( expectedValue ), [desiredValue] "r" ( desiredValue ), "m" ( *integerPointer )		/* Input arguments */
                        : "memory", "cc", "%rax" );                                                                                                                 			/* Clobbers and scratch registers */

    // Check if the actual and expected values were the same
    if ( doActualAndExpectedValuesMatch == false )
    {
        // The actual and expected values were not the same

        // Set the actual value
        expectedValue = actualValue;
    }

    // Return if the arguments were equal and the memory was set with the required value
    return ( doActualAndExpectedValuesMatch );
}



// The following methods will provide the bitwise logical operations AND, OR, XOR and Negate :



template< Concepts::Integer IntegerType >
inline void CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::Read_XOR_Write( volatile IntegerType* const integerPointer, const IntegerType valueToXORwith )
{
    // This will be added only in test mode, to ensure that the given data to the method is valid   
    AssertPointerIsNotNull( integerPointer );

    // The following is an extended inline assembly statement. It will be used to do the read and write of the memory address with no interference. This is not 
    // possible only using C++
    __asm__ volatile ( "LOCK XOR %[memoryAddress], %[valueToXORwith];"                                              /* Assembly code */
                        
                        : "+m" ( *integerPointer )                                                                	/* Output arguments */
                        : [valueToXORwith] "r" ( valueToXORwith ), [memoryAddress] "m" ( *integerPointer )       	/* Input arguments */
                        : "memory", "cc" );                                                                         /* Clobbers and scratch registers */
}


template< Concepts::Integer IntegerType >
inline void CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::Read_OR_Write( volatile IntegerType* const integerPointer, const IntegerType valueToORwith )
{
    // This will be added only in test mode, to ensure that the given data to the method is valid   
    AssertPointerIsNotNull( integerPointer );

    // The following is an extended inline assembly statement. It will be used to do the read and write of the memory address with no interference. This is not 
    // possible only using C++
    __asm__ volatile ( "LOCK OR %[memoryAddress], %[valueToORwith];"                                            /* Assembly code */

                        : "+m" ( *integerPointer )                                                            	/* Output arguments */
                        : [valueToORwith] "r" ( valueToORwith ), [memoryAddress] "m" ( *integerPointer )     	/* Input arguments */
                        : "memory", "cc" );                                                                     /* Clobbers and scratch registers */
}


template< Concepts::Integer IntegerType >
inline void CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::Read_AND_Write( volatile IntegerType* const integerPointer, const IntegerType valueToANDwith )
{
    // This will be added only in test mode, to ensure that the given data to the method is valid   
    AssertPointerIsNotNull( integerPointer );

    // The following is an extended inline assembly statement. It will be used to do the read and write of the memory address with no interference. This is not 
    // possible only using C++
    __asm__ volatile ( "LOCK AND %[memoryAddress], %[valueToANDwith];"                                              /* Assembly code */

                        :  "+m" ( *integerPointer )                                                               	/* Output arguments */
                        : [valueToANDwith] "r" ( valueToANDwith ), [memoryAddress] "m" ( *integerPointer )       	/* Input arguments */
                        : "memory", "cc" );                                                                         /* Clobbers and scratch registers */
}


template< Concepts::Integer IntegerType >
inline void CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::Read_NOT_Write( volatile IntegerType* const integerPointer )
{
    // This will be added only in test mode, to ensure that the given data to the method is valid   
    AssertPointerIsNotNull( integerPointer );

    // The following is an extended inline assembly statement. It will be used to do the read and write of the memory address with no interference. This is not 
    // possible only using C++
    __asm__ volatile ( "LOCK NOT %[memoryAddress];"                     /* Assembly code */

                        : "+m" ( *integerPointer )                    	/* Output arguments */
                        : [memoryAddress] "m" ( *integerPointer )     	/* Input arguments */
                        : "memory", "cc" );                             /* Clobbers and scratch registers */
}


template< Concepts::Integer IntegerType >
inline void CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::Read_NEG_Write( volatile IntegerType* const integerPointer )
{
    // This will be added only in test mode, to ensure that the given data to the method is valid   
    AssertPointerIsNotNull( integerPointer );

    // The following is an extended inline assembly statement. It will be used to do the read and write of the memory address with no interference. This is not 
    // possible only using C++
    __asm__ volatile ( "LOCK NEG %[memoryAddress];"                     /* Assembly code */

                        : "+m" ( *integerPointer )                    	/* Output arguments */
                        : [memoryAddress] "m" ( *integerPointer )     	/* Input arguments */
                        : "memory", "cc" );                             /* Clobbers and scratch registers */
}



// The following methods will provide the bitwise operations BTC, BTR and BTS :



template< Concepts::Integer IntegerType >
inline void CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::ReadBitIntoCarryFlag_WriteOppositeBitState( volatile IntegerType* const integerPointer, UnsignedInteger64bits bitOffset )
{
    // This will be added only in test mode, to ensure that the given data to the method is valid   
    AssertPointerIsNotNull( integerPointer );

    // The following is an extended inline assembly statement. It will be used to do the read and write of the memory address with no interference. This is not 
    // possible only using C++
    __asm__ volatile ( "LOCK BTC %[memoryAddress], %[bitOffset];"                                       /* Assembly code */

                        : "+m" ( *integerPointer )                                                    	/* Output arguments */
                        : [bitOffset] "r" ( bitOffset ), [memoryAddress] "m" ( *integerPointer )     	/* Input arguments */
                        : "memory", "cc" );                                                             /* Clobbers and scratch registers */
}


template< Concepts::Integer IntegerType >
inline void CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::ReadBitIntoCarryFlag_SetBitOFF( volatile IntegerType* const integerPointer, UnsignedInteger64bits bitOffset )
{
    // This will be added only in test mode, to ensure that the given data to the method is valid   
    AssertPointerIsNotNull( integerPointer );

    // The following is an extended inline assembly statement. It will be used to do the read and write of the memory address with no interference. This is not 
    // possible only using C++
    __asm__ volatile ( "LOCK BTR %[memoryAddress], %[bitOffset];"                                       /* Assembly code */

                        : "+m" ( *integerPointer )                                                    	/* Output arguments */
                        : [bitOffset] "r" ( bitOffset ), [memoryAddress] "m" ( *integerPointer )     	/* Input arguments */
                        : "memory", "cc" );                                                             /* Clobbers and scratch registers */
}


template< Concepts::Integer IntegerType >
inline void CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::ReadBitIntoCarryFlag_SetBitON( volatile IntegerType* const integerPointer, UnsignedInteger64bits bitOffset )
{
    // This will be added only in test mode, to ensure that the given data to the method is valid   
    AssertPointerIsNotNull( integerPointer );

    // The following is an extended inline assembly statement. It will be used to do the read and write of the memory address with no interference. This is not 
    // possible only using C++
    __asm__ volatile ( "LOCK BTS %[memoryAddress], %[bitOffset];"                                       /* Assembly code */
    
                        : "+m" ( *integerPointer )                                                    	/* Output arguments */
                        : [bitOffset] "r" ( bitOffset ), [memoryAddress] "m" ( *integerPointer )     	/* Input arguments */
                        : "memory", "cc" );                                                             /* Clobbers and scratch registers */
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	inline void CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::UnitTest()
	{
        UnsignedInteger64bits testMemory_1 = 0UL;

        UnsignedInteger64bits returnValue = 0UL;

        returnValue = Read_Add_Write_ReturnOldValue< UnsignedInteger64bits >( &testMemory_1, 10UL );

        Assert_Test( ( returnValue == 0UL ));

        returnValue = Read_Add_Write_ReturnOldValue< UnsignedInteger64bits >( &testMemory_1, 20UL );

        Assert_Test( ( returnValue == 10UL ));
    
        returnValue = Read_Add_Write_ReturnOldValue< UnsignedInteger64bits >( &testMemory_1, 50UL );

        Assert_Test( ( returnValue == 30UL ));

        returnValue = Read_WriteOtherValue_ReturnOldValue< UnsignedInteger64bits >( &testMemory_1, 0UL );

        Assert_Test( ( returnValue == 80UL ));

        returnValue = Read_Add_Write_ReturnOldValue< UnsignedInteger64bits >( &testMemory_1, 80UL );

        Assert_Test( ( returnValue == 0UL ));

        returnValue = Read_WriteOtherValue_ReturnOldValue< UnsignedInteger64bits >( &testMemory_1, 55555UL );

        Assert_Test( ( returnValue == 80UL ));

        returnValue = Read_WriteOtherValue_ReturnOldValue< UnsignedInteger64bits >( &testMemory_1, 1UL );

        Assert_Test( ( returnValue == 55555UL ));

        Read_XOR_Write< UnsignedInteger64bits >( &testMemory_1, 1UL );

        Assert_Test( ( testMemory_1 == 0UL ));

        returnValue = Read_Add_Write_ReturnOldValue< UnsignedInteger64bits >( &testMemory_1, 1000UL );

        Assert_Test( ( testMemory_1 == 1000UL ));

        Read_Subtract_Write< UnsignedInteger64bits >( &testMemory_1, 990UL );

        returnValue = Read_WriteOtherValue_ReturnOldValue< UnsignedInteger64bits >( &testMemory_1, 200UL );

        Assert_Test( ( returnValue == 10UL ));

        UnsignedInteger64bits testMemory_2 = 666UL;

        returnValue = Read_WriteOtherValue_ReturnOldValue< UnsignedInteger64bits >( &testMemory_2, 999UL );

        Assert_Test( ( returnValue == 666UL ) );

        returnValue = Read_WriteOtherValue_ReturnOldValue< UnsignedInteger64bits >( &testMemory_2, 155555UL );

        Assert_Test( ( returnValue == 999UL ) );
        
        returnValue = Read_WriteOtherValue_ReturnOldValue< UnsignedInteger64bits >( &testMemory_2, 0UL );

        Assert_Test( ( returnValue == 155555UL ) );

        UnsignedInteger8bits testMemory_3 = 66;
        UnsignedInteger8bits expectedValue_3 = 66;

        Boolean comparisonResult = false;

        comparisonResult = Read_Compare_IfTrueStoreTheDesiredValueInstead< UnsignedInteger8bits >( &testMemory_3, expectedValue_3, 45 );

        Assert_Test( ( comparisonResult == true ) );  
        Assert_Test( ( testMemory_3 == 45 ) );  

        comparisonResult = Read_Compare_IfTrueStoreTheDesiredValueInstead< UnsignedInteger8bits >( &testMemory_3, expectedValue_3, 12 );

        Assert_Test( ( comparisonResult == false ) );
        Assert_Test( ( expectedValue_3 == 45 ) );
        Assert_Test( ( testMemory_3 == 45 ) );

        UnsignedInteger16bits testMemory_4 = 3456;
        UnsignedInteger16bits expectedValue_4 = 3456;

        comparisonResult = Read_Compare_IfTrueStoreTheDesiredValueInstead< UnsignedInteger16bits >( &testMemory_4, expectedValue_4, 12321 );
	
        Assert_Test( ( comparisonResult == true ) );  
        Assert_Test( ( testMemory_4 == 12321 ) );  

        comparisonResult = Read_Compare_IfTrueStoreTheDesiredValueInstead< UnsignedInteger16bits >( &testMemory_4, expectedValue_4, 12 );
	
        Assert_Test( ( comparisonResult == false ) );
        Assert_Test( ( expectedValue_4 == 12321 ) );
        Assert_Test( ( testMemory_4 == 12321 ) );  

        UnsignedInteger32bits testMemory_5 = 123456;
        UnsignedInteger32bits expectedValue_5 = 123456;

        comparisonResult = Read_Compare_IfTrueStoreTheDesiredValueInstead< UnsignedInteger32bits >( &testMemory_5, expectedValue_5, 1000000 );
	
        Assert_Test( ( comparisonResult == true ) );  
        Assert_Test( ( testMemory_5 == 1000000 ) );  

        comparisonResult = Read_Compare_IfTrueStoreTheDesiredValueInstead< UnsignedInteger32bits >( &testMemory_5, expectedValue_5, 12 );
	
        Assert_Test( ( comparisonResult == false ) );
        Assert_Test( ( expectedValue_5 == 1000000 ) );
        Assert_Test( ( testMemory_5 == 1000000 ) );  

        UnsignedInteger64bits testMemory_6 = 23454334;
        UnsignedInteger64bits expectedValue_6 = 23454334;

        comparisonResult = Read_Compare_IfTrueStoreTheDesiredValueInstead< UnsignedInteger64bits >( &testMemory_6, expectedValue_6, 34565 );
	
        Assert_Test( ( comparisonResult == true ) );  
        Assert_Test( ( testMemory_6 == 34565 ) );  

        comparisonResult = Read_Compare_IfTrueStoreTheDesiredValueInstead< UnsignedInteger64bits >( &testMemory_6, expectedValue_6, 12 );
	
        Assert_Test( ( comparisonResult == false ) );
        Assert_Test( ( expectedValue_6 == 34565 ) );
        Assert_Test( ( testMemory_6 == 34565 ) );   
	}

)  //  End of debug tool



}  //  Namespace CentralProcessingUnit


}  //  Namespace Universe