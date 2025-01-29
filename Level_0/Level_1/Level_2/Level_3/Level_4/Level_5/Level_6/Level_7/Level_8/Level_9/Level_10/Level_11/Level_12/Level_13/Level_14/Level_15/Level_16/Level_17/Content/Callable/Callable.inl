// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *********************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Invokable ojbect with arguments   *********************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< typename ReturnType, typename... ArgumentTypes >
inline Callable< ReturnType ( ArgumentTypes... ) >::Callable() :
	member_callablePointer( nullptr )
{}


template< typename ReturnType, typename... ArgumentTypes >
inline Callable< ReturnType ( ArgumentTypes... ) >::Callable( SelfFunctionType const* rawFunctionPointer ) :
	member_callablePointer( Memory::MainMemoryManager::template AllocateAndConstruct< FunctionPointer< SelfFunctionType > >( rawFunctionPointer ) )
{}


template< typename ReturnType, typename... ArgumentTypes >
inline Callable< ReturnType ( ArgumentTypes... ) >::Callable( const FunctionPointer< SelfFunctionType >& functionPointer ) :
	member_callablePointer( Memory::MainMemoryManager::template AllocateAndConstruct< FunctionPointer< SelfFunctionType > >( functionPointer ) )
{}


template< typename ReturnType, typename... ArgumentTypes >
template< typename ObjectType, typename MethodType >
inline Callable< ReturnType ( ArgumentTypes... ) >::Callable( ObjectType& instance, MethodType&& methodRawPointer ) :
	member_callablePointer( Memory::MainMemoryManager::template AllocateAndConstruct< MethodPointerBoundToInstance< ObjectType, SelfFunctionType >, ObjectType&, ReturnType ( ObjectType::* )( ArgumentTypes... ) >( instance, methodRawPointer ) )
{}


template< typename ReturnType, typename... ArgumentTypes >
template< typename ObjectType >
inline Callable< ReturnType ( ArgumentTypes... ) >::Callable( const MethodPointerBoundToInstance< ObjectType, SelfFunctionType >& methodPointerBoundToInstance ) :
	member_callablePointer( Memory::MainMemoryManager::template AllocateAndConstruct< MethodPointerBoundToInstance< ObjectType, SelfFunctionType > >( methodPointerBoundToInstance ) )
{}


template< typename ReturnType, typename... ArgumentTypes >
template< typename ObjectType, typename ConstantMethodType >
inline Callable< ReturnType ( ArgumentTypes... ) >::Callable( const ObjectType& instance, ConstantMethodType&& constantMethodRawPointer ) :
	member_callablePointer( Memory::MainMemoryManager::template AllocateAndConstruct< ConstantMethodPointerBoundToInstance< ObjectType, SelfFunctionType >, const ObjectType&, ReturnType ( ObjectType::* )( ArgumentTypes... ) const >( instance, constantMethodRawPointer ) )
{}


template< typename ReturnType, typename... ArgumentTypes >
template< typename ObjectType >
inline Callable< ReturnType ( ArgumentTypes... ) >::Callable( const ConstantMethodPointerBoundToInstance< ObjectType, ReturnType ( ArgumentTypes... ) >& constantMethodPointerBoundToInstance ) :
	member_callablePointer( Memory::MainMemoryManager::template AllocateAndConstruct< ConstantMethodPointerBoundToInstance< ObjectType, ReturnType ( ArgumentTypes... ) > >( constantMethodPointerBoundToInstance ) )
{}


template< typename ReturnType, typename... ArgumentTypes >
template< typename FunctorType > requires ( ( Concepts::Functor< FunctorType, ArgumentTypes... > ) && ( !Concepts::SameAsRegardlessOfTemplateArguments< FunctorType, MethodPointerBoundToInstance< FunctorType, ReturnType ( ArgumentTypes... ) > > ) && ( !Concepts::SameAsRegardlessOfTemplateArguments< FunctorType, ConstantMethodPointerBoundToInstance< FunctorType, ReturnType ( ArgumentTypes... ) > > ) )
inline Callable< ReturnType ( ArgumentTypes... ) >::Callable( FunctorType& functor ) :
	member_callablePointer( Memory::MainMemoryManager::template AllocateAndConstruct< InvokableObjectInterfaceWrapper< FunctorType, ReturnType, ArgumentTypes... >, FunctorType& >( functor ) )
{}


