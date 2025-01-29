//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline FileWrapper::FileWrapper() :
	member_path(),
	member_doesExistInSecondaryMemory( false ),
	member_wasFileLoadedFromSecondaryMemory( false ),
	member_spinWaitLoop(),
	member_wasFileChanged( false ),
	member_numberOfThreadsOfExecutionUsingTheInstance(),
	member_file()
{}


template< typename UniversalReferencePathType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferencePathType, Path >::Result == true )
inline FileWrapper::FileWrapper( UniversalReferencePathType&& path, const Boolean doesExistInSecondaryMemory ) :
	member_path( AssignOnlyIfAssertionPassed( ForwardUniversalReference< UniversalReferencePathType >( path ), ( path.DoesPointToFile() == true ), "The given path does not point to a file" ) ),
	member_doesExistInSecondaryMemory( doesExistInSecondaryMemory ),
	member_wasFileLoadedFromSecondaryMemory( false ),
	member_spinWaitLoop(),
	member_wasFileChanged( false ),
	member_numberOfThreadsOfExecutionUsingTheInstance(),
	member_file( MemoryHandlerName::PagesArray )
{}


inline FileWrapper::~FileWrapper()
{
	// Try catch structure to ensure no exception will propogate from this destructor
    try
    {
	
		// Download the content of the file from main memory to secondary memory if needed
		DownloadContentFromMainMemoryToSecondaryMemory();

    }
    catch ( const Error::Exception& exception )
    {
    	std::cout << exception.ErrorMessage() << std::endl;
    }
}


inline void FileWrapper::Utilize()
{
	// Increment the number of threads of execution using the instance by 1
	member_numberOfThreadsOfExecutionUsingTheInstance += 1;
}


inline void FileWrapper::Done()
{
	// Decrement the number of threads of execution using the instance by 1
		SignedInteger64bits oldValue = member_numberOfThreadsOfExecutionUsingTheInstance.SubtractAndReturnOldValue( 1 );

		// Assert that the old value was not 0, which means the thread of execution did not use the required method 'Use' to notify to all
		// other threads of execution that it will use this instance
		AssertValueIsLargerThenZero( oldValue );
}


inline Boolean FileWrapper::IsCurrentlyUtilizedByOtherThreadsOfExecution()
{
	// Check if there is at lease one other thread of execution using the instance, and return the result
	return ( member_numberOfThreadsOfExecutionUsingTheInstance.Load() > 0 );
}


template< typename ReturnType, typename... AdditionalArgumentTypes >
inline ReturnType FileWrapper::ViewFile( const Callable< ReturnType ( const File&, AdditionalArgumentTypes... ) >& callable, AdditionalArgumentTypes... additionalArguments )
{
	// In case the file exists in secondary memory and still was not loaded to main memory, load it
	EnsureFileExistInMainMemory__Private();

	// Wait until allowed to continue, and then let the current thread of execution view the file
	return ( member_file.template View< ReturnType, AdditionalArgumentTypes... >( callable, ForwardUniversalReference< AdditionalArgumentTypes >( additionalArguments )... ) );
}


template< typename ReturnType, typename... AdditionalArgumentTypes >
inline ReturnType FileWrapper::EditFile( const Callable< ReturnType ( File&, AdditionalArgumentTypes... ) >& callable, AdditionalArgumentTypes... additionalArguments )
{
	// In case the file exists in secondary memory and still was not loaded to main memory, load it
	EnsureFileExistInMainMemory__Private();

	// Set that the file was changed
	member_wasFileChanged = true;

	// Wait until allowed to continue, and then let the current thread of execution edit the file
	return ( member_file.template Edit< ReturnType, AdditionalArgumentTypes... >( callable, ForwardUniversalReference< AdditionalArgumentTypes >( additionalArguments )... ) );
}


inline void FileWrapper::DownloadContentFromMainMemoryToSecondaryMemory()
{
	// Create a callabe to the download content from main memory to secondary memory, and bind it with this instance
	const Callable< void ( File& ) > downloadContentFromMainMemoryToSecondaryMemoryMethodPointerBoundToInstance( *this, &FileWrapper::DownloadContentFromMainMemoryToSecondaryMemory__Private );

	// Wait until allowed to edit the file, and than download its content from main memory to secondary memory
	member_file.template Edit< void >( downloadContentFromMainMemoryToSecondaryMemoryMethodPointerBoundToInstance );
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



inline void FileWrapper::EnsureFileExistInMainMemory__Private()
{
	// Check if the file exist in secondary memory
	if ( member_doesExistInSecondaryMemory == true )
	{
		// The file exist in secondary memory

		// Check if the file was loaded from secondary memory to main memory
		if ( member_wasFileLoadedFromSecondaryMemory.Load() == false )
		{
			// The file exist in secondary memory, and it was not loaded to main memory yet

			// Ensure only one thread of execution will continue
			MultiThread::ScopedSpinWaitLoop ensureOnlyOneThreadOfExecutionWillContinue( &member_spinWaitLoop );

			// This boolean will be used to determine if this thread of execution needs to create the file
			Boolean shouldThisThreadOfExecutionCreateTheFile = false;

			// Try to set the atomic boolean with the value 'true'. If the value will be actually set by this thread of execution, than it
			// will be responsible for loading the file from secondary memory to main memory
			if ( member_wasFileLoadedFromSecondaryMemory.CompareTheActualValueWithTheExpectedAndIfEqualSetTheDesiredValue( shouldThisThreadOfExecutionCreateTheFile, true ) == true )
			{
				// The value was set by this thread of execution

				// Create a method pointer to the download content from main memory to secondary memory, and bind it with this instance
				const Callable< void ( File&, const Path& ) > loadFileFromSecondaryMemoryToMainMemoryMethodPointerBoundToInstance( &FileWrapper::LoadFileFromSecondaryMemoryToMainMemory__Private );

				// Load the file
				member_file.template Edit< void, const Path& >( loadFileFromSecondaryMemoryToMainMemoryMethodPointerBoundToInstance, member_path );
			}
		}
	}
}



}  //  Namespace FileSystem 


}  //  Namespace Universe