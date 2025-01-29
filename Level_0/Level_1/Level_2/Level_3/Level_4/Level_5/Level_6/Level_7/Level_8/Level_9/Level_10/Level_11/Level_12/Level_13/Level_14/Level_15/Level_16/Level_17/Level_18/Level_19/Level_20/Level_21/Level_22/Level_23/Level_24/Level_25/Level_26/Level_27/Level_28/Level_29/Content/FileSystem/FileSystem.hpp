// namespace Universe
// {



// // Class Information :
// //
// //  Purpose :
// //
// //		Artifical Inteligence
// //
// //  Description :
// //
// //		1. This object is used only to wrap some static methods, which can be used without any instance of the object
// //
// //		2. This object has all the methods to create, destory, copy and move disabled to ensure that no instances of it will be created
// //
// // 		3. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
// //		   providing 3 keywords :
// //
// //			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
// //						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
// //						member is public all the encapsulation is lost, so it should be avoided in most cases
// //
// //			2. Protected - this part is for developing purposes, inheritance. A developer can inherit from this object and it will
// //						   be able to access all the data and methods inside this part. This part will usually containt some methods and few
// //						   data members
// //
// //			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
// //						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this
// //						 part will end with the suffix __Private
// //
// //  Expectations :
// //
// //		NONE
// //
// //  Possible errors :
// //
// //		Too many to count
// //
// class FileSystem NotForInheritance
// {
// public:


// 	// Create a type definition for this object
// 	using SelfType = FileSystem;


// 	// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object.
// 	// Satic functions only have access to static data members, which also don't belong to any instance, this means all other data members
// 	// can not be used. The only purpose then of declaring a static function is when a private static data member needs to be manipulated,
// 	// or some functionality needed that does not involve the non static data members


// 	// Method Information :
// 	//
// 	//  Description :
// 	//
// 	//      Use this method to get the total size in bytes that the instance use. It is true that there is the operator 'sizeof', which will
// 	//		return the size of the object in bytes. But the 'sizeof' operator has one disadvantage, it only takes into account the size of
// 	//		the members the object has. In case one of this members is a pointer or a reference, the instance can allocate more memory space
// 	//		beyond the members of the object, and the 'sizeof' operator will not take this into account. This method comes to solve this
// 	//		problem. It will provide the correct memory size used in bytes by the instance
// 	//
// 	//  Required arguments :
// 	//
// 	//      User information needed :
// 	//
// 	//          NONE
// 	//
// 	//      Information returned to the user :
// 	//
// 	//          NONE
// 	//
// 	//  Return value :
// 	//
// 	//      The memory size used by the instance
// 	//
// 	//  Expectations :
// 	//
// 	//		NONE
// 	//
// 	//  Possible errors :
// 	//
// 	//      They will come
// 	//
// 	static constexpr UnsignedInteger64bits MemorySizeUsedByInstanceInBytes();


// 	DEBUG_TOOL(

// 		// This part of the object is dedicated for testing :


// 		// Method Information :
// 		//
// 		//  Description :
// 		//
// 		//		This method is used to test the object. It is not part of the implementation, it is only used to find problems with the code
// 		//
// 		//  Required arguments :
// 		//
// 		//		User information needed :
// 		//
// 		//			NONE
// 		//
// 		//		Information returned to the user :
// 		//
// 		//			NONE
// 		//
// 		//  Return value :
// 		//
// 		//			NONE
// 		//
// 		//  Expectations :
// 		//
// 		//		Please let the test pass lord!!
// 		//
// 		//  Possible errors :
// 		//
// 		//		It says there are no problems, which is even scarier, did I just wrote a working code??
// 		//
// 		static void Test() __attribute__ (( __unused__ ));

// 	)  //  End of debug tool


// private:


// 	// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
// 	NoInstances( FileSystem )


// 	// Static data members do not belong to any instance, they belong to the object. Like every global variable it is created with the
// 	// start of the program and only destroyed when the program ends. The access to the static member is bound to this object of course


// 	// This object will store the file system in system memory
// 	static InvokeFunctionBeforeDestructor< Memory::Tree< Directory< Memory::HeapArray >, Language::String< Memory::HeapArray >, Memory::HeapArray >, FunctionPointer< void, Memory::Tree< Directory< Memory::HeapArray >, Language::String< Memory::HeapArray >, Memory::HeapArray > >& > member_fileSystemTree;

// 	// This object will store the directories needed to be deleted from the secondary memory
// 	static SequentialDataStructure< Language::String< Memory::HeapArray >, Memory::DoubleLinkedList > member_directoriesToDeleteFromSecondaryMemory;

// 	// This object will store the files needed to be deleted from the secondary memory
// 	static SequentialDataStructure< Language::String< Memory::HeapArray >, Memory::DoubleLinkedList > member_filesToDeleteFromSecondaryMemory;


// 	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of
// 	// the interface, but rather help implement it :


// };  //  Class FileSystem