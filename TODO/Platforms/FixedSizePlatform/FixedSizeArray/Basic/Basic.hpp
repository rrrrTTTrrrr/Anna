#ifndef  FIXEDSIZEARRAYBASIC_HPP
#define  FIXEDSIZEARRAYBASIC_HPP


#include "../../../../../Definitions/VariableTypesDefinitions.hpp"  //  Typedef UnsignedInteger64bits, Typedef Boolean
#include "../../../../../BasicUtilities/C++/cpp_BasicUtilities.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../Memory/MemoryOperations/Swap/Swap.hpp"  //  Class Swap
#include "../../../../../Memory/MemoryOperations/Copy/Copy.hpp"  //  Class Copy
#include "../../../../../Memory/MemoryOperations/Compare/Compare.hpp"  //  Class Compare
#include "../../../../../Memory/MemoryOperations/Set/Set.hpp"  //  Class Set
#include "../../../../../Abilities/Proxy/Basic/Basic.hpp"  //  Class Proxy::Basic
#include "../../../../../DataTypes/SmartPointers/HeapSharedPointer/HeapSharedPointer.hpp"  //  Class HeapSharedPointer


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../../../ErrorHandling/Assert/Assert.hpp"  //  Class Assert
#endif


// When a function name ends with the suffix IMP, the function is not part of the object interface ( capabilities ), it only used as aid to the function that
// it is, implementing only spsecific part



namespace Universe
{

    namespace Abilities
    {

        namespace FixedSizeArray
        {


        	// This is used when only declaring the object in this source file will be enough to pass compilation. The implementation is given to the compiler through the
        	// cpp source file that the object is nested within
        	//
        	// Forward declarations :
        	//
        	//  NONE
        	//


        	// Give proper treatment, by dealing with big and little endian encoding systems where it is required. The big or little endian encoding appear when dealing
        	// with byte order in memory. In the byte itself the bit the is closest to the address of the byte, is the high order bit
        	//
        	//    The closest bit to the    The farest bit from the
        	//     address of the byte        address of the byte
        	//                        |      |
        	//      Byte address ->   00000000
        	//                        |      |
        	//            High order bit    Low order bit
        	//
        	// Then the value 1 will be stored this way :
        	//
        	//      Byte address ->   00000001
        	//                        |      |
        	//            High order bit    Low order bit
        	//
        	// Then in 1 byte this is always the case. But when dealing with more then 1 byte it is up to the system to decide whether the address of the first byte will
        	// contain the high order bits or the low order bits. For example for 2 bytes, store the value 1 in the 2 ways of endian encoding :
        	//
        	//    Big endian encoding :
        	//
        	//      First address of data type ->   00000000 00000001
        	//
        	//    Big endian encoding :
        	//
        	//      First address of data type ->   00000001 00000000


        	// To support move semantics every object must provide a default state. There are  how ever few exceptions, as objects that their members stay exactly the same along
        	// the run of the program, objects that don't have members at all, and objects with undefined state. This default state will be used to notify that the object should
        	// not be used


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
	        // Stroustrup reused the existing class keyword to specify a type parameter rather than introduce a new keyword that might of course break existing programs. It 
	        // wasn’t that a new keyword wasn’t considered — just that it wasn’t considered necessary given its potential disruption. And up until the ISO-C++ standard, this 
	        // was the only way to declare a type parameter. Reuses of existing keywords seems to always sow confusion. What we found is that beginners were whether the use 
	        // of the class constrained or limited the type arguments a user could specify to be class types rather than, say, a built-in or pointer type. So, there was some 
	        // feeling that not having introduced a new keyword was a mistake. During standardization, certain constructs were discovered within a template definition that 
	        // resolved to expressions although they were meant to indicate declarations. For example,
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
	        // While the statement containing aObj is intended by the programmer to be interpreted as the declaration of a pointer to a nested type A within the type 
	        // parameter T, the language grammar interprets it as an arithmetic expression multiplying the static member A of type T with aObj and throwing away the result. 
	        // Isn’t that annoying! ( This sort of dilemna is not possible within generics – there is no way to safely verify that any T contains an A so that the runtime 
	        // can safely construct an instance of the generic type ). The committee decided that a new keyword was just the ticket to get the compiler off its unfortunate 
	        // obsession with expressions. The new keyword was the self-describing typename. When applied to a statement, such as,
	        //
	        //
	        //          typename T::A* a6; // declare pointer to T’s A
	        //
	        //
	        // it instructs the compiler to treat the subsequent statement as a declaration. Since the keyword was on the payroll, heck, why not fix the confusion caused by 
	        // the original decision to reuse the class keyword. Of course, given the extensive body of existing code and books and articles and talks and postings using the 
	        // class keyword, they chose to also retain support for that use of the keyword as well. So that’s why you have both


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
	        // In this case, p will point to x forever; any attempt to change this is undefined behavior ( and the compiler may put p in read-only memory, or assume that *p 
	        // refers to x, regardless of any other code )


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


