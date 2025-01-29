namespace Universe
{


namespace Error
{



// In the C programming language, data types are declarations for memory locations or variables that determine the characteristics of the data that 
// may be stored and the methods ( operations ) of processing that are permitted involving them.
//
// The C language provides basic arithmetic types, such as integer and real number types, and syntax to build array and compound types. Several 
// headers in the C standard library contain definitions of support types, that have additional properties, such as providing storage with an 
// exact size, independent of the implementation



// Class Information :
//
//  Purpose :
//
//		This object purpose is to allow better interface for checking error conditions and reporting them. It should not be used directly but through the
//		macros provided above
//
//  Description :
//
//		1. This object is used only to wrap some static methods, which can be used without any instance of the object. Then this object is
//		   an interface which conatins only static methods, and does not need to never be instantied
//
//		2. This object has all the methods to create, destory, copy and move disabled to ensure that no instances of it will be created
//
//		3. Template arguments :
//
//			1. Type -
//
//  Possible errors :
//
//		Too many to count
//
template< typename ExceptionType >
class Assert
{
public:


    // The following are type definitions of the object and all the provided template arguments :


	// Create a type definition for the object itself
	using ObjectType = Assert< ExceptionType >;


	// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions
	// only have access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only
	// purpose then of declaring a static function is when a private static data member needs to be manipulated, or some functionality needed that
	// does not involve the non static data members


    // Method Information :
    //
    //  Description :
    //
    //      Use to check if the expression result is not true, then throw an exception
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. expressionResult - the result of the expression which could be true or false
    //          2. fileName - an ascii string with the file name from which the exception was thrown
    //          3. functionName - an ascii string with the function name from which the exception was thrown
    //          4. lineNumber - the number of line from which the exception was thrown
    //          4. errorMessage - the memory address of the user error message
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      NONE
    //
    //  Expectations :
    //
    //      1. The given pointer to the file name should not be NULL
    //      2. The given pointer to the function name should not be NULL
    //      3. The given pointer to the error message should not be NULL
    //      4. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    static inline void True( const Boolean expressionResult, const AsciiCharacter* const fileName, const AsciiCharacter* const functionName, const SignedInteger32bits lineNumber, const AsciiCharacter* const errorMessage );



    // Method Information :
    //
    //  Description :
    //
    //      Use to check if the expression result is not true, then throw an exception. In case the expression result is true, it 
    //      will return the value given
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. instanceToAssignInCaseAssertionPassed - a constant refernce to the instance to return if the expression result is true
    //          2. expressionResult - the result of the expression which could be true or false
    //          3. fileName - an ascii string with the file name from which the exception was thrown
    //          4. functionName - an ascii string with the function name from which the exception was thrown
    //          5. lineNumber - the number of line from which the exception was thrown
    //          6. errorMessage - the memory address of the user error message
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      NONE
    //
    //  Expectations :
    //
    //      1. The given pointer to the file name should not be NULL
    //      2. The given pointer to the function name should not be NULL
    //      3. The given pointer to the error message should not be NULL
    //      4. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename AnyType >
    EnsureRetrunValueIsUsed static inline AnyType AssignOnlyIfTrue( AnyType instanceToAssignInCaseAssertionPassed, const Boolean expressionResult, const AsciiCharacter* const fileName, const AsciiCharacter* const functionName, const SignedInteger32bits lineNumber, const AsciiCharacter* const errorMessage );


	DEBUG_TOOL(

		// This part of the object is dedicated for testing :


		// Method Information :
		//
		//  Description :
		//
		//      This method is used to test the object. It is not part of the implementation, it is only used to find problems with the code
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          NONE
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//			NONE
		//
		//  Expectations :
		//
		//		Please let the test pass lord!!
		//
		//  Possible errors :
		//
		//		It says there are no problems, which is even scarier, did I just wrote a working code??
		//
		static void UnitTest() __attribute__ (( __unused__ ));

	)  //  End of debug tool


private:


	// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
	NoInstances( Assert );


};  //  Class Assert



// The following macros wrap all the required functionality of the exceptions and assert to make as much things automtaic and they should be used to
// test for error situations :


// Use this macro to assert that the result of the expression is true, and if it is false throw an exception
//
#define Assert( Expression, ErrorMessage ) Error::Assert< Error::Exception >::True( Expression, __FILE__, __FUNCTION__, __LINE__, ErrorMessage )


// Use this macro to assert that the pointer is not NULL, and if it is throw an exception
//
#define AssertPointerIsNotNull( Pointer ) Error::Assert< Error::Exception >::True( ( Pointer != nullptr ), __FILE__, __FUNCTION__, __LINE__, "The given pointer is NULL" )


// Use this macro to assert that the pointer is NULL, and if it is not throw an exception
//
//
// BE CAREFUL - RETURN TRUE IF THE POINTER IS NULL
//
#define AssertPointerIsNull( Pointer ) Error::Assert< Error::Exception >::True( ( Pointer == nullptr ), __FILE__, __FUNCTION__, __LINE__, "The given pointer is not NULL" )


// Use this macro to assert that the given value is not 0, and if it is throw an exception
//
#define AssertValuesAreEqual( FirstValue, SecondValue ) Error::Assert< Error::Exception >::True( ( FirstValue == SecondValue ), __FILE__, __FUNCTION__, __LINE__, "The values should be equal" )


// Use this macro to assert that the given value is larger then 0, and if it is not throw an exception
//
#define AssertValueIsLargerThenZero( Value ) Error::Assert< Error::Exception >::True( ( Value > 0 ), __FILE__, __FUNCTION__, __LINE__, "The value should be larger then 0" )


// Use this macro to assert that the given value is not 0, and if it is throw an exception
//
#define AssertValueIsNotZero( Value ) Error::Assert< Error::Exception >::True( ( Value != 0 ), __FILE__, __FUNCTION__, __LINE__, "The value should not be 0" )


// Use this macro to assert that the given value is 0, and if it is throw an exception
//
#define AssertValueIsZero( Value ) Error::Assert< Error::Exception >::True( ( Value == 0 ), __FILE__, __FUNCTION__, __LINE__, "The value should be 0" )


// Use this macro to assert that the value is smaller then a certain limit, and if not throw an exception
//
#define AssertValueIsBelowCertainLimit( Value, Limit ) Error::Assert< Error::Exception >::True( ( Value < Limit ), __FILE__, __FUNCTION__, __LINE__, "The given value should be smaller then the limit" )


// Use this macro to assert that the value is equal or smaller then a certain limit, and if not throw an exception
//
#define AssertValueIsEqualOrBelowCertainLimit( Value, Limit ) Error::Assert< Error::Exception >::True( ( Value <= Limit ), __FILE__, __FUNCTION__, __LINE__, "The given value should be equal or smaller then the limit" )


// Use this macro to assert that the value is larger then a certain limit, and if not throw an exception
//
#define AssertValueIsAboveCertainLimit( Value, Limit ) Error::Assert< Error::Exception >::True( ( Value > Limit ), __FILE__, __FUNCTION__, __LINE__, "The given value should be larger then the limit" )


// Use this macro to assert that the value is equal or larger then a certain limit, and if not throw an exception
//
#define AssertValueIsEqualOrAboveCertainLimit( Value, Limit ) Error::Assert< Error::Exception >::True( ( Value >= Limit ), __FILE__, __FUNCTION__, __LINE__, "The given value should be equal or larger then the limit" )


// Use this macro to assert that the value is in the required range, and if not throw an exception
//
#define AssertValueIsInRange( Value, MinimumRangeValue, MaximumRangeValue ) Error::Assert< Error::Exception >::True( ( ( Value >= MinimumRangeValue ) && ( Value <= MaximumRangeValue ) ), __FILE__, __FUNCTION__, __LINE__, "The given value is not in the range" )


// Use this macro to assert that the value is in the required range the minimum value of the range excluded, and if not throw an exception
//
#define AssertValueIsInRangeWhenMinimumValueOfTheRangeIsExcluded( Value, MinimumRangeValue, MaximumRangeValue ) Error::Assert< Error::Exception >::True( ( ( Value > MinimumRangeValue ) && ( Value <= MaximumRangeValue ) ), __FILE__, __FUNCTION__, __LINE__, "The given value is not in the range" )


// Use this macro to assert that the value is in the required range the maximum value of the range excluded, and if not throw an exception
//
#define AssertValueIsInRangeWhenMaximumValueOfTheRangeIsExcluded( Value, MinimumRangeValue, MaximumRangeValue ) Error::Assert< Error::Exception >::True( ( ( Value >= MinimumRangeValue ) && ( Value < MaximumRangeValue ) ), __FILE__, __FUNCTION__, __LINE__, "The given value is not in the range" )


// Use this macro to assert that the value is in the required range, where the minimum and maximum values of the range are excluded, and if 
// not throw an exception
//
#define AssertValueIsInRangeWhenMinimumAndMaximumValuesOfTheRangeAreExcluded( Value, MinimumRangeValue, MaximumRangeValue ) Error::Assert< Error::Exception >::True( ( ( Value >= MinimumRangeValue ) && ( Value < MaximumRangeValue ) ), __FILE__, __FUNCTION__, __LINE__, "The given value is not in the range" )


// Use this macro to assert that the sum of two values is equal or smaller then a certain limit, and if not throw an exception
//
#define AssertSumOfTheValuesIsEqualOrBelowCertainLimit( FirstValue, SecondValue, Limit ) Error::Assert< Error::Exception >::True( ( ( FirstValue + SecondValue ) <= Limit ), __FILE__, __FUNCTION__, __LINE__, "The sum of the two values should be equal or smaller then the limit" )


// Use this macro to assert that the given value is a power of 2, and if it is not throw an exception. Note - should only be used after level 10
//
#define AssertValueIsPowerOfTwo( Value ) Error::Assert< Error::Exception >::True( ( Arithmetics::IsPowerOfTwo< typename RemoveQualifiers< decltype( Value ) >::Type >( Value ) == true ), __FILE__, __FUNCTION__, __LINE__, "The value must be a power of 2" )


// Use this macro to assert that the value is a digit, and if not throw an exception
//
#define AssertValueIsDigit( Value ) Error::Assert< Error::Exception >::True( ( ( Value >= '0' ) || ( Value <= '9' ) ), __FILE__, __FUNCTION__, __LINE__, "The value is not a digit" )


// Use this macro to assert that the value is a smallr letter 'a-z', and if not throw an exception
//
#define AssertValueIsSmallLetter( Value ) Error::Assert< Error::Exception >::True( ( ( Value >= 'a' ) || ( Value <= 'z' ) ), __FILE__, __FUNCTION__, __LINE__, "The value is not a small letter" )


// Use this macro to assert that the value is a capital letter 'A-Z', and if not throw an exception
//
#define AssertValueIsCapitalLetter( Value ) Error::Assert< Error::Exception >::True( ( ( Value >= 'A' ) || ( Value <= 'Z' ) ), __FILE__, __FUNCTION__, __LINE__, "The value is not a capital letter" )


// Use this macro to assert that the value is a letter, either small or capital, and if not throw an exception
//
#define AssertValueIsLetter( Value ) Error::Assert< Error::Exception >::True( ( ( ( Value >= 'a' ) && ( Value <= 'z' ) ) || ( ( Value >= 'A' ) && ( Value <= 'Z' ) ) ), __FILE__, __FUNCTION__, __LINE__, "The value is not a letter" )



// The following macros allow to assert a condition on a value and only if the condition is met, assign the same value :


// Use this macro to assert that the result of the expression is true, and if it is false throw an exception
//
#define AssignOnlyIfAssertionPassed( Value, Expression, ErrorMessage ) Error::Assert< Error::Exception >::AssignOnlyIfTrue< decltype( Value ) >( Value, Expression, __FILE__, __FUNCTION__, __LINE__, ErrorMessage )


// Use this macro to assert that the pointer is not NULL, and if it is throw an exception
//
#define AssignOnlyIfPointerIsNotNULL( Pointer ) Error::Assert< Error::Exception >::AssignOnlyIfTrue< decltype( Pointer ) >( Pointer, ( Pointer != nullptr ), __FILE__, __FUNCTION__, __LINE__, "The given pointer is NULL" )


// Use this macro to assert that the given value is larger then 0, and if it is not throw an exception
//
#define AssignOnlyIfValueIsLargerThenZero( Value ) Error::Assert< Error::Exception >::AssignOnlyIfTrue< decltype( Value ) >( Value, ( Value > 0 ), __FILE__, __FUNCTION__, __LINE__, "The value should be larger then 0" )


// Use this macro to assert that the given value is not 0, and if it is throw an exception
//
#define AssignOnlyIfValueIsNotZero( Value ) Error::Assert< Error::Exception >::AssignOnlyIfTrue< decltype( Value ) >( Value, ( Value != 0 ), __FILE__, __FUNCTION__, __LINE__, "The value should not be 0" )


// Use this macro to assert that the value is smaller then a certain limit, and if not throw an exception
//
#define AssignOnlyIfValueIsBelowCertainLimit( Value, Limit ) Error::Assert< Error::Exception >::AssignOnlyIfTrue< decltype( Value ) >( Value, ( Value < Limit ), __FILE__, __FUNCTION__, __LINE__, "The given value should be smaller then the limit" )


// Use this macro to assert that the value is equal or smaller then a certain limit, and if not throw an exception
//
#define AssignOnlyIfValueIsEqualOrBelowCertainLimit( Value, Limit ) Error::Assert< Error::Exception >::AssignOnlyIfTrue< decltype( Value ) >( Value, ( Value <= Limit ), __FILE__, __FUNCTION__, __LINE__, "The given value should be equal or smaller then the limit" )


// Use this macro to assert that the value is equal or smaller then a certain limit, and if not throw an exception
//
#define AssignOnlyIfValueIsWithinRange( Value, RangeMinimum, RangeMaximum ) Error::Assert< Error::Exception >::AssignOnlyIfTrue< decltype( Value ) >( Value, ( ( Value >= RangeMinimum ) && ( Value <= RangeMaximum ) ), __FILE__, __FUNCTION__, __LINE__, "The given value should be in the range" )




// The following macros allow to assert a condition on a value and only if the condition is met, assign the another value :


// Use this macro to assert that the given value is larger then 0, and if it is not throw an exception
//
#define AssignOnlyIfValueToAssertIsLargerThenZero( ValueToAssign, ValueToAssert ) Error::Assert< Error::Exception >::AssignOnlyIfTrue< decltype( ValueToAssign ) >( ValueToAssign, ( ValueToAssert > 0 ), __FILE__, __FUNCTION__, __LINE__, "The value should be larger then 0" )


// Use this macro to assert that the given value is not 0, and if it is throw an exception
//
#define AssignOnlyIfValueToAssertIsNotZero( ValueToAssign, ValueToAssert ) Error::Assert< Error::Exception >::AssignOnlyIfTrue< decltype( ValueToAssign ) >( ValueToAssign, ( ValueToAssert != 0 ), __FILE__, __FUNCTION__, __LINE__, "The value should not be 0" )


// Use this macro to assert that the value is smaller then a certain limit, and if not throw an exception
//
#define AssignOnlyIfValueToAssertIsBelowCertainLimit( ValueToAssign, ValueToAssert, Limit ) Error::Assert< Error::Exception >::AssignOnlyIfTrue< decltype( ValueToAssign ) >( ValueToAssign, ( ValueToAssert < Limit ), __FILE__, __FUNCTION__, __LINE__, "The given value should be smaller then the limit" )


// Use this macro to assert that the value is equal or smaller then a certain limit, and if not throw an exception
//
#define AssignOnlyIfValueToAssertIsEqualOrBelowCertainLimit( ValueToAssign, ValueToAssert, Limit ) Error::Assert< Error::Exception >::AssignOnlyIfTrue< decltype( ValueToAssign ) >( ValueToAssign, ( ValueToAssert <= Limit ), __FILE__, __FUNCTION__, __LINE__, "The given value should be equal or smaller then the limit" )




// The following macros should be used in functions that can be executed during compile time or run time :


// Use this macro to assert that the result of the expression is true, and if it is false throw an exception
//
#define Assert_CompileTimeSupportedAsWell( Expression, ErrorMessage ) if consteval { if ( ( Expression ) == false ) { throw 0; } } else { Error::Assert< Error::Exception >::True( Expression, __FILE__, __FUNCTION__, __LINE__, ErrorMessage ); }


// Use this macro to assert that the given value is not 0, and if it is throw an exception
//
#define AssertValuesAreEqual_CompileTimeSupportedAsWell( FirstValue, SecondValue ) if consteval { if ( FirstValue != SecondValue ) { throw 0; } } else { Error::Assert< Error::Exception >::True( ( FirstValue == SecondValue ), __FILE__, __FUNCTION__, __LINE__, "The values should be equal" ); }


// Use this macro to assert that the given value is larger then 0, and if it is not throw an exception
//
#define AssertValueIsLargerThenZero_CompileTimeSupportedAsWell( Value ) if consteval { if ( Value <= 0 ) { throw 0; } } else { Error::Assert< Error::Exception >::True( ( Value > 0 ), __FILE__, __FUNCTION__, __LINE__, "The value should be larger then 0" ); }


// Use this macro to assert that the given value is not 0, and if it is throw an exception
//
#define AssertValueIsNotZero_CompileTimeSupportedAsWell( Value ) if consteval { if ( Value == 0 ) { throw 0; } } else { Error::Assert< Error::Exception >::True( ( Value != 0 ), __FILE__, __FUNCTION__, __LINE__, "The value should not be 0" ); }


// Use this macro to assert that the given value is 0, and if it is throw an exception
//
#define AssertValueIsZero_CompileTimeSupportedAsWell( Value ) if consteval { if ( Value != 0 ) { throw 0; } } else { Error::Assert< Error::Exception >::True( ( Value == 0 ), __FILE__, __FUNCTION__, __LINE__, "The value should be 0" ); }


// Use this macro to assert that the value is smaller then a certain limit, and if not throw an exception
//
#define AssertValueIsBelowCertainLimit_CompileTimeSupportedAsWell( Value, Limit ) if consteval { if ( Value >= Limit ) { throw 0; } } else { Error::Assert< Error::Exception >::True( ( Value < Limit ), __FILE__, __FUNCTION__, __LINE__, "The given value should be smaller then the limit" ); }


// Use this macro to assert that the value is equal or smaller then a certain limit, and if not throw an exception
//
#define AssertValueIsEqualOrBelowCertainLimit_CompileTimeSupportedAsWell( Value, Limit ) if consteval { if ( Value > Limit ) { throw 0; } } else { Error::Assert< Error::Exception >::True( ( Value <= Limit ), __FILE__, __FUNCTION__, __LINE__, "The given value should be equal or smaller then the limit" ); }


// Use this macro to assert that the value is larger then a certain limit, and if not throw an exception
//
#define AssertValueIsAboveCertainLimit_CompileTimeSupportedAsWell( Value, Limit ) if consteval { if ( Value <= Limit ) { throw 0; } } else { Error::Assert< Error::Exception >::True( ( Value > Limit ), __FILE__, __FUNCTION__, __LINE__, "The given value should be larger then the limit" ); }


// Use this macro to assert that the value is equal or larger then a certain limit, and if not throw an exception
//
#define AssertValueIsEqualOrAboveCertainLimit_CompileTimeSupportedAsWell( Value, Limit ) if consteval { if ( Value < Limit ) { throw 0; } } else { Error::Assert< Error::Exception >::True( ( Value >= Limit ), __FILE__, __FUNCTION__, __LINE__, "The given value should be equal or larger then the limit" ); }


// Use this macro to assert that the value is in the required range, and if not throw an exception
//
#define AssertValueIsInRange_CompileTimeSupportedAsWell( Value, MinimumRangeValue, MaximumRangeValue ) if consteval { if ( ( Value < MinimumRangeValue ) || ( Value > MaximumRangeValue ) ) { throw 0; } } else { Error::Assert< Error::Exception >::True( ( ( Value >= MinimumRangeValue ) && ( Value <= MaximumRangeValue ) ), __FILE__, __FUNCTION__, __LINE__, "The given value is not in the range" ); }


// Use this macro to assert that the value is in the required range the minimum value of the range excluded, and if not throw an exception
//
#define AssertValueIsInRangeWhenMinimumValueOfTheRangeIsExcluded_CompileTimeSupportedAsWell( Value, MinimumRangeValue, MaximumRangeValue ) if consteval { if ( ( Value <= MinimumRangeValue ) || ( Value > MaximumRangeValue ) ) { throw 0; } } else { Error::Assert< Error::Exception >::True( ( ( Value > MinimumRangeValue ) && ( Value <= MaximumRangeValue ) ), __FILE__, __FUNCTION__, __LINE__, "The given value is not in the range" ); }


// Use this macro to assert that the value is in the required range the maximum value of the range excluded, and if not throw an exception
//
#define AssertValueIsInRangeWhenMaximumValueOfTheRangeIsExcluded_CompileTimeSupportedAsWell( Value, MinimumRangeValue, MaximumRangeValue ) if consteval { if ( ( Value < MinimumRangeValue ) || ( Value >= MaximumRangeValue ) ) { throw 0; } } else { Error::Assert< Error::Exception >::True( ( ( Value >= MinimumRangeValue ) && ( Value < MaximumRangeValue ) ), __FILE__, __FUNCTION__, __LINE__, "The given value is not in the range" ); }


// Use this macro to assert that the value is in the required range, where the minimum and maximum values of the range are excluded, and if 
// not throw an exception
//
#define AssertValueIsInRangeWhenMinimumAndMaximumValuesOfTheRangeAreExcluded_CompileTimeSupportedAsWell( Value, MinimumRangeValue, MaximumRangeValue ) if consteval { if ( ( Value <= MinimumRangeValue ) || ( Value >= MaximumRangeValue ) ) { throw 0; } } else { Error::Assert< Error::Exception >::True( ( ( Value >= MinimumRangeValue ) && ( Value < MaximumRangeValue ) ), __FILE__, __FUNCTION__, __LINE__, "The given value is not in the range" ); }


// Use this macro to assert that the sum of two values is equal or smaller then a certain limit, and if not throw an exception
//
#define AssertSumOfTheValuesIsEqualOrBelowCertainLimit_CompileTimeSupportedAsWell( FirstValue, SecondValue, Limit ) if consteval { if ( ( FirstValue + SecondValue ) > Limit ) { throw 0; } } else { Error::Assert< Error::Exception >::True( ( ( FirstValue + SecondValue ) <= Limit ), __FILE__, __FUNCTION__, __LINE__, "The sum of the two values should be equal or smaller then the limit" ); }


// Use this macro to assert that the given value is a power of 2, and if it is not throw an exception. Note - should only be used after level 10
//
#define AssertValueIsPowerOfTwo_CompileTimeSupportedAsWell( Value ) if consteval { if (  ) { throw 0; } } else { Error::Assert< Error::Exception >::True( ( Arithmetics::IsPowerOfTwo< typename RemoveQualifiers< decltype( Value ) >::Type >( Value ) == true ), __FILE__, __FUNCTION__, __LINE__, "The value must be a power of 2" ); }


// Use this macro to assert that the value is a digit, and if not throw an exception
//
#define AssertValueIsDigit_CompileTimeSupportedAsWell( Value ) if consteval { if ( ( Value < '0' ) || ( Value > '9' ) ) { throw 0; } } else { Error::Assert< Error::Exception >::True( ( ( Value >= '0' ) || ( Value <= '9' ) ), __FILE__, __FUNCTION__, __LINE__, "The value is not a digit" ); }


// Use this macro to assert that the value is a smallr letter 'a-z', and if not throw an exception
//
#define AssertValueIsSmallLetter_CompileTimeSupportedAsWell( Value ) if consteval { if ( ( Value < 'a' ) || ( Value > 'z' ) ) { throw 0; } } else { Error::Assert< Error::Exception >::True( ( ( Value >= 'a' ) || ( Value <= 'z' ) ), __FILE__, __FUNCTION__, __LINE__, "The value is not a small letter" ); }


// Use this macro to assert that the value is a capital letter 'A-Z', and if not throw an exception
//
#define AssertValueIsCapitalLetter_CompileTimeSupportedAsWell( Value ) if consteval { if ( ( Value < 'A' ) || ( Value > 'Z' ) ) { throw 0; } } else { Error::Assert< Error::Exception >::True( ( ( Value >= 'A' ) || ( Value <= 'Z' ) ), __FILE__, __FUNCTION__, __LINE__, "The value is not a capital letter" ); }


// Use this macro to assert that the value is a letter, either small or capital, and if not throw an exception
//
#define AssertValueIsLetter_CompileTimeSupportedAsWell( Value ) if consteval { if ( ( Value < 'A' ) || ( Value > 'z' ) || ( ( Value < 'a' ) && ( Value > 'Z' ) ) ) { throw 0; } } else { Error::Assert< Error::Exception >::True( ( ( ( Value >= 'a' ) && ( Value <= 'z' ) ) || ( ( Value >= 'A' ) && ( Value <= 'Z' ) ) ), __FILE__, __FUNCTION__, __LINE__, "The value is not a letter" ); }