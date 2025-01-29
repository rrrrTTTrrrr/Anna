namespace Universe
{



// Template Class Information :
//
//  Purpose :
//
//		This object is a wrapper to a static constant integral value. There are a few cases where this object is very useful. One of them is tag dispatch.
//      For example :
//
//      The first implementation is for primitive types :
//
//              template< typename TYPE >
//              UnsignedInteger32bits SomeMethod( TYPE instance, IntegralConstant< true, TYPE > )
//              {
//                  Method body...
//              }
//
//      The second implementation is for all others :
//
//              template< typename TYPE >
//              UnsignedInteger32bits SomeMethod( TYPE instance, IntegralConstant< false, TYPE > )
//              {   
//                  Method body... ohhh youre so sexy
//              }
//
//      And now it can be invoked for example :
//
//              template< typename TYPE >
//              void DoSomethingElse()
//              {
//                  // Invoke the method o
//                  SomeMethod< TYPE >( value, TypeCheck_Primitive< TYPE >{} );
//              }
//
//		Basically this object is used as the interface to use the type check objects and many more
//
//  Description :
//
//		1. This object contains an instance of the object "State" to allow each instance of this object to have a defined state
//
// 		2. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by providing 3 keywords :
//
//				1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the obejct using the tools
//							presented here. This part will usually contain only methods and not data members. If a data member is public all the encapsulation is
//							lost, so it should be avoided in most cases
//
//				2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will be able to access
//							   all the data and methods inside this part. This part will usually containt some methods and few data members
//
//				3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object and all the
//							 methods the developer needed to implement the interface presented in the public part. Every method in this part will end with the
//							 suffix __Private
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< typename IntegerType, IntegerType IntegerValue >
class IntegralConstant
{
public:


    // This object will store the value
    static constexpr IntegerType Result = IntegerValue;


private:


	// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
	NoInstances( IntegralConstant );


};  //  Class IntegralConstant



}  //  Namespace Universe