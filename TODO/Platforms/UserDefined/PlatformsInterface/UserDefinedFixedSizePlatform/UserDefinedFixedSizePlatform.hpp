#ifndef  USERDEFINEDFIXEDSIZEPLATFORM_HPP
#define  USERDEFINEDFIXEDSIZEPLATFORM_HPP


#include "../../../../../Definitions/VariableTypesDefinitions.hpp"  //  Typedef
#include "../../../../../BasicUtilities/C++/cpp_BasicUtilities.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../Memory/Swap/Swap.hpp"  //  Class Swap
#include "../../../../../Memory/Copy/Copy/Copy.hpp"  //  Class Copy
#include "../../../../../Memory/Compare/Compare/Compare.hpp"  //  Class Compare
#include "../../../../../Memory/Set/Set/Set.hpp"  //  Class Set
#include "../../../../../Abilities/Proxy/UserDefinedProxy/UserDefinedProxy.hpp"  //  Class UserDefinedProxy
#include "../../../../../DataTypes/SmartPointers/HeapSharedPointer/HeapSharedPointer.hpp"  //  Class HeapSharedPointer


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../../../ErrorHandling/Assert/Assert.hpp"  //  Class Assert
#endif


// When a function name ends with the suffix IMP, the function is not part of the object interface ( capabilities ), it only used as aid to the function that
// it is, implementing only spsecific part



namespace Universe
{

    namespace Memory
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


        // The operator-> has special semantics in the language in that, when overloaded, it reapplies itself to the result. While the rest of the operators are applied only 
        // once, operator-> will be applied by the compiler as many times as needed to get to a raw pointer and once more to access the memory referred by that pointer


        // When aggregate initializers ( initializers in {} ) are used in the "traditional" ANSI C language ( C89/90 ), an individual initializer must be supplied for each 
        // structure member in order, beginning with the first, for example :
        //
        //      struct S { int a, b, c, d; };
        //
        //      struct S s = { 1, 2, 3, 4 };
        //
        // 1 for `s.a`, 2 for `s.b` and so on...
        //
        // You are not required to specify initializers for all members, i.e. you can stop at any time ( remaining members will be zero-initialized ). If for some reason 
        // you only cared to explicitly initialize the third member of the structure, you had to supply "dummy" explicit initializers for the first and the second members
        // ( just to get to the desired third ), for example :
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
        // That way you only explicitly initialize the desired member(s) ( and have the compiler to zero-initialize the rest ). This not only saves you some typing but 
        // also makes the aggregate initializers independent from the order in which the members are specified in the struct type declaration.
        //
        // Aggregate initializers, can be used with arrays, too. And C99 supports "tagged" initialization with arrays as well. How the "tags" look in case of an array is 
        // illustrated by the following example :
        //
        //      int a[10] = { [5] = 3 };
        //
        // It is worth noting one more time that C language continues to stick to the "all or nothing" approach to aggregate initialization: if you specify an explicit 
        // initializer for just one ( or some ) members of a struct or an array, the whole aggregate ( struct or array ) gets initialized, and the members without 
        // explicit initializers get zero-initialized


    	// Template class Information :
    	//
    	//  Purpose :
    	//
    	//      Use this object to manage a contigous segment of basic types data, when the number of entries required is known in advance
    	//
   	    //  Description :
   	    //
  	    //		1. The access to elements in the container should be through the operator []. This will allow the object to prevent copying the resource when it needs to only
  	    //		   read from it. In other words it will allow the resource inside each instance to be shared as long as changes are not made to it. To implement this the arithmetic
  	    //		   for basic types containers object is inherited. This object will add the functionality of a proxy. Instead of returning the data or a reference to data, a proxy
  	    //		   instance is created with the knowledge of the required data, this gives the abililty to know what is the next required thing from the data. The basic change is
  	    //		   if we need to write or read. For example,
  	    //
  	    //					container[ index ] + 3
  	    //
  	    //		   In this case a proxy will be created from the first part of the expression, and then the operator+ will be choosen from the proxy. This method does not change
  	    //		   the instance, it only needs to read the data, and therefore no copy on write is needed, but in the case,
  	    //
  	    //					container[ index ] += 3
  	    //
  	    //			In this case the object does need to change, and therefore the proxy must make sure the container performs a copy on write prior to actual writing
    	//
    	//  Possible errors :
    	//
    	//
    	//
    	template< typename UserDefinedType >
        class UserDefinedFixedSizePlatform
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
    		inline UserDefinedFixedSizePlatform();


