namespace Universe
{



// Template Class Information :
//
//  Purpose :
//
//      Use this object to provide a type check. In general If the given type is floating point, this object will contain a boolean value of true, 
//      and otherwise false. This is the main template it will conatin false for all types, and each floating point type needs to have a template
//      specialization of its own, which will contain true
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
class IsFloatingPoint : public IntegralConstant< Boolean, false >
{
private:


    // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
    NoInstances( IsFloatingPoint );


};  //  Class IsFloatingPoint



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ***************************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION   *************************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //



// Use this macro to create a template specialization for the object 'IsFloatingPoint'.
//
// The required arguments are :
//
//      1. InputFloatingPointType - the floating point input type
//
#define CreateIsFloatingPointTemplateSpecialization( InputFloatingPointType )                                                                                                     \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
    template<>                                                                                                                                                                          \
    class IsFloatingPoint< InputFloatingPointType > : public IntegralConstant< Boolean, true >                                                                                          \
    {                                                                                                                                                                                   \
    private:                                                                                                                                                                            \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
        NoInstances( IsFloatingPoint );                                                                                                                                           \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
    }  // Class IsFloatingPoint



// Create all the required template specializations, the type are :
//
//      FloatingPoint32bits
//      FloatingPoint64bits
//
// And also for the cv qualifiers types :
//
//      const FloatingPoint32bits
//      volatile FloatingPoint32bits
//      const volatile FloatingPoint32bits
//
CreateIsFloatingPointTemplateSpecialization( FloatingPoint32bits );
CreateIsFloatingPointTemplateSpecialization( FloatingPoint64bits );

CreateIsFloatingPointTemplateSpecialization( const FloatingPoint32bits );
CreateIsFloatingPointTemplateSpecialization( const FloatingPoint64bits );

CreateIsFloatingPointTemplateSpecialization( volatile FloatingPoint32bits );
CreateIsFloatingPointTemplateSpecialization( volatile FloatingPoint64bits );

CreateIsFloatingPointTemplateSpecialization( const volatile FloatingPoint32bits );
CreateIsFloatingPointTemplateSpecialization( const volatile FloatingPoint64bits );



}  //  Namespace Universe