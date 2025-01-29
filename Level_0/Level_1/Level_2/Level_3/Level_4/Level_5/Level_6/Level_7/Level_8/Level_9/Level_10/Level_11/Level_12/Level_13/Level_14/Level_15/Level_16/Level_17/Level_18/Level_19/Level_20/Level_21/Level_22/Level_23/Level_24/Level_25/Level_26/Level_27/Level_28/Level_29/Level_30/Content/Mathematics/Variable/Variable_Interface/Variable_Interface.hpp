#ifndef MATHEMATICS_VARIABLE_INTERFACE
#define MATHEMATICS_VARIABLE_INTERFACE


#include "../../../../../../../../../../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../../../../../../../../../../../../Content/Object/ObjectInfrastructure/BasicObjectFunctionality/BasicObjectFunctionality.hpp"  //  Macro ObjectInfrastructure


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe
{


	namespace Mathematics
    {



		// In mathematics the order of operations is a collection of rules that reflect conventions about which procedures to perform first in order
		// to evaluate a given mathematical expression.
		//
		// For example, multiplication is granted a higher precedence than addition, and it had been this way since the introduction of modern algebric
		// notation. Thus, the expression :
		//
		//		1 + 2 * 3
		//
		// Is interpreted to have the value :
		//
		//		1 + (2 * 3) = 7
		//
		// And not :
		//
		//		(1 +  2) * 3 = 9
		//
		// When exponents were introduced in the 16th and 17th centuries, they were given precedence over both addition and multiplication, and could
		// be placed only as superscript to the right of their base. Thus :
		//
		//		3 + 5^2 = 28
		//
		// And :
		//
		//		3 * 5^2 = 75
		//
		// These conventions exist to eliminate notational ambiguity, while allowing notation to be as brief as possible. Where it is desired to 
		// override the precedence conventions, or even simply to emphasize them, parentheses '()' can be used to indicate an alternative order of
		// operations. 
		//
		// The order of operations, which is used throughout mathematics, is as follows :
		//
		//	1. exponentiation and root extraction
		//	2. multiplication and division
		//	3. addition and subtraction



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
		//		1. The main purpose of an interface is to ensure that the group of objects which inherit from it, will be forced to implement some
		//		   functionality. The interface will only decalre some methods, without implementing them. The point is that all the inherting objects
		//		   will have to implement the lacking functionality. Methods that are only declared, and do not have implementation in the object, are
		//		   called pure virtual methods. The syntax for pure virtual methods is :
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
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		Too many to count
		//
		class Variable_Interface
		{
		public:


			// Create a type definition for this object
			using SelfType = Variable_Interface;


			// This macro will be used to add all the infrastructure of an interface. All the methods will have the default behaviour generated by the compiler :
			//
			//		1. Defualt constructor
			//		2. Copy constructor
			//		3. Assignment operator
			//		4. Move constructor
			//		5. Move assignment operator
			//		6. Destructor
			//
			InterfaceInfrastructure_ForInheritance( Variable_Interface )


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
			virtual FloatingPoint64bits Value( FloatingPoint64bits value ) const = 0;


		};  //  Class Variable_Interface



	}  //  Namespace Mathematics


}  //  Namespace Universe



#endif  // MATHEMATICS_VARIABLE_INTERFACE