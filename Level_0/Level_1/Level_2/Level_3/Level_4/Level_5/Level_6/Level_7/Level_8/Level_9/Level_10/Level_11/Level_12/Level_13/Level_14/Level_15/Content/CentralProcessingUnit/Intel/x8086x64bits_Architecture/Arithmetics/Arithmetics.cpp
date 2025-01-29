namespace Universe 
{


namespace CentralProcessingUnit
{



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	void Arithmetics::UnitTest()
	{
		// SIGNED :

		// Create a test dividend
		SignedInteger8bits testDividend_0 = 89;

		// Create a test divisor
		SignedInteger8bits testDivisor_0 = 89;

		// Perform the divison
		DivisonResultSignedInteger8bits testResult_0 = Divison( testDividend_0, testDivisor_0 );

		// Check that the result is correct
		Assert_Test( testResult_0.Quotient() == 1 );
		Assert_Test( testResult_0.Remainder() == 0 );

		// Create a test dividend
		SignedInteger16bits testDividend_1 = 1000;

		// Create a test divisor
		SignedInteger16bits testDivisor_1 = 101;

		// Perform the divison
		DivisonResultSignedInteger16bits testResult_1 = Divison( testDividend_1, testDivisor_1 );

		// Check that the result is correct
		Assert_Test( testResult_1.Quotient() == 9 );
		Assert_Test( testResult_1.Remainder() == 91 );

		// Create a test dividend
		SignedInteger32bits testDividend_2 = 256;

		// Create a test divisor
		SignedInteger32bits testDivisor_2 = 100;

		// Perform the divison
		DivisonResultSignedInteger32bits testResult_2 = Divison( testDividend_2, testDivisor_2 );

		// Check that the result is correct
		Assert_Test( testResult_2.Quotient() == 2 );
		Assert_Test( testResult_2.Remainder() == 56 );

		// Create a test dividend
		SignedInteger64bits testDividend_3 = 256875860;

		// Create a test divisor
		SignedInteger64bits testDivisor_3 = 100;

		// Perform the divison
		DivisonResultSignedInteger64bits testResult_3 = Divison( testDividend_3, testDivisor_3 );

		// Check that the result is correct
		Assert_Test( testResult_3.Quotient() == 2568758 );
		Assert_Test( testResult_3.Remainder() == 60 );

		// Perform the divison
		testResult_3 = Divison( -testDividend_3, testDivisor_3 );

		// Check that the result is correct
		Assert_Test( testResult_3.Quotient() == -2568758 );
		Assert_Test( testResult_3.Remainder() == -60 );

		// UNSIGNED :

		// Create a test dividend
		UnsignedInteger8bits testDividend_4 = 89;

		// Create a test divisor
		UnsignedInteger8bits testDivisor_4 = 89;

		// Perform the divison
		DivisonResultUnsignedInteger8bits testResult_4 = Divison( testDividend_4, testDivisor_4 );

		// Check that the result is correct
		Assert_Test( testResult_4.Quotient() == 1 );
		Assert_Test( testResult_4.Remainder() == 0 );

		// Create a test dividend
		UnsignedInteger16bits testDividend_5 = 1000;

		// Create a test divisor
		UnsignedInteger16bits testDivisor_5 = 101;

		// Perform the divison
		DivisonResultUnsignedInteger16bits testResult_5 = Divison( testDividend_5, testDivisor_5 );

		// Check that the result is correct
		Assert_Test( testResult_5.Quotient() == 9 );
		Assert_Test( testResult_5.Remainder() == 91 );

		// Create a test dividend
		UnsignedInteger32bits testDividend_6 = 256;

		// Create a test divisor
		UnsignedInteger32bits testDivisor_6 = 100;

		// Perform the divison
		DivisonResultUnsignedInteger32bits testResult_6 = Divison( testDividend_6, testDivisor_6 );

		// Check that the result is correct
		Assert_Test( testResult_6.Quotient() == 2 );
		Assert_Test( testResult_6.Remainder() == 56 );

		// Create a test dividend
		UnsignedInteger64bits testDividend_7 = 256875860;

		// Create a test divisor
		UnsignedInteger64bits testDivisor_7 = 100;

		// Perform the divison
		DivisonResultUnsignedInteger64bits testResult_7 = Divison( testDividend_7, testDivisor_7 );

		// Check that the result is correct
		Assert_Test( testResult_7.Quotient() == 2568758 );
		Assert_Test( testResult_7.Remainder() == 60 );
	}

)  //  End of debug tool



}  //  Namespace CentralProcessingUnit


}  //  Namespace Universe