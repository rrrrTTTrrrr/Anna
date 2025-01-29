//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline SpinWaitLoopQueueRequestHandle::SpinWaitLoopQueueRequestHandle() :
	member_currentRequestAllowedToStopWaiting( 0U ),
    member_spinLoopWaitQueueRequestHandle( 1U )
{}


inline Boolean SpinWaitLoopQueueRequestHandle::ShouldStopWaiting()
{
    // Check if the identifier of the request that should stop wait matches this instance identifier
    return ( member_spinLoopWaitQueueRequestHandle == member_currentRequestAllowedToStopWaiting );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

    inline void SpinWaitLoopQueueRequestHandle::UnitTest()
    {}

)  //  End of debug tool



}  //  Namespace CentralProcessingUnit


}  //  Namespace Universe