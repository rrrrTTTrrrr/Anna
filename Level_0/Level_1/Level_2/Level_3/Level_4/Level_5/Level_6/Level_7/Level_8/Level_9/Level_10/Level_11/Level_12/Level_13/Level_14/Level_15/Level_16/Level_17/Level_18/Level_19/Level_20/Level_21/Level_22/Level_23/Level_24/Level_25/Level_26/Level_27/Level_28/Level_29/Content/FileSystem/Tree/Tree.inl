//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline Tree::Tree() :
	member_rootDirectoryPointer( Memory::MainMemoryManager::template AllocateAndDefaultConstruct< Directory >().Acquire() )
{}


inline Tree::~Tree()
{
	// Try catch structure to ensure no exception will propogate from this destructor
    try
    {
	
		// Create the callable that will be used to download from main memory to secondary memory all the file system content
		const Callable< void ( SequentialDataStructure< Directory* >&, Directory* ) > callable( *this, &Tree::DownloadToSecondaryMemoryAndDeleteFromMainMemoryForDestructionRecursively__Private );

	    // Delete all the tree nodes recursively
	    member_rootDirectoryPointer->template EditChildDirectories< void, Directory* >( callable, true, member_rootDirectoryPointer );

		// Delete the root directory from main memory
		Memory::MainMemoryManager::template Done< Directory >( member_rootDirectoryPointer );

    }
    catch ( const Error::Exception& exception )
    {
    	std::cout << exception.ErrorMessage() << std::endl;
    }
}


inline MultiThread::Result Tree::TryToCreatePath( const Path& path )
{
	// Check if the path points to the root directory, then return that it is already exist
	if ( path.Size() == 1UL )
	{
		// The path points to the root directory
		return ( MultiThread::Result::AlreadyExist );
	}
	
	// Perfrom a recursive call, and try to create the given path. Finally return if the file or directory the path points too were created or 
	// already existed
	return ( TryToCreatePathRecursive__Private( path, 0UL, member_rootDirectoryPointer ) );
}


inline MultiThread::Result Tree::TryToRemovePath( const Path& path )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	Assert( path.Size() > 1UL, "The root directory can not removed" );
	
	// Perfrom a recursive call, and try to remove the given path. Finally return if the file or directory the path points too were created or 
	// did not exist
	return ( TryToRmovePathRecursive__Private( path, 0UL, member_rootDirectoryPointer ) );
}


// template< typename... AdditionalArgumentTypes >
// inline MultiThread::Result Tree::TryToViewFile( const Path& filePath, const Callable< void ( const FileWrapper&, AdditionalArgumentTypes... ) >& callable, AdditionalArgumentTypes... additionalArguments )
// {
// 	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
// 	// instance is ready to be used
// 	Assert( filePath.DoesPointToFile() == true, "The path does not lead to a file" );

// 	// Try to locate the file, and if it exists execute the required operation on it. Finally return the information of the process to
// 	// the caller
// 	return ( TryToPerformActionOnFileRecursive__Private< AdditionalArgumentTypes... >( filePath, 1UL, member_rootDirectoryPointer, callable, ForwardUniversalReference< AdditionalArgumentTypes >( additionalArguments )... ) );
// }


// template< typename ReturnType, typename... AdditionalArgumentTypes >
// inline MultiThread::Result Tree::TryToViewFile( const Path& filePath, const Callable< ReturnType ( const FileWrapper&, AdditionalArgumentTypes... ) >& callable, ReturnType& returnValue, AdditionalArgumentTypes... additionalArguments )
// {
// 	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
// 	// instance is ready to be used
// 	Assert( filePath.DoesPointToFile() == true, "The path does not lead to a file" );

// 	// Try to locate the file, and if it exists execute the required operation on it. Finally return the information of the process to
// 	// the caller
// 	return ( TryToPerformActionOnFileRecursive__Private< ReturnType, AdditionalArgumentTypes... >( filePath, 1UL, member_rootDirectoryPointer, callable, returnValue, ForwardUniversalReference< AdditionalArgumentTypes >( additionalArguments )... ) );
// }


// template< typename... AdditionalArgumentTypes >
// inline MultiThread::Result Tree::TryToEditFile( const Path& filePath, const Callable< void ( FileWrapper&, AdditionalArgumentTypes... ) >& callable, AdditionalArgumentTypes... additionalArguments )
// {
// 	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
// 	// instance is ready to be used
// 	Assert( filePath.DoesPointToFile() == true, "The path does not lead to a file" );

// 	// Try to locate the file, and if it exists execute the required operation on it. Finally return the information of the process to
// 	// the caller
// 	return ( TryToPerformActionOnFileRecursive__Private< AdditionalArgumentTypes... >( filePath, 1UL, member_rootDirectoryPointer, callable, ForwardUniversalReference< AdditionalArgumentTypes >( additionalArguments )... ) );
// }


// template< typename ReturnType, typename... AdditionalArgumentTypes >
// inline MultiThread::Result Tree::TryToEditFile( const Path& filePath, const Callable< ReturnType ( FileWrapper&, AdditionalArgumentTypes... ) >& callable, ReturnType& returnValue, AdditionalArgumentTypes... additionalArguments )
// {
// 	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
// 	// instance is ready to be used
// 	Assert( filePath.DoesPointToFile() == true, "The path does not lead to a file" );

