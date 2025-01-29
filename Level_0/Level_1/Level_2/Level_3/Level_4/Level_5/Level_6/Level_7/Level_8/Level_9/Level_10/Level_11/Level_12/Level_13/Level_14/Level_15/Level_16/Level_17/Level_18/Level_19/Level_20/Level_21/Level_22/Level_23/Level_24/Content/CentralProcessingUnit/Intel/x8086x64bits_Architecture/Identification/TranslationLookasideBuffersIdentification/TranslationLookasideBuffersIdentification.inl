//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline TranslationLookasideBuffersIdentification::TranslationLookasideBuffersIdentification() :
	member_translationLookasideBuffersIdentification()
{}


inline TranslationLookasideBuffersIdentification::TranslationLookasideBuffersIdentification( const Memory::Array< UnsignedInteger32bits, 4UL >& EAX_EBX_ECX_EDX_registersContentStoredAfterCpuidInstructionExecutedWithEAXsetToTwo ) :
	member_translationLookasideBuffersIdentification()
{
    // Extract the information from the byte descriptors, and initialize the array entries with it
    InitializeTranslationLookasideBuffersIdentificationArray__Private( EAX_EBX_ECX_EDX_registersContentStoredAfterCpuidInstructionExecutedWithEAXsetToTwo );
}


inline TranslationLookasideBuffersIdentification::TranslationLookasideBuffersIdentification( const SelfType& other ) :
	member_translationLookasideBuffersIdentification( other.member_translationLookasideBuffersIdentification )
{}


inline LargestUnsignedInteger TranslationLookasideBuffersIdentification::NumberOfTranslationLookasideBuffers() const
{
	// Return the number of translation lookaside buffers, which is the size of the array
	return ( member_translationLookasideBuffersIdentification.Size() );
}


inline const TranslationLookasideBufferIdentification& TranslationLookasideBuffersIdentification::DataTranslationLookasideBufferIdentification() const
{
	// Loop on the existing translation lookaside buffer identification instances
	for ( LargestUnsignedInteger index = 0UL ; index < member_translationLookasideBuffersIdentification.Size() ; ++index )
	{
		// Check if the current translation lookaside buffer identification instance is for data
		if ( member_translationLookasideBuffersIdentification[ index ].IsForInstructions() == false && member_translationLookasideBuffersIdentification[ index ].IsSharedByMultipleCentralProcessingUnits() == false )
		{
			// Return a constant reference to translation lookaside buffer identification instance for data
			return ( member_translationLookasideBuffersIdentification[ index ] );
		}
	}

	// A translation lookaside buffer identification instance for data does not exist, throw an exception
	ThrowException( "A translation lookaside buffer identification instance for data does not exist" );
}


inline const TranslationLookasideBufferIdentification& TranslationLookasideBuffersIdentification::InstructionsTranslationLookasideBufferIdentification() const
{
	// Loop on the existing translation lookaside buffer identification instances
	for ( LargestUnsignedInteger index = 0UL ; index < member_translationLookasideBuffersIdentification.Size() ; ++index )
	{
		// Check if the current translation lookaside buffer identification instance is for instructions
		if ( member_translationLookasideBuffersIdentification[ index ].IsForInstructions() == true && member_translationLookasideBuffersIdentification[ index ].IsSharedByMultipleCentralProcessingUnits() == false )
		{
			// Return a constant reference to translation lookaside buffer identification instance for instructions
			return ( member_translationLookasideBuffersIdentification[ index ] );
		}
	}

	// A translation lookaside buffer identification instance for instructions does not exist, throw an exception
	ThrowException( "A translation lookaside buffer identification instance for instructions does not exist" );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



inline Boolean TranslationLookasideBuffersIdentification::operator==( const SelfType& other ) const
{
	// Compare the translation lookaside buffer information in both instance, and return the result
	return ( member_translationLookasideBuffersIdentification == other.member_translationLookasideBuffersIdentification );
}


inline Boolean TranslationLookasideBuffersIdentification::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}



}  //  Namespace CentralProcessingUnit


}  //  Namespace Universe