template< typename ReturnType, typename... ArgumentTypes >
template< typename FunctorType > requires ( ( Concepts::Functor< FunctorType, ArgumentTypes... > ) && ( !Concepts::SameAsRegardlessOfTemplateArguments< FunctorType, MethodPointerBoundToInstance< FunctorType, ReturnType ( ArgumentTypes... ) > > ) && ( !Concepts::SameAsRegardlessOfTemplateArguments< FunctorType, ConstantMethodPointerBoundToInstance< FunctorType, ReturnType ( ArgumentTypes... ) > > ) )
inline Callable< ReturnType ( ArgumentTypes... ) >::Callable( const FunctorType& functor ) :
	member_callablePointer( Memory::MainMemoryManager::template AllocateAndConstruct< InvokableObjectInterfaceWrapper< FunctorType, ReturnType, ArgumentTypes... >, const FunctorType& >( functor ) )
{}


template< typename ReturnType, typename... ArgumentTypes >
inline Callable< ReturnType ( ArgumentTypes... ) >::~Callable()
{
    // Check if the instance was constructed using the default constructor or the 'Reset' method was used, which usually signify that there
    // are no resources used by the instance, and nothing needs to be done further in the destructor
    ReturnIfExpressionIsTrue( member_callablePointer == nullptr );

    // Release the memory space used for the invokable object
    Memory::MainMemoryManager::template Done< InvokableObjectInterface< ReturnType, ArgumentTypes... > >( member_callablePointer );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< typename ReturnType, typename... ArgumentTypes >
inline ReturnType Callable< ReturnType ( ArgumentTypes... ) >::operator()( ArgumentTypes... arguments )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertPointerIsNotNull( member_callablePointer );

	// Execute the function using the arguments, and return the value
	return ( member_callablePointer->operator()( ForwardUniversalReference< ArgumentTypes >( arguments )... ) );
}


template< typename ReturnType, typename... ArgumentTypes >
inline ReturnType Callable< ReturnType ( ArgumentTypes... ) >::operator()( ArgumentTypes... arguments ) const
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertPointerIsNotNull( member_callablePointer );

	// Execute the function using the arguments, and return the value
	return ( member_callablePointer->operator()( ForwardUniversalReference< ArgumentTypes >( arguments )... ) );
}


template< typename ReturnType, typename... ArgumentTypes >
inline ReturnType Callable< ReturnType ( ArgumentTypes... ) >::operator()( const Memory::Tuple< ArgumentTypes... >& argumentsTuple )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertPointerIsNotNull( member_callablePointer );

	// Invoke the function with the tuple of arguments, and return the value
	return ( InvokeUsingTuple__Private( argumentsTuple, IncrementingIntegerSequence< sizeof...( ArgumentTypes ) >{} ) );
}


template< typename ReturnType, typename... ArgumentTypes >
inline ReturnType Callable< ReturnType ( ArgumentTypes... ) >::operator()( const Memory::Tuple< ArgumentTypes... >& argumentsTuple ) const
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertPointerIsNotNull( member_callablePointer );

	// Invoke the function with the tuple of arguments, and return the value
	return ( InvokeUsingTuple__Private( argumentsTuple, IncrementingIntegerSequence< sizeof...( ArgumentTypes ) >{} ) );
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



template< typename ReturnType, typename... ArgumentTypes >
template< UnsignedInteger64bits... ArgumentIndices >
inline ReturnType Callable< ReturnType ( ArgumentTypes... ) >::InvokeUsingTuple__Private( const Memory::Tuple< ArgumentTypes... >& argumentsTuple, IncrementingIntegerSequenceHolder< ArgumentIndices... > ) const
{
	// Invoke the function with the given tuple of arguments
	return ( member_callablePointer->operator()( argumentsTuple.template Entry< ArgumentIndices >()... ) );
}



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *********************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Invokable object with no arguments   *********************************************//
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< typename ReturnType >
inline Callable< ReturnType () >::Callable() :
	member_callablePointer( nullptr )
{}


template< typename ReturnType >
inline Callable< ReturnType () >::Callable( SelfFunctionType* const rawFunctionPointer ) :
	member_callablePointer( Memory::MainMemoryManager::template AllocateAndConstruct< FunctionPointer< SelfFunctionType > >( rawFunctionPointer ) )
{}


