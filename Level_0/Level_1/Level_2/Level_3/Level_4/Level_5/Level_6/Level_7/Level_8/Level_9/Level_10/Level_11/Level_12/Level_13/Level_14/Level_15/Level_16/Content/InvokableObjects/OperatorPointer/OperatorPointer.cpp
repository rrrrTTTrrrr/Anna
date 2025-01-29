namespace Universe 
{



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	void OperatorPointer::UnitTest()
	{
		// Create 2 test objects to use in the operator invokation
		Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits > testTestObjectWithAllOperatorsOverloaded_0( 20 );
		Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits > testTemplateObjectWithAllOperatorsOverloaded( 10 );

		// Invoke all the operators and assert the result
		Assert_Test( ConsiderAsOneArgument( Addition< UnsignedInteger32bits, Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits >, Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits > >( testTestObjectWithAllOperatorsOverloaded_0, testTemplateObjectWithAllOperatorsOverloaded ) == 30 ) );
		Assert_Test( ConsiderAsOneArgument( Subtraction< UnsignedInteger32bits, Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits >, Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits > >( testTestObjectWithAllOperatorsOverloaded_0, testTemplateObjectWithAllOperatorsOverloaded ) == 10 ) );
		Assert_Test( ConsiderAsOneArgument( Multiplication< UnsignedInteger32bits, Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits >, Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits > >( testTestObjectWithAllOperatorsOverloaded_0, testTemplateObjectWithAllOperatorsOverloaded ) == 200 ) );
		Assert_Test( ConsiderAsOneArgument( Division< UnsignedInteger32bits, Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits >, Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits > >( testTestObjectWithAllOperatorsOverloaded_0, testTemplateObjectWithAllOperatorsOverloaded ) == 2 ) );
		Assert_Test( ConsiderAsOneArgument( Modulo< UnsignedInteger32bits, Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits >, Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits > >( testTestObjectWithAllOperatorsOverloaded_0, testTemplateObjectWithAllOperatorsOverloaded ) == 0 ) );

		Assert_Test( ConsiderAsOneArgument( AssignmentAddition< Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits >, Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits > >( testTestObjectWithAllOperatorsOverloaded_0, testTemplateObjectWithAllOperatorsOverloaded ).GetInteger() == 30 ) );
		Assert_Test( ConsiderAsOneArgument( AssignmentSubtraction< Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits >, Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits > >( testTestObjectWithAllOperatorsOverloaded_0, testTemplateObjectWithAllOperatorsOverloaded ).GetInteger() == 20 ) );
		Assert_Test( ConsiderAsOneArgument( AssignmentMultiplication< Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits >, Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits > >( testTestObjectWithAllOperatorsOverloaded_0, testTemplateObjectWithAllOperatorsOverloaded ).GetInteger() == 200 ) );
		Assert_Test( ConsiderAsOneArgument( AssignmentDivision< Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits >, Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits > >( testTestObjectWithAllOperatorsOverloaded_0, testTemplateObjectWithAllOperatorsOverloaded ).GetInteger() == 20 ) );
		Assert_Test( ConsiderAsOneArgument( AssignmentModulo< Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits >, Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits > >( testTestObjectWithAllOperatorsOverloaded_0, testTemplateObjectWithAllOperatorsOverloaded ).GetInteger() == 0 ) );

		// Create 2 test objects to use in the relational operator invokation
		Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits > testTestObjectWithAllOperatorsOverloaded_2( 20 );
		Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits > testTestObjectWithAllOperatorsOverloaded_3( 10 );

		Assert_Test( ConsiderAsOneArgument( Equal< Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits >, Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits > >( testTestObjectWithAllOperatorsOverloaded_2, testTestObjectWithAllOperatorsOverloaded_3 ) == false ) );
		Assert_Test( ConsiderAsOneArgument( NonEqual< Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits >, Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits > >( testTestObjectWithAllOperatorsOverloaded_2, testTestObjectWithAllOperatorsOverloaded_3 ) == true ) );
		Assert_Test( ConsiderAsOneArgument( Larger< Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits >, Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits > >( testTestObjectWithAllOperatorsOverloaded_2, testTestObjectWithAllOperatorsOverloaded_3 ) == true ) );
		Assert_Test( ConsiderAsOneArgument( Smaller< Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits >, Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits > >( testTestObjectWithAllOperatorsOverloaded_2, testTestObjectWithAllOperatorsOverloaded_3 ) == false ) );
		Assert_Test( ConsiderAsOneArgument( LargerOrEqual< Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits >, Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits > >( testTestObjectWithAllOperatorsOverloaded_2, testTestObjectWithAllOperatorsOverloaded_3 ) == true ) );
		Assert_Test( ConsiderAsOneArgument( SmallerOrEqual< Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits >, Test::TemplateObjectWithAllOperatorsOverloaded< UnsignedInteger32bits > >( testTestObjectWithAllOperatorsOverloaded_2, testTestObjectWithAllOperatorsOverloaded_3 ) == false ) );
	}

)  //  End of debug tool



}  //  Namespace Universe