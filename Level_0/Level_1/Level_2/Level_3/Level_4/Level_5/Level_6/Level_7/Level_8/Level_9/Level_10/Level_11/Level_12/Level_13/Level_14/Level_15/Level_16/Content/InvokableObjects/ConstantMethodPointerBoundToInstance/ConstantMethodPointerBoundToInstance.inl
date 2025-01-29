//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< typename ObjectType, typename ReturnType, typename... ArgumentTypes >
inline ConstantMethodPointerBoundToInstance< ObjectType, ReturnType ( ArgumentTypes... ) >::ConstantMethodPointerBoundToInstance() :
	member_instance( nullptr ),
	member_constantMethodPointer( nullptr )
{}


template< typename ObjectType, typename ReturnType, typename... ArgumentTypes >
inline ConstantMethodPointerBoundToInstance< ObjectType, ReturnType ( ArgumentTypes... ) >::ConstantMethodPointerBoundToInstance( const ObjectType& instance, ConstantMethodPointerType const constantMethodRawPointer ) :
	member_instance( &instance ),
	member_constantMethodPointer( constantMethodRawPointer )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertPointerIsNotNull( constantMethodRawPointer );
}


template< typename ObjectType, typename ReturnType, typename... ArgumentTypes >
inline ConstantMethodPointerBoundToInstance< ObjectType, ReturnType ( ArgumentTypes... ) >::ConstantMethodPointerBoundToInstance( const SelfType& other ) :
	member_instance( other.member_instance ),
	member_constantMethodPointer( other.member_constantMethodPointer )
{}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< typename ObjectType, typename ReturnType, typename... ArgumentTypes >
ReturnType ConstantMethodPointerBoundToInstance< ObjectType, ReturnType ( ArgumentTypes... ) >::operator()( ArgumentTypes... arguments )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertPointerIsNotNull( member_instance );
	AssertPointerIsNotNull( member_constantMethodPointer );

	// Invoke the method using the arguments on the instance of the object that contains the method, and return value
	return ( ( member_instance->*member_constantMethodPointer )( ForwardUniversalReference< ArgumentTypes >( arguments )... ) );
}


template< typename ObjectType, typename ReturnType, typename... ArgumentTypes >
ReturnType ConstantMethodPointerBoundToInstance< ObjectType, ReturnType ( ArgumentTypes... ) >::operator()( ArgumentTypes... arguments ) const
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertPointerIsNotNull( member_instance );
	AssertPointerIsNotNull( member_constantMethodPointer );

	// Invoke the method using the arguments on the instance of the object that contains the method, and return value
	return ( ( member_instance->*member_constantMethodPointer )( ForwardUniversalReference< ArgumentTypes >( arguments )... ) );
}


template< typename ObjectType, typename ReturnType, typename... ArgumentTypes >
inline ReturnType ConstantMethodPointerBoundToInstance< ObjectType, ReturnType ( ArgumentTypes... ) >::operator()( const Memory::Tuple< ArgumentTypes... >& arguments ) const
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertPointerIsNotNull( member_instance );
	AssertPointerIsNotNull( member_constantMethodPointer );

    // Set the return value from invoking the function with the tuple of arguments, and return the value
    return ( InvokeUsingTuple__Private( arguments, IncrementingIntegerSequence< sizeof...( ArgumentTypes ) >{} ) );
}


template< typename ObjectType, typename ReturnType, typename... ArgumentTypes >
inline Boolean ConstantMethodPointerBoundToInstance< ObjectType, ReturnType ( ArgumentTypes... ) >::operator==( const SelfType& other ) const
{
	// Check if the instances point to the same function, and return the result
	return ( member_constantMethodPointer == other.member_constantMethodPointer && member_instance == other.member_instance );
}


template< typename ObjectType, typename ReturnType, typename... ArgumentTypes >
inline Boolean ConstantMethodPointerBoundToInstance< ObjectType, ReturnType ( ArgumentTypes... ) >::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



template< typename ObjectType, typename ReturnType, typename... ArgumentTypes >
template< UnsignedInteger64bits... ArgumentIndices >
inline ReturnType ConstantMethodPointerBoundToInstance< ObjectType, ReturnType ( ArgumentTypes... ) >::InvokeUsingTuple__Private( const Memory::Tuple< ArgumentTypes... >& arguments, IncrementingIntegerSequenceHolder< ArgumentIndices... > ) const
{
    // Invoke the method with the given tuple of arguments
    return ( ( member_instance->*member_constantMethodPointer )( arguments.template Entry< ArgumentIndices >()... ) );
}



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - No arguments to function   ************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< typename ObjectType, typename ReturnType >
inline ConstantMethodPointerBoundToInstance< ObjectType, ReturnType () >::ConstantMethodPointerBoundToInstance() :
	member_instance( nullptr ),
	member_constantMethodPointer( nullptr )
{}


template< typename ObjectType, typename ReturnType >
inline ConstantMethodPointerBoundToInstance< ObjectType, ReturnType () >::ConstantMethodPointerBoundToInstance( const ObjectType& instance, ConstantMethodPointerType const constantMethodRawPointer ) :
	member_instance( &instance ),
	member_constantMethodPointer( constantMethodRawPointer )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertPointerIsNotNull( constantMethodRawPointer );
}


template< typename ObjectType, typename ReturnType >
inline ConstantMethodPointerBoundToInstance< ObjectType, ReturnType () >::ConstantMethodPointerBoundToInstance( const SelfType& other ) :
	member_instance( other.member_instance ),
	member_constantMethodPointer( other.member_constantMethodPointer )
{}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************


