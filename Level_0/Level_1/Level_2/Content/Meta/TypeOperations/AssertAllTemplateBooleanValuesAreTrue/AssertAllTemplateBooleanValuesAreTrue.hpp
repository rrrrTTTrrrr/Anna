namespace Universe
{



// Template Class Information :
//
//  Purpose :
//
//		The problem this object comes to help solving is how to check a condition on all types of a parameter pack. For example :
//
//			template< typename... Types >
//			class Mother
//			{};
//		
//		Then class 'Mother' can only work with types that are not constant for example, and for constant types it has a template specialization.
//		The question then how to check if one of the types in the parameter pack is constant and choose the correct implementation of the object.
//		This object receives a parameter pack of booleans, and recursively passes on each one of them and check if all of them are true. It
//		will continue passing until the end only if all booleans are true, otherwise it will stop on the first boolean that has the value
//		false, it basically acts as 'AND' between the booleans. This is the general template, it will be choosen when all booleans are true 
//      and will contain the value true
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
//          1. Booleans - a parameter pack of booleans
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< Boolean... Booleans >
class AssertAllTemplateBooleansValuesAreTrue : public IntegralConstant< Boolean, true >
{
private:


    // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
    NoInstances( AssertAllTemplateBooleansValuesAreTrue );


};  //  Class AssertAllTemplateBooleansValuesAreTrue



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ****************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - For case even one condition does not apply   ***************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //



// Template Class Information :
//
//  Purpose :
//
//      The problem this object comes to help solving is how to check a condition on all types of a parameter pack. For example :
//
//          template< typename... Types >
//          class Mother
//          {};
//      
//      Then class 'Mother' can only work with types that are not constant for example, and for constant types it has a template specialization.
//      The question then how to check if one of the types in the parameter pack is constant and choose the correct implementation of the object.
//      This object receives a parameter pack of booleans, and recursively passes on each one of them and check if all of them are true. It
//      will continue passing until the end only if all booleans are true, otherwise it will stop on the first boolean that has the value
//      false, it basically acts as 'AND' between the booleans. This is the a template specialization, it will be choosen when even one 
//      boolean has the value false and will contain the value false
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
//          1. ExposedBoolean - the current exposed boolean value
//          2. Booleans - the rest of the booleans parameter pack
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< Boolean ExposedBoolean, Boolean... Booleans >
class AssertAllTemplateBooleansValuesAreTrue< ExposedBoolean, Booleans... > : public ChooseBetweenTwoTypes< ExposedBoolean, AssertAllTemplateBooleansValuesAreTrue< Booleans... >, IntegralConstant< Boolean, false > >::Type
{
private:


    // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
    NoInstances( AssertAllTemplateBooleansValuesAreTrue );


};  //  Class AssertAllTemplateBooleansValuesAreTrue



}  //  Namespace Universe