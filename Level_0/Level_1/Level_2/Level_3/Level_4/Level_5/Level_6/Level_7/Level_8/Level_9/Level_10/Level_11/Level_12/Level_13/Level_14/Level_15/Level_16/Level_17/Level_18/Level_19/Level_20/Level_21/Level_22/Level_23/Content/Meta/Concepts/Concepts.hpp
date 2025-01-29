namespace Universe
{


namespace Concepts
{




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************************************   CONCEPTS   ******************************************************************************* //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //




//  ************************************************************************   UNIVERSAL REFERENCE   ************************************************************************ //



// Check if the template type object is a universal reference that points to 'Language::String". Universal reference means either constant lvalue 
// reference or an rvalue reference, which means implemented the operator '()'. The check is done, by
//
template< typename ExaminedType >
concept String = CompareTypes< typename RemoveAttributes< ExaminedType >::Type, Language::String >::Result == true;



}  //  Namespace Concepts


}  //  Namespace Universe