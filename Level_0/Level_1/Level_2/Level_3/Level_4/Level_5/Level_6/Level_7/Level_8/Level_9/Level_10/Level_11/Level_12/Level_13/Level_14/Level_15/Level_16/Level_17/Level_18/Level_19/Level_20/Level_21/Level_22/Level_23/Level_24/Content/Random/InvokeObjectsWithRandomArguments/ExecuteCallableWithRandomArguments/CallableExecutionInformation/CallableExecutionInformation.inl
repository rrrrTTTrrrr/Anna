//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< typename ReturnType, typename... ArgumentTypes >
inline CallableExecutionInformation< ReturnType ( ArgumentTypes... ) >::CallableExecutionInformation() :
	member_arguments(),
	member_returnValue(),
	member_wasExceptionThrown( false ),
	member_errorMessage()
{}


template< typename ReturnType, typename... ArgumentTypes >
inline CallableExecutionInformation< ReturnType ( ArgumentTypes... ) >::CallableExecutionInformation( const SelfType& other ) :
	member_arguments( other.member_arguments ),
	member_returnValue( other.member_returnValue ),
	member_wasExceptionThrown( other.member_wasExceptionThrown ),
	member_errorMessage( other.member_errorMessage )
{}


template< typename ReturnType, typename... ArgumentTypes >
template< typename UniversalReferenceTupleWithArgumentsType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceTupleWithArgumentsType, Memory::Tuple< ArgumentTypes... > >::Result == true )
inline void CallableExecutionInformation< ReturnType ( ArgumentTypes... ) >::AddArguments( UniversalReferenceTupleWithArgumentsType&& arguments )
{
	// Set the arguments
	member_arguments = ForwardUniversalReference< UniversalReferenceTupleWithArgumentsType >( arguments );
}


template< typename ReturnType, typename... ArgumentTypes >
template< typename UniversalReferenceReturnType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceReturnType, ReturnType >::Result == true )
inline void CallableExecutionInformation< ReturnType ( ArgumentTypes... ) >::AddReturnValue( UniversalReferenceReturnType&& returnValue )
{
	// Set the return value
	member_returnValue = ForwardUniversalReference< UniversalReferenceReturnType >( returnValue );
}


template< typename ReturnType, typename... ArgumentTypes >
inline void CallableExecutionInformation< ReturnType ( ArgumentTypes... ) >::AddWasExceptionThrown( const Boolean wasExceptionThrown )
{
	// Set the boolean to true in case an exception was thrown
	member_wasExceptionThrown = wasExceptionThrown;
}


template< typename ReturnType, typename... ArgumentTypes >
template< Concepts::String UniversalReferenceStringType >
inline void CallableExecutionInformation< ReturnType ( ArgumentTypes... ) >::AddExceptionErrorMessage( UniversalReferenceStringType&& errorMessage )
{
	// Set the error message of the exception, if one was thrown
	member_errorMessage = ForwardUniversalReference< UniversalReferenceStringType >( errorMessage );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< typename ReturnType, typename... ArgumentTypes >
inline Boolean CallableExecutionInformation< ReturnType ( ArgumentTypes... ) >::operator==( const SelfType& other ) const
{
	// Compare the instances and return the result
	return ( ( member_arguments == other.member_arguments ) && ( member_returnValue == other.member_returnValue ) && ( member_wasExceptionThrown == other.member_wasExceptionThrown ) && ( member_errorMessage == other.member_errorMessage ) );
}


template< typename ReturnType, typename... ArgumentTypes >
inline Boolean CallableExecutionInformation< ReturnType ( ArgumentTypes... ) >::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - No arguments to function   ************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< typename ReturnType >
inline CallableExecutionInformation< ReturnType () >::CallableExecutionInformation() :
	member_returnValue(),
	member_wasExceptionThrown( false ),
	member_errorMessage()
{}


template< typename ReturnType >
inline CallableExecutionInformation< ReturnType () >::CallableExecutionInformation( const SelfType& other ) :
	member_returnValue( other.member_returnValue ),
	member_wasExceptionThrown( other.member_wasExceptionThrown ),
	member_errorMessage( other.member_errorMessage )
{}


template< typename ReturnType >
template< typename UniversalReferenceReturnType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceReturnType, ReturnType >::Result == true )
inline void CallableExecutionInformation< ReturnType () >::AddReturnValue( UniversalReferenceReturnType&& returnValue )
{
	// Set the return value
	member_returnValue = ForwardUniversalReference< UniversalReferenceReturnType >( returnValue );
}


template< typename ReturnType >
inline void CallableExecutionInformation< ReturnType () >::AddWasExceptionThrown( const Boolean wasExceptionThrown )
{
	// Set the boolean to true in case an exception was thrown
	member_wasExceptionThrown = wasExceptionThrown;
}


