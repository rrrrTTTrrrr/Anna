#ifndef  TYPECHECK_BUILTINTYPE_HPP
#define  TYPECHECK_BUILTINTYPE_HPP


#include "../../../../../CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  // Macro DEBUG_TOOL, Macro COMMA, Typedef Boolean, Typedef UnsignedInteger8bits, Typedef UnsignedInteger16bits, Typedef UnsignedInteger32bits, Typedef UnsignedInteger64bits, Typedef SignedInteger8bits, Typedef SignedInteger16bits, Typedef SignedInteger32bits, Typedef SignedInteger64bits
#include "../../../../CommonFunctionality/IntegralConstant/IntegralConstant.hpp"  //  Class IntegralConstant
#include "../../Integers/TypeCheck_Integer/TypeCheck_Integer.hpp"  //  Class TypeCheck_Integer
#include "../../Reference/TypeCheck_Reference/TypeCheck_Reference.hpp"  //  Class TypeCheck_Reference
#include "../../Pointers/TypeCheck_Pointer/TypeCheck_Pointer.hpp"  //  Class TypeCheck_Pointer
#include "../../FloatingPoint/TypeCheck_FloatingPoint/TypeCheck_FloatingPoint.hpp"  //  Class TypeCheck_FloatingPoint


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



	// Template Class Information :
	//
	//  Purpose :
	//
	//		Use this object to provide a type check. In general If the given type is a built in type, something the C++ provides as default to
    //      write code, which means it does not provide all the functionality of an object, which include how to construt, destory, copy, initialize
    //      and more and more, this object will contain a boolean value of true, and otherwise false. This is needed because built in type will need
    //      different behavior usually then objects, for example they have usually a defualt state of 0, and not through the default construtor or 
    //      the reset method. There are 4 options of built in types :
    //
    //          1. Integers
    //          2. Floating points
    //          3. Pointers
    //          4. Reference ( lvalue and rvalue )
    //
    //      And all have also the constant option
	//
	//  Description :
	//
    //      1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
    //         providing 3 keywords :
    //
    //          1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
    //                      obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
    //                      member is public all the encapsulation is lost, so it should be avoided in most cases
    //
    //          2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will
    //                         be able to access all the data and methods inside this part. This part will usually containt some methods and few
    //                         data members
    //
    //          3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
    //                       and all the methods the developer needed to implement the interface presented in the public part. Every method in this
    //                       part will end with the suffix __Private
    //
    //      2. Template arguments :
    //
    //          1. Type - any type
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	template< typename Type >
	class TypeCheck_BuiltInType : public IntegralConstant< Boolean, TypeCheck_Integer< Type >::Result() || TypeCheck_Pointer< Type >::Result() || TypeCheck_Reference< Type >::Result() || TypeCheck_FloatingPoint< Type >::Result() >
	{
	private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( TypeCheck_BuiltInType )


	};  //  Class TypeCheck_BuiltInType










}  //  Namespace Universe



#endif  // TYPECHECK_BUILTINTYPE_HPP