namespace Universe 
{


namespace CentralProcessingUnit
{



//	********************************************************************   PRIVATE METHODS IMPLEMENTATION   *********************************************************************



void TranslationLookasideBufferIdentification::InitializeInstanceWithTranslationLookasideBufferAttributesRepresentedByByteDescriptor__Private( const UnsignedInteger8bits translationLookasideBufferByteDescriptor )
{

    // Switch case to choose the specific translation lookaside buffer information
    switch ( translationLookasideBufferByteDescriptor )
    {

        case 0x01 :
        {
        	// Description :
        	//
        	//  Instruction TLB: 4 KByte pages, 4-way set associative, 32 entries

            // This value represents a translation lookaside buffer of size - 128 KiloByte
            member_sizeInBytes = KiloByte( 4 * 32 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents an instruction translation lookaside buffer
            member_trueForInstructions_falseForData = true;

            // This value represents a translation lookaside buffer that only support one page size
            member_numberOfPageSizesSupported = 1U;

            // The associativity is known
            member_isAssociativityKnown = true;

            // This is set associativity, the value was already set to false

            // This value represents 4 KiloByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = KiloByte( 4UL );

            // This value represents a 4 way set associative
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 1UL >() = 4UL;

            // This value represents 32 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 32UL;

            // There is nothing else to do
            break;
        }

        case 0x02 :
        {
        	// Description :
        	//
        	//  Instruction TLB: 4 MByte pages, fully associative, 2 entries

            // This value represents a translation lookaside buffer of size - 8 MegaByte
            member_sizeInBytes = MegaByte( 4 * 2 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents an instruction translation lookaside buffer
            member_trueForInstructions_falseForData = true;

            // This value represents a translation lookaside buffer that only support one page size
            member_numberOfPageSizesSupported = 1U;

            // The associativity is known
            member_isAssociativityKnown = true;

            // This is full associative
            member_trueForFullAssociative_falseForSetAssociative = true;

            // This value represents 4 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = MegaByte( 4UL );

            // This value represents 2 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 2UL;

            // There is nothing else to do
            break;
        }

        case 0x03 :
        {
        	// Description :
        	//
        	//  Data TLB: 4 KByte pages, 4-way set associative, 64 entries

            // This value represents a translation lookaside buffer of size - 256 KiloByte
            member_sizeInBytes = KiloByte( 4 * 64 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents a data translation lookaside buffer, the value was already set to false

            // This value represents a translation lookaside buffer that only support one page size
            member_numberOfPageSizesSupported = 1U;

            // The associativity is known
            member_isAssociativityKnown = true;

            // This is set associativity, the value was already set to false

            // This value represents 4 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = MegaByte( 4UL );

            // This value represents a 4 way set associative
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 1UL >() = 4UL;

            // This value represents 64 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 64UL;

            // There is nothing else to do
            break;
        }

        case 0x04 :
        {
        	// Description :
        	//
        	//  Data TLB: 4 MByte pages, 4-way set associative, 8 entries

            // This value represents a translation lookaside buffer of size - 32 MegaByte
            member_sizeInBytes = MegaByte( 4 * 8 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents a data translation lookaside buffer, the value was already set to false

            // This value represents a translation lookaside buffer that only support one page size
            member_numberOfPageSizesSupported = 1U;

            // The associativity is known
            member_isAssociativityKnown = true;

            // This is set associativity, the value was already set to false

            // This value represents 4 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = MegaByte( 4UL );

            // This value represents a 4 way set associative
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 1UL >() = 4UL;

            // This value represents 8 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 8UL;

            // There is nothing else to do
            break;
        }

        case 0x05 :
        {
        	// Description :
        	//
        	//  Data TLB1: 4 MByte pages, 4-way set associative, 32 entries

            // This value represents a translation lookaside buffer of size - 128 MegaByte
            member_sizeInBytes = MegaByte( 4 * 32 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents a data translation lookaside buffer, the value was already set to false

            // This value represents a translation lookaside buffer that only support one page size
            member_numberOfPageSizesSupported = 1U;

            // The associativity is known
            member_isAssociativityKnown = true;

            // This is set associativity, the value was already set to false

            // This value represents 4 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = MegaByte( 4UL );

            // This value represents a 4 way set associative
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 1UL >() = 4UL;

            // This value represents 32 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 32UL;

            // There is nothing else to do
            break;
        }

        case 0x0B :
        {
        	// Description :
        	//
        	//  Instruction TLB: 4 MByte pages, 4-way set associative, 4 entries

            // This value represents a translation lookaside buffer of size - 16 MegaByte
            member_sizeInBytes = MegaByte( 4 * 4 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents an instruction translation lookaside buffer
            member_trueForInstructions_falseForData = true;

            // This value represents a translation lookaside buffer that only support one page size
            member_numberOfPageSizesSupported = 1U;

            // The associativity is known
            member_isAssociativityKnown = true;

            // This is set associativity, the value was already set to false

            // This value represents 4 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = MegaByte( 4UL );

            // This value represents a 4 way set associative
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 1UL >() = 4UL;

            // This value represents 4 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 4UL;

            // There is nothing else to do
            break;
        }

        case 0x4F :
        {
        	// Description :
        	//
        	//  Instruction TLB: 4 KByte pages, 32 entries

            // This value represents a translation lookaside buffer of size - 128 KiloByte
            member_sizeInBytes = KiloByte( 4 * 32 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents an instruction translation lookaside buffer
            member_trueForInstructions_falseForData = true;

            // This value represents a translation lookaside buffer that only support one page size
            member_numberOfPageSizesSupported = 1U;

            // The associativity is not known, the value was already set to false

            // This value represents 4 KiloByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = KiloByte( 4UL );

            // This value represents 32 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 32UL;

            // There is nothing else to do
            break;
        }

        case 0x50 :
        {
        	// Description :
        	//
        	//  Instruction TLB: 4 KByte and 2-MByte or 4-MByte pages, 64 entries

            // This value represents a translation lookaside buffer of size - 256 MegaByte
            member_sizeInBytes = MegaByte( 4 * 64 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents an instruction translation lookaside buffer
            member_trueForInstructions_falseForData = true;

            // This value represents a translation lookaside buffer that supports 3 page sizes
            member_numberOfPageSizesSupported = 3U;

            // The associativity is not known, the value was already set to false

            // This value represents 4 KiloByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = KiloByte( 4UL );

            // This value represents 64 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 64UL;

            // This value represents 2 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 0UL >() = MegaByte( 2UL );

            // This value represents 64 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 2UL >() = 64UL;

            // This value represents 4 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[2].template Entry< 0UL >() = MegaByte( 4UL );

            // This value represents 64 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[2].template Entry< 2UL >() = 64UL;

            // The 4 KiloByte and 2 MegaByte page sizes can coexist
            member_pageSizeCanWorkToghterWithThisOtherPageSizes[0][1] = true;
            member_pageSizeCanWorkToghterWithThisOtherPageSizes[1][0] = true;

            // There is nothing else to do
            break;
        }

        case 0x51 :
        {
        	// Description :
        	//
        	//  Instruction TLB: 4 KByte and 2-MByte or 4-MByte pages, 128 entries

            // This value represents a translation lookaside buffer of size - 512 MegaByte
            member_sizeInBytes = MegaByte( 4 * 128 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents an instruction translation lookaside buffer
            member_trueForInstructions_falseForData = true;

            // This value represents a translation lookaside buffer that supports 3 page sizes
            member_numberOfPageSizesSupported = 3U;

            // The associativity is not known, the value was already set to false

            // This value represents 4 KiloByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = KiloByte( 4UL );

            // This value represents 128 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 128UL;

            // This value represents 2 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 0UL >() = MegaByte( 2UL );

            // This value represents 128 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 2UL >() = 128UL;

            // This value represents 4 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[2].template Entry< 0UL >() = MegaByte( 4UL );

            // This value represents 128 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[2].template Entry< 2UL >() = 128UL;

            // The 4 KiloByte and 2 MegaByte page sizes can coexist
            member_pageSizeCanWorkToghterWithThisOtherPageSizes[0][1] = true;
            member_pageSizeCanWorkToghterWithThisOtherPageSizes[1][0] = true;

            // There is nothing else to do
            break;
        }

        case 0x52 :
        {
        	// Description :
        	//
        	//  Instruction TLB: 4 KByte and 2-MByte or 4-MByte pages, 256 entries

            // This value represents a translation lookaside buffer of size - 1024 MegaByte
            member_sizeInBytes = MegaByte( 4 * 256 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents an instruction translation lookaside buffer
            member_trueForInstructions_falseForData = true;

            // This value represents a translation lookaside buffer that supports 3 page sizes
            member_numberOfPageSizesSupported = 3U;

            // The associativity is not known, the value was already set to false

            // This value represents 4 KiloByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = KiloByte( 4UL );

            // This value represents 256 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 256UL;

            // This value represents 2 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 0UL >() = MegaByte( 2UL );

            // This value represents 256 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 2UL >() = 256UL;

            // This value represents 4 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[2].template Entry< 0UL >() = MegaByte( 4UL );

            // This value represents 256 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[2].template Entry< 2UL >() = 256UL;

            // The 4 KiloByte and 2 MegaByte page sizes can coexist
            member_pageSizeCanWorkToghterWithThisOtherPageSizes[0][1] = true;
            member_pageSizeCanWorkToghterWithThisOtherPageSizes[1][0] = true;

            // There is nothing else to do
            break;
        }

        case 0x55 :
        {
        	// Description :
        	//
        	//  Instruction TLB: 2-MByte or 4-MByte pages, fully associative, 7 entries

            // This value represents a translation lookaside buffer of size - 28 MegaByte
            member_sizeInBytes = MegaByte( 4 * 7 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents an instruction translation lookaside buffer
            member_trueForInstructions_falseForData = true;

            // This value represents a translation lookaside buffer that supports 2 page sizes
            member_numberOfPageSizesSupported = 2U;

            // The associativity is known
            member_isAssociativityKnown = true;

            // This is full associative
            member_trueForFullAssociative_falseForSetAssociative = true;

            // This value represents 2 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = MegaByte( 2UL );

            // This value represents 7 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 7UL;

            // This value represents 4 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 0UL >() = MegaByte( 4UL );

            // This value represents 7 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 2UL >() = 7UL;

            // There are no page sizes that can coexist, all the array was already set to false

            // There is nothing else to do
            break;
        }

        case 0x56 :
        {
        	// Description :
        	//
        	//  Data TLB0: 4 MByte pages, 4-way set associative, 16 entries

            // This value represents a translation lookaside buffer of size - 64 MegaByte
            member_sizeInBytes = MegaByte( 4 * 16 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents a data translation lookaside buffer, the value was already set to false

            // This value represents a translation lookaside buffer that only support one page size
            member_numberOfPageSizesSupported = 1U;

            // The associativity is known
            member_isAssociativityKnown = true;

            // This is set associativity, the value was already set to false

            // This value represents 4 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = MegaByte( 4UL );

            // This value represents a 4 way set associative
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 1UL >() = 4UL;

            // This value represents 16 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 16UL;

            // There is nothing else to do
            break;
        }

        case 0x57 :
        {
        	// Description :
        	//
        	//  Data TLB0: 4 KByte pages, 4-way set associative, 16 entries

            // This value represents a translation lookaside buffer of size - 64 KiloByte
            member_sizeInBytes = KiloByte( 4 * 16 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents a data translation lookaside buffer, the value was already set to false

            // This value represents a translation lookaside buffer that only support one page size
            member_numberOfPageSizesSupported = 1U;

            // The associativity is known
            member_isAssociativityKnown = true;

            // This is set associativity, the value was already set to false

            // This value represents 4 KiloByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = KiloByte( 4UL );

            // This value represents a 4 way set associative
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 1UL >() = 4UL;

            // This value represents 16 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 16UL;

            // There is nothing else to do
            break;
        }

        case 0x59 :
        {
        	// Description :
        	//
        	//  Data TLB0: 4 KByte pages, 4-way set associative, 16 entries

            // This value represents a translation lookaside buffer of size - 64 KiloByte
            member_sizeInBytes = KiloByte( 4 * 16 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents a data translation lookaside buffer, the value was already set to false

            // This value represents a translation lookaside buffer that only support one page size
            member_numberOfPageSizesSupported = 1U;

            // The associativity is known
            member_isAssociativityKnown = true;

            // This is full associative
            member_trueForFullAssociative_falseForSetAssociative = true;

            // This value represents 4 KiloByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = KiloByte( 4UL );

            // This value represents 16 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 16UL;

            // There is nothing else to do
            break;
        }

        case 0x5A :
        {
        	// Description :
        	//
        	//  Data TLB0: 2-MByte or 4-MByte pages, 4-way set associative, 32 entries

            // This value represents a translation lookaside buffer of size - 128 MegaByte
            member_sizeInBytes = MegaByte( 4 * 32 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents a data translation lookaside buffer, the value was already set to false

            // This value represents a translation lookaside buffer that supports 2 page sizes
            member_numberOfPageSizesSupported = 2U;

            // The associativity is known
            member_isAssociativityKnown = true;

            // This is set associativity, the value was already set to false

            // This value represents 2 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = MegaByte( 2UL );

            // This value represents a 4 way set associative
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 1UL >() = 4UL;

            // This value represents 32 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 32UL;

            // This value represents 4 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 0UL >() = MegaByte( 4UL );

            // This value represents a 4 way set associative
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 1UL >() = 4UL;

            // This value represents 32 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 2UL >() = 32UL;

            // There are no page sizes that can coexist, all the array was already set to false

            // There is nothing else to do
            break;
        }

        case 0x5B :
        {
        	// Description :
        	//
        	//  Data TLB: 4-KByte and 4-MByte pages, 64 entries

            // This value represents a translation lookaside buffer of size - 256 MegaByte
            member_sizeInBytes = MegaByte( 4 * 64 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents a data translation lookaside buffer, the value was already set to false

            // This value represents a translation lookaside buffer that supports 2 page sizes
            member_numberOfPageSizesSupported = 2U;

            // The associativity is not known, the value was already set to false

            // This value represents 4 KiloByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = KiloByte( 4UL );

            // This value represents 64 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 64UL;

            // This value represents 4 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 0UL >() = MegaByte( 4UL );

            // This value represents 64 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 2UL >() = 64UL;

            // The 4 KiloByte and 4 MegaByte page sizes can coexist
            member_pageSizeCanWorkToghterWithThisOtherPageSizes[0][1] = true;
            member_pageSizeCanWorkToghterWithThisOtherPageSizes[1][0] = true;

            // There is nothing else to do
            break;
        }

        case 0x5C :
        {
        	// Description :
        	//
        	//  Data TLB: 4-KByte and 4-MByte pages, 128 entries

            // This value represents a translation lookaside buffer of size - 512 MegaByte
            member_sizeInBytes = MegaByte( 4 * 128 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents a data translation lookaside buffer, the value was already set to false

            // This value represents a translation lookaside buffer that supports 2 page sizes
            member_numberOfPageSizesSupported = 2U;

            // The associativity is not known, the value was already set to false

            // This value represents 4 KiloByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = KiloByte( 4UL );

            // This value represents 128 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 128UL;

            // This value represents 4 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 0UL >() = MegaByte( 4UL );

            // This value represents 128 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 2UL >() = 128UL;

            // The 4 KiloByte and 4 MegaByte page sizes can coexist
            member_pageSizeCanWorkToghterWithThisOtherPageSizes[0][1] = true;
            member_pageSizeCanWorkToghterWithThisOtherPageSizes[1][0] = true;

            // There is nothing else to do
            break;
        }

        case 0x5D :
        {
        	// Description :
        	//
        	//  Data TLB: 4-KByte and 4-MByte pages, 256 entries

            // This value represents a translation lookaside buffer of size - 1024 MegaByte
            member_sizeInBytes = MegaByte( 4 * 256 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents a data translation lookaside buffer, the value was already set to false

            // This value represents a translation lookaside buffer that supports 2 page sizes
            member_numberOfPageSizesSupported = 2U;

            // The associativity is not known, the value was already set to false

            // This value represents 4 KiloByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = KiloByte( 4UL );

            // This value represents 256 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 256UL;

            // This value represents 4 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 0UL >() = MegaByte( 4UL );

            // This value represents 256 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 2UL >() = 256UL;

            // The 4 KiloByte and 4 MegaByte page sizes can coexist
            member_pageSizeCanWorkToghterWithThisOtherPageSizes[0][1] = true;
            member_pageSizeCanWorkToghterWithThisOtherPageSizes[1][0] = true;

            // There is nothing else to do
            break;
        }

        case 0x61 :
        {
        	// Description :
        	//
        	//  Instruction TLB: 4 KByte pages, fully associative, 48 entries

            // This value represents a translation lookaside buffer of size - 192 KiloByte
            member_sizeInBytes = KiloByte( 4 * 48 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents an instruction translation lookaside buffer
            member_trueForInstructions_falseForData = true;

            // This value represents a translation lookaside buffer that only support one page size
            member_numberOfPageSizesSupported = 1U;

            // The associativity is known
            member_isAssociativityKnown = true;

            // This is full associative
            member_trueForFullAssociative_falseForSetAssociative = true;

            // This value represents 4 KiloByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = KiloByte( 4UL );

            // This value represents 48 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 48UL;

            // There is nothing else to do
            break;
        }

        case 0x64 :
        {
        	// Description :
        	//
        	//  Data TLB: 4 KByte pages, 4-way set associative, 512 entries

            // This value represents a translation lookaside buffer of size - 2048 KiloByte
            member_sizeInBytes = KiloByte( 4 * 512 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents a data translation lookaside buffer, the value was already set to false

            // This value represents a translation lookaside buffer that only support one page size
            member_numberOfPageSizesSupported = 1U;

            // The associativity is known
            member_isAssociativityKnown = true;

            // This is set associativity, the value was already set to false

            // This value represents 4 KiloByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = KiloByte( 4UL );

            // This value represents a 4 way set associative
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 1UL >() = 4UL;

            // This value represents 512 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 512UL;

            // There is nothing else to do
            break;
        }

        case 0x76 :
        {
        	// Description :
        	//
        	//  Instruction TLB: 2-MByte or 4-MByte pages, fully associative, 8 entries

            // This value represents a translation lookaside buffer of size - 32 MegaByte
            member_sizeInBytes = MegaByte( 4 * 8 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents an instruction translation lookaside buffer
            member_trueForInstructions_falseForData = true;

            // This value represents a translation lookaside buffer that supports 2 page sizes
            member_numberOfPageSizesSupported = 2U;

            // The associativity is known
            member_isAssociativityKnown = true;

            // This is full associative
            member_trueForFullAssociative_falseForSetAssociative = true;

            // This value represents 2 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = MegaByte( 2UL );

            // This value represents 8 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 8UL;

            // This value represents 4 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 0UL >() = MegaByte( 4UL );

            // This value represents 8 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 2UL >() = 8UL;

            // There is nothing else to do
            break;
        }

        case 0xA0 :
        {
        	// Description :
        	//
        	//  Data TLB: 4 KByte pages, fully associative, 32 entries

            // This value represents a translation lookaside buffer of size - 128 KiloByte
            member_sizeInBytes = KiloByte( 4 * 32 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents a data translation lookaside buffer, the value was already set to false

            // This value represents a translation lookaside buffer that only support one page size
            member_numberOfPageSizesSupported = 1U;

            // The associativity is known
            member_isAssociativityKnown = true;

            // This is full associative
            member_trueForFullAssociative_falseForSetAssociative = true;

            // This value represents 4 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = MegaByte( 4UL );

            // This value represents 32 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 32UL;

            // There is nothing else to do
            break;
        }

        case 0xB0 :
        {
        	// Description :
        	//
        	//  Instruction TLB: 4 KByte pages, 4-way set associative, 128 entries

            // This value represents a translation lookaside buffer of size - 512 KiloByte
            member_sizeInBytes = KiloByte( 4 * 128 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents an instruction translation lookaside buffer
            member_trueForInstructions_falseForData = true;

            // This value represents a translation lookaside buffer that only support one page size
            member_numberOfPageSizesSupported = 1U;

            // The associativity is known
            member_isAssociativityKnown = true;

            // This is set associativity, the value was already set to false

            // This value represents 4 KiloByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = KiloByte( 4UL );

            // This value represents a 4 way set associative
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 1UL >() = 4UL;

            // This value represents 128 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 128UL;

            // There is nothing else to do
            break;
        }

        case 0xB1 :
        {
        	// Description :
        	//
        	//  Instruction TLB: 2M pages, 4-way, 8 entries or 4M pages, 4-way, 4 entries

            // This value represents a translation lookaside buffer of size - 16 MegaByte
            member_sizeInBytes = MegaByte( 4 * 4 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents an instruction translation lookaside buffer
            member_trueForInstructions_falseForData = true;

            // This value represents a translation lookaside buffer that supports 2 page sizes
            member_numberOfPageSizesSupported = 2U;

            // The associativity is known
            member_isAssociativityKnown = true;

            // This is set associativity, the value was already set to false

            // This value represents 2 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = MegaByte( 2UL );

            // This value represents a 4 way set associative
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 1UL >() = 4UL;

            // This value represents 8 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 8UL;

            // This value represents 4 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 0UL >() = MegaByte( 4UL );

            // This value represents a 4 way set associative
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 1UL >() = 4UL;

            // This value represents 4 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 2UL >() = 4UL;

            // There are no page sizes that can coexist, all the array was already set to false

            // There is nothing else to do
            break;
        }

        case 0xB2 :
        {
        	// Description :
        	//
        	//  Instruction TLB: 4KByte pages, 4-way set associative, 64 entries

            // This value represents a translation lookaside buffer of size - 256 KiloByte
            member_sizeInBytes = KiloByte( 4 * 64 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents an instruction translation lookaside buffer
            member_trueForInstructions_falseForData = true;

            // This value represents a translation lookaside buffer that only support one page size
            member_numberOfPageSizesSupported = 1U;

            // The associativity is known
            member_isAssociativityKnown = true;

            // This is set associativity, the value was already set to false

            // This value represents 4 KiloByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = KiloByte( 4UL );

            // This value represents a 4 way set associative
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 1UL >() = 4UL;

            // This value represents 64 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 64UL;

            // There is nothing else to do
            break;
        }

        case 0xB3 :
        {
        	// Description :
        	//
        	//  Data TLB: 4 KByte pages, 4-way set associative, 128 entries

            // This value represents a translation lookaside buffer of size - 512 KiloByte
            member_sizeInBytes = KiloByte( 4 * 128 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents a data translation lookaside buffer, the value was already set to false

            // This value represents a translation lookaside buffer that only support one page size
            member_numberOfPageSizesSupported = 1U;

            // The associativity is known
            member_isAssociativityKnown = true;

            // This is set associativity, the value was already set to false

            // This value represents 4 KiloByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = KiloByte( 4UL );

            // This value represents a 4 way set associative
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 1UL >() = 4UL;

            // This value represents 128 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 128UL;

            // There is nothing else to do
            break;
        }

        case 0xB4 :
        {
        	// Description :
        	//
        	//  Data TLB: 4 KByte pages, 4-way set associative, 256 entries

            // This value represents a translation lookaside buffer of size - 1024 KiloByte
            member_sizeInBytes = KiloByte( 4 * 256 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents a data translation lookaside buffer, the value was already set to false

            // This value represents a translation lookaside buffer that only support one page size
            member_numberOfPageSizesSupported = 1U;

            // The associativity is known
            member_isAssociativityKnown = true;

            // This is set associativity, the value was already set to false

            // This value represents 4 KiloByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = KiloByte( 4UL );

            // This value represents a 4 way set associative
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 1UL >() = 4UL;

            // This value represents 256 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 256UL;

            // There is nothing else to do
            break;
        }

        case 0xB5 :
        {
        	// Description :
        	//
        	//  Instruction TLB: 4KByte pages, 8-way set associative, 64 entries

            // This value represents a translation lookaside buffer of size - 256 KiloByte
            member_sizeInBytes = KiloByte( 4 * 64 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents an instruction translation lookaside buffer
            member_trueForInstructions_falseForData = true;

            // This value represents a translation lookaside buffer that only support one page size
            member_numberOfPageSizesSupported = 1U;

            // The associativity is known
            member_isAssociativityKnown = true;

            // This is set associativity, the value was already set to false

            // This value represents 4 KiloByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = KiloByte( 4UL );

            // This value represents a 8 way set associative
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 1UL >() = 8UL;

            // This value represents 64 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 64UL;

            // There is nothing else to do
            break;
        }

        case 0xB6 :
        {
        	// Description :
        	//
        	//  Instruction TLB: 4KByte pages, 8-way set associative, 128 entries

            // This value represents a translation lookaside buffer of size - 512 KiloByte
            member_sizeInBytes = KiloByte( 4 * 128 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents an instruction translation lookaside buffer
            member_trueForInstructions_falseForData = true;

            // This value represents a translation lookaside buffer that only support one page size
            member_numberOfPageSizesSupported = 1U;

            // The associativity is known
            member_isAssociativityKnown = true;

            // This is set associativity, the value was already set to false

            // This value represents 4 KiloByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = KiloByte( 4UL );

            // This value represents a 8 way set associative
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 1UL >() = 8UL;

            // This value represents 128 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 128UL;

            // There is nothing else to do
            break;
        }

        case 0xBA :
        {
        	// Description :
        	//
        	//  Data TLB: 4 KByte pages, 4-way set associative, 64 entries

            // This value represents a translation lookaside buffer of size - 256 KiloByte
            member_sizeInBytes = KiloByte( 4 * 64 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents a data translation lookaside buffer, the value was already set to false

            // This value represents a translation lookaside buffer that only support one page size
            member_numberOfPageSizesSupported = 1U;

            // The associativity is known
            member_isAssociativityKnown = true;

            // This is set associativity, the value was already set to false

            // This value represents 4 KiloByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = KiloByte( 4UL );

            // This value represents a 4 way set associative
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 1UL >() = 4UL;

            // This value represents 64 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 64UL;

            // There is nothing else to do
            break;
        }

        case 0xC0 :
        {
        	// Description :
        	//
        	//  Data TLB: 4 KByte and 4 MByte pages, 4-way associative, 8 entries

            // This value represents a translation lookaside buffer of size - 32 MegaByte
            member_sizeInBytes = MegaByte( 4 * 8 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents a data translation lookaside buffer, the value was already set to false

            // This value represents a translation lookaside buffer that supports 2 page sizes
            member_numberOfPageSizesSupported = 2U;

            // The associativity is not known, the value was already set to false

            // This value represents 4 KiloByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = KiloByte( 4UL );

            // This value represents 8 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 8UL;

            // This value represents 4 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 0UL >() = MegaByte( 4UL );

            // This value represents 8 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 2UL >() = 8UL;

            // The 4 KiloByte and 4 MegaByte page sizes can coexist
            member_pageSizeCanWorkToghterWithThisOtherPageSizes[0][1] = true;
            member_pageSizeCanWorkToghterWithThisOtherPageSizes[1][0] = true;

            // There is nothing else to do
            break;
        }

        case 0xC1 :
        {
        	// Description :
        	//
        	//  Shared 2nd-Level TLB: 4 KByte/2MByte pages, 8-way associative, 1024 entries

            // This value represents a translation lookaside buffer of size - 2048 MegaByte
            member_sizeInBytes = MegaByte( 2 * 1024 );

            // This is a shared translation lookaside buffer
            member_trueForShared_falseForExclusiveUse = true;

            // This value represents a data translation lookaside buffer, the value was already set to false

            // This value represents a translation lookaside buffer that supports 2 page sizes
            member_numberOfPageSizesSupported = 2U;

            // The associativity is known
            member_isAssociativityKnown = true;

            // This is set associativity, the value was already set to false

            // This value represents 4 KiloByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = KiloByte( 4UL );

            // This value represents a 8 way set associative
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 1UL >() = 8UL;

            // This value represents 1024 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 1024UL;

            // This value represents 2 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 0UL >() = MegaByte( 2UL );

            // This value represents a 8 way set associative
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 1UL >() = 8UL;
            
            // This value represents 1024 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 2UL >() = 1024UL;

            // There are no page sizes that can coexist, all the array was already set to false

            // There is nothing else to do
            break;
        }   

        case 0xC2 :
        {
        	// Description :
        	//
        	//  DTLB: 4 KByte/2 MByte pages, 4-way associative, 16 entries

            // This value represents a translation lookaside buffer of size - 32 MegaByte
            member_sizeInBytes = MegaByte( 2 * 16 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents a data translation lookaside buffer, the value was already set to false

            // This value represents a translation lookaside buffer that supports 2 page sizes
            member_numberOfPageSizesSupported = 2U;

            // The associativity is known
            member_isAssociativityKnown = true;

            // This is set associativity, the value was already set to false

            // This value represents 4 KiloByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = KiloByte( 4UL );

            // This value represents a 4 way set associative
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 1UL >() = 4UL;

            // This value represents 16 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 16UL;

            // This value represents 2 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 0UL >() = MegaByte( 2UL );

            // This value represents a 4 way set associative
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 1UL >() = 4UL;
            
            // This value represents 16 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 2UL >() = 16UL;

            // There are no page sizes that can coexist, all the array was already set to false

            // There is nothing else to do
            break;
        }

        case 0xC3 :
        {
        	// Description :
        	//
        	//  Shared 2nd-Level TLB: 4 KByte /2 MByte pages, 6-way associative, 1536 entries. Also 1GBbyte pages, 4-way, 16 entries

            // This value represents a translation lookaside buffer of size - 3072 MegaByte
            member_sizeInBytes = MegaByte( 2 * 1536 );

            // This is a shared translation lookaside buffer
            member_trueForShared_falseForExclusiveUse = true;

            // This value represents a data translation lookaside buffer, the value was already set to false

            // This value represents a translation lookaside buffer that supports 2 page sizes
            member_numberOfPageSizesSupported = 2U;

            // The associativity is known
            member_isAssociativityKnown = true;

            // This is set associativity, the value was already set to false

            // This value represents 4 KiloByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = KiloByte( 4UL );

            // This value represents a 6 way set associative
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 1UL >() = 6UL;

            // This value represents 1536 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 1536UL;

            // This value represents 2 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 0UL >() = MegaByte( 2UL );

            // This value represents a 6 way set associative
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 1UL >() = 6UL;
            
            // This value represents 1536 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 2UL >() = 1536UL;

            // There are no page sizes that can coexist, all the array was already set to false

            // There is nothing else to do
            break;
        }

        case 0xC4 :
        {
        	// Description :
        	//
        	//  DTLB: 2M/4M Byte pages, 4-way associative, 32 entries

            // This value represents a translation lookaside buffer of size - 128 MegaByte
            member_sizeInBytes = MegaByte( 4 * 16 );

            // This is exclusive translation lookaside buffer, the value was already set to false

            // This value represents a data translation lookaside buffer, the value was already set to false

            // This value represents a translation lookaside buffer that supports 2 page sizes
            member_numberOfPageSizesSupported = 2U;

            // The associativity is known
            member_isAssociativityKnown = true;

            // This is set associativity, the value was already set to false

            // This value represents 2 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = MegaByte( 2UL );

            // This value represents a 4 way set associative
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 1UL >() = 4UL;

            // This value represents 32 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 32UL;

            // This value represents 4 MegaByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 0UL >() = MegaByte( 4UL );

            // This value represents a 4 way set associative
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 1UL >() = 4UL;
            
            // This value represents 32 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[1].template Entry< 2UL >() = 32UL;

            // There are no page sizes that can coexist, all the array was already set to false

            // There is nothing else to do
            break;
        }

        case 0xCA :
        {
        	// Description :
        	//
        	//  Shared 2nd-Level TLB: 4 KByte pages, 4-way associative, 512 entries

            // This value represents a translation lookaside buffer of size - 2048 KiloByte
            member_sizeInBytes = KiloByte( 4 * 512 );

            // This is a shared translation lookaside buffer
            member_trueForShared_falseForExclusiveUse = true;

            // This value represents a data translation lookaside buffer, the value was already set to false

            // This value represents a translation lookaside buffer that only support one page size
            member_numberOfPageSizesSupported = 1U;

            // The associativity is known
            member_isAssociativityKnown = true;

            // This is set associativity, the value was already set to false

            // This value represents 4 KiloByte pages
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 0UL >() = KiloByte( 4UL );

            // This value represents a 4 way set associative
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 1UL >() = 4UL;

            // This value represents 512 entries
            member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative[0].template Entry< 2UL >() = 512UL;

            // There is nothing else to do
            break;
        }

        // Every other value given does not represent translation lookaside buffer information
        default :
        {
            // The given byte descriptor is invalid, throw an exception describing the problem
            ThrowException( "The given byte descriptor does not represent translation lookaside buffer" );                     
        }
    }
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	void TranslationLookasideBufferIdentification::UnitTest()
	{}

)  //  End of debug tool



}  //  Namespace CentralProcessingUnit


}  //  Namespace Universe