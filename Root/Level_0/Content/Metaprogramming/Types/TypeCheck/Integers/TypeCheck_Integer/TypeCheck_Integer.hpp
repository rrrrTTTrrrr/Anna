#ifndef  TYPECHECK_INTEGRAL_HPP
#define  TYPECHECK_INTEGRAL_HPP


#include "../../../../../CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  // Macro DEBUG_TOOL, Macro COMMA
#include "../../../../CommonFunctionality/IntegralConstant/IntegralConstant.hpp"  //  Class IntegralConstant
#include "../TypeCheck_SignedInteger/TypeCheck_SignedInteger.hpp"  //  Class TypeCheck_SignedInteger
#include "../TypeCheck_UnsignedInteger/TypeCheck_UnsignedInteger.hpp"  //  Class TypeCheck_UnsignedInteger


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
    //      Use this object to provide a type check. In general If the given type is primitive integral type, this object will contain a boolean 
    //      value of true, and otherwise false. This is the main template it will check if the types are signed or unsigned integer and will contain
    //      the value of the boolean accordignly. It will have a template specialization for the type 'boolean'
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
    //      NONE
    //
    //  Possible errors :
    //
    //      Too many to count
    //
    template< typename Type >
    class TypeCheck_Integer : public IntegralConstant< Boolean, TypeCheck_SignedInteger< Type >::Result() || TypeCheck_UnsignedInteger< Type >::Result() >
    {
    private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( TypeCheck_Integer )


    };  //  Class TypeCheck_Integer
































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ********************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = Boolean   ***************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //



































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. In general If the given type is primitive integral type, this object will contain a boolean 
    //      value of true, and otherwise false. This is a template specialization for the type boolean, to return true when this type is checked
    //
    //  Description :
    //
    //      1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by providing 3 keywords :
    //
    //              1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the obejct using the tools
    //                          presented here. This part will usually contain only methods and not data members. If a data member is public all the encapsulation is
    //                          lost, so it should be avoided in most cases
    //
    //              2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will be able to access
    //                             all the data and methods inside this part. This part will usually containt some methods and few data members
    //
    //              3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object and all the
    //                           methods the developer needed to implement the interface presented in the public part. Every method in this part will end with the
    //                           suffix __Private
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      Too many to count
    //
    template<>
    class TypeCheck_Integer< Boolean > : public IntegralConstant< Boolean, true >
    {
    private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( TypeCheck_Integer )


    };  //  Class TypeCheck_Integer
































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = constant Boolean   ************************************************ //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //



































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. In general If the given type is primitive integral type, this object will contain a boolean 
    //      value of true, and otherwise false. This is a template specialization for the type constant boolean, to return true when this type is checked
    //
    //  Description :
    //
    //      1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by providing 3 keywords :
    //
    //              1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the obejct using the tools
    //                          presented here. This part will usually contain only methods and not data members. If a data member is public all the encapsulation is
    //                          lost, so it should be avoided in most cases
    //
    //              2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will be able to access
    //                             all the data and methods inside this part. This part will usually containt some methods and few data members
    //
    //              3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object and all the
    //                           methods the developer needed to implement the interface presented in the public part. Every method in this part will end with the
    //                           suffix __Private
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      Too many to count
    //
    template<>
    class TypeCheck_Integer< const Boolean > : public IntegralConstant< Boolean, true >
    {
    private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( TypeCheck_Integer )


    };  //  Class TypeCheck_Integer










}  //  Namespace Universe



#endif  // TYPECHECK_INTEGRAL_HPP