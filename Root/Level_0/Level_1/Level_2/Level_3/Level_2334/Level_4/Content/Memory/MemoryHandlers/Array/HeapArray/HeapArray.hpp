#ifndef HEAPARRAY_HPP
#define HEAPARRAY_HPP


#include "../../../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA, Macro CompileTimeAssert
#include "../../../../../../../../../../ObjectBranch/Content/ObjectInfrastructure/BasicObjectFunctionality/BasicObjectFunctionality.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../../../../../../../../../ObjectBranch/Content/ObjectInfrastructure/GetAndSetForMembers/GetAndSetForMembers.hpp"  //  Macro VirtualGetByReferenceOnlyIfInstanceIsReady_MACRO
#include "../../../../../../../Content/Memory/Operations/Operations.hpp"  //  Class Operations
#include "../../../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../../../../../../../../../Content/Metaprogramming/MetaprogrammingMacros/MetaprogrammingMacros.hpp"  //  Macro MOVE
#include "../../../../../../../Content/Interfaces/AccessDataUsingIndices_Interface/AccessDataUsingIndices_Interface.hpp"  //  Class AccessDataUsingIndices_Interface
#include "../../../../../../../../../../Content/Metaprogramming/Types/PerformActionAccordingToType/PerformActionAccordingToType.hpp"  //  Class PerformActionAccordingToType
#include "../../../../../../Content/BindObjects/Tuple/Tuple.hpp"  //  Class Tuple
#include "../../../../../../../Content/Random/Generator/Generator.hpp"  //  Class Generator
#include "../../../../../../../Content/NumericRange/NumericRange.hpp"  //  Class NumericRange


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../../../../../../../../TestBranch/GeneralTests/SanityCheck/SanityCheck.hpp"  //  Class SanityCheck
#include "../../../../../../../../../../TestBranch/TestingTools/Objects/TestObject_1/TestObject_1.hpp"  //  Class TestObject_1
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



    	// What is the behavior of the operator 'new' in the following case :
    	//
    	//		new int[0]
    	//
    	// When the value of the expression in a direct new declarator is zero, the allocation function is called to allocate an array with no elements.
    	// The effect of dereferencing a pointer returned as a request for zero size is undefiend. Even if the size of the space requested is zero the
    	// request can fail. 
    	//
    	// This means that there is no well defined manner across all platforms to dereference the memory returned from the call of new with zero size,
    	// and it should be deleted. The intent is to have operator new implementable by calling malloc and calloc, so the rules are substantially the
    	// same. C++ differs from C in requiring a zero request to return a non null pointer



        // Placement new :
        //
        // Placement new allows you to constrcut an object on memory that's already allocated.
        //
        // Standard C++ also supports placement new operator, which constructs an object on a pre-allocated buffer. This is useful when building a memory
        // pool, a garbage collector or simply when performance and exception safety are paramount ( there's no danger of allocation failure since the memory
        // has already been allocated, and constructing an object on a pre-allocated buffer takes less time )



        // In order to create an array of objects, for example :
        //
        //      Class* classArray = new Class[34];
        //
        // The given class must have default constructor, or else the compiler does not know how to initialize the area



        // In C++ an inner class is by default a friend of the class it is decalred within. This means that if a reference to the outer class is given to 
        // the inner class, it can acess every member of the outer class 



        // Class size in C++ :
        //
        // To a first order approximation, the size of an object is the sum of the sizes of its constituent data members. Ths size will never be smaller 
        // than this. More precisely, the compiler is entitled to insert padding space between data members to ensure that each data member meets the 
        // alignment requirements of the platform. Some platforms are very strict about alignment, while others ( x86 ) are more forgiving, but will 
        // perform significantly better with proper alignment. So, even the compiler optimization setting can affect the object size.
        //
        // Inheritance and virtual functions add an additional complication. Member functions of a class do not take up "per object" space, but the 
        // existence of virtual functions in that class's interface generally implies the existence of a virtual table, essentially a lookup table 
        // of function pointers used to dynamically resolve the proper function implementation to call at runtime. The virtual table is accessed 
        // generally via a pointer stored in each object/
        //
        // Derived class objects also include all data members of their base classes. Finally, access specifiers ( public, private, protected ) grant 
        // the compiler certain leeway with packing of data members



        // When aggregate initializers ( initializers in {} ) are used in the "traditional" ANSI C language ( C89/90 ), an individual initializer must 
        // be supplied for each structure member in order, beginning with the first, for example :
        //
        //      struct S { int a, b, c, d; };
        //
        //      struct S s = { 1, 2, 3, 4 };
        //
        // 1 for `s.a`, 2 for `s.b` and so on...
        //
        // You are not required to specify initializers for all members, i.e. you can stop at any time ( remaining members will be zero-initialized ). 
        // If for some reason you only cared to explicitly initialize the third member of the structure, you had to supply "dummy" explicit initializers 
        // for the first and the second members ( just to get to the desired third ), for example :
        //
        // We only care to explicitly initialize `s.c`
        //
        //      struct S s = { 0, 0, 3 };
        //
        // but we have to explicitly initialize `s.a` and `s.b` as well
        //
        // Or abandon specific initialization entirely ( likely replacing it with generic = { 0 } ) and use a subsequent assignment to specific members, 
        // for example :
        //
        //      struct S s = { 0 };
        //      s.c = 3;
        //
        // One notable benefit of this assignment-based approach is that it is independent from the position of member c in the declaration of struct S. 
        // The new specification of C language ( C99 ) allows you to use "tagged" initializers by supplying the desired member name within the {}, for 
        // example :
        //
        //      struct S s = { .c = 3 };
        //
        // That way you only explicitly initialize the desired member(s) ( and have the compiler to zero-initialize the rest ). This not only saves you 
        // some typing but also makes the aggregate initializers independent from the order in which the members are specified in the struct type declaration.
        //
        // Aggregate initializers, can be used with arrays, too. And C99 supports "tagged" initialization with arrays as well. How the "tags" look in case 
        // of an array is illustrated by the following example :
        //
        //      int a[10] = { [5] = 3 };
        //
        // It is worth noting one more time that C language continues to stick to the "all or nothing" approach to aggregate initialization: if you specify 
        // an explicit initializer for just one ( or some ) members of a struct or an array, the whole aggregate ( struct or array ) gets initialized, and 
        // the members without explicit initializers get zero-initialized



		// Template Class Information :
		//
		//  Purpose :
		//
		//		Use this object to store multiple instances of the same type. The size of the array is provided as an argument to the constructor
    	//		which means that is allocated during run time, and therefore it will be placed on the heap memory segment
		//
		//  Description :
		//
		//		1. This object contains an instance of the object "InstanceState" to allow each instance of this object to have a defined state
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
		//			1. Type - any type
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		Too many to count
		//
		template< typename AnyType >
		class HeapArray : public AccessDataUsingIndices_Interface< AnyType >
		{
		public:


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
			inline HeapArray();


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
			//			1. size - the number of entries in the array
			//			2. instance - a reference to the instance that will be used to Initialize all the entries of the array
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
			//		1. The given size is larger then 0
			//		2. 
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			explicit inline HeapArray( UnsignedInteger64bits size, const AnyType& instance = PerformActionAccordingToType::GetDefaultInstance< AnyType >() );


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
	        //          other - a constant reference to an other heap array instance
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
	        //      1. The given heap array instance is ready 
	        //      2. The given heap array instance size should be larger then 0
	        //      3. 
	        //
	        //  Possible errors :
	        //
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
	        //
	        explicit inline HeapArray( const AccessDataUsingIndices_Interface< AnyType >& other );


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
	        //          2. rangeForSize - this will be used to limit the possible size of the random instance
	        //          3. argumentsNeededToGenerateRandomInstanceOfDataType - any arguments needed to create a random instance of the data type
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
	        explicit inline HeapArray( RandomInstance, NumericRange< UnsignedInteger64bits > rangeForSize = NumericRange< UnsignedInteger64bits >( 1UL, 10000UL ), ArgumentsTypesNeededToGenerateRandomInstanceOfDataType... argumentsNeededToGenerateRandomInstanceOfDataType );


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
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			inline HeapArray( const HeapArray< AnyType >& other );


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
			ObjectInfrastructure_ForInheritance_MACRO( HeapArray< AnyType > )


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
			inline void Swap( HeapArray< AnyType >& other );


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
			//			1. size - the number of entries in the array
			//			2. instance - a reference to the instance that will be used to Initialize all the entries of the array
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
			//		1. The given size is larger then 0
			//		2. 
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			inline void Initiate( UnsignedInteger64bits size, const AnyType& instance = PerformActionAccordingToType::GetDefaultInstance< AnyType >() );


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
	        //          2. rangeForSize - this will be used to limit the possible size of the random instance
	        //          3. argumentsNeededToGenerateRandomInstanceOfDataType - any arguments needed to create a random instance of the data type
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
	        inline void Initiate( RandomInstance, NumericRange< UnsignedInteger64bits > rangeForSize, ArgumentsTypesNeededToGenerateRandomInstanceOfDataType... argumentsNeededToGenerateRandomInstanceOfDataType );


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
			virtual ~HeapArray();


			// This part will contain all the get and set methods for the members of the object :


			// Member - member_size
			VirtualGetByValueOnlyIfInstanceIsReady_MACRO( Size, member_size, UnsignedInteger64bits )


			// The following methods give access and manipulate the data inside this object :


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to set the memory space with a specific instance
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. sizeToSet - the memory space size that needs to be set
			//			2. setStartingAtThisIndex - the index of the first entry that should be set
			//			3. instance - a constant reference to an instance that will be used to set all the required memory space
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
			//		1. The heap array instance should be ready
			//		2. The given index plus the size should be smaller then the heap array size
			//		3. The size to set should be larger then 0
			//		4. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			void Set( UnsignedInteger64bits sizeToSet, UnsignedInteger64bits setStartingAtThisIndex = 0UL, const AnyType& instance = PerformActionAccordingToType::GetDefaultInstance< AnyType >() );


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this method to get an instance with only part of the current instance
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          1. partStartingIndex - the starting index from which the part instance will start
	        //			2. partSize - the size of the part instance
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //      An instance with only the required part from this instance
	        //
	        //  Expectations :
	        //
	        //      1. The given part starting index is smaller then the instance size
	        //      2. The given part starting index and size is smaller or equal to the size of the instance
	        //      3. The given part size should be larger then 0
	        //		4. 
	        //
	        //  Possible errors :
	        //
	        //      They will come
	        //
	        inline HeapArray< AnyType > Part( UnsignedInteger64bits partStartingIndex, UnsignedInteger64bits partSize ) const;


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
			//		1. The instance should be ready
			//		2. The other instance should be ready
			//		3. The given part starting index plus the size must result in a sum smaller or equal to the instance size
			//		4. The given part starting index on the other instance plus the size must result in a sum smaller or equal to the other instance size
	        //      5. The part to compare size must be larger then 0
	        //		6. 
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
	        //		NONE
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
			//      Use this operator to get a copy of the value inside the required entry
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
			inline Boolean operator==( const HeapArray< AnyType >& other ) const;


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
			inline Boolean operator!=( const HeapArray< AnyType >& other ) const;


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
	        //          1. rangeForSize - this will be used to limit the possible size of the random instance
	        //          2. argumentsNeededToGenerateRandomInstanceOfDataType - any arguments needed to create a random instance of the data type
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
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
	        //
	        template< typename... ArgumentsTypesNeededToGenerateRandomInstanceOfDataType >
	        static inline HeapArray< AnyType > GenerateRandomInstance( NumericRange< UnsignedInteger64bits > rangeForSize = NumericRange< UnsignedInteger64bits >( 1UL, 10000UL ), ArgumentsTypesNeededToGenerateRandomInstanceOfDataType... argumentsNeededToGenerateRandomInstanceOfDataType );


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


			// This object will store the memory address of the memory space allocated for the array on the heap memory segment
 			Type* member_heapArray;

 			// This object will store the size of the array
 			UnsignedInteger64bits member_size;


		};  //  Class HeapArray




































