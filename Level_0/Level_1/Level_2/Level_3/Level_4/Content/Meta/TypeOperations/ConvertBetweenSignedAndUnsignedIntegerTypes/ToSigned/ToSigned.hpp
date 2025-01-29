namespace Universe
{



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
template< Concepts::Integer SignedIntegerType >
class ToSigned
{
public:


    // Type definition for the signed integer type provided
    using Type = SignedIntegerType;


private:


    // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
    NoInstances( ToSigned );


};  //  Class ToSigned



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ***************************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION   *************************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //



// Use this macro to create a template specialization for the object 'ToSigned'.
//
// The required arguments are :
//
//      1. InputUnsignedType - the unsigned input type
//      2. OutputSignedType - the output signed counterpart type of the unsigned input type 
//
#define CreateUnsignedToSignedTemplateSpecialization( InputUnsignedType, OutputSignedType )                                                                                       \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
    template<>                                                                                                                                                                          \
    class ToSigned< InputUnsignedType >                                                                                                                                                 \
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
        NoInstances( ToSigned );                                                                                                                                                  \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
    };  // Class ToSigned



// Create all the required template specializations, the type are :
//
//      UnsignedInteger8bits      ->        SignedInteger8bits
//      UnsignedInteger16bits     ->        SignedInteger16bits
//      UnsignedInteger32bits     ->        SignedInteger32bits
//      UnsignedInteger64bits     ->        SignedInteger64bits
//
// All the types returned will match the cv qualifiers of the type. For example :
//
//      const UnsignedInteger8bits            -> const SignedInteger64bits
//      volatile UnsignedInteger8bits         -> volatile SignedInteger64bits
//      const volatile UnsignedInteger8bits   -> const volatile SignedInteger64bits
//
CreateUnsignedToSignedTemplateSpecialization( UnsignedInteger8bits, SignedInteger8bits )
CreateUnsignedToSignedTemplateSpecialization( UnsignedInteger16bits, SignedInteger16bits )
CreateUnsignedToSignedTemplateSpecialization( UnsignedInteger32bits, SignedInteger32bits )
CreateUnsignedToSignedTemplateSpecialization( UnsignedInteger64bits, SignedInteger64bits )



}  //  Namespace Universe