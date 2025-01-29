namespace Universe
{


namespace FileSystem
{



// Class Information :
//
//  Purpose :
//
//		This object is part of the tree implementation. It acts as a directory of the tree, it connectes the tree parts together. It stores
//		one pointer to an higher directory in the hierarchy, and as much as needed pointers to lower directories in the hierarchy. It can contain
//		data or not. Finally, each child directory pointed by this instance, must contain a unique identifier, it can not point to two child
//		directories with the same identifier
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
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
class Directory NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = Directory;


	// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
	// the compiler generates a basic behavior for them if possible :


	// Method Information :
	//
	//  Description :
	//
	//		Default constructor, only the root of the tree should be created using this constructor
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
	inline Directory();


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
	//			1. path - a universal reference to a string with the directory path
	//			2. parentDirectoryPointer - a pointer to the parent directory of this directory
	//			3. doesExistInSecondaryMemory - a boolean used to descrive if the directory already exist in secondary memory
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
	//		1. The given path must be larger then 1
	//		2. The given pointer to the parent directory is not NULL
	//		3. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< typename UniversalReferencePathType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferencePathType, Path >::Result == true )
	inline Directory( UniversalReferencePathType&& path, SelfType* const parentDirectoryPointer, const Boolean doesExistInSecondaryMemory = false );


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
	inline ~Directory() = default;


	// This part will contain all the get and set methods for the members of the object :


	GetByConstantReference_FromMemberGetMethod_Creator( /* GetMethodName */ Name, /* MemberName */ member_path, /* MemberGetMethodName */ NamePathLeadsTo, /* MemberType */ Language::String )
	GetByConstantReference_Creator( /* GetMethodName */ GetPath, /* MemberName */ member_path, /* MemberType */ Path )
	GetByValue_Creator( /* GetMethodName */ ParentDirectory, /* MemberName */ member_parentDirectoryPointer, /* MemberType */ SelfType* )
	GetByValue_Creator( /* GetMethodName */ DoesExistInSecondaryMemory, /* MemberName */ member_doesExistInSecondaryMemory, /* MemberType */ Boolean )


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
	//      Use this method to view the container that stores the pointers to the child directories. The action to execute must not change
	//		the container
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. invokableObject - a universal reference to an invokable object, the signature of the function that will be called must be :
	//
	//					AnyReturnType Function( const SequentialDataStructure< Directory* >&, AdditionalArgumentTypes... )
	//
	//			2. disableLoading - an option to allow viewing the child directories without loading the content from secondary memory
	//          3. arguments - any additional arguments needed
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
    //      The result from performing the action on the child directories container
	//
	//  Expectations :
	//
	//		1. The resource will not be changed by the action
	//		2. 
	//
	//  Possible errors :
	//
	//      1. The given invokable object might throw any exception it sees fit
	//		2.
	//
	template< typename ReturnType, typename... AdditionalArgumentTypes >
	inline ReturnType ViewChildDirectories( const Callable< ReturnType ( const SequentialDataStructure< SelfType* >&, AdditionalArgumentTypes... ) >& callable, const Boolean disableLoading, AdditionalArgumentTypes... additionalArguments );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to edit the container that stores the pointers to the child directories
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. invokableObject - a universal reference to an invokable object, the signature of the function that will be called must be :
	//
	//					AnyReturnType Function( SequentialDataStructure< Directory* >&, AdditionalArgumentTypes... )
	//
	//			2. disableLoading - an option to allow viewing the child directories without loading the content from secondary memory
	//          3. arguments - any additional arguments needed
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
    //      The result from performing the action on the child directories container
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
	inline ReturnType EditChildDirectories( const Callable< ReturnType ( SequentialDataStructure< SelfType* >&, AdditionalArgumentTypes... ) >& callable, const Boolean disableLoading, AdditionalArgumentTypes... additionalArguments );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to view the container that stores the pointers to the files. The action to execute must not change
	//		the container
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. invokableObject - a universal reference to an invokable object, the signature of the function that will be called must be :
	//
	//					AnyReturnType Function( const SequentialDataStructure< File* >&, AdditionalArgumentTypes... )
	//
	//			2. disableLoading - an option to allow viewing the child directories without loading the content from secondary memory
	//          3. arguments - any additional arguments needed
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
    //      The result from performing the action on the files container
	//
	//  Expectations :
	//
	//		1. The resource will not be changed by the action
	//		2. 
	//
	//  Possible errors :
	//
	//      1. The given invokable object might throw any exception it sees fit
	//		2.
	//
	template< typename ReturnType, typename... AdditionalArgumentTypes >
	inline ReturnType ViewFilesWrappers( const Callable< ReturnType ( const SequentialDataStructure< FileWrapper* >&, AdditionalArgumentTypes... ) >& callable, const Boolean disableLoading, AdditionalArgumentTypes... additionalArguments );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to edit the container that stores the pointers to the files
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. invokableObject - a universal reference to an invokable object, the signature of the function that will be called must be :
	//
	//					AnyReturnType Function( SequentialDataStructure< File* >&, AdditionalArgumentTypes... )
	//
	//			2. disableLoading - an option to allow viewing the child directories without loading the content from secondary memory
	//          3. arguments - any additional arguments needed
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
    //      The result from performing the action on the files container
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
	inline ReturnType EditFilesWrappers( const Callable< ReturnType ( SequentialDataStructure< FileWrapper* >&, AdditionalArgumentTypes... ) >& callable, const Boolean disableLoading, AdditionalArgumentTypes... additionalArguments );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to collect all the names of child directories of this directory
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			pointers - a reference to a sequential data structure with the pointers to the child directories
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
    //      A sequential data structure with the required child directories names
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
	inline SequentialDataStructure< Language::String > ChildDirectoriesNames();


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to collect all the names of files of this directory
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			pointers - a reference to a sequential data structure with the pointers to the files wrappers
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
    //      A sequential data structure with the required files names
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
	inline SequentialDataStructure< Language::String > FilesNames();


	inline void DisplayContent();


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
	DisableCopyAndMove( Directory );


	// This string will store the absolute path to the directory and the current directory name
	Path member_path;

	// This object will store the pointer to the higher directory in the tree hierarchy, the parent directory
	SelfType* member_parentDirectoryPointer;

	// This boolean will store if the directory exist on secondary memory
	Boolean member_doesExistInSecondaryMemory;

	// This object will store if the directory content was loaded from secondary memory
	MultiThread::Atomic< Boolean > member_wasDirectoryContentLoadedFromSecondaryMemory;

	// This spin wait loop will be used to allow all the threads of execution to wait until the first thread of execution will load the
	// directory content from secondary memory
	CentralProcessingUnit::SpinWaitLoop member_spinWaitLoopToAllowThreadsOfExecutionToWaitUntilTheDirectoryContentWasLoadedFromSecondaryMemory;

	// This object will store the files of the directory. It will ensure correct behavior for multiple therads of execution
	MultiThread::SharedResource< SequentialDataStructure< FileWrapper* > > member_fileWrappersPointers;

	// This object will store the child directories of this directory. It will ensure correct behavior for multiple therads of execution
	MultiThread::SharedResource< SequentialDataStructure< SelfType* > > member_childDirectoriesPointers;

	// This object will store the number of threads of execution using the directory. This is needed only for the case, where a thread
	// of execution is trying to delete the directory
	MultiThread::Atomic< SignedInteger64bits > member_numberOfThreadsOfExecutionUsingTheInstance;


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of
	// the interface, but rather help implement it :


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to load the directory content from secondary memory if needed. The method will check first of all if the directory
	//		exist in secondary memory, if it does, it will check if the content was already loaded from secondary memory. If it wasn't it will
	//		load the content from secondary memory
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
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	inline void LoadDirectoryContentFromSecondaryMemoryIfNeeded__Private();


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to load the directory content from secondary memory
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
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	inline void LoadDirectoryContentFromSecondaryMemory__Private();


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to add the directories loaded from secondary memory to the child directories container
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. childDirectoriesPointers - a reference to the child directories container
	//			2. childDirectoriesNames - an rvalue reference to a sequential data structure with the names of the child directories loaded from secondary memory
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
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	inline void AddChildDirectoriesFromSecondaryMemory__Private( SequentialDataStructure< SelfType* >& childDirectoriesPointers, SequentialDataStructure< Language::String >&& childDirectoriesNames );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to add the files loaded from secondary memory to the files container
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. filesPointers - a reference to the files container
	//			2. filesNames - an rvalue reference to a sequential data structure with the names of the files loaded from secondary memory
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
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	inline void AddFilesFromSecondaryMemory__Private( SequentialDataStructure< FileWrapper* >& filesPointers, SequentialDataStructure< Language::String >&& filesNames );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to collect all the names of child directories or files of this directory
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			pointers - a reference to a sequential data structure with the pointers to the child directories or file wrappers
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
    //      A sequential data structure with the required names
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
	template< typename DirectoryOrFileWrapperType >
	inline SequentialDataStructure< Language::String > CollectNames__Private( const SequentialDataStructure< DirectoryOrFileWrapperType* >& pointers ) const;


};  //  Class Directory