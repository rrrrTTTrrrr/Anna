namespace Universe
{



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
        inline PublicMemberDetector_ ## MemberName() = default; 																																								\
																																																								\
        																																																						\
        inline ~PublicMemberDetector_ ## MemberName() = default; 																																								\
																																																								\
																																																								\
	private:																																																					\
																																																								\
																																																								\
        /* Disable all copy and move related methods */ 																																										\
        DisableCopyAndMove( PublicMemberDetector_ ## MemberName );																																						\
																																																								\
																																																								\
	};    /*  Class PublicMemberDetector_ ## MemberName  */ 																																									\
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
        inline PublicMemberDetector_ ## MemberName() = default; 																																								\
																																																								\
        																																																						\
        inline ~PublicMemberDetector_ ## MemberName() = default;																																								\
																																																								\
																																																								\
	private: 																																																					\
																																																								\
																																																								\
        /* Disable all copy and move related methods */ 																																										\
        DisableCopyAndMove( PublicMemberDetector_ ## MemberName ) 																																						\
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