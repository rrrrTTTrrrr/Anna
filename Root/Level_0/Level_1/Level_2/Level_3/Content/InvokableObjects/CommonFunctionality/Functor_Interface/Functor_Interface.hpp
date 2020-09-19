#ifndef FUNCTOR_INTERFACE_HPP
#define FUNCTOR_INTERFACE_HPP


#include "../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../Content/BindObjects/Tuple/Tuple.hpp"  //  Class Tuple


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



	// Class Information :
	//
	//  Purpose :
	//
	//		The purpose of this object is to allow an instance, of the object that will inherit from this interface and implement it, to be 
	//		called as if it were a function. The advantage of using a functor instead of a function, is the ability to store a state, that
	//		can propgate to the next call, and the next call, which function mostly can not allow. The only technique in function is to declare
	//		a static local variable, but it does not helo in most cases. A functor on the other hand is an object, which can store members
	//		and manipulate them in every way it is needed.
	//
	//		For example, the followng function declaration :
	//
	//			void FunctionSoviet();
	//
	//		Now this function can be invoked simply by :
	//
	//			FunctionSoviet();
	//
	//		An object that overload the operator parenthesis '()', can be called the same :
	//
	//			class FunctorSoviet
	//			{
	//				void operator()() {}
	//			};
	//
	//		And using it :
	//
	//			FunctorSoviet sovietFunctorInstance;
	//			sovietFunctorInstance();		
	//
	//		Just as if it is a function call!
	//
	//  Description :
	//
	//		1. The main purpose of an interface is to ensure that the group of objects that inherit from it, will be forced to implement some
	//		   functionality. The interface will decalre some methods, will not implement them, and the purpose that all the inherting objects
	//		   will have to implement them. This methods that the interface decalres but doesn't provide a definition are called pure virtual,
	//		   methods. The syntax for pure virtual methods are :
	//
	//				virtual void PureVirutalMethod( UnsignedInteger64bits number ) = 0;
	//
	//		   A pure virtual method means, that the object 'lacks' some part of the implementation, and therefore no instances of the object
	//		   can be created, because it is not a 'complete object'. Now, each object that inherits from it, will be forced to implement that
	//		   missing functionality, and instances of the inherting object can exist. As said above this is good to ensure a group of objects
	//		   implement some functionality, but it also gives the ability to point only to the 'interface part' of the object and use it without
	//		   actually knowing the exact type of the object. This is used, for example, to create containers of pointers to different objects,
	//		   that all inherit from the same object, and this is also valid to base objects that are not pure interfaces
	//
	// 		1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
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
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	template< typename ReturnValueType, typename... FunctorArgumentTypes >
	class Functor_Interface
	{
	public:


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
		inline Functor_Interface() = default;


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
		inline Functor_Interface( const Functor_Interface< ReturnValueType, FunctorArgumentTypes... >& other ) = default;


		// Method Information :
		//
		//  Description :
		//
		//      Assignment operator, can handle with self assignment and instances in default state
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          other - a reference to the object that should be copied
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      A reference to this object
		//
		//  Excpectations :
		//
		//      NONE
		//
		//  Possible errors :
		//
		//      They will come
		//
		inline Functor_Interface< ReturnValueType, FunctorArgumentTypes... >& operator=( const Functor_Interface< ReturnValueType, FunctorArgumentTypes... >& other ) = default;


		// Method Information :
		//
		//  Description :
		//
		//      Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances in default state
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          other - a reference to the object that should be moved
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      NONE
		//
		//  Excpectations :
		//
		//      NONE
		//
		//  Possible errors :
		//
		//      They will come
		//
		inline Functor_Interface( Functor_Interface< ReturnValueType, FunctorArgumentTypes... >&& other ) = default;


		// Method Information :
		//
		//  Description :
		//
		//      Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          other - a reference to the object that should be moved
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      A reference to this object
		//
		//  Excpectations :
		//
		//      NONE
		//
		//  Possible errors :
		//
		//      They will come
		//
		inline Functor_Interface< ReturnValueType, FunctorArgumentTypes... >& operator=( Functor_Interface< ReturnValueType, FunctorArgumentTypes... >&& other ) = default;


		// Method Information :
		//
		//  Description :
		//
		//		Destructor, does not throw. Only declared to ensure that each object that inherits from this interface, will have a virtual desctructor
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
		virtual ~Functor_Interface() = default;


		// The following methods declare the overloaded operators for the object, which each inherting object will have to implement :


		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to invoke the functor pointed to be this instance, using a tuple of arguments. This operator will give instances of
		//		this object the ability to be used as if they are functions
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			arguments - the arguments required to invoke the functor
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		The return value from invoking the function will be returned
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		virtual ReturnValueType operator()( FunctorArgumentTypes... arguments ) = 0;


		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to invoke the functor pointed to be this instance, using a tuple of arguments. This operator will give instances of
		//		this object the ability to be used as if they are functions. Now to invoke a function using a tuple, the syntax is as follows :
	    //
	    //				MethodSomething( tupleInstance.Entry< 0 >(), tupleInstance.Entry< 1 >(), tupleInstance.Entry< 2 >() );
	    //
	    //      To avoid writing all the arguments by hand, parameter pack expansion exist. To use it an integer sequence needs to be passed to the function. 
	    //		This sequence will be used to unpack the tuple of arguments, and allow an easy invoke of the function :
	    //
	    //				MethodSomething( tupleInstance.Entry< INTEGERS >() );
	    //
	    //		Then this method is just a wrapper to the method the receives the integer sequence as an argument and perform the expansion pack, and then
	    //		invoke the functor
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			arguments - a tuple containing the arguments required to invoke the functor
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		The return value from invoking the function will be returned
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		virtual ReturnValueType operator()( const Tuple< FunctorArgumentTypes... >& arguments ) = 0;


	};  //  Class HeaderFileNameFirstLetterUpperCase































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - No arguments needed   **************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //

































	// Class Information :
	//
	//  Purpose :
	//
	//		The purpose of this object is to allow an instance, of the object that will inherit from this interface and implement it, to be 
	//		called as if it were a function. The advantage of using a functor instead of a function, is the ability to store a state, that
	//		can propgate to the next call, and the next call, which function mostly can not allow. The only technique in function is to declare
	//		a static local variable, but it does not helo in most cases. A functor on the other hand is an object, which can store members
	//		and manipulate them in every way it is needed. This version is for functors that dont't require any arguments to be invoked!
	//
	//		For example, the followng function declaration :
	//
	//			void FunctionSoviet();
	//
	//		Now this function can be invoked simply by :
	//
	//			FunctionSoviet();
	//
	//		An object that overload the operator parenthesis '()', can be called the same :
	//
	//			class FunctorSoviet
	//			{
	//				void operator()() {}
	//			};
	//
	//		And using it :
	//
	//			FunctorSoviet sovietFunctorInstance;
	//			sovietFunctorInstance();		
	//
	//		Just as if it is a function call!
	//
	//  Description :
	//
	//		1. The main purpose of an interface is to ensure that the group of objects that inherit from it, will be forced to implement some
	//		   functionality. The interface will decalre some methods, will not implement them, and the purpose that all the inherting objects
	//		   will have to implement them. This methods that the interface decalres but doesn't provide a definition are called pure virtual,
	//		   methods. The syntax for pure virtual methods are :
	//
	//				virtual void PureVirutalMethod( UnsignedInteger64bits number ) = 0;
	//
	//		   A pure virtual method means, that the object 'lacks' some part of the implementation, and therefore no instances of the object
	//		   can be created, because it is not a 'complete object'. Now, each object that inherits from it, will be forced to implement that
	//		   missing functionality, and instances of the inherting object can exist. As said above this is good to ensure a group of objects
	//		   implement some functionality, but it also gives the ability to point only to the 'interface part' of the object and use it without
	//		   actually knowing the exact type of the object. This is used, for example, to create containers of pointers to different objects,
	//		   that all inherit from the same object, and this is also valid to base objects that are not pure interfaces
	//
	// 		1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
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
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	template< typename ReturnValueType >
	class Functor_Interface< ReturnValueType >
	{
	public:


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
		inline Functor_Interface() = default;


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
		inline Functor_Interface( const Functor_Interface< ReturnValueType >& other ) = default;


		// Method Information :
		//
		//  Description :
		//
		//      Assignment operator, can handle with self assignment and instances in default state
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          other - a reference to the object that should be copied
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      A reference to this object
		//
		//  Excpectations :
		//
		//      NONE
		//
		//  Possible errors :
		//
		//      They will come
		//
		inline Functor_Interface< ReturnValueType >& operator=( const Functor_Interface< ReturnValueType >& other ) = default;


		// Method Information :
		//
		//  Description :
		//
		//      Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances in default state
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          other - a reference to the object that should be moved
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      NONE
		//
		//  Excpectations :
		//
		//      NONE
		//
		//  Possible errors :
		//
		//      They will come
		//
		inline Functor_Interface( Functor_Interface< ReturnValueType >&& other ) = default;


		// Method Information :
		//
		//  Description :
		//
		//      Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          other - a reference to the object that should be moved
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      A reference to this object
		//
		//  Excpectations :
		//
		//      NONE
		//
		//  Possible errors :
		//
		//      They will come
		//
		inline Functor_Interface< ReturnValueType >& operator=( Functor_Interface< ReturnValueType >&& other ) = default;


		// Method Information :
		//
		//  Description :
		//
		//		Destructor, does not throw. Only declared to ensure that each object that inherits from this interface, will have a virtual desctructor
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
		virtual ~Functor_Interface() = default;


		// The following methods declare the overloaded operators for the object, which each inherting object will have to implement :


		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to invoke the functor pointed to be this instance, using a tuple of arguments. This operator will give instances of
		//		this object the ability to be used as if they are functions
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			arguments - the arguments required to invoke the functor
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		The return value from invoking the function will be returned
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		virtual ReturnValueType operator()() = 0;


	};  //  Class HeaderFileNameFirstLetterUpperCase










}  //  Namespace Universe



#endif  // FUNCTOR_INTERFACE_HPP