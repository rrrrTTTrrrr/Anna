namespace Universe
{


namespace FileSystem
{



//	********************************************************************   PRIVATE METHODS IMPLEMENTATION   *********************************************************************



inline void FileWrapper::DownloadContentFromMainMemoryToSecondaryMemory__Private( File& file )
{
	// This object will store the path to the file as an ascii string
	Memory::HeapPointer< AsciiCharacter > pathAsAsciiString;

	// Check the file already exist in secondary memory
	if ( member_doesExistInSecondaryMemory == true )
	{
		// The file already exist in secondary memory

		// Check if the file was changed
		if ( member_wasFileChanged.Load() == false )
		{
			// The file was not changed, therefore there is no need to copy the content from main memory to secondary memory

			// Clear all the file content from main memory
			file.Reset();

			// Set that the file is no longer in main memory
			member_wasFileLoadedFromSecondaryMemory = false;

			// Nothing else needs to be done
			return;
		}

		// The file was changed, therefore the content needs to be copied from main memory to secondary memory

		// Store the path as ascii string
		pathAsAsciiString = TakeResourcesAndLeaveInstanceInDefaultState( member_path.ToAsciiString( member_path.Size() ) );

		// Check if the file is empty
		if ( file.Size() == 0UL )
		{
			// Use the Linux system call to delete the content of the file
			Linux::SystemCalls::DeleteFileContent( &pathAsAsciiString[0] );

			// Nothing else needs to be done
			return;
		}
	}
	else
	{
		// The file does not exist in secondary memory

		// Store the path as ascii string
		pathAsAsciiString = TakeResourcesAndLeaveInstanceInDefaultState( member_path.ToAsciiString( member_path.Size() ) );

		// Use the Linux system call to create the file in secondary memory
		Linux::SystemCalls::CreateFile( &pathAsAsciiString[0] );

		// Check if the file is empty
		if ( file.Size() == 0UL )
		{
			// The file is empty, there is nothing else that needs to be done
			return;
		}
	}

	// The file either does not exist already in secondary memory, or it does exist but was changed. Therefore the content needs to be copied
	// from main memory to secondary memory

	// Collect all the information form the pages array memory handler used to store the file in main memory

	// Create a constant reference to the pages array memory handler of the file, to allow acquiring information
	const SelfPagesArrayType& pagesArray = file.GetPagesArray();

	// Get the pages pointers container
	const Memory::Vector< Language::Character* >& pagesPointers = pagesArray.PointersToPages();

	// Get the pages size in bytes
	const LargestUnsignedInteger pagesSizeInBytes = pagesArray.PageSizeInBytes();

	// Get the index of the first used entry in the first page
	const LargestUnsignedInteger indexOfFirstUsedEntryInFirstPage = pagesArray.IndexOfFirstEntryUsedInFirstPageIndex();

	// Get the size used in the last page
	const LargestUnsignedInteger sizeUsedInLastPage = pagesArray.SizeUsedInLastPage();

	// Now all the required information is known

	// Use the Linux system call to open the required file
	const SignedInteger32bits fileDescriptor = Linux::SystemCalls::OpenFile( &pathAsAsciiString[0], O_WRONLY );

	// This object will store the size used in the first page
	const LargestUnsignedInteger sizeUsedInFirstPage = pagesSizeInBytes - indexOfFirstUsedEntryInFirstPage;

	// Download the first page conetnt to secondary memory
	Assert( Linux::SystemCalls::Write( fileDescriptor, pagesPointers[0] + indexOfFirstUsedEntryInFirstPage, sizeUsedInFirstPage ) == sizeUsedInFirstPage, "Not all the required data was written to secondary memory" );

	// This object will store the last page index
	const LargestUnsignedInteger lastPageIndex = pagesPointers.Size() - 1UL;

	// Loop on all the pages except for the last page
	for ( LargestUnsignedInteger pageIndex = 1UL ; pageIndex < lastPageIndex ; ++pageIndex )
	{
		// Download the current page from main to secondary memory
		Assert( Linux::SystemCalls::Write( fileDescriptor, pagesPointers[ pageIndex ], pagesSizeInBytes ) == pagesSizeInBytes, "Not all the required data was written to secondary memory" );
	}

	// Download the last page content to secondary memory
	Assert( Linux::SystemCalls::Write( fileDescriptor, pagesPointers[ lastPageIndex ], sizeUsedInLastPage ) == sizeUsedInLastPage, "Not all the required data was written to secondary memory" );

	// Use the Linux system call to close the required file
	Linux::SystemCalls::Close( fileDescriptor );

	// Clear all the file content from main memory
	file.Reset();
}



//  ********************************************************************   STATIC FUNCTIONS IMPLEMENTATION   ********************************************************************



inline void FileWrapper::LoadFileFromSecondaryMemoryToMainMemory__Private( File& file, const Path& filePath )
{
	// Store the file path as an ascii string
	const Memory::HeapPointer< AsciiCharacter > pathAsAsciiString = TakeResourcesAndLeaveInstanceInDefaultState( filePath.ToAsciiString( filePath.Size() ) );

	// Use the Linux system call to open the required file
	const SignedInteger32bits fileDescriptor = Linux::SystemCalls::OpenFile( &pathAsAsciiString[0], O_RDONLY );

	// This object will store the file size in bytes
	const LargestUnsignedInteger fileSizeInBytes = Linux::SystemCalls::GetFileSizeInBytes( fileDescriptor );

	// This object will store the file size in terms of characters
	const LargestUnsignedInteger fileSizeInCharacters = fileSizeInBytes / file.DataTypeSizeInBytes();

	// Allocate space in main memory to store the file
	file.InsertMultipleTimesTheSameElement( 0UL, fileSizeInCharacters );

	// Create a constant reference to the pages array memory handler of the file, to allow acquiring information
	const SelfPagesArrayType& pagesArray = file.GetPagesArray();

	// Get the pages pointers container
	const Memory::Vector< Language::Character* >& pagesPointers = pagesArray.PointersToPages();

	// Get the pages size in bytes
	const LargestUnsignedInteger pagesSizeInBytes = pagesArray.PageSizeInBytes();

	// This object will store the division result of the file size by the page size, both quotient and remainder are needed
    const CentralProcessingUnit::DivisonResultUnsignedInteger64bits fileSizeInBytesDividedByPageSizeInBytesResult = CentralProcessingUnit::Arithmetics::Divison( fileSizeInBytes, pagesSizeInBytes );

	// This object will store the number of full pages the file contains
	const LargestUnsignedInteger numberOfFullFilePages = fileSizeInBytesDividedByPageSizeInBytesResult.Quotient();

	// This object will store the current page index
	LargestUnsignedInteger currentPageIndex = 0UL;

	// Loop until all the file was loaded from secondary memory to main memory
	for ( LargestUnsignedInteger pageIndex = 0UL ; pageIndex < numberOfFullFilePages ; ++pageIndex )
	{
		// Load the current page from secondary to main memory
		Assert( Linux::SystemCalls::Read( fileDescriptor, pagesPointers[ currentPageIndex ], pagesSizeInBytes ) == pagesSizeInBytes, "Not all the required data was read from secondary memory" );
	}

	// If the file size divided by the page size, than all the file was loaded. But if that is not the case, than there is more at
	// the end of the file
	if ( fileSizeInBytesDividedByPageSizeInBytesResult.Remainder() > 0UL )
	{
		// Load the last part of the file from secondary to main memory
		Assert( Linux::SystemCalls::Read( fileDescriptor, pagesPointers[ pagesPointers.Size() - 1UL ], fileSizeInBytesDividedByPageSizeInBytesResult.Remainder() ) == fileSizeInBytesDividedByPageSizeInBytesResult.Remainder(), "Not all the required data was read to secondary memory" );
	}

	// Use the Linux system call to close the required file
	Linux::SystemCalls::Close( fileDescriptor );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	// inline void ViewFileTest( const File& file )
	// {
	// 	for ( LargestUnsignedInteger index = 0UL ; index < file.Size() ; ++index )
	// 	{
	// 		std::cout << file[ index ].GetAsAsciiCharacter() << std::endl;
	// 	}
	// }

	inline void FileWrapper::UnitTest()
	{
		// FileWrapper testFileWrapper_0( "/tmp/ii.txt", true );

		// testFileWrapper_0.template ViewFile< void >( &ViewFileTest );
	}

)  //  End of debug tool



}  //  Namespace FileSystem


}  //  Namespace Universe