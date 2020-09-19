#ifndef TYPECHECK_UNSIGNEDTOSIGNED_HPP
#define TYPECHECK_UNSIGNEDTOSIGNED_HPP


#include "../../../../CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  // Macro DEBUG_TOOL, Macro COMMA
#include "../../../Types/TypeCheck/Integers/TypeCheck_UnsignedInteger/TypeCheck_UnsignedInteger.hpp"  //  Class TypeCheck_UnsignedInteger


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
    //      Use this object to provide to take an integer unsigned type, and create a type definition of the same size just signed. This is the main
    //      template, it will just create a type definition within for every signed integer type provided, because it is already sigend. A 
    //      template specialization will be created for each unsigned integer type to convert to the corresponding sgined type with the same size
    //      
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
    //          1. UnsignedIntegerType - any unsigned integer type
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      Too many to count
    //
    template< typename UnsignedIntegerType >
    class UnsignedToSigned
    {
    public:


        // Type definition for the signed integer type provided
        using Type = UnsignedIntegerType;


    private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( UnsignedToSigned )


        // Assert all the requirements on the template arguments provided to the object. To perform a compile time assert the C++ language provides
        // the keyword 'static_assert', which receives an expression and an error message to display if the expression result is false. The important
        // thing is that the expression is evaluted during compile time, and therefore if the expression is false the compilation will be terminated
        // and the error message will be displayed. This method should not be used, because it does nothing during run time
        CompileTimeAssert( ( TypeCheck_UnsignedInteger< UnsignedIntegerType >::Result() == true ), "UnsignedToSigned - The given type should be an unsigned integer" );


    };  //  Class UnsignedToSigned



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ***************************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION   *************************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //



    // Use this macro to create a template specialization for the object 'UnsignedToSigned'.
    //
    // The required arguments are :
    //
    //      1. InputUnsignedType - the unsigned input type
    //      2. OutputSignedType - the output signed counterpart type of the unsigned input type 
    //
    #define CreateUnsignedToSignedTemplateSpecialization_Macro( InputUnsignedType, OutputSignedType )                                                                                       \
                                                                                                                                                                                            \
                                                                                                                                                                                            \
        template<>                                                                                                                                                                          \
        class UnsignedToSigned< InputUnsignedType >                                                                                                                                         \
        {                                                                                                                                                                                   \
        public:                                                                                                                                                                             \
                                                                                                                                                                                            \
                                                                                                                                                                                            \
            /* Type definition for the signed counterpart type of the unsigned input type */                                                                                                \
            using Type = OutputSignedType;                                                                                                                                                  \
                                                                                                                                                                                            \
                                                                                                                                                                                            \
        private:                                                                                                                                                                            \
                                                                                                                                                                                            \
                                                                                                                                                                                            \
            /* Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator */                     \
            NoInstances_MACRO( UnsignedToSigned )                                                                                                                                           \
                                                                                                                                                                                            \
                                                                                                                                                                                            \
        };  // Class UnsignedToSigned



    // Create all the required template specializations, the type are :
    //
    //      UnsignedInteger8bits      -> SignedInteger8bits
    //      UnsignedInteger16bits     -> SignedInteger16bits
    //      UnsignedInteger32bits     -> SignedInteger32bits
    //      UnsignedInteger64bits     -> SignedInteger64bits
    //
    // All the types returned will match the cv qualifiers of the type. For example :
    //
    //      const UnsignedInteger8bits            -> const SignedInteger64bits
    //      volatile UnsignedInteger8bits         -> volatile SignedInteger64bits
    //      const volatile UnsignedInteger8bits   -> const volatile SignedInteger64bits
    //
    CreateUnsignedToSignedTemplateSpecialization_Macro( UnsignedInteger8bits, SignedInteger8bits )
    CreateUnsignedToSignedTemplateSpecialization_Macro( UnsignedInteger16bits, SignedInteger16bits )
    CreateUnsignedToSignedTemplateSpecialization_Macro( UnsignedInteger32bits, SignedInteger32bits )
    CreateUnsignedToSignedTemplateSpecialization_Macro( UnsignedInteger64bits, SignedInteger64bits )

    CreateUnsignedToSignedTemplateSpecialization_Macro( const UnsignedInteger8bits, const SignedInteger8bits )
    CreateUnsignedToSignedTemplateSpecialization_Macro( const UnsignedInteger16bits, const SignedInteger16bits )
    CreateUnsignedToSignedTemplateSpecialization_Macro( const UnsignedInteger32bits, const SignedInteger32bits )
    CreateUnsignedToSignedTemplateSpecialization_Macro( const UnsignedInteger64bits, const SignedInteger64bits )

    CreateUnsignedToSignedTemplateSpecialization_Macro( volatile UnsignedInteger8bits, volatile SignedInteger8bits )
    CreateUnsignedToSignedTemplateSpecialization_Macro( volatile UnsignedInteger16bits, volatile SignedInteger16bits )
    CreateUnsignedToSignedTemplateSpecialization_Macro( volatile UnsignedInteger32bits, volatile SignedInteger32bits )
    CreateUnsignedToSignedTemplateSpecialization_Macro( volatile UnsignedInteger64bits, volatile SignedInteger64bits )

    CreateUnsignedToSignedTemplateSpecialization_Macro( const volatile UnsignedInteger8bits, const volatile SignedInteger8bits )
    CreateUnsignedToSignedTemplateSpecialization_Macro( const volatile UnsignedInteger16bits, const volatile SignedInteger16bits )
    CreateUnsignedToSignedTemplateSpecialization_Macro( const volatile UnsignedInteger32bits, const volatile SignedInteger32bits )
    CreateUnsignedToSignedTemplateSpecialization_Macro( const volatile UnsignedInteger64bits, const volatile SignedInteger64bits )


}  //  Namespace Universe



#endif  // TYPECHECK_UNSIGNEDTOSIGNED_HPP