//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< Concepts::Object Type, LargestUnsignedInteger CircularBufferSize > requires ( ( CircularBufferSize > 0UL ) && ( Arithmetics::IsPowerOfTwo< UnsignedInteger64bits >( CircularBufferSize ) == true ) )
inline CircularBuffer< Type, CircularBufferSize >::CircularBuffer() :
	member_mask( static_cast< LargestSignedInteger >( CircularBufferSize ) - 1 ),
	member_circularBuffer{},
	member_pushIndex( -1 ),
	member_popIndex( -1 ),
	member_isFree{0}
{
	// Set that all the locations are currently free to use
	Memory::Operations::Set< UnsignedInteger8bits >( member_isFree, CircularBufferSize, 1 );
}


template< Concepts::Object Type, LargestUnsignedInteger CircularBufferSize > requires ( ( CircularBufferSize > 0UL ) && ( Arithmetics::IsPowerOfTwo< UnsignedInteger64bits >( CircularBufferSize ) == true ) )
template< typename UniversalReferenceType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceType, Type >::Result == true )
EnsureRetrunValueIsUsed inline Boolean CircularBuffer< Type, CircularBufferSize >::Push( UniversalReferenceType&& data, const LargestUnsignedInteger timeoutInSeconds )
{	
	// This object will store the duration, to ensure that when the timeout in seconds has reached the method will return
	Duration duration;

	// This object will store the index at which the data will be inserted
	LargestSignedInteger pushIndex = 0;

	// Loop until all the required conditions are met
	do
	{
		// Get the current value of the push index
		pushIndex = member_pushIndex;

		// Wait until the buffer is not full
		while ( IsFull__Private( pushIndex ) == true )
		{
			// Check if the timeout in seconds has passed
			if ( duration.DidEnoughSecondsPassed( timeoutInSeconds ) == true )
			{
				// The timeout in seconds has passed
				return ( false );
			}

	        // Delay the central processing unit for a finite time. The method uses the 'PAUSE' instruction which provides a hint to the processor
	    	// that a thread is trying to lock using a loop. It will improve performance and power consumption
	    	CentralPrcessingUnit_Pause();		
		}


	} while ( ( member_isFree[ pushIndex & member_mask ] == 0 ) || ( member_pushIndex.CompareTheActualValueWithTheExpectedAndIfEqualSetTheDesiredValue( pushIndex, pushIndex + 1 ) == false ) || ( pushIndex == 0 ) );

	// Set the data into the required index
	member_circularBuffer[ pushIndex & member_mask ] = ForwardUniversalReference< UniversalReferenceType >( data );

	// Set that the location is used
	member_isFree[ pushIndex & member_mask ] = 0;

	// Return that the data was pushed successfully
	return ( true );
}


