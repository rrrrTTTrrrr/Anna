//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< typename Type, typename MemoryManagerType >
inline HeapPointer< Type, MemoryManagerType >::HeapPointer() :
    member_pointer( MemoryManagerType::template AllocateAndDefaultConstruct< Type >() )
{}


template< typename Type, typename MemoryManagerType >
template< typename FirstConstructorArgumentType, typename... RestOfConstructorArgumentTypes >
inline HeapPointer< Type, MemoryManagerType >::HeapPointer( FirstConstructorArgumentType&& firstArgument, RestOfConstructorArgumentTypes&&... restOfCconstructorArguments ) :
    member_pointer( MemoryManagerType::template AllocateAndConstruct< Type >( ForwardUniversalReference< FirstConstructorArgumentType >( firstArgument ), ForwardUniversalReference< RestOfConstructorArgumentTypes >( restOfCconstructorArguments )... ) )
{}


template< typename Type, typename MemoryManagerType >
inline HeapPointer< Type, MemoryManagerType >::HeapPointer( Type* const pointer ) :
    member_pointer( AssignOnlyIfPointerIsNotNULL( pointer ) )
{}


template< typename Type, typename MemoryManagerType >
inline HeapPointer< Type, MemoryManagerType >::~HeapPointer()
{
    // Release the memory used on the heap memory segment
    MemoryManagerType::template Done< Type >( member_pointer );
}


template< typename Type, typename MemoryManagerType >
inline LargestUnsignedInteger HeapPointer< Type, MemoryManagerType >::SizeInBytes() const
{
    // Multiply the size by the size in bytes of each instance of the type, and return the result
    return ( sizeof( Type ) );
}


template< typename Type, typename MemoryManagerType >
inline Type* HeapPointer< Type, MemoryManagerType >::Get()
{
    // Return the memory address of the resource
    return ( member_pointer );
}


template< typename Type, typename MemoryManagerType >
inline Type* HeapPointer< Type, MemoryManagerType >::Acquire()
{
    // This pointer will store the memory address of the resource
    Type* const resourcePointer = member_pointer;

    // Set the pointer to NULL
    member_pointer = nullptr;

    // Return the memory address of the resource
    return ( resourcePointer );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< typename Type, typename MemoryManagerType >
inline Boolean HeapPointer< Type, MemoryManagerType >::operator==( const SelfType& other ) const
{
	// Compare the memory address of both instances and return the result
	return ( member_pointer == other.member_pointer );
}


template< typename Type, typename MemoryManagerType >
inline Boolean HeapPointer< Type, MemoryManagerType >::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}


template< typename Type, typename MemoryManagerType >
inline Type* HeapPointer< Type, MemoryManagerType >::operator->()
{
    // Return the pointer to the resource
    return ( member_pointer );
}


template< typename Type, typename MemoryManagerType >
inline Type* HeapPointer< Type, MemoryManagerType >::operator+( const LargestUnsignedInteger offset ) const
{
    // Return the memory address of the required offset
    return ( member_pointer + offset );
}


template< typename Type, typename MemoryManagerType >
inline Type* HeapPointer< Type, MemoryManagerType >::operator-( const LargestUnsignedInteger offset ) const
{
    // Return the memory address of the required offset
    return ( member_pointer - offset );
}


template< typename Type, typename MemoryManagerType >
inline Boolean HeapPointer< Type, MemoryManagerType >::operator>( const HeapPointer< Type, MemoryManagerType >& other ) const
{
    // Return the required object in the resource
    return ( member_pointer > other.member_pointer );
}


template< typename Type, typename MemoryManagerType >
inline Boolean HeapPointer< Type, MemoryManagerType >::operator<( const HeapPointer< Type, MemoryManagerType >& other ) const
{
    // Return the required object in the resource
    return ( member_pointer < other.member_pointer );
}


template< typename Type, typename MemoryManagerType >
inline Boolean HeapPointer< Type, MemoryManagerType >::operator>=( const HeapPointer< Type, MemoryManagerType >& other ) const
{
    // Return the required object in the resource
    return ( member_pointer >= other.member_pointer );
}


template< typename Type, typename MemoryManagerType >
inline Boolean HeapPointer< Type, MemoryManagerType >::operator<=( const HeapPointer< Type, MemoryManagerType >& other ) const
{
    // Return the required object in the resource
    return ( member_pointer <= other.member_pointer );
}



// **********************************************************   INLINE AND TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   ***********************************************************



template< typename TYPE >
EnsureRetrunValueIsUsed inline TYPE& operator*( HeapPointer< TYPE, MainMemoryManager >& heapPointer )
{    
    // Return the object pointed
    return ( *heapPointer.member_pointer );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< typename Type COMMA typename MemoryManagerType >
	void HeapPointer< Type COMMA MemoryManagerType >::UnitTest()
	{}

)  //  End of debug tool



}  //  Namespace Memory


}  //  Namespace Universe
