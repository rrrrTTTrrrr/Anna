namespace Universe
{


namespace Concepts
{




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************************************   CONCEPTS   ******************************************************************************* //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //




//  ******************************************************************************   RAW TYPE   ***************************************************************************** //



// Check that the type is not a pointer or reference and it does not have any constant or volatile qualifiers
//
template< typename ExaminedType >
concept Raw = !IsPointer< ExaminedType >::Result && !IsReference< ExaminedType >::Result && !IsConstant< ExaminedType >::Result && !IsVolatile< ExaminedType >::Result;


// Check that the type is not a reference and it does not have any constant or volatile qualifiers
//
template< typename ExaminedType >
concept RawButPointerIsAllowed = !IsReference< ExaminedType >::Result && !IsConstant< ExaminedType >::Result && !IsVolatile< ExaminedType >::Result;


// Check that the type does not have any constant or volatile qualifiers
//
template< typename ExaminedType >
concept NotConstOrVolatile = !IsReference< ExaminedType >::Result && !IsConstant< ExaminedType >::Result && !IsVolatile< ExaminedType >::Result;



//  ******************************************************************************   BUILT IN   ***************************************************************************** //



// BUILT IN :


// Check if the template type object is a pointer to built in type ( int, double )
//
template< typename ExaminedType >
concept PointerToBuiltIn = IsBuiltIn< ExaminedType >::Result && IsPointer< ExaminedType >::Result;


// Check if the template type object is a reference to built in type ( int, double )
//
template< typename ExaminedType >
concept ReferenceToBuiltIn = IsBuiltIn< ExaminedType >::Result && IsReference< ExaminedType >::Result;


// Check if the template type object is a rvalue to built in type ( int, double ) reference
//
template< typename ExaminedType >
concept RvalueReferenceToBuiltIn = IsBuiltIn< ExaminedType >::Result && IsRvalueReference< ExaminedType >::Result;


// Check if the template type object is a built in type ( int, double ). The type must be non pointer, non reference and without 'const' or 'volatile'
// qualifiers
//
template< typename ExaminedType >
concept BuiltIn = IsBuiltIn< ExaminedType >::Result;


// Check if the template type object is a built in type ( int, double ) and with size in bytes which is less than 8. The type must be non
// pointer, non reference and without 'const' or 'volatile' qualifiers
//
template< typename ExaminedType >
concept BuiltInAndSizeLessThanEightBytes = IsBuiltIn< ExaminedType >::Result && ( sizeof( ExaminedType ) < 8 );


// Check if the template type object is a built in type ( int, double ) and with size in bytes which is exactly 8. The type must be non
// pointer, non reference and without 'const' or 'volatile' qualifiers
//
template< typename ExaminedType >
concept BuiltInAndSizeOfEightBytes = IsBuiltIn< ExaminedType >::Result && ( sizeof( ExaminedType ) == 8 );


// NOT BUILT IN ( USER DEFINED ) :


// Check if the template type object is a signed numeric pointer
//
template< typename ExaminedType >
concept PointerToNonBuiltIn = !IsBuiltIn< ExaminedType >::Result && IsPointer< ExaminedType >::Result;


// Check if the template type object is a signed numeric reference
//
template< typename ExaminedType >
concept ReferenceToNonBuiltIn = !IsBuiltIn< ExaminedType >::Result && IsReference< ExaminedType >::Result;


// Check if the template type object is a signed numeric rvalue reference
//
template< typename ExaminedType >
concept RvalueReferenceToNonBuiltIn = !IsBuiltIn< ExaminedType >::Result && IsRvalueReference< ExaminedType >::Result;


// Check if the template type object is a signed numeric. The type must be non pointer, non reference and without 'const' or 'volatile'
// qualifiers
//
template< typename ExaminedType >
concept NotBuiltIn = !IsBuiltIn< ExaminedType >::Result;


// BUILT IN AND NOT BUILT IN ( USER DEFINED ) COMBINED :


// Check if the template type object is a signed numeric. The type must be non pointer, non reference and without 'const' or 'volatile'
// qualifiers
//
template< typename ExaminedType >
concept NotBuiltInOrBuiltInAndSizeOfEightBytes = !IsBuiltIn< ExaminedType >::Result || BuiltInAndSizeOfEightBytes< ExaminedType >;



//  ******************************************************************************   NUMERIC   ****************************************************************************** //



// Create the concepts that can be used to ensure that the template type has some numeric property, like signed or unsigned :


// SIGNED NUMERIC :


// Check if the template type object is a signed numeric pointer
//
template< typename ExaminedType >
concept PointerToSignedNumeric = IsSignedNumeric< ExaminedType >::Result && IsPointer< ExaminedType >::Result;


// Check if the template type object is a signed numeric reference
//
template< typename ExaminedType >
concept ReferenceToSignedNumeric = IsSignedNumeric< ExaminedType >::Result && IsReference< ExaminedType >::Result;


// Check if the template type object is a signed numeric rvalue reference
//
template< typename ExaminedType >
concept RvalueReferenceToSignedNumeric = IsSignedNumeric< ExaminedType >::Result && IsRvalueReference< ExaminedType >::Result;


// Check if the template type object is a signed numeric. The type must be non pointer, non reference and without 'const' or 'volatile'
// qualifiers
//
template< typename ExaminedType >
concept SignedNumeric = IsSignedNumeric< ExaminedType >::Result;


// UNSIGNED NUMERIC :


// Check if the template type object is a signed numeric pointer
//
template< typename ExaminedType >
concept PointerToUnsignedNumeric = IsUnsignedNumeric< ExaminedType >::Result && IsPointer< ExaminedType >::Result;


// Check if the template type object is an unsigned numeric reference
//
template< typename ExaminedType >
concept ReferenceToUnsignedNumeric = IsUnsignedNumeric< ExaminedType >::Result && IsReference< ExaminedType >::Result;


// Check if the template type object is an unsigned numeric rvalue reference
//
template< typename ExaminedType >
concept RvalueReferenceToUnsignedNumeric = IsUnsignedNumeric< ExaminedType >::Result && IsRvalueReference< ExaminedType >::Result;


// Check if the template type object is an unsigned numeric. The type must be non pointer, non reference and without 'const' or 'volatile'
// qualifiers
//
template< typename ExaminedType >
concept UnsignedNumeric = IsUnsignedNumeric< ExaminedType >::Result;


// NUMERIC :


// Check if the template type object is a numeric pointer
//
template< typename ExaminedType >
concept PointerToNumeric = IsNumeric< ExaminedType >::Result && IsPointer< ExaminedType >::Result;


// Check if the template type object is a numeric reference
//
template< typename ExaminedType >
concept ReferenceToNumeric = IsNumeric< ExaminedType >::Result && IsReference< ExaminedType >::Result;


// Check if the template type object is a numeric rvalue reference
//
template< typename ExaminedType >
concept RvalueReferenceToNumeric = IsNumeric< ExaminedType >::Result && IsRvalueReference< ExaminedType >::Result;


// Check if the template type object is a numeric. The type must be non pointer, non reference and without 'const' or 'volatile'
// qualifiers
//
template< typename ExaminedType >
concept Numeric = IsNumeric< ExaminedType >::Result;



//  ******************************************************************************   MIX   ****************************************************************************** //



// Check if the template type is raw (only pointer allowed) and numeric 
//
template< typename ExaminedType >
concept RawButPointerIsAllowedAndNumeric = RawButPointerIsAllowed< ExaminedType > && Numeric< ExaminedType >;



}  //  Namespace Concepts


}  //  Namespace Universe