template< typename ReturnType >
inline Callable< ReturnType () >::Callable( const FunctionPointer< SelfFunctionType >& functionPointer ) :
	member_callablePointer( Memory::MainMemoryManager::template AllocateAndConstruct< FunctionPointer< SelfFunctionType > >( functionPointer ) )
{}


template< typename ReturnType >
template< typename ObjectType, typename MethodType >
inline Callable< ReturnType () >::Callable( ObjectType& instance, const MethodType& methodRawPointer ) :
	member_callablePointer( Memory::MainMemoryManager::template AllocateAndConstruct< MethodPointerBoundToInstance< ObjectType, SelfFunctionType >, ObjectType&, const MethodType& >( instance, methodRawPointer ) )
{}


template< typename ReturnType >
template< typename ObjectType >
inline Callable< ReturnType () >::Callable( const MethodPointerBoundToInstance< ObjectType, SelfFunctionType >& methodPointerBoundToInstance ) :
	member_callablePointer( Memory::MainMemoryManager::template AllocateAndConstruct< MethodPointerBoundToInstance< ObjectType, SelfFunctionType > >( methodPointerBoundToInstance ) )
{}


template< typename ReturnType >
template< typename ObjectType, typename ConstantMethodType >
inline Callable< ReturnType () >::Callable( const ObjectType& instance, const ConstantMethodType& constantMethodRawPointer ) :
	member_callablePointer( Memory::MainMemoryManager::template AllocateAndConstruct< ConstantMethodPointerBoundToInstance< ObjectType, SelfFunctionType >, const ObjectType&, const ConstantMethodType& >( instance, constantMethodRawPointer ) )
{}


template< typename ReturnType >
template< typename ObjectType >
inline Callable< ReturnType () >::Callable( const ConstantMethodPointerBoundToInstance< ObjectType, SelfFunctionType >& constantMethodPointerBoundToInstance ) :
	member_callablePointer( Memory::MainMemoryManager::template AllocateAndConstruct< ConstantMethodPointerBoundToInstance< ObjectType, SelfFunctionType > >( constantMethodPointerBoundToInstance ) )
{}


template< typename ReturnType >
template< Concepts::Functor FunctorType > requires ( ( !Concepts::SameAsRegardlessOfTemplateArguments< FunctorType, MethodPointerBoundToInstance< FunctorType, ReturnType () > > ) && ( !Concepts::SameAsRegardlessOfTemplateArguments< FunctorType, ConstantMethodPointerBoundToInstance< FunctorType, ReturnType () > > ) )
inline Callable< ReturnType () >::Callable( FunctorType& functor ) :
	member_callablePointer( Memory::MainMemoryManager::template AllocateAndConstruct< InvokableObjectInterfaceWrapper< FunctorType, ReturnType >, FunctorType& >( functor ) )
{}


template< typename ReturnType >
template< Concepts::Functor FunctorType > requires ( ( !Concepts::SameAsRegardlessOfTemplateArguments< FunctorType, MethodPointerBoundToInstance< FunctorType, ReturnType () > > ) && ( !Concepts::SameAsRegardlessOfTemplateArguments< FunctorType, ConstantMethodPointerBoundToInstance< FunctorType, ReturnType () > > ) )
inline Callable< ReturnType () >::Callable( const FunctorType& functor ) :
	member_callablePointer( Memory::MainMemoryManager::template AllocateAndConstruct< InvokableObjectInterfaceWrapper< FunctorType, ReturnType >, const FunctorType& >( functor ) )
{}


template< typename ReturnType >
inline Callable< ReturnType () >::~Callable()
{
    // Check if the instance was constructed using the default constructor or the 'Reset' method was used, which usually signify that there
    // are no resources used by the instance, and nothing needs to be done further in the destructor
    ReturnIfExpressionIsTrue( member_callablePointer == nullptr );

    // Release the memory space used for the invokable object
    Memory::MainMemoryManager::template Done< InvokableObjectInterface< ReturnType > >( member_callablePointer );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< typename ReturnType >
inline ReturnType Callable< ReturnType () >::operator()()
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertPointerIsNotNull( member_callablePointer );

	// Execute the function using the arguments, and return the value
	return ( member_callablePointer->operator()() );
}


