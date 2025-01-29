#ifndef  ARRAYBASIC_HPP
#define  ARRAYBASIC_HPP


#include <new>  //  Class std::bad_alloc


#include "../../../../../Definitions/VariableTypesDefinitions.hpp"  //  Typedef UnsignedInteger64bits, Typedef UnsignedInteger8bits, Typedef Boolean
#include "../../../../../BasicUtilities/C++/cpp_BasicUtilities.hpp"  //  Macro DEBUG_TOOL
#include "../../../../../Memory/MemoryOperations/Copy/Copy.hpp"  //  Class Copy
#include "../../../../../Memory/MemoryOperations/Set/Set.hpp"  //  Class Set
#include "../../../../../Memory/MemoryOperations/Compare/Compare.hpp"  //  Class Compare
#include "../../../../../Memory/MemoryOperations/Swap/Swap.hpp"  //  Class Swap
#include "../../../../../Abilities/Proxy/Basic/Basic.hpp"  //  Class Basic
#include "../../../../../DataTypes/SmartPointers/HeapSharedPointer/HeapSharedPointer.hpp"  //  Class HeapSharedPointer


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../../../ErrorHandling/Assert/Assert.hpp"  //  Class Assert
#include <vector>
#endif


// When a function name ends with the suffix IMP, the function is not part of the object interface ( capabilities ), it only used as aid to the function that
// it is, implementing only spsecific part


namespace Universe
{

    namespace Abilities
    {

        namespace Array
        {


            // This is used when only declaring the object in this source file will be enough to pass compilation. The implementation is given to the compiler through the
            // cpp source file that the object is nested within
            //
            // Forward declarations :
            

            // This object will store the percentage from the given basic types array size. This will be used to allocate more entries to better manage the basic types array
            #define AdditionalMemoryPercentageFromSize 10


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
            // placeholder that will be replaced by a user-specfied actual type. The reason for the two indexwords is historical. In the original template specification, 
            // Stroustrup reused the existing class indexword to specify a type parameter rather than introduce a new indexword that might of course break existing programs. 
            // It wasn’t that a new indexword wasn’t considered — just that it wasn’t considered necessary given its potential disruption. And up until the ISO-C++ standard, 
            // this was the only way to declare a type parameter. Reuses of existing indexwords seems to always sow confusion. What we found is that beginners were whether 
            // the use of the class constrained or limited the type arguments a user could specify to be class types rather than, say, a built-in or pointer type. So, there 
            // was some feeling that not having introduced a new indexword was a mistake. During standardization, certain constructs were discovered within a template 
            // definition that resolved to expressions although they were meant to indicate declarations. For example,
        	//
            // 		template <class T>
            //  	class Demonstration {
            //  	public:
            //
            //  		void method() {
        	//
            //      		T::A *aObj; // oops …
        	//
            //       		// …
            //			}
        	//
            //  	};
        	//
            // While the statement containing aObj is intended by the programmer to be interpreted as the declaration of a pointer to a nested type A within the type parameter 
            // T, the language grammar interprets it as an arithmetic expression multiplying the static member A of type T with aObj and throwing away the result. Isn’t that 
            // annoying! ( This sort of dilemna is not possible within generics – there is no way to safely verify that any T contains an A so that the runtime can safely 
            // construct an instance of the generic type ). The committee decided that a new indexword was just the ticket to get the compiler off its unfortunate obsession 
            // with expressions. 
            // The new indexword was the self-describing typename. When applied to a statement, such as,
        	//
            //  	typename T::A* a6; // declare pointer to T’s A
        	//
            // it instructs the compiler to treat the subsequent statement as a declaration. Since the indexword was on the payroll, heck, why not fix the confusion caused 
            // by the original decision to reuse the class indexword. Of course, given the extensive body of existing code and books and articles and talks and postings using 
            // the class indexword, they chose to also retain support for that use of the indexword as well. So that’s why you have both


            // The main point of a class is to manage resources ( In theory every class should maintain one and only one resource ), one of the important aspects of managing 
            // a resource is performance, the amount of time every operation take should be as minimal as possible, the basic operations should take almost the same as when 
            // working with the resource without the class covering it


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


            // Assignment operator ( = ), curel brackets operator ( () ), square brackets opeartor ( [] ), and pointer dereference operator ( -> ) must be member methods!!


    		// Template class Information :
        	//
        	//  Purpose :
        	//
            //      Template class to work with contigous segments containing multiple objects from the same kind
        	//
       	    //  Description :
            //
            //      1. When dealing with array of objects, it does not behave the same as with basic types. The reason is that with basic types, the location can be allocated 
            //		   before, and then that location is just set with the value. This is just copying the bits. With objects copying the bits is not enough, there is a procedure 
            //		   ( constructor ) that should create the object. For this reason the placement new exist
            //
            //      2. The memory space life time is divided from the life time of the object inside it. For that the object is initialized using displacment new, and deleted 
            //		   using explicit call to it's destructor when the program ends
            //
            //      3. Some terminology, the given index ( which is just an index for array ) is used to divide the array into 2 parts. The beginning which include the entry
            //         associated with the index, and the ending part. So for example index 6 will divide the following array :
            //
            //                                              array       ->      {1,2,3,4,5,6,7,8,9,10}
            //                                                                   **************&&&&&&
            //                                                                       |       |      |
            //                                                                       |    index 6   |
            //                                                                       |              |
            //                                                                 beginning part       |
            //                                                                                 ending part
            //
            //  Excpections :
            //
            //      NONE
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
                //      Constructor, receive the required size of the basic types array and a reference to an existing object. The reference will be used to initialze all the 
                //      entries of the basic types array
                //
                //      Non explicit on purpose to allow implicit converstions between basic data types
                //
                //  Required arguments :
                //
                //      User information needed :
                //
                //          1. size - the required number of entries in the basic types array
                //          2. value - a reference to an object that all the entries will be initialzed to
                //
                //      Information returned to the user :
                //
                //          NONE
                //
                //  Return value :
                //
                //        NONE
                //
                //  Excpections :
                //
                //      1. The given size should be larger then 0
                //      2. 
                //
                //  Possible errors :
                //
                //      1. There is no more free memory space - a class std::bad_alloc is thrown
                //      2. 
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
                //      Assignment operator, can handle with self assignment and instances in default state
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
                //      Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances in default state
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
                //      Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state
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
                //  Excpections :
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
                //      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
                //
                //  Required arguments :
                //
                //      User information needed :
                //
                //          1. newSize - the required number of entries in the basic types array
                //          2. value - the memory segment will be intialized with this value
                //
                //      Information returned to the user :
                //
                //          NONE
                //
                //  Return value :
                //
                //      NONE
                //
                //  Excpections :
                //
                //      1. The given size should be larger then 0
                //      2. 
                //
                //  Possible errors :
                //
                //      1. There is no more free memory space - a class std::bad_alloc is thrown
                //      2. 
                //
                inline void Initiate( UnsignedInteger64bits newSize, BasicType value = 0 );


        		// Method Information :
        		//
        		//  Description :
        		//
        		//   	Destructor,
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
        		virtual inline void SetToDefaultState();


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
        		virtual inline Boolean DefaultState() const;


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
        		virtual inline void DeleteResourcesAndSetToDefaultState();


        		// The following methods are the interface of the object. This methods implement the capabilities of the object :


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
                //  Excpections :
                //
                //      1. The instance should not be in default state, although the method will work it will just return 0
                //      2. 
                //
                //  Possible errors :
                //
                //      They will come
                //
                inline UnsignedInteger64bits Size() const;


                // Method Information :
                //
                //  Description :
                //
                //      Use this to set all the entries of the basic types array to the required value
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
                //  Excpections :
                //
                //      1. The instance should not be in default state
                //      2. The instance should not be empty
                //      3. 
                //
                //  Possible errors :
                //
                //      1. There is no more free memory space - a class std::bad_alloc is thrown
                //      2. 
                //
                inline void SetAll( BasicType value );


                // This part of the interface will deal with all the changes to the memory segment, adding and removing entries :


                // Method Information :
                //
                //  Description :
                //
                //      Use this method to add an other instance before the entry associated with the index. The addition of entries starts from the given index, which means 
                //      that the current entry in the index will be pushed up the required amount of additional entires. There is one edge case that needs to be dealt with, 
                //      how to add after the array. For this case the range of allowed values for the index is increased by 1 and it covers also the first entry behind the 
                //      end of the array
                //
                //  Required arguments :
                //
                //      User information needed :
                //
                //          1. index - this will used to determine the entry
                //          2. value - this value will be added to the array
                //
                //      Information returned to the user :
                //
                //          NONE
                //
                //  Return value :
                //
                //      NONE
                //
                //  Excpections :
                //
                //      1. The instance should not be in default state
                //      2. The index should be in the range 0 until the size of the array
                //      3. 
                //
                //  Possible errors :
                //
                //      1. There is no more free memory space - a class std::bad_alloc is thrown
                //      2. Deleting the old memory space failed
                //      3. 
                //
                inline void Add( UnsignedInteger64bits index, BasicType value );


                // Method Information :
                //
                //  Description :
                //
                //      Use this method to add an other instance before the entry associated with the index. If the instance is empty, then it will just become a copy of the
                //      other instance. The addition of entries starts from the given index, which means that the current entry in the index will be pushed up the required
                //      amount of additional entires. There is one edge case that needs to be dealt with, how to add after the array. For this case the range of allowed 
                //      values for the index is increased by 1 and it covers also the first entry behind the end of the array
                //
                //  Required arguments :
                //
                //      User information needed :
                //
                //          1. startingIndex - this will used to determine the starting entry
                //          2. other - a reference to an other instance
                //
                //      Information returned to the user :
                //
                //          NONE
                //
                //  Return value :
                //
                //      NONE
                //
                //  Excpections :
                //
                //      1. The instance should not be in default state
                //      2. The other instance should not be in default state or empty
                //      3. The starting index should be in the range 0 until the size of the array
                //      4. 
                //
                //  Possible errors :
                //
                //      1. There is no more free memory space - a class std::bad_alloc is thrown
                //      2. Deleting the old memory space failed
                //      3. 
                //
                inline void Add( UnsignedInteger64bits startingIndex, const Basic< BasicType >& other );


                // Method Information :
                //
                //  Description :
                //
                //      Use this method to remove all the entries starting from the one associated with the index
                //
                //  Required arguments :
                //
                //      User information needed :
                //
                //          1. index - this will used to determine the required entry
                //          2. size- the number of entries before that needs to be moved
                //
                //      Information returned to the user :
                //
                //          NONE
                //
                //  Return value :
                //
                //      NONE
                //
                //  Excpections :
                //
                //      1. The instance should not be in default state
                //      2. The instance is not empty
                //      3. The starting index should be in the range of the array current entries
                //      4. The given size should not be 0, or larger then the array size
                //      5.    
                //
                //  Possible errors :
                //
                //      They will come
                //
                inline void Remove( UnsignedInteger64bits startingIndex, UnsignedInteger64bits size );                


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
                //      An arithmetic proxy object
                //
                //  Excpections :
                //
                //      1. The instance should not be in default state
                //      2. The index should be in the range of the array current entries
                //      3. 
                //
                //  Possible errors :
                //
                //      They will come
                //
                inline typename Proxy::Basic< Basic< BasicType > , UnsignedInteger64bits, BasicType > operator[]( UnsignedInteger64bits index );


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
                //  Excpections :
                //
                //      1. The instance should not be in default state
                //      2. The index should be in the range of the array current entries
                //      3.           
                //
                //  Possible errors :
                //
                //      They will come
                //
                inline BasicType operator[]( UnsignedInteger64bits index ) const;


