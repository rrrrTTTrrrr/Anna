namespace Universe 
{


namespace CentralProcessingUnit
{



//	********************************************************************   PRIVATE METHODS IMPLEMENTATION   *********************************************************************



Boolean TranslationLookasideBuffersIdentification::DoesByteDescriptorValueRepresentTranslaionLookasideBuffer__Private( const UnsignedInteger8bits byteDescriptor )
{
    // This array will contain all the valid byte descriptors that describe translation lookaside buffers
	static const Boolean byteDescriptorsThatRepresentTranslationLookasideBuffer[256] = { false, true, true, true, true, true, false, false, false, false, false, true, false, false, false, false,
																						 false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
																						 false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
																						 false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
																						 false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true,
																						 true, true, true, false, false, true, true, true, false, true, true, true, true, true, false, false,
																						 false, true, false, true, true, false, false, false, false, false, false, false, false, false, false, false,
																						 false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false,
																						 false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
																						 false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
																						 true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
																						 true, true, true, true, true, true, true, false, false, false, true, false, false, false, false, false,
																						 true, true, true, true, true, false, false, false, false, false, true, false, false, false, false, false,
																						 false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
																						 false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
																						 false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false };

	// Use the byte descriptor as index to the array, and return if it describes a translation lookaside buffer or not
	return ( byteDescriptorsThatRepresentTranslationLookasideBuffer[ byteDescriptor ] );
}


void TranslationLookasideBuffersIdentification::InitializeTranslationLookasideBuffersIdentificationArray__Private( const Memory::Array< UnsignedInteger32bits, 4UL >& EAX_EBX_ECX_EDX_registersContentStoredAfterCpuidInstructionExecutedWithEAXsetToTwo )
{
    // The information is in EAX, EBX, ECX and EDX when executing the CPUID with EAX set to 2, beside the lowest significant byte in
    // the EAX part of the RAX register. Each byte of this registers contains a descriptor. This descriptor is an index into a table,
    // in the Intel software developer manual part 2 in the CPUID instruction part ( table 3-12 - Encoding of CPUID Leaf 2 descriptors ),
    // that contains information on the translation lookaside buffers of the central processing unit

    // Loop on all the registers parts EAX, EBX, ECX and EDX
    for ( LargestUnsignedInteger registerIndex = 0 ; registerIndex < EAX_EBX_ECX_EDX_registersContentStoredAfterCpuidInstructionExecutedWithEAXsetToTwo.Size() ; ++registerIndex )
    {
        // Create an instance that will point to the most significant bit of the current register
        const Memory::Bit< UnsignedInteger32bits > registerMostSignificantBit( const_cast< UnsignedInteger32bits* >( &EAX_EBX_ECX_EDX_registersContentStoredAfterCpuidInstructionExecutedWithEAXsetToTwo[ registerIndex ] ), 31 );

    	// Check if the most significant bit of the current register is set ON which means it is reserved, and does not contain valid information
    	if ( registerMostSignificantBit.State() == Memory::BitState::ON )
    	{
    		// The most significant bit of the current register is ON

    		// Continue to the next register
    		continue;
    	}

        // This object will store the current byte descriptor
        UnsignedInteger8bits byteDescriptor = 0;

        // Loop on the 4 byte of each part of the register
        for ( LargestUnsignedInteger registerByteIndex = 0 ; registerByteIndex < EAX_EBX_ECX_EDX_registersContentStoredAfterCpuidInstructionExecutedWithEAXsetToTwo.Size() ; ++registerByteIndex )
        {
            // Set the byte descriptor
            byteDescriptor = *( reinterpret_cast< const UnsignedInteger8bits* >( &EAX_EBX_ECX_EDX_registersContentStoredAfterCpuidInstructionExecutedWithEAXsetToTwo[ registerIndex ] ) + registerByteIndex );

            // The least significant byte of EAX does not contain information, check if it is the current byte
            if ( ( registerIndex == 0UL ) && ( registerByteIndex == 0 ) )
            {
                // This is the least significant byte of EAX

                // Skip this byte
                continue;
            }

            // Check if the current byte descriptor represents translation lookaside buffer
            if ( DoesByteDescriptorValueRepresentTranslaionLookasideBuffer__Private( byteDescriptor ) == false )
            {
            	// The current byte descriptor does not represents translation lookaside buffer

            	// Continue to the next byte descriptor
            	continue;
            }

            // Provide the current byte descriptor to try initialize the translation lookaside buffer identification instance, it will
            // only be initialized in case the descriptor match one of the values that describe a translation lookaside buffer
            member_translationLookasideBuffersIdentification.InsertSingleElement( 0UL, TakeResourcesAndLeaveInstanceInDefaultState( TranslationLookasideBufferIdentification( byteDescriptor ) ) );
        }   
    }
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	void TranslationLookasideBuffersIdentification::UnitTest()
	{}

)  //  End of debug tool



}  //  Namespace CentralProcessingUnit


}  //  Namespace Universe