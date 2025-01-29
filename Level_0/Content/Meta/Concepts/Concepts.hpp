namespace Universe
{


namespace Concepts
{




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************************************   CONCEPTS   ******************************************************************************* //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //




// For concepts that need one parameter ( not necessarily type ), there is a shorthand :
//
//	template< Integer Type >
//
// For those that need two or more parameters, there is no shorthand :
//
//	template< typename FirstType, typename SecondType > requires CompareTypes< FirstType, SecondType >



//  *********************************************************************  BASIC OBJECT FUNCTIONALITY   ********************************************************************* //



// Create the concepts that can be used to ensure that the template type has some basic functionality, like default constructr and assignment 
// operator the use of template types :


// CONSTRUCTOR :


// Check if the template type object has a default constructor. The check is done, by trying to compile the following code, which contains a call to the
// template type default constructor
//
template< typename ExaminedType >
concept DefaultConstructible = requires()
{
	{ ExaminedType() };
};


// DESTRUCTOR :


// Check if the template type object has a default constructor. The check is done, by trying to compile the following code, which contains a call to the
// template type default constructor
//
template< typename ExaminedType >
concept Destructible = requires( ExaminedType instance )
{
	{ instance.~ExaminedType() };
};


// COPY CONSTRUCTOR :


// Check if the template type object has a copy constructor. The check is done, by trying to compile the following code, which contains a call to the
// template type copy constructor
//
template< typename ExaminedType >
concept CopyConstructible = requires( ExaminedType instance )
{
	{ ExaminedType( instance ) };
};


// ASSIGNMENT OPERATOR :


// Check if the template type object has a copy constructor. The check is done, by trying to compile the following code, which contains a call to the
// template type copy constructor
//
template< typename ExaminedType >
concept Assignable = requires( ExaminedType instance, ExaminedType otherInstance )
{
	{ instance = otherInstance };
};


// COPYABLE :


// Check if the template type object is copyable, which means it has a copy constructor and assignment operator
//
template< typename ExaminedType >
concept Copyable = CopyConstructible< ExaminedType > &&  Assignable< ExaminedType >;


// MOVE CONSTRUCTOR :


// Check if the template type object has a copy constructor. The check is done, by trying to compile the following code, which contains a call to the
// template type copy constructor
//
template< typename ExaminedType >
concept MoveConstructible = requires( ExaminedType&& instance )
{
	{ ExaminedType( static_cast< ExaminedType&& >( instance ) ) };
};


// MOVE ASSIGNMENT OPERATOR :


// Check if the template type object has a copy constructor. The check is done, by trying to compile the following code, which contains a call to the
// template type copy constructor
//
template< typename ExaminedType >
concept MoveAssignable = requires( ExaminedType instance, ExaminedType&& otherInstance )
{
	{ instance = static_cast< ExaminedType&& >( otherInstance ) };
};


// COPYABLE :


// Check if the template type object is copyable, which means it has a move constructor and move assignment operator
//
template< typename ExaminedType >
concept Movable = MoveConstructible< ExaminedType > &&  MoveAssignable< ExaminedType >;



//  *********************************************************************  OBJECT OPERATORS DETECTORS   ******************************************************************** //



// OPERATOR '<' :


// Check if the template type object has the operator is smaller '<' implemented
//
template< typename ExaminedType >
concept ObjectWithIsSmallerOperator = requires( ExaminedType firstInstance, ExaminedType secondInstance )
{
	{ firstInstance < secondInstance };
};


// OPERATOR '>' :


// Check if the template type object has the operator is larger '>' implemented
//
template< typename ExaminedType >
concept ObjectWithIsLargerOperator = requires( ExaminedType firstInstance, ExaminedType secondInstance )
{
	{ firstInstance > secondInstance };
};


// MULTIPLE OPERAOTR REQUIREMENTS :


// Check if the template type object has the operator is smaller '>' implemented, and the operator is larger not implemented
//
template< typename ExaminedType >
concept ObjectWithIsSmallerOperatorAndIsLargerOpeatorDoesNotExist = ObjectWithIsSmallerOperator< ExaminedType > && !ObjectWithIsLargerOperator< ExaminedType >;


// Check if the template type object has the operator is larger '>' implemented, and the operator is smaller not implemented
//
template< typename ExaminedType >
concept ObjectWithIsLargerOperatorAndIsSmallerOpeatorDoesNotExist = ObjectWithIsLargerOperator< ExaminedType > && !ObjectWithIsSmallerOperator< ExaminedType >;



//  ******************************************************************************   FUNCTOR   ****************************************************************************** //



// Create the concepts required to constraint the use of template types for functors :


// Check if the template type object is a functor, which means implemented the operator '()'. The check is done, by trying to compile the following code, 
// which contains a call to the template type operator '()' with the required arguments
//
template< typename ExaminedType, typename... ArgumentsTypes >
concept Functor = requires( ExaminedType instance, ArgumentsTypes... arguments )
{
	{ instance( arguments... )  };
};


// Check if the template type object is a functor without arguments, which means implemented the operator '()'. The check is done, by
// trying to compile the following code, which contains a call to the template type operator '()'
//
template< typename ExaminedType >
concept FunctorWithoutArguments = requires( ExaminedType instance )
{
	{ instance() };
};


// Check if the template type object is a functor that accept at least one argument, which means implemented the operator '()'. The check is done, by 
// trying to compile the following code, which contains a call to the template type operator '()' with the required arguments
//
template< typename ExaminedType, typename FirstArgumentType, typename... RestOfArgumentsTypes >
concept FunctorWithAtLeastOneArgument = requires( ExaminedType instance, FirstArgumentType firstArgument, RestOfArgumentsTypes... restOfArguments )
{
	{ instance( firstArgument, restOfArguments... )  };
};



}  //  Namespace Concepts


}  //  Namespace Universe
