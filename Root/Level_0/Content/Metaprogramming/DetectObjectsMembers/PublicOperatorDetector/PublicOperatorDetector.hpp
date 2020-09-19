#ifndef PUBLICOPERATORDETECTOR_HPP
#define PUBLICOPERATORDETECTOR_HPP


#include "../../../../CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../IntegralConstant/IntegralConstant.hpp"  //  Class IntegralConstant
#include "../../SequenceOfTypesToVoid/SequenceOfTypesToVoid.hpp"  //  Typedef SequenceOfTypesToVoid


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe
{



	// When a type is forward declared, all the compiler knows is that this type exists. It does not know its size, members or methods. This is why its
	// called incomplete type. Therefore, it can not be used to declare a variable, member or base class since the compiler would need the layout of the
	// type. In other words, it can not be used for anything that requires information on the specific type. What can be done is declaring pointer and
	// reference to the incomplete type. The pointer and refernce can act as a variable, argument to a method or as the return type.
	//
	// Forward declarations :
	//
	//  NONE
	//



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
		/* Template Class Information :																																																\
																																																									\		
		  Purpose :																																																					\
																																																									\		
				Use this object to check for the existence of a public operator member. In general If the given type is has the public operator member, 																			\
				this object will contain a boolean value of true, and otherwise false. This is the main template it will conatin false if the object type 																			\
				does not have a public operator member with the required name 																																						\
																																																									\		
		  Description : 																																																			\
																																																									\		
	          1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by 																						\
	             providing 3 keywords : 																																															\
	     																																																							\
	              1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the 																						\
	                          obejct using the tools presented here. This part will usually contain only methods and not data members. If a data 																					\
	                          member is public all the encapsulation is lost, so it should be avoided in most cases 																												\
	     																																																							\
	              2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will 																					\
	                             be able to access all the data and methods inside this part. This part will usually containt some methods and few 																					\
	                             data members 																																														\
	     																																																							\
	              3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object 																				\
	                           and all the methods the developer needed to implement the interface presented in the public part. Every method in this 																				\
	                           part will end with the suffix __Private 																																								\
	     																																																							\
	          2. Template arguments : 																																																\
	     																																																							\
	              1. Type - any type 																																																\
																																																									\		
		  Expectations : 																																																			\
																																																									\		
				NONE 																																																				\
		 																																																							\
		  Possible errors : 																																																		\
		 																																																							\
				Too many to count */ 																																																\
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
	        /* Method Information :																																																	\
	        																																																						\
	          Description :																																																			\
	        																																																						\
	              Default Constructor,																																																\
	        																																																						\
	          Required arguments :																																																	\
	        																																																						\
	              User information needed :																																															\
	        																																																						\
	                  NONE 																																																			\
	        																																																						\
	              Information returned to the user : 																																												\
	        																																																						\
	                  NONE 																																																			\
	        																																																						\
	          Return value : 																																																		\
	        																																																						\
	              NONE 																																																				\
	        																																																						\
	          Expectations : 																																																		\
	        																																																						\
	              NONE 																																																				\
	        																																																						\
	          Possible errors : 																																																	\
	        																																																						\
	              They will come */ 																																																\
	        																																																						\
	        inline PublicOperatorDetector_ ## OperatorName() = default; 																																							\
																																																									\
																																																									\
	        /* Method Information :																																																	\
	        																																																						\
	          Description : 																																																		\
	        																																																						\
	              Destructor, does not throw 																																														\
	        																																																						\
	          Required arguments : 																																																	\
	        																																																						\
	              User information needed : 																																														\
	        																																																						\
	                  NONE 																																																			\
	        																																																						\
	              Information returned to the user : 																																												\
	        																																																						\
	                  NONE 																																																			\
	        																																																						\
	          Return value : 																																																		\
	        																																																						\
	              NONE 																																																				\
	        																																																						\
	          Expectations : 																																																		\
	        																																																						\
	              NONE 																																																				\
	        																																																						\
	          Possible errors : 																																																	\
	        																																																						\
	              They will come */																																																	\
	        																																																						\
	        inline ~PublicOperatorDetector_ ## OperatorName() = default; 																																							\
																																																									\
																																																									\
		private:																																																					\
																																																									\
																																																									\
	        /* Disable all copy and move related methods */ 																																										\
	        DisableCopyAndMove_MACRO( PublicOperatorDetector_ ## OperatorName )																																						\
																																																									\
																																																									\
		};    /*  Class PublicOperatorDetector_ ## OperatorName  */ 																																								\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
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
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
																																																									\
		/* Template Class Information : 																																															\
		 																																																							\
		  Purpose : 																																																				\
		 																																																							\
				Use this object to check for the existence of a public operator member. In general If the given type is has the public operator member, 																			\
				this object will contain a boolean value of true, and otherwise false. This is a template specialization it will conatin true if the object type 																	\
				have a public operator member with the required name 																																								\
		 																																																							\
		  Description : 																																																			\
																																																									\
	          1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by 																						\
	             providing 3 keywords : 																																															\
	     																																																							\
	              1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the 																						\
	                          obejct using the tools presented here. This part will usually contain only methods and not data members. If a data 																					\
	                          member is public all the encapsulation is lost, so it should be avoided in most cases 																												\
	     																																																							\
	              2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will 																					\
	                             be able to access all the data and methods inside this part. This part will usually containt some methods and few 																					\
	                             data members 																																														\
	     																																																							\
	              3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object 																				\
	                           and all the methods the developer needed to implement the interface presented in the public part. Every method in this 																				\
	                           part will end with the suffix __Private 																																								\
	    																																																							\
	          2. Template arguments : 																																																\
	     																																																							\
	              1. Type - any type 																																																\
																																																									\
		  Expectations :																																																			\
																																																									\
				NONE 																																																				\
																																																									\
		  Possible errors :																																																			\
																																																									\
				Too many to count */																																																\
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
	        /* Method Information :																																																	\
	        																																																						\
	          Description : 																																																		\
	        																																																						\
	              Default Constructor,																																																\
	        																																																						\
	          Required arguments :																																																	\
	        																																																						\
	              User information needed :																																															\
	        																																																						\
	                  NONE 																																																			\
	        																																																						\
	              Information returned to the user : 																																												\
	        																																																						\
	                  NONE 																																																			\
	        																																																						\
	          Return value : 																																																		\
	        																																																						\
	              NONE 																																																				\
	        																																																						\
	          Expectations : 																																																		\
	        																																																						\
	              NONE 																																																				\
	        																																																						\
	          Possible errors : 																																																	\
	        																																																						\
	              They will come */ 																																																\
	        																																																						\
	        inline PublicOperatorDetector_ ## OperatorName() = default; 																																							\
																																																									\
																																																									\
	        /* Method Information : 																																																\
	        																																																						\
	          Description : 																																																		\
	        																																																						\
	              Destructor, does not throw 																																														\
	        																																																						\
	          Required arguments : 																																																	\
	        																																																						\
	              User information needed : 																																														\
	        																																																						\
	                  NONE 																																																			\
	        																																																						\
	              Information returned to the user : 																																												\
	        																																																						\
	                  NONE 																																																			\
	        																																																						\
	          Return value : 																																																		\
	        																																																						\
	              NONE 																																																				\
	        																																																						\
	          Expectations : 																																																		\
	        																																																						\
	              NONE 																																																				\
	        																																																						\
	          Possible errors : 																																																	\
	        																																																						\
	              They will come */ 																																																\
	        																																																						\
	        inline ~PublicOperatorDetector_ ## OperatorName() = default;																																							\
																																																									\
																																																									\
		private: 																																																					\
																																																									\
																																																									\
	        /* Disable all copy and move related methods */ 																																										\
	        DisableCopyAndMove_MACRO( PublicOperatorDetector_ ## OperatorName ) 																																					\
																																																									\
																																																									\
		};  /*  Class PublicOperatorDetector_ ## OperatorName  */ 																																									\









































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *************************************************************   CreatePublicOperatorDetector specific definitions   ************************************************************ //
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
	CreatePublicOperatorDetector( SmallerOrEqual, <= )
	CreatePublicOperatorDetector( Larger, > )
	CreatePublicOperatorDetector( LargerOrEqual, >= )


	CreatePublicOperatorDetector( DereferencePointerToMember, ->* )








}  //  Namespace Universe



#endif  // PUBLICOPERATORDETECTOR_HPP