template< Concepts::Object Type, LargestUnsignedInteger CircularBufferSize > requires ( ( CircularBufferSize > 0 ) && ( Arithmetics::IsPowerOfTwo< UnsignedInteger64bits >( CircularBufferSize ) == true ) )
EnsureRetrunValueIsUsed inline Boolean CircularBuffer< Type, CircularBufferSize >::Pop( Type& data, const LargestUnsignedInteger timeoutInSeconds )
{
	// This object will store the duration, to ensure that when the timeout in seconds has reached the method will return
	Duration duration;

	// This object will store the index at which the data will be removed from
	LargestSignedInteger popIndex = 0;

	// Loop until all the required conditions are met
	do
	{
		// Loop until the pop index is not zero
		do
		{
			// Get the current value of the pop index
			popIndex = member_popIndex;

		} while ( ( popIndex == 0 ) && ( member_popIndex.CompareTheActualValueWithTheExpectedAndIfEqualSetTheDesiredValue( popIndex, 1 ) == false ) );

		// Wait until the buffer is not empty
		while ( IsEmpty__Private( popIndex ) == true )
		{
			// Check if the timeout in seconds has passed
			if ( duration.DidEnoughSecondsPassed( timeoutInSeconds ) == true )
			{
				// The timeout in seconds has passed
				return ( false );
			}

	        // Delay the central processing unit for a finite time. The method uses the 'PAUSE' instruction which provides a hint to the processor
	    	// that a thread is trying to lock using a loop. It will improve performance and power consumption
	    	CentralPrcessingUnit_Pause();		
		}


	} while ( ( member_isFree[ popIndex & member_mask ] == 1 ) || ( member_popIndex.CompareTheActualValueWithTheExpectedAndIfEqualSetTheDesiredValue( popIndex, popIndex + 1 ) == false ) );

	// Store the data, and leave the instance in the buffer invalidated
	data = TakeResourcesAndLeaveInstanceInDefaultState( member_circularBuffer[ popIndex & member_mask ] );

	// Set that the location is free to be used again
	member_isFree[ popIndex & member_mask ] = 1;

	// Return that the data was poped successfully
	return ( true );
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



template< Concepts::Object Type, LargestUnsignedInteger CircularBufferSize > requires ( ( CircularBufferSize > 0 ) && ( Arithmetics::IsPowerOfTwo< UnsignedInteger64bits >( CircularBufferSize ) == true ) )
EnsureRetrunValueIsUsed inline Boolean CircularBuffer< Type, CircularBufferSize >::IsFull__Private( const LargestSignedInteger pushIndex ) const
{
	// If the push index is at a distance larger then the mask, which is the size of the buffer, then the buffer is full
	return ( ( pushIndex - member_popIndex ) > member_mask );
}


template< Concepts::Object Type, LargestUnsignedInteger CircularBufferSize > requires ( ( CircularBufferSize > 0 ) && ( Arithmetics::IsPowerOfTwo< UnsignedInteger64bits >( CircularBufferSize ) == true ) )
EnsureRetrunValueIsUsed inline Boolean CircularBuffer< Type, CircularBufferSize >::IsEmpty__Private( const LargestSignedInteger popIndex ) const
{
	// If the given pop index is the same as the push index, the buffer is empty
	return ( popIndex == member_pushIndex );
}



// *********************************************************************************   TESTING   ********************************************************************************




//DEBUG_TOOL(

	template< LargestUnsignedInteger CircularBufferSize >
	void TestCircularBufferWithSpecificSize( const LargestUnsignedInteger numberOfIterations )
	{
		// Create a test instance
		CircularBuffer< LargestUnsignedInteger COMMA CircularBufferSize > testCircularBuffer;

		LargestUnsignedInteger currentPoppedValue = 0UL;
		LargestUnsignedInteger sum = 0UL;

		// Create the producer function
		auto producer = [ &testCircularBuffer ]( const LargestUnsignedInteger amountOfIterations )
		{
			for ( LargestUnsignedInteger index = 0UL ; index < amountOfIterations ; ++index )
			{
				Assert_Test( testCircularBuffer.Push( 1UL ) == true );
			}

			Assert_Test( testCircularBuffer.Push( 2UL ) == true );
		};

		// Create the consumer function
		auto consumer = [ &testCircularBuffer COMMA &sum COMMA &currentPoppedValue ]()
		{
			while ( currentPoppedValue != 2UL )
			{
				Assert_Test( testCircularBuffer.Pop( currentPoppedValue ) == true );

				sum += 1UL;
			}
		};

		const Callable< void ( const LargestUnsignedInteger ) > producerCallable( producer );
		const Callable< void () > consumerCallable( consumer );

		// Execute the threads
		ThreadOfExecution< void ( const LargestUnsignedInteger ) > producerThread( producerCallable, numberOfIterations );
		ThreadOfExecution< void () > consumerThread( consumerCallable );

		// Wait for the result
		producerThread.WaitForThreadOfExecutionToFinish();
		consumerThread.WaitForThreadOfExecutionToFinish();

		// Assert that the result is valid
		Assert_Test( sum == ( numberOfIterations + 1UL ) );
	}

	template< Concepts::Object Type COMMA LargestUnsignedInteger CircularBufferSize > requires ( ( CircularBufferSize > 0 ) && ( Arithmetics::IsPowerOfTwo< UnsignedInteger64bits >( CircularBufferSize ) == true ) )
	void CircularBuffer< Type COMMA CircularBufferSize >::UnitTest()
	{
		// Create a test instance
		CircularBuffer< LargestSignedInteger COMMA 64UL > testCircularBuffer_0;

		// Try to push and pop one time
		Assert_Test( testCircularBuffer_0.Push( 89L ) == true );

		// Create an object to store the popped values
		LargestSignedInteger currentPoppedValue = 0;

		Assert_Test( testCircularBuffer_0.Pop( currentPoppedValue ) == true );
		Assert_Test( currentPoppedValue == 89L );

		currentPoppedValue = 0;

		Assert_Test( testCircularBuffer_0.Push( 89L ) == true );
		Assert_Test( testCircularBuffer_0.Push( 89L ) == true );
		Assert_Test( testCircularBuffer_0.Push( 89L ) == true );
		Assert_Test( testCircularBuffer_0.Push( 89L ) == true );
		Assert_Test( testCircularBuffer_0.Push( 89L ) == true );
		Assert_Test( testCircularBuffer_0.Push( 89L ) == true );

		Assert_Test( testCircularBuffer_0.Pop( currentPoppedValue ) == true );
		Assert_Test( currentPoppedValue == 89L );

		currentPoppedValue = 0;

		Assert_Test( testCircularBuffer_0.Pop( currentPoppedValue ) == true );
		Assert_Test( currentPoppedValue == 89L );

		currentPoppedValue = 0;

		Assert_Test( testCircularBuffer_0.Pop( currentPoppedValue ) == true );
		Assert_Test( currentPoppedValue == 89L );

		currentPoppedValue = 0;

		Assert_Test( testCircularBuffer_0.Pop( currentPoppedValue ) == true );
		Assert_Test( currentPoppedValue == 89L );

		currentPoppedValue = 0;

		Assert_Test( testCircularBuffer_0.Pop( currentPoppedValue ) == true );
		Assert_Test( currentPoppedValue == 89L );

		currentPoppedValue = 0;

		Assert_Test( testCircularBuffer_0.Pop( currentPoppedValue ) == true );
		Assert_Test( currentPoppedValue == 89L );

		currentPoppedValue = 0;

		TestCircularBufferWithSpecificSize< 64UL >( 1000UL );
		TestCircularBufferWithSpecificSize< 256UL >( 100000UL );
		TestCircularBufferWithSpecificSize< 8UL >( 11111UL );
	}

//)  //  End of debug tool



}  //  Namespace MultiThread


}  //  Namespace Universe
