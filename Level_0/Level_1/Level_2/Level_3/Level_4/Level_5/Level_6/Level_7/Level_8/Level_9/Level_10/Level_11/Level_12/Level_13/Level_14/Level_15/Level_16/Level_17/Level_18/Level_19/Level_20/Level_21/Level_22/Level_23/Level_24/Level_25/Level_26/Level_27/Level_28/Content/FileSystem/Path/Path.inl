//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline Path::Path( const MemoryHandlerName memoryHandlerName ) :
	member_path( memoryHandlerName, 1UL, "/" ),
	member_doesPathPointsToFile( false )
{}


inline Path::Path( const AsciiLiteral& absolutePath, const Boolean doesPointToFile, const MemoryHandlerName memoryHandlerName ) :
	member_path( memoryHandlerName, 1UL, "/" ),
	member_doesPathPointsToFile( doesPointToFile )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	Assert( ( absolutePath[0] == '/' ), "The path needs to start with the ascii character \'/\'" );

	// This object will store the last index in the absolute path
	const LargestUnsignedInteger absolutePathLastIndex = absolutePath.Size() - 1UL;

	// This object will store the starting index of the current name seperated be the delimiter '/'
	LargestUnsignedInteger currentStartingIndex = 1UL;

	// This object will store the current size of the directory of file
	LargestUnsignedInteger currentSize = 0UL;

	// Loop on all the parts of the path, each part is separated by the delimiter '/'
	for ( LargestUnsignedInteger index = 1UL ; index < absolutePath.Size() ; ++index )
	{
		// Check if the current ascii character in the path is the delimiter '/'
		if ( absolutePath[ index ] == '/' )
		{
			// The delimiter was encountered

			// Set the size of the current directory or file name
			currentSize = index - currentStartingIndex;

			// Insert the current part of the path
			member_path.InsertSingleElementAtTheEnd( TakeResourcesAndLeaveInstanceInDefaultState( Language::String( absolutePath, currentStartingIndex, currentSize ) ) );

			// Set the current starting index to the next index after the index the delimiter was found in
			currentStartingIndex = index + 1UL;
		}
		// Check if this is the last index of the absolute path
		else if ( index == absolutePathLastIndex )
		{
			// This is the last index of the absolute path

			// Set the size of the current directory or file name
			currentSize = index - currentStartingIndex + 1UL;

			// Insert the current part of the path
			member_path.InsertSingleElementAtTheEnd( TakeResourcesAndLeaveInstanceInDefaultState( Language::String( absolutePath, currentStartingIndex, currentSize ) ) );			
		}
	}
}


template< Concepts::String UniversalReferenceStringType >
inline Path::Path( const Path& other, UniversalReferenceStringType&& directoryOrFileNameToAdd, const Boolean isDirectory ) :
	SelfType( other )
{
	// Check if the path should lead to a directory or file
	if ( isDirectory == true )
	{
		// The path will lead to a directory

		// Add the directory to the ending of the path
		AddDirectory( ForwardUniversalReference< UniversalReferenceStringType >( directoryOrFileNameToAdd ) );
	}
	else
	{
		// The path will lead to a file

		// Add the file to the ending of the path
		AddFile( ForwardUniversalReference< UniversalReferenceStringType >( directoryOrFileNameToAdd ) );			
	}
}


inline Path::Path( const Path& other, const LargestUnsignedInteger sizeFromPathToInclude ) :
	SelfType()
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsAboveCertainLimit( sizeFromPathToInclude, 1UL );

	// Loop on all the required entries of the path
	for ( LargestUnsignedInteger index = 0UL ; index < sizeFromPathToInclude ; ++index )
	{
		// Add the current entry from the other path to end of this path
		member_path.InsertSingleElementAtTheEnd( other[ index ] );
	}

	// Check if all the path was included, in this case if the last entry of the path points to a file set the required member in this instance
	// accordingly
	if ( other.Size() == sizeFromPathToInclude )
	{
		// All the path was included

		// Set the member that notifies if the last entry points to a file according to the other member
		member_doesPathPointsToFile = other.member_doesPathPointsToFile;
	}
}


inline Path::Path( const SelfType& other ) :
	member_path( other.member_path ),
	member_doesPathPointsToFile( other.member_doesPathPointsToFile )
{}


inline void Path::AddDirectory( const Language::String& directoryName )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertValueIsLargerThenZero( directoryName.Size() );
	Assert( member_doesPathPointsToFile == false, "The last part of the path is a file name" );

	// Add the directory name to the end of the path
	member_path.InsertSingleElementAtTheEnd( directoryName );
}


