namespace Universe
{


namespace User
{



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	void WriteToStandardOutput::UnitTest()
	{
		WriteToStandardOutput testWriteToStandardOutput;

		// Create an instance of all the built in types
		UnsignedInteger8bits testBuiltIn_0 = 1;
		UnsignedInteger16bits testBuiltIn_1 = 2;
		UnsignedInteger32bits testBuiltIn_2 = 3;
		UnsignedInteger64bits testBuiltIn_3 = 4;
		SignedInteger8bits testBuiltIn_4 = 5;
		SignedInteger16bits testBuiltIn_5 = 6;
		SignedInteger32bits testBuiltIn_6 = -7;
		SignedInteger64bits testBuiltIn_7 = -888;
		Boolean testBuiltIn_8 = false;
		Boolean testBuiltIn_9 = true;

		// Display the content to the built in
		testWriteToStandardOutput << testBuiltIn_0 << "\n";
		testWriteToStandardOutput << testBuiltIn_1 << "\n";
		testWriteToStandardOutput << testBuiltIn_2 << "\n";
		testWriteToStandardOutput << testBuiltIn_3 << "\n";
		testWriteToStandardOutput << testBuiltIn_4 << "\n";
		testWriteToStandardOutput << testBuiltIn_5 << "\n";
		testWriteToStandardOutput << testBuiltIn_6 << "\n";
		testWriteToStandardOutput << testBuiltIn_7 << "\n";
		testWriteToStandardOutput << testBuiltIn_8 << "\n";
		testWriteToStandardOutput << testBuiltIn_9 << "\n";

		// Create a test memory handler
		SequentialDataStructure< SignedInteger32bits > testMemoryHandler_0( MemoryHandlerName::Vector, 9UL, 89 );

		// Display the content to the user
		testWriteToStandardOutput << testMemoryHandler_0 << "\n";

		// Display the content to the user
		testWriteToStandardOutput << "I dont know" << "\n";

		// Create a test string
		Language::String testString_0( "I dont know" );

		// Display the content to the user
		testWriteToStandardOutput << testString_0 << "\n";

		// Test for display bits, this test needs to be examined by the user :

		// Create an object and store the value 1
		UnsignedInteger64bits testInteger_1 = 1;

		// Display the bits
		testWriteToStandardOutput.Bits< UnsignedInteger64bits >( testInteger_1 ).MoveCursorLineDown__Private();

		// Left shift the bit to the last bit 
		testInteger_1 <<= 63;

		// Display the bits
		testWriteToStandardOutput.Bits< UnsignedInteger64bits >( testInteger_1 ).MoveCursorLineDown__Private();

		// Create an object with the value 8  -  00001000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
		UnsignedInteger64bits testObject_1 = 8;

		// Create an object with the value 1024  -  00000000 00000100 00000000 00000000 00000000 00000000 00000000 00000000
		UnsignedInteger64bits testObject_2 = 1024;

		// Create an object with the value 56  -  00111000
		UnsignedInteger64bits testObject_3 = 56;

		// Check the display bits method
		testWriteToStandardOutput.Bits< UnsignedInteger64bits >( testObject_1 ).MoveCursorLineDown__Private();

		// Check the display bits method
		testWriteToStandardOutput.Bits< UnsignedInteger64bits >( testObject_2 ).MoveCursorLineDown__Private();

		// Check the display bits method
		testWriteToStandardOutput.Bits< UnsignedInteger64bits >( testObject_3 ).MoveCursorLineDown__Private();

		// Check the template method - 00001001
		testWriteToStandardOutput.Bits< UnsignedInteger8bits >( 9 ).MoveCursorLineDown__Private();

		// Check the template method - 00000000 00000001
		testWriteToStandardOutput.Bits< UnsignedInteger16bits >( 256 ).MoveCursorLineDown__Private();

		// Check the template method - 00000001 00000000 00000001 00000000
		testWriteToStandardOutput.Bits< UnsignedInteger32bits >( 65537 ).MoveCursorLineDown__Private();

		// Check the template method
		testWriteToStandardOutput.Bits< UnsignedInteger64bits >( 50000000001UL ).MoveCursorLineDown__Private();

		// Check the template method
		testWriteToStandardOutput.Bits< SignedInteger8bits >( -1 ).MoveCursorLineDown__Private();

		// Check the template method
		testWriteToStandardOutput.Bits< SignedInteger16bits >( -256 ).MoveCursorLineDown__Private();

		// Check the template method
		testWriteToStandardOutput.Bits< SignedInteger32bits >( -16000 ).MoveCursorLineDown__Private();

		// Check the template method
		testWriteToStandardOutput.Bits< SignedInteger64bits >( ~0 ).MoveCursorLineDown__Private();

		// Check the template method
		testWriteToStandardOutput.Bits< FloatingPoint32bits >( 2 ).MoveCursorLineDown__Private();

		// Check the template method
		testWriteToStandardOutput.Bits< FloatingPoint32bits >( -2 ).MoveCursorLineDown__Private();

		// Check the template method
		testWriteToStandardOutput.Bits< FloatingPoint64bits >( 2 ).MoveCursorLineDown__Private();

		// Check the template method
		testWriteToStandardOutput.Bits< FloatingPoint64bits >( -2 ).MoveCursorLineDown__Private();

		testWriteToStandardOutput.Bits< SignedInteger8bits >( 127 ).MoveCursorLineDown__Private();
		testWriteToStandardOutput.Bits< SignedInteger8bits >( -128 ).MoveCursorLineDown__Private();
		testWriteToStandardOutput.Bits< SignedInteger8bits >( -127 ).MoveCursorLineDown__Private();
	}

)  //  End of debug tool



}  //  Namespace User


}  //  Namespace Universe