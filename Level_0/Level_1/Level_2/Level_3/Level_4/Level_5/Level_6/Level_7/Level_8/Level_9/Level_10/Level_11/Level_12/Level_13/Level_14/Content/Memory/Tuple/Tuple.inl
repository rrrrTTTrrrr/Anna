//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< typename ExposedType, typename... RestOfTheTypes >
inline Tuple< ExposedType, RestOfTheTypes... >::Tuple( const ExposedType& data, const RestOfTheTypes&... restOfData ) :
	Tuple< RestOfTheTypes... >( restOfData... ),
	member_data( data )
{}


template< typename ExposedType, typename... RestOfTheTypes >
inline Tuple< ExposedType, RestOfTheTypes... >::Tuple( ExposedType&& data, RestOfTheTypes&&... restOfData ) :
    Tuple< RestOfTheTypes... >( ForwardUniversalReference< RestOfTheTypes >( restOfData )... ),
    member_data( TakeResourcesAndLeaveInstanceInDefaultState( data ) )
{}


template< typename ExposedType, typename... RestOfTheTypes >
template< typename UniverslReferenceExposedType >
inline Tuple< ExposedType, RestOfTheTypes... >::Tuple( const Tuple< RestOfTheTypes... >& other, UniverslReferenceExposedType data ) :
    Tuple< RestOfTheTypes... >( other ),
    member_data( ForwardUniversalReference< UniverslReferenceExposedType >( data ) )
{}


template< typename ExposedType, typename... RestOfTheTypes >
template< typename UniverslReferenceExposedType >
inline Tuple< ExposedType, RestOfTheTypes... >::Tuple( Tuple< RestOfTheTypes... >&& other, UniverslReferenceExposedType data ) :
    Tuple< RestOfTheTypes... >( TakeResourcesAndLeaveInstanceInDefaultState( other ) ),
    member_data( ForwardUniversalReference< UniverslReferenceExposedType >( data ) )
{}


template< typename ExposedType, typename... RestOfTheTypes >
template< typename LastDataMemberOfOtherTupleType >
inline Tuple< ExposedType, RestOfTheTypes... >::Tuple( const Tuple< LastDataMemberOfOtherTupleType, ExposedType, RestOfTheTypes... >& other ) :
    SelfType( *reinterpret_cast< const SelfType* >( &other ) )
{}


template< typename ExposedType, typename... RestOfTheTypes >
template< typename LastDataMemberOfOtherTupleType >
inline Tuple< ExposedType, RestOfTheTypes... >::Tuple( Tuple< LastDataMemberOfOtherTupleType, ExposedType, RestOfTheTypes... >&& other ) :
    SelfType( TakeResourcesAndLeaveInstanceInDefaultState( *reinterpret_cast< SelfType* >( &other ) ) )
{}


template< typename ExposedType, typename... RestOfTheTypes >
inline Tuple< ExposedType, RestOfTheTypes... >::Tuple( const SelfType& other ) :
	Tuple< RestOfTheTypes... >( other ),
	member_data( other.member_data )
{}


template< typename ExposedType, typename... RestOfTheTypes >
inline LargestUnsignedInteger Tuple< ExposedType, RestOfTheTypes... >::NumberOfDataMembers() const
{
	// Just return 0
	return ( member_numberOfDataMembers );
}


template< typename ExposedType, typename... RestOfTheTypes >
template< LargestUnsignedInteger ArgumentIndex >
inline typename ProvideTypeOnlyIfAssertionIsTrue< ArgumentIndex != 0UL, typename TypesHolder< ArgumentIndex, ExposedType, RestOfTheTypes... >::Type& >::Type Tuple< ExposedType, RestOfTheTypes... >::Entry() 
{            
    // Create a reference to the base of the current tuple
    Tuple< RestOfTheTypes... >& baseTuple = *this;

    // Call the next method in the recursion with the number of arguments decreased by 1
    return ( baseTuple.template Entry< ArgumentIndex - 1UL >() );
}