// 	// Try to locate the file, and if it exists execute the required operation on it. Finally return the information of the process to
// 	// the caller
// 	return ( TryToPerformActionOnFileRecursive__Private< ReturnType, AdditionalArgumentTypes... >( filePath, 1UL, member_rootDirectoryPointer, callable, returnValue, ForwardUniversalReference< AdditionalArgumentTypes >( additionalArguments )... ) );
// }


// template< typename... AdditionalArgumentTypes >
// inline void Tree::ViewAllFiles( const Callable< Boolean ( const File&, const Path&, AdditionalArgumentTypes... ) >& callable, AdditionalArgumentTypes... additionalArguments )
// {
// 	// Perform a recursive call on all the files and execute the given action on them
// 	ViewAllFilesRecursive__Private( member_rootDirectoryPointer, callable, ForwardUniversalReference< AdditionalArgumentTypes >( additionalArguments )... );
// }


// template< typename... AdditionalArgumentTypes >
// inline void Tree::EditAllFiles( const Callable< Boolean ( File&, const Path&, AdditionalArgumentTypes... ) >& callable, AdditionalArgumentTypes... additionalArguments )
// {
// 	// Perform a recursive call on all the files and execute the given action on them
// 	PerformActionOnAllFilesRecursive__Private( member_rootDirectoryPointer, callable, ForwardUniversalReference< AdditionalArgumentTypes >( additionalArguments )... );
// }



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



inline void Tree::DownloadToSecondaryMemoryAndDeleteFromMainMemoryForDestructionRecursively__Private( SequentialDataStructure< Directory* >& childDirectoriesPointers, Directory* const currentDirectoryPointer )
{
	// Check if the current directory does not exist in secondary memory
	if ( currentDirectoryPointer->DoesExistInSecondaryMemory() == false )
	{
		// The directory does not exist in secondary memory

		// This reference will store the directory path
		const Path& directoryPath = currentDirectoryPointer->GetPath();

		// Create the directory on secondary memory
		Linux::SystemCalls::CreateDirectory( directoryPath.ToAsciiString().Get(), S_IRWXU );
	}

	// Create the callable that will be used to download from main memory to secondary memory all the file system content
	const Callable< void ( SequentialDataStructure< FileWrapper* >& ) > callableToDownloadDirectoryFilesContent( *this, &Tree::DownloadToSecondaryMemoryAllFilesOfDirectoryForDestructionRecursively__Private );

	// Pass on all the files of the current directory and download to secondary memory all the required files. Finally delete them all from
	// main memory
	currentDirectoryPointer->template EditFilesWrappers< void >( callableToDownloadDirectoryFilesContent, true );

	// This object will store the number of child directories
	const LargestUnsignedInteger numberOfChildeDirectories = childDirectoriesPointers.Size();

	// Create the callable that will be used to download from main memory to secondary memory all the file system content
	const Callable< void ( SequentialDataStructure< Directory* >&, Directory* ) > callableToPerformRecursiveCall( *this, &Tree::DownloadToSecondaryMemoryAndDeleteFromMainMemoryForDestructionRecursively__Private );

	// Loop on all the child directories pointers
	for ( LargestUnsignedInteger index = 0UL ; index < numberOfChildeDirectories ; ++index )
	{
		// Perform a recursive call on the current child directory
		childDirectoriesPointers[ index ]->template EditChildDirectories< void, Directory* >( callableToPerformRecursiveCall, true, childDirectoriesPointers[ index ] );

		// Delete the current child directory from main memory
		Memory::MainMemoryManager::template Done< Directory >( childDirectoriesPointers[ index ] );
	}
}


inline void Tree::DownloadToSecondaryMemoryAllFilesOfDirectoryForDestructionRecursively__Private( SequentialDataStructure< FileWrapper* >& filesWrappersPointers )
{
	// This object will store the number of files
	const LargestUnsignedInteger numberOfFiles = filesWrappersPointers.Size();

	// Loop on all the existing files in the container
	for ( LargestUnsignedInteger index = 0UL ; index < numberOfFiles ; ++index )
	{
		// Download the file from main memory to secondary memory if needed, and then delete it from main memory
		Memory::MainMemoryManager::template Done< FileWrapper >( filesWrappersPointers[ index ] );
	}
}