        	// Template class Information :
        	//
        	//  Purpose :
        	//
        	//      Use this object to manage a contigous segment of basic types data, when the number of entries required is known in advance
        	//
       	    //  Description :
       	    //
      	    //		1. The access to elements in the container should be through the operator []. This will allow the object to prevent copying the resource when it needs to 
            //         only read from it. In other words it will allow the resource inside each instance to be shared as long as changes are not made to it. To implement this 
            //         the arithmetic for basic types containers object is inherited. This object will add the functionality of a proxy. Instead of returning the data or a 
            //         reference to data, a proxy instance is created with the knowledge of the required data, this gives the abililty to know what is the next required thing 
            //         from the data. The basic change is if we need to write or read. For example,
      	    //
      	    //					container[ index ] + 3
      	    //
      	    //		   In this case a proxy will be created from the first part of the expression, and then the operator+ will be choosen from the proxy. This method does not 
            //         change the instance, it only needs to read the data, and therefore no copy on write is needed, but in the case,
      	    //
      	    //					container[ index ] += 3
      	    //
      	    //			In this case the object does need to change, and therefore the proxy must make sure the container performs a copy on write prior to actual writing
        	//
        	//  Possible errors :
        	//
        	//
        	//
        	template< typename BasicType >
            class Basic 
            {
            public:


                // The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler
                // generates a basic behavior for them :


                // Method Information :
        	    //
        	    //  Description :
                //
        		//   	Default Constructor, used to support move semantics
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
    			//  Possible errors :
        		//
        		//		They will come
        		//
        		inline Basic();


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
                //          1. size - the required number of entries in the basic types fixed size platfrom
                //          2. value - a value to initialze all the entries
                //
                //      Information returned to the user :
                //
                //          NONE
                //
                //  Return value :
                //
                //        NONE
                //
                //  Possible errors :
                //
                //      1. There is no more free memory space - class std::bad_alloc is thrown
                //      2. The given size of the basic types fixed size platfrom is 0
                //      3. The object does not have assignment operator
                //      4. 
                //
                explicit inline Basic( UnsignedInteger64bits size, BasicType value = 0 );


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
        		//          other - a reference to the object that should be copied
        		//
        		//		Information returned to the user :
        		//
        		//          NONE
        		//
        		//  Return value :
        		//
        		//   	A reference to the new copy is returned
        		//
        		//  Possible errors :
        		//
        		//		They will come
        		//
        		inline Basic( const Basic< BasicType >& other );


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
        		//			other - a reference to the object that should be copied
        		//
        		//		Information returned to the user :
        		//
        		//          NONE
        		//
        		//  Return value :
        		//
        		//   	A reference to this object
        		//
        		//  Possible errors :
        		//
        		//		They will come
        		//
        		inline Basic< BasicType >& operator=( const Basic< BasicType >& other );


        		// Method Information :
        		//
        		//  Description :
        		//
        		//   	Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances in default state
        		//
        		//  Required arguments :
        		//
        		//   	User information needed :
        		//
        		//          other - a reference to the object that should be moved
        		//
        		//      Information returned to the user :
        		//
        		//          NONE
        		//
        		//  Return value :
        		//
        		//   	NONE
        		//
        		//  Possible errors :
        		//
        		//		They will come
        		//
        		inline Basic( Basic< BasicType >&& other );


