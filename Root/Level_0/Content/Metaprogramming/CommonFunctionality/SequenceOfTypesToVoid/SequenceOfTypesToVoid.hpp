#ifndef SEQUENCEOFTYPESTOVOID_HPP
#define SEQUENCEOFTYPESTOVOID_HPP


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



	// The following type definition maps a sequence of any types to the type 'void'. It is used to detect ill-formed types in substitution is not an error
	// context, and can also detect validity of an expression :
	//
	//		template< typename, typename = SequenceOfTypesToVoid<> >
	//		class HasMember_Type : public IntegralConstant< Boolean, false >
	//		{};
	//
	//		template< typename T >
	//		class HasMember_Type< T, SequenceOfTypesToVoid< typename T::Type > : public IntegralConstant< Boolean, true >
	//		{};
	//
	// This example helps check if a type conatains inside it a member with the name 'Type'. The next example will show how to check if the pre-increment
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



#endif  // SEQUENCEOFTYPESTOVOID_HPP