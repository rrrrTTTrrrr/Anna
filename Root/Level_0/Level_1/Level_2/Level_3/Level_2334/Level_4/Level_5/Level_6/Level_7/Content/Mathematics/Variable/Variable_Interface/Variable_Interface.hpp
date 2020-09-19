#ifndef VARIABLE_INTERFACE_HPP
#define VARIABLE_INTERFACE_HPP


#include "../../../../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe
{

	namespace Mathematics
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
		//		In elementry mathematics, a variable is a symbol, commonly a singlel letter, that represents a number, called the value of the variable,
		//		which is either arbitrary, not fully specified, or unknown. "Variable" comes from a Latin word, 'variabilis', with 'vari' meaning various 
		//		and 'abilis' meaning able, meaning "capable of changing". This means that a varaible in mathematics is sort of a place holder, it holds
		//		a certain operation, that will be performed once the value of the variable is given, which that can be any arbitrary numeric value. For
		//		example :
		//
		//			2 * X
		//
		//		The operation of the variable is multiply the given numeric value by 2, and that would be the result of the variable for the specific value.
		//		Variables can perform on the value any of the following :
		//
		//			1. Multiply by a coefficient
		//	
		//			2. Take the power of
		//
		//			3. Take the logarithm
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
		template< typename NumericType >
		class Variable_Interface
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
			inline Variable_Interface() = default;


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
			inline Variable_Interface( const Variable_Interface< NumericType >& other ) = default;


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
			inline Variable_Interface< NumericType >& operator=( const Variable_Interface< NumericType >& other ) = default;


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
			inline Variable_Interface( Variable_Interface< NumericType >&& other ) = default;


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
			inline Variable_Interface< NumericType >& operator=( Variable_Interface< NumericType >&& other ) = default;


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
			virtual ~Variable_Interface() = default;


			// The following methods are the interface that each inherting object will have to implement :


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to get the "result" of the variable, when acted on the given value
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			value - this will be used as the value of the variable to perform the calculation
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		The "result" of the variable, when acted on the given value		
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			virtual NumericType Value( NumericType value ) = 0;


		};  //  Class HeaderFileNameFirstLetterUpperCase








	}  //  Namespace Mathematics

}  //  Namespace Universe



#endif  // VARIABLE_INTERFACE_HPP