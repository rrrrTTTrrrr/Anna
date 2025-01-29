namespace Universe
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
//			3. ArgumentTypes - the arguments types of the required function
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< typename ObjectType, typename FunctionType >
class MethodPointerBoundToInstance
{};



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// **************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Method with arguments   **************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



// Template Class Information :
//
//  Purpose :
//
//		Use this object to store the memory address of a specific method, and allowing to invoke it during run time. The difference between a
//		function and method, is that method is a function that belongs to an object. This object also stores an instance of the object that
//		the method belongs to, to operate on
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
//			3. ArgumentTypes - the arguments types of the required function
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< typename ObjectType, typename ReturnType, typename... ArgumentTypes >
class MethodPointerBoundToInstance< ObjectType, ReturnType ( ArgumentTypes... ) > : public BaseInvokableObject< ReturnType, ArgumentTypes... >, public InvokableObjectInterface< ReturnType, ArgumentTypes... >
{
public:


	// Create a type definition for this object
	using SelfType = MethodPointerBoundToInstance< ObjectType, ReturnType ( ArgumentTypes... ) >;

	// Create a type definition for the method using the specific given template arguments
	using MethodPointerType = ReturnType ( ObjectType::* )( ArgumentTypes... );


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
	//      Information returned to the user :
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
	inline MethodPointerBoundToInstance();


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
	//			1. instance - the memory address of an instance of the object that the method belongs to
	//			2. methodRawPointer - the memory address of the method to call
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
	//		1. The given pointer to the method should not be NULL
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	explicit inline MethodPointerBoundToInstance( ObjectType& instance, MethodPointerType const methodRawPointer );


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
	//			other - a reference to the instance that should be copied
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
	inline MethodPointerBoundToInstance( const SelfType& other );


	// This macro will be used to all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
	// simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
	// any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
	// be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
	// macro will be used to add the following methods to each object :
	//
	//		1. Assignment operator
	//		2. Move constructor
	//		3. Move assignment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure_ForInheritance( MethodPointerBoundToInstance )


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
	//      Information returned to the user :
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
	virtual ~MethodPointerBoundToInstance() = default;


	// The following methods declare the overloaded operators for the object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to invoke the method pointed to by this instance, on an instance of an object that the method belongs too, using the
	//		given arguments. This operator will give instances of this object the ability to be used as if they are functions
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			arguments - the arguments required to invoke the method the instance points too
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The return value from calling the method
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
	//		Use this operator to invoke the method pointed to by this instance, on an instance of an object that the method belongs too, using the
	//		given arguments. This operator will give instances of this object the ability to be used as if they are functions
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			arguments - the arguments required to invoke the method the instance points too
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The return value from calling the method
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


    // Method Information :
    //
    //  Description :
    //
	//		Use this operator to invoke the method pointed to by this instance, on an instance of an object that the method belongs too, using a 
	//		tuple of arguments. This operator will give instances of this object the ability to be used as if they are functions. Now to invoke a 
	//		function using a tuple, the syntax is as follows :
    //
    //				MethodSomething( tupleInstance.Entry< 0 >(), tupleInstance.Entry< 1 >(), tupleInstance.Entry< 2 >() );
    //
    //      To avoid writing all the arguments by hand, parameter pack expansion exist. To use it an integer sequence needs to be passed to the function. 
    //		This sequence will be used to unpack the tuple of arguments, and allow an easy invoke of the function :
    //
    //				MethodSomething( tupleInstance.Entry< INTEGERS >() );
    //
    //		Then this method is just a wrapper to the method the receives the integer sequence as an argument and perform the expansion pack, and then
    //		invoke the method
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          arguments - a tuple containing the arguments required to invoke the method 
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      The return value from invokeing the method will be returned
    //
    //  Expectations :
    //
	//		1. The instance should be ready
	//		2. The refernce to the tuple instance should be ready
	//		3. 
    //
    //  Possible errors :
    //
	//		1. The given function failes and throws an exception
	//		2.
    //
    EnsureRetrunValueIsUsed inline ReturnType operator()( const Memory::Tuple< ArgumentTypes... >& arguments ) const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to check if the this instance match the other
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			other - a reference to the instance that should be compared with this object
	//
	//      Information returned to the user :
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
	//			other - a reference to the instance that should be compared with this object
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
		static void UnitTest() __attribute__ (( __unused__ ));

	)  //  End of debug tool


protected:


    // The protected part is used for inheritance. This means that only this object and the objects that inherit from it can use the protected members data or methods


	// This object will store an instance of the object that the method belongs to, to operate on
	ObjectType* member_instance;

	// This object will store the address of the method
	MethodPointerType member_methodPointer;


