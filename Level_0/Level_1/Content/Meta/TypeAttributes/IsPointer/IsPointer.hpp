namespace Universe
{



// Template Class Information :
//
//  Purpose :
//
//      Use this object to provide a type check. In general If the given type is a pointer, this object will contain a boolean value of true, 
//      and otherwise false. This is the main template it will conatin false for all types, and each pointer type needs to have a template
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
//          1. Type - any type
//
//  Expectations :
//
//      NONE
//
//  Possible errors :
//
//      Too many to count
//
template< typename Type >
class IsPointer : public IntegralConstant< Boolean, false >
{
public:


    // Create a type definition for this object
    using SelfType = IsPointer< Type >;


private:


    // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
    NoInstances( IsPointer );


};  //  Class IsPointer




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// **************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Type - Function pointer   ************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



// Template Class Information :
//
//  Purpose :
//
//      Use this object to provide a type check. In general If the given type is a pointer, this object will contain a boolean value of true, 
//      and otherwise false. This is the main template it will conatin false for all types, and each pointer type needs to have a template
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
//          1. Type - any type
//
//  Expectations :
//
//      NONE
//
//  Possible errors :
//
//      Too many to count
//
template< typename ReturnType, typename... ArgumentTypes >
class IsPointer< ReturnType (*)( ArgumentTypes... ) >  : public IntegralConstant< Boolean, false >
{
private:


    // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
    NoInstances( IsPointer );


};  //  Class IsPointer



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ***************************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION   *************************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



// Use this macro to create a template specialization for the object 'IsPointer'.
//
// The required arguments are :
//
//      1. InputPointerType - the pointer input type, it needs to be of the form   ->   ... Type* ...
//
#define CreateIsPointerTemplateSpecialization( InputPointerType )                                                                                                                 \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
    template< typename Type >                                                                                                                                                        \
    class IsPointer< InputPointerType > : public IntegralConstant< Boolean, true >                                                                                                      \
    {                                                                                                                                                                                   \
    private:                                                                                                                                                                            \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
        /* Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator */                     \
        NoInstances( IsPointer );                                                                                                                                                 \
                                                                                                                                                                                        \
                                                                                                                                                                                        \
    }  // Class IsPointer



// Create all the required template specializations, the type are :
//
//      Type*
//
// And also for the cv qualifiers types :
//
//      const Type*
//      Type* const
//      const Type* const
//
//      volatile Type*
//      Type* volatile
//      volatile Type* volatile
//
//      const Type* volatile
//      volatile Type* const
//
//      const volatile Type* const
//      const Type* const volatile
//
//      const volatile Type* volatile
//      volatile Type* const volatile
//
//      const volatile Type* 
//      Type* const volatile
//      const volatile Type* const volatile
//
CreateIsPointerTemplateSpecialization( Type* );

CreateIsPointerTemplateSpecialization( const Type* );
CreateIsPointerTemplateSpecialization( Type* const );
CreateIsPointerTemplateSpecialization( const Type* const );

CreateIsPointerTemplateSpecialization( volatile Type* );
CreateIsPointerTemplateSpecialization( Type* volatile );
CreateIsPointerTemplateSpecialization( volatile Type* volatile );

CreateIsPointerTemplateSpecialization( const Type* volatile );
CreateIsPointerTemplateSpecialization( volatile Type* const );

CreateIsPointerTemplateSpecialization( const volatile Type* const );
CreateIsPointerTemplateSpecialization( const Type* const volatile );

CreateIsPointerTemplateSpecialization( const volatile Type* volatile );
CreateIsPointerTemplateSpecialization( volatile Type* const volatile );

CreateIsPointerTemplateSpecialization( const volatile Type* );
CreateIsPointerTemplateSpecialization( Type* const volatile );
CreateIsPointerTemplateSpecialization( const volatile Type* const volatile );



}  //  Namespace Universe