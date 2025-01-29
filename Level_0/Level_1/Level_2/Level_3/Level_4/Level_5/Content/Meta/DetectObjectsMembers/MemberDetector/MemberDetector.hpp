namespace Universe
{



// Pointers to classes are not real pointers, a class is a logical construct and has no physical existence in memory, however, a pointer to
// a member of a class gives an offset into the object itself where the member is located!



// The purpose of a member detector is to detect the presence of a specific member attribute, function or type in a class! AMAZING!!
//
// Compile time reflection capabilities are the corenerstone of C++ template meta-programming. Type traits libraries provide powerful
// ways of extracting information about types and their relationships. Detecting the presence of a data member in a class is also an
// example of compile time reflection.
//
// Member detector idiom is implemented using the substitution failure is not an error ( SFAINE ) idiom. The following class template
// 'Detect' is a meta function that determines whether the template type has a data or function member with the name 'X' in it or 
// not. Note that the tyoe if the data member X does not matter nor does the return value and arguments of the member function!
//
//		template< typename Type >
//		class MemberDetector
//		{
//		public:
//
//			using ObjectType = MemberDetector;
//
//			enum { value = ( sizeof( DummyFunction< Derived >( 0 ) ) == 2 ) };
//
//		private:
//
//			struct Fallback 
//			{ 
//				int X; 																				// Add member name 'X'
//			}
//
//			struct Derived : public Type, public Fallback 
//			{}
//
//			template< typename Type2, Type2 >
//			struct Check;
//
//			using ArrayOfSizeOne = char[1];  														// Type definition for an array of size 1
//			using ArrayOfSizeTwo = char[2];															// Type definition for an array of size 2
//
//			template< typename Type2 >
//			static ArrayOfSizeOne& DummyFunction( Check< int Fallback::*, &Type2::X >* );
//
//			template< typename Type2 >
//			static ArrayOfSizeTwo& DummyFunction( ... );
//
//		};
//
// This idiom works by creating a controlled ambiguity during compilation and recovering from that using the SFAINE idiom. First proxy class,
// 'Fallback', has a data member of the same name that needed to be detected. class 'Derived' inherits from both the template type and the 
// 'Fallback' class. As a result, 'Derived' objects will have at least one data member named X. Potentially, 'Derived' objects may have two
// 'X' data members if the template type also has a member with the name X.
//
// The 'Check' template is used to create controlled ambiguity. 'Check' templates takes two parameters. First is a type parameter and the second
// is an instance of that type. For example :
//
//		Check< int, 78 >
//
// is a valid instantation. Two overloaded functions named 'DummyFunction' create an overload set as required by the SFAINE idiom. The first
// 'DummyFunction' can be instantied only if the address of data member 'Type2::X' can be taken unambiguously. The address of it can be 
// taken if there is exactly one X data member in the 'Derived' class, in other words, onlt if the template type does not have any data member
// called 'X'. If it does have, the address of 'Type2::X' can't be taken without further disambiguation and therefore the instantaion of the
// first 'DummyFunction' fails and the other function is choosen, all without an error. Note the difference between the return types of the 
// two 'DummyFunction' declarations. The first returns a reference to array if size one whereas the second one returns a reference to an array
// of size two. This difference in the sizes allows to identify which function was instantiated.
//
// Finally a boolean value is exposed, which is true if the sizeof the return type of the function is two. That is, when the second declaration
// of the 'DummyFunction' was instantied because the template type has a data member called 'X'.
//
// Using C++11 features, this example can be rewritten so that the controlled ambiguity is created using the 'decltype' specifier instead of a
// 'Check' template and a pointer to member :
//
//		template< typename Type >
//		class MemberDetector
//		{
//		public:
//
//			static constexpr bool Result = ( sizeof( DummyFunction< Derived >( 0 ) ) == sizeof( Yes ) );
//
//		private:
//
//			struct Fallback 
//			{ 
//				int X; 																				// Add member name 'X'
//			}
//
//			struct Derived : public Type, public Fallback 
//			{}
//
//			using No = char[1];  														// Type definition for an array of size 1
//			using Yes = char[2];															// Type definition for an array of size 2
//
//			template< typename Type2 >
//			static No& DummyFunction( decltype( Type2::X )* );
//
//			template< typename Type2 >
//			static Yes& DummyFunction( Type2* );
//
//		};
//



// This macro should be used to create member detectors. The object needs to know what is the name of the member to detect in the template type object,
// therefore the member detector object is wrapped with a macro to allow text manipulation and create an object for each name of a member that needs
// to be detected.
//
// For example if a member with the name 'member_Teeth' needs to be detected, the syntax will look :
//
//      CreateMemberDetector( Teeth )
//
// The preprocessor will create the following object :
//
//		template< typename ObjectToDetectMemberNameInsideType >
//		MemberDetector_Teeth
//
// It is basically used to create different objects, by switching the text in the required locations!
//
// The comments inside are C style. This is the only way to create multi line macro
//
#define CreateMemberDetector( MemberName )                                                                                                                                                      																					\
																																																																					\
																																																																					\
	template< typename ObjectToDetectMemberNameInsideType > 																																																						\
	class MemberDetector_ ## MemberName NotForInheritance 																																																							\
	{ 																																																																				\
	public:																																																																			\
																																																																					\
																																																																					\
		/* The following are type definitions of the object and all the provided template arguments : */ 																																											\
																																																																					\
																																																																					\
		/* Create a type definition for the object itself */																																																						\
		using ObjectType = MemberDetector_ ## MemberName< ObjectToDetectMemberNameInsideType >;																																														\
																																																																					\
		/* Create a type definition for the first template argument */																																																				\
		using FirstTemplateArgumentType = ObjectToDetectMemberNameInsideType;																																																		\
																																																																					\
																																																																					\
		/* The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared																																\
		 the compiler generates a basic behavior for them if possible : */ 																																																			\
																																																																					\
																																																																					\
		inline MemberDetector_ ## MemberName() = default; 																																																							\
																																																																					\
																																																																					\
		inline ~MemberDetector_ ## MemberName() = default;																																																							\
																																																																					\
																																																																					\
		/* The following methods declare the overloaded operators for the object : */ 																																																\
																																																																					\
																																																																					\
        constexpr operator Boolean() const;																																																											\
        																																																																			\
        																																																																			\
		/* The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have 																												\
		 access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring 																												\
		 a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members */ 																											\
        																																																																			\
																																																																					\
        constexpr static Boolean Result(); 																																																											\
        																																																																			\
        																																																																			\
	private:																																																																		\
																																																																					\
																																																																					\
        /* Disable all copy and move related methods */ 																																																							\
        DisableCopyAndMove( MemberDetector_ ## MemberName ); 																																																					\
        																																																																			\
        																																																																			\
		/* The following data members will be used to create a controlled ambiguity. The first is an artifical object that will contain a member with the 																															\
		 required name. The second is also an artifical object that will inherit from the the first artifical object and from the object type that the 																																\
		 a member with the name needs to be detected in. This way if such a member with the required name does exist in the object, the derived object 																																\
		 will contain two members with the same which will cause ambiguity : */ 																																																	\
																																																																					\
																																																																					\
		/* This object will be created to store a member with the same name as the required member name */ 																																											\
		class ObjectWithMemberThatHasTheNameThatNeedsToBeDetected 																																																					\
		{ 																																																																			\
		public: 																																																																	\
																																																																					\
			SignedInteger32bits member_ ## MemberName; 																																																								\
																																																																						\
		}; 																																																																			\
																																																																						\
		/* This object will derive from the given template type object that the a member with the given name needs to be detected in, and from the object above */ 																													\
		class ObjectToCreateAmbiguityInCaseMemberWithTheNameDoesExist : public ObjectWithMemberThatHasTheNameThatNeedsToBeDetected, public ObjectToDetectMemberNameInsideType 																										\
		{}; 																																																																		\
																																																																					\
																																																																					\
		/* The following two type definitions will be used as the return types for a set of overloaded functions, that will use the substitution failure is not 																													\
		 an error idiom to make the decision based on the return type size of the function that will be choosen durin the resolution of the instantaion : */ 																														\
																																																																					\
																																																																					\
		/* The first type definition of size 1, for objects that does not contain a member with the given name */ 																																									\
		using DoesNotContainMemberWithTheName = UnsignedInteger8bits[1]; 																																																			\
																																																																					\
		/* The second type definition of size 2, for objects that does contain a member with the given name */ 																																										\
		using ContainMemberWithTheName = UnsignedInteger8bits[2]; 																																																					\
																																																																					\
																																																																					\
		/* The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but 																													\
		 rather help implement it : */ 																																																												\
																																																																					\
																																																																					\
		/* The following two methods will create an overloaded set to allow choose the correct declaration using substitution faliure is not an error : */ 																															\
																																																																					\
																																																																					\
		template< typename ObjectToCreateAmbiguityInCaseMemberWithTheNameDoesExistType >																																															\
		static DoesNotContainMemberWithTheName& UseThisToCheckIfTheObjectContainMemberWithTheName( decltype( ObjectToCreateAmbiguityInCaseMemberWithTheNameDoesExistType::member_ ## MemberName )* );																				\
																																																																					\
																																																																					\
		template< typename ObjectToCreateAmbiguityInCaseMemberWithTheNameDoesExistType >																																															\
		static ContainMemberWithTheName& UseThisToCheckIfTheObjectContainMemberWithTheName( ObjectToCreateAmbiguityInCaseMemberWithTheNameDoesExistType* );																															\
																																																																					\
																																																																					\
		/* Static data members do not belong to any instance, they belong to the object. Like every global variable it is created with the start of the program 																													\
		 and only destroyed when the program ends. The access to the static member is bound to this object of course */ 																																							\
																																																																					\
		/* This boolean will contain true if the template type object contains a member with the given name, and false otherwise */ 																																				\
		static constexpr Boolean member_containsMemberWithTheRequiredNameOrNot = ( sizeof( UseThisToCheckIfTheObjectContainMemberWithTheName< ObjectToCreateAmbiguityInCaseMemberWithTheNameDoesExist >( 0UL ) ) == sizeof( ContainMemberWithTheName ) ); 							\
																																																																					\
																																																																					\
	};    /* Class MemberDetector_ ## MemberName */ 																																																								\
																																																																					\
																																																																					\
																																																																					\
/*  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   *************************************************************** */ 																									\
																																																																					\
																																																																					\
     																																																																				\
    template< typename ObjectToDetectMemberNameInsideType > 																																																						\
    constexpr MemberDetector_ ## MemberName< ObjectToDetectMemberNameInsideType >::operator Boolean() const 																																										\
    { 																																																																				\
    	/* Return the constant expression value that store if a member with the required name exist or not */ 																																										\
    	return ( member_containsMemberWithTheRequiredNameOrNot ); 																																																					\
    } 																																																																				\
    																																																																				\
    																																																																				\
    																																																																				\
/*  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************ */ 																									\
    																																																																				\
    																																																																				\
    																																																																				\
    template< typename ObjectToDetectMemberNameInsideType > 																																																						\
    constexpr Boolean MemberDetector_ ## MemberName< ObjectToDetectMemberNameInsideType >::Value() 																																													\
    {																																																																				\
    	/* Return the constant expression value that store if a member with the required name exist or not */ 																																										\
    	return ( member_containsMemberWithTheRequiredNameOrNot ); 																																																					\
    }




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// **************************************************************   CreateMemberDetector specific definitions   ************************************************************* //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //




// Create all the possible member detectors that this macro will support :
//





}  //  Namespace Universe