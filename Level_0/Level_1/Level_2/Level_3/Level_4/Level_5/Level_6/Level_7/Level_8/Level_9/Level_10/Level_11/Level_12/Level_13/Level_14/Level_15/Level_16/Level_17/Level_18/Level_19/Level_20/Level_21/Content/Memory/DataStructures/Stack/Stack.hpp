namespace Universe
{


namespace Memory
{



// Why is the size of an empty class not zero?
//
// To ensure that the addresses of two different insances will be different. For the same reason, "new" always returns pointers to distinct instances.
// Consider :
//
//		class Empty
//		{}
//
//		void DoSomething()
//		{
//			Empty a;
//			Empty b;
//
//			if ( &a == &b )
//			{
//				std::cout << "Impossible - report error to compiler supplier" << std::endl;
//			}
//		
//		}
//
// There is an interesting rule that says that an empty base class need not be represented by a separate byte :
//
//		class Derived : public Empty
//		{
//			int a;
//			...
//		}
//
//		void DoOtherThing( Derived* pointer )
//		{
//			void* p1 = pointer;
//			void* p2 = &p->a;
//
//			if ( p1 == p2 )
//			{
//				std::cout << "Nice - good optimizer" << std::endl;
//			}
//
//		}
//
// This optimization is safe and can be most useful. It allows a programmer to use empty classes to represent very simple concepts without overhead.
// Some current compilers provide this "empty base class optimization"



// Class Information :
//
//  Purpose :
//
//		This object implements the concept of 'First In last Out'. This means that this container has two main operations, one is to push 
//		into the queue and another to pop off the queue. Each push adds an element to the beginning of the stack, and each pop takes off 
//		the element that was last pushed into the queue. It can be viewed as :
//
//				Push 	  Entries				 Entries		 
//				Pop		  pushed				 pushed
//						  later					 earlier
//
//				--->	 .......  X X X X X X X  .......         
//				<---
//
//  Description :
//
// 		1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
//		   providing 3 keywords :
//
//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
//						member is public all the encapsulation is lost, so it should be avoided in most cases
//
//			2. Protected - this part is for developing purposes, inheritance. A developer can inherit from this object and it will
//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few
//						   data members
//
//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this
//						 part will end with the suffix __Private
//
//		2. Template arguments :
//
//			1.
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType = Memory::MainMemoryManager >
class Stack NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = Stack< DataType, MemoryManagerType >;


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
	//			memoryHandlerName - the enumeration of the memory handler to use
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
	inline Stack( const MemoryHandlerName memoryHandlerName = MemoryHandlerName::Vector );


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
	//			1. memoryManagerPointer - a pointer to a memory manger. The pointr should be NULL if the main memory manager to be used
	//			2. memoryHandlerName - the enumeration of the memory handler to use
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
	inline Stack( MemoryManagerType* const memoryManagerPointer, const MemoryHandlerName memoryHandlerName = MemoryHandlerName::Vector );


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
	//		    other - a reference to the instance that should be copied
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
	inline Stack( const SelfType& other );


	// This macro will be used to add all the functionality that is similiar in each object ( beside the name of the object ). It is done
	// as a macro to allow simple text manipulation, instead of inherting it through an object, which becomes a problem when an object
	// inherits from 2 objects, the first is any object, but the second is an object that also inhrits from the first object. This can be
	// solved through virtual inheritance but then can only be one instance of it. Furthermore, each object in the system will need to
	// inherit from it, which will cause inheritance 'chaos'. Therefore, this macro will be used to add the following methods to each object :
	//
	//		1. Assigenment operator
	//		2. Move constructor
	//		3. Move assigenment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure( Stack )


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
	inline ~Stack() = default;


	// This part will contain all the get and set methods for the members of the object :


	GetByValue_FromMemberGetMethod_Creator( /* GetMethodName */ UsedMemoryHandlerName, /* MemberName */ member_stack, /* MemberGetMethodName */ UsedMemoryHandlerName, /* MemberType */  MemoryHandlerName )


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		Use the method to switch between memory handlers
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			newMemoryHandlerName - the new memory handler to use in the instance
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
	//		1. The current memory handler used is different then the new memory handler
	//		2.
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	inline void SwitchMemoryHandler( const MemoryHandlerName newMemoryHandlerName );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the size of the stack
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
	//		The size of the stack
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline UnsignedInteger64bits Size() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to push data to the top of the stack. This overload is to allow adding data to stack by taking the
	//		resources of the given instance, instead of copying it
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			data - a universal reference to the data to add
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
	template< typename UniversalReferenceDataType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceDataType, DataType >::Result == true )
	inline void PushIn( UniversalReferenceDataType&& data );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to pop out of the stack the top entry, and return a copy of the data inside it
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
	//		A copy of the data in the entry that was popped out
	//
	//  Expectations :
	//
	//		1. The stack size should be larger then 0
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline DataType PopOut();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the data inside the entry at the top of the stack
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
	//		A constant reference to the data inside the entry at the top of the stack
	//
	//  Expectations :
	//
	//		1. The stack size should be larger then 0
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline const DataType& PeakTop() const;


	// The following methods declare the overloaded operators for the object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to check if the this instance match the other
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a reference to the instance that should be compared with this object
	//
	//		Information returned to the user :
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
	EnsureRetrunValueIsUsed inline Boolean operator==( const SelfType& other ) const;


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
	//		    other - a reference to the instance that should be compared with this object
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
	EnsureRetrunValueIsUsed inline Boolean operator!=( const SelfType& other ) const;


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
		static inline void UnitTest() __attribute__ (( __unused__ ));

	)  //  End of debug tool


private:


	// This memory handler will store the data
	SequentialDataStructure< DataType > member_stack;


};  //  Class Stack