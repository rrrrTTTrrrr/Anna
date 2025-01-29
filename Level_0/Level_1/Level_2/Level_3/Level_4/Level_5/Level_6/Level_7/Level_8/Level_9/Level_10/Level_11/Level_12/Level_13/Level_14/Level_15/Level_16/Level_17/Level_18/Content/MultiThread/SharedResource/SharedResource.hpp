namespace Universe
{


namespace MultiThread
{



// If a template-parameter of a class template or alias template has a default template-argument, each subsequent template-parameter shall 
// either have a default template-argument supplied or be a template parameter pack. If a template-parameter of a primary class template or
// alias template is a template parameter pack, it shall be the last template-parameter. A template parameter pack of a function template
// shall not be followed by another template parameter unless that template parameter can be deduced or has a default argument



// In order to take the address of an overloaded method, use static cast :
//
//		static_cast< void (ObjectType::*)( int ) >( &ObjectType::MethodName )
//
//		static_cast< void (ObjectType::*)( int, long ) >( &ObjectType::MethodName )



// When dynamically allocating an array, the values are undefined :
//
//		UnsignedInteger64bits* memoryAddress = new UnsignedInteger64bits[ 98 ];
//
// But there is a way to invoke the default constructor, on each element of the memory : 
//
//		UnsignedInteger64bits* memoryAddress = new UnsignedInteger64bits[ 98 ]();
//
// This in the case of integers for example, will set all the values to 0. This works only for default constructor, the following is
// an error :
//
//		UnsignedInteger64bits* memoryAddress = new UnsignedInteger64bits[ 98 ]( 1 );  //  Error - will not compile




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
template< typename Type >
class SharedResource
{
private:


	// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
	NoInstances( SharedResource );


};




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ********************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = Built in   **************************************************** //
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
template< Concepts::BuiltIn BuiltInType >
class SharedResource< BuiltInType > NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = SharedResource< BuiltInType >;


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
	inline SharedResource();


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
	//			value - a constant reference to the value that will be used to initialize the resource
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
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2.
	//
	explicit inline SharedResource( const BuiltInType& value );


	// Add the following infrastructure to the object :
	//
	//		1. Reset
	//
	Reset_Creator( inline )


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
	inline ~SharedResource() = default;


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to perform an action on the resource. The action must not change the resource, and only view it
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. invokableObject - a universal reference to an invokable object, the signature of the function that will be called must be :
	//
	//					AnyReturnType Function( const BuiltInType&, AdditionalArgumentTypes... )
	//
	//          2. additionalArguments - any additional arguments needed
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      The result from performing the action on the resource
	//
	//  Expectations :
	//
	//		1. The resource will not be changed by the action
	//		2. 
	//
	//  Possible errors :
	//
	//      1. The given invokable object might throw any exception it sees fit
	//		2.
	//
	template< typename ReturnType, typename... AdditionalArgumentTypes >
	EnsureRetrunValueIsUsed inline ReturnType View( const Callable< ReturnType ( const BuiltInType&, AdditionalArgumentTypes... ) >& callable, AdditionalArgumentTypes... additionalArguments );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to perform an action on the resource. The action can change the resource
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. invokableObject - a universal reference to an invokable object, the signature of the function that will be called must be :
	//
	//					AnyReturnType Function( BuiltInType&, AdditionalArgumentTypes... )
	//
	//          2. additionalArguments - any additional arguments needed
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      The result from performing the action on the resource
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//      1. The given invokable object might throw any exception it sees fit
	//		2.
	//
	template< typename ReturnType, typename... AdditionalArgumentTypes >
	EnsureRetrunValueIsUsed inline ReturnType Edit( const Callable< ReturnType ( BuiltInType&, AdditionalArgumentTypes... ) >& callable, AdditionalArgumentTypes... additionalArguments );


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
	EnsureRetrunValueIsUsed inline Boolean operator==( const SelfType& other ) const;


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


    // This macro will add to objects, that deal with numeric types as data members, all the operators C++ had to offer for each numeric 
    // type. This will make the object appear as the data itself, to some extent
	AddAllOperatorsToObject( member_resource, BuiltInType, ConsiderAsOneArgument( ScopedViewAndEditSynchronization ensureResourceWillNotBeEditedDuringCopyConstruction( member_viewAndEditSynchronization ); ), ConsiderAsOneArgument( ScopedViewAndEditSynchronization ensureResourceWillNotBeEditedDuringCopyConstruction( member_viewAndEditSynchronization, true ); ) )


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


	// Disable all copy and move related methods, this include the copy constructor, move constructor, assignment operator and move assignment operator
	DisableCopyAndMove( SharedResource );


	// This object will store the resource
	BuiltInType member_resource;

	// This object will store the memory address of the synchronization tool for accessing the resource
	ViewAndEditSynchronization member_viewAndEditSynchronization;


};  //  Class SharedResource




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = Not built int   ************************************************** //
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
template< Concepts::NotBuiltIn ObjectType >
class SharedResource< ObjectType > NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = SharedResource< ObjectType >;


	// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
	// the compiler generates a basic behavior for them if possible :


	// Method Information :
	//
	//  Description :
	//
	//		Default constructor,
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
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2.
	//
	inline SharedResource();


	// Method Information :
	//
	//  Description :
	//
	//		Constructor, to allow creating the resource from arguments
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. The first argument purpose is to ensure this constructor will be called by setting a special type
	//			2. argumentsNeededToConstructTheResource - any arguments required to construct the resource
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
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2.
	//
	template< typename... ArgumentNeededToConstructTheResourceTypes >
	inline SharedResource( BuildResourceFromArguments, ArgumentNeededToConstructTheResourceTypes&&... argumentsNeededToConstructTheResource );


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
	//			resource - a constant reference to the resource
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
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2.
	//
	explicit inline SharedResource( const ObjectType& resource );


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
	//			resource - an rvalue reference to the resource
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
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2.
	//
	explicit inline SharedResource( ObjectType&& resource );


	// Add the following infrastructure to the object :
	//
	//		1. Reset
	//
	Reset_Creator( inline )


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
	inline ~SharedResource() = default;


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to perform an action on the resource. The action must not change the resource, and only view it
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. invokableObject - a universal reference to an invokable object, the signature of the function that will be called must be :
	//
	//					AnyReturnType Function( const ObjectType&, AdditionalArgumentTypes... )
	//
	//          2. additionalArguments - any additional arguments needed
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      The result from performing the action on the resource
	//
	//  Expectations :
	//
	//		1. The resource will not be changed by the action
	//		2. 
	//
	//  Possible errors :
	//
	//      1. The given invokable object might throw any exception it sees fit
	//		2.
	//
	template< typename ReturnType, typename... AdditionalArgumentTypes >
	EnsureRetrunValueIsUsed inline ReturnType View( const Callable< ReturnType ( const ObjectType&, AdditionalArgumentTypes... ) >& callable, AdditionalArgumentTypes... additionalArguments );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to perform an action on the resource. The action can change the resource
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. invokableObject - a universal reference to an invokable object, the signature of the function that will be called must be :
	//
	//					AnyReturnType Function( ObjectType&, AdditionalArgumentTypes... )
	//
	//          2. additionalArguments - any additional arguments needed
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      The result from performing the action on the resource
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//      1. The given invokable object might throw any exception it sees fit
	//		2.
	//
	template< typename ReturnType, typename... AdditionalArgumentTypes >
	EnsureRetrunValueIsUsed inline ReturnType Edit( const Callable< ReturnType ( ObjectType&, AdditionalArgumentTypes... ) >& callable, AdditionalArgumentTypes... additionalArguments );


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
	EnsureRetrunValueIsUsed inline Boolean operator==( const SelfType& other ) const;


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


	// Disable all copy and move related methods, this include the copy constructor, move constructor, assignment operator and move assignment operator
	DisableCopyAndMove( SharedResource );


	// This object will store the resource
	ObjectType member_resource;

	// This object will store the memory address of the synchronization tool for accessing the resource
	ViewAndEditSynchronization member_viewAndEditSynchronization;


};  //  Class SharedResource