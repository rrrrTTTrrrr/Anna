//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< Concepts::Integer IntegerType >
inline TemplateObjectWithAllOperatorsOverloaded< IntegerType >::TemplateObjectWithAllOperatorsOverloaded() :
	member_integer( 0 )
{}


template< Concepts::Integer IntegerType >
inline TemplateObjectWithAllOperatorsOverloaded< IntegerType >::TemplateObjectWithAllOperatorsOverloaded( IntegerType startingValue ) :
	member_integer( startingValue )
{}


template< Concepts::Integer IntegerType >
inline TemplateObjectWithAllOperatorsOverloaded< IntegerType >::TemplateObjectWithAllOperatorsOverloaded( const SelfType& other ) :
	member_integer( other.member_integer )
{}


template< Concepts::Integer IntegerType >
inline TemplateObjectWithAllOperatorsOverloaded< IntegerType >& TemplateObjectWithAllOperatorsOverloaded< IntegerType >::operator=( const SelfType& other )
{
    // Create a copy of the other instance
    SelfType temporary( other );

    // Swap between this instance and the temporary one, this will leave the temporary instance with the old data, and he will delete it
    Swap( temporary );

    // Return a reference to this object
    return ( *this );
}


template< Concepts::Integer IntegerType >
inline TemplateObjectWithAllOperatorsOverloaded< IntegerType >::TemplateObjectWithAllOperatorsOverloaded( TemplateObjectWithAllOperatorsOverloaded&& other ) :
	SelfType()
{
    // Swap between this instance and the other one
    Swap( other );
}


template< Concepts::Integer IntegerType >
inline TemplateObjectWithAllOperatorsOverloaded< IntegerType >& TemplateObjectWithAllOperatorsOverloaded< IntegerType >::operator=( SelfType&& other )
{
    // Create a default constructed instance
    SelfType defaultConstructedInstance;

    // Swap between the default constructed instance, which is in default state, and the other instance
    defaultConstructedInstance.Swap( other );

    // Swap between this instance and the default constructed instance one
    Swap( defaultConstructedInstance );

    // Return a reference to this object
    return ( *this );
}


template< Concepts::Integer IntegerType >
inline void TemplateObjectWithAllOperatorsOverloaded< IntegerType >::Swap( SelfType& other )
{
	// Swap the integer
	IntegerType otherIntegerCopy = other.member_integer;
	other.member_integer = member_integer;
	member_integer = otherIntegerCopy;
}



}  //  Namespace Test


}  //  Namespace Universe