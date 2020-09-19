#ifndef  BASICTYPESARRAY_HPP
#define  BASICTYPESARRAY_HPP


#include <new>  //  Class std::bad_alloc


#include "../../../../Definitions/VariableTypesDefinitions.hpp"  //  Typedef UnsignedInteger64bits, Typedef UnsignedInteger8bits
#include "../../../../BasicUtilities/C++/cpp_BasicUtilities.hpp"  //  Macro DEBUG_TOOL
#include "../../../../Memory/Copy/Copy/Copy.hpp"  //  Class Copy
#include "../../../../Memory/Set/Set/Set.hpp"  //  Class Set
#include "../../../../Memory/Compare/Compare/Compare.hpp"  //  Class Compare
#include "../../../../Memory/Swap/Swap.hpp"  //  Class Swap
#include "../../../../Abilities/Proxy/BasicTypesProxy/BasicTypesProxy.hpp"  //  Class BasicTypesProxy
#include "../../../../DataTypes/SmartPointers/HeapSharedPointer/HeapSharedPointer.hpp"  //  Class HeapSharedPointer


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../../ErrorHandling/Assert/Assert.hpp"  //  Class Assert
#include <vector>
#endif


// When a function name ends with the suffix IMP, the function is not part of the object interface ( capabilities ), it only used as aid to the function that
// it is, implementing only spsecific part



namespace Universe
{

    namespace Containers
    {


        // This is used when only declaring the object in this source file will be enough to pass compilation. The implementation is given to the compiler through the
        // cpp source file that the object is nested within
        //
        // Forward declarations :
        //
        //      NONE
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
        // placeholder that will be replaced by a user-specfied actual type. The reason for the two indexwords is historical. In the original template specification, Stroustrup 
        // reused the existing class indexword to specify a type parameter rather than introduce a new indexword that might of course break existing programs. It wasn’t that a 
        // new indexword wasn’t considered — just that it wasn’t considered necessary given its potential disruption. And up until the ISO-C++ standard, this was the only way 
        // to declare a type parameter. Reuses of existing indexwords seems to always sow confusion. What we found is that beginners were whether the use of the class constrained 
        // or limited the type arguments a user could specify to be class types rather than, say, a built-in or pointer type. So, there was some feeling that not having 
        // introduced a new indexword was a mistake. During standardization, certain constructs were discovered within a template definition that resolved to expressions 
        // although they were meant to indicate declarations. For example,
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
        // While the statement containing aObj is intended by the programmer to be interpreted as the declaration of a pointer to a nested type A within the type parameter T, 
        // the language grammar interprets it as an arithmetic expression multiplying the static member A of type T with aObj and throwing away the result. Isn’t that annoying! 
        // ( This sort of dilemna is not possible within generics – there is no way to safely verify that any T contains an A so that the runtime can safely construct an 
        // instance of the generic type ). The committee decided that a new indexword was just the ticket to get the compiler off its unfortunate obsession with expressions. 
        // The new indexword was the self-describing typename. When applied to a statement, such as,
    	//
        //  	typename T::A* a6; // declare pointer to T’s A
    	//
        // it instructs the compiler to treat the subsequent statement as a declaration. Since the indexword was on the payroll, heck, why not fix the confusion caused by the 
        // original decision to reuse the class indexword. Of course, given the extensive body of existing code and books and articles and talks and postings using the class 
        // indexword, they chose to also retain support for that use of the indexword as well. So that’s why you have both


        // The main point of a class is to manage resources ( In theory every class should maintain one and only one resource ), one of the important aspects of managing a 
        // resource is performance, the amount of time every operation take should be as minimal as possible, the basic operations should take almost the same as when working 
        // with the resource without the class covering it


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
    	//  Possible errors :
    	//
    	//
    	//
    	template< typename BasicType >
        class BasicTypesArray : public BasicTypesPlatform< BasicTypesArray< BasicType >, UnsignedInteger64bits, BasicType >
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
    	    inline BasicTypesArray();


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
            //  Possible errors :
            //
            //      1. There is no more free memory space - class std::bad_alloc is thrown
            //      2. The given size of the basic types array is 0
            //      3. 
            //
            explicit inline BasicTypesArray( UnsignedInteger64bits size, BasicType value = 0 );


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
    		inline BasicTypesArray( const BasicTypesArray< BasicType >& other );


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
    		inline BasicTypesArray< BasicType >& operator=( const BasicTypesArray< BasicType >& other );


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
    		inline BasicTypesArray( BasicTypesArray< BasicType >&& other );


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
    		inline BasicTypesArray< BasicType >& operator=( BasicTypesArray< BasicType >&& other );


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
            inline void Swap( BasicTypesArray< BasicType >& other );


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
    		virtual inline ~BasicTypesArray() = default;


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
    		virtual inline bool DefaultState() const;


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
            //      Use this method to initiate the basic types array
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
            //      NONE
            //
            //  Possible errors :
            //
            //      1. The given pointer is NULL
            //      2. 
            //
            inline void Initiate( UnsignedInteger64bits size, BasicType value = 0 );


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
            //  Possible errors :
            //
            //      1. The object does not have an assignment operator
            //      2. The object is in default state
            //      3.
            //
            void SetAll( BasicType value );


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to set a new basic types array
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. newBasicTypesArray - the address of the new basic types array
            //          2. newsize - the size of the new basci types array
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
            //      1. There is no more free memory space - class std::bad_alloc is thrown
            //      2. 
            //
            void SetNewBasicTypesArray( const BasicType* newBasicTypesArray, UnsignedInteger64bits newsize );


            // Method Information :
            //
            //  Description :
            //
            //      Use to remove the first entry from the basic types array
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
            //      1. The object is in default state
            //      2.
            //
            void PopHead();


            // Method Information :
            //
            //  Description :
            //
            //      Use to remove the last entry from the basic types array
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
            //      1. The object is in default state
            //      2.
            //
            void PopTail();


            // Method Information :
            //
            //  Description :
            //
            //      Use to enter a new entry before the current first entry
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          value - the entry will be set to this value
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
            //      1. There is no more memory space - class std::bad_alloc is thrown
            //      2. The object does not have assignment opeartor
            //      3. Deleting the old memory space failed - class std::bad_alloc is thrown
            //      4.
            //
            void PushHead( BasicType value );


            // Method Information :
            //
            //  Description :
            //
            //      Use to enter a new entry after the current last entry
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          value - the new last entry will be set to this value
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
            //      1. There is no more memory space - class std::bad_alloc is thrown
            //      2. The object does not have assignment opeartor
            //      3. Deleting the old memory space failed
            //      4.
            //
            void PushTail( BasicType value );


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
            //          entryIndex - the index of the entry required
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      An arithmetic proxy object
            //
            //  Possible errors :
            //
            //      1. The object is in default state
            //      2. The entry index is out of the basic types array range
            //      3.
            //
            inline typename Abilities::BasicTypesProxy< BasicTypesArray< BasicType > , UnsignedInteger64bits, BasicType > operator[]( UnsignedInteger64bits entryIndex );


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
            //          entryIndex - the index of the entry required
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
            //      2. The entry index is out of the array range
            //      3.
            //
            inline BasicType operator[]( UnsignedInteger64bits entryIndex ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use to get the address of the required entry
            //
            //      User information needed :
            //
            //          entryIndex - the index of the entry required
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
            //      2. The entry index is out of the basic types array range
            //      3.
            //
            inline BasicType* operator+( UnsignedInteger64bits entryIndex );


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
            //  Possible errors :
            //
            //      1. There is no more free memory space - class std::bad_alloc is thrown
            //      2. 
            //
            inline BasicTypesArray< BasicType >& operator+=( const BasicTypesArray< BasicType >& other );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to check if the this object matches the other object. Important note - if both objects
            //      are in default state, then the objects still match and true will be returned
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
            //      1. Both of the objects are in default state
            //      2. 
            //
            bool operator==( const BasicTypesArray< BasicType >& other ) const;

        
            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to check if the this object does not match the other object. Important note - if both objects
            //      are in default state, then the objects still match and false will be returned
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
            //      1. Both of the objects are in default state
            //      2. 
            //
            bool operator!=( const BasicTypesArray< BasicType >& other ) const;


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
                //  Possible errors :
                //
                //      1. A method does not work correctly
                //      2. There is no more free memory space - class std::bad_alloc is thrown
                //      3. 
                //
                static void Test();


                // Method Information :
                //
                //  Description :
                //
                //      This method is used to display the basic types array content
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
                void Display() const;

            )  //  End of debug tool


