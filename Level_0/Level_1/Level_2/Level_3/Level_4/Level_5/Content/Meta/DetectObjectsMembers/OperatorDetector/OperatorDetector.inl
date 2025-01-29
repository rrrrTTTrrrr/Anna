// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************************   OperatorDetector for operator '()'   ***************************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



template< typename ObjectToDetectOperatorInsideType >
constexpr Boolean OperatorDetector_RoundBrackets< ObjectToDetectOperatorInsideType >::Result()
{
	// Return the constant expression value that store if the operator exist or not
	return ( member_containsOperatorOrNot );
}




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************************   OperatorDetector for operator '[]'   ***************************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



template< typename ObjectToDetectOperatorInsideType >
constexpr Boolean OperatorDetector_SquareBrackets< ObjectToDetectOperatorInsideType >::Result()
{
	// Return the constant expression value that store if the operator exist or not
	return ( member_containsOperatorOrNot );
}




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************************   OperatorDetector for operator '~'   ****************************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



template< typename ObjectToDetectOperatorInsideType >
constexpr Boolean OperatorDetector_BitwiseNot< ObjectToDetectOperatorInsideType >::Result()
{
	// Return the constant expression value that store if the operator exist or not
	return ( member_containsOperatorOrNot );
}




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************************   OperatorDetector for operator '!'   ****************************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



template< typename ObjectToDetectOperatorInsideType >
constexpr Boolean OperatorDetector_LogicalNot< ObjectToDetectOperatorInsideType >::Result()
{
	// Return the constant expression value that store if the operator exist or not
	return ( member_containsOperatorOrNot );
}




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************************   OperatorDetector for operator '->'   ***************************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



template< typename ObjectToDetectOperatorInsideType >
constexpr Boolean OperatorDetector_StructureDereference< ObjectToDetectOperatorInsideType >::Result()
{
	// Return the constant expression value that store if the operator exist or not
	return ( member_containsOperatorOrNot );
}



}  //  Namespace Universe