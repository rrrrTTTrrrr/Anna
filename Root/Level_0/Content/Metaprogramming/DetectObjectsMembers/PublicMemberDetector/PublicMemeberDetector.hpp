#ifndef PUBLICMEMBERDETECTOR_HPP
#define PUBLICMEMBERDETECTOR_HPP


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



    // This macro should be used to create public member detectors. The object needs to know what is the name of the public member to detect in
	// the templte type object, therefore the public member detector object is wrapped with a macro to allow text manipulation and create an object 
	// for each name of a public member that needs to be detected. The meaning of public here, is relative to the context, the protected part of an
	// object is private to the outside world, but public to the inherting object. Another example is an object declared friend of another object
	// which makes all its content public to that object.
    //
    // For example if a public member with the name 'Teeth' needs to be detected, the syntax will look :
    //
    //      CreateMemberDetector( Teeth )
    //
    // The preprocessor will create the following object :
    //
    //		template< typename ObjectToDetectMemberNameInsideType >
    //		PublicMethodDetector_Teeth
    //
    // It is basically used to create different objects, by switching the text in the required locations!
    //
    // The comments inside are C style. This is the only way to create multi line macro
    //
    #define CreatePublicMemberDetector( MemberName )                                                                                                                                                      							\
																																																									\
																																																									\
		/* Template Class Information :																																																\
																																																									\		
		  Purpose :																																																					\
																																																									\		
				Use this object to check for the existence of a public member. In general If the given type is has the public member, this object will contain 																		\
				a boolean value of true, and otherwise false. This is the main template it will conatin false if the object type does not have a public member 																		\
				with the required name 																																																\
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
		class PublicMemberDetector_ ## MemberName NotForInheritance : public IntegralConstant< Boolean, false > 																													\
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
	        inline PublicMemberDetector_ ## MemberName() = default; 																																								\
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
	        inline ~PublicMemberDetector_ ## MemberName() = default; 																																								\
																																																									\
																																																									\
		private:																																																					\
																																																									\
																																																									\
	        /* Disable all copy and move related methods */ 																																										\
	        DisableCopyAndMove_MACRO( PublicMemberDetector_ ## MemberName )																																							\
																																																									\
																																																									\
		};    /*  Class PublicMemberDetector_ ## MemberName  */ 																																									\
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
   ***************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - For types that conatin the public member member   ************************************* 														\
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
				Use this object to check for the existence of a public member. In general If the given type is has the public member, this object will contain 																		\
				a boolean value of true, and otherwise false. This is the template specialization it will conatin true if the object type have a public member 																		\
				with the required name 																																																\
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
		class PublicMemberDetector_ ## MemberName< Type, SequenceOfTypesToVoid< decltype( &Type::MemberName ) > > NotForInheritance : public IntegralConstant< Boolean, true >														\
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
	        inline PublicMemberDetector_ ## MemberName() = default; 																																								\
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
	        inline ~PublicMemberDetector_ ## MemberName() = default;																																								\
																																																									\
																																																									\
		private: 																																																					\
																																																									\
																																																									\
	        /* Disable all copy and move related methods */ 																																										\
	        DisableCopyAndMove_MACRO( PublicMemberDetector_ ## MemberName ) 																																						\
																																																									\
																																																									\
		};  /*  Class PublicMemberDetector_ ## MemberName  */ 																																										\









































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ***********************************************************   CreatePublicMemberDetector specific definitions   ********************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //





































    // Declare all the instances required that the macro will create :















}  //  Namespace Universe



#endif  // PUBLICMEMBERDETECTOR_HPP