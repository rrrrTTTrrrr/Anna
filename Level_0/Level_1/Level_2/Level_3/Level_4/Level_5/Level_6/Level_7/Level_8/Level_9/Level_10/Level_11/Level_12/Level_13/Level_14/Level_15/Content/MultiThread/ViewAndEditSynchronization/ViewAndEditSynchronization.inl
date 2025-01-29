//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline ViewAndEditSynchronization::ViewAndEditSynchronization() :
	member_numberOfViewingThreadsOfExecution( 0 ),
	member_spinWaitLoopToSynchronizeThreadsOfExecution()
{}


inline void ViewAndEditSynchronization::View()
{
	// Wait until it is allowed to lock the spin wait loop, to ensure only this thread will continue. This will ensure that only thread at 
	// a time access the counter
	member_spinWaitLoopToSynchronizeThreadsOfExecution.WaitUntilAllowedToLockToEnsureOnlyThisThreadOfExecutionWillContinue();

	// Increment the number of threads that were allowed to continue
	member_numberOfViewingThreadsOfExecution += 1;

	// Unlock the spin wait loop to let the next thread access the counter
	member_spinWaitLoopToSynchronizeThreadsOfExecution.Unlock();
}


inline void ViewAndEditSynchronization::Edit()
{
	// Wait until it is allowed to lock the spin wait loop, to ensure only this thread will continue. This will ensure that only thread at 
	// a time access the counter
	member_spinWaitLoopToSynchronizeThreadsOfExecution.WaitUntilAllowedToLockToEnsureOnlyThisThreadOfExecutionWillContinue();

	// Spin wait loop until the number of threads that were allowed to continue is 0
	while ( member_numberOfViewingThreadsOfExecution.Load() > 0 )
	{
        // Delay the central processing unit for a finite time. The method uses the 'PAUSE' instruction which provides a hint to the processor
        // that a thread is trying to lock using a loop. It will improve performance and power consumption
        CentralPrcessingUnit_Pause();			
	}
}


inline void ViewAndEditSynchronization::EditThenViewWithoutLettingOtherThreadsOfExecutionEditBetween()
{
	// Wait until it is allowed to lock the spin wait loop, to ensure only this thread will continue. This will ensure that only thread at 
	// a time access the counter
	member_spinWaitLoopToSynchronizeThreadsOfExecution.WaitUntilAllowedToLockToEnsureOnlyThisThreadOfExecutionWillContinue();

	// Spin wait loop until the number of threads that were allowed to continue is 0
	while ( member_numberOfViewingThreadsOfExecution.Load() > 0 )
	{
        // Delay the central processing unit for a finite time. The method uses the 'PAUSE' instruction which provides a hint to the processor
        // that a thread is trying to lock using a loop. It will improve performance and power consumption
        CentralPrcessingUnit_Pause();			
	}

	// Increment the number of threads that were allowed to continue
	member_numberOfViewingThreadsOfExecution += 1;
}


inline void ViewAndEditSynchronization::DoneViewing()
{
	// Decrement the number of threads that were allowed to continue, and store the old value
	SignedInteger64bits oldValue = member_numberOfViewingThreadsOfExecution.SubtractAndReturnOldValue( 1 );

	// Assert that the method 'view' or 'EditThenViewWithoutLettingOtherThreadsOfExecutionEditBetween' were called prior to using this method
	// by checking that old value is not 0 or less
	AssertValueIsLargerThenZero( oldValue );
}


inline void ViewAndEditSynchronization::DoneEditing()
{
	// Unlock the spin wait loop to allow other threads to continue
	member_spinWaitLoopToSynchronizeThreadsOfExecution.Unlock();
}



}  //  Namespace MultiThread


}  //  Namespace Universe