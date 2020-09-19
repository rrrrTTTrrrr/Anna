#ifndef INVOKABLEOBJECT_HPP
#define INVOKABLEOBJECT_HPP


#include "../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../../ObjectBranch/Content/ObjectInfrastructure/BasicObjectFunctionality/BasicObjectFunctionality.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../../../../../../ObjectBranch/Content/ObjectInfrastructure/GetAndSetForMembers/GetAndSetForMembers.hpp"  //  Macro Get_MACRO, Macro Set_MACRO
#include "../../../../Content/Memory/Operations/Operations.hpp"  //  Class Operations
#include "../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../CommonFunctionality/Functor_Interface/Functor_Interface.hpp"  //  Class FunctorPointer
#include "../FunctionAndMethodPointers/FunctionPointer/FunctionPointer.hpp"  //  Class FunctionPointer
#include "../FunctionAndMethodPointers/MethodPointers/MethodPointerBoundToSpecificInstance/MethodPointerBoundToSpecificInstance.hpp"  //  Class MethodPointerBoundToSpecificInstance
#include "../LambdaExpression/LambdaExpression.hpp"  //  Class LambdaExpression
#include "../FunctorInvoker/FunctorInvoker.hpp"  //  Class FunctorInvoker


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../../../../../TestBranch/TestingTools/Functions/TestFunctions.hpp"  //  Class TestFunctions
#include "../../../../../../../TestBranch/TestingTools/Objects/TestObject_1/TestObject_1.hpp"  //  Class TestObject_1
#endif


namespace Universe
{



    // When a type is forward declared, all the compiler knows is that this type exists. It does not know its size, members or methods. This is why its
	// called incomplete type. Therefore, it can not be used to declare a variable, member or base class since the compiler would need the layout of the
	// type. In other words, it can not be used for anything that requires information on the specific type. What can be done is declaring pointer and
	// reference to the incomplete type. The pointer and refernce can act as a variable, argument to a method or as the return type.
	//
	// Forward declarations :
	//
	//  NONE
	//



	// The following enumeration will be used to describe the type of invokable object
	enum class InvokableObjectType : UnsignedInteger8bits
	{
		None = 0,
		Function = 1,
		Method = 2,
		Functor = 3,
		LambdaExpression = 4
	};



	// Template Class Information :
	//
	//  Purpose :
	//
	//		The purpose of this object is to allow passing any invokable type, and invoke it in run time
	//
	//  Description :
	//
	//		1. This object contains an instance of the object "InstanceState" to allow each instance of this object to have a defined state
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
	//			1. InvokableObjectType - any type that can be invoked. This includes functions, methods, lambda expressions and functors
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	template< typename ReturnValueType, typename... ArgumentTypes >
	class InvokableObject NotForInheritance
	{
	public:


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
		inline InvokableObject();


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
		//			functionPointer - a constant reference to a function pointer instance
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
		//		1. The given function pointer instance is ready
		//		2. 
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		inline InvokableObject( const FunctionPointer< ReturnValueType, ArgumentTypes... >& functionPointer );


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
		//			boundMethodPointer - a constant reference to a method pointer instance
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
		//		1. The given method pointer instance is ready
		//		2. 
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename ObjectType >
		inline InvokableObject( const MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType, ArgumentTypes... >& boundMethodPointer );


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
		//			lambdaExpression - a constant reference to a lambda expression instance
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
		//		1. The given lambda expression instance is ready
		//		2. 
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename LambdaExpressionType >
		inline InvokableObject( const LambdaExpressionType& lambdaExpression );


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
		//			functor - a constant reference to a functor instance
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
		//		1. The given functor instance is ready
		//		2. 
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename ObjectType >
		inline InvokableObject( const Functor_Interface< ReturnValueType, ArgumentTypes... >& functor );


		// This macro will be used to add all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
		// simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
		// any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
		// be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
		// macro will be used to add the following methods to each object :
		//
		//		1. Move constructor
		//		2. Move assigenment operator
		//		3. Reset
		//		4. State
		//
		ObjectInfrastructure_WithoutAssignmentOperator_MACRO( InvokableObject< ReturnValueType, ArgumentTypes... > )


