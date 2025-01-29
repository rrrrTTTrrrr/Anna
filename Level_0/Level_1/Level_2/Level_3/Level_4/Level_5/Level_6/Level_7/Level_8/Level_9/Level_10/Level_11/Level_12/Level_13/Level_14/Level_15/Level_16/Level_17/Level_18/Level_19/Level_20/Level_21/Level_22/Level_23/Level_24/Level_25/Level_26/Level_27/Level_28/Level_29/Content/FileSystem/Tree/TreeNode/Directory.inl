//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline Directory::Directory() :
	member_path(),
	member_parentDirectoryPointer( nullptr ),
	member_doesExistInSecondaryMemory( true ),
	member_fileWrappersPointers(),
	member_childDirectoriesPointers(),
	member_numberOfThreadsOfExecutionUsingTheInstance()
{}


template< typename UniversalReferencePathType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferencePathType, Path >::Result == true )
inline Directory::Directory( UniversalReferencePathType&& path, SelfType* const parentDirectoryPointer, const Boolean doesExistInSecondaryMemory ) :
	member_path( AssignOnlyIfAssertionPassed( ForwardUniversalReference< UniversalReferencePathType >( path ), ( path.Size() > 1UL ), "The given path points to the root directory, it is the only directory that already exist on boot" ) ),
	member_parentDirectoryPointer( AssignOnlyIfPointerIsNotNULL( parentDirectoryPointer ) ),
	member_doesExistInSecondaryMemory( doesExistInSecondaryMemory ),
	member_fileWrappersPointers(),
	member_childDirectoriesPointers(),
	member_numberOfThreadsOfExecutionUsingTheInstance()
{}


inline void Directory::Utilize()
{
	// Increment the number of threads of execution using the instance by 1
	member_numberOfThreadsOfExecutionUsingTheInstance += 1;
}


inline void Directory::Done()
{
	// Decrement the number of threads of execution using the instance by 1
	const SignedInteger64bits oldValue = member_numberOfThreadsOfExecutionUsingTheInstance.SubtractAndReturnOldValue( 1 );

	// Assert that the old value was not 0, which means the thread of execution did not use the required method 'Use' to notify to all
	// other threads of execution that it will use this instance
	AssertValueIsLargerThenZero( oldValue );
}


inline Boolean Directory::IsCurrentlyUtilizedByOtherThreadsOfExecution()
{
	// Check if there is at lease one other thread of execution using the instance, and return the result
	return ( member_numberOfThreadsOfExecutionUsingTheInstance.Load() > 0 );
}


template< typename ReturnType, typename... AdditionalArgumentTypes >
inline ReturnType Directory::ViewChildDirectories( const Callable< ReturnType ( const SequentialDataStructure< SelfType* >&, AdditionalArgumentTypes... ) >& callable, const Boolean disableLoading, AdditionalArgumentTypes... additionalArguments )
{
	// Check if the loading of the content from secondary memroy is disabled
	if ( disableLoading == false )
	{
		// If the directory already exist in secondary memory load its content if needed
		LoadDirectoryContentFromSecondaryMemoryIfNeeded__Private();
	}

	// Wait until allowed to continue, and then let the current thread of execution view the child directories container
	return ( member_childDirectoriesPointers.template View< ReturnType, AdditionalArgumentTypes... >( callable, ForwardUniversalReference< AdditionalArgumentTypes >( additionalArguments )... ) );
}


template< typename ReturnType, typename... AdditionalArgumentTypes >
inline ReturnType Directory::EditChildDirectories( const Callable< ReturnType ( SequentialDataStructure< SelfType* >&, AdditionalArgumentTypes... ) >& callable, const Boolean disableLoading, AdditionalArgumentTypes... additionalArguments )
{
	// Check if the loading of the content from secondary memroy is disabled
	if ( disableLoading == false )
	{
		// If the directory already exist in secondary memory load its content if needed
		LoadDirectoryContentFromSecondaryMemoryIfNeeded__Private();
	}

	// Wait until allowed to continue, and then let the current thread of execution edit the child directories container
	return ( member_childDirectoriesPointers.template Edit< ReturnType, AdditionalArgumentTypes... >( callable, ForwardUniversalReference< AdditionalArgumentTypes >( additionalArguments )... ) );
}


