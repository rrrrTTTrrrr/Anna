namespace Universe
{


namespace Memory
{



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	void Bits::UnitTest()
	{
		// Check the test for 8 bits integer
		Assert_Test( GetIntegerWithAllMostSignificantBitsOnFromIndexAndAbove< UnsignedInteger8bits >( 6 ) == 0xC0 );

		// Check the test for 16 bits integer
		Assert_Test( GetIntegerWithAllMostSignificantBitsOnFromIndexAndAbove< UnsignedInteger16bits >( 15 ) == 0x8000 );

		// Check the test for 64 bits integer
		Assert_Test( GetIntegerWithAllMostSignificantBitsOnFromIndexAndAbove< UnsignedInteger64bits >( 41 ) == 0xFFFFFE0000000000 );

		// Check the test for 8 bits integer
		Assert_Test( GetIntegerWithAllMostSignificantBitsOffFromIndexAndAbove< UnsignedInteger8bits >( 6 ) == 0x3F );

		// Check the test for 16 bits integer
		Assert_Test( GetIntegerWithAllMostSignificantBitsOffFromIndexAndAbove< UnsignedInteger16bits >( 15 ) == 0x7FFF );

		// Check the test for 64 bits integer
		Assert_Test( GetIntegerWithAllMostSignificantBitsOffFromIndexAndAbove< UnsignedInteger64bits >( 41 ) == 0x00001FFFFFFFFFF );
	}

)  //  End of debug tool



}  //  Namespace Memory


}  //  Namespace Universe