#ifndef ASSERTALLTRUE_HPP
#define ASSERTALLTRUE_HPP


#include "../../../CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA, Macro CompileTimeAssert
#include "../IntegralConstant/IntegralConstant.hpp"  //  Class IntegralConstant
#include "../../Types/ChooseBetweenTwoTypes/ChooseBetweenTwoTypes.hpp"  //  Class ChooseBetweenTwoTypes


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
	//		The problem this object comes to help solving is how to check a condition on all types of a parameter pack. For example :
	//
	//			template< typename... Types >
	//			class Mother
	//			{};
	//		
	//		Then class 'Mother' can only work with types that are not constant for example, and for constant types it has a template specialization.
	//		The question then how to check if one of the types in the parameter pack is constant and choose the correct implementation of the object.
	//		This object receives a parameter pack of booleans, and recursively passes on each one of them and check if all of them are true. It
	//		will continue passing until the end only if all booleans are true, otherwise it will stop on the first boolean that has the value
	//		false, it basically acts as 'AND' between the booleans. This is the general template, it will be choosen when all booleans are true 
    //      and will contain the value true
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
    //          1. Booleans - a parameter pack of booleans
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	template< Boolean... Booleans >
	class AssertAllTrue : public IntegralConstant< Boolean, true >
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
        inline AssertAllTrue() {}  //  Empty method


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
        inline ~AssertAllTrue() = default;


	private:


        // Disable all copy and move related methods
        DisableCopyAndMove_MACRO( AssertAllTrue )


	};  //  Class AssertAllTrue






































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ****************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - For case even one condition does not apply   ***************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //








































	// Template Class Information :
	//
	//  Purpose :
	//
    //      The problem this object comes to help solving is how to check a condition on all types of a parameter pack. For example :
    //
    //          template< typename... Types >
    //          class Mother
    //          {};
    //      
    //      Then class 'Mother' can only work with types that are not constant for example, and for constant types it has a template specialization.
    //      The question then how to check if one of the types in the parameter pack is constant and choose the correct implementation of the object.
    //      This object receives a parameter pack of booleans, and recursively passes on each one of them and check if all of them are true. It
    //      will continue passing until the end only if all booleans are true, otherwise it will stop on the first boolean that has the value
    //      false, it basically acts as 'AND' between the booleans. This is the a template specialization, it will be choosen when even one 
    //      boolean has the value false and will contain the value false
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
    //          1. Conditions - a parameter pack of object that check some condition on a type
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	template< Boolean ExposedBoolean, Boolean... Booleans >
	class AssertAllTrue< ExposedBoolean, Booleans... > : public ChooseBetweenTwoTypes< ExposedBoolean, AssertAllTrue< Booleans... >, IntegralConstant< Boolean, false > >::Type
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
        inline AssertAllTrue() {}  //  Empty method


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
        inline ~AssertAllTrue() = default;


	private:


        // Disable all copy and move related methods
        DisableCopyAndMove_MACRO( AssertAllTrue )


	};  //  Class AssertAllTrue












}  //  Namespace Universe



#endif  // ASSERTALLTRUE_HPP