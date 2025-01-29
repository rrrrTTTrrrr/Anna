//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline SpinWaitLoopQueue::SpinWaitLoopQueue() :
	member_currentRequestAllowedToStopWaiting( 0U ),
    member_spinWaitQueue( 0U )
{}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

    inline void SpinWaitLoopQueue::UnitTest()
    {}

)  //  End of debug tool



}  //  Namespace CentralProcessingUnit


}  //  Namespace Universe