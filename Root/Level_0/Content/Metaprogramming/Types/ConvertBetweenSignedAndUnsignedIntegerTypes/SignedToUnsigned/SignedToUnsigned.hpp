#ifndef TYPECHECK_SIGNEDTOUNSIGNED_HPP
#define TYPECHECK_SIGNEDTOUNSIGNED_HPP


#include "../../../../CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  // Macro DEBUG_TOOL, Macro COMMA
#include "../../../Types/TypeCheck/Integers/TypeCheck_SignedInteger/TypeCheck_SignedInteger.hpp"  //  Class TypeCheck_SignedInteger


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
    //      Use this object to provide to take an integer signed type, and create a type definition of the same size just unsigned. This is the main
    //      template, it will just create a type definition within for every unsigned integer type provided, because it is already unsigend. A 
    //      template specialization will be created for each signed integer type to convert to the corresponding unsgined type with the same size
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
    //          1. SignedIntegerType - any signed integer type
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      Too many to count
    //
    template< typename SignedIntegerType >
    class SignedToUnsigned
    {
    private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( SignedToUnsigned )


        // Assert all the requirements on the template arguments provided to the object. To perform a compile time assert the C++ language provides
        // the keyword 'static_assert', which receives an expression and an error message to display if the expression result is false. The important
        // thing is that the expression is evaluted during compile time, and therefore if the expression is false the compilation will be terminated
        // and the error message will be displayed. This method should not be used, because it does nothing during run time
        CompileTimeAssert( ( TypeCheck_SignedInteger< SignedIntegerType >::Result() == true ), "SignedToUnsigned - The given type should be a signed integer" );


    };  //  Class SignedToUnsigned



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ***************************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION   *************************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //



    // Use this macro to create a template specialization for the object 'SignedToUnsigned'.
    //
    // The required arguments are :
    //
    //      1. InputSignedType - the signed input type
    //      2. OutputUnsignedType - the output unsigned counterpart type of the signed input type 
    //
    #define CreateSignedToUnsignedTemplateSpecialization_Macro( InputSignedType, OutputUnsignedType )                                                                                       \
                                                                                                                                                                                            \
                                                                                                                                                                                            \
        template<>                                                                                                                                                                          \
        class SignedToUnsigned< InputSignedType >                                                                                                                                           \
        {                                                                                                                                                                                   \
        public:                                                                                                                                                                             \
                                                                                                                                                                                            \
                                                                                                                                                                                            \
            /* Type definition for the unsigned counterpart type of the signed input type */                                                                                                \
            using Type = OutputUnsignedType;                                                                                                                                                \
                                                                                                                                                                                            \
                                                                                                                                                                                            \
        private:                                                                                                                                                                            \
                                                                                                                                                                                            \
                                                                                                                                                                                            \
            /* Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator */                     \
            NoInstances_MACRO( SignedToUnsigned )                                                                                                                                           \
                                                                                                                                                                                            \
                                                                                                                                                                                            \
        };  // Class SignedToUnsigned



    // Create all the required template specializations, the type are :
    //
    //      SignedInteger8bits      -> UnsignedInteger8bits
    //      SignedInteger16bits     -> UnsignedInteger16bits
    //      SignedInteger32bits     -> UnsignedInteger32bits
    //      SignedInteger64bits     -> UnsignedInteger64bits
    //
    // All the types returned will match the cv qualifiers of the type. For example :
    //
    //      const SignedInteger8bits            -> const UnsignedInteger64bits
    //      volatile SignedInteger8bits         -> volatile UnsignedInteger64bits
    //      const volatile SignedInteger8bits   -> const volatile UnsignedInteger64bits
    //
    CreateSignedToUnsignedTemplateSpecialization_Macro( SignedInteger8bits, UnsignedInteger8bits )
    CreateSignedToUnsignedTemplateSpecialization_Macro( SignedInteger16bits, UnsignedInteger16bits )
    CreateSignedToUnsignedTemplateSpecialization_Macro( SignedInteger32bits, UnsignedInteger32bits )
    CreateSignedToUnsignedTemplateSpecialization_Macro( SignedInteger64bits, UnsignedInteger64bits )

    CreateSignedToUnsignedTemplateSpecialization_Macro( const SignedInteger8bits, const UnsignedInteger8bits )
    CreateSignedToUnsignedTemplateSpecialization_Macro( const SignedInteger16bits, const UnsignedInteger16bits )
    CreateSignedToUnsignedTemplateSpecialization_Macro( const SignedInteger32bits, const UnsignedInteger32bits )
    CreateSignedToUnsignedTemplateSpecialization_Macro( const SignedInteger64bits, const UnsignedInteger64bits )

    CreateSignedToUnsignedTemplateSpecialization_Macro( volatile SignedInteger8bits, volatile UnsignedInteger8bits )
    CreateSignedToUnsignedTemplateSpecialization_Macro( volatile SignedInteger16bits, volatile UnsignedInteger16bits )
    CreateSignedToUnsignedTemplateSpecialization_Macro( volatile SignedInteger32bits, volatile UnsignedInteger32bits )
    CreateSignedToUnsignedTemplateSpecialization_Macro( volatile SignedInteger64bits, volatile UnsignedInteger64bits )

    CreateSignedToUnsignedTemplateSpecialization_Macro( const volatile SignedInteger8bits, const volatile UnsignedInteger8bits )
    CreateSignedToUnsignedTemplateSpecialization_Macro( const volatile SignedInteger16bits, const volatile UnsignedInteger16bits )
    CreateSignedToUnsignedTemplateSpecialization_Macro( const volatile SignedInteger32bits, const volatile UnsignedInteger32bits )
    CreateSignedToUnsignedTemplateSpecialization_Macro( const volatile SignedInteger64bits, const volatile UnsignedInteger64bits )



}  //  Namespace Universe



#endif  // TYPECHECK_SIGNEDTOUNSIGNED_HPP