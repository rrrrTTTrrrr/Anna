namespace Universe
{



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
template< typename FunctorType, typename ReturnType, typename... ArgumentTypes > requires ( Concepts::FunctorWithSpecificReturnType< FunctorType, ReturnType, ArgumentTypes... > )
class InvokableObjectInterfaceWrapper : public InvokableObjectInterface< ReturnType, ArgumentTypes... >
{
public:


	// Create a type definition for this object
	using SelfType = InvokableObjectInterfaceWrapper< FunctorType, ReturnType, ArgumentTypes... >;


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
	inline InvokableObjectInterfaceWrapper();


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
	//			functor - a reference to the functor instance
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
	explicit inline InvokableObjectInterfaceWrapper( FunctorType& functor );


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
	//			functor - a constant reference to the functor instance
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
	explicit inline InvokableObjectInterfaceWrapper( const FunctorType& functor );


	// Add the following infrastructure to the object :
	//
	//		1. Move constructor
	//		2. Move assigenment operator
	//		3. Swap
	//		4. Reset
	//
	ObjectInfrastructureWithoutTheAbilityToCopyItself_ForInheritance( InvokableObjectInterfaceWrapper )


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
	virtual ~InvokableObjectInterfaceWrapper() = default;


	// The following methods declare the overloaded operators for the object :


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to invoke the function pointed to be this instance, using the given arguments. This operator will give instances of
	//		this object the ability to be used as if they are functions
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			arguments - the arguments required to invoke the function the instance points too
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The return value from calling the function
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. The given function failes and throws an exception
	//		2.
	//
	EnsureRetrunValueIsUsed virtual ReturnType operator()( ArgumentTypes... arguments ) override;


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to invoke the function pointed to be this instance, using the given arguments. This operator will give instances of
	//		this object the ability to be used as if they are functions. This version is for constant instances
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			arguments - the arguments required to invoke the function the instance points too
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The return value from calling the function
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. The given function failes and throws an exception
	//		2.
	//
	EnsureRetrunValueIsUsed virtual ReturnType operator()( ArgumentTypes... arguments ) const override;


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


	// Disable all the abilites of the object to copy itself, this include the copy constructor and assignment operator
	DisableCopyConstructorAndAssignmentOperator( InvokableObjectInterfaceWrapper );


	// This object will store the template functor type instance
	FunctorType* member_functorPointer;

	// This object will store the template functor type instance if constant
	const FunctorType* member_constantFunctorPointer;


};  //  Class InvokableObjectInterfaceWrapper