		// Method Information :
		//
		//  Description :
		//
		//      This method is used to swap the content between this instance and the other one
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			other - a reference to the instance that should be swaped
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//      NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//      They will come
		//
		inline void Swap( InvokableObject< ReturnValueType, ArgumentTypes... >& other );


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			functionPointer - a constant reference to a function pointer instance
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
		inline void Initiate( const FunctionPointer< ReturnValueType, ArgumentTypes... >& functionPointer );


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			boundMethodPointer - a constant reference to a method pointer instance
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
		template< typename ObjectType >
		inline void Initiate( const MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType, ArgumentTypes... >& boundMethodPointer );


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			lambdaExpression - a constant reference to a lambda expression instance
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
		template< typename ObjectType >
		inline void Initiate( const LambdaExpression< ObjectType, ReturnValueType, ArgumentTypes... >& lambdaExpression );


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			functor - a constant reference to a functor instance
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
		template< typename ObjectType >
		inline void Initiate( const FunctorInvoker< ObjectType, ReturnValueType, ArgumentTypes... >& functor );


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
		inline ~InvokableObject() = default;


		// The following methods declare the overloaded operators for the object :


		// Method Information :
		//
		//  Description :
		//
		//		Use this operator to invoke the invokable object instance inside this instance, using the given argumetns. This operator will give
		//		instances of this object the ability to be used as if they were functions
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			arguments - the arguments required to invoke the object
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
		//		1. The instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		1. The invokation of the object failes and throws an exception
		//		2.
		//
		inline ReturnValueType operator()( ArgumentTypes... arguments ) const;


		// Method Information :
		//
		//  Description :
		//
		//		Use this operator to invoke the invokable object instance inside this instance, using the given argumetns. This operator will give
		//		instances of this object the ability to be used as if they were functions
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			arguments - a tuple containing the arguments required to invoke the object
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
		//		1. The instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		1. The invokation of the object failes and throws an exception
		//		2.
		//
		inline ReturnValueType operator()( const Tuple< ArgumentTypes... >& arguments ) const;


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
			static void Test() __attribute__ (( __unused__ ));

		)  //  End of debug tool


	private:


		// Disable all the abilites of the object to copy itself, this include the copy constructor and assignment operator
		DisableCopyConstructorAndAssignmentOperator_MACRO( InvokableObject )


		// This pointer will store the memory address allocated on the heap for the derived instance. This is can by an invokable object, this
		// includes functions, methods, lambda expressions and functors 
		void* member_invokableObject;

		// This object will store the type of the current invokable object the instance contains
		InvokableObjectType member_type;


	};  //  Class InvokableObject




































