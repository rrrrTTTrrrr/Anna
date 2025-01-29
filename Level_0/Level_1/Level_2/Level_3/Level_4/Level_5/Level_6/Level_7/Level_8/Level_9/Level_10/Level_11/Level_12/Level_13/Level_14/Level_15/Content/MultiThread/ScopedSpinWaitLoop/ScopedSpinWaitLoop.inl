//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline ScopedSpinWaitLoop::ScopedSpinWaitLoop( CentralProcessingUnit::SpinWaitLoop* const spinWaitLoop ) :
	member_spinWaitLoop( AssignOnlyIfPointerIsNotNULL( spinWaitLoop ) )
{
    // Lock the spin wait loop instance
    member_spinWaitLoop->WaitUntilAllowedToLockToEnsureOnlyThisThreadOfExecutionWillContinue();
}


inline ScopedSpinWaitLoop::~ScopedSpinWaitLoop()
{
    // Unlock the spin wait loop instance
    member_spinWaitLoop->Unlock();
}



}  //  Namespace MultiThread


}  //  Namespace Universe