                // Method Information :
                //
                //  Description :
                //
                //      Use to get the address of the required entry
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
                //  Excpections :
                //
                //      1. The instance should not be in default state
                //      2. The index should be in the range of the array current entries
                //      3.             
                //
                //  Possible errors :
                //
                //      They will come
                //
                inline BasicType* operator+( UnsignedInteger64bits index );


                // Method Information :
                //
                //  Description :
                //
                //      Use to concatenate the given array to the end of the basic types array
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
                //      a reference to this instance
                //
                //  Excpections :
                //
                //      1. The instance should not be in default state
                //      2. The other instance should not be in default state or empty
                //      3. 
                //
                //
                //  Possible errors :
                //
                //      1. There is no more free memory space - class std::bad_alloc is thrown
                //      2. 
                //
                inline Basic< BasicType >& operator+=( const Basic< BasicType >& other );


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
                //  Excpections :
                //
                //      NONE
                //
                //  Possible errors :
                //
                //      They will come
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
                //  Excpections :
                //
                //      NONE
                //
                //  Possible errors :
                //
                //      They will come
                //
                Boolean operator!=( const Basic< BasicType >& other ) const;


                DEBUG_TOOL(

                    // This part of the class is dedicated for testing :


                    // Method Information :
                    //
                    //  Description :
                    //
                    //      This method is used to test the object
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
                    //  Excpections :
                    //
                    //      NONE
                    //
                    //  Possible errors :
                    //
                    //      1. A method does not work correctly
                    //      2. There is no more free memory space - class std::bad_alloc is thrown
                    //      3. 
                    //
                    static void Test();

                )  //  End of debug tool


            protected:


        		// The protected part is used for inheritance. This means that only this object and the objects that will inherit from it can use the protected data
        		// members or methods

        		// This object will store the basic types array
        		DataTypes::HeapSharedPointer< BasicType > m_array;

                // This object will store the size of the basic types array
                UnsignedInteger64bits m_size;
                
                // This object will store the free space that can be used before the first entry of the basic types array
                UnsignedInteger64bits m_numberOfFreeEntriesBefore;


        	private:


                // Allow the inherited arithmetic proxy object, to access protected and private sections of this object
                friend class Proxy::Basic< Basic< BasicType >, UnsignedInteger64bits, BasicType >;


        		// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
        		// rather help implement it :


                // Method Information :
                //
                //  Description :
                //
                //      Use this to get the number of additional bits to manage the basic types array. This additional space will be used to prevent allocating new space and copying 
                //      the array into it every change in the basic types array size
                //
                //  Required arguments :
                //
                //      User information needed :
                //
                //          size - the number of entires required for the basic types array
                //
                //      Information returned to the user :
                //
                //          NONE
                //  
                //  Return value :
                //
                //      The number of additional entries required to manage the basic types array
                //
                //  Excpections :
                //
                //      1. The given size is larger then 0
                //      2. 
                //
                //  Possible errors :
                //
                //      They will come
                //
                inline UnsignedInteger64bits MoreEntriesRequired_IMP( UnsignedInteger64bits size ) const;


                // Method Information :
                //
                //  Description :
                //
                //      Use this method to make space for adding entries to the array        
                //
                //  Required arguments :
                //
                //      User information needed :
                //
                //          1. index - this will used to determine the required entry
                //          2. size - the number of additional entries needed
                //          3. 
                //
                //      Information returned to the user :
                //
                //          NONE
                //  
                //  Return value :
                //
                //      NONE
                //
                //  Excpections :
                //
                //      1. The instance should not be in default state
                //      2. The number of additional entries required should be larger then 0
                //      3. The index should be in the range of the array current entries
                //      4.            
                //
                //  Possible errors :
                //
                //      1. There is no more memory space - class std::bad_alloc is thrown
                //      2. Deleting the old memory space failed
                //      3.
                //
                void MakeSpace_IMP( UnsignedInteger64bits index, UnsignedInteger64bits size );


                // Method Information :
                //
                //  Description :
                //
                //      Use this method to ensure that the memory space can contain the given amount before the beginning of the basic types array        
                //
                //  Required arguments :
                //
                //      User information needed :
                //
                //          size - the number of additional entries needed at the beginning
                //
                //      Information returned to the user :
                //
                //          NONE
                //  
                //  Return value :
                //
                //      NONE
                //
                //  Excpections :
                //
                //      1. The instance should not be in default state
                //      2. The number of additional entries required should be larger then 0
                //      3.            
                //
                //  Possible errors :
                //
                //      1. There is no more memory space - class std::bad_alloc is thrown
                //      2. Deleting the old memory space failed
                //      3.
                //
                void MakeSpaceAtTheBeginning_IMP( UnsignedInteger64bits size );


                // Method Information :
                //
                //  Description :
                //
                //      Use to allocate bigger memory space and copy the basic types array to the middle of the new memory space
                //
                //  Required arguments :
                //
                //      User information needed :
                //  
                //          size - the number of additional entries required
                //
                //      Information returned to the user :
                //
                //          NONE
                //
                //  Return value :
                //
                //      NONE
                //
                //  Excpections :
                //
                //      1. The instance should not be in default state
                //      2. The number of additional entries required should be larger then 0
                //      3.            
                //
                //  Possible errors :
                //
                //      1. There is no more memory space - class std::bad_alloc is thrown
                //      2. Deleting the old memory space failed
                //      3.
                //
                inline void AllocateBiggerMemorySpaceAndCopyTheArrayToTheMiddle_IMP( UnsignedInteger64bits size );


                // Method Information :
                //
                //  Description :
                //
                //      Use this to check if the given number of entries can still fit before the beginning of the basic types array
                //
                //  Required arguments :
                //
                //      User information needed :
                //  
                //          size - the amount to check if it can fit before the beginning of the basic types array
                //
                //      Information returned to the user :
                //
                //          NONE
                //
                //  Return value :
                //
                //      1. true - if the amount can fit before the beginning of the basic types array
                //      2. false - if there is not enough free space
                //
                //  Excpections :
                //
                //      1. The instance should not be in default state
                //      2. The given size is larger then 0
                //      3.             
                //
                //  Possible errors :
                //
                //      They will come
                //
                inline Boolean DoesEnoughFreeMemorySpaceExistInTheBeginning_IMP( UnsignedInteger64bits size ) const;


                // Method Information :
                //
                //  Description :
                //
                //      Use this to check if the given number of entries can still fit after the end of the basic types array
                //
                //  Required arguments :
                //
                //      User information needed :
                //  
                //          size - the amount to check if it can fit after the end of the basic types array
                //
                //      Information returned to the user :
                //
                //          NONE
                //
                //  Return value :
                //
                //      1. true - if the amount can fit after the end of the basic types array
                //      2. false - if there is not enough free space
                //
                //  Excpections :
                //
                //      1. The instance should not be in default state
                //      2. The given size is larger then 0
                //      3.             
                //
                //  Possible errors :
                //
                //      They will come
                //
                inline Boolean DoesEnoughFreeMemorySpaceExistInTheEnd_IMP( UnsignedInteger64bits size ) const;


                // Method Information :
                //
                //  Description :
                //
                //      Use this to get the number of free entries after the end of the basic types array
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
                //      The number of free entries after the end of the basic types array
                //
                //  Excpections :
                //
                //      1. The instance should not be in default state
                //      2.             
                //
                //  Possible errors :
                //
                //      They will come
                //
                inline UnsignedInteger64bits DetermineTheSizeOfTheFreeMemorySpaceAtTheEnd_IMP() const;


                // Method Information :
                //
                //  Description :
                //
                //      Use this to get a number. This number should be used to decide whether move the array to the middle of the current memory space or to allocate a new larger 
                //      memory space. This number represent the number of entries that should be sent to the methods that check if the memory space can contain more entries. The
                //      method will take into account the current number of free entries before and after the array in the memory segment. The array should only be moved if it will 
                //      make dealing with further changes possible and not copying a large array and then after 2 new entries, to copy it again
                //
                //  Required arguments :
                //
                //      User information needed :
                //  
                //          size - the number of additional entries required
                //
                //      Information returned to the user :
                //
                //          NONE
                //
                //  Return value :
                //
                //      A number of entries that if can fit, makes moving the basic types array currently preferable, then allocating new memory space
                //
                //  Excpections :
                //
                //      1. The instance should not be in default state
                //      2. The given number of additional entries required is larger then 0
                //      3.             
                //
                //  Possible errors :
                //
                //      They will come
                //
                inline UnsignedInteger64bits CalculateSizeThatMakesMovingTheArrayPreferableThenAllocatingAnotherMemorySpace_IMP( UnsignedInteger64bits size ) const;


                // Method Information :
                //
                //  Description :
                //
                //      Use this method to ensure that the memory space can contain the given amount after the end of the basic types array
                //
                //  Required arguments :
                //
                //      User information needed :
                //
                //          size - the number of additional entries needed at the end
                //
                //      Information returned to the user :
                //
                //          NONE
                //  
                //  Return value :
                //
                //      NONE
                //
                //  Excpections :
                //
                //      1. The instance should not be in default state or empty
                //      2. The number of additional entries required should be larger then 0
                //      3.            
                //
                //  Possible errors :
                //
                //      1. There is no more memory space - class std::bad_alloc is thrown
                //      2. Deleting the old memory space failed
                //      3.
                //
                void MakeSpaceAtTheEnd_IMP( UnsignedInteger64bits size );


                // Method Information :
                //
                //  Description :
                //
                //      Use this method to ensure that the memory space can contain the given amount at the middle of the basic types array        
                //
                //  Required arguments :
                //
                //      User information needed :
                //
                //          1. index - this will used to determine the required entry
                //          2. size - the number of additional entries needed at the middle
                //
                //      Information returned to the user :
                //
                //          NONE
                //  
                //  Return value :
                //
                //      NONE
                //
                //  Excpections :
                //
                //      1. The instance should not be in default state or empty
                //      2. The number of additional entries required should be larger then 0
                //      3. The index should be in the range of the array current entries
                //      4. 
                //
                //  Possible errors :
                //
                //      1. There is no more memory space - class std::bad_alloc is thrown
                //      2. The object does not have assignment opeartor
                //      3. Deleting the old memory space failed
                //      4.
                //
                void MakeSpaceAtTheMiddle_IMP( UnsignedInteger64bits index, UnsignedInteger64bits size );


