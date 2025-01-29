namespace Universe 
{


namespace Memory
{



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	void MainMemoryManager::UnitTest()
	{
		// Try to allocte
		auto testPointer_0 = AllocateAndDefaultConstruct< UnsignedInteger64bits >();

		// Set the memory space with value
		*testPointer_0 = 89UL;

		// Ensure the memory space was set with the value
		Assert_Test( *testPointer_0 == 89UL );
	}

)  //  End of debug tool



}  //  Namespace Memory


}  //  Namespace Universe
