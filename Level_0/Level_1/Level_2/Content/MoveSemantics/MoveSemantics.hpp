namespace Universe
{




// ************************************************************************************************************************************************************************** //
// ************************************************************************************************************************************************************************** //
// **														   						C/C++ LANGUAGE                                                                         ** //
// ************************************************************************************************************************************************************************** //
// ************************************************************************************************************************************************************************** //




// ************************************************************************************************************************************************************************** //
// **                                                                              MOVE SEMANTICS                                                                          ** //
// ************************************************************************************************************************************************************************** //



// This function should be used when an instance data will be not needed anymore. Then another instance can instaed of copying all the data can just take the data instead
// which makes the process usually much faster. This macro can handle with reference types as well
template< typename AnyType >
EnsureRetrunValueIsUsed constexpr typename RemoveReference< AnyType >::Type&& TakeResourcesAndLeaveInstanceInDefaultState( AnyType&& instance )
{ 
	return ( static_cast< typename RemoveReference< AnyType >::Type&& >( instance ) ); 
}



// *********************************************************************   REFERENCE COLLAPSING RULES   ********************************************************************* //



// Before C++11, references to references are ill-formed in the C++ language. In C++11 the rules of reference collapsing apply when reference
// to reference is used through one of the following contexts :
//
//	1. A 'decltype' specifier
//	2. A 'typeded' or 'using' name
//	3. A template type parameter
//
// The following is legit :
//
//		using Type = int&;
//
//		using TypeReference = Type&;
//
//		TypeReference variable;
//
// The actual type for each case is listed below :
//
//			Type 			TypeReference			ResultType
//
//			 A                    T  					 A
//			 A 					  T& 					 A&
//			 A 					  T&&                    A&&
//			 A& 				  T                      A&
//			 A&					  T&                     A&
//			 A& 				  T&&                    A&
//			 A&& 				  T                      A&&
//			 A&& 				  T&                     A&
//			 A&& 				  T&&                    A&&
//
// Note - only both 'Type' and 'TypeReference' are reference, then the reference collapsing rules apply. The general rule in this table is that
// when both types are references, the only case that the result can end up as an rvalue reference is if both are rvalue reference.


// The reference collapsing rules exist for one reason - to allow perfect forwarding to work. "Perfect" forwarding means to effectively forward
// parameters as if the user had called the function directly ( minus elision, which is broken by forwarding ). There are three kinds of values
// the user could pass - lvalues, xvalues and prvalues. There are three ways that the receiving location can take a value - by value, by constant
// or non constant lvalue reference and by constant or non constant rvalue reference.
//
// The following function will be used for the explanation :
//
//		template< class Type >
//		void Forward( T&& instance )
//		{
//			Call( std::forward< Type >( instance ) );
//		}
//
//
// By value :
//
// If 'Call' takes its parameter by value, then a copy/move must happen into that parameter. Which one depends on what the incoming value is. If the
// incoming value is an lvalue, then it must copy the lvalue. If the incoming value is an rvalue ( which collectively are xvalues and prvalues ), then 
// it must move from it. If the function 'forward' is called with an lvalue, C++'s type deduction rules mean that the type will be deduced as 'Type&'.
// Obviously if the lvalue is declared 'const', it will be deduced as 'const Type&'. The reference collapsing rules mean that 'Type& &&' becomes 'Type&'
// for an lvalue reference. Which is exactly what is needed to invoke 'Call'. Calling it with lvalue reference will force copy, exactly as if it was
// called directly. If 'Forward' is called with an rvalue then the type will be deduced as 'Type'. The reference collapsing rules give us 'Type &&',
// which provokes a move/copy, which is almost exactly as if the function was called directly ( minus elision ).
//
// By lvalue reference :
//
// If 'Call' takes its value by lvalue reference, then it should only be callable when the user uses lvalue parameters. If it's a constant lvalue 
// reference, then it can be callable by anything ( lvalue, xvalues, prvalues ). If 'Forward' is called with an lvalue, the result is 'Type&'. This
// will bind to a non constant lvalue reference. If it is a constant lvalue the result is 'const Type&', which will only bind to a constant lvalue
// reference argument in 'Call'. If 'Forward' is called with an xvalue, the result is 'Type&&'. This will not allow to call a function that takes
// a non constant lvalue, as an xvalue cannot bind to a non constant lvalue reference. If 'Forward' is called with a prvalue, again the result is
// 'Type&&', so everything works as before. Temporary can not be passed to a function that takes a non constant lvalue, so the forwarding function
// will choke in the attempt to do so!
//
// By rvalue reference :
//
// If 'Call' takes its argument by rvalue reference, then it should only be callable when the user uses xvalue or rvalue parameters. If 'Forward'
// is called with an lvalue, the result is 'Type&'. This will not bind to an rvalue reference parameter, so a compile error results. A 'const Type&'
// also won't bind to an rvalue reference parameter, so it still fails. And this is exactly what would happen it 'Call' was invoked directly.
// If 'Forward' is called with an xvalue, the result is 'Type&&', which works, while constant and volatile qualification still matters, the same
// goes for using prvalues


// The next 2 functions are needed where universal references exist. To understand universal references, the following snippet will be used :
//
//		template< typename Type >
//		void Foo( Type&& instance )
//		{
//			...
//		}
//
// For a reference to be consider as universal reference, two conditions must apply. The type itself must be in a deduced context, in this
// case the function is a template. And the other one, is that it must be declared with the rvalue reference sign '&&'. Now, the template 
// type 'Type' will be the same no matter what, if it's an integer or double it will stay the same. The thing that can change is if the 
// ending type will be an lvalue reference or an rvalue reference, and that depends on the template argument type. Eventually the type is
// choosen according to the reference collapsing rules.
//
// The last thing that needs to be addressed, is why after that the type was set by the compiler, and it ended up as an rvalue reference,
// why does not the instance is passed as an rvalue to the called function? For each type it is known that the following will work :
//
//		void Foo( int& instance )
//		{
//			...
//		}
//
//		void Foo( int* instance )
//		{
//			...
//		}
//
//		template< typename Type >
//		void Foott( Type instance )
//		{
//			Foo( instance );
//		}
//
// If the type is a reference then the first version of 'Foo' should be called, and if it's a pointer then the second version. But in
// the following case :
//
//		void Foo( int& instance )
//		{
//			...
//		}
//
//		void Foo( int&& instance )
//		{
//			...
//		}
//
//		template< typename Type >
//		void Foott( Type instance )
//		{
//			Foo( instance );
//		}
//
// No matter what type will be passed, only the first version that accept lvalue reference will be called. It is true, the type of the 
// instance can be an rvalue reference, but when entering the function, instance is a variable with a name, which automatically makes
// it an lvalue	variable! This is important! Every variable with a name, although declared as rvalue reference, is an lvalue!
//
// To sum it up, although the user called the move operation on an instance, and the function that accept an rvalue reference was called,
// inside the function that variable has a name and therefore it is an lvalue. In order to forward it as an rvalue, it must be explicitly
// casted again into an rvalue! This the purpose of the following functions, to ensure that instance will propagte through the function
// calls with the required type


// In order to use the following forward method on a template pack use the following syntax :
//
//		template< typename... TemplatePack >
//		void Foo( TemplatePack... arguments )
//		{
//			ForwardUniversalReference< TemplatePack >( arguments )... );
//		}


// Important note :
//
// For the following cases :
//
//		template< typename UniversalReferenceType >
//		void Function( UniversalReferenceType instance )
//
//		template< typename UniversalReferenceType >
//		void Function( UniversalReferenceType&& instance )
//
// As it seems at first redundent to use the addition of the rvalue reference '&&', the difference is that in the first case it will copy by
// value, and in the second case it will pass as reference. Then to ensure pass by reference in this case the rvalue reference sign must be
// present as well



template< typename UniversalReferenceType >
EnsureRetrunValueIsUsed constexpr UniversalReferenceType&& ForwardUniversalReference( typename RemoveReference< UniversalReferenceType >::Type& instance )
{ 
	return ( static_cast< UniversalReferenceType&& >( instance ) );
}


template< typename UniversalReferenceType >
EnsureRetrunValueIsUsed constexpr UniversalReferenceType&& ForwardUniversalReference( typename RemoveReference< UniversalReferenceType >::Type&& instance )
{
	// Ensure that this method will not convert an rvalue to an lvalue. The reason :
	//
	// Why not to use this function to Convert an Rvalue to an Lvalue?
	//
	// std::forward should not be used to convert an rvalue to an lvalue because std::forward is designed to preserve the value category of a
	// parameter in a template function, not to change it. Misusing it in this way can result in undefined behavior, compilation errors, or 
	// logical errors in your program.
	//
	// Attempting to forward an rvalue as an lvalue can lead to trying to bind an rvalue to an lvalue reference, which is not allowed and will
	// cause a compilation error.
	//
	// For exmaple what not to do :
	//
	//	void foo( int& x ) 
	//	{
	//	    std::cout << "foo called with lvalue\n";
	//	}
	//
	//	int main() 
	//	{
	//	    foo( ForwardUniversalReference< int& >( 5 ) );  // Incorrect: trying to forward an rvalue as an lvalue
	//	}
	//
	static_assert( IsLvalueReference< UniversalReferenceType >::Result == false, "Forward must not be used to convert an rvalue to an lvalue" );

	return ( static_cast< UniversalReferenceType&& >( instance ) );
}


template< typename UniversalReferenceContainerType, typename DataType >
EnsureRetrunValueIsUsed constexpr typename ChooseBetweenTwoTypes< CompareTypes< UniversalReferenceContainerType&&, typename RemoveReference< UniversalReferenceContainerType >::Type& >::Result(), DataType&, DataType&& >::Type ForwardUniversalReferenceDataAccordingToContainerType( typename RemoveReference< DataType >::Type& dataInstance )
{
	return ( static_cast< typename ChooseBetweenTwoTypes< CompareTypes< UniversalReferenceContainerType&&, typename RemoveReference< UniversalReferenceContainerType >::Type& >::Result(), DataType&, DataType&& >::Type >( dataInstance ) );
}



}  //  namespace Universe