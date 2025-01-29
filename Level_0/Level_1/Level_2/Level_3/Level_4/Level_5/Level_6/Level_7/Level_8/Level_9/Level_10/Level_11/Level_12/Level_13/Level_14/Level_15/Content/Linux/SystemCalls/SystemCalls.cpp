namespace Universe 
{


namespace Linux
{



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	void DisplayDirectoryEntryContent( const struct linux_dirent64* directoryEntry )
	{
		std::cout << "Directory entry:" << std::endl; 
		std::cout << "	Name: " << directoryEntry->member_fileName << std::endl; 
		std::cout << "	Inode number: " << directoryEntry->member_inode << std::endl; 
		std::cout << "	Offset to next structure: " << directoryEntry->member_offsetToNextStructure << std::endl;
		std::cout << "	Entry size: " << directoryEntry->member_size << std::endl;

		switch ( directoryEntry->member_fileType )
		{
			case DT_REG:
			{
				std::cout << "	File type: " << "Regular" << std::endl << std::endl;
				break;
			}
			case DT_DIR:
			{
				std::cout << "	File type: " << "Directory" << std::endl << std::endl;
				break;
			}
			case DT_FIFO:
			{
				std::cout << "	File type: " << "FIFO" << std::endl << std::endl;
				break;
			}
			case DT_SOCK:
			{
				std::cout << "	File type: " << "Socket" << std::endl << std::endl;
				break;
			}
			case DT_LNK:
			{
				std::cout << "	File type: " << "Symbolic link" << std::endl << std::endl;
				break;
			}
			case DT_BLK:
			{
				std::cout << "	File type: " << "Block device" << std::endl << std::endl;
				break;
			}
			case DT_CHR:
			{
				std::cout << "	File type: " << "Character device" << std::endl << std::endl;
				break;
			}
			default:
			{
				std::cout << "	File type: " << "Unknown" << std::endl << std::endl;
			}
		}
	}

	void DisplayDirectoryEntriesContent( const UnsignedInteger8bits* directoryEntries, UnsignedInteger64bits size )
	{
		for ( UnsignedInteger64bits index = 0UL ; index < size ; index += ((const struct linux_dirent64*)( directoryEntries + index ))->member_size )
		{
			DisplayDirectoryEntryContent( (const struct linux_dirent64*)( directoryEntries + index ) );
		}
	}

	void SystemCalls::UnitTest()
	{
		// Create a place to store the content from read
		SignedInteger8bits testCharacter_1 = 0;

		// Display to the user to enter a character
		std::cout << "Please enter a character :" << std::endl;

		// Read the input from the user
		auto result = Read( 0, &testCharacter_1, 1UL );

		// Write thank you to the user!!!!
		result = Write( 1UL, "Thank you for the character", 27UL );

		std::cout << std::endl;

		// Create a place to store the content from read
		SignedInteger8bits testString_1[20] = {0};

		// Create the file
		CreateFile( "/tmp/lllk.txt", S_IRWXU );

		// Open the file for read and write
		SignedInteger32bits fileDescriptor_1 = OpenFile( "/tmp/lllk.txt", O_RDWR );

		// Write the content read from the file
		result = Write( fileDescriptor_1, "sHizzbala12345678913", 20UL );

		SetReadAndWriteMarkerOffsetForFile( fileDescriptor_1, 0 );

		// Read the input from the user
		result = Read( fileDescriptor_1, testString_1, 20UL );

		// Write the content read from the file
		result = Write( 1UL, testString_1, 20UL );

		result++;

		std::cout << std::endl;

		// Create a buffer to store the directory entry
		UnsignedInteger8bits directoryEntries[5000] = {0};

		// Open the file for read and write
		SignedInteger32bits directoryDescriptor_2 = OpenDirectory( "/root/Anna/AnnaVersions", O_RDONLY );

		// Read the directory entry
		UnsignedInteger64bits numberOfBytesRead = GetDirectoryEntry( directoryDescriptor_2, directoryEntries, 5000 );

		DisplayDirectoryEntriesContent( directoryEntries, numberOfBytesRead );
		std::cout << numberOfBytesRead << std::endl;

		// Close the directory
		Close( directoryDescriptor_2 );

		// Create a buffer to store the file information
		struct stat64 fileInformation;

		// Get the file information
		GetFileInformation( fileDescriptor_1, &fileInformation );

		Assert_Test( fileInformation.st_size == 20 );

		// Close the file
		Close( fileDescriptor_1 );

		// Try to create a directory
		CreateDirectory( "/tmp/Root" );

		// Delete the directory
		DeleteEmptyDirectory( "/tmp/Root" );
	}

)  //  End of debug tool



}  //  Namespace Linux


}  //  Namespace Universe