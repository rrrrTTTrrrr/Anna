//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline PosixThread::PosixThread( FunctionPointerType const functionPointer, void* const argumentPointer ) :
	member_thread(),
	member_functionPointer( AssignOnlyIfPointerIsNotNULL( functionPointer ) ),
	member_argumentPointer( argumentPointer ),
	member_didThreadOfExecutionFinished( false )
{
	// Start a new thread of execution that will run the given function with the required argument
	const SignedInteger32bits pthreadCreateReturnValue = pthread_create( &member_thread, nullptr, member_functionPointer, member_argumentPointer );

	// Check if the call was successful
	if ( pthreadCreateReturnValue != 0 )
	{
		// The call failed

		// Throw an errno exception
		ThrowErrnoException;
	}
}


inline PosixThread::~PosixThread()
{
	// Check if the thread of execution has finished already
	if ( member_didThreadOfExecutionFinished == false )
	{
		// Wait for the thread of execution to finish
		pthread_join( member_thread, nullptr );
	}
}


inline void* PosixThread::WaitForThreadOfExecutionToFinish()
{
	// This object will store the function, that the thread of execution was running, return value
	void* functionReturnValue = nullptr;

	// Wait for the thread of execution to finish
	const SignedInteger32bits pthreadJoinReturnValue = pthread_join( member_thread, &functionReturnValue );

	// Check if the call was successful
	if ( pthreadJoinReturnValue != 0 )
	{
		// The call failed

		// Throw an errno exception
		ThrowErrnoException;
	}

	// Mark that the thread of execution has finished
	member_didThreadOfExecutionFinished = true;

	// Return the value from the function call
	return ( functionReturnValue );
}



}  //  Namespace Linux


}  //  Namespace Universe
