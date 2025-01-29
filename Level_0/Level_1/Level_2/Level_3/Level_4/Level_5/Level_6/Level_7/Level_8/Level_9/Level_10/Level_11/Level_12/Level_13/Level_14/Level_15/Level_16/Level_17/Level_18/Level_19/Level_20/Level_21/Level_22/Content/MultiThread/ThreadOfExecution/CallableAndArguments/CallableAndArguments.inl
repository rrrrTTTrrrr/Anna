//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< typename ReturnType, typename... ArgumentsTypes >
inline CallableAndArguments< ReturnType, ArgumentsTypes... >::CallableAndArguments( const Callable< FunctionSignatureType >& callable, ArgumentsTypes... arguments ) :
	member_callablePointer( &callable ),
	member_argumentsTuple( arguments... )
{}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< typename ReturnType COMMA typename... ArgumentsTypes >
	void CallableAndArguments< ReturnType COMMA ArgumentsTypes... >::UnitTest()
	{}

)  //  End of debug tool



}  //  Namespace MultiThread


}  //  Namespace Universe