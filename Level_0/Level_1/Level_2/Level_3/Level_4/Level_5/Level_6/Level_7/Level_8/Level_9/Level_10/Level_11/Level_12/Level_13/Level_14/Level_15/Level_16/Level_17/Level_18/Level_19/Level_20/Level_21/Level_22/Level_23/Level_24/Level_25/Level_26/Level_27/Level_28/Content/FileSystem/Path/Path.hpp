namespace Universe
{


namespace FileSystem
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
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
class Path NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = Path;


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
	explicit inline Path( const MemoryHandlerName memoryHandlerName = MemoryHandlerName::Vector );


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
	//			1. absolutePath - a constant reference to an ascii literal instance that contains the absoulte path
	//			2. doesPointToFile - a boolean to notify if the last part of the path is a directory or a file name
	//			3. memoryHandlerName - the enumeration of the memory handler to use
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
	//		1. The given ascii literal instance size, that contains the path, is larger then 0
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	explicit inline Path( const AsciiLiteral& absolutePath, const Boolean doesPointToFile = false, const MemoryHandlerName memoryHandlerName = MemoryHandlerName::Vector );


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
	//			1. other - a constant reference to another path instance
	//			2. directoryOrFileNameToAdd - a universal reference to a string that contain the directory or file name to add to ending of this path
	//			3. isDirectory - a boolean that should contain the value true if the path leads to a directory, and false if it leads to a file
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
	template< Concepts::String UniversalReferenceStringType >
	explicit inline Path( const Path& other, UniversalReferenceStringType&& directoryOrFileNameToAdd, const Boolean isDirectory = false );


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
	//			1. other - a constant reference to another path instance
	//			2. sizeFromPathToInclude - the number of entries from the beginning of the path to include in this path
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
	//		1. The size from path to include must be smaller then the size of the path
	//		2. The size from path to include must be larger then 1, because the root directory already exist
	//		3.
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	explicit inline Path( const Path& other, const LargestUnsignedInteger sizeFromPathToInclude );


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
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	inline Path( const SelfType& other );


	// Add the following infrastructure to the object :
	//
	//		1. Assigenment operator
	//		2. Move constructor
	//		3. Move assigenment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure( Path )


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
	inline ~Path() = default;


	// This part will contain all the get and set methods for the members of the object :


	GetByValue_FromMemberGetMethod_Creator( /* GetMethodName */ Size, /* MemberName */ member_path, /* MemberGetMethodName */ Size, /* MemberType */ LargestUnsignedInteger )


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to add a directory name to end of the path
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    directoryName - a constant reference to a string with the directory name
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
	//		1. The given string with the directory name size must be larger then 0
	//		2. The path does not contain a file name at the end
	//		3. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	inline void AddDirectory( const Language::String& directoryName );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to add a directory name to end of the path
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    directoryName - an rvalue reference to a string with the directory name
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
	//		1. The given string with the directory name size must be larger then 0
	//		2. The path does not contain a file name at the end
	//		3. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	inline void AddDirectory( Language::String&& directoryName );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to add a file name to end of the path. After this operation the path can not be added any more parts
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    fileName - a constant reference to a string with the file name
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
	//		1. The given string with the file name size must be larger then 0
	//		2. The path does not contain a file name at the end
	//		3. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	inline void AddFile( const Language::String& fileName );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to add a file name to end of the path. After this operation the path can not be added any more parts
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    fileName - an rvalue constant reference to a string with the file name
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
	//		1. The given string with the file name size must be larger then 0
	//		2. The path does not contain a file name at the end
	//		3. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	inline void AddFile( Language::String&& fileName );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to remove the part the path currently points to. This means that after the removal the path will point to
	//		the directory that is located in the one before the last part of the path
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    NONE
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
	//		1. The path does not point to the 'Root' directory, it is the only part that can not be removed
	//		2. 
	//
	//  Possible errors :
	//
	//		NONE
	//
	inline void RemoveLastPart();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the last part of the path, it can either be a directory or file name
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
	//		A boolean with the value true if the path leads to a file, and false if it leads to a directory
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
	EnsureRetrunValueIsUsed inline Boolean DoesPointToFile() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the last part of the path, it can either be a directory or file name
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
	//		A constant reference to string in the last part of the path, it can either be a directory or file name
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
	EnsureRetrunValueIsUsed inline const Language::String& NamePathLeadsTo() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to convert the path to an ascii string. The format is :
	//
	//			/Part_1_of_path/Part_2_of_path/Part_3_of_path/Last_part_of_path
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			sizeFromPathToInclude - this size will be used to determine the number of parts from the path to include in the ascii 
	//									string. It will always start from the beginning until the required part
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The path as an ascii string
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
	EnsureRetrunValueIsUsed inline Memory::Vector< AsciiCharacter > ToAsciiString( const LargestUnsignedInteger sizeFromPathToInclude ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to convert the path to an ascii string. The format is :
	//
	//			/Part_1_of_path/Part_2_of_path/Part_3_of_path/Last_part_of_path
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
	//		The path as an ascii string
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
	EnsureRetrunValueIsUsed inline Memory::HeapPointer< AsciiCharacter > ToAsciiString() const;


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


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to get a constant reference to the required part of the path
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    index - the index of the required part of the path
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A constant reference to the required part of the path
	//
	//  Expectations :
	//
	//		1. The given index is smaller then path size
	//		2.
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline const Language::String& operator[]( const LargestUnsignedInteger index ) const;


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
		static void UnitTest() __attribute__ (( __unused__ ));

	)  //  End of debug tool


private:


	// This object will store the various parts of the path. It can contain directory names, and only at the last part a file name
	SequentialDataStructure< Language::String > member_path;

	// This object will store if the last part of the path contains a directory or a file. If the last part contains a file, no more
	// entries can be added to the path
	Boolean member_doesPathPointsToFile;


};  //  Class Path