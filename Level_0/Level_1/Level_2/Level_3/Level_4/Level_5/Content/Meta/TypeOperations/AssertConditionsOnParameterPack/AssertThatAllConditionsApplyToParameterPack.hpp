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
//		The question then how to check if all of the types in the parameter pack is constant and choose the correct implementation of the object.
//
//		This object receives a parameter pack of conditions, and recursively passes on each one of them and check if the condition is true. It
//		will continue passing until the end only if all conditions are valid, otherwise it will stop on the first condition that has the value
//		false, it basically acts as 'AND' between the conditions. Note, this object does not accept types, it accepts objects that check conditions 
//		on types and inherit from the object 'IntegralConstant', and it knows to check for the result of the condition checked. This is the
//		general template, it will be choosen when all conditions are valid and will contain the value true. There is one problem with this object
//		that it can generate a lot of extra code, then most of times instead of sending the actual condition it is better to send just the result
//		of the condition and use the object 'AssertAllTrue'
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
//          1. Conditions - a parameter pack of object that check some condition on a type
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< typename... Conditions >
class AssertThatAllConditionsApplyToParameterPack : public IntegralConstant< Boolean, true >
{
private:


    // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
    NoInstances( AssertThatAllConditionsApplyToParameterPack );


};  //  Class AssertThatAllConditionsApplyToParameterPack



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ****************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - For case even one condition does not apply   ***************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //



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
//		The question then how to check if all of the types in the parameter pack is constant and choose the correct implementation of the object.
//
//		This object receives a parameter pack of conditions, and recursively passes on each one of them and check if the condition is true. It
//		will continue passing until the end only if all conditions are valid, otherwise it will stop on the first condition that has the value
//		false, it basically acts as 'AND' between the conditions. Note, this object does not accept types, it accepts objects that check conditions 
//		on types and inherit from the object 'IntegralConstant', and it knows to check for the result of the condition checked. This is the
//		a template specialization, it will be choosen when even one condition does not apply and will contain the value false. There is one problem 
//		with this object that it can generate a lot of extra code, then most of times instead of sending the actual condition it is better to send 
//		just the result of the condition and use the object 'AssertAllTrue'
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
//          1. Conditions - a parameter pack of object that check some condition on a type
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< typename Condition, typename... Conditions >
class AssertThatAllConditionsApplyToParameterPack< Condition, Conditions... > : public ChooseBetweenTwoTypes< Condition::Result, AssertThatAllConditionsApplyToParameterPack< Conditions... >, IntegralConstant< Boolean, false > >::Type
{
private:


    // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
    NoInstances( AssertThatAllConditionsApplyToParameterPack );


};  //  Class AssertThatAllConditionsApplyToParameterPack



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// **************************************************   TYPE DEFINITIONS FOR POSSIBLE CHECKS ON TYPES OF PARAMETERS PACK   ************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //



// Use this type definition to check if a parameter pack has all types declared as constant
template< typename... ParameterPack >
using DoesParameterPackContainAllConstantTypes = AssertThatAllConditionsApplyToParameterPack< IsConstant< ParameterPack >... >;


// Use this type definition to check if a parameter pack has all types declared as references
template< typename... ParameterPack >
using DoesParameterPackContainAllReferenceTypes = AssertThatAllConditionsApplyToParameterPack< IsReference< ParameterPack >... >;


// Use this type definition to check if a parameter pack has all types declared as lvalue references
template< typename... ParameterPack >
using DoesParameterPackContainAllLvalueReferenceTypes = AssertThatAllConditionsApplyToParameterPack< IsLvalueReference< ParameterPack >... >;


// Use this type definition to check if a parameter pack has all types declared as rvalue references
template< typename... ParameterPack >
using DoesParameterPackContainAllRvalueReferenceTypes = AssertThatAllConditionsApplyToParameterPack< IsRvalueReference< ParameterPack >... >;


// Use this type definition to check if all the types of the parameter pack has default constructor
template< typename... ParameterPack >
using DoesParameterPackContainAllTypesWithDefaultConstructor = AssertThatAllConditionsApplyToParameterPack< IsDefaultConstructible< ParameterPack >... >;


// Use this type definition to check if all the types of the parameter pack are pointers
template< typename... ParameterPack >
using DoesParameterPackContainsOnlyPointerTypes = AssertThatAllConditionsApplyToParameterPack< IsPointer< ParameterPack >... >;


// Use this type definition to check if all the types of the parameter pack are numeric
template< typename... ParameterPack >
using DoesParameterPackContainsOnlyNumericTypes = AssertThatAllConditionsApplyToParameterPack< IsNumeric< ParameterPack >... >;



}  //  Namespace Universe
