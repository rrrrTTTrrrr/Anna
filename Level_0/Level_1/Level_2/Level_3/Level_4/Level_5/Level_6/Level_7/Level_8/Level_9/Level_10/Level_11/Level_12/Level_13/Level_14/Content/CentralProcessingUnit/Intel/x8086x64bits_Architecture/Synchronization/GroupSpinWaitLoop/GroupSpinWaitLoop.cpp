namespace Universe 
{


namespace CentralProcessingUnit
{



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

    void* GroupSpinWaitLoop::UnitTest_Add( void* argument )
    {
        UnitTest_ArgumentsToFunction* argumentsToFunction = reinterpret_cast< UnitTest_ArgumentsToFunction* >( argument );

        GroupSpinWaitLoop* const testLoopLockPointer = argumentsToFunction->groupSpinWaitLoopPointer;
        UnsignedInteger64bits* const sharedMemoryPointer = argumentsToFunction->sharedMemoryPointer;

        testLoopLockPointer->Wait();

        CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::Read_Add_Write< UnsignedInteger64bits >( sharedMemoryPointer, 1UL );

        return ( nullptr );
    }

	void GroupSpinWaitLoop::UnitTest()
	{
        // This definition will be used to determine the total number of additions to perfrom. Then each thread will execute this number divided by
        // the number of threads additons
        constexpr UnsignedInteger64bits numberOfAdditionsToExecute = 10;
        constexpr UnsignedInteger64bits numberOfThreadsOfExecutionToCreate = 10;

        // Create a loop lock instance
        GroupSpinWaitLoop testLoopLock_1;

        // This will be the shared memory
        UnsignedInteger64bits sharedMemory;
        sharedMemory = 0UL;

        UnitTest_ArgumentsToFunction argumentsToFunction = { .groupSpinWaitLoopPointer = &testLoopLock_1 COMMA .sharedMemoryPointer = &sharedMemory };

        // Loop the required amount of iterations
        for ( UnsignedInteger64bits iteration = 0UL ; iteration < numberOfAdditionsToExecute ; ++iteration )
        {
            // Create and execute the threads of execution
            Linux::PosixThreadsArray threadsOfExecution( numberOfThreadsOfExecutionToCreate, &UnitTest_Add, &argumentsToFunction );

            // Wait for all the threads to reach the waiting point
            sleep( 1 );

            // Ensure that the threads of execution actualy wait by comparing the value in the shard memory
            Assert_Test( sharedMemory == numberOfThreadsOfExecutionToCreate * iteration );

            // Release all the waiting threads
            testLoopLock_1.ReleaseCurrentWaitingGroupThreadsOfExecution();

            // Wait for all the created threads of execution to finish
            threadsOfExecution.WaitForThreadsOfExecutionToFinish();

            // Ensure that the value is 10
            Assert_Test( ( sharedMemory == numberOfThreadsOfExecutionToCreate * ( iteration + 1UL ) ) );
        }
    }

)  //  End of debug tool



}  //  Namespace CentralProcessingUnit


}  //  Namespace Universe