//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< typename... Types >
inline TemplatePack< Types... >::TemplatePack()
{}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< typename... Types >
inline LargestUnsignedInteger TemplatePack< Types... >::operator[]( const LargestUnsignedInteger index ) const
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertValueIsBelowCertainLimit( index, sizeof...( Types ) );

	// Return the size of the required template argument type
	return ( member_typesSize[ index ] );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< typename... Types >
	inline void TemplatePack< Types... >::UnitTest()
	{
		for ( LargestUnsignedInteger index = 0UL ; index < sizeof...( Types ) ; ++index )
		{
			std::cout << member_typesSize[ index ] << std::endl;
		}
	}

)  //  End of debug tool



}  //  Namespace Universe