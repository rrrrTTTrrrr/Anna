namespace Universe
{


namespace MultiThread
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
template< typename Type >
class CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource
{
private:


	// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
	NoInstances( CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource );


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
class CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource< BuiltInType > NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource< BuiltInType >;


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
	inline CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource();


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
	explicit inline CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource( const BuiltInType& value );


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
	inline ~CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource() = default;


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to compare the value stored in this instance with the other value. In case the comparison is true, the required
	//		new value will be stored in this instance instead
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	// 			1. expectedValue - the current value inside this instance will be compared with this value
	//			2. desiredValue - this value will be stored inside this instance instead of the current one if the comparison is true 
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A boolean with the value true in case the comparison result was true, and false otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Boolean CompareTheActualValueWithTheExpectedAndIfEqualSetTheDesiredValue( const BuiltInType expectedValue, const BuiltInType desiredValue );


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
	//					AnyReturnType Function( const BuiltInType&, ArgumentTypes... )
	//
	//          2. arguments - any additional arguments needed
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
	template< typename InvokableObjectType, typename ReturnType, typename... ArgumentTypes >
	EnsureRetrunValueIsUsed inline ReturnType View( InvokableObjectType&& invokableObject, ArgumentTypes&&... arguments );


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
	//					AnyReturnType Function( BuiltInType&, ArgumentTypes... )
	//
	//          2. arguments - any additional arguments needed
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
	template< typename InvokableObjectType, typename ReturnType, typename... ArgumentTypes >
	EnsureRetrunValueIsUsed inline ReturnType Edit( InvokableObjectType&& invokableObject, ArgumentTypes&&... arguments );


	// The following methods declare the overloaded operators for the object :


    // This macro will add to objects, that deal with numeric types as data members, all the operators C++ had to offer for each numeric 
    // type. This will make the object appear as the data itself, to some extent
	AddAllOperatorsToObject( member_resource, BuiltInType, ConsiderAsOneArgument( ScopedSpinWaitLoop ensureOnlyThisThreadOfExecutionWillUseTheResource( &member_spinWaitLoop ); ), ConsiderAsOneArgument( ScopedSpinWaitLoop ensureOnlyThisThreadOfExecutionWillUseTheResource( &member_spinWaitLoop ); ) )


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
	DisableCopyAndMove( CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource );


	// This object will store the memory address of the resource
	BuiltInType member_resource;

	// This object will store the memory address of the synchronization tool for accessing the resource
	CentralProcessingUnit::SpinWaitLoop member_spinWaitLoop;


};  //  Class CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource




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
class CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource< ObjectType > NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource< ObjectType >;


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
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2.
	//
	inline CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource();


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
	inline CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource( BuildResourceFromArguments, ArgumentNeededToConstructTheResourceTypes&&... argumentsNeededToConstructTheResource );


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
	explicit inline CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource( const ObjectType& resource );


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
	explicit inline CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource( ObjectType&& resource );


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
	inline ~CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource() = default;


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to compare the resource stored in this instance with the other resource. In case the comparison is true, the required
	//		new resource will be stored in this instance instead
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	// 			1. resourceToCompareWith - the current resource inside this instance will be compared with this resource
	//			2. resourceToSetIfComparisonTrue - this resource will be stored inside this instance instead of the current one if the comparison is true 
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A boolean with the resource true in case the comparison result was true, and false otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename UniversalReferenceResourceObjectType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceResourceObjectType, ObjectType >::Result == true )
	EnsureRetrunValueIsUsed inline Boolean CompareTheActualValueWithTheExpectedAndIfEqualSetTheDesiredValue( const ObjectType& resourceToCompareWith, UniversalReferenceResourceObjectType&& resourceToSetIfComparisonTrue );


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
	//					AnyReturnType Function( const ObjectType&, ArgumentTypes... )
	//
	//          2. arguments - any additional arguments needed
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
	template< typename InvokableObjectType, typename ReturnType, typename... ArgumentTypes >
	EnsureRetrunValueIsUsed inline ReturnType View( InvokableObjectType&& invokableObject, ArgumentTypes&&... arguments );


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
	//					AnyReturnType Function( ObjectType&, ArgumentTypes... )
	//
	//          2. arguments - any additional arguments needed
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
	template< typename InvokableObjectType, typename ReturnType, typename... ArgumentTypes >
	EnsureRetrunValueIsUsed inline ReturnType Edit( InvokableObjectType&& invokableObject, ArgumentTypes&&... arguments );


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
	DisableCopyAndMove( CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource );


	// This object will store the memory address of the resource
	ObjectType member_resource;

	// This object will store the memory address of the synchronization tool for accessing the resource
	CentralProcessingUnit::SpinWaitLoop member_spinWaitLoop;


};  //  Class CoherentSystemMemoryAndCacheAcrossAllSharingCentralProcessingUnitsResource