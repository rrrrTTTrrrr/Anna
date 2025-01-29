//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



template< Concepts::BuiltIn Type >
inline void ActAccordingToType::Reset( Type& instance )
{
	// The template type is built in type

	// Set the instance to 0
	instance = static_cast< Type >( 0 );
}


template< Concepts::NotBuiltIn Type >
inline void ActAccordingToType::Reset( Type& instance )
{
	// The template type is not a built in type

	// Use the method to reset the instance
	instance.Reset();
}


template< Concepts::BuiltIn Type >
inline Type ActAccordingToType::GetDefaultInstance()
{
	// The template type is built in type

	// Return the value 0
	return ( static_cast< Type >( 0 ) );
}


template< Concepts::NotBuiltIn Type >
inline Type ActAccordingToType::GetDefaultInstance()
{
	// The template type is not a built in type

	// Use the default constructor to create an instance and return a copy of it
	return ( Type() );
}


template< Concepts::ObjectWithIsSmallerOperator ObjectWithIsSmallerOperatorType >
inline Boolean ActAccordingToType::IsFirstInstanceEqualOrSmallerThenTheSecond( const ObjectWithIsSmallerOperatorType& first, const ObjectWithIsSmallerOperatorType& second )
{
	// The template type has implemnted the smaller comparison operator '<'

	// Check if the first instance is smaller then the second instance, using the operator '<', and return the result
	return ( first <= second );
}


template< Concepts::ObjectWithIsLargerOperatorAndIsSmallerOpeatorDoesNotExist ObjectWithIsLargerOperatorAndIsSmallerOpeatorDoesNotExistType >
inline Boolean ActAccordingToType::IsFirstInstanceEqualOrSmallerThenTheSecond( const ObjectWithIsLargerOperatorAndIsSmallerOpeatorDoesNotExistType& first, const ObjectWithIsLargerOperatorAndIsSmallerOpeatorDoesNotExistType& second )
{
	// The template type has implemnted the larger comparison operator '>'

	// Check if the first instance is smaller then the second instance, using the operator '>', and return the result
	return ( second >= first );
}


template< Concepts::ObjectWithIsSmallerOperator ObjectWithIsSmallerOperatorType >
inline Boolean ActAccordingToType::IsFirstInstanceSmallerThenTheSecond( const ObjectWithIsSmallerOperatorType& first, const ObjectWithIsSmallerOperatorType& second )
{
	// The template type has implemnted the smaller comparison operator '<'

	// Check if the first instance is smaller then the second instance, using the operator '<', and return the result
	return ( first < second );
}


template< Concepts::ObjectWithIsLargerOperatorAndIsSmallerOpeatorDoesNotExist ObjectWithIsLargerOperatorAndIsSmallerOpeatorDoesNotExistType >
inline Boolean ActAccordingToType::IsFirstInstanceSmallerThenTheSecond( const ObjectWithIsLargerOperatorAndIsSmallerOpeatorDoesNotExistType& first, const ObjectWithIsLargerOperatorAndIsSmallerOpeatorDoesNotExistType& second )
{
	// The template type has implemnted the larger comparison operator '>'

	// Check if the first instance is smaller then the second instance, using the operator '>', and return the result
	return ( second > first );
}



}  //  Namespace Universe