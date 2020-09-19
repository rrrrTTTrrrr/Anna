//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



	template< typename ObjectToTestType, typename ConstructorArgumentConstraintsTupleType, typename... ConstructorArgumentTypes >
 	inline void SanityCheck< ObjectToTestType, ConstructorArgumentConstraintsTupleType, ConstructorArgumentTypes... >::Full( const ConstructorArgumentConstraintsTupleType& constructorArgumentConstraintsTuple, UnsignedInteger64bits numberOfIterationsToPerform )
	{
		// Test the default constructor
		DefaultConstructor__Private();

		// Call the private method that performs the rest of the check
		Full__Private( constructorArgumentConstraintsTuple, numberOfIterationsToPerform );
	}


	template< typename ObjectToTestType, typename ConstructorArgumentConstraintsTupleType, typename... ConstructorArgumentTypes >
 	inline void SanityCheck< ObjectToTestType, ConstructorArgumentConstraintsTupleType, ConstructorArgumentTypes... >::Full_ForObjectWithStateAlwaysReady( const ConstructorArgumentConstraintsTupleType& constructorArgumentConstraintsTuple, UnsignedInteger64bits numberOfIterationsToPerform )
	{
		// Call the private method that performs the rest of the check
		Full__Private( constructorArgumentConstraintsTuple, numberOfIterationsToPerform );
	}


	template< typename ObjectToTestType, typename ConstructorArgumentConstraintsTupleType, typename... ConstructorArgumentTypes >
 	inline void SanityCheck< ObjectToTestType, ConstructorArgumentConstraintsTupleType, ConstructorArgumentTypes... >::NoMoveConstructorAndMoveAssignmentOperator( const ConstructorArgumentConstraintsTupleType& constructorArgumentConstraintsTuple, UnsignedInteger64bits numberOfIterationsToPerform )
	{
		// This is a compile time assertion. The compiler checks the condition during compile time, and the condition does not apply an error message will be displayed
		CompileTimeAssert( ( sizeof...( ConstructorArgumentTypes ) == constructorArgumentConstraintsTuple.Size() ), "The number of constructor arguments should be equal to the number of constraints" );

		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertSizeIsLargerThenZero_MACRO( numberOfIterationsToPerform );

		// Call the private method that test the functionality that each object must have. An incrementing integer sequence is provided to allow 
		// the private method to unpack the tuple members and call the parameterized constructor using it
		TestFunctionalityThatEachObjectMustHave__Private( constructorArgumentConstraintsTuple, numberOfIterationsToPerform, IncrementingIntegerSequence< sizeof...( ConstructorArgumentTypes ) >{} );

		// Call the private method that test the copy constructor and assignment operator. An incrementing integer sequence is provided to 
		// allow the private method to unpack the tuple members and call the parameterized constructor using it
		Test_CopyConstructor_AssignmentOperator__Private( constructorArgumentConstraintsTuple, numberOfIterationsToPerform, IncrementingIntegerSequence< sizeof...( ConstructorArgumentTypes ) >{} );
	}


	template< typename ObjectToTestType, typename ConstructorArgumentConstraintsTupleType, typename... ConstructorArgumentTypes >
 	inline void SanityCheck< ObjectToTestType, ConstructorArgumentConstraintsTupleType, ConstructorArgumentTypes... >::NoCopyConstructorAndAssignmentOperator( const ConstructorArgumentConstraintsTupleType& constructorArgumentConstraintsTuple, UnsignedInteger64bits numberOfIterationsToPerform )
	{
		// This is a compile time assertion. The compiler checks the condition during compile time, and the condition does not apply an error message will be displayed
		CompileTimeAssert( ( sizeof...( ConstructorArgumentTypes ) == constructorArgumentConstraintsTuple.Size() ), "The number of constructor arguments should be equal to the number of constraints" );

		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertSizeIsLargerThenZero_MACRO( numberOfIterationsToPerform );

		// Call the private method that test the functionality that each object must have. An incrementing integer sequence is provided to allow 
		// the private method to unpack the tuple members and call the parameterized constructor using it
		TestFunctionalityThatEachObjectMustHave__Private( constructorArgumentConstraintsTuple, numberOfIterationsToPerform, IncrementingIntegerSequence< sizeof...( ConstructorArgumentTypes ) >{} );

		// Call the private method that test the move constructor and move assignment operator. An incrementing integer sequence is provided to 
		// allow the private method to unpack the tuple members and call the parameterized constructor using it
		Test_MoveConstructor_MoveAssignmentOperator__Private( constructorArgumentConstraintsTuple, numberOfIterationsToPerform, IncrementingIntegerSequence< sizeof...( ConstructorArgumentTypes ) >{} );
	}


	template< typename ObjectToTestType, typename ConstructorArgumentConstraintsTupleType, typename... ConstructorArgumentTypes >
 	inline void SanityCheck< ObjectToTestType, ConstructorArgumentConstraintsTupleType, ConstructorArgumentTypes... >::NoCopyOrMove( const ConstructorArgumentConstraintsTupleType& constructorArgumentConstraintsTuple, UnsignedInteger64bits numberOfIterationsToPerform )
	{
		// This is a compile time assertion. The compiler checks the condition during compile time, and the condition does not apply an error message will be displayed
		CompileTimeAssert( ( sizeof...( ConstructorArgumentTypes ) == constructorArgumentConstraintsTuple.Size() ), "The number of constructor arguments should be equal to the number of constraints" );

		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertSizeIsLargerThenZero_MACRO( numberOfIterationsToPerform );

		// Call the private method that test the functionality that each object must have. An incrementing integer sequence is provided to allow 
		// the private method to unpack the tuple members and call the parameterized constructor using it
		TestFunctionalityThatEachObjectMustHave__Private( constructorArgumentConstraintsTuple, numberOfIterationsToPerform, IncrementingIntegerSequence< sizeof...( ConstructorArgumentTypes ) >{} );
	}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



	template< typename ObjectToTestType, typename ConstructorArgumentConstraintsTupleType, typename... ConstructorArgumentTypes >
 	inline void SanityCheck< ObjectToTestType, ConstructorArgumentConstraintsTupleType, ConstructorArgumentTypes... >::Full__Private( const ConstructorArgumentConstraintsTupleType& constructorArgumentConstraintsTuple, UnsignedInteger64bits numberOfIterationsToPerform )
	{
		// This is a compile time assertion. The compiler checks the condition during compile time, and the condition does not apply an error message will be displayed
		CompileTimeAssert( ( sizeof...( ConstructorArgumentTypes ) == constructorArgumentConstraintsTuple.Size() ), "The number of constructor arguments should be equal to the number of constraints" );

		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertSizeIsLargerThenZero_MACRO( numberOfIterationsToPerform );

		// Call the private method that test the functionality that each object must have. An incrementing integer sequence is provided to allow 
		// the private method to unpack the tuple members and call the parameterized constructor using it
		TestFunctionalityThatEachObjectMustHave__Private( constructorArgumentConstraintsTuple, numberOfIterationsToPerform, IncrementingIntegerSequence< sizeof...( ConstructorArgumentTypes ) >{} );

		// Call the private method that test the copy constructor and assignment operator. An incrementing integer sequence is provided to 
		// allow the private method to unpack the tuple members and call the parameterized constructor using it
		Test_CopyConstructor_AssignmentOperator__Private( constructorArgumentConstraintsTuple, numberOfIterationsToPerform, IncrementingIntegerSequence< sizeof...( ConstructorArgumentTypes ) >{} );

		// Call the private method that test the move constructor and move assignment operator. An incrementing integer sequence is provided to 
		// allow the private method to unpack the tuple members and call the parameterized constructor using it
		Test_MoveConstructor_MoveAssignmentOperator__Private( constructorArgumentConstraintsTuple, numberOfIterationsToPerform, IncrementingIntegerSequence< sizeof...( ConstructorArgumentTypes ) >{} );
	}


	template< typename ObjectToTestType, typename ConstructorArgumentConstraintsTupleType, typename... ConstructorArgumentTypes >
 	void SanityCheck< ObjectToTestType, ConstructorArgumentConstraintsTupleType, ConstructorArgumentTypes... >::DefaultConstructor__Private()
	{
		// Create an instance using the default constructor
		ObjectToTestType testDefaultConstructedInstance_1;

		// Assert that the instance is in default state
		Assert_Test_MACRO( testDefaultConstructedInstance_1.State().Get() == InstanceState::Default );

		// Create an instance using the default constructor
		ObjectToTestType testDefaultConstructedInstance_2;

		// Assert that the instance is in default state
		Assert_Test_MACRO( testDefaultConstructedInstance_1.State().Get() == InstanceState::Default );

		// Reset the instance
		testDefaultConstructedInstance_2.Reset();

		// Assert that the instance is in default state
		Assert_Test_MACRO( testDefaultConstructedInstance_2.State().Get() == InstanceState::Default );
	}

	template< typename ObjectToTestType, typename ConstructorArgumentConstraintsTupleType, typename... ConstructorArgumentTypes >
	template< UnsignedInteger64bits... ArgumentIndices >
 	inline void SanityCheck< ObjectToTestType, ConstructorArgumentConstraintsTupleType, ConstructorArgumentTypes... >::TestFunctionalityThatEachObjectMustHave__Private( const ConstructorArgumentConstraintsTupleType& constructorArgumentConstraintsTuple, UnsignedInteger64bits numberOfIterationsToPerform, IncrementingIntegerSequenceHolder< ArgumentIndices... > )
	{

		// Loop the required number of iterations
		for ( UnsignedInteger64bits iteration = 0UL ; iteration < numberOfIterationsToPerform ; ++iteration )
		{
			// Generate random arguments to use in this test iteration
			Tuple< ConstructorArgumentTypes... > randomGeneratedArguments( GenerateRandomInstance, constructorArgumentConstraintsTuple.template Entry< ArgumentIndices >()... );

			// Create an instance using the random generated arguments
			ObjectToTestType testInstance( randomGeneratedArguments.template Entry< ArgumentIndices >()... ); 

			// Assert that the instance is ready
			Assert_Test_MACRO( testInstance.State().Get() == InstanceState::Ready );
		}

	}


	template< typename ObjectToTestType, typename ConstructorArgumentConstraintsTupleType, typename... ConstructorArgumentTypes >
	template< UnsignedInteger64bits... ArgumentIndices >
 	void SanityCheck< ObjectToTestType, ConstructorArgumentConstraintsTupleType, ConstructorArgumentTypes... >::Test_CopyConstructor_AssignmentOperator__Private( const ConstructorArgumentConstraintsTupleType& constructorArgumentConstraintsTuple, UnsignedInteger64bits numberOfIterationsToPerform, IncrementingIntegerSequenceHolder< ArgumentIndices... > )
	{

		// Loop the required number of iterations
		for ( UnsignedInteger64bits iteration = 0UL ; iteration < numberOfIterationsToPerform ; ++iteration )
		{
			// Create an instance using the random generated arguments
			ObjectToTestType testInstance( GenerateRandomInstance, constructorArgumentConstraintsTuple.template Entry< ArgumentIndices >()... ); 

			// Assert that the instance is ready
			Assert_Test_MACRO( testInstance.State().Get() == InstanceState::Ready );

			// Construct an instance using the copy constructor
			ObjectToTestType testInstance_1( testInstance );

			// Assert that both instances are ready
			Assert_Test_MACRO( testInstance.State().Get() == InstanceState::Ready );
			Assert_Test_MACRO( testInstance_1.State().Get() == InstanceState::Ready );

			// Assert that both instances are the same using the equal operator
			Assert_Test_MACRO( ( testInstance == testInstance_1 ) );

			// Assert that both instances are the same using the not equal operator
			Assert_Test_MACRO( ( testInstance != testInstance_1 ) == false );

			// Construct an instance using the default constructor
			ObjectToTestType testInstance_2;

			// Assert that the instance is in default state
			Assert_Test_MACRO( testInstance_2.State().Get() == InstanceState::Default );

			// Use the assignment operator
			testInstance_2 = testInstance_1;

			// Assert that the three instances are ready
			Assert_Test_MACRO( testInstance.State().Get() == InstanceState::Ready );
			Assert_Test_MACRO( testInstance_1.State().Get() == InstanceState::Ready );
			Assert_Test_MACRO( testInstance_2.State().Get() == InstanceState::Ready );

			// Assert that three instances are the same using the equal operator
			Assert_Test_MACRO( ( testInstance == testInstance_1 ) && ( testInstance == testInstance_2 ) && ( testInstance_1 == testInstance_2 ) );

			// Assert that three instances are the same using the not equal operator
			Assert_Test_MACRO( ( ( testInstance != testInstance_1 ) == false ) && ( ( testInstance != testInstance_2 ) == false ) && ( ( testInstance_1 != testInstance_2 ) == false ) );
		}

	}


	template< typename ObjectToTestType, typename ConstructorArgumentConstraintsTupleType, typename... ConstructorArgumentTypes >
	template< UnsignedInteger64bits... ArgumentIndices >
 	void SanityCheck< ObjectToTestType, ConstructorArgumentConstraintsTupleType, ConstructorArgumentTypes... >::Test_MoveConstructor_MoveAssignmentOperator__Private( const ConstructorArgumentConstraintsTupleType& constructorArgumentConstraintsTuple, UnsignedInteger64bits numberOfIterationsToPerform, IncrementingIntegerSequenceHolder< ArgumentIndices... > )
	{

		// Loop the required number of iterations
		for ( UnsignedInteger64bits iteration = 0UL ; iteration < numberOfIterationsToPerform ; ++iteration )
		{
			// Create an instance using the random generated arguments
			ObjectToTestType testInstance( GenerateRandomInstance, constructorArgumentConstraintsTuple.template Entry< ArgumentIndices >()... ); 

			// Assert that the instance is ready
			Assert_Test_MACRO( testInstance.State().Get() == InstanceState::Ready );

			// Construct an instance using the move constructor
			ObjectToTestType testInstance_1( MOVE( testInstance ) );

			// Assert that the instance that the resources were taken from is in default state
			Assert_Test_MACRO( testInstance.State().Get() == InstanceState::Default );

			// Assert that the instance that took the resources is ready
			Assert_Test_MACRO( testInstance_1.State().Get() == InstanceState::Ready );

			// Use the move assignment operator
			testInstance = MOVE( testInstance_1 );

			// Assert that the instance that the resources were taken from is in default state
			Assert_Test_MACRO( testInstance_1.State().Get() == InstanceState::Default );

			// Assert that the instance that took the resources is ready
			Assert_Test_MACRO( testInstance.State().Get() == InstanceState::Ready );
		}

	}



