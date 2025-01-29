namespace Universe
{



// Template Class Information :
//
//  Purpose :
//
//      Use this object to take a signed integer type, and create a type definition of the same size just unsigned. This is the main
//      template, it used to decalre the object, and to provide a compilation error if any other type, then signed integer is used. A 
//      template specialization will be created for each signed integer type to convert to the corresponding unsgined type with the 
//      same size
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
//          1. UnsignedIntegerType - any type
//
//  Expectations :
//
//      NONE
//
//  Possible errors :
//
//      Too many to count
//
template< Concepts::Integer UnsignedIntegerType >
class ToUnsigned
{
public:


    // Type definition for the signed integer type provided
    using Type = UnsignedIntegerType;


private:


    // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
    NoInstances( ToUnsigned );


};  //  Class ToUnsigned



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ***************************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION   *************************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //



// Use this macro to create a template specialization for the object 'ToUnsigned'.
//
// The required arguments are :
//
//      1. InputSignedType - the signed input type
//      2. OutputUnsignedType - the output unsigned counterpart type of the signed input type 
//
#define CreateToUnsignedTemplateSpecialization( InputSignedType, OutputUnsignedType )                                                                                             \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
    template<>                                                                                                                                                                          \
    class ToUnsigned< InputSignedType >                                                                                                                                                 \
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
        NoInstances( ToUnsigned );                                                                                                                                                \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
    }  // Class ToUnsigned



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
CreateToUnsignedTemplateSpecialization( SignedInteger8bits, UnsignedInteger8bits );
CreateToUnsignedTemplateSpecialization( SignedInteger16bits, UnsignedInteger16bits );
CreateToUnsignedTemplateSpecialization( SignedInteger32bits, UnsignedInteger32bits );
CreateToUnsignedTemplateSpecialization( SignedInteger64bits, UnsignedInteger64bits );



}  //  Namespace Universe