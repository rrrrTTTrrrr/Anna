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
	inline PassOnRangeInConstantJumps< IntegerType >::PassOnRangeInConstantJumps() :
	member_currentValue( 0 ),
	member_jumpSize( 0 )
	{}


	// Method Information :
	//
	//  Description :
	//
	//		Constructor,
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. jumpSize - each time a next value will be used this will be the jump between the 2 values
	//			2. startingValue - the first value to will be returned when using the isntance
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
	inline PassOnRangeInConstantJumps< IntegerType >::PassOnRangeInConstantJumps( IntegerType jumpSize, IntegerType startingValue ) :
	member_currentValue( startingValue ),
	member_jumpSize( jumpSize )
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid
		Assert_MACRO( ( jumpSize != 0 ), "The given jump size must not be 0" );
	}


	// Method Information :
	//
	//  Description :
	//
	//		Copy constructor, will operate correctly even if the other instance is in default state or self assignment
	//
	//  Required arguments :
	//
    //		User information needed :
	//
	//			other - a reference to the instance that should be copied
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
	inline PassOnRangeInConstantJumps< IntegerType >::PassOnRangeInConstantJumps( const SelfType& other ) :
	member_currentValue( other.member_currentValue ),
	member_jumpSize( other.member_jumpSize )
	{}


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to perfrom the jump from the current value, and return a copy of the new value
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
	//		The next value in the range
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename IntegerType >
	inline IntegerType PassOnRangeInConstantJumps< IntegerType >::NextValue()
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid
		Assert_MACRO( ( member_jumpSize != 0 ), "The jump size must not be 0, this can only happen if the instance resources was moved" );

		// Perform the jump to the next value in the range, and store it
		member_currentValue += member_jumpSize;

		// Return a copy of the next value 
		return ( member_currentValue );
	}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



	// Method Information :
	//
	//  Description :
	//
	//      This method will be used to assert all the requirements on the template arguments provided to the object. To perform a compile time assert
	//		the C++ language provides the keyword 'static_assert', which receives an expression and an error message to display if the expression
	//		result is false. The important thing is that the expression is evaluted during compile time, and therefore if the expression is false
	//		the compilation will be terminated and the error message will be displayed. This method should not be used, because it does nothing during
	//		run time
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          NONE
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      NONE
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
	inline void PassOnRangeInConstantJumps< IntegerType >::AssertTemplateArgumentsRequirementsDuringCompileTime__Private() const
	{
		// This method will contain as much as neccessary compile time assertions to check that the given template arguments pass the requirements
		CompileTimeAssert( ( TypeCheck_Integer< IntegerType >::Result() == true ), "Random::PassOnRangeInConstantJumps failed - the given template type should be shallow copied type" );
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
		inline void PassOnRangeInConstantJumps< IntegerType >::Test()
		{}

	)  //  End of debug tool