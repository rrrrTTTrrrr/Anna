namespace Universe
{



// The following type definition maps a sequence of any types to the type 'void'. It is used to detect ill-formed types in substitution is not an error
// context, and can also detect validity of an expression :
//
//		template< typename, typename = SequenceOfTypesToVoid<> >
//		class HasMember_Type : public IntegralConstant< Boolean, false >
//		{};
//
//		template< typename T >
//		class HasMember_Type< T, SequenceOfTypesToVoid< typename T::member_name > : public IntegralConstant< Boolean, true >
//		{};
//
// This example helps check if a type conatains inside it a member with the name 'member_name'. The next example will show how to check if the pre-increment
// operator is overladed in a type :
//
//		template< typename, typename = SequenceOfTypesToVoid<> >
//		class HasMember_PreIncrement : public IntegralConstant< Boolean, false >
//		{};
//
//		template< typename T >
//		class HasMember_PreIncrement< T, SequenceOfTypesToVoid< decltype( ++std::declval< T& >() ) > : public IntegralConstant< Boolean, true >
//		{};
//
template< typename... >
using SequenceOfTypesToVoid = void;



}  //  Namespace Universe