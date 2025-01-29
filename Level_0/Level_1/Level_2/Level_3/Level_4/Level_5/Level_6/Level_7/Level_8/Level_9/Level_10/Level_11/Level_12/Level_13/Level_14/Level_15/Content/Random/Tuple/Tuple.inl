//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



template< Concepts::RawButPointerIsAllowedAndNumeric ExposedType, Concepts::RawButPointerIsAllowedAndNumeric... RestOfTemplateArgumentTypes >
inline Memory::Tuple< ExposedType, RestOfTemplateArgumentTypes... > Tuple< ExposedType, RestOfTemplateArgumentTypes... >::Next()
{
	// Generate random values and use them to construct the tuple instance
	const Memory::Tuple< ExposedType, RestOfTemplateArgumentTypes... > randomGeneratedTuple( RunTimeGenerator::Numeric::Next< ExposedType >(), RunTimeGenerator::Numeric::Next< RestOfTemplateArgumentTypes >()... );

	// Return the random generated tuple
	return ( randomGeneratedTuple );
}


template< Concepts::RawButPointerIsAllowedAndNumeric ExposedType, Concepts::RawButPointerIsAllowedAndNumeric... RestOfTemplateArgumentTypes >
template< typename ExposedRangeType, typename... RestOfTemplateArgumentRangeTypes >
inline Memory::Tuple< ExposedType, RestOfTemplateArgumentTypes... > Tuple< ExposedType, RestOfTemplateArgumentTypes... >::Next( const ExposedRangeType& exposedRange, const RestOfTemplateArgumentRangeTypes&... restOfTemplateArgumentRanges )
{
	// Create a tuple instance using the default constructor
	Memory::Tuple< ExposedType, RestOfTemplateArgumentTypes... > randomGeneratedTuple;

	// Generate random values and store them in the tuple instance
	GenerateRandomValueAndStoreItInTheExposedMemberRecursive__Private< ExposedRangeType, RestOfTemplateArgumentRangeTypes... >( randomGeneratedTuple, exposedRange, restOfTemplateArgumentRanges... );

	// Return the random generated tuple
	return ( randomGeneratedTuple );
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



template< Concepts::RawButPointerIsAllowedAndNumeric ExposedType, Concepts::RawButPointerIsAllowedAndNumeric... RestOfTemplateArgumentTypes >
template< typename ExposedRangeType, typename... RestOfTemplateArgumentRangeTypes >
inline void Tuple< ExposedType, RestOfTemplateArgumentTypes... >::GenerateRandomValueAndStoreItInTheExposedMemberRecursive__Private( Memory::Tuple< ExposedType, RestOfTemplateArgumentTypes... >& tuple, const ExposedRangeType& exposedRange, const RestOfTemplateArgumentRangeTypes&... restOfTemplateArgumentRanges )
{
	// Create a random value and store in the exposed member
	tuple.template Entry< 0UL >() = RunTimeGenerator::Numeric::Next< ExposedType >( exposedRange );

    // Create a reference to the base of the current tuple
	Tuple< RestOfTemplateArgumentTypes... >& baseTuple = tuple;

	// Perform a recursive call on the next member of the tuple instance
	GenerateRandomValueAndStoreItInTheExposedMemberRecursive__Private< RestOfTemplateArgumentRangeTypes... >( tuple, restOfTemplateArgumentRanges... );
}


template< Concepts::RawButPointerIsAllowedAndNumeric ExposedType, Concepts::RawButPointerIsAllowedAndNumeric... RestOfTemplateArgumentTypes >
template< typename ExposedRangeType >
inline void Tuple< ExposedType, RestOfTemplateArgumentTypes... >::GenerateRandomValueAndStoreItInTheExposedMemberRecursive__Private( Memory::Tuple< ExposedType >& tuple, const ExposedRangeType& exposedRange )
{
	// Create a random value and store in the exposed member
	tuple.template Entry< 0UL >() = RunTimeGenerator::Numeric::Next< ExposedType >( exposedRange );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< Concepts::RawButPointerIsAllowedAndNumeric ExposedType COMMA Concepts::RawButPointerIsAllowedAndNumeric... RestOfTemplateArgumentTypes >
	void Tuple< ExposedType COMMA RestOfTemplateArgumentTypes... >::UnitTest()
	{}

)  //  End of debug tool



}  //  Namespace Generator


}  //  Namespace Random


}  //  Namespace Universe