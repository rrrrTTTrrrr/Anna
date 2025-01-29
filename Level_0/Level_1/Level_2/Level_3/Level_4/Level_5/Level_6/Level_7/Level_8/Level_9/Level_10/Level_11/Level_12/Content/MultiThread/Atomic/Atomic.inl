//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< Concepts::BuiltIn BuiltInType >
inline Atomic< BuiltInType >::Atomic() :
	member_variable( 0 )
{}


template< Concepts::BuiltIn BuiltInType >
inline Atomic< BuiltInType >::Atomic( const BuiltInType value ) :
	member_variable( value )
{}


template< Concepts::BuiltIn BuiltInType >
inline Atomic< BuiltInType >::Atomic( const SelfType& other ) :
	member_variable( other.member_variable )
{}


template< Concepts::BuiltIn BuiltInType >
inline BuiltInType Atomic< BuiltInType >::Load() const
{
	// Read the value. The value will be read from system memory no matter what the state of the cache is. Finally return the value
	return ( Compiler_EnsureReadingVariableFromSystemMemory( member_variable ) );
}


template< Concepts::BuiltIn BuiltInType >
inline void Atomic< BuiltInType >::SetValue( const BuiltInType newValue )
{
	// Set the variable with the new value. The value will be written to system memory, and all other central processing units using the same
	// system memory caches will be invalidated to ensure they will read the new value from system memory before using it
	member_variable = newValue;

	// Ensure that the compiler will not reorder write across this barrier, and all operations after will have a coherent view of the 
	// variable value
	CompilerBarrier_AllPreviousMemoryAccessesWillNotBeReorderedWithTheNextMemoryAccesses;

	// Ensure that the central processing unit will not reorder write across this barrier, and all operations after will have a coherent
	// view of the variable value
	CentralProcessingUnit_MemoryBarrier_EnsureAllDataWasWrittenToSystemMemory;
}


template< Concepts::BuiltIn BuiltInType >
inline BuiltInType Atomic< BuiltInType >::AddAndReturnOldValue( const BuiltInType valueToAdd )
{
	// Try getting the value of the variable from cache. If the cache is invalidated, fetch the value from system memory. Now increment the
	// value by the required amount, and write the value back to system memory. Ensure that all central processing are aware of the change, 
	// by invalidating the proper caches. Finally return the old value, before the addition
	return ( CentralProcessingUnit::CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::Read_Add_Write_ReturnOldValue( &member_variable, valueToAdd ) );
}


template< Concepts::BuiltIn BuiltInType >
inline BuiltInType Atomic< BuiltInType >::SubtractAndReturnOldValue( const BuiltInType valueToSubtract )
{
	// Try getting the value of the variable from cache. If the cache is invalidated, fetch the value from system memory. Now decrement the
	// value by the required amount, and write the value back to system memory. Ensure that all central processing are aware of the change, 
	// by invalidating the proper caches. Finally return the old value, before the subtraction
	return ( CentralProcessingUnit::CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::Read_Add_Write_ReturnOldValue( &member_variable, -valueToSubtract ) );
}