inline MultiThread::Result Tree::TryToCreatePathRecursive__Private( const Path& path, const LargestUnsignedInteger pathIndex, Directory* const currentDirectoryPointer )
{
	// This object will store the result of the function, since it is used by multiple threads of execution. It will store if the directory was
	// created or already existed
	MultiThread::Result result = MultiThread::Result::Success;

	// Create the callable that will be used to search for the required child directory and if it does not exist create it
	const Callable< Memory::Tuple< Directory*, Boolean > ( SequentialDataStructure< Directory* >&, Directory*, const Path&, LargestUnsignedInteger ) > searchForChildDirectoryAndIfDoesNotExistCreateItCallable( *this, &Tree::SearchForChildDirectoryAndIfDoesNotExistCreateIt__Private );

	// Check if this is the last directory in the path before the directory or file the path points too. This is the condition to stop the
	// rucursion calls
	if ( pathIndex == path.Size() - 2UL )
	{
		// This is the last directory in the path before the directory or file the path points too

		// Check if the path points to a file
		if ( path.DoesPointToFile() == true )
		{
			// The path points to a file

			// Create the callable that will be used to try to create the file, and store the memory address of the file instance
			const Callable< MultiThread::Result ( SequentialDataStructure< FileWrapper* >&, const Path& ) > searchForFileAndIfDoesNotExistCreateItCallable( *this, &Tree::SearchForFileAndIfDoesNotExistCreateIt__Private );

			// Try to create the file, and store the memory address of the file instance. Finally set if the file was created or already existed
			result = currentDirectoryPointer->template EditFilesWrappers< MultiThread::Result, const Path& >( searchForFileAndIfDoesNotExistCreateItCallable, false, path );
		}
		else
		{
			// The path points to a directory

			// Try to create the last directory in the path, and store the memory address of the directory instance
			const Memory::Tuple< Directory*, Boolean > lastDirectoryPointerAndIfItWasJustCreatedTuple = currentDirectoryPointer->template EditChildDirectories< Memory::Tuple< Directory*, Boolean >, Directory*, const Path&, LargestUnsignedInteger >( searchForChildDirectoryAndIfDoesNotExistCreateItCallable, false, currentDirectoryPointer, path, pathIndex + 1UL );

			// Notify that the current thread of execution has finished using the directory
			lastDirectoryPointerAndIfItWasJustCreatedTuple.template Entry< POINTER_TO_DIRECTORY >()->Done();

			// Check the directory was created or already existed
			if ( lastDirectoryPointerAndIfItWasJustCreatedTuple.template Entry< WAS_DIRECTORY_CREATED >() == false )
			{
				// The last directory in the path already existed

				// Set that the directory already existed
				result = MultiThread::Result::AlreadyExist;
			}
		}

		// Return to the user if the directory was created or already existed
		return ( result );
	}

	// Try to create the current directory in the path, and store the memory address of the directory instance
	const Memory::Tuple< Directory*, Boolean > nextDirectoryPointerAndIfItWasJustCreatedTuple = currentDirectoryPointer->template EditChildDirectories< Memory::Tuple< Directory*, Boolean >, Directory*, const Path&, LargestUnsignedInteger >( searchForChildDirectoryAndIfDoesNotExistCreateItCallable, false, currentDirectoryPointer, path, pathIndex + 1UL );

	// Recursive call to advance on the next directory in the path
	result = TryToCreatePathRecursive__Private( path, pathIndex + 1UL, nextDirectoryPointerAndIfItWasJustCreatedTuple.template Entry< POINTER_TO_DIRECTORY >() );

	// Notify that the current thread of execution has finished using the directory
	nextDirectoryPointerAndIfItWasJustCreatedTuple.template Entry< POINTER_TO_DIRECTORY >()->Done();

	// Return to the caller if the directory was created or already existed
	return ( result );
}


inline Memory::Tuple< Directory*, Boolean > Tree::SearchForChildDirectoryAndIfDoesNotExistCreateIt__Private( SequentialDataStructure< Directory* >& childDirectoriesPointers, Directory* const parentDirectoryPointer, const Path& path, const LargestUnsignedInteger pathIndex )
{
	// This pointer will store the child directory memory address
	Directory* childDirectoryPointer = nullptr;

	// This boolean will store if the directory already existed or it was created
	Boolean wasDirectoryCreated = false;

	// This object will store the number of child directories
	const LargestUnsignedInteger numberOfChildeDirectories = childDirectoriesPointers.Size();

	// This string will store the name of the required directory in the path
	const Language::String& directoryName = path[ pathIndex ];

	// Loop on all the existing child directories
	for ( LargestUnsignedInteger index = 0UL ; index < numberOfChildeDirectories ; ++index )
	{
		// Check if the current child directory has the required name
		if ( childDirectoriesPointers[ index ]->Name() == directoryName )
		{
			// The required child directory was located

			// Store the memory address of the child directory
			childDirectoryPointer = childDirectoriesPointers[ index ];

			// The required child directory was located break the loop
			break;
		}
	}

	// Check if the child directory does not exist
	if ( childDirectoryPointer == nullptr )
	{
		// The child directory does not exist

		// Create the child directory and insert it to the child directories container
		childDirectoriesPointers.InsertSingleElementAtTheBeginning( Memory::MainMemoryManager::template AllocateAndConstruct< Directory >( TakeResourcesAndLeaveInstanceInDefaultState( Path( path, pathIndex + 1UL ) ), parentDirectoryPointer ).Acquire() );

		// Store the memory address of the child directory
		childDirectoryPointer = childDirectoriesPointers.First();

		// Set the boolean to true, to notify that the child directory was created
		wasDirectoryCreated = true;
	}

	// Notify other threads of execution that the current thread of execution will use the directory
	childDirectoryPointer->Utilize();

	// Return a tuple with the pointer to the directory, and a boolean set to true, to notify that the directory was created
	return ( Memory::Tuple< Directory*, Boolean >( childDirectoryPointer, wasDirectoryCreated ) );
}


inline MultiThread::Result Tree::SearchForFileAndIfDoesNotExistCreateIt__Private( SequentialDataStructure< FileWrapper* >& filesWrappersPointers, const Path& path )
{
	// This object will store the number of files
	const LargestUnsignedInteger numberOfFiles = filesWrappersPointers.Size();

	// This reference will store the name of file the path points to
	const Language::String& namePathLeadsTo = path.NamePathLeadsTo();

	// Loop on all the existing files
	for ( LargestUnsignedInteger index = 0UL ; index < numberOfFiles ; ++index )
	{
		// Check if the current file has the required name, then this means that a file with the required name already exist, return that
		// iformation to the caller
		ReturnValueIfExpressionIsTrue( ( filesWrappersPointers[ index ]->Name() == namePathLeadsTo ), MultiThread::Result::AlreadyExist );
	}

	// The file does not yet exist

	// Create the file wrapper and insert it to the container
	filesWrappersPointers.InsertSingleElementAtTheBeginning( Memory::MainMemoryManager::template AllocateAndConstruct< FileWrapper >( path ).Acquire() );

	// The file was successfully created, return this information to the caller
	return ( MultiThread::Result::Success );
}


