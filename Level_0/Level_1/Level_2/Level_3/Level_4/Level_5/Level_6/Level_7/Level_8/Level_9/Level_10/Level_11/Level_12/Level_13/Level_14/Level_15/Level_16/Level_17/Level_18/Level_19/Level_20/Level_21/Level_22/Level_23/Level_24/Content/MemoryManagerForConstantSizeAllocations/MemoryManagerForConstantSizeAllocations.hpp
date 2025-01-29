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
class MemoryManagerForConstantSizeAllocations NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = MemoryManagerForConstantSizeAllocations;


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to allocate memory
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
	//		An heap pointer with the memory address to use
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
	template< typename Type >
	EnsureRetrunValueIsUsed static inline Type* AllocateAndDefaultConstruct( const LargestUnsignedInteger = 0UL );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to allocate memory space, and initialize it with the given arguments
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			constructorArguments - list of arguments the template type constructor requires
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A pointer with the memory address of the allocated memory space
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
	template< typename Type, typename... ConstructorArgumentTypes >
	EnsureRetrunValueIsUsed static inline Type* AllocateAndConstruct( ConstructorArgumentTypes&&... constructorArguments );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to free memory
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			pointerToMemoryToRelease - a pointer with the memory address to release
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
	//		1. The given pointer with the memory address to release is not NULL
	//		2. The given memory address to release is valid and marked as used, which means the address was provided by calling the 'Allocate' method
	//		3.
	//
	//  Possible errors :
	//
	//		NONE
	//
	template< typename Type >
	static inline void Done( const void* const pointerToMemoryToRelease, const Boolean = false );


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


	// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
	NoInstances( MemoryManagerForConstantSizeAllocations );


	// Static data members do not belong to any instance, they belong to the object. Like every global variable it is created with the
	// start of the program and only destroyed when the program ends. The access to the static member is bound to this object of course


	// This object will store the size in bytes of the memory
	static constexpr LargestUnsignedInteger member_sizeInBytes = GigaByte( 8UL );

	// This object will store the constant size to allocate with each request
	static constexpr LargestUnsignedInteger member_constantSizeToAllocateInBytes = MegaByte( 2UL );

	// This object will store the number of parts that the can be allocated from the memory
	static constexpr LargestUnsignedInteger member_numberOfPartsThatCanBeAllocated = member_sizeInBytes / member_constantSizeToAllocateInBytes;

	// This object will store the number of memory locations to store at maximum
	static constexpr LargestUnsignedInteger member_maximumNumberOfNextMemoryLocationsToStoreInLookupTable = 128UL;


	// This vector will store the memory needs to be managed
	static Vector< UnsignedInteger8bits > member_memory;

	// This bit array will manage the constant size parts of the memory, it will store which is used and which can be allocated
	static BitArray member_memoryManager;

	// This single linked list will store the next memory locations to allocate. This is an optimization to avoid searching the entire bit array
	// each time a memory needs to be allocated, and instead the bit array will be searched once all the locations here are used
	static LargestUnsignedInteger member_nextMemoryLocationsToAllocateLookupTable[ member_maximumNumberOfNextMemoryLocationsToStoreInLookupTable ];

	// This object will store the index to the next memory location to allocate in the lookup table
	static LargestUnsignedInteger member_nextMemoryLocationsToAllocateLookupTableIndex;

	// This object will store the function that should be called when the manager does not have anymore free memory space
	static Callable< void () > member_allMemoryIsUsedHandler;


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
	// rather help implement it :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to check if there is still free memory space that can be allocated
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
	//		A boolean with the value true, if there is still memory left to allocate, and false otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
	EnsureRetrunValueIsUsed static inline Boolean DoesFreeMemorySpaceExist__Private();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to search for the next memory location to provide
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
	//		NONE
	//
	static inline void SearchForNextFreeLocations__Private();


};  //  Class MemoryManagerForConstantSizeAllocations


// Allocate the requied memory from the main memory manager, and store the memory address inside the pointer
Vector< UnsignedInteger8bits > MemoryManagerForConstantSizeAllocations::member_memory( member_sizeInBytes );

// Initialize the bit array that will manage if the part of the memory is used or not
BitArray MemoryManagerForConstantSizeAllocations::member_memoryManager( member_numberOfPartsThatCanBeAllocated );

// Initialize the next locations that will be provided to the user
LargestUnsignedInteger MemoryManagerForConstantSizeAllocations::member_nextMemoryLocationsToAllocateLookupTable[ member_maximumNumberOfNextMemoryLocationsToStoreInLookupTable ] = { 0UL };

// Initialize the next memory location index
LargestUnsignedInteger MemoryManagerForConstantSizeAllocations::member_nextMemoryLocationsToAllocateLookupTableIndex = 0UL;

// Set the handler for the case there is no more free memory space
Callable< void () > MemoryManagerForConstantSizeAllocations::member_allMemoryIsUsedHandler( []() { std::cout << "Yeah" << std::endl; } );