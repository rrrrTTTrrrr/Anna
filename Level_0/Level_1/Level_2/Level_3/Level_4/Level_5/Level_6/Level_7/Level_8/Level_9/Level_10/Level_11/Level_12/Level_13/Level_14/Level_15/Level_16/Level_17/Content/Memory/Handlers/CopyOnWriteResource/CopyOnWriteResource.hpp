namespace Universe
{


namespace Memory
{



// How to define a templated constructor of a template class outside the class declaration?
//
// Consider the following object :
//
//		template< typename Type >
//		class X
//		{
//
//			template< typename OtherType >
//			X( OtherType foo );
//
//		};
//
// To define the constructor outside of the class declaration the following syntax is needed :
//
//		template< typename Type >
//		template< typename OtherType >
//		X< Type >::X( OtherType foo )
//		{
//			...
//		}



// In a template constructor, the template arguments can not be specified explicitly because the constructor has no name on its own, and so no
// syntax for it. One of the ways is to use the template type as an argument to the constructor, and let the compiler deduce the type automatically!



// Class Information :
//
//  Purpose :
//
//		Use this object to wrap a resource with the copy on write functionality. The point is to avoid copying the resource, as long as no
//		changes are made to it. This means when an instance of this object is copied both instances will use the same resource, only if 
//		a write operation is about to happen, the resource will be copied for that instance, and than the change will happen on the copied
//		resource. Note - it is important to access the resource only through this object, and store the provided references. The object can
//		not know of those external references, and undefined behavior will be the result
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
template< Concepts::Raw Type, typename MemoryManagerType = MainMemoryManager >
class CopyOnWriteResource NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = CopyOnWriteResource< Type, MemoryManagerType >;


	// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
	// the compiler generates a basic behavior for them if possible :


	// Method Information :
	//
	//  Description :
	//
	//		Constructor, to allow creating the resource from arguments
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			argumentsNeededToConstruct - any arguments needed to construct a random instance of the resource
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
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2.
	//
	template< typename... ArgumentTypesNeededToConstruct >
	explicit inline CopyOnWriteResource( ArgumentTypesNeededToConstruct... argumentsNeededToConstruct );


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
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	inline CopyOnWriteResource( const SelfType& other );


	// Add the following infrastructure to the object :
	//
	//		1. Assigenment operator
	//		2. Move constructor
	//		3. Move assigenment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure( CopyOnWriteResource )


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
	inline ~CopyOnWriteResource();


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get a constant reference to the resource inside, that can be used to read from the resource
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
	//      A constant reference to the resource
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//      They will come
	//
	EnsureRetrunValueIsUsed inline const Type& View() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get a reference to the resource inside, that can be used to change the resource. if more than one instance
	//		is using the resource, it will be copied so that only this instance will be left with the changes
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
	//      A reference to the resource
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	EnsureRetrunValueIsUsed inline Type& Edit();


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
	EnsureRetrunValueIsUsed Boolean operator==( const SelfType& other ) const;


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


	// This pointer will store the memory address allocated on the heap for the template type object instance
	Type* member_resourcePointer;

	// This pointer will store the memory address of an integer allocated on the heap, to count the number of references using the resource
	SignedInteger64bits* member_usersCounterPointer;


};  //  Class CopyOnWriteResource