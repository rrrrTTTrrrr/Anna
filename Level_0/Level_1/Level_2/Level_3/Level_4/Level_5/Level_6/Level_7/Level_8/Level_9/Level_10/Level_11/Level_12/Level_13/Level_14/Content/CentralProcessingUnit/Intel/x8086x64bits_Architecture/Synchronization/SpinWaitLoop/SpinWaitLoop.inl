//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline SpinWaitLoop::SpinWaitLoop() :
    member_spinWaitLoopQueue()
{}


inline void SpinWaitLoop::WaitUntilAllowedToLockToEnsureOnlyThisThreadOfExecutionWillContinue()
{
    // This object ( hopefully, and not on the stack memory segment ) will be in a register in the current thread's context and therefore only accessable 
    // to it. It will be used to communicate with spin wait loop queue member. The members and size of both the spin wait loop queue object and the spin
    // wait loop request handle object are identical, the only difference is the functionailty working on them. This is on purpose, to allow manipulating
    // the entire instance as an integer that can be contained in a single register, and not through the regular methods interface or data members. When
    // This instance is constructed, it initializes the matching part of the instance ( unsigned integer 32 high significant bits ) to 1, and the other 
    // to 0. It then locks the memory space of the spin wait loop, so no other central processing unit can access that memory, reads the current value
    // of the spin wait loop queue as unsigned integer 64 bits, increment the queue by 1 to notify that this instance also waits for a turn, but no 
    // changes will be made to the current request allowed to stop waiting part. The old value will be stored inside the instance, it will be used to 
    // determine if the method flow should keep waiting or not. The concept is that the instance layout is :
    //
    //                                       spin wait loop queue            current request allowed to 
    //                                          request handle                      stop waiting
    //                              ___________________________________ ___________________________________
    //                              |                                 | |                                 |
    //         Address   ->         00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
    //                              |                                                                     |
    //                     High significant bit                                                 Low significant bit
    //
    // Then when reading the spin wait loop queue as an 64 bits unsigned integer, the queue itself will be stored in the high significant bits of the
    // instance, and the current request allowed to stop waiting at the low significant bits. The high significant bits of the instance now caontain
    // an handle that can tell this instance when to stop waiting. Then this part of the instance will reamin constant for the remain of the method.
    // The low significant bits value will be changed in each iteration and checked if the values are equal. When the 2 values are equal there is no
    // more need to wait, and the flow of the method can proceed
    SpinWaitLoopQueueRequestHandle spinWaitLoopQueueRequestHandle;

    // Read the value from memory of the other instance as unsigned integer 64 bits, which will contain the 2 identifiers ( it is possible because 
    // the size of this object is 8 bytes which is the size of the register as well ), add this instance to it, and store back the new value into
    // the memory while not allowing any other central processing unit in the system to access the specific memory. At last, the other instance value
    // read from memory will be stored in this instance
    *( reinterpret_cast< UnsignedInteger64bits* >( &spinWaitLoopQueueRequestHandle ) ) = CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::Read_Add_Write_ReturnOldValue< UnsignedInteger64bits >( reinterpret_cast< volatile UnsignedInteger64bits* >( &member_spinWaitLoopQueue ), *( reinterpret_cast< volatile UnsignedInteger64bits* >( &spinWaitLoopQueueRequestHandle ) ) );

    // Loop forever and ever
    while ( true )
    {
        // Check if both parts of the instance ( each 32 bits unsigned integer ) are equal
        if ( spinWaitLoopQueueRequestHandle.ShouldStopWaiting() == true )
        {
            // Both parts of the instance are equal

            // My turn has arrived!!!
            break;
        }

        // Delay the central processing unit for a finite time. The method uses the 'PAUSE' instruction which provides a hint to the processor
        // that a thread is trying to lock using a loop. It will improve performance and power consumption
        CentralPrcessingUnit_Pause();

        // Update the 32 low significant bits of the instance with the valid value of in the spin wait loop queue
        spinWaitLoopQueueRequestHandle.member_currentRequestAllowedToStopWaiting = Compiler_EnsureReadingVariableFromSystemMemory( member_spinWaitLoopQueue.member_currentRequestAllowedToStopWaiting );
    }

    // Ensure that the compiler will not reorder write and read across this boundary
    CompilerBarrier_AllPreviousMemoryAccessesWillNotBeReorderedWithTheNextMemoryAccesses;
}


inline void SpinWaitLoop::Unlock()
{
    // This object will be used to lock a memory area from other central processing units to access it. Then it will read the value of the current
    // request allowed to stop waiting from memory, increment it by 1 and store the result back to memory
    CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::Read_Add_Write< UnsignedInteger32bits >( &member_spinWaitLoopQueue.member_currentRequestAllowedToStopWaiting, 1U );
}


inline Boolean SpinWaitLoop::IsIdle()
{
    // The spin wait loop is idle, when all the previous users has finished, and no new user is currently waiting for service. This
    // information can be obtained from the spin wait loop queue, if the current request allowed to continue value is the same as the
    // queue itself then nobody is using the spin wait loop
    return ( Compiler_EnsureReadingVariableFromSystemMemory( member_spinWaitLoopQueue.member_currentRequestAllowedToStopWaiting ) == Compiler_EnsureReadingVariableFromSystemMemory( member_spinWaitLoopQueue.member_spinWaitQueue ) );
}



}  //  Namespace CentralProcessingUnit


}  //  Namespace Universe