template< typename ObjectType, typename ReturnType >
ReturnType ConstantMethodPointerBoundToInstance< ObjectType, ReturnType () >::operator()()
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertPointerIsNotNull( member_instance );
	AssertPointerIsNotNull( member_constantMethodPointer );

	// Invoke the method, and return the value
	return ( ( member_instance->*member_constantMethodPointer )() );
}


template< typename ObjectType, typename ReturnType >
ReturnType ConstantMethodPointerBoundToInstance< ObjectType, ReturnType () >::operator()() const
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertPointerIsNotNull( member_instance );
	AssertPointerIsNotNull( member_constantMethodPointer );

	// Invoke the method, and return the value
	return ( ( member_instance->*member_constantMethodPointer )() );
}


template< typename ObjectType, typename ReturnType >
inline Boolean ConstantMethodPointerBoundToInstance< ObjectType, ReturnType () >::operator==( const SelfType& other ) const
{
	// Check if the instances point to the same function, and return the result
	return ( member_constantMethodPointer == other.member_constantMethodPointer && member_instance == other.member_instance );
}


template< typename ObjectType, typename ReturnType >
inline Boolean ConstantMethodPointerBoundToInstance< ObjectType, ReturnType () >::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< typename ObjectType COMMA typename ReturnType COMMA typename... ArgumentTypes >
	inline void ConstantMethodPointerBoundToInstance< ObjectType COMMA ReturnType ( ArgumentTypes... ) >::UnitTest()
	{
		// Create a test instance 
		const Test::Object testObject_1( 654, 56 );

		// Create an instance
		ConstantMethodPointerBoundToInstance< Test::Object COMMA UnsignedInteger32bits ( UnsignedInteger32bits COMMA UnsignedInteger64bits ) > testMethodPointer_1( testObject_1, &Test::Object::Method_1_Constant );

		// Invoke the method
		testMethodPointer_1( 8, 9 );

		// Check that the number of arguments is correct
        Assert_Test( testMethodPointer_1.ArgumentsNumber() == 2 );

		// Check that there is return value
        Assert_Test( testMethodPointer_1.ReturnValueExist() == true );

		// Create an instance
		ConstantMethodPointerBoundToInstance< Test::Object COMMA UnsignedInteger32bits ( UnsignedInteger32bits COMMA UnsignedInteger64bits COMMA UnsignedInteger64bits ) > testMethodPointer_2( testObject_1, &Test::Object::Method_2_Constant );

		// Invoke the method
		auto testReturnValue_1 = testMethodPointer_2( 8, 9, 84758 );

		// Check that the number of arguments is correct
        Assert_Test( testMethodPointer_2.ArgumentsNumber() == 3 );

		// Check that the return value is correct
        Assert_Test( testReturnValue_1 == 99 );

        // Check for a function that doesn't has no retrun value or arguments
        ConstantMethodPointerBoundToInstance< Test::Object COMMA void () > testMethodPointer_3( testObject_1, &Test::Object::Method_3_Constant );

		// Invoke the method
		testMethodPointer_3();

		// Check that the number of arguments is correct
        Assert_Test( testMethodPointer_3.ArgumentsNumber() == 0 );

        // Create an instance of the tuple function pointer
        ConstantMethodPointerBoundToInstance< Test::Object COMMA UnsignedInteger32bits ( UnsignedInteger32bits COMMA UnsignedInteger64bits COMMA UnsignedInteger64bits ) > testMethodPointer_4( testObject_1, &Test::Object::Method_2_Constant );

        // Check that the number of arguments is correct
        Assert_Test( testMethodPointer_4.ArgumentsNumber() == 3 );

        // Invoke the method using a parameter pack
        auto testReturnValue_2 = testMethodPointer_4( 99, 100, 101 );

        // Check that the return value is correct
        Assert_Test( testReturnValue_2 == 99 );

        // Create a tuple instance
        Memory::Tuple< UnsignedInteger32bits COMMA UnsignedInteger64bits COMMA UnsignedInteger64bits > testTuple_1( 8, 9, 84758 );

        // Invoke the method using the tuple
        auto testReturnValue_3 = testMethodPointer_4( testTuple_1 );

        // Check that the return value is correct
        Assert_Test( testReturnValue_3 == 99 );

        // Create an instance of the tuple function pointer
        ConstantMethodPointerBoundToInstance< Test::Object COMMA void ( UnsignedInteger32bits COMMA UnsignedInteger64bits ) > TestMethodPointer_5( testObject_1, &Test::Object::Method_5_Constant );

        // Check that the number of arguments is correct
        Assert_Test( TestMethodPointer_5.ArgumentsNumber() == 2 );

        // Invoke the method using a parameter pack
        TestMethodPointer_5( 99, 100 );

        // Create a tuple instance
        Memory::Tuple< UnsignedInteger32bits COMMA UnsignedInteger64bits > testTuple_2( 8, 9 );

        // Invoke the method using the tuple
        TestMethodPointer_5( testTuple_2 );

        // Create an instance of the tuple function pointer
        ConstantMethodPointerBoundToInstance< Test::Object COMMA UnsignedInteger32bits () > testMethodPointer_6( testObject_1, &Test::Object::Method_4_Constant );

        // Invoke the method
        testMethodPointer_6();
	}

)  //  End of debug tool



}  //  Namespace Universe