        		// Method Information :
        		//
        		//  Description :
        		//
        		//   	Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state
        		//
        		//  Required arguments :
        		//
        		//   	User information needed :
        		//
        		//          other - a reference to the object that should be moved
        		//
        		//      Information returned to the user :
        		//
        		//          NONE
        		//
        		//  Return value :
        		//
        		//   	A reference to this object
        		//
        		//  Possible errors :
        		//
        		//		They will come
        		//
        		inline Basic< BasicType >& operator=( Basic< BasicType >&& other );


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
                //          other - a reference to the object that should be swaped
                //
                //      Information returned to the user :
                //
                //          NONE
                //
                //  Return value :
                //
                //      NONE
                //
                //  Possible errors :
                //
                //      They will come
                //
                inline void Swap( Basic< BasicType >& other );


                // Method Information :
                //
                //  Description :
                //
                //      Use this to set a new size for the basic types fixed size platfrom. Note - all previous data in the platfrom will be lost
                //
                //  Required arguments :
                //
                //      User information needed :
                //
                //          1. newSize - the required number of entries in the basic types fixed size platfrom
                //          2. value - a value to initialze all the entries
                //
                //      Information returned to the user :
                //
                //          NONE
                //  
                //  Return value :
                //
                //      NONE
                //
                //  Possible errors :
                //
                //      1. The given size of the new basic types fixed size platfrom is 0 
                //      2.
                //
                void Initiate( UnsignedInteger64bits newSize, BasicType value = 0 );


        		// Method Information :
        		//
        		//  Description :
        		//
        		//   	Destructor, does not throw
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
        		//  Possible errors :
        		//
        		//		They will come
        		//
        		virtual inline ~Basic() = default;


        		// To support Move semantics, the following 3 methods are added to every object. One method to set the object into the default state, another to check if the
        		// object is in the default state, and the last method to delete all the object resources and set the object to default state :


        		// Method Information :
        		//
        		//  Description :
        		//
            	//      Use to set the object into his default state. It does not delete the resources, if the method is used all the information inside will be lost and
        		//		a memory leak will occuer
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
        		//  Possible errors :
        		//
        		//	    They will come
        		//
        		inline void SetToDefaultState();


        		// Method Information :
        		//
        		//  Description :
        		//
        		//   	Use to check if the object is in default state
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
        		//      1. true, if instance is at default state
        		//      2. false, if instance is not at default state
        		//
        		//  Possible errors :
        		//
        		//		They will come
        		//
        		inline Boolean DefaultState() const;


        		// Method Information :
        		//
        		//  Description :
        		//
        		//      Use to delete the instance resources and set it to default state
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
        		//      NONE
        		//
        		//  Possible errors :
        		//
        		//      1. Deleting the object resources failed
        		//      2.
        		//
        		inline void DeleteResourcesAndSetToDefaultState();


        		// The following methods are the interface of the object. This methods implement the capabilities of the object :


                // Method Information :
                //
                //  Description :
                //
                //      Use this to set all the entries of the basic types fixed size platfrom to the required value
                //
                //  Required arguments :
                //
                //      User information needed :
                //
                //          value - the entries will be set to this object
                //
                //      Information returned to the user :
                //
                //          NONE
                //  
                //  Return value :
                //
                //      NONE
                //
                //  Possible errors :
                //
                //      1. The object does not have an assignment operator
                //      2. The object is in default state
                //      3.
                //
                inline void SetAll( BasicType value );


                // Method Information :
                //
                //  Description :
                //
                //      Use to get the number of entries in the basic types fixed size platfrom
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
                //      The size of the basic types fixed size platfrom
                //
                //  Possible errors :
                //
                //      1. The object is in default state
                //      2.
                //
                inline UnsignedInteger64bits Size() const;


        		// The following methods declare the overloaded operators for the object :


                // Method Information :
                //
                //  Description :
                //
                //      Use to get reference to an entry
                //
                //  Required arguments :
                //
                //      User information needed :
                //
                //          index - the index of the entry required
                //
                //      Information returned to the user :
                //
                //          NONE
                //
                //  Return value :
                //
                //      The basic types fixed size platfrom proxy class
                //
                //  Possible errors :
                //
                //      1. The object is in default state
                //      2. The entry index is out of the basic types fixed size platfrom range
                //      3.
                //
                inline typename Proxy::Basic< Basic< BasicType >, UnsignedInteger64bits, BasicType > operator[]( const UnsignedInteger64bits& index );


