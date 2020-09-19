#ifndef DYNAMICHEAPARRAY_HPP
#define DYNAMICHEAPARRAY_HPP


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

    namespace Memory
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
		template< typename Type >
		class DynamicHeapArray : public AccessDataUsingIndices_Interface< Type >
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
			inline DynamicHeapArray();


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
			explicit inline DynamicHeapArray( UnsignedInteger64bits size, const Type& instance = PerformActionAccordingToType::GetDefaultInstance< Type >() );


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
			//				1. size - the number of entries in the array
			//				2. instance - a reference to the instance that will be used to Initialize all the entries of the array
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
			explicit inline DynamicHeapArray( const Tuple< UnsignedInteger64bits, const Type& >& arguments );


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
	        //          other - a constant reference to an instance of an object that implements the required access data using indices interface
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
	        //      1. The given dynamic array instance is ready 
	        //      2. The given dynamic array instance size should be larger then 0
	        //      3. 
	        //
	        //  Possible errors :
	        //
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
	        //
	        explicit inline DynamicHeapArray( const AccessDataUsingIndices_Interface< Type >& other );


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
			inline DynamicHeapArray( const DynamicHeapArray< Type >& other );


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
			ObjectInfrastructure_ForInheritance_MACRO( DynamicHeapArray< Type > )


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
			inline void Swap( DynamicHeapArray< Type >& other );


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
			//		2. The given maximum capcity is larger or equal to the size
			//		3. 
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			inline void Initiate( UnsignedInteger64bits size, const Type& instance = PerformActionAccordingToType::GetDefaultInstance< Type >() );


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
	        //          other - a constant reference to an instance of an object that implements the required access data using indices interface
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
	        //      1. The given dynamic array instance is ready 
	        //      2. The given dynamic array instance size should be larger then 0
	        //      3. 
	        //
	        //  Possible errors :
	        //
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			inline void Initiate( const AccessDataUsingIndices_Interface< Type >& other );


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
			virtual ~DynamicHeapArray();


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
			//		1. The dynamic array instance should be ready
			//		2. The given index plus the size should be smaller then the dynamic array size
			//		3. The size to set should be larger then 0
			//		4. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			void Set( UnsignedInteger64bits sizeToSet, UnsignedInteger64bits setStartingAtThisIndex = 0UL, const Type& instance = PerformActionAccordingToType::GetDefaultInstance< Type >() );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to add data to the dynamic array. The data will be added at the provided index, which means that after the
			//		addition accessing the data with the given index will return the currently added data, furthermore the data currently represented
			//		by the index will be advanced one index up, as well as all the rest of the data above the index
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. addTheDataAtThisIndex - the index in which the data should be added in the dynamic array instance
			//			2. dataToAdd - a constant reference to the data to add
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
			//		1. The dynamic array instance should be ready
			//		2. The given index should be smaller or equal to the dynamic array size
			//		3. 
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			inline void AddData( UnsignedInteger64bits addTheDataAtThisIndex, const Type& dataToAdd );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to add data to the dynamic array. The data will be added starting from the provided index
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. addTheDataStartingAtThisIndex - add the data starting from this index
			//			2. dataToAdd - a constant reference to an instance of an object that implements the required access data using indices interface
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
			//		1. The dynamic array instance should be ready
			//		2. The given index should be smaller or equal to the dynamic array size
			//		3. The dynamic array given by the reference should be ready
			//		4. The dynamic array given by the reference should have a size larger then 0
			//		5. 
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			inline void AddData( UnsignedInteger64bits addTheDataStartingAtThisIndex, const AccessDataUsingIndices_Interface< Type >& dataToAdd );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to remove data from the dynamic array. The data will be added at the provided index, which means that after 
			//		the removal the data currently represented by the index plus one will be drawn back one index down, as well as all the rest of 
			//		the data above the index
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. indexOfFirstDataToRemove - the first index from which data should be removed from the dynamic array instance
			//			2. sizeToRemove - the number of entries to remove from the dynamic array
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
			//		1. The instance should be ready
			//		2. The given index to the remove the data plus the size to remove must result in a sum smaller or equal to the instance size
			//		3. 
			//
			//  Possible errors :
			//
			//		NONE
			//
			inline void RemoveData( UnsignedInteger64bits indexOfFirstDataToRemove, UnsignedInteger64bits sizeToRemove );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to reserve memory space at the dynamic array. This method will allocate memory space in advance, without
			//		the need for the actual data, and then the data can just be set into the allocated memory when needed
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. reserveStartingFromThisIndex - the first index from which memory space should be reserved at the dynamic array instance
			//			2. sizeToReserve - the number of entries to reserve
			//			3. instance - a constant reference to an instance that will be used to initialize all the reserved memory space
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
			//		1. The instance should be ready
			//		2. The given index should be smaller or equal to the dynamic array size
			//		3. The size to reserve should be larger then 0
			//		4.  
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			void Reserve( UnsignedInteger64bits reserveStartingFromThisIndex, UnsignedInteger64bits sizeToReserve, const Type& instance = PerformActionAccordingToType::GetDefaultInstance< Type >() );


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
			//		1. The instance should be ready
			//		2. The given part starting index plus the size must result in a sum smaller or equal to the instance size
	        //      3. The part size must be larger then 0
	        //		4. 
	        //
	        //  Possible errors :
	        //
	        //      They will come
	        //
	        inline DynamicHeapArray< Type > Part( UnsignedInteger64bits partStartingIndex, UnsignedInteger64bits partSize ) const;


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
	        //			2. sizeToCompare - the size of the instance that needs to be compared
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
	        inline Boolean Compare( const AccessDataUsingIndices_Interface< Type >& other, UnsignedInteger64bits sizeToCompare, UnsignedInteger64bits startingIndexInThisInstance = 0UL, UnsignedInteger64bits startingIndexInOtherInstance = 0UL ) const;


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
			virtual Type& operator[]( UnsignedInteger64bits index ) override;


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
			virtual const Type& operator[]( UnsignedInteger64bits index ) const override;


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
			inline Boolean operator==( const DynamicHeapArray< Type >& other ) const;


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
			inline Boolean operator!=( const DynamicHeapArray< Type >& other ) const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this operator to add the content of another instance to the end of this instance
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			data - a reference to the instance that should be concatenated to the end of this instance
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
			//		1. The instance should be ready
			//		2. The data instance should be ready
			//		3. 
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			inline AccessDataUsingIndices_Interface< Type >& operator+=( const AccessDataUsingIndices_Interface< Type >& data );


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
	        static inline DynamicHeapArray< Type > GenerateRandomInstance( NumericRange< UnsignedInteger64bits > rangeForSize = NumericRange< UnsignedInteger64bits >( 1UL, 10000UL ), ArgumentsTypesNeededToGenerateRandomInstanceOfDataType... argumentsNeededToGenerateRandomInstanceOfDataType );


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
 			Type* member_dynamicArray;

 			// This object will store the size of the array
 			UnsignedInteger64bits member_size;


			// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
			// rather help implement it :


			// Method Information :
			//
			//  Description :
			//
	        //		Use this method to allocate a larger memory space, according to the required size to add, and copy the current data into it, leaving
	        //		a new free memory space to be used 
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. addMemorySpaceStartingFromThisIndex - the first index from which memory space should be added to the dynamic array instance
			//			2. moreSizeToAllocate - the number of entries needed to be added
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
			//		1. The given index should be smaller or equal to the dynamic array size
			//		2. 
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			inline void AllocateLargerMemorySpaceAndCopyTheCurrentDataToTheNewLocation__Private( UnsignedInteger64bits addMemorySpaceStartingFromThisIndex, UnsignedInteger64bits moreSizeToAllocate );


		};  //  Class DynamicHeapArray




































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
		template< typename Type >
		inline DynamicHeapArray< Type >::DynamicHeapArray() :
        AccessDataUsingIndices_Interface< Type >(),
		member_state(),
		member_dynamicArray( 0UL ),
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
		//			2. instance - a reference to the instance that will be used to initialize all the entries of the array
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
		template< typename Type >
		inline DynamicHeapArray< Type >::DynamicHeapArray( UnsignedInteger64bits size, const Type& instance ) :
        AccessDataUsingIndices_Interface< Type >(),
		member_state( InstanceState::Ready ),
		member_dynamicArray( new Type[ size ] ),
		member_size( size )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertSizeIsLargerThenZero_MACRO( size )

			// Set all the entries to the required instance
			Memory::Operations::Set< Type >( member_dynamicArray, size, instance );
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
		//				1. size - the number of entries in the array
		//				2. instance - a reference to the instance that will be used to Initialize all the entries of the array
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
		template< typename Type >
		inline DynamicHeapArray< Type >::DynamicHeapArray( const Tuple< UnsignedInteger64bits, const Type& >& arguments ) :
		DynamicHeapArray( arguments.template Entry< 0 >(), arguments.template Entry< 1 >() )
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
        //          other - a constant reference to an instance of an object that implements the required access data using indices interface
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
        //      1. The given dynamic array instance is ready 
        //      2. The given dynamic array instance size should be larger then 0
        //      3. 
        //
        //  Possible errors :
        //
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
        //
        template< typename Type >
        inline DynamicHeapArray< Type >::DynamicHeapArray( const AccessDataUsingIndices_Interface< Type >& other ) :
        AccessDataUsingIndices_Interface< Type >(),
        member_state( InstanceState::Ready ),
        member_dynamicArray( new Type[ other.Size() ] ),
        member_size( other.Size() )
        {
			// Each method that interacts with the user directly needs to ensure that the given data is valid
            AssertSizeIsLargerThenZero_MACRO( other.Size() )
            
            // Loop on all the entries of the other dynamic array
            for ( UnsignedInteger64bits otherSequentialPlatformIndex = 0UL ; otherSequentialPlatformIndex < other.Size() ; ++otherSequentialPlatformIndex )
            {
                // Copy the current entry from the other dynamic array to this instance
                member_dynamicArray[ otherSequentialPlatformIndex ] = other[ otherSequentialPlatformIndex ];
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
		template< typename Type >
		inline DynamicHeapArray< Type >::DynamicHeapArray( const DynamicHeapArray< Type >& other ) :
        AccessDataUsingIndices_Interface< Type >(),
		member_state( other.member_state ),
		member_dynamicArray(),
		member_size( other.member_size )
		{

			// Check if the other instance is ready
			if ( other.member_state.Get() == InstanceState::Ready )
			{
				// The other instance is ready

				// Allocate the memory space for the dynamic array
				member_dynamicArray = new Type[ other.member_size ];

				// Copy the content of the other array to this array
				Memory::Operations::Copy< Type >( other.member_dynamicArray, member_dynamicArray, other.member_size );
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
		template< typename Type >
		inline void DynamicHeapArray< Type >::Swap( DynamicHeapArray< Type >& other )
		{
		    // Swap betwen the state instances
		    member_state.Swap( other.member_state );

		    // Swap between the arrays
		    Memory::Operations::Swap< Type* >( member_dynamicArray, other.member_dynamicArray );

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
		//		2. The given maximum capcity is larger or equal to the size
		//		3. 
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename Type >
		inline void DynamicHeapArray< Type >::Initiate( UnsignedInteger64bits size, const Type& instance )
		{
		    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
		    // leave this scope it will delete the old data
		    DynamicHeapArray< Type > temporary( size, instance );

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
        //          other - a constant reference to an instance of an object that implements the required access data using indices interface
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
        //      1. The given dynamic array instance is ready 
        //      2. The given dynamic array instance size should be larger then 0
        //      3. 
        //
        //  Possible errors :
        //
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename Type >
		inline void DynamicHeapArray< Type >::Initiate( const AccessDataUsingIndices_Interface< Type >& other )
		{
		    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
		    // leave this scope it will delete the old data
		    DynamicHeapArray< Type > temporary( other );

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
		template< typename Type >
		inline DynamicHeapArray< Type >::~DynamicHeapArray()
		{
		    // Check if the object is in default state, then noting needs to be done
		    ReturnIfExpressionIsTrue_MACRO( member_state.Get() == InstanceState::Default )

		    // Delete the memory space allocated for the array
		    delete[] member_dynamicArray;
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
		//		1. The dynamic array instance should be ready
		//		2. The given index plus the size should be smaller then the dynamic array size
		//		3. The size to set should be larger then 0
		//		4. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename Type >
		void DynamicHeapArray< Type >::Set( UnsignedInteger64bits sizeToSet, UnsignedInteger64bits setStartingAtThisIndex, const Type& instance )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
            AssertThisInstanceIsReady_MACRO
            Assert_MACRO( ( ( setStartingAtThisIndex + sizeToSet ) <= member_size ), "The sum of the given starting index and size should be smaller or equal to the current size" );
            AssertSizeIsLargerThenZero_MACRO( sizeToSet );

			// Set all the entries to the required instance
			Memory::Operations::Set< Type >( ( member_dynamicArray + setStartingAtThisIndex ), sizeToSet, instance );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to add data to the dynamic array. The data will be added at the provided index, which means that after the
		//		addition accessing the data with the given index will return the currently added data, furthermore the data currently represented
		//		by the index will be advanced one index up, as well as all the rest of the data above the index
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. addTheDataAtThisIndex - the index in which the data should be added in the dynamic array instance
		//			2. dataToAdd - a constant reference to the data to add
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
		//		1. The dynamic array instance should be ready
		//		2. The given index should be smaller or equal to the dynamic array size
		//		3. 
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename Type >
		void DynamicHeapArray< Type >::AddData( UnsignedInteger64bits addTheDataAtThisIndex, const Type& dataToAdd )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
            AssertIndexIsEqualOrBelowCertainLimit_MACRO( addTheDataAtThisIndex, member_size )

            // Allocate a larger array to contain the additional data, and move the existing data into it
			AllocateLargerMemorySpaceAndCopyTheCurrentDataToTheNewLocation__Private( addTheDataAtThisIndex, 1UL );

        	// Set the entry with the new data
        	member_dynamicArray[ addTheDataAtThisIndex ] = dataToAdd;
   		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to add data to the dynamic array. The data will be added starting from the provided index
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. addTheDataStartingAtThisIndex - add the data starting from this index
		//			2. dataToAdd - a constant reference to an instance of an object that implements the required access data using indices interface
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
		//		1. The dynamic array instance should be ready
		//		2. The given index should be smaller or equal to the dynamic array size
		//		3. The dynamic array given by the reference should be ready
		//		4. The dynamic array given by the reference should have a size larger then 0
		//		5. 
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename Type >
		void DynamicHeapArray< Type >::AddData( UnsignedInteger64bits addTheDataStartingAtThisIndex, const AccessDataUsingIndices_Interface< Type >& dataToAdd )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
            AssertIndexIsEqualOrBelowCertainLimit_MACRO( addTheDataStartingAtThisIndex, member_size )
            AssertInstanceIsReady_MACRO( dataToAdd )
            AssertInstanceSizeIsLargerThenZero_MACRO( dataToAdd )

            // Allocate a larger array to contain the additional data, and move the existing data into it
			AllocateLargerMemorySpaceAndCopyTheCurrentDataToTheNewLocation__Private( addTheDataStartingAtThisIndex, dataToAdd.Size() );

			// This object will store the last index that needs to be set to end the loop
			UnsignedInteger64bits lastIndexToSet = addTheDataStartingAtThisIndex + dataToAdd.Size();

        	// Loop on the data to add, and set all the entries into this instance
        	for ( UnsignedInteger64bits dataToSetIndex = addTheDataStartingAtThisIndex ; dataToSetIndex < lastIndexToSet ; ++dataToSetIndex )
        	{
        		// Set the current entry
        		member_dynamicArray[ dataToSetIndex ] = dataToAdd[ dataToSetIndex ];
        	}

		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to remove data from the dynamic array. The data will be added at the provided index, which means that after 
		//		the removal the data currently represented by the index plus one will be drawn back one index down, as well as all the rest of 
		//		the data above the index
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. indexOfFirstDataToRemove - the first index from which data should be removed from the dynamic array instance
		//			2. sizeToRemove - the number of entries to remove from the dynamic array
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
		//		1. The instance should be ready
		//		2. The given index to the remove the data plus the size to remove must result in a sum smaller or equal to the instance size
		//		3. 
		//
		//  Possible errors :
		//
		//		NONE
		//
		template< typename Type >
		void DynamicHeapArray< Type >::RemoveData( UnsignedInteger64bits indexOfFirstDataToRemove, UnsignedInteger64bits sizeToRemove )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertThisInstanceIsReady_MACRO
            Assert_MACRO( ( ( indexOfFirstDataToRemove + sizeToRemove ) <= member_size ), "The sum of the given starting index and size to remove should be smaller or equal to the current size" );

            // Check if the size of the current instance is the same as the size that should be removed
            if ( member_size == sizeToRemove )
            {
            	// The current size is the same as the size that needs to be removed

            	// Reset the instance
            	Reset();

            	// Nothing else needs to be done
            	return;
            }

            // Allocate a larger array to contain the additional data
            DynamicHeapArray< Type > smallerTemporaryInstanceToContainWithoutTheRemovedData( member_size - sizeToRemove );

            // Now there are 3 options, the first one is that the new data needs to be removed from the beginning of the array, which means that all the 
            // curren data needs to be copied one index down in the new array. The second is that the new data needs to be removed from the end of the array
            // which means that the current data needs to be copied to the same location just minus the last entry. And finally the new data needs to be 
            // removed from the middle, which means that the start of the current data up to the location to remove the data, needs to be copied to the
            // same location, and all the data from there needs be copied one index down, to clear the uneeded entry

            // Check if the data needs to be removed from the beginning of the array
            if ( indexOfFirstDataToRemove == 0UL )
            {
            	// The data needs to be removed from the beginning

            	// Copy the current data one index down into the new array
            	Memory::Operations::Move< Type >( ( member_dynamicArray + sizeToRemove ), smallerTemporaryInstanceToContainWithoutTheRemovedData.member_dynamicArray, ( member_size - sizeToRemove ) );
            }
            else if ( ( indexOfFirstDataToRemove + sizeToRemove ) == member_size )
            {
            	// The data needs to be removed from the end

            	// Copy the current data to the same location in the new array
            	Memory::Operations::Move< Type >( member_dynamicArray, smallerTemporaryInstanceToContainWithoutTheRemovedData.member_dynamicArray, ( member_size - sizeToRemove ) );
            }
            else
            {
            	// The data needs to be removed from the middle of the array

            	// Copy all the entries in the current data before the required index to the same location in the new array
            	Memory::Operations::Move< Type >( member_dynamicArray, smallerTemporaryInstanceToContainWithoutTheRemovedData.member_dynamicArray, indexOfFirstDataToRemove );

            	// Copy all the entries in the current data after the required index after to one index down into the new array 
            	Memory::Operations::Move< Type >( ( member_dynamicArray + indexOfFirstDataToRemove + sizeToRemove ), ( smallerTemporaryInstanceToContainWithoutTheRemovedData.member_dynamicArray + indexOfFirstDataToRemove ), ( member_size - indexOfFirstDataToRemove ) );
            }

            // Swap between this instance and the temporary that stores the data without the removed entries
            Swap( smallerTemporaryInstanceToContainWithoutTheRemovedData );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to reserve memory space at the dynamic array. This method will allocate memory space in advance, without
		//		the need for the actual data, and then the data can just be set into the allocated memory when needed
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. reserveStartingFromThisIndex - the first index from which memory space should be reserved at the dynamic array instance
		//			2. sizeToReserve - the number of entries to reserve
		//			3. instance - a constant reference to an instance that will be used to initialize all the reserved memory space
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
		//		1. The instance should be ready
		//		2. The given index should be smaller or equal to the dynamic array size
		//		3. The size to reserve should be larger then 0
		//		4.  
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename Type >
		void DynamicHeapArray< Type >::Reserve( UnsignedInteger64bits reserveStartingFromThisIndex, UnsignedInteger64bits sizeToReserve, const Type& instance )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertThisInstanceIsReady_MACRO
            AssertIndexIsEqualOrBelowCertainLimit_MACRO( reserveStartingFromThisIndex, member_size )
            AssertSizeIsLargerThenZero_MACRO( sizeToReserve )

            // Allocate a larger array to contain the additional data, and move the existing data into it
			AllocateLargerMemorySpaceAndCopyTheCurrentDataToTheNewLocation__Private( reserveStartingFromThisIndex, sizeToReserve );

			// Set all the entries with the given instance
			Set( reserveStartingFromThisIndex, sizeToReserve, instance );
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
		//		1. The instance should be ready
		//		2. The given part starting index plus the size must result in a sum smaller or equal to the instance size
        //      3. The part size must be larger then 0
        //		4. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename Type >
        inline DynamicHeapArray< Type > DynamicHeapArray< Type >::Part( UnsignedInteger64bits partStartingIndex, UnsignedInteger64bits partSize ) const
        {
            // Each method that interacts with the user directly needs to ensure that the given data is valid
            AssertThisInstanceIsReady_MACRO
            Assert_MACRO( ( ( partStartingIndex + partSize ) <= member_size ), "The sum of the given starting index and size should be smaller or equal to the current size" );
            AssertSizeIsLargerThenZero_MACRO( partSize );

            // Create an instance to store only the required part from the current instance
            DynamicHeapArray< Type > part( partSize );
            
            // Copy the required part to the new instance
            Memory::Operations::Copy< Type >( ( member_dynamicArray + partStartingIndex ), part.member_dynamicArray, partSize );

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
        //			2. sizeToCompare - the size of the instance that needs to be compared
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
        template< typename Type >
        inline Boolean DynamicHeapArray< Type >::Compare( const AccessDataUsingIndices_Interface< Type >& other, UnsignedInteger64bits sizeToCompare, UnsignedInteger64bits startingIndexInThisInstance, UnsignedInteger64bits startingIndexInOtherInstance ) const
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
                ReturnValueIfExpressionIsTrue_MACRO( ( member_dynamicArray[ indexOnThisInstance ] != other[ indexOnOtherInstance ] ), false )
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
        template< typename Type >
        inline UnsignedInteger64bits DynamicHeapArray< Type >::SizeOfMemorySpaceUsedInBytes() const
        {
            // Calculate the total size used by the instance in bytes, and return the result
            return ( sizeof( DynamicHeapArray< Type > ) + member_size * sizeof( Type ) );
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
		template< typename Type >
		Type& DynamicHeapArray< Type >::operator[]( UnsignedInteger64bits index )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertThisInstanceIsReady_MACRO
			AssertIndexIsBelowCertainLimit_MACRO( index, member_size )
			
			// Return a reference to the required entry
			return ( member_dynamicArray[ index ] );
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
		template< typename Type >
		const Type& DynamicHeapArray< Type >::operator[]( UnsignedInteger64bits index ) const
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertThisInstanceIsReady_MACRO
			AssertIndexIsBelowCertainLimit_MACRO( index, member_size )
			
			// Return a reference to the required entry
			return ( member_dynamicArray[ index ] );
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
		template< typename Type >
		inline Boolean DynamicHeapArray< Type >::operator==( const DynamicHeapArray< Type >& other ) const
		{
			// Check if both or only one of the instances is in default state
			CompareInstances_BothInDefaultStateReturnTrue_OnlyOneInDefaultStateReturnFalse_OtherwiseContinue_MACRO
			
			// Check if the instances match, and return the result
			return ( ( member_size == other.member_size ) && Memory::Operations::Compare< Type >( member_dynamicArray, other.member_dynamicArray, member_size ) );
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
		template< typename Type >
		inline Boolean DynamicHeapArray< Type >::operator!=( const DynamicHeapArray< Type >& other ) const
		{
			// Return the negotiated value from the equal operator
			return ( !( *this == other ) );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to add the content of another instance to the end of this instance
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			data - a reference to the instance that should be concatenated to the end of this instance
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
		//		1. The instance should be ready
		//		2. The data instance should be ready
		//		3. 
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename Type >
		AccessDataUsingIndices_Interface< Type >& DynamicHeapArray< Type >::operator+=( const AccessDataUsingIndices_Interface< Type >& data )
		{
            // Add the data to the end of this double linked list instance
            AddData( member_size, data );

            // Return a reference to this instance
            return ( *this );
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
		template< typename Type >
        template< typename... ArgumentsTypesNeededToGenerateRandomInstanceOfDataType >
        inline DynamicHeapArray< Type > DynamicHeapArray< Type >::GenerateRandomInstance( NumericRange< UnsignedInteger64bits > rangeForSize, ArgumentsTypesNeededToGenerateRandomInstanceOfDataType... argumentsNeededToGenerateRandomInstanceOfDataType )
        {
        	// This object will store the random generate size
        	UnsignedInteger64bits randomSize = Random::Generator::Get< UnsignedInteger64bits >( rangeForSize );

            // Create an instance
            DynamicHeapArray< Type > randomInstance( randomSize, Random::Generator::Get< Type >( argumentsNeededToGenerateRandomInstanceOfDataType... ), Random::Generator::Get< UnsignedInteger64bits >( NumericRange< UnsignedInteger64bits >( ( randomSize + 1UL ), NumericLimits< UnsignedInteger64bits >::Maximum() ) ) );

            // Set the entries of the generated instance to random values
            for ( UnsignedInteger64bits arrayIndex = 0UL ; arrayIndex < randomInstance.Size() ; ++arrayIndex )
            {
                // Set the current entry to a random value
                randomInstance[ arrayIndex ] = Random::Generator::Get< Type >( argumentsNeededToGenerateRandomInstanceOfDataType... );
            }

            // Return a copy of the instance
            return ( MOVE( randomInstance ) );
        }































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************
































		// Method Information :
		//
		//  Description :
		//
        //		Use this method to allocate a larger memory space, according to the required size to add, and copy the current data into it, leaving
        //		a new free memory space to be used 
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. addMemorySpaceStartingFromThisIndex - the first index from which memory space should be added to the dynamic array instance
		//			2. moreSizeToAllocate - the number of entries needed to be added
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
		//		1. The given index should be smaller or equal to the dynamic array size
		//		2. 
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename Type >
		inline void DynamicHeapArray< Type >::AllocateLargerMemorySpaceAndCopyTheCurrentDataToTheNewLocation__Private( UnsignedInteger64bits addMemorySpaceStartingFromThisIndex, UnsignedInteger64bits moreSizeToAllocate )
		{

            // Check if the size of the instance is 0
            if ( member_size == 0UL )
            {
            	// The size of the instance is 0

            	// Initiate the instance
            	Initiate( moreSizeToAllocate );

            	// Nothing else needs to be done
            	return;
            }

            // Allocate a larger array to contain the additional data
            DynamicHeapArray< Type > largerTemporaryInstanceToContainTheAdditionalData( member_size + moreSizeToAllocate );

            // Now there are 3 options, the first one is that the new data needs to be added at the beginning of the array, which means that all the 
            // curren data needs to be copied one index up in the new array. The second is that the new data needs to be added to the end of the array
            // which means that the current data needs to be copied to the same location. And finally the new data needs to be added to the middle,
            // which means that the start of the current data up to the location to add the new data, needs to be copied to the same location, and all
            // the data from there needs be copied one index up, to clear an entry to store the new data

            // Check if the data needs to be added at the beginning of the array
            if ( addMemorySpaceStartingFromThisIndex == 0UL )
            {
            	// The data needs to be added at the beginning

            	// Copy the current data one index up into the new array
            	Memory::Operations::Move< Type >( member_dynamicArray, ( largerTemporaryInstanceToContainTheAdditionalData.member_dynamicArray + moreSizeToAllocate ), member_size );
            }
            else if ( addMemorySpaceStartingFromThisIndex == member_size )
            {
            	// The data needs to be added at the end

            	// Copy the current data to the same location in the new array
            	Memory::Operations::Move< Type >( member_dynamicArray, largerTemporaryInstanceToContainTheAdditionalData.member_dynamicArray, member_size );
            }
            else
            {
            	// The data needs to be added to the middle of the array

            	// Copy all the entries in the current data before the required index to the same location in the new array
            	Memory::Operations::Move< Type >( member_dynamicArray, largerTemporaryInstanceToContainTheAdditionalData.member_dynamicArray, addMemorySpaceStartingFromThisIndex );

            	// Copy all the entries in the current data after the required index after to one index up into the new array 
            	Memory::Operations::Move< Type >( ( member_dynamicArray + addMemorySpaceStartingFromThisIndex ), ( largerTemporaryInstanceToContainTheAdditionalData.member_dynamicArray + addMemorySpaceStartingFromThisIndex + moreSizeToAllocate ), ( member_size - addMemorySpaceStartingFromThisIndex ) );
            }

            // Swap between this instance and the temporary that stores the new data
            Swap( largerTemporaryInstanceToContainTheAdditionalData );
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
			template< typename Type >
			void DynamicHeapArray< Type >::Test()
			{
				// Perform a sanity to ensure that all the methods that are common among all objects, for example defualt constructor, copy constructor,
				// destructor, swap and more, seem to work correctly
				Testing::SanityCheck::NoParameterizedConstructor< DynamicHeapArray< Type > >( 100UL );

                // Create an instance of the object using the default constructor
                DynamicHeapArray< SignedInteger32bits > testDynamicArray_1;

                // Check that it is really in default state
                Assert_Test_MACRO( testDynamicArray_1.State().Get() == InstanceState::Default )

                // Create an instnace of the object using the parameterized constructor
                DynamicHeapArray< SignedInteger32bits > testDynamicArray_2( 67UL, 0 );

                // Check the size of the array
                Assert_Test_MACRO( testDynamicArray_2.Size() == 67UL )

                // Create an instnace of the object using the parameterized constructor
                DynamicHeapArray< SignedInteger32bits > testDynamicArray_3( 67UL, 77 );

                // Check the size of the array
                Assert_Test_MACRO( ( testDynamicArray_3.Size() == 67UL ) && ( testDynamicArray_3[45] == 77 ) )

                // Create an instance using the copy constructor
                DynamicHeapArray< SignedInteger32bits > testDynamicArray_4( testDynamicArray_3 );

                // Check that the 2 instnaces are the same
                Assert_Test_MACRO( testDynamicArray_3 == testDynamicArray_4 )

                // A write operation is performed, to check that the object uses the copy on write method before
                testDynamicArray_4[5] += 1;

                // Check that the 2 instnaces are not the same
                Assert_Test_MACRO( testDynamicArray_3 != testDynamicArray_4 )

                // Check if the addition works
                Assert_Test_MACRO( ( testDynamicArray_4[5] + 2UL ) == 80 )

                DynamicHeapArray< DynamicHeapArray< UnsignedInteger64bits > > testDynamicArray_5( 2UL, DynamicHeapArray< UnsignedInteger64bits >( 2UL, 55UL ) );

                // Create an instnace of the object using the parameterized constructor
                DynamicHeapArray< Testing::TestObject_1< UnsignedInteger64bits > > testDynamicArray_7( 2, Testing::TestObject_1< UnsignedInteger64bits >( 5UL, 89UL ) ); 

                // Test the generate random instance method
                DynamicHeapArray< SignedInteger32bits >::GenerateRandomInstance( NumericRange( 456UL, 8796UL ) );
                DynamicHeapArray< SignedInteger32bits >::GenerateRandomInstance( NumericRange( 456UL, 8796UL ), NumericRange( 45, 67 ) );

                // Create an instance
                DynamicHeapArray< UnsignedInteger64bits > testDynamicArray_8( 2UL, 55UL );

                // Loop on the instance
                for ( UnsignedInteger64bits index = 0UL ; index < testDynamicArray_8.Size() ; ++index )
                {
                	// Assert that all the entries has the value 55
                	Assert_Test_MACRO( testDynamicArray_8[ index ] == 55UL )
                }

                // Add data
				testDynamicArray_8.AddData( 0UL, 44UL );

            	// Assert that the first entry has the value 44
            	Assert_Test_MACRO( testDynamicArray_8[0] == 44UL )

                // Loop on the instance
                for ( UnsignedInteger64bits index = 1UL ; index < testDynamicArray_8.Size() ; ++index )
                {
                	// Assert that all the entries has the value 55
                	Assert_Test_MACRO( testDynamicArray_8[ index ] == 55UL )
                }

                // Create an instance
                const DynamicHeapArray< UnsignedInteger64bits >& testDynamicArray_9 = testDynamicArray_8.Part( 1UL, 2UL );
			}

		)  //  End of debug tool











    }  //  Namespace Memory

}  //  Namespace Universe



#endif  // DYNAMICHEAPARRAY_HPP