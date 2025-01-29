namespace Universe
{



// Template Class Information :
//
//  Purpose :
//
//		Use this object to provide a type check. In general If the given type is a built in type, something the C++ provides as default to
//      write code, which means it does not provide all the functionality of an object, which include how to construt, destory, copy, initialize
//      and more and more, this object will contain a boolean value of true, and otherwise false. This is needed because built in type will need
//      different behavior usually then objects, for example they have usually a defualt state of 0, and not through the default construtor or 
//      the reset method. There are 4 options of built in types :
//
//          1. Integers
//          2. Floating points
//          3. Pointers
//          4. References - lvalue and rvalue
//
//      And all have also the constant option
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
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< typename AnyType >
class IsBuiltIn : public IntegralConstant< Boolean, IsInteger< AnyType >::Result || IsFloatingPoint< AnyType >::Result || IsPointer< AnyType >::Result || IsReference< AnyType >::Result || CompareTypes< AsciiCharacter, AnyType >::Result >
{
private:


    // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
    NoInstances( IsBuiltIn );


};  //  Class IsBuiltIn



}  //  Namespace Universe