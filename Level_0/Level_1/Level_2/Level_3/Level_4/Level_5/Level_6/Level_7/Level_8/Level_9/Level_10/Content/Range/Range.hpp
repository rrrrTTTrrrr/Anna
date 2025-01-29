namespace Universe
{



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *************************************************************************   GENERAL DECLRATION    ************************************************************************ //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //




// Template Class Information :
//
//  Purpose :
//
//		This is only a declaration. It declares the general form of the object that will be implemented later in this file. The point is to
//		create multiple objects with the same name, and to choose among them according to the types of the template arguments provided. This
//		is possible using subtitution failure is not an error ( SFAINE ), the general point is that the compiler allow to create functions
//		and objects with invalid signature if at least one other valid signature exist. As can be seen in the declaration below a template
//		argument with default value of 'void' is added. In each implementation of the object, a conditon on this template argument will be
//		tested, and only if the condition is satisfied, then the type 'void' will be provided which will make a valid object. If the condition
//		does not apply the type 'void' will no be provided which will make invalid object. The syntax is as follows :
//
//
//				template< typename Type, typename ImplementationEnabler = void >
//				class Object;
//
//				template< typename Type >
//				class Object< Type, ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_Primitive< Type >::Value() == true >::Type >
//				{
//					Implementation 1
//				}
//
//				template< typename Type >
//				class Object< Type, ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_Primitive< Type >::Value() == false >::Type >
//				{
//					Implementation 2
//				}
//
//
//		In the example if the type is primitive the first implementation will be choosen, and if it is not then the second implementation
//		will be choosen. In this case there were 2 implementations, but this can be applied to as much implementations as wanted
//
//  Description :
//
//		1. Template arguments :
//
//			1. AnyType - Any type
//			2. ImplementationEnabler - a template argument to allow choosing between different implementations based on the given type
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< typename AnyType, typename ImplementationEnabler = void >
class Range;




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *******************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = Numeric   ****************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //




// Class Information :
//
//  Purpose :
//
//		Use this object to create a range of the given template numeric type
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
//			2. Protected - this part is for developing purposes, inheritance. A developer can inherit from this object and it will
//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few
//						   data members
//
//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this
//						 part will end with the suffix __Private
//
//		2. Template arguments :
//
//			1. NumericType - any numeric type
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< Concepts::Numeric NumericType >
class Range< NumericType > NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = Range< NumericType >;


	// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
	// the compiler generates a basic behavior for them if possible :


	// Method Information :
	//
	//  Description :
	//
	//		Default Constructor,
	//
	//  Required arguments :
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
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline Range();


	// Method Information :
	//
	//  Description :
	//
	//		Constructor,
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. minimum - the minimum value for the range 
	//			2. maximum - the maximum value for the range 
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		1. The maximum value is equal or larger then the minimum value
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	explicit inline Range( const NumericType minimum, const NumericType maximum );


	// Method Information :
	//
	//  Description :
	//
	//		Copy constructor, will operate correctly even if the other instance is in default state or self assignment
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a reference to the instance that should be copied
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline Range( const SelfType& other );


	// Add the following infrastructure to the object :
	//
	//		1. Assigenment operator
	//		2. Move constructor
	//		3. Move assigenment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure( Range )


	// Method Information :
	//
	//  Description :
	//
	//		Destructor, does not throw
	//
	//  Required arguments :
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
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline ~Range() = default;


	// This part will contain all the get and set methods for the members of the object :


	GetByValue_Creator( /* GetMethodName */ Minimum, /* MemberName */ member_minimum, /* MemberType */ NumericType )
	GetByValue_Creator( /* GetMethodName */ Maximum, /* MemberName */ member_maximum, /* MemberType */ NumericType )


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the size of the range, or in other words the distance between the minimum to the maximum value
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
	//		The size of the range
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline NumericType Size() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to set the lowest value in the range
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          minimum - the new minimum for the range
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		1. The given minimum is equal or smaller then the current maximum
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void SetMinimum( const NumericType minimum );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to set the highest value in the range
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          maximum - the new maximum for the range
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		1. The given maximum is equal or larger then the current minimum
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void SetMaximum( const NumericType maximum );


	// The following methods declare the overloaded operators for the object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to check if the this instance match the other
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a reference to the instance that should be compared with this object
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		1. true - if the 2 instances are the same
	//		2. false - otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed Boolean operator==( const SelfType& other ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to check if the this instance does not match the other
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a reference to the instance that should be compared with this object
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		1. true - if the 2 instances are not the same
	//		2. false - otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Boolean operator!=( const SelfType& other ) const;


	DEBUG_TOOL(

		// This part of the object is dedicated for testing :


		// Method Information :
		//
		//  Description :
		//
		//		This method is used to test the object. It is not part of the implementation, it is only used to find problems with the code
		//
		//  Required arguments :
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
		static inline void UnitTest() __attribute__ (( __unused__ ));

	)  //  End of debug tool


private:


	// This object will store the minimum of the range
	NumericType member_minimum;

	// This object will store the maximum of the range
	NumericType member_maximum;


};  //  Class Range




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = Object ( Not numeric )   ********************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //




