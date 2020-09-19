#ifndef ASCIICHARACTER_HPP
#define ASCIICHARACTER_HPP


#include "../../../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../../../../../Content/Metaprogramming/NumericLimits/NumericLimits.hpp"  //  Class NumericLimits
#include "../../../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../../../../../../Content/Memory/Operations/Operations.hpp"  //  Class Operations 
#include "../../../../../../Content/BindObjects/Tuple/Tuple.hpp"  //  Class Tuple
#include "../../../../../../../Content/Random/Generator/Generator.hpp"  //  Class Generator
#include "../../../../../../../Content/NumericRange/NumericRange.hpp"  //  Class NumericRange


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



	namespace Language
	{



	    // typename :
	    //
	    // The keyword typename was introduced to specify that the identifier that follows is a type. Consider the following example:
	    //
	    //      template <class T>
	    //      Class MyClass
	    //      {
	    //          typename T::SubType * ptr;
	    //          ...
	    //      };
	    //
	    // Here, typename is used to clarify that SubType is a type of class T. Thus, ptr is a pointer to the type T::SubType. Without typename, 
	    // SubType would be considered a static member. Thus :
	    //
	    //      T::SubType * ptr
	    //
	    // would be a multiplication of value SubType of type T with ptr



	    // One of the primary goal when overloading operator() is to create a functor. A functor acts just like a function, but it has the 
	    // advantages that it is stateful, meaning it can keep data reflecting its state between calls. 
	    //
	    // Here is a simple functor example :
	    // 
	    //      struct Count
	    //      {
	    //          int counter = 0;
	    //  
	    //          int operator()( int integer ) { return ( counter += integer ); }
	    //      }
	    //
	    //      Count countThis;
	    //      std::cout << countThis( 10 ) << std::endl;      // Display "10"
	    //      std::cout << countThis( 20 ) << std::endl;      //prints "30"
	    //
	    // Functors are heavily used with generic programming. The purpose is to be able to plug-in custom function or functor when needed.
	    //
	    // For example,
	    //
	    //      template< typename Functor >
	    //      void DoSomething( Functor functor )
	    //      {}
	    //
	    // This is very generic since it is parametrized by a function. By using the operator(), this function lets you use either a functor 
	    // or a function pointer



	    // std::uncaught_exception :
	    //
	    // This function is used to detect if an exception is currently active! this is important because throwing exception when another exception 
	    // is active will cause the call of the terminate function, and the end of the program
	    //
	    // Returns true if an exception has been thrown but the initialization of the exception declaration in the matching handler ( including 
	    // an automatic call to unexpected or terminate ) is not yet complete. Or in other words, it returns true if an exception has been thrown 
	    // and has not yet been handled by its appropriate catch handler, including stack unwinding
	    //
	    // Returns false in all other cases, including when unexpected or terminate is explicitly called by the program



	    // The keyword inline is not allowed in declaration of friend template specialization



	    // When declaring an outside template method friend with an class template, all instances of that methods no matter the template object 
	    // are friends with all instances of the object no matter the template object also here, meaning AutomaticPointer< int > will be friends 
	    // with operator*< double >, Therefore this two declarations are made. operator* is declared as a template method using a declared ( but 
	    // not yet defined ) templated class. AutomaticPointer then defines the template instantiation of operator* matching the template 
	    // instantiation of AutomaticPointer as a friend. Note - no exception specification on purpose, becuase when using templates there is 
	    // no way of knowing what the given type will throw



	    // Operator "->" :
	    //
	    //      someClass->Something()
	    //
	    // Will be converted by the compiler to the following statement :
	    //
	    //      someClass.operator->()->Something()
	    //
	    // The first call to the overloaded operator-> gives a pointer of some type which has an accessible member function called Something



	    // The keyword inline is not allowed in declaration of friend template specialization



	    // When declaring an outside template method friend with an class template, all instances of that methods no matter the template object are friends with all instances 
	    // of the object no matter the template object also here, meaning Pointer< int > will be friends with operator*< double >, Therefore this two declarations are made. 
	    // operator* is declared  as a template method using a declared ( but not yet defined ) templated class. Pointer then defines the template instantiation of operator* 
	    // matching the template instantiation of Pointer as a friend. Note - no exception specification on purpose, becuase when using templates there is no way of knowing 
	    // what the given type will throw



	    // Namespaces avoid name clashes. Polymorphism is outside their charter!



	    // Operator "->" :
	    //
	    //  someClass->Something()
	    //
	    // Will be converted by the compiler to the following statement :
	    //
	    //  someClass.operator->()->Something()
	    //
	    // The first call to the overloaded operator-> gives a pointer of some type which has an accessible member function called Something



	    // C++ has two kinds of enumeration :
	    //
	    //  1. enum classes
	    //  2. Plain enums
	    //
	    //  Here are a couple of examples how to declare them :
	    //
	    //      enum class Color { red, green, blue }; // enum class
	    //      enum Animal { dog, cat, bird, human }; // plain enum 
	    //
	    // What is the difference between two?
	    //
	    //  enum classes - enumerator names are local to the enum and their values do not implicitly convert to other types ( like another enum or int )
	    //  Plain enums - where enumerator names are in the same scope as the enum and their values implicitly convert to integers and other types
	    //
	    // Enum classes should be preferred because they cause fewer surprises that could potentially lead to bugs



	    // To overload operator "++" for prefix and postfix use the following syntax :
	    //
	    //      class Number 
	    //      {
	    //      public:
	    //
	    //          Number& operator++ ();     // prefix ++: no parameter, returns a reference
	    //          Number  operator++ (int);  // postfix ++: dummy parameter, returns a value
	    //
	    //      };



	    // When a template specialization is created, it is an entirly different object. All the interface and data members must be redeclared!



		// Class Information :
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
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		Too many to count
		//
		class AsciiCharacter NotForInheritance
		{
		public:


			// Create a type definition of this object
			using SelfType = AsciiCharacter;


			// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
			// the compiler generates a basic behavior for them if possible :


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
			//			asciiCharacter - this value will be used to initialize the instance
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
			inline AsciiCharacter( SignedInteger8bits asciiCharacter = 0 );


			// Method Information :
			//
			//  Description :
			//
			//		Constructor, to allow creating an instance with the same arguments as the parameterized constructor, just that the arguments will be
			//		wrapped in a tuple, to allow more automatic creation of instances. Each parameterized constructor will have an equivalent constructor
			//		to inokve with a tuple, which will only call the required constructor and unpack the tuple to the arguments inisde
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			arguments - the arguments needed to construct an instance, only wrapped in a tuple. The arguments are :
			//
			//				1. asciiCharacter - this value will be used to initialize the instance
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
			explicit inline AsciiCharacter( const Tuple< SignedInteger8bits >& arguments );


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
			//		    other - a reference to the instance that should be copied
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
			inline AsciiCharacter( const SelfType& other );


			// This macro will be used to add all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
			// simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
			// any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
			// be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
			// macro will be used to add the following methods to each object :
			//
			//		1. Assigenment operator
			//		2. Move constructor
			//		3. Move assigenment operator
			//		4. Reset
			//		5. State
			//
			ObjectInfrastructure_ForInheritance_WithStateAlwaysReady_MACRO( AsciiCharacter )


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
			//		    other - a reference to the instance that should be swapped
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
			inline void Swap( SelfType& other );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			asciiCharacter - this value will be used to initialize the instance
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
			inline void Initiate( SignedInteger8bits asciiCharacter );


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
			inline ~AsciiCharacter() = default;


			// The following methods give access and manipulate the data inside this object :


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get the ascii character inside to allow the standard output to recognize the type
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
			//		The ascii character inside
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline char Get() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to check if the current ascii character value represent a digit
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
			//		1. true - if the current value represent a digit
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
			inline Boolean Digit() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to check if the current ascii character value represent an English alphabet letter in the capital form
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
			//		1. true - if the current value represent an English alphabet capital letter
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
			inline Boolean EnglishAlphabetCapitalLetter() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to check if the current ascii character value represent an English alphabet letter in the small form
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
			//		1. true - if the current value represent an English alphabet small letter
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
			inline Boolean EnglishAlphabetSmallLetter() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to check if the current value represent an English alphabet letter
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
			//		1. true - if the current value represent an English alphabet letter
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
			inline Boolean EnglishAlphabetLetter() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to check if the current value represent an English alphabet letter
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
			//		1. true - if the current value represent an English alphabet letter
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
			inline Boolean CanCurrentAsciiCharacterBeDisplayed() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to convert an english alphabet letter from the small form to capital form
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
			//		1. The current value in the instance describes one of the letters in the english alphabet
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline void ConvertToCapitalLetter();


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to convert an english alphabet letter from capital form to small form
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
			//		1. The current value in the instance describes one of the letters in the english alphabet
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline void ConvertToSmallLetter();


			// The following methods declare the overloaded operators for the object :


			// Method Information :
			//
			//  Description :
			//
			//		Use this operator to check if the this instance match the other
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//		    other - a reference to the instance that should be compared with this object
			//
			//		Information returned to the user :
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
			//		    other - a reference to the instance that should be compared with this object
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


			// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have
			// access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring
			// a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this method to generate a random instance of this object
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          rangeForAsciiCharacter - this will be used to limit the possible size of the random instance
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //      A random generated instance
	        //
	        //  Expectations :
	        //
	        //      NONE
	        //
	        //  Possible errors :
	        //
	        //		They will come
	        //
	        static inline SelfType GenerateRandomInstance( NumericRange< SignedInteger8bits > rangeForAsciiCharacter = NumericRange< SignedInteger8bits >( 0, 127 ) );


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
				static void Test() __attribute__ ((unused));

			)  //  End of debug tool


		private:


			// This object will store the ascii character
			SignedInteger8bits member_asciiCharacter;


			// Friend class or friend function can access private and protected members of other object in which it is declared as friend. It is sometimes useful
			// to allow a particular object to access private members of other object. The declration of such function is private, because these functions are part
			// of the implemntation, which the user should not be aware of. The use of this functions is not limited to the object's scope. One of the problems that
			// friend declaration solves is when the object needs to be as a right side operand in expressions. Every method in the object is implicitly added a pointer
			// to the location of the object data with the name "this", and to enable this the method must be called from an existing instance. This means that the
			// object can only be implemented as the left side operand of an expression with methods, and friend functions and objects does not have this limitation


			// Method Information :
			//
			//  Description :
			//
			//		Use this operator to check if the this instance match the other
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. asciiCharacter - the ascii character to compare with
			//		    2. instance - a reference to the instance that should be compared with the ascii character
			//
			//		Information returned to the user :
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
			friend inline Boolean operator==( SignedInteger8bits asciiCharacter, const SelfType& instance );


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
			//			1. asciiCharacter - the ascii character to compare with
			//		    2. instance - a reference to the instance that should be compared with the ascii character
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
			friend inline Boolean operator!=( SignedInteger8bits asciiCharacter, const SelfType& instance );


		};  //  Class AsciiCharacter




































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
		//			asciiCharacter - this value will be used to initialize the instance
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
		//		1. The given value is not negative
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		AsciiCharacter::AsciiCharacter( SignedInteger8bits asciiCharacter ) :
		member_asciiCharacter( asciiCharacter )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			Assert_MACRO( ( asciiCharacter >= 0 ), "An ascii character can not have a negative value" )
		}


		// Method Information :
		//
		//  Description :
		//
		//		Constructor, to allow creating an instance with the same arguments as the parameterized constructor, just that the arguments will be
		//		wrapped in a tuple, to allow more automatic creation of instances. Each parameterized constructor will have an equivalent constructor
		//		to inokve with a tuple, which will only call the required constructor and unpack the tuple to the arguments inisde
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			arguments - the arguments needed to construct an instance, only wrapped in a tuple. The arguments are :
		//
		//				1. asciiCharacter - this value will be used to initialize the instance
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
		inline AsciiCharacter::AsciiCharacter( const Tuple< SignedInteger8bits >& arguments ) :
		AsciiCharacter( arguments.template Entry< 0 >() )
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
		//		    other - a reference to the instance that should be copied
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
		inline AsciiCharacter::AsciiCharacter( const SelfType& other ) :
		member_asciiCharacter( other.member_asciiCharacter )
		{}


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
		//		other - a reference to the instance that should be swaped
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
		void AsciiCharacter::Swap( SelfType& other )
		{
			// Swap the ascii character
			Memory::Operations::Swap< SignedInteger8bits >( member_asciiCharacter, other.member_asciiCharacter );
		}


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
		//			asciiCharacter - this value will be used to initialize the instance
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
		//		1. The given value is not negative
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline void AsciiCharacter::Initiate( SignedInteger8bits asciiCharacter )
		{
		    // Use the required constructor to create an instance. It will be swaped with this instance, leaving this instance with the new data. When sequence control will
		    // leave this scope it delete the old data if exist
		    SelfType instanceCreatedUsingTheRequiredConstructor( asciiCharacter );

		    // Swap between this instance and the temporary instance
		    Swap( instanceCreatedUsingTheRequiredConstructor );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the ascii character inside to allow the standard output to recognize the type
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
		//		The ascii character inside
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline char AsciiCharacter::Get() const
		{
			// Return the the ascii character as 'char' type, to allow the standard output to recognize type
			return ( member_asciiCharacter );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to check if the current ascii character value represent a digit
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
		//		1. true - if the current value represent a digit
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
		inline Boolean AsciiCharacter::Digit() const
		{
			// Check if the current ascii character value represent a digit, and return the result
			//
			//		'0' - 48 Decimal
			//		'9' - 57 Decimal
			//
			return ( ( member_asciiCharacter >= '0' ) && ( member_asciiCharacter <= '9' ) );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to check if the current ascii character value represent an English alphabet letter in the capital form
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
		//		1. true - if the current value represent an English alphabet capital letter
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
		inline Boolean AsciiCharacter::EnglishAlphabetCapitalLetter() const
		{
			// Check if the current ascii character value represent an English alphabet letter in the capital form, and return the result
			//
			//		Capital A - 65 Decimal
			//		Capital Z - 90 Decimal
			//
			return ( ( member_asciiCharacter >= 'A' ) && ( member_asciiCharacter <= 'Z' ) );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to check if the current ascii character value represent an English alphabet letter in the small form
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
		//		1. true - if the current value represent an English alphabet small letter
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
		inline Boolean AsciiCharacter::EnglishAlphabetSmallLetter() const
		{
			// Check if the current ascii character value represent an English alphabet letter in the small form, and return the result
			//
			//		Small a - 97 Decimal
			//		Small z - 122 Decimal
			//
			return ( ( member_asciiCharacter >= 'a' ) && ( member_asciiCharacter <= 'z' ) );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to check if the current value represent an English alphabet letter
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
		//		1. true - if the current value represent an English alphabet letter
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
		inline Boolean AsciiCharacter::EnglishAlphabetLetter() const
		{
			// Check if the current value represent one of the English alphabet letters, and return the result. The English alphabet letters has the following
			// values :
			//
			//		Capital A - 65 Decimal
			//		Capital Z - 90 Decimal
			//
			//		Small a - 97 Decimal
			//		Small z - 122 Decimal
			//
			return ( EnglishAlphabetCapitalLetter() || EnglishAlphabetSmallLetter() );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to check if the current value represent an English alphabet letter
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
		//		1. true - if the current value represent an English alphabet letter
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
		inline Boolean AsciiCharacter::CanCurrentAsciiCharacterBeDisplayed() const
		{
			// Check if the current value represent one of the ascii characters that can be displayed, and return the result. The values that can be 
			// displayed start at the value 33 and  end at 126
			return ( ( member_asciiCharacter >= 33 ) && ( member_asciiCharacter >= 126 ) );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to convert an english alphabet letter from the small form to capital form
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
		//		1. The current value in the instance describes one of the letters in the english alphabet
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline void AsciiCharacter::ConvertToCapitalLetter()
		{
			// This will be added only in test mode, to ensure that the given data to the method is valid
			Assert_MACRO( ( EnglishAlphabetLetter() == true ), "The current ascii character value does not represent an English alphabet letter" )

			// Check if the current English alphabet letter is in the capital or small form, if it is in the capital form then there is nothing to do
			if ( EnglishAlphabetSmallLetter() == true )
			{
				// The current English alphabet letter is in the small form

				// Subtract 32 from the current value, to convert the small form into the capital form of the letter
				member_asciiCharacter -= 32;
			}

		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to convert an english alphabet letter from capital form to small form
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
		//		1. The current value in the instance describes one of the letters in the english alphabet
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline void AsciiCharacter::ConvertToSmallLetter()
		{
			// This will be added only in test mode, to ensure that the given data to the method is valid
			Assert_MACRO( ( EnglishAlphabetLetter() == true ), "The current ascii character value does not represent an English alphabet letter" )

			// Check if the current English alphabet letter is in the capital or small form, if it is in the small form then there is nothing to do
			if ( EnglishAlphabetSmallLetter() == true )
			{
				// The current English alphabet letter is in the capital form

				// Add 32 to the current value, to convert the capital form into the small form of the letter
				member_asciiCharacter += 32;
			}

		}

































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



































		// Method Information :
		//
		//  Description :
		//
		//		Use this operator to check if the this instance match the other
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//		    other - a reference to the instance that should be compared with this object
		//
		//		Information returned to the user :
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
		inline Boolean AsciiCharacter::operator==( const SelfType& other ) const
		{
			// Compare between the ascii characters and return the result
			return ( member_asciiCharacter == other.member_asciiCharacter );
		}


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
		//		    other - a reference to the instance that should be compared with this object
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
		inline Boolean AsciiCharacter::operator!=( const SelfType& other ) const
		{
			// Return the negotiated value from the equal operator
			return ( !( *this == other ) );
		}




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************






































	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this method to generate a random instance of this object
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          rangeForAsciiCharacter - this will be used to limit the possible size of the random instance
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //      A random generated instance
	        //
	        //  Expectations :
	        //
	        //      NONE
	        //
	        //  Possible errors :
	        //
	        //		They will come
	        //
	        inline AsciiCharacter AsciiCharacter::GenerateRandomInstance( NumericRange< SignedInteger8bits > rangeForAsciiCharacter )
	        {
	        	// Generate random ascii character in the required range, and return a copy of the random instance
	        	return ( Random::Generator::Get< SignedInteger8bits >( rangeForAsciiCharacter ) );
	        }



































// **********************************************************   INLINE AND TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   ***********************************************************



































		// Method Information :
		//
		//  Description :
		//
		//		Use this operator to check if the this instance match the other
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. asciiCharacter - the ascii character to compare with
		//		    2. instance - a reference to the instance that should be compared with the ascii character
		//
		//		Information returned to the user :
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
		inline Boolean operator==( SignedInteger8bits asciiCharacter, const AsciiCharacter& instance )
		{
			// Compare between the ascii characters and return the result
			return ( asciiCharacter == instance.member_asciiCharacter );
		}


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
		//			1. asciiCharacter - the ascii character to compare with
		//		    2. instance - a reference to the instance that should be compared with the ascii character
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
		inline Boolean operator!=( SignedInteger8bits asciiCharacter, const AsciiCharacter& instance )
		{
			// Return the negotiated value from the equal operator
			return ( !( asciiCharacter == instance ) );
		}











	}  //  Namespace Language

}  //  Namespace Universe



#endif  // ASCIICHARACTER_HPP