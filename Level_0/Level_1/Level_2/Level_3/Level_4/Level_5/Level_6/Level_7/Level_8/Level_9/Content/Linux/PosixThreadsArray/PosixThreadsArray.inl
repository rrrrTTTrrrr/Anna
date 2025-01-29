//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline PosixThreadsArray::PosixThreadsArray( const LargestUnsignedInteger numberOfThreadsOfExecution, FunctionPointerType functionPointer, void* const functionArgument ) :
	member_numberOfThreadsOfExecution( AssignOnlyIfValueIsLargerThenZero( numberOfThreadsOfExecution ) ),
	member_functionPointer( AssignOnlyIfPointerIsNotNULL( functionPointer ) ),
	member_threadsOfExecutionArray( Memory::MainMemoryManager::template AllocateAndDefaultConstruct< UnsignedInteger8bits >( sizeof( PosixThread ) * numberOfThreadsOfExecution ) ),
	member_didThreadsOfExecutionFinished( false )
{
	// Loop on all the threads of execution pointers
	for ( LargestUnsignedInteger index = 0UL ; index < member_numberOfThreadsOfExecution ; ++index )
	{
		// Determine the offset to the current posix thread instance
		const LargestUnsignedInteger offset = index * sizeof( PosixThread );

		// Allocate new standard thread of execution instance, and store the memory address of it in the pointer
		Memory::MainMemoryManager::template Construct< Linux::PosixThread, FunctionPointerType, void* const >( member_threadsOfExecutionArray + offset, member_functionPointer, functionArgument );
	}
}


inline PosixThreadsArray::~PosixThreadsArray()
{
	// Loop on all the threads of execution pointers
    for ( LargestUnsignedInteger index = 0 ; index < member_numberOfThreadsOfExecution ; ++index )
    {
        // Call the destructor of the current posix thread of execution instance
        Memory::MainMemoryManager::Destruct< PosixThread >( GetPosixThreadMemoryAddressByIndex__Private( index ) );
    }

    // Delete the memory space used
    Memory::MainMemoryManager::template Done< UnsignedInteger8bits >( member_threadsOfExecutionArray, false );
}


inline void PosixThreadsArray::WaitForThreadsOfExecutionToFinish()
{
	// Loop on all the threads of execution pointers
    for ( LargestUnsignedInteger index = 0 ; index < member_numberOfThreadsOfExecution ; ++index )
    {
    	// Wait for the thread of execution to finish
        reinterpret_cast< PosixThread* >( GetPosixThreadMemoryAddressByIndex__Private( index ) )->WaitForThreadOfExecutionToFinish();
    }
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



inline UnsignedInteger8bits* PosixThreadsArray::GetPosixThreadMemoryAddressByIndex__Private( const LargestUnsignedInteger index ) const
{
	// Add the given index times the size of each posix thread structure, add the sum to the starting index of the array and return the result
	return ( member_threadsOfExecutionArray + index * sizeof( PosixThread ) );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	inline void PosixThreadsArray::UnitTest()
	{}

)  //  End of debug tool



}  //  Namespace Linux


}  //  Namespace Universe
