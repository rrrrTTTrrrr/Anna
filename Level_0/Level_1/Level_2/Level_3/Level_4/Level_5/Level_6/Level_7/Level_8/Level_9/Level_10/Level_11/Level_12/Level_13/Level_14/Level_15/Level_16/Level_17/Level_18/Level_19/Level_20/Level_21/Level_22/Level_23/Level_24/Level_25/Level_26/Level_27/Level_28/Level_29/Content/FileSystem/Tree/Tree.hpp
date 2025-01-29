namespace Universe
{


namespace FileSystem
{



// The following definitions are used to make the access to the tuple entries more clear. In other words it will provide an enumeration
// to the value instead of using the value itself :

// This definitions are for the tuple returned by the private methods - 'GetPointerToLastDirectoryThatExistsInMainMemory__Private' and 'LoadAllTheDirectoriesThatExistInSecondaryMemoryToMainMemoryAndGetPointerToLastDirectoryThatExistsInThePath__Private'
#define POINTER_TO_DIRECTORY 0
#define WAS_DIRECTORY_CREATED 1



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
//			1. IdentifierType - this type will be used to identify each node
//			2. DataType - the type of data each node will store
//			3. SequentialMemoryHandlerToStoreChildNodesPointersType - the sequential data structure type to store the child nodes
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
class Tree NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = Tree;


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
	inline Tree();


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
	inline ~Tree();


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to create the given path. The path can point to a directory or a file. In the path there can be multiple
	//		non existent directories, and they will be created
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			path - a constant reference to a path instance
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		In case the last directory or file that the path points to already exists, the method will return that it is already exist.
	//		If the file or directory were created it will return success
	//
	//  Expectations :
	//
	//		1. The path does not point to the root direcotry
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	EnsureRetrunValueIsUsed inline MultiThread::Result TryToCreatePath( const Path& path );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to remove the given path. The path can point to a directory or a file
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			path - a constant reference to a path instance
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		In case the last directory or file that the path points to does not exist, the method will return that it does not exist.
	//		If the last directory or file that the path points to exist, but other threads of execution are using it, then the method
	//		will return that it can't be removed since other threads of execution are using it. Finally, if the file or directory were
	//		removed it will return success
	//
	//  Expectations :
	//
	//		1. The path does not point to the root direcotry
	//		2. 
	//
	//  Possible errors :
	//
	//		NONE
	//
	EnsureRetrunValueIsUsed inline MultiThread::Result TryToRemovePath( const Path& path );


	// // Method Information :
	// //
	// //  Description :
	// //
	// //		Use this method to perform an action on a file. This overlaod of the method is for a function that does not have a return value
	// //
	// //  Required arguments :
	// //
	// //		User information needed :
	// //
	// //			1. pathToFile - a constant reference to a path instance that points to a file
	// //			2. invokableObject - a universal reference to an invokable object, the signature of the function that will be called must be :
	// //
	// //					void FunctionName( const File&, ArgumentTypes... )
	// //
	// //          3. arguments - any additional arguments needed
	// //
	// //		Information returned to the user :
	// //
	// //			NONE
	// //
	// //  Return value :
	// //
	// //		In case the file does not exist, the method will return that it does not exist. If the file exist and the action was executed on it
	// //		the method will return success
	// //
	// //  Expectations :
	// //
	// //		1. The path does not point to the root direcotry
	// //		2. The path points to a file
	// //		3.
	// //
	// //  Possible errors :
	// //
	// //      1. The given invokable object might throw any exception it sees fit
	// //		2.
	// //
	// template< typename InvokableObjectType, typename... ArgumentTypes >
	// EnsureRetrunValueIsUsed inline MultiThread::Result TryToPerfomAnActionOnFile( const Path& pathToFile, InvokableObjectType&& invokableObject, ArgumentTypes&&... arguments );


	// // Method Information :
	// //
	// //  Description :
	// //
	// //		Use this method to perform an action on a file. This overlaod of the method is for a function that has a return value
	// //
	// //  Required arguments :
	// //
	// //		User information needed :
	// //
	// //			1. pathToFile - a constant reference to a path instance that points to a file
	// //			2. invokableObject - a universal reference to an invokable object, the signature of the function that will be called must be :
	// //
	// //					ReturnType Function( const File&, ArgumentTypes... )
	// //
	// //			3. returnValue - a reference to an object where the result of the action can be stored
	// //          4. arguments - any additional arguments needed
	// //
	// //		Information returned to the user :
	// //
	// //			NONE
	// //
	// //  Return value :
	// //
	// //		In case the file does not exist, the method will return that it does not exist. If the file exist and the action was executed on it
	// //		the method will return success
	// //
	// //  Expectations :
	// //
	// //		1. The path does not point to the root direcotry
	// //		2. The path points to a file
	// //		3.
	// //
	// //  Possible errors :
	// //
	// //      1. The given invokable object might throw any exception it sees fit
	// //		2.
	// //
	// template< typename InvokableObjectType, typename ReturnValueType, typename... ArgumentTypes >
	// EnsureRetrunValueIsUsed inline MultiThread::Result TryToPerfomAnActionOnFile( const Path& pathToFile, InvokableObjectType&& invokableObject, ReturnValueType& returnValue, ArgumentTypes&&... arguments );


	// // Method Information :
	// //
	// //  Description :
	// //
	// //		Use this method to perform an action on all the files in the file system
	// //
	// //  Required arguments :
	// //
	// //		User information needed :
	// //
	// //			1. invokableObject - a universal reference to an invokable object, the signature of the function that will be called must be :
	// //
	// //					void Function( const File&, ArgumentTypes... )
	// //
	// //          2. arguments - any additional arguments needed
	// //
	// //		Information returned to the user :
	// //
	// //			NONE
	// //
	// //  Return value :
	// //
	// //		NONE
	// //
	// //  Expectations :
	// //
	// //		NONE
	// //
	// //  Possible errors :
	// //
	// //      1. The given invokable object might throw any exception it sees fit
	// //		2.
	// //
	// template< typename InvokableObjectType, typename... ArgumentTypes >
	// inline void PerfomActionOnAllFiles( InvokableObjectType&& invokableObject, ArgumentTypes&&... arguments );


	// // Method Information :
	// //
	// //  Description :
	// //
	// //		Use this method to perform an action on all the files under a specific directory
	// //
	// //  Required arguments :
	// //
	// //		User information needed :
	// //
	// //			1. directoryPath - a constant reference to a path instance that points to a directory
	// //			2. invokableObject - a universal reference to an invokable object, the signature of the function that will be called must be :
	// //
	// //					void Function( const File&, ArgumentTypes... )
	// //
	// //          3. arguments - any additional arguments needed
	// //
	// //		Information returned to the user :
	// //
	// //			NONE
	// //
	// //  Return value :
	// //
	// //		NONE
	// //
	// //  Expectations :
	// //
	// //		1. The path points to a directory
	// //		2.
	// //
	// //  Possible errors :
	// //
	// //      1. The given invokable object might throw any exception it sees fit
	// //		2.
	// //
	// template< typename InvokableObjectType, typename... ArgumentTypes >
	// inline void PerfomActionOnAllFiles( const Path& directoryPath, InvokableObjectType&& invokableObject, ArgumentTypes&&... arguments );


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
		//		NONE
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
	DisableCopyAndMove( Tree );


	// This object will store the memory address of the tree root node
	Directory* member_rootDirectoryPointer;


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of
	// the interface, but rather help implement it :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to download all the files content to secondary memory when destructing this instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. childDirectoriesPointers - a reference to the container of the directory that stores the sub directories
	//			2. currentDirectoryPointer - a pointer to the current directory
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
	//		1. The given pointer to the current directory must not be NULL
	//		2.
	//
	//  Possible errors :
	//
	//		NONE
	//
	inline void DownloadToSecondaryMemoryAndDeleteFromMainMemoryForDestructionRecursively__Private( SequentialDataStructure< Directory* >& childDirectoriesPointers, Directory* const currentDirectoryPointer );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to download all the files content of the current directory to secondary memory when destructing this instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			filesWrappersPointers - a reference to the container of the directory that stores the files
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
	inline void DownloadToSecondaryMemoryAllFilesOfDirectoryForDestructionRecursively__Private( SequentialDataStructure< FileWrapper* >& filesWrappersPointers );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to create the given path. It will recursively pass on the path and create it. The path can point to a directory
	//		or a file. In the path there can be multiple non existent directories, and they will be created
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. path - a constant reference to a path instance
	//			2. pathIndex - an index to point to the entry in the path that needs to be dealt with in this call
	//			3. currentDirectoryPointer - a pointer to the current directory
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		In case the last directory or file that the path points to already exists, the method will return that it is already exist.
	//		If the file or directory were created it will return success
	//
	//  Expectations :
	//
	//		1. The path does not point to the root direcotry
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	EnsureRetrunValueIsUsed inline MultiThread::Result TryToCreatePathRecursive__Private( const Path& path, const LargestUnsignedInteger pathIndex, Directory* const currentDirectoryPointer );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to create the child directory. I will search for the required child directory in the child directories 
	//		pointers container of the current directory, if it exist it will return a pointer to it. If it does not exist it will 
	//		create it and then return a pointer to it
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. childDirectoriesPointers - a reference to the child directories pointers container
	//			2. parentDirectoryPointer - a pointer to the parent directory
	//			3. path - a constant reference to a path instance
	//			4. pathIndex - an index to point to the entry in the path that needs to be dealt with in this call
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A tuple with a pointer to the child directory, and a boolean to notify the caller if the child directory was created or
	//		already existed. If it was created the boolean will be set to true
	//
	//  Expectations :
	//
	//		1. The path does not point to the root direcotry
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	EnsureRetrunValueIsUsed inline Memory::Tuple< Directory*, Boolean > SearchForChildDirectoryAndIfDoesNotExistCreateIt__Private( SequentialDataStructure< Directory* >& childDirectoriesPointers, Directory* const parentDirectoryPointer, const Path& path, const LargestUnsignedInteger pathIndex );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to create the file. I will search for the required file in the files pointers container of the current directory, 
	//		if it exist it will return a pointer to it. If it does not exist it will create it and then return a pointer to it
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. filesWrappersPointers - a reference to the files pointers container
	//			2. path - a constant reference to a path instance
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		If the file already existed, then the method will return that the file already exist. If it was created, then the method
	//		will return success
	//
	//  Expectations :
	//
	//		1. The path does not point to the root direcotry
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	EnsureRetrunValueIsUsed inline MultiThread::Result SearchForFileAndIfDoesNotExistCreateIt__Private( SequentialDataStructure< FileWrapper* >& filesWrappersPointers, const Path& path );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to remove the given path. It will recursively pass on the path and remove it. The path can point to a 
	//		directory or a file
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. path - a constant reference to a path instance
	//			2. pathIndex - an index to point to the entry in the path that needs to be dealt with in this call
	//			3. currentDirectoryPointer - a pointer to the current directory
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		In case the last directory or file that the path points to does not exist, the method will return that it does not exist.
	//		If the last directory or file that the path points to exist, but other threads of execution are using it, then the method
	//		will return that it can't be removed since other threads of execution are using it. Finally, if the file or directory were
	//		removed it will return success
	//
	//  Expectations :
	//
	//		1. The path does not point to the root direcotry
	//		2. 
	//
	//  Possible errors :
	//
	//		NONE
	//
	EnsureRetrunValueIsUsed inline MultiThread::Result TryToRmovePathRecursive__Private( const Path& path, const LargestUnsignedInteger pathIndex, Directory* const currentDirectoryPointer );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to search for the required child directory, and if it exists return a pointer to it
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. childDirectoriesPointers - a reference to the child directories pointers container
	//			2. path - a constant reference to a path instance
	//			3. pathIndex - an index to point to the entry in the path that needs to be dealt with in this call
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		If the required child direcotry exist, a pointer with the memory address of it will be returned. Otherwise NULL
	//
	//  Expectations :
	//
	//		1. The path does not point to the root direcotry
	//		2. 
	//
	//  Possible errors :
	//
	//		NONE
	//
	EnsureRetrunValueIsUsed inline Directory* TryToGetPointerChildDirectory__Private( const SequentialDataStructure< Directory* >& childDirectoriesPointers, const Path& path, const LargestUnsignedInteger pathIndex );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to remove a file
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. filesWrappersPointers - a reference to the container of the directory that stores the files
	//			2. path - a constant reference to a path instance
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		In case the last directory or file that the path points to does not exist, the method will return that it does not exist.
	//		If the last directory or file that the path points to exist, but other threads of execution are using it, then the method
	//		will return that it can't be currently removed. Finally, if the file or directory were removed it will return success
	//
	//  Expectations :
	//
	//		1. The path point to a file
	//		2. 
	//
	//  Possible errors :
	//
	//		NONE
	//
	EnsureRetrunValueIsUsed inline MultiThread::Result TryToRemoveFileWrapper__Private( SequentialDataStructure< FileWrapper* >& filesWrappersPointers, const Path& path );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to remove the file from main memory, and also from secondary memory if it exists there
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			fileWrapperPointer - a pointer with the memory address of the file to remove
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
	//		1. The given pointer to the file to remove is not NULL
	//		2. 
	//
	//  Possible errors :
	//
	//		NONE
	//
	inline void DeleteFileFromMainAndSecondaryMemoryIfExistsThere__Private( FileWrapper* const fileWrapperPointer );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to remove a directory and all its sub directories
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. childDirectoriesPointers - a reference to the container of the directory that stores the sub directories
	//			2. path - a constant reference to a path instance
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		In case the last directory that the path points to does not exist, the method will return that it does not exist. If the 
	//		last directory that the path points to exist, but other threads of execution are using it, the method will return that it
	//		can't be currently removed. Finally, if the file or directory were removed it will return success
	//
	//  Expectations :
	//
	//		1. The path point to a directory
	//		2. 
	//
	//  Possible errors :
	//
	//		NONE
	//
	EnsureRetrunValueIsUsed inline MultiThread::Result TryToRemoveAllDirectoryContent__Private( SequentialDataStructure< Directory* >& childDirectoriesPointers, const Path& path );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to remove all the sub directories of a directory
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. childDirectoriesPointers - a reference to the container of the directory that stores the sub directories
	//			2. currentDirectoryPointer - a pointer with the memory address of the current directory that the sub directories needs to be removed
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
	//		1. The given pointer to the directory is not NULL
	//		2. 
	//
	//  Possible errors :
	//
	//		NONE
	//
	inline void RemoveChildDirectoriesRecursively__Private( SequentialDataStructure< Directory* >& childDirectoriesPointers, Directory* const currentDirectoryPointer );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to remove all the files of a directory
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			filesWrappersPointers - a reference to the container of the directory that stores the files
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
	inline void RemoveAllFilesInTheDirectory__Private( SequentialDataStructure< FileWrapper* >& filesWrappersPointers );


	// // Method Information :
	// //
	// //  Description :
	// //
	// //		Use this method to recursively pass on the path, and if the required file exists it will execute the action on it. This 
	// //		overlaod of the method is for a function that does not have a return value 
	// //
	// //  Required arguments :
	// //
	// //		User information needed :
	// //
	// //			1. pathToFile - a constant reference to a path instance that points to a file
	// //			2. pathIndex - an index to point to the entry in the path that needs to be dealt with in this call
	// //			3. currentDirectoryPointer - a pointer to the current directory
	// //			4. invokableObject - a universal reference to an invokable object, the signature of the function that will be called must be :
	// //
	// //					void Function( const ResourceBuiltInType&, ArgumentTypes... )
	// //
	// //          5. arguments - any additional arguments needed
	// //
	// //		Information returned to the user :
	// //
	// //			NONE
	// //
	// //  Return value :
	// //
	// //		In case the file does not exist, the method will return that it does not exist. If the file exist and the action was executed on it
	// //		the method will return success
	// //
	// //  Expectations :
	// //
	// //		1. The path does not point to the root direcotry
	// //		2. The path points to a file
	// //		3.
	// //
	// //  Possible errors :
	// //
	// //      1. The given invokable object might throw any exception it sees fit
	// //		2.
	// //
	// template< typename InvokableObjectType, typename... ArgumentTypes >
	// EnsureRetrunValueIsUsed inline MultiThread::Result TryToPerformActionOnFileRecursive__Private( const Path& pathToFile, const LargestUnsignedInteger pathIndex, Directory* const currentDirectoryPointer, InvokableObjectType&& invokableObject, ArgumentTypes&&... arguments ) const;



	// // Method Information :
	// //
	// //  Description :
	// //
	// //		Use this method to recursively pass on the path, and if the required file exists it will execute the action on it. This
	// //		overlaod of the method is for a function that has a return value 
	// //
	// //  Required arguments :
	// //
	// //		User information needed :
	// //
	// //			1. pathToFile - a constant reference to a path instance that points to a file
	// //			2. pathIndex - an index to point to the entry in the path that needs to be dealt with in this call
	// //			3. currentDirectoryPointer - a pointer to the current directory
	// //			4. invokableObject - a universal reference to an invokable object, the signature of the function that will be called must be :
	// //
	// //					ReturnType Function( const ResourceBuiltInType&, ArgumentTypes... )
	// //
	// //			5. returnValue - a reference to an object where the result of the action can be stored
	// //          6. arguments - any additional arguments needed
	// //
	// //		Information returned to the user :
	// //
	// //			NONE
	// //
	// //  Return value :
	// //
	// //		In case the file does not exist, the method will return that it does not exist. If the file exist and the action was executed on it
	// //		the method will return success
	// //
	// //  Expectations :
	// //
	// //		1. The path points to a file
	// //		2. The given pointer to the current directory must not be NULL
	// //		3.
	// //
	// //  Possible errors :
	// //
	// //      1. The given invokable object might throw any exception it sees fit
	// //		2.
	// //
	// template< typename InvokableObjectType, typename ReturnValueType, typename... ArgumentTypes >
	// EnsureRetrunValueIsUsed inline MultiThread::Result TryToPerformActionOnFileRecursive__Private( const Path& pathToFile, const LargestUnsignedInteger pathIndex, Directory* const currentDirectoryPointer, InvokableObjectType&& invokableObject, ReturnValueType& returnValue, ArgumentTypes&&... arguments ) const;


	// // Method Information :
	// //
	// //  Description :
	// //
	// //		Use this method to try locating the file, in the files pointers container of the current direcotry. If it exists it will
	// //		notify other threads of execution that the current thread of execution needs to use the file, and return a pointer to it
	// //
	// //  Required arguments :
	// //
	// //		User information needed :
	// //
	// //			1. files - a reference to the files pointers container
	// //			2. pathToFile - a constant reference to a path instance that points to a file
	// //
	// //		Information returned to the user :
	// //
	// //			NONE
	// //
	// //  Return value :
	// //
	// //		If the file exist, a pointer with the memory address of it will be returned. Otherwise NULL
	// //
	// //  Expectations :
	// //
	// //		1. The path points to a file
	// //		2.
	// //
	// //  Possible errors :
	// //
	// //		NONE
	// //
	// EnsureRetrunValueIsUsed inline FileWrapper* SearchForFileAndIfExistReturnPointerToIt__Private( const SequentialDataStructure< FileWrapper* >& files, const Path& pathToFile ) const;


};  //  Class Tree