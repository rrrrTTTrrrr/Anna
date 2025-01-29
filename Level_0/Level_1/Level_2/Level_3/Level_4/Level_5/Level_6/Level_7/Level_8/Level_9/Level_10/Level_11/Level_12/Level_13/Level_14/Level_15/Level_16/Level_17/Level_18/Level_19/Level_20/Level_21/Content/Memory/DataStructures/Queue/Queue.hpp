namespace Universe
{


namespace Memory
{



// Deduction refers to the process of determining the type of a template parameter from a given argument. It applies to function templates, auto
// and few other cases ( e.g partial specialization ). For example, consider :
//
//		template< typename Type >
//		void Flow( std::list< Type > );
//
// Now if the function is used as 'Flow( X )', where X was declared as :
//
//		std::list< int > X;
//
// Then the template type is deduced as 'int', and the resulting specialization 'Flow< int >'.
//
// In order for deduction to work, the template parameter type that is to be deduced has to appear in a deducible context. In this example, the
// function parameter of 'Flow' is such a deducible context. That is, an argument in the function call expression allows us to determine what 
// the template parameter should be in order for the call expression to be valid.
//
// However there are non deduced contexts, where no deduction is possible. The canonical example is "a template parameter that appears to the
// left of a ::" :
//
//		template< typename Type >
//		class Anna;
//
// 		template< typename Type >
//		void FuckAnna( typename Anna< Type >::type );
//
// In this function template, the template argument is a non deduced context. Thus it cannot be be used as 'FuckAnna( X )' and deduce the template
// argument. The reason for this is that there is no "backwards correspondence" between arbitrary types and members. For example, the following
// specializations can be created :
//
//		template<>
//		class FuckAnna< int >
//		{
//			using type = double;
//		}
//
//		template<>
//		class FuckAnna< double >
//		{
//			using type = double;
//		}
//
//		template<>
//		class FuckAnna< char >
//		{
//			using type = short;
//		}
//
// As can be seen calling the function as 'FuckAnna( int() )' has two possible answers for the template argument!



// What are aggregates and why they are speical?
//
// Formal definition form the C++ standard - an aggregate is an array or a class with no user declared constructors, no private or protected 
// non static data members, no base classes, and no virtual functions!
//
// First of all, any array is an aggregate. A class can also be an aggregate, and although noting is said about structures and unions, they
// also can be aggregates. In C++ the term class referes to all classes, structures and unions. A class then can only be an aggregate if it
// satisfies the criteria from the above definitions. What do these criteria imply?
//
// 	1. This does not mean an aggregate class cannot have constructors, in fact it can have default consturctor, copy and move constructors as
//     long as they are implicitly decalred by the compiler, and not explicitly by the user
//
// 	2. No private or protected non static data members. It can have many private and protected member functions as well as many private and
//     protected static data members and member functions as needed and not violate the rules for aggregate classes
//
// 	3. An aggregate class can have a user defined copy assignment operator and destructor
//
// 	4. An array is an aggregate even if it has non aggregate class type as data
//
// Aggregates, unlike non aggregate calsses can be initialized with curly braces '{}'. For exmaple :
//
//		UnsignedInteger64bits Array[ size ] = { 1, 2, 3, ... };
//
// There are 4 cases :
//
//	1. The size is equal to the number of values - all the elements of the array are initialized
//
//	2. The size of the array is larger then number of values - only the first entries of the array are initialized with the values and the rest
//	   if possible are value initialized
//
//	3. The size of the array is smaller then number of values - the compiler will issue an error
//
//	4. In case the size of the array is not supplied, it is the same as case 1



// Class Information :
//
//  Purpose :
//
//		This object implements the concept of 'First In First Out'. This means that this container has two main operations, one is to push 
//		into the queue and another to pop off the queue. Each push adds an element to the end of the queue, and each pop takes off the 
//		element that was first pushed into the queue. It can be viewed as :
//
//				Push 	  Entries				 Entries		 Pop
//						  pushed				 pushed
//						  later					 earlier
//
//				--->	 .......  X X X X X X X  .......         --->
//
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
class Queue NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = Queue< DataType, MemoryManagerType >;


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
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline Queue( const MemoryHandlerName newMemoryHandlerName = MemoryHandlerName::Vector );


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
	inline Queue( const SelfType& other );


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
	ObjectInfrastructure( Queue )


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
	inline ~Queue() = default;


	// This part will contain all the get and set methods for the members of the object :


	GetByValue_FromMemberGetMethod_Creator( /* GetMethodName */ UsedMemoryHandlerName, /* MemberName */ member_queue, /* MemberGetMethodName */ UsedMemoryHandlerName, /* MemberType */  MemoryHandlerName )


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
	//		Use this method to get the size of the queue
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
	//		The size of the queue
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
	//		Use this method to push data to the top of the queue. This overload is to allow adding data to queue by taking the
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
	//		The size of the queue of this instance
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
	//		Use this method to pop out of the queue the top entry, and return a copy of the data inside it
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
	//		1. The queue size should be larger then 0
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
	//		Use this method to get the data inside the entry at the top of the queue
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
	//		A constant reference to the data inside the entry at the top of the queue
	//
	//  Expectations :
	//
	//		1. The queue size should be larger then 0
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
	SequentialDataStructure< DataType > member_queue;


};  //  Class Queue