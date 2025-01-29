namespace Universe
{


namespace Memory
{



// Class Information :
//
//  Purpose :
//
//		Artifical Inteligence
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
template< typename... PointerToDeleteInCaseAnExceptionWasThrownTypes >
class TryAllocatingMemoryInCaseAnExceptionWasThrownDeleteAllPreviousAllocatedMemory NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = TryAllocatingMemoryInCaseAnExceptionWasThrownDeleteAllPreviousAllocatedMemory< PointerToDeleteInCaseAnExceptionWasThrownTypes... >;


	// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
	// the compiler generates a basic behavior for them if possible :


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
	//			pointerToDeleteInCaseAnExceptionWasThrown - all the pointers that needs to be deleted in case an exception is thrown during the allocation of the new memory space
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
	explicit inline TryAllocatingMemoryInCaseAnExceptionWasThrownDeleteAllPreviousAllocatedMemory( PointerToDeleteInCaseAnExceptionWasThrownTypes... pointerToDeleteInCaseAnExceptionWasThrown );


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
	inline ~TryAllocatingMemoryInCaseAnExceptionWasThrownDeleteAllPreviousAllocatedMemory() = default;


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		This method will allocate memory space for the resource, and construct it using the given arguments. In case an exception
	//		is thrown along the process all the memory address pointed by the pointers will be deleted
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          argumentsNeedeToConstructResource - any argument needed to construct an instance of the resource
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      A pointer with the memory address of the new created resource
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
	template< typename ResourceToAllocateMemorySpaceForType, typename... argumentNeedeToConstructResourceTypes >
	EnsureRetrunValueIsUsed inline ResourceToAllocateMemorySpaceForType* AllocateResource( argumentNeedeToConstructResourceTypes... argumentsNeedeToConstructResource );


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


	// Disable all copy and move related methods, this include the copy constructor, move constructor, assignment operator and move assignment operator
	DisableCopyAndMove( TryAllocatingMemoryInCaseAnExceptionWasThrownDeleteAllPreviousAllocatedMemory );


	// This object will store the memory addresses that needs to be deleted, in case an exception is thrown during the allocation of the
	// new memory. The type of the memory address is needed to delete the memory space, as it tells what the size that was actually
	// allocated, but in order to store the pointers there is no need to know the type, therefore they will be stored as pointer to void
	void* member_pointersToDeleteInCaseAnExceptionWasThrown[ sizeof...( PointerToDeleteInCaseAnExceptionWasThrownTypes ) ];


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of
	// the interface, but rather help implement it :


	// Method Information :
	//
	//  Description :
	//
	//		This method will store all the given pointers into the array. This method is overloaded, and this version will be used as
	//		long as there are more then one pointer left to store
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. storeAtThisIndex - the index at which to store the exposed pointer
	//			2. exposedPointerToDeleteInCaseAnExceptionWasThrown - the pointer that will currently be stored in the array
	//			3. additionalExposedPointerToDeleteInCaseAnExceptionWasThrown - the pointer that will be stored in the next recursive call. This is needed to make sure that as long as there are more then one pointer, this version of the overloaded method will be called
	//			4. restOfPointerToDeleteInCaseAnExceptionWasThrown - the rest of the pointers that will be stored in later recursive calls
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
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
	template< typename ExposedPointerToDeleteInCaseAnExceptionWasThrownType, typename AdditionalExposedPointerToDeleteInCaseAnExceptionWasThrownType, typename... RestOfPointerToDeleteInCaseAnExceptionWasThrownTypes > 
	inline void StorePointers__Private( UnsignedInteger64bits storeAtThisIndex, ExposedPointerToDeleteInCaseAnExceptionWasThrownType exposedPointerToDeleteInCaseAnExceptionWasThrown, AdditionalExposedPointerToDeleteInCaseAnExceptionWasThrownType additionalExposedPointerToDeleteInCaseAnExceptionWasThrown, RestOfPointerToDeleteInCaseAnExceptionWasThrownTypes... restOfPointerToDeleteInCaseAnExceptionWasThrown );


	// Method Information :
	//
	//  Description :
	//
	//		This method will store all the given pointers into the array. This method is overloaded, and this version will be used when
	//		there is one pointer left to store
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. storeAtThisIndex - the index at which to store the exposed pointer
	//			2. exposedPointerToDeleteInCaseAnExceptionWasThrown - the pointer that will currently be stored in the array
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
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
	template< typename ExposedPointerToDeleteInCaseAnExceptionWasThrownType > 
	inline void StorePointers__Private( UnsignedInteger64bits storeAtThisIndex, ExposedPointerToDeleteInCaseAnExceptionWasThrownType exposedPointerToDeleteInCaseAnExceptionWasThrown );


	// Method Information :
	//
	//  Description :
	//
	//		This method will delete the memory space stored in the pointr. The pointer is choosen using the given index.This method is 
	//		overloaded, and this version will be used as long as there are more then one pointer left to store
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			deleteAtThisIndex - the index at which the pointer is stored in the array
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
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
	template< typename ExposedPointerToDeleteInCaseAnExceptionWasThrownType, typename AdditionalExposedPointerToDeleteInCaseAnExceptionWasThrownType, typename... RestOfPointerToDeleteInCaseAnExceptionWasThrownTypes > 
	inline void DeleteMemorySpacePointedByPointers__Private( UnsignedInteger64bits deleteAtThisIndex );


	// Method Information :
	//
	//  Description :
	//
	//		This method will store all the given pointers into the array. This method is overloaded, and this version will be used when
	//		there is one pointer left to delete
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			deleteAtThisIndex - the index at which the pointer is stored in the array
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
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
	template< typename ExposedPointerToDeleteInCaseAnExceptionWasThrownType > 
	inline void DeleteMemorySpacePointedByPointers__Private( UnsignedInteger64bits deleteAtThisIndex );


	// Assert all the requirements on the template arguments provided to the object. To perform a compile time assert the C++ language provides
	// the keyword 'static_assert', which receives an expression and an error message to display if the expression result is false. The important
	// thing is that the expression is evaluted during compile time, and therefore if the expression is false the compilation will be terminated
	// and the error message will be displayed. In this case it will ensure that all the template types are actually pointers
	CompileTimeAssert( ( DoesParameterPackContainsOnlyPointerTypes< PointerToDeleteInCaseAnExceptionWasThrownTypes... >::Result == true ), "Memory::TryAllocatingMemoryInCaseAnExceptionWasThrownDeleteAllPreviousAllocatedMemory failed - not all the given types in the templatep pack are pointers" );


};  //  Class TryAllocatingMemoryInCaseAnExceptionWasThrownDeleteAllPreviousAllocatedMemory