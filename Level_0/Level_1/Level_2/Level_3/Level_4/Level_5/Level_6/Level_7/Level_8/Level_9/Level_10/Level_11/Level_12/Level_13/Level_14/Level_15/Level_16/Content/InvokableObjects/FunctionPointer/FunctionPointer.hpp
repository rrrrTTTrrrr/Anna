namespace Universe
{



// In C++11, there are two syntaxes for function declaration :
//
//     return-type identifier ( argument-declarations... )
//
// and
//
//     auto identifier ( argument-declarations... ) -> return_type
//
// They are equivalent. Now when they are equivalent, why do you ever want to use the latter? Well, C++11 introduced this cool decltype thing that lets you describe 
// type of an expression. So you might want to derive the return type from the argument types. So you try :
//
// 		template < typename T1, typename T2 >
// 		decltype( a + b ) Stink( T1 a, T2 b );
//
// and the compiler will tell you that it does not know what a and b are in the decltype argument. That is because they are only declared by the argument list.
//
// You could easily work around the problem by using declval and the template parameters that are already declared. Like :
//
// 		template < typename T1, typename T2 >
// 		decltype( std::declval< T1 >() + std::declval< T2 >() ) Stink( T1 a, T2 b );
//
// except it's getting really verbose now. So the alternate declaration syntax was proposed and implemented and now you can write
//
// 		template < typename T1, typename T2 >
// 		auto Stink( T1 a, T2 b ) -> decltype( a + b );
//
// and it's less verbose and the scoping rules didn't need to change.
//
// C++14 update: C++14 also permits just
//
//     auto identifier ( argument-declarations... )
//
// as long as the function is fully defined before use and all return statements deduce to the same type



// A pointer to function can be the return value of a function. First of all a type definiton for the function pointer needs to be created :
//
//		using functionPointer = void (*)( int );
//
// Now it can be used as the return type :
//		
//		functionPointer FunctionWeird()
//		{
//			return ( someFunctionNameWithTheRequiredSignature );
//		}



// Template template parameters :
//
//	It enables to do the following syntax - it is basically a way to tell the compiler that the given template type depends also on a template
//	type itself :
//
//		template< template< typename, typename > class ContainerType, typename ValueType, typename AllocType >
//		void Print( const ContainerType< ValueType, AllocType& alloc )
//		{
//			for ( const auto& curr : alloc )
//			{
//				std::cout << v << ' ';
//			}
//			
//			std::cout << std::endl;
//		}
//
//	It improves readability of the code, provides extra type safety and save some compiler efforts. If the template class or function is designed
//	to handle template parameter, it is better to make it clear!



// Multiple parameter packs in a variadic template :
//
//	The rational is to put a knwon type that won't be used never in the specific parameter pack, and using a template template parameter!
//
//	The syntax :	
//
//		template< typename... PackParameter1, template< typename... > class Type1, typename... PackParameter2, template< typename... > class Type2 >
//
// Note, this can only be applied currently to template functions!!! 



// Template Class Information :
//
//  Purpose :
//
//		Use this object to store the memory address of a specific function, and allowing to invoke it during run time
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
//			FunctionType - the function signature type
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
class FunctionPointer
{};



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Function with arguments   *************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



// Template Class Information :
//
//  Purpose :
//
//		Use this object to store the memory address of a specific function, and allowing to invoke it during run time
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
//			1. ReturnType - the return value type of the required function
//			2. ArgumentTypes - the arguments types of the required function
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
class FunctionPointer< ReturnType ( ArgumentTypes... ) > : public BaseInvokableObject< ReturnType, ArgumentTypes... >, public InvokableObjectInterface< ReturnType, ArgumentTypes... >
{
private:


	// The following object will be used to determine properties on the given template type. These properties will be used to determine the
	// behavior and the methods that object will contain according to the template type. This is needed because this object is a template,
	// therefore the deduction of the template type is done on the all object and before any method declaration. To workaround this issue
	// the method must have also a template parameter, to make the compiler perform the template type deduction on the method itself as
	// well only when the template type is known
	template< typename DummyType >
	class TypeCheckRequirements
	{
	public:


		// This is the method that will do the actual checking. It will detect if the template type has at least one of the operators '>' or
		// '<' implemented
		static constexpr Boolean DoesTypeImplementIsLargerOrIsSmallerOperators()
		{
			// Check if the template type has implemented at least one of the operators '<' or '>', and return the result
			return ( OperatorDetector_Larger< DummyType >::Result() == true || OperatorDetector_Smaller< DummyType >::Result() == true );
		}


		// This is the method that will do the actual checking. It will detect if the template type has not implemented any of the operators
		// '>' or '<'
		static constexpr Boolean DoesTypeDoNotImplementIsLargerOrIsSmallerOperators()
		{
			// Check if the template type has not implemented any one of the operators '<' or '>', and return the result
			return ( OperatorDetector_Larger< DummyType >::Result() == false && OperatorDetector_Smaller< DummyType >::Result() == false );
		}


		// This is the method that will do the actual checking. It will detect if the template type has implemented the operator '>'
		static constexpr Boolean DoesTypeImplementIsLargerOperator()
		{
			// Check if the template type has implemented the operator '>', and return the result
			return ( OperatorDetector_Larger< DummyType >::Result() == true );
		}


		// This is the method that will do the actual checking. It will detect if the template type has implemented the operator '<',
		// but not the '>' operator
		static constexpr Boolean DoesTypeImplementIsSmallerOperatorButNotIsLargerOperator()
		{
			// Check if the template type has implemented the operator '<' but not the '>', and return the result
			return ( OperatorDetector_Larger< DummyType >::Result() == false && OperatorDetector_Smaller< DummyType >::Result() == true );
		}


	};

	
public:


    // Create a type definition for this object
    using SelfType = FunctionPointer< ReturnType ( ArgumentTypes... ) >;

	// Create a type definition for the function using the specific given template arguments
	using FunctionPointerType = ReturnType (*)( ArgumentTypes... );


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
	inline FunctionPointer();


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
	//			functionPointer - the memory address of the function to call
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
	//		1. The given pointer to the function should not be NULL
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline FunctionPointer( FunctionPointerType const functionPointer );


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
	inline FunctionPointer( const SelfType& other );


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
	ObjectInfrastructure_ForInheritance( FunctionPointer )


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
	virtual ~FunctionPointer() = default;


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


    // Method Information :
    //
    //  Description :
    //
	//      Use this operator to invoke the function pointed to be this instance, using a tuple of arguments. This operator will give instances of
	//		this object the ability to be used as if they are functions. This version is for constant instances. Now to invoke a function using a 
	//		tuple, the syntax is as follows :
    //
    //				MethodSomething( tupleInstance.Entry< 0 >(), tupleInstance.Entry< 1 >(), tupleInstance.Entry< 2 >() );
    //
    //      To avoid writing all the arguments by hand, parameter pack expansion exist. To use it an integer sequence needs to be passed to the function. 
    //		This sequence will be used to unpack the tuple of arguments, and allow an easy invoke of the function :
    //
    //				MethodSomething( tupleInstance.Entry< INTEGERS >() );
    //
    //		Then this method is just a wrapper to the method the receives the integer sequence as an argument and perform the expansion pack, and then
    //		invoke the function
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          arguments - a tuple containing the arguments required to invoke the function 
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      The return value from invoking the function will be returned
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. 
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


	// This object will store the address of the function
	FunctionPointerType member_functionPointer;


private:


    // The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
    // rather help implement it :


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to invoke the function, using a tuple of arguments. Now to invoke a function using a tuple, the syntax is as follows :
    //
    //				MethodSomething( tupleInstance.Entry< 0 >(), tupleInstance.Entry< 1 >(), tupleInstance.Entry< 2 >() );
    //
    //      To avoid writing all the arguments by hand, parameter pack expansion exist. To use it an integer sequence needs to be passed to the function. 
    //		This sequence will be used to unpack the tuple of arguments, and allow an easy invoke of the function :
    //
    //				MethodSomething( tupleInstance.Entry< INTEGERS >() );
    //
    //		Then this method receives an integer sequence as an argument and perform the expansion pack, and then invoke the function
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. arguments - a tuple containing the arguments required to invoke the function 
    //          2. An incrementing integer sequence, it is part of the functionality required to invoke the function using the tuple
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      The return value from invoking the function will be returned
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< UnsignedInteger64bits... ArgumentIndices >
    EnsureRetrunValueIsUsed inline ReturnType InvokeUsingTuple__Private( const Memory::Tuple< ArgumentTypes... >& arguments, IncrementingIntegerSequenceHolder< ArgumentIndices... > ) const;


};  //  Class FunctionPointer



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
//		for functions that does not require any arguments
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
//			ReturnType - the return value type of the required function
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
class FunctionPointer< ReturnType () > : public BaseInvokableObject< ReturnType >, public InvokableObjectInterface< ReturnType >
{
public:


    // Create a type definition for this object
    using SelfType = FunctionPointer< ReturnType () >;

	// Create a type definition for the function using the specific given template arguments
	using FunctionPointerType = ReturnType (*)();


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
	inline FunctionPointer();


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
	//			functionPointer - the memory address of the function to call
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
	//		1. The given pointer to the function should not be NULL
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline FunctionPointer( FunctionPointerType const functionPointer );


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
	inline FunctionPointer( const SelfType& other );


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
	ObjectInfrastructure_ForInheritance( FunctionPointer )


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
	virtual ~FunctionPointer() = default;


	// The following methods declare the overloaded operators for the object :


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to invoke the function pointed to be this instance. This operator will give instances of this object the ability to be
	//		used as if they are functions.
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
	EnsureRetrunValueIsUsed virtual ReturnType operator()() override;


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to invoke the function pointed to be this instance. This operator will give instances of this object the ability to be
	//		used as if they are functions. This version is for constant instances.
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
		static void UnitTest() __attribute__ (( __unused__ )) { FunctionPointer< UnsignedInteger64bits ( UnsignedInteger64bits ) >::UnitTest(); }

	)  //  End of debug tool


protected:


    // The protected part is used for inheritance. This means that only this object and the objects that inherit from it can use the protected members data or methods


	// This object will store the address of the function
	FunctionPointerType member_functionPointer;


};  //  Class FunctionPointer