//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************




































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
	template< typename ReturnValueType, typename... ArgumentTypes >
	inline InvokableObject< ReturnValueType, ArgumentTypes... >::InvokableObject() :
	member_state(),
	member_invokableObject( nullptr ),
	member_type( InvokableObjectType::None )
	{}


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
	//			functionPointer - a constant reference to a function pointer instance
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
	//		1. The given function pointer instance is ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< typename ReturnValueType, typename... ArgumentTypes >
	inline InvokableObject< ReturnValueType, ArgumentTypes... >::InvokableObject( const FunctionPointer< ReturnValueType, ArgumentTypes... >& functionPointer ) :
	member_state( InstanceState::Ready ),
	member_invokableObject( nullptr ),
	member_type( InvokableObjectType::Function )
	{
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertInstanceIsReady_MACRO( functionPointer )

		// Allocate memory space on the heap memory segment to store the function pointer
		reinterpret_cast< FunctionPointer< ReturnValueType, ArgumentTypes... > >( member_invokableObject ) = new FunctionPointer< ReturnValueType, ArgumentTypes... >( functionPointer );
	}


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
	//			boundMethodPointer - a constant reference to a method pointer instance
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
	//		1. The given method pointer instance is ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< typename ReturnValueType, typename... ArgumentTypes >
	template< typename ObjectType >
	inline InvokableObject< ReturnValueType, ArgumentTypes... >::InvokableObject( const MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType, ArgumentTypes... >& boundMethodPointer ) :
	member_state( InstanceState::Ready ),
	member_invokableObject( nullptr ),
	member_type( InvokableObjectType::Method )
	{
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertInstanceIsReady_MACRO( boundMethodPointer )

		// Allocate memory space on the heap memory segment to store the method pointer
		reinterpret_cast< MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType, ArgumentTypes... > >( member_invokableObject ) = new MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType, ArgumentTypes... >( boundMethodPointer );
	}


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
	//			lambdaExpression - a constant reference to a lambda expression instance
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
	//		1. The given lambda expression instance is ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< typename ReturnValueType, typename... ArgumentTypes >
	template< typename LambdaExpressionType >
	inline InvokableObject< ReturnValueType, ArgumentTypes... >::InvokableObject( const LambdaExpressionType& lambdaExpression ) :
	member_state( InstanceState::Ready ),
	member_invokableObject( nullptr ),
	member_type( InvokableObjectType::LambdaExpression )
	{
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertInstanceIsReady_MACRO( lambdaExpression )

		// Allocate memory space on the heap memory segment to store the lambda expression
		reinterpret_cast< LambdaExpressionType* >( member_invokableObject ) = new LambdaExpressionType( lambdaExpression );
	}


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
	//			functor - a constant reference to a functor instance
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
	//		1. The given functor instance is ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< typename ReturnValueType, typename... ArgumentTypes >
	template< typename ObjectType >
	inline InvokableObject< ReturnValueType, ArgumentTypes... >::InvokableObject( const Functor_Interface< ReturnValueType, ArgumentTypes... >& functor ) :
	member_state( InstanceState::Ready ),
	member_invokableObject( nullptr ),
	member_type( InvokableObjectType::Functor )
	{
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertInstanceIsReady_MACRO( functor )

		// Allocate memory space on the heap memory segment to store the functor
		reinterpret_cast< Functor_Interface< ReturnValueType, ArgumentTypes... >* >( member_invokableObject ) = new ObjectType( functor );
	}


	// Method Information :
	//
	//  Description :
	//
	//		This method is used to swap the content between this instance and the other one
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			other - a reference to the instance that should be swaped
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
	template< typename ReturnValueType, typename... ArgumentTypes >
	inline void InvokableObject< ReturnValueType, ArgumentTypes... >::Swap( InvokableObject< ReturnValueType, ArgumentTypes... >& other )
	{
	    // Swap betwen the state instances
	    member_state.Swap( other.member_state );

	    // Swap between the invokable instances
	    Memory::Operations::Swap< void* >( member_invokableObject, other.member_invokableObject );

	    // Swap between the types
	    Memory::Operations::Swap< InvokableObjectType >( member_type, other.member_type );
	}


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			functionPointer - a constant reference to a function pointer instance
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
	template< typename ReturnValueType, typename... ArgumentTypes >
	inline void InvokableObject< ReturnValueType, ArgumentTypes... >::Initiate( const FunctionPointer< ReturnValueType, ArgumentTypes... >& functionPointer )
	{
	    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
	    // leave this scope it will delete the old data
	    InvokableObject< ReturnValueType, ArgumentTypes... > temporary( functionPointer );

	    // Swap between this instance and the temporary instance
	    Swap( temporary );
	}


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			boundMethodPointer - a constant reference to a method pointer instance
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
	template< typename ReturnValueType, typename... ArgumentTypes >
	template< typename ObjectType >
	inline void InvokableObject< ReturnValueType, ArgumentTypes... >::Initiate( const MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType, ArgumentTypes... >& boundMethodPointer )
	{
	    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
	    // leave this scope it will delete the old data
	    InvokableObject< ReturnValueType, ArgumentTypes... > temporary( boundMethodPointer );

	    // Swap between this instance and the temporary instance
	    Swap( temporary );
	}


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			lambdaExpression - a constant reference to a lambda expression instance
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
	template< typename ReturnValueType, typename... ArgumentTypes >
	template< typename ObjectType >
	inline void InvokableObject< ReturnValueType, ArgumentTypes... >::Initiate( const LambdaExpression< ObjectType, ReturnValueType, ArgumentTypes... >& lambdaExpression )
	{
	    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
	    // leave this scope it will delete the old data
	    InvokableObject< ReturnValueType, ArgumentTypes... > temporary( lambdaExpression );

	    // Swap between this instance and the temporary instance
	    Swap( temporary );
	}


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			functor - a constant reference to a functor instance
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
	template< typename ReturnValueType, typename... ArgumentTypes >
	template< typename ObjectType >
	inline void InvokableObject< ReturnValueType, ArgumentTypes... >::Initiate( const FunctorInvoker< ObjectType, ReturnValueType, ArgumentTypes... >& functor )
	{
	    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
	    // leave this scope it will delete the old data
	    InvokableObject< ReturnValueType, ArgumentTypes... > temporary( functor );

	    // Swap between this instance and the temporary instance
	    Swap( temporary );
	}

































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************




































	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to invoke the invokable object instance inside this instance, using the given argumetns. This operator will give
	//		instances of this object the ability to be used as if they were functions
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			arguments - the arguments required to invoke the object
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
	//		1. The instance should be ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. The invokation of the object failes and throws an exception
	//		2.
	//
	template< typename ReturnValueType, typename... ArgumentTypes >
	inline ReturnValueType InvokableObject< ReturnValueType, ArgumentTypes... >::operator()( ArgumentTypes... arguments ) const
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO

		// Invoke the operation using the given arguments, and return the result
		return ( (*member_invokableObject)( arguments... ) );
	}


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to invoke the invokable object instance inside this instance, using the given argumetns. This operator will give
	//		instances of this object the ability to be used as if they were functions
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			arguments - a tuple containing the arguments required to invoke the object
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
	//		1. The instance should be ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. The invokation of the object failes and throws an exception
	//		2.
	//
	template< typename ReturnValueType, typename... ArgumentTypes >
	inline ReturnValueType InvokableObject< ReturnValueType, ArgumentTypes... >::operator()( const Tuple< ArgumentTypes... >& arguments ) const
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO

		// Invoke the operation using the tuple of arguments, and return the result
		return ( (*member_invokableObject)( arguments ) );
	}




































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - No arguments to function   ************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //

































	// Template Class Information :
	//
	//  Purpose :
	//
	//		The purpose of this object is to allow passing any invokable type, and invoke it in run time
	//
	//  Description :
	//
	//		1. This object contains an instance of the object "InstanceState" to allow each instance of this object to have a defined state
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
	//			1. InvokableObjectType - any type that can be invoked. This includes functions, methods, lambda expressions and functors
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	template< typename ReturnValueType >
	class InvokableObject< ReturnValueType > NotForInheritance
	{
	public:


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
		inline InvokableObject();


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
		//			functionPointer - a constant reference to a function pointer instance
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
		//		1. The given function pointer instance is ready
		//		2. 
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		inline InvokableObject( const FunctionPointer< ReturnValueType >& functionPointer );


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
		//			boundMethodPointer - a constant reference to a method pointer instance
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
		//		1. The given method pointer instance is ready
		//		2. 
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename ObjectType >
		inline InvokableObject( const MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType >& boundMethodPointer );


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
		//			lambdaExpression - a constant reference to a lambda expression instance
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
		//		1. The given lambda expression instance is ready
		//		2. 
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename LambdaExpressionType >
		inline InvokableObject( const LambdaExpressionType& lambdaExpression );


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
		//			lambdaExpression - a constant reference to a functor instance
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
		//		1. The given functor instance is ready
		//		2. 
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename ObjectType >
		inline InvokableObject( const Functor_Interface< ObjectType, ReturnValueType >& functor );


		// This macro will be used to add all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
		// simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
		// any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
		// be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
		// macro will be used to add the following methods to each object :
		//
		//		1. Move constructor
		//		2. Move assigenment operator
		//		3. Reset
		//		4. State
		//
		ObjectInfrastructure_WithoutAssignmentOperator_MACRO( InvokableObject< ReturnValueType > )


		// Method Information :
		//
		//  Description :
		//
		//      This method is used to swap the content between this instance and the other one
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			other - a reference to the instance that should be swaped
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//      NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//      They will come
		//
		inline void Swap( InvokableObject< ReturnValueType >& other );


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			functionPointer - a constant reference to a function pointer instance
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
		inline void Initiate( const FunctionPointer< ReturnValueType >& functionPointer );


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			boundMethodPointer - a constant reference to a method pointer instance
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
		template< typename ObjectType >
		inline void Initiate( const MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType >& boundMethodPointer );


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			lambdaExpression - a constant reference to a lambda expression instance
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
		template< typename ObjectType >
		inline void Initiate( const LambdaExpression< ObjectType, ReturnValueType >& lambdaExpression );


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			functor - a constant reference to a functor instance
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
		template< typename ObjectType >
		inline void Initiate( const FunctorInvoker< ObjectType, ReturnValueType >& functor );


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
		inline ~InvokableObject() = default;


		// The following methods declare the overloaded operators for the object :


		// Method Information :
		//
		//  Description :
		//
		//		Use this operator to invoke the invokable object instance inside this instance, using the given argumetns. This operator will give
		//		instances of this object the ability to be used as if they were functions
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			arguments - the arguments required to invoke the object
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
		//		1. The instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		1. The invokation of the object failes and throws an exception
		//		2.
		//
		inline ReturnValueType operator()() const;


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
			static void Test() __attribute__ (( __unused__ )) { InvokableObject< ReturnValueType COMMA UnsignedInteger64bits >::Test(); }

		)  //  End of debug tool


	private:


		// Disable all the abilites of the object to copy itself, this include the copy constructor and assignment operator
		DisableCopyConstructorAndAssignmentOperator_MACRO( InvokableObject )


		// This pointer will store the memory address allocated on the heap for the derived instance. This is can by an invokable object, this
		// includes functions, methods, lambda expressions and functors 
		void* member_invokableObject;

		// This object will store the type of the current invokable object the instance contains
		InvokableObjectType member_type;


	};  //  Class InvokableObject




































