//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



	inline Member::Member() :
		member_name(),
		member_encapsulationClassification(),
		member_isConstantExpression( false ),
		member_isConstant( false ),
		member_isVolatile( false ),
		member_isStatic( false )
	{}


	inline Member::Member( const Language::String& name, const Language::String& encapsulationClassification, Boolean isConstantExpression, Boolean isConstant, Boolean isVolatile, Boolean isStatic ) :
		member_name( name ),
		member_encapsulationClassification( encapsulationClassification ),
		member_isConstantExpression( isConstantExpression ),
		member_isConstant( isConstant ),
		member_isVolatile( isVolatile ),
		member_isStatic( isStatic )
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	    // instance is ready to be used
		AssertValueIsLargerThenZero( name.Size() );
		AssertValueIsLargerThenZero( encapsulationClassification.Size() );
	}



// *********************************************************************************   TESTING   ********************************************************************************



	DEBUG_TOOL(

		void Member::UnitTest()
		{}

	)  //  End of debug tool



	}  //  Namespace Meta

}  //  Namespace Universe



#endif  // MEMBER