inline MultiThread::Result Tree::TryToRmovePathRecursive__Private( const Path& path, const LargestUnsignedInteger pathIndex, Directory* const currentDirectoryPointer )
{
	// This object will store the result of the function, since it is used by multiple threads of execution. It will store if the directory was
	// created or already existed
	MultiThread::Result result = MultiThread::Result::Success;

	// Create the callable that will be used to search for the required child directory and if it does not exist create it
	const Callable< Memory::Tuple< Directory*, Boolean > ( SequentialDataStructure< Directory* >&, Directory*, const Path&, LargestUnsignedInteger ) > searchForChildDirectoryAndIfDoesNotExistCreateItCallable( *this, &Tree::SearchForChildDirectoryAndIfDoesNotExistCreateIt__Private );

	// Check if this is the last directory in the path before the directory or file the path points too. This is the condition to stop the
	// rucursion calls
	if ( pathIndex == path.Size() - 2UL )
	{
		// This is the last directory in the path before the directory or file the path points too

		// Check if the path points to a file
		if ( path.DoesPointToFile() == true )
		{
			// The path points to a file

			// Create the callable that will be used to try removing the file
			const Callable< MultiThread::Result ( SequentialDataStructure< FileWrapper* >&, const Path& ) > callable( *this, &Tree::TryToRemoveFileWrapper__Private );

			// Try to remove the file
			return ( currentDirectoryPointer->template EditFilesWrappers< MultiThread::Result, const Path& >( callable, false, path ) );
		}
		else
		{
			// The path points to a directory

			// Create the callable that will be used to try removing all the child directories
			const Callable< MultiThread::Result ( SequentialDataStructure< Directory* >&, const Path& ) > callable( *this, &Tree::TryToRemoveAllDirectoryContent__Private );

			// Try to remove all the directory child directories, and to delete it from secondary memory
			result = currentDirectoryPointer->template EditChildDirectories< MultiThread::Result, const Path& >( callable, false, path );

			// Check if there is no other thread of execution using the directory in the entry
			if ( result == MultiThread::Result::UtilizedByOtherThreadsOfExecution || currentDirectoryPointer->IsCurrentlyUtilizedByOtherThreadsOfExecution() == true )
			{
				// There are other thread of execution using the directory in the entry

				// Return to the caller that the directory can not be removed currently
				return ( MultiThread::Result::UtilizedByOtherThreadsOfExecution );
			}

			// Now that all the directory content was removed, and it was removed from secondary memory, delete it also from main memory
			Memory::MainMemoryManager::template Done< Directory >( currentDirectoryPointer );

			// Return that the directory was successfully removed
			return ( MultiThread::Result::Success );
		}

		// Return to the user if the directory was created or already existed
		return ( result );
	}

	// Try to create the current directory in the path, and store the memory address of the directory instance
	const Memory::Tuple< Directory*, Boolean > nextDirectoryPointerAndIfItWasJustCreatedTuple = currentDirectoryPointer->template EditChildDirectories< Memory::Tuple< Directory*, Boolean >, Directory*, const Path&, LargestUnsignedInteger >( searchForChildDirectoryAndIfDoesNotExistCreateItCallable, false, currentDirectoryPointer, path, pathIndex + 1UL );

	// Recursive call to advance on the next directory in the path
	result = TryToCreatePathRecursive__Private( path, pathIndex + 1UL, nextDirectoryPointerAndIfItWasJustCreatedTuple.template Entry< POINTER_TO_DIRECTORY >() );

	// Notify that the current thread of execution has finished using the directory
	nextDirectoryPointerAndIfItWasJustCreatedTuple.template Entry< POINTER_TO_DIRECTORY >()->Done();

	// Return to the caller if the directory was created or already existed
	return ( result );












	// Check if the recursive calls has reached the last entry of the path
	if ( pathIndex == path.Size() - 1UL )
	{
		// The recursive calls has reached the last entry of the path

		// Check if the path point to a file or directory
		if ( path.DoesPointToFile() == true )
		{
			// The path point to a file

			// Create the callable that will be used to try removing the file
			const Callable< MultiThread::Result ( SequentialDataStructure< FileWrapper* >&, const Path& ) > callable( *this, &Tree::TryToRemoveFileWrapper__Private );

			// Try to remove the file
			return ( currentDirectoryPointer->template EditFilesWrappers< MultiThread::Result, const Path& >( callable, false, path ) );
		}

		// The path point to a directory

		// Create the callable that will be used to try removing all the child directories
		const Callable< MultiThread::Result ( SequentialDataStructure< Directory* >&, const Path& ) > callable( *this, &Tree::TryToRemoveAllDirectoryContent__Private );

		// Try to remove all the directory child directories, and to delete it from secondary memory
		const MultiThread::Result result = currentDirectoryPointer->template EditChildDirectories< MultiThread::Result, const Path& >( callable, false, path );

		// Check if there is no other thread of execution using the directory in the entry
		if ( result == MultiThread::Result::UtilizedByOtherThreadsOfExecution || currentDirectoryPointer->IsCurrentlyUtilizedByOtherThreadsOfExecution() == true )
		{
			// There are other thread of execution using the directory in the entry

			// Return to the caller that the directory can not be removed currently
			return ( MultiThread::Result::UtilizedByOtherThreadsOfExecution );
		}

		// Now that all the directory content was removed, and it was removed from secondary memory, delete it also from main memory
		Memory::MainMemoryManager::template Done< Directory >( currentDirectoryPointer );

		// Return that the directory was successfully removed
		return ( MultiThread::Result::Success );
	}

	// Create the callable that will be used to try and getting the pointer of the next directory in the path
	const Callable< Directory* ( const SequentialDataStructure< Directory* >&, const Path&, LargestUnsignedInteger ) > callable( *this, &Tree::TryToGetPointerChildDirectory__Private );

	// Try to get a pointer to the next directory in the path
	Directory* const nextDirectoryPointer = currentDirectoryPointer->template ViewChildDirectories< Directory*, const Path&, LargestUnsignedInteger >( callable, false, path, pathIndex );

	// Check if the next directory in the path exist, and if not return that information to the caller
	ReturnValueIfPointerIsNull( nextDirectoryPointer, MultiThread::Result::DoesNotExist );

	// Perform a recursice call on the next directory
	const MultiThread::Result result = TryToRmovePathRecursive__Private( path, pathIndex + 1UL, nextDirectoryPointer );

	// Notify that the current thread of execution has finished using the directory
	nextDirectoryPointer->Done();

	// Return to the caller if the directory or file were successfully removed
	return ( result );
}


