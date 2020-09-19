#ifndef ASCIISTRING_HPP
#define ASCIISTRING_HPP


#include "../../../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../../../../../ObjectBranch/Content/ObjectInfrastructure/ObjectInfrastructure.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../../../../../../Content/Memory/Operations/Operations.hpp"  //  Class Operations
#include "../../../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../AsciiCharacter/AsciiCharacter.hpp"  //  Class AsciiCharacter
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



        // If a program could assign a pointer of type T** to a pointer of type const T**, a program could inadvertently modify a const object. 
        // For example,
        //
        //      int main() 
        //      {
        //          const char c = 'c';
        //          char* pc = 0;
        //          const char** pcc = &pc;     // not allowed
        //          *pcc = &c;
        //          *pc = 'C';                  // modifies a const object
        //      }
        //
        // The constant comes to state that the function will not modify the given object. The question then is how to achieve this without resolving
        // to ugly casts. The correct way to achieve that is to change the type of the function parameter to 'const pointer* const*'. The additional
        // constant between the stars assures the compiler that the method will not try to store pointers to constant objects in the array, since 
        // this type declares that the pointer values are also constant



		// Class Information :
		//
		//  Purpose :
		//
		//		Use this object to store an ascii string. This is a template specialization for all sequential platforms which their size is not
		//		determined durin compile time
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
		//			1. SequentialPlatformType - the sequential platform type to enforce the ascii string policy on
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
		class AsciiString : public SequentialPlatformType< AsciiCharacter >
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
					return ( CompareTypes< SequentialPlatformType< AsciiCharacter >, Memory::HeapArray< AsciiCharacter > >::Result() || CompareTypes< SequentialPlatformType< AsciiCharacter >, Memory::DynamicArray< AsciiCharacter > >::Result() );
				}


			};


        public:


			// Create a type definition for this object
			using SelfType = AsciiString< SequentialPlatformType >;


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
			inline AsciiString();


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
			//			1. asciiStringSize - the required size for the ascii string
			//			2. asciiCharacter - this ascii character will be used to initialize all the entries
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
			explicit inline AsciiString( UnsignedInteger64bits asciiStringSize, const AsciiCharacter& asciiCharacter = AsciiCharacter() ) :
			SequentialPlatformType< AsciiCharacter >( asciiStringSize, asciiCharacter )
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
			//			1. asciiStringSize - the required size for the ascii string
			//			2. asciiCharacter - this ascii character will be used to initialize all the entries
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
			explicit inline AsciiString( const AsciiCharacter& asciiCharacter ) :
			SequentialPlatformType< AsciiCharacter >( asciiCharacter )
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
			//				1. asciiStringSize - the required size for the ascii string
			//				2. AsciiCharacter - this ascii character will be used to initialize all the entries
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
			explicit inline AsciiString( const Tuple< UnsignedInteger64bits, const AsciiCharacter& >& arguments ) : 
			AsciiString( arguments.template Entry< 0 >(), arguments.template Entry< 1 >() )
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
			//				1. asciiStringSize - the required size for the ascii string
			//				2. AsciiCharacter - this ascii character will be used to initialize all the entries
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
			explicit inline AsciiString( const Tuple< const AsciiCharacter& >& arguments ) : 
			AsciiString( arguments.template Entry< 0 >() )
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
			inline AsciiString( const SelfType& other );


			// This macro will be used to all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
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
			ObjectInfrastructure_ForInheritance_StateTakenFromBaseObject_MACRO( AsciiString< SequentialPlatformType >, SequentialPlatformType< AsciiCharacter > )


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
			//			1. asciiStringSize - the required size for the ascii string
			//			2. asciiCharacter - this ascii character will be used to initialize all the entries
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
			inline void Initiate( UnsignedInteger64bits asciiStringSize, const AsciiCharacter& asciiCharacter = AsciiCharacter() )
			{
			    // Use the required constructor to create an instance. It will be swaped with this instance, leaving this instance with the new data. When sequence control will
			    // leave this scope it delete the old data if exist
			    SelfType instanceCreatedUsingTheRequiredConstructor( asciiStringSize, asciiCharacter );

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
			//			asciiCharacter - this ascii character will be used to initialize all the entries
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
			inline void Initiate( const AsciiCharacter& asciiCharacter = AsciiCharacter() )
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
			virtual ~AsciiString() = default;


			// The following methods are the interface of the object :











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
			//			1. rangeForAsciiStringSize - this will be used to limit the possible values of the size in the random instance
			//			2. rangeForAsciiCharacters - this will be used to limit the possible values of the ascii characters inside in the random instance
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
			static inline SelfType GenerateRandomInstance( NumericRange< UnsignedInteger64bits > rangeForAsciiStringSize = NumericRange< UnsignedInteger64bits >( 1UL, 10000UL ),  NumericRange< SignedInteger8bits > rangeForAsciiCharacters = NumericRange< SignedInteger8bits >( 1, 127 ) );


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
			CompileTimeAssert( ( CompareTypes< SequentialPlatformType< AsciiCharacter >, Memory::HeapArray< AsciiCharacter > >::Result() || 
				                 CompareTypes< SequentialPlatformType< AsciiCharacter >, Memory::DynamicArray< AsciiCharacter > >::Result() ||
				                 CompareTypes< SequentialPlatformType< AsciiCharacter >, Memory::SingleLinkedList< AsciiCharacter > >::Result() || 
				                 CompareTypes< SequentialPlatformType< AsciiCharacter >, Memory::DoubleLinkedList< AsciiCharacter > >::Result() ), "The given template type is not a sequential platform" );


		};  //  Class AsciiString




































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
        inline AsciiString< SequentialPlatformType >::AsciiString() :
		SequentialPlatformType< AsciiCharacter >()
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
        inline AsciiString< SequentialPlatformType >::AsciiString( const AsciiString< SequentialPlatformType >& other ) :
		SequentialPlatformType< AsciiCharacter >( other )
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
		inline void AsciiString< SequentialPlatformType >::Swap( AsciiString< SequentialPlatformType >& other )
		{
			// Swap between the base sequential platform instances
			SequentialPlatformType< AsciiCharacter >::Swap( other );
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
        inline Boolean AsciiString< SequentialPlatformType >::operator==( const AsciiString< SequentialPlatformType >& other ) const
		{
			// Use the compare operator of the base instance
			return ( SequentialPlatformType< AsciiCharacter >::operator==( other ) );
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
        inline Boolean AsciiString< SequentialPlatformType >::operator!=( const AsciiString< SequentialPlatformType >& other ) const
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
		//			1. rangeForAsciiStringSize - this will be used to limit the possible values of the size in the random instance
		//			2. rangeForAsciiCharacters - this will be used to limit the possible values of the ascii characters inside in the random instance
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
		inline AsciiString< SequentialPlatformType > AsciiString< SequentialPlatformType >::GenerateRandomInstance( NumericRange< UnsignedInteger64bits > rangeForAsciiStringSize, NumericRange< SignedInteger8bits > rangeForAsciiCharacters )
		{
			// Create an instance
			SelfType randomInstance;

			// Generate a random instance of the base sequential platform, and store the in the random instance
			*reinterpret_cast< SequentialPlatformType< AsciiCharacter >* >( &randomInstance ) = MOVE( SequentialPlatformType< AsciiCharacter >::GenerateRandomInstance( rangeForAsciiStringSize, rangeForAsciiCharacters ) );

			// Return a copy of the instance
			return ( MOVE( randomInstance ) );
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
			void AsciiString< SequentialPlatformType >::Test()
			{
				// Perform a sanity to ensure that all the methods that are common among all objects, for example defualt constructor, copy constructor,
				// destructor, swap and more, seem to work correctly
				Testing::SanityCheck::Full< AsciiString< Memory::HeapArray > COMMA UnsignedInteger64bits COMMA const AsciiCharacter& >();
				Testing::SanityCheck::Full< AsciiString< Memory::DynamicArray > COMMA UnsignedInteger64bits COMMA const AsciiCharacter& >();
				Testing::SanityCheck::Full< AsciiString< Memory::SingleLinkedList > COMMA const AsciiCharacter& >();
				Testing::SanityCheck::Full< AsciiString< Memory::DoubleLinkedList > COMMA const AsciiCharacter& >();
			}

		)  //  End of debug tool











    }  //  Namespace Language

}  //  Namespace Universe


#endif  // ASCIISTRING_HPP