namespace Universe 
{


namespace MultiThread
{



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	void* ViewAndEditSynchronization::UnitTest_Read( void* argument )
	{
		UnitTest_ArgumentsToFunction* argumentsToFunction = reinterpret_cast< UnitTest_ArgumentsToFunction* >( argument );

		UnsignedInteger64bits counterCopy = 12UL;

		for ( UnsignedInteger64bits index = 0UL ; index < 100000UL ; ++index )
		{
			argumentsToFunction->testInstance->View();

			if ( *argumentsToFunction->testCounter != counterCopy )
			{
				counterCopy = *argumentsToFunction->testCounter;
			}

			argumentsToFunction->testInstance->DoneViewing();
		}

		return ( nullptr );
	}

	void* ViewAndEditSynchronization::UnitTest_Write( void* argument )
	{
		UnitTest_ArgumentsToFunction* argumentsToFunction = reinterpret_cast< UnitTest_ArgumentsToFunction* >( argument );

		for ( UnsignedInteger64bits index = 0UL ; index < argumentsToFunction->numberOfAdditionsToExecute ; ++index )
		{
			argumentsToFunction->testInstance->Edit();

			*argumentsToFunction->testCounter += 1;

			argumentsToFunction->testInstance->DoneEditing();
		}

		return ( nullptr );
	}

	void ViewAndEditSynchronization::UnitTest()
	{
        // This definition will be used to determine the total number of additions to perfrom. Then each thread will execute this number divided by
        // the number of threads additons
        constexpr UnsignedInteger64bits numberOfAdditionsToExecute = 10000000;
        constexpr UnsignedInteger64bits numberOfThreadsToCreate = 5;

		ViewAndEditSynchronization testInstance;
		UnsignedInteger64bits testCounter = 0UL;

        UnitTest_ArgumentsToFunction argumentsToFunction = { .testInstance = &testInstance COMMA .testCounter = &testCounter COMMA .numberOfAdditionsToExecute = numberOfAdditionsToExecute };

        // Create and execute the threads of execution for read
        Linux::PosixThreadsArray threadsOfExecution_Read( 3UL, &UnitTest_Read, &argumentsToFunction );

        // Create and execute the threads of execution for read
        Linux::PosixThreadsArray threadsOfExecution_Write( numberOfThreadsToCreate, &UnitTest_Write, &argumentsToFunction );

        // Wait for the threads of execution to finishd
        threadsOfExecution_Read.WaitForThreadsOfExecutionToFinish();
        threadsOfExecution_Write.WaitForThreadsOfExecutionToFinish();

		UnsignedInteger64bits expectedResultForTestCounter = numberOfAdditionsToExecute * numberOfThreadsToCreate;

		Assert_Test( expectedResultForTestCounter == testCounter );
	}

)  //  End of debug tool



}  //  Namespace MultiThread


}  //  Namespace Universe