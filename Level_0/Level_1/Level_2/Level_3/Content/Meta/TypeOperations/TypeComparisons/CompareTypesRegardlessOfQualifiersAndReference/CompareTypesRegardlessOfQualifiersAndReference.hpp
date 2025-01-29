namespace Universe
{



// Template Class Information :
//
//  Purpose :
//
//      Use this object ot compare if all the template types provided are the same type. This is the most genral case, and the basic case which is only for two
//      types is used each time to compare the types recursively. The idea is that to compare if all the types match there should be :
//
//                  int int short int int short
//                   |   |    |    |   |    |
//                   -----    ------   ------       <-- 3 comparisons
//                     |         |        |
//                     -----------        |         <-- 1 comparison
//                          |             |
//                          ---------------         <-- 1 comparison
//
//      As can be seen to compare 6 types, 5 comparisons are needed, and in the general the formula is 2 in the power of the number of types minus 1 ( 2^N - 1 ).
//      After this unconnected piece of information, the process will be checking the first two arguments, and to compare the second argument from the orevious 
//      comparison with the next type in the list in the next recuression
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
//  Expectations :
//
//      NONE
//
//  Possible errors :
//
//      Too many to count
//
template< typename FirstType, typename SecondType, typename... Types >
class CompareTypesRegardlessOfQualifiersAndReference : public IntegralConstant< Boolean, CompareTypes< typename RemoveQualifiersAndReference< FirstType >::Type, typename RemoveQualifiersAndReference< SecondType >::Type >::Result && CompareTypesRegardlessOfQualifiersAndReference< SecondType, Types... >::Result >
{
private :


    // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
    NoInstances( CompareTypesRegardlessOfQualifiersAndReference );


};  //  Class CompareTypesRegardlessOfQualifiersAndReference



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ****************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Only two template arguments, and different type   ************************************ //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //



// Template Class Information :
//
//  Purpose :
//
//      This is a template specialization for two template types, that are different types. The result method will return false
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
//  Expectations :
//
//      NONE
//
//  Possible errors :
//
//      Too many to count
//
template< typename FirstType, typename SecondType >
class CompareTypesRegardlessOfQualifiersAndReference< FirstType, SecondType > : public IntegralConstant< Boolean, CompareTypes< typename RemoveQualifiersAndReference< FirstType >::Type, typename RemoveQualifiersAndReference< SecondType >::Type >::Result >
{
private :


    // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
    NoInstances( CompareTypesRegardlessOfQualifiersAndReference );


};  //  Class CompareTypesRegardlessOfQualifiersAndReference



}  //  Namespace Universe