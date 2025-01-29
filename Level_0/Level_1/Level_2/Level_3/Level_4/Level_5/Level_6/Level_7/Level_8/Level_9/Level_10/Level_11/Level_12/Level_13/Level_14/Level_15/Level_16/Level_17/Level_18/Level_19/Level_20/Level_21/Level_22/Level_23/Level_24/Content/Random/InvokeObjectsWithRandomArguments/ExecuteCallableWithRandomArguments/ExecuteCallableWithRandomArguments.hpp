namespace Universe
{


namespace Random
{



// Template Class Information :
//
//  Purpose :
//
//		Use this object to store the memory address of a specific method, and allowing to invoke it during run time. The difference between a
//		function and method, is that method is a function that belongs to an object
//
//  Description :
//
//		1. This object contains an instance of the object "State" to allow each instance of this object to have a defined state
//
// 		2. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
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
//			1. ObjectType - the type of the object the method belongs to
//			2. ReturnType - the return value type of the required function
//			3. MethodArgumentTypes - the arguments types of the required function
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< typename FunctionType >
class ExecuteCallableWithRandomArguments
{
private:


	// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
	NoInstances( ExecuteCallableWithRandomArguments );


};



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *********************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - To allow deducing the return and function argument types   ********************************** //
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
template< typename ReturnType, typename... ArgumentTypes >
class ExecuteCallableWithRandomArguments< ReturnType ( ArgumentTypes... ) > NotForInheritance
{
public:


	// Create a type definition for the function
	using SelfFunctionType = ReturnType ( ArgumentTypes... );

	// Create a type definition for this object
	using SelfType = ExecuteCallableWithRandomArguments< SelfFunctionType >;


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
	inline ExecuteCallableWithRandomArguments();


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
	//			callable - a constant reference to a callable instance
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
	//		1. The callable instance is ready
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline ExecuteCallableWithRandomArguments( const Callable< SelfFunctionType >& callable );


	// Add the following infrastructure to the object :
	//
	//		1. Move constructor
	//		2. Move assigenment operator
	//		3. Swap
	//		4. Reset
	//
	ObjectInfrastructureWithoutTheAbilityToCopyItself( ExecuteCallableWithRandomArguments )


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
	inline ~ExecuteCallableWithRandomArguments() = default;


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the number of times the function was invoked using random arguments
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
	//		The number of times the function was invoked using random arguments
	//
	//  Expectations :
	//
	//		NONE 
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline LargestUnsignedInteger NumberOfExecutions() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to invoke the function using random generated arguments
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			constraintsOnRandomArguments - any constraints needed on creating the random arguments
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
	//		1. The instance is ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< typename... ConstraintsOnRandomArgumentsTypes >
	inline void Invoke( ConstraintsOnRandomArgumentsTypes... constraintsOnRandomArguments );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to invoke the function using random generated arguments
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
	//		1. The instance is ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	inline void Invoke();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to invoke the function multiple times using random generated arguments
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. numberOfTimesToInvoke - the number of times to invoke the function
	//			2. constraintsOnRandomArguments - any constraints needed on creating the random arguments
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
	//		1. The instance is ready
	//		2. The number of times to invoke the function is larger then 0
	//		3. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< typename... ConstraintsOnRandomArgumentsTypes >
	inline void InvokeMultipleTimes( const LargestUnsignedInteger numberOfTimesToInvoke, ConstraintsOnRandomArgumentsTypes... constraintsOnRandomArguments );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get information on an invocation of the function
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			index - the index of the required invocation of the function
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		Information on an invocation of the function
	//
	//  Expectations :
	//
	//		1. The instance has invoked the function enough times that the index is valid
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline const CallableExecutionInformation< SelfFunctionType >& ExecutionInformation( const LargestUnsignedInteger index ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get information on the last invocation of the function
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
	//		Information on the last invocation of the function
	//
	//  Expectations :
	//
	//		1. The instance has invoked the function at least one time
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline const CallableExecutionInformation< SelfFunctionType >& LastInvocationInformation() const;


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
	DisableCopyConstructorAndAssignmentOperator( ExecuteCallableWithRandomArguments );


	// This object will store the invokable object
	const Callable< SelfFunctionType >* member_callablePointer;

	// This object will store the following properties on each invokation of the function :
	//
	//	1. The random arguments generated to invoke the function
	//	2. The return value, if no exception was thrown
	//	3. If an exception was thrown
	//	4. The error message in case an exception was thrown
	//
	SequentialDataStructure< CallableExecutionInformation< SelfFunctionType > > member_history;


};  //  Class ExecuteCallableWithRandomArguments




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ********************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - To allow deducing the return type   ********************************************** //
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
template< typename ReturnType >
class ExecuteCallableWithRandomArguments< ReturnType () > NotForInheritance
{
public:


	// Create a type definition for the function
	using SelfFunctionType = ReturnType ();

	// Create a type definition for this object
	using SelfType = ExecuteCallableWithRandomArguments< SelfFunctionType >;


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
	inline ExecuteCallableWithRandomArguments();


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
	//			callable - a constant reference to a callable instance
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
	//		1. The callable instance is ready
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline ExecuteCallableWithRandomArguments( const Callable< SelfFunctionType >& callable );


	// Add the following infrastructure to the object :
	//
	//		1. Move constructor
	//		2. Move assigenment operator
	//		3. Swap
	//		4. Reset
	//
	ObjectInfrastructureWithoutTheAbilityToCopyItself( ExecuteCallableWithRandomArguments )


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
	inline ~ExecuteCallableWithRandomArguments() = default;


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the number of times the function was invoked using random arguments
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
	//		The number of times the function was invoked using random arguments
	//
	//  Expectations :
	//
	//		NONE 
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline LargestUnsignedInteger NumberOfExecutions() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to invoke the function using random generated arguments
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			constraintsOnRandomArguments - any constraints needed on creating the random arguments
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
	//		1. The instance is ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	inline void Invoke();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to invoke the function multiple times using random generated arguments
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			numberOfTimesToInvoke - the number of times to invoke the function
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
	//		1. The instance is ready
	//		2. The number of times to invoke the function is larger then 0
	//		3. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	inline void InvokeMultipleTimes( const LargestUnsignedInteger numberOfTimesToInvoke );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get information on an invocation of the function
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			index - the index of the required invocation of the function
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		Information on an invocation of the function
	//
	//  Expectations :
	//
	//		1. The instance has invoked the function enough times that the index is valid
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline const CallableExecutionInformation< SelfFunctionType >& ExecutionInformation( const LargestUnsignedInteger index ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get information on the last invocation of the function
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
	//		Information on the last invocation of the function
	//
	//  Expectations :
	//
	//		1. The instance has invoked the function at least one time
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline const CallableExecutionInformation< SelfFunctionType >& LastInvocationInformation() const;


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
		static inline void UnitTest() __attribute__ (( __unused__ )) { ExecuteCallableWithRandomArguments< LargestUnsignedInteger ( LargestUnsignedInteger ) >::UnitTest(); }

	)  //  End of debug tool


private:


	// Disable all the abilites of the object to copy itself, this include the copy constructor and assignment operator
	DisableCopyConstructorAndAssignmentOperator( ExecuteCallableWithRandomArguments );


	// This object will store the invokable object
	const Callable< SelfFunctionType >* member_callablePointer;

	// This object will store the following properties on each invokation of the function :
	//
	//	1. The random arguments generated to invoke the function
	//	2. The return value, if no exception was thrown
	//	3. If an exception was thrown
	//	4. The error message in case an exception was thrown
	//
	SequentialDataStructure< CallableExecutionInformation< SelfFunctionType > > member_history;


};  //  Class ExecuteCallableWithRandomArguments



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// **************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - To allow deducing the function argument types   **************************************** //
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
template< typename... ArgumentTypes >
class ExecuteCallableWithRandomArguments< void ( ArgumentTypes... ) > NotForInheritance
{
public:


	// Create a type definition for the function
	using SelfFunctionType = void ( ArgumentTypes... );

	// Create a type definition for this object
	using SelfType = ExecuteCallableWithRandomArguments< SelfFunctionType >;


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
	inline ExecuteCallableWithRandomArguments();


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
	//			callable - a constant reference to a callable instance
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
	//		1. The callable instance is ready
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline ExecuteCallableWithRandomArguments( const Callable< SelfFunctionType >& callable );


	// Add the following infrastructure to the object :
	//
	//		1. Move constructor
	//		2. Move assigenment operator
	//		3. Swap
	//		4. Reset
	//
	ObjectInfrastructureWithoutTheAbilityToCopyItself( ExecuteCallableWithRandomArguments )


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
	inline ~ExecuteCallableWithRandomArguments() = default;


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the number of times the function was invoked using random arguments
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
	//		The number of times the function was invoked using random arguments
	//
	//  Expectations :
	//
	//		NONE 
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline LargestUnsignedInteger NumberOfExecutions() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to invoke the function using random generated arguments
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			constraintsOnRandomArguments - any constraints needed on creating the random arguments
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
	//		1. The instance is ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< typename... ConstraintsOnRandomArgumentsTypes >
	inline void Invoke( ConstraintsOnRandomArgumentsTypes... constraintsOnRandomArguments );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to invoke the function using random generated arguments
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
	//		1. The instance is ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	inline void Invoke();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to invoke the function multiple times using random generated arguments
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. numberOfTimesToInvoke - the number of times to invoke the function
	//			2. constraintsOnRandomArguments - any constraints needed on creating the random arguments
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
	//		1. The instance is ready
	//		2. The number of times to invoke the function is larger then 0
	//		3. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< typename... ConstraintsOnRandomArgumentsTypes >
	inline void InvokeMultipleTimes( const LargestUnsignedInteger numberOfTimesToInvoke, ConstraintsOnRandomArgumentsTypes... constraintsOnRandomArguments );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get information on an invocation of the function
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			index - the index of the required invocation of the function
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		Information on an invocation of the function
	//
	//  Expectations :
	//
	//		1. The instance has invoked the function enough times that the index is valid
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline const CallableExecutionInformation< SelfFunctionType >& ExecutionInformation( const LargestUnsignedInteger index ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get information on the last invocation of the function
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
	//		Information on the last invocation of the function
	//
	//  Expectations :
	//
	//		1. The instance has invoked the function at least one time
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline const CallableExecutionInformation< SelfFunctionType >& LastInvocationInformation() const;


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
	DisableCopyConstructorAndAssignmentOperator( ExecuteCallableWithRandomArguments );


	// This object will store the invokable object
	const Callable< SelfFunctionType >* member_callablePointer;

	// This object will store the following properties on each invokation of the function :
	//
	//	1. The random arguments generated to invoke the function
	//	2. The return value, if no exception was thrown
	//	3. If an exception was thrown
	//	4. The error message in case an exception was thrown
	//
	SequentialDataStructure< CallableExecutionInformation< SelfFunctionType > > member_history;


};  //  Class ExecuteCallableWithRandomArguments



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *********************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - No return or function arguments   *********************************************** //
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
template<>
class ExecuteCallableWithRandomArguments< void () > NotForInheritance
{
public:


	// Create a type definition for the function
	using SelfFunctionType = void ();

	// Create a type definition for this object
	using SelfType = ExecuteCallableWithRandomArguments< SelfFunctionType >;


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
	inline ExecuteCallableWithRandomArguments();


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
	//			callable - a constant reference to a callable instance
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
	//		1. The callable instance is ready
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline ExecuteCallableWithRandomArguments( const Callable< SelfFunctionType >& callable );


	// Add the following infrastructure to the object :
	//
	//		1. Move constructor
	//		2. Move assigenment operator
	//		3. Swap
	//		4. Reset
	//
	ObjectInfrastructureWithoutTheAbilityToCopyItself( ExecuteCallableWithRandomArguments )


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
	inline ~ExecuteCallableWithRandomArguments() = default;


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the number of times the function was invoked using random arguments
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
	//		The number of times the function was invoked using random arguments
	//
	//  Expectations :
	//
	//		NONE 
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline LargestUnsignedInteger NumberOfExecutions() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to invoke the function using random generated arguments
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			constraintsOnRandomArguments - any constraints needed on creating the random arguments
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
	//		1. The instance is ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	inline void Invoke();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to invoke the function multiple times using random generated arguments
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			numberOfTimesToInvoke - the number of times to invoke the function
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
	//		1. The instance is ready
	//		2. The number of times to invoke the function is larger then 0
	//		3. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	inline void InvokeMultipleTimes( const LargestUnsignedInteger numberOfTimesToInvoke );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get information on an invocation of the function
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			index - the index of the required invocation of the function
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		Information on an invocation of the function
	//
	//  Expectations :
	//
	//		1. The instance has invoked the function enough times that the index is valid
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline const CallableExecutionInformation< SelfFunctionType >& ExecutionInformation( const LargestUnsignedInteger index ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get information on the last invocation of the function
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
	//		Information on the last invocation of the function
	//
	//  Expectations :
	//
	//		1. The instance has invoked the function at least one time
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline const CallableExecutionInformation< SelfFunctionType >& LastInvocationInformation() const;


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
		static inline void UnitTest() __attribute__ (( __unused__ )) { ExecuteCallableWithRandomArguments< LargestUnsignedInteger ( LargestUnsignedInteger ) >::UnitTest(); }

	)  //  End of debug tool


private:


	// Disable all the abilites of the object to copy itself, this include the copy constructor and assignment operator
	DisableCopyConstructorAndAssignmentOperator( ExecuteCallableWithRandomArguments );


	// This object will store the invokable object
	const Callable< SelfFunctionType >* member_callablePointer;

	// This object will store the following properties on each invokation of the function :
	//
	//	1. The random arguments generated to invoke the function
	//	2. The return value, if no exception was thrown
	//	3. If an exception was thrown
	//	4. The error message in case an exception was thrown
	//
	SequentialDataStructure< CallableExecutionInformation< SelfFunctionType > > member_history;


};  //  Class ExecuteCallableWithRandomArguments
