namespace Universe
{

namespace CentralProcessingUnit
{



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

    void* SpinWaitLoop::UnitTest_Add( void* argument )
    {
        UnitTest_ArgumentsToFunction* argumentsToFunction = reinterpret_cast< UnitTest_ArgumentsToFunction* >( argument );

        for ( UnsignedInteger64bits index = 0 ; index < argumentsToFunction->numberOfAdditionsToExecute ; ++index )
        {
            argumentsToFunction->testLoopLock->WaitUntilAllowedToLockToEnsureOnlyThisThreadOfExecutionWillContinue();

            *(argumentsToFunction->sharedMemoryPointer) += 1;

            argumentsToFunction->testLoopLock->Unlock();
        }

        return ( nullptr );
    }

	void SpinWaitLoop::UnitTest()
	{
        // This definition will be used to determine the total number of additions to perfrom. Then each thread will execute this number divided by
        // the number of threads additons
        constexpr UnsignedInteger64bits numberOfAdditionsToExecute = 10000000;
        constexpr UnsignedInteger64bits numberOfThreadsOfExecutionToCreate = 10;

        // Create a loop lock instance
        SpinWaitLoop testLoopLock_1;

        // Ensure that the spin wait loop idle method works
        Assert_Test( testLoopLock_1.IsIdle() == true );

        // This will be the shared memory
        UnsignedInteger64bits sharedMemory = 0;

        // Try the basic funtionality
        testLoopLock_1.WaitUntilAllowedToLockToEnsureOnlyThisThreadOfExecutionWillContinue();
        testLoopLock_1.Unlock();

        UnitTest_ArgumentsToFunction argumentsToFunction = { .testLoopLock = &testLoopLock_1 COMMA .sharedMemoryPointer = &sharedMemory COMMA .numberOfAdditionsToExecute = numberOfAdditionsToExecute };

        // Create and execute the threads of execution
        Linux::PosixThreadsArray threadsOfExecution( numberOfThreadsOfExecutionToCreate, &UnitTest_Add, &argumentsToFunction );

        // Ensure that the spin wait loop idle method works
        Assert_Test( testLoopLock_1.IsIdle() == false );

        // Wait for the threads of execution to finish
        threadsOfExecution.WaitForThreadsOfExecutionToFinish();

        // Ensure that the spin wait loop idle method works
        Assert_Test( testLoopLock_1.IsIdle() == true );

        // Ensure that the value is 1000000
        Assert_Test( ( sharedMemory == ( numberOfThreadsOfExecutionToCreate * numberOfAdditionsToExecute ) ) );
    }

)  //  End of debug tool



}  //  Namespace CentralProcessingUnit


}  //  Namespace Universe