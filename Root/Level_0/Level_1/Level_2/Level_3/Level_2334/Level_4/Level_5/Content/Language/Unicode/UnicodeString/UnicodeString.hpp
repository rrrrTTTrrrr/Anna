#ifndef UNICODESTRING_HPP
#define UNICODESTRING_HPP


#include "../../../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../../../../../ObjectBranch/Content/ObjectInfrastructure/ObjectInfrastructure.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../../../../../../Content/Memory/Operations/Operations.hpp"  //  Class Operations
#include "../../../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../UnicodeCharacter/UnicodeCharacter.hpp"  //  Class UnicodeCharacter
#include "../../../../../Content/Memory/SequentialPlatforms/HeapArray/HeapArray.hpp"  //  Class HeapArray
#include "../../../../../Content/Memory/SequentialPlatforms/DynamicArray/DynamicArray.hpp"  //  Class DynamicArray
#include "../../../../../Content/Memory/SequentialPlatforms/SingleLinkedList/SingleLinkedList.hpp"  //  Class SingleLinkedList
#include "../../../../../Content/Memory/SequentialPlatforms/DoubleLinkedList/DoubleLinkedList.hpp"  //  Class DoubleLinkedList
#include "../../../../../../../../../../Content/Metaprogramming/Types/CompareTypes/CompareTypes.hpp"  //  Class CompareTypes
#include "../../../../../../Content/BindObjects/Tuple/Tuple.hpp"  //  Class Tuple
#include "../../../../../../../Content/Random/Generator/Generator.hpp"  //  Class Generator
#include "../../../../../../../Content/NumericRange/NumericRange.hpp"  //  Class NumericRange


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../../../../../../../../TestBranch/SanityCheck/SanityCheck.hpp"  //  Class SanityCheck
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



	    // A virtual function or virtual method is a function or method whose behavior can be overridden within an inheriting class by a function with the 
	    // same signature, whereas..
	    //
	    // A pure virtual function or pure virtual method is a virtual function that is required to be implemented by a derived class that is not abstract!



	    // Abstract classes and construction of such
	    //
	    // An abstract class cannot be instantiated. He must be inherited in order to have it's constructor called, and since the derived class calls the 
	    // constructor of the abstract class it doesn't matter what is the protection level, as long as the Derived class can access it.
	    //
	    // So it doesn't matter if the constructor is public or protected. One reason that one could possibly have for making it protected is to serve as 
	    // a reminder that the class must be constructed through inheritance



	    // A pure virtual function must be implemented in a derived type that will be directly instantiated, however the base type can still define an 
	    // implementation. A derived class can explicitly call the base class implementation ( if access permissions allow it ) by using a fully-scoped 
	    // name.
	    //
	    // The use case is when there's a more-or-less reasonable default behavior, but the class designer wants that sort-of-default behavior be invoked
	    // only explicitly. It can also be the case what you want derived classes to always perform their own work but also be able to call a common set 
	    // of functionality



	    // The 3 dots function argument, for example :
	    //
	    //  void function( int index, ... )
	    //
	    // They usually mark the function as having a variable number of arguments. In a real system, however, a system call can’t actually have a variable
	    // number of arguments. System calls must have a well-defined prototype, because user programs can access them only through hardware “gates”. 
	    // Therefore, the dots in the prototype represent not a variable number of arguments but a single optional argument, traditionally identified as 
	    // char *argp. The dots are simply there to prevent type checking during compilation. Using a pointer is the way to pass arbitrary data to the function



	    // There are two ways to look at inline functios :
	    //
	    //  1. Inline functions are declared in the header because, in order to inline a function call, the compiler must be able to see the function body. 
	    //     For a naive compiler to do that, the function body must be in the same translation unit as the call. ( A modern compiler can optimize across 
	    // 	   translation units, and so a function call may be inlined even though the function definition is in a separate translation unit, but these 
	    //	   optimizations are expensive, aren't always enabled, and weren't always supported by the compiler )
	    //
	    //  2. Functions declared in the header must be marked inline because otherwise, every translation unit which includes the header will contain a 
	    //	   definition of the function, and the linker will complain about multiple definitions ( a violation of the One Definition Rule ). The inline 
	    //	   keyword suppresses this, allowing multiple translation units to contain ( identical ) definitions
	    //
	    // The two explanations really boil down to the fact that the inline keyword doesn't exactly do what you'd expect.
	    //
	    // A C++ compiler is free to apply the inlining optimization ( replace a function call with the body of the called function, saving the call 
	    // overhead ) any time it likes, as long as it doesn't alter the observable behavior of the program.
	    //
	    // The inline keyword makes it easier for the compiler to apply this optimization, by allowing the function definition to be visible in multiple
	    // translation units, but using the keyword doesn't mean the compiler has to inline the function, and not using the keyword doesn't forbid the 
	    // compiler from inlining the function



		// Class Information :
		//
		//  Purpose :
		//
		//		Artifical Inteligence
		//
   	    //  Description :
   	    //
		//		1. This object is used as a base object in inheritance. Therefore it must have a few methods virtual. When an object has a virtual method, the
		//		   C++ automatically creates a table with all the pointers to the virtual methods, where the pointer to the table is stored in the beginning of
		//		   the object. The problem arises when a new method needs to be created with the same signature as one in the base object, and the use of pointers.
		//		   Take a look at next example :
		//
		//				class Base
		//				{
		//				    void Display() { cout << "Lord" << endl; }
		//				};
		//
		//				class Derived : public Base
		//				{
		//				    void Display(); { cout << "Help Me" << endl; }    -> Derived inherits Display from Base but needs another behavior
		//				};
		//
		//         Now if a call is made :
		//
		//				Base* base = new Base;
		//				Derived* derived = new Derived;
		//
		//				base->Display( 5 );   -> Outputs "Lord"
		//				derived->Display();   -> Outputs "Help Me"
		//
		//         So far so good, a normal method is called by the static type of the pointer. This means no matter what the object the pointer is
		//		   pointing to it will call the method of the type he was declared as. This is a problematic behavior in inheritance, we need to point
		//		   to derived objects with base pointers and that the correct method will be called. But now :
		//
		//				void Do( Base* base ) { base->Display(); }
		//
		//				Base* base = new Base;
		//				Derived* derived = new Derived;
		//
		//				Do( base );        -> Outputs "Lord"
		//				Do( derived );     -> Outputs "Lord"
		//
		//         This is what virtual allow in C++, instead of calling the method by the static type in compilation, the call to the method is picked
		//		   dynamically by the actual type of the object. This is done by the pointer in the beginning of the object that points to the virtual
		//		   table of the type. Of course it can be overloaded to the derived, but then if there is a deep inheritance a method will be needed to
		//		   be overloaded for each one
		//
		//		2. This object contains an instance of the object "InstanceState" to allow each instance of this object to have a defined state
		//
		//		3. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
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
		//		4. Template arguments :
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
		template< template< typename > class SequentialPlatformType >
        class UnicodeString : public SequentialPlatformType< UnicodeCharacter >
        {
		private:


			// The following object will be used to determine if the specific sequential platform type supplied as the template argument. It divides
			// into 2 groups. The first are the contigous memory area sequential platforms, which has a constructor that accept also the size to
			// allocate, this are 'HeapArray' and 'DynamicArray'. The second group are the sequential platforms that only accept one single data at
			// the constructor, and initialize the instance with one data, this are 'SingleLinkedList' and 'DoubleLinkedList'. Then this object will
			// help in determining the required constructor for the given sequential platform. This is needed because this object is a template, 
			// therefore the deduction of the template type is done on the all object and before the constructor declaration. To workaround this 
			// issue the constructor must have also a template parameter, to make the compiler perform the template type deduction on the constructor 
			// itself
			template< typename DummyType >
			class TypeCheck__Private
			{
			public:


				// This is the method that will do the actual checking. It will check if the template types is array based or linked list based 
				// sequential platform
				static constexpr Boolean TrueForArrayBasedSequentialPlatformAndFalseForLinkedListBasedSequentialPlatform()
				{
					// Check if the template types is array based or linked list based sequential platform
					return ( CompareTypes< SequentialPlatformType< UnicodeCharacter >, Memory::HeapArray< UnicodeCharacter > >::Result() || CompareTypes< SequentialPlatformType< UnicodeCharacter >, Memory::DynamicArray< UnicodeCharacter > >::Result() );
				}


			};


        public:


            // Create a type definition for this object
			using SelfType = UnicodeString< SequentialPlatformType >;


			// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
			// the compiler generates a basic behavior for them if possible :


			// Method Information :
			//
			//  Description :
			//
			//   	Default Constructor
			//
			//  Required arguments :
			//
			//   	User information needed :
			//
			//          NONE
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
			inline UnicodeString();


			// Method Information :
			//
			//  Description :
			//
			//		Constructor, this will only be available when the sequential platform are array based!
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. unicodeStringSize - the required size for the unicode string
			//			2. unicodeCharacter - this unicode character will be used to initialize all the entries
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
			template< typename DummyType = void, typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck__Private< DummyType >::TrueForArrayBasedSequentialPlatformAndFalseForLinkedListBasedSequentialPlatform(), Boolean >::Type = true >
			explicit inline UnicodeString( UnsignedInteger64bits unicodeStringSize, const UnicodeScalarValue& unicodeCharacter = UnicodeScalarValue() ) :
			SequentialPlatformType< UnicodeScalarValue >( unicodeStringSize, unicodeCharacter )
			{}


			// Method Information :
			//
			//  Description :
			//
			//		Constructor, this will only be available when the sequential platform are linked list based!
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. unicodeStringSize - the required size for the unicode string
			//			2. unicodeCharacter - this unicode character will be used to initialize all the entries
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
			template< typename DummyType = void, typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck__Private< DummyType >::TrueForArrayBasedSequentialPlatformAndFalseForLinkedListBasedSequentialPlatform() == false, Boolean >::Type = true >
			explicit inline UnicodeString( const UnicodeScalarValue& unicodeCharacter ) :
			SequentialPlatformType< UnicodeScalarValue >( unicodeCharacter )
			{}


			// Method Information :
			//
			//  Description :
			//
			//		Constructor, to allow creating an instance with the same arguments as the parameterized constructor, just that the arguments will be
			//		wrapped in a tuple, to allow more automatic creation of instances. Each parameterized constructor will have an equivalent constructor
			//		to inokve with a tuple, which will only call the required constructor and unpack the tuple to the arguments inisde
			//
			//		this will only be available when the sequential platform are array based!
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			arguments - the arguments needed to construct an instance, only wrapped in a tuple. The arguments are :
			//
			//				1. unicodeStringSize - the required size for the unicode string
			//				2. UnicodeScalarValue - this unicode character will be used to initialize all the entries
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
			template< typename DummyType = void, typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck__Private< DummyType >::TrueForArrayBasedSequentialPlatformAndFalseForLinkedListBasedSequentialPlatform(), Boolean >::Type = true >
			explicit inline UnicodeString( const Tuple< UnsignedInteger64bits, const UnicodeScalarValue& >& arguments ) : 
			UnicodeString( arguments.template Entry< 0 >(), arguments.template Entry< 1 >() )
			{}


			// Method Information :
			//
			//  Description :
			//
			//		Constructor, to allow creating an instance with the same arguments as the parameterized constructor, just that the arguments will be
			//		wrapped in a tuple, to allow more automatic creation of instances. Each parameterized constructor will have an equivalent constructor
			//		to inokve with a tuple, which will only call the required constructor and unpack the tuple to the arguments inisde
			//
			//		this will only be available when the sequential platform are linked list based!
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			arguments - the arguments needed to construct an instance, only wrapped in a tuple. The arguments are :
			//
			//				1. unicodeStringSize - the required size for the unicode string
			//				2. UnicodeScalarValue - this unicode character will be used to initialize all the entries
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
			template< typename DummyType = void, typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck__Private< DummyType >::TrueForArrayBasedSequentialPlatformAndFalseForLinkedListBasedSequentialPlatform() == false, Boolean >::Type = true >
			explicit inline UnicodeString( const Tuple< const UnicodeScalarValue& >& arguments ) : 
			UnicodeString( arguments.template Entry< 0 >() )
			{}


			// Method Information :
			//
			//  Description :
			//
			//   	Copy constructor, will operate correctly even if the other object is in default state
			//
			//  Required arguments :
			//
			//   	User information needed :
			//
			//          other - a reference to the instance that should be copied
			//
			//		Information returned to the user :
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
			inline UnicodeString( const SelfType& other );


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
			ObjectInfrastructure_ForInheritance_StateTakenFromBaseObject_MACRO( UnicodeString< SequentialPlatformType >, SequentialPlatformType< UnicodeCharacter > )


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
			//          other - a reference to the instance that should be swaped
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
			//      User information needed :
			//
			//			1. unicodeStringSize - the required size for the unicode string
			//			2. unicodeCharacter - this unicode character will be used to initialize all the entries
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
			//		NONE
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			template< typename DummyType = void, typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck__Private< DummyType >::TrueForArrayBasedSequentialPlatformAndFalseForLinkedListBasedSequentialPlatform(), Boolean >::Type = true >
			inline void Initiate( UnsignedInteger64bits unicodeStringSize, const UnicodeCharacter& unicodeCharacter = UnicodeCharacter() )
			{
			    // Use the required constructor to create an instance. It will be swaped with this instance, leaving this instance with the new data. When sequence control will
			    // leave this scope it delete the old data if exist
			    SelfType instanceCreatedUsingTheRequiredConstructor( unicodeStringSize, unicodeCharacter );

			    // Swap between this instance and the temporary instance
			    Swap( instanceCreatedUsingTheRequiredConstructor );
			}


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			unicodeCharacter - this unicode character will be used to initialize all the entries
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
			//		NONE
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			template< typename DummyType = void, typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck__Private< DummyType >::TrueForArrayBasedSequentialPlatformAndFalseForLinkedListBasedSequentialPlatform() == false, Boolean >::Type = true >
			inline void Initiate( const UnicodeCharacter& unicodeCharacter = UnicodeCharacter() )
			{
			    // Use the required constructor to create an instance. It will be swaped with this instance, leaving this instance with the new data. When sequence control will
			    // leave this scope it delete the old data if exist
			    SelfType instanceCreatedUsingTheRequiredConstructor( unicodeCharacter );

			    // Swap between this instance and the temporary instance
			    Swap( instanceCreatedUsingTheRequiredConstructor );
			}


			// Method Information :
			//
			//  Description :
			//
			//   	Destructor, does not throw. Declared virtual to ensure correct deletion for derived objects
			//
			//  Required arguments :
			//
			//   	User information needed :
			//
			//          NONE
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
			virtual ~UnicodeString() = default;


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
			//          other - a reference to the instance that should be compared with this object
			//
			//      Information returned to the user :
			//
			//          NONE
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
			inline Boolean operator==( const SelfType& other ) const;


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
			//          other - a reference to the instance that should be compared with this object
			//
			//      Information returned to the user :
			//
			//          NONE
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
			//		User information needed :
			//
			//			1. rangeForUnicodeStringSize - this will be used to limit the possible values of the size in the random instance
			//			2. rangeForUnicodeCharacters - this will be used to limit the possible values of the unicode characters inside in the random instance
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		A random generated instance
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			static inline UnicodeString< SequentialPlatformType > GenerateRandomInstance( NumericRange< UnsignedInteger64bits > rangeForUnicodeStringSize, NumericRange< UnsignedInteger32bits > rangeForUnicodeCharacters );


			DEBUG_TOOL(

				// This part of the object is dedicated for testing :


				// Method Information :
				//
				//  Description :
				//
				//      This method is used to test the object. It is not part of the implementation, it is only used to find problems with the code
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


			// Assert all the requirements on the template arguments provided to the object. To perform a compile time assert the C++ language provides
			// the keyword 'static_assert', which receives an expression and an error message to display if the expression result is false. The important
			// thing is that the expression is evaluted during compile time, and therefore if the expression is false the compilation will be terminated
			// and the error message will be displayed. This method should not be used, because it does nothing during run time
			CompileTimeAssert( ( CompareTypes< SequentialPlatformType< UnicodeCharacter >, Memory::HeapArray< UnicodeCharacter > >::Result() || 
				                 CompareTypes< SequentialPlatformType< UnicodeCharacter >, Memory::DynamicArray< UnicodeCharacter > >::Result() ||
				                 CompareTypes< SequentialPlatformType< UnicodeCharacter >, Memory::SingleLinkedList< UnicodeCharacter > >::Result() || 
				                 CompareTypes< SequentialPlatformType< UnicodeCharacter >, Memory::DoubleLinkedList< UnicodeCharacter > >::Result() ), "The given template type is not a sequential platform" );


		};  //  Class UnicodeString




































//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************




































		// Method Information :
		//
		//  Description :
		//
		//   	Default Constructor
		//
		//  Required arguments :
		//
		//   	User information needed :
		//
		//          NONE
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
		template< template< typename > class SequentialPlatformType >
        inline UnicodeString< SequentialPlatformType >::UnicodeString() :
		SequentialPlatformType< UnicodeCharacter >()
		{}


		// Method Information :
		//
		//  Description :
		//
		//   	Copy constructor, will operate correctly even if the other instance is in default state or self assignment
		//
		//  Required arguments :
		//
		//   	User information needed :
		//
		//          other - a reference to the instance that should be copied
		//
		//		Information returned to the user :
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
		template< template< typename > class SequentialPlatformType >
        inline UnicodeString< SequentialPlatformType >::UnicodeString( const SelfType& other ) :
		SequentialPlatformType< UnicodeCharacter >( other )
		{}


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
		//          other - a reference to the instance that should be swaped
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
		//		NONE
		//
		//  Possible errors :
		//
		//      They will come
		//
		template< template< typename > class SequentialPlatformType >
		inline void UnicodeString< SequentialPlatformType >::Swap( SelfType& other )
		{
			// Swap between the base sequential platform instances
			SequentialPlatformType< UnicodeCharacter >::Swap( other );
		}


		// Method Information :
		//
		//  Description :
		//
	    // 		Use to check the amount of bytes would take to compress the unicode character as UTF-8    	
	    //
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			NONE
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//   	The amount of bytes that would take to compress the unicode character into UTF-8
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		NONE
		//
		template< template< typename > class SequentialPlatformType >
	    inline UnsignedInteger64bits UnicodeString< SequentialPlatformType >::GetNumberOfBytesNeededToStoreTheCompressedUnicodeStringAs_UTF8() const
	    {
	    	// This object will store the number of bytes needed to compress the unicode string into UTF-8
	    	UnsignedInteger64bits numberBytesNeededToCompressUnicodeStringAs_UTF8 = 0UL;

	    	// Loop on all the unicode characters
	    	for ( UnsignedInteger64bits unicodeStringIndex = 0UL ; unicodeStringIndex < member_unicodeString.Size() ; ++unicodeStringIndex )
	    	{
				// Get the number of bytes needed to compress the current unicode character as UTF-8, and add it to the total number
				numberBytesNeededToCompressUnicodeStringAs_UTF8 += member_unicodeString[ unicodeStringIndex ].GetNumberOfBytesNeededToStoreTheCompressedUnicodeStringAs_UTF8();
	    	}

	    	// Return the number of bytes needed to compress the unicode string into UTF-8
	    	return ( numberBytesNeededToCompressUnicodeStringAs_UTF8 );
	    }


		// Method Information :
		//
		//  Description :
		//
	    // 		Use to check the amount of bytes would take to compress the unicode character as UTF-16
	    //
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			NONE
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//   	The amount of bytes that would take to compress the unicode character into UTF-16
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		NONE
		//
		template< template< typename > class SequentialPlatformType >
	    inline UnsignedInteger64bits UnicodeString< SequentialPlatformType >::GetNumberOfBytesNeededToStoreTheCompressedUnicodeStringAs_UTF16() const
	    {
	    	// This object will store the number of bytes needed to compress the unicode string into UTF-16
	    	UnsignedInteger64bits numberBytesNeededToCompressUnicodeStringAs_UTF16 = 0UL;

	    	// Loop on all the unicode characters
	    	for ( UnsignedInteger64bits unicodeStringIndex = 0UL ; unicodeStringIndex < member_unicodeString.Size() ; ++unicodeStringIndex )
	    	{
				// Get the number of bytes needed to compress the current unicode character as UTF-16, and add it to the total number
				numberBytesNeededToCompressUnicodeStringAs_UTF16 += member_unicodeString[ unicodeStringIndex ].GetNumberOfBytesNeededToStoreTheCompressedUnicodeStringAs_UTF16();
	    	}

	    	// Return the number of bytes needed to compress the unicode string into UTF-16
	    	return ( numberBytesNeededToCompressUnicodeStringAs_UTF16 );
	    }


		// Method Information :
		//
		//  Description :
		//
		// 		Use to compress the unicode string as UTF-8
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			destinationToStore_UTF8_compression - a pointer to the memory address where to store the unicode string compressed as UTF-8
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	The number of bytes needed to compress the unicode string as UTF-8
		//
		//	Expectations :
	    //
	    //		1. The given pointer is not NULL
	    //		2. The given pointer point to enough memory space to compress as UTF-8 ( there is no way to validate this at this level )
	    //		3. 
	    //
		//  Possible errors :
		//
		//		NONE
	    //
		template< template< typename > class SequentialPlatformType >
		inline void UnicodeString< SequentialPlatformType >::::CompressAs_UTF8( UnsignedInteger8bits* destinationToStore_UTF8_compression ) const
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertPointer_MACRO( destinationToStore_UTF8_compression )

			// This object will store the current number of bytes needed to compress as UTF-8
			UnsignedInteger64bits numberOfBytesNeededToCompressAs_UTF8_currentUnicdoeCharacter = 0UL;

			// Loop on all the unicode characters of the unicode string
	    	for ( UnsignedInteger64bits unicodeStringIndex = 0UL ; unicodeStringIndex < member_unicodeString.Size() ; ++unicodeStringIndex )
	    	{
	    		// Compress the current unicode character and store at the destination
				numberOfBytesNeededToCompressAs_UTF8_currentUnicdoeCharacter = member_unicodeString[ unicodeStringIndex ].CompressAs_UTF8( destinationToStore_UTF8_compression );

				// Advance the pointer to the location to store the next unicode character
				destinationToStore_UTF8_compression += numberOfBytesNeededToCompressAs_UTF8_currentUnicdoeCharacter;
			}

		}


		// Method Information :
		//
		//  Description :
		//
		// 		Use to compress the unicode string as UTF-16
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			destinationToStore_UTF16_compression - a pointer to the memory address where to store the unicode string compressed as UTF-16
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	The number of bytes needed to compress the unicode string as UTF-16
		//
		//	Expectations :
	    //
	    //		1. The given pointer is not NULL
	    //		2. The given pointer point to enough memory space to compress as UTF-16 ( there is no way to validate this at this level )
	    //		3. 
	    //
		//  Possible errors :
		//
		//		NONE
	    //
		template< template< typename > class SequentialPlatformType >
		void UnicodeString< SequentialPlatformType >::CompressAs_UTF16( UnsignedInteger16bits* destinationToStore_UTF16_compression ) const
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertPointer_MACRO( destinationToStore_UTF16_compression )

			// This object will store the current number of bytes needed to compress as UTF-16
			UnsignedInteger64bits numberOfBytesNeededToCompressAs_UTF16_currentUnicdoeCharacter = 0UL;

			// Loop on all the unicode characters of the unicode string
	    	for ( UnsignedInteger64bits unicodeStringIndex = 0UL ; unicodeStringIndex < member_unicodeString.Size() ; ++unicodeStringIndex )
	    	{
	    		// Compress the current unicode character and store at the destination
				numberOfBytesNeededToCompressAs_UTF16_currentUnicdoeCharacter = member_unicodeString[ unicodeStringIndex ].CompressAs_UTF16( destinationToStore_UTF16_compression );

				// Advance the pointer to the location to store the next unicode character
				destinationToStore_UTF16_compression += numberOfBytesNeededToCompressAs_UTF8_currentUnicdoeCharacter;
			}

		}


		// Method Information :
		//
		//  Description :
		//
		// 		Use to decode UTF-8 into a unicode scalar value and store inside this instance
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			UTF8_compression - a pointer to the memory address where the unicode scalar value compressed as UTF-8 is stored
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	The number of bytes the compressed unicode scalar value as UTF-8 contains
		//
		//	Expectations :
	    //
	    //		1. The given pointer is not NULL
	    //		2. The given UTF-8 is compressed correctly
	    //		3. 
	    //
		//  Possible errors :
		//
		//		NONE
	    //
	    template< template< typename > class SequentialPlatformType >
		UnsignedInteger64bits UnicodeString< SequentialPlatformType >::DecompressFrom_UTF8( const UnsignedInteger8bits* UTF8_compression )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertPointer_MACRO( UTF8_compression )

			// This object will store the size needed to be allocated in order to store the decompressed UTF-8 unicode string	
			UnsignedInteger64bits decompressedUnicodeStringSize = GetNumberOfBytesNeededToStoreTheCompressedUnicodeStringAs_UTF8( UTF8_compression, sizeInBytes_UTF8_compression );

			
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
		//          other - a reference to the instance that should be compared with this object
		//
		//      Information returned to the user :
		//
		//          NONE
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
		template< template< typename > class SequentialPlatformType >
        inline Boolean UnicodeString< SequentialPlatformType >::operator==( const SelfType& other ) const
		{
			// Use the compare operator of the base instance
			return ( SequentialPlatformType< UnicodeCharacter >::operator==( other ) );
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
		//          other - a reference to the instance that should be compared with this object
		//
		//      Information returned to the user :
		//
		//          NONE
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
		template< template< typename > class SequentialPlatformType >
        inline Boolean UnicodeString< SequentialPlatformType >::operator!=( const SelfType& other ) const
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
		//		User information needed :
		//
		//			1. rangeForUnicodeStringSize - this will be used to limit the possible values of the size in the random instance
		//			2. rangeForUnicodeCharacters - this will be used to limit the possible values of the unicode characters inside in the random instance
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		A random generated instance
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< template< typename > class SequentialPlatformType >
		inline UnicodeString< SequentialPlatformType > UnicodeString< SequentialPlatformType >::GenerateRandomInstance( NumericRange< UnsignedInteger64bits > rangeForUnicodeStringSize, NumericRange< UnsignedInteger32bits > rangeForUnicodeCharacters )
		{
			// Create an instance
			SelfType randomInstance;

			// Generate a random instance of the base sequential platform, and store the in the random instance
			*reinterpret_cast< SequentialPlatformType< UnicodeCharacter >* >( &randomInstance ) = MOVE( SequentialPlatformType< UnicodeCharacter >::GenerateRandomInstance( rangeForUnicodeStringSize, rangeForUnicodeCharacters ) );

			// Return a copy of the instance
			return ( MOVE( randomInstance ) );
		}




































//  ********************************************************   TEMPLATE OR INLINE PURE VIRTUAL METHODS IMPLEMENTATION   *********************************************************




































//	**********************************************************   TEMPLATE OR INLINE PROTECTED METHODS IMPLEMENTATION   **********************************************************




































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************






































		// Method Information :
		//
		//  Description :
		//
		//		Use to get the amount of bytes needed to compress the unicode scalar value as UTF-8
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			1. UTF8_compression - a pointr to the memory address with a unicode scalar value compressd into UTF-8
		//			2. sizeInBytes_UTF8_compression - the size in bytes of the UTF-8 compression
		//
		//      Information returned to the user :
		//
		//            NONE
		//
		//  Return value :
		//
		//   	The amount of bytes needed to compress the unicode scalar value as UTF-8
		//
		//  Expectations :
		//
		//		1. The given pointer is not NULL
		//		2. The given UTF-8 was compressd correctly
		//		3. The given size should be larger then 0
		//		4. 
		//
		//  Possible errors :
		//
		//		NONE
	    //
		template< template< typename > class SequentialPlatformType >
		inline UnsignedInteger64bits UnicodeString< SequentialPlatformType >::GetNumberOfBytesNeededToStoreTheCompressedUnicodeStringAs_UTF8( const UnsignedInteger8bits* UTF8_compression, UnsignedInteger64bits sizeInBytes_UTF8_compression )
		{
			// This object will store the size needed to be allocated in order to store the decompressed unicode string	
			UnsignedInteger64bits decompressedUnicodeStringSize = 0UL;

			// This object will store the number of bytes needed to compress the current unicode scalar value
			UnsignedInteger64bits numberBytesNeededToCompressCurrentUnicodeScalarValueAs_UTF8 = 0UL;

			// Loop on all the unicode characters of the unicode string
	    	for ( UnsignedInteger64bits UTF8_compressionIndex = 0UL ; UTF8_compressionIndex < sizeInBytes_UTF8_compression ; UTF8_compressionIndex += numberBytesNeededToCompressCurrentUnicodeScalarValueAs_UTF8 )
	    	{
	    		// Get the number of bytes needed to compress the current unicode scalar value
	    		numberBytesNeededToCompressCurrentUnicodeScalarValueAs_UTF8 = UnicodeCharacter::GetNumberOfBytesNeededToStoreTheCompressedUnicodeCharacterAs_UTF8( UTF8_compression );

	    		// Increment by 1 the number of decompressed unicode string size
	    		decompressedUnicodeStringSize += 1UL;
	    	}

	    	// Return the size that decompressed unicode string will hold
	    	return ( decompressedUnicodeStringSize );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use to get the amount of pair bytes, each element in UTF-16 takes at least two bytes, needed to compress the unicode scalar value as UTF-16
		//
		//  Required arguments :
		//
	    //   	User information needed :
		//
		//			1. UTF16_compression - a pointr to the memory address with a unicode scalar value compressd into UTF-16
		//			2. sizeInPairBytes_UTF16_compression - the size in bytes of the UTF-16 compression
		//
		//      Information returned to the user :
		//
		//            NONE
		//
		//  Return value :
		//
		//   	The amount of pair bytes, each element in UTF-16 takes at least two bytes, needed to compress the unicode scalar value as UTF-16
		//
		//  Expectations :
		//
		//		1. The given pointer is not NULL
		//		2. The given UTF-16 was compressd correctly
		//		3. The given size should be larger then 0
		//		4. 
		//
		//  Possible errors :
		//
		//		NONE
	    //
		template< template< typename > class SequentialPlatformType >
		inline UnsignedInteger64bits UnicodeString< SequentialPlatformType >::GetNumberOfPairBytesNeededToStoreTheCompressedUnicodeCharacterAs_UTF16( const UnsignedInteger16bits* UTF16_compression, UnsignedInteger64bits sizeInPairBytes_UTF16_compression )
		{
			// This object will store the size needed to be allocated in order to store the decompressed unicode string	
			UnsignedInteger64bits decompressedUnicodeStringSize = 0UL;

			// This object will store the number of bytes needed to compress the current unicode scalar value
			UnsignedInteger64bits numberBytesNeededToCompressCurrentUnicodeScalarValueAs_UTF16 = 0UL;

			// Loop on all the unicode characters of the unicode string
	    	for ( UnsignedInteger64bits UTF16_compressionIndex = 0UL ; UTF16_compressionIndex < sizeInPairBytes_UTF8_compression ; UTF16_compressionIndex += numberBytesNeededToCompressCurrentUnicodeScalarValueAs_UTF16 )
	    	{
	    		// Get the number of bytes needed to compress the current unicode scalar value
	    		numberBytesNeededToCompressCurrentUnicodeScalarValueAs_UTF16 = UnicodeCharacter::GetNumberOfPairBytesNeededToStoreTheCompressedUnicodeCharacterAs_UTF16( UTF16_compression );

	    		// Increment by 1 the number of decompressed unicode string size
	    		decompressedUnicodeStringSize += 1UL;
	    	}

	    	// Return the size that decompressed unicode string will hold
	    	return ( decompressedUnicodeStringSize );
		}





































// ***************************************************************   NESTED CLASS PUBLIC METHODS IMPLEMENTATION -    ************************************************************




































// **********************************************************   INLINE AND TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   ***********************************************************




































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
			//          NONE
			//
			//      Information returned to the user :
			//
			//          NONE
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
			//		1. An assertion failed - class Exception is thrown
			//		2. There is no more free memory space - class std::bad_alloc is thrown
			//		3. 
			//
			template< template< typename > class SequentialPlatformType >
			void UnicodeString< SequentialPlatformType >::Test()
			{
				// Perform a sanity to ensure that all the methods that are common among all objects, for example defualt constructor, copy constructor,
				// destructor, swap and more, seem to work correctly
				Testing::SanityCheck::Full< SelfType,  >();
			}

		)  //  End of debug tool











    }  //  Namespace Language

}  //  Namespace Universe


#endif  // UNICODESTRING_HPP