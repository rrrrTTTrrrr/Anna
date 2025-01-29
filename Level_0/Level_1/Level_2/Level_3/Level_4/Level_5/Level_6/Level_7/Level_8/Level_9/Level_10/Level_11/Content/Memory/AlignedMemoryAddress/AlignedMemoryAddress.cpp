namespace Universe 
{


namespace Memory
{



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	void AlignedMemoryAddress::UnitTest()
	{
		// Store a memory address
		const void* const pointer = (void*)0x1C4CBF;

		// Assert that the next aligned memory address is - 0x1C4CC0
		Assert_Test( Next< void >( pointer, 8UL ) == (void*)0x1C4CC0 );

		// Assert that the next aligned memory address is - 0x1C4CC0
		Assert_Test( Next< void >( pointer, 16UL ) == (void*)0x1C4CC0 );

		// Assert that the previous aligned memory address is - 0x1C4CB8
		Assert_Test( Previous< void >( pointer, 8UL ) == (void*)0x1C4CB8 );

		// Assert that the previous aligned memory address is - 0x1C4CB0
		Assert_Test( Previous< void >( pointer, 16UL ) == (void*)0x1C4CB0 );
	}

)  //  End of debug tool



}  //  Namespace Memory


}  //  Namespace Universe