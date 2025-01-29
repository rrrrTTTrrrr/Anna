namespace Universe 
{



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	void ConvertBetweenNumericSystems::UnitTest()
	{
		// BINARY - HEXADECIMAL :


		// Convert to hexadecimal
		const Language::String hexadecimalResult_0 = BinaryToHexadecimal< UnsignedInteger64bits >( 1UL );

		// This will store the expected result
		const Language::String expectedHexadecimalResult_0 = "L0x0100000000000000";

		// Loop on the result
		for ( UnsignedInteger64bits index = 0 ; index < hexadecimalResult_0.Size() ; ++index )
		{
			// Assert that the result is correct
			Assert_Test( hexadecimalResult_0[ index ] == expectedHexadecimalResult_0[ index ] );
		}

		// Convert now from hexadecimal to binary, and assert the result
		Assert_Test( HexadecimalToBinary< UnsignedInteger64bits >( hexadecimalResult_0 ) == 1UL );

		// Convert to hexadecimal
		const Language::String hexadecimalResult_1 = BinaryToHexadecimal< UnsignedInteger64bits >( 128UL );

		// This will store the expected result
		const Language::String expectedHexadecimalResult_1 = "L0x8000000000000000";

		// Loop on the result
		for ( UnsignedInteger64bits index = 0 ; index < hexadecimalResult_1.Size() ; ++index )
		{
			// Assert that the result is correct
			Assert_Test( hexadecimalResult_1[ index ] == expectedHexadecimalResult_1[ index ] );
		}

		// Convert now from hexadecimal to binary, and assert the result
		Assert_Test( HexadecimalToBinary< UnsignedInteger64bits >( hexadecimalResult_1 ) == 128UL );

		// Convert to hexadecimal
		const Language::String hexadecimalResult_2 = BinaryToHexadecimal< UnsignedInteger64bits >( 9428938493UL );

		// This will store the expected result
		const Language::String expectedHexadecimalResult_2 = "L0xFD2E023202000000";

		// Loop on the result
		for ( UnsignedInteger64bits index = 0 ; index < hexadecimalResult_2.Size() ; ++index )
		{
			// Assert that the result is correct
			Assert_Test( hexadecimalResult_2[ index ] == expectedHexadecimalResult_2[ index ] );
		}

		// Convert now from hexadecimal to binary, and assert the result
		Assert_Test( HexadecimalToBinary< UnsignedInteger64bits >( hexadecimalResult_2 ) == 9428938493UL );

		// Convert to hexadecimal
		const Language::String hexadecimalResult_3 = BinaryToHexadecimal< SignedInteger32bits >( -23431 );

		// This will store the expected result
		const Language::String expectedHexadecimalResult_3 = "L0x79A4FFFF";

		// Loop on the result
		for ( UnsignedInteger64bits index = 0 ; index < hexadecimalResult_3.Size() ; ++index )
		{
			// Assert that the result is correct
			Assert_Test( hexadecimalResult_3[ index ] == expectedHexadecimalResult_3[ index ] );
		}

		// Convert now from hexadecimal to binary, and assert the result
		Assert_Test( HexadecimalToBinary< SignedInteger32bits >( hexadecimalResult_3 ) == -23431 );


		// BINARY - DECIMAL :


		// Convert to decimal
		const Language::String decimalResult_0( 9875 );

		// This will store the expected result
		const Language::String expectedDecimalResult_0 = "9875";

		// Loop on the result
		for ( UnsignedInteger64bits index = 0 ; index < decimalResult_0.Size() ; ++index )
		{
			// Assert that the result is correct
			Assert_Test( decimalResult_0[ index ] == expectedDecimalResult_0[ index ] );
		}

		// Convert now from hexadecimal to binary, and assert the result
		Assert_Test( DecimalToBinary< SignedInteger32bits >( decimalResult_0 ) == 9875 );

		// Convert to decimal
		const Language::String decimalResult_1( -11233 );

		// This will store the expected result
		const Language::String expectedDecimalResult_1 = "-11233";

		// Loop on the result
		for ( UnsignedInteger64bits index = 0 ; index < decimalResult_1.Size() ; ++index )
		{
			// Assert that the result is correct
			Assert_Test( decimalResult_1[ index ] == expectedDecimalResult_1[ index ] );
		}

		// Convert now from hexadecimal to binary, and assert the result
		Assert_Test( DecimalToBinary< SignedInteger32bits >( decimalResult_1 ) == -11233 );

		// Convert to decimal
		const Language::String decimalResult_2( 0 );

		// This will store the expected result
		const Language::String expectedDecimalResult_2 = "0";

		// Loop on the result
		for ( UnsignedInteger64bits index = 0 ; index < decimalResult_2.Size() ; ++index )
		{
			// Assert that the result is correct
			Assert_Test( decimalResult_2[ index ] == expectedDecimalResult_2[ index ] );
		}

		// Convert now from hexadecimal to binary, and assert the result
		Assert_Test( DecimalToBinary< SignedInteger32bits >( decimalResult_2 ) == 0 );

		const UnsignedInteger8bits binaryCodedDecimal_0 = 0x98;

		Assert_Test( BinaryCodedDecimalToBinary< UnsignedInteger8bits >( binaryCodedDecimal_0 ) == 98 );

		const UnsignedInteger16bits binaryCodedDecimal_1 = 0x9845;

		Assert_Test( BinaryCodedDecimalToBinary< UnsignedInteger16bits >( binaryCodedDecimal_1 ) == 9845 );

		// const UnsignedInteger32bits binaryCodedDecimal_2 = 0x98457777;

		// Assert_Test( BinaryCodedDecimalToBinary< UnsignedInteger32bits >( binaryCodedDecimal_2 ) == 98457777 );

		// const UnsignedInteger64bits binaryCodedDecimal_3 = 0x9845777798457777;

		// Assert_Test( BinaryCodedDecimalToBinary< UnsignedInteger64bits >( binaryCodedDecimal_3 ) == 9845777798457777 );
	}

)  //  End of debug tool



}  //  Namespace Universe