#ifndef VALIDANDINVALID_HPP
#define VALIDANDINVALID_HPP


#include "../../../CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe
{




	// When a type is forward declared, all the compiler knows is that this type exists. It does not know its size, members or methods. This is why its
	// called incomplete type. Therefore, it can not be used to declare a variable, member or base class since the compiler would need the layout of the
	// type. In other words, it can not be used for anything that requires information on the specific type. What can be done is declaring pointer and
	// reference to the incomplete type. The pointer and refernce can act as a variable, argument to a method or as the return type.
	//
	// Forward declarations :
	//
	//  NONE
	//



	// The content of this file is 2 types, with different size. When of the ways to check requirements on types, is by creating a set of overloaded
	// functions, where one will check some requirement on the type, and the other is the fallback in case the requirement is not valid on the current
	// type. In this set of functions to know which verison was choosen, the function that checks the requirement on the type will return the 'Valid'
	// type, and the other will return the 'Invalid' type. This way the type can be compared, or the size of it can be taken, to know which version was
	// choosen, and as a result know if the requirement is valid for the type



	// The 'Valid' type
	using Valid = UnsignedInteger8bits;


	// The 'No' type
	class Invalid
	{
	private:

		UnsignedInteger64bits member_padding;

	};  //  Class Invalid









}  //  Namespace Universe



#endif  // VALIDANDINVALID_HPP