                // Method Information :
                //
                //  Description :
                //
                //      Use to get reference to an entry
                //
                //  Required arguments :
                //
                //      User information needed :
                //
                //          index - the index of the entry required
                //
                //      Information returned to the user :
                //
                //          NONE
                //
                //  Return value :
                //
                //      The array proxy class
                //
                //  Possible errors :
                //
                //      1. The object is in default state
                //      2. The entry index is out of the basic types fixed size platfrom range
                //      3.
                //
                inline BasicType operator[]( const UnsignedInteger64bits& index ) const;


                // Method Information :
                //
                //  Description :
                //
                //      Use to get the address of the required entry
                //
                //  Required arguments :
                //
                //      User information needed :
                //
                //          index - the index of the entry required
                //
                //      Information returned to the user :
                //
                //          NONE
                //
                //  Return value :
                //
                //      The address of the required entry
                //
                //  Possible errors :
                //
                //      1. The object is in default state
                //      2. The entry index is out of the basic types fixed size platfrom range
                //      3.
                //
                inline BasicType* operator+( UnsignedInteger64bits index );


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
        		//          other - a reference to the object that should be compared with this object
        		//
        		//      Information returned to the user :
        		//
        		//          NONE
        		//
        		//  Return value :
        		//
        		//      1. true - if the 2 objects are the same
        		//      2. false - otherwise
        		//
        		//  Possible errors :
        		//
        		//      1. The template type object does not have the comparison operator ( == )
        		//      2. 
        		//
        		Boolean operator==( const Basic< BasicType >& other ) const;


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
        		//          other - a reference to the object that should be compared with this object
        		//
        		//      Information returned to the user :
        		//
        		//          NONE
        		//
        		//  Return value :
        		//
        		//      1. true - if the 2 objects are not the same
        		//      2. false - otherwise
        		//
        		//  Possible errors :
        		//
        		//      1. The template type object does not have the comparison operator ( == )
        		//      2. 
        		//
        		inline Boolean operator!=( const Basic< BasicType >& other ) const;


        		DEBUG_TOOL(

        			// This part of the class is dedicated for testing :


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
        			//  Possible errors :
        			//
        			//      1. A method does not work correctly - class Exception is thrown
        			//		2. There is no more free memory space - class std::bad_alloc is thrown
        			//		3. 
        			//
        			static void Test();

        		)  //  End of debug tool


        	protected:


        		// The protected part is used for inheritance. This means that only this object and the objects that inherit from it can use the protected members data or methods


                // This object will store the basic types fixed size platfrom
                DataTypes::HeapSharedPointer< BasicType > m_fixedSizeArray;


        	private:


                // Allow the inherited arithmetic proxy object, to access protected and private sections of this object
                friend class Proxy::Basic< Basic< BasicType >, UnsignedInteger64bits, BasicType >;


                // The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
                // rather help implement it :


                // Method Information :
                //
                //  Description :
                //
                //      Use this method to copy the basic types fixed size platfrom to a new memory space
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
                //      NONE
                //
                //  Possible errors :
                //
                //      They will come
                //
                inline void Copy_IMP();


                // The following methods decalre the pure virtual methods derived :


                // Method Information :
                //
                //  Description :
                //
                //      This method will be used for non constant objects
                //
                //  Required arguments :
                //
                //      User information needed :
                //
                //          index - the index to the required element in the container
                //
                //      Information returned to the user :
                //
                //          NONE
                //
                //  Return value :
                //
                //      A reference to the data
                //
                //  Possible errors :
                //
                //      They will come
                //
                virtual inline BasicType& GetData_IMP( const UnsignedInteger64bits& index );


