#ifndef  METAPROGRAMMINGMACROS_HPP
#define  METAPROGRAMMINGMACROS_HPP


#include "../../CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  // Macro DEBUG_TOOL, Macro COMMA
#include "../Types/TypeRemoval/RemoveReference/RemoveReference.hpp"  //  Class RemoveReference


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe
{



	// This is used when only declaring the object in this source file will be enough to pass compilation. The implementation is given to the compiler through the
	// cpp source file that the object is nested within
	//
	// Forward declarations :
	//
	//  NONE
	//



// ************************************************************************************************************************************************************************** //
// **                                                                              MOVE SEMANTICS                                                                          ** //
// ************************************************************************************************************************************************************************** //



    // This macro should be used when an instance data will be not needed anymore. Then another instance can instaed of copying all the data can just take the data instead
    // which makes the process usually much faster
    #define MOVE( Instance ) static_cast< typename RemoveReference< decltype( Instance ) >::Type&& >( Instance )





}  //  Namespace Universe



#endif  // METAPROGRAMMINGMACROS_HPP