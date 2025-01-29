namespace Universe
{



// This macro should be used to create operator detectors. The object needs to know what is the name of the member operator to detect in the templte 
// type object, therefore the operator detector object is wrapped with a macro to allow text manipulation and create an object for each name of a 
// member operator that needs to be detected.
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
//      CreateOperatorDetector( Addition, + )
//
// The preprocessor will create the following object :
//
//		template< typename ObjectToDetectOperatorInsideType >
//		OperatorDetector_Addition
//
// It is basically used to create different objects, by switching the text in the required locations!
//
// The comments inside are C style. This is the only way to create multi line macro
//
#define CreateOperatorDetector( OperatorName, OperatorTextReprsentation )                                                                                                                                                    														\
																																																																					\
																																																																					\
	template< typename ObjectToDetectOperatorInsideType, typename ImplementationEnabler = void >																																													\
	class OperatorDetector_ ## OperatorName;																																																										\
																																																																					\
																																																																					\
	template< typename ObjectToDetectOperatorInsideType > 																																																							\
	class OperatorDetector_ ## OperatorName< ObjectToDetectOperatorInsideType, typename ProvideTypeOnlyIfAssertionIsTrue< IsBuiltIn< ObjectToDetectOperatorInsideType >::Result() == false >::Type > NotForInheritance 																\
	{ 																																																																				\
	public:																																																																			\
																																																																					\
																																																																					\
		/* The following are type definitions of the object and all the provided template arguments : */ 																																											\
																																																																					\
																																																																					\
		/* Create a type definition for the first template argument */																																																				\
		using FirstTemplateArgumentType = ObjectToDetectOperatorInsideType;																																																			\
																																																																					\
																																																																					\
		inline OperatorDetector_ ## OperatorName() = default; 																																																						\
																																																																					\
																																																																					\
		inline ~OperatorDetector_ ## OperatorName() = default;																																																						\
																																																																					\
        																																																																			\
		/* The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have 																												\
		 access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring 																												\
		 a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members */ 																											\
        																																																																			\
        																																																																			\
        constexpr static Boolean Result() 																																																											\
        {																																																																			\
        	return ( member_containsOperatorOrNot );																																																								\
        }																																																																			\
        																																																																			\
        																																																																			\
	private:																																																																		\
																																																																					\
																																																																					\
        /* Disable all copy and move related methods */ 																																																							\
        DisableCopyAndMove( OperatorDetector_ ## OperatorName ); 																																																				\
        																																																																			\
        																																																																			\
		/* The following data members will be used to create a controlled ambiguity. The first is an artifical object that will contain the operator 																																\
		 type that the operator needs to be detected in. This way if such an operator does exist in the object, the derived object will contain two 																																\
		 operatore of the same kine which will cause ambiguity : */ 																																																				\
																																																																					\
																																																																					\
		/* This object will be created with the operator that needs to be detected */ 																																																\
		class ObjectWithOperatorThatNeedsToBeDetected 																																																								\
		{ 																																																																			\
		public: 																																																																	\
																																																																					\
			void operator OperatorTextReprsentation( SignedInteger32bits ); 																																																		\
																																																																						\
		}; 																																																																			\
																																																																						\
		/* This object will derive from the given template type object that the operator needs to be detected in, and from the object above */ 																																		\
		class ObjectToCreateAmbiguityInCaseOperatorDoesExist : public ObjectWithOperatorThatNeedsToBeDetected, public ObjectToDetectOperatorInsideType 																																\
		{}; 																																																																		\
																																																																					\
																																																																					\
		/* The following two type definitions will be used as the return types for a set of overloaded functions, that will use the substitution failure is not 																													\
		 an error idiom to make the decision based on the return type size of the function that will be choosen during the resolution of the instantaion : */ 																														\
																																																																					\
																																																																					\
		/* The first type definition of size 1, for objects that does not contain the operator */ 																																													\
		using DoesNotContainOperator = UnsignedInteger8bits[1]; 																																																					\
																																																																					\
		/* The second type definition of size 2, for objects that does contain the operator */ 																																														\
		using ContainOperator = UnsignedInteger8bits[2]; 																																																							\
																																																																					\
																																																																					\
		/* The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but 																													\
		 rather help implement it : */ 																																																												\
																																																																					\
																																																																					\
		/* The following two methods will create an overloaded set to allow choose the correct declaration using substitution faliure is not an error : */ 																															\
																																																																					\
																																																																					\
		template< typename ObjectToCreateAmbiguityInCaseOperatorDoesExistType >																																																		\
		static DoesNotContainOperator& UseThisToCheckIfTheObjectContainTheOperator( decltype( &ObjectToCreateAmbiguityInCaseOperatorDoesExistType::operator OperatorTextReprsentation )* );																							\
																																																																					\
																																																																					\
		template< typename ObjectToCreateAmbiguityInCaseOperatorDoesExistType >																																																		\
		static ContainOperator& UseThisToCheckIfTheObjectContainTheOperator( ObjectToCreateAmbiguityInCaseOperatorDoesExistType* );																																					\
																																																																					\
																																																																					\
		/* Static data members do not belong to any instance, they belong to the object. Like every global variable it is created with the start of the program 																													\
		 and only destroyed when the program ends. The access to the static member is bound to this object of course */ 																																							\
																																																																					\
		/* This boolean will contain true if the template type object contains the operator, and false otherwise */ 																																								\
		static constexpr Boolean member_containsOperatorOrNot = ( sizeof( UseThisToCheckIfTheObjectContainTheOperator< ObjectToCreateAmbiguityInCaseOperatorDoesExist >( 0UL ) ) == sizeof( ContainOperator ) ); 																	\
																																																																					\
																																																																					\
	};    /* Class OperatorDetector_ ## OperatorName */ 																																																							\
																																																																					\
																																																																					\
	template< typename ObjectToDetectOperatorInsideType > 																																																							\
	class OperatorDetector_ ## OperatorName< ObjectToDetectOperatorInsideType, typename ProvideTypeOnlyIfAssertionIsTrue< IsBuiltIn< ObjectToDetectOperatorInsideType >::Result() == true >::Type > NotForInheritance 																\
	{ 																																																																				\
	public:																																																																			\
																																																																					\
																																																																					\
		/* The following are type definitions of the object and all the provided template arguments : */ 																																											\
																																																																					\
																																																																					\
		/* Create a type definition for the first template argument */																																																				\
		using FirstTemplateArgumentType = ObjectToDetectOperatorInsideType;																																																			\
																																																																					\
																																																																					\
		inline OperatorDetector_ ## OperatorName() = default; 																																																						\
																																																																					\
																																																																					\
		inline ~OperatorDetector_ ## OperatorName() = default;																																																						\
																																																																					\
        																																																																			\
		/* The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have 																												\
		 access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring 																												\
		 a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members */ 																											\
        																																																																			\
        																																																																			\
        constexpr static Boolean Result() 																																																											\
        {																																																																			\
        	return ( true );																																																														\
        }																																																																			\
        																																																																			\
        																																																																			\
	private:																																																																		\
																																																																					\
																																																																					\
        /* Disable all copy and move related methods */ 																																																							\
        DisableCopyAndMove( OperatorDetector_ ## OperatorName ); 																																																				\
        																																																																			\
        																																																																			\
	};    // Class OperatorDetector_ ## OperatorName




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *************************************************************   CreateOperatorDetector specific definitions   ************************************************************ //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //




// Create all the possible operator detectors that this macro can support :


CreateOperatorDetector( Assignment, = )
CreateOperatorDetector( AndCondition, && )
CreateOperatorDetector( OrCondition, || )


CreateOperatorDetector( Addition, + )
CreateOperatorDetector( AdditionAndAssignment, += )
CreateOperatorDetector( Subtraction, - )
CreateOperatorDetector( SubtractionAndAssignment, -= )
CreateOperatorDetector( Multiply, * )
CreateOperatorDetector( MultiplyAndAssignment, *= )
CreateOperatorDetector( Divide, / )
CreateOperatorDetector( DivideAndAssignment, /= )
CreateOperatorDetector( Modulo, % )
CreateOperatorDetector( ModuloAndAssignment, %= )
CreateOperatorDetector( IncrementOne, ++ )
CreateOperatorDetector( DecrementOne, -- )


CreateOperatorDetector( XOR, ^ )
CreateOperatorDetector( XorAndAssignment, ^= )
CreateOperatorDetector( AND, & )
CreateOperatorDetector( AndAndAssignment, &= )
CreateOperatorDetector( OR, | )
CreateOperatorDetector( OrAndAssignment, |= )


CreateOperatorDetector( LeftShift, << )
CreateOperatorDetector( LeftShiftAndAssignment, <<= )
CreateOperatorDetector( RightShift, >> )
CreateOperatorDetector( RightShiftAndAssignment, >>= )


CreateOperatorDetector( Equal, == )
CreateOperatorDetector( NotEqual, != )
CreateOperatorDetector( Smaller, < )
CreateOperatorDetector( SmallerOrEqual, <= )
CreateOperatorDetector( Larger, > )
CreateOperatorDetector( LargerOrEqual, >= )


CreateOperatorDetector( DereferencePointerToMember, ->* )




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************************   OperatorDetector for operator '()'   ***************************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //




// Template Class Information :
//
//  Purpose :
//	
//		Use this object to detect if an object contains an overload for the round brackets operator. The signature of the operator is not important,
//	 	only if the operator exist or not
//
//  Description :
//
// 		1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
//		   providing 3 keywords :
//
//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
//						member is public all the encapsulation is lost, so it should be avoided in most cases
//
//			2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will 
//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few 
//						   data members
//
//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this 											
//						 part will end with the suffix __Private																		
//
//		3. Template arguments :
//
//			1. ObjectToDetectOperatorInsideType - the type of the object that the operator needs to be detected in
//
//  Expectations :
//
//		NONE		
//
//  Possible errors :
//
//		Too many to count
//
template< typename ObjectToDetectOperatorInsideType >
class OperatorDetector_RoundBrackets NotForInheritance
{
public:


	// The following are type definitions of the object and all the provided template arguments :


	// Create a type definition for the first template argument
	using FirstTemplateArgumentType = ObjectToDetectOperatorInsideType;


	// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
	// the compiler generates a basic behavior for them if possible :


	// Method Information :
    //
    //  Description :
	//	
	//		Default Constructor,
	//
	//	Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :																						
	//
	//			NONE
	//
	//	Return value :
	//
	//		NONE
	//
	//	Expectations :
	//
	//		NONE	
	//
	//	Possible errors :
	//
	//		They will come																		
	//
	inline OperatorDetector_RoundBrackets() = default;


	// Method Information :
	//
	//	Description :
	//
	//		Destructor, does not throw
	//
	//	Required arguments :			
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :																							
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE	
	//
	//	Expectations :
	//
	//		NONE	
	//
	//	Possible errors :			
	//
	//		They will come																		
	//
	inline ~OperatorDetector_RoundBrackets() = default;
   				
   				
	// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have		
	// access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring		
	// a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members 	
   				
   				
    // Method Information :		
	//
    //  Description :		 
	//
    //     Use this method to get the static constant expression value inside it														
	//
    //  Required arguments :
	//
    //      User information needed :
	//
    //         NONE
	//
    //      Information returned to the user :								
	//
    //          NONE
	//
    //  Return value :	
	//
    //		A copy of the static constant expression value inside this object will be returned											
	//
    //  Expectations :	
	//
    //      NONE
	//
    //  Possible errors :	
	//
    //      They will come
    //
    constexpr static Boolean Result();					
   				
   				
private:


    // Disable all copy and move related methods												
    DisableCopyAndMove( OperatorDetector_RoundBrackets );
   				
   				
	// The following data members will be used to create a controlled ambiguity. The first is an artifical object that will contain the operator
	// type that the operator needs to be detected in. This way if such an operator does exist in the object, the derived object will contain two
	// operatore of the same kine which will cause ambiguity :


	// This object will be created with the operator that needs to be detected
	class ObjectWithOperatorThatNeedsToBeDetected
	{
	public:

		void operator()( SignedInteger32bits );

	};											

	// This object will derive from the given template type object that the operator needs to be detected in, and from the object above 
	class ObjectToCreateAmbiguityInCaseOperatorDoesExist : public ObjectWithOperatorThatNeedsToBeDetected, public ObjectToDetectOperatorInsideType
	{};			


	// The following two type definitions will be used as the return types for a set of overloaded functions, that will use the substitution failure is not			
	// an error idiom to make the decision based on the return type size of the function that will be choosen during the resolution of the instantaion :


	// The first type definition of size 1, for objects that does not contain the operator		
	using DoesNotContainOperator = UnsignedInteger8bits[1];																			

	// The second type definition of size 2, for objects that does contain the operator			
	using ContainOperator = UnsignedInteger8bits[2];	


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but			
	// rather help implement it :																	


	// The following two methods will create an overloaded set to allow choose the correct declaration using substitution faliure is not an error : 					


	// Method Information :
	//
	//	Description :		
	//
	//		This method will be used to notify that the given template type object does not contain the operator						
	//
	//	Required arguments :
	//
	//		User information needed :											
	//
	//			NONE
	//
	//		Information returned to the user :								
	//
	//			NONE
	//
	//	Return value :	
	//
	//		A reference to 'DoesNotContainOperator'																						
	//
	//	Expectations :	
	//
	//		NONE
	//
	//	Possible errors :	
	//
	//		They will come 
	//
	template< typename ObjectToCreateAmbiguityInCaseOperatorDoesExistType >																										
	static DoesNotContainOperator& UseThisToCheckIfTheObjectContainTheOperator( decltype( &ObjectToCreateAmbiguityInCaseOperatorDoesExistType::operator() )* );


	// Method Information :
	//		
	//	Description :		
	//
	//		This method will be used to notify that the given template type object does contain the operator							
	//
	//	Required arguments :
	//
	//		User information needed :											
	//
	//			NONE
	//
	//		Information returned to the user :								
	//
	//			NONE
	//
	//	Return value :	
	//
	//		A reference to 'DoesNotContainOperator'																						
	//
	//	Expectations :	
	//
	//		NONE
	//
	//	Possible errors :	
	//
	//		They will come 
	//
	template< typename ObjectToCreateAmbiguityInCaseOperatorDoesExistType >																										
	static ContainOperator& UseThisToCheckIfTheObjectContainTheOperator( ObjectToCreateAmbiguityInCaseOperatorDoesExistType* );													


	// Static data members do not belong to any instance, they belong to the object. Like every global variable it is created with the start of the program			
	// and only destroyed when the program ends. The access to the static member is bound to this object of course

	// This boolean will contain true if the template type object contains the operator, and false otherwise
	static constexpr Boolean member_containsOperatorOrNot = ( sizeof( UseThisToCheckIfTheObjectContainTheOperator< ObjectToCreateAmbiguityInCaseOperatorDoesExist >( 0UL ) ) == sizeof( ContainOperator ) );


};    // Class OperatorDetector_RoundBrackets




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************************   OperatorDetector for operator '[]'   ***************************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //




// Template Class Information :
//
//  Purpose :
//	
//		Use this object to detect if an object contains an overload for the square brackets operator. The signature of the operator is not important,
//	 	only if the operator exist or not
//
//  Description :
//
// 		1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
//		   providing 3 keywords :
//
//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
//						member is public all the encapsulation is lost, so it should be avoided in most cases
//
//			2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will 
//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few 
//						   data members
//
//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this 											
//						 part will end with the suffix __Private																		
//
//		3. Template arguments :
//
//			1. ObjectToDetectOperatorInsideType - the type of the object that the operator needs to be detected in
//
//  Expectations :
//
//		NONE		
//
//  Possible errors :
//
//		Too many to count
//
template< typename ObjectToDetectOperatorInsideType >
class OperatorDetector_SquareBrackets NotForInheritance
{
public:


	// The following are type definitions of the object and all the provided template arguments :


	// Create a type definition for the first template argument
	using FirstTemplateArgumentType = ObjectToDetectOperatorInsideType;


	// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
	// the compiler generates a basic behavior for them if possible :


	// Method Information :
    //
    //  Description :
	//	
	//		Default Constructor,
	//
	//	Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :																							
	//
	//			NONE
	//
	//	Return value :
	//
	//		NONE
	//
	//	Expectations :
	//
	//		NONE	
	//
	//	Possible errors :
	//
	//		They will come																		
	//
	inline OperatorDetector_SquareBrackets() = default;


	// Method Information :
	//
	//	Description :
	//
	//		Destructor, does not throw
	//
	//	Required arguments :			
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :																							
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE	
	//
	//	Expectations :
	//
	//		NONE	
	//
	//	Possible errors :			
	//
	//		They will come																		
	//
	inline ~OperatorDetector_SquareBrackets() = default;
   				
   				
	// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have		
	// access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring		
	// a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members 	
   				
   				
    // Method Information :		
	//
    //  Description :		 
	//
    //     Use this method to get the static constant expression value inside it														
	//
    //  Required arguments :
	//
    //      User information needed :
	//
    //         NONE
	//
    //      Information returned to the user :								
	//
    //          NONE
	//
    //  Return value :	
	//
    //		A copy of the static constant expression value inside this object will be returned											
	//
    //  Expectations :	
	//
    //      NONE
	//
    //  Possible errors :	
	//
    //      They will come
    //
    constexpr static Boolean Result();					
   				
   				
private:


    // Disable all copy and move related methods												
    DisableCopyAndMove( OperatorDetector_SquareBrackets );
   				
   				
	// The following data members will be used to create a controlled ambiguity. The first is an artifical object that will contain the operator
	// type that the operator needs to be detected in. This way if such an operator does exist in the object, the derived object will contain two
	// operatore of the same kine which will cause ambiguity :


	// This object will be created with the operator that needs to be detected
	class ObjectWithOperatorThatNeedsToBeDetected
	{
	public:

		void operator[]( SignedInteger32bits );

	};											

	// This object will derive from the given template type object that the operator needs to be detected in, and from the object above 
	class ObjectToCreateAmbiguityInCaseOperatorDoesExist : public ObjectWithOperatorThatNeedsToBeDetected, public ObjectToDetectOperatorInsideType
	{};			


	// The following two type definitions will be used as the return types for a set of overloaded functions, that will use the substitution failure is not			
	// an error idiom to make the decision based on the return type size of the function that will be choosen during the resolution of the instantaion :


	// The first type definition of size 1, for objects that does not contain the operator		
	using DoesNotContainOperator = UnsignedInteger8bits[1];																			

	// The second type definition of size 2, for objects that does contain the operator			
	using ContainOperator = UnsignedInteger8bits[2];	


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but			
	// rather help implement it :																	


	// The following two methods will create an overloaded set to allow choose the correct declaration using substitution faliure is not an error : 					


	// Method Information :
	//
	//	Description :		
	//
	//		This method will be used to notify that the given template type object does not contain the operator						
	//
	//	Required arguments :
	//
	//		User information needed :											
	//
	//			NONE
	//
	//		Information returned to the user :								
	//
	//			NONE
	//
	//	Return value :	
	//
	//		A reference to 'DoesNotContainOperator'																						
	//
	//	Expectations :	
	//
	//		NONE
	//
	//	Possible errors :	
	//
	//		They will come 
	//
	template< typename ObjectToCreateAmbiguityInCaseOperatorDoesExistType >																										
	static DoesNotContainOperator& UseThisToCheckIfTheObjectContainTheOperator( decltype( &ObjectToCreateAmbiguityInCaseOperatorDoesExistType::operator[] )* );


	// Method Information :
	//		
	//	Description :		
	//
	//		This method will be used to notify that the given template type object does contain the operator							
	//
	//	Required arguments :
	//
	//		User information needed :											
	//
	//			NONE
	//
	//		Information returned to the user :								
	//
	//			NONE
	//
	//	Return value :	
	//
	//		A reference to 'DoesNotContainOperator'																						
	//
	//	Expectations :	
	//
	//		NONE
	//
	//	Possible errors :	
	//
	//		They will come 
	//
	template< typename ObjectToCreateAmbiguityInCaseOperatorDoesExistType >																										
	static ContainOperator& UseThisToCheckIfTheObjectContainTheOperator( ObjectToCreateAmbiguityInCaseOperatorDoesExistType* );													


	// Static data members do not belong to any instance, they belong to the object. Like every global variable it is created with the start of the program			
	// and only destroyed when the program ends. The access to the static member is bound to this object of course

	// This boolean will contain true if the template type object contains the operator, and false otherwise
	static constexpr Boolean member_containsOperatorOrNot = ( sizeof( UseThisToCheckIfTheObjectContainTheOperator< ObjectToCreateAmbiguityInCaseOperatorDoesExist >( 0UL ) ) == sizeof( ContainOperator ) );


};    // Class OperatorDetector_SquareBrackets




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************************   OperatorDetector for operator '~'   ****************************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //




// Template Class Information :
//
//  Purpose :
//	
//		Use this object to detect if an object contains an overload for the bitwise not operator. The signature of the operator is not important,
//	 	only if the operator exist or not
//
//  Description :
//
// 		1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
//		   providing 3 keywords :
//
//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
//						member is public all the encapsulation is lost, so it should be avoided in most cases
//
//			2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will 
//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few 
//						   data members
//
//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this 											
//						 part will end with the suffix __Private																		
//
//		3. Template arguments :
//
//			1. ObjectToDetectOperatorInsideType - the type of the object that the operator needs to be detected in
//
//  Expectations :
//
//		NONE		
//
//  Possible errors :
//
//		Too many to count
//
template< typename ObjectToDetectOperatorInsideType >
class OperatorDetector_BitwiseNot NotForInheritance
{
public:


	// The following are type definitions of the object and all the provided template arguments :


	// Create a type definition for the first template argument
	using FirstTemplateArgumentType = ObjectToDetectOperatorInsideType;


	// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
	// the compiler generates a basic behavior for them if possible :


	// Method Information :
    //
    //  Description :
	//	
	//		Default Constructor,
	//
	//	Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :																							
	//
	//			NONE
	//
	//	Return value :
	//
	//		NONE
	//
	//	Expectations :
	//
	//		NONE	
	//
	//	Possible errors :
	//
	//		They will come																		
	//
	inline OperatorDetector_BitwiseNot() = default;


	// Method Information :
	//
	//	Description :
	//
	//		Destructor, does not throw
	//
	//	Required arguments :			
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :																							
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE	
	//
	//	Expectations :
	//
	//		NONE	
	//
	//	Possible errors :			
	//
	//		They will come																		
	//
	inline ~OperatorDetector_BitwiseNot() = default;
   				
   				
	// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have		
	// access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring		
	// a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members 	
   				
   				
    // Method Information :		
	//
    //  Description :		 
	//
    //     Use this method to get the static constant expression value inside it														
	//
    //  Required arguments :
	//
    //      User information needed :
	//
    //         NONE
	//
    //      Information returned to the user :								
	//
    //          NONE
	//
    //  Return value :	
	//
    //		A copy of the static constant expression value inside this object will be returned											
	//
    //  Expectations :	
	//
    //      NONE
	//
    //  Possible errors :	
	//
    //      They will come
    //
    constexpr static Boolean Result();					
   				
   				
private:


    // Disable all copy and move related methods												
    DisableCopyAndMove( OperatorDetector_BitwiseNot );
   				
   				
	// The following data members will be used to create a controlled ambiguity. The first is an artifical object that will contain the operator
	// type that the operator needs to be detected in. This way if such an operator does exist in the object, the derived object will contain two
	// operatore of the same kine which will cause ambiguity :


	// This object will be created with the operator that needs to be detected
	class ObjectWithOperatorThatNeedsToBeDetected
	{
	public:

		void operator~();

	};											

	// This object will derive from the given template type object that the operator needs to be detected in, and from the object above 
	class ObjectToCreateAmbiguityInCaseOperatorDoesExist : public ObjectWithOperatorThatNeedsToBeDetected, public ObjectToDetectOperatorInsideType
	{};			


	// The following two type definitions will be used as the return types for a set of overloaded functions, that will use the substitution failure is not			
	// an error idiom to make the decision based on the return type size of the function that will be choosen during the resolution of the instantaion :


	// The first type definition of size 1, for objects that does not contain the operator		
	using DoesNotContainOperator = UnsignedInteger8bits[1];																			

	// The second type definition of size 2, for objects that does contain the operator			
	using ContainOperator = UnsignedInteger8bits[2];	


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but			
	// rather help implement it :																	


	// The following two methods will create an overloaded set to allow choose the correct declaration using substitution faliure is not an error : 					


	// Method Information :
	//
	//	Description :		
	//
	//		This method will be used to notify that the given template type object does not contain the operator						
	//
	//	Required arguments :
	//
	//		User information needed :											
	//
	//			NONE
	//
	//		Information returned to the user :								
	//
	//			NONE
	//
	//	Return value :	
	//
	//		A reference to 'DoesNotContainOperator'																						
	//
	//	Expectations :	
	//
	//		NONE
	//
	//	Possible errors :	
	//
	//		They will come 
	//
	template< typename ObjectToCreateAmbiguityInCaseOperatorDoesExistType >																										
	static DoesNotContainOperator& UseThisToCheckIfTheObjectContainTheOperator( decltype( &ObjectToCreateAmbiguityInCaseOperatorDoesExistType::operator~ )* );


	// Method Information :
	//		
	//	Description :		
	//
	//		This method will be used to notify that the given template type object does contain the operator							
	//
	//	Required arguments :
	//
	//		User information needed :											
	//
	//			NONE
	//
	//		Information returned to the user :								
	//
	//			NONE
	//
	//	Return value :	
	//
	//		A reference to 'DoesNotContainOperator'																						
	//
	//	Expectations :	
	//
	//		NONE
	//
	//	Possible errors :	
	//
	//		They will come 
	//
	template< typename ObjectToCreateAmbiguityInCaseOperatorDoesExistType >																										
	static ContainOperator& UseThisToCheckIfTheObjectContainTheOperator( ObjectToCreateAmbiguityInCaseOperatorDoesExistType* );													


	// Static data members do not belong to any instance, they belong to the object. Like every global variable it is created with the start of the program			
	// and only destroyed when the program ends. The access to the static member is bound to this object of course

	// This boolean will contain true if the template type object contains the operator, and false otherwise
	static constexpr Boolean member_containsOperatorOrNot = ( sizeof( UseThisToCheckIfTheObjectContainTheOperator< ObjectToCreateAmbiguityInCaseOperatorDoesExist >( 0UL ) ) == sizeof( ContainOperator ) );


};    // Class OperatorDetector_BitwiseNot




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************************   OperatorDetector for operator '!'   ****************************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //




// Template Class Information :
//
//  Purpose :
//	
//		Use this object to detect if an object contains an overload for the logical not operator. The signature of the operator is not important,
//	 	only if the operator exist or not
//
//  Description :
//
// 		1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
//		   providing 3 keywords :
//
//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
//						member is public all the encapsulation is lost, so it should be avoided in most cases
//
//			2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will 
//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few 
//						   data members
//
//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this 											
//						 part will end with the suffix __Private																		
//
//		3. Template arguments :
//
//			1. ObjectToDetectOperatorInsideType - the type of the object that the operator needs to be detected in
//
//  Expectations :
//
//		NONE		
//
//  Possible errors :
//
//		Too many to count
//
template< typename ObjectToDetectOperatorInsideType >
class OperatorDetector_LogicalNot NotForInheritance
{
public:


	// The following are type definitions of the object and all the provided template arguments :


	// Create a type definition for the first template argument
	using FirstTemplateArgumentType = ObjectToDetectOperatorInsideType;


	// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
	// the compiler generates a basic behavior for them if possible :


	// Method Information :
    //
    //  Description :
	//	
	//		Default Constructor,
	//
	//	Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :																							
	//
	//			NONE
	//
	//	Return value :
	//
	//		NONE
	//
	//	Expectations :
	//
	//		NONE	
	//
	//	Possible errors :
	//
	//		They will come																		
	//
	inline OperatorDetector_LogicalNot() = default;


	// Method Information :
	//
	//	Description :
	//
	//		Destructor, does not throw
	//
	//	Required arguments :			
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :																							
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE	
	//
	//	Expectations :
	//
	//		NONE	
	//
	//	Possible errors :			
	//
	//		They will come																		
	//
	inline ~OperatorDetector_LogicalNot() = default;
   				
   				
	// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have		
	// access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring		
	// a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members 	
   				
   				
    // Method Information :		
	//
    //  Description :		 
	//
    //     Use this method to get the static constant expression value inside it														
	//
    //  Required arguments :
	//
    //      User information needed :
	//
    //         NONE
	//
    //      Information returned to the user :								
	//
    //          NONE
	//
    //  Return value :	
	//
    //		A copy of the static constant expression value inside this object will be returned											
	//
    //  Expectations :	
	//
    //      NONE
	//
    //  Possible errors :	
	//
    //      They will come
    //
    constexpr static Boolean Result();					
   				
   				
private:


    // Disable all copy and move related methods												
    DisableCopyAndMove( OperatorDetector_LogicalNot );
   				
   				
	// The following data members will be used to create a controlled ambiguity. The first is an artifical object that will contain the operator
	// type that the operator needs to be detected in. This way if such an operator does exist in the object, the derived object will contain two
	// operatore of the same kine which will cause ambiguity :


	// This object will be created with the operator that needs to be detected
	class ObjectWithOperatorThatNeedsToBeDetected
	{
	public:

		void operator!();

	};											

	// This object will derive from the given template type object that the operator needs to be detected in, and from the object above 
	class ObjectToCreateAmbiguityInCaseOperatorDoesExist : public ObjectWithOperatorThatNeedsToBeDetected, public ObjectToDetectOperatorInsideType
	{};			


	// The following two type definitions will be used as the return types for a set of overloaded functions, that will use the substitution failure is not			
	// an error idiom to make the decision based on the return type size of the function that will be choosen during the resolution of the instantaion :


	// The first type definition of size 1, for objects that does not contain the operator		
	using DoesNotContainOperator = UnsignedInteger8bits[1];																			

	// The second type definition of size 2, for objects that does contain the operator			
	using ContainOperator = UnsignedInteger8bits[2];	


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but			
	// rather help implement it :																	


	// The following two methods will create an overloaded set to allow choose the correct declaration using substitution faliure is not an error : 					


	// Method Information :
	//
	//	Description :		
	//
	//		This method will be used to notify that the given template type object does not contain the operator						
	//
	//	Required arguments :
	//
	//		User information needed :											
	//
	//			NONE
	//
	//		Information returned to the user :								
	//
	//			NONE
	//
	//	Return value :	
	//
	//		A reference to 'DoesNotContainOperator'																						
	//
	//	Expectations :	
	//
	//		NONE
	//
	//	Possible errors :	
	//
	//		They will come 
	//
	template< typename ObjectToCreateAmbiguityInCaseOperatorDoesExistType >																										
	static DoesNotContainOperator& UseThisToCheckIfTheObjectContainTheOperator( decltype( &ObjectToCreateAmbiguityInCaseOperatorDoesExistType::operator! )* );


	// Method Information :
	//		
	//	Description :		
	//
	//		This method will be used to notify that the given template type object does contain the operator							
	//
	//	Required arguments :
	//
	//		User information needed :											
	//
	//			NONE
	//
	//		Information returned to the user :								
	//
	//			NONE
	//
	//	Return value :	
	//
	//		A reference to 'DoesNotContainOperator'																						
	//
	//	Expectations :	
	//
	//		NONE
	//
	//	Possible errors :	
	//
	//		They will come 
	//
	template< typename ObjectToCreateAmbiguityInCaseOperatorDoesExistType >																										
	static ContainOperator& UseThisToCheckIfTheObjectContainTheOperator( ObjectToCreateAmbiguityInCaseOperatorDoesExistType* );													


	// Static data members do not belong to any instance, they belong to the object. Like every global variable it is created with the start of the program			
	// and only destroyed when the program ends. The access to the static member is bound to this object of course

	// This boolean will contain true if the template type object contains the operator, and false otherwise
	static constexpr Boolean member_containsOperatorOrNot = ( sizeof( UseThisToCheckIfTheObjectContainTheOperator< ObjectToCreateAmbiguityInCaseOperatorDoesExist >( 0UL ) ) == sizeof( ContainOperator ) );


};    // Class OperatorDetector_LogicalNot




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************************   OperatorDetector for operator '->'   ***************************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //




// Template Class Information :
//
//  Purpose :
//	
//		Use this object to detect if an object contains an overload for the structure dereference operator. The signature of the operator is not 
//		important, only if the operator exist or not
//
//  Description :
//
// 		1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
//		   providing 3 keywords :
//
//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
//						member is public all the encapsulation is lost, so it should be avoided in most cases
//
//			2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will 
//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few 
//						   data members
//
//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this 											
//						 part will end with the suffix __Private																		
//
//		3. Template arguments :
//
//			1. ObjectToDetectOperatorInsideType - the type of the object that the operator needs to be detected in
//
//  Expectations :
//
//		NONE		
//
//  Possible errors :
//
//		Too many to count
//
template< typename ObjectToDetectOperatorInsideType >
class OperatorDetector_StructureDereference NotForInheritance
{
public:


	// The following are type definitions of the object and all the provided template arguments :


	// Create a type definition for the first template argument
	using FirstTemplateArgumentType = ObjectToDetectOperatorInsideType;


	// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
	// the compiler generates a basic behavior for them if possible :


	// Method Information :
    //
    //  Description :
	//	
	//		Default Constructor,
	//
	//	Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :																							
	//
	//			NONE
	//
	//	Return value :
	//
	//		NONE
	//
	//	Expectations :
	//
	//		NONE	
	//
	//	Possible errors :
	//
	//		They will come																		
	//
	inline OperatorDetector_StructureDereference() = default;


	// Method Information :
	//
	//	Description :
	//
	//		Destructor, does not throw
	//
	//	Required arguments :			
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :																							
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE	
	//
	//	Expectations :
	//
	//		NONE	
	//
	//	Possible errors :			
	//
	//		They will come																		
	//
	inline ~OperatorDetector_StructureDereference() = default;
   				
   				
	// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have		
	// access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring		
	// a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members 	
   				
   				
    // Method Information :		
	//
    //  Description :		 
	//
    //     Use this method to get the static constant expression value inside it														
	//
    //  Required arguments :
	//
    //      User information needed :
	//
    //         NONE
	//
    //      Information returned to the user :								
	//
    //          NONE
	//
    //  Return value :	
	//
    //		A copy of the static constant expression value inside this object will be returned											
	//
    //  Expectations :	
	//
    //      NONE
	//
    //  Possible errors :	
	//
    //      They will come
    //
    constexpr static Boolean Result();					
   				
   				
private:


    // Disable all copy and move related methods												
    DisableCopyAndMove( OperatorDetector_StructureDereference );
   				
   				
	// The following data members will be used to create a controlled ambiguity. The first is an artifical object that will contain the operator
	// type that the operator needs to be detected in. This way if such an operator does exist in the object, the derived object will contain two
	// operatore of the same kine which will cause ambiguity :


	// This object will be created with the operator that needs to be detected
	class ObjectWithOperatorThatNeedsToBeDetected
	{
	public:

		void operator->();

	};											

	// This object will derive from the given template type object that the operator needs to be detected in, and from the object above 
	class ObjectToCreateAmbiguityInCaseOperatorDoesExist : public ObjectWithOperatorThatNeedsToBeDetected, public ObjectToDetectOperatorInsideType
	{};			


	// The following two type definitions will be used as the return types for a set of overloaded functions, that will use the substitution failure is not			
	// an error idiom to make the decision based on the return type size of the function that will be choosen during the resolution of the instantaion :


	// The first type definition of size 1, for objects that does not contain the operator		
	using DoesNotContainOperator = UnsignedInteger8bits[1];																			

	// The second type definition of size 2, for objects that does contain the operator			
	using ContainOperator = UnsignedInteger8bits[2];	


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but			
	// rather help implement it :																	


	// The following two methods will create an overloaded set to allow choose the correct declaration using substitution faliure is not an error : 					


	// Method Information :
	//
	//	Description :		
	//
	//		This method will be used to notify that the given template type object does not contain the operator						
	//
	//	Required arguments :
	//
	//		User information needed :											
	//
	//			NONE
	//
	//		Information returned to the user :								
	//
	//			NONE
	//
	//	Return value :	
	//
	//		A reference to 'DoesNotContainOperator'																						
	//
	//	Expectations :	
	//
	//		NONE
	//
	//	Possible errors :	
	//
	//		They will come 
	//
	template< typename ObjectToCreateAmbiguityInCaseOperatorDoesExistType >																										
	static DoesNotContainOperator& UseThisToCheckIfTheObjectContainTheOperator( decltype( &ObjectToCreateAmbiguityInCaseOperatorDoesExistType::operator-> )* );


	// Method Information :
	//		
	//	Description :		
	//
	//		This method will be used to notify that the given template type object does contain the operator							
	//
	//	Required arguments :
	//
	//		User information needed :											
	//
	//			NONE
	//
	//		Information returned to the user :								
	//
	//			NONE
	//
	//	Return value :	
	//
	//		A reference to 'DoesNotContainOperator'																						
	//
	//	Expectations :	
	//
	//		NONE
	//
	//	Possible errors :	
	//
	//		They will come 
	//
	template< typename ObjectToCreateAmbiguityInCaseOperatorDoesExistType >																										
	static ContainOperator& UseThisToCheckIfTheObjectContainTheOperator( ObjectToCreateAmbiguityInCaseOperatorDoesExistType* );													


	// Static data members do not belong to any instance, they belong to the object. Like every global variable it is created with the start of the program			
	// and only destroyed when the program ends. The access to the static member is bound to this object of course

	// This boolean will contain true if the template type object contains the operator, and false otherwise
	static constexpr Boolean member_containsOperatorOrNot = ( sizeof( UseThisToCheckIfTheObjectContainTheOperator< ObjectToCreateAmbiguityInCaseOperatorDoesExist >( 0UL ) ) == sizeof( ContainOperator ) );


};    // Class OperatorDetector_StructureDereference