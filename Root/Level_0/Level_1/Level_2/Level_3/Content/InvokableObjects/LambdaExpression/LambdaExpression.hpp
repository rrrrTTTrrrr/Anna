#ifndef LAMBDAEXPRESSION_HPP
#define LAMBDAEXPRESSION_HPP


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



	// The following macros, should be used in order to create the instances of the objects implemented in this file. The problem is that the
	// the lambda expression type is unknown, and in the current standard, lambda exprssion signature can not be used a template argument. To
	// overcome this, the following macros exist, they will get the lambda expression itself, the return value and arguments if exist of the
	// lambda expression, and finally also the name for the instance. They will use the capability of the 'auto' keyword to deduce the lambda
	// exprssion type, and using the 'decltype' keyword will create the instance of the required object

	// This type definition is for a lambda expression with no arguments
	#define CreateLambdaExpressionInstanceWithNoArguments( TheLambdaExpressionItself, InstanceName, ReturnValueType ) auto lambda##InstanceName = TheLambdaExpressionItself; LambdaExpression< decltype( lambda##InstanceName ), ReturnValueType > InstanceName( lambda##InstanceName );

	// This type definition is for a lambda expression with arguments. The arguments should be supplied at the location '...'
	#define CreateLambdaExpressionInstanceWithArguments( TheLambdaExpressionItself, InstanceName, ReturnValueType, ... ) auto lambda##InstanceName = TheLambdaExpressionItself; LambdaExpression< decltype(lambda##InstanceName), ReturnValueType, __VA_ARGS__ > InstanceName( lambda##InstanceName );



	// Template Class Information :
	//
	//  Purpose :
	//
	//		The purpose of this object is to allow storing a lambda expression, and reused whenever needed
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
	template< typename LambdaExpressionType, typename ReturnValueType, typename... LambdaEpressionArgumentTypes >
	class LambdaExpression : public BaseInvokableObject< ReturnValueType, LambdaEpressionArgumentTypes... >, public Functor_Interface< ReturnValueType, LambdaEpressionArgumentTypes... >
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
		inline LambdaExpression();


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
		//			lambdaExpression - a universal reference to a lambda expression
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
		explicit inline LambdaExpression( LambdaExpressionType lambdaExpression );


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
		inline LambdaExpression( const LambdaExpression< LambdaExpressionType, ReturnValueType, LambdaEpressionArgumentTypes... >& other );


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
		ObjectInfrastructure_MACRO( LambdaExpression< LambdaExpressionType, ReturnValueType, LambdaEpressionArgumentTypes... > )


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
		inline void Swap( LambdaExpression< LambdaExpressionType, ReturnValueType, LambdaEpressionArgumentTypes... >& other );


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
		//			lambdaExpression - a universal reference to a lambda expression
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
		inline void Initiate( LambdaExpressionType lambdaExpression );


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
		virtual ~LambdaExpression() = default;


		// The following methods declare the overloaded operators for the object :


		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to invoke the lambda expression pointed to be this instance, using the given arguments. This operator will give 
		//		instances of this object the ability to be used as if they are functions
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			arguments - the arguments required to invoke the lambda expression the instance points too
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		The return value from calling the lambda expression 
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		1. The given lambda expression failes and throws an exception
		//		2.
		//
		virtual ReturnValueType operator()( LambdaEpressionArgumentTypes... arguments ) override;


		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to invoke the lambda expression pointed to be this instance, using the given arguments. This operator will give 
		//		instances of this object the ability to be used as if they are functions. This version is for constant instances
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			arguments - the arguments required to invoke the lambda expression the instance points too
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		The return value from calling the lambda expression 
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		1. The given lambda expression failes and throws an exception
		//		2.
		//
		inline ReturnValueType operator()( LambdaEpressionArgumentTypes... arguments ) const;


	    // Method Information :
	    //
	    //  Description :
	    //
		//      Use this operator to invoke the lambda expression pointed to be this instance, using a tuple of arguments. This operator will give 
		//		instances of this object the ability to be used as if they are functions. Now to invoke a lambda expression using a tuple, the syntax
		//		is as follows :
	    //
	    //				MethodSomething( tupleInstance.Entry< 0 >(), tupleInstance.Entry< 1 >(), tupleInstance.Entry< 2 >() );
	    //
	    //      To avoid writing all the arguments by hand, parameter pack expansion exist. To use it an integer sequence needs to be passed to the function. 
	    //		This sequence will be used to unpack the tuple of arguments, and allow an easy invoke of the lambda expression :
	    //
	    //				MethodSomething( tupleInstance.Entry< INTEGERS >() );
	    //
	    //		Then this method is just a wrapper to the method the receives the integer sequence as an argument and perform the expansion pack, and then
	    //		invoke the lambda expression
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
	    //          arguments - a tuple containing the arguments required to invoke the lambda expression 
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //      The return value from invokeing the lambda expression will be returned
	    //
	    //  Expectations :
	    //
	    //      1. The instance should be ready
	    //      2. 
	    //
	    //  Possible errors :
	    //
		//		1. The given lambda expression failes and throws an exception
		//		2.
	    //
	    virtual ReturnValueType operator()( const Tuple< LambdaEpressionArgumentTypes... >& arguments ) override;


	    // Method Information :
	    //
	    //  Description :
	    //
		//      Use this operator to invoke the lambda expression pointed to be this instance, using a tuple of arguments. This operator will give 
		//		instances of this object the ability to be used as if they are functions. This version is for constant instances. Now to invoke a 
		//		lambda expression using a tuple, the syntax is as follows :
	    //
	    //				MethodSomething( tupleInstance.Entry< 0 >(), tupleInstance.Entry< 1 >(), tupleInstance.Entry< 2 >() );
	    //
	    //      To avoid writing all the arguments by hand, parameter pack expansion exist. To use it an integer sequence needs to be passed to the function. 
	    //		This sequence will be used to unpack the tuple of arguments, and allow an easy invoke of the lambda expression :
	    //
	    //				MethodSomething( tupleInstance.Entry< INTEGERS >() );
	    //
	    //		Then this method is just a wrapper to the method the receives the integer sequence as an argument and perform the expansion pack, and then
	    //		invoke the lambda expression
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
	    //          arguments - a tuple containing the arguments required to invoke the lambda expression 
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //      The return value from invokeing the lambda expression will be returned
	    //
	    //  Expectations :
	    //
	    //      1. The instance should be ready
	    //      2. 
	    //
	    //  Possible errors :
	    //
		//		1. The given lambda expression failes and throws an exception
		//		2.
	    //
	    inline ReturnValueType operator()( const Tuple< LambdaEpressionArgumentTypes... >& arguments ) const;


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
		inline Boolean operator==( const LambdaExpression< LambdaExpressionType, ReturnValueType, LambdaEpressionArgumentTypes... >& other ) const;


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
		inline Boolean operator!=( const LambdaExpression< LambdaExpressionType, ReturnValueType, LambdaEpressionArgumentTypes... >& other ) const;


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
		LambdaExpressionType member_lambdaExpression;


        // The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
        // rather help implement it :


	    // Method Information :
	    //
	    //  Description :
	    //
	    //      Use this method to invoke the lambda expression, using a tuple of arguments. Now to invoke a lambda expression using a tuple, the 
	    //		syntax is as follows :
	    //
	    //				MethodSomething( tupleInstance.Entry< 0 >(), tupleInstance.Entry< 1 >(), tupleInstance.Entry< 2 >() );
	    //
	    //      To avoid writing all the arguments by hand, parameter pack expansion exist. To use it an integer sequence needs to be passed to 
	    //		the lambda expression. This sequence will be used to unpack the tuple of arguments, and allow an easy invoke of the lambda 
	    //		expression :
	    //
	    //				MethodSomething( tupleInstance.Entry< INTEGERS >() );
	    //
	    //		Then this method receives an integer sequence as an argument and perform the expansion pack, and then invoke the lambda expression
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
	    //          1. arguments - a tuple containing the arguments required to invoke the lambda expression 
	    //          2. An incrementing integer sequence, it is part of the functionality required to invoke the lambda expression using the tuple
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //      The return value from invokeing the lambda expression will be returned
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
	    inline ReturnValueType InvokeUsingTuple__Private( const Tuple< LambdaEpressionArgumentTypes... >& arguments, IncrementingIntegerSequenceHolder< ArgumentIndices... > ) const;


	};  //  Class LambdaExpression




































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
	template< typename LambdaExpressionType, typename ReturnValueType, typename... LambdaEpressionArgumentTypes >
	inline LambdaExpression< LambdaExpressionType, ReturnValueType, LambdaEpressionArgumentTypes... >::LambdaExpression() :
	member_state(),
	member_lambdaExpression()
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
	//			lambdaExpression - a universal reference to a lambda expression
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
	template< typename LambdaExpressionType, typename ReturnValueType, typename... LambdaEpressionArgumentTypes >
	inline LambdaExpression< LambdaExpressionType, ReturnValueType, LambdaEpressionArgumentTypes... >::LambdaExpression( LambdaExpressionType lambdaExpression ) :
	member_state( InstanceState::Ready ),
	member_lambdaExpression( lambdaExpression )
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
	template< typename LambdaExpressionType, typename ReturnValueType, typename... LambdaEpressionArgumentTypes >
	inline LambdaExpression< LambdaExpressionType, ReturnValueType, LambdaEpressionArgumentTypes... >::LambdaExpression( const LambdaExpression< LambdaExpressionType, ReturnValueType, LambdaEpressionArgumentTypes... >& other ) :
	member_state( other.member_state ),
	member_lambdaExpression( other.member_lambdaExpression )
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
	template< typename LambdaExpressionType, typename ReturnValueType, typename... LambdaEpressionArgumentTypes >
	inline void LambdaExpression< LambdaExpressionType, ReturnValueType, LambdaEpressionArgumentTypes... >::Swap( LambdaExpression< LambdaExpressionType, ReturnValueType, LambdaEpressionArgumentTypes... >& other )
	{
	    // Swap betwen the state instances
	    member_state.Swap( other.member_state );

	    // Swap between the lambda instances
	    Memory::Operations::Swap< LambdaExpressionType >( member_lambdaExpression, other.member_lambdaExpression );
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
	//			lambdaExpression - a universal reference to a lambda expression
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
	template< typename LambdaExpressionType, typename ReturnValueType, typename... LambdaEpressionArgumentTypes >
	inline void LambdaExpression< LambdaExpressionType, ReturnValueType, LambdaEpressionArgumentTypes... >::Initiate( LambdaExpressionType lambdaExpression )
	{
	    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
	    // leave this scope it will delete the old data
	    LambdaExpression< LambdaExpressionType, ReturnValueType, LambdaEpressionArgumentTypes... > temporary( lambdaExpression );

	    // Swap between this instance and the temporary instance
	    Swap( temporary );
	}





































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************


































	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to invoke the lambda expression pointed to be this instance, using the given arguments. This operator will give 
	//		instances of this object the ability to be used as if they are functions
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			arguments - the arguments required to invoke the lambda expression the instance points too
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The return value from calling the lambda expression 
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. The given lambda expression failes and throws an exception
	//		2.
	//
	template< typename LambdaExpressionType, typename ReturnValueType, typename... LambdaEpressionArgumentTypes >
	ReturnValueType LambdaExpression< LambdaExpressionType, ReturnValueType, LambdaEpressionArgumentTypes... >::operator()( LambdaEpressionArgumentTypes... arguments )
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO;

		// Invoke the lambda expression using the arguments, and return the value
		return ( member_lambdaExpression( arguments... ) );
	}


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to invoke the lambda expression pointed to be this instance, using the given arguments. This operator will give 
	//		instances of this object the ability to be used as if they are functions. This version is for constant instances
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			arguments - the arguments required to invoke the lambda expression the instance points too
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The return value from calling the lambda expression 
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. The given lambda expression failes and throws an exception
	//		2.
	//
	template< typename LambdaExpressionType, typename ReturnValueType, typename... LambdaEpressionArgumentTypes >
	inline ReturnValueType LambdaExpression< LambdaExpressionType, ReturnValueType, LambdaEpressionArgumentTypes... >::operator()( LambdaEpressionArgumentTypes... arguments ) const
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO;

		// Invoke the lambda expression using the arguments, and return the value
		return ( member_lambdaExpression( arguments... ) );
	}


    // Method Information :
    //
    //  Description :
    //
	//      Use this operator to invoke the lambda expression pointed to be this instance, using a tuple of arguments. This operator will give 
	//		instances of this object the ability to be used as if they are functions. Now to invoke a lambda expression using a tuple, the syntax
	//		is as follows :
    //
    //				MethodSomething( tupleInstance.Entry< 0 >(), tupleInstance.Entry< 1 >(), tupleInstance.Entry< 2 >() );
    //
    //      To avoid writing all the arguments by hand, parameter pack expansion exist. To use it an integer sequence needs to be passed to the function. 
    //		This sequence will be used to unpack the tuple of arguments, and allow an easy invoke of the lambda expression :
    //
    //				MethodSomething( tupleInstance.Entry< INTEGERS >() );
    //
    //		Then this method is just a wrapper to the method the receives the integer sequence as an argument and perform the expansion pack, and then
    //		invoke the lambda expression
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          arguments - a tuple containing the arguments required to invoke the lambda expression 
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      The return value from invokeing the lambda expression will be returned
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. 
    //
    //  Possible errors :
    //
	//		1. The given lambda expression failes and throws an exception
	//		2.
    //
	template< typename LambdaExpressionType, typename ReturnValueType, typename... LambdaEpressionArgumentTypes >
    ReturnValueType LambdaExpression< LambdaExpressionType, ReturnValueType, LambdaEpressionArgumentTypes... >::operator()( const Tuple< LambdaEpressionArgumentTypes... >& arguments )
    {
	    // Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO;

        // Invoke the lambda expression with the tuple of arguments, and return the value
        return ( InvokeUsingTuple__Private( arguments, IncrementingIntegerSequence< sizeof...( LambdaEpressionArgumentTypes ) >{} ) );
    }


    // Method Information :
    //
    //  Description :
    //
	//      Use this operator to invoke the lambda expression pointed to be this instance, using a tuple of arguments. This operator will give 
	//		instances of this object the ability to be used as if they are functions. This version is for constant instances. Now to invoke a 
	//		lambda expression using a tuple, the syntax is as follows :
    //
    //				MethodSomething( tupleInstance.Entry< 0 >(), tupleInstance.Entry< 1 >(), tupleInstance.Entry< 2 >() );
    //
    //      To avoid writing all the arguments by hand, parameter pack expansion exist. To use it an integer sequence needs to be passed to the function. 
    //		This sequence will be used to unpack the tuple of arguments, and allow an easy invoke of the lambda expression :
    //
    //				MethodSomething( tupleInstance.Entry< INTEGERS >() );
    //
    //		Then this method is just a wrapper to the method the receives the integer sequence as an argument and perform the expansion pack, and then
    //		invoke the lambda expression
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          arguments - a tuple containing the arguments required to invoke the lambda expression 
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      The return value from invokeing the lambda expression will be returned
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. 
    //
    //  Possible errors :
    //
	//		1. The given lambda expression failes and throws an exception
	//		2.
    //
	template< typename LambdaExpressionType, typename ReturnValueType, typename... LambdaEpressionArgumentTypes >
    inline ReturnValueType LambdaExpression< LambdaExpressionType, ReturnValueType, LambdaEpressionArgumentTypes... >::operator()( const Tuple< LambdaEpressionArgumentTypes... >& arguments ) const
    {
	    // Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO;

        // Invoke the lambda expression with the tuple of arguments, and return the value
        return ( InvokeUsingTuple__Private( arguments, IncrementingIntegerSequence< sizeof...( LambdaEpressionArgumentTypes ) >{} ) );
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
	template< typename LambdaExpressionType, typename ReturnValueType, typename... LambdaEpressionArgumentTypes >
	inline Boolean LambdaExpression< LambdaExpressionType, ReturnValueType, LambdaEpressionArgumentTypes... >::operator==( const LambdaExpression< LambdaExpressionType, ReturnValueType, LambdaEpressionArgumentTypes... >& other ) const
	{
		// Compare between the lambda instances, and return the result
		return ( member_lambdaExpression == other.member_lambdaExpression );
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
	template< typename LambdaExpressionType, typename ReturnValueType, typename... LambdaEpressionArgumentTypes >
	inline Boolean LambdaExpression< LambdaExpressionType, ReturnValueType, LambdaEpressionArgumentTypes... >::operator!=( const LambdaExpression< LambdaExpressionType, ReturnValueType, LambdaEpressionArgumentTypes... >& other ) const
	{
		// Return the negotiated value from the equal operator
		return ( !( *this == other ) );
	}




































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************

































    // Method Information :
    //
    //  Description :
    //
    //      Use this method to invoke the lambda expression, using a tuple of arguments. Now to invoke a lambda expression using a tuple, the 
    //		syntax is as follows :
    //
    //				MethodSomething( tupleInstance.Entry< 0 >(), tupleInstance.Entry< 1 >(), tupleInstance.Entry< 2 >() );
    //
    //      To avoid writing all the arguments by hand, parameter pack expansion exist. To use it an integer sequence needs to be passed to 
    //		the lambda expression. This sequence will be used to unpack the tuple of arguments, and allow an easy invoke of the lambda 
    //		expression :
    //
    //				MethodSomething( tupleInstance.Entry< INTEGERS >() );
    //
    //		Then this method receives an integer sequence as an argument and perform the expansion pack, and then invoke the lambda expression
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. arguments - a tuple containing the arguments required to invoke the lambda expression 
    //          2. An incrementing integer sequence, it is part of the functionality required to invoke the lambda expression using the tuple
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      The return value from invokeing the lambda expression will be returned
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
	template< typename LambdaExpressionType, typename ReturnValueType, typename... LambdaEpressionArgumentTypes >
    template< UnsignedInteger64bits... ArgumentIndices >
    inline ReturnValueType LambdaExpression< LambdaExpressionType, ReturnValueType, LambdaEpressionArgumentTypes... >::InvokeUsingTuple__Private( const Tuple< LambdaEpressionArgumentTypes... >& arguments, IncrementingIntegerSequenceHolder< ArgumentIndices... > ) const
    {
        // Invoke the lambda expression with the given tuple of arguments
        return ( member_lambdaExpression( arguments.template Entry< ArgumentIndices >()... ) );
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
	//		The purpose of this object is to allow storing a lambda expression, and reused whenever needed. This version is for lambda
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
	template< typename LambdaExpressionType, typename ReturnValueType >
	class LambdaExpression< LambdaExpressionType, ReturnValueType > : public BaseInvokableObject< ReturnValueType >, public Functor_Interface< ReturnValueType >
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
		inline LambdaExpression();


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
		//			lambdaExpression - a universal reference to a lambda expression
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
		explicit inline LambdaExpression( LambdaExpressionType lambdaExpression );


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
		inline LambdaExpression( const LambdaExpression< LambdaExpressionType, ReturnValueType >& other );


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
		ObjectInfrastructure_MACRO( LambdaExpression< LambdaExpressionType, ReturnValueType > )


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
		inline void Swap( LambdaExpression< LambdaExpressionType, ReturnValueType >& other );


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
		//			lambdaExpression - a universal reference to a lambda expression
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
		inline void Initiate( LambdaExpressionType lambdaExpression );


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
		virtual ~LambdaExpression() = default;


		// The following methods declare the overloaded operators for the object :


		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to invoke the lambda expression pointed to be this instance, using the given arguments. This operator will give 
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
		//		The return value from calling the lambda expression 
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		1. The given lambda expression failes and throws an exception
		//		2.
		//
		virtual ReturnValueType operator()() override;


		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to invoke the lambda expression pointed to be this instance, using the given arguments. This operator will give 
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
		//		The return value from calling the lambda expression 
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		1. The given lambda expression failes and throws an exception
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
		inline Boolean operator==( const LambdaExpression< LambdaExpressionType, ReturnValueType >& other ) const;


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
		inline Boolean operator!=( const LambdaExpression< LambdaExpressionType, ReturnValueType >& other ) const;


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
			static void Test() __attribute__ (( __unused__ )) { LambdaExpression< LambdaExpressionType COMMA ReturnValueType COMMA UnsignedInteger64bits >::Test(); }

		)  //  End of debug tool


	private:


		// This object will store the required lambda
		LambdaExpressionType member_lambdaExpression;


	};  //  Class LambdaExpression




































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
	template< typename LambdaExpressionType, typename ReturnValueType >
	inline LambdaExpression< LambdaExpressionType, ReturnValueType >::LambdaExpression() :
	member_state(),
	member_lambdaExpression()
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
	//			lambdaExpression - a universal reference to a lambda expression
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
	template< typename LambdaExpressionType, typename ReturnValueType >
	inline LambdaExpression< LambdaExpressionType, ReturnValueType >::LambdaExpression( LambdaExpressionType lambdaExpression ) :
	member_state( InstanceState::Ready ),
	member_lambdaExpression( lambdaExpression )
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
	template< typename LambdaExpressionType, typename ReturnValueType >
	inline LambdaExpression< LambdaExpressionType, ReturnValueType >::LambdaExpression( const LambdaExpression< LambdaExpressionType, ReturnValueType >& other ) :
	member_state( other.member_state ),
	member_lambdaExpression( other.member_lambdaExpression )
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
	template< typename LambdaExpressionType, typename ReturnValueType >
	inline void LambdaExpression< LambdaExpressionType, ReturnValueType >::Swap( LambdaExpression< LambdaExpressionType, ReturnValueType >& other )
	{
	    // Swap betwen the state instances
	    member_state.Swap( other.member_state );

	    // Swap between the lambda instances
	    Memory::Operations::Swap< LambdaExpressionType >( member_lambdaExpression, other.member_lambdaExpression );
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
	//			lambdaExpression - a universal reference to a lambda expression
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
	template< typename LambdaExpressionType, typename ReturnValueType >
	inline void LambdaExpression< LambdaExpressionType, ReturnValueType >::Initiate( LambdaExpressionType lambdaExpression )
	{
	    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
	    // leave this scope it will delete the old data
	    LambdaExpression< LambdaExpressionType, ReturnValueType > temporary( lambdaExpression );

	    // Swap between this instance and the temporary instance
	    Swap( temporary );
	}





































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************





































	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to invoke the lambda expression pointed to be this instance, using the given arguments. This operator will give 
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
	//		The return value from calling the lambda expression 
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. The given lambda expression failes and throws an exception
	//		2.
	//
	template< typename LambdaExpressionType, typename ReturnValueType >
	ReturnValueType LambdaExpression< LambdaExpressionType, ReturnValueType >::operator()()
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO;

		// Invoke the lambda expression using the arguments, and return the value
		return ( member_lambdaExpression() );
	}


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to invoke the lambda expression pointed to be this instance, using the given arguments. This operator will give 
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
	//		The return value from calling the lambda expression 
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. The given lambda expression failes and throws an exception
	//		2.
	//
	template< typename LambdaExpressionType, typename ReturnValueType >
	inline ReturnValueType LambdaExpression< LambdaExpressionType, ReturnValueType >::operator()() const
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO;

		// Invoke the lambda expression using the arguments, and return the value
		return ( member_lambdaExpression() );
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
	template< typename LambdaExpressionType, typename ReturnValueType >
	inline Boolean LambdaExpression< LambdaExpressionType, ReturnValueType >::operator==( const LambdaExpression< LambdaExpressionType, ReturnValueType >& other ) const
	{
		// Compare between the lambda instances, and return the result
		return ( member_lambdaExpression == other.member_lambdaExpression );
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
	template< typename LambdaExpressionType, typename ReturnValueType >
	inline Boolean LambdaExpression< LambdaExpressionType, ReturnValueType >::operator!=( const LambdaExpression< LambdaExpressionType, ReturnValueType >& other ) const
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
		template< typename LambdaExpressionType COMMA typename ReturnValueType COMMA typename... LambdaEpressionArgumentTypes >
		void LambdaExpression< LambdaExpressionType COMMA ReturnValueType COMMA LambdaEpressionArgumentTypes... >::Test()
		{
			// Create a test instance
			CreateLambdaExpressionInstanceWithNoArguments( []() -> void 
			{ 

				UnsignedInteger64bits temporary = 89; ++temporary; 

			}, testLambdaExpression_1, void )

			// Invoke the test instance
			testLambdaExpression_1();

			// Create a temporary
			UnsignedInteger64bits testTemporary_1 = 98UL;

			// Create a test instance
			CreateLambdaExpressionInstanceWithNoArguments( [ testTemporary_1 ]() -> void 
			{ 

				UnsignedInteger64bits temporary = testTemporary_1; ++temporary; 

			}, testLambdaExpression_2, void )

			// Invoke the test instance
			testLambdaExpression_2();

			// Create a temporary
			UnsignedInteger64bits testTemporary_2 = 98UL;

			// Create a test instance
			CreateLambdaExpressionInstanceWithNoArguments( ConsiderAsOneArgument( [ testTemporary_1, testTemporary_2 ]() -> void 
			{ 

				UnsignedInteger64bits temporary = testTemporary_1; temporary += testTemporary_2; 

			} ), testLambdaExpression_3, void )

			// Invoke the test instance
			testLambdaExpression_3();

			// Create a test instance
			CreateLambdaExpressionInstanceWithArguments( []( UnsignedInteger64bits ) -> void 
			{ 

				UnsignedInteger64bits temporary = 89; ++temporary; 

			}, testLambdaExpression_4, void, UnsignedInteger64bits )

			// Invoke the test instance
			testLambdaExpression_4( 456UL );

			// Create a test instance
			CreateLambdaExpressionInstanceWithArguments( [ testTemporary_1 ]( UnsignedInteger64bits, UnsignedInteger32bits ) -> void 
			{ 

				UnsignedInteger64bits temporary = testTemporary_1; ++temporary; 

			}, testLambdaExpression_5, void, UnsignedInteger64bits, UnsignedInteger32bits )

			// Invoke the test instance
			testLambdaExpression_5( 456UL, 897 );

			// Create a test instance
			CreateLambdaExpressionInstanceWithArguments( ConsiderAsOneArgument( [ testTemporary_1, testTemporary_2 ]( UnsignedInteger64bits ) -> void 
			{ 

				UnsignedInteger64bits temporary = testTemporary_1; temporary += testTemporary_2; 

			} ), testLambdaExpression_6, void, UnsignedInteger64bits )

			// Invoke the test instance
			testLambdaExpression_6( 456UL );
		}

	)  //  End of debug tool












}  //  Namespace Universe



#endif  // LAMBDAEXPRESSION_HPP