namespace Universe
{



// Template Class Information :
//
//  Purpose :
//
//      Use this object to take a type declared with the constant qualifier, and remove the constant qualifier. This means :
//
//          const Type     ->    Type
//          Type* const    ->    Type*
//          Type&          ->    Type&
//
//      Any volatile qualifier will remain : 
//
//          volatile Type          ->    volatile Type
//          const volatile Type    ->    volatile Type
//
//      This is the main template, it will accept only types not decalred with the constant qualifier and will create a type definition to 
//      exactly the same type given. Note - when the constant qualifier is applied on a pointer, there is a constant qualifier that applies
//      to the pointer itself, which means the pointer itself can not be changes, and this is the constant qualifier this object aims to remove.
//      And there is the constant qualifier that applies to the pointed instance by the pointer, which has no effect in this object. The same
//      applies for reference, which are inheritly constant, but can have the constant qualifier towards the instance it references
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
class RemoveConstantQualifier NotForInheritance
{
public:


    // This type definition will be for the same type exactly as the template type
    using Type = AnyType;


private :


    // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
    NoInstances( RemoveConstantQualifier );


};  //  Class RemoveConstantQualifier



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ***************************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION   *************************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //



// Use this macro to create a template specialization for the object 'RemoveConstantQualifier'.
//
// The required arguments are :
//
//      1. InputConstantType - the input type with the constant qualifier
//      2. OutputTypeWithoutConstantQualifier - the type without the constant qualifier
//
#define CreateRemoveConstantQualifierTemplateSpecialization( InputConstantType, OutputTypeWithoutConstantQualifier )                                                              \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
    template< typename AnyType >                                                                                                                                                        \
    class RemoveConstantQualifier< InputConstantType >                                                                                                                                  \
    {                                                                                                                                                                                   \
    public:                                                                                                                                                                             \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
        /* Create a type definition of the template type without the constant qualifier */                                                                                              \
        using Type = OutputTypeWithoutConstantQualifier;                                                                                                                                \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
    private:                                                                                                                                                                            \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
        /* Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator */                     \
        NoInstances( RemoveConstantQualifier );                                                                                                                                   \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
    }  // Class RemoveConstantQualifier



// Create all the required template specializations, the possibilites are :
//
//      const AnyType                               ->  AnyType
//      const volatile AnyType                      ->  volatile AnyType
//
//      AnyType* const                              ->  AnyType*
//      AnyType* const volatile                     ->  AnyType* volatile
//      const AnyType* const                        ->  const AnyType*
//      const volatile AnyType* const               ->  const volatile AnyType*
//      AnyType* const volatile                     ->  AnyType* volatile 
//      const AnyType* const volatile               ->  const AnyType* volatile 
//      const volatile AnyType* const volatile      ->  const volatile AnyType* volatile
//
//      const AnyType&                               ->  AnyType&
//      const volatile AnyType&                      ->  volatile AnyType&
//
CreateRemoveConstantQualifierTemplateSpecialization( const AnyType, AnyType );
CreateRemoveConstantQualifierTemplateSpecialization( const volatile AnyType, volatile AnyType );

CreateRemoveConstantQualifierTemplateSpecialization( AnyType* const, AnyType* );
CreateRemoveConstantQualifierTemplateSpecialization( AnyType* const volatile, AnyType* volatile );
CreateRemoveConstantQualifierTemplateSpecialization( const AnyType* const, const AnyType* );
CreateRemoveConstantQualifierTemplateSpecialization( const volatile AnyType* const, const volatile AnyType* );
CreateRemoveConstantQualifierTemplateSpecialization( const AnyType* const volatile, const AnyType* volatile );
CreateRemoveConstantQualifierTemplateSpecialization( const volatile AnyType* const volatile, const volatile AnyType* volatile );

CreateRemoveConstantQualifierTemplateSpecialization( const AnyType&, AnyType& );



}  //  Namespace Universe