                // Method Information :
                //
                //  Description :
                //
                //      This method will be used for constant objects
                //
                //  Required arguments :
                //
                //      User information needed :
                //
                //          index - the index to the required element in the container
                //
                //      Information returned to the user :
                //
                //          NONE
                //
                //  Return value :
                //
                //      NONE
                //
                //  Possible errors :
                //
                //      They will come
                //
                virtual inline BasicType GetData_IMP( const UnsignedInteger64bits& index ) const;


                // Method Information :
                //
                //  Description :
                //
                //      This method can be used when the default behavior for operators that change the state of the object is not good enough. It is very important for object 
                //      with shared main resource inside. When a write operation needs to take place, the number of instances using the resource must be checked. If only one
                //      instance uses the resource then there are no problems and the write operation can take place. If there is more then one instance using the resource then, 
                //      the resource must be copied first, to prevent changing it also for other instances. Only then the write operation can take place. This method then should 
                //      be used everytime before changes are made to the inherting object
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
                //      NONE
                //
                //  Possible errors :
                //
                //      They will come
                //
                virtual inline void ExecuteTaskBeforeObjectChanges_IMP();


        	};  //  Class Basic













































//  *******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************












































        	// Method Information :
        	//
        	//  Description :
        	//
        	//   	Default Constructor, used to support move semantics
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
        	//  Possible errors :
        	//
        	//		They will come
        	//
        	template< typename BasicType >
        	inline Basic< BasicType >::Basic() :
            m_fixedSizeArray()
        	{}


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
            //          1. size - the required number of entries in the basic types fixed size platfrom
            //          2. value - a value to initialze all the entries
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //        NONE
            //
            //  Possible errors :
            //
            //      1. There is no more free memory space - class std::bad_alloc is thrown
            //      2. The given size of the basic types fixed size platfrom is 0
            //      3. The object does not have assignment operator
            //      4. 
            //
            template< typename BasicType >
            inline Basic< BasicType >::Basic( UnsignedInteger64bits size, BasicType value ) :
            m_fixedSizeArray( size )
            {
                // Set the elements of the memory segment to the required value
                SetAll( value );
            }


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
        	//          other - a reference to the object that should be copied
        	//
        	//		Information returned to the user :
        	//
        	//          NONE
        	//
        	//  Return value :
        	//
        	//   	A reference to the new copy is returned
        	//
        	//  Possible errors :
        	//
        	//		They will come
        	//
        	template< typename BasicType >
        	inline Basic< BasicType >::Basic( const Basic< BasicType >& other ) :
        	m_fixedSizeArray( other.m_fixedSizeArray )
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
        	//			other - a reference to the object that should be copied
        	//
        	//		Information returned to the user :
        	//
        	//          NONE
        	//
        	//  Return value :
        	//
        	//   	A reference to this object
        	//
        	//  Possible errors :
        	//
        	//		They will come
        	//
        	template< typename BasicType >
        	inline Basic< BasicType >& Basic< BasicType >::operator=( const Basic< BasicType >& other )
        	{
        		// Create a copy of the other instance
        		Basic< BasicType > temporary( other );

        		// Swap between this instance and the temporary one, this will leave the temporary instance with the old data, and he will delete it
        		Swap( temporary );

        		// Return a reference to this object
        		return ( *this );
        	}


        	// Method Information :
        	//
        	//  Description :
        	//
        	//   	Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances in default state
        	//
        	//  Required arguments :
        	//
        	//   	User information needed :
        	//
        	//          other - a reference to the object that should be moved
        	//
        	//      Information returned to the user :
        	//
        	//          NONE
        	//
        	//  Return value :
        	//
        	//   	NONE
        	//
        	//  Possible errors :
        	//
        	//		They will come
        	//
        	template< typename BasicType >
        	inline Basic< BasicType >::Basic( Basic< BasicType >&& other ) :
        	Basic< BasicType >()
        	{
        		// Swap between this instance, which is in default state, and the other one
        		Swap( other );
        	}


