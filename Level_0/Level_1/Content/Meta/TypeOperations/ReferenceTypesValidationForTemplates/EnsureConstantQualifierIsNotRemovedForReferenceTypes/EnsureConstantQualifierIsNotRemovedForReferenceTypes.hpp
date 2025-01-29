namespace Universe
{



// The object that deals with this problem in boost is - call_traits



// Template Class Information :
//
//  Purpose :
//
//      In a C++ template with a generic type :
//
//          template< typename Type >
//          void Follow( const Type instance )
//          {}
//          
//      If the template provided is a reference, for example 'int&', the reference type '&' conversion operator binds stronger then the 'const' 
//      qualifier. The function will end up with :
//
//          void Follow( int& )
//
//      And not :
//
//          void Follow( const int& )     ->   Which is WTFFFFFFFFF
//
//      To solve this problem this object exist. This is the general form, for any type which is not a reference, the template type will stay 
//      the same. For any reference type, it will be converted to a constant reference using a type definition, to ensure that the compiler
//      does not change the constant qualifier. This is the main template it will be used for all the types beside references. This object
//      can be used for return types as well as for arguments to methods types
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
template< typename AnyType >
class EnsureConstantQualifierIsNotRemovedForReferenceTypes NotForInheritance
{
public:


    // Create a type definition for the template argument which should stay the same
    using Type = AnyType;


private:


    // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
    NoInstances( EnsureConstantQualifierIsNotRemovedForReferenceTypes );


};  //  Class EnsureConstantQualifierIsNotRemovedForReferenceTypes



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ***************************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION   *************************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



// Use this macro to create a template specialization for the object 'EnsureConstantQualifierIsNotRemovedForReferenceTypes'.
//
// The required arguments are :
//
//      1. InputReferenceType - the reference input type
//      2. OutputTypeWithReferenceAndConstantQualifiers - the type without the reference qualifier
//
#define CreateEnsureConstantQualifierIsNotRemovedForReferenceTypesTemplateSpecialization( InputReferenceType, OutputTypeWithReferenceAndConstantQualifiers )                      \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
    template< typename AnyType >                                                                                                                                                        \
    class EnsureConstantQualifierIsNotRemovedForReferenceTypes< InputReferenceType >                                                                                                    \
    {                                                                                                                                                                                   \
    public:                                                                                                                                                                             \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
        /* Create a type definition of the template type, which is a reference, and add the constant qualifier to ensure that the compiler will not remove it */                        \
        using Type = OutputTypeWithReferenceAndConstantQualifiers;                                                                                                                      \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
    private:                                                                                                                                                                            \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
        /* Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator */                     \
        NoInstances( EnsureConstantQualifierIsNotRemovedForReferenceTypes );                                                                                                      \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
    }  // Class EnsureConstantQualifierIsNotRemovedForReferenceTypes



// Create all the required template specializations, the possibilites are :
//
//      AnyType&                    -> const AnyType&
//      AnyType&&                   -> const AnyType&&
//      volatile AnyType&           -> const volatile AnyType&
//      volatile AnyType&&          -> const volatile AnyType&&
//
CreateEnsureConstantQualifierIsNotRemovedForReferenceTypesTemplateSpecialization( AnyType&, const AnyType& );
CreateEnsureConstantQualifierIsNotRemovedForReferenceTypesTemplateSpecialization( AnyType&&, const AnyType&& );
CreateEnsureConstantQualifierIsNotRemovedForReferenceTypesTemplateSpecialization( volatile AnyType&, const volatile AnyType& );
CreateEnsureConstantQualifierIsNotRemovedForReferenceTypesTemplateSpecialization( volatile AnyType&&, const volatile AnyType&& );



}  //  Namespace Universe