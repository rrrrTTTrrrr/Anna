namespace Universe
{


namespace Concepts
{



// Check if the template type object is an floating point. The type must be non pointer, non reference and without 'const' or 'volatile'
// qualifiers
//
template< typename ExaminedType >
concept MemoryHandler = CompareRegardlessOfTemplateArguments< ExaminedType, Memory::Vector< LargestUnsignedInteger > >::Result || CompareRegardlessOfTemplateArguments< ExaminedType, Memory::SingleLinkedList< LargestUnsignedInteger > >::Result || CompareRegardlessOfTemplateArguments< ExaminedType, Memory::DoubleLinkedList< LargestUnsignedInteger > >::Result || CompareRegardlessOfTemplateArguments< ExaminedType, Memory::PagesArray< LargestUnsignedInteger > >::Result;



}  //  Namespace Concepts


}  //  Namespace Universe