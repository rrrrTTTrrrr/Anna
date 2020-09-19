#ifndef TUPLE_HPP
#define TUPLE_HPP


#include "../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA, Macro CompileTimeAssert
#include "../../../../../../Content/Metaprogramming/MetaprogrammingMacros/MetaprogrammingMacros.hpp"  //  Macro MOVE
#include "../../../../../../Content/Metaprogramming/CommonFunctionality/SubstitutionFailureIsNotAnError/ProvideTypeOnlyIfAssertionIsTrue/ProvideTypeOnlyIfAssertionIsTrue.hpp"  //  Class ProvideTypeOnlyIfAssertionIsTrue
#include "../../../../../../Content/Metaprogramming/CommonFunctionality/AssertAllTrue/AssertAllTrue.hpp"  //  Class AssertAllTrue
#include "../../../../../../Content/Metaprogramming/Types/TypesHolders/TypesHolder/TypesHolder.hpp"  //  Class TypesHolder
#include "../../../../../../Content/Metaprogramming/Types/TypesHolders/ConstantTypesHolder/ConstantTypesHolder.hpp"  //  Class ConstantTypesHolder
#include "../../../../../../Content/Metaprogramming/Types/AssertConditionsOnParameterPack/AssertConditionsOnParameterPack_OR.hpp"  //  Typedef 
#include "../../../../../../Content/Metaprogramming/Types/AssertConditionsOnParameterPack/AssertConditionsOnParameterPack_AND.hpp"  //  Typedef DoesParameterPackContainAllTypesWithDefaultConstructor
#include "../../../../../../Content/Metaprogramming/Types/TypeCheck/Reference/TypeCheck_NonConstant_LvalueReference/TypeCheck_NonConstant_LvalueReference.hpp"
#include "../../../../Content/Random/Generator/Generator.hpp"  //  Class Generator



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



	// VARIADIC TEMPLATES :
	//
	// Prior to C++11, the only way to write functions that take an arbitrary number of arguments was to use variadic functions, with the ellipsis syntax (...) and the 
	// accompanying va_ family of macros. It is cumbersome using it. In addition to being type unsafe ( all type resolution has to be done explicitly with casts in 
	// va_arg, at runtime ), it's also tricky to get right.
	//
	// The biggest problem with this approach is leaving something that is clearly known at compile-time, to run-time. When writing a variadic function, all the ways 
	// it's going to be used is not known. But when the compiler puts the whole program together, it does know. It sees perfectly well all the invocations of the function 
	// throughout the program, and all the possible argument types it gets passed ( types are, after all, resolved at compile-time in C++ ).
	//
	// Variadic templates :
	//
	// One of the new features of C++11 is variadic templates. Finally, there's a way to write functions that take an arbitrary number of arguments in a type-safe way 
	// and have all the argument handling logic resolved at compile-time, rather than run-time. Variadic templates can be used for much more than just functions that 
	// take an arbitrary number of arguments.
	//
	// Basic example, implementing a function that adds all of its arguments together :
	//
	// 		template< typename T >
	// 		T adder( T v ) 
	//		{
	//   		return v;
	// 		}
	//
	// 		template< typename T, typename... Args >
	// 		T adder( T first, Args... args ) 
	//		{
	//   		return first + adder( args... );
	// 		}
	//
	// And here are a couple of ways we could call it:
	//
	// 		long sum = adder( 1, 2, 3, 8, 7 );
	//
	// 		std::string s1 = "x", s2 = "aa", s3 = "bb", s4 = "yy";
	// 		std::string ssum = adder( s1, s2, s3, s4 );
	//
	// adder will accept any number of arguments, and will compile properly as long as it can apply the + operator to them. This checking is done by the compiler, at 
	// compile time. There's nothing magical about it - it follows C++'s usual template and overload resolution rules.
	//
	// 'typename... Args' is called a template parameter pack, and 'Args... args' is called a function parameter pack ( Args is, of course, a completely arbitrary name 
	// and could be anything else ). Variadic templates are written just the way recursive code does - a base case, and a general case which "recurses". The recursion 
	// itself happens in the call adder( args... ). Note how the general adder is defined - the first argument is peeled off the template parameter pack into type T 
	// ( and accordingly, argument first ). So with each call, the parameter pack gets shorter by one parameter. Eventually, the base case is encountered.
	//
	// To get a better feel for the process, one can use the __PRETTY_FUNCTION__ macro. If we insert the following as the first line in both versions of adder above:
	//
	// 		std::cout << __PRETTY_FUNCTION__ << "\n";
	//
	// And then execute adder(1, 2, 3, 8, 7), we'll see:
	//
	// 		T adder(T, Args...) [T = int, Args = <int, int, int, int>]
	// 		T adder(T, Args...) [T = int, Args = <int, int, int>]
	// 		T adder(T, Args...) [T = int, Args = <int, int>]
	// 		T adder(T, Args...) [T = int, Args = <int>]
	// 		T adder(T) [T = int]
	//
	// Some simple variations
	//
	// When reading about C++ template meta-programming, one often hears about "pattern matching" and how this part of the language constitutes a fairly complete 
	// compile-time functional language.
	//
	// The example shown above is very basic - template arguments are peeled off one by one until the base case is hit. Here's a somewhat more interesting display 
	// of pattern matching :
	//
	// 		template< typename T >
	// 		bool pair_comparer( T a, T b ) 
	//		{
	//   		return a == b;
	// 		}
	//
	// 		template< typename T, typename... Args >
	// 		bool pair_comparer( T a, T b, Args... args ) 
	//		{
	//   		return a == b && pair_comparer( args... );
	// 		}
	//
	// pair_comparer accepts any number of arguments and returns true if and only if they are pair-wise equal. The types are not enforced - everything that can be 
	// compared goes. For example:
	//
	// 		pair_comparer( 1.5, 1.5, 2, 2, 6, 6 )
	//
	// Returns true. But if we change the second argument to just 1, this won't compile since a double and int are not the same type.
	//
	// More interestingly, pair_comparer will only work for an even number of arguments because they are peeled off in pairs and the base case compares two. The 
	// following :
	//
	// 		pair_comparer( 1.5, 1.5, 2, 2, 6, 6, 7 )
	//
	// Does not compile. The compiler complains that the base case expects 2 arguments but only 1 is provided. To fix this, we can add another variation of the function 
	// template :
	//
	// 		template< typename T >
	// 		bool pair_comparer( T a ) 
	//		{
	//   		return false;
	// 		}
	//
	// Here, we force all odd-numbered sequences of arguments to return false, because when only a single argument is left this version is matched. Note that 
	// pair_comparer forces both members of the compared pair to be of the exact same type. 
	//
	// Performance :
	//
	// If you're concerned with the performance of code that relies on variadic templates, worry not. As there's no actual recursion involved, all we have is a 
	// sequence of function calls pre-generated at compile-time. This sequence is, in practice, fairly short ( variadic calls with more than 5-6 arguments are rare ). 
	// Since modern compilers are aggressively inlining code, it's likely to end up being compiled to machine code that has absolutely no function calls. What you end 
	// up with, actually, is not unlike loop unrolling.
	//
	// Compared to the C-style variadic functions, this is a marked win, because C-style variadic arguments have to be resolved at runtime. The va_ macros are literally 
	// manipulating the runtime stack. Therefore, variadic templates are often a performance optimization for variadic functions.
	//
	// Type-safe variadic functions :
	//
	// It's pretty obvious how variadic templates enable us to write type safe functions. In the case of printf, when the implementation reaches a new formatting 
	// directive it can actually assert the type of the argument passed. This assertion won't fire at compile-time, but it will fire - and a nice error message can be 
	// generated instead of undefined behavior.
	//
	// Varidic data structures :
	//
	// This use-case is much more interesting, IMHO, because it was something that just wasn't possible prior to introduction of C++11, at least without considerable 
	// hackery. Custom data structures have compile-time defined fields. They can represent types that grow at runtime ( std::vector, for example ) but if you want to 
	// add new fields, this is something the compiler has to see. Variadic templates make it possible to define data structures that could have an arbitrary number of 
	// fields, and have this number configured per use. The prime example of this is a tuple class.
	//
	// Let's start with the type definition :
	//
	// 		template < class... Ts > struct tuple {};
	//
	// 		template < class T, class... Ts >
	// 		class tuple< T, Ts... > : tuple< Ts... > 
	//		{
	//		public:
	//
	//   		tuple( T t, Ts... ts ) : tuple<Ts...>( ts... ), tail( t ) {}
	//
	//   		T tail;
	// 		};
	//
	// We start with the base case - the definition of a class template named tuple, which is empty. The specialization that follows peels off the first type from the
	// parameter pack, and defines a member of that type named tail. It also derives from the tuple instantiated with the rest of the pack. This is a recursive definition 
	// that stops when there are no more types to peel off, and the base of the hierarchy is an empty tuple. To get a better feel for the resulting data structure, let's 
	// use a concrete example :
	//
	// 		tuple< double, uint64_t, const char* > t1(12.2, 42, "big");
	//
	// Ignoring the constructor, here's a pseudo-trace of the tuple structures created:
	//
	// 		class tuple< double, uint64_t, const char* > : tuple< uint64_t, const char* > 
	//		{
	//   		double tail;
	// 		}
	//
	// 		class tuple< uint64_t, const char* > : tuple< const char* > 
	//		{
	//   		uint64_t tail;
	// 		}
	//
	// 		class tuple< const char* > : tuple 
	//		{
	//   		const char* tail;
	// 		}
	//
	// 		class tuple {
	// 		}
	//
	// The layout of data members in the original 3-element tuple will be:
	//
	// 		[const char* tail, uint64_t tail, double tail]
	//
	// Note that the empty base consumes no space, due to empty base optimization
	//
	// So, the struct definition above lets us create tuples, but there's not much else we can do with them yet. The way to access tuples is with the get function 
	// template, so let's see how it works. First, we'll have to define a helper type that lets us access the type of the k-th element in a tuple :
	//
	// 		template <class T, class... Ts>
	// 		class elem_type_holder<0, tuple<T, Ts...>> 
	//		{
	//   		typedef T type;
	// 		};
	//
	// 		template <size_t k, class T, class... Ts>
	// 		class elem_type_holder<k, tuple<T, Ts...>> 
	//		{
	//   		typedef typename elem_type_holder<k - 1, tuple<Ts...>>::type type;
	// 		};
	//
	// elem_type_holder is yet another variadic class template. It takes a number k and the tuple type we're interested in as template parameters. Note that this is a 
	// compile-time template metaprogramming construct - it acts on constants and types, not on runtime objects. For example, given : 
	//
	//		elem_type_holder< 2, some_tuple_type >
	//
	// we'll get the following pseudo expansion :
	//
	// 		class elem_type_holder< 2, tuple< T, Ts... > > 
	//		{
	//   		typedef typename elem_type_holder< 1, tuple< Ts... > >::type type;
	// 		}
	//
	// 		class elem_type_holder< 1, tuple< T, Ts... > > 
	//		{
	//   		typedef typename elem_type_holder< 0, tuple< Ts... > >::type type;
	// 		}
	//
	// 		class elem_type_holder< 0, tuple< T, Ts... > > 
	//		{
	//   		typedef T type;
	// 		}
	//
	// So the call peels off two types from the beginning of the tuple, and sets its type to the type of the third one, which is what we need. Armed with this, we can 
	// implement get :
	//
	// 		template < size_t k, class... Ts >
	// 		typename std::enable_if< k == 0, typename elem_type_holder< 0, tuple< Ts... > >::type& >::type get( tuple< Ts... >& t ) 
	//		{
	//   		return t.tail;
	// 		}
	//
	// 		template < size_t k, class T, class... Ts >
	// 		typename std::enable_if< k != 0, typename elem_type_holder< k, tuple< T, Ts... > >::type& >::type get( tuple< T, Ts... >& t ) 
	//		{
	//   		tuple< Ts... >& base = t;
	//   		return get< k - 1 >( base );
	// 		}
	//
	// Here, enable_if is used to select between two template overloads of get - one for when k is zero, and one for the general case which peels off the first type 
	// and recurses, as usual with variadic function templates.
	//
	// Since it returns a reference, we can use get to both read tuple elements and write to them:
	//
	// 		tuple<double, uint64_t, const char*> t1(12.2, 42, "big");
	//
	// 		std::cout << "0th elem is " << get<0>(t1) << "\n";
	// 		std::cout << "1th elem is " << get<1>(t1) << "\n";
	// 		std::cout << "2th elem is " << get<2>(t1) << "\n";
	//
	// 		get<1>(t1) = 103;
	//
	// 		std::cout << "1th elem is " << get<1>(t1) << "\n";



    // In some situations, it can be useful ot generate sequences of numbers at compile time. This paragraph shows how to generate integer sequences with C++ templates, 
    // and gives an example how to use it.
    //
    // Compile Time Integer Sequences :
    //
    // Integer sequence look like the following :
    //
    //      sequence< 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 >
    //
    // This is the structure which holds sequences :
    //
    //      template< int ... Ns > 
    //      struct sequence 
    //      {};
    //
    // Now a way to generate sequences is needed. The signature is :
    //
    //      template< int ... Ns > 
    //      struct SequenceGenerator;
    //
    // Recursion case :
    //
    //      template< int I, int ... Ns >
    //      struct SequenceGenerator< I, Ns... >
    //      {
    //          // Take front most number of sequence, decrement it, and prepend it twice. First I - 1 goes into the counter, Second I - 1 goes into the sequence.
    //          using type = typename SequenceGenerator< I - 1, I - 1, Ns... >::type;
    //      };
    //
    // Recursion base case :
    //
    //      template< int ... Ns >
    //      struct SequenceGenerator< 0, Ns... >
    //      {
    //          using type = sequence< Ns... >;
    //      };
    //
    //      template< int N >
    //      using sequence_t = typename SequenceGenerator< N >::type;
    //
    // sequence_t’s purpose is solely carrying number sequences. Note that it is an empty class which is actually defined ( because it has an empty {} definition body ). 
    // This is important, because in some use cases it is going to be instantiated.
    //
    // Sequence generator is used to recursively generate the integer sequence.
    //
    // sequence_t is the using clause which represents the interface for the end user. Writing sequence_t<10> evaluates to the initial example with the numeric range 
    // going from 0 to 9.
    //
    // Usage Example, Unpacking Tuples for Function Calls :
    //
    // Imagine a function which takes a specific set of parameters with specific types:
    //
    //      void MyLove( double, float, int )
    //
    // And a std::tuple which carries exactly the same types as the arguments of the fucntion :
    //
    //      std::tuple< double, float, int > tuple
    //
    // In order to call the function with the values in the tuple, the following code can be used :
    //
    //      MyLove( std::get<0>(tup), std::get<1>(tup), std::get<2>(tup) )
    //
    // This is not too nice to read, and it is error prone, because it’s possible to use wrong indices. Such mistakes would even compile, if the type at the wrong 
    // index is the same, as the type at the right index.
    //
    // It would be nicer to have a function wrapper which has semantics like “Use this function and this tuple. Then automatically take all the tuple values out of 
    // the tuple, in order to call the function with them” :
    //
    //     unpack_and_call(f, tup);
    //
    // This is indeed possible since C++11. Let’s have a look how to implement that:
    //
    //      #include <iostream>
    //      #include <tuple>
    //
    //      using std::tuple;
    //
    //      static void func( double d, float f, int i )
    //      {
    //          std::cout << d << ", " << f << ", " << i << std::endl;    
    //      }
    //
    // The following code passes all parameters by value, for the sake of simplicity :
    //
    //      template< typename F, typename TUP, int ... INDICES >
    //      static void tuple_call_( F f, TUP tup, sequence< INDICES... > )
    //      {
    //          f( std::get< INDICES >( tup ) ... );   
    //      }
    //
    //      template< typename F, typename ... Ts >
    //      static void tuple_call( F f, tuple< Ts... > tup )
    //      {
    //          tuple_call_( f, tup, sequence_t< sizeof...( Ts ) >{} );
    //      }
    //
    //      int main()
    //      {
    //          func( 1.0, 2.0, 3 ); 
    //
    //          tuple< double, float, int > tup {1.0, 2.0, 3};
    //          tuple_call( func, tup ); // same effect
    //      }
    // 
    // func is the example function with its own specific signature. It has no knowledge about tuples at all. It could even be a legacy C function



    // When a type needs to be known only in compile time, which means the keyword "typename" must come before so the compiler will know to make the right text 
    // substitution, and it also needs to be constant the "const" keyword needs to come before the "typename" keyword



    // From the standard on creating a template constructor whether in template or non template object :
    //
    //      Because the explicit template argument list follows the function template name, and because conversion member function templates and 
    //      constructor member fucntion templates are cakked without using a function name, there is no way to provide an explicit template 
    //      argument list for these functions
    //
    //      Again, there is no way to explicitly specifiy the template arguments for constructor






























// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ***************************************************************************    GENERAL CASE   **************************************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //        







































	// Template Class Information :
	//
	//  Purpose :
	//
	//		Use this object to store multiple objects that can be of any type. The types of the required members are provided through as template
	//		arguments. Each time there is only one argument type exposed, and only it can be used to create the next member. The members then are
	//		created in recursion, each time the exposed type is created, until there are no more template arguments and the base case is choosen
	//		to end the recursion
	//
	//  Description :
	//
	//		1. This object contains an instance of the object "State" to allow each instance of this object to have a defined state
	//
	// 		2. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
	//		   providing 3 keywords :
	//
	//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
	//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
	//						member is public all the encapsulation is lost, so it should be avoided in most cases
	//
	//			2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will
	//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few
	//						   data members
	//
	//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
	//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this
	//						 part will end with the suffix __Private
	//
	//		3. Template arguments :
	//
	//			1. Type -
	//			2.
	//
	//		4. In mathematics, a "tuple" is a finite ordered list ( sequence ) of elements
    //
    //		5. The tuple memory will look :
    //
    //
    //              --------------------------------------------------
    //              |     -------------------------------------      |
    //              |     |      -----------------------      |      |
    //              |     |      |      --------       |      |      |
    //              |     |      |      | last |       |      |      |
    //              |     |      |      --------       |      |      |
    //              |     |      |                     |      |      |
    //              |     |      |   one before last   |      |      |
    //              |     |      -----------------------      |      |
    //              |     |                                   |      |
    //              |     |               ...                 |      |
    //              |     |                                   |      |
    //              |     -------------------------------------      |
    //              |                                                |
    //              |                    First                       |
    //              --------------------------------------------------
	//
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	template< typename ExposedType, typename... TemplateArgumentTypes >
	class Tuple : public Tuple< TemplateArgumentTypes... >
	{
	private:


		// The following object will be used to determine if the template arguments provided to the tuple object are all default constructible. If they
		// all are then the tuple will contain a default constructore, otherwise not. This is needed because this object is a template, therefore
		// the deduction of the template type is done on the all object and before the constructor declaration. To workaround this issue the constructor
		// must have also a template parameter, to make the compiler perform the template type deduction on the constructor itself
		template< typename DummyType >
		class TypeCheckRequirements
		{
		public:


			// This is the method that will do the actual checking. It will pass on each template type in the parameter pack of the tuple, and detect if
			// it has a default constructor or not
			static constexpr Boolean AllTypesHasDefaultConstructor()
			{
				// Check if all the template types has a default constructor, and return the result
				return ( DoesParameterPackContainAllTypesWithDefaultConstructor< ExposedType, TemplateArgumentTypes... >::Result() );
			}


			// This is the method that will do the actual checking. It will pass on each template type and check if there is at least one non constant lvalue
			// reference
			static constexpr Boolean AllTypesAreNotNonConstantLvalueReference()
			{
				// Check if all the template types are not non constant lvalue reference, and return the result
				return ( DoesParameterPackContainAtLeastOneNonConstantLvalueReferenceTypes< ExposedType, TemplateArgumentTypes... >::Result() == false );
			}


		};


	public:


	    // Create a type definition for this object
        using SelfType = Tuple< ExposedType, TemplateArgumentTypes... >;


		// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
		// the compiler generates a basic behavior for them if possible :


		// Method Information :
	    //
	    //  Description :
		//
		//		Default Constructor,
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			NONE
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename DummyType = void, typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheckRequirements< DummyType >::AllTypesHasDefaultConstructor(), Boolean >::Type = true >
		inline Tuple() :
		Tuple< TemplateArgumentTypes... >(),
		member_data()
		{}


		// Method Information :
		//
		//  Description :
		//
		//		Constructor,
		//
		//  Required arguments :
		//
		//		User information needed :
		//
        //          1. first - a copy of the first object that needs to be stored in the tuple
        //          2. rest - a copy of the rest of the objects that needs to be stored in the tuple
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
        //      1. The given number of arguments to invoke the method match the number of template arguments provided
        //      2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		explicit inline Tuple( ExposedType first, TemplateArgumentTypes... rest );


        // Method Information :
        //
        //  Description :
        //
        //      Constructor, to allow creating a random generated instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          The first argument purpose is to ensure this constructor will be called by setting a special type
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
		template< typename DummyType = void, typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheckRequirements< DummyType >::AllTypesHasDefaultConstructor() || ( TypeCheckRequirements< DummyType >::AllTypesHasDefaultConstructor() == false && TypeCheckRequirements< DummyType >::AllTypesAreNotNonConstantLvalueReference() == true ), Boolean >::Type = true >
		explicit inline Tuple( RandomInstance ) :
		SelfType( Random::Generator::Get< ExposedType >(), Random::Generator::Get< TemplateArgumentTypes >()... )
		{}


		// Method Information :
	    //
	    //  Description :
		//
        //      Constructor, to allow creating a random generated instance
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. The first argument purpose is to ensure this constructor will be called by setting a special type
		//			2. constraintOnHowToGenerateRandomInstanceOfExposedType - the constraint on how to generate the random instance of the exposed type
        //          3. constraintsOnHowToGenerateRandomInstanceOfTemplateArgumentTypes - the constraints on how to generate the random instance of the rest of the types
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename DummyType = void, typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheckRequirements< DummyType >::AllTypesHasDefaultConstructor() || ( TypeCheckRequirements< DummyType >::AllTypesHasDefaultConstructor() == false && TypeCheckRequirements< DummyType >::AllTypesAreNotNonConstantLvalueReference() == true ), Boolean >::Type = true, typename ConstraintOnHowToGenerateRandomInstanceOfExposedType, typename... ConstraintsOnHowToGenerateRandomInstanceOfTemplateArgumentTypes >
		explicit inline Tuple( RandomInstance, ConstraintOnHowToGenerateRandomInstanceOfExposedType constraintOnHowToGenerateRandomInstanceOfExposedType, ConstraintsOnHowToGenerateRandomInstanceOfTemplateArgumentTypes... constraintsOnHowToGenerateRandomInstanceOfTemplateArgumentTypes ) :
		SelfType( Random::Generator::Get< ExposedType >( constraintOnHowToGenerateRandomInstanceOfExposedType ), Random::Generator::Get< TemplateArgumentTypes >( constraintsOnHowToGenerateRandomInstanceOfTemplateArgumentTypes )...  )
		{}


		// Method Information :
		//
		//  Description :
		//
		//		Copy constructor, will operate correctly even if the other instance is in default state or self assignment
		//
		//  Required arguments :
		//
	    //		User information needed :
		//
		//			other - a reference to the instance that should be copied
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline Tuple( const SelfType& other );


		// Method Information :
		//
		//  Description :
		//
		//   	Assignment operator, can handle with self assignment and instances in default state
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			other - a reference to the instance that should be copied
		//
		//		Information returned to the user :
		//
		//         NONE
		//
		//  Return value :
		//
		//   	A reference to this instance
		//
		//  Expectations :
		//
		//		NONE	
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline SelfType& operator=( const SelfType& other );


		// Method Information :
		//
		//  Description :
		//
		//   	Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances
		//		in default state
		//
		//  Required arguments :
		//
		//   	User information needed :
		//
		//          other - a reference to the instance that should be moved
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	NONE		
		//
		//  Expectations :
		//
		//		NONE	
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline Tuple( SelfType&& other );


		// Method Information :
		//
		//  Description :
		//
		//   	Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			other - a reference to the instance that should be moved
		//
		//		Information returned to the user :
		//
		//         NONE
		//
		//  Return value :
		//
		//   	A reference to this instance
		//
		//  Expectations :
		//
		//		NONE	
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline SelfType& operator=( SelfType&& other );


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to take an instance already initialized, delete the current resources and set it to default state
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			NONE
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//      NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//      They will come
		//
		template< typename DummyType = void, typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheckRequirements< DummyType >::AllTypesHasDefaultConstructor(), Boolean >::Type = true >
		inline void Reset()
		{
		    // Create a default constructed instance. Swap it with this instance, which will be left in default state. When control leaves this method it
			// will delete the old resources
		    SelfType defaultConstructedInstance;

		    // Swap between this instance and the default constructed instance
		    Swap( defaultConstructedInstance );
		}


		// Method Information :
		//
		//  Description :
		//
		//      This method is used to swap the content between this instance and the other one
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			other - a reference to the instance that should be swaped
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//      NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//      They will come
		//
		inline void Swap( SelfType& other );


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
		//
		//  Required arguments :
		//
		//		User information needed :
		//
        //          1. first - a copy of the first object that needs to be stored in the tuple
        //          2. rest - a copy of the rest of the objects that needs to be stored in the tuple
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
        //      1. The given number of arguments to invoke the method match the number of template arguments provided
        //      2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename DummyType = void, typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheckRequirements< DummyType >::AllTypesHasDefaultConstructor(), Boolean >::Type = true >
		inline void Initiate( ExposedType first, TemplateArgumentTypes... rest )
		{
		    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
		    // leave this scope it will delete the old data
		    SelfType temporary( first, rest... );

		    // Swap between this instance and the temporary instance
		    Swap( temporary );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance. This
		//		version is to initate an instance with random generated values. This version doesn't allow any constraints on the random data generated
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. The first argument purpose is to ensure this constructor will be called by setting a special type
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename DummyType = void, typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheckRequirements< DummyType >::AllTypesHasDefaultConstructor(), Boolean >::Type = true >
		inline void Initiate( RandomInstance )
		{
		    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
		    // leave this scope it will delete the old data
		    SelfType temporary( GenerateRandomInstance );

		    // Swap between this instance and the temporary instance
		    Swap( temporary );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance. This
		//		version is to initate an instance with random generated values
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. The first argument purpose is to ensure this constructor will be called by setting a special type
		//			2. constraintOnHowToGenerateRandomInstanceOfExposedType - the constraint on how to generate the random instance of the exposed type
        //          3. constraintsOnHowToGenerateRandomInstanceOfTemplateArgumentTypes - the constraints on how to generate the random instance of the rest of the types
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename DummyType = void, typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheckRequirements< DummyType >::AllTypesHasDefaultConstructor(), Boolean >::Type = true, typename ConstraintOnHowToGenerateRandomInstanceOfExposedType, typename... ConstraintsOnHowToGenerateRandomInstanceOfTemplateArgumentTypes >
		inline void Initiate( RandomInstance, ConstraintOnHowToGenerateRandomInstanceOfExposedType constraintOnHowToGenerateRandomInstanceOfExposedType, ConstraintsOnHowToGenerateRandomInstanceOfTemplateArgumentTypes... constraintsOnHowToGenerateRandomInstanceOfTemplateArgumentTypes )
		{
		    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
		    // leave this scope it will delete the old data
		    SelfType temporary( GenerateRandomInstance, constraintOnHowToGenerateRandomInstanceOfExposedType, constraintsOnHowToGenerateRandomInstanceOfTemplateArgumentTypes... );

		    // Swap between this instance and the temporary instance
		    Swap( temporary );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Destructor, does not throw
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			NONE
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		virtual ~Tuple() = default;


		// The following methods give access and manipulate the data inside this object :


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the number of objects in the tuple
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
		//      The value zero
		//
		//	Excpectations :
		//
		//		The number of objects in the tuple
		//
		//  Possible errors :
		//
		//      They will come
		//
		constexpr UnsignedInteger64bits Size() const;


        // Method Information :
        //
        //  Description :
        //
        //      This method uses the object type holder, which stores the arbitrary number of arguments provided to the object, and can provide a type
        //		definition of the required template argument from the list. This is a recursive method and this is the general case. It peels off the 
        //		required layers until the number of arguments gets to 0, and then the base case is called instead and ends the recursion
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
        //      A reference to the data inside the required entry
        //
        //  Excpectations :
        //
        //      1. The provided argument index is in the range of the provided template arguments types
        //		2. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< UnsignedInteger64bits ArgumentIndex >
        inline typename ProvideTypeOnlyIfAssertionIsTrue< ArgumentIndex != 0, typename TypesHolder< ArgumentIndex, ExposedType, TemplateArgumentTypes... >::Type& >::Type Entry();


        // Method Information :
        //
        //  Description :
        //
        //      This method uses the object type holder, which stores the arbitrary number of arguments provided to the object, and can provide a type
        //		definition of the required template argument from the list. This is a recursive method and this is the base case. After the general case
        //		method has peeled off the required layers until the number of arguments gets to 0, which means the exposed template argument is the required
        //		data the user needs, it returns a reference to the data
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
        //      A reference to the data inside the required entry
        //
        //  Excpectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< UnsignedInteger64bits ArgumentIndex >
        inline typename ProvideTypeOnlyIfAssertionIsTrue< ArgumentIndex == 0, typename TypesHolder< 0, ExposedType, TemplateArgumentTypes... >::Type& >::Type Entry();


        // Method Information :
        //
        //  Description :
        //
        //		For constant instances.
        //
        //      This method uses the object type holder, which stores the arbitrary number of arguments provided to the object, and can provide a type
        //		definition of the required template argument from the list. This is a recursive method and this is the general case. It peels off the 
        //		required layers until the number of arguments gets to 0, and then the base case is called instead and ends the recursion. This method
        //		is for constant instances
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
        //      A constant reference to the data inside the required entry
        //
        //  Excpectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< UnsignedInteger64bits ArgumentIndex >
        inline typename ProvideTypeOnlyIfAssertionIsTrue< ArgumentIndex != 0, typename ConstantTypesHolder< ArgumentIndex, ExposedType, TemplateArgumentTypes... >::Type& >::Type Entry() const;


        // Method Information :
        //
        //  Description :
        //
        //		For constant instances.
        //
        //      This method uses the object type holder, which stores the arbitrary number of arguments provided to the object, and can provide a type
        //		definition of the required template argument from the list. This is a recursive method and this is the base case. After the general case
        //		method has peeled off the required layers until the number of arguments gets to 0, which means the exposed template argument is the required
        //		data the user needs, it returns a reference to the data. This method is for constant instances
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
        //      A constant reference to the data inside the required entry
        //
        //  Excpectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< UnsignedInteger64bits ArgumentIndex >
        inline typename ProvideTypeOnlyIfAssertionIsTrue< ArgumentIndex == 0, typename ConstantTypesHolder< 0, ExposedType, TemplateArgumentTypes... >::Type& >::Type Entry() const;


		// The following methods declare the overloaded operators for the object :


		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to check if the this instance match the other
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			other - a reference to the instance that should be compared with this object
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		1. true - if the 2 instances are the same
		//		2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline Boolean operator==( const SelfType& other ) const;


		// Method Information :
		//
		//  Description :
		//
		//		Use this operator to check if the this instance does not match the other
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			other - a reference to the instance that should be compared with this object
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		1. true - if the 2 instances are not the same
		//		2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline Boolean operator!=( const SelfType& other ) const;


		DEBUG_TOOL(

			// This part of the object is dedicated for testing :


			// Method Information :
			//
			//  Description :
			//
			//		This method is used to test the object. It is not part of the implementation, it is only used to find problems with the code
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			NONE
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//			NONE
			//
			//  Expectations :
			//
			//		Please let the test pass lord!!
			//
			//  Possible errors :
			//
			//		It says there are no problems, which is even scarier, did I just wrote a working code??
			//
			static void Test() __attribute__ (( __unused__ ));

		)  //  End of debug tool


	private:


		// Use the exposed type to create the current member
		ExposedType member_data;


	};  //  Class Tuple




































//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************






































	// Method Information :
	//
	//  Description :
	//
	//		Constructor,
	//
	//  Required arguments :
	//
	//		User information needed :
	//
    //          1. first - a copy of the first object that needs to be stored in the tuple
    //          2. rest - a copy of the rest of the objects that needs to be stored in the tuple
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
    //      1. The given number of arguments to invoke the method match the number of template arguments provided
    //      2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename ExposedType, typename... TemplateArgumentTypes >
	inline Tuple< ExposedType, TemplateArgumentTypes... >::Tuple( ExposedType first, TemplateArgumentTypes... rest ) :
	Tuple< TemplateArgumentTypes... >( rest... ),
	member_data( first )
	{}


	// Method Information :
	//
	//  Description :
	//
	//		Copy constructor, will operate correctly even if the other instance is in default state or self assignment
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			other - a reference to the instance that should be copied
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename ExposedType, typename... TemplateArgumentTypes >
	inline Tuple< ExposedType, TemplateArgumentTypes... >::Tuple( const SelfType& other ) :
	Tuple< TemplateArgumentTypes... >( other ),
	member_data( other.member_data )
	{}


	// Method Information :
	//
	//  Description :
	//
	//   	Assignment operator, can handle with self assignment and instances in default state
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			other - a reference to the instance that should be copied
	//
	//		Information returned to the user :
	//
	//         NONE
	//
	//  Return value :
	//
	//   	A reference to this instance
	//
	//  Expectations :
	//
	//		NONE	
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename ExposedType, typename... TemplateArgumentTypes >
	inline Tuple< ExposedType, TemplateArgumentTypes... >& Tuple< ExposedType, TemplateArgumentTypes... >::operator=( const SelfType& other )
	{
		// Create a copy of the other instance
		SelfType copyOfOther( other );

		// Swap between this instance and the copy of the other one, this will leave the copy instance with the old data, and it will be deleted
		Swap( copyOfOther );

		// Return a reference to this instance
		return ( *this );
	}


	// Method Information :
	//
	//  Description :
	//
	//   	Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances
	//		in default state
	//
	//  Required arguments :
	//
	//   	User information needed :
	//
	//          other - a reference to the instance that should be moved
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//   	NONE		
	//
	//  Expectations :
	//
	//		NONE	
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename ExposedType, typename... TemplateArgumentTypes >
	inline Tuple< ExposedType, TemplateArgumentTypes... >::Tuple( SelfType&& other ) :
	Tuple< TemplateArgumentTypes... >( other ),
	member_data( other.member_data )
	{}


	// Method Information :
	//
	//  Description :
	//
	//   	Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			other - a reference to the instance that should be moved
	//
	//		Information returned to the user :
	//
	//         NONE
	//
	//  Return value :
	//
	//   	A reference to this instance
	//
	//  Expectations :
	//
	//		NONE	
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename ExposedType, typename... TemplateArgumentTypes >
	inline Tuple< ExposedType, TemplateArgumentTypes... >& Tuple< ExposedType, TemplateArgumentTypes... >::operator=( SelfType&& other )
	{
		// Use the move assignment of the base tuple
		Tuple< TemplateArgumentTypes... >::operator=( other );

		// Move the data member
		member_data = other.member_data;

		// Return a reference to this instance
		return ( *this );
	}


	// Method Information :
	//
	//  Description :
	//
	//		This method is used to swap the content between this instance and the other one
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			other - a reference to the instance that should be swaped
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename ExposedType, typename... TemplateArgumentTypes >
	inline void Tuple< ExposedType, TemplateArgumentTypes... >::Swap( SelfType& other )
	{
        // Create a reference to the base tuple
        Tuple< TemplateArgumentTypes... >& baseTuple = *this;

        // Create a recursive call that will swap the data in the layer below this one of the tuple instance with the data in the other instance
        baseTuple.Swap( other );

        // Move the the data in this instance into a temporary
        ExposedType temporaryWithTheDataInThisInstance( MOVE( member_data ) );

        // Move the the data from the other instance in to this instance
        member_data = MOVE( other.member_data );

        // Set the data from the temporary into the other instance
        other.member_data = MOVE( temporaryWithTheDataInThisInstance );
	}


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the number of objects in the tuple
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
	//      The value zero
	//
	//	Excpectations :
	//
	//		The number of objects in the tuple
	//
	//  Possible errors :
	//
	//      They will come
	//
	template< typename ExposedType, typename... TemplateArgumentTypes >
	constexpr UnsignedInteger64bits Tuple< ExposedType, TemplateArgumentTypes... >::Size() const
	{
		// Just return 0
		return ( 1 + sizeof...( TemplateArgumentTypes ) );
	}


    // Method Information :
    //
    //  Description :
    //
    //      This method uses the object type holder, which stores the arbitrary number of arguments provided to the object, and can provide a type
    //		definition of the required template argument from the list. This is a recursive method and this is the general case. It peels off the 
    //		required layers until the number of arguments gets to 0, and then the base case is called instead and ends the recursion
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
    //      A reference to the data inside the required entry
    //
    //  Excpectations :
    //
    //      1. The provided argument index is in the range of the provided template arguments types
    //		2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename ExposedType, typename... TemplateArgumentTypes >
    template< UnsignedInteger64bits ArgumentIndex >
    inline typename ProvideTypeOnlyIfAssertionIsTrue< ArgumentIndex != 0, typename TypesHolder< ArgumentIndex, ExposedType, TemplateArgumentTypes... >::Type& >::Type Tuple< ExposedType, TemplateArgumentTypes... >::Entry() 
    {            
        // Create a reference to the base of the current tuple
        Tuple< TemplateArgumentTypes... >& baseTuple = *this;

        // Call the next method in the recursion with the number of arguments decreased by 1
        return ( baseTuple.template Entry< ArgumentIndex - 1 >() );
    }


    // Method Information :
    //
    //  Description :
    //
    //      This method uses the object type holder, which stores the arbitrary number of arguments provided to the object, and can provide a type
    //		definition of the required template argument from the list. This is a recursive method and this is the base case. After the general case
    //		method has peeled off the required layers until the number of arguments gets to 0, which means the exposed template argument is the required
    //		data the user needs, it returns a reference to the data
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
    //      A reference to the data inside the required entry
    //
    //  Excpectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename ExposedType, typename... TemplateArgumentTypes >
    template< UnsignedInteger64bits ArgumentIndex >
    inline typename ProvideTypeOnlyIfAssertionIsTrue< ArgumentIndex == 0, typename TypesHolder< 0, ExposedType, TemplateArgumentTypes... >::Type& >::Type Tuple< ExposedType, TemplateArgumentTypes... >::Entry() 
    {
        // Return a reference to the data member
        return ( member_data );
    }


    // Method Information :
    //
    //  Description :
    //
    //		For constant instances.
    //
    //      This method uses the object type holder, which stores the arbitrary number of arguments provided to the object, and can provide a type
    //		definition of the required template argument from the list. This is a recursive method and this is the general case. It peels off the 
    //		required layers until the number of arguments gets to 0, and then the base case is called instead and ends the recursion. This method
    //		is for constant instances
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
    //      A constant reference to the data inside the required entry
    //
    //  Excpectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename ExposedType, typename... TemplateArgumentTypes >
    template< UnsignedInteger64bits ArgumentIndex >
    inline typename ProvideTypeOnlyIfAssertionIsTrue< ArgumentIndex != 0, typename ConstantTypesHolder< ArgumentIndex, ExposedType, TemplateArgumentTypes... >::Type& >::Type Tuple< ExposedType, TemplateArgumentTypes... >::Entry() const 
    {               
        // Create a reference to the base of the current tuple
        const Tuple< TemplateArgumentTypes... >& baseTuple = *this;

        // Call the next method in the recursion with the number of arguments decreased by 1
        return ( baseTuple.template Entry< ArgumentIndex - 1 >() );
    }


    // Method Information :
    //
    //  Description :
    //
    //		For constant instances.
    //
    //      This method uses the object type holder, which stores the arbitrary number of arguments provided to the object, and can provide a type
    //		definition of the required template argument from the list. This is a recursive method and this is the base case. After the general case
    //		method has peeled off the required layers until the number of arguments gets to 0, which means the exposed template argument is the required
    //		data the user needs, it returns a reference to the data. This method is for constant instances
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
    //      A constant reference to the data inside the required entry
    //
    //  Excpectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename ExposedType, typename... TemplateArgumentTypes >
    template< UnsignedInteger64bits ArgumentIndex >
    inline typename ProvideTypeOnlyIfAssertionIsTrue< ArgumentIndex == 0, typename ConstantTypesHolder< 0, ExposedType, TemplateArgumentTypes... >::Type& >::Type Tuple< ExposedType, TemplateArgumentTypes... >::Entry() const
    {
        // Return a reference to the data member
        return ( member_data );
    }

































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************




































	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to check if the this instance match the other
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			other - a reference to the instance that should be compared with this object
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//      1. true - if the 2 instances are the same
	//      2. false - otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename ExposedType, typename... TemplateArgumentTypes >
	inline Boolean Tuple< ExposedType, TemplateArgumentTypes... >::operator==( const SelfType& other ) const
	{
        // Check if the instances match, and return the result
        return ( ( member_data == other.member_data ) && ( Tuple< TemplateArgumentTypes... >::operator==( other ) ) );
	}


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to check if the this instance does not match the other
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			other - a reference to the instance that should be compared with this object
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//      1. true - if the 2 instances are not the same
	//      2. false - otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename ExposedType, typename... TemplateArgumentTypes >
	inline Boolean Tuple< ExposedType, TemplateArgumentTypes... >::operator!=( const SelfType& other ) const
	{
		// Return the negotiated value from the equal operator
		return ( !( *this == other ) );
	}







































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************************************    BASE CASE   ***************************************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** // 



































	// Template Class Information :
	//
	//  Purpose :
	//
	//		Artifical Inteligence
	//
	//  Description :
	//
	//		1. This object contains an instance of the object "State" to allow each instance of this object to have a defined state
	//
	// 		2. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
	//		   providing 3 keywords :
	//
	//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
	//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
	//						member is public all the encapsulation is lost, so it should be avoided in most cases
	//
	//			2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will
	//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few
	//						   data members
	//
	//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
	//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this
	//						 part will end with the suffix __Private
	//
	//		3. Template arguments :
	//
	//			1. Type -
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	template< typename ExposedType >
	class Tuple< ExposedType >
	{
	private:


		// The following object will be used to determine if the template arguments provided to the tuple object are all default constructible. If they
		// all are then the tuple will contain a default constructore, otherwise not. This is needed because this object is a template, therefore
		// the deduction of the template type is done on the all object and before the constructor declaration. To workaround this issue the constructor
		// must have also a template parameter, to make the compiler perform the template type deduction on the constructor itself
		template< typename DummyType >
		class TypeCheckRequirements
		{
		public:

			// This is the method that will do the actual checking. It will pass on the template type of the tuple, and detect if it has a default 
			// constructor or not
			static constexpr Boolean TypeHasDefaultConstructor()
			{
				// Check if the template type has a default constructor, and return the result
				return ( TypeCheck_DefaultConstructible< ExposedType >::Result() );
			}

			// This is the method that will do the actual checking. It will pass on the template type of the tuple, and check if it is a non constant
			// lvalue reference. This is needed because an lvalue reference is the only reference type that can't bind to a temporary ( rvalue )
			static constexpr Boolean TypeIsNonConstantLvalueReference()
			{
				// Check if the template type is a non constant lvalue reference, and return the result
				return ( TypeCheck_NonConstant_LvalueReference< ExposedType >::Result() );
			}

		};


	public:


    	// Create a type definition for this object
        using SelfType = Tuple< ExposedType >;


		// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
		// the compiler generates a basic behavior for them if possible :


		// Method Information :
		//
		//  Description :
		//
		//		Default Constructor,
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			NONE
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename DummyType = void, typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheckRequirements< DummyType >::TypeHasDefaultConstructor(), Boolean >::Type = true >
		inline Tuple() : 
		member_data() 
		{}


		// Method Information :
		//
		//  Description :
		//
		//		Constructor,
		//
		//  Required arguments :
		//
		//		User information needed :
		//
        //          instance - a reference to an instance that needs to be stored in the tuple
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		explicit inline Tuple( const ExposedType& instance );


		// Method Information :
	    //
	    //  Description :
		//

//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			The first argument purpose is to ensure this constructor will be called by setting a special type
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename DummyType = void, typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheckRequirements< DummyType >::TypeIsNonConstantLvalueReference() == false, Boolean >::Type = true >
		explicit inline Tuple( RandomInstance ) :
		SelfType( Random::Generator::Get< ExposedType >() )
		{}


        // Method Information :
        //
        //  Description :
        //
        //      Constructor, to allow creating a random generated instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
		//			1. The first argument purpose is to ensure this constructor will be called by setting a special type
		//			2. constraintOnHowToGenerateRandomInstanceOfExposedType - the constraint on how to generate the random instance of the exposed type
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
		template< typename DummyType = void, typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheckRequirements< DummyType >::TypeIsNonConstantLvalueReference() == false, Boolean >::Type = true, typename ConstraintOnHowToGenerateRandomInstanceOfExposedType >
		explicit inline Tuple( RandomInstance, ConstraintOnHowToGenerateRandomInstanceOfExposedType constraintOnHowToGenerateRandomInstanceOfExposedType ) :
		SelfType( Random::Generator::Get< ExposedType >( constraintOnHowToGenerateRandomInstanceOfExposedType ) )
		{}


		// Method Information :
		//
		//  Description :
		//
		//		Copy constructor, will operate correctly even if the other instance is in default state or self assignment
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			other - a reference to the instance that should be copied
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline Tuple( const SelfType& other );


		// Method Information :
		//
		//  Description :
		//
		//   	Assignment operator, can handle with self assignment and instances in default state
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			other - a reference to the instance that should be copied
		//
		//		Information returned to the user :
		//
		//         NONE
		//
		//  Return value :
		//
		//   	A reference to this instance
		//
		//  Expectations :
		//
		//		NONE	
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline SelfType& operator=( const SelfType& other );


		// Method Information :
		//
		//  Description :
		//
		//   	Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances
		//		in default state
		//
		//  Required arguments :
		//
		//   	User information needed :
		//
		//          other - a reference to the instance that should be moved
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	NONE		
		//
		//  Expectations :
		//
		//		NONE	
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline Tuple( SelfType&& other );


		// Method Information :
		//
		//  Description :
		//
		//   	Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			other - a reference to the instance that should be moved
		//
		//		Information returned to the user :
		//
		//         NONE
		//
		//  Return value :
		//
		//   	A reference to this instance
		//
		//  Expectations :
		//
		//		NONE	
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline SelfType& operator=( SelfType&& other );


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to take an instance already initialized, delete the current resources and set it to default state
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			NONE
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//      NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//      They will come
		//
		template< typename DummyType = void, typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheckRequirements< DummyType >::TypeHasDefaultConstructor(), Boolean >::Type = true >
		inline void Reset()
		{
		    // Create a default constructed instance. Swap it with this instance, which will be left in default state. When control leaves this method it
			// will delete the old resources
		    SelfType defaultConstructedInstance;

		    // Swap between this instance and the default constructed instance
		    Swap( defaultConstructedInstance );
		}


		// Method Information :
		//
		//  Description :
		//
		//      This method is used to swap the content between this instance and the other one
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			other - a reference to the instance that should be swaped
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//      NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//      They will come
		//
		inline void Swap( SelfType& other );


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
		//
		//  Required arguments :
		//
		//		User information needed :
		//
        //          instance - a reference to an instance that needs to be stored in the tuple
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename DummyType = void, typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheckRequirements< DummyType >::TypeHasDefaultConstructor(), Boolean >::Type = true >
		inline void Initiate( const ExposedType& instance )
		{
		    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
		    // leave this scope it will delete the old data
		    SelfType temporary( instance );

		    // Swap between this instance and the temporary instance
		    Swap( temporary );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance. This
		//		version is to initate an instance with random generated values. This version doesn't allow any constraints on the random data generated
		//
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			The first argument purpose is to ensure this constructor will be called by setting a special type
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename DummyType = void, typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheckRequirements< DummyType >::TypeHasDefaultConstructor(), Boolean >::Type = true >
		inline void Initiate( RandomInstance )
		{
		    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
		    // leave this scope it will delete the old data
		    SelfType temporary( GenerateRandomInstance );

		    // Swap between this instance and the temporary instance
		    Swap( temporary );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance. This
		//		version is to initate an instance with random generated values
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. The first argument purpose is to ensure this constructor will be called by setting a special type
		//			2. constraintOnHowToGenerateRandomInstanceOfExposedType - the constraint on how to generate the random instance of the exposed type
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename DummyType = void, typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheckRequirements< DummyType >::TypeHasDefaultConstructor(), Boolean >::Type = true, typename ConstraintOnHowToGenerateRandomInstanceOfExposedType >
		inline void Initiate( RandomInstance, ConstraintOnHowToGenerateRandomInstanceOfExposedType constraintOnHowToGenerateRandomInstanceOfExposedType )
		{
		    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
		    // leave this scope it will delete the old data
		    SelfType temporary( GenerateRandomInstance, constraintOnHowToGenerateRandomInstanceOfExposedType );

		    // Swap between this instance and the temporary instance
		    Swap( temporary );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Destructor, does not throw
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			NONE
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		virtual ~Tuple() = default;


		// The following methods give access and manipulate the data inside this object :


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the number of objects in the tuple
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
		//      The value zero
		//
		//	Excpectations :
		//
		//		The number of objects in the tuple
		//
		//  Possible errors :
		//
		//      They will come
		//
		constexpr UnsignedInteger64bits Size() const;


        // Method Information :
        //
        //  Description :
        //
        //      This method uses the object type holder, which stores the arbitrary number of arguments provided to the object, and can provide a type
        //		definition of the required template argument from the list. This is a recursive method and this is the general case. It peels off the 
        //		required layers until the number of arguments gets to 0, and then the base case is called instead and ends the recursion
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
        //      A reference to the data inside the required entry
        //
        //  Excpectations :
        //
        //      1. The provided argument index is in the range of the provided template arguments types
        //		2. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< UnsignedInteger64bits ArgumentIndex >
        inline ExposedType& Entry();


        // Method Information :
        //
        //  Description :
        //
        //		For constant instances.
        //
        //      This method uses the object type holder, which stores the arbitrary number of arguments provided to the object, and can provide a type
        //		definition of the required template argument from the list. This is a recursive method and this is the general case. It peels off the 
        //		required layers until the number of arguments gets to 0, and then the base case is called instead and ends the recursion. This method
        //		is for constant instances
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
        //      A constant reference to the data inside the required entry
        //
        //  Excpectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< UnsignedInteger64bits ArgumentIndex >
        inline const ExposedType& Entry() const;


		// The following methods declare the overloaded operators for the object :


		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to check if the this instance match the other
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			other - a reference to the instance that should be compared with this object
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		1. true - if the 2 instances are the same
		//		2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline Boolean operator==( const SelfType& other ) const;


		// Method Information :
		//
		//  Description :
		//
		//		Use this operator to check if the this instance does not match the other
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			other - a reference to the instance that should be compared with this object
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		1. true - if the 2 instances are not the same
		//		2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline Boolean operator!=( const SelfType& other ) const;


		DEBUG_TOOL(

			// This part of the object is dedicated for testing :


			// Method Information :
			//
			//  Description :
			//
			//		This method is used to test the object. It is not part of the implementation, it is only used to find problems with the code
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			NONE
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//			NONE
			//
			//  Expectations :
			//
			//		Please let the test pass lord!!
			//
			//  Possible errors :
			//
			//		It says there are no problems, which is even scarier, did I just wrote a working code??
			//
			static void Test() __attribute__ (( __unused__ )) { Tuple< UnsignedInteger64bits COMMA UnsignedInteger64bits >::Test(); }

		)  //  End of debug tool


	private:


		// Use the exposed type to create the current member
		ExposedType member_data;


	};  //  Class Tuple





































//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************





































	// Method Information :
	//
	//  Description :
	//
	//		Constructor,
	//
	//  Required arguments :
	//
	//		User information needed :
	//
    //          instance - a reference to an instance that needs to be stored in the tuple
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename ExposedType >
	inline Tuple< ExposedType >::Tuple( const ExposedType& instance ) :
	member_data( instance )
	{}


	// Method Information :
	//
	//  Description :
	//
	//		Copy constructor, will operate correctly even if the other instance is in default state or self assignment
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			other - a reference to the instance that should be copied
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename ExposedType >
	inline Tuple< ExposedType >::Tuple( const SelfType& other ) :
	member_data( other.member_data )
	{}


	// Method Information :
	//
	//  Description :
	//
	//   	Assignment operator, can handle with self assignment and instances in default state
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			other - a reference to the instance that should be copied
	//
	//		Information returned to the user :
	//
	//         NONE
	//
	//  Return value :
	//
	//   	A reference to this instance
	//
	//  Expectations :
	//
	//		NONE	
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename ExposedType >
	inline Tuple< ExposedType >& Tuple< ExposedType >::operator=( const SelfType& other )
	{
		// Create a copy of the other instance
		SelfType copyOfOther( other );

		// Swap between this instance and the copy of the other one, this will leave the copy instance with the old data, and it will be deleted
		Swap( copyOfOther );

		// Return a reference to this instance
		return ( *this );
	}


	// Method Information :
	//
	//  Description :
	//
	//   	Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances
	//		in default state
	//
	//  Required arguments :
	//
	//   	User information needed :
	//
	//          other - a reference to the instance that should be moved
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//   	NONE		
	//
	//  Expectations :
	//
	//		NONE	
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename ExposedType >
	inline Tuple< ExposedType >::Tuple( SelfType&& other ) :
	member_data( other.member_data )
	{}


	// Method Information :
	//
	//  Description :
	//
	//   	Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			other - a reference to the instance that should be moved
	//
	//		Information returned to the user :
	//
	//         NONE
	//
	//  Return value :
	//
	//   	A reference to this instance
	//
	//  Expectations :
	//
	//		NONE	
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename ExposedType >
	inline Tuple< ExposedType >& Tuple< ExposedType >::operator=( SelfType&& other )
	{
		// Move the data member
		member_data = other.member_data;

		// Return a reference to this instance
		return ( *this );
	}


	// Method Information :
	//
	//  Description :
	//
	//		This method is used to swap the content between this instance and the other one
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			other - a reference to the instance that should be swaped
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename ExposedType >
	inline void Tuple< ExposedType >::Swap( SelfType& other )
	{
        // Move the the data in this instance into a temporary
        ExposedType temporaryWithTheDataInThisInstance( MOVE( member_data ) );

        // Move the the data from the other instance in to this instance
        member_data = MOVE( other.member_data );

        // Set the data from the temporary into the other instance
        other.member_data = MOVE( temporaryWithTheDataInThisInstance );
	}


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the number of objects in the tuple
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
	//      The value zero
	//
	//	Excpectations :
	//
	//		The number of objects in the tuple
	//
	//  Possible errors :
	//
	//      They will come
	//
	template< typename ExposedType >
	constexpr UnsignedInteger64bits Tuple< ExposedType >::Size() const
	{
		// Just return 1
		return ( 1UL );
	}


    // Method Information :
    //
    //  Description :
    //
    //      This method uses the object type holder, which stores the arbitrary number of arguments provided to the object, and can provide a type
    //		definition of the required template argument from the list. This is a recursive method and this is the general case. It peels off the 
    //		required layers until the number of arguments gets to 0, and then the base case is called instead and ends the recursion
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
    //      A reference to the data inside the required entry
    //
    //  Excpectations :
    //
    //      1. The provided argument index is in the range of the provided template arguments types
    //		2. The instance should be ready
    //		3. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename ExposedType >
    template< UnsignedInteger64bits ArgumentIndex >
    inline ExposedType& Tuple< ExposedType >::Entry() 
    {            
		// This is a compile time assertion. The compiler checks the condition during compile time, and the condition does not apply an error message will be displayed
		CompileTimeAssert( ( ArgumentIndex == 0 ), "The argument index should be zero" );

        // Call the next method in the recursion with the number of arguments decreased by 1
        return ( member_data );
    }


    // Method Information :
    //
    //  Description :
    //
    //		For constant instances.
    //
    //      This method uses the object type holder, which stores the arbitrary number of arguments provided to the object, and can provide a type
    //		definition of the required template argument from the list. This is a recursive method and this is the general case. It peels off the 
    //		required layers until the number of arguments gets to 0, and then the base case is called instead and ends the recursion. This method
    //		is for constant instances
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
    //      A constant reference to the data inside the required entry
    //
    //  Excpectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename ExposedType >
    template< UnsignedInteger64bits ArgumentIndex >
    inline const ExposedType& Tuple< ExposedType >::Entry() const
    {
		// This is a compile time assertion. The compiler checks the condition during compile time, and the condition does not apply an error message will be displayed
		CompileTimeAssert( ( ArgumentIndex == 0 ), "The argument index should be zero" );
        
        // Call the next method in the recursion with the number of arguments decreased by 1
        return ( member_data );
    }



































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************




































	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to check if the this instance match the other
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			other - a reference to the instance that should be compared with this object
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//      1. true - if the 2 instances are the same
	//      2. false - otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename ExposedType >
	inline Boolean Tuple< ExposedType >::operator==( const SelfType& other ) const
	{
        // Check if the instances match, and return the result
        return ( member_data == other.member_data );
	}


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to check if the this instance does not match the other
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			other - a reference to the instance that should be compared with this object
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//      1. true - if the 2 instances are not the same
	//      2. false - otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename ExposedType >
	inline Boolean Tuple< ExposedType >::operator!=( const SelfType& other ) const
	{
		// Return the negotiated value from the equal operator
		return ( !( *this == other ) );
	}





































// *********************************************************************************   TESTING   ********************************************************************************




































	DEBUG_TOOL(

		// Method Information :
		//
		//  Description :
		//
		//      This method is used to test the object. It is not part of the implementation, it is only used to find problem with the code that does implement
		//		the functionality
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			NONE
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//      1. true - if the object passed the test
		//      2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		1. An assertion failed - class Exception or ErrnoException is thrown
		//		2. There is no more free memory space - class std::bad_alloc is thrown
		//		3. 
		//
		template< typename ExposedType COMMA typename... TemplateArgumentTypes >
		void Tuple< ExposedType COMMA TemplateArgumentTypes... >::Test()
		{
            // Create a simple tuffle with the default constructor
            Tuple< UnsignedInteger32bits COMMA double COMMA char* > testTuple_1;

            // Initiate the tuple
            testTuple_1.Initiate( 132, 99.8945, 0 );

            // Check that the size of the tuple is really 3
            Assert_Test_MACRO( testTuple_1.Size() == 3 );

            // Create a simple tuffle with the parameterized constructor
            Tuple< UnsignedInteger32bits COMMA UnsignedInteger32bits > testTuple_2( 8, 10 );

            // Check that the size of the tuple is really 2
            Assert_Test_MACRO( testTuple_2.Size() == 2 );

            // Change the tuple
            testTuple_2.Initiate( 132, 99 );

            // Create a simple tuffle with the parameterized constructor
            Tuple< UnsignedInteger32bits COMMA UnsignedInteger32bits > testTuple_3( testTuple_2 );

            // Check the comparison operator
            Assert_Test_MACRO( testTuple_2 == testTuple_3 );

            // Check the non comparison operator
            Assert_Test_MACRO( testTuple_2 == testTuple_3 );

            // // Create a simple tuffle with the default constructor
            Tuple< UnsignedInteger32bits COMMA UnsignedInteger32bits > testTuple_4( MOVE( testTuple_2 ) );

            // Check that the size of the tuple is really 2
            Assert_Test_MACRO( testTuple_4.Size() == 2 );

            // Test the Entry method
            Assert_Test_MACRO( testTuple_4.Entry< 0 >() == 132 ); 

            // Test the Entry method
            testTuple_4.Entry< 0 >() = 45;

            // Test the Entry method
            Assert_Test_MACRO( testTuple_4.Entry< 0 >() == 45 );             

            // Create a simple constant tuffle with the parameterized constructor
            const Tuple< UnsignedInteger32bits COMMA UnsignedInteger32bits > testTuple_5( 78, 999999 );

        	// Test the Entry method
            Assert_Test_MACRO( testTuple_5.Entry< 0 >() == 78 );

            // Create a simple constant tuffle with the parameterized constructor
            Tuple< UnsignedInteger32bits COMMA UnsignedInteger32bits > testTuple_6( 78, 999999 );

            // Set to default state
            testTuple_6.Reset();

            // Initiate the instance
            testTuple_6.Initiate( 4566, 8792 );

            // Set a value
            testTuple_6.Entry< 1 >() = 77;

            // Reset
            testTuple_6.Reset();

            // Initiate the instance
            testTuple_6.Initiate( 4566, 8792 );

            // Set a value
            testTuple_6.Entry< 1 >() = 77;

            // Create a simple constant tuffle with the parameterized constructor
            Tuple< UnsignedInteger32bits COMMA UnsignedInteger32bits COMMA UnsignedInteger32bits > testTuple_7( 99, 99, 69 );

            // Create a simple constant tuffle with the parameterized constructor
            Tuple< UnsignedInteger32bits COMMA UnsignedInteger32bits COMMA UnsignedInteger32bits > testTuple_8( testTuple_7 );

            // Check the comparison operator
            Assert_Test_MACRO( testTuple_7 == testTuple_8 );

            // Create a simple constant tuffle with the parameterized constructor
            Tuple< UnsignedInteger32bits COMMA UnsignedInteger32bits COMMA UnsignedInteger32bits > testTuple_9;

            // Create a simple constant tuffle with the parameterized constructor
            Tuple< UnsignedInteger32bits COMMA UnsignedInteger32bits COMMA UnsignedInteger32bits > testTuple_10;

            // Check the comparison operator
            Assert_Test_MACRO( testTuple_9 == testTuple_10 );

            // Create avariable to set the address of inside the tuple
            UnsignedInteger32bits testVariable_1 = 0;

            // Create a tuple with pointer
            Tuple< UnsignedInteger32bits* > testTuple_11;

            // Initiate the instance
            testTuple_11.Initiate( &testVariable_1 );

            // Set the variable
            *testTuple_11.Entry< 0 >() = 889;

            // Check the comparison operator
            Assert_Test_MACRO( testVariable_1 == 889 );

            // Set the pointer
            testTuple_11.Entry< 0 >() = &testVariable_1;

            // Set the variable
            *testTuple_11.Entry< 0 >() = 88999;

            // Check the comparison operator
            Assert_Test_MACRO( testVariable_1 == 88999 );

            // Create a simple constant tuffle with the parameterized constructor
            Tuple< UnsignedInteger32bits COMMA UnsignedInteger32bits COMMA UnsignedInteger32bits > testTuple_12( GenerateRandomInstance );
            Tuple< UnsignedInteger32bits > testTuple_13( GenerateRandomInstance );

            // Create a tuple with reference
            Tuple< const UnsignedInteger32bits > testTuple_14( testVariable_1 );

            // Check the comparison operator
            Assert_Test_MACRO( testVariable_1 == 88999 );

            // Create a tuple with reference
            Tuple< UnsignedInteger32bits& > testTuple_15( testVariable_1 );

            // Set the variable
            testTuple_15.Entry< 0 >() = 345345;

            // Check the comparison operator
            Assert_Test_MACRO( testVariable_1 == 345345 );

            // Generate a random instance with references
	        Tuple< const UnsignedInteger32bits& > testTuple_16( GenerateRandomInstance );
	        Tuple< const UnsignedInteger32bits& COMMA UnsignedInteger32bits > testTuple_17( GenerateRandomInstance );

            // Create a simple constant tuffle with the parameterized constructor with constraints
            Tuple< UnsignedInteger32bits COMMA UnsignedInteger32bits COMMA UnsignedInteger32bits > testTuple_18( GenerateRandomInstance, NumericRange< UnsignedInteger32bits >(), NumericRange< UnsignedInteger32bits >(), NumericRange< UnsignedInteger32bits >() );
            Tuple< UnsignedInteger32bits > testTuple_19( GenerateRandomInstance, NumericRange< UnsignedInteger32bits >() );
            testTuple_19.Initiate( GenerateRandomInstance );
            testTuple_19.Initiate( GenerateRandomInstance, NumericRange< UnsignedInteger32bits >() );
		}

	)  //  End of debug tool













}  //  Namespace Universe



#endif  // TUPLE_HPP