inline Directory* Tree::TryToGetPointerChildDirectory__Private( const SequentialDataStructure< Directory* >& childDirectoriesPointers, const Path& path, const LargestUnsignedInteger pathIndex )
{
	// This object will store the number of child directories
	const LargestUnsignedInteger numberOfChildeDirectories = childDirectoriesPointers.Size();

	// Loop on all the existing child directories
	for ( LargestUnsignedInteger index = 0UL ; index < numberOfChildeDirectories ; ++index )
	{
		// Check if the current child directory has the required name
		if ( childDirectoriesPointers[ index ]->Name() == path[ pathIndex ] )
		{
			// The required child directory was located

			// Notify other threads of execution that the current thread of execution will use the directory
			childDirectoriesPointers[ index ]->Utilize();

			// Return the memory address for the required directory
			return ( childDirectoriesPointers[ index ] );
		}
	}

	// The child directory does not exist, return NULL
	return ( nullptr );
}


inline MultiThread::Result Tree::TryToRemoveFileWrapper__Private( SequentialDataStructure< FileWrapper* >& filesWrappersPointers, const Path& path )
{
	// This object will store the number of files
	const LargestUnsignedInteger numberOfFiles = filesWrappersPointers.Size();

	// Loop on all the existing entries in the container
	for ( LargestUnsignedInteger index = 0UL ; index < numberOfFiles ; ++index )
	{
		// Check if the current entry has the required name
		if ( filesWrappersPointers[ index ]->Name() == path.NamePathLeadsTo() )
		{
			// The required entry was located

			// Check if there is no other thread of execution using the file in the entry
			if ( filesWrappersPointers[ index ]->IsCurrentlyUtilizedByOtherThreadsOfExecution() == true )
			{
				// There are other thread of execution using the file in the entry

				// Return to the caller that the file can not be removed currently
				return ( MultiThread::Result::UtilizedByOtherThreadsOfExecution );
			}

			// There are no other threads of execution using the file in the entry

			// Delete the file from main and secondary memory if it exists there
			DeleteFileFromMainAndSecondaryMemoryIfExistsThere__Private( filesWrappersPointers[ index ] );

			// Remove the pointer from the files pointers container
			filesWrappersPointers.Remove( index, 1UL );

			// Return that the file was successfully removed
			return ( MultiThread::Result::Success );
		}
	}

	// Return that the file does not exist
	return ( MultiThread::Result::DoesNotExist );
}


inline void Tree::DeleteFileFromMainAndSecondaryMemoryIfExistsThere__Private( FileWrapper* const fileWrapperPointer )
{
	// Check if the file exist in secondary memory
	if ( fileWrapperPointer->DoesExistInSecondaryMemory() == true )
	{
		// The file exist in secondary memory

		// This reference will store the file path
		const Path& filePath = fileWrapperPointer->GetPath();

		// Delete the file from secondary memory if exist
		Linux::SystemCalls::DeleteFile( filePath.ToAsciiString().Get() );
	}

	// Delete the file from main memory
	Memory::MainMemoryManager::template Done< FileWrapper >( fileWrapperPointer );
}


