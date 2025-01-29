//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< Concepts::FunctorWithoutReturnValueOrArguments TaskType, LargestUnsignedInteger CircularBufferSize > requires ( ThreadsOfExecutionNumber > 0UL )
inline WorkersThreadsOfExecution< TaskType, CircularBufferSize >::WorkersThreadsOfExecution( const LargestUnsignedInteger numberOfThreadsOfExecution,  ) :
	member_tasks(),
	member_threadsOfExecution(),
	member_shouldStop( false )
{}


template< Concepts::FunctorWithoutReturnValueOrArguments TaskType, LargestUnsignedInteger CircularBufferSize > requires ( ThreadsOfExecutionNumber > 0UL )
inline WorkersThreadsOfExecution< TaskType, CircularBufferSize >::~WorkersThreadsOfExecution()
{
	// Check if the instance was constructed using the default constructor or the 'Reset' method was used, which usually signify that there
    // are no resources used by the instance, and nothing needs to be done further in the destructor
    ReturnIfExpressionIsTrue();
}


template< Concepts::FunctorWithoutReturnValueOrArguments TaskType, LargestUnsignedInteger CircularBufferSize > requires ( ThreadsOfExecutionNumber > 0UL )
inline void WorkersThreadsOfExecution< TaskType, CircularBufferSize >::Start()
{
	// Start the required number threads of execution to perform the tasks
	for ( LargestUnsignedInteger index = 0UL ; index < ThreadsOfExecutionNumber ; ++index )
	{
		// Create a thread of execution and provide with the method that waits until there is a task to pefrorm and then execute it
		member_threadsOfExecution[ index ] = ThreadsOfExecution< void () >(  );
	}

}



//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



//  ********************************************************   TEMPLATE OR INLINE PURE VIRTUAL METHODS IMPLEMENTATION   *********************************************************



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



template< Concepts::FunctorWithoutReturnValueOrArguments TaskType, LargestUnsignedInteger CircularBufferSize > requires ( ThreadsOfExecutionNumber > 0UL )
inline void WorkersThreadsOfExecution< TaskType, CircularBufferSize >::WaitForTasksToArriveAndExecute__Private()
{
	// This object will store the current task that needs to be performed
	TaskType task;

	// This object will store if a task was popped from the circular buffer
	Boolean doesTaskExist = false;

	// Loop until request to exit arrive
	while ( member_shouldStop == false )
	{
		// Wait for a task
		doesTaskExist = member_tasks.Pop( task, 2UL );

		// Check if a task exist
		if ( doesTaskExist == true )
		{
			// Perform the task
			task();

			// Set that the current task was performed
			doesTaskExist = false;
		}
	}
}



// ***************************************************************   NESTED CLASS PUBLIC METHODS IMPLEMENTATION -    ************************************************************



// **********************************************************   INLINE AND TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   ***********************************************************



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

template< Concepts::FunctorWithoutReturnValueOrArguments TaskType, LargestUnsignedInteger CircularBufferSize > requires ( ThreadsOfExecutionNumber > 0UL )
void WorkersThreadsOfExecution< TaskType, CircularBufferSize >::UnitTest()
{}

)  //  End of debug tool



}  //  Namespace MultiThread

}  //  Namespace Universe