template< typename ExposedType, typename... RestOfTheTypes >
template< LargestUnsignedInteger ArgumentIndex >
inline typename ProvideTypeOnlyIfAssertionIsTrue< ArgumentIndex == 0UL, typename TypesHolder< ArgumentIndex, ExposedType, RestOfTheTypes... >::Type& >::Type Tuple< ExposedType, RestOfTheTypes... >::Entry() 
{
    // Return a reference to the data member
    return ( member_data );
}


template< typename ExposedType, typename... RestOfTheTypes >
template< LargestUnsignedInteger ArgumentIndex >
inline typename ProvideTypeOnlyIfAssertionIsTrue< ArgumentIndex != 0UL, typename ConstantTypesHolder< ArgumentIndex, ExposedType, RestOfTheTypes... >::Type& >::Type Tuple< ExposedType, RestOfTheTypes... >::Entry() const 
{               
    // Create a reference to the base of the current tuple
    const Tuple< RestOfTheTypes... >& baseTuple = *this;

    // Call the next method in the recursion with the number of arguments decreased by 1
    return ( baseTuple.template Entry< ArgumentIndex - 1UL >() );
}


template< typename ExposedType, typename... RestOfTheTypes >
template< LargestUnsignedInteger ArgumentIndex >
inline typename ProvideTypeOnlyIfAssertionIsTrue< ArgumentIndex == 0UL, typename ConstantTypesHolder< ArgumentIndex, ExposedType, RestOfTheTypes... >::Type& >::Type Tuple< ExposedType, RestOfTheTypes... >::Entry() const
{
    // Return a reference to the data member
    return ( member_data );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< typename ExposedType, typename... RestOfTheTypes >
inline Boolean Tuple< ExposedType, RestOfTheTypes... >::operator==( const SelfType& other ) const
{
    // Check if the instances match, and return the result
    return ( ( member_data == other.member_data ) && ( Tuple< RestOfTheTypes... >::operator==( other ) ) );
}


template< typename ExposedType, typename... RestOfTheTypes >
inline Boolean Tuple< ExposedType, RestOfTheTypes... >::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************************************    BASE CASE   ***************************************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //




//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< typename ExposedType >
template< typename UniverslReferenceExposedType >
inline Tuple< ExposedType >::Tuple( UniverslReferenceExposedType data ) :
   member_data( ForwardUniversalReference< UniverslReferenceExposedType >( data ) )
{}


template< typename ExposedType >
template< typename LastDataMemberOfOtherTupleType >
inline Tuple< ExposedType >::Tuple( const Tuple< LastDataMemberOfOtherTupleType, ExposedType >& other ) :
    SelfType( *reinterpret_cast< const SelfType* >( &other ) )
{}


template< typename ExposedType >
template< typename LastDataMemberOfOtherTupleType >
inline Tuple< ExposedType >::Tuple( Tuple< LastDataMemberOfOtherTupleType, ExposedType >&& other ) :
    SelfType( TakeResourcesAndLeaveInstanceInDefaultState( *reinterpret_cast< SelfType* >( &other ) ) )
{}


template< typename ExposedType >
inline Tuple< ExposedType >::Tuple( const SelfType& other ) :
   member_data( other.member_data )
{}


template< typename ExposedType >
inline LargestUnsignedInteger Tuple< ExposedType >::NumberOfDataMembers() const
{
	// Just return 1
	return ( member_numberOfDataMembers );
}


template< typename ExposedType >
template< LargestUnsignedInteger ArgumentIndex >
inline ExposedType& Tuple< ExposedType >::Entry() 
{            
	// This is a compile time assertion. The compiler checks the condition during compile time, and if the condition does not apply an error 
    // message will be displayed
	CompileTimeAssert( ( ArgumentIndex == 0UL ), "The argument index should be zero" );

    // Call the next method in the recursion with the number of arguments decreased by 1
    return ( member_data );
}


template< typename ExposedType >
template< LargestUnsignedInteger ArgumentIndex >
inline const ExposedType& Tuple< ExposedType >::Entry() const
{
    // This is a compile time assertion. The compiler checks the condition during compile time, and if the condition does not apply an error 
    // message will be displayed
	CompileTimeAssert( ( ArgumentIndex == 0UL ), "The argument index should be zero" );
    
    // Call the next method in the recursion with the number of arguments decreased by 1
    return ( member_data );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< typename ExposedType >
inline Boolean Tuple< ExposedType >::operator==( const SelfType& other ) const
{
    // Check if the instances match, and return the result
    return ( member_data == other.member_data );
}


template< typename ExposedType >
inline Boolean Tuple< ExposedType >::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(


    CreateTupleWithTwoNamedDataMembers( TestNamedTuple, UnsignedInteger32bits, First, UnsignedInteger32bits, Second )


	template< typename ExposedType COMMA typename... RestOfTheTypes >
	void Tuple< ExposedType COMMA RestOfTheTypes... >::UnitTest()
	{
        // Create a simple tuple with the default constructor
        Tuple< UnsignedInteger32bits COMMA double COMMA char* > testTuple_1;
        
        // Initiate the tuple
        testTuple_1 = Tuple< UnsignedInteger32bits COMMA double COMMA char* >( 132, 99.8945, 0 );

        // Check that the size of the tuple is really 3
        Assert_Test( testTuple_1.NumberOfDataMembers() == 3 );

        // Create a simple tuple with the parameterized constructor
        Tuple< UnsignedInteger32bits COMMA UnsignedInteger32bits > testTuple_2( 8, 10 );

        // Check that the size of the tuple is really 2
        Assert_Test( testTuple_2.NumberOfDataMembers() == 2 );

        // Change the tuple
        testTuple_2 = Tuple< UnsignedInteger32bits COMMA UnsignedInteger32bits >( 132, 99 );

        // Create a simple tuple with the parameterized constructor
        Tuple< UnsignedInteger32bits COMMA UnsignedInteger32bits > testTuple_3( testTuple_2 );

        // Check the comparison operator
        Assert_Test( testTuple_2 == testTuple_3 );

        // Check the non comparison operator
        Assert_Test( testTuple_2 == testTuple_3 );

        // // Create a simple tuple with the default constructor
        Tuple< UnsignedInteger32bits COMMA UnsignedInteger32bits > testTuple_4( TakeResourcesAndLeaveInstanceInDefaultState( testTuple_2 ) );

        // Check that the size of the tuple is really 2
        Assert_Test( testTuple_4.NumberOfDataMembers() == 2 );

        // Test the Entry method
        Assert_Test( testTuple_4.Entry< 0 >() == 132 ); 

        // Test the Entry method
        testTuple_4.Entry< 0 >() = 45;

        // Test the Entry method
        Assert_Test( testTuple_4.Entry< 0 >() == 45 );             

        // Create a simple constant tuple with the parameterized constructor
        const Tuple< UnsignedInteger32bits COMMA UnsignedInteger32bits > testTuple_5( 78, 999999 );

    	// Test the Entry method
        Assert_Test( testTuple_5.Entry< 0 >() == 78 );

        // Create a simple constant tuple with the parameterized constructor
        Tuple< UnsignedInteger32bits COMMA UnsignedInteger32bits > testTuple_6( 78, 999999 );

        // Set to default state
        testTuple_6.Reset();

        // Initiate the instance
        testTuple_6 = Tuple< UnsignedInteger32bits COMMA UnsignedInteger32bits >( 4566, 8792 );

        // Set a value
        testTuple_6.Entry< 1 >() = 77;

        // Reset
        testTuple_6.Reset();

        // Initiate the instance
        testTuple_6 = Tuple< UnsignedInteger32bits COMMA UnsignedInteger32bits >( 4566, 8792 );

        // Set a value
        testTuple_6.Entry< 1 >() = 77;

        // Create a simple constant tuple with the parameterized constructor
        Tuple< UnsignedInteger32bits COMMA UnsignedInteger32bits COMMA UnsignedInteger32bits > testTuple_7( 99, 99, 69 );

        // Create a simple constant tuple with the parameterized constructor
        Tuple< UnsignedInteger32bits COMMA UnsignedInteger32bits COMMA UnsignedInteger32bits > testTuple_8( testTuple_7 );

        // Check the comparison operator
        Assert_Test( testTuple_7 == testTuple_8 );

        // Create a simple constant tuple with the parameterized constructor
        Tuple< UnsignedInteger32bits COMMA UnsignedInteger32bits COMMA UnsignedInteger32bits > testTuple_9;

        // Create a simple constant tuple with the parameterized constructor
        Tuple< UnsignedInteger32bits COMMA UnsignedInteger32bits COMMA UnsignedInteger32bits > testTuple_10;

        // Check the comparison operator
        Assert_Test( testTuple_9 == testTuple_10 );

        // Create avariable to set the address of inside the tuple
        UnsignedInteger32bits testVariable_1 = 0;

        // Create a tuple with pointer
        Tuple< UnsignedInteger32bits* > testTuple_11;

        // Initiate the instance
        testTuple_11 = Tuple< UnsignedInteger32bits* >( &testVariable_1 );

        // Set the variable
        *testTuple_11.Entry< 0 >() = 889;

        // Check the comparison operator
        Assert_Test( testVariable_1 == 889 );

        // Set the pointer
        testTuple_11.Entry< 0 >() = &testVariable_1;

        // Set the variable
        *testTuple_11.Entry< 0 >() = 88999;

        // Check the comparison operator
        Assert_Test( testVariable_1 == 88999 );

        // Check the comparison operator
        Assert_Test( testVariable_1 == 88999 );

        // Create a simple tuple
        Tuple< UnsignedInteger32bits COMMA double COMMA LargestUnsignedInteger > testTuple_20( 132, 99.8945, 0 );

        // Create a larger tuple with another test tuple instance to fill the first entries according to its size
        Tuple< LargestUnsignedInteger COMMA UnsignedInteger32bits COMMA double COMMA LargestUnsignedInteger > testTuple_21( testTuple_20 );

        // Ensure that both instance match at the required entries
        Assert_Test( testTuple_20.template Entry< 0UL >() == testTuple_21.template Entry< 1UL >() );
        Assert_Test( testTuple_20.template Entry< 1UL >() == testTuple_21.template Entry< 2UL >() );
        Assert_Test( testTuple_20.template Entry< 2UL >() == testTuple_21.template Entry< 3UL >() );

        // Create a larger tuple with another test tuple instance to fill the first entries according to its size
        Tuple< LargestUnsignedInteger COMMA UnsignedInteger32bits COMMA double COMMA LargestUnsignedInteger > testTuple_22( testTuple_20, 89UL );

        // Ensure that both instance match at the required entries
        Assert_Test( testTuple_22.template Entry< 0UL >() == 89UL );
        Assert_Test( testTuple_20.template Entry< 0UL >() == testTuple_22.template Entry< 1UL >() );
        Assert_Test( testTuple_20.template Entry< 1UL >() == testTuple_22.template Entry< 2UL >() );
        Assert_Test( testTuple_20.template Entry< 2UL >() == testTuple_22.template Entry< 3UL >() );

        // Create a larger tuple with another test tuple instance to fill the first entries according to its size
        Tuple< double COMMA LargestUnsignedInteger > testTuple_23( testTuple_20 );

        // Ensure that both instance match at the required entries
        Assert_Test( testTuple_20.template Entry< 1UL >() == testTuple_23.template Entry< 0UL >() );
        Assert_Test( testTuple_20.template Entry< 2UL >() == testTuple_23.template Entry< 1UL >() );

        TestNamedTuple testNamedTuple_0;

        testNamedTuple_0.First() = 89;
        testNamedTuple_0.Second() = 89;
	}

)  //  End of debug tool



}   //  Namespace Memory


}  //  Namespace Universe
