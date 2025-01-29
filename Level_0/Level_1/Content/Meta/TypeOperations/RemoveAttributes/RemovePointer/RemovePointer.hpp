namespace Universe
{



// Template Class Information :
//
//  Purpose :
//
//      Use this object to take a pointer type, and remove the pointer qualifier. This means :
//
//          Type*     ->    Type
//
//      Any const or volatile qualifier will remain : 
//
//          const Type*             ->    const Type*
//          volatile Type*          ->    volatile Type*
//          const volatile Type*    ->    const volatile Type*
//
//      This is the main template, it will accept only non pointer types and will create a type definition to exactly the same type given
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
//      2. Template arguments :
//
//          1. AnyType - any type
//
//  Expectations :
//
//      NONE
//
//  Possible errors :
//
//      Too many to count
//
template< typename AnyType >
class RemovePointer NotForInheritance
{
public:


    // This type definition will be for the same type exactly as the template type
    using Type = AnyType;


private :


    // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
    NoInstances( RemovePointer );


};  //  Class RemovePointer



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ***************************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION   *************************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //



// Use this macro to create a template specialization for the object 'RemovePointer'.
//
// The required arguments are :
//
//      1. InputPointerType - the pointer input type
//      2. OutputTypeWithoutPointerQualifier - the type without the pointer qualifier
//
#define CreateRemovePointerTemplateSpecialization( InputPointerType, OutputTypeWithoutPointerQualifier )                                                                          \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
    template< typename AnyType >                                                                                                                                                        \
    class RemovePointer< InputPointerType >                                                                                                                                             \
    {                                                                                                                                                                                   \
    public:                                                                                                                                                                             \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
        /* Create a type definition of the template type without the reference qualifier */                                                                                             \
        using Type = OutputTypeWithoutPointerQualifier;                                                                                                                                 \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
    private:                                                                                                                                                                            \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
        /* Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator */                     \
        NoInstances( RemovePointer );                                                                                                                                             \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
    }  // Class RemovePointer



// Create all the required template specializations, the possibilites are :
//
//      AnyType*                    -> AnyType
//      const AnyType*              -> AnyType
//      volatile AnyType*           -> AnyType
//      const volatile AnyType*     -> AnyType
//
//      AnyType* const              -> const AnyType
//      AnyType* volatile           -> volatile AnyType
//      AnyType* const volatile     -> const volatile AnyType
//
CreateRemovePointerTemplateSpecialization( AnyType*, AnyType );

CreateRemovePointerTemplateSpecialization( const AnyType*, AnyType );
CreateRemovePointerTemplateSpecialization( volatile AnyType*, AnyType );
CreateRemovePointerTemplateSpecialization( const volatile AnyType*, AnyType );

CreateRemovePointerTemplateSpecialization( AnyType* const, const AnyType );
CreateRemovePointerTemplateSpecialization( AnyType* volatile, volatile AnyType );
CreateRemovePointerTemplateSpecialization( AnyType* const volatile, const volatile AnyType );

CreateRemovePointerTemplateSpecialization( const AnyType* const, const AnyType );
CreateRemovePointerTemplateSpecialization( const AnyType* volatile, volatile AnyType );
CreateRemovePointerTemplateSpecialization( const AnyType* const volatile, const volatile AnyType );

CreateRemovePointerTemplateSpecialization( volatile AnyType* const, const AnyType );
CreateRemovePointerTemplateSpecialization( volatile AnyType* volatile, volatile AnyType );
CreateRemovePointerTemplateSpecialization( volatile AnyType* const volatile, const volatile AnyType );

CreateRemovePointerTemplateSpecialization( const volatile AnyType* const, const AnyType );
CreateRemovePointerTemplateSpecialization( const volatile AnyType* volatile, volatile AnyType );
CreateRemovePointerTemplateSpecialization( const volatile AnyType* const volatile, const volatile AnyType );



}  //  Namespace Universe