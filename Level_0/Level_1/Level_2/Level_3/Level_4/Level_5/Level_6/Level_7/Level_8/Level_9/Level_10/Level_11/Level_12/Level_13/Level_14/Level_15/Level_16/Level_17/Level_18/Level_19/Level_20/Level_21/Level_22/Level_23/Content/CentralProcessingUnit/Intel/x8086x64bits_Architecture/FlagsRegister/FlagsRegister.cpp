namespace Universe 
{


namespace CentralProcessingUnit
{



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	void FlagsRegister::UnitTest()
	{
		FlagsRegister testFlagsRegister_0;

		std::cout << testFlagsRegister_0.ToString().ToAsciiString().DataPointer() << std::endl;

		testFlagsRegister_0.Parity().TurnOn();
		testFlagsRegister_0.Sign().TurnOn();
		testFlagsRegister_0.Zero().TurnOn();
		testFlagsRegister_0.Carry().TurnOn();
		testFlagsRegister_0.Auxiliary().TurnOn();

		std::cout << testFlagsRegister_0.ToString().ToAsciiString().DataPointer() << std::endl;

		testFlagsRegister_0.SetHardwareFlagsRegister();

		FlagsRegister testFlagsRegister_1;

		Assert_Test( testFlagsRegister_0 == testFlagsRegister_1 );
	}

)  //  End of debug tool



}  //  Namespace CentralProcessingUnit


}  //  Namespace Universe