template< Concepts::BuiltIn BuiltInType >
inline Boolean Atomic< BuiltInType >::CompareTheActualValueWithTheExpectedAndIfEqualSetTheDesiredValue( BuiltInType& expectedValue, const BuiltInType desiredValue )
{
	// Try getting the value of the variable from cache. If the cache is invalidated, fetch the value from system memory. Now compare it 
	// with the given value. If the comparison is true write the required new value, instead of the old one, to system memory. Ensure that
	// all central processing are aware of the change, by invalidating the proper caches. Finally return the result of the comparison
	return ( CentralProcessingUnit::CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::Read_Compare_IfTrueStoreTheDesiredValueInstead( &member_variable, expectedValue, desiredValue ) );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< Concepts::BuiltIn BuiltInType >
EnsureRetrunValueIsUsed inline Atomic< BuiltInType >::operator BuiltInType() const
{
	return ( Load() );
}


template< Concepts::BuiltIn BuiltInType >
inline Atomic< BuiltInType >& Atomic< BuiltInType >::operator=( const BuiltInType value )
{
	// Set the value
	SetValue( value );

	// Return a reference to this instance
	return ( *this );
}


template< Concepts::BuiltIn BuiltInType >
inline Atomic< BuiltInType >& Atomic< BuiltInType >::operator+=( const BuiltInType valueToAdd )
{
	// Try getting the value of the variable from cache. If the cache is invalidated, fetch the value from system memory. Now increment the
	// value by the required amount, and write the value back to system memory. Ensure that all central processing are aware of the change, 
	// by invalidating the proper caches
	CentralProcessingUnit::CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::Read_Add_Write( &member_variable, valueToAdd );

	// Return a reference to this instance
	return ( *this );
}


template< Concepts::BuiltIn BuiltInType >
inline Atomic< BuiltInType >& Atomic< BuiltInType >::operator-=( const BuiltInType valueToSubtract )
{
	// Try getting the value of the variable from cache. If the cache is invalidated, fetch the value from system memory. Now decrement the
	// value by the required amount, and write the value back to system memory. Ensure that all central processing are aware of the change, 
	// by invalidating the proper caches
	CentralProcessingUnit::CoherentSystemMemoryAndCacheOperationAcrossAllSharingCentralProcessingUnits::Read_Subtract_Write( &member_variable, valueToSubtract );

	// Return a reference to this instance
	return ( *this );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< Concepts::BuiltIn BuiltInType >
	inline void Atomic< BuiltInType >::UnitTest()
	{
		// Create a test instance
		Atomic< UnsignedInteger64bits > testInstance_0;

		// Assert that the value is 0
		Assert_Test( testInstance_0.Load() == 0UL );

		// Increment the value by 10
		testInstance_0 += 10UL;

		// Assert that the value is 0
		Assert_Test( testInstance_0.Load() == 10UL );

		// Decrement the value by 10
		testInstance_0 -= 10UL;

		// Assert that the value is 0
		Assert_Test( testInstance_0.Load() == 0UL );

		// Increment the value by 10
		testInstance_0 += 10UL;

		// Decrement the value by 3
		testInstance_0 -= 3UL;

		// Assert that the value is 0
		Assert_Test( testInstance_0.Load() == 7UL );

		// Decrement the value by 8
		testInstance_0 -= 8UL;

		// Assert that the value is 0
		Assert_Test( testInstance_0.Load() == 0UL - 1UL );

		// Create a test instance
		Atomic< UnsignedInteger64bits > testInstance_1;

		// Assert that the value is 0
		Assert_Test( testInstance_1.Load() == 0UL );

		// Increment the value by 10
		testInstance_1 += 10UL;

		// Assert that the value is 0
		Assert_Test( testInstance_1.Load() == 10UL );

		// Decrement the value by 10
		Assert_Test( testInstance_1.SubtractAndReturnOldValue( 10UL ) == 10UL );

		// Assert that the value is 0
		Assert_Test( testInstance_1.Load() == 0UL );

		// Increment the value by 10
		testInstance_1 += 10UL;

		// Decrement the value by 3
		Assert_Test( testInstance_1.SubtractAndReturnOldValue( 3UL ) == 10UL );

		// Assert that the value is 0
		Assert_Test( testInstance_1.Load() == 7UL );

		// Decrement the value by 8
		Assert_Test( testInstance_1.SubtractAndReturnOldValue( 8UL ) == 7UL );

		// Assert that the value is 0
		Assert_Test( testInstance_1.Load() == 0UL - 1UL );

		// Create a test instance
		Atomic< SignedInteger64bits > testInstance_2;

		// Assert that the value is 0
		Assert_Test( testInstance_2.Load() == 0 );

		// Increment the value by 10
		testInstance_2 += 10;

		// Assert that the value is 0
		Assert_Test( testInstance_2.Load() == 10 );

		// Create a test instance by copy constructor
		Atomic< SignedInteger64bits > testInstance_3( testInstance_2 );

		// Create a test instance by copy constructor
		Atomic< SignedInteger64bits > testInstance_4( testInstance_2 );

		// Create a test instance
		Atomic< Boolean > testInstance_5( true );
		Boolean expectedValue_5 = true;

		Assert_Test( testInstance_5.CompareTheActualValueWithTheExpectedAndIfEqualSetTheDesiredValue( expectedValue_5, false ) == true );
		Assert_Test( testInstance_5.CompareTheActualValueWithTheExpectedAndIfEqualSetTheDesiredValue( expectedValue_5, true ) == false );
	}

)  //  End of debug tool



}  //  Namespace MultiThread


}  //  Namespace Universe