inline MultiThread::Result Tree::TryToRemoveAllDirectoryContent__Private( SequentialDataStructure< Directory* >& childDirectoriesPointers, const Path& path )
{
	// This object will store the number of child directories
	const LargestUnsignedInteger numberOfChildeDirectories = childDirectoriesPointers.Size();

	// Loop on all the existing entries in the container
	for ( LargestUnsignedInteger index = 0UL ; index < numberOfChildeDirectories ; ++index )
	{
		// Check if the current entry has the required name
		if ( childDirectoriesPointers[ index ]->Name() == path.NamePathLeadsTo() )
		{
			// The required child directory was located

			// Check if there is no other thread of execution using the directory in the entry
			if ( childDirectoriesPointers[ index ]->IsCurrentlyUtilizedByOtherThreadsOfExecution() == true )
			{
				// There are other thread of execution using the directory in the entry

				// Return to the caller that the directory can not be removed currently
				return ( MultiThread::Result::UtilizedByOtherThreadsOfExecution );
			}

			// There are no other threads of execution using the directory in the entry

			// Create the callable that will remove the directory and all its content from main and secondary memory
			const Callable< void ( SequentialDataStructure< Directory* >&, Directory* ) > callable( *this, &Tree::RemoveChildDirectoriesRecursively__Private );

			// Remove the directory and all its content from main and secondary memory
			childDirectoriesPointers[ index ]->template EditChildDirectories< void, Directory* >( callable, false, childDirectoriesPointers[ index ] );

			// Now that all the child directories are empty, and were deleted from secondary memory, delete them also from main memory
			Memory::MainMemoryManager::template Done< Directory >( childDirectoriesPointers[ index ] );
		}
	}

	// Return that the directory content was successfully removed
	return ( MultiThread::Result::Success );
}


inline void Tree::RemoveChildDirectoriesRecursively__Private( SequentialDataStructure< Directory* >& childDirectoriesPointers, Directory* const currentDirectoryPointer )
{
	// This object will store the number of child directories
	const LargestUnsignedInteger numberOfChildeDirectories = childDirectoriesPointers.Size();

	// Create the callable that will remove the directory and all its content from main and secondary memory
	const Callable< void ( SequentialDataStructure< Directory* >&, Directory* ) > callableToRemoveChildDirectoriesRecursively( *this, &Tree::RemoveChildDirectoriesRecursively__Private );

	// Loop on all the child directories pointers
	for ( LargestUnsignedInteger index = 0UL ; index < numberOfChildeDirectories ; ++index )
	{
		// Perform a recursive call on the current child directory
		childDirectoriesPointers[ index ]->template EditChildDirectories< void, Directory* >( callableToRemoveChildDirectoriesRecursively, false, childDirectoriesPointers[ index ] );

		// When the control flow reaches here the current child directory is empty and was removed from secondary memory

		// Delete the child directory from main memory
		Memory::MainMemoryManager::template Done< Directory >( childDirectoriesPointers[ index ] );
	}

	// When the control flow reaches here the current directory does not have any child directories anymore

	// Create the callable that will be used to try removing the file
	const Callable< void ( SequentialDataStructure< FileWrapper* >& ) > callableRemoveAllFilesInTheDirectory( *this, &Tree::RemoveAllFilesInTheDirectory__Private );

	// Remove all the files of the directory
	currentDirectoryPointer->template EditFilesWrappers< void >( callableRemoveAllFilesInTheDirectory, false );

	// Now the directory does not contain any child directroies or files

	// Check if the file exist in secondary memory
	if ( currentDirectoryPointer->DoesExistInSecondaryMemory() == true )
	{
		// This reference will store the directory path
		const Path& directoryPath = currentDirectoryPointer->GetPath();

		// Delete the directory from secondary memory
		Linux::SystemCalls::DeleteEmptyDirectory( directoryPath.ToAsciiString().Get() );
	}
}


inline void Tree::RemoveAllFilesInTheDirectory__Private( SequentialDataStructure< FileWrapper* >& filesWrappersPointers )
{
	// This object will store the number of files
	const LargestUnsignedInteger numberOfFiles = filesWrappersPointers.Size();

	// Loop on all the existing entries in the container
	for ( LargestUnsignedInteger index = 0UL ; index < numberOfFiles ; ++index )
	{
		// Delete the file from main and secondary memory if it exists there
		DeleteFileFromMainAndSecondaryMemoryIfExistsThere__Private( filesWrappersPointers[ index ] );
	}
}


// template< typename CallableType, typename... AdditionalArgumentTypes >
// inline MultiThread::Result Tree::TryToPerformActionOnFileRecursive__Private( const Path& filePath, const LargestUnsignedInteger pathIndex, Directory* const currentDirectoryPointer, CallableType&& callable, AdditionalArgumentTypes... additionalArguments ) const
// {
// 	// Check if recursive calls reached the last entry of the path that contains the file name
// 	if ( pathIndex == filePath.Size() - 1UL )
// 	{
// 		// The last entry of the path that contains the file name

// 		// Try to get a pointer to the required file node
// 		FileWrapper* const FileWrapperPointer = currentDirectoryPointer->template ViewFilesWrappers< FileWrapper* ( const SequentialDataStructure< FileWrapper* >&, const Path& ), FileWrapper*, const Path& >( &Tree::SearchForFileAndIfExistReturnPointerToIt__Private, filePath );

// 		// Check if the required file exist, if it does not return that information to the caller
// 		ReturnValueIfPointerIsNull( FileWrapperPointer, MultiThread::Result::DoesNotExist );

// 		// Perform the action on the file
// 		callable( FileWrapperPointer->File(), arguments... );

// 		// Notify that the current thread of execution has finished using the file
// 		FileWrapperPointer->Done();

// 		// The file was located and the operation was successfully executed on it, return that information to the caller
// 		return ( MultiThread::Result::Success );
// 	}

// 	// Try to get a pointer to the next directory in the path
// 	Directory* const nextDirectoryPointer = currentDirectoryPointer->template ViewChildDirectories< Directory* ( const SequentialDataStructure< Directory* >&, const Path&, LargestUnsignedInteger ), const Path&, LargestUnsignedInteger >( &Tree::TryToGetPointerChildDirectory__Private, filePath, pathIndex );

