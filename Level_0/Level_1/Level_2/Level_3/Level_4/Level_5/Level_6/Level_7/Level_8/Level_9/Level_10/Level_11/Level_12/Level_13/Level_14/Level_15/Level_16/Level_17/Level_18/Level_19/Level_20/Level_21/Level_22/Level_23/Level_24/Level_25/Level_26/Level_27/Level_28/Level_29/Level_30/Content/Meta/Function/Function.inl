//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



	inline Function::Function() :
		member_name(),
		member_containingFileAbsolutePath(),
		member_namespace(),
		member_isInline( false ),
		member_isConstantExpression( false ),
		member_canThrowException( false )
	{}


	inline Function( const Language::String& name, const Language::String& containingFileAbsolutePath, const Language::String& namespaceName, Boolean isInline, Boolean isConstantExpression, Boolean canThrowException ) :
		member_name( name ),
		member_containingFileAbsolutePath( containingFileAbsolutePath ),
		member_namespace( namespaceName ),
		member_isInline( isInline ),
		member_isConstantExpression( isConstantExpression ),
		member_canThrowException( canThrowException )
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	    // instance is ready to be used
		AssertValueIsLargerThenZero( name.Size() );
		AssertValueIsLargerThenZero( containingFileAbsolutePath.Size() );
		AssertValueIsLargerThenZero( namespaceName.Size() );
	}



// *********************************************************************************   TESTING   ********************************************************************************



	DEBUG_TOOL(

		void Function::UnitTest()
		{}

	)  //  End of debug tool



	}  //  Namespace Meta

}  //  Namespace Universe



#endif  // FUNCTION