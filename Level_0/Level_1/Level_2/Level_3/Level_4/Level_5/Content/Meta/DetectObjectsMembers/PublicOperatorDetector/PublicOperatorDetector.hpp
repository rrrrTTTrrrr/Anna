namespace Universe
{



// This macro should be used to create public operator detectors. The object needs to know what is the name of the public operator to detect in
// the templte type object, therefore the public operator detector object is wrapped with a macro to allow text manipulation and create an object 
// for each name of a public operator that needs to be detected. The meaning of public here, is relative to the context, the protected part of an
// object is private to the outside world, but public to the inherting object. Another example is an object declared friend of another object
// which makes all its content public to that object.
//
// Note - currently the following operators can not be used through this macro :
//
//	1. Round brackets / parentheses - '()'
//	2. Square brackets - '[]'
//	3. Negate - '~'
//	4. Not - '!'
//	5. Dereference - '->'
//
// For example if the operator '+' needs to be detected write its name as addition, the syntax will look :
//
//      CreatePublicOperatorDetector( Addition, + )
//
// The preprocessor will create the following object :
//
//		template< typename ObjectToDetectOperatorInsideType >
//		PublicOperatorDetector_Addition
//
// It is basically used to create different objects, by switching the text in the required locations!
//
// The comments inside are C style. This is the only way to create multi line macro
//
#define CreatePublicOperatorDetector( OperatorName, OperatorTextReprsentation )                                                                                                                                                 \
																																																								\
	  																																																							\
	template< typename Type, typename Void = SequenceOfTypesToVoid<> > 																																							\
	class PublicOperatorDetector_ ## OperatorName NotForInheritance : public IntegralConstant< Boolean, false > 																												\
	{																																																							\
	public: 																																																					\
																																																								\
																																																								\
        /* The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler 															\
         generates a basic behavior for them : */																																												\
																																																								\
        																																																						\
        inline PublicOperatorDetector_ ## OperatorName() = default; 																																							\
																																																								\
																																																								\
        inline ~PublicOperatorDetector_ ## OperatorName() = default; 																																							\
																																																								\
																																																								\
	private:																																																					\
																																																								\
																																																								\
        /* Disable all copy and move related methods */ 																																										\
        DisableCopyAndMove( PublicOperatorDetector_ ## OperatorName );																																						\
																																																								\
																																																								\
	};    /*  Class PublicOperatorDetector_ ## OperatorName  */ 																																								\
																																																								\
																																																								\
																																																								\
/* **************************************************************************************************************************************************************************  														\
                                                                                                                                                                         														\
**************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - For types that conatin the public operator member   ************************************ 														\
                                                                                                                                                                              													\
************************************************************************************************************************************************************************** */													\
																																																								\
																																																								\
																																																								\
	template< typename Type >																																																	\
	class PublicOperatorDetector_ ## OperatorName< Type, SequenceOfTypesToVoid< decltype( &Type::operator OperatorTextReprsentation ) > > NotForInheritance : public IntegralConstant< Boolean, true >							\
	{																																																							\
	public: 																																																					\
																																																								\
																																																								\
        /* The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler 															\
         generates a basic behavior for them : */ 																																												\
																																																								\
        																																																						\
        inline PublicOperatorDetector_ ## OperatorName() = default; 																																							\
																																																								\
        																																																						\
        inline ~PublicOperatorDetector_ ## OperatorName() = default;																																							\
																																																								\
																																																								\
	private: 																																																					\
																																																								\
																																																								\
        /* Disable all copy and move related methods */ 																																										\
        DisableCopyAndMove( PublicOperatorDetector_ ## OperatorName ); 																																					\
																																																								\
																																																								\
	};  /*  Class PublicOperatorDetector_ ## OperatorName  */ 																																									\



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// **********************************************************   CreatePublicOperatorDetector specific definitions   ********************************************************* //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //



// Create all the possible operator detectors that this macro can support :


CreatePublicOperatorDetector( Assignment, = )
CreatePublicOperatorDetector( AndCondition, && )
CreatePublicOperatorDetector( OrCondition, || )


CreatePublicOperatorDetector( Addition, + )
CreatePublicOperatorDetector( AdditionAndAssignment, += )
CreatePublicOperatorDetector( Subtraction, - )
CreatePublicOperatorDetector( SubtractionAndAssignment, -= )
CreatePublicOperatorDetector( Multiply, * )
CreatePublicOperatorDetector( MultiplyAndAssignment, *= )
CreatePublicOperatorDetector( Divide, / )
CreatePublicOperatorDetector( DivideAndAssignment, /= )
CreatePublicOperatorDetector( Modulo, % )
CreatePublicOperatorDetector( ModuloAndAssignment, %= )
CreatePublicOperatorDetector( IncrementOne, ++ )
CreatePublicOperatorDetector( DecrementOne, -- )


CreatePublicOperatorDetector( XOR, ^ )
CreatePublicOperatorDetector( XorAndAssignment, ^= )
CreatePublicOperatorDetector( AND, & )
CreatePublicOperatorDetector( AndAndAssignment, &= )
CreatePublicOperatorDetector( OR, | )
CreatePublicOperatorDetector( OrAndAssignment, |= )


CreatePublicOperatorDetector( LeftShift, << )
CreatePublicOperatorDetector( LeftShiftAndAssignment, <<= )
CreatePublicOperatorDetector( RightShift, >> )
CreatePublicOperatorDetector( RightShiftAndAssignment, >>= )


CreatePublicOperatorDetector( Equal, == )
CreatePublicOperatorDetector( NotEqual, != )
CreatePublicOperatorDetector( Smaller, < )
CreatePublicOperatorDetector( EqualOrSmaller, <= )
CreatePublicOperatorDetector( Larger, > )
CreatePublicOperatorDetector( EqualOrLarger, >= )


CreatePublicOperatorDetector( DereferencePointerToMember, ->* )



}  //  Namespace Universe