namespace Universe
{



// Template Class Information :
//
//  Purpose :
//
//      Use this object to provide a type check. In general If the given type is declared constant, this object will contain a boolean value of true, 
//      and otherwise false. This is the main template it will conatin false for all types not decalred as constant, and will contain true if the type
//      is a reference, reference does not need the 'const' qualifier, it is inheritly constant. Each possible declaration of constant with type, needs
//      to have a template specialization of its own, which will contain true
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
class IsVolatile : public IntegralConstant< Boolean, false >
{
private:


    // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
    NoInstances( IsVolatile );


};  //  Class IsVolatile



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ***************************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION   *************************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //



// Use this macro to create a template specialization for the object 'IsVolatile'.
//
// The required arguments are :
//
//      1. InputConstantType - the constant input type, it needs to be of the form   ->   ... AnyType ...
//
#define CreateIsVolatileTemplateSpecialization( InputConstantType )                                                                                                               \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
    template< typename AnyType >                                                                                                                                                        \
    class IsVolatile< InputConstantType > : public IntegralConstant< Boolean, true >                                                                                                    \
    {                                                                                                                                                                                   \
    private:                                                                                                                                                                            \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
        /* Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator */                     \
        NoInstances( IsVolatile );                                                                                                                                                \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
    }  // Class IsVolatile



// Create all the required template specializations, the type are :
//
//      volatile Type
//      const volatile Type
//  
//      Type* volatile
//      Type* const volatile
//
CreateIsVolatileTemplateSpecialization( volatile AnyType );
CreateIsVolatileTemplateSpecialization( const volatile AnyType );

CreateIsVolatileTemplateSpecialization( AnyType* volatile );
CreateIsVolatileTemplateSpecialization( AnyType* const volatile );



}  //  Namespace Universe