inline void Path::AddDirectory( Language::String&& directoryName )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertValueIsLargerThenZero( directoryName.Size() );
	Assert( member_doesPathPointsToFile == false, "The last part of the path is a file name" );

	// Add the directory name to the end of the path
	member_path.InsertSingleElementAtTheEnd( TakeResourcesAndLeaveInstanceInDefaultState( directoryName ) );
}


inline void Path::AddFile( const Language::String& fileName )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertValueIsLargerThenZero( fileName.Size() );
	Assert( member_doesPathPointsToFile == false, "The last part of the path is already a file name" );

	// Add the file name to the end of the path
	member_path.InsertSingleElementAtTheEnd( fileName );

	// Set that the path points to a file
	member_doesPathPointsToFile = true;
}


inline void Path::AddFile( Language::String&& fileName )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertValueIsLargerThenZero( fileName.Size() );
	Assert( member_doesPathPointsToFile == false, "The last part of the path is already a file name" );

	// Add the file name to the end of the path
	member_path.InsertSingleElementAtTheEnd( TakeResourcesAndLeaveInstanceInDefaultState( fileName ) );

	// Set that the path points to a file
	member_doesPathPointsToFile = true;
}


inline void Path::RemoveLastPart()
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsLargerThenZero( member_path.Size() );

	// The last part will be removed. Instead of checking each time if its a file and only then setting the object to false, the object
	// will just be set to false each time. Because the previous part in the path must be a directory
	member_doesPathPointsToFile = false;

	// Remove the last part of the path
	member_path.RemoveLast();
}


inline Boolean Path::DoesPointToFile() const
{
    // Return the value of the boolean that stores if the path point to a file or not
    return ( member_doesPathPointsToFile );
}


inline const Language::String& Path::NamePathLeadsTo() const
{
    // Return a constant reference to the base name, which is the last part of the path. It can be either a directory name or a file name
    return ( member_path.Last() );
}


inline Memory::Vector< AsciiCharacter > Path::ToAsciiString( const LargestUnsignedInteger sizeFromPathToInclude ) const
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsLargerThenZero( sizeFromPathToInclude );

	// This object will store the path as an ascii string
	Memory::Vector< AsciiCharacter > pathAsAsciiString;

	// Check if only the root directory needs to be included
	if ( sizeFromPathToInclude == 1UL )
	{
		// Only the root directory needs to be included

		// Allocate the memory space to store the ascii string
		pathAsAsciiString.InsertMultipleTimesTheSameElement( 2UL, 0 );

		// Set the root directory
		pathAsAsciiString[0] = '/';

		// Set the NULL terminator at the ending of the ascii string
		pathAsAsciiString[1] = 0;

		// Return the result
		return ( pathAsAsciiString );
	}

	// This object will store the size required for the path to be stored as ascii string. It will be initialized to 2, for the '/' ascii
	// character that needs to always exist, and for the NULL character at the end of the string
	LargestUnsignedInteger asciiStringSize = 2UL;

	// This object will store the last index to end the loop
	const LargestUnsignedInteger lastIndex = sizeFromPathToInclude - 1UL;

	// Loop on all the parts of the path
	for ( LargestUnsignedInteger index = 1UL ; index < lastIndex ; ++index )
	{
		// Add the size of the current part of the path. Add plus one for the delimiter '/' that needs to appear between parts of the path
		// in the ascii string
		asciiStringSize += member_path[ index ].Size() + 1UL;
	}

	// Only the size of the last part of the path needs to be added
	asciiStringSize += member_path[ lastIndex ].Size();

	// This object will store the path as an ascii string
	pathAsAsciiString.InsertMultipleTimesTheSameElement( asciiStringSize );

	// Set the root directory '/' mark at the beginning of the ascii string
	pathAsAsciiString[0] = '/';

	// This object will be used as an index to the path as ascii string
	LargestUnsignedInteger asciiStringIndex = 1UL;

	// Loop on all the parts of the path
	for ( LargestUnsignedInteger index = 1UL ; index < sizeFromPathToInclude ; ++index )
	{
		// This ojbect will store the size of the current part of the path
		const LargestUnsignedInteger partSize = member_path[ index ].Size();

		// Loop on all the characters in the current path part
		for ( LargestUnsignedInteger partIndex = 0UL ; partIndex < partSize ; ++partIndex )
		{
			// Copy the current character into the ascii string
			pathAsAsciiString[ asciiStringIndex ] = member_path[ index ][ partIndex ].GetAsAsciiCharacter();

			// Increment the path as ascii string index by 1
			asciiStringIndex += 1UL;
		}

		// Check if the delimiter '/' needs to be added. It needs to be added after all the parts except for the last one
		if ( index != lastIndex )
		{
			// Add the delimiter '/' to the ascii string
			pathAsAsciiString[ asciiStringIndex ] = '/';

			// Increment the path as ascii string index by 1
			asciiStringIndex += 1UL;
		}
	}

	// Set the NULL terminator at the ending of the ascii string
	pathAsAsciiString[ asciiStringSize - 1UL ] = 0;

	// Return the result
	return ( pathAsAsciiString );
}