            // Method Information :
            //
            //  Description :
            //
            //      Constructor, receive the required size of the user defined fixed size platfrom and a reference to an existing object.
            //      The reference will be used to initialze all the entries of the user defined fixed size platfrom
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. size - the required number of entries in the user defined fixed size platfrom
            //          2. instance - a reference to an instance to initialze all the entries
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
            //      2. The given size of the user defined fixed size platfrom is 0
            //      3. The object does not have assignment operator
            //      4. 
            //
            explicit inline UserDefinedFixedSizePlatform( UnsignedInteger64bits size, const UserDefinedType& instance = UserDefinedType() );


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
    		inline UserDefinedFixedSizePlatform( const UserDefinedFixedSizePlatform< UserDefinedType >& other );


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
    		inline UserDefinedFixedSizePlatform< UserDefinedType >& operator=( const UserDefinedFixedSizePlatform< UserDefinedType >& other );


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
    		inline UserDefinedFixedSizePlatform( UserDefinedFixedSizePlatform< UserDefinedType >&& other );


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
    		inline UserDefinedFixedSizePlatform< UserDefinedType >& operator=( UserDefinedFixedSizePlatform< UserDefinedType >&& other );


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
            inline void Swap( UserDefinedFixedSizePlatform< UserDefinedType >& other );


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
    		virtual inline ~UserDefinedFixedSizePlatform();


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
    		inline bool DefaultState() const;


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
	        //      Use this to set a new size for the user defined fixed size platfrom. Note - all previous data in the platfrom will be lost
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
            //          1. newSize - the size of the new user defined fixed size platfrom
            //          2. instance - a reference to an instance to initialze all the entries
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
	        //      1. The given size of the new user defined fixed size platfrom is 0 
	        //      2.
	        //
	        void Initiate( UnsignedInteger64bits newSize, const UserDefinedType& instance = UserDefinedType() );


            // Method Information :
            //
            //  Description :
            //
            //      Use this to set all the entries of the user defined fixed size platfrom to the required value
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          instance - a reference to an instance to initialze all the entries
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
            inline void SetAll( const UserDefinedType& instance );


            // Method Information :
            //
            //  Description :
            //
            //      Use to get the number of entries in the user defined fixed size platfrom
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
            //      The size of the user defined fixed size platfrom
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
            //      The user defined fixed size platfrom proxy class
            //
            //  Possible errors :
            //
            //      1. The object is in default state
            //      2. The entry index is out of the user defined fixed size platfrom range
            //      3.
            //
            inline typename Abilities::UserDefinedProxy< UserDefinedFixedSizePlatform< UserDefinedType >, UnsignedInteger64bits, UserDefinedType > operator[]( UnsignedInteger64bits index );


            // Method Information :
            //
            //  Description :
            //
            //      Use to get a constant reference to an entry
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
            //      A constant reference to the required instance
            //
            //  Possible errors :
            //
            //      1. The object is in default state
            //      2. The entry index is out of the user defined fixed size platfrom range
            //      3.
            //
            inline const UserDefinedType& operator[]( UnsignedInteger64bits index ) const;


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
            //      2. The entry index is out of the user defined fixed size platfrom range
            //      3.
            //
            inline UserDefinedType* operator+( UnsignedInteger64bits index );


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
    		bool operator==( const UserDefinedFixedSizePlatform< UserDefinedType >& other ) const;


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
    		inline bool operator!=( const UserDefinedFixedSizePlatform< UserDefinedType >& other ) const;


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


            // This object will store the objects fixed size array
            DataTypes::HeapSharedPointer< UnsignedInteger8bits > m_userDefinedFixedSizePlatform;

            // This object will be used to point to the array as the user defined type
            DataTypes::Pointer< UserDefinedType > m_userDefinedFixedSizePlatformPointer;


    	private:


            // Allow the inherited arithmetic proxy object, to access protected and private sections of this object
            friend class Abilities::UserDefinedProxy< UserDefinedFixedSizePlatform< UserDefinedType >, UnsignedInteger64bits, UserDefinedType >;