// 	// Check if the next directory in the path exist, and if not return that information to the caller
// 	ReturnValueIfPointerIsNull( nextDirectoryPointer, nullptr );

// 	// Perform a recursice call on the next directory
// 	MultiThread::Result result = TryToRmovePathRecursive__Private( path, pathIndex + 1UL, nextDirectoryPointer );

// 	// Notify that the current thread of execution has finished using the directory
// 	nextDirectoryPointer->Done();

// 	// Return to the caller if the file exist and the action was successfully executed on it
// 	return ( result );
// }


// template< typename CallableType, typename ReturnType, typename... ArgumentTypes >
// inline MultiThread::Result Tree::TryToPerformActionOnFileRecursive__Private( const Path& filePath, const LargestUnsignedInteger pathIndex, Directory* const currentDirectoryPointer, CallableType&& callable, ReturnType& returnValue, ArgumentTypes... arguments ) const
// {
// 	// Check if recursive calls reached the last entry of the path that contains the file name
// 	if ( pathIndex == filePath.Size() - 1UL )
// 	{
// 		// The last entry of the path that contains the file name

// 		// Try to get a pointer to the required file
// 		FileWrapper* const FileWrapperPointer = currentDirectoryPointer->template ViewFiles< FileWrapper* ( const SequentialDataStructure< FileWrapper* >&, const Path& ), FileWrapper*, const Path& >( &Tree::SearchForFileAndIfExistReturnPointerToIt__Private, filePath );

// 		// Check if the required file exist, if it does not return that information to the caller
// 		ReturnValueIfPointerIsNull( FileWrapperPointer, MultiThread::Result::DoesNotExist );

// 		// Perform the action on the file and store the result
// 		returnValue = callable( FileWrapperPointer->File(), arguments... );

// 		// Notify that the current thread of execution has finished using the file
// 		FileWrapperPointer->Done();

// 		// The file was located and the operation was successfully executed on it, return that information to the caller
// 		return ( MultiThread::Result::Success );
// 	}

// 	// Try to get a pointer to the next directory in the path
// 	Directory* const nextDirectoryPointer = currentDirectoryPointer->template ViewChildDirectories< Directory* ( const SequentialDataStructure< Directory* >&, const Path&, LargestUnsignedInteger ), const Path&, LargestUnsignedInteger >( &Tree::TryToGetPointerChildDirectory__Private, filePath, pathIndex );

// 	// Check if the next directory in the path exist, and if not return that information to the caller
// 	ReturnValueIfPointerIsNull( nextDirectoryPointer, nullptr );

// 	// Perform a recursice call on the next directory
// 	MultiThread::Result result = TryToRmovePathRecursive__Private( path, pathIndex + 1UL, nextDirectoryPointer );

// 	// Notify that the current thread of execution has finished using the directory
// 	nextDirectoryPointer->Done();

// 	// Return to the caller if the file exist and the action was successfully executed on it
// 	return ( result );
// }


// inline FileWrapper* Tree::SearchForFileAndIfExistReturnPointerToIt__Private( const SequentialDataStructure< FileWrapper* >& filesWrappersPointers, const Path& filePath ) const
// {
// 	// This object will store the number of files
// 	const LargestUnsignedInteger numberOfFiles = filesWrappersPointers.Size();

// 	// Loop on all the existing file nodes
// 	for ( LargestUnsignedInteger index = 0UL ; index < numberOfFiles ; ++index )
// 	{
// 		// Check if the current file node has the required name
// 		if ( filesWrappersPointers[ index ]->Name() == filePath.NamePathLeadsTo() )
// 		{
// 			// The required file node exist

// 			// Notify other threads of execution that the current thread of execution will use the file node
// 			filesWrappersPointers[ index ]->Utilize();

// 			// Return a pointer to the file node
// 			return ( filesWrappersPointers[ index ] );
// 		}
// 	}

// 	// The file node does not exist return NULL
// 	return ( nullptr );
// }


// template< typename CallableType, typename... ArgumentTypes >
// inline Boolean Tree::ViewAllFilesRecursive__Private( Directory* const currentDirectoryPointer, CallableType&& callable, ArgumentTypes... arguments )
// {
// 	// Perform the action on the files of the current directory
// 	ReturnValueIfExpressionIsTrue( ConsiderAsOneArgument( currentDirectoryPointer->template ViewFiles< Boolean ( const SequentialDataStructure< FileWrapper* >&, CallableType&&, ArgumentTypes... ), CallableType&&, ArgumentTypes... >( &Tree::ViewAllFilesOfDirectory__Private, callable, ForwardUniversalReference< ArgumentTypes >( arguments )... ) ), true );

// 	// Perform a recurssive call on all the child directories
// 	ReturnValueIfExpressionIsTrue( ConsiderAsOneArgument( currentDirectoryPointer->template ViewChildDirectories< Boolean ( const SequentialDataStructure< Directory* >&, CallableType&&, ArgumentTypes... ), CallableType&&, ArgumentTypes... >( &Tree::ViewAllFilesOfChildDirectoriesRecursive__Private, callable, ForwardUniversalReference< ArgumentTypes >( arguments )... ) ), true );
// }


// template< typename CallableType, typename... ArgumentTypes >
// inline Boolean Tree::ViewAllFilesOfChildDirectoriesRecursive__Private( const SequentialDataStructure< Directory* >& childDirectoriesPointers, CallableType&& callable, ArgumentTypes... arguments )
// {
// 	// This object will store the number of child directories
// 	const LargestUnsignedInteger numberOfChildeDirectories = childDirectoriesPointers.Size();

