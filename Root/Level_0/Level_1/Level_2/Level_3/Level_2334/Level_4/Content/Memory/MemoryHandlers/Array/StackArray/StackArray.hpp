#ifndef STACKARRAY_HPP
#define STACKARRAY_HPP


#include "../../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA, Macro CompileTimeAssert
#include "../../../../../../../../../Content/Object/ObjectInfrastructure/BasicObjectFunctionality/BasicObjectFunctionality.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../../../../../../../../Content/Object/ObjectInfrastructure/GetAndSetForMembers/GetAndSetForMembers.hpp"  //  Macro VirtualGetByReferenceOnlyIfInstanceIsReady_MACRO
#include "../../../../../../../Content/Memory/Operations/Operations.hpp"  //  Class Operations
#include "../../../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../../../../../../../../Content/Metaprogramming/MetaprogrammingMacros/MetaprogrammingMacros.hpp"  //  Macro MOVE
#include "../../../../../../../Content/Interfaces/AccessDataUsingIndices_Interface/AccessDataUsingIndices_Interface.hpp"  //  Class AccessDataUsingIndices_Interface
#include "../../../../../../../../../Content/Metaprogramming/Types/PerformActionAccordingToType/PerformActionAccordingToType.hpp"  //  Class PerformActionAccordingToType
#include "../../../../../../Content/BindObjects/Tuple/Tuple.hpp"  //  Class Tuple
#include "../../../../../../../Content/Random/Generator/Generator.hpp"  //  Class Generator
#include "../../../../../../../Content/NumericRange/NumericRange.hpp"  //  Class NumericRange


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../../../../../../../../../Test/GeneralTests/SanityCheck/SanityCheck.hpp"  //  Class SanityCheck
#include "../../../../../../../../../../../Test/TestingTools/Objects/TestObject_1/TestObject_1.hpp"  //  Class TestObject_1
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



    namespace Memory
    {



        // There are two versions of using the operator new :
        //
        //      new unsigned int;       // default initialized ( nothing happens )
        //      new unsigned int();     // zero initialized ( set to 0 )
        //
        // Also works for arrays :
        //
        //      new unsigned int[5];    // default initialized ( nothing happens )
        //      new unsigned int[5]();  // zero initialized ( all elements set to 0 )



        // Both "class" and "typename" within C++ indicate a type parameter since the keywords do not hold any platform significance – for example, class is not meant to 
        // suggest a native type nor is typename meant to suggest a CLI type. Rather, both equivalently indicate that the name following represents a parameterized type 
        // placeholder that will be replaced by a user-specfied actual type. The reason for the two keywords is historical. In the original template specification, 
        // Stroustrup reused the existing class keyword to specify a type parameter rather than introduce a new keyword that might of course break existing programs. It wasn’t
        // that a new keyword wasn’t considered — just that it wasn’t considered necessary given its potential disruption. And up until the ISO-C++ standard, this was the only 
        // way to declare a type parameter. Reuses of existing keywords seems to always sow confusion. What we found is that beginners were whether the use of the class 
        // constrained or limited the type arguments a user could specify to be class types rather than, say, a built-in or pointer type. So, there was some feeling that not 
        // having introduced a new keyword was a mistake. During standardization, certain constructs were discovered within a template definition that resolved to expressions 
        // although they were meant to indicate declarations. For example,
        //
        //          template <class T>
        //
        //          class Demonstration {
        //
        //          public:
        //
        //              void method() {
        //  
        //                  T::A *aObj; // oops …
        //
        //                  // …
        //
        //         };
        //
        //
        // While the statement containing aObj is intended by the programmer to be interpreted as the declaration of a pointer to a nested type A within the type parameter T, 
        // the language grammar interprets it as an arithmetic expression multiplying the static member A of type T with aObj and throwing away the result. Isn’t that annoying! 
        // ( This sort of dilemna is not possible within generics – there is no way to safely verify that any T contains an A so that the runtime can safely construct an instance 
        // of the generic type ). The committee decided that a new keyword was just the ticket to get the compiler off its unfortunate obsession with expressions. The new keyword 
        // was the self-describing typename. When applied to a statement, such as,
        //
        //
        //          typename T::A* a6; // declare pointer to T’s A
        //
        //
        // it instructs the compiler to treat the subsequent statement as a declaration. Since the keyword was on the payroll, heck, why not fix the confusion caused by the original 
        // decision to reuse the class keyword. Of course, given the extensive body of existing code and books and articles and talks and postings using the class keyword, they chose 
        // to also retain support for that use of the keyword as well. So that’s why you have both



        // The main point of an object is to manage resources ( In theory every object should maintain one and only one resource ), one of the important aspects of managing
        // a resource is performance, the amount of time every operation take should be as minimal as possible, the basic operations should take almost the same as when 
        // working with the resource without the object covering it



        // top-level const qualifier affects the object itself. Others are only relevant with pointers and references. They do not make the object const, and only prevent 
        // modification through a path using the pointer or reference. Thus :
        //
        //      char x;
        //
        //      char const* p = &x;
        //
        // This is not a top-level const, and none of the objects are immutable. The expression *p cannot be used to modify x, but other expressions can be; x is not const. 
        // For that matter :
        //
        //      *const_cast< char* >( p ) = 't';
        //
        // is legal and well defined.
        //
        // But,
        //
        //      char const x = 't';
        //
        //      char const* p = &x;
        //
        // This time, there is a top-level const on x, so x is immutable. No expression is allowed to change it ( even if const_cast is used ). The compiler may put x in 
        // read-only memory, and it may assume that the value of x never changes, regardless of what other code may do.
        // 
        // To give the pointer top-level const, you'd write:
        //
        //      char x = 't';
        //
        //      char *const p = &x;
        //
        // In this case, p will point to x forever; any attempt to change this is undefined behavior ( and the compiler may put p in read-only memory, or assume that *p refers 
        // to x, regardless of any other code )



        // Two method can have the same signature except that one is const and the other is not. The const method will be called on const objects and the non const method is 
        // called on non-const objects. C++ allows member methods to be overloaded on the basis of const type. Overloading on the basis of const type can be useful when a 
        // function return reference or pointer. It is possible to make one function const, that returns a const reference or const pointer, other non-const function, that 
        // returns non-const reference or pointer



        // In C++ any of the following 38 operators can be overloaded :
        //
        //  "+", "-", "*", "/", "%", "^", "&", "|", "~", "!", "=", "<", ">", "+=", "-=", "*=", "/=", "%=", "^=", "&=", "|=", "<<", ">>", ">>=", "<<="
        //  "==", "!=", "<=", ">=", "&&", "||", "++", "--", ",", "->*", "->", "( )", "[ ]"
        //
        // Assignment operator ( = ), curel brackets operator ( () ), square brackets opeartor ( [] ), and pointer dereference operator ( -> ) can 
        // not be non members!!



        // When aggregate initializers ( initializers in {} ) are used in the "traditional" ANSI C language ( C89/90 ), an individual initializer must be supplied for each 
        // structure member in order, beginning with the first, for example :
        //
        //      struct S { int a, b, c, d; };
        //
        //      struct S s = { 1, 2, 3, 4 };
        //
        // 1 for `s.a`, 2 for `s.b` and so on...
        //
        // You are not required to specify initializers for all members, i.e. you can stop at any time ( remaining members will be zero-initialized ). If for some reason you 
        // only cared to explicitly initialize the third member of the structure, you had to supply "dummy" explicit initializers for the first and the second members ( just 
        // to get to the desired third ), for example :
        //
        // We only care to explicitly initialize `s.c`
        //
        //      struct S s = { 0, 0, 3 };
        //
        // but we have to explicitly initialize `s.a` and `s.b` as well
        //
        // Or abandon specific initialization entirely ( likely replacing it with generic = { 0 } ) and use a subsequent assignment to specific members, for example :
        //
        //      struct S s = { 0 };
        //      s.c = 3;
        //
        // One notable benefit of this assignment-based approach is that it is independent from the position of member c in the declaration of struct S. The new specification 
        // of C language ( C99 ) allows you to use "tagged" initializers by supplying the desired member name within the {}, for example :
        //
        //      struct S s = { .c = 3 };
        //
        // That way you only explicitly initialize the desired member(s) ( and have the compiler to zero-initialize the rest ).This not only saves you some typing but also 
        // makes the aggregate initializers independent from the order in which the members are specified in the struct type declaration.
        //
        // Aggregate initializers, can be used with arrays, too. And C99 supports "tagged" initialization with arrays as well. How the "tags" look in case of an array is 
        // illustrated by the following example :
        //
        //      int a[10] = { [5] = 3 };
        //
        // It is worth noting one more time that C language continues to stick to the "all or nothing" approach to aggregate initialization: if you specify an explicit 
        // initializer for just one ( or some ) members of a struct or an array, the whole aggregate ( struct or array ) gets initialized, and the members without explicit 
        // initializers get zero-initialized



        // Explicit ( Full ) template specialization :
        //
        //  Any of the following can be fully specialized :
        //
        //      1. function template
        //      2. class template
        //      3. variable template
        //      4. member function of a class template
        //      5. static data member of a class template
        //      6. member class of a class template
        //      7. member enumeration of a class template
        //      8. member class template of a class or class template
        //      9. member function template of a class or class template
        //
        //  For example,
        //
        //      template<typename T>            // primary template
        //      class Universe
        //      {};
        //
        //      template<>                      // explicit specialization for T = int
        //      struct Universe< int >
        //      {};



        // A function definition should only appear in a header file if :
        //
        //      It has been declared with the inline keyword
        //      It is defined within a class definition
        //      It involves at least one template parameter
        //
        // Those are among the cases where the multiple-identical-definitions version of ODR applies.
        //
        // So inline is not usually required with template functions. But an explicit specialization doesn't actually have any template parameters, so it should be marked 
        // as inline if it is in the header file



        // In order to access private members of template class instantiated with different types, the friend keyword is needed to allow that access :
        //
        //      template< typename Type >
        //      class Cock
        //      {
        //
        //          template< typename OtherType >
        //          friend class Cock;
        //
        //      };
        //
        // In case the two types are different, then both cocks are two completely different classes, one cannot access private members of other if you
        // don't make friend one of other. Note, in the code above all instantations of the class template are friend of each other. That is if the cock
        // is intstantied with 'char', 'int' and 'short' then :
        //
        //      - 'Cock< int >' will be friend both of 'Cock< char >' and 'Cock< short >'
        //      - 'Cock< char >' will be friend both of 'Cock< int >' and 'Cock< short >'
        //      - 'Cock< short >' will be friend both of 'Cock< char >' and 'Cock< int >'
        //
        // The interesting pharse here is "friend of each other". Usually this doesn't happen. For example, the following code :
        //
        //      class A
        //      {
        //          friend class B;
        //      };
        //
        // Here only B is friend of A, but A is not friend of B! ( fuck you snob A!! )
        //
        // In order to declare a friend with the same template argument, the template argument should not be givin a name :
        //
        //      template< typename Type >
        //      class Cock
        //      {
        //
        //          template< typename >
        //          friend class Balls;
        //
        //      };



		// Template Class Information :
		//
		//  Purpose :
		//
		//		Use this object to store multiple instances of the same type. The size of the array is provided as a template argument, which means that
        //      it is known already in compile time. The size then is determined and can not be changed. This is mandatory because the array will be 
        //      placed in the stack memory segment, and the compiler must know in advance how much memory space is needed to allocate it
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
		//			1. AnyType - any type
        //          2. ArraySize - the number of entries for the array
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		Too many to count
		//
		template< typename AnyType, UnsignedInteger64bits ArraySize >
		class StackArray : public AccessDataUsingIndices_Interface< AnyType > 
		{
		public:


            // Create a type definition for this object
            using SelfType = StackArray< AnyType, ArraySize >;


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
            //          instance - a reference to an instance that will be used to initialize all the entries
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
			explicit inline StackArray( const AnyType& instance = PerformActionAccordingToType::GetDefaultInstance< AnyType >() );


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Constructor,
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          1. other - a constant reference to an instance of an object that implements the required access data using indices interface
			//			2. sizeFromOtherToAdd - the size of the data to add
			//			3. startingIndexOnOther - the index on the data from which to add it to this instance
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
	        //      1. The other instance is ready 
	        //		2. The size to add must be smaller then the size of the array
	        //      3. The given starting index plus the size to copy from the other instance must be less or equal to the size of the other instance
	        //      4. 
	        //
	        //  Possible errors :
	        //
	        //      They will come
	        //
	        explicit inline StackArray( const AccessDataUsingIndices_Interface< AnyType >& other, UnsignedInteger64bits sizeFromOtherToAdd, UnsignedInteger64bits startingIndexOnOther = 0UL );


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
            //          1. The first argument purpose is to ensure this constructor will be called by setting a special type
            //          2. argumentsNeededToGenerateRandomInstanceOfDataType - any arguments needed to create a random instance of the data type
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
            template< typename... ArgumentsTypesNeededToGenerateRandomInstanceOfDataType >
            explicit inline StackArray( RandomInstance, ArgumentsTypesNeededToGenerateRandomInstanceOfDataType... argumentsNeededToGenerateRandomInstanceOfDataType );


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
			inline StackArray( const SelfType& other );


			// This macro will be used to all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
			// simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
			// any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
			// be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
			// macro will be used to add the following methods to each object :
			//
            //      1. Assigenment operator
            //      2. Move constructor
            //      3. Move assigenment operator
            //      4. Reset
            //      5. State
            //
            ObjectInfrastructure_ForInheritance_WithStateAlwaysReady_MACRO( StackArray< AnyType, ArraySize > )


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
            //          instance - a reference to an instance that will be used to initialize all the entries
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
			//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
			//		2. 
			//
			inline void Initiate( const AnyType& instance = PerformActionAccordingToType::GetDefaultInstance< AnyType >() );


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
	        //          1. other - a constant reference to an instance of an object that implements the required access data using indices interface
			//			2. sizeFromOtherToAdd - the size of the data to add
			//			3. startingIndexOnOther - the index on the data from which to add it to this instance
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
	        //      1. The other instance is ready 
	        //		2. The size to add must be smaller then the size of the array
	        //      3. The given starting index plus the size to copy from the other instance must be less or equal to the size of the other instance
	        //      4. 
			//
			//  Possible errors :
			//
			//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
			//		2. 
			//
			inline void Initiate( const AccessDataUsingIndices_Interface< AnyType >& other, UnsignedInteger64bits sizeFromOtherToAdd, UnsignedInteger64bits startingIndexOnOther = 0UL );


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance.
            //      This version is to allow initiating random instance
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. The first argument purpose is to ensure this constructor will be called by setting a special type
            //          2. argumentsNeededToGenerateRandomInstanceOfDataType - any arguments needed to create a random instance of the data type
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
			//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
			//		2. 
            //
            template< typename... ArgumentsTypesNeededToGenerateRandomInstanceOfDataType >
            inline void Initiate( RandomInstance, ArgumentsTypesNeededToGenerateRandomInstanceOfDataType... argumentsNeededToGenerateRandomInstanceOfDataType );


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
			virtual ~StackArray() = default;


            // This part will contain all the get and set methods for the members of the object :


            // Member - ArraySize
            GetByValue_DeclaredVirtualAndOverride_MACRO( Size, ArraySize, UnsignedInteger64bits )


			// The following methods give access and manipulate the data inside this object :


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to set the memory space with a specific instance
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. sizeToSet - the memory space size that needs to be set
            //          2. setStartingAtThisIndex - the index of the first entry that should be set
            //          3. instance - a constant reference to an instance that will be used to set all the required memory space
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
            //      1. The stack array instance should be ready
            //      2. The given index plus the size should be smaller then the stack array size
            //      3. The size to set should be larger then 0
            //      4. 
            //
            //  Possible errors :
            //
            //      They will come
            //
            void Set( UnsignedInteger64bits sizeToSet, UnsignedInteger64bits setStartingAtThisIndex = 0UL, const AnyType& instance = PerformActionAccordingToType::GetDefaultInstance< AnyType >() );


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to compare only the required part of the instance
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. other - a constant reference to an instance of an object that implements the required access data using indices interface
            //          2. sizeToCompare - the size of the instance that needs to be compared
            //          3. startingIndexInThisInstance - the index from to start the comparison on this instance
            //          4. startingIndexInOtherInstance - the index from to start the comparison on the other instance
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      True if the parts are equal, and false otherwise
            //
            //  Expectations :
            //
            //      1. The instance should be ready
            //      2. The given part starting index plus the size must result in a sum smaller or equal to the instance size
            //      3. The given part starting index on the other instance plus the size must result in a sum smaller or equal to the other instance size
            //      4. The part to compare size must be larger then 0
            //      5. 
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline Boolean Compare( const AccessDataUsingIndices_Interface< AnyType >& other, UnsignedInteger64bits sizeToCompare, UnsignedInteger64bits startingIndexInThisInstance = 0UL, UnsignedInteger64bits startingIndexInOtherInstance = 0UL ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to get the total size in bytes that the instance use
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
            //      The total size in bytes that the instance use
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline UnsignedInteger64bits SizeOfMemorySpaceUsedInBytes() const;


			// The following methods declare the overloaded operators for the object :


			// Method Information :
			//
			//  Description :
			//
			//      Use this operator to get a reference to the required entry
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			index - the index of the required entry
			//
			//      Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		A reference to the required entry
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			virtual AnyType& operator[]( UnsignedInteger64bits index ) override;


			// Method Information :
			//
			//  Description :
			//
			//      Use this operator to get a constant reference to the required entry
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			index - the index of the required entry
			//
			//      Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
            //      A constant reference to the required entry
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			virtual const AnyType& operator[]( UnsignedInteger64bits index ) const override;


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


			// DEBUG_TOOL(

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

			// )  //  End of debug tool


		private:


 			// This object is the array to contain the required information
 			AnyType member_array[ ArraySize ];


            // // Declare all the instantations of the template object with the same data type, but with different sizes to be friends. This will allow 
            // // to access the private members of each other
            // template< typename, UnsignedInteger64bits OtherArraySize >
            // friend class StackArray;


            // Assert all the requirements on the template arguments provided to the object. To perform a compile time assert the C++ language provides
            // the keyword 'static_assert', which receives an expression and an error message to display if the expression result is false. The important
            // thing is that the expression is evaluted during compile time, and therefore if the expression is false the compilation will be terminated
            // and the error message will be displayed. This method should not be used, because it does nothing during run time
            CompileTimeAssert( ( ArraySize > 0UL ), "Memory::StackArray failed - The given array size is 0" );


		};  //  Class StackArray




































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
        //          instance - a reference to an instance that will be used to initialize all the entries
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
		template< typename AnyType, UnsignedInteger64bits ArraySize >
		inline StackArray< AnyType, ArraySize >::StackArray( const AnyType& instance ) :
        AccessDataUsingIndices_Interface< AnyType >(),
		member_array()
		{
            // Set all the entries to the given instance
            Memory::Operations::Set< AnyType >( member_array, ArraySize, instance );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Constructor,
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. other - a constant reference to an instance of an object that implements the required access data using indices interface
		//			2. sizeFromOtherToAdd - the size of the data to add
		//			3. startingIndexOnOther - the index on the data from which to add it to this instance
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
        //      1. The other instance is ready 
        //		2. The size to add must be smaller then the size of the array
        //      3. The given starting index plus the size to copy from the other instance must be less or equal to the size of the other instance
        //      4. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename AnyType, UnsignedInteger64bits ArraySize >
        inline StackArray< AnyType, ArraySize >::StackArray( const AccessDataUsingIndices_Interface< AnyType >& other, UnsignedInteger64bits sizeFromOtherToAdd, UnsignedInteger64bits startingIndexOnOther ) :
        AccessDataUsingIndices_Interface< AnyType >(),
        member_array()
        {
			// Each method that interacts with the user directly needs to ensure that the given data is valid
            AssertOtherInstanceIsReady_MACRO;
            Assert_MACRO( ( ArraySize >= sizeFromOtherToAdd ), "The size to add must be less or equal to the array size" );
            AssertThatTheSumOfTheIndexPlusTheSizeIsEqualOrBelowCertainLimit_MACRO( startingIndexOnOther, sizeFromOtherToAdd, other.Size() );

            // Loop on all the entries of the other stack array
            for ( UnsignedInteger64bits index = 0UL ; index < sizeFromOtherToAdd ; ++index )
            {
                // Copy the current entry from the other stack array to this instance
                member_array[ index ] = other[ index + startingIndexOnOther ];
            }

        }


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
        //          1. The first argument purpose is to ensure this constructor will be called by setting a special type
        //          2. argumentsNeededToGenerateRandomInstanceOfDataType - any arguments needed to create a random instance of the data type
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
        template< typename AnyType, UnsignedInteger64bits ArraySize >
        template< typename... ArgumentsTypesNeededToGenerateRandomInstanceOfDataType >
        inline StackArray< AnyType, ArraySize >::StackArray( RandomInstance, ArgumentsTypesNeededToGenerateRandomInstanceOfDataType... argumentsNeededToGenerateRandomInstanceOfDataType ) :
        member_array()
        {

            // Set the entries of the generated instance to random values
            for ( UnsignedInteger64bits arrayIndex = 0UL ; arrayIndex < ArraySize ; ++arrayIndex )
            {
                // Set the current entry to a random value
                member_array[ arrayIndex ] = Random::Generator::Get< AnyType >( argumentsNeededToGenerateRandomInstanceOfDataType... );
            }

        }


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
		template< typename AnyType, UnsignedInteger64bits ArraySize >
		inline StackArray< AnyType, ArraySize >::StackArray( const SelfType& other ) :
		AccessDataUsingIndices_Interface< AnyType >(),
		member_array()
		{
			// Copy the content of the other array to this array
			Memory::Operations::Copy< AnyType >( other.member_array, member_array, ArraySize );
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
        //          instance - a reference to an instance that will be used to initialize all the entries
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
		//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename AnyType, UnsignedInteger64bits ArraySize >
		inline void StackArray< AnyType, ArraySize >::Initiate( const AnyType& instance )
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
		//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
		//
		//  Required arguments :
		//
		//		User information needed :
		//
        //          1. other - a constant reference to an instance of an object that implements the required access data using indices interface
		//			2. sizeFromOtherToAdd - the size of the data to add
		//			3. startingIndexOnOther - the index on the data from which to add it to this instance
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
        //      1. The other instance is ready 
        //		2. The size to add must be smaller then the size of the array
        //      3. The given starting index plus the size to copy from the other instance must be less or equal to the size of the other instance
        //      4. 
		//
		//  Possible errors :
		//
		//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
		//		2. 
		//
        template< typename AnyType, UnsignedInteger64bits ArraySize >
		inline void StackArray< AnyType, ArraySize >::Initiate( const AccessDataUsingIndices_Interface< AnyType >& other, UnsignedInteger64bits sizeFromOtherToAdd, UnsignedInteger64bits startingIndexOnOther )
		{
		    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
		    // leave this scope it will delete the old data
		    SelfType temporary( other, sizeFromOtherToAdd, startingIndexOnOther );

		    // Swap between this instance and the temporary instance
		    Swap( temporary );
    	}


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance.
        //      This version is to allow initiating random instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. The first argument purpose is to ensure this constructor will be called by setting a special type
        //          2. argumentsNeededToGenerateRandomInstanceOfDataType - any arguments needed to create a random instance of the data type
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
		//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
		//		2. 
        //
        template< typename AnyType, UnsignedInteger64bits ArraySize >
        template< typename... ArgumentsTypesNeededToGenerateRandomInstanceOfDataType >
        inline void StackArray< AnyType, ArraySize >::Initiate( RandomInstance, ArgumentsTypesNeededToGenerateRandomInstanceOfDataType... argumentsNeededToGenerateRandomInstanceOfDataType )
        {
            // Use the required constructor to create an instance. It will be swaped with this instance, leaving this instance with the new data. When sequence control will
            // leave this scope it delete the old data if exist
            SelfType randomGeneratedInstance( GenerateRandomInstance, argumentsNeededToGenerateRandomInstanceOfDataType... );

            // Swap between this instance and the temporary instance
            Swap( randomGeneratedInstance );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to set the memory space with a specific instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. sizeToSet - the memory space size that needs to be set
        //          2. setStartingAtThisIndex - the index of the first entry that should be set
        //          3. instance - a constant reference to an instance that will be used to set all the required memory space
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
        //      1. The stack array instance should be ready
        //      2. The given index plus the size should be smaller then the stack array size
        //      3. The size to set should be larger then 0
        //      4. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename AnyType, UnsignedInteger64bits ArraySize >
        void StackArray< AnyType, ArraySize >::Set( UnsignedInteger64bits sizeToSet, UnsignedInteger64bits setStartingAtThisIndex, const AnyType& instance )
        {
            // Each method that interacts with the user directly needs to ensure that the given data is valid
            AssertSizeIsLargerThenZero_MACRO( sizeToSet );
            AssertThatTheSumOfTheIndexPlusTheSizeIsEqualOrBelowCertainLimit_MACRO( setStartingAtThisIndex, sizeToSet, ArraySize );

            // Set all the entries to the required instance
            Memory::Operations::Set< AnyType >( ( member_array + setStartingAtThisIndex ), sizeToSet, instance );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to compare only the required part of the instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. other - a constant reference to an instance of an object that implements the required access data using indices interface
        //          2. sizeToCompare - the size of the instance that needs to be compared
        //          3. startingIndexInThisInstance - the index from to start the comparison on this instance
        //          4. startingIndexInOtherInstance - the index from to start the comparison on the other instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      True if the parts are equal, and false otherwise
        //
        //  Expectations :
        //
        //      1. The instance should be ready
        //      2. The given part starting index plus the size must result in a sum smaller or equal to the instance size
        //      3. The given part starting index on the other instance plus the size must result in a sum smaller or equal to the other instance size
        //      4. The part to compare size must be larger then 0
        //      5. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename AnyType, UnsignedInteger64bits ArraySize >
        inline Boolean StackArray< AnyType, ArraySize >::Compare( const AccessDataUsingIndices_Interface< AnyType >& other, UnsignedInteger64bits sizeToCompare, UnsignedInteger64bits startingIndexInThisInstance, UnsignedInteger64bits startingIndexInOtherInstance ) const
        {
            // Each method that interacts with the user directly needs to ensure that the given data is valid
            AssertSizeIsLargerThenZero_MACRO( sizeToCompare );
            AssertThatTheSumOfTheIndexPlusTheSizeIsEqualOrBelowCertainLimit_MACRO( startingIndexInThisInstance, sizeToCompare, ArraySize );
            AssertThatTheSumOfTheIndexPlusTheSizeIsEqualOrBelowCertainLimit_MACRO( startingIndexInOtherInstance, sizeToCompare, other.Size() );
            
            // This object will store the index on the other instance
            UnsignedInteger64bits indexOnOtherInstance = startingIndexInOtherInstance;

            // This object will store the index after the last index that needs to be compared
            UnsignedInteger64bits stopAtThisIndex = ( startingIndexInOtherInstance + sizeToCompare );

            // Loop on all the required entries and compare their content
            for ( UnsignedInteger64bits indexOnThisInstance = startingIndexInThisInstance ; indexOnThisInstance < stopAtThisIndex ; ++indexOnThisInstance, ++indexOnOtherInstance )
            {
                // Compare the current entries in both instances
                ReturnValueIfExpressionIsTrue_MACRO( ( member_array[ indexOnThisInstance ] != other[ indexOnOtherInstance ] ), false )
            }

            // If the control of the method reached this far, then the cmpared parts match, return true
            return ( true );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to get the total size in bytes that the instance use
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
        //      The total size in bytes that the instance use
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename AnyType, UnsignedInteger64bits ArraySize >
        inline UnsignedInteger64bits StackArray< AnyType, ArraySize >::SizeOfMemorySpaceUsedInBytes() const
        {
            // Calculate the total size used by the instance in bytes, and return the result
            return ( sizeof( SelfType ) );
        }



































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



































        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to get a reference to the required entry
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          index - the index of the required entry
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A reference to the required entry
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename AnyType, UnsignedInteger64bits ArraySize >
        AnyType& StackArray< AnyType, ArraySize >::operator[]( UnsignedInteger64bits index )
        {
            // Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertIndexIsBelowCertainLimit_MACRO( index, ArraySize );
            
            // Return a reference to the required entry
            return ( member_array[ index ] );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to get a constant reference to the required entry
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          index - the index of the required entry
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A constant reference to the instance inside the required entry
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename AnyType, UnsignedInteger64bits ArraySize >
        const AnyType& StackArray< AnyType, ArraySize >::operator[]( UnsignedInteger64bits index ) const
        {
            // Each method that interacts with the user directly needs to ensure that the given data is valid
            AssertIndexIsBelowCertainLimit_MACRO( index, ArraySize );

            // Return a reference to the required entry
            return ( member_array[ index ] );
        }


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
		template< typename AnyType, UnsignedInteger64bits ArraySize >
		inline Boolean StackArray< AnyType, ArraySize >::operator==( const SelfType& other ) const
		{            
            // Compare between the arrays, and return the result
            return ( Memory::Operations::Compare< AnyType >( member_array, other.member_array, ArraySize ) );
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
		template< typename AnyType, UnsignedInteger64bits ArraySize >
		inline Boolean StackArray< AnyType, ArraySize >::operator!=( const SelfType& other ) const
		{
			// Return the negotiated value from the equal operator
			return ( !( *this == other ) );
		}































// *********************************************************************************   TESTING   ********************************************************************************




































		// DEBUG_TOOL(

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
			template< typename AnyType COMMA UnsignedInteger64bits ArraySize >
			void StackArray< AnyType COMMA ArraySize >::Test()
			{
				// Create a tuple with the constraints
				Tuple< NumericRange< UnsignedInteger64bits > > constraintsTuple( NumericRange< UnsignedInteger64bits >( 1UL, 10000UL ) );

                // Perform a sanity check to ensure that all the methods that are common among all objects, for example defualt constructor, copy constructor,
                // destructor, swap and more, are working correctly
                Testing::SanityCheck< StackArray< UnsignedInteger64bits COMMA ArraySize > COMMA Tuple< NumericRange< UnsignedInteger64bits > > COMMA const UnsignedInteger64bits& >::Full_ForObjectWithStateAlwaysReady( constraintsTuple );

                // Create an instance of the object using the default constructor
                StackArray< SignedInteger32bits COMMA 89 > testArray_1;

                // Check that it is really in default state
                Assert_Test_MACRO( testArray_1[0] == 0 );

                // Create an instance of the object using the parameterized constructor
                StackArray< SignedInteger32bits COMMA 873 > testArray_2( 67 );

                // Check the size of the array
                Assert_Test_MACRO( testArray_2.Size() == 873 );

                // Create an instance of the object using the parameterized constructor
                StackArray< SignedInteger32bits COMMA 49 > testArray_3( 77 );

                // Check the size of the array
                Assert_Test_MACRO( ( testArray_3.Size() == 49 ) && ( testArray_3[45] == 77 ) );

                // Create an instance of the object using the parameterized constructor
                StackArray< SignedInteger32bits COMMA 49 > testArray_4( 799 );      

                // Check that the 2 instnaces are different
                Assert_Test_MACRO( testArray_3 != testArray_4 );

                // Set all the entries
                testArray_4.Initiate( 77 );

                // Check that the 2 instnaces are the same
                Assert_Test_MACRO( testArray_3 == testArray_4 );

                // A write operation is performed, to check that the object uses the copy on write method before
                testArray_4[5] += 1;

                // Check that the 2 instnaces point to the same address
                Assert_Test_MACRO( testArray_3 != testArray_4 );

                // Check if the addition works
                Assert_Test_MACRO( 80 == ( testArray_4[5] + 2 ) );

                // Create an instance of the object using the parameterized constructor
                StackArray< Testing::TestObject_1< UnsignedInteger64bits > COMMA 49 > testArray_5;
                testArray_5.Initiate( Testing::TestObject_1< UnsignedInteger64bits >( 18, 45 ) );

                // Test the generate random instance method
                StackArray< SignedInteger32bits COMMA 45 > testArray_6( GenerateRandomInstance );

                StackArray< SignedInteger32bits COMMA 12UL > testArray_7( testArray_6, 12UL, 7UL );

			}

		// )  //  End of debug tool











    }  //  Namespace Memory

}  //  Namespace Universe



#endif  // STACKARRAY_HPP