//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************




































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
	template< typename ReturnValueType >
	inline InvokableObject< ReturnValueType >::InvokableObject() :
	member_state(),
	member_invokableObject( nullptr ),
	member_type( InvokableObjectType::None )
	{}


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
	//			functionPointer - a constant reference to a function pointer instance
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
	//		1. The given function pointer instance is ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< typename ReturnValueType >
	inline InvokableObject< ReturnValueType >::InvokableObject( const FunctionPointer< ReturnValueType >& functionPointer ) :
	member_state( InstanceState::Ready ),
	member_invokableObject( nullptr ),
	member_type( InvokableObjectType::Function )
	{
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertInstanceIsReady_MACRO( functionPointer )

		// Allocate memory space on the heap memory segment to store the function pointer
		reinterpret_cast< FunctionPointer< ReturnValueType >* >( member_invokableObject ) = new FunctionPointer< ReturnValueType >( functionPointer );
	}


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
	//			boundMethodPointer - a constant reference to a method pointer instance
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
	//		1. The given method pointer instance is ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< typename ReturnValueType >
	template< typename ObjectType >
	inline InvokableObject< ReturnValueType >::InvokableObject( const MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType >& boundMethodPointer ) :
	member_state( InstanceState::Ready ),
	member_invokableObject( nullptr ),
	member_type( InvokableObjectType::Method )
	{
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertInstanceIsReady_MACRO( boundMethodPointer )

		// Allocate memory space on the heap memory segment to store the method pointer
		reinterpret_cast< MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType >* >( member_invokableObject ) = new MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType >( boundMethodPointer );
	}


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
	//			lambdaExpression - a constant reference to a lambda expression instance
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
	//		1. The given lambda expression instance is ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< typename ReturnValueType >
	template< typename LambdaExpressionType >
	inline InvokableObject< ReturnValueType >::InvokableObject( const LambdaExpressionType& lambdaExpression ) :
	member_state( InstanceState::Ready ),
	member_invokableObject( nullptr ),
	member_type( InvokableObjectType::LambdaExpression )
	{
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertInstanceIsReady_MACRO( lambdaExpression )

		// Allocate memory space on the heap memory segment to store the lambda expression
		reinterpret_cast< LambdaExpressionType* >( member_invokableObject ) = new LambdaExpressionType( lambdaExpression );
	}


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
	//			lambdaExpression - a constant reference to a functor instance
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
	//		1. The given functor instance is ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< typename ReturnValueType >
	template< typename ObjectType >
	inline InvokableObject< ReturnValueType >::InvokableObject( const Functor_Interface< ObjectType, ReturnValueType >& functor ) :
	member_state( InstanceState::Ready ),
	member_invokableObject( nullptr ),
	member_type( InvokableObjectType::LambdaExpression )
	{
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertInstanceIsReady_MACRO( functor )

		// Allocate memory space on the heap memory segment to store the functor
		reinterpret_cast< Functor_Interface< ObjectType, ReturnValueType >* >( member_invokableObject ) = new Functor_Interface< ObjectType, ReturnValueType >( functor );
	}


	// Method Information :
	//
	//  Description :
	//
	//		This method is used to swap the content between this instance and the other one
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			other - a reference to the instance that should be swaped
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
	template< typename ReturnValueType >
	inline void InvokableObject< ReturnValueType >::Swap( InvokableObject< ReturnValueType >& other )
	{
	    // Swap betwen the state instances
	    member_state.Swap( other.member_state );

	    // Swap between the invokable instances
	    Memory::Operations::Swap< void* >( member_invokableObject, other.member_invokableObject );

	    // Swap between the types
	    Memory::Operations::Swap< InvokableObjectType >( member_type, other.member_type );
	}


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			functionPointer - a constant reference to a function pointer instance
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
	template< typename ReturnValueType >
	inline void InvokableObject< ReturnValueType >::Initiate( const FunctionPointer< ReturnValueType >& functionPointer )
	{
	    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
	    // leave this scope it will delete the old data
	    InvokableObject< ReturnValueType > temporary( functionPointer );

	    // Swap between this instance and the temporary instance
	    Swap( temporary );
	}


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			boundMethodPointer - a constant reference to a method pointer instance
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
	template< typename ReturnValueType >
	template< typename ObjectType >
	inline void InvokableObject< ReturnValueType >::Initiate( const MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType >& boundMethodPointer )
	{
	    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
	    // leave this scope it will delete the old data
	    InvokableObject< ReturnValueType > temporary( boundMethodPointer );

	    // Swap between this instance and the temporary instance
	    Swap( temporary );
	}


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			lambdaExpression - a constant reference to a lambda expression instance
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
	template< typename ReturnValueType >
	template< typename ObjectType >
	inline void InvokableObject< ReturnValueType >::Initiate( const LambdaExpression< ObjectType, ReturnValueType >& lambdaExpression )
	{
	    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
	    // leave this scope it will delete the old data
	    InvokableObject< ReturnValueType > temporary( lambdaExpression );

	    // Swap between this instance and the temporary instance
	    Swap( temporary );
	}


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			functor - a constant reference to a functor instance
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
	template< typename ReturnValueType >
	template< typename ObjectType >
	inline void InvokableObject< ReturnValueType >::Initiate( const FunctorInvoker< ObjectType, ReturnValueType >& functor )
	{
	    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
	    // leave this scope it will delete the old data
	    InvokableObject< ReturnValueType > temporary( functor );

	    // Swap between this instance and the temporary instance
	    Swap( temporary );
	}





























