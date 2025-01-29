namespace Universe
{



// Template Class Information :
//
//  Purpose :
//
//      Use this object to take a type declared with the volatile qualifier, and remove the volatile qualifier. This means :
//
//          volatile Type     ->    Type
//          Type* volatile    ->    Type*
//          Type&          ->    Type&
//
//      Any constant qualifier will remain : 
//
//          const Type          ->    const Type
//          const const Type    ->    const Type
//
//      This is the main template, it will accept only types not decalred with the constant qualifier and will create a type definition to 
//      exactly the same type given. Note - when the volatile qualifier is applied on a pointer, there is a volatile qualifier that applies
//      to the pointer itself, which means the compiler can not perform optimization on the pointer itself, and this is the volatile qualifier
//      this object aims to remove. And there is the volatile qualifier that applies to the pointed instance by the pointer, which has no effect
//      in this object
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
class RemoveVolatileQualifier NotForInheritance
{
public:


    // This type definition will be for the same type exactly as the template type
    using Type = AnyType;


private :


    // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
    NoInstances( RemoveVolatileQualifier );


};  //  Class RemoveVolatileQualifier



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ***************************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION   *************************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //



// Use this macro to create a template specialization for the object 'RemoveVolatileQualifier'.
//
// The required arguments are :
//
//      1. InputVolatileType - the input type with the volatile qualifier
//      2. OutputTypeWithoutVolatileQualifier - the type without the volatile qualifier
//
#define CreateRemoveVolatileQualifierTemplateSpecialization( InputVolatileType, OutputTypeWithoutVolatileQualifier )                                                              \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
    template< typename AnyType >                                                                                                                                                        \
    class RemoveVolatileQualifier< InputVolatileType >                                                                                                                                  \
    {                                                                                                                                                                                   \
    public:                                                                                                                                                                             \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
        /* Create a type definition of the template type without the volatile qualifier */                                                                                              \
        using Type = OutputTypeWithoutVolatileQualifier;                                                                                                                                \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
    private:                                                                                                                                                                            \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
        /* Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator */                     \
        NoInstances( RemoveVolatileQualifier );                                                                                                                                    \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
    }  // Class RemoveVolatileQualifier



// Create all the required template specializations, the possibilites are :
//
//      volatile AnyType                            ->  AnyType
//      const volatile AnyType                      ->  const AnyType
//
//      AnyType* volatile                           ->  AnyType*
//      AnyType* const volatile                     ->  AnyType* const
//      const AnyType* volatile                     ->  const AnyType*
//      const volatile AnyType* volatile            ->  const volatile AnyType*
//      AnyType* const volatile                     ->  AnyType* const 
//      const AnyType* const volatile               ->  const AnyType* const 
//      const volatile AnyType* const volatile      ->  const volatile AnyType* const
//
//      const AnyType&                               ->  AnyType&
//      const volatile AnyType&                      ->  volatile AnyType&
//
CreateRemoveVolatileQualifierTemplateSpecialization( volatile AnyType, AnyType );
CreateRemoveVolatileQualifierTemplateSpecialization( const volatile AnyType, const AnyType );

CreateRemoveVolatileQualifierTemplateSpecialization( AnyType* volatile, AnyType* );
CreateRemoveVolatileQualifierTemplateSpecialization( AnyType* const volatile, AnyType* const );
CreateRemoveVolatileQualifierTemplateSpecialization( const AnyType* volatile, const AnyType* );
CreateRemoveVolatileQualifierTemplateSpecialization( const volatile AnyType* volatile, const volatile AnyType* );
CreateRemoveVolatileQualifierTemplateSpecialization( const AnyType* const volatile, const AnyType* const );
CreateRemoveVolatileQualifierTemplateSpecialization( const volatile AnyType* const volatile, const volatile AnyType* const );

CreateRemoveConstantQualifierTemplateSpecialization( volatile AnyType&, AnyType& );
CreateRemoveConstantQualifierTemplateSpecialization( const volatile AnyType&, const AnyType& );



}  //  Namespace Universe