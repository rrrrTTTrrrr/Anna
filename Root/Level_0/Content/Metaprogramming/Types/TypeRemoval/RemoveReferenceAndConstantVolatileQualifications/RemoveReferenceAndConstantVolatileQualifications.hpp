#ifndef  REMOVEREFERENCEANDCONSTANTVOLATILEQUALIFICATIONS_HPP
#define  REMOVEREFERENCEANDCONSTANTVOLATILEQUALIFICATIONS_HPP


#include "../../../../CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  // Macro DEBUG_TOOL, Macro COMMA


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe
{



	// This is used when only declaring the object in this source file will be enough to pass compilation. The implementation is given to the compiler through the
	// cpp source file that the object is nested within
	//
	// Forward declarations :
	//
	//  NONE
	//



    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to take a reference type, can be to lvalue or rvalue, with constant and volatile qualifications, and remove them. This means :
    //
    //          Type&                       ->    Type
    //          const Type&                 ->    Type
    //          volatile Type&              ->    Type
    //          const volatile Type&&       ->    Type
    //          Type&&                      ->    Type
    //          const Type&&                ->    Type
    //          volatile Type&&             ->    Type
    //          const volatile Type&&       ->    Type
    //
    //          Any other Type              ->    Stays the same
    //
    //      This is the main template, it will accept only non reference types and will create a type definition to exactly the same type given
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
    template< typename TYPE >
    class RemoveReferenceAndConstantVolatileQualifications NotForInheritance
    {
    public:


        // This type definition will be for the same type exactly as the template type
        using Type = TYPE;


    private :


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( RemoveReferenceAndConstantVolatileQualifications )


    };  //  Class RemoveReferenceAndConstantVolatileQualifications
































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - For lvalue references   ************************************************* //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to take a reference type, can be to lvalue or rvalue, with constant and volatile qualifications, and remove them. This means :
    //
    //          Type&                       ->    Type
    //          const Type&                 ->    Type
    //          volatile Type&              ->    Type
    //          const volatile Type&&       ->    Type
    //          Type&&                      ->    Type
    //          const Type&&                ->    Type
    //          volatile Type&&             ->    Type
    //          const volatile Type&&       ->    Type
    //
    //          Any other Type              ->    Stays the same
    //
    //      This template specialization will accept lvalue references 'Type&' and create a type definition to the type itself without the reference
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
    template< typename TYPE >
    class RemoveReferenceAndConstantVolatileQualifications< TYPE& > NotForInheritance
    {
    public:


        // This type definition will be for the same type exactly as the template type
        using Type = TYPE;


    private :


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( RemoveReferenceAndConstantVolatileQualifications )


    };  //  Class RemoveReferenceAndConstantVolatileQualifications
































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ******************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - For constant non volatile lvalue references   ************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to take a reference type, can be to lvalue or rvalue, with constant and volatile qualifications, and remove them. This means :
    //
    //          Type&                       ->    Type
    //          const Type&                 ->    Type
    //          volatile Type&              ->    Type
    //          const volatile Type&&       ->    Type
    //          Type&&                      ->    Type
    //          const Type&&                ->    Type
    //          volatile Type&&             ->    Type
    //          const volatile Type&&       ->    Type
    //
    //          Any other Type              ->    Stays the same
    //
    //      This template specialization will accept constant non volatile lvalue references 'const Type&' and create a type definition to the type itself 
    //      without the reference
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
    template< typename TYPE >
    class RemoveReferenceAndConstantVolatileQualifications< const TYPE& > NotForInheritance
    {
    public:


        // This type definition will be for the same type exactly as the template type
        using Type = TYPE;


    private :


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( RemoveReferenceAndConstantVolatileQualifications )


    };  //  Class RemoveReferenceAndConstantVolatileQualifications







































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ******************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - For volatile non constant lvalue references   ************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to take a reference type, can be to lvalue or rvalue, with constant and volatile qualifications, and remove them. This means :
    //
    //          Type&                       ->    Type
    //          const Type&                 ->    Type
    //          volatile Type&              ->    Type
    //          const volatile Type&&       ->    Type
    //          Type&&                      ->    Type
    //          const Type&&                ->    Type
    //          volatile Type&&             ->    Type
    //          const volatile Type&&       ->    Type
    //
    //          Any other Type              ->    Stays the same
    //
    //      This template specialization will accept volatile non constant lvalue references 'volatile Type&' and create a type definition to the type itself 
    //      without the reference
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
    template< typename TYPE >
    class RemoveReferenceAndConstantVolatileQualifications< volatile TYPE& > NotForInheritance
    {
    public:


        // This type definition will be for the same type exactly as the template type
        using Type = TYPE;


    private :


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( RemoveReferenceAndConstantVolatileQualifications )


    };  //  Class RemoveReferenceAndConstantVolatileQualifications








































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ******************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - For volatile and constant lvalue references   ************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to take a reference type, can be to lvalue or rvalue, with constant and volatile qualifications, and remove them. This means :
    //
    //          Type&                       ->    Type
    //          const Type&                 ->    Type
    //          volatile Type&              ->    Type
    //          const volatile Type&&       ->    Type
    //          Type&&                      ->    Type
    //          const Type&&                ->    Type
    //          volatile Type&&             ->    Type
    //          const volatile Type&&       ->    Type
    //
    //          Any other Type              ->    Stays the same
    //
    //      This template specialization will accept volatile and constant lvalue references 'const volatile Type&' and create a type definition to the type itself 
    //      without the reference
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
    template< typename TYPE >
    class RemoveReferenceAndConstantVolatileQualifications< const volatile TYPE& > NotForInheritance
    {
    public:


        // This type definition will be for the same type exactly as the template type
        using Type = TYPE;


    private :


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( RemoveReferenceAndConstantVolatileQualifications )


    };  //  Class RemoveReferenceAndConstantVolatileQualifications




































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - For rvalue references   ************************************************* //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to take a reference type, can be to rvalue or rvalue, with constant and volatile qualifications, and remove them. This means :
    //
    //          Type&                       ->    Type
    //          const Type&                 ->    Type
    //          volatile Type&              ->    Type
    //          const volatile Type&&       ->    Type
    //          Type&&                      ->    Type
    //          const Type&&                ->    Type
    //          volatile Type&&             ->    Type
    //          const volatile Type&&       ->    Type
    //
    //          Any other Type              ->    Stays the same
    //
    //      This template specialization will accept rvalue references 'Type&&' and create a type definition to the type itself without the reference
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
    template< typename TYPE >
    class RemoveReferenceAndConstantVolatileQualifications< TYPE&& > NotForInheritance
    {
    public:


        // This type definition will be for the same type exactly as the template type
        using Type = TYPE;


    private :


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( RemoveReferenceAndConstantVolatileQualifications )


    };  //  Class RemoveReferenceAndConstantVolatileQualifications
































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ******************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - For constant non volatile rvalue references   ************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to take a reference type, can be to rvalue or rvalue, with constant and volatile qualifications, and remove them. This means :
    //
    //          Type&                       ->    Type
    //          const Type&                 ->    Type
    //          volatile Type&              ->    Type
    //          const volatile Type&&       ->    Type
    //          Type&&                      ->    Type
    //          const Type&&                ->    Type
    //          volatile Type&&             ->    Type
    //          const volatile Type&&       ->    Type
    //
    //          Any other Type              ->    Stays the same
    //
    //      This template specialization will accept constant non volatile rvalue references 'const Type&&' and create a type definition to the type itself 
    //      without the reference
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
    template< typename TYPE >
    class RemoveReferenceAndConstantVolatileQualifications< const TYPE&& > NotForInheritance
    {
    public:


        // This type definition will be for the same type exactly as the template type
        using Type = TYPE;


    private :


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( RemoveReferenceAndConstantVolatileQualifications )


    };  //  Class RemoveReferenceAndConstantVolatileQualifications







































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ******************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - For volatile non constant rvalue references   ************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to take a reference type, can be to rvalue or rvalue, with constant and volatile qualifications, and remove them. This means :
    //
    //          Type&                       ->    Type
    //          const Type&                 ->    Type
    //          volatile Type&              ->    Type
    //          const volatile Type&&       ->    Type
    //          Type&&                      ->    Type
    //          const Type&&                ->    Type
    //          volatile Type&&             ->    Type
    //          const volatile Type&&       ->    Type
    //
    //          Any other Type              ->    Stays the same
    //
    //      This template specialization will accept volatile non constant rvalue references 'volatile Type&&' and create a type definition to the type itself 
    //      without the reference
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
    template< typename TYPE >
    class RemoveReferenceAndConstantVolatileQualifications< volatile TYPE&& > NotForInheritance
    {
    public:


        // This type definition will be for the same type exactly as the template type
        using Type = TYPE;


    private :


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( RemoveReferenceAndConstantVolatileQualifications )


    };  //  Class RemoveReferenceAndConstantVolatileQualifications








































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ******************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - For volatile and constant rvalue references   ************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //


































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to take a reference type, can be to rvalue or rvalue, with constant and volatile qualifications, and remove them. This means :
    //
    //          Type&                       ->    Type
    //          const Type&                 ->    Type
    //          volatile Type&              ->    Type
    //          const volatile Type&&       ->    Type
    //          Type&&                      ->    Type
    //          const Type&&                ->    Type
    //          volatile Type&&             ->    Type
    //          const volatile Type&&       ->    Type
    //
    //          Any other Type              ->    Stays the same
    //
    //      This template specialization will accept volatile and constant rvalue references 'const volatile Type&&' and create a type definition to the type itself 
    //      without the reference
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
    template< typename TYPE >
    class RemoveReferenceAndConstantVolatileQualifications< const volatile TYPE&& > NotForInheritance
    {
    public:


        // This type definition will be for the same type exactly as the template type
        using Type = TYPE;


    private :


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( RemoveReferenceAndConstantVolatileQualifications )


    };  //  Class RemoveReferenceAndConstantVolatileQualifications












}  //  Namespace Universe



#endif  // REMOVEREFERENCEANDCONSTANTVOLATILEQUALIFICATIONS_HPP