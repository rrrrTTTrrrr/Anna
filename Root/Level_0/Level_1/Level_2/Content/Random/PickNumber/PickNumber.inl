//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



	// Method Information :
	//
	//  Description :
	//
	//		Default Constructor,
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename IntegerType >
	inline PickNumber< IntegerType >::PickNumber() :
	member_PassOnRangeInConstantJumpsInstances(),
	member_lastUsedEntry( 0UL )
	{
		// This object will store the current jump size
		IntegerType jumpSize = 1;

		// Loop on all the entries of the array
		for ( UnsignedInteger64bits instnaceIndex = 0UL ; instnaceIndex < member_numberOfInstancesToPassOnRangeInConstantJumps ; ++instnaceIndex )
		{
			// Initialize the current instance. Each instance will be given the jump size multiplied by 2 from the previous jump
			member_PassOnRangeInConstantJumpsInstances[ instnaceIndex ] = MOVE( PassOnRangeInConstantJumps< IntegerType >( jumpSize, 0 ) );

			// Multyply by 2 the jump size
			jumpSize *= 2;
		}

	}


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to pick a number in the range of the template integer type
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A number in the range of the template integer type
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename IntegerType >
	inline IntegerType PickNumber< IntegerType >::Get()
	{

		// Check if the last used entry is the last entry of the array
		if ( member_lastUsedEntry == member_numberOfInstancesToPassOnRangeInConstantJumps )
		{
			// The last used entry is the last entry of the array

			// Set the last used entry to the first entry
			member_lastUsedEntry = 0UL;
		}

		// Use the instance to pass on the range in constant jumps located at the current index of the array to return the next number
		return ( member_PassOnRangeInConstantJumpsInstances[ member_lastUsedEntry++ ].NextValue() );
	}


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to pick a number if the range of the template integer type is too large and should be narrowed down
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			range - this will be used to set the limits for the possible values used
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A number between the minimum and maximum provided
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename IntegerType >
	inline IntegerType PickNumber< IntegerType >::Get( NumericRange< IntegerType > range )
	{

		// Check if the last used entry is the last entry of the array
		if ( member_lastUsedEntry == member_numberOfInstancesToPassOnRangeInConstantJumps )
		{
			// The last used entry is the last entry of the array

			// Set the last used entry to the first entry
			member_lastUsedEntry = 0UL;
		}

		// Pick the next number
		IntegerType pickedNumber = ( member_PassOnRangeInConstantJumpsInstances[ member_lastUsedEntry ].NextValue() );

		// Increment the last used entry by 1
		member_lastUsedEntry += 1UL;

		// The process to ensure that all the numbers are within the required range :
		//
		// 	The first stage is to calculate the range size by taking the subtraction result of the minimum from the maximum. Now this size will be
		//	used as the right side operand in the modulo operation on the random number. This will result in a number in the range :
		//
		//			[ 0, ( size - 1 ) ]
		//
		// And now this result can be added to the minimum of the range, and it will always land on a number within the range! This is correct for
		// positive values, the case is a little different for negative values, therefore negative values will be converted to their positive form

		// Check if the picked number is negative
		if ( pickedNumber < 0 )
		{
			// The picked number is negative

			// Multiply the picked number by -1 to make it positive
			pickedNumber *= -1;
		}

		// The picked number is positive!!

		// Add the minimum value of the range to the picked number and return the result
		return ( ( pickedNumber % range.Size() ) + range.Minimum() );
	}




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - IntegerType = Boolean   ************************************************* //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //




//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



	// Method Information :
	//
	//  Description :
	//
	//		Default Constructor,
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline PickNumber< Boolean >::PickNumber() :
	member_pickNumber()
	{}


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to pick a number in the range of the template integer type
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A number in the range of the template integer type
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline Boolean PickNumber< Boolean >::Get()
	{
		// Use the instance to pass on the range in constant jumps located at the current index of the array to return the next number
		return ( member_pickNumber.Get( NumericRange< UnsignedInteger8bits >( 0U, 2U ) ) );
	}


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to pick a number if the range of the template integer type is too large and should be narrowed down
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			range - this will be used to set the limits for the possible values used
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A number between the minimum and maximum provided
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline Boolean PickNumber< Boolean >::Get( NumericRange< Boolean > )
	{
		// Use the instance to pass on the range in constant jumps located at the current index of the array to return the next number
		return ( member_pickNumber.Get( NumericRange< UnsignedInteger8bits >( 0U, 2U ) ) );
	}



// *********************************************************************************   TESTING   ********************************************************************************



	DEBUG_TOOL(

		// Method Information :
		//
		//  Description :
		//
		//      This method is used to test the object. It is not part of the implementation, it is only used to find problem with the code that does implement
		//		the functionality
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			NONE
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//      1. true - if the object passed the test
		//      2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		1. An assertion failed - class Exception or ErrnoException is thrown
		//		2. There is no more free memory space - class std::bad_alloc is thrown
		//		3. 
		//
		template< typename IntegerType >
		inline void PickNumber< IntegerType >::Test()
		{
			// Create an instance
			PickNumber< UnsignedInteger8bits > testPickNumber_1;

			// Just ensure the code does not crash
			for ( UnsignedInteger64bits iteration = 0UL ; iteration < 100000UL ; ++iteration )
			{
				testPickNumber_1.Get();
			}

			// Create an instance
			PickNumber< UnsignedInteger64bits > testPickNumber_2;

			// Just ensure the code does not crash
			for ( UnsignedInteger64bits iteration = 0UL ; iteration < 10000UL ; ++iteration )
			{
				testPickNumber_2.Get();
			}

			// Create an instance
			PickNumber< UnsignedInteger16bits > testPickNumber_3;

			// Just ensure the code does not crash
			for ( UnsignedInteger64bits iteration = 0UL ; iteration < 10000UL ; ++iteration )
			{
				// Store the current random number
				UnsignedInteger16bits currentNumber = testPickNumber_3.Get( NumericRange< UnsignedInteger16bits >( 620U, 2340U ) );

				// Check that the given number is in the range
				Assert_MACRO( ( currentNumber >= 620U ) && ( currentNumber <= 2340U ), "Test failed - 1" );
			}

			// Create an instance
			PickNumber< UnsignedInteger64bits > testPickNumber_4;

			// Just ensure the code does not crash
			for ( UnsignedInteger64bits iteration = 0UL ; iteration < 10000UL ; ++iteration )
			{
				// Store the current random number
				UnsignedInteger64bits currentNumber = testPickNumber_4.Get( NumericRange( 4500UL, 123000UL ) );

				// Check that the given number is in the range
				Assert_MACRO( ( currentNumber >= 4500U ) && ( currentNumber <= 123000U ), "Test failed - 2" );
			}

		}

	)  //  End of debug tool
