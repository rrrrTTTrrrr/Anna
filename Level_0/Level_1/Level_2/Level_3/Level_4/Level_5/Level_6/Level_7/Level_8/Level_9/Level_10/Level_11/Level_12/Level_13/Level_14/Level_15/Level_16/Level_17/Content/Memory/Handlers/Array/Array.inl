//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< Concepts::RawButPointerIsAllowed DataType, LargestUnsignedInteger ArraySize > requires( ArraySize > 0UL )
inline Array< DataType, ArraySize >::Array() :
    member_array{}
{}


template< Concepts::RawButPointerIsAllowed DataType, LargestUnsignedInteger ArraySize > requires( ArraySize > 0UL )
inline Array< DataType, ArraySize >::Array( const DataType& data ) :
    member_array{}
{
    // Set all the entries to the required instance
    Memory::Operations::Set< DataType >( member_array, ArraySize, data );
}


template< Concepts::RawButPointerIsAllowed DataType, LargestUnsignedInteger ArraySize > requires( ArraySize > 0UL )
inline Array< DataType, ArraySize >::Array( const std::initializer_list< DataType >& initializerList ) :
    member_array{}
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValuesAreEqual( ArraySize, initializerList.size() );

    // This object will store the current index to set in the array
    LargestUnsignedInteger index = 0UL;

    // Loop on all the entries in the initializer list
    for ( auto iterator = initializerList.begin() ; iterator != initializerList.end() ; ++iterator, ++index )
    {
        // Set the current entry
        member_array[ index ] = *iterator;
    }
}


template< Concepts::RawButPointerIsAllowed DataType, LargestUnsignedInteger ArraySize > requires( ArraySize > 0UL )
template< template< typename, typename... > class OtherMemoryHandlerType >
inline Array< DataType, ArraySize >::Array( const OtherMemoryHandlerType< DataType >& other ) :
    member_array{}
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValuesAreEqual( ArraySize, other.Size() );

    // Loop on all the entries of the other stack array
    for ( LargestUnsignedInteger index = 0UL ; index < ArraySize ; ++index )
    {
        // Copy the current entry from the other stack array to this instance
        member_array[ index ] = other[ index ];
    }
}


template< Concepts::RawButPointerIsAllowed DataType, LargestUnsignedInteger ArraySize > requires( ArraySize > 0UL )
inline Array< DataType, ArraySize >::Array( const SelfType& other ) :
   member_array{}
{
	// Copy the content of the other array to this array
	Memory::Operations::Copy< DataType >( other.member_array, member_array, ArraySize );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< Concepts::RawButPointerIsAllowed DataType, LargestUnsignedInteger ArraySize > requires( ArraySize > 0UL )
inline Boolean Array< DataType, ArraySize >::operator==( const SelfType& other ) const
{            
    // Compare between the arrays, and return the result
    return ( Memory::Operations::Compare< DataType >( member_array, other.member_array, ArraySize ) );
}


template< Concepts::RawButPointerIsAllowed DataType, LargestUnsignedInteger ArraySize > requires( ArraySize > 0UL )
inline Boolean Array< DataType, ArraySize >::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}


template< Concepts::RawButPointerIsAllowed DataType, LargestUnsignedInteger ArraySize > requires( ArraySize > 0UL )
inline DataType& Array< DataType, ArraySize >::operator[]( const LargestUnsignedInteger index )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsBelowCertainLimit( index, ArraySize );
    
    // Return a reference to the required entry
    return ( member_array[ index ] );
}


template< Concepts::RawButPointerIsAllowed DataType, LargestUnsignedInteger ArraySize > requires( ArraySize > 0UL )
inline const DataType& Array< DataType, ArraySize >::operator[]( const LargestUnsignedInteger index ) const
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsBelowCertainLimit( index, ArraySize );

    // Return a reference to the required entry
    return ( member_array[ index ] );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< Concepts::RawButPointerIsAllowed DataType COMMA LargestUnsignedInteger ArraySize > requires( ArraySize > 0UL )
	void Array< DataType COMMA ArraySize >::UnitTest()
	{
        // Create an instance of the object using the default constructor
        Array< SignedInteger32bits COMMA 89 > testArray_1;

        // Check that it is really in default state
        Assert_Test( testArray_1[0] == 0 );

        // Create an instance of the object using the parameterized constructor
        Array< SignedInteger32bits COMMA 873 > testArray_2( 67 );

        // Check the size of the array
        Assert_Test( testArray_2.Size() == 873 );

        // Create an instance of the object using the parameterized constructor
        Array< SignedInteger32bits COMMA 49 > testArray_3( 77 );

        // Check the size of the array
        Assert_Test( testArray_3.Size() == 49 );

        // Check the size of the array
        Assert_Test( testArray_3[45] == 77 );

        // Create an instance of the object using the parameterized constructor
        Array< SignedInteger32bits COMMA 49 > testArray_4( 799 );

        // Check that the 2 instnaces are different
        Assert_Test( testArray_3 != testArray_4 );

        // Set all the entries
        testArray_4 = TakeResourcesAndLeaveInstanceInDefaultState( Array< SignedInteger32bits COMMA 49 >( 77 ) );

        // Check that the 2 instnaces are the same
        Assert_Test( testArray_3 == testArray_4 );

        // A write operation is performed, to check that the object uses the copy on write method before
        testArray_4[5] += 1;

        // Check that the 2 instnaces point to the same address
        Assert_Test( testArray_3 != testArray_4 );

        // Check if the addition works
        Assert_Test( 80 == ( testArray_4[5] + 2 ) );

        // Ensure that the default constructor can deal with this situation
        Memory::Array< Tuple< LargestUnsignedInteger COMMA LargestUnsignedInteger COMMA LargestUnsignedInteger > COMMA 3UL > testTemplateParamerts;
	}

)  //  End of debug tool



}  //  Namespace Memory


}  //  Namespace Universe