template< typename ReturnType, typename... AdditionalArgumentTypes >
inline ReturnType Directory::ViewFilesWrappers( const Callable< ReturnType ( const SequentialDataStructure< FileWrapper* >&, AdditionalArgumentTypes... ) >& callable, const Boolean disableLoading, AdditionalArgumentTypes... additionalArguments )
{
	// Check if the loading of the content from secondary memroy is disabled
	if ( disableLoading == false )
	{
		// If the directory already exist in secondary memory load its content if needed
		LoadDirectoryContentFromSecondaryMemoryIfNeeded__Private();
	}

	// Wait until allowed to continue, and then let the current thread of execution view the files container
	return ( member_fileWrappersPointers.template View< ReturnType, AdditionalArgumentTypes... >( callable, ForwardUniversalReference< AdditionalArgumentTypes >( additionalArguments )... ) );
}


template< typename ReturnType, typename... AdditionalArgumentTypes >
inline ReturnType Directory::EditFilesWrappers( const Callable< ReturnType ( SequentialDataStructure< FileWrapper* >&, AdditionalArgumentTypes... ) >& callable, const Boolean disableLoading, AdditionalArgumentTypes... additionalArguments )
{
	// Check if the loading of the content from secondary memroy is disabled
	if ( disableLoading == false )
	{
		// If the directory already exist in secondary memory load its content if needed
		LoadDirectoryContentFromSecondaryMemoryIfNeeded__Private();
	}

	// Wait until allowed to continue, and then let the current thread of execution edit the files container
	return ( member_fileWrappersPointers.template Edit< ReturnType, AdditionalArgumentTypes... >( callable, ForwardUniversalReference< AdditionalArgumentTypes >( additionalArguments )... ) );
}


inline SequentialDataStructure< Language::String > Directory::ChildDirectoriesNames()
{
	// Create the callable that will be used to collect the child directories names
	const Callable< SequentialDataStructure< Language::String > ( const SequentialDataStructure< SelfType* >& ) > collectChildDirectoriesNamesCallable( *this, &Directory::CollectNames__Private< SelfType > );

	// Collect all the child directories names of this directory, and return the result
	return ( member_childDirectoriesPointers.template View< SequentialDataStructure< Language::String > >( collectChildDirectoriesNamesCallable ) );
}


inline SequentialDataStructure< Language::String > Directory::FilesNames()
{
	// Create the callable that will be used to collect all the files names
	const Callable< SequentialDataStructure< Language::String > ( const SequentialDataStructure< FileWrapper* >& ) > collectFilesNamesCallable( *this, &Directory::CollectNames__Private< FileWrapper > );

	// Collect all the files names of this directory, and return the result
	return ( member_fileWrappersPointers.template View< SequentialDataStructure< Language::String > >( collectFilesNamesCallable ) );
}