// *********************************************************************************   TESTING   ********************************************************************************



	DEBUG_TOOL(

		template< typename ObjectToTestType COMMA typename ConstructorArgumentConstraintsTupleType COMMA typename... ConstructorArgumentTypes >
		void SanityCheck< ObjectToTestType COMMA ConstructorArgumentConstraintsTupleType COMMA ConstructorArgumentTypes... >::Test()
		{
			// Create a tuple with the constraints
			Tuple< NumericRange< UnsignedInteger64bits > COMMA NumericRange< UnsignedInteger64bits > COMMA NumericRange< Boolean > > constraintsTuple( NumericRange< UnsignedInteger64bits >( 1UL, 10000UL ), NumericRange< UnsignedInteger64bits >( 1UL, 10000UL ), NumericRange< Boolean >() );

			// Test the API
			SanityCheck< TestObject_1< UnsignedInteger64bits > COMMA Tuple< NumericRange< UnsignedInteger64bits > COMMA NumericRange< UnsignedInteger64bits > COMMA NumericRange< Boolean > > COMMA UnsignedInteger64bits COMMA UnsignedInteger64bits COMMA Boolean >::NoCopyOrMove( constraintsTuple, 3UL );
			SanityCheck< TestObject_1< UnsignedInteger64bits > COMMA Tuple< NumericRange< UnsignedInteger64bits > COMMA NumericRange< UnsignedInteger64bits > COMMA NumericRange< Boolean > > COMMA UnsignedInteger64bits COMMA UnsignedInteger64bits COMMA Boolean >::NoCopyConstructorAndAssignmentOperator( constraintsTuple, 3UL );
			SanityCheck< TestObject_1< UnsignedInteger64bits > COMMA Tuple< NumericRange< UnsignedInteger64bits > COMMA NumericRange< UnsignedInteger64bits > COMMA NumericRange< Boolean > > COMMA UnsignedInteger64bits COMMA UnsignedInteger64bits COMMA Boolean >::NoMoveConstructorAndMoveAssignmentOperator( constraintsTuple, 3UL );
			SanityCheck< TestObject_1< UnsignedInteger64bits > COMMA Tuple< NumericRange< UnsignedInteger64bits > COMMA NumericRange< UnsignedInteger64bits > COMMA NumericRange< Boolean > > COMMA UnsignedInteger64bits COMMA UnsignedInteger64bits COMMA Boolean >::Full( constraintsTuple, 3UL );
		}

	)  //  End of debug tool