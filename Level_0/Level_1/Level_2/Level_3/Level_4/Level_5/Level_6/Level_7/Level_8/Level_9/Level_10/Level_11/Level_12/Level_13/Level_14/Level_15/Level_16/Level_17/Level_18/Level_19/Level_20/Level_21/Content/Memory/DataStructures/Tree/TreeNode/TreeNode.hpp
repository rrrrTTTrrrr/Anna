namespace Universe
{


namespace Memory
{



// Class Information :
//
//  Purpose :
//
//		This object is part of the tree implementation. It acts as a node of the tree, it connectes the tree parts together. It stores
//		one pointer to an higher node in the hierarchy, and as much as needed pointers to lower nodes in the hierarchy. It can contain
//		data or not. Finally, each child node pointed by this instance, must contain a unique identifier, it can not point to two child
//		nodes with the same identifier
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
template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType = MainMemoryManager >
class TreeNode NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = TreeNode< DataType, IdentifierType, MemoryManagerType >;


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
	//			1. memoryHandlerName - the enumeration of the memory handler to use
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
	explicit inline TreeNode( const MemoryHandlerName memoryHandlerName = MemoryHandlerName::Vector );


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
	//			1. Identifier - a universal reference the node identifier
	//			2. parentNode - a pointer to the parent node
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
	//		1. The given pointer to the parent node is not NULL
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename UniversalReferenceIdentifierType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceIdentifierType, IdentifierType >::Result == true )
	explicit inline TreeNode( UniversalReferenceIdentifierType&& identifier, SelfType* const parentNode, const MemoryHandlerName memoryHandlerName = MemoryHandlerName::Vector );


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
	//			1. Identifier - a universal reference the node identifier
	//			2. parentNode - a pointer to the parent node
	//			3. data - a universal reference to the data to add
	//			4. memoryHandlerName - the enumeration of the memory handler to use
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
	//		1. The given pointer to the parent node is not NULL
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename UniversalReferenceIdentifierType, typename UniversalReferenceDataType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceIdentifierType, IdentifierType >::Result == true && CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceDataType, DataType >::Result == true )
	explicit inline TreeNode( UniversalReferenceIdentifierType&& identifier, SelfType* const parentNode, UniversalReferenceDataType&& data, const MemoryHandlerName memoryHandlerName = MemoryHandlerName::Vector );


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
	inline ~TreeNode();


	// This part will contain all the get and set methods for the members of the object :


	GetByConstantReference_Creator( /* GetMethodName */ Identify, /* MemberName */ member_identifier, /* MemberType */ IdentifierType )
	GetByValue_Creator( /* GetMethodName */ ParentNode, /* MemberName */ member_parentNode, /* MemberType */ SelfType* )
	GetByValue_FromMemberGetMethod_Creator( /* GetMethodName */ NumberOfChildNodes, /* MemberName */ member_childNodes, /* MemberGetMethodName */ Size, /* ReturnValueType */ UnsignedInteger64bits )
	GetByValue_Creator( /* GetMethodName */ UsedMemoryHandlerNameToStoreChildNodes, /* MemberName */ member_childNodes, /* MemberType */ MemoryHandlerName )


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to check if the node currently contains data
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
	//		A boolean with value true if the current node contains data, and false other wise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Boolean DoesContainData() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get a reference to data
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
	//		A reference to data
	//
	//  Expectations :
	//
	//		1. The node contains data
	//		2.
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline DataType& Data();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get a constant reference to data
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
	//		A constant reference to data
	//
	//  Expectations :
	//
	//		1. The node contains data
	//		2.
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline const DataType& Data() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to add data to this node
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
	//		1. The node does not contain data already
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< typename UniversalReferenceDataType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceDataType, DataType >::Result == true )
	inline void AddData( UniversalReferenceDataType&& data );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to remove the data in this node
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
	//		1. The node contains data
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void RemoveData();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to add a pointer to a child node
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			childNodePointer - a pointer with the memory address of the child node
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
	//		1. The given pointer to the child node is not NULL
	//		2. The child node parent node pointer is set to point to this node
	//		3. The identifier of the child node does not already exist in any other child node
	//		4.
	//
	//  Possible errors :
	//
	//      They will come
	//
	inline void AddChildNode( SelfType* const childNodePointer );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to remove a child node pointer at the given index
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			childNodePointer - the child node pointer that needs to be removed
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
	//		1. The given child node pointer to remove exist
	//		2. 
	//
	//  Possible errors :
	//
	//      They will come
	//
	inline void RemoveChildNode( SelfType* const childNodePointer );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to get a pointer to the required child node
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			index - the index of the required child node
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
    //      A pointer to the required child node
	//
	//  Expectations :
	//
	//		1. The given index is smaller then the number of child nodes
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline SelfType* GetChildNode( const UnsignedInteger64bits index ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use the method to switch between memory handlers that will store the child nodes
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
	inline void SwitchMemoryHandlerUsedToStoreChildNodes( const MemoryHandlerName newMemoryHandlerName );


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
	DisableCopyAndMove( TreeNode );


	// This object will store the identifier of the node
	IdentifierType member_identifier;

	// This object will store the data of the node
	DataType* member_data;

	// This object will store the pointer to the higher node in the tree hierarchy, the parent node
	SelfType* member_parentNode;

	// This sequential data structure will store the pointers to the lower nodes in the tree hierarchy, the child nodes
	SequentialDataStructure< SelfType* > member_childNodes;


};  //  Class TreeNode