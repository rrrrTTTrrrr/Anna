namespace Universe
{


namespace Memory
{


// Constructor of derived object, when called, all the base class constructors are executed first, according to the order they appear in the class 
// declaration, and only then the user code is executed
//
// Destructor of derived object, when it is called, the user code existing in the destructor itself is executed first and then all the destructors 
// of the base objects, in an opposite way from which they were constructed



// When catching an exception, after performing all the required operations, and even changing the exception instance itself, the exception can be
// rethrown to notify the caller of the code of the problem. To throw the same instance use only the keywrod 'throw', to throw new instance use 
// the keyword 'throw' with the name of the specific instance to throw



// Change default values during run time :
//
//		class DefaultValueChanger
//		{
//		public:
//
//			void DisplayDefaultValue( LargestUnsignedInteger newDefaltValue = member_defautValue )
//			{
//				std::cout << newDefaltValue << std::cout;
//			}
//	
//			void SetDefaultValue( LargestUnsignedInteger newDefaultValue )
//			{
//				member_defautValue = newDefaultValue;
//			}
//
//		private:
//
//			static LargestUnsignedInteger member_defautValue;
//
//		};
//
//		LargestUnsignedInteger DefaultValueChanger::member_defautValue = 0UL;
//
//		int main
//		{
//			DefaultValueChanger defaultValueChangerInstance;
//
//			defaultValueChangerInstance.DisplayDefaultValue();
//
//			defaultValueChangerInstance.SetDefaultValue( 8UL );
//
//			defaultValueChangerInstance.DisplayDefaultValue();
//		}
//
// A default argument to a function doesn't have to be a constant expression, it just has to be "available" at every place the function is 
// called. And a static variable is just that. It also doesn't have to be accessible at the call site. So if the class should control that
// it is possible to make it private



// Static constant expression data member :
//
// Static data members are not associated with any object. They exist even if no objects of the class have been defined. There is only
// one instance of the static data member in the entire program with static storage duration.
//
// A static data member may be declared 'inline'. An inline static data member can be defined in the class definition and may specifiy
// an initializer. It does not need an out of class definition :
//
//		class X
//		{
//			static inline int number = 1;
//		}
//
// If a static data member is declared 'constexpr', it is implicitly 'inline' and does not need to be redecalred at namespace scope :
//
//		class X
//		{
//			static constexpr int number = 1;
//		}



// Template Class Information :
//
//  Purpose :
//
//		Use this object to store multiple instances of the same type. The instances will not be stored in contigous memory space, but rather
//		as seperated nodes connected through pointers. Each node will have a pointer to the next node in the list. This allows making changes
//		without the needs to copy large amout of contigous memory spaces, in other words changes in this platform cost very little in terms
//		of performance. This is a single linked list which means the current node only knows about the next node, and therefore passes on this
//		platform are only in one direction
//
//  Description :
//
//		1. This object contains an instance of the object "InstnaceState" to allow each instance of this object to have a defined state
//
// 		2. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
//		   providing 3 keywords :
//
//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
//						member is public all the encapsulation is lost, so it should be avoided in most cases
//
//			2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will
//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few
//						   data members
//
//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this
//						 part will end with the suffix __Private
//
//		3. Template arguments :
//
//			1. DataType - any type
//
//		4. If a node needs to be added at index 2 then :
//
//				Currently the singled linked list looks :
//
//					--------------	--------------	--------------	--------------	  
//					| Old Node 0 |	| Old Node 1 |	| Old Node 2 |	| Old Node 3 |	...
//					--------------	--------------	--------------	--------------  
//
//				After the addition :
//
//														Added 	  Moved up by 1 index
//														  |				   |
//					--------------	--------------	--------------	--------------	--------------	  
//					| Old Node 0 |	| Old Node 1 |	| New Node 2 |	| Old Node 3 |	| Old Node 4 |	...
//					--------------	--------------	--------------	--------------	-------------- 
//
//			As can be seen all the nodes that exist in the single linked list before the addition, starting from the node with the required index,
//			will be moved one index up
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType = MainMemoryManager >
class SingleLinkedList
{
public:


	// Create a type definition for this object
	using SelfType = SingleLinkedList< DataType, MemoryManagerType >;

	// Create a type definition for the nodes of this object
	using NodeType = SingleLinkedListNode< DataType >;

    // Create a type definition for the data
    using SelfDataType = DataType;


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
	//      Information returned to the user :
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
	inline SingleLinkedList();


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
	//			1. size - the number of entries in the single linked list
	//			2. data - a constant reference to the data that will be used to initialize all the nodes
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
	//		1. The given size is larger then 0
	//		2. 
	//
	//  Possible errors :
	//
	//		1. No more free memory space exist in the heap - Class Error::Exception is thrown
	//		2. 
	//
	explicit inline SingleLinkedList( const LargestUnsignedInteger size, const DataType& data = ActAccordingToType::GetDefaultInstance< DataType >() );


	// Method Information :
	//
	//  Description :
	//
	//		Constructor, to allow copying only from the given index on the other instance until the given size
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. other - a constant reference to other memory handler instance
	//			2. startingIndexOnOtherInstance - the index of the first entry that should be copied from the other instance
	//			3. sizeFromOther - the size from the other instance to copy to this instance
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
	//		1. The size of the other instance should be larger then 0
	//		2. The index to start from on the other instance should be smaller then the size of the other instance
	//		3. The size from other to copy must be larger then 0
	//		4. The size of the other instance minus the index to start from should be larger or equal then the size to copy
	//		5.
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
    template< template< typename, typename > class OtherMemoryHandlerType, typename OtherMemoryHandlerMemoryManagerType = MainMemoryManager >
	explicit inline SingleLinkedList( const OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >& other, const LargestUnsignedInteger startingIndexOnOtherInstance, const LargestUnsignedInteger sizeFromOther );


	// Method Information :
	//
	//  Description :
	//
	//		Constructor, to allow copying only from the given index on the other instance until the given size. This overload is for
	//		rvalue reference, it will move the data from the other instance instead of copying it
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. other - an rvalue reference to other memory handler instance
	//			2. startingIndexOnOtherInstance - the index of the first entry that should be copied from the other instance
	//			3. sizeFromOther - the size from the other instance to copy to this instance
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
	//		1. The size of the other instance should be larger then 0
	//		2. The index to start from on the other instance should be smaller then the size of the other instance
	//		3. The size from other to copy must be larger then 0
	//		4. The size of the other instance minus the index to start from should be larger or equal then the size to copy
	//		5.
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
    template< template< typename, typename > class OtherMemoryHandlerType, typename OtherMemoryHandlerMemoryManagerType = MainMemoryManager >
	explicit inline SingleLinkedList( OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >&& other, const LargestUnsignedInteger startingIndexOnOtherInstance, const LargestUnsignedInteger sizeFromOther );


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
	//			other - a reference to the instance that should be copied
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
	//		1. No more free memory space exist in the heap - Class Error::Exception is thrown
	//		2. 
	//
	inline SingleLinkedList( const SelfType& other );


	// Add the following infrastructure to the object :
	//
	//		1. Assignment operator
	//		2. Move constructor
	//		3. Move assignment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure_ForInheritance( SingleLinkedList )


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
	//      Information returned to the user :
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
	virtual ~SingleLinkedList();


	// This part will contain all the get and set methods for the members of the object :


	GetByValue_Creator( /* GetMethodName */ Size, /* MemberName */ member_size, /* MemberType */ LargestUnsignedInteger )


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the size in bytes of the data in the instance
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
	//		The size of the data in the instance multiplied by the data type size in bytes
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
    EnsureRetrunValueIsUsed inline LargestUnsignedInteger SizeInBytes() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the size in bytes of the data type used in the object
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
	//		The size of the data type used in the object
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
    EnsureRetrunValueIsUsed inline LargestUnsignedInteger DataTypeSizeInBytes() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to add data to the instance. The data will be added at the provided index, which means that after the
	//		addition accessing the data with the given index will return the currently added data, furthermore the data currently represented
	//		by the index will be advanced one index up, as well as all the rest of the data above the index
	//
	//		Note 1 - if the data should be added to the end of the instance, provide as index the current size of the instance
	//		Note 2 - if the instance is in default state, the only valid index to insert datat to is 0
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. addTheDataAtThisIndex - the index in which the data should be added
	//			2. data - a universal reference to the data to add
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
	//		1. The given index should be smaller or equal to the instance size
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	template< typename UniversalReferenceDataType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceDataType, DataType >::Result == true )
    inline void InsertSingleElement( const LargestUnsignedInteger addTheDataAtThisIndex, UniversalReferenceDataType&& data );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to add data to the instance. The data will be added starting from the provided index. This overload is
	//		to allow constructing the data instance from arguments
	//
	//		Note 1 - if the data should be added to the end of the instance, provide as index the current size of the instance
	//		Note 2 - if the instance is in default state, the only valid index to insert datat to is 0
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. addTheDataAtThisIndex - the index at which the data will be inserted to
    //			2. anyArgumentNeededToConstructDataIstance - any arguments needed to construct an instance of the data
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
	//		1. The index to add the data must be smaller or equal to the size of the memory handler
	//		2. There is a constructor of the data object that accepts the given arguemnts
	//		3. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
    template< typename... AnyArgumentNeededToConstructDataInstanceTypes >
	inline void InsertSingleElementCreateFromArguments( const LargestUnsignedInteger addTheDataAtThisIndex, AnyArgumentNeededToConstructDataInstanceTypes&&... anyArgumentNeededToConstructDataIstance );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to add data to the instance. The data will be added starting from the provided index. This overload is
	//		to allow adding the same data to multiple entries
	//
	//		Note 1 - if the data should be added to the end of the instance, provide as index the current size of the instance
	//		Note 2 - if the instance is in default state, the only valid index to insert datat to is 0
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. addTheDataAtThisIndex - the index in which the data should be added in the instance
	//			2. sizeToAdd - the number of elements to add
	//			3. data - the data the will be store in the new entries
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
	//		1. The first index to add should be smaller or equal to the size of this instance
	//		2.
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
    inline void InsertMultipleTimesTheSameElement( const LargestUnsignedInteger addTheDataAtThisIndex, const LargestUnsignedInteger sizeToAdd, const DataType& data = DataType() );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to add data to the instance. The data will be added starting from the provided index. It allows setting the
	//		data starting from an offset on the other instance until the required size
	//
	//		Note 1 - if the data should be added to the end of the instance, provide as index the current size of the instance
	//		Note 2 - if the instance is in default state, the only valid index to insert datat to is 0
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. other - a constant reference to other memory handler
	//			2. firstIndexInThisInstance - the index at which the data from the other instance needs to be inserted to
	//			3. firstIndexOnOtherInstance - the index of the first entry to insert from the other instance
	//			4. sizeToAdd - the size from the other instance to insert
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
	//		1. The other instance size should be larger then 0
	//		2. The index to start from on the this instance should be smaller then the size of this instance
	//		3. The index to start from on the other instance should be smaller then the size of the other instance
	//		4. This instance size minus index to start from on this instance should be equal or larger then the size to set
	//		5. The other instance size minus index to start from on the other instance should be equal or larger then the size to set
	//		6.
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
    template< template< typename, typename > class OtherMemoryHandlerType, typename OtherMemoryHandlerMemoryManagerType = MainMemoryManager >
    inline void InsertElementsFromOtherInstance( const OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >& other, const LargestUnsignedInteger firstIndexInThisInstance, const LargestUnsignedInteger firstIndexOnOtherInstance, const LargestUnsignedInteger sizeToAdd );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to add data to the instance. The data will be added starting from the provided index. It allows setting 
	//		the data starting from an offset on the other instance until the required size. This overload is for rvalue reference
	//		instances, that the data can be moved from and there is no need to copy
	//
	//		Note 1 - if the data should be added to the end of the instance, provide as index the current size of the instance
	//		Note 2 - if the instance is in default state, the only valid index to insert datat to is 0
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. other - a constant reference to other memory handler
	//			2. firstIndexInThisInstance - the index at which the data from the other instance needs to be inserted to
	//			3. firstIndexOnOtherInstance - the index of the first entry to insert from the other instance
	//			4. sizeToAdd - the size from the other instance to insert
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
	//		1. The other instance size should be larger then 0
	//		2. The index to start from on the this instance should be smaller then the size of this instance
	//		3. The index to start from on the other instance should be smaller then the size of the other instance
	//		4. This instance size minus index to start from on this instance should be equal or larger then the size to set
	//		5. The other instance size minus index to start from on the other instance should be equal or larger then the size to set
	//		6.
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
    template< template< typename, typename > class OtherMemoryHandlerType, typename OtherMemoryHandlerMemoryManagerType = MainMemoryManager >
    inline void InsertElementsFromOtherInstance( OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >&& other, const LargestUnsignedInteger firstIndexInThisInstance, const LargestUnsignedInteger firstIndexOnOtherInstance, const LargestUnsignedInteger sizeToAdd );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to add data to the instance. The data will be added starting from the provided index
	//
	//		Note 1 - if the data should be added to the end of the instance, provide as index the current size of the instance
	//		Note 2 - if the instance is in default state, the only valid index to insert datat to is 0
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. dataPointer - a pointer with the memory address of the data
	//			2. addTheDataAtThisIndex - the index at which the data needs to be inserted to
	//			3. dataSize - the size of the data the pointer points to
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
	//		1. The given pointer to the data is not NULL
	//		2. The index to start from on the this instance should be smaller then the size of this instance
	//		3. The data size should be larger then 0
	//		4. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	inline void InsertElementsFromRawData( const DataType* const dataPointer, const LargestUnsignedInteger addTheDataAtThisIndex, const LargestUnsignedInteger dataSize );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to remove data. The data will be added at the provided index, which means that after the removal the data 
	// 		currently represented by the index plus one will be drawn back one index down, as well as all the rest of the data above 
	//		the index
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. indexOfFirstDataToRemove - the first index from which data should be removed
	//			2. sizeToRemove - the number of entries to remove
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
	//		1. The instance should be ready
	//		2. The given index to remove the data plus the size to remove must result in a sum smaller or equal to the instance size
	//		3. 
	//
	//  Possible errors :
	//
	//		NONE
	//
	inline void Remove( const LargestUnsignedInteger indexOfFirstDataToRemove, const LargestUnsignedInteger sizeToRemove );


	// The following methods declare the overloaded operators for the object :


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to check if the this instance match the other
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			other - a constnt reference to a single linekd list instance
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//      1. true - if the 2 instances are the same
	//      2. false - otherwise
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
	//      Use this operator to check if the this instance does not match the other
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			other - a reference to the instance that should be compared with this object
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//      1. true - if the 2 instances are not the same
	//      2. false - otherwise
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
	//			index - the index of the required data
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
	//		1. The instance should be ready
	//		2. The given index is smaller then the single linked list size
	//		3. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline DataType& operator[]( const LargestUnsignedInteger index );


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
	//			index - the index of the required data
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
    //      A constant reference to the required data
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. The given index is smaller then the single linked list size
	//		3. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline const DataType& operator[]( const LargestUnsignedInteger index ) const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to add the content of another instance to the end of this instance
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			other - a reference to the instance that should be concatenated to the end of this instance
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A referene to this instance
	//
	//  Expectations :
	//
	//		1. The other instance must be ready
	//		2. The other instance size must be larger then 0
	//		3.
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	inline SelfType& operator+=( const SelfType& other );


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


	// This object will be the root of the single linked list instance
	NodeType* member_root;

	// This object will store the memory address of the last node in the single linked list instance
	NodeType* member_lastNode;

	// This object will store the number of nodes in the single linked list instance
	LargestUnsignedInteger member_size;
	

	// The following data members are added to make specific optimizations. The first one is to store the memory address of the last node, to allow 
	// adding a node to the end of the single linked list without passing on all the nodes for it. The second and third are used to store the memory
	// address and index of the last used node. This will allow first of all another starting point beside the beginning of the single linked list
	// to find specific nodes, furthermore, it will allow passing on all the nodes, without starting each time from the root :

	// This object will store the active node, meaning the node that the instance is currently workin on
	mutable NodeType* member_activeNode;

	// This object will store the active node index, meaning the node index that the instance is currently workin on
	mutable LargestUnsignedInteger member_activeNodeIndex;


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
	// rather help implement it :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to delete all the node from the single linked list
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			firstNodeToDelete - the memory address of the first node to delete
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
	//		1. The given pointer is not NULL
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void DeleteNodes__Private( NodeType* const firstNodeToDelete );


	// Method Information :
	//
	//  Description :
	//
    //		Use this method to add a chain of nodes into the instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. firstNodePointer - a pointer with the memory address of the first node in the chain
	//			2. lastNodePointer - a pointer with the memory address of the last noode in the chain
	//			3. addNodesStartingFromThisIndex - the first index from which nodes should be added to the single linked list instance
	//			4. size - the number of nodes
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
	//		1. The given pointer to the first node should not be NULL
	//		2. The given pointer to the last node should not be NULL
	//		3. The given index should be smaller or equal to the single linked list size
	//		4. The given size of the chain should be larger then 0
	//		5. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void InsertTheNewNodesToTheRequiredLocation__Private( NodeType* const firstNodePointer, NodeType* const lastNodePointer, const LargestUnsignedInteger addNodesStartingFromThisIndex, const LargestUnsignedInteger size );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to get the memory address of a specific node. The method will check if the shortest path to the required node is from
	//		the beginning or from the last used node, and take that path. The required node will be stored in the active node member
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			index - the index of the required node
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
	//		1. The given index is smaller then the single linked list size
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void TakeShortestPathToNodeAndSetItAsTheActiveNode__Private( const LargestUnsignedInteger index ) const;


};  //  Class SingleLinkedList