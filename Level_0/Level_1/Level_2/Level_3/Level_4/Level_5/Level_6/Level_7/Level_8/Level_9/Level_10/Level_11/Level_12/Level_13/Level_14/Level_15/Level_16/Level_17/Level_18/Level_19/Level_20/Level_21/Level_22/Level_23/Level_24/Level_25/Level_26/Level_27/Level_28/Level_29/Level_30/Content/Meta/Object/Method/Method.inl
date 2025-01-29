//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



	inline Method::Method() :
		member_name(),
		member_encapsulationClassification(),
		member_isInline( false ),
		member_isConstantExpression( false ),
		member_canThrowException( false ),
		member_isConstant( false ),
		member_isStatic( false ),
		member_isVirtual( false ),
		member_doesOverride( false ),
		member_isPureVirtual( false )
	{}


	inline Method::Method( const Language::String& name, const Language::String& encapsulationClassification, Boolean isInline, Boolean isConstantExpression, Boolean canThrowException, Boolean isConstant, Boolean isStatic, Boolean isVirtual, Boolean doesOverride, Boolean isPureVirtual ) :
		member_name( name ),
		member_encapsulationClassification( encapsulationClassification ),
		member_isInline( isInline ),
		member_isConstantExpression( isConstantExpression ),
		member_canThrowException( canThrowException ),
		member_isConstant( isConstant ),
		member_isStatic( isStatic ),
		member_isVirtual( isVirtual ),
		member_doesOverride( doesOverride ),
		member_isPureVirtual( isPureVirtual )
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	    // instance is ready to be used
		AssertValueIsLargerThenZero( name.Size() );
		AssertValueIsLargerThenZero( encapsulationClassification.Size() );
	}



// *********************************************************************************   TESTING   ********************************************************************************



	DEBUG_TOOL(

		void Method::UnitTest()
		{}

	)  //  End of debug tool



	}  //  Namespace Meta

}  //  Namespace Universe



#endif  // METHOD