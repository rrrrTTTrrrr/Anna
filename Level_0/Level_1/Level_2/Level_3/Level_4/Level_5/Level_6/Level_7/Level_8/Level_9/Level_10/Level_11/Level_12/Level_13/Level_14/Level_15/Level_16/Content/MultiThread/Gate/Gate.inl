//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline Gate::Gate() :
	member_isOpen( false )
{}


inline void Gate::Open()
{
    // Set the boolean that notifies if the access to the resource is open or close to true
    member_isOpen = true;
}


inline void Gate::Close()
{
    // Set the boolean that notifies if the access to the resource is open or close to false
    member_isOpen = false;
}


inline void Gate::WaitUntilOpen()
{
    // Loop forever and ever
    while ( true )
    {
        // Check if the access to the resource is allowed
        if ( member_isOpen.Load() == true )
        {
            // The access to the resource is allowed. This means that the current thread of execution should stop waiting and continue

            // I can finally enter!!!
            break;
        }

        // Delay the central processing unit for a finite time. The method uses the 'PAUSE' instruction which provides a hint to the processor
        // that a thread is trying to lock using a loop. It will improve performance and power consumption
        CentralPrcessingUnit_Pause();
    }

    // Ensure that the compiler will not reorder write and read across this boundary
    CompilerBarrier_AllPreviousMemoryAccessesWillNotBeReorderedWithTheNextMemoryAccesses;
}



}  //  Namespace MultiThread


}  //  Namespace Universe