                // Method Information :
                //
                //  Description :
                //
                //      Use to allocate bigger memory space and copy the 2 parts of the array divided by the given index with gap to the new memory space
                //
                //  Required arguments :
                //
                //      User information needed :
                // 
                //          1. arrayBeginning - this will point to the beginning part of the array
                //          2. arrayEnding - this will point to the ending part of the array
                //          3. size - the number of additional entries required at the middle
                //
                //      Information returned to the user :
                //
                //          NONE
                //
                //  Return value :
                //
                //      NONE
                //
                //  Excpections :
                //
                //      1. The instance should not be in default state or empty
                //      2. The number of additional entries required should be larger then 0
                //      3. The pointer instance to the beginning of the array should not be in default state
                //      4. The pointer instance to the ending of the array should not be in default state
                //      5.
                //
                //  Possible errors :
                //
                //      1. There is no more memory space - class std::bad_alloc is thrown
                //      2. The object does not have assignment opeartor
                //      3. Deleting the old memory space failed
                //      4.
                //
                inline void AllocateBiggerMemorySpaceAndCopyTheArrayPartsWithGap_IMP( const DataTypes::HeapSharedPointer< BasicType > arrayBeginning, const DataTypes::HeapSharedPointer< BasicType > arrayEnding, UnsignedInteger64bits size );


                // Method Information :
                //
                //  Description :
                //
                //      Use to allocate smaller memory space and copy the basic types array parts contigous without the removed entries
                //
                //  Required arguments :
                //
                //      User information needed :
                //  
                //          1. arrayBeginning - this will point to the beginning part of the array
                //          2. arrayEnding - this will point to the ending part of the array
                //          3. numberOfEntriesToRemove - the number of entries needed to be removed
                //
                //      Information returned to the user :
                //
                //          NONE
                //
                //  Return value :
                //
                //      NONE
                //
                //  Excpections :
                //
                //      1. The instance should not be in default state, and the size at least 3
                //      2. The number of entries to remove should be larger then 0
                //      3. The pointer instance to the beginning of the array should not be in default state
                //      4. The pointer instance to the ending of the array should not be in default state
                //      5.
                //
                //  Possible errors :
                //
                //      1. There is no more memory space - class std::bad_alloc is thrown
                //      2. The object does not have assignment opeartor
                //      3. Deleting the old memory space failed
                //      4.
                //
                inline void AllocateSmallerMemorySpaceAndCopyTheArrayPartsContigousWithoutTheRemovedEntries_IMP( const DataTypes::HeapSharedPointer< BasicType > arrayBeginning, const DataTypes::HeapSharedPointer< BasicType > arrayEnding, UnsignedInteger64bits numberOfEntriesToRemove );
            

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
                //  Excpections :
                //
                //      1. The instance should not be in default state or empty
                //      2. The index should be in the range of the array current entries
                //      3. 
                //
                //  Possible errors :
                //
                //      They will come
                //
                inline BasicType& GetData_IMP( UnsignedInteger64bits index );


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
                //  Excpections :
                //
                //      1. The instance should not be in default state or empty
                //      2. The index should be in the range of the array current entries
                //      3. 
                //
                //  Possible errors :
                //
                //      They will come
                //
                inline BasicType GetData_IMP( UnsignedInteger64bits index ) const;


                // Method Information :
                //
                //  Description :
                //
                //      This method can be used when the default behavior for operators that change the state of the object
                //      is not good enough. As default this method will be left empty, and if the user needs some different
                //      behavior then he can override it
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
                //  Excpections :
                //
                //      NONE
                //
                //  Possible errors :
                //
                //      They will come
                //
                void ExecuteTaskBeforeObjectChanges_IMP();


            };  //  Class BasicTypesArray











































//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************















































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
            //  Excpections :
            //
            //      NONE
        	//
        	//  Possible errors :
        	//
        	//		They will come
        	//
        	template< typename BasicType >
        	inline Basic< BasicType >::Basic() :
            m_array(),
            m_size( 0 ),
            m_numberOfFreeEntriesBefore( 0 )
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
            //          1. size - the required number of entries in the basic types array
            //          2. value - the memory segment will be intialized with this value
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //        NONE
            //
            //  Excpections :
            //
            //      1. The given size should be larger then 0
            //      2. 
            //
            //  Possible errors :
            //
            //      1. There is no more free memory space - a class std::bad_alloc is thrown
            //      2. 
            //
            template< typename BasicType >
            inline Basic< BasicType >::Basic( UnsignedInteger64bits size, BasicType value ) :
            m_array(),
            m_size( size ),
            m_numberOfFreeEntriesBefore()
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                ASSERT( ( size > 0 ), "Abilities::Array::Basic::Constructor failed - the size should be larger then 0" )

                // Check if the given size is larger or equal to 32
                if ( size >= 128 )
                {
                    // The size is larger or equal to 32

                    // Use the size to create the capacity
                    m_array.Initiate( size + MoreEntriesRequired_IMP( size ) );

                    // Set the number of free entries before the beginning of the array
                    m_numberOfFreeEntriesBefore = ( MoreEntriesRequired_IMP( size ) / 2 );
                }
                else
                {
                    // The size is smaller then 128, to prevent many allocations and copies the capacity will be determined using 128

                    // Use 128 to create the capacity
                    m_array.Initiate( 128 );

                    // Set the number of free entries before the beginning of the array
                    m_numberOfFreeEntriesBefore = ( ( 128 - size ) / 2 );
                }

                // Set the elements of the memory segment to the required value
                SetAll( value );
            }


        	// Method Information :
        	//
        	//  Description :
        	//
            //      Copy constructor, will operate correctly even if the other object is in default state
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
            //  Excpections :
            //
            //      NONE
            //
        	//  Possible errors :
        	//
        	//		They will come
        	//
        	template< typename BasicType >
        	inline Basic< BasicType >::Basic( const Basic< BasicType >& other ) :
            m_array( other.m_array ),
            m_size( other.m_size ),
            m_numberOfFreeEntriesBefore( other.m_numberOfFreeEntriesBefore )
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
            //  Excpections :
            //
            //      NONE
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
            //  Excpections :
            //
            //      NONE
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
            //  Excpections :
            //
            //      NONE
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

        	    // Swap between the default constructed instance, which is in default state, and the other instance
        	    defaultConstructedInstance.Swap( other );

        	    // Swap between this instance and the default constructed instance one
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
            //  Excpections :
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
                // Swap the share pointers
                m_array.Swap( other.m_array );

                // Swap the sizes
                Memory::Swap< UnsignedInteger64bits >( m_size, other.m_size );

                // Swap the number of free entries before
                Memory::Swap< UnsignedInteger64bits >( m_numberOfFreeEntriesBefore, other.m_numberOfFreeEntriesBefore );
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
            //          1. newSize - the required number of entries in the basic types array
            //          2. value - the memory segment will be intialized with this value
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Excpections :
            //
            //      1. The given size should be larger then 0
            //      2. 
            //
            //  Possible errors :
            //
            //      1. There is no more free memory space - a class std::bad_alloc is thrown
            //      2. 
            //
            template< typename BasicType >
            inline void Basic< BasicType >::Initiate( UnsignedInteger64bits newSize, BasicType value )
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                ASSERT( ( newSize > 0 ), "Abilities::Array::Basic::Initiate failed - the size should be larger then 0" )

                // Create a temporary instance
                Basic< BasicType > temporary( newSize, value );

                // Swap between this instance and the temporary
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
            //  Excpections :
            //
            //      NONE
            //
        	//  Possible errors :
        	//
        	//	    They will come
        	//
        	template< typename BasicType >
        	inline void Basic< BasicType >::SetToDefaultState()
        	{
        		// Set the pointer instance to default state
        		m_array.SetToDefaultState();

                // Set the size to 0
                m_size = 0;

        		// Set the number of free entries before the beginning of the basic types array
        		m_numberOfFreeEntriesBefore = 0;
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
            //  Excpections :
            //
            //      NONE
            //
        	//  Possible errors :
        	//
        	//		They will come
        	//
        	template< typename BasicType >
        	inline Boolean Basic< BasicType >::DefaultState() const
        	{
        		// Check if the object is not in default state, and return the result
        		return ( ( m_array.DefaultState() == true ) && ( m_size == 0 ) && ( m_numberOfFreeEntriesBefore == 0 ) );
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
            //  Excpections :
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

                // Release the resources of this object
                m_array.DeleteResourcesAndSetToDefaultState();

                // Set the size to 0
                m_size = 0;

                // Set the number of free entries before the beginning of the basic types array
                m_numberOfFreeEntriesBefore = 0;
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
            //  Excpections :
            //
            //      1. The instance should not be in default state, although the method will work it will just return 0
            //      2. 
            //
            //  Possible errors :
            //
            //      They will come
            //
            template< typename BasicType >
            inline UnsignedInteger64bits Basic< BasicType >::Size() const
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                ASSERT( ( DefaultState() == false ), "Abilities::Array::Basic::Size failed - the instance is in default state" )

                // Return the number of entries in the basic types platfrom
                return ( m_size );
            }


            // Method Information :
            //
            //  Description :
            //
            //      Use this to set all the entries of the basic types array to the required value
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
            //  Excpections :
            //
            //      1. The instance should not be in default state
            //      2. The instance should not be empty
            //      3. 
            //
            //  Possible errors :
            //
            //      1. There is no more free memory space - a class std::bad_alloc is thrown
            //      2.             
            //
            template< typename BasicType >
            inline void Basic< BasicType >::SetAll( BasicType value )
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                ASSERT( ( DefaultState() == false ), "Abilities::Array::Basic::SetAll failed - the instance is in default state" )
                ASSERT( ( m_size > 0 ), "Abilities::Array::Basic::SetAll failed - the instance is empty" )

                // A write operation is about to take place, check if only this instance uses the resource, if not, copy it to a new one that only this instance uses
                ExecuteTaskBeforeObjectChanges_IMP();

                // Set the all the entries to the required value
                Memory::Set::Basic< BasicType >( TAKE( m_array.Part( m_numberOfFreeEntriesBefore, m_size ) ), value );
            }


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to add an other instance before the entry associated with the index. If the instance is empty, then it will just become a copy of the
            //      other instance. The addition of entries starts from the given index, which means that the current entry in the index will be pushed up the required
            //      amount of additional entires. There is one edge case that needs to be dealt with, how to add after the array. For this case the range of allowed 
            //      values for the index is increased by 1 and it covers also the first entry behind the end of the array
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. startingIndex - this will used to determine the starting entry
            //          2. other - a reference to an other instance
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Excpections :
            //
            //      1. The instance should not be in default state
            //      2. The other instance should not be in default state or empty
            //      3. The starting index should be in the range 0 until the size of the array
            //      4. 
            //
            //  Possible errors :
            //
            //      1. There is no more free memory space - a class std::bad_alloc is thrown
            //      2. Deleting the old memory space failed
            //      3. 
            //
            template< typename BasicType >
            inline void Basic< BasicType >::Add( UnsignedInteger64bits startingIndex, const Basic< BasicType >& other )
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                ASSERT( ( DefaultState() == false ), "Abilities::Array::Basic::Add failed - the instance is in default state" )
                ASSERT( ( other.DefaultState() == false ), "Abilities::Array::Basic::Add failed - the other instance is in default state" )
                ASSERT( ( other.m_size > 0 ), "Abilities::Array::Basic::Add failed - the other instance is empty" )            
                ASSERT( ( ( startingIndex >= 0 ) && ( startingIndex <= m_size ) ), "Abilities::Array::Basic::Add failed - the given starting index is out of the allowed range" )