inline void Directory::DisplayContent()
{
	// Collect the child directories names
	SequentialDataStructure< Language::String > childDirectoriesNames = ChildDirectoriesNames();

	// Collect the files names
	SequentialDataStructure< Language::String > filesNames = FilesNames();

	// Display to the user that the child directories names
	User::output << "CHILD DIRECTORIES NAMES :\n" << childDirectoriesNames;

	// Display to the user that the files names
	User::output << "FILES NAMES :\n" << filesNames;
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



inline void Directory::LoadDirectoryContentFromSecondaryMemoryIfNeeded__Private()
{
	// Check if the current directory exist in secondary memory
	if ( member_doesExistInSecondaryMemory == true )
	{
		// Check if the directory content was loaded already from secondary memory
		if ( member_wasDirectoryContentLoadedFromSecondaryMemory.Load() == false )
		{
			// The directory content was not loaded yet from secondary memory

			// Ensure only one thread of execution will continue to load the directory content from the secondary memory, whil all other
			// threads of execution needs to wait
			MultiThread::ScopedSpinWaitLoop ensureOnlyThisThreadOfExecutionWillContinue( &member_spinWaitLoopToAllowThreadsOfExecutionToWaitUntilTheDirectoryContentWasLoadedFromSecondaryMemory );

			// Check again if the directory content was loaded already from secondary memory, this will ensure that only the first thread of
			// execution will pass this point and load the directory content from secondary memory
			if ( member_wasDirectoryContentLoadedFromSecondaryMemory.Load() == false )
			{
				// Load the directory content from secondary memory
				LoadDirectoryContentFromSecondaryMemory__Private();

				// This boolean will be used to verify that this thread of execution loaded the content of the directory
				Boolean verifyThisThreadOfExecutionLoadedTheDirectoryContent = false;

				// Set that the directory content was loaded from secondary memory
				Assert( member_wasDirectoryContentLoadedFromSecondaryMemory.CompareTheActualValueWithTheExpectedAndIfEqualSetTheDesiredValue( verifyThisThreadOfExecutionLoadedTheDirectoryContent, true ) == true, "The value should have been false" );
			}
		}
	}
}


inline void Directory::LoadDirectoryContentFromSecondaryMemory__Private()
{
	// This object will store the directories names
	SequentialDataStructure< Language::String > childDirectoriesNames;

	// This object will store the files names
	SequentialDataStructure< Language::String > filesNames;

	// Convert the path to ascii string
	const Memory::HeapPointer< AsciiCharacter > pathAsAsciiString = TakeResourcesAndLeaveInstanceInDefaultState( member_path.ToAsciiString() );

	// Use the Linux system call to open the required directory
	const SignedInteger32bits directoryDescriptor = Linux::SystemCalls::OpenDirectory( &pathAsAsciiString[0], O_RDONLY );

	// Create a buffer to store the directory entries read from secondary memory
	UnsignedInteger8bits directoryEntries[4096] = {0};

	// Use the Linux system call to load the directory content from secondary memory, and store the number of bytes read
	const UnsignedInteger64bits numberOfBytesRead = Linux::SystemCalls::GetDirectoryEntry( directoryDescriptor, directoryEntries, 4096 );

	// This pointer will store the memory address of the current directory entry
	const struct Linux::linux_dirent64* currentDirectoryEntryPointer = nullptr;

	// Loop on all the directory entries read from secondary memory
	for ( UnsignedInteger64bits byteIndex = 0UL ; byteIndex < numberOfBytesRead ; byteIndex += ((const struct Linux::linux_dirent64*)( directoryEntries + byteIndex ))->member_size )
	{
		// Set the current directory entry
		currentDirectoryEntryPointer = reinterpret_cast< const struct Linux::linux_dirent64* >( directoryEntries + byteIndex );

		// Switch case structure to choose if the current entry is a file or a directory
		switch ( currentDirectoryEntryPointer->member_fileType )
		{
			// File
			case DT_REG:
			{
				// Add the file name
				filesNames.InsertSingleElementAtTheEnd( TakeResourcesAndLeaveInstanceInDefaultState( Language::String( currentDirectoryEntryPointer->member_fileName ) ) );

				// Break the switch case to move to the next directory entry
				break;
			}

			// Directory
			case DT_DIR:
			{
				// Check if the directory name is "." and ".." than just skip it
				if ( currentDirectoryEntryPointer->member_fileName[0] == '.' )
				{
					if ( currentDirectoryEntryPointer->member_fileName[1] == 0 || ( ( currentDirectoryEntryPointer->member_fileName[1] == '.' ) && ( currentDirectoryEntryPointer->member_fileName[2] == 0 ) ) )
					{
						// The current directory is either "." or ".." then nothing needs to be done
						break;
					}
				}

				// Add the directory name
				childDirectoriesNames.InsertSingleElementAtTheEnd( TakeResourcesAndLeaveInstanceInDefaultState( Language::String( currentDirectoryEntryPointer->member_fileName ) ) );

				// Break the switch case to move to the next directory entry
				break;
			}

			case DT_BLK:
			case DT_CHR:
			case DT_FIFO:
			case DT_LNK:
			case DT_SOCK:
			case DT_UNKNOWN:
			{
				break;
			}
			
			default:
			{
				ThrowException( "The directory entry contains an entry which is not a file or directory" );
			}
		}
	}

	// Check if there are child directories
	if ( childDirectoriesNames.Size() > 0UL )
	{
		// There are child directories

		// Create a callable to the add child directories from secondary memory method, and bind it with this instance
		const Callable< void ( SequentialDataStructure< SelfType* >&, SequentialDataStructure< Language::String >&& ) > addChildDirectoriesFromSecondaryMemory( *this, &Directory::AddChildDirectoriesFromSecondaryMemory__Private );

		// Insert all the child directories loaded from secondary memory
		member_childDirectoriesPointers.template Edit< void, SequentialDataStructure< Language::String >&& >( addChildDirectoriesFromSecondaryMemory, TakeResourcesAndLeaveInstanceInDefaultState( childDirectoriesNames ) );
	}

	// Check if there are files
	if ( filesNames.Size() > 0UL )
	{
		// There are files

		// Create a callable to the add child directories from secondary memory method, and bind it with this instance
		const Callable< void ( SequentialDataStructure< FileWrapper* >&, SequentialDataStructure< Language::String >&& ) > addFilesFromSecondaryMemory( *this, &Directory::AddFilesFromSecondaryMemory__Private );

		// Insert all the files loaded from secondary memory
		member_fileWrappersPointers.template Edit< void, SequentialDataStructure< Language::String >&& >( addFilesFromSecondaryMemory, TakeResourcesAndLeaveInstanceInDefaultState( filesNames ) );
	}
}


inline void Directory::AddChildDirectoriesFromSecondaryMemory__Private( SequentialDataStructure< SelfType* >& childDirectoriesPointers, SequentialDataStructure< Language::String >&& childDirectoriesNames )
{
	// This pointer will store the memory address of the new created tree directory
	SelfType* currentDirectoryPointer = nullptr;

	// Loop on all the child directories names loaded from secondary memory
	for ( UnsignedInteger64bits index = 0UL ; index < childDirectoriesNames.Size() ; ++index )
	{
		// Create a child directory, and store the memory address of it
		currentDirectoryPointer = Memory::MainMemoryManager::template AllocateAndConstruct< Directory, Path&&, SelfType*, Boolean >( TakeResourcesAndLeaveInstanceInDefaultState( Path( member_path, TakeResourcesAndLeaveInstanceInDefaultState( childDirectoriesNames[ index ] ), true ) ), this, true ).Acquire();

		// Add the child directory pointer
		childDirectoriesPointers.InsertSingleElementAtTheEnd( currentDirectoryPointer );
	}
}


inline void Directory::AddFilesFromSecondaryMemory__Private( SequentialDataStructure< FileWrapper* >& filesPointers, SequentialDataStructure< Language::String >&& filesNames )
{
	// This pointer will store the memory address of the new created file directory
	FileWrapper* currentFileWrapperPointer = nullptr;

	// Loop on all the files names loaded from secondary memory
	for ( UnsignedInteger64bits index = 0UL ; index < filesNames.Size() ; ++index )
	{
		// Create a file directory, and store the memory address of it
		currentFileWrapperPointer = Memory::MainMemoryManager::template AllocateAndConstruct< FileWrapper, Path&&, Boolean >( TakeResourcesAndLeaveInstanceInDefaultState( Path( member_path, TakeResourcesAndLeaveInstanceInDefaultState( filesNames[ index ] ) ) ), true ).Acquire();

		// Add the file directory pointer
		filesPointers.InsertSingleElementAtTheEnd( currentFileWrapperPointer );
	}
}


template< typename DirectoryOrFileWrapperType >
inline SequentialDataStructure< Language::String > Directory::CollectNames__Private( const SequentialDataStructure< DirectoryOrFileWrapperType* >& pointers ) const
{
	// This object will store the names
	SequentialDataStructure< Language::String > names( MemoryHandlerName::Vector, pointers.Size() );

	// Loop on all the pointers
	for ( UnsignedInteger64bits index = 0UL ; index < pointers.Size() ; ++index )
	{
		// Store the current name
		names[ index ] = pointers[ index ]->Name();
	}

	// Return the names
	return ( names );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	inline void Directory::UnitTest()
	{}

)  //  End of debug tool



}  //  Namespace FileSystem


}  //  Namespace Universe