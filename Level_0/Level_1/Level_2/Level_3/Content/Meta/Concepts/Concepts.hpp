namespace Universe
{


namespace Concepts
{




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ******************************************************************   CONCEPTS - ATOMIC CONSTRAINTS    ******************************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //




// The following are the 'atomic constraints'. They are the building blocks for creating more complex concepts. Each constraint is a 
// condition that can be checked on a template type :


template< typename FirstType, typename... RestOfTypes >
concept NonVoid = CompareTypes< void, FirstType, RestOfTypes... >::Result == false;


template< typename FirstType, typename SecondType, typename... RestOfTypes >
concept SameAs = CompareTypes< FirstType, SecondType, RestOfTypes... >::Result && CompareTypes< SecondType, FirstType, RestOfTypes... >::Result;


template< typename FirstType, typename SecondType, typename... RestOfTypes >
concept SameAsRegardlessOfTemplateArguments = CompareRegardlessOfTemplateArguments< FirstType, SecondType, RestOfTypes... >::Result && CompareRegardlessOfTemplateArguments< SecondType, FirstType, RestOfTypes... >::Result;


template< typename ExaminedType >
concept Pointer = IsPointer< ExaminedType >::Result;




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************************************   CONCEPTS   ******************************************************************************* //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



//  ******************************************************************************   NUMERIC   ****************************************************************************** //



// Create a prototype for object in the system. It should have :
//
//	1. Default constructor
//	2. Copy constructor
//	3. Assignment operator
//	4. Move constructor
//	5. Move assignment operator
//	6. Destructor
//
template< typename ExaminedType >
concept Object = DefaultConstructible< ExaminedType > && CopyConstructible< ExaminedType > && Assignable< ExaminedType > && MoveConstructible< ExaminedType > && MoveAssignable< ExaminedType > && Destructible< ExaminedType >;



//  ******************************************************************************   NUMERIC   ****************************************************************************** //



// Create the concepts that can be used to ensure that the template type has some numeric property, like signed or unsigned :


// SIGNED INTEGER :


// Check if the template type object is a signed integer pointer
//
template< typename ExaminedType >
concept SignedIntegerPointer = IsSignedInteger< ExaminedType >::Result && IsPointer< ExaminedType >::Result;


// Check if the template type object is a signed integer reference
//
template< typename ExaminedType >
concept SignedIntegerReference = IsSignedInteger< ExaminedType >::Result && IsReference< ExaminedType >::Result;


// Check if the template type object is a signed integer rvalue reference
//
template< typename ExaminedType >
concept SignedIntegerRvalueReference = IsSignedInteger< ExaminedType >::Result && IsRvalueReference< ExaminedType >::Result;


// Check if the template type object is a signed integer. The type must be non pointer, non reference and without 'const' or 'volatile'
// qualifiers
//
template< typename ExaminedType >
concept SignedInteger = IsSignedInteger< ExaminedType >::Result;


// UNSIGNED INTEGER :


// Check if the template type object is an unsigned integer pointer
//
template< typename ExaminedType >
concept UnsignedIntegerPointer = IsUnsignedInteger< ExaminedType >::Result && IsPointer< ExaminedType >::Result;


// Check if the template type object is an unsigned integer reference
//
template< typename ExaminedType >
concept UnsignedIntegerReference = IsUnsignedInteger< ExaminedType >::Result && IsReference< ExaminedType >::Result;


// Check if the template type object is an unsigned integer rvalue reference
//
template< typename ExaminedType >
concept UnsignedIntegerRvalueReference = IsUnsignedInteger< ExaminedType >::Result && IsRvalueReference< ExaminedType >::Result;


// Check if the template type object is an unsigned integer. The type must be non pointer, non reference and without 'const' or 'volatile'
// qualifiers
//
template< typename ExaminedType >
concept UnsignedInteger = IsUnsignedInteger< ExaminedType >::Result;


// INTEGER :


// Check if the template type object is an integer pointer
//
template< typename ExaminedType >
concept IntegerPointer = IsInteger< ExaminedType >::Result && IsPointer< ExaminedType >::Result;


// Check if the template type object is an integer reference
//
template< typename ExaminedType >
concept IntegerReference = IsInteger< ExaminedType >::Result && IsReference< ExaminedType >::Result;


// Check if the template type object is an integer rvalue reference
//
template< typename ExaminedType >
concept IntegerRvalueReference = IsInteger< ExaminedType >::Result && IsRvalueReference< ExaminedType >::Result;


// Check if the template type object is an integer. The type must be non pointer, non reference and without 'const' or 'volatile'
// qualifiers
//
template< typename ExaminedType >
concept Integer = IsInteger< ExaminedType >::Result;


// FLOATING POINT :


// Check if the template type object is an floating point pointer
//
template< typename ExaminedType >
concept FloatingPointPointer = IsFloatingPoint< ExaminedType >::Result && IsPointer< ExaminedType >::Result;


// Check if the template type object is an floating point reference
//
template< typename ExaminedType >
concept FloatingPointReference = IsFloatingPoint< ExaminedType >::Result && IsReference< ExaminedType >::Result;


// Check if the template type object is an floating point rvalue reference
//
template< typename ExaminedType >
concept FloatingPointRvalueReference = IsFloatingPoint< ExaminedType >::Result && IsRvalueReference< ExaminedType >::Result;


// Check if the template type object is an floating point. The type must be non pointer, non reference and without 'const' or 'volatile'
// qualifiers
//
template< typename ExaminedType >
concept FloatingPoint = IsFloatingPoint< ExaminedType >::Result;



//  ******************************************************************************   FUNCTOR   ****************************************************************************** //



// Create the concepts required to constraint the use of template types for functors :


// Check if the template type object is a functor, which means implemented the operator '()'. It will ensure that the functor can be called with the given
// arguments and that it returns the given type. The check is done, by trying to compile the following code, which contains a call to the template type 
// operator '()' with the required arguments
//
template< typename ExaminedType, typename ReturnType, typename... ArgumentsTypes >
concept FunctorWithSpecificReturnType = requires( ExaminedType instance, ArgumentsTypes... arguments )
{
	{ instance( arguments... )  } -> SameAs< ReturnType >;
};


// Check if the template type object is a functor that accept at least one argument, which means implemented the operator '()'. It will ensure that the 
// functor can be called with the given arguments and that it returns the given type. The check is done, by trying to compile the following code, which 
// contains a call to the template type operator '()' with the required arguments
//
template< typename ExaminedType, typename ReturnType, typename FirstArgumentType, typename... RestOfArgumentsTypes >
concept FunctorWithAtLeastOneArgumentAndSpecificRetrunType = requires( ExaminedType instance, FirstArgumentType firstArgument, RestOfArgumentsTypes... restOfArguments )
{
	{ instance( firstArgument, restOfArguments... )  } -> SameAs< ReturnType >;
};


// Check if the template type object is a functor that has a return value, which means implemented the operator '()'. The check is done, by
// trying to compile the following code, which contains a call to the template type operator '()' with the required arguments
//
template< typename ExaminedType, typename... ArgumentsTypes >
concept FunctorWithoutReturnValue = requires( ExaminedType instance, ArgumentsTypes... arguments )
{
	{ instance( arguments... )  } -> SameAs< void >;
};


// Check if the template type object is a functor without return value and arguments, which means implemented the operator '()'. The check is done, by
// trying to compile the following code, which contains a call to the template type operator '()'
//
template< typename ExaminedType >
concept FunctorWithoutReturnValueOrArguments = requires( ExaminedType instance )
{
	{ instance() } -> SameAs< void >;
};



}  //  Namespace Concepts


}  //  Namespace Universe