                // Check if the instance is empty
                if ( m_size == 0 )
                {
                    // The instance is empty

                    // Copy the other instance
                    *this = other;

                    // There is nothing else that needs to be done
                    return;
                }

                // Make space for the other entries 
                MakeSpace_IMP( startingIndex, other.Size() );

                // Copy the other instance to the gap starting from the entry the index is point to. The value that was in that location was moved to the first location of the
                // ending part
                Memory::Copy::Basic< BasicType >( TAKE( other.m_array.Part( other.m_numberOfFreeEntriesBefore, other.m_size ) ), TAKE( m_array.Part( ( m_numberOfFreeEntriesBefore + startingIndex ), other.m_size ) ) );
            }


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to add an other instance before the entry associated with the index. The addition of entries starts from the given index, which means 
            //      that the current entry in the index will be pushed up the required amount of additional entires. There is one edge case that needs to be dealt with, 
            //      how to add after the array. For this case the range of allowed values for the index is increased by 1 and it covers also the first entry behind the 
            //      end of the array
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. index - this will used to determine the entry
            //          2. value - this value will be added to the array
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Excpections :
            //
            //      1. The instance should not be in default state
            //      2. The index should be in the range 0 until the size of the array
            //      3. 
            //
            //  Possible errors :
            //
            //      1. There is no more free memory space - a class std::bad_alloc is thrown
            //      2. Deleting the old memory space failed
            //      3. 
            //
            template< typename BasicType >
            inline void Basic< BasicType >::Add( UnsignedInteger64bits index, BasicType value )
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                ASSERT( ( DefaultState() == false ), "Abilities::Array::Basic::Add value failed - the instance is in default state" )           
                ASSERT( ( ( index >= 0 ) && ( index <= m_size ) ), "Abilities::Array::Basic::Add value failed - the given starting index is out of the allowed range" )

                // Check if the instance is empty
                if ( m_size == 0 )
                {
                    // The instance is empty

                    // Set the entry with the required value
                    m_array[ m_numberOfFreeEntriesBefore + index ] = value;

                    // There is nothing else that needs to be done
                    return;
                }

                // Make space for the other entries 
                MakeSpace_IMP( index, 1 );

                // Set the entry with the required value
                m_array[ m_numberOfFreeEntriesBefore + index ] = value;
            }


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to remove all the entries starting from the one associated with the index
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. index - this will used to determine the required entry
            //          2. size- the number of entries before that needs to be moved
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Excpections :
            //
            //      1. The instance should not be in default state or empty
            //      2. The starting index should be in the range of the array current entries
            //      3. The given size should not be 0, or larger then the array size
            //      4.    
            //
            //  Possible errors :
            //
            //      They will come
            //
            template< typename BasicType >
            void Basic< BasicType >::Remove( UnsignedInteger64bits startingIndex, UnsignedInteger64bits size )
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                ASSERT( ( DefaultState() == false ), "Abilities::Array::Basic::Remove failed - the instance is in default state" )
                ASSERT( ( m_size > 0 ), "Abilities::Array::Basic::Remove failed - the instance is empty" )
                ASSERT( ( ( startingIndex >= 0 ) && ( startingIndex < m_size ) ), "Abilities::Array::Basic::Remove failed - the given starting index is out of the array range" )
                ASSERT( ( ( size > 0 ) && ( size <= m_size ) ), "Abilities::Array::Basic::Remove failed - the given size is larger then the array current size" )

                // Check if all the entries needs to be removed
                if ( ( startingIndex == 0 ) && ( size == m_size ) )
                {
                    // All the entries needs to be removed

                    // Set the size to 0
                    m_size = 0;

                    // Set the memory space to 128
                    m_array.Initiate( 128 );

                    // Set the number of free entries before the beginning of the array according to the capacity
                    m_numberOfFreeEntriesBefore = 63;

                    // There is nothing else to do
                    return;
                }

                // Check if the starting index is 0
                if ( startingIndex == 0 )
                {
                    // The starting index is 0

                    // A chunck in the beginning of the array needs to be removed

                    // Decrease the size of the array by the required amount
                    m_size -= size;

                    // Increase the number of free entries befroe the beginning of the array by the size
                    m_numberOfFreeEntriesBefore += size;

                    // There is nothing else that needs to be done
                    return;
                }

                // Check if the removed area is a part from the starting index until the last entry including
                if ( ( startingIndex + size ) == m_size )
                {
                    // A chunck in the end of the array needs to be removed

                    // Remove it

                    // Decrease the size of the array by the required amount
                    m_size -= size;

                    // There is nothing else that needs to be done
                    return;
                }

                // The method will locate the smaller part of the 2, the beginning or ending part without the removed entries. The point is to find which one is smaller, 
                // and then if the beginning part is smaller copy it up the indexes to the ending part, and vice versa

                // This pointer will point to the beginning part of the array that needs to stay
                DataTypes::HeapSharedPointer< BasicType > arrayBeginning = TAKE( m_array.Part( m_numberOfFreeEntriesBefore, startingIndex ) );

                // This pointer will point to the end part of the array that needs to stay
                DataTypes::HeapSharedPointer< BasicType > arrayEnding = TAKE( m_array.Part( ( m_numberOfFreeEntriesBefore + startingIndex + size ), ( m_size - startingIndex - size ) ) );

                // Check if other instances use the resource as well, or the current size of the array is less then half of the capacity
                if ( ( m_array.Counter() > 1 ) || ( m_size < ( m_array.Size() / 2 ) ) )
                {
                    // Not only this instance uses the resource

                    // Allocate larger memory space and copy the array parts to it with a gap in the size of the additional required entries
                    AllocateSmallerMemorySpaceAndCopyTheArrayPartsContigousWithoutTheRemovedEntries_IMP( TAKE( arrayBeginning ), TAKE( arrayEnding ), size );

                    // Nothing else needs to be done
                    return;
                }

                // Check which of the 2 parts is smaller
                if ( arrayBeginning.Size() < arrayEnding.Size() )
                {
                    // The beginning part is smaller then the ending part

                    // This object will store the number of entries to move the section to make the array contigous again
                    UnsignedInteger64bits numberOfEntriesToMove = ( arrayBeginning.Size() - size );

                    // Check if the size of the removed segment is larger then the array beginning
                    if ( arrayBeginning.Size() < size )
                    {
                        // The removed segment is larger then the array beginning

                        // Set the number of entries to move correctly
                        numberOfEntriesToMove = ( size - arrayBeginning.Size() );
                    }

                    // Copy the beginning part before the ending part of the array
                    Memory::Copy::Basic< BasicType >( arrayBeginning, TAKE( m_array.Part( ( m_numberOfFreeEntriesBefore + numberOfEntriesToMove ), arrayBeginning.Size() ) ) );                    

                    // Set the number of free entries before the beginning of the array
                    m_numberOfFreeEntriesBefore += size;
                }
                else
                {
                    // The ending part is smaller or equal to the beginning part

                    // Copy the ending after the beginning part of the array
                    Memory::Copy::Basic< BasicType >( arrayEnding, TAKE( m_array.Part( ( m_numberOfFreeEntriesBefore + arrayBeginning.Size() ), arrayEnding.Size() ) ) );                    
                }

                // Set the new size
                m_size -= size;
            }














