inline Memory::HeapPointer< AsciiCharacter > Path::ToAsciiString() const
{
	// Create an ascii string from the full path, and return the result
	return ( ToAsciiString( member_path.Size() ) );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



inline Boolean Path::operator==( const SelfType& other ) const
{
	// Compare the paths and return the result
	return ( member_path == other.member_path );
}


inline Boolean Path::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}


inline const Language::String& Path::operator[]( const LargestUnsignedInteger index ) const
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsBelowCertainLimit( index, member_path.Size() );

    // Return a constant reference to the required part of the path
    return ( member_path[ index ] );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	inline void Path::UnitTest()
	{
		// Create a test instance
		Path testPath_0;

		// Assert that the size is 1
		Assert_Test( testPath_0.Size() == 1UL );

		// Ensure that the path doesn not point to a file
		Assert_Test( testPath_0.DoesPointToFile() == false );

		// Ensure the ascii string is correct
		Assert_Test( strcmp( testPath_0.ToAsciiString().Get(), "/" ) == 0 );

		testPath_0.AddDirectory( "Level_0" );

		// Assert that the size is 1
		Assert_Test( testPath_0.Size() == 2UL );

		// Assert that the names of the directories are correct
		Assert_Test( testPath_0[0] == "/" );
		Assert_Test( testPath_0[1] == "Level_0" );

		// Ensure that the path doesn not point to a file
		Assert_Test( testPath_0.DoesPointToFile() == false );

		// Ensure the ascii string is correct
		Assert_Test( strcmp( testPath_0.ToAsciiString().Get(), "/Level_0" ) == 0 );

		testPath_0.AddDirectory( "Level_1" );

		// Assert that the size is 3
		Assert_Test( testPath_0.Size() == 3UL );

		// Assert that the names of the directories are correct
		Assert_Test( testPath_0[0] == "/" );
		Assert_Test( testPath_0[1] == "Level_0" );
		Assert_Test( testPath_0[2] == "Level_1" );

		// Ensure that the path doesn not point to a file
		Assert_Test( testPath_0.DoesPointToFile() == false );

		// Ensure the ascii string is correct
		Assert_Test( strcmp( testPath_0.ToAsciiString().Get(), "/Level_0/Level_1" ) == 0 );

		testPath_0.AddFile( "Forever.cpp" );

		// Assert that the size is 4
		Assert_Test( testPath_0.Size() == 4UL );

		// Assert that the names of the directories are correct
		Assert_Test( testPath_0[0] == "/" );
		Assert_Test( testPath_0[1] == "Level_0" );
		Assert_Test( testPath_0[2] == "Level_1" );
		Assert_Test( testPath_0[3] == "Forever.cpp" );

		// Ensure that the path points to a file
		Assert_Test( testPath_0.DoesPointToFile() );

		// Ensure the ascii string is correct
		Assert_Test( strcmp( testPath_0.ToAsciiString().Get(), "/Level_0/Level_1/Forever.cpp" ) == 0 );

		// Try to remove the last part
		testPath_0.RemoveLastPart();

		// Assert that the size is 3
		Assert_Test( testPath_0.Size() == 3UL );

		// Assert that the names of the directories are correct
		Assert_Test( testPath_0[0] == "/" );
		Assert_Test( testPath_0[1] == "Level_0" );
		Assert_Test( testPath_0[2] == "Level_1" );

		// Ensure that the path points to a file
		Assert_Test( testPath_0.DoesPointToFile() == false );

		// Ensure the ascii string is correct
		Assert_Test( strcmp( testPath_0.ToAsciiString().Get(), "/Level_0/Level_1" ) == 0 );

		// Create a test instance
		Path testPath_1( "/tmp/Root" );

		// Ensure the ascii string is correct
		Assert_Test( strcmp( testPath_1.ToAsciiString().Get(), "/tmp/Root" ) == 0 );

		// Create a test instance
		Path testPath_2( "/" );

		// Ensure the ascii string is correct
		Assert_Test( strcmp( testPath_2.ToAsciiString().Get(), "/" ) == 0 );

		// Create a test instance
		Path testPath_3( "/tmp/Death/Lord/Dude/fffff/lol.txt", true );

		// Ensure the ascii string is correct
		Assert_Test( strcmp( testPath_3.ToAsciiString().Get(), "/tmp/Death/Lord/Dude/fffff/lol.txt" ) == 0 );

		// Ensure that the path points to a file
		Assert_Test( testPath_3.DoesPointToFile() == true );
	}

)  //  End of debug tool



}  //  Namespace FileSystem


}  //  Namespace Universe