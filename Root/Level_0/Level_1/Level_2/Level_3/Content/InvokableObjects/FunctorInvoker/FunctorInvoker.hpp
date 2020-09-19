#ifndef FUNCTORINVOKER_HPP
#define FUNCTORINVOKER_HPP


#include "../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../Content/Object/ObjectInfrastructure/BasicObjectFunctionality/BasicObjectFunctionality.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../../../../../Content/Object/ObjectInfrastructure/GetAndSetForMembers/GetAndSetForMembers.hpp"  //  Macro Get_MACRO, Macro Set_MACRO
#include "../../../../Content/Memory/Operations/Operations.hpp"  //  Class Operations
#include "../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../CommonFunctionality/BaseInvokableObject/BaseInvokableObject.hpp"  //  Class BaseInvokableObject
#include "../CommonFunctionality/Functor_Interface/Functor_Interface.hpp"  //  Class Functor_Interface
#include "../../BindObjects/Tuple/Tuple.hpp"  //  Class Tuple
#include "../../../../../../Content/Metaprogramming/CommonFunctionality/Sequences/IncrementingIntegerSequenceGenerator/IncrementingIntegerSequenceGenerator.hpp"  //  Typedef IncrementingIntegerSequence


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../../../../../../Test/TestingTools/Objects/TestFunctorObject_1/TestFunctorObject_1.hpp"  //  Class TestFunctorObject_1
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
	//		The purpose of this object is to allow storing a functor, and reused whenever needed
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
	//			1. Type -
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	template< typename FunctorObjectType, typename ReturnValueType, typename... FunctorArgumentTypes >
	class FunctorInvoker : public BaseInvokableObject< ReturnValueType, FunctorArgumentTypes... >, public Functor_Interface< ReturnValueType, FunctorArgumentTypes... >
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
		inline FunctorInvoker();


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
		//			functorInstance - a universal reference to a functor
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
		inline FunctorInvoker( const FunctorObjectType& functorInstance );


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
		inline FunctorInvoker( const FunctorInvoker< FunctorObjectType, ReturnValueType, FunctorArgumentTypes... >& other );


		// This macro will be used to add all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
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
		ObjectInfrastructure_MACRO( FunctorInvoker< FunctorObjectType, ReturnValueType, FunctorArgumentTypes... > )


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
		inline void Swap( FunctorInvoker< FunctorObjectType, ReturnValueType, FunctorArgumentTypes... >& other );


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			functorInstance - a universal reference to a functor
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
		//		They will come
		//
		inline void Initiate( const FunctorObjectType& functorInstance );


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
		virtual ~FunctorInvoker() = default;


		// The following methods declare the overloaded operators for the object :


		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to invoke the functor pointed to be this instance, using the given arguments. This operator will give 
		//		instances of this object the ability to be used as if they are functions
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			arguments - the arguments required to invoke the functor the instance points too
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		The return value from calling the functor 
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		1. The given functor failes and throws an exception
		//		2.
		//
		virtual ReturnValueType operator()( FunctorArgumentTypes... arguments ) override;


		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to invoke the functor pointed to be this instance, using the given arguments. This operator will give 
		//		instances of this object the ability to be used as if they are functions. This version is for constant instances
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			arguments - the arguments required to invoke the functor the instance points too
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		The return value from calling the functor 
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		1. The given functor failes and throws an exception
		//		2.
		//
		inline ReturnValueType operator()( FunctorArgumentTypes... arguments ) const;


	    // Method Information :
	    //
	    //  Description :
	    //
		//      Use this operator to invoke the functor pointed to be this instance, using a tuple of arguments. This operator will give 
		//		instances of this object the ability to be used as if they are functions. Now to invoke a functor using a tuple, the syntax
		//		is as follows :
	    //
	    //				MethodSomething( tupleInstance.Entry< 0 >(), tupleInstance.Entry< 1 >(), tupleInstance.Entry< 2 >() );
	    //
	    //      To avoid writing all the arguments by hand, parameter pack expansion exist. To use it an integer sequence needs to be passed to the function. 
	    //		This sequence will be used to unpack the tuple of arguments, and allow an easy invoke of the functor :
	    //
	    //				MethodSomething( tupleInstance.Entry< INTEGERS >() );
	    //
	    //		Then this method is just a wrapper to the method the receives the integer sequence as an argument and perform the expansion pack, and then
	    //		invoke the functor
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
	    //          arguments - a tuple containing the arguments required to invoke the functor 
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //      The return value from invokeing the functor will be returned
	    //
	    //  Expectations :
	    //
	    //      1. The instance should be ready
	    //      2. 
	    //
	    //  Possible errors :
	    //
		//		1. The given functor failes and throws an exception
		//		2.
	    //
	    virtual ReturnValueType operator()( const Tuple< FunctorArgumentTypes... >& arguments ) override;


	    // Method Information :
	    //
	    //  Description :
	    //
		//      Use this operator to invoke the functor pointed to be this instance, using a tuple of arguments. This operator will give 
		//		instances of this object the ability to be used as if they are functions. This version is for constant instances. Now to invoke a 
		//		functor using a tuple, the syntax is as follows :
	    //
	    //				MethodSomething( tupleInstance.Entry< 0 >(), tupleInstance.Entry< 1 >(), tupleInstance.Entry< 2 >() );
	    //
	    //      To avoid writing all the arguments by hand, parameter pack expansion exist. To use it an integer sequence needs to be passed to the function. 
	    //		This sequence will be used to unpack the tuple of arguments, and allow an easy invoke of the functor :
	    //
	    //				MethodSomething( tupleInstance.Entry< INTEGERS >() );
	    //
	    //		Then this method is just a wrapper to the method the receives the integer sequence as an argument and perform the expansion pack, and then
	    //		invoke the functor
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
	    //          arguments - a tuple containing the arguments required to invoke the functor 
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //      The return value from invokeing the functor will be returned
	    //
	    //  Expectations :
	    //
	    //      1. The instance should be ready
	    //      2. 
	    //
	    //  Possible errors :
	    //
		//		1. The given functor failes and throws an exception
		//		2.
	    //
	    inline ReturnValueType operator()( const Tuple< FunctorArgumentTypes... >& arguments ) const;


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
		inline Boolean operator==( const FunctorInvoker< FunctorObjectType, ReturnValueType, FunctorArgumentTypes... >& other ) const;


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
		inline Boolean operator!=( const FunctorInvoker< FunctorObjectType, ReturnValueType, FunctorArgumentTypes... >& other ) const;


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


		// This object will store the required lambda
		FunctorObjectType member_functor;


        // The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
        // rather help implement it :


	    // Method Information :
	    //
	    //  Description :
	    //
	    //      Use this method to invoke the functor, using a tuple of arguments. Now to invoke a functor using a tuple, the 
	    //		syntax is as follows :
	    //
	    //				MethodSomething( tupleInstance.Entry< 0 >(), tupleInstance.Entry< 1 >(), tupleInstance.Entry< 2 >() );
	    //
	    //      To avoid writing all the arguments by hand, parameter pack expansion exist. To use it an integer sequence needs to be passed to 
	    //		the functor. This sequence will be used to unpack the tuple of arguments, and allow an easy invoke of the lambda 
	    //		expression :
	    //
	    //				MethodSomething( tupleInstance.Entry< INTEGERS >() );
	    //
	    //		Then this method receives an integer sequence as an argument and perform the expansion pack, and then invoke the functor
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
	    //          1. arguments - a tuple containing the arguments required to invoke the functor 
	    //          2. An incrementing integer sequence, it is part of the functionality required to invoke the functor using the tuple
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //      The return value from invokeing the functor will be returned
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
	    inline ReturnValueType InvokeUsingTuple__Private( const Tuple< FunctorArgumentTypes... >& arguments, IncrementingIntegerSequenceHolder< ArgumentIndices... > ) const;


	};  //  Class FunctorInvoker




































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
	template< typename FunctorObjectType, typename ReturnValueType, typename... FunctorArgumentTypes >
	inline FunctorInvoker< FunctorObjectType, ReturnValueType, FunctorArgumentTypes... >::FunctorInvoker() :
	member_state(),
	member_functor()
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
	//			functorInstance - a universal reference to a functor
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
	template< typename FunctorObjectType, typename ReturnValueType, typename... FunctorArgumentTypes >
	inline FunctorInvoker< FunctorObjectType, ReturnValueType, FunctorArgumentTypes... >::FunctorInvoker( const FunctorObjectType& functorInstance ) :
	member_state( InstanceState::Ready ),
	member_functor( functorInstance )
	{}


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
	template< typename FunctorObjectType, typename ReturnValueType, typename... FunctorArgumentTypes >
	inline FunctorInvoker< FunctorObjectType, ReturnValueType, FunctorArgumentTypes... >::FunctorInvoker( const FunctorInvoker< FunctorObjectType, ReturnValueType, FunctorArgumentTypes... >& other ) :
	member_state( other.member_state ),
	member_functor( other.member_functor )
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
	template< typename FunctorObjectType, typename ReturnValueType, typename... FunctorArgumentTypes >
	inline void FunctorInvoker< FunctorObjectType, ReturnValueType, FunctorArgumentTypes... >::Swap( FunctorInvoker< FunctorObjectType, ReturnValueType, FunctorArgumentTypes... >& other )
	{
	    // Swap betwen the state instances
	    member_state.Swap( other.member_state );

	    // Swap between the lambda instances
	    Memory::Operations::Swap< FunctorObjectType >( member_functor, other.member_functor );
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
	//			functorInstance - a universal reference to a functor
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
	template< typename FunctorObjectType, typename ReturnValueType, typename... FunctorArgumentTypes >
	inline void FunctorInvoker< FunctorObjectType, ReturnValueType, FunctorArgumentTypes... >::Initiate( const FunctorObjectType& functorInstance )
	{
	    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
	    // leave this scope it will delete the old data
	    FunctorInvoker< FunctorObjectType, ReturnValueType, FunctorArgumentTypes... > temporary( functorInstance );

	    // Swap between this instance and the temporary instance
	    Swap( temporary );
	}





































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************


































	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to invoke the functor pointed to be this instance, using the given arguments. This operator will give 
	//		instances of this object the ability to be used as if they are functions
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			arguments - the arguments required to invoke the functor the instance points too
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The return value from calling the functor 
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. The given functor failes and throws an exception
	//		2.
	//
	template< typename FunctorObjectType, typename ReturnValueType, typename... FunctorArgumentTypes >
	ReturnValueType FunctorInvoker< FunctorObjectType, ReturnValueType, FunctorArgumentTypes... >::operator()( FunctorArgumentTypes... arguments )
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO;

		// Invoke the functor using the arguments, and return the value
		return ( member_functor( arguments... ) );
	}


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to invoke the functor pointed to be this instance, using the given arguments. This operator will give 
	//		instances of this object the ability to be used as if they are functions. This version is for constant instances
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			arguments - the arguments required to invoke the functor the instance points too
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The return value from calling the functor 
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. The given functor failes and throws an exception
	//		2.
	//
	template< typename FunctorObjectType, typename ReturnValueType, typename... FunctorArgumentTypes >
	inline ReturnValueType FunctorInvoker< FunctorObjectType, ReturnValueType, FunctorArgumentTypes... >::operator()( FunctorArgumentTypes... arguments ) const
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO;

		// Invoke the functor using the arguments, and return the value
		return ( member_functor( arguments... ) );
	}


    // Method Information :
    //
    //  Description :
    //
	//      Use this operator to invoke the functor pointed to be this instance, using a tuple of arguments. This operator will give 
	//		instances of this object the ability to be used as if they are functions. Now to invoke a functor using a tuple, the syntax
	//		is as follows :
    //
    //				MethodSomething( tupleInstance.Entry< 0 >(), tupleInstance.Entry< 1 >(), tupleInstance.Entry< 2 >() );
    //
    //      To avoid writing all the arguments by hand, parameter pack expansion exist. To use it an integer sequence needs to be passed to the function. 
    //		This sequence will be used to unpack the tuple of arguments, and allow an easy invoke of the functor :
    //
    //				MethodSomething( tupleInstance.Entry< INTEGERS >() );
    //
    //		Then this method is just a wrapper to the method the receives the integer sequence as an argument and perform the expansion pack, and then
    //		invoke the functor
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          arguments - a tuple containing the arguments required to invoke the functor 
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      The return value from invokeing the functor will be returned
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. 
    //
    //  Possible errors :
    //
	//		1. The given functor failes and throws an exception
	//		2.
    //
	template< typename FunctorObjectType, typename ReturnValueType, typename... FunctorArgumentTypes >
    ReturnValueType FunctorInvoker< FunctorObjectType, ReturnValueType, FunctorArgumentTypes... >::operator()( const Tuple< FunctorArgumentTypes... >& arguments )
    {
	    // Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO;

        // Invoke the functor with the tuple of arguments, and return the value
        return ( InvokeUsingTuple__Private( arguments, IncrementingIntegerSequence< sizeof...( FunctorArgumentTypes ) >{} ) );
    }


    // Method Information :
    //
    //  Description :
    //
	//      Use this operator to invoke the functor pointed to be this instance, using a tuple of arguments. This operator will give 
	//		instances of this object the ability to be used as if they are functions. This version is for constant instances. Now to invoke a 
	//		functor using a tuple, the syntax is as follows :
    //
    //				MethodSomething( tupleInstance.Entry< 0 >(), tupleInstance.Entry< 1 >(), tupleInstance.Entry< 2 >() );
    //
    //      To avoid writing all the arguments by hand, parameter pack expansion exist. To use it an integer sequence needs to be passed to the function. 
    //		This sequence will be used to unpack the tuple of arguments, and allow an easy invoke of the functor :
    //
    //				MethodSomething( tupleInstance.Entry< INTEGERS >() );
    //
    //		Then this method is just a wrapper to the method the receives the integer sequence as an argument and perform the expansion pack, and then
    //		invoke the functor
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          arguments - a tuple containing the arguments required to invoke the functor 
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      The return value from invokeing the functor will be returned
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. 
    //
    //  Possible errors :
    //
	//		1. The given functor failes and throws an exception
	//		2.
    //
	template< typename FunctorObjectType, typename ReturnValueType, typename... FunctorArgumentTypes >
    inline ReturnValueType FunctorInvoker< FunctorObjectType, ReturnValueType, FunctorArgumentTypes... >::operator()( const Tuple< FunctorArgumentTypes... >& arguments ) const
    {
	    // Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO;

        // Invoke the functor with the tuple of arguments, and return the value
        return ( InvokeUsingTuple__Private( arguments, IncrementingIntegerSequence< sizeof...( FunctorArgumentTypes ) >{} ) );
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
	template< typename FunctorObjectType, typename ReturnValueType, typename... FunctorArgumentTypes >
	inline Boolean FunctorInvoker< FunctorObjectType, ReturnValueType, FunctorArgumentTypes... >::operator==( const FunctorInvoker< FunctorObjectType, ReturnValueType, FunctorArgumentTypes... >& other ) const
	{
		// Compare between the lambda instances, and return the result
		return ( member_functor == other.member_functor );
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
	template< typename FunctorObjectType, typename ReturnValueType, typename... FunctorArgumentTypes >
	inline Boolean FunctorInvoker< FunctorObjectType, ReturnValueType, FunctorArgumentTypes... >::operator!=( const FunctorInvoker< FunctorObjectType, ReturnValueType, FunctorArgumentTypes... >& other ) const
	{
		// Return the negotiated value from the equal operator
		return ( !( *this == other ) );
	}




































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************

































    // Method Information :
    //
    //  Description :
    //
    //      Use this method to invoke the functor, using a tuple of arguments. Now to invoke a functor using a tuple, the 
    //		syntax is as follows :
    //
    //				MethodSomething( tupleInstance.Entry< 0 >(), tupleInstance.Entry< 1 >(), tupleInstance.Entry< 2 >() );
    //
    //      To avoid writing all the arguments by hand, parameter pack expansion exist. To use it an integer sequence needs to be passed to 
    //		the functor. This sequence will be used to unpack the tuple of arguments, and allow an easy invoke of the lambda 
    //		expression :
    //
    //				MethodSomething( tupleInstance.Entry< INTEGERS >() );
    //
    //		Then this method receives an integer sequence as an argument and perform the expansion pack, and then invoke the functor
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. arguments - a tuple containing the arguments required to invoke the functor 
    //          2. An incrementing integer sequence, it is part of the functionality required to invoke the functor using the tuple
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      The return value from invokeing the functor will be returned
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
	template< typename FunctorObjectType, typename ReturnValueType, typename... FunctorArgumentTypes >
    template< UnsignedInteger64bits... ArgumentIndices >
    inline ReturnValueType FunctorInvoker< FunctorObjectType, ReturnValueType, FunctorArgumentTypes... >::InvokeUsingTuple__Private( const Tuple< FunctorArgumentTypes... >& arguments, IncrementingIntegerSequenceHolder< ArgumentIndices... > ) const
    {
        // Invoke the functor with the given tuple of arguments
        return ( member_functor( arguments.template Entry< ArgumentIndices >()... ) );
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
	//		The purpose of this object is to allow storing a functor, and reused whenever needed. This version is for lambda
	//		expressions that require no arguments to be invoked
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
	//			1. Type -
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	template< typename FunctorObjectType, typename ReturnValueType >
	class FunctorInvoker< FunctorObjectType, ReturnValueType > : public BaseInvokableObject< ReturnValueType >, public Functor_Interface< ReturnValueType >
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
		inline FunctorInvoker();


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
		//			functorInstance - a universal reference to a functor
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
		inline FunctorInvoker( const FunctorObjectType& functorInstance );


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
		inline FunctorInvoker( const FunctorInvoker< FunctorObjectType, ReturnValueType >& other );


		// This macro will be used to add all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
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
		ObjectInfrastructure_MACRO( FunctorInvoker< FunctorObjectType, ReturnValueType > )


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
		inline void Swap( FunctorInvoker< FunctorObjectType, ReturnValueType >& other );


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			functorInstance - a universal reference to a functor
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
		//		They will come
		//
		inline void Initiate( const FunctorObjectType& functorInstance );


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
		virtual ~FunctorInvoker() = default;


		// The following methods declare the overloaded operators for the object :


		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to invoke the functor pointed to be this instance, using the given arguments. This operator will give 
		//		instances of this object the ability to be used as if they are functions
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
		//		The return value from calling the functor 
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		1. The given functor failes and throws an exception
		//		2.
		//
		virtual ReturnValueType operator()() override;


		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to invoke the functor pointed to be this instance, using the given arguments. This operator will give 
		//		instances of this object the ability to be used as if they are functions. This version is for constant instances
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
		//		The return value from calling the functor 
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		1. The given functor failes and throws an exception
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
		inline Boolean operator==( const FunctorInvoker< FunctorObjectType, ReturnValueType >& other ) const;


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
		inline Boolean operator!=( const FunctorInvoker< FunctorObjectType, ReturnValueType >& other ) const;


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
			static void Test() __attribute__ (( __unused__ )) { FunctorInvoker< FunctorObjectType COMMA UnsignedInteger64bits COMMA UnsignedInteger64bits >::Test(); }

		)  //  End of debug tool


	private:


		// This object will store the required lambda
		FunctorObjectType member_functor;


	};  //  Class FunctorInvoker




































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
	template< typename FunctorObjectType, typename ReturnValueType >
	inline FunctorInvoker< FunctorObjectType, ReturnValueType >::FunctorInvoker() :
	member_state(),
	member_functor()
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
	//			functorInstance - a universal reference to a functor
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
	template< typename FunctorObjectType, typename ReturnValueType >
	inline FunctorInvoker< FunctorObjectType, ReturnValueType >::FunctorInvoker( const FunctorObjectType& functorInstance ) :
	member_state( InstanceState::Ready ),
	member_functor( functorInstance )
	{}


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
	template< typename FunctorObjectType, typename ReturnValueType >
	inline FunctorInvoker< FunctorObjectType, ReturnValueType >::FunctorInvoker( const FunctorInvoker< FunctorObjectType, ReturnValueType >& other ) :
	member_state( other.member_state ),
	member_functor( other.member_functor )
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
	template< typename FunctorObjectType, typename ReturnValueType >
	inline void FunctorInvoker< FunctorObjectType, ReturnValueType >::Swap( FunctorInvoker< FunctorObjectType, ReturnValueType >& other )
	{
	    // Swap betwen the state instances
	    member_state.Swap( other.member_state );

	    // Swap between the lambda instances
	    Memory::Operations::Swap< FunctorObjectType >( member_functor, other.member_functor );
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
	//			functorInstance - a universal reference to a functor
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
	template< typename FunctorObjectType, typename ReturnValueType >
	inline void FunctorInvoker< FunctorObjectType, ReturnValueType >::Initiate( const FunctorObjectType& functorInstance )
	{
	    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
	    // leave this scope it will delete the old data
	    FunctorInvoker< FunctorObjectType, ReturnValueType > temporary( functorInstance );

	    // Swap between this instance and the temporary instance
	    Swap( temporary );
	}





































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************





































	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to invoke the functor pointed to be this instance, using the given arguments. This operator will give 
	//		instances of this object the ability to be used as if they are functions
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
	//		The return value from calling the functor 
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. The given functor failes and throws an exception
	//		2.
	//
	template< typename FunctorObjectType, typename ReturnValueType >
	ReturnValueType FunctorInvoker< FunctorObjectType, ReturnValueType >::operator()()
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO;

		// Invoke the functor using the arguments, and return the value
		return ( member_functor() );
	}


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to invoke the functor pointed to be this instance, using the given arguments. This operator will give 
	//		instances of this object the ability to be used as if they are functions. This version is for constant instances
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
	//		The return value from calling the functor 
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. The given functor failes and throws an exception
	//		2.
	//
	template< typename FunctorObjectType, typename ReturnValueType >
	inline ReturnValueType FunctorInvoker< FunctorObjectType, ReturnValueType >::operator()() const
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO;

		// Invoke the functor using the arguments, and return the value
		return ( member_functor() );
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
	template< typename FunctorObjectType, typename ReturnValueType >
	inline Boolean FunctorInvoker< FunctorObjectType, ReturnValueType >::operator==( const FunctorInvoker< FunctorObjectType, ReturnValueType >& other ) const
	{
		// Compare between the lambda instances, and return the result
		return ( member_functor == other.member_functor );
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
	template< typename FunctorObjectType, typename ReturnValueType >
	inline Boolean FunctorInvoker< FunctorObjectType, ReturnValueType >::operator!=( const FunctorInvoker< FunctorObjectType, ReturnValueType >& other ) const
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
		//		1. An assertion failed - class Exception is thrown
		//		2. There is no more free memory space - class std::bad_alloc is thrown
		//		3. 
		//
		template< typename FunctorObjectType COMMA typename ReturnValueType COMMA typename... FunctorArgumentTypes >
		void FunctorInvoker< FunctorObjectType COMMA ReturnValueType COMMA FunctorArgumentTypes... >::Test()
		{
			// Create a type definition
			using TestFunctorObjectType = Testing::TestFunctorObject_1< UnsignedInteger64bits COMMA Boolean COMMA UnsignedInteger64bits COMMA UnsignedInteger64bits >;

			// Create a functor instance
			TestFunctorObjectType testFunctor_1( 845UL );

			// Create a test instance
			FunctorInvoker< TestFunctorObjectType COMMA Boolean COMMA UnsignedInteger64bits COMMA UnsignedInteger64bits > testFunctorInvoker_1( testFunctor_1 );

			// Invoke the functor
			testFunctorInvoker_1( 3456UL, 333UL );
		}

	)  //  End of debug tool












}  //  Namespace Universe



#endif  // FUNCTORINVOKER_HPP