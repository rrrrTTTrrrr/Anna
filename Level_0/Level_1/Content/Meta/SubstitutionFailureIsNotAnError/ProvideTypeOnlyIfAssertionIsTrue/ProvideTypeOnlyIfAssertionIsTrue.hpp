namespace Universe
{



// Or in short, SFINAE
//
// Removing functions that do not yield valid template instantiations from a set of overloaded functions!
//
// Fucking A!
//
// In the process of template argument deduction, a C++ compiler attempts to instantiate signatures of a number of candidate overloaded functions to make sure that 
// exactly one overloaded function is available as a perfect match for a given function call. If an invalid argument or return type is formed during the instantiation 
// of a function template, the instantiation is removed from the overload resolution set instead of causing a compilation error. As long as there is one and only one 
// function to which the call can be dispatched, the compiler issues no errors.
//
// This feature is exploited using the following object!



// Template Class Information :
//
//  Purpose :
//
//      This object will have a type definition of the given type only if the expression result is true. It can be used as a return value, 
//      argument to methods and object template arguments to allow use only for certain types and situations
//
//  Description :
//
// 		1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by providing 3 keywords :
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
//      2. This object can be used to manipulate template types :
//
//              template< Boolean trueOrFalse, typename ProvideTypeOnlyIfAssertionIsTrue< trueOrFalse >::type* = nullptr >
//              void StaticAssert()
//              {
//                  std::cout << "Assertion Okay" << std::endl;
//              }
//
//              int main()
//              {
//                  StaticAssert< false >();    // Fails to compile
//                  StaticAssert< true >();     // Fucking compiles
//              }
//
//      2. Template arguments :
//
//          1. ExpressionResult - an expression that the result can be calculated during compile time, and the result is true or false
//          2. AnyType - any type
//
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< Boolean ExpressionResult, typename AnyType = void >
class ProvideTypeOnlyIfAssertionIsTrue NotForInheritance
{
public:


    // Create a type definition of the given template argument
    using Type = AnyType;


private:


    // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
    NoInstances( ProvideTypeOnlyIfAssertionIsTrue );


};  //  Class ProvideTypeOnlyIfAssertionIsTrue



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ***************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Expression Result = false   *********************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //



// Template Class Information :
//
//  Purpose :
//
//      This template specialization will be used when false is the result of the expression. It will not contain a type definition, it will be just an
//      empty object. The main template object is used to provide a return value type to the method only if the expression result is true, which means 
//      that this object will provide no type definition when the expression result will be false, will cause an invalid signature of the method. The 
//      point is that the compiler will try to instantiate each candidate method signature, now if it finds at least one valid signature, it has no
//      problem that while trying to instantiate all this candidate some signature comes out invalid. This is the all point of subtitution failure is 
//      not an error
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
class ProvideTypeOnlyIfAssertionIsTrue< false, AnyType > NotForInheritance
{
private:


    // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
    NoInstances( ProvideTypeOnlyIfAssertionIsTrue );


};  //  Class ProvideTypeOnlyIfAssertionIsTrue



}  //  Namespace Universe