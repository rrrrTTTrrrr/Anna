#ifndef METHODPOINTERBOUNDTOSPECIFICINSTANCE_HPP
#define METHODPOINTERBOUNDTOSPECIFICINSTANCE_HPP


#include "../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA, Macro CompileTimeAssert
#include "../../../../../../../../Content/Object/ObjectInfrastructure/BasicObjectFunctionality/BasicObjectFunctionality.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../../../../../../../Content/Object/ObjectInfrastructure/GetAndSetForMembers/GetAndSetForMembers.hpp"  //  Macro Get_MACRO, Macro Set_MACRO
#include "../../../../../../Content/Memory/Operations/Operations.hpp"  //  Class Operations
#include "../../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../../CommonFunctionality/BaseInvokableObject/BaseInvokableObject.hpp"  //  Class BaseInvokableObject
#include "../../../CommonFunctionality/Functor_Interface/Functor_Interface.hpp"  //  Class Functor_Interface
#include "../../../../BindObjects/Tuple/Tuple.hpp"  //  Class Tuple
#include "../../../../../../../../Content/Metaprogramming/CommonFunctionality/Sequences/IncrementingIntegerSequenceGenerator/IncrementingIntegerSequenceGenerator.hpp"  //  Typedef IncrementingIntegerSequence
 

// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../../../../../../../../Test/TestingTools/Objects/TestObject_2/TestObject_2.hpp"  //  Class TestObject_2
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
	//			2. ReturnValueType - the return value type of the required function
	//			3. MethodArgumentsTypes - the arguments types of the required function
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
	class MethodPointerBoundToSpecificInstance : public BaseInvokableObject< ReturnValueType, MethodArgumentsTypes... >, public Functor_Interface< ReturnValueType, MethodArgumentsTypes... >
	{
	public:


		// Create a type definition for the method using the specific given template arguments
		using MethodPointerType = ReturnValueType ( ObjectType::* )( MethodArgumentsTypes... );


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
		inline MethodPointerBoundToSpecificInstance();


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
		//			1. methodMemoryAddress - the memory address of the function to call
		//			2. instance - a constant reference to an instance that the method will operate on
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
		explicit inline MethodPointerBoundToSpecificInstance( MethodPointerType methodMemoryAddress, const ObjectType& instance );


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
		inline MethodPointerBoundToSpecificInstance( const MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType, MethodArgumentsTypes... >& other );


		// This macro will be used to all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
		// simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
		// any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
		// be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
		// macro will be used to add the following methods to each object :
		//
		//		1. Assigenment operator
		//		2. Move constructor
		//		3. Move assigenment operator
		//		4. Reset
		//		5. State
		//
		ObjectInfrastructure_ForInheritance_MACRO( ConsiderAsOneArgument( MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType, MethodArgumentsTypes... > ) )


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
		inline void Swap( MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType, MethodArgumentsTypes... >& other );


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
		//			1. methodMemoryAddress - the memory address of the function to call
		//			2. instance - a constant reference to an instance that the method will operate on
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
		inline void Initiate( MethodPointerType methodMemoryAddress, const ObjectType& instance );


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
		virtual ~MethodPointerBoundToSpecificInstance() = default;


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
		virtual ReturnValueType operator()( MethodArgumentsTypes... arguments ) override;


		// Method Information :
		//
		//  Description :
		//
		//		Use this operator to invoke the method pointed to by this instance, on an instance of an object that the method belongs too, using the
		//		given arguments. This operator will give instances of this object the ability to be used as if they are functions. This version is for
		//		constant instances
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
		inline ReturnValueType operator()( MethodArgumentsTypes... arguments ) const;


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
		//		4. 
	    //
	    //  Possible errors :
	    //
		//		1. The given function failes and throws an exception
		//		2.
	    //
	    virtual ReturnValueType operator()( const Tuple< MethodArgumentsTypes... >& arguments ) override;


	    // Method Information :
	    //
	    //  Description :
	    //
		//		Use this operator to invoke the method pointed to by this instance, on an instance of an object that the method belongs too, using a 
		//		tuple of arguments. This operator will give instances of this object the ability to be used as if they are functions. This version is
		//		for constant instances. Now to invoke a function using a tuple, the syntax is as follows :
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
		//		4. 
	    //
	    //  Possible errors :
	    //
		//		1. The given function failes and throws an exception
		//		2.
	    //
	    inline ReturnValueType operator()( const Tuple< MethodArgumentsTypes... >& arguments ) const;


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
		inline Boolean operator==( const MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType, MethodArgumentsTypes... >& other ) const;


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
		inline Boolean operator!=( const MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType, MethodArgumentsTypes... >& other ) const;


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


	protected:


        // The protected part is used for inheritance. This means that only this object and the objects that inherit from it can use the protected members data or methods


		// This object will store the address of the function
		MethodPointerType member_methodMemoryAddress;

		// This object will store the instance of the object that the method is bound to operate on
		ObjectType member_instance;


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
	    inline ReturnValueType InvokeUsingTuple__Private( const Tuple< MethodArgumentsTypes... >& arguments, IncrementingIntegerSequenceHolder< ArgumentIndices... > );


	    // Method Information :
	    //
	    //  Description :
	    //
	    //      Use this method to invoke the method, using an argument tuple, on the given reference to an instance of the object that the method belongs to.
	    //		This version is for constant instances. This is the method that invoke the method. It is needed to allow an easy call of the tuple. This means 
	    //		for a tuple with 3 arguments, the following code should be written to invoke the method :
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
	    inline ReturnValueType InvokeUsingTuple__Private( const Tuple< MethodArgumentsTypes... >& arguments, IncrementingIntegerSequenceHolder< ArgumentIndices... > ) const;


	};  //  Class MethodPointerBoundToSpecificInstance




































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
	template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
	inline MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType, MethodArgumentsTypes... >::MethodPointerBoundToSpecificInstance() :
	member_state(),
	member_methodMemoryAddress( nullptr ),
	member_instance()
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
	//			1. methodMemoryAddress - the memory address of the function to call
	//			2. instance - a constant reference to an instance that the method will operate on
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
	template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
	inline MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType, MethodArgumentsTypes... >::MethodPointerBoundToSpecificInstance( MethodPointerType methodMemoryAddress, const ObjectType& instance ) :
	member_state( InstanceState::Ready ),
	member_methodMemoryAddress( methodMemoryAddress ),
	member_instance( instance )
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertPointer_MACRO( methodMemoryAddress );
	}


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
	template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
	inline MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType, MethodArgumentsTypes... >::MethodPointerBoundToSpecificInstance( const MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType, MethodArgumentsTypes... >& other ) :
	member_state( other.member_state ),
	member_methodMemoryAddress( other.member_methodMemoryAddress ),
	member_instance( other.member_instance )
	{}


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
	template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
	inline void MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType, MethodArgumentsTypes... >::Swap( MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType, MethodArgumentsTypes... >& other )
	{
	    // Swap betwen the state instances
	    member_state.Swap( other.member_state );

	    // Swap between the functions memory address
	    Memory::Operations::Swap< MethodPointerType >( member_methodMemoryAddress, other.member_methodMemoryAddress );

	    // Swap between the instances
	    member_instance.Swap( other.member_instance );
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
	//			1. methodMemoryAddress - the memory address of the function to call
	//			2. instance - a constant reference to an instance that the method will operate on
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
	template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
	inline void MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType, MethodArgumentsTypes... >::Initiate( MethodPointerType methodMemoryAddress, const ObjectType& instance )
	{
	    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
	    // leave this scope it will delete the old data
	    MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType, MethodArgumentsTypes... > temporary( methodMemoryAddress, instance );

	    // Swap between this instance and the temporary instance
	    Swap( temporary );
	}































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************





























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
	template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
	ReturnValueType MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType, MethodArgumentsTypes... >::operator()( MethodArgumentsTypes... arguments )
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO;

		// Invoke the method using the arguments on the instance of the object that contains the method, and return value
		return ( ( member_instance.*member_methodMemoryAddress )( arguments... ) );
	}


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to invoke the method pointed to by this instance, on an instance of an object that the method belongs too, using the
	//		given arguments. This operator will give instances of this object the ability to be used as if they are functions. This version is for
	//		constant instances
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
	template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
	inline ReturnValueType MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType, MethodArgumentsTypes... >::operator()( MethodArgumentsTypes... arguments ) const
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO;

		// Invoke the method using the arguments on the instance of the object that contains the method, and return value
		return ( ( member_instance.*member_methodMemoryAddress )( arguments... ) );
	}


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
	//		4. 
    //
    //  Possible errors :
    //
	//		1. The given function failes and throws an exception
	//		2.
    //
    template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
    ReturnValueType MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType, MethodArgumentsTypes... >::operator()( const Tuple< MethodArgumentsTypes... >& arguments )
    {
	    // Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO;

        // Set the return value from invoking the function with the tuple of arguments, and return the value
        return ( InvokeUsingTuple__Private( arguments, IncrementingIntegerSequence< sizeof...( MethodArgumentsTypes ) >{} ) );
    }


    // Method Information :
    //
    //  Description :
    //
	//		Use this operator to invoke the method pointed to by this instance, on an instance of an object that the method belongs too, using a 
	//		tuple of arguments. This operator will give instances of this object the ability to be used as if they are functions. This version is
	//		for constant instances. Now to invoke a function using a tuple, the syntax is as follows :
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
	//		4. 
    //
    //  Possible errors :
    //
	//		1. The given function failes and throws an exception
	//		2.
    //
    template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
    inline ReturnValueType MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType, MethodArgumentsTypes... >::operator()( const Tuple< MethodArgumentsTypes... >& arguments ) const
    {
	    // Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO;

        // Set the return value from invoking the function with the tuple of arguments, and return the value
        return ( InvokeUsingTuple__Private( arguments, IncrementingIntegerSequence< sizeof...( MethodArgumentsTypes ) >{} ) );
    }


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
	//      1. true - if the 2 instances are the same
	//      2. false - otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
	inline Boolean MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType, MethodArgumentsTypes... >::operator==( const MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType, MethodArgumentsTypes... >& other ) const
	{
		// Check if the instances point to the same function, and return the result
		return ( member_methodMemoryAddress == other.member_methodMemoryAddress );
	}


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to check if the this instance does not match the other
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
	//      1. true - if the 2 instances are not the same
	//      2. false - otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
	inline Boolean MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType, MethodArgumentsTypes... >::operator!=( const MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType, MethodArgumentsTypes... >& other ) const
	{
		// Return the negotiated value from the equal operator
		return ( !( *this == other ) );
	}







































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************









































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
    template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
    template< UnsignedInteger64bits... ArgumentIndices >
    inline ReturnValueType MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType, MethodArgumentsTypes... >::InvokeUsingTuple__Private( const Tuple< MethodArgumentsTypes... >& arguments, IncrementingIntegerSequenceHolder< ArgumentIndices... > )
    {
        // Invoke the method with the given tuple of arguments
        return ( ( member_instance.*member_methodMemoryAddress )( arguments.template Entry< ArgumentIndices >()... ) );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to invoke the method, using an argument tuple, on the given reference to an instance of the object that the method belongs to.
    //		This version is for constant instances. This is the method that invoke the method. It is needed to allow an easy call of the tuple. This means 
    //		for a tuple with 3 arguments, the following code should be written to invoke the method :
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
    template< typename ObjectType, typename ReturnValueType, typename... MethodArgumentsTypes >
    template< UnsignedInteger64bits... ArgumentIndices >
    inline ReturnValueType MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType, MethodArgumentsTypes... >::InvokeUsingTuple__Private( const Tuple< MethodArgumentsTypes... >& arguments, IncrementingIntegerSequenceHolder< ArgumentIndices... > ) const
    {
        // Invoke the method with the given tuple of arguments
        return ( ( member_instance.*member_methodMemoryAddress )( arguments.template Entry< ArgumentIndices >()... ) );
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
	//		Use this object to store the memory address of a specific function, and allowing to invoke it during run time. This is a template specialization
	//		for functions that does not required any arguments. The difference between a function and method, is that method is a function that belongs to an object
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
	//			2. ReturnValueType - the return value type of the required function
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	template< typename ObjectType, typename ReturnValueType >
	class MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType > : public BaseInvokableObject< ReturnValueType >, public Functor_Interface< ReturnValueType >
	{
	public:


		// Create a type definition for the method using the specific given template arguments
		using MethodPointerType = ReturnValueType ( ObjectType::* )();


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
		inline MethodPointerBoundToSpecificInstance();


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
		//			1. methodMemoryAddress - the memory address of the function to call
		//			2. instance - a constant reference to an instance that the method will operate on
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
		explicit inline MethodPointerBoundToSpecificInstance( MethodPointerType methodMemoryAddress, const ObjectType& instance );


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
		inline MethodPointerBoundToSpecificInstance( const MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType >& other );


		// This macro will be used to all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
		// simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
		// any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
		// be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
		// macro will be used to add the following methods to each object :
		//
		//		1. Assigenment operator
		//		2. Move constructor
		//		3. Move assigenment operator
		//		4. Reset
		//		5. State
		//
		ObjectInfrastructure_ForInheritance_MACRO( ConsiderAsOneArgument( MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType > ) )


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
		inline void Swap( MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType >& other );


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
		//			1. methodMemoryAddress - the memory address of the function to call
		//			2. instance - a constant reference to an instance that the method will operate on
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
		inline void Initiate( MethodPointerType methodMemoryAddress, const ObjectType& instance );


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
		virtual ~MethodPointerBoundToSpecificInstance() = default;


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
		virtual ReturnValueType operator()() override;


		// Method Information :
		//
		//  Description :
		//
		//		Use this operator to invoke the method pointed to by this instance, on an instance of an object that the method belongs too. This operator
		//		will give instances of this object the ability to be used as if they are functions. This version is for constant instances
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
		inline ReturnValueType operator()() const;


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
		inline Boolean operator==( const MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType >& other ) const;


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
		inline Boolean operator!=( const MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType >& other ) const;


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
			static void Test() __attribute__ (( __unused__ )) { MethodPointerBoundToSpecificInstance< InstanceState COMMA UnsignedInteger64bits COMMA UnsignedInteger32bits >::Test(); }

		)  //  End of debug tool


	protected:


        // The protected part is used for inheritance. This means that only this object and the objects that inherit from it can use the protected 
        // members data or methods :


		// This object will store the address of the function
		MethodPointerType member_methodMemoryAddress;

		// This object will store the instance of the object that the method is bound to operate on
		ObjectType member_instance;


	};  //  Class MethodPointerBoundToSpecificInstance







































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
	template< typename ObjectType, typename ReturnValueType >
	inline MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType >::MethodPointerBoundToSpecificInstance() :
	member_state(),
	member_methodMemoryAddress( nullptr ),
	member_instance()
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
	//			1. methodMemoryAddress - the memory address of the function to call
	//			2. instance - a constant reference to an instance that the method will operate on
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
	template< typename ObjectType, typename ReturnValueType >
	inline MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType >::MethodPointerBoundToSpecificInstance( MethodPointerType methodMemoryAddress, const ObjectType& instance ) :
	member_state( InstanceState::Ready ),
	member_methodMemoryAddress( methodMemoryAddress ),
	member_instance( instance )
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertPointer_MACRO( methodMemoryAddress );
	}


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
	template< typename ObjectType, typename ReturnValueType >
	inline MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType >::MethodPointerBoundToSpecificInstance( const MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType >& other ) :
	member_state( other.member_state ),
	member_methodMemoryAddress( other.member_methodMemoryAddress ),
	member_instance( other.member_instance )
	{}


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
	template< typename ObjectType, typename ReturnValueType >
	inline void MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType >::Swap( MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType >& other )
	{	    
	    // Swap betwen the state instances
	    member_state.Swap( other.member_state );

	    // Swap between the functions memory address
	    Memory::Operations::Swap< MethodPointerType >( member_methodMemoryAddress, other.member_methodMemoryAddress );

    	// Swap between the instances
	    member_instance.Swap( other.member_instance );
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
	//			1. methodMemoryAddress - the memory address of the function to call
	//			2. instance - a constant reference to an instance that the method will operate on
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
	template< typename ObjectType, typename ReturnValueType >
	inline void MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType >::Initiate( MethodPointerType methodMemoryAddress, const ObjectType& instance )
	{
	    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
	    // leave this scope it will delete the old data
	    MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType > temporary( methodMemoryAddress, instance );

	    // Swap between this instance and the temporary instance
	    Swap( temporary );
	}



































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************































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
	template< typename ObjectType, typename ReturnValueType >
	ReturnValueType MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType >::operator()()
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO;

		// Invoke the method, and return the value
		return ( ( member_instance.*member_methodMemoryAddress )() );
	}


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to invoke the method pointed to by this instance, on an instance of an object that the method belongs too. This operator
	//		will give instances of this object the ability to be used as if they are functions. This version is for constant instances
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
	template< typename ObjectType, typename ReturnValueType >
	inline ReturnValueType MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType >::operator()() const
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO;

		// Invoke the method, and return the value
		return ( ( member_instance.*member_methodMemoryAddress )() );
	}


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
	//      1. true - if the 2 instances are the same
	//      2. false - otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename ObjectType, typename ReturnValueType >
	inline Boolean MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType >::operator==( const MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType >& other ) const
	{
		// Check if the instances point to the same function, and return the result
		return ( member_methodMemoryAddress == other.member_methodMemoryAddress );
	}


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to check if the this instance does not match the other
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
	//      1. true - if the 2 instances are not the same
	//      2. false - otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename ObjectType, typename ReturnValueType >
	inline Boolean MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType >::operator!=( const MethodPointerBoundToSpecificInstance< ObjectType, ReturnValueType >& other ) const
	{
		// Return the negotiated value from the equal operator
		return ( !( *this == other ) );
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
		//		1. An assertion failed - class Exception or ErrnoException is thrown
		//		2. There is no more free memory space - class std::bad_alloc is thrown
		//		3. 
		//
		template< typename ObjectType COMMA typename ReturnValueType COMMA typename... MethodArgumentsTypes >
		void MethodPointerBoundToSpecificInstance< ObjectType COMMA ReturnValueType COMMA MethodArgumentsTypes... >::Test()
		{
			// Create an instance
			MethodPointerBoundToSpecificInstance< Testing::TestObject_2 COMMA UnsignedInteger32bits COMMA UnsignedInteger32bits COMMA UnsignedInteger64bits > testMethodPointer_1( &Testing::TestObject_2::TestMethod_1, Testing::TestObject_2( 654, 56 ) );

			// Invoke the method
			testMethodPointer_1( 8, 9 );

			// Check that the number of arguments is correct
            Assert_MACRO( ( testMethodPointer_1.ArgumentsNumber() == 2 ), "Test failed - 1" );

			// Check that there is return value
            Assert_MACRO( ( testMethodPointer_1.ReturnValueExist() == true ), "Test failed - 2" );

			// Create an instance
			MethodPointerBoundToSpecificInstance< Testing::TestObject_2 COMMA UnsignedInteger32bits COMMA UnsignedInteger32bits COMMA UnsignedInteger64bits COMMA UnsignedInteger64bits > testMethodPointer_2( &Testing::TestObject_2::TestMethod_2, Testing::TestObject_2( 654, 56 ) );

			// Invoke the method
			auto testReturnValue_1 = testMethodPointer_2( 8, 9, 84758 );

			// Check that the number of arguments is correct
            Assert_MACRO( ( testMethodPointer_2.ArgumentsNumber() == 3 ), "Test failed - 3" );

			// Check that the return value is correct
            Assert_MACRO( ( testReturnValue_1 == 99 ), "Test failed - 4" );

            // Check for a function that doesn't has no retrun value or arguments
            MethodPointerBoundToSpecificInstance< Testing::TestObject_2 COMMA void > testMethodPointer_3( &Testing::TestObject_2::TestMethod_3, Testing::TestObject_2( 654, 56 ) );

			// Invoke the method
			testMethodPointer_3();

			// Check that the number of arguments is correct
            Assert_MACRO( ( testMethodPointer_3.ArgumentsNumber() == 0 ), "Test failed - 5" );

            // Create an instance of the tuple function pointer
	        MethodPointerBoundToSpecificInstance< Testing::TestObject_2 COMMA UnsignedInteger32bits COMMA UnsignedInteger32bits COMMA UnsignedInteger64bits COMMA UnsignedInteger64bits > testMethodPointer_4( &Testing::TestObject_2::TestMethod_2, Testing::TestObject_2( 654, 56 ) );

	        // Check that the number of arguments is correct
	        Assert_MACRO( ( testMethodPointer_4.ArgumentsNumber() == 3 ), "Test failed - 6" );

	        // Invoke the method using a parameter pack
	        auto testReturnValue_2 = testMethodPointer_4( 99, 100, 101 );

	        // Check that the return value is correct
	        Assert_MACRO( ( testReturnValue_2 == 99 ), "Test failed - 7" );

	        // Create a tuple instance
	        Tuple< UnsignedInteger32bits COMMA UnsignedInteger64bits COMMA UnsignedInteger64bits > testTuple_1( 8, 9, 84758, Testing::TestObject_2( 654, 56 ) );

	        // Invoke the method using the tuple
	        auto testReturnValue_3 = testMethodPointer_4( testTuple_1 );

	        // Check that the return value is correct
	        Assert_MACRO( ( testReturnValue_3 == 99 ), "Test failed - 8" );

	        // Create an instance of the tuple function pointer
	        MethodPointerBoundToSpecificInstance< Testing::TestObject_2 COMMA void COMMA UnsignedInteger32bits COMMA UnsignedInteger64bits > TestMethodPointer_5( &Testing::TestObject_2::TestMethod_5, Testing::TestObject_2( 654, 56 ) );

	        // Check that the number of arguments is correct
	        Assert_MACRO( ( TestMethodPointer_5.ArgumentsNumber() == 2 ), "Test failed - 9" );

	        // Invoke the method using a parameter pack
	        TestMethodPointer_5( 99, 100 );

	        // Create a tuple instance
	        Tuple< UnsignedInteger32bits COMMA UnsignedInteger64bits > testTuple_2( 8, 9 );

	        // Invoke the method using the tuple
	        TestMethodPointer_5( testTuple_2 );

            // Create an instance of the tuple function pointer
	        MethodPointerBoundToSpecificInstance< Testing::TestObject_2 COMMA UnsignedInteger32bits > testMethodPointer_6( &Testing::TestObject_2::TestMethod_4, Testing::TestObject_2( 654, 56 ) );

	        // Invoke the method
	        testMethodPointer_6();
		}

	)  //  End of debug tool












}  //  Namespace Universe



#endif  // METHODPOINTERBOUNDTOSPECIFICINSTANCE_HPP