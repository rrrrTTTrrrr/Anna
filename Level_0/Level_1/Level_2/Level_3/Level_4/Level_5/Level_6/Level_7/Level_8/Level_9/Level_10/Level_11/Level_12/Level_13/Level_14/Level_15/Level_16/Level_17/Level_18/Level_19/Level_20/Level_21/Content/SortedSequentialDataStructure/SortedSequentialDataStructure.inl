//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline SortedSequentialDataStructure< DataType, MemoryManagerType >::SortedSequentialDataStructure( const SelfType& other ) :
	member_sequentialDataStructure( other.member_sequentialDataStructure ),
	member_isLargerFunctionPointer( other.member_isLargerFunctionPointer )
{}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename UniversalReferenceDataType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceDataType, DataType >::Result == true )
inline void SortedSequentialDataStructure< DataType, MemoryManagerType >::Insert( UniversalReferenceDataType&& data )
{
	// This object will store the index at which the new data needs to be added
	LargestUnsignedInteger addDataAtThisIndex = 0UL;

	// Check if the sequential data structure is empty
	if ( member_sequentialDataStructure.Size() > 0UL && IsLarger__Private( data, member_sequentialDataStructure[0] ) == true )
	{
		// Search for the data. If the data exist it will return an index and then the new data can be inserted in the same index. If the data
		// does not exist already, it will return the index at which the search ended which is the closest location to where the data actually
		// needs to be added at
		const Memory::Tuple< Boolean, LargestUnsignedInteger > searchResult = SearchSingleElement__Private( data );

		// Store the index at which the data needs to be added at
		addDataAtThisIndex = searchResult.template Entry< DATA_LOCATION >();

		// Check if the data does not already exist in the instance
		if ( searchResult.template Entry< WAS_DATA_FOUND >() == false )
		{
			// The data does not already exist in the instance

			// Since the search did not find the data, the index provided contains the closest value which is smaller then the new data. This means
			// that the data needs to be added above it
			addDataAtThisIndex += 1UL;
		}
	}

	// Add the new data to the required location
	member_sequentialDataStructure.template InsertSingleElement< UniversalReferenceDataType >( addDataAtThisIndex, ForwardUniversalReference< UniversalReferenceDataType >( data ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline Memory::Tuple< Boolean, LargestUnsignedInteger > SortedSequentialDataStructure< DataType, MemoryManagerType >::SearchSingleElement( const DataType& data ) const
{
	// Search for the data and return the result
	return ( SearchSingleElement__Private( data ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline const DataType& SortedSequentialDataStructure< DataType, MemoryManagerType >::PeakTop() const
{
	// Return a constant reference to the entry which contains the highest value
	return ( member_sequentialDataStructure[ member_sequentialDataStructure.Size() - 1UL ] );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline const DataType& SortedSequentialDataStructure< DataType, MemoryManagerType >::PeakBottom() const
{
	// Return a constant reference to the entry which contains the lowest value
	return ( member_sequentialDataStructure[0] );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline DataType SortedSequentialDataStructure< DataType, MemoryManagerType >::PopTop()
{
	// This object will store a copy of the entry which contains the highest value
	DataType highestValue = TakeResourcesAndLeaveInstanceInDefaultState( member_sequentialDataStructure[ member_sequentialDataStructure.Size() - 1UL ] );

	// Remove the entry which contains the highest value from the sequential data structure
	member_sequentialDataStructure.Remove( member_sequentialDataStructure.Size() - 1UL, 1UL );

	// Return a copy of the highest value
	return ( highestValue );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline DataType SortedSequentialDataStructure< DataType, MemoryManagerType >::PopBottom()
{
	// This object will store a copy of the entry which contains the lowest value
	DataType lowestValue = TakeResourcesAndLeaveInstanceInDefaultState( member_sequentialDataStructure[0] );

	// Remove the entry which contains the lowest value from the sequential data structure
	member_sequentialDataStructure.Remove( 0UL, 1UL );

	// Return a copy of the lowest value
	return ( lowestValue );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline Boolean SortedSequentialDataStructure< DataType, MemoryManagerType >::operator==( const SelfType& other ) const
{
	// Compare the content of the sequential data structures, and return the result
	return ( member_sequentialDataStructure == other.member_sequentialDataStructure );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline Boolean SortedSequentialDataStructure< DataType, MemoryManagerType >::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline Memory::Tuple< Boolean, LargestUnsignedInteger > SortedSequentialDataStructure< DataType, MemoryManagerType >::SearchSingleElement__Private( const DataType& data ) const
{
	// This object will store if the required data was found
	Boolean wasDataFound = false;

	// This object will store the current starting index of the segment
	LargestUnsignedInteger startingIndex = 0UL;

	// This object will store the current size of the segment
	LargestUnsignedInteger currentSize = member_sequentialDataStructure.Size();

	// This object will store the current size of the segment divided by 2 to avoid repeating the calculation
	LargestUnsignedInteger currentSizeDividedByTwo = 0UL;

	// This object will store the current index at the middle of the segment that needs to be checked
	LargestUnsignedInteger currentMiddleSegmentIndex = 0UL;

	// Loop as long as the size is larger then zero
	while ( currentSize > 0UL )
	{
		// Store the size divided by two
		currentSizeDividedByTwo = DivideByTwo( currentSize );

		// Add to the starting index to the size divided by two, and store the result. This will be the next index to check
		currentMiddleSegmentIndex = startingIndex + currentSizeDividedByTwo;

		// Check if the current entry has a value larger then the given data
		if ( IsLarger__Private( member_sequentialDataStructure[ currentMiddleSegmentIndex ], data ) )
		{
			// The current entry has a value larger then the given data, therefore the starting index of the segment does not need to change

			// Store as the new size for the next iteration as the current size divided by two
			currentSize = currentSizeDividedByTwo;
		}
		else if ( IsLarger__Private( data, member_sequentialDataStructure[ currentMiddleSegmentIndex ] ) )
		{
			// The current entry has a value smaller then the given data

			// Check if the size is even
			if ( Arithmetics::IsEven< LargestUnsignedInteger >( currentSize ) == true )
			{
				// The size is even

				// Set the starting index to the next index after the current middle segment index
				startingIndex = currentMiddleSegmentIndex + 1UL;

				// Decrement the size divided by two by one, and store as the new size for the next iteration
				currentSize = currentSizeDividedByTwo - 1UL;
			}
			else
			{
				// The size is odd

				// Set the starting index to the next index after the current middle segment index
				startingIndex = currentMiddleSegmentIndex + 1UL;

				// Store as the new size for the next iteration as the current size divided by two
				currentSize = currentSizeDividedByTwo;
			}
		}
		else
		{
			// An entry with the required data was found
			
			// Set that the data was found
			wasDataFound = true;

			// Break the loop
			break;
		}
	}

	// Return a tuple with boolean that will notify if the data was found or not, and the last index that was examined
	return ( Memory::Tuple< Boolean, LargestUnsignedInteger >( wasDataFound, currentMiddleSegmentIndex ) );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< Concepts::RawButPointerIsAllowed DataType COMMA typename MemoryManagerType >
	void SortedSequentialDataStructure< DataType COMMA MemoryManagerType >::UnitTest()
	{
		// Create a test instance
		SortedSequentialDataStructure< SignedInteger32bits > testSortedSequentialDataStructure_0;

		// Add multiple entries to the test instance
		testSortedSequentialDataStructure_0.Insert( 89 );
		testSortedSequentialDataStructure_0.Insert( 89 );
		testSortedSequentialDataStructure_0.Insert( 89 );
		testSortedSequentialDataStructure_0.Insert( 89 );
		testSortedSequentialDataStructure_0.Insert( 89 );
		testSortedSequentialDataStructure_0.Insert( 89 );
		testSortedSequentialDataStructure_0.Insert( 89 );
		testSortedSequentialDataStructure_0.Insert( 89 );
		testSortedSequentialDataStructure_0.Insert( 89 );
		testSortedSequentialDataStructure_0.Insert( 89 );
		testSortedSequentialDataStructure_0.Insert( 90 );
		testSortedSequentialDataStructure_0.Insert( 102 );
		testSortedSequentialDataStructure_0.Insert( 444 );
		testSortedSequentialDataStructure_0.Insert( 444 );
		testSortedSequentialDataStructure_0.Insert( 444 );
		testSortedSequentialDataStructure_0.Insert( 444 );
		testSortedSequentialDataStructure_0.Insert( 444 );
		testSortedSequentialDataStructure_0.Insert( 444 );
		testSortedSequentialDataStructure_0.Insert( 444 );
		testSortedSequentialDataStructure_0.Insert( 444 );
		testSortedSequentialDataStructure_0.Insert( 444 );
		testSortedSequentialDataStructure_0.Insert( 444 );
		testSortedSequentialDataStructure_0.Insert( 444 );
		testSortedSequentialDataStructure_0.Insert( 444 );
		testSortedSequentialDataStructure_0.Insert( 234 );
		testSortedSequentialDataStructure_0.Insert( 12 );
		testSortedSequentialDataStructure_0.Insert( 45 );
		testSortedSequentialDataStructure_0.Insert( 45 );
		testSortedSequentialDataStructure_0.Insert( 34 );
		testSortedSequentialDataStructure_0.Insert( 1000 );
		testSortedSequentialDataStructure_0.Insert( 234 );
		testSortedSequentialDataStructure_0.Insert( 0 );

		// Create the expected result
		SignedInteger32bits expectedResult[] = {0 COMMA 
												  12 COMMA 
												  34 COMMA 
												  45 COMMA 
												  45 COMMA
												  89 COMMA 
												  89 COMMA 
												  89 COMMA 
												  89 COMMA 
												  89 COMMA 
												  89 COMMA 
												  89 COMMA 
												  89 COMMA 
												  89 COMMA 
												  89 COMMA 
												  90 COMMA 
												  102 COMMA 
												  234 COMMA 
												  234 COMMA 
												  444 COMMA 
												  444 COMMA 
												  444 COMMA 
												  444 COMMA 
												  444 COMMA 
												  444 COMMA 
												  444 COMMA 
												  444 COMMA 
												  444 COMMA 
												  444 COMMA 
												  444 COMMA 
												  444 COMMA 
												  1000};

		// Assert that the top and bottom are correct
		Assert_Test( testSortedSequentialDataStructure_0.PeakTop() == 1000UL );
		Assert_Test( testSortedSequentialDataStructure_0.PeakBottom() == 0UL );

		// Loop on all the entries and ensure the result is correct
		for ( LargestUnsignedInteger index = 0UL ; index < testSortedSequentialDataStructure_0.Size() ; ++index )
		{
			// Assert that the current entry contains the expected result
			Assert_Test( expectedResult[ index ] == testSortedSequentialDataStructure_0.PopBottom() );
		}
	}

)  //  End of debug tool



}  //  Namespace Universe