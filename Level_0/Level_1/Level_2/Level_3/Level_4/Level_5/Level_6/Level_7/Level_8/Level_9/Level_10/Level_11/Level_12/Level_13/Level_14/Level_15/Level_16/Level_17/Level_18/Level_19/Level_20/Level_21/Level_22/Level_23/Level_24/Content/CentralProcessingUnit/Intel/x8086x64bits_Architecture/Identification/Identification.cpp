namespace Universe
{


namespace CentralProcessingUnit
{



// Initialize the static members :


// Set the maximum value that for EAX register that will still provide basic information when calling 'CPUID'
LargestUnsignedInteger Identification::member_Basic_EAX_valuesMaximum = Identification::GetMaximumValueForBasicInformation__Private();

// Collect all the possible basic information on the central processing unit
Memory::Vector< Memory::Array< UnsignedInteger32bits, 4UL > > Identification::member_centralProcessingUnitBasicInformation = TakeResourcesAndLeaveInstanceInDefaultState( Identification::GetBasicInformation__Private() );

// Set the vendor identification string
Language::String Identification::member_vendorIdentificationString = TakeResourcesAndLeaveInstanceInDefaultState( ExtractVendorIdentificationString__Private() );

// Extract all the information on the translation lookaside buffers for the central processing unit
//const TranslationLookasideBuffersIdentification Identification::member_translationLookasideBuffersIdentification;/*( Identification::member_centralProcessingUnitBasicInformation[2]  )*/



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	void Identification::UnitTest()
	{
		for ( LargestUnsignedInteger index = 0UL ; index < member_vendorIdentificationString.Size() ; ++index )
		{
			std::cout << member_vendorIdentificationString[index].GetAsAsciiCharacter();
		}

		std::cout << std::endl;
	}

)  //  End of debug tool



}  //  Namespace CentralProcessingUnit


}  //  Namespace Universe