        protected:


    		// The protected part is used for inheritance. This means that only this object and the objects that will inherit from it can use the protected data
    		// members or methods

    		// This object will store the basic types array
    		DataTypes::HeapSharedPointer< BasicType > m_basicTypesArray;
            
            // This object will store the free space that can be used before the first entry of the basic types array
            UnsignedInteger64bits m_numberOfFreeEntriesBefore;


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
	        //  Possible errors :
	        //
	        //      They will come
	        //
	        inline BasicType& GetData( UnsignedInteger64bits index );


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
	        inline BasicType GetData( UnsignedInteger64bits index ) const;


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
            //  Possible errors :
            //
            //      They will come
            //
            void ExecuteTaskBeforeObjectChanges();


    	private:


            // This object will store the percentage from the given basic types array size. This will be used to allocate more entries to better manage the basic types array
            #define AdditionalMemoryPercentageFromSize 10


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
            //          2. numberOfAdditionalEntriesRequired - the number of additional entries needed
            //          3. trueForBeforeAndFalseForAfter - this boolean is needed to determine if the entries must be added before or after the entry associated with the index
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
            //      1. There is no more memory space - class std::bad_alloc is thrown
            //      2. The basic type does not have assignment opeartor
            //      3. Deleting the old memory space failed
            //      4.
            //
            void MakeSpace_IMP( const UnsignedInteger64bits& index, UnsignedInteger64bits numberOfAdditionalEntriesRequired, bool trueForBeforeAndFalseForAfter );


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
            //          numberOfAdditionalEntriesRequiredAtTheBeginning - the number of additional entries needed at the beginning
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
            //      1. There is no more memory space - class std::bad_alloc is thrown
            //      2. The object does not have assignment opeartor
            //      3. Deleting the old memory space failed
            //      4.
            //
            void MakeSpaceAtTheBeginning_IMP( UnsignedInteger64bits numberOfAdditionalEntriesRequiredAtTheBeginning );


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to copy the array to a new memory space if other instances use the resource as well. The memory space will be bigger according to the 
            //      given number of additional entries required, and the array will be copied to the middle of the memory space
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          numberOfAdditionalEntriesRequired - the number of additional entries needed
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
            //      1. There is no more memory space - class std::bad_alloc is thrown
            //      2. Deleting the old memory space failed
            //      3.
            //
            void CheckIfMoreInstancesUseTheResourceAndCopyTheArrayToTheMiddleOfLargerMemorySpaceIfNecessary_IMP( UnsignedInteger64bits numberOfAdditionalEntriesRequired );


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
            //          numberOfAdditionalEntriesRequired - the number of additional entries required
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
            //      1. There is no more free memory space - class std::bad_alloc is thrown
            //      2. Deleting the old memory space failed
            //      3. 
            //
            inline void AllocateBiggerMemorySpaceAndCopyTheArrayToTheMiddle_IMP( UnsignedInteger64bits numberOfAdditionalEntriesRequired );


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
            //  Possible errors :
            //
            //      They will come
            //
            inline bool DoesEnoughFreeMemorySpaceExistInTheBeginning_IMP( UnsignedInteger64bits size ) const;


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
            //  Possible errors :
            //
            //      They will come
            //
            inline bool DoesEnoughFreeMemorySpaceExistInTheEnd_IMP( UnsignedInteger64bits size ) const;


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
            //          numberOfAdditionalEntriesRequired - the number of additional entries required
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      A number of entries that if can fit, makes moving the basic types array currently preferable, then allocating new memory space
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline UnsignedInteger64bits CalculateSizeThatMakesMovingTheArrayPreferableThenAllocatingAnotherMemorySpace_IMP( UnsignedInteger64bits numberOfAdditionalEntriesRequired ) const;


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
            //          numberOfAdditionalEntriesRequiredAtTheEnd - the number of additional entries needed at the end
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
            //      1. There is no more memory space - class std::bad_alloc is thrown
            //      2. The object does not have assignment opeartor
            //      3. Deleting the old memory space failed
            //      4.
            //
            void MakeSpaceAtTheEnd_IMP( UnsignedInteger64bits numberOfAdditionalEntriesRequiredAtTheEnd );


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
            //          2. numberOfAdditionalEntriesRequiredAtTheMiddle - the number of additional entries needed at the middle
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
            //      1. There is no more memory space - class std::bad_alloc is thrown
            //      2. The object does not have assignment opeartor
            //      3. Deleting the old memory space failed
            //      4.
            //
            void MakeSpaceAtTheMiddle_IMP( const UnsignedInteger64bits& index, UnsignedInteger64bits numberOfAdditionalEntriesRequiredAtTheMiddle );


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
            //          1. arrayBeginning - a pointer object to the beginning part of the array
            //          2. arrayEnding - a pointer object to the ending part of the array
            //          3. index - this will used to determine the required entry
            //          4. numberOfAdditionalEntriesRequiredAtTheMiddle - the number of additional entries required at the middle
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
            //      1. There is no more free memory space - class std::bad_alloc is thrown
            //      2. Deleting the old memory space failed
            //      3. 
            //
            inline void AllocateBiggerMemorySpaceAndCopyTheArrayPartsWithGap_IMP( const DataTypes::Pointer< BasicType >& arrayBeginning, const DataTypes::Pointer< BasicType >& arrayEnding, const UnsignedInteger64bits& index, UnsignedInteger64bits numberOfAdditionalEntriesRequiredAtTheMiddle );


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to move the beginning part of the part determind by the index, the required entries        
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. arrayEnding - this will point to the ending part of the array
            //          2. index - this will used to determine the required entry
            //          3. numberOfAdditionalEntriesRequiredAtTheBeginning - the number of additional entries needed at the beginning
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
            //      1. There is no more memory space - class std::bad_alloc is thrown
            //      2. The object does not have assignment opeartor
            //      3. Deleting the old memory space failed
            //      4.
            //
            void MoveTheEndOfTheArrayTheRequiredAmountEntries_IMP( DataTypes::Pointer< BasicType >& arrayEnding, const UnsignedInteger64bits& index, UnsignedInteger64bits numberOfAdditionalEntriesRequiredAtTheMiddle );


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to move the beginning part of the part determind by the index, the required entries        
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. arrayBeginning - this will point to the beginning part of the array
            //          2. index - this will used to determine the required entry
            //          3. numberOfAdditionalEntriesRequiredAtTheBeginning - the number of additional entries needed at the beginning
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
            //      1. There is no more memory space - class std::bad_alloc is thrown
            //      2. The object does not have assignment opeartor
            //      3. Deleting the old memory space failed
            //      4.
            //
            void MoveTheBeginningOfTheArrayTheRequiredAmountEntries_IMP( DataTypes::Pointer< BasicType >& arrayBeginning, const UnsignedInteger64bits& index, UnsignedInteger64bits numberOfAdditionalEntriesRequiredAtTheMiddle );


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
            //      1. Deleting the old memory space failed
            //      2. 
            //
            inline void AllocateSmallerMemorySpaceAndCopyTheArrayPartsContigousWithoutTheRemovedEntries_IMP( const DataTypes::Pointer< BasicType >& arrayBeginning, const DataTypes::Pointer< BasicType >& arrayEnding, const UnsignedInteger64bits& index, UnsignedInteger64bits numberOfEntriesToRemove );
        

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
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	template< typename BasicType >
    	inline BasicTypesArray< BasicType >::BasicTypesArray() :
        BasicTypesPlatform< BasicType, UnsignedInteger64bits >(),
        m_basicTypesArray(),
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
        //  Possible errors :
        //
        //      1. There is no more free memory space
        //      2. The given size of the basic types array is 0
        //      3. 
        //
        template< typename BasicType >
        inline BasicTypesArray< BasicType >::BasicTypesArray( UnsignedInteger64bits size, BasicType value ) :
        BasicTypesPlatform< BasicType, UnsignedInteger64bits >( size ),
        m_basicTypesArray(),
        m_numberOfFreeEntriesBefore()
        {

            // Check if the given size is larger then 32
            if ( size > 32 )
            {
                // The size is larger then 32

                // Use the size to create the capacity
                m_basicTypesArray.Initiate( new BasicType[ size + MoreEntriesRequired_IMP( size ) ], ( size + MoreEntriesRequired_IMP( size ) ) );

                // Set the number of free entries before the beginning of the array
                m_numberOfFreeEntriesBefore = ( MoreEntriesRequired_IMP( size ) / 2 );
            }
            else
            {
                // The size is smaller then 32, to prevent many allocations and copies the capacity will be determined using 32

                // Use 32 to create the capacity
                m_basicTypesArray.Initiate( new BasicType[ 32 ], 32 );

                // Set the number of free entries before the beginning of the array
                m_numberOfFreeEntriesBefore = ( ( 32 - size ) / 2 );
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
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	template< typename BasicType >
    	inline BasicTypesArray< BasicType >::BasicTypesArray( const BasicTypesArray< BasicType >& other ) :
        BasicTypesPlatform< BasicType, UnsignedInteger64bits >( other ),
        m_basicTypesArray( other.m_basicTypesArray ),
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
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	template< typename BasicType >
    	inline BasicTypesArray< BasicType >& BasicTypesArray< BasicType >::operator=( const BasicTypesArray< BasicType >& other )
    	{
    		// Create a copy of the other instance
    		BasicTypesArray< BasicType > temporary( other );

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
    	inline BasicTypesArray< BasicType >::BasicTypesArray( BasicTypesArray< BasicType >&& other ) :
    	BasicTypesArray< BasicType >()
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
    	inline BasicTypesArray< BasicType >& BasicTypesArray< BasicType >::operator=( BasicTypesArray< BasicType >&& other )
    	{
    	    // Create a default constructed instance
    	    BasicTypesArray< BasicType > defaultConstructedInstance;

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
        //  Possible errors :
        //
        //      They will come
        //
        template< typename BasicType >
        inline void BasicTypesArray< BasicType >::Swap( BasicTypesArray< BasicType >& other )
    	{
            // Call the platform base class swap method
            BasicTypesPlatform< BasicType, UnsignedInteger64bits >::Swap( other );

            // Swap the share pointers
            m_basicTypesArray.Swap( other.m_basicTypesArray );

            // Swap the number of free entries before
            Memory::Swap< UnsignedInteger64bits >( m_numberOfFreeEntriesBefore, other.m_numberOfFreeEntriesBefore );
    	}


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to take an instance in default state and prepare it for work. It can also be uses to reinitialize the instance
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
        //      NONE
        //
        //  Possible errors :
        //
        //      1. The object 
        //      2. 
        //
        template< typename BasicType >
        inline void BasicTypesArray< BasicType >::Initiate( UnsignedInteger64bits size, BasicType value )
        {
            // Create a temporary instance
            BasicTypesArray< BasicType > temporary( size, value );

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
    	//  Possible errors :
    	//
    	//	    They will come
    	//
    	template< typename BasicType >
    	inline void BasicTypesArray< BasicType >::SetToDefaultState()
    	{
            // Set the platform base class to default state
            BasicTypesPlatform< BasicType, UnsignedInteger64bits >::SetToDefaultState();

    		// Set the pointer instance to default state
    		m_basicTypesArray.SetToDefaultState();

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
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	template< typename BasicType >
    	inline bool BasicTypesArray< BasicType >::DefaultState() const
    	{

    		// Check if the object is not in default state
    		if ( ( BasicTypesPlatform< BasicType, UnsignedInteger64bits >::DefaultState() == true ) &&
                 ( m_basicTypesArray.DefaultState() == true ) &&
    		     ( m_numberOfFreeEntriesBefore == 0 ) )
    		{
    			// The object is in default state
    			return ( true );
    		}

    		// The object is not in default state
    		return ( false );
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
    	inline void BasicTypesArray< BasicType >::DeleteResourcesAndSetToDefaultState()
    	{
            // Check if the object is in default state, then noting needs to be done
            RETURN_IF_EXPRESSION_IS_TRUE( DefaultState() )

            // Set the platform base class to default state
            BasicTypesPlatform< BasicType, UnsignedInteger64bits >::SetToDefaultState();

            // Release the resources of this object
            m_basicTypesArray.DeleteResourcesAndSetToDefaultState();

            // Set the number of free entries before the beginning of the basic types array
            m_numberOfFreeEntriesBefore = 0;
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
        //  Possible errors :
        //
        //      1. The object does not have an assignment operator
        //      2. The object is in default state
        //      3.
        //
        template< typename BasicType >
        inline void BasicTypesArray< BasicType >::SetAll( BasicType value )
        {
            // A write operation is about to take place, check if only this instance uses the resource, if not, copy it to a new one that only this instance uses
            ExecuteTaskBeforeObjectChanges();

            // Set the all the entries to the required value
            Memory::Set< BasicType >( m_basicTypesArray.Part( m_numberOfFreeEntriesBefore, m_size ), value );
        }
















































//  *********************************************************  TEMPLATE OR INLINE PURE VIRTUAL METHODS IMPLEMENTATION   ***************************************************************


















































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
        //  Possible errors :
        //
        //      1. The object is in default state
        //      2. The index does not exist in the platform
        //      3.
        //
        template< typename BasicType >
        inline typename Abilities::BasicTypesProxy< BasicTypesArray< BasicType >, UnsignedInteger64bits, BasicType > BasicTypesArray< BasicType >::operator[]( UnsignedInteger64bits entryIndex )
        {
            // Create an instance of the proxy with the required information and return a copy of it
            return ( typename Abilities::BasicTypesProxy< BasicTypesArray< BasicType > , UnsignedInteger64bits, BasicType >( *this, ( m_numberOfFreeEntriesBefore + entryIndex ) ) );
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
        //  Possible errors :
        //
        //      1. The object is in default state
        //      2. The index does not exist in the platform
        //      3.
        //
        template< typename BasicType >
        inline BasicType BasicTypesArray< BasicType >::operator[]( UnsignedInteger64bits entryIndex ) const
        {
            // Create the proxy class and return it
            return ( m_basicTypesArray[ m_numberOfFreeEntriesBefore + entryIndex ] );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to find the index of the required basic type value
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          value - the value that needs to be located
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      1. A copy of the index associated with value, if the value exist
        //      2. If the value does not exist, the return value will be casted to a signed integer and the value -1 will be set
        //
        //  Possible errors :
        //
        //      1. The instance is in default state
        //      2. 
        //
        template< typename BasicType >
        inline UnsignedInteger64bits BasicTypesArray< BasicType >::Findindex( BasicType value ) const
        {

            // Move on the array until the required index is found or the array was exhausted
            for ( UnsignedInteger64bits index = 0 ; index < m_size ; ++index )
            {

                // Check if the current entry has the required data
                if ( m_basicTypesArray[ m_numberOfFreeEntriesBefore + index ] == value )
                {
                    // The required location of the data was found

                    // Return the current index
                    return ( index );
                }

            }

            // If control reached here the given data does not exist in the array

            // Set the return value to -1
            return ( reinterpret_cast< SignedInteger64bits >( -1 ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to add an other instance before the entry associated with the index
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. index - this will used to determine the required entry
        //          2. other - a reference to an other instance to be added before the given entry
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
        //      1. The given pointer is NULL
        //      2. 
        //
        template< typename BasicType >
        inline void BasicTypesArray< BasicType >::AddBefore( const UnsignedInteger64bits& index, const BasicTypesArray< BasicType >& other )
        {
            // Make space for the additional entries
            MakeSpace_IMP( index, other.Size(), true );

            // Copy the other instance to the gap starting from the entry the index is point to. The value that was in that location was moved to the first location of the
            // ending part
            Memory::Copy< BasicType >( DataTypes::Pointer< BasicType >( ( other.m_basicTypesArray + other.m_numberOfFreeEntriesBefore ), other.m_size ), DataTypes::Pointer< BasicType >( ( m_basicTypesArray + ( m_numberOfFreeEntriesBefore + index ) ), other.m_size ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to add a value before the entry associated with the index
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. index - this will used to determine the required entry
        //          2. value - the value that needs to be added before
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
        //      1. The given pointer is NULL
        //      2. 
        //
        template< typename BasicType >
        inline void BasicTypesArray< BasicType >::AddBefore( const UnsignedInteger64bits& index, BasicType value )
        {
            // Make space for the additional entries
            MakeSpace_IMP( index, 1, false );

            // Set the entry the index is point to. The value that was in that location was moved one entry up in the indexes
            m_basicTypesArray[ m_numberOfFreeEntriesBefore + index ] = value;
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to add an other instance after the entry associated with the key
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. index - this will used to determine the required entry
        //          2. other - a reference to an other instance to be added before the given entry
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
        //      1. The given pointer is NULL
        //      2. 
        //
        template< typename BasicType >
        inline void BasicTypesArray< BasicType >::AddAfter( const UnsignedInteger64bits& index, const BasicTypesArray< BasicType >& other )
        {
            // Make space for the additional entries
            MakeSpace_IMP( index, other.Size(), true );

            // Copy the other instance to the gap starting from the entry the index added 1 is point to
            Memory::Copy< BasicType >( DataTypes::Pointer< BasicType >( ( other.m_basicTypesArray + m_numberOfFreeEntriesBefore ), other.m_size ), DataTypes::Pointer< BasicType >( ( m_basicTypesArray + ( m_numberOfFreeEntriesBefore + ( index + 1 ) ) ), other.m_size ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to add a value before the entry associated with the key
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. index - this will used to determine the required entry
        //          2. value - the value that needs to be added before
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
        //      1. The given pointer is NULL
        //      2. 
        //
        template< typename BasicType >
        inline void BasicTypesArray< BasicType >::AddAfter( const UnsignedInteger64bits& index, BasicType value )
        {
            // Make space for the additional entries
            MakeSpace_IMP( index, 1, false );

            // Set the entry the index added 1 is point to
            m_basicTypesArray[ m_numberOfFreeEntriesBefore + ( index + 1 ) ] = value;
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
        //  Possible errors :
        //
        //      1. The given pointer is NULL
        //      2. 
        //
        inline void Remove( const UnsignedInteger64bits& index, UnsignedInteger64bits size )
        {
            // The method will locate the smaller part of the 2, the beginning or ending part without the removed entries. The point is to find which one is smaller, 
            // and then if the beginning part is smaller copy it up the indexes to the ending part, and vice versa

            // This pointer will point to the beginning part of the array that needs to stay
            DataTypes::Pointer< BasicType > arrayBeginning( ( m_basicTypesArray + m_numberOfFreeEntriesBefore ), index );

            // This pointer will point to the end part of the array that needs to stay
            DataTypes::Pointer< BasicType > arrayEnding( ( m_basicTypesArray + ( m_numberOfFreeEntriesBefore + size ) ), ( m_size - index - size ) );

            // Check if other instances use the resource as well, or the size of the array will be less then half of the capacity after removing the nentries
            if ( ( m_basicTypesArray.GetNumberOfReferences() > 1 ) || ( m_size < ( m_basicTypesArray.Size() / 2 ) ) )
            {
                // Not only this instance uses the resource

                // Allocate larger memory space and copy the array parts to it with a gap in the size of the additional required entries
                AllocateSmallerMemorySpaceAndCopyTheArrayPartsContigousWithoutTheRemovedEntries_IMP( arrayBeginning, arrayEnding, index, size );

                // Nothing else needs to be done
                return;
            }

            // Check which of the 2 parts is smaller
            if ( index < ( m_size - index - size ) )
            {
                // The beginning part is smaller then the ending part

                // Copy the beginning part before the ending part of the array
                Memory::Copy< BasicType >( arrayBeginning, DataTypes::Pointer< BasicType >( ( m_basicTypesArray + ( m_numberOfFreeEntriesBefore + size ) ), index ) );                    

                // Set the number of free entries before the beginning of the array
                m_numberOfFreeEntriesBefore += size;
            }
            else
            {
                // The ending part is smaller or equal to the beginning part

                // Copy the beginning part before the ending part of the array
                Memory::Copy< BasicType >( arrayEnding, DataTypes::Pointer< BasicType >( ( m_basicTypesArray + ( m_numberOfFreeEntriesBefore + index ) ), ( m_size - index - size ) ) );                    
            }

            // Set the new size
            m_size -= size;
        }




































//  ***************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************












































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
        //          entryIndex - the index of the entry required
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
        //      2. The entry index is out of the basic types array range
        //      3.
        //
        template< typename BasicType >
        inline BasicType* BasicTypesArray< BasicType >::operator+( UnsignedInteger64bits entryIndex )
        {
            // Create the proxy class and return it
            return ( m_basicTypesArray + entryIndex );
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
        //  Possible errors :
        //
        //      1. There is no more free memory space - class std::bad_alloc is thrown
        //      2. 
        //
        template< typename BasicType >
        inline BasicTypesArray< BasicType >& BasicTypesArray< BasicType >::operator+=( const BasicTypesArray< BasicType >& other ) 
        {
            // Add the other instance to the end of this instance
            AddAfter( ( m_size - 1 ), other );

            // Return a reference to this instance
            return ( *this );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the this object matches the other object. Important note - if both objects
        //      are in default state, then the objects still match and true will be returned
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
        //      1. Both of the objects are in default state
        //      2. 
        //
        template< typename BasicType >
        bool BasicTypesArray< BasicType >::operator==( const BasicTypesArray< BasicType >& other ) const
        {

            // Check that the size, capacity and number of free entries before the first entry match in both objects
            if ( m_size != other.m_size )
            {
                // The 2 instances mismatch
                return ( false );
            }

            // This object will store the result of the comparison
            bool comparisonResult = false;

			// Compare the 2 memory segments
			Memory::Compare< BasicType >( DataTypes::Pointer< BasicType >( ( m_basicTypesArray + m_numberOfFreeEntriesBefore ), m_size ), DataTypes::Pointer< BasicType >( ( other.m_basicTypesArray + other.m_numberOfFreeEntriesBefore ), other.m_size ), comparisonResult );

            // Return the result of the comparison
            return ( comparisonResult );
        }

    
        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the this object does not match the other object. Important note - if both objects
        //      are in default state, then the objects still match and false will be returned
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
        //      1. Both of the objects are in default state
        //      2. 
        //
        template< typename BasicType >
        bool BasicTypesArray< BasicType >::operator!=( const BasicTypesArray< BasicType >& other ) const
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
        //  Possible errors :
        //
        //      They will come
        //
        template< typename BasicType >
        inline UnsignedInteger64bits BasicTypesArray< BasicType >::MoreEntriesRequired_IMP( UnsignedInteger64bits size ) const
        {
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
        //          2. numberOfAdditionalEntriesRequired - the number of additional entries needed
        //          3. trueForBeforeAndFalseForAfter - this boolean is needed to determine if the entries must be added before or after the entry associated with the index
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
        //      1. There is no more memory space - class std::bad_alloc is thrown
        //      2. The basic type does not have assignment opeartor
        //      3. Deleting the old memory space failed
        //      4.
        //
        template< typename BasicType >
        void BasicTypesArray< BasicType >::MakeSpace_IMP( const UnsignedInteger64bits& index, UnsignedInteger64bits numberOfAdditionalEntriesRequired, bool trueForBeforeAndFalseForAfter )
        {
            // Check the value of the index and determine the required operation

            // Check if the index is index 0, and the entries should be added before it
            if ( ( index == 0 ) && ( trueForBeforeAndFalseForAfter == true ) )
            {
                // The required entries should be added before the beginning of the array
                MakeSpaceAtTheBeginning_IMP( numberOfAdditionalEntriesRequired );
            }
            // Check if the index is the last one in the array, and the entries should be added after it
            else if ( ( index == ( m_size - 1 ) ) && ( trueForBeforeAndFalseForAfter == false ) )
            {
                // The required entries should be added after the end of the array
                MakeSpaceAtTheEnd_IMP( numberOfAdditionalEntriesRequired );
            }
            else
            {
                // The required entries should be added at the middle, then make room
                MakeSpaceAtTheMiddle_IMP( index, numberOfAdditionalEntriesRequired );

                // The method make space at the middle acts as if the entries need to be added after the entry associated with the index. Then if it should be added before,
                // the last entry of the beginning part of the array should be moved to be the first entry of the last part

                // Check if the required entries should be added before
                if ( trueForBeforeAndFalseForAfter == true )
                {
                    // The entries should be added before

                    // The last entry of the beginning part needs to be copied to be the first of the ending part
                    m_basicTypesArray[ m_numberOfFreeEntriesBefore + index + numberOfAdditionalEntriesRequired ] = m_basicTypesArray[ m_numberOfFreeEntriesBefore + index ];
                }

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
        //          numberOfAdditionalEntriesRequiredAtTheBeginning - the number of additional entries needed at the beginning
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
        //      1. There is no more memory space - class std::bad_alloc is thrown
        //      2. The object does not have assignment opeartor
        //      3. Deleting the old memory space failed
        //      4.
        //
        template< typename BasicType >
        void BasicTypesArray< BasicType >::MakeSpaceAtTheBeginning_IMP( UnsignedInteger64bits numberOfAdditionalEntriesRequiredAtTheBeginning )
        {
        	// Copy the array to the middle of a bigger memory space if more instances use the resource, to ensure that the data will not change for other instances
        	CheckIfMoreInstancesUseTheResourceAndCopyTheArrayToTheMiddleOfLargerMemorySpaceIfNecessary_IMP( numberOfAdditionalEntriesRequiredAtTheBeginning );

            // Check if the current instance has enough free space to contain another entry. If it does then all good, if it doesn't it chooses between 2 options. The first 
            // is of course to allocate bigger memory space and copy the basic types array over there, the other is to just move the basic types array to the middle of the 
            // current memory space, with no need to allocate another

            // Check if there is more free space to use before the first entry
            if ( DoesEnoughFreeMemorySpaceExistInTheBeginning_IMP( numberOfAdditionalEntriesRequiredAtTheBeginning ) == false )
            {
                // There is not enough memory space at the beginning of the array

                // Check if there is free space after the last entry
                if ( DoesEnoughFreeMemorySpaceExistInTheEnd_IMP( CalculateSizeThatMakesMovingTheArrayPreferableThenAllocatingAnotherMemorySpace_IMP( numberOfAdditionalEntriesRequiredAtTheBeginning ) ) == true )
                {
                    // There is enough memory space at the end of the array, move the array to the middle of the memory space
                    
                    // Create an object to store the amount of entries to move, in order to put the array at the middle of memory space
                    UnsignedInteger64bits numberOfEntriesToMove = ( DetermineTheSizeOfTheFreeMemorySpaceAtTheEnd_IMP() / 2 );

                    // Move the array to the middle of the current memory space
					Memory::Copy< BasicType >( DataTypes::Pointer< BasicType >( ( m_basicTypesArray + m_numberOfFreeEntriesBefore ), m_size ), DataTypes::Pointer< BasicType >( ( m_basicTypesArray + ( m_numberOfFreeEntriesBefore + numberOfEntriesToMove ) ), m_size ) );

                    // Set the new size of the array
                    m_size += numberOfAdditionalEntriesRequiredAtTheBeginning;

                    // Subtract the number of entries moved from the number of free entries before the beginning of the array
                    m_numberOfFreeEntriesBefore += numberOfEntriesToMove;
                }
                else
                {
                    // The free space has ended, a new bigger space must be fetched
                    AllocateBiggerMemorySpaceAndCopyTheArrayToTheMiddle_IMP( numberOfAdditionalEntriesRequiredAtTheBeginning );
                }

            }

        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to copy the array to a new memory space if other instances use the resource as well. The memory space will be bigger according to the 
        //      given number of additional entries required, and the array will be copied to the middle of the memory space
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          numberOfAdditionalEntriesRequired - the number of additional entries needed
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
        //      1. There is no more memory space - class std::bad_alloc is thrown
        //      2. Deleting the old memory space failed
        //      3.
        //
        template< typename BasicType >
        void BasicTypesArray< BasicType >::CheckIfMoreInstancesUseTheResourceAndCopyTheArrayToTheMiddleOfLargerMemorySpaceIfNecessary_IMP( UnsignedInteger64bits numberOfAdditionalEntriesRequired )
        {

            // Check if other instances use the resource as well
            if ( m_basicTypesArray.GetNumberOfReferences() > 1 )
            {
                // Not only this instance uses the resource

                // Allocate larger memory space and copy the content to it
                AllocateBiggerMemorySpaceAndCopyTheArrayToTheMiddle_IMP( numberOfAdditionalEntriesRequired );
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
        //          numberOfAdditionalEntriesRequired - the number of additional entries required
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
        //      1. There is no more free memory space - class std::bad_alloc is thrown
        //      2. Deleting the old memory space failed
        //      3. 
        //
        template< typename BasicType >
        inline void BasicTypesArray< BasicType >::AllocateBiggerMemorySpaceAndCopyTheArrayToTheMiddle_IMP( UnsignedInteger64bits numberOfAdditionalEntriesRequired )
        {
            // Create a copy of the other instance
            BasicTypesArray< BasicType > temporary( m_size + numberOfAdditionalEntriesRequired );

            // Copy the basic types array to the middle of the new memory space
            Memory::Copy< BasicType >( DataTypes::Pointer< BasicType >( ( m_basicTypesArray + m_numberOfFreeEntriesBefore ), m_size ), DataTypes::Pointer< BasicType >( ( temporary.m_basicTypesArray + temporary.m_numberOfFreeEntriesBefore ), m_size ) );

            // Swap between the heap shared pointer inside this instance and the temporary
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
        //  Possible errors :
        //
        //      They will come
        //
        template< typename BasicType >
        inline bool BasicTypesArray< BasicType >::DoesEnoughFreeMemorySpaceExistInTheBeginning_IMP( UnsignedInteger64bits size ) const
        {
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
        //  Possible errors :
        //
        //      They will come
        //
        template< typename BasicType >
        inline bool BasicTypesArray< BasicType >::DoesEnoughFreeMemorySpaceExistInTheEnd_IMP( UnsignedInteger64bits size ) const
        {
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
        //  Possible errors :
        //
        //      They will come
        //
        template< typename BasicType >
        inline UnsignedInteger64bits BasicTypesArray< BasicType >::DetermineTheSizeOfTheFreeMemorySpaceAtTheEnd_IMP() const
        {
            // Return the number of free entries after the end of the basic types array
            return ( m_basicTypesArray.Size() - ( m_numberOfFreeEntriesBefore + m_size ) );
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
        //          numberOfAdditionalEntriesRequired - the number of additional entries required
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A number of entries that if can fit, makes moving the basic types array currently preferable, then allocating new memory space
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename BasicType >
        inline UnsignedInteger64bits BasicTypesArray< BasicType >::CalculateSizeThatMakesMovingTheArrayPreferableThenAllocatingAnotherMemorySpace_IMP( UnsignedInteger64bits numberOfAdditionalEntriesRequired ) const
        {
            // The minimum number of free entries for making the array use the same memory is 2 percentage from the basic types array size. The only left question is 
            // whether the number of additional entries required is smaller or larger then the current 2 percentage of the basic types array. Therefore the larger will 
            // be returned

            // Create an object to store 2 percentage from the current size, an additional 2 is added becasue this is the minimum value for which a move operation can happen
            UnsignedInteger64bits sizeOfFreeSpaceInCurrentMemorySpaceThatMakesNoNeedToGetAnother = ( ( ( m_size * 2 ) / 100 ) + 2 );

            // Check what is larger, the additional amount of entries or the 2 percentage from the size
            if ( numberOfAdditionalEntriesRequired > sizeOfFreeSpaceInCurrentMemorySpaceThatMakesNoNeedToGetAnother )
            {
                // The additional amount of entries required is larger then 2 percentage of the array size, then return the additional amount
                return ( numberOfAdditionalEntriesRequired );
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
        //          numberOfAdditionalEntriesRequiredAtTheEnd - the number of additional entries needed at the end
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
        //      1. There is no more memory space - class std::bad_alloc is thrown
        //      2. The object does not have assignment opeartor
        //      3. Deleting the old memory space failed
        //      4.
        //
        template< typename BasicType >
        void BasicTypesArray< BasicType >::MakeSpaceAtTheEnd_IMP( UnsignedInteger64bits numberOfAdditionalEntriesRequiredAtTheEnd )
        {
        	// Copy the array to the middle of a bigger memory space if more instances use the resource, to ensure that the data will not change for other instances
        	CheckIfMoreInstancesUseTheResourceAndCopyTheArrayToTheMiddleOfLargerMemorySpaceIfNecessary_IMP( numberOfAdditionalEntriesRequiredAtTheEnd );

            // Check if the current instance has enough free space to contain another entry. If it does then all good, if it doesn't it chooses between 2 options. The first 
            // is of course to allocate bigger memory space and copy the basic types array over there, the other is to just move the basic types array to the middle of the 
            // current memory space, with no need to allocate another

            // Check if there is more free space to use after last entry
            if ( DoesEnoughFreeMemorySpaceExistInTheEnd_IMP( numberOfAdditionalEntriesRequiredAtTheEnd ) == false )
            {
                // There is not enough memory space at the end of the array

                // Check if there is free space before the first entry
                if ( DoesEnoughFreeMemorySpaceExistInTheBeginning_IMP( CalculateSizeThatMakesMovingTheArrayPreferableThenAllocatingAnotherMemorySpace_IMP( numberOfAdditionalEntriesRequiredAtTheEnd ) ) == true )
                {
                    // There is enough memory space at the beginning of the array, move the array to the middle of the memory space

                    // Move the array to the middle of the current memory space 
					Memory::Copy< BasicType >( DataTypes::Pointer< BasicType >( ( m_basicTypesArray + m_numberOfFreeEntriesBefore ), m_size ), DataTypes::Pointer< BasicType > destination( ( m_basicTypesArray + ( m_numberOfFreeEntriesBefore / 2 ) ), m_size ) );

                    // Set the new size of the array
                    m_size += numberOfAdditionalEntriesRequiredAtTheEnd;                    

                    // Subtract the number of entries moved from the number of free entries before the beginning of the array
                    m_numberOfFreeEntriesBefore /= 2;
                }
                else
                {
                    // The free space has ended, a new bigger space must be fetched
                    AllocateBiggerMemorySpaceAndCopyTheArrayToTheMiddle_IMP( numberOfAdditionalEntriesRequiredAtTheEnd );
                }

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
        //          1. index - this will used to determine the required entry
        //          2. numberOfAdditionalEntriesRequiredAtTheMiddle - the number of additional entries needed at the middle
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
        //      1. There is no more memory space - class std::bad_alloc is thrown
        //      2. The object does not have assignment opeartor
        //      3. Deleting the old memory space failed
        //      4.
        //
        template< typename BasicType >
        void BasicTypesArray< BasicType >::MakeSpaceAtTheMiddle_IMP( const UnsignedInteger64bits& index, UnsignedInteger64bits numberOfAdditionalEntriesRequiredAtTheMiddle )
        {
            // This pointer will point to the beginning part of the array
            DataTypes::Pointer< BasicType > arrayBeginning( ( m_basicTypesArray + m_numberOfFreeEntriesBefore ), ( index + 1 ) );

            // This pointer will point to the end part of the array
            DataTypes::Pointer< BasicType > arrayEnding( ( m_basicTypesArray + ( m_numberOfFreeEntriesBefore + ( index + 2 ) ) ), ( m_size - ( index + 1 ) ) );

            // Check if other instances use the resource as well
            if ( m_basicTypesArray.GetNumberOfReferences() > 1 )
            {
                // Not only this instance uses the resource

                // Allocate larger memory space and copy the array parts to it with a gap in the size of the additional required entries
                AllocateBiggerMemorySpaceAndCopyTheArrayPartsWithGap_IMP( arrayBeginning, arrayEnding, index, numberOfAdditionalEntriesRequiredAtTheMiddle );

                // Nothing else needs to be done
                return;
            }

            // Check if the current instance has enough free space to contain all the additional entries. The rational is that the index will be used to check if the 
            // required entry is closer to the beginning or the end of the array, this will allow to copy the smaller part of the array. The last thing to deal with 
            // is cases where bigger memory space needs to be allocated first

            // Check if the entry is closer to the beginning or the end
            if ( index < ( m_size / 2 ) )
            {
                // The entry is closer to the beginning

                // Check if there is more free space to use before the first entry
                if ( DoesEnoughFreeMemorySpaceExistInTheBeginning_IMP( numberOfAdditionalEntriesRequiredAtTheMiddle ) == false )
                {
                    // There is not enough memory space at the beginning of the array

                    // Check if there is free space after the last entry
                    if ( DoesEnoughFreeMemorySpaceExistInTheEnd_IMP( CalculateSizeThatMakesMovingTheArrayPreferableThenAllocatingAnotherMemorySpace_IMP( numberOfAdditionalEntriesRequiredAtTheMiddle ) ) == true )
                    {
                        // There is enough memory space at the end of the array, move the end part of the array the required amount of entries
                        MoveTheEndOfTheArrayTheRequiredAmountEntries_IMP( arrayBeginning, index, numberOfAdditionalEntriesRequiredAtTheMiddle );
                    }
                    else
                    {
                        // A new bigger memory space must be allocated, and the 2 parts of the array must be copied to it with a gap in the size of the additional 
                        // entries required
                        AllocateBiggerMemorySpaceAndCopyTheArrayPartsWithGap_IMP( arrayBeginning, arrayEnding, index, numberOfAdditionalEntriesRequiredAtTheMiddle );
                    }

                }
                else
                {
                    // There is enough memory space at the beginnig of the array, move the beginnig part of the array the required amount of entries
                    MoveTheBeginningOfTheArrayTheRequiredAmountEntries_IMP( arrayBeginning, index, numberOfAdditionalEntriesRequiredAtTheMiddle );
                }

            }
            else
            {
                // The entry is closer to the end

                // Check if there is more free space to use after the last entry
                if ( DoesEnoughFreeMemorySpaceExistInTheEnd_IMP( numberOfAdditionalEntriesRequiredAtTheMiddle ) == false )
                {
                    // There is not enough memory space after the end of the array

                    // Check if there is free space before the first entry
                    if ( DoesEnoughFreeMemorySpaceExistInTheBeginning_IMP( CalculateSizeThatMakesMovingTheArrayPreferableThenAllocatingAnotherMemorySpace_IMP( numberOfAdditionalEntriesRequiredAtTheMiddle ) ) == true )
                    {
                        // There is enough memory space at the beginnig of the array, move the beginnig part of the array the required amount of entries
                        MoveTheBeginningOfTheArrayTheRequiredAmountEntries_IMP( arrayBeginning, index, numberOfAdditionalEntriesRequiredAtTheMiddle );
                    }
                    else
                    {
                        // A new bigger memory space must be allocated, and the 2 parts of the array must be copied to it with a gap in the size of the additional 
                        // entries required
                        AllocateBiggerMemorySpaceAndCopyTheArrayPartsWithGap_IMP( arrayBeginning, arrayEnding, index, numberOfAdditionalEntriesRequiredAtTheMiddle );
                    }

                }
                else
                {
                    // There is enough memory space at the end of the array, move the end part of the array the required amount of entries
                    MoveTheEndOfTheArrayTheRequiredAmountEntries_IMP( arrayBeginning, index, numberOfAdditionalEntriesRequiredAtTheMiddle );
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
        //          1. arrayBeginning - a pointer object to the beginning part of the array
        //          2. arrayEnding - a pointer object to the ending part of the array
        //          3. index - this will used to determine the required entry
        //          4. numberOfAdditionalEntriesRequiredAtTheMiddle - the number of additional entries required at the middle
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
        //      1. There is no more free memory space - class std::bad_alloc is thrown
        //      2. Deleting the old memory space failed
        //      3. 
        //
        template< typename BasicType >
        inline void BasicTypesArray< BasicType >::AllocateBiggerMemorySpaceAndCopyTheArrayPartsWithGap_IMP( const DataTypes::Pointer< BasicType >& arrayBeginning, const DataTypes::Pointer< BasicType >& arrayEnding, const UnsignedInteger64bits& index, UnsignedInteger64bits numberOfAdditionalEntriesRequiredAtTheMiddle )
        {
            // Create a temporary with enough memory space for the additional entries
            BasicTypesArray< BasicType > temporary( m_size + numberOfAdditionalEntriesRequiredAtTheMiddle );

            // Now all the array must be copied, but it will be copied with the additional entries in the middle

            // This pointer will point to the beginning part of the array
            DataTypes::Pointer< BasicType > temporaryBeginning( ( temporary.m_basicTypesArray + temporary.m_numberOfFreeEntriesBefore ), ( index + 1 ) );

            // This pointer will point to the end part of the array
            DataTypes::Pointer< BasicType > temporaryEnd( ( temporary.m_basicTypesArray + ( temporary.m_numberOfFreeEntriesBefore + ( index + 1 ) + numberOfAdditionalEntriesRequiredAtTheMiddle ) ), ( m_size - ( index + 1 ) ) );

            // Copy the beginning of the basic types array to the new memory space
            Memory::Copy< BasicType >( arrayBeginning, temporaryBeginning );

            // Copy the beginning of the basic types array to the new memory space
            Memory::Copy< BasicType >( arrayEnding, temporaryEnd );

            // Swap between the heap shared pointer inside this instance and the temporary
            Swap( temporary );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to move the beginning part of the part determind by the index, the required entries        
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. arrayEnding - this will point to the ending part of the array
        //          2. index - this will used to determine the required entry
        //          3. numberOfAdditionalEntriesRequiredAtTheBeginning - the number of additional entries needed at the beginning
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
        //      1. There is no more memory space - class std::bad_alloc is thrown
        //      2. The object does not have assignment opeartor
        //      3. Deleting the old memory space failed
        //      4.
        //
        template< typename BasicType >
        void BasicTypesArray< BasicType >::MoveTheEndOfTheArrayTheRequiredAmountEntries_IMP( DataTypes::Pointer< BasicType >& arrayEnding, const UnsignedInteger64bits& index, UnsignedInteger64bits numberOfAdditionalEntriesRequiredAtTheMiddle )
        {
            // This pointer will point to the destination of the ending part of the array that needs to be moved
            DataTypes::Pointer< BasicType > destination( ( m_basicTypesArray + ( ( m_numberOfFreeEntriesBefore + ( index + 1 ) ) + numberOfAdditionalEntriesRequiredAtTheMiddle ) ), ( m_size - ( index + 1 ) ) );

            // Move the end part of the array the required amount of entries 
            Memory::Copy< BasicType >( arrayEnding, destination );

            // Set the new size of the array
            m_size += numberOfAdditionalEntriesRequiredAtTheMiddle;
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to move the beginning part of the part determind by the index, the required entries        
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. arrayBeginning - this will point to the beginning part of the array
        //          2. index - this will used to determine the required entry
        //          3. numberOfAdditionalEntriesRequiredAtTheBeginning - the number of additional entries needed at the beginning
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
        //      1. There is no more memory space - class std::bad_alloc is thrown
        //      2. The object does not have assignment opeartor
        //      3. Deleting the old memory space failed
        //      4.
        //
        template< typename BasicType >
        void BasicTypesArray< BasicType >::MoveTheBeginningOfTheArrayTheRequiredAmountEntries_IMP( DataTypes::Pointer< BasicType >& arrayBeginning, const UnsignedInteger64bits& index, UnsignedInteger64bits numberOfAdditionalEntriesRequiredAtTheMiddle )
        {
            // This pointer will point to the destination of the ending part of the array that needs to be moved
            DataTypes::Pointer< BasicType > destination( ( m_basicTypesArray + ( m_numberOfFreeEntriesBefore - ( index + 1 ) ) ), ( index + 1 ) );

            // Move the beginning part of the array the required amount of entries 
            Memory::Copy< BasicType >( arrayBeginning, destination );

            // Set the new size of the array
            m_size += numberOfAdditionalEntriesRequiredAtTheMiddle;

            // Set the new number of entries before the beginning of the array
            m_numberOfFreeEntriesBefore -= ( index + 1 );
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
        //      1. Deleting the old memory space failed
        //      2. 
        //
        template< typename BasicType >
        inline void BasicTypesArray< BasicType >::AllocateSmallerMemorySpaceAndCopyTheArrayPartsContigousWithoutTheRemovedEntries_IMP( const DataTypes::Pointer< BasicType >& arrayBeginning, const DataTypes::Pointer< BasicType >& arrayEnding, const UnsignedInteger64bits& index, UnsignedInteger64bits numberOfEntriesToRemove )
        {
            // Create a copy of the other instance
            BasicTypesArray< BasicType > temporary( m_size - numberOfEntriesToRemove );

            // Copy the beginning part of the basic typea array to the new location
            Memory::Copy< BasicType >( arrayBeginning, DataTypes::Pointer< BasicType >( ( temporary + temporary.m_numberOfFreeEntriesBefore ), arrayBeginning.Size() ) );

            // Copy the ending part of the basic typea array to the new location
            Memory::Copy< BasicType >( arrayEnding, DataTypes::Pointer< BasicType >( ( temporary + ( temporary.m_numberOfFreeEntriesBefore + arrayBeginning.Size() ) ), arrayEnding.Size() ) );

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
        //  Possible errors :
        //
        //      They will come
        //
        template< typename BasicType >
        inline BasicType& BasicTypesArray< BasicType >::GetData__IMP( const UnsignedInteger64bits& index )
        {
            // Return a reference to the data
            return ( m_basicTypesArray[ index ] );
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
        inline BasicType BasicTypesArray< BasicType >::GetData__IMP( const UnsignedInteger64bits& index ) const
        {
            // Return a copy of the data
            return ( m_basicTypesArray[ index ] );
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
        inline void BasicTypesArray< BasicType >::ExecuteTaskBeforeObjectChanges__IMP()
        {
            // Check if only this instance uses the shared resource
            RETURN_IF_THE_VALUES_ARE_EQUAL( m_basicTypesArray.GetNumberOfReferences(), 1 )

            // More then 1 instance uses the shared resource, Create a new copy of the resource            
            AllocateBiggerMemorySpaceAndCopyTheArrayToTheMiddle_IMP( 0 );
        }




















































































// *********************************************************************************   TESTING   *******************************************************************************









































        // All the following methods will be added only in test mode, they are not part of the implementation, their purpose is to
        // help locate problems in the code


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
            //  Possible errors :
            //
            //      They will come
            //
            template< typename BasicType >
            void BasicTypesArray< BasicType >::Test()
            {
                // Create an instance of basic types array
                BasicTypesArray< SignedInteger32bits > testArray_1;

                // Check that it is really in default state
                ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1.DefaultState() == true ), "BasicTypesArray::Test failed - the default constructor does not work correctly - 1" );

                for ( int i = 0 ; i < 100000 ; ++i )
                {
                	std::cout << i << std::endl;
                	testArray_1.PushHead( i );
                    testArray_1.Display();
                }

                std::cout << "Lol" << std::endl;

                // Create another instance using the copy constructor
                BasicTypesArray< SignedInteger32bits > testArray_2( testArray_1 );

                // Check that the 2 instnaces are the same
                ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1 == testArray_2 ), "BasicTypesArray::Test failed - copy constructor does not work correctly - 2" );

                // Check that the 2 instnaces are the same
                ErrorHandling::Assert< ErrorHandling::Exception >::False( ( testArray_1 != testArray_2 ), "BasicTypesArray::Test failed - copy constructor does not work correctly - 3" );

                // Check the copy on write 
                testArray_2[2] += 673;

                // Check that the 2 instnaces are the same
                ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1 != testArray_2 ), "BasicTypesArray::Test failed - copy constructor does not work correctly - 4" );

                // Check that the 2 instnaces are the same
                ErrorHandling::Assert< ErrorHandling::Exception >::False( ( testArray_1 == testArray_2 ), "BasicTypesArray::Test failed - copy constructor does not work correctly - 5" );

                // Try to add 2 instnaces
                testArray_1 += testArray_2;

                // The first flow is to create the basic types array from default state by pushing the head

                // Set the instnace to default state
                testArray_1.DeleteResourcesAndSetToDefaultState();

                // Try to add an entry to the array
                testArray_1.PushHead( 56 );

                // Check that the parameters are correct
                ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1[0] == 56 ), "BasicTypesArray::Test failed - push head does not work correctly - 6" );

                // Try to add a lot of entries
                for ( SignedInteger32bits index = 0 ; index < 50001 ; ++index )
                {
                    // Add the entry
                    testArray_1.PushHead( index );

                    // Check that the parameters are correct
                    ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1[0] == index ), "BasicTypesArray::Test failed - push head does not work correctly - 7" );
                }

                // Try to remove all of the entries
                for ( SignedInteger32bits index = 50002 ; index > 3 ; --index )
                {
                    // Remove the entry
                    testArray_1.PopHead();

                    // Check that the parameters are correct
                    ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1[0] == ( index - 3 ) ), "BasicTypesArray::Test failed - pop head does not work correctly - 8" );
                }

                // Try to remove all of the entries
                for ( SignedInteger32bits index = 0 ; index < 3 ; ++index )
                {
                    // Remove the entry
                    testArray_1.PopHead();
                }

                // Check that it is really in default state
                ErrorHandling::Assert< ErrorHandling::Exception >::True( testArray_1.DefaultState(), "BasicTypesArray::Test failed - the pop head does not move the object to default state when the size is 0 - 9" );

                // Try to add a lot of entries
                for ( SignedInteger32bits index = 0 ; index < 50001 ; ++index )
                {
                    // Add the entry
                    testArray_1.PushTail( index );

                    // Check that the parameters are correct
                    ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1[ testArray_1.Size() - 1 ] == index ), "BasicTypesArray::Test failed - push tail does not work correctly - 10" );
                }

                // Try to remove all of the entries
                for ( SignedInteger32bits index = 50002 ; index > 3 ; --index )
                {
                    // Remove the entry
                    testArray_1.PopTail();

                    // Check that the parameters are correct
                    ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1[ testArray_1.Size() - 1 ] == ( index - 3 ) ), "BasicTypesArray::Test failed - pop tail does not work correctly - 11" );
                }

                // Try to remove all of the entries
                for ( SignedInteger32bits index = 0 ; index < 2 ; ++index )
                {
                    // Remove the entry
                    testArray_1.PopTail();
                }

                // Create an instance of basic types array
                BasicTypesArray< SignedInteger32bits > testArray_3;

                // Create a vector instnace
                std::vector< SignedInteger32bits > testVector_1;

                // Add some values
                testArray_1.PushTail( 56 );
                testArray_1.PushTail( 66 );
                testArray_1.PushTail( 76 );
                testArray_1.PushTail( 86 );
                testArray_1.PushTail( 96 );
                testArray_1.PushTail( 106 );
                testArray_1.PushTail( 116 );
                testArray_1.PushTail( 126 );
                testArray_1.PushTail( 136 );

                // Add some values to vecotr
                testVector_1.push_back( 56 );
                testVector_1.push_back( 66 );
                testVector_1.push_back( 76 );
                testVector_1.push_back( 86 );
                testVector_1.push_back( 96 );
                testVector_1.push_back( 106 );
                testVector_1.push_back( 116 );
                testVector_1.push_back( 126 );
                testVector_1.push_back( 136 );

                // Check that the sizes of the arrays are the same
                ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1.Size() == testVector_1.size() ), "BasicTypesArray::Test failed - the sizes of the arrays do not match" );

                // Loop on all the entries and check that they match in both arrays
                for ( SignedInteger32bits basicTypesArrayIndex = 0 ; basicTypesArrayIndex < static_cast< SignedInteger32bits >( testArray_1.Size() ) ; ++basicTypesArrayIndex )
                {
                    // Check that the sizes of the arrays are the same
                    ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1[ basicTypesArrayIndex ] == testVector_1[ basicTypesArrayIndex ] ), "BasicTypesArray::Test failed - the values inside the entries of the 2 arrays do not match" );
                }

                // Create an instance of basic types array
                BasicTypesArray< SignedInteger32bits > testArray_4;

                // Create a vector instnace
                std::vector< SignedInteger32bits > testVector_2;

                // Add many entries
                for ( SignedInteger32bits index = 0 ; index < 1000000 ; ++index )
                {
                    // Add the values
                    testArray_4.PushTail( index );
                    testVector_2.push_back( index );
                }

                // Check that the sizes of the arrays are the same
                ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1.Size() == testVector_1.size() ), "BasicTypesArray::Test failed - the sizes of the arrays do not match" );

                // Loop on all the entries and check that they match in both arrays
                for ( SignedInteger32bits basicTypesArrayIndex = 0 ; basicTypesArrayIndex < static_cast< SignedInteger32bits >( testArray_1.Size() ) ; ++basicTypesArrayIndex )
                {
                    // Check that the sizes of the arrays are the same
                    ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1[ basicTypesArrayIndex ] == testVector_1[ basicTypesArrayIndex ] ), "BasicTypesArray::Test failed - the values inside the entries of the 2 arrays do not match" );
                }

                // Add many entries
                for ( SignedInteger32bits index = 0 ; index < 10000 ; ++index )
                {
                    // Add the values
                    testArray_4.PushTail( index );
                    testVector_2.push_back( index );
                }

                // Remove many entries
                for ( SignedInteger32bits index = 0 ; index < 234000 ; ++index )
                {
                    // Add the values
                    testArray_4.PopTail();
                    testVector_2.pop_back();
                }

                // Add many entries
                for ( SignedInteger32bits index = 0 ; index < 3000000 ; ++index )
                {
                    // Add the values
                    testArray_4.PushTail( index );
                    testVector_2.push_back( index );
                }

                // Remove many entries
                for ( SignedInteger32bits index = 0 ; index < 1500000 ; ++index )
                {
                    // Add the values
                    testArray_4.PopTail();
                    testVector_2.pop_back();
                }

                // Check that the sizes of the arrays are the same
                ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1.Size() == testVector_1.size() ), "BasicTypesArray::Test failed - the sizes of the arrays do not match" );

                // Loop on all the entries and check that they match in both arrays
                for ( SignedInteger32bits basicTypesArrayIndex = 0 ; basicTypesArrayIndex < static_cast< SignedInteger32bits >( testArray_1.Size() ) ; ++basicTypesArrayIndex )
                {
                    // Check that the sizes of the arrays are the same
                    ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1[ basicTypesArrayIndex ] == testVector_1[ basicTypesArrayIndex ] ), "BasicTypesArray::Test failed - the values inside the entries of the 2 arrays do not match" );
                }

                // Yay, test passed!!!
            }


            // Method Information :
            //
            //  Description :
            //
            //      This method is used to display the basic types array content
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
            void BasicTypesArray< BasicType >::Display() const
            {

                // Loop on all the entries
                for ( UnsignedInteger64bits basicTypesArrayIndex = m_numberOfFreeEntriesBefore ; basicTypesArrayIndex < ( m_numberOfFreeEntriesBefore + m_size ) ; ++basicTypesArrayIndex )
                {
                    // Display current entry
                    std::cout << m_basicTypesArray[ basicTypesArrayIndex ] << " ";
                }

                // Go down one line for better readability
                std::cout << std::endl;
            }

        // )  //  End of debug tool








    }  //  Namespace Containers

}  //  Namespace Universe



#endif  // BASICTYPESARRAY_HPP











