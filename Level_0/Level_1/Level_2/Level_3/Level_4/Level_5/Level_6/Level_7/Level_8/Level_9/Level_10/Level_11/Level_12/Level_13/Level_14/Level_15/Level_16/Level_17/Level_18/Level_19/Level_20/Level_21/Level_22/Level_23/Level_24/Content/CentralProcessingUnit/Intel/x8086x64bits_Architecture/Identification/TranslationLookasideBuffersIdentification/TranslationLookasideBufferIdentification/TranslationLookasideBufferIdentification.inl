//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline TranslationLookasideBufferIdentification::TranslationLookasideBufferIdentification() :
	member_translationLookasideBufferByteDescriptor( 0UL ),
    member_sizeInBytes( 0UL ),
    member_trueForShared_falseForExclusiveUse( false ),
    member_trueForInstructions_falseForData( false ),
    member_numberOfPageSizesSupported( 0UL ),
    member_isAssociativityKnown( false ),
    member_trueForFullAssociative_falseForSetAssociative( false ),
    member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative(),
    member_pageSizeCanWorkToghterWithThisOtherPageSizes()
{}


inline TranslationLookasideBufferIdentification::TranslationLookasideBufferIdentification( const UnsignedInteger8bits translationLookasideBufferByteDescriptor ) :
	member_translationLookasideBufferByteDescriptor( translationLookasideBufferByteDescriptor ),
    member_sizeInBytes( 0UL ),
    member_trueForShared_falseForExclusiveUse( false ),
    member_trueForInstructions_falseForData( false ),
    member_numberOfPageSizesSupported( 0UL ),
    member_isAssociativityKnown( false ),
    member_trueForFullAssociative_falseForSetAssociative( false ),
    member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative(),
    member_pageSizeCanWorkToghterWithThisOtherPageSizes()
{
	// Initialize the instance using the given byte descriptor
	InitializeInstanceWithTranslationLookasideBufferAttributesRepresentedByByteDescriptor__Private( translationLookasideBufferByteDescriptor );
}


inline TranslationLookasideBufferIdentification::TranslationLookasideBufferIdentification( const SelfType& other ) :
	member_translationLookasideBufferByteDescriptor( other.member_translationLookasideBufferByteDescriptor ),
    member_sizeInBytes( other.member_sizeInBytes ),
    member_trueForShared_falseForExclusiveUse( other.member_trueForShared_falseForExclusiveUse ),
    member_trueForInstructions_falseForData( other.member_trueForInstructions_falseForData ),
    member_numberOfPageSizesSupported( other.member_numberOfPageSizesSupported ),
    member_isAssociativityKnown( other.member_isAssociativityKnown ),
    member_trueForFullAssociative_falseForSetAssociative( other.member_trueForFullAssociative_falseForSetAssociative ),
    member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative( other.member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative ),
    member_pageSizeCanWorkToghterWithThisOtherPageSizes( other.member_pageSizeCanWorkToghterWithThisOtherPageSizes )
{}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



inline Boolean TranslationLookasideBufferIdentification::operator==( const SelfType& other ) const
{
	// Compare the byte descriptors of both instance, and return the result
	return ( member_translationLookasideBufferByteDescriptor == other.member_translationLookasideBufferByteDescriptor );
}


inline Boolean TranslationLookasideBufferIdentification::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}



}  //  Namespace CentralProcessingUnit


}  //  Namespace Universe