template< typename ReturnType >
template< Concepts::String UniversalReferenceStringType >
inline void CallableExecutionInformation< ReturnType () >::AddExceptionErrorMessage( UniversalReferenceStringType&& errorMessage )
{
	// Set the error message of the exception, if one was thrown
	member_errorMessage = ForwardUniversalReference< UniversalReferenceStringType >( errorMessage );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< typename ReturnType >
inline Boolean CallableExecutionInformation< ReturnType () >::operator==( const SelfType& other ) const
{
	// Compare the instances and return the result
	return ( ( member_returnValue == other.member_returnValue ) && ( member_wasExceptionThrown == other.member_wasExceptionThrown ) && ( member_errorMessage == other.member_errorMessage ) );
}


template< typename ReturnType >
inline Boolean CallableExecutionInformation< ReturnType () >::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ******************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - No return value   ****************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< typename... ArgumentTypes >
inline CallableExecutionInformation< void ( ArgumentTypes... ) >::CallableExecutionInformation() :
	member_arguments(),
	member_wasExceptionThrown( false ),
	member_errorMessage()
{}


template< typename... ArgumentTypes >
inline CallableExecutionInformation< void ( ArgumentTypes... ) >::CallableExecutionInformation( const SelfType& other ) :
	member_arguments( other.member_arguments ),
	member_wasExceptionThrown( other.member_wasExceptionThrown ),
	member_errorMessage( other.member_errorMessage )
{}


template< typename... ArgumentTypes >
template< typename UniversalReferenceTupleWithArgumentsType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceTupleWithArgumentsType, Memory::Tuple< ArgumentTypes... > >::Result == true )
inline void CallableExecutionInformation< void ( ArgumentTypes... ) >::AddArguments( UniversalReferenceTupleWithArgumentsType&& arguments )
{
	// Set the arguments
	member_arguments = ForwardUniversalReference< UniversalReferenceTupleWithArgumentsType >( arguments );
}


template< typename... ArgumentTypes >
inline void CallableExecutionInformation< void ( ArgumentTypes... ) >::AddWasExceptionThrown( const Boolean wasExceptionThrown )
{
	// Set the boolean to true in case an exception was thrown
	member_wasExceptionThrown = wasExceptionThrown;
}


template< typename... ArgumentTypes >
template< Concepts::String UniversalReferenceStringType >
inline void CallableExecutionInformation< void ( ArgumentTypes... ) >::AddExceptionErrorMessage( UniversalReferenceStringType&& errorMessage )
{
	// Set the error message of the exception, if one was thrown
	member_errorMessage = ForwardUniversalReference< UniversalReferenceStringType >( errorMessage );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< typename... ArgumentTypes >
inline Boolean CallableExecutionInformation< void ( ArgumentTypes... ) >::operator==( const SelfType& other ) const
{
	// Compare the instances and return the result
	return ( ( member_arguments == other.member_arguments ) && ( member_wasExceptionThrown == other.member_wasExceptionThrown ) && ( member_errorMessage == other.member_errorMessage ) );
}


template< typename... ArgumentTypes >
inline Boolean CallableExecutionInformation< void ( ArgumentTypes... ) >::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ****************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - No arguments to function and return value   ****************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline CallableExecutionInformation< void () >::CallableExecutionInformation() :
	member_wasExceptionThrown( false ),
	member_errorMessage()
{}


inline CallableExecutionInformation< void () >::CallableExecutionInformation( const SelfType& other ) :
	member_wasExceptionThrown( other.member_wasExceptionThrown ),
	member_errorMessage( other.member_errorMessage )
{}


inline void CallableExecutionInformation< void () >::AddWasExceptionThrown( const Boolean wasExceptionThrown )
{
	// Set the boolean to true in case an exception was thrown
	member_wasExceptionThrown = wasExceptionThrown;
}


template< Concepts::String UniversalReferenceStringType >
inline void CallableExecutionInformation< void () >::AddExceptionErrorMessage( UniversalReferenceStringType&& errorMessage )
{
	// Set the error message of the exception, if one was thrown
	member_errorMessage = ForwardUniversalReference< UniversalReferenceStringType >( errorMessage );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



inline Boolean CallableExecutionInformation< void () >::operator==( const SelfType& other ) const
{
	// Compare the instances and return the result
	return ( ( member_wasExceptionThrown == other.member_wasExceptionThrown ) && ( member_errorMessage == other.member_errorMessage ) );
}


inline Boolean CallableExecutionInformation< void () >::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< typename ReturnType COMMA typename... ArgumentTypes >
	inline void CallableExecutionInformation< ReturnType ( ArgumentTypes... ) >::UnitTest()
	{}

)  //  End of debug tool



}  //  Namespace Random


}  //  Namespace Universe