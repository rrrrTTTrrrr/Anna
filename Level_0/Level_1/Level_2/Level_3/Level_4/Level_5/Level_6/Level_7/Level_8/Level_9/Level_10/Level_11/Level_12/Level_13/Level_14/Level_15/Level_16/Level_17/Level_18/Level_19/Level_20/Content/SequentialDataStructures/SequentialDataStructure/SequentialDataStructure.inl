//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename... AnyArgumentsNeededToConstructMemoryHandlerTypes >
inline SequentialDataStructure< DataType, MemoryManagerType >::SequentialDataStructure( const MemoryHandlerName memoryHandlerName, AnyArgumentsNeededToConstructMemoryHandlerTypes&&... anyArgumentsNeededToConstructMemoryHandler ) :
	member_memoryHandler{ nullptr },
	member_memoryHandlerName( memoryHandlerName )
{
	// Allocate memory space, construct the required memory handler on it, and store the memory address into the pointer
	ConstructMemoryHandler__Private< AnyArgumentsNeededToConstructMemoryHandlerTypes... >( ForwardUniversalReference< AnyArgumentsNeededToConstructMemoryHandlerTypes >( anyArgumentsNeededToConstructMemoryHandler )... );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline SequentialDataStructure< DataType, MemoryManagerType >::SequentialDataStructure( const SelfType& other, const LargestUnsignedInteger otherInstanceStartingIndex, const LargestUnsignedInteger size, const MemoryHandlerName memoryHandlerName ) :
	member_memoryHandler{ nullptr },
	member_memoryHandlerName( memoryHandlerName )
{
	// Switch case to choose the required memory handler
	switch ( other.member_memoryHandlerName )
	{
		// Vector
		case MemoryHandlerName::Vector :
		{
			// Copy construct the memory handler from the required part of the other instance memory handler
			ConstructMemoryHandler__Private< const SelfVectorType&, LargestUnsignedInteger, LargestUnsignedInteger >( *other.member_memoryHandler.member_vectorPointer, otherInstanceStartingIndex, size );

			// Nothing else needs to be done
			break;
		}

		// Single linked list
		case MemoryHandlerName::SingleLinkedList :
		{
			// Copy construct the memory handler from the required part of the other instance memory handler
			ConstructMemoryHandler__Private< const SelfSingleLinkedListType&, LargestUnsignedInteger, LargestUnsignedInteger >( *other.member_memoryHandler.member_singleLinkedListPointer, otherInstanceStartingIndex, size );

			// Nothing else needs to be done
			break;
		}

		// Double linked list
		case MemoryHandlerName::DoubleLinkedList :
		{
			// Copy construct the memory handler from the required part of the other instance memory handler
			ConstructMemoryHandler__Private< const SelfDoubleLinkedListType&, LargestUnsignedInteger, LargestUnsignedInteger >( *other.member_memoryHandler.member_doubleLinkedListPointer, otherInstanceStartingIndex, size );

			// Nothing else needs to be done
			break;
		}

		// Pages array
		case MemoryHandlerName::PagesArray :
		{
			// Copy construct the memory handler from the required part of the other instance memory handler
			ConstructMemoryHandler__Private< const SelfPagesArrayType&, LargestUnsignedInteger, LargestUnsignedInteger >( *other.member_memoryHandler.member_pagesArrayPointer, otherInstanceStartingIndex, size );

			// Nothing else needs to be done
			break;
		}

		default:
		{
			// The memory handler type is unknown, throw an exception
			ThrowException( "Unknown memory handler type" );
		}
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline SequentialDataStructure< DataType, MemoryManagerType >::SequentialDataStructure( const SelfType& other ) :
	member_memoryHandler{ nullptr },
	member_memoryHandlerName( other.member_memoryHandlerName )
{
	// Switch case to choose the required memory handler
	switch ( other.member_memoryHandlerName )
	{
		// Vector
		case MemoryHandlerName::Vector :
		{
			// Copy construct the memory handler from the other instance memory handler
			member_memoryHandler.member_vectorPointer = MemoryManagerType::template AllocateAndConstruct< SelfVectorType >( *other.member_memoryHandler.member_vectorPointer );

			// Nothing else needs to be done
			break;
		}

		// Single linked list
		case MemoryHandlerName::SingleLinkedList :
		{
			// Copy construct the memory handler from the other instance memory handler
			member_memoryHandler.member_singleLinkedListPointer = MemoryManagerType::template AllocateAndConstruct< SelfSingleLinkedListType >( *other.member_memoryHandler.member_singleLinkedListPointer );

			// Nothing else needs to be done
			break;
		}

		// Double linked list
		case MemoryHandlerName::DoubleLinkedList :
		{
			// Copy construct the memory handler from the other instance memory handler
			member_memoryHandler.member_doubleLinkedListPointer = MemoryManagerType::template AllocateAndConstruct< SelfDoubleLinkedListType >( *other.member_memoryHandler.member_doubleLinkedListPointer );

			// Nothing else needs to be done
			break;
		}

		// Pages array
		case MemoryHandlerName::PagesArray :
		{
			// Copy construct the memory handler from the other instance memory handler
			member_memoryHandler.member_pagesArrayPointer = MemoryManagerType::template AllocateAndConstruct< SelfPagesArrayType >( *other.member_memoryHandler.member_pagesArrayPointer );

			// Nothing else needs to be done
			break;
		}

		default:
		{
			// The memory handler type is unknown, throw an exception
			ThrowException( "Unknown memory handler type" );
		}
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline SequentialDataStructure< DataType, MemoryManagerType >::~SequentialDataStructure()
{
	// Switch case to choose the required memory handler
	switch ( member_memoryHandlerName )
	{
		// Vector
		case MemoryHandlerName::Vector :
		{
			// Delete the memory handler
			delete member_memoryHandler.member_vectorPointer;

			// Nothing else needs to be done
			break;
		}

		// Single linked list
		case MemoryHandlerName::SingleLinkedList :
		{
			// Delete the memory handler
			delete member_memoryHandler.member_singleLinkedListPointer;

			// Nothing else needs to be done
			break;
		}

		// Double linked list
		case MemoryHandlerName::DoubleLinkedList :
		{
			// Delete the memory handler
			delete member_memoryHandler.member_doubleLinkedListPointer;

			// Nothing else needs to be done
			break;
		}

		// Pages array
		case MemoryHandlerName::PagesArray :
		{
			// Delete the memory handler
			delete member_memoryHandler.member_pagesArrayPointer;

			// Nothing else needs to be done
			break;
		}
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void SequentialDataStructure< DataType, MemoryManagerType >::SwitchMemoryHandler( const MemoryHandlerName newMemoryHandlerName )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	Assert( ( member_memoryHandlerName != newMemoryHandlerName ), "The instance already uses the given memory handler to switch to" );

	// Switch case to choose the required memory handler
	switch ( member_memoryHandlerName )
	{
		// Vector
		case MemoryHandlerName::Vector :
		{
			// Switch from the current memory handler to the required memory handler
			SwitchMemoryHandler__Private< SelfVectorType >( newMemoryHandlerName, member_memoryHandler.member_vectorPointer );

			// Nothing else needs to be done
			break;
		}

		// Single linked list
		case MemoryHandlerName::SingleLinkedList :
		{
			// Switch from the current memory handler to the required memory handler
			SwitchMemoryHandler__Private< SelfSingleLinkedListType >( newMemoryHandlerName, member_memoryHandler.member_singleLinkedListPointer );

			// Nothing else needs to be done
			break;
		}

		// Double linked list
		case MemoryHandlerName::DoubleLinkedList :
		{
			// Switch from the current memory handler to the required memory handler
			SwitchMemoryHandler__Private< SelfDoubleLinkedListType >( newMemoryHandlerName, member_memoryHandler.member_doubleLinkedListPointer );

			// Nothing else needs to be done
			break;
		}

		// Pages array
		case MemoryHandlerName::PagesArray :
		{
			// Switch from the current memory handler to the required memory handler
			SwitchMemoryHandler__Private< SelfPagesArrayType >( newMemoryHandlerName, member_memoryHandler.member_pagesArrayPointer );

			// Nothing else needs to be done
			break;
		}

		default:
		{
			// The memory handler type is unknown, throw an exception
			ThrowException( "Unknown memory handler type" );
		}
	}

	// Set the new memory handler name
	member_memoryHandlerName = newMemoryHandlerName;
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline LargestUnsignedInteger SequentialDataStructure< DataType, MemoryManagerType >::Size() const
{
	// Switch case to choose the required memory handler
	switch ( member_memoryHandlerName )
	{
		// Vector
		case MemoryHandlerName::Vector :
		{
			// Return the size of the memory handler
			return ( member_memoryHandler.member_vectorPointer->Size() );
		}

		// Single linked list
		case MemoryHandlerName::SingleLinkedList :
		{
			// Return the size of the memory handler
			return ( member_memoryHandler.member_singleLinkedListPointer->Size() );
		}

		// Double linked list
		case MemoryHandlerName::DoubleLinkedList :
		{
			// Return the size of the memory handler
			return ( member_memoryHandler.member_doubleLinkedListPointer->Size() );
		}

		// Pages array
		case MemoryHandlerName::PagesArray :
		{
			// Return the size of the memory handler
			return ( member_memoryHandler.member_pagesArrayPointer->Size() );
		}

		default:
		{
			// The memory handler type is unknown, throw an exception
			ThrowException( "Unknown memory handler type" );
		}
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline LargestUnsignedInteger SequentialDataStructure< DataType, MemoryManagerType >::SizeInBytes() const
{
	// Switch case to choose the required memory handler
	switch ( member_memoryHandlerName )
	{
		// Vector
		case MemoryHandlerName::Vector :
		{
			// Return the size in bytes of the memory handler
			return ( member_memoryHandler.member_vectorPointer->SizeInBytes() );
		}

		// Single linked list
		case MemoryHandlerName::SingleLinkedList :
		{
			// Return the size in bytes of the memory handler
			return ( member_memoryHandler.member_singleLinkedListPointer->SizeInBytes() );
		}

		// Double linked list
		case MemoryHandlerName::DoubleLinkedList :
		{
			// Return the size in bytes of the memory handler
			return ( member_memoryHandler.member_doubleLinkedListPointer->SizeInBytes() );
		}

		// Pages array
		case MemoryHandlerName::PagesArray :
		{
			// Return the size in bytes of the memory handler
			return ( member_memoryHandler.member_pagesArrayPointer->SizeInBytes() );
		}

		default:
		{
			// The memory handler type is unknown, throw an exception
			ThrowException( "Unknown memory handler type" );
		}
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline LargestUnsignedInteger SequentialDataStructure< DataType, MemoryManagerType >::DataTypeSizeInBytes() const
{
	// Switch case to choose the required memory handler
	switch ( member_memoryHandlerName )
	{
		// Vector
		case MemoryHandlerName::Vector :
		{
			// Return the size in bytes of the data type used by the memory handler
			return ( member_memoryHandler.member_vectorPointer->DataTypeSizeInBytes() );
		}

		// Single linked list
		case MemoryHandlerName::SingleLinkedList :
		{
			// Return the size in bytes of the data type used by the memory handler
			return ( member_memoryHandler.member_singleLinkedListPointer->DataTypeSizeInBytes() );
		}

		// Double linked list
		case MemoryHandlerName::DoubleLinkedList :
		{
			// Return the size in bytes of the data type used by the memory handler
			return ( member_memoryHandler.member_doubleLinkedListPointer->DataTypeSizeInBytes() );
		}

		// Pages array
		case MemoryHandlerName::PagesArray :
		{
			// Return the size in bytes of the data type used by the memory handler
			return ( member_memoryHandler.member_pagesArrayPointer->DataTypeSizeInBytes() );
		}

		default:
		{
			// The memory handler type is unknown, throw an exception
			ThrowException( "Unknown memory handler type" );
		}
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void SequentialDataStructure< DataType, MemoryManagerType >::Set( const LargestUnsignedInteger startingIndex, const LargestUnsignedInteger size, const DataType& data )
{
	// Switch case to choose the required memory handler
	switch ( member_memoryHandlerName )
	{
		// Vector
		case MemoryHandlerName::Vector :
		{
			// Set the data into this instance
			Loop::Set< SelfVectorType >( *member_memoryHandler.member_vectorPointer, startingIndex, size, data );

			// Nothing else needs to be done
			break;
		}

		// Single linked list
		case MemoryHandlerName::SingleLinkedList :
		{
			// Set the data into this instance
			Loop::Set< SelfSingleLinkedListType >( *member_memoryHandler.member_singleLinkedListPointer, startingIndex, size, data );

			// Nothing else needs to be done
			break;
		}

		// Double linked list
		case MemoryHandlerName::DoubleLinkedList :
		{
			// Set the data into this instance
			Loop::Set< SelfDoubleLinkedListType >( *member_memoryHandler.member_doubleLinkedListPointer, startingIndex, size, data );

			// Nothing else needs to be done
			break;
		}

		// Pages array
		case MemoryHandlerName::PagesArray :
		{
			// Set the data into this instance
			Loop::Set< SelfPagesArrayType >( *member_memoryHandler.member_pagesArrayPointer, startingIndex, size, data );

			// Nothing else needs to be done
			break;
		}

		default:
		{
			// The memory handler type is unknown, throw an exception
			ThrowException( "Unknown memory handler type" );
		}
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void SequentialDataStructure< DataType, MemoryManagerType >::Copy( const SelfType& other, const LargestUnsignedInteger thisInstanceStartingIndex, const LargestUnsignedInteger otherInstanceStartingIndex, const LargestUnsignedInteger size )
{
	// There are 9 options for the currently used pointers in both instances. Pick the required pointers and copy the content from the other
	// instance into this instance

	// This instance - vector -- Other instance - vector 
	if ( member_memoryHandlerName == MemoryHandlerName::Vector && other.member_memoryHandlerName == MemoryHandlerName::Vector )
	{
		Loop::Copy< SelfVectorType, SelfVectorType >( *member_memoryHandler.member_vectorPointer, *other.member_memoryHandler.member_vectorPointer, thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - vector -- Other instance - single linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::Vector && other.member_memoryHandlerName == MemoryHandlerName::SingleLinkedList )
	{
		Loop::Copy< SelfVectorType, SelfSingleLinkedListType >( *member_memoryHandler.member_vectorPointer, *other.member_memoryHandler.member_singleLinkedListPointer, thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - vector -- Other instance - dobule linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::Vector && other.member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList )
	{
		Loop::Copy< SelfVectorType, SelfDoubleLinkedListType >( *member_memoryHandler.member_vectorPointer, *other.member_memoryHandler.member_doubleLinkedListPointer, thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - single linked list -- Other instance - vector
	else if ( member_memoryHandlerName == MemoryHandlerName::SingleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::Vector )
	{
		Loop::Copy< SelfSingleLinkedListType, SelfVectorType >( *member_memoryHandler.member_singleLinkedListPointer, *other.member_memoryHandler.member_vectorPointer, thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - single linked list -- Other instance - single linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::SingleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::SingleLinkedList )
	{
		Loop::Copy< SelfSingleLinkedListType, SelfSingleLinkedListType >( *member_memoryHandler.member_singleLinkedListPointer, *other.member_memoryHandler.member_singleLinkedListPointer, thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - single linked list -- Other instance - double linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::SingleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList )
	{
		Loop::Copy< SelfSingleLinkedListType, SelfDoubleLinkedListType >( *member_memoryHandler.member_singleLinkedListPointer, *other.member_memoryHandler.member_doubleLinkedListPointer, thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - double linked list -- Other instance - vector
	else if ( member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::Vector )
	{
		Loop::Copy< SelfDoubleLinkedListType, SelfVectorType >( *member_memoryHandler.member_singleLinkedListPointer, *other.member_memoryHandler.member_vectorPointer, thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - double linked list -- Other instance - single linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::SingleLinkedList )
	{
		Loop::Copy< SelfDoubleLinkedListType, SelfSingleLinkedListType >( *member_memoryHandler.member_singleLinkedListPointer, *other.member_memoryHandler.member_singleLinkedListPointer, thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - double linked list -- Other instance - double linked list
	else
	{
		Loop::Copy< SelfDoubleLinkedListType, SelfDoubleLinkedListType >( *member_memoryHandler.member_singleLinkedListPointer, *other.member_memoryHandler.member_doubleLinkedListPointer, thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void SequentialDataStructure< DataType, MemoryManagerType >::Move( SelfType&& other, const LargestUnsignedInteger thisInstanceStartingIndex, const LargestUnsignedInteger otherInstanceStartingIndex, const LargestUnsignedInteger size )
{
	// There are 9 options for the currently used pointers in both instances. Pick the required pointers and move the content from the other
	// instance into this instance

	// This instance - vector -- Other instance - vector 
	if ( member_memoryHandlerName == MemoryHandlerName::Vector && other.member_memoryHandlerName == MemoryHandlerName::Vector )
	{
		Loop::Move< SelfVectorType, SelfVectorType >( *member_memoryHandler.member_vectorPointer, TakeResourcesAndLeaveInstanceInDefaultState( *other.member_memoryHandler.member_vectorPointer ), thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - vector -- Other instance - single linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::Vector && other.member_memoryHandlerName == MemoryHandlerName::SingleLinkedList )
	{
		Loop::Move< SelfVectorType, SelfSingleLinkedListType >( *member_memoryHandler.member_vectorPointer, TakeResourcesAndLeaveInstanceInDefaultState( *other.member_memoryHandler.member_singleLinkedListPointer ), thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - vector -- Other instance - dobule linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::Vector && other.member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList )
	{
		Loop::Move< SelfVectorType, SelfDoubleLinkedListType >( *member_memoryHandler.member_vectorPointer, TakeResourcesAndLeaveInstanceInDefaultState( *other.member_memoryHandler.member_doubleLinkedListPointer ), thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - single linked list -- Other instance - vector
	else if ( member_memoryHandlerName == MemoryHandlerName::SingleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::Vector )
	{
		Loop::Move< SelfSingleLinkedListType, SelfVectorType >( *member_memoryHandler.member_singleLinkedListPointer, TakeResourcesAndLeaveInstanceInDefaultState( *other.member_memoryHandler.member_vectorPointer ), thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - single linked list -- Other instance - single linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::SingleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::SingleLinkedList )
	{
		Loop::Move< SelfSingleLinkedListType, SelfSingleLinkedListType >( *member_memoryHandler.member_singleLinkedListPointer, TakeResourcesAndLeaveInstanceInDefaultState( *other.member_memoryHandler.member_singleLinkedListPointer ), thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - single linked list -- Other instance - double linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::SingleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList )
	{
		Loop::Move< SelfSingleLinkedListType, SelfDoubleLinkedListType >( *member_memoryHandler.member_singleLinkedListPointer, TakeResourcesAndLeaveInstanceInDefaultState( *other.member_memoryHandler.member_doubleLinkedListPointer ), thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - double linked list -- Other instance - vector
	else if ( member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::Vector )
	{
		Loop::Move< SelfDoubleLinkedListType, SelfVectorType >( *member_memoryHandler.member_singleLinkedListPointer, TakeResourcesAndLeaveInstanceInDefaultState( *other.member_memoryHandler.member_vectorPointer ), thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - double linked list -- Other instance - single linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::SingleLinkedList )
	{
		Loop::Move< SelfDoubleLinkedListType, SelfSingleLinkedListType >( *member_memoryHandler.member_singleLinkedListPointer, TakeResourcesAndLeaveInstanceInDefaultState( *other.member_memoryHandler.member_singleLinkedListPointer ), thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - double linked list -- Other instance - double linked list
	else
	{
		Loop::Move< SelfDoubleLinkedListType, SelfDoubleLinkedListType >( *member_memoryHandler.member_singleLinkedListPointer, TakeResourcesAndLeaveInstanceInDefaultState( *other.member_memoryHandler.member_doubleLinkedListPointer ), thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline Boolean SequentialDataStructure< DataType, MemoryManagerType >::Compare( const SelfType& other, LargestUnsignedInteger thisInstanceStartingIndex, const LargestUnsignedInteger otherInstanceStartingIndex, const LargestUnsignedInteger size ) const
{
	// There are 9 options for the currently used pointers in both instances. Pick the required pointers and copy the content from the other
	// instance into this instance

	// This instance - vector -- Other instance - vector 
	if ( member_memoryHandlerName == MemoryHandlerName::Vector && other.member_memoryHandlerName == MemoryHandlerName::Vector )
	{
		return ( Loop::Compare< SelfVectorType, SelfVectorType >( *member_memoryHandler.member_vectorPointer, *other.member_memoryHandler.member_vectorPointer, thisInstanceStartingIndex, otherInstanceStartingIndex, size ) );
	}

	// This instance - vector -- Other instance - single linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::Vector && other.member_memoryHandlerName == MemoryHandlerName::SingleLinkedList )
	{
		return ( Loop::Compare< SelfVectorType, SelfSingleLinkedListType >( *member_memoryHandler.member_vectorPointer, *other.member_memoryHandler.member_singleLinkedListPointer, thisInstanceStartingIndex, otherInstanceStartingIndex, size ) );
	}

	// This instance - vector -- Other instance - dobule linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::Vector && other.member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList )
	{
		return ( Loop::Compare< SelfVectorType, SelfDoubleLinkedListType >( *member_memoryHandler.member_vectorPointer, *other.member_memoryHandler.member_doubleLinkedListPointer, thisInstanceStartingIndex, otherInstanceStartingIndex, size ) );
	}

	// This instance - single linked list -- Other instance - vector
	else if ( member_memoryHandlerName == MemoryHandlerName::SingleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::Vector )
	{
		return ( Loop::Compare< SelfSingleLinkedListType, SelfVectorType >( *member_memoryHandler.member_singleLinkedListPointer, *other.member_memoryHandler.member_vectorPointer, thisInstanceStartingIndex, otherInstanceStartingIndex, size ) );
	}

	// This instance - single linked list -- Other instance - single linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::SingleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::SingleLinkedList )
	{
		return ( Loop::Compare< SelfSingleLinkedListType, SelfSingleLinkedListType >( *member_memoryHandler.member_singleLinkedListPointer, *other.member_memoryHandler.member_singleLinkedListPointer, thisInstanceStartingIndex, otherInstanceStartingIndex, size ) );
	}

	// This instance - single linked list -- Other instance - double linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::SingleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList )
	{
		return ( Loop::Compare< SelfSingleLinkedListType, SelfDoubleLinkedListType >( *member_memoryHandler.member_singleLinkedListPointer, *other.member_memoryHandler.member_doubleLinkedListPointer, thisInstanceStartingIndex, otherInstanceStartingIndex, size ) );
	}

	// This instance - double linked list -- Other instance - vector
	else if ( member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::Vector )
	{
		return ( Loop::Compare< SelfDoubleLinkedListType, SelfVectorType >( *member_memoryHandler.member_doubleLinkedListPointer, *other.member_memoryHandler.member_vectorPointer, thisInstanceStartingIndex, otherInstanceStartingIndex, size ) );
	}

	// This instance - double linked list -- Other instance - single linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::SingleLinkedList )
	{
		return ( Loop::Compare< SelfDoubleLinkedListType, SelfSingleLinkedListType >( *member_memoryHandler.member_doubleLinkedListPointer, *other.member_memoryHandler.member_singleLinkedListPointer, thisInstanceStartingIndex, otherInstanceStartingIndex, size ) );
	}

	// This instance - double linked list -- Other instance - double linked list
	else
	{
		return ( Loop::Compare< SelfDoubleLinkedListType, SelfDoubleLinkedListType >( *member_memoryHandler.member_doubleLinkedListPointer, *other.member_memoryHandler.member_doubleLinkedListPointer, thisInstanceStartingIndex, otherInstanceStartingIndex, size ) );
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename UniversalReferenceDataType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceDataType, DataType >::Result == true )
inline void SequentialDataStructure< DataType, MemoryManagerType >::InsertSingleElement( const LargestUnsignedInteger index, UniversalReferenceDataType&& data )
{
	// Switch case to choose the required memory handler
	switch ( member_memoryHandlerName )
	{
		// Vector
		case MemoryHandlerName::Vector :
		{
			// Insert the new data
			member_memoryHandler.member_vectorPointer->template InsertSingleElement< UniversalReferenceDataType >( index, ForwardUniversalReference< UniversalReferenceDataType >( data ) );

			// Nothing else needs to be done
			break;
		}

		// Single linked list
		case MemoryHandlerName::SingleLinkedList :
		{
			// Insert the new data
			member_memoryHandler.member_singleLinkedListPointer->template InsertSingleElement< UniversalReferenceDataType >( index, ForwardUniversalReference< UniversalReferenceDataType >( data ) );

			// Nothing else needs to be done
			break;
		}

		// Double linked list
		case MemoryHandlerName::DoubleLinkedList :
		{
			// Insert the new data
			member_memoryHandler.member_doubleLinkedListPointer->template InsertSingleElement< UniversalReferenceDataType >( index, ForwardUniversalReference< UniversalReferenceDataType >( data ) );

			// Nothing else needs to be done
			break;
		}

		// Pages array
		case MemoryHandlerName::PagesArray :
		{
			// Insert the new data
			member_memoryHandler.member_pagesArrayPointer->template InsertSingleElement< UniversalReferenceDataType >( index, ForwardUniversalReference< UniversalReferenceDataType >( data ) );

			// Nothing else needs to be done
			break;
		}

		default:
		{
			// The memory handler type is unknown, throw an exception
			ThrowException( "Unknown memory handler type" );
		}
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename... AnyArgumentNeededToConstructDataInstanceTypes >
inline void SequentialDataStructure< DataType, MemoryManagerType >::InsertSingleElementCreateFromArguments( const LargestUnsignedInteger index, AnyArgumentNeededToConstructDataInstanceTypes&&... anyArgumentNeededToConstructDataIstance )
{
	// Switch case to choose the required memory handler
	switch ( member_memoryHandlerName )
	{
		// Vector
		case MemoryHandlerName::Vector :
		{
			// Insert the new data, by taking all the required arguments that are needed for constructing an instance of the data, 
			// creating one and then setting it
			member_memoryHandler.member_vectorPointer->template InsertSingleElementCreateFromArguments< AnyArgumentNeededToConstructDataInstanceTypes... >( index, ForwardUniversalReference< AnyArgumentNeededToConstructDataInstanceTypes >( anyArgumentNeededToConstructDataIstance )... );;

			// Nothing else needs to be done
			break;
		}

		// Single linked list
		case MemoryHandlerName::SingleLinkedList :
		{
			// Insert the new data, by taking all the required arguments that are needed for constructing an instance of the data, 
			// creating one and then setting it
			member_memoryHandler.member_singleLinkedListPointer->template InsertSingleElementCreateFromArguments< AnyArgumentNeededToConstructDataInstanceTypes... >( index, ForwardUniversalReference< AnyArgumentNeededToConstructDataInstanceTypes >( anyArgumentNeededToConstructDataIstance )... );;

			// Nothing else needs to be done
			break;
		}

		// Double linked list
		case MemoryHandlerName::DoubleLinkedList :
		{
			// Insert the new data, by taking all the required arguments that are needed for constructing an instance of the data, 
			// creating one and then setting it
			member_memoryHandler.member_doubleLinkedListPointer->template InsertSingleElementCreateFromArguments< AnyArgumentNeededToConstructDataInstanceTypes... >( index, ForwardUniversalReference< AnyArgumentNeededToConstructDataInstanceTypes >( anyArgumentNeededToConstructDataIstance )... );;

			// Nothing else needs to be done
			break;
		}

		// Pages array
		case MemoryHandlerName::PagesArray :
		{
			// Insert the new data, by taking all the required arguments that are needed for constructing an instance of the data, 
			// creating one and then setting it
			member_memoryHandler.member_pagesArrayPointer->template InsertSingleElementCreateFromArguments< AnyArgumentNeededToConstructDataInstanceTypes... >( index, ForwardUniversalReference< AnyArgumentNeededToConstructDataInstanceTypes >( anyArgumentNeededToConstructDataIstance )... );;

			// Nothing else needs to be done
			break;
		}

		default:
		{
			// The memory handler type is unknown, throw an exception
			ThrowException( "Unknown memory handler type" );
		}
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void SequentialDataStructure< DataType, MemoryManagerType >::InsertMultipleTimesTheSameElement( const LargestUnsignedInteger index, const LargestUnsignedInteger size, const DataType& data )
{
	// Switch case to choose the required memory handler
	switch ( member_memoryHandlerName )
	{
		// Vector
		case MemoryHandlerName::Vector :
		{
			// Insert the new data
			member_memoryHandler.member_vectorPointer->InsertMultipleTimesTheSameElement( index, size, data );

			// Nothing else needs to be done
			break;
		}

		// Single linked list
		case MemoryHandlerName::SingleLinkedList :
		{
			// Insert the new data
			member_memoryHandler.member_singleLinkedListPointer->InsertMultipleTimesTheSameElement( index, size, data );

			// Nothing else needs to be done
			break;
		}

		// Double linked list
		case MemoryHandlerName::DoubleLinkedList :
		{
			// Insert the new data
			member_memoryHandler.member_doubleLinkedListPointer->InsertMultipleTimesTheSameElement( index, size, data );

			// Nothing else needs to be done
			break;
		}

		// Pages array
		case MemoryHandlerName::PagesArray :
		{
			// Insert the new data
			member_memoryHandler.member_pagesArrayPointer->InsertMultipleTimesTheSameElement( index, size, data );

			// Nothing else needs to be done
			break;
		}

		default:
		{
			// The memory handler type is unknown, throw an exception
			ThrowException( "Unknown memory handler type" );
		}
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void SequentialDataStructure< DataType, MemoryManagerType >::InsertElementsFromOtherInstance( const SelfType& other, const LargestUnsignedInteger thisInstanceStartingIndex, const LargestUnsignedInteger otherInstanceStartingIndex, const LargestUnsignedInteger size )
{
	// There are 9 options for the currently used pointers in both instances. Pick the required pointers and move the content from the other
	// instance into this instance

	// This instance - vector -- Other instance - vector 
	if ( member_memoryHandlerName == MemoryHandlerName::Vector && other.member_memoryHandlerName == MemoryHandlerName::Vector )
	{
		member_memoryHandler.member_vectorPointer->template InsertElementsFromOtherInstance< SelfVectorType >( *other.member_memoryHandler.member_vectorPointer, thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - vector -- Other instance - single linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::Vector && other.member_memoryHandlerName == MemoryHandlerName::SingleLinkedList )
	{
		member_memoryHandler.member_vectorPointer->template InsertElementsFromOtherInstance< SelfSingleLinkedListType >( *other.member_memoryHandler.member_singleLinkedListPointer, thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - vector -- Other instance - dobule linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::Vector && other.member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList )
	{
		member_memoryHandler.member_vectorPointer->template InsertElementsFromOtherInstance< SelfDoubleLinkedListType >( *other.member_memoryHandler.member_doubleLinkedListPointer, thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - single linked list -- Other instance - vector
	else if ( member_memoryHandlerName == MemoryHandlerName::SingleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::Vector )
	{
		member_memoryHandler.member_singleLinkedListPointer->template InsertElementsFromOtherInstance< SelfVectorType >( *other.member_memoryHandler.member_vectorPointer, thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - single linked list -- Other instance - single linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::SingleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::SingleLinkedList )
	{
		member_memoryHandler.member_singleLinkedListPointer->template InsertElementsFromOtherInstance< SelfSingleLinkedListType >( *other.member_memoryHandler.member_singleLinkedListPointer, thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - single linked list -- Other instance - double linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::SingleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList )
	{
		member_memoryHandler.member_singleLinkedListPointer->template InsertElementsFromOtherInstance< SelfDoubleLinkedListType >( *other.member_memoryHandler.member_doubleLinkedListPointer, thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - double linked list -- Other instance - vector
	else if ( member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::Vector )
	{
		member_memoryHandler.member_doubleLinkedListPointer->template InsertElementsFromOtherInstance< SelfVectorType >( *other.member_memoryHandler.member_vectorPointer, thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - double linked list -- Other instance - single linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::SingleLinkedList )
	{
		member_memoryHandler.member_doubleLinkedListPointer->template InsertElementsFromOtherInstance< SelfSingleLinkedListType >( *other.member_memoryHandler.member_singleLinkedListPointer, thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - double linked list -- Other instance - double linked list
	else
	{
		member_memoryHandler.member_doubleLinkedListPointer->template InsertElementsFromOtherInstance< SelfDoubleLinkedListType >( *other.member_memoryHandler.member_doubleLinkedListPointer, thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}	
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void SequentialDataStructure< DataType, MemoryManagerType >::InsertElementsFromOtherInstance( SelfType&& other, const LargestUnsignedInteger thisInstanceStartingIndex, const LargestUnsignedInteger otherInstanceStartingIndex, const LargestUnsignedInteger size )
{
	// There are 9 options for the currently used pointers in both instances. Pick the required pointers and move the content from the other
	// instance into this instance

	// This instance - vector -- Other instance - vector 
	if ( member_memoryHandlerName == MemoryHandlerName::Vector && other.member_memoryHandlerName == MemoryHandlerName::Vector )
	{
		member_memoryHandler.member_vectorPointer->template InsertElementsFromOtherInstance< SelfVectorType >( TakeResourcesAndLeaveInstanceInDefaultState( *other.member_memoryHandler.member_vectorPointer ), thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - vector -- Other instance - single linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::Vector && other.member_memoryHandlerName == MemoryHandlerName::SingleLinkedList )
	{
		member_memoryHandler.member_vectorPointer->template InsertElementsFromOtherInstance< SelfSingleLinkedListType >( TakeResourcesAndLeaveInstanceInDefaultState( *other.member_memoryHandler.member_singleLinkedListPointer ), thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - vector -- Other instance - dobule linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::Vector && other.member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList )
	{
		member_memoryHandler.member_vectorPointer->template InsertElementsFromOtherInstance< SelfDoubleLinkedListType >( TakeResourcesAndLeaveInstanceInDefaultState( *other.member_memoryHandler.member_doubleLinkedListPointer ), thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - single linked list -- Other instance - vector
	else if ( member_memoryHandlerName == MemoryHandlerName::SingleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::Vector )
	{
		member_memoryHandler.member_singleLinkedListPointer->template InsertElementsFromOtherInstance< SelfVectorType >( TakeResourcesAndLeaveInstanceInDefaultState( *other.member_memoryHandler.member_vectorPointer ), thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - single linked list -- Other instance - single linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::SingleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::SingleLinkedList )
	{
		member_memoryHandler.member_singleLinkedListPointer->template InsertElementsFromOtherInstance< SelfSingleLinkedListType >( TakeResourcesAndLeaveInstanceInDefaultState( *other.member_memoryHandler.member_singleLinkedListPointer ), thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - single linked list -- Other instance - double linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::SingleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList )
	{
		member_memoryHandler.member_singleLinkedListPointer->template InsertElementsFromOtherInstance< SelfDoubleLinkedListType >( TakeResourcesAndLeaveInstanceInDefaultState( *other.member_memoryHandler.member_doubleLinkedListPointer ), thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - double linked list -- Other instance - vector
	else if ( member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::Vector )
	{
		member_memoryHandler.member_doubleLinkedListPointer->template InsertElementsFromOtherInstance< SelfVectorType >( TakeResourcesAndLeaveInstanceInDefaultState( *other.member_memoryHandler.member_vectorPointer ), thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - double linked list -- Other instance - single linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::SingleLinkedList )
	{
		member_memoryHandler.member_doubleLinkedListPointer->template InsertElementsFromOtherInstance< SelfSingleLinkedListType >( TakeResourcesAndLeaveInstanceInDefaultState( *other.member_memoryHandler.member_singleLinkedListPointer ), thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}

	// This instance - double linked list -- Other instance - double linked list
	else
	{
		member_memoryHandler.member_doubleLinkedListPointer->template InsertElementsFromOtherInstance< SelfDoubleLinkedListType >( TakeResourcesAndLeaveInstanceInDefaultState( *other.member_memoryHandler.member_doubleLinkedListPointer ), thisInstanceStartingIndex, otherInstanceStartingIndex, size );
	}	
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void SequentialDataStructure< DataType, MemoryManagerType >::InsertElementsFromRawData( const DataType* const dataPointer, const LargestUnsignedInteger index, const LargestUnsignedInteger size )
{
	// Switch case to choose the required memory handler
	switch ( member_memoryHandlerName )
	{
		// Vector
		case MemoryHandlerName::Vector :
		{
			// Insert the new data
			member_memoryHandler.member_vectorPointer->InsertElementsFromRawData( dataPointer, index, size );

			// Nothing else needs to be done
			break;
		}

		// Single linked list
		case MemoryHandlerName::SingleLinkedList :
		{
			// Insert the new data
			member_memoryHandler.member_singleLinkedListPointer->InsertElementsFromRawData( dataPointer, index, size );

			// Nothing else needs to be done
			break;
		}

		// Double linked list
		case MemoryHandlerName::DoubleLinkedList :
		{
			// Insert the new data
			member_memoryHandler.member_doubleLinkedListPointer->InsertElementsFromRawData( dataPointer, index, size );

			// Nothing else needs to be done
			break;
		}

		// Pages array
		case MemoryHandlerName::PagesArray :
		{
			// Insert the new data
			member_memoryHandler.member_pagesArrayPointer->InsertElementsFromRawData( dataPointer, index, size );

			// Nothing else needs to be done
			break;
		}

		default:
		{
			// The memory handler type is unknown, throw an exception
			ThrowException( "Unknown memory handler type" );
		}
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename UniversalReferenceDataType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceDataType, DataType >::Result == true )
inline void SequentialDataStructure< DataType, MemoryManagerType >::InsertSingleElementAtTheEnd( UniversalReferenceDataType&& data )
{
	// Insert the element to the end
	InsertSingleElement< UniversalReferenceDataType >( Size(), ForwardUniversalReference< UniversalReferenceDataType >( data ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename UniversalReferenceDataType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceDataType, DataType >::Result == true )
inline void SequentialDataStructure< DataType, MemoryManagerType >::InsertSingleElementAtTheBeginning( UniversalReferenceDataType&& data )
{
	// Insert the element to the beginning
	InsertSingleElement< UniversalReferenceDataType >( 0UL, ForwardUniversalReference< UniversalReferenceDataType >( data ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void SequentialDataStructure< DataType, MemoryManagerType >::Remove( const LargestUnsignedInteger index, const LargestUnsignedInteger size )
{
	// Switch case to choose the required memory handler
	switch ( member_memoryHandlerName )
	{
		// Vector
		case MemoryHandlerName::Vector :
		{
			// Remove the required entries
			member_memoryHandler.member_vectorPointer->Remove( index, size );

			// Nothing else needs to be done
			break;
		}

		// Single linked list
		case MemoryHandlerName::SingleLinkedList :
		{
			// Remove the required entries
			member_memoryHandler.member_singleLinkedListPointer->Remove( index, size );

			// Nothing else needs to be done
			break;
		}

		// Double linked list
		case MemoryHandlerName::DoubleLinkedList :
		{
			// Remove the required entries
			member_memoryHandler.member_doubleLinkedListPointer->Remove( index, size );

			// Nothing else needs to be done
			break;
		}

		// Pages array
		case MemoryHandlerName::PagesArray :
		{
			// Remove the required entries
			member_memoryHandler.member_pagesArrayPointer->Remove( index, size );

			// Nothing else needs to be done
			break;
		}

		default:
		{
			// The memory handler type is unknown, throw an exception
			ThrowException( "Unknown memory handler type" );
		}
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void SequentialDataStructure< DataType, MemoryManagerType >::RemoveFirst()
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsLargerThenZero( Size() );

	// Remove the first element
	Remove( 0UL, 1UL );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline void SequentialDataStructure< DataType, MemoryManagerType >::RemoveLast()
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsLargerThenZero( Size() );

	// Remove the last element
	Remove( Size() - 1UL, 1UL );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline Memory::Tuple< Boolean, LargestUnsignedInteger > SequentialDataStructure< DataType, MemoryManagerType >::SearchSingleElement( const DataType& data, const LargestUnsignedInteger apperanceNumber ) const
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsLargerThenZero( Size() );
	AssertValueIsLargerThenZero( apperanceNumber );

	// Switch case to choose the required memory handler
	switch ( member_memoryHandlerName )
	{
		// Vector
		case MemoryHandlerName::Vector :
		{
			// Search for all the apperances of the required element
			const SequentialDataStructure< LargestUnsignedInteger > apperancesIndices = TakeResourcesAndLeaveInstanceInDefaultState( SearchAllApperancesOfSingleElement__Private< SelfVectorType >( *member_memoryHandler.member_vectorPointer, data ) );

			// Create a tuple with the result and a boolean that tells if the required data was found
			return ( Memory::Tuple< Boolean, LargestUnsignedInteger >( ( apperancesIndices.Size() > 0UL ), apperancesIndices[0] ) );
		}

		// Single linked list
		case MemoryHandlerName::SingleLinkedList :
		{
			// Search for all the apperances of the required element
			const SequentialDataStructure< LargestUnsignedInteger > apperancesIndices = TakeResourcesAndLeaveInstanceInDefaultState( SearchAllApperancesOfSingleElement__Private< SelfSingleLinkedListType >( *member_memoryHandler.member_singleLinkedListPointer, data ) );

			// Create a tuple with the result and a boolean that tells if the required data was found
			return ( Memory::Tuple< Boolean, LargestUnsignedInteger >( ( apperancesIndices.Size() > 0UL ), apperancesIndices[0] ) );
		}

		// Double linked list
		case MemoryHandlerName::DoubleLinkedList :
		{
			// Search for all the apperances of the required element
			const SequentialDataStructure< LargestUnsignedInteger > apperancesIndices = TakeResourcesAndLeaveInstanceInDefaultState( SearchAllApperancesOfSingleElement__Private< SelfDoubleLinkedListType >( *member_memoryHandler.member_doubleLinkedListPointer, data ) );

			// Create a tuple with the result and a boolean that tells if the required data was found
			return ( Memory::Tuple< Boolean, LargestUnsignedInteger >( ( apperancesIndices.Size() > 0UL ), apperancesIndices[0] ) );
		}

		// Pages array
		case MemoryHandlerName::PagesArray :
		{
			// Search for all the apperances of the required element
			const SequentialDataStructure< LargestUnsignedInteger > apperancesIndices = TakeResourcesAndLeaveInstanceInDefaultState( SearchAllApperancesOfSingleElement__Private< SelfPagesArrayType >( *member_memoryHandler.member_pagesArrayPointer, data ) );

			// Create a tuple with the result and a boolean that tells if the required data was found
			return ( Memory::Tuple< Boolean, LargestUnsignedInteger >( ( apperancesIndices.Size() > 0UL ), apperancesIndices[0] ) );
		}

		default:
		{
			// The memory handler type is unknown, throw an exception
			ThrowException( "Unknown memory handler type" );
		}
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline SequentialDataStructure< LargestUnsignedInteger > SequentialDataStructure< DataType, MemoryManagerType >::SearchAllApperancesOfSingleElement( const DataType& data ) const
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsLargerThenZero( Size() );

	// Switch case to choose the required memory handler
	switch ( member_memoryHandlerName )
	{
		// Vector
		case MemoryHandlerName::Vector :
		{
			// Search for all the apperances of the required element. Finally return the results
			return ( SearchAllApperancesOfSingleElement__Private< SelfVectorType >( *member_memoryHandler.member_vectorPointer, data ) );
		}

		// Single linked list
		case MemoryHandlerName::SingleLinkedList :
		{
			// Search for all the apperances of the required element. Finally return the results
			return ( SearchAllApperancesOfSingleElement__Private< SelfSingleLinkedListType >( *member_memoryHandler.member_singleLinkedListPointer, data ) );
		}

		// Double linked list
		case MemoryHandlerName::DoubleLinkedList :
		{
			// Search for all the apperances of the required element. Finally return the results
			return ( SearchAllApperancesOfSingleElement__Private< SelfDoubleLinkedListType >( *member_memoryHandler.member_doubleLinkedListPointer, data ) );
		}

		// Pages array
		case MemoryHandlerName::PagesArray :
		{
			// Search for all the apperances of the required element. Finally return the results
			return ( SearchAllApperancesOfSingleElement__Private< SelfPagesArrayType >( *member_memoryHandler.member_pagesArrayPointer, data ) );
		}

		default:
		{
			// The memory handler type is unknown, throw an exception
			ThrowException( "Unknown memory handler type" );
		}
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename PatternMemoryManagerType >
inline Memory::Tuple< Boolean, LargestUnsignedInteger > SequentialDataStructure< DataType, MemoryManagerType >::SearchPattern( const SequentialDataStructure< DataType, PatternMemoryManagerType >& pattern, const LargestUnsignedInteger apperanceNumber ) const
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsLargerThenZero( Size() );
	AssertValueIsLargerThenZero( pattern.Size() );
	AssertValueIsLargerThenZero( apperanceNumber );

	// There are 9 options for the currently used pointers in this instance and the pattern. Pick the required pointer and use it to search 
	// for the required pattern and specific appearance. Finally return the results

	// This instance - vector -- Other instance - vector 
	if ( member_memoryHandlerName == MemoryHandlerName::Vector && pattern.member_memoryHandlerName == MemoryHandlerName::Vector )
	{
		return ( SearchPattern__Private< SelfVectorType, SelfVectorType >( *member_memoryHandler.member_vectorPointer, *pattern.member_memoryHandler.member_vectorPointer, apperanceNumber ) );
	}

	// This instance - vector -- Other instance - single linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::Vector && pattern.member_memoryHandlerName == MemoryHandlerName::SingleLinkedList )
	{
		return ( SearchPattern__Private< SelfVectorType, SelfSingleLinkedListType >( *member_memoryHandler.member_vectorPointer, *pattern.member_memoryHandler.member_singleLinkedListPointer, apperanceNumber ) );
	}

	// This instance - vector -- Other instance - dobule linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::Vector && pattern.member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList )
	{
		return ( SearchPattern__Private< SelfVectorType, SelfDoubleLinkedListType >( *member_memoryHandler.member_vectorPointer, *pattern.member_memoryHandler.member_doubleLinkedListPointer, apperanceNumber ) );
	}

	// This instance - single linked list -- Other instance - vector
	else if ( member_memoryHandlerName == MemoryHandlerName::SingleLinkedList && pattern.member_memoryHandlerName == MemoryHandlerName::Vector )
	{
		return ( SearchPattern__Private< SelfSingleLinkedListType, SelfVectorType >( *member_memoryHandler.member_singleLinkedListPointer, *pattern.member_memoryHandler.member_vectorPointer, apperanceNumber ) );
	}

	// This instance - single linked list -- Other instance - single linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::SingleLinkedList && pattern.member_memoryHandlerName == MemoryHandlerName::SingleLinkedList )
	{
		return ( SearchPattern__Private< SelfSingleLinkedListType, SelfSingleLinkedListType >( *member_memoryHandler.member_singleLinkedListPointer, *pattern.member_memoryHandler.member_singleLinkedListPointer, apperanceNumber ) );
	}

	// This instance - single linked list -- Other instance - double linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::SingleLinkedList && pattern.member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList )
	{
		return ( SearchPattern__Private< SelfSingleLinkedListType, SelfDoubleLinkedListType >( *member_memoryHandler.member_singleLinkedListPointer, *pattern.member_memoryHandler.member_doubleLinkedListPointer, apperanceNumber ) );
	}

	// This instance - double linked list -- Other instance - vector
	else if ( member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList && pattern.member_memoryHandlerName == MemoryHandlerName::Vector )
	{
		return ( SearchPattern__Private< SelfDoubleLinkedListType, SelfVectorType >( *member_memoryHandler.member_doubleLinkedListPointer, *pattern.member_memoryHandler.member_vectorPointer, apperanceNumber ) );
	}

	// This instance - double linked list -- Other instance - single linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList && pattern.member_memoryHandlerName == MemoryHandlerName::SingleLinkedList )
	{
		return ( SearchPattern__Private< SelfDoubleLinkedListType, SelfSingleLinkedListType >( *member_memoryHandler.member_doubleLinkedListPointer, *pattern.member_memoryHandler.member_singleLinkedListPointer, apperanceNumber ) );
	}

	// This instance - double linked list -- Other instance - double linked list
	else
	{
		return ( SearchPattern__Private< SelfDoubleLinkedListType, SelfDoubleLinkedListType >( *member_memoryHandler.member_doubleLinkedListPointer, *pattern.member_memoryHandler.member_doubleLinkedListPointer, apperanceNumber ) );
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename PatternMemoryManagerType >
inline SequentialDataStructure< LargestUnsignedInteger, MemoryManagerType > SequentialDataStructure< DataType, MemoryManagerType >::SearchAllApperancesOfPattern( const SequentialDataStructure< DataType, PatternMemoryManagerType >& pattern ) const
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsLargerThenZero( Size() );
	AssertValueIsLargerThenZero( pattern.Size() );

	// There are 9 options for the currently used pointers in this instance and the pattern. Pick the required pointer and use it to search
	// for all the apperances of the required pattern. Finally return the results

	// This instance - vector -- Other instance - vector 
	if ( member_memoryHandlerName == MemoryHandlerName::Vector && pattern.member_memoryHandlerName == MemoryHandlerName::Vector )
	{
		return ( SearchAllApperancesOfPattern__Private< SelfVectorType, SelfVectorType >( *member_memoryHandler.member_vectorPointer, *pattern.member_memoryHandler.member_vectorPointer ) );
	}

	// This instance - vector -- Other instance - single linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::Vector && pattern.member_memoryHandlerName == MemoryHandlerName::SingleLinkedList )
	{
		return ( SearchAllApperancesOfPattern__Private< SelfVectorType, SelfSingleLinkedListType >( *member_memoryHandler.member_vectorPointer, *pattern.member_memoryHandler.member_singleLinkedListPointer ) );
	}

	// This instance - vector -- Other instance - dobule linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::Vector && pattern.member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList )
	{
		return ( SearchAllApperancesOfPattern__Private< SelfVectorType, SelfDoubleLinkedListType >( *member_memoryHandler.member_vectorPointer, *pattern.member_memoryHandler.member_doubleLinkedListPointer ) );
	}

	// This instance - single linked list -- Other instance - vector
	else if ( member_memoryHandlerName == MemoryHandlerName::SingleLinkedList && pattern.member_memoryHandlerName == MemoryHandlerName::Vector )
	{
		return ( SearchAllApperancesOfPattern__Private< SelfSingleLinkedListType, SelfVectorType >( *member_memoryHandler.member_singleLinkedListPointer, *pattern.member_memoryHandler.member_vectorPointer ) );
	}

	// This instance - single linked list -- Other instance - single linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::SingleLinkedList && pattern.member_memoryHandlerName == MemoryHandlerName::SingleLinkedList )
	{
		return ( SearchAllApperancesOfPattern__Private< SelfSingleLinkedListType, SelfSingleLinkedListType >( *member_memoryHandler.member_singleLinkedListPointer, *pattern.member_memoryHandler.member_singleLinkedListPointer ) );
	}

	// This instance - single linked list -- Other instance - double linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::SingleLinkedList && pattern.member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList )
	{
		return ( SearchAllApperancesOfPattern__Private< SelfSingleLinkedListType, SelfDoubleLinkedListType >( *member_memoryHandler.member_singleLinkedListPointer, *pattern.member_memoryHandler.member_doubleLinkedListPointer ) );
	}

	// This instance - double linked list -- Other instance - vector
	else if ( member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList && pattern.member_memoryHandlerName == MemoryHandlerName::Vector )
	{
		return ( SearchAllApperancesOfPattern__Private< SelfDoubleLinkedListType, SelfVectorType >( *member_memoryHandler.member_doubleLinkedListPointer, *pattern.member_memoryHandler.member_vectorPointer ) );
	}

	// This instance - double linked list -- Other instance - single linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList && pattern.member_memoryHandlerName == MemoryHandlerName::SingleLinkedList )
	{
		return ( SearchAllApperancesOfPattern__Private< SelfDoubleLinkedListType, SelfSingleLinkedListType >( *member_memoryHandler.member_doubleLinkedListPointer, *pattern.member_memoryHandler.member_singleLinkedListPointer ) );
	}

	// This instance - double linked list -- Other instance - double linked list
	else
	{
		return ( SearchAllApperancesOfPattern__Private< SelfDoubleLinkedListType, SelfDoubleLinkedListType >( *member_memoryHandler.member_doubleLinkedListPointer, *pattern.member_memoryHandler.member_doubleLinkedListPointer ) );
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename PatternMemoryManagerType >
EnsureRetrunValueIsUsed inline Boolean SequentialDataStructure< DataType, MemoryManagerType >::Contains( const SequentialDataStructure< DataType, PatternMemoryManagerType >& pattern ) const
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsLargerThenZero( Size() );
	AssertValueIsLargerThenZero( pattern.Size() );

	// Search for the pattern
	const Memory::Tuple< Boolean, LargestUnsignedInteger > searchResult = SearchPattern( pattern );

	// Return if the pattern exist
	return ( searchResult.template Entry< 0UL >() );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline DataType& SequentialDataStructure< DataType, MemoryManagerType >::First()
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsLargerThenZero( Size() );

	// Return a reference to the first element
	return ( operator[]( 0UL ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline const DataType& SequentialDataStructure< DataType, MemoryManagerType >::First() const
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsLargerThenZero( Size() );

	// Return a constant reference to the first element
	return ( operator[]( 0UL ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline DataType& SequentialDataStructure< DataType, MemoryManagerType >::Last()
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsLargerThenZero( Size() );

	// Return a reference to the last element
	return ( operator[]( Size() - 1UL ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline const DataType& SequentialDataStructure< DataType, MemoryManagerType >::Last() const
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsLargerThenZero( Size() );

	// Return a constant reference to the last element
	return ( operator[]( Size() - 1UL ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline DataType* SequentialDataStructure< DataType, MemoryManagerType >::DataPointer() const
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	Assert( member_memoryHandlerName == MemoryHandlerName::Vector, "The instance is not using the vector as the memory handler" );

	// Return a the pointer inside the vector memory handler
	return ( member_memoryHandler.member_vectorPointer->DataPointer() );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline const Memory::Vector< DataType* >& SequentialDataStructure< DataType, MemoryManagerType >::PointersToPages() const
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	Assert( member_memoryHandlerName == MemoryHandlerName::PagesArray, "The instance is not using the pages array as the memory handler" );

	// Return a vector with the pointers to the pages
	return ( member_memoryHandler.member_pagesArrayPointer->PointersToPages() );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline Boolean SequentialDataStructure< DataType, MemoryManagerType >::operator==( const SelfType& other ) const
{
	// This object will store the size of this instance
	const LargestUnsignedInteger size = Size();

	// This object will store the size of the other instance
	const LargestUnsignedInteger otherSize = other.Size();

	// Compare the size of both instances and in case its different return false
	ReturnValueIfExpressionIsTrue( ( size != otherSize ), false );

	// The size of both instance is the same, check if both instances size is zero, which means both of them are in default state
	// then return true
	ReturnValueIfExpressionIsTrue( ( size == 0UL ), true );

	// Compare the instance and return the result
    return ( Compare( other, 0UL, 0UL, size ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline Boolean SequentialDataStructure< DataType, MemoryManagerType >::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline DataType& SequentialDataStructure< DataType, MemoryManagerType >::operator[]( const LargestUnsignedInteger index )
{
	// Switch case to choose the required memory handler
	switch ( member_memoryHandlerName )
	{
		// Vector
		case MemoryHandlerName::Vector :
		{
			// Use the square brackets operator to return a reference to the required entry
			return ( member_memoryHandler.member_vectorPointer->operator[]( index ) );
		}

		// Single linked list
		case MemoryHandlerName::SingleLinkedList :
		{
			// Use the square brackets operator to return a reference to the required entry
			return ( member_memoryHandler.member_singleLinkedListPointer->operator[]( index ) );
		}

		// Double linked list
		case MemoryHandlerName::DoubleLinkedList :
		{
			// Use the square brackets operator to return a reference to the required entry
			return ( member_memoryHandler.member_doubleLinkedListPointer->operator[]( index ) );
		}

		// Pages array
		case MemoryHandlerName::PagesArray :
		{
			// Use the square brackets operator to return a reference to the required entry
			return ( member_memoryHandler.member_pagesArrayPointer->operator[]( index ) );
		}

		default:
		{
			// The memory handler type is unknown, throw an exception
			ThrowException( "Unknown memory handler type" );
		}
	}	
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline const DataType& SequentialDataStructure< DataType, MemoryManagerType >::operator[]( const LargestUnsignedInteger index ) const
{
	// Switch case to choose the required memory handler
	switch ( member_memoryHandlerName )
	{
		// Vector
		case MemoryHandlerName::Vector :
		{
			// Use the square brackets operator to return a constant reference to the required entry
			return ( member_memoryHandler.member_vectorPointer->operator[]( index ) );
		}

		// Single linked list
		case MemoryHandlerName::SingleLinkedList :
		{
			// Use the square brackets operator to return a constant reference to the required entry
			return ( member_memoryHandler.member_singleLinkedListPointer->operator[]( index ) );
		}

		// Double linked list
		case MemoryHandlerName::DoubleLinkedList :
		{
			// Use the square brackets operator to return a constant reference to the required entry
			return ( member_memoryHandler.member_doubleLinkedListPointer->operator[]( index ) );
		}

		// Pages array
		case MemoryHandlerName::PagesArray :
		{
			// Use the square brackets operator to return a constant reference to the required entry
			return ( member_memoryHandler.member_pagesArrayPointer->operator[]( index ) );
		}

		default:
		{
			// The memory handler type is unknown, throw an exception
			ThrowException( "Unknown memory handler type" );
		}
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
inline SequentialDataStructure< DataType, MemoryManagerType >& SequentialDataStructure< DataType, MemoryManagerType >::operator+=( const SelfType& other )
{
	// There are 9 options for the currently used pointers in this instance and the pattern. Pick the required pointer and use it to add 
	// the other instance to the end of this instance

	// This instance - vector -- Other instance - vector 
	if ( member_memoryHandlerName == MemoryHandlerName::Vector && other.member_memoryHandlerName == MemoryHandlerName::Vector )
	{
		member_memoryHandler.member_vectorPointer->operator+=( *other.member_memoryHandler.member_vectorPointer );
	}

	// This instance - vector -- Other instance - single linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::Vector && other.member_memoryHandlerName == MemoryHandlerName::SingleLinkedList )
	{
		member_memoryHandler.member_vectorPointer->operator+=( *other.member_memoryHandler.member_vectorPointer );
	}

	// This instance - vector -- Other instance - dobule linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::Vector && other.member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList )
	{
		member_memoryHandler.member_vectorPointer->operator+=( *other.member_memoryHandler.member_vectorPointer );
	}

	// This instance - single linked list -- Other instance - vector
	else if ( member_memoryHandlerName == MemoryHandlerName::SingleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::Vector )
	{
		member_memoryHandler.member_singleLinkedListPointer->operator+=( *other.member_memoryHandler.member_singleLinkedListPointer );
	}

	// This instance - single linked list -- Other instance - single linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::SingleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::SingleLinkedList )
	{
		member_memoryHandler.member_singleLinkedListPointer->operator+=( *other.member_memoryHandler.member_singleLinkedListPointer );
	}

	// This instance - single linked list -- Other instance - double linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::SingleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList )
	{
		member_memoryHandler.member_singleLinkedListPointer->operator+=( *other.member_memoryHandler.member_singleLinkedListPointer );
	}

	// This instance - double linked list -- Other instance - vector
	else if ( member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::Vector )
	{
		member_memoryHandler.member_doubleLinkedListPointer->operator+=( *other.member_memoryHandler.member_doubleLinkedListPointer );
	}

	// This instance - double linked list -- Other instance - single linked list
	else if ( member_memoryHandlerName == MemoryHandlerName::DoubleLinkedList && other.member_memoryHandlerName == MemoryHandlerName::SingleLinkedList )
	{
		member_memoryHandler.member_doubleLinkedListPointer->operator+=( *other.member_memoryHandler.member_doubleLinkedListPointer );
	}

	// This instance - double linked list -- Other instance - double linked list
	else
	{
		member_memoryHandler.member_doubleLinkedListPointer->operator+=( *other.member_memoryHandler.member_doubleLinkedListPointer );
	}


	// Return a reference to this instance
	return ( *this );
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename... AnyArgumentsNeededToConstructMemoryHandlerTypes >
inline void SequentialDataStructure< DataType, MemoryManagerType >::ConstructMemoryHandler__Private( AnyArgumentsNeededToConstructMemoryHandlerTypes... anyArgumentsNeededToConstructMemoryHandler )
{
	// Switch case to choose the required memory handler
	switch ( member_memoryHandlerName )
	{
		// Vector
		case MemoryHandlerName::Vector :
		{
			// Construct the vector
			member_memoryHandler.member_vectorPointer = MemoryManagerType::template AllocateAndConstruct< SelfVectorType >( ForwardUniversalReference< AnyArgumentsNeededToConstructMemoryHandlerTypes >( anyArgumentsNeededToConstructMemoryHandler )... );

			// Nothing else needs to be done
			break;
		}

		// Single linked list
		case MemoryHandlerName::SingleLinkedList :
		{
			// Construct the single linked list
			member_memoryHandler.member_singleLinkedListPointer = MemoryManagerType::template AllocateAndConstruct< SelfSingleLinkedListType >( ForwardUniversalReference< AnyArgumentsNeededToConstructMemoryHandlerTypes >( anyArgumentsNeededToConstructMemoryHandler )... );

			// Nothing else needs to be done
			break;
		}

		// Double linked list
		case MemoryHandlerName::DoubleLinkedList :
		{
			// Construct the double linked list
			member_memoryHandler.member_doubleLinkedListPointer = MemoryManagerType::template AllocateAndConstruct< SelfDoubleLinkedListType >( ForwardUniversalReference< AnyArgumentsNeededToConstructMemoryHandlerTypes >( anyArgumentsNeededToConstructMemoryHandler )... );

			// Nothing else needs to be done
			break;
		}

		// Pages array
		case MemoryHandlerName::PagesArray :
		{
			// Construct the pages array
			member_memoryHandler.member_pagesArrayPointer = MemoryManagerType::template AllocateAndConstruct< SelfPagesArrayType >( ForwardUniversalReference< AnyArgumentsNeededToConstructMemoryHandlerTypes >( anyArgumentsNeededToConstructMemoryHandler )... );

			// Nothing else needs to be done
			break;
		}

		default:
		{
			// The memory handler type is unknown, throw an exception
			ThrowException( "Unknown memory handler type" );
		}
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename CurrentMemoryHandlerType >
inline void SequentialDataStructure< DataType, MemoryManagerType >::SwitchMemoryHandler__Private( const MemoryHandlerName newMemoryHandlerName, CurrentMemoryHandlerType* const currentMemoryHandlerPointer )
{
	// Switch case to choose the required memory handler
	switch ( newMemoryHandlerName )
	{
		// Vector
		case MemoryHandlerName::Vector :
		{
			// Create the new memory handler from the current one, and store the memory address in the pointer
			SelfVectorType* const newMemoryHandlerPointer = MemoryManagerType::template AllocateAndConstruct< SelfVectorType >( TakeResourcesAndLeaveInstanceInDefaultState( *currentMemoryHandlerPointer ), 0UL, currentMemoryHandlerPointer->Size() );

			// Delete the memory space used for the current memory handler
			delete currentMemoryHandlerPointer;

			// Set the new vector memory handler
			member_memoryHandler.member_vectorPointer = newMemoryHandlerPointer;

			// Nothing else needs to be done
			break;
		}

		// Single linked list
		case MemoryHandlerName::SingleLinkedList :
		{
			// Create the new memory handler from the current one, and store the memory address in the pointer
			SelfSingleLinkedListType* const newMemoryHandlerPointer = MemoryManagerType::template AllocateAndConstruct< SelfSingleLinkedListType >( TakeResourcesAndLeaveInstanceInDefaultState( *currentMemoryHandlerPointer ), 0UL, currentMemoryHandlerPointer->Size() );

			// Delete the memory space used for the current memory handler
			delete currentMemoryHandlerPointer;

			// Set the new single linked list memory handler
			member_memoryHandler.member_singleLinkedListPointer = newMemoryHandlerPointer;

			// Nothing else needs to be done
			break;
		}

		// Double linked list
		case MemoryHandlerName::DoubleLinkedList :
		{
			// Create the new memory handler from the current one, and store the memory address in the pointer
			SelfDoubleLinkedListType* const newMemoryHandlerPointer = MemoryManagerType::template AllocateAndConstruct< SelfDoubleLinkedListType >( TakeResourcesAndLeaveInstanceInDefaultState( *currentMemoryHandlerPointer ), 0UL, currentMemoryHandlerPointer->Size() );

			// Delete the memory space used for the current memory handler
			delete currentMemoryHandlerPointer;

			// Set the new double linked list memory handler
			member_memoryHandler.member_doubleLinkedListPointer = newMemoryHandlerPointer;

			// Nothing else needs to be done
			break;
		}

		// Pages array
		case MemoryHandlerName::PagesArray :
		{
			// Create the new memory handler from the current one, and store the memory address in the pointer
			SelfPagesArrayType* const newMemoryHandlerPointer = MemoryManagerType::template AllocateAndConstruct< SelfPagesArrayType >( TakeResourcesAndLeaveInstanceInDefaultState( *currentMemoryHandlerPointer ), 0UL, currentMemoryHandlerPointer->Size() );

			// Delete the memory space used for the current memory handler
			delete currentMemoryHandlerPointer;

			// Set the new pages array memory handler
			member_memoryHandler.member_pagesArrayPointer = newMemoryHandlerPointer;

			// Nothing else needs to be done
			break;
		}

		default:
		{
			// The memory handler type is unknown, throw an exception
			ThrowException( "Unknown memory handler type" );
		}
	}
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename MemoryHandlerType >
inline Memory::Tuple< Boolean, LargestUnsignedInteger > SequentialDataStructure< DataType, MemoryManagerType >::SearchSingleElement__Private( const MemoryHandlerType& memoryHandler, const DataType& data, LargestUnsignedInteger apperanceNumber ) const
{
	// This object will store the size of the instance
	const LargestUnsignedInteger size = Size();

	// This object will store the number of apperances already found
	LargestUnsignedInteger numberOfApperancesAlreadyFound = 0UL;

	// Loop until the required apperance was found or the data ended
	for ( LargestUnsignedInteger index = 0UL ; index < size ; ++index )
	{
		// Check if the current entry contains the required data
		if ( memoryHandler[ index ] == data )
		{
			// The next apperance of the data was found

			// Increment the number of apperances found by 1
			numberOfApperancesAlreadyFound += 1UL;

			// Check if the required apperance of the data was reached
			if ( numberOfApperancesAlreadyFound == apperanceNumber )
			{
				// The required apperance was found

				// Return the index of the current apperance
				return ( Memory::Tuple< Boolean, LargestUnsignedInteger >( true, index ) );
			}
		}
	}

	// The required appearance of the data was not found
	return ( Memory::Tuple< Boolean, LargestUnsignedInteger >( false, 0UL ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename MemoryHandlerType >
inline SequentialDataStructure< LargestUnsignedInteger > SequentialDataStructure< DataType, MemoryManagerType >::SearchAllApperancesOfSingleElement__Private( const MemoryHandlerType& memoryHandler, const DataType& data ) const
{
	// This object will store the indices where the required data was found
	SequentialDataStructure< LargestUnsignedInteger > apperancesIndices( MemoryHandlerName::Vector );

	// This object will store the number of apperances already found
	LargestUnsignedInteger numberOfApperancesAlreadyFound = 0UL;

	// This object will store the size of the instance
	const LargestUnsignedInteger size = Size();

	// Loop until the required apperance was found or the sequential data structure instance reached the end
	for ( LargestUnsignedInteger index = 0UL ; index < size ; ++index )
	{
		// Check if the current entry contains the required data
		if ( memoryHandler[ index ] == data )
		{
			// The required data was found

			// Add the current index
			apperancesIndices.InsertSingleElement( apperancesIndices.Size(), index );
		}
	}

	// Return a tuple that contains a boolean with the value false, to notify that the search was unsuccessful
	return ( apperancesIndices );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename PatternMemoryHandlerType >
inline Memory::Vector< LargestUnsignedInteger > SequentialDataStructure< DataType, MemoryManagerType >::ProcessPatternToFindTheStartingPointForTheNextSearchIfMismatchWasFoundBetweenThePatternAndTheData__Private( const PatternMemoryHandlerType& pattern ) const
{
	// The rational :
	//
	// When searching for a pattern in the data, the complexity is large because for each index in the data, the search needs to be made which 
	// can be in the worst case, for 'n' number of entries and 'm' number of entries in the pattern :
	//
	//			O( n * ( m - 1 ) )
	//
	// Which is unwanted.
	//
	// Now, the data is not known in advance, but only the pattern that needs to be found, therefore to optimize the search the pattern will
	// be processed. The general point is to set the amount to increase the index on the data in the next search for every entry in the pattern,
	// if the mismatch between the data and the pattern happend in that entry.
	//
	// The first 2 entries of each pattern always act the same on the increasing of the index on the data for mismatch. For the first entry if
	// it does not match the data then the index on the data must increase by 1 to check the next entry. In the case of the second entry, the
	// amount to advance depends if the first and second entry has the same content. If they do have the same content, then the index on the data
	// can advance by 2, and if they mismatch then only by 1.
	//
	//
	//			Data 		->		hklsdlfslklsda
	//
	//			Pattern    	->    	abcdefg
	//
	//
	//				Try to match 1 :      index of data == 1  index of pattern == 1
	//
	//															hkasdlfslklsda
	//					   mismatch at first entry of pattern	|
	//															abcdefg
	//
	//				Result - index on data needs to be increased by 1
	//
	//
	//				Try to match 2 :      index of data == 2  index of pattern == 1
	//
	//															hkasdlfslklsda
	//					   mismatch at first entry of pattern	 |
	//												 			 abcdefg
	//
	//				Result - index on data needs to be increased by 1
	//
	//
	//				Try to match 3 :      index of data == 3  index of pattern == 1
	//
	//															hkasdlfslklsda
	//					   match at first entry of pattern	      |
	//												 			  abcdefg
	//
	//				Result - index on the pattern needs to be increased by 1
	//
	//
	//				Try to match 3 :      index of data == 3  index of pattern == 2
	//
	//															hkasdlfslklsda
	//					   mismatch at second entry of pattern	   |
	//												 			  abcdefg
	//
	//				Result - index on the pattern needs to be increased by 1
	//
	//
	// The easiest pattern is where all the parts of the pattern are different. In the easiest pattern, each entry beside the first 2, the index
	// on the data at the next search will be increased by the entry index in the pattern. This because what is known that the data match exactly
	// all the previous part of the pattern until the point of the mismatch, each part of the pattern is different so shifting it by any number 
	// smaller then the location of the mismatch will also create mismatch.
	// 
	//
	//			Data 		->		abcdefhhslklsda
	//
	//			Pattern    	->    	abcdefg
	//
	//
	//				Try to match 1 :      index of data == 1  index of pattern == 6
	//
	//															abcdefhhslklsda
	//					   mismatch at first entry of pattern	      |
	//															abcdefg
	//
	//				Result - index on data needs to be increased by 6, as can be seen any other shift will return mismatch :
	//
	//															abcdefhhslklsda
	//					   mismatch at first entry of pattern	 |
	//															 abcdefg
	//
	//															abcdefhhslklsda
	//					   mismatch at first entry of pattern	  |
	//															  abcdefg
	//
	// And so on.
	//
	// In most cases then the next index on the data will be increased by the index of the pattern where the mismatch happend. The cases
	// where this does not apply, is for patterns that contains repeating parts inside them. For example :
	//
	//
	//			Pattern    	->    	abcabcf
	//
	//
	// At this case mismatch at 'f', will allow adding to the index on the data only 3, because all that is known that the data does not contain
	// 'f', but it can contain 'a'. For example :
	//
	//
	//			Data 		->		abcabcabcf
	//
	//			Pattern    	->    	abcabcf
	//
	//				Try to match 1 :      index of data == 1  index of pattern == 6
	//
	//															abcabcabcf
	//					   mismatch at first entry of pattern	      |
	//															abcabcf
	//
	//				Result - index on data needs to be increased by 3 and not by 6, otherwise the apperance of the pattern in the data will be skipped
	//
	//
	// Therefore the processing of the pattern means for each entry of the pattern checking if it contains matching subparts, and setting the amount
	// to increase the index of the data appropriately!
	//
	// Then processing the pattern means for each entry trying to find a subpattern that match the starting of the pattern. For example :
	//
	//
	//			Pattern    	->    	abcabwf
	//
	//			For index 2 :
	//
	//					ab c abwf
	//
	//				The subpatterns are : 
	//
	//					a - b
	//
	//
	// And as can be seen 'a' and 'b' do not match.
	//
	//
	//			For index 3 :
	//
	//					abc a bwf
	//
	//				The subpatterns are : 
	//
	//					ab - bc AND a - c
	//
	//
	// Again the subpatterns do not match.
	//
	//
	//			For index 4 :
	//
	//					abca b wf
	//
	//				The subpatterns are : 
	//
	//					abc - bca AND ab - ca AND a - a
	//
	//
	// Only the last subpattern which consist of 'a' match, but because the mismatch happend with 'b', and also in the beginning of the pattern
	// the next letter after 'a' is 'b', then it won't match anyway and in this case the index on the data can also increase by the index on the
	// pattern.
	//
	//
	//			For index 5 :
	//
	//					abcab w f
	//
	//				The subpatterns are : 
	//
	//					abca - bcab AND abc - cab AND ab - ab AND a - b
	//
	//
	// The subpattern 'ab' match. The mismatch happend at 'w', therefore the index on the data can only increase by 3, becasue in the mismatch
	// it is known that is not 'w', but it can be 'c!


	// This object will store the size of the pattern
	const LargestUnsignedInteger patternSize = pattern.Size();

	// This object will store the final result of processing the pattern. Processing the pattern means finding for each entry at the pattern, what to do
	// if a mismatch with the actual data of the container was found. Without this optimization each time a mismatch will be found the search will have to
	// start from the beginning of the pattern, instead this object will tell from which index of entry at the pattern the search should start again. If the
	// pattern size less then 3, this object is redundant
	Memory::Vector< LargestUnsignedInteger > startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch( patternSize );

	// If the mismatch between the pattern and the data happend in the first entry of the pattern, the index on the data should always be increased
	// by 1
	startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch[0] = 1UL;

	// Check if the size of the pattern is 1
	if ( patternSize == 1UL )
	{
		// The size of the pattern is 1

		// Nothing else needs to be done
		return ( startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch );
	}

	// If the mismatch between the pattern and the data happend in the second entry of the pattern, the content of the first and second entry
	// in the pattern needs to be compared. If the content is the same, then the index on the data needs to be advanced by 1, otherwise it
	// can be advanced by 2
	if ( pattern[0] != pattern[1] )
	{
		// The content of the first and second entry of the pattern are not the same

		// Set to advance the index on the data by 1
		startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch[1] = 1UL;
	}
	else
	{
		// The content of the first and second entry of the pattern are the same

		// Set to advance the index on the data by 2
		startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch[1] = 2UL;
	}

	// Check if the size of the pattern is 2
	if ( patternSize == 2UL )
	{
		// The size of the pattern is 1

		// Nothing else needs to be done
		return ( startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch );
	}

	// This object will store the amount the index on the data needs to be incremented by, if a mismatch happend at the current index
	LargestUnsignedInteger incrementIndexOnDataByThisAmount = 0UL;

	// Loop on all the entries of the pattern, starting from the third entry
	for ( LargestUnsignedInteger patternIndex = 2UL ; patternIndex < patternSize ; ++patternIndex )
	{
		// Check if the search needs to start again from lower or index, or it can move forward. It is done by passing on all the subpatterns
		// that start from the second entry of the pattern, until the given index, when each subpattern start one index forward and is smaller
		// by one then the previous. The point is to match this subpatterns with subpatterns that always start from the beginning of the pattern,
		// but the size is smaller by one each time

		// Set the amount to increase the index on the data to the current pattern index. This is the general case, if a subpattern will be found
		// it will set this object to the required amount instead
		incrementIndexOnDataByThisAmount = patternIndex;

		// Loop on the entries of the pattern from the second one until the current pattern index
		for ( LargestUnsignedInteger subpatternFirstEntryIndex = 1UL ; subpatternFirstEntryIndex < patternIndex ; ++subpatternFirstEntryIndex )
		{
			// Check if the current subpattern, match the subpattern at the beginning of the pattern, with the same size
			if ( Compare__Private( pattern, subpatternFirstEntryIndex, ( patternIndex - subpatternFirstEntryIndex ) ) == true )
			{
				// A subpattern that match the beginning of the pattern was found

				// The index on the data then should not be incremented by the pattern index, but rather only the amount to the first entry
				// of the matching subpattern
				incrementIndexOnDataByThisAmount = subpatternFirstEntryIndex;

				// The longest subpattern was found, break the loop
				break;
			}
		}

		// Set the amount that the index on the data needs to be incremented by, if a mismatch happend at the current pattern index
		startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch[ patternIndex ] = incrementIndexOnDataByThisAmount;
	}

	// Return the result of processing the pattern
	return ( startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename PatternMemoryHandlerType >
inline Boolean SequentialDataStructure< DataType, MemoryManagerType >::Compare__Private( const PatternMemoryHandlerType& pattern, const LargestUnsignedInteger subpatternFirstEntryIndex, const LargestUnsignedInteger subpatternSize ) const
{
	// Loop on all the entries of the subpattern
	for ( LargestUnsignedInteger subpatternIndex = 0UL ; subpatternIndex < subpatternSize ; ++subpatternIndex )
	{
		// Check if the content of the current entry in the subpattern match the content of the equivalent entry of the subpattern
		// that starts from the beginning of the pattern
		if ( pattern[ subpatternIndex ] != pattern[ subpatternFirstEntryIndex + subpatternIndex ] )
		{
			// The content does not match

			// Return that the subpatterns are not the same
			return ( false );
		}
	}

	// If control of the method reached here then the subpatterns match
	return ( true );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename MemoryHandlerType, typename PatternMemoryHandlerType >
inline LargestUnsignedInteger SequentialDataStructure< DataType, MemoryManagerType >::FindNextApperance__Private( const MemoryHandlerType& memoryHandler, LargestUnsignedInteger startSearchFromThisIndex, const PatternMemoryHandlerType& pattern, const Memory::Vector< LargestUnsignedInteger >& startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch ) const
{
	// This object will store the size of the pattern
	const LargestUnsignedInteger patternSize = pattern.Size();

	// This object will store the index on the pattern
	LargestUnsignedInteger patternIndex = 0UL;

	// This object will store the data size minus the pattern size, to prevent calculating it each time
	const LargestUnsignedInteger stopAtThisIndex = ( memoryHandler.Size() - ( patternSize - 1UL ) );

	// Loop on the data starting at the given index
	for ( LargestUnsignedInteger index = startSearchFromThisIndex ; index < stopAtThisIndex ; index += startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch[ patternIndex ] )
	{
		// Set the index on the pattern to 0
		patternIndex = 0UL;

		// Loop on the pattern
		while ( patternIndex < patternSize )
		{
			// Check if the current entry in the pattern match the data
			if ( memoryHandler[ index + patternIndex ] != pattern[ patternIndex ] )
			{
				// The data and the pattern does not match

				// Break the loop
				break;
			}

			// Increment the index on the pattern by 1
			patternIndex += 1UL;
		}

		// Check if the pattern was currently found in the data, by checking if the loop passed on all the pattern
		if ( patternIndex == patternSize )
		{
			// An apperance of the pattern in the data was found

			// Return the index on the data
			return ( index );
		}
	}

	// If control reached here this means the pattern was not found in the data, return the size of the data
	return ( Size() );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename MemoryHandlerType, typename PatternMemoryHandlerType >
inline Memory::Tuple< Boolean, LargestUnsignedInteger > SequentialDataStructure< DataType, MemoryManagerType >::SearchPattern__Private( const MemoryHandlerType& memoryHandler, const PatternMemoryHandlerType& pattern, const LargestUnsignedInteger apperanceNumber ) const
{
	// This object will store the result of processing the pattern. It will contain the information on the amount to advance the index on the data
	// in case a mismatch between the data and the pattern was found at a specific index on the pattern
	const Memory::Vector< LargestUnsignedInteger > startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch( TakeResourcesAndLeaveInstanceInDefaultState( ProcessPatternToFindTheStartingPointForTheNextSearchIfMismatchWasFoundBetweenThePatternAndTheData__Private< PatternMemoryHandlerType >( pattern ) ) );

	// This object will store the index of the current apperance
	LargestUnsignedInteger indexOfCurrentApperance = 0UL;

	// This object will store the number of apperances already found
	LargestUnsignedInteger numberOfApperancesAlreadyFound = 0UL;

	// This object will store the size of the instance
	const LargestUnsignedInteger size = Size();

	// This object will store the sequential data structure size minus the pattern size, to prevent calculating it each time
	const LargestUnsignedInteger lastIndexPatternCanStillFitIn = ( size - pattern.Size() + 1 );

	// Loop until the required apperance was found or the data ended
	for ( LargestUnsignedInteger index = 0UL ; index < lastIndexPatternCanStillFitIn ; index = indexOfCurrentApperance + 1UL )
	{
		// Try to find the next apperance of the pattern in the data
		indexOfCurrentApperance = FindNextApperance__Private< MemoryHandlerType, PatternMemoryHandlerType >( memoryHandler, index, pattern, startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch );

		// Check if the next apperance of the pattern was not found
		if ( indexOfCurrentApperance == size )
		{
			// The next apperance of the pattern was not found

			// Break the loop
			break;
		}

		// The next apperance of the pattern was found

		// Increment the number of apperances of the pattern found by 1
		numberOfApperancesAlreadyFound += 1UL;

		// Check if the required apperance number was found
		if ( apperanceNumber == numberOfApperancesAlreadyFound )
		{
			// The required apperance of the pattern in the data was found

			// Create a tuple with a boolean with the value true to notify that the search was successful, and the index the pattern 
			// was found at
			return ( Memory::Tuple< Boolean, LargestUnsignedInteger >( true, indexOfCurrentApperance ) );
		}
	}

	// Return a tuple that contains a boolean with the value false, to notify that the search was unsuccessful
	return ( Memory::Tuple< Boolean, LargestUnsignedInteger >( false, 0UL ) );
}


template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
template< typename MemoryHandlerType, typename PatternMemoryHandlerType >
inline SequentialDataStructure< LargestUnsignedInteger > SequentialDataStructure< DataType, MemoryManagerType >::SearchAllApperancesOfPattern__Private( const MemoryHandlerType& memoryHandler, const PatternMemoryHandlerType& pattern ) const
{
	// This object will store the indices where the pattern was found
	SequentialDataStructure< LargestUnsignedInteger > apperancesIndices( MemoryHandlerName::Vector );

	// This object will store the size of the apperances indices sequential data structure
	LargestUnsignedInteger apperancesIndicesSize = 0UL;

	// This object will store the result of processing the pattern. It will contain the information on the amount to advance the index on the data
	// in case a mismatch between the data and the pattern was found at a specific index on the pattern
	const Memory::Vector< LargestUnsignedInteger > startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch( TakeResourcesAndLeaveInstanceInDefaultState( ProcessPatternToFindTheStartingPointForTheNextSearchIfMismatchWasFoundBetweenThePatternAndTheData__Private( pattern ) ) );

	// This object will store the index of the current apperance
	LargestUnsignedInteger indexOfCurrentApperance = 0UL;

	// This object will store the number of apperances already found
	LargestUnsignedInteger numberOfApperancesAlreadyFound = 0UL;

	// This object will store the size of the instance
	const LargestUnsignedInteger size = Size();

	// This object will store the sequential data structure size minus the pattern size, to prevent calculating it each time
	const LargestUnsignedInteger lastIndexPatternCanStillFitIn = size - pattern.Size() + 1;

	// Loop until the required apperance was found or the data ended
	for ( LargestUnsignedInteger index = 0UL ; index < lastIndexPatternCanStillFitIn ; index = indexOfCurrentApperance + 1UL )
	{
		// Try to find the next apperance of the pattern in the data
		indexOfCurrentApperance = FindNextApperance__Private< MemoryHandlerType, PatternMemoryHandlerType >( memoryHandler, index, pattern, startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch );

		// Check if the next apperance of the pattern was not found
		if ( indexOfCurrentApperance == size )
		{
			// The next apperance of the pattern was not found

			// Break the loop
			break;
		}

		// The next apperance of the pattern was found

		// Add the current index
		apperancesIndices.InsertSingleElement( apperancesIndicesSize, index );

		// Increment the size of the apperance indices sequential data structure by 1
		apperancesIndicesSize += 1UL;
	}

	// Return a tuple that contains a boolean with the value false, to notify that the search was unsuccessful
	return ( apperancesIndices );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< Concepts::RawButPointerIsAllowed DataType COMMA typename MemoryManagerType >
	inline void SequentialDataStructure< DataType COMMA MemoryManagerType >::UnitTest()
	{
		// Create a test instance with vector
		SequentialDataStructure< LargestUnsignedInteger > testInstance_0;

		// Insert some data
		testInstance_0.InsertSingleElement( 0UL, 455UL );

		// Loop many times
		for ( LargestUnsignedInteger index = 0UL ; index < 24543UL ; ++index )
		{
			// Insert some data
			testInstance_0.InsertSingleElement( 0UL, 455UL );
		}

		// Loop on all the entries of the test instance
		for ( LargestUnsignedInteger index = 0UL ; index < testInstance_0.Size() ; ++index )
		{
			// Ensure the data in the current entry is correct
			Assert_Test( testInstance_0[ index ] == 455UL );
		}

		// Create a test instance with single linked list
		SequentialDataStructure< LargestUnsignedInteger > testInstance_1( MemoryHandlerName::SingleLinkedList, 465UL, 455UL );

		// Insert some data
		testInstance_1.InsertSingleElement( 0UL, 455UL );

		// Loop many times
		for ( LargestUnsignedInteger index = 0UL ; index < 24543UL ; ++index )
		{
			// Insert some data
			testInstance_1.InsertSingleElement( 0UL, 455UL );
		}

		// Loop on all the entries of the test instance
		for ( LargestUnsignedInteger index = 0UL ; index < testInstance_1.Size() ; ++index )
		{
			// Ensure the data in the current entry is correct
			Assert_Test( testInstance_1[ index ] == 455UL );
		}

		// Create a test instance with double linked list
		SequentialDataStructure< LargestUnsignedInteger > testInstance_2( MemoryHandlerName::DoubleLinkedList, 465UL, 455UL );

		// Insert some data
		testInstance_2.InsertSingleElement( 0UL, 455UL );

		// Loop many times
		for ( LargestUnsignedInteger index = 0UL ; index < 24543UL ; ++index )
		{
			// Insert some data
			testInstance_2.InsertSingleElement( 0UL, 455UL );
		}

		// Loop on all the entries of the test instance
		for ( LargestUnsignedInteger index = 0UL ; index < testInstance_2.Size() ; ++index )
		{
			// Ensure the data in the current entry is correct
			Assert_Test( testInstance_2[ index ] == 455UL );
		}

		// Compare between the instancs
		Assert_Test( testInstance_1 == testInstance_2 );

		// Copy construct an instance
		SequentialDataStructure< LargestUnsignedInteger > testInstance_3( testInstance_1 );

		// Ensure the copy constructed instance match the instance that was used
		Assert_Test( testInstance_1 == testInstance_3 );

		// Move construct an instance
		SequentialDataStructure< LargestUnsignedInteger > testInstance_4( TakeResourcesAndLeaveInstanceInDefaultState( testInstance_2 ) );

		// Make sure the move construct was successful, by comparing to an instance that had the same data as the instance that was used
		// for the move construction
		Assert_Test( testInstance_1 == testInstance_4 );

		// Ensure that the move operation left the other instance in default state, and the comparing default state instances works
		Assert_Test( SequentialDataStructure< LargestUnsignedInteger >() == testInstance_2 );

		// Switch between memory handlers
		testInstance_1.SwitchMemoryHandler( MemoryHandlerName::Vector );

		// Ensure that the switch was done correctly
		Assert_Test( testInstance_1 == testInstance_4 );
	}

)  //  End of debug tool



}  //  Namespace Universe