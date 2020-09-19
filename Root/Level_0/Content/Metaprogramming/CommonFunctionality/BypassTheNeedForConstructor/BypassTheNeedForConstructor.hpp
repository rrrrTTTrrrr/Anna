#ifndef BYPASSTHENEEDFORCONSTRUCTOR_HPP
#define BYPASSTHENEEDFORCONSTRUCTOR_HPP


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



	// Converts any type to a reference type, making it possible to use member functions in 'decltype' expressions without the need to go through 
	// constructors. 'declval' is commonly used in templates where acceptable template parameters may have no constructor in common, but have the 
	// same member functions whose return type is needed. Note that 'declval' can only be used in unevaluated contexts and is not required to be
	// defined, it is an error to evaluate an expression that contains this function. The return type of is 'Type&&' an rvalue reference unless
	// the template type is void, in which case the return type is the also void.
	//
	//		template< typename T >
	//		typename std::add_rvalue_reference< T >::type declval() noexcpet;
	//
	// Usage example :
	//
	//		class WithDefaultConstructor
	//		{
	//			
	//			int Foo() const
	//			{
	//				return ( 1 );
	//			}
	//
	//		}
	//
	//		class WithoutDefaultConstructor
	//		{
	//			
	//			WithoutDefaultConstructor( const WithoutDefaultConstructor& )
	//			{}	
	//
	//			int Foo() const
	//			{
	//				return ( 1 );
	//			}
	//
	//		}
	//
	//
	//		int main()
	//		{
	//			decltype( WithDefaultConstructor().Foo() ) variable1 = 1;								// Type of variable is 'int'
	//
	//			decltype( WithoutDefaultConstructor().Foo() ) variable2 = 6;							// Error - no default constructor
	//
	//			decltype( std::declval< WithoutDefaultConstructor >().Foo() ) variable3 = varaible1;	// Type of varaible is 'int'
	//		}



    // Method Information :
    //
    //  Description :
    //
    //      Use this method in a 'decltype' parentheses to allow taking the return value of object members, without the need for constructors. It should
    //		not be used in any other context, it does not contain a definition only a declaration
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          NONE
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      An rvalue reference of the given template type
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
	template< typename Type, typename TypeAsRvalueReference = Type&& >
	TypeAsRvalueReference BypassTheNeedForConstructor();








}  //  Namespace Universe



#endif  // BYPASSTHENEEDFORCONSTRUCTOR_HPP