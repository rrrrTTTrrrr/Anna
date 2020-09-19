#ifndef TYPECHECK_CALLABLE_HPP
#define TYPECHECK_CALLABLE_HPP


#include "../../../../CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA, Macro CompileTimeAssert
#include "../../../CommonFunctionality/IntegralConstant/IntegralConstant.hpp"  //  Class IntegralConstant
#include "../../../CommonFunctionality/DetectObjectsMembers/OperatorDetector/OperatorDetector.hpp"  //  Class OperatorDetector_RoundBrackets
#include "../../Pointers/TypeCheck_FunctionPointer/TypeCheck_FunctionPointer.hpp"  //  Class TypeCheck_FunctionPointer
#include "../../Pointers/TypeCheck_MethodPointer/TypeCheck_MethodPointer.hpp"  //  Class TypeCheck_MethodPointer


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
	//		Use this object to provide a type check. In general If the given type can be called or invoked, this object will contain a boolean value 
	//		of true, and otherwise false. This is the main template it will conatin false for all non reference types.
    //
    //      A callable element can be either :
    //
    //          1. Function pointer
    //          2. Member function pointer
    //          3. An object of a functor class ( a class that overload the operator() )
    //          4. Anonymous functions ( lambdas )
    //
    //      Therefore a template specialization will be created for each type
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
	class TypeCheck_Callable NotForInheritance : public IntegralConstant< Boolean, TypeCheck_FunctionPointer< Type >::Value() || TypeCheck_MethodPointer< Type >::Value() >
	{
	public:


        // The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler
        // generates a basic behavior for them :


        // Method Information :
        //
        //  Description :
        //
        //      Default Constructor,
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline TypeCheck_Callable() {}  //  Empty method


        // Method Information :
        //
        //  Description :
        //
        //      Destructor, does not throw
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline ~TypeCheck_Callable() = default;


	private:


        // Disable all copy and move related methods
        DisableCopyAndMove_MACRO( TypeCheck_Callable )


	};  //  Class TypeCheck_Callable







}  //  Namespace Universe



#endif  // TYPECHECK_CALLABLE_HPP