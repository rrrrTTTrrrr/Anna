#ifndef CHOOSEBETWEENTWOTYPES_HPP
#define CHOOSEBETWEENTWOTYPES_HPP


#include "../../../CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  // Macro DEBUG_TOOL, Macro COMMA
#include "../../CommonFunctionality/IntegralConstant/IntegralConstant.hpp"  //  Class IntegralConstant


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
	//		Use this object to choose between the two provided template types according to the result of the expression. If the result is true
	//		then a type definition of the first template type will be created, and if false then for the second. This is the general case, and it
	//		will be used for the case where the exression is true, and will contain a type definition for the first template type
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
	template< Boolean ExpressionResult, typename FirstType, typename SecondType >
	class ChooseBetweenTwoTypes NotForInheritance
	{
    public:


        // Create a type definition of the first template type
        using Type = FirstType;


    private :


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( ChooseBetweenTwoTypes )


	};  //  Class ChooseBetweenTwoTypes






































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ***************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Expression Result = false   *********************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //







































	// Template Class Information :
	//
	//  Purpose :
	//
	//		Use this object to choose between the two provided template types according to the result of the expression. If the result is true
	//		then a type definition of the first template type will be created, and if false then for the second. This is a template specialization
	//		for epression result of false, and it will contain a type definition for the second template type
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
	template< typename FirstType, typename SecondType >
	class ChooseBetweenTwoTypes< false, FirstType, SecondType > NotForInheritance
	{
    public:


        // Create a type definition of the second template type
        using Type = SecondType;


    private :


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( ChooseBetweenTwoTypes )


	};  //  Class ChooseBetweenTwoTypes









}  //  Namespace Universe



#endif  // CHOOSEBETWEENTWOTYPES_HPP