        	// Method Information :
        	//
        	//  Description :
        	//
        	//   	Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state
        	//
        	//  Required arguments :
        	//
        	//   	User information needed :
        	//
        	//          other - a reference to the object that should be moved
        	//
        	//      Information returned to the user :
        	//
        	//          NONE
        	//
        	//  Return value :
        	//
        	//   	A reference to this object
        	//
        	//  Possible errors :
        	//
        	//		They will come
        	//
        	template< typename BasicType >
        	inline Basic< BasicType >& Basic< BasicType >::operator=( Basic< BasicType >&& other )
        	{
        	    // Create a default constructed instance
        	    Basic< BasicType > defaultConstructedInstance;

        	    // Swap between the temporary instance, which is in default state, and the other instance
        	    defaultConstructedInstance.Swap( other );

        	    // Swap between this instance and the temporary one
        	    Swap( defaultConstructedInstance );

        	    // Return a reference to this object
        	    return ( *this );
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
            //          other - a reference to the object that should be swaped
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            template< typename BasicType >
            inline void Basic< BasicType >::Swap( Basic< BasicType >& other )
        	{
                // Swap between the heap shared pointers
                m_fixedSizeArray.Swap( other.m_fixedSizeArray );
            }


            // Method Information :
            //
            //  Description :
            //
            //      Use this to set a new size for the basic types fixed size platfrom. Note - all previous data in the platfrom will be lost
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. newSize - the required number of entries in the basic types fixed size platfrom
            //          2. value - a value to initialze all the entries
            //
            //      Information returned to the user :
            //
            //          NONE
            //  
            //  Return value :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      1. The given size of the new basic types fixed size platfrom is 0 
            //      2.
            //
            template< typename BasicType >
            void Basic< BasicType >::Initiate( UnsignedInteger64bits newSize, BasicType value )
            {
                // Create a new temporary instance
                Basic< BasicType > temporary( newSize, value );

                // Swap between this instance and the temporary one
                Swap( temporary );
            }


            // Method Information :
        	//
        	//  Description :
        	//
            //      Use to set the object into his default state. It does not delete the resources, if the method is used all the information inside will be lost and
        	//		a memory leak will occuer
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
        	//  Possible errors :
        	//
        	//	    They will come
        	//
        	template< typename BasicType >
        	inline void Basic< BasicType >::SetToDefaultState()
        	{
                // Set the heap shared pointer to default state
                m_fixedSizeArray.SetToDefaultState();
        	}


        	// Method Information :
        	//
        	//  Description :
        	//
        	//   	Use to check if the object is in default state
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
        	//      1. true, if instance is at default state
        	//      2. false, if instance is not at default state
        	//
        	//  Possible errors :
        	//
        	//		They will come
        	//
        	template< typename BasicType >
        	inline Boolean Basic< BasicType >::DefaultState() const
        	{
        		// Check if the object is in default state, and return the result
        		return ( m_fixedSizeArray.DefaultState() == true );
        	}


        	// Method Information :
        	//
        	//  Description :
        	//
        	//      Use to delete the instance resources and set it to default state
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
        	//      NONE
        	//
        	//  Possible errors :
        	//
        	//      1. Deleting the object resources failed
        	//      2.
        	//
        	template< typename BasicType >
        	inline void Basic< BasicType >::DeleteResourcesAndSetToDefaultState()
        	{
                // Check if the object is in default state, then noting needs to be done
                RETURN_IF_EXPRESSION_IS_TRUE( DefaultState() )

                // Delete the memory space
                m_fixedSizeArray.DeleteResourcesAndSetToDefaultState();
        	}


            // Method Information :
            //
            //  Description :
            //
            //      Use this to set all the entries of the basic types fixed size platfrom to the required value
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          value - the entries will be set to this object
            //
            //      Information returned to the user :
            //
            //          NONE
            //  
            //  Return value :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      1. The object does not have an assignment operator
            //      2. The object is in default state
            //      3.
            //
            template< typename BasicType >
            inline void Basic< BasicType >::SetAll( BasicType value )
            {
                // A write operation is about to take place, check if only this instance uses the resource, if not, copy it to a new one that only this instance uses
                ExecuteTaskBeforeObjectChanges_IMP();

                // Set the all the entries to the required value
                Memory::Set::Basic< BasicType >( m_fixedSizeArray, value );
            }


            // Method Information :
            //
            //  Description :
            //
            //      Use to get the number of entries in the basic types fixed size platfrom
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
            //      The size of the basic types fixed size platfrom
            //
            //  Possible errors :
            //
            //      1. The object is in default state
            //      2.
            //
            template< typename BasicType >
            inline UnsignedInteger64bits Basic< BasicType >::Size() const
            {
                // Return the number of entries in the basic types fixed size platfrom
                return ( m_fixedSizeArray.Size() );
            }











































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************










































            // Method Information :
            //
            //  Description :
            //
            //      Use to get reference to an entry
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          index - the index of the entry required
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      The basic types fixed size platfrom proxy class
            //
            //  Possible errors :
            //
            //      1. The object is in default state
            //      2. The entry index is out of the basic types fixed size platfrom range
            //      3.
            //
            template< typename BasicType >
            inline typename Proxy::Basic< Basic< BasicType >, UnsignedInteger64bits, BasicType > Basic< BasicType >::operator[]( const UnsignedInteger64bits& index )
            {
                // Create the proxy class and return it
                return ( typename Proxy::Basic< Basic< BasicType >, UnsignedInteger64bits, BasicType >( *this, index ) );
            }


            // Method Information :
            //
            //  Description :
            //
            //      Use to get reference to an entry
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          index - the index of the entry required
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      The array proxy class
            //
            //  Possible errors :
            //
            //      1. The object is in default state
            //      2. The entry index is out of the basic types fixed size platfrom range
            //      3.
            //
            template< typename BasicType >
            inline BasicType Basic< BasicType >::operator[]( const UnsignedInteger64bits& index ) const
            {
                // Return a copy of the value in the entry
                return ( m_fixedSizeArray[ index ] );
            }


            // Method Information :
            //
            //  Description :
            //
            //      Use to get the address of the required entry
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          index - the index of the entry required
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      The address of the required entry
            //
            //  Possible errors :
            //
            //      1. The object is in default state
            //      2. The entry index is out of the basic types fixed size platfrom range
            //      3.
            //
            template< typename BasicType >
            inline BasicType* Basic< BasicType >::operator+( UnsignedInteger64bits index )
            {
                // Return the required address
                return ( m_fixedSizeArray + index );
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
        	//          other - a reference to the object that should be compared with this object
        	//
        	//      Information returned to the user :
        	//
        	//          NONE
        	//
        	//  Return value :
        	//
        	//      1. true - if the 2 objects are the same
        	//      2. false - otherwise
        	//
        	//  Possible errors :
        	//
        	//      1. The template type object does not have the comparison operator ( == )
        	//      2. 
        	//
        	template< typename BasicType >
        	inline Boolean Basic< BasicType >::operator==( const Basic< BasicType >& other ) const
        	{
                // Return the result of the comparison
                return ( Memory::Compare::Basic< BasicType >( m_fixedSizeArray, other.m_fixedSizeArray ) );
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
        	//          other - a reference to the object that should be compared with this object
        	//
        	//      Information returned to the user :
        	//
        	//          NONE
        	//
        	//  Return value :
        	//
        	//      1. true - if the 2 objects are not the same
        	//      2. false - otherwise
        	//
        	//  Possible errors :
        	//
        	//      1. The template type object does not have the comparison operator ( == )
        	//      2. 
        	//
        	template< typename BasicType >
        	inline Boolean Basic< BasicType >::operator!=( const Basic< BasicType >& other ) const
        	{
        		// Return the negotiated value from the equal operator
        		return ( !( *this == other ) );
        	}















































//  ********************************************************   TEMPLATE OR INLINE PURE VIRTUAL METHODS IMPLEMENTATION   *********************************************************







































            // Method Information :
            //
            //  Description :
            //
            //      This method will be used for non constant objects
            //      
            //  Required arguments :
            //
            //      User information needed :
            //
            //          index - this will be used to identify the required data
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      A reference to the data
            //
            //  Possible errors :
            //
            //      They will come
            //
            template< typename BasicType >
            inline BasicType& Basic< BasicType >::GetData_IMP( const UnsignedInteger64bits& index )
            {
                // Return a reference to the data
                return ( m_fixedSizeArray[ index ] );
            }


            // Method Information :
            //
            //  Description :
            //
            //      This method will be used for non constant objects
            //      
            //  Required arguments :
            //
            //      User information needed :
            //
            //          index - this will be used to identify the required data
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      A reference to the data
            //
            //  Possible errors :
            //
            //      They will come
            //
            template< typename BasicType >
            inline BasicType Basic< BasicType >::GetData_IMP( const UnsignedInteger64bits& index ) const
            {
                // Return a copy of the data
                return ( m_fixedSizeArray[ index ] );
            }


            // Method Information :
            //
            //  Description :
            //
            //      This method can be used when the default behavior for operators that change the state of the object is not good enough. It is very important for object 
            //      with shared main resource inside. When a write operation needs to take place, the number of instances using the resource must be checked. If only one
            //      instance uses the resource then there are no problems and the write operation can take place. If there is more then one instance using the resource then, 
            //      the resource must be copied first, to prevent changing it also for other instances. Only then the write operation can take place. This method then should 
            //      be used everytime before changes are made to the inherting object
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
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            template< typename BasicType >
            inline void Basic< BasicType >::ExecuteTaskBeforeObjectChanges_IMP()
            {
                // Check if only this instance uses the shared resource
                RETURN_IF_THE_VALUES_ARE_EQUAL( m_fixedSizeArray.Counter(), 1 )

                // More then 1 instance uses the shared resource, Create a new copy of the resource            
                Copy_IMP();
            }









































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************








































            // Method Information :
            //
            //  Description :
            //
            //      Use this method to copy the basic types fixed size platfrom to a new memory space
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
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            template< typename BasicType >
            inline void Basic< BasicType >::Copy_IMP()
            {
                // This object will store the new allocated memory space
                DataTypes::HeapSharedPointer< BasicType > temporary( m_fixedSizeArray.Size() );

                // Copy the basic types fixed size platfrom to the new memory space
                Memory::Copy::Basic< BasicType >( m_fixedSizeArray, temporary );

                // Swap between the temporary and this instance
                m_fixedSizeArray.Swap( temporary );
            }









































// ********************************************************************************   TESTING   *********************************************************************************








































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
        		//  Possible errors :
        		//
        		//      1. A method does not work correctly - class Exception is thrown
        		//		2. There is no more free memory space - class std::bad_alloc is thrown
        		//		3. 
        		//
        		template< typename BasicType >
        		void Basic< BasicType >::Test()
        		{
                    // Create an instance of the object using the default constructor
                    Basic< SignedInteger32bits > testArray_1;

                    // Check that it is really in default state
                    ErrorHandling::Assert< ErrorHandling::Exception >::True( testArray_1.DefaultState(), "Basic::Test failed - 1" );

                    // Create an instnace of the object using the parameterized constructor
                    Basic< SignedInteger32bits > testArray_2( 67 );

                    // Check the size of the array
                    ErrorHandling::Assert< ErrorHandling::Exception >::True( ( 67 == testArray_2.Size() ), "Basic::Test failed - 2" );            

                    // Create an instnace of the object using the parameterized constructor
                    Basic< SignedInteger32bits > testArray_3( 67, 77 );

                    // Check the size of the array
                    ErrorHandling::Assert< ErrorHandling::Exception >::True( ( 67 == testArray_3.Size() ) && ( testArray_3[45] == 77 ), "Basic::Test failed - 3" );            

                    // Create an instance using the copy constructor
                    Basic< SignedInteger32bits > testArray_4( testArray_3 );

                    // Check that the 2 instnaces point to the same address
                    ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_3 == testArray_4 ), "Basic::Test failed - 4" );            

                    // A write operation is performed, to check that the object uses the copy on write method before
                    testArray_4[5] += 1;

                    // Check that the 2 instnaces point to the same address
                    ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_3 != testArray_4 ), "Basic::Test failed - 5" );                                              

                    // Check if the addition works
                    ErrorHandling::Assert< ErrorHandling::Exception >::True( ( 80 == ( testArray_4[5] + 2 ) ), "Basic::Test failed - 6" );
                }

        	)  //  End of debug tool



















        }  //  Namespace FixedSizeArray

    }  //  Namespace Abilities

}  //  Namespace Universe


#endif  // FIXEDSIZEARRAYBASIC_HPP