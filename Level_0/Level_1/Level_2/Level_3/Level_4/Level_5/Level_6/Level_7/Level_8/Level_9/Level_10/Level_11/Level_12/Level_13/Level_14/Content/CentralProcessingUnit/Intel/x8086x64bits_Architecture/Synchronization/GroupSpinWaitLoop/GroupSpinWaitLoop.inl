//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline GroupSpinWaitLoop::GroupSpinWaitLoop() :
    member_groupIdentifier()
{}


inline void GroupSpinWaitLoop::Wait()
{
    // Read the current value of the group spin wait loop integer
    const UnsignedInteger64bits groupIdentifier = member_groupIdentifier.Load();

    // Loop forever and ever
    while ( true )
    {
        // Check if the updated group identifier value is larger then the one fetched at the begining
        if ( groupIdentifier < member_groupIdentifier.Load() )
        {
            // The group identifier value is larger then the initial value. This means that the current group of threads of execution should
            // stop waiting and continue

            // Our group turn has arrived!!!
            break;
        }

        // Delay the central processing unit for a finite time. The method uses the 'PAUSE' instruction which provides a hint to the processor
        // that a thread is trying to lock using a loop. It will improve performance and power consumption
        CentralPrcessingUnit_Pause();
    }

    // Ensure that the compiler will not reorder write and read across this boundary
    CompilerBarrier_AllPreviousMemoryAccessesWillNotBeReorderedWithTheNextMemoryAccesses;
}


inline void GroupSpinWaitLoop::ReleaseCurrentWaitingGroupThreadsOfExecution()
{
    // Increment the group spin wait loop integer by one, to release all the threads of execution that currently wait
    member_groupIdentifier += 1UL;
}



}  //  Namespace CentralProcessingUnit


}  //  Namespace Universe