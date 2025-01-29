namespace Universe
{


namespace Memory
{



// The keyword inline is not allowed in declaration of friend template specialization



// When declaring an outside template method friend with an class template, all instances of that methods no matter the template object are friends with all instances 
// of the object no matter the template object also here, meaning Read< int > will be friends with operator*< double >, Therefore this two declarations are made. 
// operator* is declared as a template method using a declared ( but not yet defined ) templated class. Pointer then defines the template instantiation of operator* 
// matching the template instantiation of Pointer as a friend. Note - no exception specification on purpose, becuase when using templates there is no way of knowing 
// what the given type will throw



// Operator "->" :
//
//  someClass->Something()
//
// Will be converted by the compiler to the following statement :
//
//  someClass.operator->()->Something()
//
// The first call to the overloaded operator-> gives a pointer of some type which has an accessible member function called Something



// C++ has two kinds of enumeration :
//
//  1. enum classes
//  2. Plain enums
//
//  Here are a couple of examples how to declare them :
//
//      enum class Color { red, green, blue }; // enum class
//      enum Animal { dog, cat, bird, human }; // plain enum 
//
// What is the difference between two?
//
//  enum classes - enumerator names are local to the enum and their values do not implicitly convert to other types ( like another enum or int )
//  Plain enums - where enumerator names are in the same scope as the enum and their values implicitly convert to integers and other types
//
// Enum classes should be preferred because they cause fewer surprises that could potentially lead to bugs



// To overload operator "++" for prefix and postfix use the following syntax :
//
//      class Number 
//      {
//      public:
//          Number& operator++ ();     // prefix ++: no parameter, returns a reference
//          Number  operator++ (int);  // postfix ++: dummy parameter, returns a value
//      };    



//      When using a pointer in C it can point to various locations in the memory of the program. It can point to location in the stack, heap, data and text segments.
//      Pointers can only be initialized by taking the address of an exisitng location in the stack, data, text, dynamically allocated heap location, mapped memory
//      and libraries allocating things. They can set to any of previous, and to other pointers. Pointer is actually an unsigned long integer describing the offset 
//      from the beginning of the program memory, this allows to C developers to assign an unsigned long integer to a pointer by casting it to the pointer type :
//
//          LargestUnsignedInteger address = 0x8080808080808080;
//
//          PointerType* pointer = ( PointerType* )address;
//
//      C pointers have the following operators :
//
//          *pointer                       ->  returns the pointed object
//          pointer->                      ->  used when the pointed object is a struct
//          pointer +,- integer            ->  adds or subtracts the integer times the size of the pointed object from the current address, and returns the result
//          pointer +=,-= integer          ->  adds or subtracts the integer times the size of the pointed object from the current address, and stores the result
//
//      Pointers can point to one object or they can point too many contigous objects, and then they have also :
//
//          pointer[ integer ]             ->  the same as *( pointer +,- integer ), returns the pointed object in the required address
//
//      Pointers are very useful because they only have an address and a type of an object, or in other words the size in bytes of the object, therefore they can be
//      casted to other type and then the data in the location will be understood differently.
//
//      One of the responsibilites of a C developer is to give back all the allocated resources, as fast as possible, for example :
//
//          void DoSomething( LargestUnsignedInteger size )
//          {
//              PointerType* heapMemory = ( PointerType* )malloc( size );
//
//              ...
//
//              free( heapMemory );
//          }
//
//      In general then, the resources are allocated in a specific scope, in this case the function DoSomething, and should be deleted when control leaves the scope of
//      the function. This is very important in big programs that use many resources, because the computer resources are limited after all.
//
//      This are the capabilites and required behavior of a C pointer.
//
//      Now, let's describe what needs to be added to a C pointer to improve it and create a C++ object from it :
//
//      1. The first thing is adding a size to each pointer. This is important to make sure the use of the pointer won't extended further then the required area 
//      
//      2. Providing all the operators a pointer have in C
//
//      3. To allow the user to give information about different parts of the memory segment, beside a pointer to the beginning



// Pure virtual methods needs to be redeclared in the derived object because :
//
//      1. The standard says so
//      2. It makes the compiler's work easier by not climbing up the hierarchy to check if such function exists
//      3. You might want to declare it lower in the hierarchy
//      4. In order to instantiate the class the compiler must know that this object is concrete



// User defined conversion :
//
// Enables implicit or explicit conversion from class type to another type. Conversion function is a method that has
// no parameters, no explicit return type, and has the form :
//
//          operator TYPE() { method body }
//
// For example :
//
//          class Jupiter
//          {
//          public:
//
//              operator int() { return m_int; }
//
//          private:
//
//              int m_int = 9;
//          };
//
// And then it can be used as :
//
//          Jupiter jupiter;
//
//          int small = jupiter;



// Member functions can be called from a constructor or destructor of an abstract class. The effect of making a virtual call to a pure 
// virtual function directly or indirectly for the object being create or destroyed from such a constrctor or destructor is undefined!



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
template< Concepts::RawButPointerIsAllowed DataType, typename IdentifierType, typename MemoryManagerType = MainMemoryManager >
class Tree NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = Tree< DataType, IdentifierType, MemoryManagerType >;

	// Create a type definition for the tree nodes
	using NodeType = TreeNode< DataType, IdentifierType, MemoryManagerType >;


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
	//		They will come
	//
	explicit inline Tree();


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
	inline Tree( const SelfType& other );


	// Add the following infrastructure to the object :
	//
	//		1. Assigenment operator
	//		2. Move constructor
	//		3. Move assigenment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure( Tree )


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


	// This part will contain all the get and set methods for the members of the object :


	GetByValue_Creator( /* GetMethodName */ Size, /* MemberName */ member_numberOfNodesWithData, /* MemberType */ LargestUnsignedInteger )


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to check if the given key exist in the instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			key - a constant reference to an instance with the identifiers that represent the path that needs to be taken to reach
	//				  the data associated with it. The instance must be of an object that implements the following method :
	//
	//					1. Size - to allow getting the number of identifiers in the key
	//					2. operator square brackets [] - to allow getiing access to each identifier
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		True if the given key exist in the instance, and false otherwise
	//
	//  Expectations :
	//
	//		1. The given key size is larger then 0
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename KeyType >
	EnsureRetrunValueIsUsed inline Boolean DoesKeyExist( const KeyType& key ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to insert data to the tree instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. key - a constant reference to an instance with the identifiers that represent the path that needs to be taken to reach
	//				     the data associated with it. The instance must be of an object that implements the following method :
	//
	//					1. Size - to allow getting the number of identifiers in the key
	//					2. operator square brackets [] - to allow getiing access to each identifier
	//
	//			2. data - the data to insert to the instance and associate with the key
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
	//		1. The given key size is larger then 0
	//		2. 
	//
	//  Possible errors :
	//
	//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
	//		2. 
	//
	template< typename KeyType, typename UniversalReferenceDataType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceDataType, DataType >::Result == true )
	inline void Insert( const KeyType& key, UniversalReferenceDataType&& data );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to remove the data associated with the key from the tree instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			key - a constant reference to an instance with the identifiers that represent the path that needs to be taken to reach
	//				  the data associated with it. The instance must be of an object that implements the following method :
	//
	//					1. Size - to allow getting the number of identifiers in the key
	//					2. operator square brackets [] - to allow getiing access to each identifier
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
	//		1. The given key size is larger then 0
	//		2. The key exist in the instance
	//		3. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename KeyType >
	inline void Remove( const KeyType& key );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to perform a certain action on all the entries of a tree instance
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			action - a constant reference to an invokable object. The signature must be :
	//
	//				Boolean SomeName( DataType&, const SequentialDataStructure< IdentifierType >& )
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		1. The tree instance is not empty
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< typename InvokableObject >
	inline void ForEachElementDo( InvokableObject&& action );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to perform a certain action that does not change the content of the instance on all the entries of a 
	//		tree instance
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			action - a constant reference to an invokable object. The signature must be :
	//
	//				Boolean SomeName( const DataType&, const SequentialDataStructure< IdentifierType >& )
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		1. The tree instance is not empty
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< typename InvokableObject >
	inline void ForEachElementDo( InvokableObject&& action ) const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to search for all the apperances of the given data in the tree instance
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			data - a constant reference to the data to search
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		A sequential data structure instance with the search results. An empty sequential data structure instance means the data does 
	//		not exist in the tree instance
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
	EnsureRetrunValueIsUsed inline SequentialDataStructure< SequentialDataStructure< IdentifierType > > Search( const DataType& data ) const;


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


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to get a reference to the required data
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			key - a constant reference to an instance with the identifiers that represent the path that needs to be taken to reach
	//				  the data associated with it. The instance must be of an object that implements the following method :
	//
	//					1. Size - to allow getting the number of identifiers in the key
	//					2. operator square brackets [] - to allow getiing access to each identifier
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A reference to the required data
	//
	//  Expectations :
	//
	//		1. The given key size is larger then 0
	//		2. The key exist in the instance
	//		3. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename KeyType >
	EnsureRetrunValueIsUsed inline DataType& operator[]( const KeyType& key );


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to get a constant reference to the required data
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			key - a constant reference to an instance with the identifiers that represent the path that needs to be taken to reach
	//				  the data associated with it. The instance must be of an object that implements the following method :
	//
	//					1. Size - to allow getting the number of identifiers in the key
	//					2. operator square brackets [] - to allow getiing access to each identifier
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A constant reference to the required data
	//
	//  Expectations :
	//
	//		1. The given key size is larger then 0
	//		2. The key exist in the instance
	//		3. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename KeyType >
	EnsureRetrunValueIsUsed inline const DataType& operator[]( const KeyType& key ) const;


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


	// This object will store the memory address of the tree root node
	NodeType* member_root;

	// This object will store the number of nodes with data, which can be considered the tree size
	LargestUnsignedInteger member_numberOfNodesWithData;


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of
	// the interface, but rather help implement it :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to recursively copy the content of other instance into this instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. nodeInOtherInstancePointer - the node to copy from the other instance
	//			2. parentNodeInThisInstancePointer - the parent node of the new node that is been copied in this instance
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
	//		1. The given pointer to the parent node in this instance is not NULL
	//		2. 
	//
	//  Possible errors :
	//
	//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
	//		2. 
	//
	inline void CopyNodesRecursively__Private( const NodeType* const nodeInOtherInstancePointer, NodeType* const parentNodeInThisInstancePointer );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to delete all the nodes of the instance
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
	inline void DeleteAllNodes__Private();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to recursively delete the nodes of this instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			nodePointer - the node to delete and recursively call the same method on all the child nodes
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
	//		1. The given pointer to the node is not NULL
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void DeleteNodesRecursively__Private( NodeType* const nodePointer );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get a pointer to a child node with the required identifier
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. nodePointer - a pointer to the node to search for the child node in it
	//			2. identifier - the identifier to search for in the child node
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A pointer to a child node with the required identifier if exist, otherwise NULL pointer
	//
	//  Expectations :
	//
	//		1. The given pointer to the node is not NULL
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline NodeType* GetChildNodeWithTheRequiredIdentifier__Private( const NodeType* const nodePointer, const IdentifierType& identifier ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to pass on the given key and return a pointer to the memory address of the last node that currently exist
	//		in the instance, that is part of the path represented by the key. The additional index returned is to allow checking if all
	//		the path represented by the key exist or not
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			key - a constant reference to an instance with the identifiers that represent the path that needs to be taken to reach
	//				  the data associated with it. The instance must be of an object that implements the following method :
	//
	//					1. Size - to allow getting the number of identifiers in the key
	//					2. operator square brackets [] - to allow getiing access to each identifier
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A tuple containing a pointer to the memory address of the last node that currently exist in the instance, that is part of the
	//		path represented by the key. The additional index returned is to allow checking if all the path represented by the key exist 
	//		or not
	//
	//  Expectations :
	//
	//		1. The given key size is larger then 0
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename KeyType >
	EnsureRetrunValueIsUsed inline Memory::Tuple< NodeType*, LargestUnsignedInteger > GetPointerToLastNodeThatCurrentlyExistInThePathRepresentedByTheKeyAndIndexForTheLocationOnTheKey__Private( const KeyType& key ) const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to recursively compare all the nodes in both instances
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. nodeInThisInstancePointer - a constant reference to a node in this instance
	//			2. nodeInOtherInstancePointer - a constant reference to a node in the other instance
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		True if all the nodes in the both instance match, and false otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
	EnsureRetrunValueIsUsed inline Boolean CompareNodesRecursively__Private( const NodeType* const nodeInThisInstancePointer, const NodeType* const nodeInOtherInstancePointer ) const;

	
	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get a pointer with the memory address of the node associated with the key
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			key - a constant reference to an instance with the identifiers that represent the path that needs to be taken to reach
	//				  the data associated with it. The instance must be of an object that implements the following method :
	//
	//					1. Size - to allow getting the number of identifiers in the key
	//					2. operator square brackets [] - to allow getiing access to each identifier
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A pointer with the memory address of the node associated with the key
	//
	//  Expectations :
	//
	//		1. A node associated with the key does exist
	//		2. The node associated with the key contains data
	//		3. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename KeyType >
	EnsureRetrunValueIsUsed inline NodeType* GetNodeAssociatedWithTheKey__Private( const KeyType& key );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to perform a certain action on all the entries of a tree instance. It will pass recursively on all the nodes
	//		and execute the action on each node that contains data
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. node - a pointer to a tree node
	//			2. key - a reference to a sequential data structure instance
	//			3. action - a constant reference to an invokable object. The signature must be :
	//
	//				Boolean SomeName( DataType&, const SequentialDataStructure< IdentifierType >& )
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		True if the there is no more need to pass on the nodes, and false otherwise. The point is to allow the caller to end the 
	//		recursion before it passed on all of the nodes, if a certian condition is met
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
	template< typename InvokableObject >
	EnsureRetrunValueIsUsed inline Boolean PassRecursivelyOnAllTheNodesAndExecuteTheRequiredAction__Private( NodeType* const node, SequentialDataStructure< IdentifierType >& key, InvokableObject&& action );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to perform a certain action that does not change the content of the instance on all the entries of a 
	//		tree instance. It will pass recursively on all the nodes and execute the action on each node that contains data
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. nodePointer - a pointer to a tree node
	//			2. key - a reference to a sequential data structure instance
	//			3. action - a constant reference to an invokable object. The signature must be :
	//
	//				Boolean SomeName( const DataType&, const SequentialDataStructure< IdentifierType >& )
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		True if the there is no more need to pass on the nodes, and false otherwise. The point is to allow the caller to end the 
	//		recursion before it passed on all of the nodes, if a certian condition is met
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
	template< typename InvokableObject >
	EnsureRetrunValueIsUsed inline Boolean PassRecursivelyOnAllTheNodesAndExecuteTheRequiredAction__Private( NodeType* const nodePointer, SequentialDataStructure< IdentifierType >& key, InvokableObject&& action ) const;


};  //  Class Tree