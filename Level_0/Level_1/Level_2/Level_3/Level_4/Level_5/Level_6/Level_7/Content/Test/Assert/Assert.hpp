namespace Universe
{


namespace Test
{



// Use this macro to assert that the result of the expression is true, inside an object test method, and if it is false throw an exception
//
#define Assert_Test( Expression ) Error::Assert< Error::Exception >::True( Expression, __FILE__, __FUNCTION__, __LINE__, "Test failed" )


// Use this macro to assert that the result of the expression is true, inside an object test method, and if it is false throw an exception
//
#define AssertExceptionWasThrown_Test( InvokableObject ) Boolean wasExceptionThrown = false; try { InvokableObject; } catch ( const Error::Exception& exception ) { wasExceptionThrown = true; } Error::Assert< Error::Exception >::True( wasExceptionThrown, __FILE__, __FUNCTION__, __LINE__, "Test failed - Exception was not thrown" )


// Use this macro to assert that the result of the expression is true, inside an object test method, and if it is false throw an exception. This
// second macro to test for exception is needed since, the main macro defines a varaible, and therefore can only be used once inside a specific
// context. Therefore the usage shold be :
//
//		// If only time, or for the first time
//		AssertExceptionWasThrown_Test( ... )
//
//		// And everytime from there use this macro
//		AssertExceptionWasThrown_Next_Test( ... )
//
#define AssertExceptionWasThrown_Next_Test( InvokableObject ) wasExceptionThrown = false; try { InvokableObject; } catch ( const Error::Exception& exception ) { wasExceptionThrown = true; } Error::Assert< Error::Exception >::True( wasExceptionThrown, __FILE__, __FUNCTION__, __LINE__, "Test failed - Exception was not thrown" )


// Use this macro to assert that the result of the expression is true, inside an object test method, and if it is false throw an exception
//
#define AssertCanBeUsedAsConstantExpression( Value ) static_assert( ( Value == Value ), "The given value can not be used as a constant expression" )



}  //  Namespace Test


}  //  Namespace Universe
