#ifndef SINGLELINKEDLIST_HPP
#define SINGLELINKEDLIST_HPP


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
#include "SingleLinkedListNode/SingleLinkedListNode.hpp"  //  Class SingleLinkedListNode
#include "../../../../../../../../../Content/Metaprogramming/NumericLimits/NumericLimits.hpp"  //  Class NumericLimits
#include "../../../../../../../Content/Interfaces/AccessDataUsingIndices_Interface/WrapSingleInstanceWithAccessDataUsingIndicesInterface/WrapSingleInstanceWithAccessDataUsingIndicesInterface.hpp"  //  Class WrapSingleInstanceWithAccessDataUsingIndicesInterface


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



    	// Constructor of derived object, when called, all the base class constructors are executed first, according to the order they appear in the class 
    	// declaration, and only then the user code is executed
    	//
    	// Destructor of derived object, when it is called, the user code existing in the destructor itself is executed first and then all the destructors 
    	// of the base objects, in an opposite way from which they were constructed



    	// When catching an exception, after performing all the required operations, and even changing the exception instance itself, the exception can be
    	// rethrown to notify the caller of the code of the problem. To throw the same instance use only the keywrod 'throw', to throw new instance use 
    	// the keyword 'throw' with the name of the specific instance to throw



    	// Change default values during run time :
    	//
    	//		class DefaultValueChanger
    	//		{
    	//		public:
    	//
		//			void DisplayDefaultValue( UnsignedInteger64bits newDefaltValue = member_defautValue )
		//			{
		//				std::cout << newDefaltValue << std::cout;
		//			}
		//	
		//			void SetDefaultValue( UnsignedInteger64bits newDefaultValue )
		//			{
    	//				member_defautValue = newDefaultValue;
		//			}
    	//
		//		private:
    	//
		//			static UnsignedInteger64bits member_defautValue;
    	//
		//		};
    	//
		//		UnsignedInteger64bits DefaultValueChanger::member_defautValue = 0UL;
    	//
		//		int main
		//		{
		//			DefaultValueChanger defaultValueChangerInstance;
    	//
		//			defaultValueChangerInstance.DisplayDefaultValue();
    	//
		//			defaultValueChangerInstance.SetDefaultValue( 8UL );
    	//
		//			defaultValueChangerInstance.DisplayDefaultValue();
		//		}
		//
		// A default argument to a function doesn't have to be a constant expression, it just has to be "available" at every place the function is 
		// called. And a static variable is just that. It also doesn't have to be accessible at the call site. So if the class should control that
		// it is possible to make it private



		// Template Class Information :
		//
		//  Purpose :
		//
		//		Use this object to store multiple instances of the same type. The instances will not be stored in contigous memory space, but rather
		//		as seperated nodes connected through pointers. Each node will have a pointer to the next node in the list. This allows making changes
		//		without the needs to copy large amout of contigous memory spaces, in other words changes in this platform cost very little in terms
		//		of performance. This is a single linked list which means the current node only knows about the next node, and therefore passes on this
		//		platform are only in one direction
		//
		//  Description :
		//
		//		1. This object contains an instance of the object "InstnaceState" to allow each instance of this object to have a defined state
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
		class SingleLinkedList : public AccessDataUsingIndices_Interface< AnyType >
		{
		public:


			// Create a type definition for this object
			using SelfType = SingleLinkedList< AnyType >;

			// Create a type definition for the nodes of this object
			using NodeType = SingleLinkedListNode< AnyType >;


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
			inline SingleLinkedList();


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
			//			1. size - the number of entries in the single linked list
			//			2. data - a constant reference to the data that will be used to initialize all the nodes
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
			//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
			//		2. 
			//
			explicit inline SingleLinkedList( UnsignedInteger64bits size, const AnyType& data = PerformActionAccordingToType::GetDefaultInstance< AnyType >() );


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
	        //      1. The given data instance is ready 
	        //      2. The given data instance size should be larger then 0
			//		3. The sum of the starting index plus the size to add from the data must smaller or equal to the data size
			//		4. The size to add should be larger then 0
			//		5. 
			//
			//  Possible errors :
			//
			//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
			//		2. 
			//
			explicit inline SingleLinkedList( const AccessDataUsingIndices_Interface< AnyType >& other, UnsignedInteger64bits sizeFromOtherToAdd, UnsignedInteger64bits startingIndexOnOther = 0UL );


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
	        explicit inline SingleLinkedList( RandomInstance, NumericRange< UnsignedInteger64bits > rangeForSize = NumericRange< UnsignedInteger64bits >( 1UL, 10000UL ), ArgumentsTypesNeededToGenerateRandomInstanceOfDataType... argumentsNeededToGenerateRandomInstanceOfDataType );


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
			//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
			//		2. 
			//
			inline SingleLinkedList( const SelfType& other );


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
			ObjectInfrastructure_ForInheritance_WithStateAlwaysReady_MACRO( SingleLinkedList< AnyType > )


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
			inline void Swap( SelfType& other );


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
			//			1. size - the number of entries in the single linked list
			//			2. data - a constant reference to the data that will be used to initialize all the nodes
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
			inline void Initiate( UnsignedInteger64bits size, const AnyType& data = PerformActionAccordingToType::GetDefaultInstance< AnyType >() );


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
	        inline void Initiate( RandomInstance, NumericRange< UnsignedInteger64bits > rangeForSize = NumericRange< UnsignedInteger64bits >( 1UL, 10000UL ), ArgumentsTypesNeededToGenerateRandomInstanceOfDataType... argumentsNeededToGenerateRandomInstanceOfDataType );


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
			virtual ~SingleLinkedList();


			// This part will contain all the get and set methods for the members of the object :


			// Member - member_size
			GetByValue_DeclaredVirtualAndOverride_MACRO( Size, member_size, UnsignedInteger64bits )


			// The following methods give access and manipulate the data inside this object :


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to set the nodes with a specific data
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. sizeToSet - the number of nodes to set
			//			2. data - a constant reference to the data that will be used to set all the required nodes
			//			3. setStartingAtThisIndex - the index of the first node that should be set
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
			//		1. The single linked list instance should be ready
			//		2. The given index plus the size should be smaller then the single linked list size
			//		3. The size to set should be larger then 0
			//		4. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline void Set( UnsignedInteger64bits sizeToSet, const AnyType& data = PerformActionAccordingToType::GetDefaultInstance< AnyType >(), UnsignedInteger64bits setStartingAtThisIndex = 0UL );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to add a node at the given index. This means that if a node needs to be added at index 2 then :
			//
			//			Currently the singled linked list looks :
			//
			//				--------------	--------------	--------------	--------------	  
			//				| Old Node 0 |	| Old Node 1 |	| Old Node 2 |	| Old Node 3 |	...
			//				--------------	--------------	--------------	--------------  
			//
			//			After the addition :
			//
			//													Added 	  Moved up by 1 index
			//													  |				   |
			//				--------------	--------------	--------------	--------------	--------------	  
			//				| Old Node 0 |	| Old Node 1 |	| New Node 2 |	| Old Node 3 |	| Old Node 4 |	...
			//				--------------	--------------	--------------	--------------	-------------- 
			//
			//		As can be seen all the nodes that exist in the single linked list before the addition, starting from the node with the required index,
			//		will be moved one index up.
			//
			//		Note 1 - if the data should be added to the end of the single linked list, provide as index the current size of the single linked list
			//		Note 2 - if the instance is currently in default state the only index that is allowed to be used with this method is 0
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. data - a reference to the data that a copy of it should be stored in the new node
			//			2. index - the index to insert the new node
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
			//		1. The given index should be smaller or equal to the single linked list size
			//		2. 
			//
			//  Possible errors :
			//
			//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
			//		2. 
			//
			inline void AddData( UnsignedInteger64bits index, const AnyType& data = PerformActionAccordingToType::GetDefaultInstance< AnyType >() );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to add a number of nodes at the given index. This means that if the nodes needs to be added starting at index 2 then :
			//
			//			Currently the singled linked list looks :
			//
			//				--------------	--------------	--------------	--------------	  
			//				| Old Node 0 |	| Old Node 1 |	| Old Node 2 |	| Old Node 3 |	...
			//				--------------	--------------	--------------	--------------  
			//
			//			After the addition :
			//
			//													Added 	  Moved up by 1 index
			//													  |				   |
			//				--------------	--------------	--------------	--------------	--------------	  
			//				| Old Node 0 |	| Old Node 1 |	| New Node 2 |	| Old Node 3 |	| Old Node 4 |	...
			//				--------------	--------------	--------------	--------------	-------------- 
			//
			//		As can be seen all the nodes that exist in the single linked list before the addition, starting from the node with the required index,
			//		will be moved one index up.
			//
			//		Note 1 - if the data should be added to the end of the single linked list, provide as index the current size of the single linked list
			//		Note 2 - if the instance is currently in default state the only index that is allowed to be used with this method is 0
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. data - a constant reference to an instance of an object that implements the required access data using indices interface
			//			2. sizeFromDataToAdd - the size of the data to add
			//			3. indexInThisInstance - the index to insert the new nodes in this instance
			//			4. startingIndexOnData - the index on the data from which to add it to this instance
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
			//		1. The given index should be smaller or equal to the single linked list size
			//		2. The data size should be larger then 0
			//		3. The sum of the starting index plus the size to add from the data must smaller or equal to the data size
			//		4. 
			//
			//  Possible errors :
			//
			//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
			//		2. 
			//
			inline void AddData( const AccessDataUsingIndices_Interface< AnyType >& data, UnsignedInteger64bits sizeFromDataToAdd = NumericLimits< UnsignedInteger64bits >::Maximum(), UnsignedInteger64bits indexInThisInstance = 0UL, UnsignedInteger64bits startingIndexOnData = 0UL );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to remove number of nodes starting at the given index. This means that if the nodes needs to be removed starting at index 2 then :
			//
			//			Currently the singled linked list looks :
			//
			//				--------------	--------------	--------------	--------------	  
			//				| Old Node 0 |	| Old Node 1 |	| Old Node 2 |	| Old Node 3 |	...
			//				--------------	--------------	--------------	--------------  
			//
			//			After the remove :
			//
			//											 Moved down by 1 index
			//													   |
			//				--------------	--------------	--------------	  
			//				| Old Node 0 |	| Old Node 1 |	| Old Node 2 |	...
			//				--------------	--------------	-------------- 
			//
			//		As can be seen all the nodes that exist in the single linked list before the removal, starting from the last node to be removed index, will be 
			//		moved one index down.
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			indexOfFirstDataToRemove - the index of the first data to remove
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
			//		2. The given index is smaller then the single linked list size
			//		3. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline void RemoveData( UnsignedInteger64bits sizeToRemove, UnsignedInteger64bits indexOfFirstDataToRemove = 0UL );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to reserve memory space at the single linked list. This method will allocate memory space in advance, without
			//		the need for the actual data, and then the data can just be set into the allocated memory when needed
			//
			//		Note 1 - if the data should be added to the end of the single linked list, provide as index the current size of the single linked list
			//		Note 2 - if the instance is currently in default state the only index that is allowed to be used with this method is 0
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. sizeToReserve - the number of entries to reserve
			//			2. data - a constant reference to the data that will be used to initialize all the reserved memory space
			//			3. reserveStartingFromThisIndex - the first index from which memory space should be reserved at the single linked list instance
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
			//		1. The given index should be smaller or equal to the single linked list size
			//		2. The size to reserve should be larger then 0
			//		3.  
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			inline void Reserve( UnsignedInteger64bits sizeToReserve, const AnyType& data = PerformActionAccordingToType::GetDefaultInstance< AnyType >(), UnsignedInteger64bits reserveStartingFromThisIndex = 0UL );


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
	        //		1. The single linked list instance should be ready
	        //		3. The other instance should be ready
	        //      4. The sum of the given starting index and size to compare is smaller or equal to the size of the this instance
	        //      5. The sum of the given starting index and size to compare is smaller or equal to the size of the other instance
	        //      6. The size to compare should be larger then 0
	        //		7. 
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
			//      Use this operator to get a reference to the required data
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			index - the index of the required data
			//
			//      Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		A reference to the required data
			//
			//  Expectations :
			//
			//		1. The instance should be ready
			//		2. The given index is smaller then the single linked list size
			//		3. 
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
			//      Use this operator to get a constant reference to the required data
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			index - the index of the required data
			//
			//      Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
	        //      A constant reference to the required data
			//
			//  Expectations :
			//
			//		1. The instance should be ready
			//		2. The given index is smaller then the single linked list size
			//		3. 
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
			//			other - a constnt reference to a single linekd list
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
			inline Boolean operator==( const AccessDataUsingIndices_Interface< AnyType >& other ) const;


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
			inline Boolean operator!=( const AccessDataUsingIndices_Interface< AnyType >& other ) const;


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
			//			other - a reference to a single linekd list to concatenate to the end of this instance
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
			//		2. The single linekd list should be ready
			//		3. The single linekd list size should be larger then 0
			//		4. 
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			inline SelfType& operator+=( const AccessDataUsingIndices_Interface< AnyType >& other );


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
				static inline void Test() __attribute__ (( __unused__ ));

			// )  //  End of debug tool


		private:


 			// This object will store the memory address of the first node in the single linked list
 			mutable NodeType member_singleLinkedListRoot;

 			// This object will store the number of nodes in the single linked list
 			UnsignedInteger64bits member_size;

 			// The following data members are added to make specific optimizations. The first one is to store the memory address of the last node, to allow 
 			// adding a node to the end of the single linked list without passing on all the nodes for it. The second and third are used to store the memory
 			// address and index of the last used node. This will allow first of all another starting point beside the beginning of the single linked list
 			// to find specific nodes, furthermore, it will allow passing on all the nodes, without starting each time from the root :

 			// This object will store the memory address of the last node in the single linked list instance
 			NodeType* member_singleLinkedListLastNode;

 			// This object will store the most recent used node used in the single linked list
 			mutable NodeType* member_lastUsedNode;

 			// This object will store the index of the last used node
 			mutable UnsignedInteger64bits member_lastUsedNodeIndex;


			// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
			// rather help implement it :


			// Method Information :
			//
			//  Description :
			//
	        //		Use this method to allocate more nodes, according to the size given, connect between them and set it into the required location
	        //		in the instance represented by the index. The last used node pointer will be set to the memory address of the first new node
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. numberOfNodesToAllocate - the number of nodes that needs to be added
			//			2. addNodesStartingFromThisIndex - the first index from which nodes should be added to the single linked list instance
			//			3. data - a constant reference to an instance of an object that implements the required access data using indices interface
			//			4. startingIndexOnData - the index on the data from which to add it to this instance
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
			//		1. The given index should be smaller or equal to the single linked list size
			//		2. The given number of nodes to allocate should be larger then 0
			//		3. 
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			inline void AllocateMoreNodesAndAddThemToTheRequiredLocation__Private( UnsignedInteger64bits numberOfNodesToAllocate, UnsignedInteger64bits addNodesStartingFromThisIndex, const AccessDataUsingIndices_Interface< AnyType >& data, UnsignedInteger64bits startingIndexOnData = 0UL );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to allocate nodes, attach them together, and return a tuple with the memory address of the first and last nodes
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. numberOfNodesToAllocate - the number of nodes to allocate
			//			2. data - a constant reference to an instance of an object that implements the required access data using indices interface
			//			3. startingIndexOnData - the index on the data from which to add it to this instance
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		A tuple with the memory address of the first and last nodes allocated
			//
			//  Expectations :
			//
			//		1. The number of nodes to allocate must be larger then 0
			//		2. 
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			inline Tuple< NodeType*, NodeType* > AllocateStringOfNodes__Private( UnsignedInteger64bits numberOfNodesToAllocate, const AccessDataUsingIndices_Interface< AnyType >& data, UnsignedInteger64bits startingIndexOnData = 0UL );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to delete all the node from the single linked list
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			firstNodeToDelete - the memory address of the first node to delete
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
			//		1. The given pointer is not NULL
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline void DeleteNodes__Private( NodeType* firstNodeToDelete );


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get the memory address of a specific node. The method will check if the shortest path to the required node is from
			//		the beginning or from the last used node, and take that path
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			index - the index of the required node
			//
			//      Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
	        //      The memory address of the required node
			//
			//  Expectations :
			//
			//		1. The given index is smaller then the single linked list size
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline NodeType* TakeShortestPathToNodeAndReturnTheMemoryAddress__Private( UnsignedInteger64bits index ) const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get the memory address of a specific node. The method starts from the given node, and advances on the list the 
			//		required amount of nodes to the required node
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			1. node - the memory address of the node to start from
			//			2. numberOfNodesToTargetNode - the number of nodes that the required node is away from the given node
			//
			//      Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		The memory address of the required node
			//
			//  Expectations :
			//
			//		1. The given pointer is not NULL
			//		2. The number of nodes to advance should be larger then 0
			//		3. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline NodeType* AdvanceUntilRequiredNodeAndReturnTheMemoryAddress__Private( NodeType* node, UnsignedInteger64bits numberOfNodesToTargetNode ) const;


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to set all the required nodes with the given data
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			1. node - a pointer to the first node that needs to be set
	        //          2. data - a constant reference to an instance of an object that implements the required access data using indices interface
			//			3. sizeFromDataToAdd - the size of the data to add
			//			4. startingIndexOnData - the index on the data from which to add it to this instance
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
			//		1. The given pointer is not NULL
	        //      1. The given data instance is ready 
	        //      2. The given data instance size should be larger then 0
			//		3. The sum of the starting index plus the size to add from the data must smaller or equal to the data size
			//		4. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline void SetAllTheNodesWithTheRequiredData__Private( NodeType* memoryAddressOfFirstNodeToSet, const AccessDataUsingIndices_Interface< AnyType >& data, UnsignedInteger64bits sizeFromDataToAdd, UnsignedInteger64bits startingIndexOnData );


		};  //  Class SingleLinkedList




































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
		inline SingleLinkedList< AnyType >::SingleLinkedList() :
		AccessDataUsingIndices_Interface< AnyType >(),
		member_singleLinkedListRoot(),
		member_size( 0UL ),
		member_singleLinkedListLastNode( &member_singleLinkedListRoot ),
		member_lastUsedNode( &member_singleLinkedListRoot ),
		member_lastUsedNodeIndex( 0UL )
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
		//			1. size - the number of entries in the single linked list
		//			2. data - a constant reference to the data that will be used to initialize all the nodes
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
		//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename AnyType >
		inline SingleLinkedList< AnyType >::SingleLinkedList( UnsignedInteger64bits size, const AnyType& data ) :
		AccessDataUsingIndices_Interface< AnyType >(),
		member_singleLinkedListRoot( data ),
		member_size( 1UL ),
		member_singleLinkedListLastNode( &member_singleLinkedListRoot ),
		member_lastUsedNode( &member_singleLinkedListRoot ),
		member_lastUsedNodeIndex( 0UL )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
            AssertSizeIsLargerThenZero_MACRO( size );

            // Check if the size is larger then 1
            if ( size > 1UL )
            {
	            // Allocate all the required nodes
				AllocateMoreNodesAndAddThemToTheRequiredLocation__Private( ( size - 1UL ), 1UL, WrapSingleInstanceWithAccessDataUsingIndicesInterface< AnyType >( data ) );
			}

		}


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
        //      1. The given data instance is ready 
        //      2. The given data instance size should be larger then 0
		//		3. The sum of the starting index plus the size to add from the data must smaller or equal to the data size
		//		4. The size to add should be larger then 0
		//		5. 
		//
		//  Possible errors :
		//
		//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename AnyType >
		inline SingleLinkedList< AnyType >::SingleLinkedList( const AccessDataUsingIndices_Interface< AnyType >& other, UnsignedInteger64bits sizeFromOtherToAdd, UnsignedInteger64bits startingIndexOnOther ) :
		AccessDataUsingIndices_Interface< AnyType >(),
		member_singleLinkedListRoot(),
		member_size( 1UL ),
		member_singleLinkedListLastNode( &member_singleLinkedListRoot ),
		member_lastUsedNode( &member_singleLinkedListRoot ),
		member_lastUsedNodeIndex( 0UL )
		{		
			// Each method that interacts with the user directly needs to ensure that the given data is valid
            AssertOtherInstanceIsReady_MACRO( other );
            AssertThatTheSumOfTheIndexPlusTheSizeIsEqualOrBelowCertainLimit_MACRO( startingIndexOnOther, sizeFromOtherToAdd, other.Size() );

            // Allocate all the required nodes
			AllocateMoreNodesAndAddThemToTheRequiredLocation__Private( sizeFromOtherToAdd, 0UL, other, startingIndexOnOther );
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
        inline SingleLinkedList< AnyType >::SingleLinkedList( RandomInstance, NumericRange< UnsignedInteger64bits > rangeForSize, ArgumentsTypesNeededToGenerateRandomInstanceOfDataType... argumentsNeededToGenerateRandomInstanceOfDataType ) :
        SelfType( Random::Generator::Get< UnsignedInteger64bits >( rangeForSize ) )
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
		//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename AnyType >
		inline SingleLinkedList< AnyType >::SingleLinkedList( const SelfType& other ) :
		AccessDataUsingIndices_Interface< AnyType >(),
		member_singleLinkedListRoot(),
		member_size( 1UL ),
		member_singleLinkedListLastNode( &member_singleLinkedListRoot ),
		member_lastUsedNode( &member_singleLinkedListRoot ),
		member_lastUsedNodeIndex( 0UL )
		{

			// Check if the other instance size is not 0
			if ( other.member_size > 0UL )
			{
				// The other instance is ready

				// Create a new instance, using the constructor that already implements the functionality of copying
				SelfType copyOfOther( other, other.member_size );

				// Swap between this instance and the instance that holds the copy of the other
				Swap( copyOfOther );
			}
			else
			{
				// The other instance is in default state

				// Set the size to 0
				member_size = 0UL;
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
		inline void SingleLinkedList< AnyType >::Swap( SelfType& other )
		{
			// Swap between the linked list root node content
			member_singleLinkedListRoot.Swap( other.member_singleLinkedListRoot );

		    // Swap between the sizes
		    Memory::Operations::Swap< UnsignedInteger64bits >( member_size, other.member_size );

		    // Swap between the single linked list last node pointers
		    Memory::Operations::Swap< NodeType* >( member_singleLinkedListLastNode, other.member_singleLinkedListLastNode );

		    // Swap between the single linked list last used node pointers
		    Memory::Operations::Swap< NodeType* >( member_lastUsedNode, other.member_lastUsedNode );

		    // Swap between the single linked list last used node index
		    Memory::Operations::Swap< UnsignedInteger64bits >( member_lastUsedNodeIndex, other.member_lastUsedNodeIndex );
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
		//			1. size - the number of entries in the single linked list
		//			2. data - a constant reference to the data that will be used to initialize all the nodes
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
		template< typename AnyType >
		inline void SingleLinkedList< AnyType >::Initiate( UnsignedInteger64bits size, const AnyType& data )
		{
		    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
		    // leave this scope it will delete the old data
		    SelfType temporary( size, data );

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
		template< typename AnyType >
		inline void SingleLinkedList< AnyType >::Initiate( const AccessDataUsingIndices_Interface< AnyType >& other, UnsignedInteger64bits sizeFromOtherToAdd, UnsignedInteger64bits startingIndexOnOther )
		{
		    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
		    // leave this scope it will delete the old data
		    SelfType temporary( data, sizeFromOtherToAdd, startingIndexOnOther );

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
        inline void SingleLinkedList< AnyType >::Initiate( RandomInstance, NumericRange< UnsignedInteger64bits > rangeForSize, ArgumentsTypesNeededToGenerateRandomInstanceOfDataType... argumentsNeededToGenerateRandomInstanceOfDataType )
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
		SingleLinkedList< AnyType >::~SingleLinkedList()
		{
		    // Check if the object is in default state, then noting needs to be done
		    ReturnIfExpressionIsTrue_MACRO( member_size <= 1UL );

		    // Delete all the nodes
		    DeleteNodes__Private( member_singleLinkedListRoot.NextNode() );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to set the nodes with a specific data
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. sizeToSet - the number of nodes to set
		//			2. data - a constant reference to the data that will be used to set all the required nodes
		//			3. setStartingAtThisIndex - the index of the first node that should be set
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
		//		1. The single linked list instance should be ready
		//		2. The given index plus the size should be smaller then the single linked list size
		//		3. The size to set should be larger then 0
		//		4. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename AnyType >
		inline void SingleLinkedList< AnyType >::Set( UnsignedInteger64bits sizeToSet, const AnyType& data, UnsignedInteger64bits setStartingAtThisIndex )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
            AssertThatTheSumOfTheIndexPlusTheSizeIsEqualOrBelowCertainLimit_MACRO( setStartingAtThisIndex, sizeToSet, member_size );
            AssertSizeIsLargerThenZero_MACRO( sizeToSet );

			// Take the shortest path to the first node that needs to be set
			NodeType* currentNodeToSet = TakeShortestPathToNodeAndReturnTheMemoryAddress__Private( setStartingAtThisIndex );

			// Loop on all the nodes that needs to be set
			for ( UnsignedInteger64bits numberOfNodesSet = 0UL ; numberOfNodesSet < sizeToSet ; ++numberOfNodesSet )
			{
				// Set the current node
				currentNodeToSet->SetData( data );

				// Advance the pointer to the next node
				currentNodeToSet = currentNodeToSet->NextNode();
			}

		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to add a node at the given index. This means that if a node needs to be added at index 2 then :
		//
		//			Currently the singled linked list looks :
		//
		//				--------------	--------------	--------------	--------------	  
		//				| Old Node 0 |	| Old Node 1 |	| Old Node 2 |	| Old Node 3 |	...
		//				--------------	--------------	--------------	--------------  
		//
		//			After the addition :
		//
		//													Added 	  Moved up by 1 index
		//													  |				   |
		//				--------------	--------------	--------------	--------------	--------------	  
		//				| Old Node 0 |	| Old Node 1 |	| New Node 2 |	| Old Node 3 |	| Old Node 4 |	...
		//				--------------	--------------	--------------	--------------	-------------- 
		//
		//		As can be seen all the nodes that exist in the single linked list before the addition, starting from the node with the required index,
		//		will be moved one index up.
		//
		//		Note 1 - if the data should be added to the end of the single linked list, provide as index the current size of the single linked list
		//		Note 2 - if the instance is currently in default state the only index that is allowed to be used with this method is 0
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. data - a reference to the data that a copy of it should be stored in the new node
		//			2. index - the index to insert the new node
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
		//		1. The given index should be smaller or equal to the single linked list size
		//		2. 
		//
		//  Possible errors :
		//
		//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename AnyType >
		inline void SingleLinkedList< AnyType >::AddData( UnsignedInteger64bits index, const AnyType& data )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertIndexIsEqualOrBelowCertainLimit_MACRO( index, member_size );

            // Check if the instance is in default state
            if ( member_size == 0UL )
            {
                // The instance is in default state

            	// Initiate the instance
            	Initiate( 1UL, data );

            	// Nothing else needs to be done
            	return;
            }

            // Allocate the new node and set it into the required location
			AllocateMoreNodesAndAddThemToTheRequiredLocation__Private( 1UL, index, WrapSingleInstanceWithAccessDataUsingIndicesInterface< AnyType >( data ) );

			// Check if the index of the last used node is larger or equal to the new node
			if ( index >= member_lastUsedNodeIndex  )
			{
				// The last used node index is larger or equal to the new added node, it means that the new index of the last used node has changed

				// Increment the last used node index by 1
				member_lastUsedNodeIndex += 1UL;
			}

		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to add a number of nodes at the given index. This means that if the nodes needs to be added starting at index 2 then :
		//
		//			Currently the singled linked list looks :
		//
		//				--------------	--------------	--------------	--------------	  
		//				| Old Node 0 |	| Old Node 1 |	| Old Node 2 |	| Old Node 3 |	...
		//				--------------	--------------	--------------	--------------  
		//
		//			After the addition :
		//
		//													Added 	  Moved up by 1 index
		//													  |				   |
		//				--------------	--------------	--------------	--------------	--------------	  
		//				| Old Node 0 |	| Old Node 1 |	| New Node 2 |	| Old Node 3 |	| Old Node 4 |	...
		//				--------------	--------------	--------------	--------------	-------------- 
		//
		//		As can be seen all the nodes that exist in the single linked list before the addition, starting from the node with the required index,
		//		will be moved one index up.
		//
		//		Note 1 - if the data should be added to the end of the single linked list, provide as index the current size of the single linked list
		//		Note 2 - if the instance is currently in default state the only index that is allowed to be used with this method is 0
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. data - a constant reference to an instance of an object that implements the required access data using indices interface
		//			2. sizeFromDataToAdd - the size of the data to add
		//			3. indexInThisInstance - the index to insert the new nodes in this instance
		//			4. startingIndexOnData - the index on the data from which to add it to this instance
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
		//		1. The given index should be smaller or equal to the single linked list size
		//		2. The data size should be larger then 0
		//		3. The sum of the starting index plus the size to add from the data must smaller or equal to the data size
		//		4. 
		//
		//  Possible errors :
		//
		//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename AnyType >
		inline void SingleLinkedList< AnyType >::AddData( const AccessDataUsingIndices_Interface< AnyType >& data, UnsignedInteger64bits sizeFromDataToAdd, UnsignedInteger64bits indexInThisInstance, UnsignedInteger64bits startingIndexOnData )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertIndexIsEqualOrBelowCertainLimit_MACRO( indexInThisInstance, member_size );
            AssertInstanceSizeIsLargerThenZero_MACRO( data );
            AssertThatTheSumOfTheIndexPlusTheSizeIsEqualOrBelowCertainLimit_MACRO( startingIndexOnData, sizeFromDataToAdd, data.Size() );

            // Check if the instance is in default state
            if ( member_size == 0UL )
            {
                // The instance is in default state

            	// Initiate the instance
            	Initiate( data, sizeFromDataToAdd, startingIndexOnData );

            	// Nothing else needs to be done
            	return;
            }

            // Allocate the new nodes
			AllocateMoreNodesAndAddThemToTheRequiredLocation__Private( sizeFromDataToAdd, indexInThisInstance, data, startingIndexOnData );

			// Check if the index of the last used node is larger or equal to the new node
			if ( indexInThisInstance >= member_lastUsedNodeIndex  )
			{
				// The last used node index is larger or equal to the new added node, it means that the new index of the last used node has changed

				// Increment the last used node index by size of the data, which is the number of nodes needed to store the data
				member_lastUsedNodeIndex += data.Size();
			}

		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to remove number of nodes starting at the given index. This means that if the nodes needs to be removed starting at index 2 then :
		//
		//			Currently the singled linked list looks :
		//
		//				--------------	--------------	--------------	--------------	  
		//				| Old Node 0 |	| Old Node 1 |	| Old Node 2 |	| Old Node 3 |	...
		//				--------------	--------------	--------------	--------------  
		//
		//			After the remove :
		//
		//											 Moved down by 1 index
		//													   |
		//				--------------	--------------	--------------	  
		//				| Old Node 0 |	| Old Node 1 |	| Old Node 2 |	...
		//				--------------	--------------	-------------- 
		//
		//		As can be seen all the nodes that exist in the single linked list before the removal, starting from the last node to be removed index, will be 
		//		moved one index down.
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			indexOfFirstDataToRemove - the index of the first data to remove
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
		//		2. The given index is smaller then the single linked list size
		//		3. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename AnyType >
		inline void SingleLinkedList< AnyType >::RemoveData( UnsignedInteger64bits sizeToRemove, UnsignedInteger64bits indexOfFirstDataToRemove )
		{

			// The logic of the method is as follows :
			//
			// The current node with the required index first of all will be found. Now because this is a single linked list and the previous node can
			// not be found without repassing on all the list, the data from the next node will be moved from the next node to the node that should be
			// removed. This can be done because the data in the node that should be removed is not needed anymore. And the pointer to the next node
			// will be set also to the pointer to the next node of the next node. In other words all the members of the next node will be taken and set
			// in the node that should have been removed, and finally the next node will be deleted. Visually it will look :
			//
			//		Before :
			//
			//					--------------		--------------		--------------		--------------
			//			...		|   data 30  |	->	|   data 31  |	->	|   data 32  |	->	|   data 33  |		...
			//					|  index 30  |		|  index 31  |		|  index 32  |		|  index 33  |
			//					--------------		--------------		--------------		--------------
			//
			//		Setting the data of the next node :
			//
			//					--------------		--------------		--------------		--------------
			//			...		|   data 30  |	->	|   data 32  |	->	|   data 32  |	->	|   data 33  |		...
			//					|  index 30  |		|  index 31  |		|  index 32  |		|  index 33  |
			//					--------------		--------------		--------------		--------------
			//
			//		Store the pointer to the next node of the next node, and delete the next node :
			//
			//																delete	   Store address in temporary
			//																  |				      |
			//					--------------		--------------		--------------		--------------
			//			...		|   data 30  |	->	|   data 32  |	->	|   data 32  |	->	|   data 33  |		...
			//					|  index 30  |		|  index 31  |		|  index 32  |		|  index 33  |
			//					--------------		--------------		--------------		--------------
			//
			//		Finally set the pointer to the next node :
			//
			//					--------------		--------------							--------------
			//			...		|   data 30  |	->	|   data 32  |	  ------------------>	|   data 33  |		...
			//					|  index 30  |		|  index 31  |							|  index 32  |
			//					--------------		--------------							--------------


			// Each method that interacts with the user directly needs to ensure that the given data is valid
            AssertThatTheSumOfTheIndexPlusTheSizeIsEqualOrBelowCertainLimit_MACRO( indexOfFirstDataToRemove, sizeToRemove, member_size );

			// Check if all the nodes needs to be removed
			if ( member_size == sizeToRemove )
			{
				// All the nodes needs to be removed

				// Reset the instance
				Reset();

				// Nothing else needs to be done
				return;
			}			

			// This object will store the first node that needs to be removed
			NodeType* firstNodeThatNeedsToBeRemoved = nullptr;

			// This object will store the last node that needs to be removed
			NodeType* lastNodeThatNeedsToBeRemoved = nullptr;

			// Check if the data in the first node needs to be removed
			if ( indexOfFirstDataToRemove == 0UL )
			{
				// The data in the first node of the single linked list needs to be removed

				// Find the last node that needs to be removed
				lastNodeThatNeedsToBeRemoved = TakeShortestPathToNodeAndReturnTheMemoryAddress__Private( indexOfFirstDataToRemove + sizeToRemove );

				// Advance the pointer of the last node that needs to be removed to the next node
				lastNodeThatNeedsToBeRemoved = lastNodeThatNeedsToBeRemoved->NextNode();

				// The node after the last node that needs to be deleted should become the new first node, but because the root of the single linked list
				// is fixed node, the data needs to pass to it
				member_singleLinkedListRoot.SetDataByMove( lastNodeThatNeedsToBeRemoved->MoveData() );

				// Set the first node that needs to be removed, which is the the next node after the single linked list root
				firstNodeThatNeedsToBeRemoved = member_singleLinkedListRoot.NextNode();

				// Set the next node of the root to the first node that does not need to be deleted
				member_singleLinkedListRoot.SetNextNode( lastNodeThatNeedsToBeRemoved->NextNode() );
			}
			// Check if the data in the last node also needs to be removed
			else if ( indexOfFirstDataToRemove + sizeToRemove == member_size )
			{
				// The data in the last node of the single linked list needs to be removed

				// Set the last node that needs to be removed, which is the last node of the single linked list
				lastNodeThatNeedsToBeRemoved = member_singleLinkedListLastNode;

				// Set the pointer to the last node of the single linked list to the last node that does not need to be removed
				member_singleLinkedListLastNode = TakeShortestPathToNodeAndReturnTheMemoryAddress__Private( indexOfFirstDataToRemove + sizeToRemove - 1UL );

				// Set the first node that needs to be removed
				firstNodeThatNeedsToBeRemoved = member_singleLinkedListLastNode->NextNode();
			}
			else
			{
				// The removed nodes does not include the first or last node of the single linked list

				// Find the node that does not need to be removed before the first node that needs to be removed
				firstNodeThatNeedsToBeRemoved = TakeShortestPathToNodeAndReturnTheMemoryAddress__Private( indexOfFirstDataToRemove - 1UL );

				// Find the last node that needs to be removed
				lastNodeThatNeedsToBeRemoved = TakeShortestPathToNodeAndReturnTheMemoryAddress__Private( indexOfFirstDataToRemove + sizeToRemove );

				// Set the next node of the node that does not need to be removed before the first node that needs to be removed, to the memory
				// address of the first node after the last node that needs to be removed
				firstNodeThatNeedsToBeRemoved->SetNextNode( lastNodeThatNeedsToBeRemoved->NextNode() );

				// Set the first node that needs to be removed
				firstNodeThatNeedsToBeRemoved = firstNodeThatNeedsToBeRemoved->NextNode();				
			}

			// Check if the last used node index is in the area that about to be removed
			if ( ( member_lastUsedNodeIndex >= indexOfFirstDataToRemove ) && ( member_lastUsedNodeIndex <= ( indexOfFirstDataToRemove + sizeToRemove ) ) )
			{
				// The lase used node points to a node that is about to be deleted

				// Set the last used node to the single linked list root
				member_lastUsedNode = &member_singleLinkedListRoot;

				// Set the last used node index to 0
				member_lastUsedNodeIndex = 0UL;
			}

			// Set the next node pointer of the last node to remove to NULL to stop the deletion of nodes at this point
			lastNodeThatNeedsToBeRemoved->SetNextNode( nullptr );

			// Delete all the required nodes
			DeleteNodes__Private( firstNodeThatNeedsToBeRemoved );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to reserve memory space at the single linked list. This method will allocate memory space in advance, without
		//		the need for the actual data, and then the data can just be set into the allocated memory when needed
		//
		//		Note 1 - if the data should be added to the end of the single linked list, provide as index the current size of the single linked list
		//		Note 2 - if the instance is currently in default state the only index that is allowed to be used with this method is 0
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. sizeToReserve - the number of entries to reserve
		//			2. data - a constant reference to the data that will be used to initialize all the reserved memory space
		//			3. reserveStartingFromThisIndex - the first index from which memory space should be reserved at the single linked list instance
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
		//		1. The given index should be smaller or equal to the single linked list size
		//		2. The size to reserve should be larger then 0
		//		3.  
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename AnyType >
		inline void SingleLinkedList< AnyType >::Reserve( UnsignedInteger64bits sizeToReserve, const AnyType& data, UnsignedInteger64bits reserveStartingFromThisIndex )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
            AssertIndexIsEqualOrBelowCertainLimit_MACRO( reserveStartingFromThisIndex, member_size );
            AssertSizeIsLargerThenZero_MACRO( sizeToReserve );

            // Check if the instance is in default state
            if ( member_size == 0UL )
            {
                // The instance is in default state

            	// Initiate the instance
            	Initiate( data, sizeToReserve, reserveStartingFromThisIndex );

            	// Nothing else needs to be done
            	return;
            }

            // Allocate a larger array to contain the additional data, and move the existing data into it
			AllocateMoreNodesAndAddThemToTheRequiredLocation__Private( sizeToReserve, reserveStartingFromThisIndex, WrapSingleInstanceWithAccessDataUsingIndicesInterface< AnyType >( data ) );
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
        //		1. The single linked list instance should be ready
        //		3. The other instance should be ready
        //      4. The sum of the given starting index and size to compare is smaller or equal to the size of the this instance
        //      5. The sum of the given starting index and size to compare is smaller or equal to the size of the other instance
        //      6. The size to compare should be larger then 0
        //		7. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename AnyType >
        inline Boolean SingleLinkedList< AnyType >::Compare( const AccessDataUsingIndices_Interface< AnyType >& other, UnsignedInteger64bits sizeToCompare, UnsignedInteger64bits startingIndexInThisInstance, UnsignedInteger64bits startingIndexInOtherInstance ) const
        {
            // Each method that interacts with the user directly needs to ensure that the given data is valid
            AssertThatTheSumOfTheIndexPlusTheSizeIsEqualOrBelowCertainLimit_MACRO( startingIndexInThisInstance, sizeToCompare, member_size );
            AssertThatTheSumOfTheIndexPlusTheSizeIsEqualOrBelowCertainLimit_MACRO( startingIndexInOtherInstance, sizeToCompare, other.Size() );

            // Loop on all the required entries and compare their content
            for ( UnsignedInteger64bits numberOfNodesAlreadyCompared = 0UL ; numberOfNodesAlreadyCompared < sizeToCompare ; ++numberOfNodesAlreadyCompared )
            {
                // Compare the current entries in both instances
                ReturnValueIfExpressionIsTrue_MACRO( ( (*this)[ startingIndexInThisInstance ] != other[ startingIndexInOtherInstance ] ), false );

                // Increment the index on the this instance
				startingIndexInThisInstance += 1UL;

                // Increment the index on the other instance
                startingIndexInOtherInstance += 1UL;
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
        inline UnsignedInteger64bits SingleLinkedList< AnyType >::SizeOfMemorySpaceUsedInBytes() const
        {
            // Calculate the total size used by the instance in bytes, and return the result
            return ( sizeof( SelfType ) + ( member_size - 1UL ) * sizeof( NodeType ) );
        }





























//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************


































		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to get a reference to the required node
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			index - the index of the required node
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		A reference to the required node
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. The given index is smaller then the single linked list size
		//		3. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename AnyType >
		AnyType& SingleLinkedList< AnyType >::operator[]( UnsignedInteger64bits index )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertIndexIsBelowCertainLimit_MACRO( index, member_size );

			// Store the required node memory address in the last used node member
			member_lastUsedNode = TakeShortestPathToNodeAndReturnTheMemoryAddress__Private( index );

			// Store the index in the last used index member
			member_lastUsedNodeIndex = index;
			
			// Find the required node, and return a reference to it
			return ( member_lastUsedNode->Data() );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to get a copy of the value inside the required node
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			index - the index of the required node
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
        //      A constant reference to the required node
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. The given index is smaller then the single linked list size
		//		3. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename AnyType >
		const AnyType& SingleLinkedList< AnyType >::operator[]( UnsignedInteger64bits index ) const
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertIndexIsBelowCertainLimit_MACRO( index, member_size );
			
			// Store the required node memory address in the last used node member
			member_lastUsedNode = TakeShortestPathToNodeAndReturnTheMemoryAddress__Private( index );

			// Store the index in the last used index member
			member_lastUsedNodeIndex = index;
			
			// Find the required node, and return a constant reference to it
			return ( member_lastUsedNode->Data() );
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
		//			other - a constnt reference to a single linekd list
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
		inline Boolean SingleLinkedList< AnyType >::operator==( const AccessDataUsingIndices_Interface< AnyType >& other ) const
		{
			// Check if the size of both instances match, if it doesn't return false
            ReturnValueIfExpressionIsTrue_MACRO( ( member_size != other.Size() ), false );

			// Compare the instances content, and return the result
			return ( Compare( other, other.Size(), 0UL, 0UL ) );
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
		inline Boolean SingleLinkedList< AnyType >::operator!=( const AccessDataUsingIndices_Interface< AnyType >& other ) const
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
		//			data - a reference to a single linekd list to concatenate to the end of this instance
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
		//		2. The single linekd list should be ready
		//		3. The single linekd list size should be larger then 0
		//		4. 
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename AnyType >
		inline SingleLinkedList< AnyType >& SingleLinkedList< AnyType >::operator+=( const AccessDataUsingIndices_Interface< AnyType >& data )
		{
			// Add the data to the end of this single linked list instance
			AddData( data, data.Size(), member_size );

			// Return a reference to this instance
			return ( *this );
		}



































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************
































		// Method Information :
		//
		//  Description :
		//
        //		Use this method to allocate more nodes, according to the size given, connect between them and set it into the required location
        //		in the instance represented by the index. The last used node pointer will be set to the memory address of the first new node
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. numberOfNodesToAllocate - the number of nodes that needs to be added
		//			2. addNodesStartingFromThisIndex - the first index from which nodes should be added to the single linked list instance
		//			3. data - a constant reference to an instance of an object that implements the required access data using indices interface
		//			4. startingIndexOnData - the index on the data from which to add it to this instance
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
		//		1. The given index should be smaller or equal to the single linked list size
		//		2. The given number of nodes to allocate should be larger then 0
		//		3. 
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename AnyType >
		inline void SingleLinkedList< AnyType >::AllocateMoreNodesAndAddThemToTheRequiredLocation__Private( UnsignedInteger64bits numberOfNodesToAllocate, UnsignedInteger64bits addNodesStartingFromThisIndex, const AccessDataUsingIndices_Interface< AnyType >& data, UnsignedInteger64bits startingIndexOnData )
		{

			// The logic of the method is as follows :
			//
			// The first operation will be to allocate a string of new nodes interconnected, in the required size. Now, the node associated with the 
			// index needs to be found, and the string ends needs be connected from one side with the node associated with the index, and from other
			// side, with the next node of the node associated with the index. And finally the data of the node associated with the index needs to
			// be moved to the last new node allocated. Visually it will look :
			//
			//		Before :
			//
			//					--------------		--------------
			//			...		|   data 30  |	->	|   data 31  |		...
			//					|  index 30  |		|  index 31  |
			//					--------------		--------------
			//
			//		Allocating new node and putting all the data of the current node in the required index to it :
			//
			//										   	New Node
			//											   |
			//					--------------		--------------		--------------
			//			...		|   data 30  |	->	|   data 30  |	->	|   data 31  |		...
			//					|  index 30  |		|  index 31  |		|  index 32  |
			//					--------------		--------------		--------------
			//
			//		And finally setting the new data :		
			//
			//					--------------		--------------		--------------
			//			...		|  data New  |	->	|   data 30  |	->	|   data 31  |		...
			//					|  index 30  |		|  index 31  |		|  index 32  |
			//					--------------		--------------		--------------
			//
			// There is one exception to this, to allow adding a node to the end of the single linked list!

			// Create two constant exrpessions to use as enumeration for the data members of the tuple
			constexpr UnsignedInteger64bits firstNodeMemoryAddress = 0UL;
			constexpr UnsignedInteger64bits lastNodeMemoryAddress = 1UL;

			// Allocate a string of nodes with the required size, the nodes will already be connected between themselves
			Tuple< NodeType*, NodeType* > firstAndLastNodesMemoryAddress = AllocateStringOfNodes__Private( numberOfNodesToAllocate, data, startingIndexOnData );

			// Check if the new nodes needs to be added to the end of the instance
			if ( member_size == addNodesStartingFromThisIndex )
			{
				// The new nodes needs to be added to the end of the instance

				// Set the memory address of the first new node as the next node of the current last node of the instance
				member_singleLinkedListLastNode->SetNextNode( firstAndLastNodesMemoryAddress.template Entry< firstNodeMemoryAddress >() );

				// Set the last node of the single linked list instance to the memory address of the last node allocated
				member_singleLinkedListLastNode = firstAndLastNodesMemoryAddress.template Entry< lastNodeMemoryAddress >();
			}
			else
			{
				// Take the shortest path to the node that is currently associated with the index to add the data to
				NodeType* nodeAssociatedWithIndex = TakeShortestPathToNodeAndReturnTheMemoryAddress__Private( addNodesStartingFromThisIndex );

				// This object will store the memory address of the next node of the node associated with the index
				NodeType* nextNodeOfNodeAssociatedWithIndex = nodeAssociatedWithIndex->NextNode();

				// Set the next node of the node associated with the index to the memory address of the first new node allocated
				nodeAssociatedWithIndex->SetNextNode( firstAndLastNodesMemoryAddress.template Entry< firstNodeMemoryAddress >() );

				// Set the next node of the last new node allocated to the old next node of the node associated with the index
				firstAndLastNodesMemoryAddress.template Entry< lastNodeMemoryAddress >()->SetNextNode( nextNodeOfNodeAssociatedWithIndex );

				// Set the data of the node associated with the index to the last node allocated
				firstAndLastNodesMemoryAddress.template Entry< lastNodeMemoryAddress >()->SetDataByMove( nodeAssociatedWithIndex->MoveData() );
			}

			// Increment the size of the instance by the size of the sequential platfrom
			member_size += numberOfNodesToAllocate;
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to allocate nodes, attach them together, and return a tuple with the memory address of the first and last nodes
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. numberOfNodesToAllocate - the number of nodes to allocate
		//			2. data - a constant reference to an instance of an object that implements the required access data using indices interface
		//			3. startingIndexOnData - the index on the data from which to add it to this instance
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		A tuple with the memory address of the first and last nodes allocated
		//
		//  Expectations :
		//
		//		1. The number of nodes to allocate must be larger then 0
		//		2. 
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename AnyType >
		inline Tuple< SingleLinkedListNode< AnyType >*, SingleLinkedListNode< AnyType >* > SingleLinkedList< AnyType >::AllocateStringOfNodes__Private( UnsignedInteger64bits numberOfNodesToAllocate, const AccessDataUsingIndices_Interface< AnyType >& data, UnsignedInteger64bits startingIndexOnData )
		{
			// Create two constant exrpessions to use as enumeration for the data members of the tuple
			constexpr UnsignedInteger64bits firstNodeMemoryAddress = 0UL;
			constexpr UnsignedInteger64bits lastNodeMemoryAddress = 1UL;

			// This object will store the memory address of the first and last nodes of the new allocated string of nodes
			Tuple< NodeType*, NodeType* > firstAndLastNodesMemoryAddress( nullptr, nullptr );

			// This object will store the memory address of the last allocated node in the string
			NodeType* currentAllocatedNode = nullptr;

			// Try catch block to ensure that all the memory space allocated is deleted before rethrowing the exception
			try
			{

				// Allocate the first node, and initialize it using the data
				firstAndLastNodesMemoryAddress.template Entry< firstNodeMemoryAddress >() = new NodeType( data[ startingIndexOnData ] );

				// Set the current allocated node memory address
				currentAllocatedNode = firstAndLastNodesMemoryAddress.template Entry< firstNodeMemoryAddress >();

				// Loop until all the nodes were allocated
				for ( UnsignedInteger64bits numberOfNodesAllocated = 1UL ; numberOfNodesAllocated < numberOfNodesToAllocate ; ++numberOfNodesAllocated )
				{
					// Allocate a new node, set the memory address of it in the node before in the string
					currentAllocatedNode->SetNextNode( new NodeType( data[ startingIndexOnData + numberOfNodesAllocated ] ) );

					// Advance the pointer to the new allocated node
					currentAllocatedNode = currentAllocatedNode->NextNode();
				}

				// Set the memory address of the last node in the string
				firstAndLastNodesMemoryAddress.template Entry< lastNodeMemoryAddress >() = currentAllocatedNode;

			}
			catch ( const std::bad_alloc& exception )
			{

				// Check if at least one node was already allocated
				if ( firstAndLastNodesMemoryAddress.template Entry< firstNodeMemoryAddress >() != nullptr )
				{
					// Delete all the nodes allocated so far
					DeleteNodes__Private( firstAndLastNodesMemoryAddress.template Entry< firstNodeMemoryAddress >() );
				}

				// Rethrow the exception to notify the caller that the operation failed
				throw;
			}

			// Return the result
			return ( MOVE( firstAndLastNodesMemoryAddress ) );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to delete all the node from the single linked list
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			firstNodeToDelete - the memory address of the first node to delete
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
		//		1. The given pointer is not NULL
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename AnyType >
		inline void SingleLinkedList< AnyType >::DeleteNodes__Private( NodeType* firstNodeToDelete )
		{
			// This pointer will store the pointer of the node that needs to be deleted
			NodeType* currentNodeToDelete = firstNodeToDelete;

			// Loop on all the entries allocated so far and delete them
			for ( NodeType* nextNodeToDelete = currentNodeToDelete->NextNode() ; nextNodeToDelete != nullptr ; nextNodeToDelete = nextNodeToDelete->NextNode() )
			{
				// Delete the node
				delete currentNodeToDelete;

				// Set the next node to delete
				currentNodeToDelete = nextNodeToDelete;
			}

			// Delete the last node
			delete currentNodeToDelete;
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the memory address of a specific node. The method will check if the shortest path to the required node is from
		//		the beginning or from the last used node, and take that path
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			index - the index of the required node
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
        //      The memory address of the required node
		//
		//  Expectations :
		//
		//		1. The given index is smaller then the single linked list size
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename AnyType >
		inline SingleLinkedListNode< AnyType >* SingleLinkedList< AnyType >::TakeShortestPathToNodeAndReturnTheMemoryAddress__Private( UnsignedInteger64bits index ) const
		{
			// Check if the index is 0, which means the first node in the single linked list is required
			ReturnValueIfExpressionIsTrue_MACRO( ( index == 0UL ), &member_singleLinkedListRoot );

			// Check if the index is smaller by 1 then the current size, which means the last node in the single linked list is required
			ReturnValueIfExpressionIsTrue_MACRO( ( index == ( member_size - 1UL ) ), member_singleLinkedListLastNode );

			// Check if the index is the same as the index of the last used node
			ReturnValueIfExpressionIsTrue_MACRO( ( index == member_lastUsedNodeIndex ), member_lastUsedNode );

			// Check if the index of the last used node is smaller then the required index, which means the required node can be moved to
			// from the last used node, and does not need to start at the beginning
			if ( index > member_lastUsedNodeIndex )
			{
				// The search for the required node can start from the last used bit

				// Advance to the required node and return the memory address
				return ( AdvanceUntilRequiredNodeAndReturnTheMemoryAddress__Private( member_lastUsedNode, ( index - member_lastUsedNodeIndex ) ) );
			}
			else
			{
				// The search for the required node will start from the beginning

				// Advance to the required node and return the memory address
				return ( AdvanceUntilRequiredNodeAndReturnTheMemoryAddress__Private( &member_singleLinkedListRoot, index ) );
			}

		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the memory address of a specific node. The method starts from the given node, and advances on the list the 
		//		required amount of nodes to the required node
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			1. node - the memory address of the node to start from
		//			2. numberOfNodesToTargetNode - the number of nodes that the required node is away from the given node
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		The memory address of the required node
		//
		//  Expectations :
		//
		//		1. The given pointer is not NULL
		//		2. The number of nodes to advance should be larger then 0
		//		3. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename AnyType >
		inline SingleLinkedListNode< AnyType >* SingleLinkedList< AnyType >::AdvanceUntilRequiredNodeAndReturnTheMemoryAddress__Private( NodeType* node, UnsignedInteger64bits numberOfNodesToTargetNode ) const
		{

			// Loop until the required amount of nodes to pass has reached
			for ( UnsignedInteger64bits numberOfNodesPassed = 0UL ; numberOfNodesPassed < numberOfNodesToTargetNode ; ++numberOfNodesPassed )
			{
				// Advance to the next node
				node = node->NextNode();
			}

			// Return the memory address of the required node 
			return ( node );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to set all the required nodes with the given data
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			1. node - a pointer to the first node that needs to be set
        //          2. data - a constant reference to an instance of an object that implements the required access data using indices interface
		//			3. sizeFromDataToAdd - the size of the data to add
		//			4. startingIndexOnData - the index on the data from which to add it to this instance
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
		//		1. The given pointer is not NULL
        //      1. The given data instance is ready 
        //      2. The given data instance size should be larger then 0
		//		3. The sum of the starting index plus the size to add from the data must smaller or equal to the data size
		//		4. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename AnyType >
		inline void SingleLinkedList< AnyType >::SetAllTheNodesWithTheRequiredData__Private( NodeType* memoryAddressOfFirstNodeToSet, const AccessDataUsingIndices_Interface< AnyType >& data, UnsignedInteger64bits sizeFromDataToAdd, UnsignedInteger64bits startingIndexOnData )
		{
			// This obejct will store condition to stop the loop that sets the data into the nodes, it will contain the index of the first entry
			// after the contigous segment to set
			UnsignedInteger64bits indexToStopLoop = startingIndexOnData + sizeFromDataToAdd;

			// Loop until the required amount of nodes to pass has reached
			for ( UnsignedInteger64bits dataIndex = startingIndexOnData ; dataIndex < indexToStopLoop ; ++dataIndex )
			{
				// Set the current node with the required data
				memoryAddressOfFirstNodeToSet->SetData( data[ dataIndex ] );

				// Advance to the next node to set
				memoryAddressOfFirstNodeToSet = memoryAddressOfFirstNodeToSet->NextNode();
			}

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
			template< typename AnyType >
			inline void SingleLinkedList< AnyType >::Test()
			{
                // Perform a sanity to ensure that all the methods that are common among all objects, for example defualt constructor, copy constructor,
                // destructor, swap and more, seem to work correctly
                Testing::SanityCheck::Full< SingleLinkedList< AnyType > COMMA UnsignedInteger64bits COMMA const AnyType& >();

				// Create a single linked list instance
				SingleLinkedList< UnsignedInteger64bits > testSingleLinkedList_1;

				// Initiate the instance
				testSingleLinkedList_1.Initiate( 89UL );
			
				// Check that the instance was initialized
				Assert_Test_MACRO( testSingleLinkedList_1.State().Get() == InstanceState::Ready );

				// Check that the node was added correctly
				Assert_Test_MACRO( testSingleLinkedList_1[0] == 89UL );

				// Add 100 nodes
				for ( UnsignedInteger64bits index = 0UL ; index < 100UL ; ++index )
				{
					// Add as node
					testSingleLinkedList_1.AddData( index, index );
				}

				const SingleLinkedList< UnsignedInteger64bits > testSingleLinkedList_49( testSingleLinkedList_1, 9UL, 43UL );

				// Check that all the nodes were added correctly
				for ( UnsignedInteger64bits index = 0UL ; index < 100UL ; ++index )
				{
					// Add as node
					Assert_Test_MACRO( testSingleLinkedList_1[ index ] == index );
				}

				// Check that the node was added correctly
				Assert_Test_MACRO( testSingleLinkedList_1[ testSingleLinkedList_1.Size() - 1 ] == 89UL );

				// Add 100000 nodes
				for ( UnsignedInteger64bits index = 0UL ; index < 100000UL ; ++index )
				{
					// Add as node
					testSingleLinkedList_1.AddData( index, index );
				}

				// Check that all the nodes were added correctly
				for ( UnsignedInteger64bits index = 0UL ; index < 100000UL ; ++index )
				{
					// Add as node
					Assert_Test_MACRO( testSingleLinkedList_1[ index ] == index );
				}

				// Check that the node was added correctly
				Assert_Test_MACRO( testSingleLinkedList_1[ testSingleLinkedList_1.Size() - 1 ] == 89UL );

				// Add 100000 nodes
				for ( UnsignedInteger64bits index = 45UL ; index < 100000UL ; ++index )
				{
					// Add as node
					testSingleLinkedList_1.AddData( index, index );
				}

				// Check that all the nodes were added correctly
				for ( UnsignedInteger64bits index = 45UL ; index < 100000UL ; ++index )
				{
					// Add as node
					Assert_Test_MACRO( testSingleLinkedList_1[ index ] == index );
				}

				// Check that the node was added correctly
				Assert_Test_MACRO( testSingleLinkedList_1[ testSingleLinkedList_1.Size() - 1 ] == 89UL );

				// Store the current size of the single linked list
				UnsignedInteger64bits currentSingleLinkedListSize = testSingleLinkedList_1.Size();

				// Add 100000 nodes
				for ( UnsignedInteger64bits index = currentSingleLinkedListSize ; index < ( currentSingleLinkedListSize + 100000UL ) ; ++index )
				{
					// Add as node
					testSingleLinkedList_1.AddData( index, index );
				}

				// Check that all the nodes were added correctly
				for ( UnsignedInteger64bits index = currentSingleLinkedListSize ; index < ( currentSingleLinkedListSize + 100000UL ) ; ++index )
				{
					// Add as node
					Assert_Test_MACRO( testSingleLinkedList_1[ index ] == index );
				}

				// Check that the node was added correctly
				Assert_Test_MACRO( testSingleLinkedList_1[ testSingleLinkedList_1.Size() - 1 ] == ( currentSingleLinkedListSize + 100000UL - 1UL ) );

				// Store the current size
				currentSingleLinkedListSize = testSingleLinkedList_1.Size();

				// Remove 100000 nodes
				for ( UnsignedInteger64bits index = 56 ; index < 100001UL ; index += 3 )
				{
					// Add as node
					testSingleLinkedList_1.RemoveData( index );
				}

				// Check that the size is correct
				Assert_Test_MACRO( testSingleLinkedList_1.Size() == ( currentSingleLinkedListSize - ( ( 100001UL - 56UL ) / 3UL ) ) );				

				// Create a new instance using the copy constructor
				SingleLinkedList< UnsignedInteger64bits > testSingleLinkedList_2( testSingleLinkedList_1 );

				// Check that the instances match
				Assert_Test_MACRO( testSingleLinkedList_1 == testSingleLinkedList_2 );			

				// Check that the instances match
				Assert_Test_MACRO( ( testSingleLinkedList_1 != testSingleLinkedList_2 ) == false );

				// Reset the second instance
				testSingleLinkedList_2.Reset();

				// Check that the instances don't match
				Assert_Test_MACRO( ( testSingleLinkedList_1 == testSingleLinkedList_2 ) == false );			

				// Check that the instances don't match
				Assert_Test_MACRO( testSingleLinkedList_1 != testSingleLinkedList_2 );

				// Check the assignment operator
				testSingleLinkedList_2 = testSingleLinkedList_1;

				// Check that the instances match
				Assert_Test_MACRO( testSingleLinkedList_1 == testSingleLinkedList_2 );			

				// Check that the instances match
				Assert_Test_MACRO( ( testSingleLinkedList_1 != testSingleLinkedList_2 ) == false );

				// Remove all nodes
				while ( testSingleLinkedList_2.Size() > 0UL )
				{
					// Remove node
					testSingleLinkedList_2.RemoveData( 0UL );
				}

				// Check the assignment operator
				testSingleLinkedList_2 = testSingleLinkedList_1;

				// Remove all nodes
				while ( testSingleLinkedList_2.Size() > 6UL )
				{
					// Remove node
					testSingleLinkedList_2.RemoveData( 5UL );
				}

				// Check that the instance is really in default state
				Assert_Test_MACRO( testSingleLinkedList_2.Size() == 6UL );

				// Create a single linked list instance
				SingleLinkedList< UnsignedInteger64bits > testSingleLinkedList_3;

				// Add some nodes
				testSingleLinkedList_3.Initiate( 8UL );
				testSingleLinkedList_3.AddData( 0UL, 8UL );
				testSingleLinkedList_3.AddData( 0UL, 8UL );
				testSingleLinkedList_3.AddData( 0UL, 8UL );
				testSingleLinkedList_3.AddData( 0UL, 8UL );
				testSingleLinkedList_3.AddData( 0UL, 8UL );
				testSingleLinkedList_3.AddData( 1UL, 8UL );
				testSingleLinkedList_3.AddData( 1UL, 8UL );
				testSingleLinkedList_3.AddData( 1UL, 8UL );
				testSingleLinkedList_3.AddData( 1UL, 8UL );
				testSingleLinkedList_3.AddData( 1UL, 8UL );
				testSingleLinkedList_3.AddData( 2UL, 8UL );
				testSingleLinkedList_3.AddData( 2UL, 8UL );
				testSingleLinkedList_3.AddData( 2UL, 8UL );
				testSingleLinkedList_3.AddData( 2UL, 8UL );
				testSingleLinkedList_3.AddData( 2UL, 8UL );
				testSingleLinkedList_3.AddData( 2UL, 8UL );
				testSingleLinkedList_3.AddData( 2UL, 8UL );
				testSingleLinkedList_3.AddData( 2UL, 8UL );
				testSingleLinkedList_3.AddData( 2UL, 8UL );
				testSingleLinkedList_3.AddData( 2UL, 8UL );
				testSingleLinkedList_3.AddData( 7UL, 8UL );
				testSingleLinkedList_3.AddData( 7UL, 8UL );
				testSingleLinkedList_3.AddData( 7UL, 8UL );
				testSingleLinkedList_3.AddData( 7UL, 8UL );
				testSingleLinkedList_3.AddData( 7UL, 8UL );
				testSingleLinkedList_3.AddData( 7UL, 8UL );
				testSingleLinkedList_3.AddData( 7UL, 8UL );
				testSingleLinkedList_3.AddData( 7UL, 8UL );
				testSingleLinkedList_3.AddData( 7UL, 8UL );
				testSingleLinkedList_3.AddData( 7UL, 8UL );
				testSingleLinkedList_3.AddData( 7UL, 8UL );
				testSingleLinkedList_3.AddData( 7UL, 8UL );
				testSingleLinkedList_3.AddData( 7UL, 8UL );
				testSingleLinkedList_3.AddData( 7UL, 8UL );
				testSingleLinkedList_3.AddData( 7UL, 8UL );
				testSingleLinkedList_3.AddData( 7UL, 8UL );
				testSingleLinkedList_3.AddData( 7UL, 8UL );
				testSingleLinkedList_3.AddData( 7UL, 8UL );
				testSingleLinkedList_3.AddData( 7UL, 8UL );
				testSingleLinkedList_3.AddData( 7UL, 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( ( testSingleLinkedList_3.Size() - 1 ), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( testSingleLinkedList_3.Size(), 8UL );
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 0UL , 8UL);
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 21UL, 8UL );
				testSingleLinkedList_3.AddData( 22UL, 8UL );
				testSingleLinkedList_3.AddData( 23UL, 8UL );
				testSingleLinkedList_3.AddData( 24UL, 8UL );
				testSingleLinkedList_3.AddData( 25UL, 8UL );
				testSingleLinkedList_3.AddData( 26UL, 8UL );
				testSingleLinkedList_3.AddData( 27UL, 8UL );
				testSingleLinkedList_3.AddData( 28UL, 8UL );
				testSingleLinkedList_3.AddData( 29UL, 8UL );
				testSingleLinkedList_3.AddData( 30UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );
				testSingleLinkedList_3.AddData( 20UL, 8UL );

				// Remove all nodes
				while ( testSingleLinkedList_3.Size() > 0UL )
				{
					// Remove node
					testSingleLinkedList_3.RemoveData( testSingleLinkedList_3.Size() - 1UL );
				}

				// Check the assignment operator
				testSingleLinkedList_2 = testSingleLinkedList_1;

				// Remove all nodes
				while ( testSingleLinkedList_2.Size() > 0UL )
				{
					// Remove node
					testSingleLinkedList_2.RemoveData( testSingleLinkedList_2.Size() - 1UL );
				}

				// Check the assignment operator
				testSingleLinkedList_2 = testSingleLinkedList_1;

				// Remove a segment of nodes
				testSingleLinkedList_2.RemoveData( 1UL, ( testSingleLinkedList_2.Size() - 7UL ) );

				// Check that the size is correct
				Assert_Test_MACRO( testSingleLinkedList_2.Size() == ( testSingleLinkedList_1.Size() - ( testSingleLinkedList_1.Size() - 7UL ) ) );

				// Check the assignment operator
				testSingleLinkedList_3 = testSingleLinkedList_1;

				// Remove a segment of nodes
				testSingleLinkedList_3.RemoveData( 0UL, ( testSingleLinkedList_3.Size() - 45UL ) );

				// Check that the size is correct
				Assert_Test_MACRO( testSingleLinkedList_3.Size() == ( testSingleLinkedList_1.Size() - ( testSingleLinkedList_1.Size() - 45UL ) ) );

				// Check the assignment operator
				testSingleLinkedList_3 = testSingleLinkedList_1;

				// Remove a segment of nodes
				testSingleLinkedList_3.RemoveData( 564UL, ( testSingleLinkedList_3.Size() - 1UL - 564UL ) );

				// Check that the size is correct
				Assert_Test_MACRO( testSingleLinkedList_3.Size() == ( testSingleLinkedList_1.Size() - ( testSingleLinkedList_1.Size() - 565UL ) ) );

				// Check the assignment operator
				testSingleLinkedList_3 = testSingleLinkedList_1;

				// Remove a segment of nodes
				testSingleLinkedList_3.RemoveData( 0UL, testSingleLinkedList_3.Size() );

				// Check that the size is correct
				Assert_Test_MACRO( testSingleLinkedList_3.Size() == 0UL );

				// Create a random instance
				SingleLinkedList< UnsignedInteger64bits > testRandomInstance_1( GenerateRandomInstance, NumericRange< UnsignedInteger64bits >( 40000UL, 60000UL ) );

				// Add segment of nodes at the beginning 
				testSingleLinkedList_3.AddData( testRandomInstance_1, testRandomInstance_1.Size() );

				// Add segment of nodes at the end
				testSingleLinkedList_3.AddData( testRandomInstance_1, testRandomInstance_1.Size(), testSingleLinkedList_3.Size() );

				// Add segment of nodes at one before the end
				testSingleLinkedList_3.AddData( testRandomInstance_1, testRandomInstance_1.Size(), ( testSingleLinkedList_3.Size() - 1UL ) );

				// Add segment of nodes at the middle
				testSingleLinkedList_3.AddData( testRandomInstance_1, testRandomInstance_1.Size(), 300UL );
				testSingleLinkedList_3.AddData( testRandomInstance_1, testRandomInstance_1.Size(), 4008UL );
			}

		// )  //  End of debug tool











    }  //  Namespace Memory

}  //  Namespace Universe



#endif  // SINGLELINKEDLIST_HPP