// Class Information :
//
//  Purpose :
//
//		Artifical Inteligence
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
//			2. Protected - this part is for developing purposes, inheritance. A developer can inherit from this object and it will
//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few
//						   data members
//
//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this
//						 part will end with the suffix __Private
//
//		2. Template arguments :
//
//			1.
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< typename ObjectType > requires ( !Concepts::Numeric< ObjectType > )
class Range< ObjectType > NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = Range< ObjectType >;


	// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
	// the compiler generates a basic behavior for them if possible :


	// Method Information :
	//
	//  Description :
	//
	//		Default Constructor,
	//
	//  Required arguments :
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
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline Range();


	// Method Information :
	//
	//  Description :
	//
	//		Constructor,
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. minimum - a constant reference to an instance the represents the minimum value for the range
	//			1. maximum - a constant reference to an instance the represents the maximum value for the range
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		1. The maximum value is equal or larger then the minimum value
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	explicit inline Range( const ObjectType& minimum, const ObjectType& maximum );


	// Method Information :
	//
	//  Description :
	//
	//		Copy constructor, will operate correctly even if the other instance is in default state or self assignment
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a reference to the instance that should be copied
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline Range( const SelfType& other );


	// Add the following infrastructure to the object :
	//
	//		1. Assigenment operator
	//		2. Move constructor
	//		3. Move assigenment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure( Range )


	// Method Information :
	//
	//  Description :
	//
	//		Destructor, does not throw
	//
	//  Required arguments :
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
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline ~Range() = default;


	// This part will contain all the get and set methods for the members of the object :


	GetByConstantReference_Creator( /* GetMethodName */ Minimum, /* MemberName */ member_instanceThatRepresentsTheMinimum, /* MemberType */ ObjectType )
	GetByConstantReference_Creator( /* GetMethodName */ Maximum, /* MemberName */ member_instanceThatRepresentsTheMaximum, /* MemberType */ ObjectType )


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to set the lowest value in the range
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          minimum - the new minimum for the range
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		1. The given minimum is equal or smaller then the current maximum
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void SetMinimum( const ObjectType& minimum );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to set the highest value in the range
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          maximum - the new maximum for the range
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		1. The given maximum is equal or larger then the current minimum
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void SetMaximum( const ObjectType& maximum );


	// The following methods declare the overloaded operators for the object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to check if the this instance match the other
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a reference to the instance that should be compared with this object
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		1. true - if the 2 instances are the same
	//		2. false - otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed Boolean operator==( const SelfType& other ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to check if the this instance does not match the other
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a reference to the instance that should be compared with this object
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		1. true - if the 2 instances are not the same
	//		2. false - otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Boolean operator!=( const SelfType& other ) const;


	DEBUG_TOOL(

		// This part of the object is dedicated for testing :


		// Method Information :
		//
		//  Description :
		//
		//		This method is used to test the object. It is not part of the implementation, it is only used to find problems with the code
		//
		//  Required arguments :
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
		static inline void UnitTest() __attribute__ (( __unused__ )) { Range< UnsignedInteger64bits >::UnitTest(); }

	)  //  End of debug tool


private:


	// This object will store an instance of the object, that represents the minimum of the object. In other words this instance when used
	// as part of a comparison with another instance using the '<' or '>' will always result as smaller
	ObjectType member_instanceThatRepresentsTheMinimum;

	// This object will store an instance of the object, that represents the maximum of the object. In other words this instance when used
	// as part of a comparison with another instance using the '<' or '>' will always result as larger
	ObjectType member_instanceThatRepresentsTheMaximum;


};  //  Class Range