//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< typename ReturnType >
inline ThreadOfExecutionResult< ReturnType >::ThreadOfExecutionResult() :
	member_wasExceptionThrown( false ),
	member_errorMessage(),
	member_returnValue()
{}


template< typename ReturnType >
inline ThreadOfExecutionResult< ReturnType >::ThreadOfExecutionResult( ReturnType&& returnValue, const Boolean wasExceptionThrown, const Language::String& errorMessage ) :
	member_wasExceptionThrown( wasExceptionThrown ),
	member_errorMessage( errorMessage ),
	member_returnValue( TakeResourcesAndLeaveInstanceInDefaultState( returnValue ) )
{}


template< typename ReturnType >
inline ThreadOfExecutionResult< ReturnType >::ThreadOfExecutionResult( const SelfType& other ) :
	member_wasExceptionThrown( other.member_wasExceptionThrown ),
	member_errorMessage( other.member_errorMessage ),
	member_returnValue( other.member_returnValue )
{}




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ********************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = void    ******************************************************* //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //




inline ThreadOfExecutionResult< void >::ThreadOfExecutionResult() :
	member_wasExceptionThrown( false ),
	member_errorMessage()
{}


inline ThreadOfExecutionResult< void >::ThreadOfExecutionResult( const Boolean wasExceptionThrown, const Language::String& errorMessage ) :
	member_wasExceptionThrown( wasExceptionThrown ),
	member_errorMessage( errorMessage )
{}


inline ThreadOfExecutionResult< void >::ThreadOfExecutionResult( const SelfType& other ) :
	member_wasExceptionThrown( other.member_wasExceptionThrown ),
	member_errorMessage( other.member_errorMessage )
{}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< typename ReturnType >
	inline void ThreadOfExecutionResult< ReturnType >::UnitTest()
	{}

)  //  End of debug tool



}  //  Namespace MultiThread

}  //  Namespace Universe