            // The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
            // rather help implement it :


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to call the destructors of all the instances in the array
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
            //  Return object :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      1. Deleting the object failed
            //      2.
            //
            inline void DestructAllInstances();


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to copy the objects fixed size array to a new memory space
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
            //  Return object :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      1. There is no more free space - class std::bad_alloc is thrown
            //      2.
            //
            inline void CopyIMP();


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
            inline UserDefinedType& GetData( UnsignedInteger64bits index );


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
            inline const UserDefinedType& GetData( UnsignedInteger64bits index ) const;


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
            inline void ExecuteTaskBeforeObjectChanges();


    	};  //  Class UserDefinedFixedSizePlatform













































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
    	template< typename UserDefinedType >
    	inline UserDefinedFixedSizePlatform< UserDefinedType >::UserDefinedFixedSizePlatform() :
        m_userDefinedFixedSizePlatform(),
        m_userDefinedFixedSizePlatformPointer()
    	{}


        // Method Information :
        //
        //  Description :
        //
        //      Constructor, receive the required size of the user defined fixed size platfrom and a reference to an existing object.
        //      The reference will be used to initialze all the entries of the user defined fixed size platfrom
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. size - the required number of entries in the user defined fixed size platfrom
        //          2. instance - a reference to an instance to initialze all the entries
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
        //      2. The given size of the user defined fixed size platfrom is 0
        //      3. The object does not have assignment operator
        //      4. 
        //
        template< typename UserDefinedType >
        inline UserDefinedFixedSizePlatform< UserDefinedType >::UserDefinedFixedSizePlatform( UnsignedInteger64bits size, const UserDefinedType& instance ) :
        m_userDefinedFixedSizePlatform( new UnsignedInteger8bits[ size * sizeof( UserDefinedType ) ], ( size * sizeof( UserDefinedType ) ) ),
        m_userDefinedFixedSizePlatformPointer( m_userDefinedFixedSizePlatform.template Get< UserDefinedType >(), size )
        {
            // Set the elements of the memory segment to the required instance
            SetAll( instance );
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
    	template< typename UserDefinedType >
    	inline UserDefinedFixedSizePlatform< UserDefinedType >::UserDefinedFixedSizePlatform( const UserDefinedFixedSizePlatform< UserDefinedType >& other ) :
        m_userDefinedFixedSizePlatform( other.m_userDefinedFixedSizePlatform ),
        m_userDefinedFixedSizePlatformPointer( other.m_userDefinedFixedSizePlatformPointer )
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
    	template< typename UserDefinedType >
    	inline UserDefinedFixedSizePlatform< UserDefinedType >& UserDefinedFixedSizePlatform< UserDefinedType >::operator=( const UserDefinedFixedSizePlatform< UserDefinedType >& other )
    	{
    		// Create a copy of the other instance
    		UserDefinedFixedSizePlatform< UserDefinedType > temporary( other );

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
    	template< typename UserDefinedType >
    	inline UserDefinedFixedSizePlatform< UserDefinedType >::UserDefinedFixedSizePlatform( UserDefinedFixedSizePlatform< UserDefinedType >&& other ) :
    	UserDefinedFixedSizePlatform< UserDefinedType >()
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
    	template< typename UserDefinedType >
    	inline UserDefinedFixedSizePlatform< UserDefinedType >& UserDefinedFixedSizePlatform< UserDefinedType >::operator=( UserDefinedFixedSizePlatform< UserDefinedType >&& other )
    	{
    	    // Create a default constructed instance
    	    UserDefinedFixedSizePlatform< UserDefinedType > defaultConstructedInstance;

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
        template< typename UserDefinedType >
        inline void UserDefinedFixedSizePlatform< UserDefinedType >::Swap( UserDefinedFixedSizePlatform< UserDefinedType >& other )
    	{
            // Swap between the heap shared pointers
            m_userDefinedFixedSizePlatform.Swap( other.m_userDefinedFixedSizePlatform );

            // Swap between the pointers
            m_userDefinedFixedSizePlatformPointer.Swap( other.m_userDefinedFixedSizePlatformPointer );
        }


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
    	template< typename UserDefinedType >
        inline UserDefinedFixedSizePlatform< UserDefinedType >::~UserDefinedFixedSizePlatform()
    	{
    		// Delete the instance resources
    		DeleteResourcesAndSetToDefaultState();
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
    	template< typename UserDefinedType >
    	inline void UserDefinedFixedSizePlatform< UserDefinedType >::SetToDefaultState()
    	{
            // Set the heap shared pointer to default state
            m_userDefinedFixedSizePlatform.SetToDefaultState();

            // Set the pointer to default state
            m_userDefinedFixedSizePlatformPointer.SetToDefaultState();
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
    	template< typename UserDefinedType >
    	inline bool UserDefinedFixedSizePlatform< UserDefinedType >::DefaultState() const
    	{

    		// Check if the object is in default state
            if ( ( m_userDefinedFixedSizePlatform.DefaultState() == true ) &&
                 ( m_userDefinedFixedSizePlatformPointer.DefaultState() == true ) )
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
    	template< typename UserDefinedType >
    	inline void UserDefinedFixedSizePlatform< UserDefinedType >::DeleteResourcesAndSetToDefaultState()
    	{
            // Check if the object is in default state, then noting needs to be done
            RETURN_IF_EXPRESSION_IS_TRUE( DefaultState() )

            // Call the destructors of all the instances in the array
            DestructAllInstances();

            // Delete the memory space
            m_userDefinedFixedSizePlatform.DeleteResourcesAndSetToDefaultState();

            // Set the pointer to default state
            m_userDefinedFixedSizePlatformPointer.SetToDefaultState();
    	}


        // Method Information :
        //
        //  Description :
        //
        //      Use this to set a new size for the user defined fixed size platfrom. Note - all previous data in the platfrom will be lost
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. newSize - the size of the new user defined fixed size platfrom
        //          2. instance - a reference to an instance to initialze all the entries
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
        //      1. The given size of the new user defined fixed size platfrom is 0 
        //      2.
        //
        template< typename UserDefinedType >
        void UserDefinedFixedSizePlatform< UserDefinedType >::Initiate( UnsignedInteger64bits newSize, const UserDefinedType& instance )
        {
            // Create a new temporary instance
            UserDefinedFixedSizePlatform< UserDefinedType > temporary( newSize, instance );

            // Swap between this instance and the temporary one
            Swap( temporary );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this to set all the entries of the user defined fixed size platfrom to the required value
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          instance - a reference to an instance to initialze all the entries
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
        template< typename UserDefinedType >
        inline void UserDefinedFixedSizePlatform< UserDefinedType >::SetAll( const UserDefinedType& instance )
        {
            // A write operation is about to take place, check if only this instance uses the resource, if not, copy it to a new one that only this instance uses
            ExecuteTaskBeforeObjectChanges();

            // Loop on the entries of the objects array
            for ( UnsignedInteger64bits index = 0 ; index < m_userDefinedFixedSizePlatformPointer.Size() ; ++index )
            {
                // Point to the current entry as the template type, and use the copy constructor
                m_userDefinedFixedSizePlatformPointer[ index ] = instance;
            }
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to get the number of entries in the user defined fixed size platfrom
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
        //      The size of the user defined fixed size platfrom
        //
        //  Possible errors :
        //
        //      1. The object is in default state
        //      2.
        //
        template< typename UserDefinedType >
        inline UnsignedInteger64bits UserDefinedFixedSizePlatform< UserDefinedType >::Size() const
        {
            // Return the number of entries in the user defined fixed size platfrom
            return ( m_userDefinedFixedSizePlatformPointer.Size() );
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
        //      The user defined fixed size platfrom proxy class
        //
        //  Possible errors :
        //
        //      1. The object is in default state
        //      2. The entry index is out of the user defined fixed size platfrom range
        //      3.
        //
        template< typename UserDefinedType >
        inline typename Abilities::UserDefinedProxy< UserDefinedFixedSizePlatform< UserDefinedType >, UnsignedInteger64bits, UserDefinedType > UserDefinedFixedSizePlatform< UserDefinedType >::operator[]( UnsignedInteger64bits index )
        {
            // Create the proxy class and return it
            return ( typename Abilities::UserDefinedProxy< UserDefinedFixedSizePlatform< UserDefinedType >, UnsignedInteger64bits, UserDefinedType >( *this, index ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to get a constant reference to an entry
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
        //      A constant reference to the required instance
        //
        //  Possible errors :
        //
        //      1. The object is in default state
        //      2. The entry index is out of the user defined fixed size platfrom range
        //      3.
        //
        template< typename UserDefinedType >
        inline const UserDefinedType& UserDefinedFixedSizePlatform< UserDefinedType >::operator[]( UnsignedInteger64bits index ) const
        {
            // Return a constant reference to the instance
            return ( m_userDefinedFixedSizePlatformPointer[ index ] );
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
        //      2. The entry index is out of the user defined fixed size platfrom range
        //      3.
        //
        template< typename UserDefinedType >
        inline UserDefinedType* UserDefinedFixedSizePlatform< UserDefinedType >::operator+( UnsignedInteger64bits index )
        {
            // Return the required address
            return ( m_userDefinedFixedSizePlatformPointer + index );
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
    	template< typename UserDefinedType >
    	inline bool UserDefinedFixedSizePlatform< UserDefinedType >::operator==( const UserDefinedFixedSizePlatform< UserDefinedType >& other ) const
    	{

            // Check that the size, capacity and number of free entries before the first entry match in both objects
            if ( m_userDefinedFixedSizePlatformPointer.Size() != other.m_userDefinedFixedSizePlatformPointer.Size() )
            {
                // The 2 instnaces are not the same
                return ( false );
            }

            // Loop on all the entries of both of the objects and check if they match
            for ( UnsignedInteger64bits index = 0 ; index < m_userDefinedFixedSizePlatformPointer.Size() ; ++index )
            {

                // Check if the value inside current entry match in both objects
                if ( m_userDefinedFixedSizePlatformPointer[ index ] != other.m_userDefinedFixedSizePlatformPointer[ index ] )
                {
                    // The value inside current entry does not match in both objects
                    return ( false );
                }

            }

            // If control reached here then both objects are the same
            return ( true );
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
    	template< typename UserDefinedType >
    	inline bool UserDefinedFixedSizePlatform< UserDefinedType >::operator!=( const UserDefinedFixedSizePlatform< UserDefinedType >& other ) const
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
        template< typename UserDefinedType >
        inline UserDefinedType& UserDefinedFixedSizePlatform< UserDefinedType >::GetData( UnsignedInteger64bits index )
        {
            // Return a reference to the data
            return ( m_userDefinedFixedSizePlatformPointer[ index ] );
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
        template< typename UserDefinedType >
        inline const UserDefinedType& UserDefinedFixedSizePlatform< UserDefinedType >::GetData( UnsignedInteger64bits index ) const
        {
            // Return a copy of the data
            return ( m_userDefinedFixedSizePlatformPointer[ index ] );
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
        template< typename UserDefinedType >
        inline void UserDefinedFixedSizePlatform< UserDefinedType >::ExecuteTaskBeforeObjectChanges()
        {
            // Check if only this instance uses the shared resource
            RETURN_IF_THE_VALUES_ARE_EQUAL( m_userDefinedFixedSizePlatform.GetNumberOfReferences(), 1 )

            // More then 1 instance uses the shared resource, Create a new copy of the resource            
            CopyIMP();
        }





































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************
































        // Method Information :
        //
        //  Description :
        //
        //      Use this method to call the destructors of all the instances in the array
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
        //  Return object :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      1. Deleting the object failed
        //      2.
        //
        template< typename UserDefinedType >
        inline void UserDefinedFixedSizePlatform< UserDefinedType >::DestructAllInstances()
        {

            // Loop on all the entries of the objects array
            for ( UnsignedInteger64bits index = 0 ; index < m_userDefinedFixedSizePlatformPointer.Size() ; ++index )
            {
                // Delete current object, using an explicit call to it's destructor
                DisplacmentDeleteForPointers< UserDefinedType >( m_userDefinedFixedSizePlatformPointer + index );
            }

        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to copy the user defined fixed size platfrom to a new memory space
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
        template< typename UserDefinedType >
        inline void UserDefinedFixedSizePlatform< UserDefinedType >::CopyIMP()
        {
            // Allocate new memory space
            DataTypes::HeapSharedPointer< UnsignedInteger8bits > temporary( new UnsignedInteger8bits[ m_userDefinedFixedSizePlatform.Size() ], m_userDefinedFixedSizePlatform.Size() );

            // Point to the new memory space as the user defined type
            DataTypes::Pointer< UserDefinedType > temporaryPointer( temporary.template Get< UserDefinedType >(), m_userDefinedFixedSizePlatformPointer.Size() );

            // Loop on all the entries and copy the fixed size array to the new memory space
            for ( UnsignedInteger64bits index = 0 ; index < m_userDefinedFixedSizePlatformPointer.Size() ; ++index )
            {
                // Initialize current entry using displacment new and the given reference to the object to copy
                new ( temporaryPointer + index ) UserDefinedType( m_userDefinedFixedSizePlatformPointer[ index ] );
            }

            // Swap between the temporary and this instance
            m_userDefinedFixedSizePlatform.Swap( temporary );

            // Swap between the pointers
            m_userDefinedFixedSizePlatformPointer.Swap( temporaryPointer );
        }






































// ********************************************************************************   TESTING   *********************************************************************************








































    	DEBUG_TOOL(

            // Create a testing object
            class Testing
            {
            public:

                Testing() : m_t( 0 ) { std::cout << "Default Constructor" << std::endl; }

                Testing( UnsignedInteger64bits tt ) : m_t( tt ) { std::cout << "Constructor" << std::endl; }

                Testing( const Testing& other ) : m_t( other.m_t ) {}

                ~Testing() { std::cout << "Destructor" << std::endl; }

                bool operator==( const Testing& other ) { return ( m_t == other.m_t ); }

                bool operator!=( const Testing& other ) { return ( m_t != other.m_t ); }

                bool operator==( UnsignedInteger64bits other ) { return ( m_t == other ); }

                void Display() { std::cout << m_t << std::endl; }

            private:

                UnsignedInteger64bits m_t;
            };

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
    		template< typename UserDefinedType >
    		void UserDefinedFixedSizePlatform< UserDefinedType >::Test()
    		{
                // Create an instance of the object using the default constructor
                UserDefinedFixedSizePlatform< Testing > testArray_1;

                // Check that it is really in default state
                ErrorHandling::Assert< ErrorHandling::Exception >::True( testArray_1.DefaultState(), "UserDefinedFixedSizePlatform::Test failed - the default constructor does not work correctly" );

                // Create another instance using the copy constructor
                testArray_1.Initiate( 15 );

                // Add some objects
                testArray_1[0] = Testing( 56 );
                testArray_1[1] = Testing( 66 );
                testArray_1[2] =  Testing( 76 );
                testArray_1[3] = Testing( 86 );
                testArray_1[4] = Testing( 96 );
                testArray_1[5] = Testing( 106 );
                testArray_1[6] = Testing( 116 );
                testArray_1[7] = Testing( 126 );
                testArray_1[8] = Testing( 136 );

                // Create an instnace using the copy constructor
                UserDefinedFixedSizePlatform< Testing > testArray_2( testArray_1 );

                // Check that the 2 instnaces are the same
                ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1 == testArray_2 ), "ObjectsArray::Test failed - copy constructor does not work correctly - 2" );

                // Check that the 2 instnaces are the same
                ErrorHandling::Assert< ErrorHandling::Exception >::False( ( testArray_1 != testArray_2 ), "ObjectsArray::Test failed - copy constructor does not work correctly - 3" );

                // Check the copy on write 
                testArray_2[2] = Testing( 22222 );

                // Check that the 2 instnaces are the same
                ErrorHandling::Assert< ErrorHandling::Exception >::False( ( testArray_1 == testArray_2 ), "ObjectsArray::Test failed - copy constructor does not work correctly - 4" );

                // Check that the 2 instnaces are the same
                ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_1 != testArray_2 ), "ObjectsArray::Test failed - copy constructor does not work correctly - 5" );

                // Create an instnace of the object using the parameterized constructor
                UserDefinedFixedSizePlatform< Testing > testArray_3( 67 );

                // Check the size of the array
                ErrorHandling::Assert< ErrorHandling::Exception >::True( ( 67 == testArray_3.Size() ), "UserDefinedFixedSizePlatform::Test failed - the constructor with only the size does not work correctly" );            

                // Create an instnace of the object using the parameterized constructor
                UserDefinedFixedSizePlatform< Testing > testArray_4( 67, Testing( 77 ) );

                // Check the size of the array
                ErrorHandling::Assert< ErrorHandling::Exception >::True( ( 67 == testArray_4.Size() ) && ( testArray_4[45] == 77 ), "UserDefinedFixedSizePlatform::Test failed - the constructor with size and value to initiate to does not work correctly" );            

                // Create an instance using the copy constructor
                UserDefinedFixedSizePlatform< Testing > testArray_5( testArray_3 );

                // Check that the 2 instnaces point to the same address
                ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_3 == testArray_5 ), "UserDefinedFixedSizePlatform::Test failed - the copy constructor does not work correctly" );            

                // A write operation is performed, to check that the object uses the copy on write method before
                testArray_5[5] = Testing( 78 );

                // Check that the 2 instnaces don't point to the same address
                ErrorHandling::Assert< ErrorHandling::Exception >::False( ( testArray_3 == testArray_5 ), "UserDefinedFixedSizePlatform::Test failed - the copy on write flow does not work correctly" );                                              
            }

    	)  //  End of debug tool





















    }  //  Namespace Memory

}  //  Namespace Universe


#endif  // USERDEFINEDFIXEDSIZEPLATFORM_HPP