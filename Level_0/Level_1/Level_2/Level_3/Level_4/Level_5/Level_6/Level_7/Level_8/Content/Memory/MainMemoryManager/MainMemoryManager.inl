//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



template< Concepts::RawButPointerIsAllowed Type > requires ( Concepts::DefaultConstructible< Type > )
inline Type* MainMemoryManager::AllocateAndDefaultConstruct( const LargestUnsignedInteger size )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertValueIsLargerThenZero( size );

	// This try catch block is used to catch the standard exception that will be thrown from 'new' and convert to own exception
	try
	{
		// Check if the required size is one
		if ( size == 1UL )
		{
			// Only one instance of the template type is required

			// Use the standard C++ main memory manager to allocate the required memory space
			return ( new Type() );
		}
		else
		{
			// Multiple instances of the template type is required

			// Use the standard C++ main memory manager to allocate the required memory space
			return ( new Type[ size ] );
		}

	}
    catch ( const std::bad_alloc& stdException )
    {
    	// Convert the standard exception to own exception
    	ThrowException( stdException.what() );
    }
}


template< typename Type, typename... ConstructorArgumentTypes >
inline Type* MainMemoryManager::AllocateAndConstruct( ConstructorArgumentTypes&&... constructorArguments )
{
	// This try catch block is used to catch the standard exception that will be thrown from 'new' and convert to own exception
	try
	{
		// Use the standard C++ main memory manager to allocate the required memory space, and initialize it using the given constructor arguments
		return ( new Type( ForwardUniversalReference< ConstructorArgumentTypes >( constructorArguments )... ) );

	}
    catch ( const std::bad_alloc& stdException )
    {
    	// Convert the standard exception to own exception
    	ThrowException( stdException.what() );
    }
}


template< Concepts::RawButPointerIsAllowed Type >
inline void MainMemoryManager::Done( const Type* const pointer, const Boolean wasSingleInstanceAllocated )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertPointerIsNotNull( pointer );

	// This try catch block is used to catch the standard exception that will be thrown from 'delete' and convert to own exception
	try
	{
		// Check if the required size is one
		if ( wasSingleInstanceAllocated == true )
		{
			// Only one instance of the template type was allocated

			// Use the standard C++ main memory manager to free the required memory space
			delete pointer;
		}
		else
		{
			// Multiple instances of the template type was allocated

			// Use the standard C++ main memory manager to free the required memory space
			delete[] pointer;
		}

	}
    catch ( const std::bad_alloc& stdException )
    {
    	// Convert the standard exception to own exception
    	ThrowException( stdException.what() );
    }	
}


template< Concepts::RawButPointerIsAllowed Type, typename... ConstructorArgumentTypes >
inline void MainMemoryManager::Construct( void* const pointer, ConstructorArgumentTypes... constructorArguments )
{
	// Allocate new standard thread of execution instance, and store the memory address of it in the pointer
	new ( pointer ) Type( ForwardUniversalReference< ConstructorArgumentTypes >( constructorArguments )... );
}


template< Concepts::RawButPointerIsAllowed Type > requires ( Concepts::Destructible< Type > )
inline void MainMemoryManager::Destruct( void* const pointer )
{
	// Cast the pointer to the required type, and call the destructor of the object
	reinterpret_cast< Type* >( pointer )->~Type();
}



}  //  Namespace Memory


}  //  Namespace Universe
