#ifndef  TYPECHECK_SHALLOWCOPY_HPP
#define  TYPECHECK_SHALLOWCOPY_HPP


#include "../../../../../CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  // Macro DEBUG_TOOL, Macro COMMA, Typedef Boolean, Typedef UnsignedInteger8bits, Typedef UnsignedInteger16bits, Typedef UnsignedInteger32bits, Typedef UnsignedInteger64bits, Typedef SignedInteger8bits, Typedef SignedInteger16bits, Typedef SignedInteger32bits, Typedef SignedInteger64bits
#include "../../../../CommonFunctionality/IntegralConstant/IntegralConstant.hpp"  //  Class IntegralConstant


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
	//		Use this object to provide a type check. In general If the given type can be shallow copied, which means it does not need a copy
    //      constructor to be copied, but the bits can be simply copied, this object will contain a boolean value of true, and otherwise false. 
    //      This is the main template it will conatin false for all types, and each type that can be shallow copied needs to have a template
    //      specialization of its own, which will contain true
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
	class TypeCheck_ShallowCopy : public IntegralConstant< Boolean, false >
	{
	private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( TypeCheck_ShallowCopy )


	};  //  Class TypeCheck_ShallowCopy































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ******************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = char / SignedInteger8bits   *************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. This is a template specialization for the type 'char', to return true when this type is checked
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
    class TypeCheck_ShallowCopy< char > : public IntegralConstant< Boolean, true >
    {
    private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( TypeCheck_ShallowCopy )


    };  //  Class TypeCheck_ShallowCopy


































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ********************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = Boolean   ***************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //



































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. This is a template specialization for the type 'Boolean', to return true when this type is checked
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
    class TypeCheck_ShallowCopy< Boolean > : public IntegralConstant< Boolean, true >
    {
    private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( TypeCheck_ShallowCopy )


    };  //  Class TypeCheck_ShallowCopy



































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// **************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = UnsignedInteger8bits   ********************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //



































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. This is a template specialization for the type 'UnsignedInteger8bits', to return true when this type is checked
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
    class TypeCheck_ShallowCopy< UnsignedInteger8bits > : public IntegralConstant< Boolean, true >
    {
    private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( TypeCheck_ShallowCopy )


    };  //  Class TypeCheck_ShallowCopy



































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// **************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = UnsignedInteger16bits   ********************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. This is a template specialization for the type 'UnsignedInteger16bits', to return true when this type is checked
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
    class TypeCheck_ShallowCopy< UnsignedInteger16bits > : public IntegralConstant< Boolean, true >
    {
    private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( TypeCheck_ShallowCopy )


    };  //  Class TypeCheck_ShallowCopy


































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// **************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = UnsignedInteger32bits   ********************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. This is a template specialization for the type 'UnsignedInteger32bits', to return true when this type is checked
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
    class TypeCheck_ShallowCopy< UnsignedInteger32bits > : public IntegralConstant< Boolean, true >
    {
    private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( TypeCheck_ShallowCopy )


    };  //  Class TypeCheck_ShallowCopy


































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// **************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = UnsignedInteger64bits   ********************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. This is a template specialization for the type 'UnsignedInteger64bits', to return true when this type is checked
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
    class TypeCheck_ShallowCopy< UnsignedInteger64bits > : public IntegralConstant< Boolean, true >
    {
    private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( TypeCheck_ShallowCopy )


    };  //  Class TypeCheck_ShallowCopy

































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// **************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = SignedInteger16bits   ********************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. This is a template specialization for the type 'SignedInteger16bits', to return true when this type is checked
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
    class TypeCheck_ShallowCopy< SignedInteger16bits > : public IntegralConstant< Boolean, true >
    {
    private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( TypeCheck_ShallowCopy )


    };  //  Class TypeCheck_ShallowCopy


































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// **************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = SignedInteger32bits   ********************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. This is a template specialization for the type 'SignedInteger32bits', to return true when this type is checked
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
    class TypeCheck_ShallowCopy< SignedInteger32bits > : public IntegralConstant< Boolean, true >
    {
    private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( TypeCheck_ShallowCopy )


    };  //  Class TypeCheck_ShallowCopy


































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ********************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = Pointer   ***************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. This is a template specialization for pointers, to return true when this type is checked
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
    template< typename Type >
    class TypeCheck_ShallowCopy< Type* > : public IntegralConstant< Boolean, true >
    {
    private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( TypeCheck_ShallowCopy )


    };  //  Class TypeCheck_ShallowCopy
































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ***************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = const char / SignedInteger8bits   ************************************ //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. This is a template specialization for the type 'char', to return true when this type is checked
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
    class TypeCheck_ShallowCopy< const char > : public IntegralConstant< Boolean, true >
    {
    private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( TypeCheck_ShallowCopy )


    };  //  Class TypeCheck_ShallowCopy


































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = const Boolean   ************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //



































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. This is a template specialization for the type 'Boolean', to return true when this type is checked
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
    class TypeCheck_ShallowCopy< const Boolean > : public IntegralConstant< Boolean, true >
    {
    private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( TypeCheck_ShallowCopy )


    };  //  Class TypeCheck_ShallowCopy



































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ***********************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = const UnsignedInteger8bits   ******************************************* //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //



































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. This is a template specialization for the type 'UnsignedInteger8bits', to return true when this type is checked
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
    class TypeCheck_ShallowCopy< const UnsignedInteger8bits > : public IntegralConstant< Boolean, true >
    {
    private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( TypeCheck_ShallowCopy )


    };  //  Class TypeCheck_ShallowCopy



































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ***********************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = const UnsignedInteger16bits   ****************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. This is a template specialization for the type 'UnsignedInteger16bits', to return true when this type is checked
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
    class TypeCheck_ShallowCopy< const UnsignedInteger16bits > : public IntegralConstant< Boolean, true >
    {
    private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( TypeCheck_ShallowCopy )


    };  //  Class TypeCheck_ShallowCopy


































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// **********************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = const UnsignedInteger32bits   ******************************************* //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. This is a template specialization for the type 'UnsignedInteger32bits', to return true when this type is checked
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
    class TypeCheck_ShallowCopy< const UnsignedInteger32bits > : public IntegralConstant< Boolean, true >
    {
    private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( TypeCheck_ShallowCopy )


    };  //  Class TypeCheck_ShallowCopy


































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ***********************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = const UnsignedInteger64bits   ****************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. This is a template specialization for the type 'UnsignedInteger64bits', to return true when this type is checked
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
    class TypeCheck_ShallowCopy< const UnsignedInteger64bits > : public IntegralConstant< Boolean, true >
    {
    private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( TypeCheck_ShallowCopy )


    };  //  Class TypeCheck_ShallowCopy

































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = const SignedInteger16bits   ****************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. This is a template specialization for the type 'SignedInteger16bits', to return true when this type is checked
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
    class TypeCheck_ShallowCopy< const SignedInteger16bits > : public IntegralConstant< Boolean, true >
    {
    private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( TypeCheck_ShallowCopy )


    };  //  Class TypeCheck_ShallowCopy


































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = const SignedInteger32bits   ******************************************* //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. This is a template specialization for the type 'SignedInteger32bits', to return true when this type is checked
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
    class TypeCheck_ShallowCopy< const SignedInteger32bits > : public IntegralConstant< Boolean, true >
    {
    private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( TypeCheck_ShallowCopy )


    };  //  Class TypeCheck_ShallowCopy


































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = const SignedInteger64bits   ******************************************* //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. This is a template specialization for the type 'SignedInteger64bits', to return true when this type is checked
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
    class TypeCheck_ShallowCopy< const SignedInteger64bits > : public IntegralConstant< Boolean, true >
    {
    private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( TypeCheck_ShallowCopy )


    };  //  Class TypeCheck_ShallowCopy





































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = constant Pointer   ************************************************ //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. This is a template specialization for constant pointers, to return true when this type is 
    //      checked
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
    template< typename Type >
    class TypeCheck_ShallowCopy< Type* const > : public IntegralConstant< Boolean, true >
    {
    private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( TypeCheck_ShallowCopy )


    };  //  Class TypeCheck_ShallowCopy
































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// **********************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = Pointer to constant object   ******************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. This is a template specialization for pointers that point to constant objects, to return true when
    //      this type is checked
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
    template< typename Type >
    class TypeCheck_ShallowCopy< const Type* > : public IntegralConstant< Boolean, true >
    {
    private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( TypeCheck_ShallowCopy )


    };  //  Class TypeCheck_ShallowCopy
































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ******************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type = constant Pointer to constant object   *************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. This is a template specialization for constant pointers that point to constant objects, to return 
    //      true when this type is checked
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
    template< typename Type >
    class TypeCheck_ShallowCopy< const Type* const > : public IntegralConstant< Boolean, true >
    {
    private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( TypeCheck_ShallowCopy )


    };  //  Class TypeCheck_ShallowCopy














}  //  Namespace Universe



#endif  // TYPECHECK_SHALLOWCOPY_HPP