//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************




































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
		template< typename AnyType >
		inline HeapArray< AnyType >::HeapArray() :
        AccessDataUsingIndices_Interface< AnyType >(),
		member_state(),
		member_heapArray( 0UL ),
		member_size( 0UL )
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
		//			1. size - the number of entries in the array
		//			2. instance - a reference to the instance that will be used to Initialize all the entries of the array
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
		//		1. The given size is larger then 0
		//		2. 
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename AnyType >
		inline HeapArray< AnyType >::HeapArray( UnsignedInteger64bits size, const AnyType& instance ) :
        AccessDataUsingIndices_Interface< AnyType >(),
		member_state( InstanceState::Ready ),
		member_heapArray( new Type[ size ] ),
		member_size( size )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
            AssertSizeIsLargerThenZero_MACRO( size )

			// Set all the entries to the required instance
			Memory::Operations::Set< AnyType >( member_heapArray, size, instance );
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
        //          other - a constant reference to an other heap array instance
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
        //      1. The given heap array instance is ready 
        //      2. The given heap array instance size should be larger then 0
        //      3. 
        //
        //  Possible errors :
        //
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
        //
        template< typename AnyType >
        inline HeapArray< AnyType >::HeapArray( const AccessDataUsingIndices_Interface< AnyType >& other ) :
        AccessDataUsingIndices_Interface< AnyType >(),
        member_state( InstanceState::Ready ),
        member_heapArray( new Type[ other.Size() ] ),
        member_size( other.member_size )
        {
			// Each method that interacts with the user directly needs to ensure that the given data is valid
            AssertSizeIsLargerThenZero_MACRO( other.Size() )
            
            // Loop on all the entries of the other heap array
            for ( UnsignedInteger64bits otherSequentialPlatformIndex = 0UL ; otherSequentialPlatformIndex < other.Size() ; ++otherSequentialPlatformIndex )
            {
                // Copy the current entry from the other heap array to this instance
                member_heapArray[ otherSequentialPlatformIndex ] = other[ otherSequentialPlatformIndex ];
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
        //          2. rangeForSize - this will be used to limit the possible size of the random instance
        //          3. argumentsNeededToGenerateRandomInstanceOfDataType - any arguments needed to create a random instance of the data type
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
		template< typename AnyType >
        template< typename... ArgumentsTypesNeededToGenerateRandomInstanceOfDataType >
        inline HeapArray< AnyType >::HeapArray( RandomInstance, NumericRange< UnsignedInteger64bits > rangeForSize, ArgumentsTypesNeededToGenerateRandomInstanceOfDataType... argumentsNeededToGenerateRandomInstanceOfDataType ) :
        SelfType( Random::Generator::Get< UnsignedInteger64bits >( rangeForSize ), Random::Generator::Get< AnyType >( argumentsNeededToGenerateRandomInstanceOfDataType... ) )
        {

            // Set the entries of the generated instance to random values
            for ( UnsignedInteger64bits index = 0UL ; index < member_size ; ++index )
            {
                // Set the current entry with random generated data
                (*this)[ index ] = MOVE( Random::Generator::Get< AnyType >( argumentsNeededToGenerateRandomInstanceOfDataType... ) );
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
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename AnyType >
		inline HeapArray< AnyType >::HeapArray( const HeapArray< AnyType >& other ) :
        AccessDataUsingIndices_Interface< AnyType >(),
		member_state( other.member_state ),
		member_heapArray(),
		member_size( other.member_size )
		{

			// Check if the other instance is ready
			if ( other.member_state.Get() == InstanceState::Ready )
			{
				// The other instance is ready

				// Allocate the memory space for the heap array
				member_heapArray = new Type[ other.member_size ];

				// Copy the content of the other array to this array
				Memory::Operations::Copy< AnyType >( other.member_heapArray, member_heapArray, other.member_size );
			}

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
		template< typename AnyType >
		inline void HeapArray< AnyType >::Swap( HeapArray< AnyType >& other )
		{
		    // Swap betwen the state instances
		    member_state.Swap( other.member_state );

		    // Swap between the arrays
		    Memory::Operations::Swap< Type* >( member_heapArray, other.member_heapArray );

		    // Swap between the sizes
		    Memory::Operations::Swap< UnsignedInteger64bits >( member_size, other.member_size );
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
		//			1. size - the number of entries in the array
		//			2. instance - a reference to the instance that will be used to Initialize all the entries of the array
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
		//		1. The given size is larger then 0
		//		2. 
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename AnyType >
		inline void HeapArray< AnyType >::Initiate( UnsignedInteger64bits size, const AnyType& instance )
		{
		    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
		    // leave this scope it will delete the old data
		    HeapArray< AnyType > temporary( size, instance );

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
        //          2. rangeForSize - this will be used to limit the possible size of the random instance
        //          3. argumentsNeededToGenerateRandomInstanceOfDataType - any arguments needed to create a random instance of the data type
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
        template< typename AnyType >
        template< typename... ArgumentsTypesNeededToGenerateRandomInstanceOfDataType >
        inline void HeapArray< AnyType >::Initiate( RandomInstance, NumericRange< UnsignedInteger64bits > rangeForSize, ArgumentsTypesNeededToGenerateRandomInstanceOfDataType... argumentsNeededToGenerateRandomInstanceOfDataType )
        {
            // Use the required constructor to create an instance. It will be swaped with this instance, leaving this instance with the new data. When sequence control will
            // leave this scope it delete the old data if exist
            SelfType randomGeneratedInstance( GenerateRandomInstance, rangeForSize, argumentsNeededToGenerateRandomInstanceOfDataType... );

            // Swap between this instance and the temporary instance
            Swap( randomGeneratedInstance );
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
		template< typename AnyType >
		inline HeapArray< AnyType >::~HeapArray()
		{
		    // Check if the object is in default state, then noting needs to be done
		    ReturnIfExpressionIsTrue_MACRO( member_state.Get() == InstanceState::Default )

		    // Delete the memory space allocated for the array
		    delete[] member_heapArray;
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to set the memory space with a specific instance
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. sizeToSet - the memory space size that needs to be set
		//			2. setStartingAtThisIndex - the index of the first entry that should be set
		//			3. instance - a constant reference to an instance that will be used to set all the required memory space
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
		//		1. The heap array instance should be ready
		//		2. The given index plus the size should be smaller then the heap array size
		//		3. The size to set should be larger then 0
		//		4. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename AnyType >
		void HeapArray< AnyType >::Set( UnsignedInteger64bits sizeToSet, UnsignedInteger64bits setStartingAtThisIndex, const AnyType& instance )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
            AssertThisInstanceIsReady_MACRO
            Assert_MACRO( ( ( setStartingAtThisIndex + sizeToSet ) <= member_size ), "The sum of the given starting index and size should be smaller or equal to the current size" );
            AssertSizeIsLargerThenZero_MACRO( sizeToSet );

			// Set all the entries to the required instance
			Memory::Operations::Set< AnyType >( ( member_heapArray + setStartingAtThisIndex ), sizeToSet, instance );
		}


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to get an instance with only part of the current instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. partStartingIndex - the starting index from which the part instance will start
        //			2. partSize - the size of the part instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      An instance with only the required part from this instance
        //
        //  Expectations :
        //
        //      1. The given part starting index is smaller then the instance size
        //      2. The given part starting index and size is smaller or equal to the size of the instance
        //      3. The given part size should be larger then 0
        //		4. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename AnyType >
        inline HeapArray< AnyType > HeapArray< AnyType >::Part( UnsignedInteger64bits partStartingIndex, UnsignedInteger64bits partSize ) const
        {
            // Each method that interacts with the user directly needs to ensure that the given data is valid
            AssertSizeIsLargerThenZero_MACRO( partSize );
            Assert_MACRO( ( ( partStartingIndex + partSize ) <= member_size ), "The sum of the given starting index and part size should be smaller or equal to the array size" );
            AssertSizeIsLargerThenZero_MACRO( partSize );

            // Create an instance to store only the required part from the current instance
            HeapArray< AnyType > part( partSize );
            
            // Copy the required part to the new instance
            Memory::Operations::Copy< AnyType >( ( member_heapArray + partStartingIndex ), part.member_heapArray, partSize );

            // Return a copy of the instance with only the required part of this instance
            return ( MOVE( part ) );
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
		//		1. The instance should be ready
		//		2. The given part starting index plus the size must result in a sum smaller or equal to the instance size
		//		3. The given part starting index on the other instance plus the size must result in a sum smaller or equal to the other instance size
        //      4. The part to compare size must be larger then 0
        //		5. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename AnyType >
        inline Boolean HeapArray< AnyType >::Compare( const AccessDataUsingIndices_Interface< AnyType >& other, UnsignedInteger64bits sizeToCompare, UnsignedInteger64bits startingIndexInThisInstance, UnsignedInteger64bits startingIndexInOtherInstance ) const
        {
            // Each method that interacts with the user directly needs to ensure that the given data is valid
            AssertThisInstanceIsReady_MACRO
            Assert_MACRO( ( ( startingIndexInThisInstance + sizeToCompare ) <= member_size ), "The sum of the given starting index on this instance and size to compare should be smaller or equal to the current size" );
            Assert_MACRO( ( ( startingIndexInOtherInstance + sizeToCompare ) <= other.member_size ), "The sum of the given starting index on the other instance and size to compare should be smaller or equal to the current size" );
            AssertSizeIsLargerThenZero_MACRO( sizeToCompare );
            
            // This object will store the index on the other instance
            UnsignedInteger64bits indexOnOtherInstance = startingIndexInOtherInstance;

            // This object will store the index after the last index that needs to be compared
            UnsignedInteger64bits stopAtThisIndex = ( startingIndexInOtherInstance + sizeToCompare );

            // Loop on all the required entries and compare their content
            for ( UnsignedInteger64bits indexOnThisInstance = startingIndexInThisInstance ; indexOnThisInstance < stopAtThisIndex ; ++indexOnThisInstance, ++indexOnOtherInstance )
            {
                // Compare the current entries in both instances
                ReturnValueIfExpressionIsTrue_MACRO( ( member_heapArray[ indexOnThisInstance ] != other[ indexOnOtherInstance ] ), false )
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
        //		NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename AnyType >
        inline UnsignedInteger64bits HeapArray< AnyType >::SizeOfMemorySpaceUsedInBytes() const
        {
            // Calculate the total size used by the instance in bytes, and return the result
            return ( sizeof( HeapArray< AnyType > ) + member_size * sizeof( Type ) );
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
		template< typename AnyType >
		AnyType& HeapArray< AnyType >::operator[]( UnsignedInteger64bits index )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertThisInstanceIsReady_MACRO
			AssertIndexIsBelowCertainLimit_MACRO( index, member_size )
			
			// Return a reference to the required entry
			return ( member_heapArray[ index ] );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to get a copy of the value inside the required entry
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
		template< typename AnyType >
		const AnyType& HeapArray< AnyType >::operator[]( UnsignedInteger64bits index ) const
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertThisInstanceIsReady_MACRO
			AssertIndexIsBelowCertainLimit_MACRO( index, member_size )
			
			// Return a reference to the required entry
			return ( member_heapArray[ index ] );
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
		template< typename AnyType >
		inline Boolean HeapArray< AnyType >::operator==( const HeapArray< AnyType >& other ) const
		{
			// Check if both or only one of the instances is in default state
			CompareInstances_BothInDefaultStateReturnTrue_OnlyOneInDefaultStateReturnFalse_OtherwiseContinue_MACRO
			
			// Check if the instances match, and return the result
			return ( ( member_size == other.member_size ) && Memory::Operations::Compare< AnyType >( member_heapArray, other.member_heapArray, member_size ) );
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
		template< typename AnyType >
		inline Boolean HeapArray< AnyType >::operator!=( const HeapArray< AnyType >& other ) const
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
        //          1. rangeForSize - this will be used to limit the possible size of the random instance
        //          2. argumentsNeededToGenerateRandomInstanceOfDataType - any arguments needed to create a random instance of the data type
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
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
        //
		template< typename AnyType >
        template< typename... ArgumentsTypesNeededToGenerateRandomInstanceOfDataType >
        inline HeapArray< AnyType > HeapArray< AnyType >::GenerateRandomInstance( NumericRange< UnsignedInteger64bits > rangeForSize, ArgumentsTypesNeededToGenerateRandomInstanceOfDataType... argumentsNeededToGenerateRandomInstanceOfDataType )
        {
            // Create an instance
            HeapArray< AnyType > randomInstance( Random::Generator::Get< UnsignedInteger64bits >( rangeForSize ), Random::Generator::Get< AnyType >( argumentsNeededToGenerateRandomInstanceOfDataType... ) );

            // Set the entries of the generated instance to random values
            for ( UnsignedInteger64bits arrayIndex = 0UL ; arrayIndex < randomInstance.Size() ; ++arrayIndex )
            {
                // Set the current entry to a random value
                randomInstance[ arrayIndex ] = Random::Generator::Get< AnyType >( argumentsNeededToGenerateRandomInstanceOfDataType... );
            }

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
			template< typename AnyType >
			void HeapArray< AnyType >::Test()
			{
                // Perform a sanity to ensure that all the methods that are common among all objects, for example defualt constructor, copy constructor,
                // destructor, swap and more, seem to work correctly
                Testing::SanityCheck::Full< HeapArray< AnyType > COMMA UnsignedInteger64bits COMMA const AnyType& >( 10UL );

                // Create an instance of the object using the default constructor
                HeapArray< SignedInteger32bits > testHeapArray_1;

                // Check that it is really in default state
                Assert_MACRO( ( testHeapArray_1.State().Get() == InstanceState::Default ), "Test failed - 1" );

                // Create an instnace of the object using the parameterized constructor
                HeapArray< SignedInteger32bits > testHeapArray_2( 67, 0 );

                // Check the size of the array
                Assert_MACRO( ( 67 == testHeapArray_2.Size() ), "Test failed - 2" );            

                // Create an instnace of the object using the parameterized constructor
                HeapArray< SignedInteger32bits > testHeapArray_3( 67, 77 );

                // Check the size of the array
                Assert_MACRO( ( 67 == testHeapArray_3.Size() ) && ( testHeapArray_3[45] == 77 ), "Test failed - 3" );            

                // Create an instance using the copy constructor
                HeapArray< SignedInteger32bits > testHeapArray_4( testHeapArray_3 );

                // Check that the 2 instnaces are the same
                Assert_MACRO( ( testHeapArray_3 == testHeapArray_4 ), "Test failed - 4" );            

                // A write operation is performed, to check that the object uses the copy on write method before
                testHeapArray_4[5] += 1;

                // Check that the 2 instnaces are not the same
                Assert_MACRO( ( testHeapArray_3 != testHeapArray_4 ), "Test failed - 5" );                                              

                // Check if the addition works
                Assert_MACRO( ( 80 == ( testHeapArray_4[5] + 2 ) ), "Test failed - 6" );

                HeapArray< HeapArray< UnsignedInteger64bits > > testHeapArray_5( 2UL, HeapArray< UnsignedInteger64bits >( 2UL, 55 ) );

                // Create an instnace of the object using the parameterized constructor
                HeapArray< Testing::TestObject_1< UnsignedInteger64bits > > testHeapArray_6( 2, Testing::TestObject_1< UnsignedInteger64bits >( 5, 89 ) ); 

                // Test the generate random instance method
                HeapArray< SignedInteger32bits >::GenerateRandomInstance( NumericRange( 456UL, 8796UL ) );
                HeapArray< SignedInteger32bits >::GenerateRandomInstance( NumericRange( 456UL, 8796UL ), NumericRange( 45, 67 ) );

                HeapArray< SignedInteger32bits > testArray_7 = MOVE( testHeapArray_4.Part( 7UL, 12 ) );
			}

		)  //  End of debug tool











    }  //  Namespace Memory

}  //  Namespace Universe



#endif  // HEAPARRAY_HPP