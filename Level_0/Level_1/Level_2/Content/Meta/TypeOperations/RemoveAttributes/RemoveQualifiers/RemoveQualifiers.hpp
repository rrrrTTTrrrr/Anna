namespace Universe
{



// Template Class Information :
//
//  Purpose :
//
//      Use this object to take a remove all qualifiers from a type. The possible qualifiers are :
//          
//          1. Constant qualifier - 'const'
//          2. Volatile qualifier - 'volatile'
//
//      This means for example :
//
//          Type                    ->    Type
//          Type&                   ->    Type&
//          Type&&                  ->    Type&&
//          Type* const             ->    Type*
//          const volatile Type     ->    Type
//          const Type&             ->    Type&
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
class RemoveQualifiers NotForInheritance
{
public:


    // This type definition will be for the same type exactly as the template type
    using Type = typename RemoveVolatileQualifier< typename RemoveConstantQualifier< typename RemoveReference< AnyType >::Type >::Type >::Type;


private :


    // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
    NoInstances( RemoveQualifiers );


};  //  Class RemoveQualifiers



}  //  Namespace Universe