template< typename ReturnType >
inline ReturnType Callable< ReturnType () >::operator()() const
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertPointerIsNotNull( member_callablePointer );

	// Execute the function using the arguments, and return the value
	return ( member_callablePointer->operator()() );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	inline void Callable_FunctioWithNoArgumentsAndNoReturnValue()
	{}

	template< typename ReturnType COMMA typename... ArgumentTypes >
	void Foo( const Callable< ReturnType ( ArgumentTypes... ) >& callable, ArgumentTypes... arguments )
	{
		auto returnValue = callable( ForwardUniversalReference< ArgumentTypes >( arguments )... );
		++returnValue;
	}

	template< typename ReturnType COMMA typename... ArgumentTypes >
	void Callable< ReturnType ( ArgumentTypes... ) >::UnitTest()
	{
		Test::Object testInstance_0;

		Callable< UnsignedInteger32bits ( UnsignedInteger32bits COMMA UnsignedInteger64bits ) > testCallable_0( MethodPointerBoundToInstance< Test::Object, UnsignedInteger32bits ( UnsignedInteger32bits COMMA UnsignedInteger64bits ) >( testInstance_0, &Test::Object::Method_1 ) );

		Assert_Test( testCallable_0( 89U, 89UL ) == 9U );

		Callable< UnsignedInteger32bits ( UnsignedInteger32bits COMMA UnsignedInteger64bits ) > testCallable_1( TakeResourcesAndLeaveInstanceInDefaultState( testCallable_0 ) );

		Assert_Test( testCallable_1( 89U, 89UL ) == 9U );

		Callable< UnsignedInteger32bits () > testCallable_2( ConstantMethodPointerBoundToInstance< Test::Object, UnsignedInteger32bits () >( testInstance_0, &Test::Object::Method_4_Constant ) );

		Assert_Test( testCallable_2() == 999U );

		Callable< UnsignedInteger32bits () > testCallable_3( TakeResourcesAndLeaveInstanceInDefaultState( testCallable_2 ) );

		Assert_Test( testCallable_3() == 999U );

		Test::FunctorObject< UnsignedInteger32bits COMMA UnsignedInteger32bits > testFunctor_0( 456UL );

		Callable< UnsignedInteger32bits ( UnsignedInteger32bits ) > testCallable_4( testFunctor_0 );

		UnsignedInteger32bits returnValue = testCallable_4( 89 );
		++returnValue;

		Callable< UnsignedInteger32bits () > testCallable_5( []() { return 99999U; } );

		Assert_Test( testCallable_5() == 99999U );

		Callable< UnsignedInteger32bits ( UnsignedInteger32bits COMMA UnsignedInteger64bits ) > testCallable_6( &Test::Functions::Function_1 );
		Callable< UnsignedInteger32bits ( UnsignedInteger32bits COMMA UnsignedInteger64bits ) > testCallable_7( FunctionPointer< UnsignedInteger32bits ( UnsignedInteger32bits COMMA UnsignedInteger64bits ) >( &Test::Functions::Function_1 ) );

		returnValue = testCallable_6( 8U, 9UL );
		returnValue = testCallable_7( 8U, 9UL );

		Foo< UnsignedInteger32bits COMMA UnsignedInteger32bits COMMA UnsignedInteger64bits >( Callable< UnsignedInteger32bits ( UnsignedInteger32bits COMMA UnsignedInteger64bits ) >( &Test::Functions::Function_1 ), 8, 8 );

		Callable< UnsignedInteger32bits () > testCallable_8( [ &returnValue COMMA &testFunctor_0 ]() -> UnsignedInteger32bits { return ( 99999U ); } );

		Assert_Test( testCallable_8() == 99999U );

		Callable< UnsignedInteger32bits ( const UnsignedInteger32bits ) > testCallable_9( [ &returnValue COMMA &testFunctor_0 ]( const UnsignedInteger32bits dummyArgument ) -> UnsignedInteger32bits { return ( dummyArgument + 99999U ); } );

		Assert_Test( testCallable_9( 87U ) == 87U + 99999U );

		Test::Object testObject( 89UL, 445UL );

		Callable< void () > testCallable_10( testObject, &Test::Object::Method_3 );
		Callable< void () > testCallable_11( testObject, TakeResourcesAndLeaveInstanceInDefaultState( &Test::Object::Method_3 ) );

		Callable< void () > testCallable_12( &Callable_FunctioWithNoArgumentsAndNoReturnValue );
		testCallable_12();
		Callable< void () > testCallable_13( TakeResourcesAndLeaveInstanceInDefaultState( testCallable_12 ) );
		testCallable_13();
	}

)  //  End of debug tool



}  //  Namespace Universe