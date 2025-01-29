namespace Universe
{



// Forward declare the character object to allow creating concepts based on it before its declaration and implementation
namespace Language
{

	class Character;


	template< typename MemoryManagerType >
	class StringImplementation;


}



namespace Concepts
{




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************************************   CONCEPTS   ******************************************************************************* //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



//  ***********************************************************************   CONVERTIBLE TO STRING   *********************************************************************** //



// Check if the template type object is convertible to string. The check is done, by trying to compile the following code, which contains a call to all
// the required methods that a class needs to implement in order to be considered as convertible to string
//
template< typename ExaminedType >
concept ConvertibleToStringObject = requires( ExaminedType instance )
{

	{ instance.ToString() } -> SameAs< Language::StringImplementation< Memory::MainMemoryManager > >;

	{ instance.NumberOfCharactersRequiredToStoreAsString() } -> SameAs< LargestUnsignedInteger >;

	{ instance.SetAsString( nullptr ) } -> SameAs< LargestUnsignedInteger >;

};


// Check if the template type object is convertible to string. Currently the supported options are :
//
//	1. Integer
//	2. Floating point
//	3. Pointer
//	4. Class that implements the 'ConvertibleToString' interface
//	5. The class 'Character'
//
template< typename ExaminedType >
concept ConvertibleToString = Integer< ExaminedType > || FloatingPoint< ExaminedType > || Pointer< ExaminedType > || ConvertibleToStringObject< ExaminedType > || SameAs< ExaminedType, Language::Character >;



}  //  Namespace Concepts


}  //  Namespace Universe