private:


    // The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
    // rather help implement it :


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to invoke the method, using an argument tuple, on the given reference to an instance of the object that the method belongs to. 
	//		This is the method that invoke the method. It is needed to allow an easy call of the tuple. This means for a tuple with 3 arguments, the 
	//		following code should be written to invoke the method :
    //
    //				MethodSomething( tupleInstance.Entry< 0 >(), tupleInstance.Entry< 1 >(), tupleInstance.Entry< 2 >() );
    //
    //      To avoid writing all the arguments by hand, parameter pack expansion exist. To use it an integer sequence needs to be passed to the function. 
    //		This sequence will be used to unpack the tuple of arguments, and allow an easy invoke of the function :
    //
    //				MethodSomething( tupleInstance.Entry< INTEGERS >() );
    //
    //		Then this method receives an integer sequence as an argument and perform the expansion pack, and then invoke the method
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. arguments - a tuple containing the arguments required to invoke the method 
    //          2. An incrementing integer sequence, it is part of the functionality required to invoke the method using the tuple
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      The return value from invokeing the method will be returned
    //
    //  Expectations :
    //
	//		1. The instance should be ready
	//		2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< UnsignedInteger64bits... ArgumentIndices >
    EnsureRetrunValueIsUsed inline ReturnType InvokeUsingTuple__Private( const Memory::Tuple< ArgumentTypes... >& arguments, IncrementingIntegerSequenceHolder< ArgumentIndices... > ) const;


};  //  Class MethodPointerBoundToInstance



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - No arguments to function   ************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



// Template Class Information :
//
//  Purpose :
//
//		Use this object to store the memory address of a specific function, and allowing to invoke it during run time. This is a template specialization
//		for functions that does not required any arguments. The difference between a function and method, is that method is a function that belongs to an object.
//		This object also stores an instance of the object that the method belongs to, to operate on
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
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< typename ObjectType, typename ReturnType >
class MethodPointerBoundToInstance< ObjectType, ReturnType () > : public BaseInvokableObject< ReturnType >, public InvokableObjectInterface< ReturnType >
{
public:


	// Create a type definition for this object
	using SelfType = MethodPointerBoundToInstance< ObjectType, ReturnType () >;

	// Create a type definition for the method using the specific given template arguments
	using MethodPointerType = ReturnType ( ObjectType::* )();


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
	//      Information returned to the user :
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
	inline MethodPointerBoundToInstance();


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
	//			1. instance - the memory address of an instance of the object that the method belongs to
	//			2. methodRawPointer - the memory address of the function to call
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
	//		1. The given pointer to the method should not be NULL
	//		2. The given pointer to the instance should not be NULL
	//		3. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline MethodPointerBoundToInstance( ObjectType& instance, MethodPointerType const methodRawPointer );


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
	//			other - a reference to the instance that should be copied
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
	inline MethodPointerBoundToInstance( const SelfType& other );


	// This macro will be used to all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
	// simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
	// any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
	// be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
	// macro will be used to add the following methods to each object :
	//
	//		1. Assignment operator
	//		2. Move constructor
	//		3. Move assignment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure_ForInheritance( MethodPointerBoundToInstance )


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
	//      Information returned to the user :
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
	virtual ~MethodPointerBoundToInstance() = default;


	// The following methods declare the overloaded operators for the object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to invoke the method pointed to by this instance, on an instance of an object that the method belongs too. This operator
	//		will give instances of this object the ability to be used as if they are functions
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
	//		The return value from calling the method
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
	EnsureRetrunValueIsUsed virtual ReturnType operator()() override;


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to invoke the method pointed to by this instance, on an instance of an object that the method belongs too. This operator
	//		will give instances of this object the ability to be used as if they are functions
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
	//		The return value from calling the method
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
	EnsureRetrunValueIsUsed virtual ReturnType operator()() const override;


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to check if the this instance match the other
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			other - a reference to the instance that should be compared with this object
	//
	//      Information returned to the user :
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
	//			other - a reference to the instance that should be compared with this object
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
		static void UnitTest() __attribute__ (( __unused__ )) { MethodPointerBoundToInstance< Test::Object COMMA UnsignedInteger64bits ( UnsignedInteger32bits ) >::UnitTest(); }

	)  //  End of debug tool


protected:


    // The protected part is used for inheritance. This means that only this object and the objects that inherit from it can use the protected 
    // members data or methods :


	// This object will store an instance of the object that the method belongs to, to operate on
	ObjectType* member_instance;

	// This object will store the address of the function
	MethodPointerType member_methodPointer;


};  //  Class MethodPointerBoundToInstance