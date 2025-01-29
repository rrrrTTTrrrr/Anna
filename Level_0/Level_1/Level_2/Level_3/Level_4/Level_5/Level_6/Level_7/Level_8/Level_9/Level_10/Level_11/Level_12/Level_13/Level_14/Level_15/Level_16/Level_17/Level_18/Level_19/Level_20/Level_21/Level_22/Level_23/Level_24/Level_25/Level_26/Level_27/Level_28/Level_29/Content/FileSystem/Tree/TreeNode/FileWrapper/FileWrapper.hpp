namespace Universe
{


namespace FileSystem
{



// Create a type definition for the string that will store the file content
using File = Language::StringWithSpecializedMemoryManager< Memory::MemoryManagerForConstantSizeAllocations >;



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
class FileWrapper
{
public:


	// Create a type definition for this object
	using SelfType = FileWrapper;


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
	inline FileWrapper();


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
	//			1. fileName - a universal reference to the file path
	//			2. doesExistInSecondaryMemory - a boolean with the value true if the directory exist in secondary memory, and false otherwise
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
	//		1. The path must not be empty
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< typename UniversalReferencePathType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferencePathType, Path >::Result == true )
	inline FileWrapper( UniversalReferencePathType&& path, const Boolean doesExistInSecondaryMemory = false );


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
	virtual ~FileWrapper();


	// This part will contain all the get and set methods for the members of the object :


	GetByConstantReference_FromMemberGetMethod_Creator( /* GetMethodName */ Name, /* MemberName */ member_path, /* MemberGetMethodName */ NamePathLeadsTo, /* MemberType */ Language::String )
	GetByConstantReference_Creator( /* GetMethodName */ GetPath, /* MemberName */ member_path, /* MemberType */ Path )
	GetByValue_Creator( /* GetMethodName */ DoesExistInSecondaryMemory, /* MemberName */ member_doesExistInSecondaryMemory, /* MemberType */ Boolean )
	GetByValue_FromNonConstantMemberGetMethod_Creator( /* GetMethodName */ WasFileChanged, /* MemberName */ member_wasFileChanged, /* MemberGetMethodName */ Load, /* MemberType */ Boolean )


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to notify other threads of execution that the current thread of execution is using the instance. This should
	//		be used each time before calling any of the other public methods of this class, to ensure that no other thread of execution
	//		will delete the instance during the call
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
    //      NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//      NONE
	//
	inline void Utilize();


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to notify other threads of execution that the current thread of execution has finished to use the instance
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
    //      NONE
	//
	//  Expectations :
	//
	//		1. The method 'Utilize' was called before this method was called
	//		2. 
	//
	//  Possible errors :
	//
	//      NONE
	//
	inline void Done();


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to check if other thread of execution is currently utilizing the directory instance
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
    //      True if other thread of execution is currently utilizing the directory instance, and false otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//      NONE
	//
	EnsureRetrunValueIsUsed inline Boolean IsCurrentlyUtilizedByOtherThreadsOfExecution();


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to download the file content from main memory to secondary memory, and reset the file instance
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
    //      NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//      NONE
	//
	inline void DownloadContentFromMainMemoryToSecondaryMemory();


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to view the file
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. callable - a constant reference to an invokable object, to execute on the file. the signature of the function that will be called must be :
	//
	//					ReturnType Function( const File&, AdditionalArgumentTypes... )
	//
	//          2. additionalArguments - any additional arguments needed
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
    //      The result from performing the action on the file
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//      1. The given invokable object might throw any exception it sees fit
	//		2.
	//
	template< typename ReturnType, typename... AdditionalArgumentTypes >
	EnsureRetrunValueIsUsed inline ReturnType ViewFile( const Callable< ReturnType ( const File&, AdditionalArgumentTypes... ) >& callable, AdditionalArgumentTypes... additionalArguments );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to edit the file
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. callable - a constant reference to an invokable object, to execute on the file. the signature of the function that will be called must be :
	//
	//					ReturnType Function( File&, AdditionalArgumentTypes... )
	//
	//          2. additionalArguments - any additional arguments needed
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
    //      The result from performing the action on the file
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//      1. The given invokable object might throw any exception it sees fit
	//		2.
	//
	template< typename ReturnType, typename... AdditionalArgumentTypes >
	EnsureRetrunValueIsUsed inline ReturnType EditFile( const Callable< ReturnType ( File&, AdditionalArgumentTypes... ) >& callable, AdditionalArgumentTypes... additionalArguments );


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


	// Create a type definition for the string memory handler
	using SelfPagesArrayType = Memory::PagesArray< Language::Character, Memory::MemoryManagerForConstantSizeAllocations >;


	// Disable all copy and move related methods, this include the copy constructor, move constructor, assignment operator and move assignment operator
	DisableCopyAndMove( FileWrapper );


	// The following objects will store the metafile, or in other words the file properties :

	// This string will store the absolute path to the file and the current file name
	Path member_path;

	// This boolean will store if the file exist on secondary memory
	Boolean member_doesExistInSecondaryMemory;

	// This boolean will store if the file needs to be loaded from secondary memory to main memory, in case it exists in secondary memory
	MultiThread::Atomic< Boolean > member_wasFileLoadedFromSecondaryMemory;

	// This spin wait loop will be used to block all threads of execution but one that will load the file from secondary memory to main
	// memory, if it exist there
	CentralProcessingUnit::SpinWaitLoop member_spinWaitLoop;

	// This boolean will be used to determine if this file needs to be downloaded to secondary memory. If the file already exist in 
	// secondary memory, it needs to be downloaded only if it was changed
	MultiThread::Atomic< Boolean > member_wasFileChanged;

	// This object will store the number of threads of execution using the file. This is needed only for the case, where a thread
	// of execution is trying to delete the file
	MultiThread::Atomic< SignedInteger64bits > member_numberOfThreadsOfExecutionUsingTheInstance;

	// This object will hold the file itself
	MultiThread::SharedResource< File > member_file;


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of
	// the interface, but rather help implement it :


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to load the file from secondary memory to main memory. The method will check if the file exist in secondary
	//		memory and if it does, it will load it
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
    //      NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//      NONE
	//
	inline void EnsureFileExistInMainMemory__Private();


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to load the file from secondary memory to main memory. The method will check if the file exist in secondary
	//		memory and if it does, it will load it
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. file - a reference to a file
	//			2. filePath - a constant reference to a path instance with the required file path
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
	//		1. The file path instance is not empty
	//		2. The file exist in secondary memory
	//		3.
	//
	//  Possible errors :
	//
	//      1. Hardware shit
	//		2.
	//
	static void LoadFileFromSecondaryMemoryToMainMemory__Private( File& file, const Path& filePath );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to download the file content from main memory to secondary memory, and reset the file instance
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
    //      NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//      NONE
	//
	void DownloadContentFromMainMemoryToSecondaryMemory__Private( File& file );
	

};  //  Class FileWrapper