// 	// Loop on all the existing child directories in the container
// 	for ( LargestUnsignedInteger index = 0UL ; index < numberOfChildeDirectories ; ++index )
// 	{
// 		// Perform a recursive call on the current child directory. If the function returned true it means that there is no more need
// 		// to pass on the rest of the files and the method should return
// 		ReturnValueIfExpressionIsTrue( ViewAllFilesRecursive__Private( childDirectoriesPointers[ index ], callable, ForwardUniversalReference< ArgumentTypes >( arguments )... ), true );
// 	}

// 	// Return false to notify that the recursive pass on the files should continue
// 	return ( false );
// }


// template< typename CallableType, typename... ArgumentTypes >
// inline Boolean Tree::ViewAllFilesOfDirectory__Private( const SequentialDataStructure< FileWrapper* >& filesWrappersPointers, CallableType&& callable, ArgumentTypes... arguments )
// {
// 	// This object will store the number of files
// 	const LargestUnsignedInteger numberOfFiles = filesWrappersPointers.Size();

// 	// Loop on all the existing files in the directory
// 	for ( LargestUnsignedInteger index = 0UL ; index < numberOfFiles ; ++index )
// 	{
// 		// Execute the given action on the current file. If the function returned true it means that there is no more need to pass on the
// 		// rest of the files and the method should return
// 		ReturnValueIfExpressionIsTrue( filesWrappersPointers[ index ]->ViewFile< Boolean, const Path&, ArgumentTypes... >( callable, filesWrappersPointers[ index ]->GetPath(), ForwardUniversalReference< ArgumentTypes >( arguments )... ), true );
// 	}

// 	// Return false to notify that the recursive pass on the files should continue
// 	return ( false );
// }


// inline void Tree::NoMoreMainMemorySpaceLeft_DownloadContentFromMainMemoryToSecondaryMemory__Private()
// {
// 	// Pass on all the files and download all the required content from main memory to secondary memory
// 	PerfomActionOnAllFiles(  );
// }


// inline Boolean Tree::NoMoreMainMemorySpaceLeft_DownloadContentFromMainMemoryToSecondaryMemory_AAAA__Private( File&, const Path& )
// {

// }



// *********************************************************************************   TESTING   ********************************************************************************



//DEBUG_TOOL(

	inline void Tree::UnitTest()
	{
		// Create a test instance
		Tree testTree_0;

		// Create a path instance that points to the root directory
		Path testPath_0( "/" );

		// Create a path instance that points to the root directory
		Path testPath_1;

		// Assert that they are equal
		Assert_Test( testPath_0 == testPath_1 );

		// Ensure that when trying to create the root directory it returns that it is already exist
		Assert_Test( testTree_0.TryToCreatePath( testPath_0 ) == MultiThread::Result::AlreadyExist );
		Assert_Test( testTree_0.TryToCreatePath( testPath_1 ) == MultiThread::Result::AlreadyExist );

		// Create a path instance
		Path testPath_2( "/tmp/Root" );

		// Try to create the path
		Assert_Test( testTree_0.TryToCreatePath( testPath_2 ) == MultiThread::Result::Success );

		// Try to create again and ensure it return already exist
		Assert_Test( testTree_0.TryToCreatePath( testPath_2 ) == MultiThread::Result::AlreadyExist );

		// Create a path instance
		Path testPath_3( "/tmp/Root/AA/BB/CC/DD" );

		// Try to create the path
		Assert_Test( testTree_0.TryToCreatePath( testPath_3 ) == MultiThread::Result::Success );

		// Try to create again and ensure it return already exist
		Assert_Test( testTree_0.TryToCreatePath( testPath_3 ) == MultiThread::Result::AlreadyExist );

		// Create a path instance
		Path testPath_4( "/tmp/Root/AA/BB/CC/rrr.txt", true );

		// Try to create the path
		Assert_Test( testTree_0.TryToCreatePath( testPath_4 ) == MultiThread::Result::Success );

		// Try to create again and ensure it return already exist
		Assert_Test( testTree_0.TryToCreatePath( testPath_4 ) == MultiThread::Result::AlreadyExist );

		// Create a path instance
		Path testPath_5( "/tmp/Root/AA/BB/CC/mmm.txt", true );

		// Try to create the path
		Assert_Test( testTree_0.TryToCreatePath( testPath_5 ) == MultiThread::Result::Success );

		// Try to create again and ensure it return already exist
		Assert_Test( testTree_0.TryToCreatePath( testPath_5 ) == MultiThread::Result::AlreadyExist );

		// Create a path instance
		Path testPath_6( "/tmp/Root/ddddddddddddddddddddd.txt", true );

		// Try to create the path
		Assert_Test( testTree_0.TryToCreatePath( testPath_6 ) == MultiThread::Result::Success );

		// Try to create again and ensure it return already exist
		Assert_Test( testTree_0.TryToCreatePath( testPath_6 ) == MultiThread::Result::AlreadyExist );

		// Try to remove the path
		Assert_Test( testTree_0.TryToRemovePath( testPath_6 ) == MultiThread::Result::Success );

		// Try to remove again and ensure it return that it does exist
		Assert_Test( testTree_0.TryToRemovePath( testPath_6 ) == MultiThread::Result::DoesNotExist );
	}

//)  //  End of debug tool




}  //  Namespace FileSystem


}  //  Namespace Universe