//  ***************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************
















































            // Method Information :
            //
            //  Description :
            //
            //      Use to get access to the required data associated with the index
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          index - this will used to determine the required entry
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      An arithmetic proxy object
            //
            //  Excpections :
            //
            //      1. The instance should not be in default state
            //      2. The index should be in the range of the array current entries
            //      3. 
            //
            //  Possible errors :
            //
            //      They will come
            //
            template< typename BasicType >
            inline typename Proxy::Basic< Basic< BasicType >, UnsignedInteger64bits, BasicType > Basic< BasicType >::operator[]( UnsignedInteger64bits index )
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                ASSERT( ( DefaultState() == false ), "Abilities::Array::Basic::operator[] failed - the instance is in default state" )
                ASSERT( ( ( index >= 0 ) && ( index < m_size ) ), "Abilities::Array::Basic::operator[] failed - the given index is out of the array range" )

                // Create an instance of the proxy with the required information and return a copy of it
                return ( typename Proxy::Basic< Basic< BasicType > , UnsignedInteger64bits, BasicType >( *this, ( m_numberOfFreeEntriesBefore + index ) ) );
            }


            // Method Information :
            //
            //  Description :
            //
            //      Use to get access to the required data associated with the index for constant instances
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          index - this will used to determine the required entry
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      A copy of the data associated with the index
            //
            //  Excpections :
            //
            //      1. The instance should not be in default state
            //      2. The index should be in the range of the array current entries
            //      3.           
            //
            //  Possible errors :
            //
            //      They will come
            //
            template< typename BasicType >
            inline BasicType Basic< BasicType >::operator[]( UnsignedInteger64bits index ) const
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                ASSERT( ( DefaultState() == false ), "Abilities::Array::Basic::operator[] constant failed - the instance is in default state" )
                ASSERT( ( ( index >= 0 ) && ( index < m_size ) ), "Abilities::Array::Basic::operator[] constant failed - the given index is out of the array range" )

                // Create the proxy class and return it
                return ( m_array[ m_numberOfFreeEntriesBefore + index ] );
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
            //  Excpections :
            //
            //      1. The instance should not be in default state
            //      2. The index should be in the range of the array current entries
            //      3.             
            //
            //  Possible errors :
            //
            //      They will come
            //
            template< typename BasicType >
            inline BasicType* Basic< BasicType >::operator+( UnsignedInteger64bits index )
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                ASSERT( ( DefaultState() == false ), "Abilities::Array::Basic::operator+ failed - the instance is in default state" )
                ASSERT( ( ( index >= 0 ) && ( index < m_size ) ), "Abilities::Array::Basic::operator+ failed - the given index is out of the array range" )

                // Create the proxy class and return it
                return ( m_array + index );
            }


            // Method Information :
            //
            //  Description :
            //
            //      Use to concatenate the given array to the end of the basic types array
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
            //      a reference to this instance
            //
            //  Excpections :
            //
            //      1. The instance should not be in default state
            //      2. The other instance should not be in default state or empty
            //      3. 
            //
            //
            //  Possible errors :
            //
            //      1. There is no more free memory space - class std::bad_alloc is thrown
            //      2. 
            //
            template< typename BasicType >
            inline Basic< BasicType >& Basic< BasicType >::operator+=( const Basic< BasicType >& other ) 
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                ASSERT( ( DefaultState() == false ), "Abilities::Array::Basic::operator+= failed - the instance is in default state" )
                ASSERT( ( other.DefaultState() == false ), "Abilities::Array::Basic::operator+= failed - the other instance is in default state" )
                ASSERT( ( other.m_size > 0 ), "Abilities::Array::Basic::operator+= failed - the other instance is empty" )

                // Add the other instance to the end of this instance
                AddAfter( ( m_size - 1 ), other );

                // Return a reference to this instance
                return ( *this );
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
            //  Excpections :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            template< typename BasicType >
            inline Boolean Basic< BasicType >::operator==( const Basic< BasicType >& other ) const
            {

                // Check if both instances are in default state
                if ( ( DefaultState() == true ) && ( other.DefaultState() == true ) )
                {
                    // Both instances are in default state

                    // Return that the instances match
                    return ( true );
                }
                // Check if this instance is in default state
                else if ( DefaultState() == true )
                {
                    // This instance is in default state

                    // Return that the instances mismatch
                    return ( false );
                }
                // Check if this instance is in default state
                else if ( other.DefaultState() == true )
                {
                    // The other instance is in default state

                    // Return that the instances mismatch
                    return ( false );
                }

                // Return the result of the comparison
                return ( Memory::Compare::Basic< BasicType >( TAKE( m_array.Part( m_numberOfFreeEntriesBefore, m_size ) ), TAKE( other.m_array.Part( other.m_numberOfFreeEntriesBefore, other.m_size ) ) ) );
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
            //  Excpections :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            template< typename BasicType >
            inline Boolean Basic< BasicType >::operator!=( const Basic< BasicType >& other ) const
            {
                // Return the negotiated value from the equal operator
                return ( !( *this == other ) );
            }












































//  ***************************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   *******************************************************















































            // Method Information :
            //
            //  Description :
            //
            //      Use this to get the number of additional bits to manage the basic types array. This additional space will be used to prevent allocating new space and copying 
            //      the array into it every change in the basic types array size
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          size - the number of entires required for the basic types array
            //
            //      Information returned to the user :
            //
            //          NONE
            //  
            //  Return value :
            //
            //      The number of additional entries required to manage the basic types array
            //
            //  Excpections :
            //
            //      1. The given size is larger then 0
            //      2. 
            //
            //  Possible errors :
            //
            //      They will come
            //
            template< typename BasicType >
            inline UnsignedInteger64bits Basic< BasicType >::MoreEntriesRequired_IMP( UnsignedInteger64bits size ) const
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                ASSERT( ( size > 0 ), "Abilities::Array::Basic::MoreEntriesRequired_IMP failed - the given size is 0" )

                // Return the number of additional bits to manage the array
                return ( ( ( size * AdditionalMemoryPercentageFromSize ) / 100 ) + 2 );
            }


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to make space for adding entries to the array        
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. index - this will used to determine the required entry
            //          2. size - the number of additional entries needed
            //          3. 
            //
            //      Information returned to the user :
            //
            //          NONE
            //  
            //  Return value :
            //
            //      NONE
            //
            //  Excpections :
            //
            //      1. The instance should not be in default state or empty
            //      2. The number of additional entries required should be larger then 0
            //      3. The index should be in the range of the array current entries
            //      4.            
            //
            //  Possible errors :
            //
            //      1. There is no more memory space - class std::bad_alloc is thrown
            //      2. Deleting the old memory space failed
            //      3.
            //
            template< typename BasicType >
            void Basic< BasicType >::MakeSpace_IMP( UnsignedInteger64bits startingIndex, UnsignedInteger64bits size )
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                ASSERT( ( DefaultState() == false ), "Abilities::Array::Basic::MakeSpace_IMP failed - the instance is in default state" )
                ASSERT( ( m_size > 0 ), "Abilities::Array::Basic::MakeSpace_IMP failed - the instance is empty" )            
                ASSERT( ( size > 0 ), "Abilities::Array::Basic::MakeSpace_IMP failed - the number of additional entries required is 0" )            
                ASSERT( ( ( startingIndex >= 0 ) && ( startingIndex <= m_size ) ), "Abilities::Array::Basic::MakeSpace_IMP failed - the given starting index is out of the array range" )

                // Check the value of the index and determine the required operation

                // Check if the index is index 0, and the entries should be added before it
                if ( startingIndex == 0 )
                {
                    // The required entries should be added before the beginning of the array
                    MakeSpaceAtTheBeginning_IMP( size );
                }
                // Check if the index is the last one in the array, and the entries should be added after it
                else if ( startingIndex == m_size )
                {
                    // The required entries should be added after the end of the array
                    MakeSpaceAtTheEnd_IMP( size );
                }
                else
                {
                    // The required entries should be added at the middle, make room
                    MakeSpaceAtTheMiddle_IMP( startingIndex, size );
                }

            }


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to ensure that the memory space can contain the given amount before the beginning of the basic types array        
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          size - the number of additional entries needed at the beginning
            //
            //      Information returned to the user :
            //
            //          NONE
            //  
            //  Return value :
            //
            //      NONE
            //
            //  Excpections :
            //
            //      1. The instance should not be in default state or empty
            //      2. The number of additional entries required should be larger then 0
            //      3.            
            //
            //  Possible errors :
            //
            //      1. There is no more memory space - class std::bad_alloc is thrown
            //      2. Deleting the old memory space failed
            //      3.
            //
            template< typename BasicType >
            void Basic< BasicType >::MakeSpaceAtTheBeginning_IMP( UnsignedInteger64bits size )
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                ASSERT( ( DefaultState() == false ), "Abilities::Array::Basic::MakeSpaceAtTheBeginning_IMP failed - the instance is in default state" )
                ASSERT( ( m_size > 0 ), "Abilities::Array::Basic::MakeSpaceAtTheBeginning_IMP failed - the instance is empty" )
                ASSERT( ( size > 0 ), "Abilities::Array::Basic::MakeSpaceAtTheBeginning_IMP failed - the number of additional entries required is 0" )            

                // Check if other instances use the resource as well, or the current instance is empty
                if ( m_array.Counter() > 1 )
                {
                    // Not only this instance uses the resource

                    // Allocate larger memory space and copy the content to it
                    AllocateBiggerMemorySpaceAndCopyTheArrayToTheMiddle_IMP( size );

                    // Nothing else needs to be done
                    return;
                }

                // Check if the current instance has enough free space to contain another entry. If it does then all good, if it doesn't it chooses between 2 options. The first 
                // is of course to allocate bigger memory space and copy the basic types array over there, the other is to just move the basic types array to the middle of the 
                // current memory space, with no need to allocate another

                // Check if there is more free space to use before the first entry
                if ( DoesEnoughFreeMemorySpaceExistInTheBeginning_IMP( size ) == true )
                {
                    // There is enough memory space at the beginning of the array

                    // Set the new size of the array
                    m_size += size;

                    // Subtract the number of entries moved from the number of free entries before the beginning of the array
                    m_numberOfFreeEntriesBefore -= size;
                }
                // Check if there is enough memory space at the end
                else if ( DoesEnoughFreeMemorySpaceExistInTheEnd_IMP( CalculateSizeThatMakesMovingTheArrayPreferableThenAllocatingAnotherMemorySpace_IMP( size ) ) == true )
                {
                    // There is enough memory space at the end of the array, move the array to the middle of the memory space
                    
                    std::cout << "[[[[[[[[[[[[[   " << size << std::endl;
                    std::cout << "#############   " << DetermineTheSizeOfTheFreeMemorySpaceAtTheEnd_IMP() << std::endl;


                    std::cout << "(((((((((((((   " << m_numberOfFreeEntriesBefore << std::endl;
                    std::cout << "$$$$$$$$$$$$$   " << m_size << std::endl;
                    ErrorHandling::Display::LinearContainer< Basic< BasicType > >( *this );

                    // Move the array the required amount of entries towards the end of the memory space allocated 
					Memory::Copy::Basic< BasicType >( TAKE( m_array.Part( m_numberOfFreeEntriesBefore, m_size ) ), TAKE( m_array.Part( ( m_numberOfFreeEntriesBefore + ( DetermineTheSizeOfTheFreeMemorySpaceAtTheEnd_IMP() / 2 ) + ( size / 2 ) ), m_size ) ) );

                    // Set the new size of the array
                    m_size += size;

                    // Set the new number of free entries before the beginning of the array
                    m_numberOfFreeEntriesBefore += ( ( DetermineTheSizeOfTheFreeMemorySpaceAtTheEnd_IMP() / 2 ) - ( size / 2 ) );

                    std::cout << "(((((((((((((   " << m_numberOfFreeEntriesBefore << std::endl;
                    std::cout << "$$$$$$$$$$$$$   " << m_size << std::endl;
                    ErrorHandling::Display::LinearContainer< Basic< BasicType > >( *this );
                }
                else
                {
                    // Memory space is absent!!

                    // The free space has ended, a new bigger space must be fetched
                    AllocateBiggerMemorySpaceAndCopyTheArrayToTheMiddle_IMP( size );
                }

            }


            // Method Information :
            //
            //  Description :
            //
            //      Use to allocate bigger memory space and copy the basic types array to the middle of the new memory space
            //
            //  Required arguments :
            //
            //      User information needed :
            //  
            //          size - the number of additional entries required
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Excpections :
            //
            //      1. The instance should not be in default state
            //      2. The number of additional entries required should be larger then 0
            //      3.            
            //
            //  Possible errors :
            //
            //      1. There is no more memory space - class std::bad_alloc is thrown
            //      2. Deleting the old memory space failed
            //      3.
            //
            template< typename BasicType >
            inline void Basic< BasicType >::AllocateBiggerMemorySpaceAndCopyTheArrayToTheMiddle_IMP( UnsignedInteger64bits size )
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                ASSERT( ( DefaultState() == false ), "Abilities::Array::Basic::AllocateBiggerMemorySpaceAndCopyTheArrayToTheMiddle_IMP failed - the instance is in default state" )
                ASSERT( ( size > 0 ), "Abilities::Array::Basic::AllocateBiggerMemorySpaceAndCopyTheArrayToTheMiddle_IMP failed - the number of additional entries required is 0" ) 
                
                // Create a temporary with the required memory space
                Basic< BasicType > temporary( m_size + size );

                // Copy the basic types array to the middle of the new memory space
                Memory::Copy::Basic< BasicType >( TAKE( m_array.Part( m_numberOfFreeEntriesBefore, m_size ) ), TAKE( temporary.m_array.Part( temporary.m_numberOfFreeEntriesBefore, m_size ) ) );

                // Swap between this instance and the temporary
                Swap( temporary );
            }


            // Method Information :
            //
            //  Description :
            //
            //      Use this to check if the given number of entries can still fit before the beginning of the basic types array
            //
            //  Required arguments :
            //
            //      User information needed :
            //  
            //          size - the amount to check if it can fit before the beginning of the basic types array
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      1. true - if the amount can fit before the beginning of the basic types array
            //      2. false - if there is not enough free space
            //
            //  Excpections :
            //
            //      1. The instance should not be in default state
            //      2. The given size is larger then 0
            //      3.             
            //
            //  Possible errors :
            //
            //      They will come
            //
            template< typename BasicType >
            inline Boolean Basic< BasicType >::DoesEnoughFreeMemorySpaceExistInTheBeginning_IMP( UnsignedInteger64bits size ) const
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                ASSERT( ( DefaultState() == false ), "Abilities::Array::Basic::DoesEnoughFreeMemorySpaceExistInTheBeginning_IMP failed - the instance is in default state" )
                ASSERT( ( size > 0 ), "Abilities::Array::Basic::DoesEnoughFreeMemorySpaceExistInTheBeginning_IMP failed - the given size is 0" )

                // Return the result of checking if the required amount at the beginning is larger or equal then the free space
                return ( m_numberOfFreeEntriesBefore >= size );
            }


            // Method Information :
            //
            //  Description :
            //
            //      Use this to check if the given number of entries can still fit after the end of the basic types array
            //
            //  Required arguments :
            //
            //      User information needed :
            //  
            //          size - the amount to check if it can fit after the end of the basic types array
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      1. true - if the amount can fit after the end of the basic types array
            //      2. false - if there is not enough free space
            //
            //  Excpections :
            //
            //      1. The instance should not be in default state
            //      2. The given size is larger then 0
            //      3.             
            //
            //  Possible errors :
            //
            //      They will come
            //
            template< typename BasicType >
            inline Boolean Basic< BasicType >::DoesEnoughFreeMemorySpaceExistInTheEnd_IMP( UnsignedInteger64bits size ) const
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                ASSERT( ( DefaultState() == false ), "Abilities::Array::Basic::DoesEnoughFreeMemorySpaceExistInTheEnd_IMP failed - the instance is in default state" )
                ASSERT( ( size > 0 ), "Abilities::Array::Basic::DoesEnoughFreeMemorySpaceExistInTheEnd_IMP failed - the given size is 0" )

                // Return the result of checking if the required amount at the beginning is larger then the free space
                return ( DetermineTheSizeOfTheFreeMemorySpaceAtTheEnd_IMP() >= size );
            }


            // Method Information :
            //
            //  Description :
            //
            //      Use this to get the number of free entries after the end of the basic types array
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
            //      The number of free entries after the end of the basic types array
            //
            //  Excpections :
            //
            //      1. The instance should not be in default state
            //      2.             
            //
            //  Possible errors :
            //
            //      They will come
            //
            template< typename BasicType >
            inline UnsignedInteger64bits Basic< BasicType >::DetermineTheSizeOfTheFreeMemorySpaceAtTheEnd_IMP() const
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                ASSERT( ( DefaultState() == false ), "Abilities::Array::Basic::DetermineTheSizeOfTheFreeMemorySpaceAtTheEnd_IMP failed - the instance is in default state" )

                // Return the number of free entries after the end of the basic types array
                return ( m_array.Size() - ( m_numberOfFreeEntriesBefore + m_size ) );
            }


            // Method Information :
            //
            //  Description :
            //
            //      Use this to get a number. This number should be used to decide whether move the array to the middle of the current memory space or to allocate a new larger 
            //      memory space. This number represent the number of entries that should be sent to the methods that check if the memory space can contain more entries. The
            //      method will take into account the current number of free entries before and after the array in the memory segment. The array should only be moved if it will 
            //      make dealing with further changes possible and not copying a large array and then after 2 new entries, to copy it again
            //
            //  Required arguments :
            //
            //      User information needed :
            //  
            //          size - the number of additional entries required
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      A number of entries that if can fit, makes moving the basic types array currently preferable, then allocating new memory space
            //
            //  Excpections :
            //
            //      1. The instance should not be in default state
            //      2. The given number of additional entries required is larger then 0
            //      3.             
            //
            //  Possible errors :
            //
            //      They will come
            //
            template< typename BasicType >
            inline UnsignedInteger64bits Basic< BasicType >::CalculateSizeThatMakesMovingTheArrayPreferableThenAllocatingAnotherMemorySpace_IMP( UnsignedInteger64bits size ) const
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                ASSERT( ( DefaultState() == false ), "Abilities::Array::Basic::CalculateSizeThatMakesMovingTheArrayPreferableThenAllocatingAnotherMemorySpace_IMP failed - the instance is in default state" )
                ASSERT( ( size > 0 ), "Abilities::Array::Basic::CalculateSizeThatMakesMovingTheArrayPreferableThenAllocatingAnotherMemorySpace_IMP failed - the given size is 0" )
                
                // The minimum number of free entries for making the array use the same memory is 2 percentage from the basic types array size. The only left question is 
                // whether the number of additional entries required is smaller or larger then the current 2 percentage of the basic types array. Therefore the larger will 
                // be returned

                // Create an object to store 2 percentage from the current size, an additional 2 is added becasue this is the minimum value for which a move operation can happen
                UnsignedInteger64bits sizeOfFreeSpaceInCurrentMemorySpaceThatMakesNoNeedToGetAnother = ( ( ( m_size * 2 ) / 100 ) + 2 );

                // Check what is larger, the additional amount of entries or the 2 percentage from the size
                if ( size > sizeOfFreeSpaceInCurrentMemorySpaceThatMakesNoNeedToGetAnother )
                {
                    // The additional amount of entries required is larger then 2 percentage of the array size, then return the additional amount
                    return ( size );
                }

                // Return 2 percentage from the basic types array size
                return ( sizeOfFreeSpaceInCurrentMemorySpaceThatMakesNoNeedToGetAnother );
            }


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to ensure that the memory space can contain the given amount after the end of the basic types array
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          size - the number of additional entries needed at the end
            //
            //      Information returned to the user :
            //
            //          NONE
            //  
            //  Return value :
            //
            //      NONE
            //
            //  Excpections :
            //
            //      1. The instance should not be in default state or empty
            //      2. The number of additional entries required should be larger then 0
            //      3.            
            //
            //  Possible errors :
            //
            //      1. There is no more memory space - class std::bad_alloc is thrown
            //      2. Deleting the old memory space failed
            //      3.
            //
            template< typename BasicType >
            void Basic< BasicType >::MakeSpaceAtTheEnd_IMP( UnsignedInteger64bits size )
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                ASSERT( ( DefaultState() == false ), "Abilities::Array::Basic::MakeSpaceAtTheEnd_IMP failed - the instance is in default state" )
                ASSERT( ( m_size > 0 ), "Abilities::Array::Basic::MakeSpaceAtTheEnd_IMP failed - the instance is empty" )
                ASSERT( ( size > 0 ), "Abilities::Array::Basic::MakeSpaceAtTheEnd_IMP failed - the number of additional entries required is 0" )            

                // Check if other instances use the resource as well, or that the instance is empty
                if ( m_array.Counter() > 1  )
                {
                    // Not only this instance uses the resource

                    // Allocate larger memory space and copy the content to it
                    AllocateBiggerMemorySpaceAndCopyTheArrayToTheMiddle_IMP( size );

                    // There is nothing else that needs to be done
                    return;
                }

                // Check if the current instance has enough free space to contain another entry. If it does then all good, if it doesn't it chooses between 2 options. The first 
                // is of course to allocate bigger memory space and copy the basic types array over there, the other is to just move the basic types array to the middle of the 
                // current memory space, with no need to allocate another

                // Check if there is more free space to use after last entry
                if ( DoesEnoughFreeMemorySpaceExistInTheEnd_IMP( size ) == false )
                {
                    // There is enough memory space at the end of the array

                    // Set the new size of the array
                    m_size += size;
                }
                // Check if there is free space before the first entry
                else if ( DoesEnoughFreeMemorySpaceExistInTheBeginning_IMP( CalculateSizeThatMakesMovingTheArrayPreferableThenAllocatingAnotherMemorySpace_IMP( size ) ) == true )
                {
                    // There is enough memory space at the beginning of the array, move the array to the middle of the memory space

                    // Move the array the required amount of entries towards the beginning of the memory space allocated 
					Memory::Copy::Basic< BasicType >( TAKE( m_array.Part( m_numberOfFreeEntriesBefore, m_size ) ), TAKE( m_array.Part( ( m_numberOfFreeEntriesBefore - ( m_numberOfFreeEntriesBefore / 2 ) + ( size / 2 ) ), m_size ) ) );

                    // Set the new size of the array
                    m_size += size;                    

                    // Subtract the number of entries moved from the number of free entries before the beginning of the array
                    m_numberOfFreeEntriesBefore -= ( ( m_numberOfFreeEntriesBefore / 2 ) + ( size / 2 ) );
                }
                else
                {
                    // The free space has ended

                    // A new bigger space must be fetched
                    AllocateBiggerMemorySpaceAndCopyTheArrayToTheMiddle_IMP( size );
                }

            }


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to ensure that the memory space can contain the given amount at the middle of the basic types array        
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. startingIndex - this will used to determine the starting entry
            //          2. size - the number of additional entries needed at the middle
            //
            //      Information returned to the user :
            //
            //          NONE
            //  
            //  Return value :
            //
            //      NONE
            //
            //  Excpections :
            //
            //      1. The instance should not be in default state or empty
            //      2. The number of additional entries required should be larger then 0
            //      3. The index should be in the range of the array current entries
            //      4. 
            //
            //  Possible errors :
            //
            //      1. There is no more memory space - class std::bad_alloc is thrown
            //      2. The object does not have assignment opeartor
            //      3. Deleting the old memory space failed
            //      4.
            //
            template< typename BasicType >
            void Basic< BasicType >::MakeSpaceAtTheMiddle_IMP( UnsignedInteger64bits startingIndex, UnsignedInteger64bits size )
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                ASSERT( ( DefaultState() == false ), "Abilities::Array::Basic::MakeSpaceAtTheMiddle_IMP failed - the instance is in default state" )
                ASSERT( ( size > 0 ), "Abilities::Array::Basic::MakeSpaceAtTheMiddle_IMP failed - the number of additional entries required is 0" )            
                ASSERT( ( ( startingIndex > 0 ) && ( startingIndex < m_size ) ), "Abilities::Array::Basic::MakeSpaceAtTheMiddle_IMP failed - the given starting index is out of the array range" )
                ASSERT( ( m_size > 1 ), "Abilities::Array::Basic::MakeSpaceAtTheMiddle_IMP failed - the array size is smaller then 2" )

                // This pointer will point to the beginning part of the array
                DataTypes::HeapSharedPointer< BasicType > arrayBeginning = TAKE( m_array.Part( m_numberOfFreeEntriesBefore, ( startingIndex + 1 ) ) );

                // This pointer will point to the end part of the array
                DataTypes::HeapSharedPointer< BasicType > arrayEnding = TAKE( m_array.Part( ( m_numberOfFreeEntriesBefore + ( startingIndex + 1 ) ), ( m_size - arrayBeginning.Size() ) ) );

                // Check if other instances use the resource as well, or that the instance is empty. Remember that the 2 pointers above also use it
                if ( ( m_array.Counter() > 1 ) )
                {
                    // Not only this instance uses the resource

                    // Allocate larger memory space and copy the array parts to it with a gap in the size of the additional required entries
                    AllocateBiggerMemorySpaceAndCopyTheArrayPartsWithGap_IMP( TAKE( arrayBeginning ), TAKE( arrayEnding ), size );

                    // Nothing else needs to be done
                    return;
                }

                // Check if the current instance has enough free space to contain all the additional entries. The rational is that the starting index will be used to 
                // check if the required entry is closer to the beginning or the end of the array, this will allow to copy the smaller part of the array. The last thing to 
                // deal with is cases where bigger memory space needs to be allocated first

                // Check if the entry is closer to the beginning or the end
                if ( arrayBeginning.Size() < arrayEnding.Size() )
                {
                    // The array beginning is smaller

                    // Check if there is more free space to use before the first entry
                    if ( DoesEnoughFreeMemorySpaceExistInTheBeginning_IMP( size ) == true )
                    {
                        // There is enough memory space at the beginnig of the array

                        // Move the beginning part of the array the required amount of entries 
                        Memory::Copy::Basic< BasicType >( arrayBeginning, TAKE( m_array.Part( ( m_numberOfFreeEntriesBefore - size ), arrayBeginning.Size() ) ) );

                        // Set the new size of the array
                        m_size += size;

                        // Set the new number of entries before the beginning of the array
                        m_numberOfFreeEntriesBefore -= size;
                    }
                    // Check if there is free space after the last entry
                    else if ( DoesEnoughFreeMemorySpaceExistInTheEnd_IMP( CalculateSizeThatMakesMovingTheArrayPreferableThenAllocatingAnotherMemorySpace_IMP( size ) ) == true )
                    {
                        // There is enough memory space at the end

                        // Move the end part of the array the required amount of entries 
                        Memory::Copy::Basic< BasicType >( arrayEnding, TAKE( arrayEnding.Part( size, arrayEnding.Size() ) ) );

                        // Set the new size of the array
                        m_size += size;
                    }
                    else
                    {
                        // No more space :(

                        // A new bigger memory space must be allocated, and the 2 parts of the array must be copied to it with a gap in the size of the additional 
                        // entries required
                        AllocateBiggerMemorySpaceAndCopyTheArrayPartsWithGap_IMP( TAKE( arrayBeginning ), TAKE( arrayEnding ), size );
                    }


                }
                else
                {
                    // The array end is smaller

                    // Check if there is more free space to use after the last entry
                    if ( DoesEnoughFreeMemorySpaceExistInTheEnd_IMP( size ) == true )
                    {
                        // There is enough memory space at the end of the array

                        // Move the end part of the array the required amount of entries 
                        Memory::Copy::Basic< BasicType >( arrayEnding, TAKE( arrayEnding.Part( size, arrayEnding.Size() ) ) );

                        // Set the new size of the array
                        m_size += size;
                    }
                    // Check if there is free space before the first entry
                    if ( DoesEnoughFreeMemorySpaceExistInTheBeginning_IMP( CalculateSizeThatMakesMovingTheArrayPreferableThenAllocatingAnotherMemorySpace_IMP( size ) ) == true )
                    {
                        // There is enough memory space at the beginnig of the array

                        // Move the beginning part of the array the required amount of entries 
                        Memory::Copy::Basic< BasicType >( arrayBeginning, TAKE( m_array.Part( ( m_numberOfFreeEntriesBefore - size ), arrayBeginning.Size() ) ) );

                        // Set the new size of the array
                        m_size += size;

                        // Set the new number of entries before the beginning of the array
                        m_numberOfFreeEntriesBefore -= size;
                    }
                    else
                    {
                        // No more space, deal with it

                        // A new bigger memory space must be allocated, and the 2 parts of the array must be copied to it with a gap in the size of the additional 
                        // entries required
                        AllocateBiggerMemorySpaceAndCopyTheArrayPartsWithGap_IMP( TAKE( arrayBeginning ), TAKE( arrayEnding ), size );
                    }

                }

            }


            // Method Information :
            //
            //  Description :
            //
            //      Use to allocate bigger memory space and copy the 2 parts of the array divided by the given index with gap to the new memory space
            //
            //  Required arguments :
            //
            //      User information needed :
            // 
            //          1. arrayBeginning - this will point to the beginning part of the array
            //          2. arrayEnding - this will point to the ending part of the array
            //          3. size - the number of additional entries required
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Excpections :
            //
            //      1. The instance should not be in default state or empty
            //      2. The number of additional entries required should be larger then 0
            //      3. The pointer instance to the beginning of the array should not be in default state
            //      4. The pointer instance to the ending of the array should not be in default state
            //      5.
            //
            //  Possible errors :
            //
            //      1. There is no more memory space - class std::bad_alloc is thrown
            //      2. The object does not have assignment opeartor
            //      3. Deleting the old memory space failed
            //      4.
            //
            template< typename BasicType >
            inline void Basic< BasicType >::AllocateBiggerMemorySpaceAndCopyTheArrayPartsWithGap_IMP( const DataTypes::HeapSharedPointer< BasicType > arrayBeginning, const DataTypes::HeapSharedPointer< BasicType > arrayEnding, UnsignedInteger64bits size )
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                ASSERT( ( DefaultState() == false ), "Abilities::Array::Basic::AllocateBiggerMemorySpaceAndCopyTheArrayPartsWithGap_IMP failed - the instance is in default state" )
                ASSERT( ( m_size > 1 ), "Abilities::Array::Basic::AllocateBiggerMemorySpaceAndCopyTheArrayPartsWithGap_IMP failed - the array size is smaller then 2" )
                ASSERT( ( size > 0 ), "Abilities::Array::Basic::AllocateBiggerMemorySpaceAndCopyTheArrayPartsWithGap_IMP failed - the number of additional entries required is 0" )            
                ASSERT( ( arrayBeginning.DefaultState() == false ), "Abilities::Array::Basic::AllocateBiggerMemorySpaceAndCopyTheArrayPartsWithGap_IMP failed - the given pointer to the array beginning is in default state" )
                ASSERT( ( arrayEnding.DefaultState() == false ), "Abilities::Array::Basic::AllocateBiggerMemorySpaceAndCopyTheArrayPartsWithGap_IMP failed - the given pointer to the array ending is in default state" )

                // Create a temporary with enough memory space for the additional entries
                Basic< BasicType > temporary( m_size + size );

                // Now all the array must be copied, but it will be copied with the additional entries in the middle

                // Copy the beginning of the basic types array to the new memory space
                Memory::Copy::Basic< BasicType >( arrayBeginning, TAKE( temporary.m_array.Part( temporary.m_numberOfFreeEntriesBefore, arrayBeginning.Size() ) ) );

                // Copy the beginning of the basic types array to the new memory space
                Memory::Copy::Basic< BasicType >( arrayEnding, TAKE( temporary.m_array.Part( ( temporary.m_numberOfFreeEntriesBefore + arrayBeginning.Size() + size ), arrayEnding.Size() ) ) );

                // Swap between the heap shared pointer inside this instance and the temporary
                Swap( temporary );
            }


            // Method Information :
            //
            //  Description :
            //
            //      Use to allocate smaller memory space and copy the basic types array parts contigous without the removed entries
            //
            //  Required arguments :
            //
            //      User information needed :
            //  
            //          1. arrayBeginning - this will point to the beginning part of the array
            //          2. arrayEnding - this will point to the ending part of the array
            //          3. numberOfEntriesToRemove - the number of entries needed to be removed
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Excpections :
            //
            //      1. The instance should not be in default state, and the size at least 3
            //      2. The number of entries to remove should be larger then 0
            //      3. The pointer instance to the beginning of the array should not be in default state
            //      4. The pointer instance to the ending of the array should not be in default state
            //      5.
            //
            //  Possible errors :
            //
            //      1. There is no more memory space - class std::bad_alloc is thrown
            //      2. The object does not have assignment opeartor
            //      3. Deleting the old memory space failed
            //      4.
            //
            template< typename BasicType >
            inline void Basic< BasicType >::AllocateSmallerMemorySpaceAndCopyTheArrayPartsContigousWithoutTheRemovedEntries_IMP( const DataTypes::HeapSharedPointer< BasicType > arrayBeginning, const DataTypes::HeapSharedPointer< BasicType > arrayEnding, UnsignedInteger64bits numberOfEntriesToRemove )
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                ASSERT( ( DefaultState() == false ), "Abilities::Array::Basic::AllocateSmallerMemorySpaceAndCopyTheArrayPartsContigousWithoutTheRemovedEntries_IMP failed - the instance is in default state" )
                ASSERT( ( m_size > 2 ), "Abilities::Array::Basic::AllocateSmallerMemorySpaceAndCopyTheArrayPartsContigousWithoutTheRemovedEntries_IMP failed - the array size is smaller then 2" )
                ASSERT( ( numberOfEntriesToRemove > 0 ), "Abilities::Array::Basic::AllocateSmallerMemorySpaceAndCopyTheArrayPartsContigousWithoutTheRemovedEntries_IMP failed - the number of additional entries required is 0" )            
                ASSERT( ( arrayBeginning.DefaultState() == false ), "Abilities::Array::Basic::AllocateSmallerMemorySpaceAndCopyTheArrayPartsContigousWithoutTheRemovedEntries_IMP failed - the given pointer to the array beginning is in default state" )
                ASSERT( ( arrayEnding.DefaultState() == false ), "Abilities::Array::Basic::AllocateSmallerMemorySpaceAndCopyTheArrayPartsContigousWithoutTheRemovedEntries_IMP failed - the given pointer to the array ending is in default state" )

                // Create a copy of the other instance
                Basic< BasicType > temporary( m_size - numberOfEntriesToRemove );

                // Copy the beginning part of the basic typea array to the new location
                Memory::Copy::Basic< BasicType >( arrayBeginning, TAKE( temporary.m_array.Part( temporary.m_numberOfFreeEntriesBefore, arrayBeginning.Size() ) ) );

                // Copy the ending part of the basic typea array to the new location
                Memory::Copy::Basic< BasicType >( arrayEnding, TAKE( temporary.m_array.Part( ( temporary.m_numberOfFreeEntriesBefore + arrayBeginning.Size() ), arrayEnding.Size() ) ) );

                // Swap between the heap shared pointer inside this instance and the temporary
                Swap( temporary );
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
            //  Excpections :
            //
            //      1. The instance should not be in default state or empty
            //      2. The index should be in the range of the array current entries
            //      3. 
            //
            //  Possible errors :
            //
            //      They will come
            //
            template< typename BasicType >
            inline BasicType& Basic< BasicType >::GetData_IMP( UnsignedInteger64bits index )
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                ASSERT( ( DefaultState() == false ), "Abilities::Array::Basic::GetData_IMP failed - the instance is in default state" )
                ASSERT( ( ( index >= 0 ) && ( index < m_size ) ), "Abilities::Array::Basic::GetData_IMP failed - the given index is out of the array range" )
                
                // Return a reference to the data
                return ( m_array[ m_numberOfFreeEntriesBefore + index ] );
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
            //  Excpections :
            //
            //      1. The instance should not be in default state or empty
            //      2. The index should be in the range of the array current entries
            //      3. 
            //
            //  Possible errors :
            //
            //      They will come
            //
            template< typename BasicType >
            inline BasicType Basic< BasicType >::GetData_IMP( UnsignedInteger64bits index ) const
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                ASSERT( ( DefaultState() == false ), "Abilities::Array::Basic::GetData_IMP constant failed - the instance is in default state" )
                ASSERT( ( ( index >= 0 ) && ( index < m_size ) ), "Abilities::Array::Basic::GetData_IMP constant failed - the given index is out of the array range" )
                
                // Return a copy of the data
                return ( m_array[ m_numberOfFreeEntriesBefore + index ] );
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
            //  Excpections :
            //
            //      1. The instance should not be in default state or empty
            //      2. 
            //
            //  Possible errors :
            //
            //      They will come
            //
            template< typename BasicType >
            inline void Basic< BasicType >::ExecuteTaskBeforeObjectChanges_IMP()
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                ASSERT( ( DefaultState() == false ), "Abilities::Array::Basic::ExecuteTaskBeforeObjectChanges_IMP failed - the instance is in default state" )
                
                // Check if only this instance uses the shared resource
                RETURN_IF_THE_VALUES_ARE_EQUAL( m_array.Counter(), 1 )

                // More then 1 instance uses the shared resource, Create a new copy of the resource            

                // Create a temporary with the required memory space
                Basic< BasicType > temporary( m_size );

                // Copy the basic types array to the middle of the new memory space
                Memory::Copy::Basic< BasicType >( TAKE( m_array.Part( m_numberOfFreeEntriesBefore, m_size ) ), TAKE( temporary.m_array.Part( temporary.m_numberOfFreeEntriesBefore, temporary.m_size ) ) );

                // Swap between this instance and the temporary
                Swap( temporary );
            }




















































    // *********************************************************************************   TESTING   *******************************************************************************






















































            // DEBUG_TOOL(


                // Method Information :
                //
                //  Description :
                //
                //      This method is used to test the object
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
                //  Excpections :
                //
                //      NONE
                //
                //  Possible errors :
                //
                //      They will come
                //
                template< typename BasicType >
                void Basic< BasicType >::Test()
                {
                    // Create an instance of basic types array
                    Basic< SignedInteger32bits > testArray_1;

                    // Check that it is really in default state
                    ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1.DefaultState() == true ), "Array::Basic::Test failed - 1" );

                    // Initiate the array
                    testArray_1.Initiate( 3, 57 );

                    // Push head the array some times
                    for ( int i = 0 ; i < 200 ; ++i )
                    {
                    	testArray_1.Add( 0, testArray_1 );
                        // ErrorHandling::Display::LinearContainer< Basic< BasicType > >( testArray_1 );
                    }


                    // std::cout << "Mama" << std::endl;

                    // // Create another instance using the copy constructor
                    // Basic< SignedInteger32bits > testArray_2( testArray_1 );

                    // ErrorHandling::Display::LinearContainer< Basic< BasicType > >( testArray_1 );
                    // ErrorHandling::Display::LinearContainer< Basic< BasicType > >( testArray_2 );

                    // // Check that the 2 instnaces are the same
                    // ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1 == testArray_2 ), "Array::Basic::Test failed - 2" );

                    // // Check that the 2 instnaces are the same
                    // ErrorHandling::Assert< ErrorHandling::Exception >::False( ( testArray_1 != testArray_2 ), "Array::Basic::Test failed - 3" );

                    // // Check the copy on write 
                    // testArray_2[2] += 673;

                    // // Check that the 2 instnaces are the same
                    // ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1 != testArray_2 ), "Array::Basic::Test failed - 4" );

                    // // Check that the 2 instnaces are the same
                    // ErrorHandling::Assert< ErrorHandling::Exception >::False( ( testArray_1 == testArray_2 ), "Array::Basic::Test failed - 5" );

                    // // Try to add 2 instnaces
                    // testArray_1 += testArray_2;

                    // // The first flow is to create the basic types array from default state by pushing the head

                    // // Set the instnace to default state
                    // testArray_1.DeleteResourcesAndSetToDefaultState();

                    // // Initiate the array
                    // testArray_1.Initiate( 1, 0 );

                    // // Try to add an entry to the array
                    // testArray_1.AddBefore( 0, 56 );

                    // // Check that the parameters are correct
                    // ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1[0] == 56 ), "Array::Basic::Test failed - 6" );

                    // // Try to add a lot of entries
                    // for ( SignedInteger32bits index = 0 ; index < 50001 ; ++index )
                    // {
                    //     // Add the entry
                    //     testArray_1.AddBefore( 0, index );

                    //     // Check that the parameters are correct
                    //     ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1[0] == index ), "Array::Basic::Test failed - 7" );
                    // }

                    // std::cout << "Lol" << std::endl;

                    // // Try to remove all of the entries
                    // for ( SignedInteger32bits index = 50002 ; index > 3 ; --index )
                    // {
                    //     // Remove the entry
                    //     testArray_1.Remove( 0, 1 );

                    //     // Check that the parameters are correct
                    //     ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1[0] == ( index - 3 ) ), "Array::Basic::Test failed - 8" );
                    // }

                    // // Try to remove all of the entries
                    // for ( SignedInteger32bits index = 0 ; index < 3 ; ++index )
                    // {
                    //     // Remove the entry
                    //     testArray_1.Remove( 0, 1 );
                    // }

                    // // Check that it is really in default state
                    // ErrorHandling::Assert< ErrorHandling::Exception >::True( testArray_1.DefaultState(), "Array::Basic::Test failed - 9" );

                    // // Try to add a lot of entries
                    // for ( SignedInteger32bits index = 0 ; index < 50001 ; ++index )
                    // {
                    //     // Add the entry
                    //     testArray_1.AddAfter( ( testArray_1.Size() - 1 ), 1 );

                    //     // Check that the parameters are correct
                    //     ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1[ testArray_1.Size() - 1 ] == index ), "Array::Basic::Test failed - 10" );
                    // }

                    // // Try to remove all of the entries
                    // for ( SignedInteger32bits index = 50002 ; index > 3 ; --index )
                    // {
                    //     // Remove the entry
                    //     testArray_1.Remove( ( testArray_1.Size() - 1 ), 1 );

                    //     // Check that the parameters are correct
                    //     ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1[ testArray_1.Size() - 1 ] == ( index - 3 ) ), "Array::Basic::Test failed - 11" );
                    // }

                    // // Try to remove all of the entries
                    // for ( SignedInteger32bits index = 0 ; index < 2 ; ++index )
                    // {
                    //     // Remove the entry
                    //     testArray_1.Remove( ( testArray_1.Size() - 1 ), 1 );
                    // }

                    // // Create an instance of basic types array
                    // Basic< SignedInteger32bits > testArray_3;

                    // // Create a vector instnace
                    // std::vector< SignedInteger32bits > testVector_1;

                    // // Add some values
                    // testArray_1.AddAfter( ( testArray_1.Size() - 1 ), 1 );
                    // testArray_1.AddAfter( ( testArray_1.Size() - 1 ), 1 );
                    // testArray_1.AddAfter( ( testArray_1.Size() - 1 ), 1 );
                    // testArray_1.AddAfter( ( testArray_1.Size() - 1 ), 1 );
                    // testArray_1.AddAfter( ( testArray_1.Size() - 1 ), 1 );
                    // testArray_1.AddAfter( ( testArray_1.Size() - 1 ), 1 );
                    // testArray_1.AddAfter( ( testArray_1.Size() - 1 ), 1 );
                    // testArray_1.AddAfter( ( testArray_1.Size() - 1 ), 1 );
                    // testArray_1.AddAfter( ( testArray_1.Size() - 1 ), 1 );

                    // // Add some values to vecotr
                    // testVector_1.push_back( 56 );
                    // testVector_1.push_back( 66 );
                    // testVector_1.push_back( 76 );
                    // testVector_1.push_back( 86 );
                    // testVector_1.push_back( 96 );
                    // testVector_1.push_back( 106 );
                    // testVector_1.push_back( 116 );
                    // testVector_1.push_back( 126 );
                    // testVector_1.push_back( 136 );

                    // // Check that the sizes of the arrays are the same
                    // ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1.Size() == testVector_1.size() ), "Array::Basic::Test failed - 12" );

                    // // Loop on all the entries and check that they match in both arrays
                    // for ( SignedInteger32bits basicTypesArrayIndex = 0 ; basicTypesArrayIndex < static_cast< SignedInteger32bits >( testArray_1.Size() ) ; ++basicTypesArrayIndex )
                    // {
                    //     // Check that the sizes of the arrays are the same
                    //     ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1[ basicTypesArrayIndex ] == testVector_1[ basicTypesArrayIndex ] ), "Array::Basic::Test failed - 13" );
                    // }

                    // // Create an instance of basic types array
                    // Basic< SignedInteger32bits > testArray_4;

                    // // Create a vector instnace
                    // std::vector< SignedInteger32bits > testVector_2;

                    // // Add many entries
                    // for ( SignedInteger32bits index = 0 ; index < 1000000 ; ++index )
                    // {
                    //     // Add the values
                    //     testArray_4.AddAfter( ( testArray_1.Size() - 1 ), 1 );
                    //     testVector_2.push_back( index );
                    // }

                    // // Check that the sizes of the arrays are the same
                    // ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1.Size() == testVector_1.size() ), "Array::Basic::Test failed - 14" );

                    // // Loop on all the entries and check that they match in both arrays
                    // for ( SignedInteger32bits basicTypesArrayIndex = 0 ; basicTypesArrayIndex < static_cast< SignedInteger32bits >( testArray_1.Size() ) ; ++basicTypesArrayIndex )
                    // {
                    //     // Check that the sizes of the arrays are the same
                    //     ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1[ basicTypesArrayIndex ] == testVector_1[ basicTypesArrayIndex ] ), "Array::Basic::Test failed - 15" );
                    // }

                    // // Add many entries
                    // for ( SignedInteger32bits index = 0 ; index < 10000 ; ++index )
                    // {
                    //     // Add the values
                    //     testArray_4.AddAfter( ( testArray_1.Size() - 1 ), 1 );
                    //     testVector_2.push_back( index );
                    // }

                    // // Remove many entries
                    // for ( SignedInteger32bits index = 0 ; index < 234000 ; ++index )
                    // {
                    //     // Add the values
                    //     testArray_4.Remove( ( testArray_4.Size() - 1 ), 1 );
                    //     testVector_2.pop_back();
                    // }

                    // // Add many entries
                    // for ( SignedInteger32bits index = 0 ; index < 3000000 ; ++index )
                    // {
                    //     // Add the values
                    //     testArray_4.AddAfter( ( testArray_1.Size() - 1 ), 1 );
                    //     testVector_2.push_back( index );
                    // }

                    // // Remove many entries
                    // for ( SignedInteger32bits index = 0 ; index < 1500000 ; ++index )
                    // {
                    //     // Add the values
                    //     testArray_4.Remove( ( testArray_4.Size() - 1 ), 1 );
                    //     testVector_2.pop_back();
                    // }

                    // // Check that the sizes of the arrays are the same
                    // ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1.Size() == testVector_1.size() ), "Array::Basic::Test failed - 16" );

                    // // Loop on all the entries and check that they match in both arrays
                    // for ( SignedInteger32bits basicTypesArrayIndex = 0 ; basicTypesArrayIndex < static_cast< SignedInteger32bits >( testArray_1.Size() ) ; ++basicTypesArrayIndex )
                    // {
                    //     // Check that the sizes of the arrays are the same
                    //     ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1[ basicTypesArrayIndex ] == testVector_1[ basicTypesArrayIndex ] ), "Array::Basic::Test failed - 17" );
                    // }

                    // Yay, test passed!!!
                }

            // )  //  End of debug tool






        }  //  Namespace Array

    }  //  Namespace Abilities

}  //  Namespace Universe



#endif  // ARRAYBASIC_HPP