//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************




































	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to invoke the invokable object instance inside this instance, using the given argumetns. This operator will give
	//		instances of this object the ability to be used as if they were functions
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			arguments - the arguments required to invoke the object
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
	//		1. The instance should be ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. The invokation of the object failes and throws an exception
	//		2.
	//
	template< typename ReturnValueType >
	inline ReturnValueType InvokableObject< ReturnValueType >::operator()() const
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO

		// Invoke the operation using the given arguments, and return the result
		return ( (*member_invokableObject)() );
	}




































// *********************************************************************************   TESTING   ********************************************************************************


































	DEBUG_TOOL(

		// Method Information :
		//
		//  Description :
		//
		//      This method is used to test the object. It is not part of the implementation, it is only used to find problem with the code that does implement
		//		the functionality
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			NONE
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//      1. true - if the object passed the test
		//      2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		1. An assertion failed - class Exception is thrown
		//		2. There is no more free memory space - class std::bad_alloc is thrown
		//		3. 
		//
		template< typename ReturnValueType COMMA typename... ArgumentTypes >
		void InvokableObject< ReturnValueType COMMA ArgumentTypes... >::Test()
		{
			// Create a test instance
			InvokableObject< UnsignedInteger32bits COMMA UnsignedInteger32bits COMMA UnsignedInteger64bits > testInvokableObject_1( &Testing::TestFunctions::TestFunction_1 );

			// Invoke the function with the required arguments
			testInvokableObject_1( 89, 4567UL );

			// Create an instance using a lambda expression with no captures, which is reduced to simple function pointer
			InvokableObject< void > testInvokableObject_3( FunctionPointer< void >( []() -> void { UnsignedInteger64bits dummy = 35UL; ++dummy; } ) );

			// Invoke the lambda expression
			testInvokableObject_3();

			// Create an instance of the object
			Testing::TestObject_1< UnsignedInteger64bits > testObject_1;

			// Create a test instance
			InvokableObject< void COMMA UnsignedInteger64bits COMMA UnsignedInteger64bits COMMA Boolean > testInvokableObject_4( MethodPointerBoundToSpecificInstance< Testing::TestObject_1< UnsignedInteger64bits >, void, UnsignedInteger64bits, UnsignedInteger64bits, Boolean >( &Testing::TestObject_1< UnsignedInteger64bits >::Initiate, testObject_1 ) );

			// Invoke the function with the required arguments
			testInvokableObject_4( 789UL, 56UL, false );

			// Move construct another instance
			InvokableObject< void COMMA UnsignedInteger64bits COMMA UnsignedInteger64bits COMMA Boolean > testInvokableObject_5( MOVE( testInvokableObject_4 ) );

			// Invoke the function with the required arguments
			testInvokableObject_5( 789UL, 56UL, false );

			// Create a lambda expression
			CreateLambdaExpressionInstanceWithNoArguments( []() -> void { UnsignedInteger64bits dummy = 35UL; ++dummy; }, testLambdaExpression_1, void )

			// Create a test instance
			InvokableObject< void > testInvokableObject_6( testLambdaExpression_1 );

			// Invoke the instance
			testInvokableObject_6();

			// Create a test instance
			UnsignedInteger64bits testVariable_1 = 987UL;

			// Create a lambda expression
			CreateLambdaExpressionInstanceWithNoArguments( [ testVariable_1 ]() -> void { UnsignedInteger64bits dummy = testVariable_1; ++dummy; }, testLambdaExpression_2, void )

			// Create a test instance
			InvokableObject< void > testInvokableObject_7( testLambdaExpression_2 );

			// Invoke the instance
			testInvokableObject_7();

			// // Create a test instance
			// InvokableObject< Testing::TestObject_1< UnsignedInteger64bits > COMMA UnsignedInteger64bits > testInvokableObject_3( ConstantMethodPointer< Testing::TestObject_1< UnsignedInteger64bits > COMMA UnsignedInteger64bits >( &Testing::TestObject_1< UnsignedInteger64bits >::Size ) );

			// // Invoke the function with the required arguments
			// Assert_Test_MACRO( testInvokableObject_3( testObject_1 ) == 789UL )
		}

	)  //  End of debug tool









}  //  Namespace Universe



#endif  // INVOKABLEOBJECT_HPP