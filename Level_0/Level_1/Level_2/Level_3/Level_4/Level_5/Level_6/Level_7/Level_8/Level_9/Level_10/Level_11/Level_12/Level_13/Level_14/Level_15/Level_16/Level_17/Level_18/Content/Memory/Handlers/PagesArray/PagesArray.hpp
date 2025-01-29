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
template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType = MainMemoryManager >
class PagesArray NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = PagesArray< DataType, MemoryManagerType >;


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
	inline PagesArray();


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
	//			1. size - the number of entries in the array
	//			2. data - a reference to the instance that will be used to Initialize all the entries of the array
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
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	explicit inline PagesArray( const LargestUnsignedInteger size, const DataType& data = ActAccordingToType::GetDefaultInstance< DataType >() );


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
	//			2. otherInstanceStartingIndex - the index of the first entry that should be copied from the other instance
	//			3. size - the size from the other instance to copy to this instance
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
	explicit inline PagesArray( const OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >& other, const LargestUnsignedInteger otherInstanceStartingIndex, const LargestUnsignedInteger size );


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
	//			1. other - a constant reference to other pages array instance
	//			2. otherInstanceStartingIndex - the index of the first entry that should be copied from the other instance
	//			3. size - the size from the other instance to copy to this instance
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
	template< typename OtherMemoryHandlerMemoryManagerType = MainMemoryManager >
	explicit inline PagesArray( const PagesArray< DataType, OtherMemoryHandlerMemoryManagerType >& other, const LargestUnsignedInteger otherInstanceStartingIndex, const LargestUnsignedInteger size );


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
	//			2. otherInstanceStartingIndex - the index of the first entry that should be copied from the other instance
	//			3. size - the size from the other instance to copy to this instance
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
	explicit inline PagesArray( OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >&& other, const LargestUnsignedInteger otherInstanceStartingIndex, const LargestUnsignedInteger size );


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
	//			1. other - an rvalue reference to other pages array instance
	//			2. otherInstanceStartingIndex - the index of the first entry that should be copied from the other instance
	//			3. size - the size from the other instance to copy to this instance
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
	template< typename OtherMemoryHandlerMemoryManagerType = MainMemoryManager >
	explicit inline PagesArray( PagesArray< DataType, OtherMemoryHandlerMemoryManagerType >&& other, const LargestUnsignedInteger otherInstanceStartingIndex, const LargestUnsignedInteger size );


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
	inline PagesArray( const SelfType& other );


	// Add the following infrastructure to the object :
	//
	//		1. Assigenment operator
	//		2. Move constructor
	//		3. Move assigenment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure_ForInheritance( PagesArray )


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
	virtual ~PagesArray();


	// This part will contain all the get and set methods for the members of the object :


	GetByValue_Creator( /* GetMethodName */ Size, /* MemberName */ member_size, /* MemberType */ LargestUnsignedInteger )


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the pages pointers
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
	//		A constant reference to the pages pointers container
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
	inline const Vector< DataType* >& PointersToPages() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the index of the first used entry in the first page
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
	//		The index of the first used entry in the first page
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
    inline LargestUnsignedInteger IndexOfFirstEntryUsedInFirstPageIndex() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the size used in the last page
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
	//		The size used in the last page
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
    inline LargestUnsignedInteger SizeUsedInLastPage() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the the page size
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
	//		The page size
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
	inline LargestUnsignedInteger PageSize() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the the page size in bytes
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
	//		The page size in bytes
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
	inline LargestUnsignedInteger PageSizeInBytes() const;


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
    inline LargestUnsignedInteger SizeInBytes() const;


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
    inline LargestUnsignedInteger DataTypeSizeInBytes() const;


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
	//			1. index - the index in which the data should be added
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
    inline void InsertSingleElement( const LargestUnsignedInteger index, UniversalReferenceDataType&& data );


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
	//			1. index - the index at which the data will be inserted to
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
	inline void InsertSingleElementCreateFromArguments( const LargestUnsignedInteger index, AnyArgumentNeededToConstructDataInstanceTypes&&... anyArgumentNeededToConstructDataIstance );


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
	//			1. index - the index in which the data should be added in the instance
	//			2. size - the number of elements to add
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
    inline void InsertMultipleTimesTheSameElement( const LargestUnsignedInteger index, const LargestUnsignedInteger size, const DataType& data = DataType() );


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
	//			2. thisInstanceFirstIndex - the index at which the data from the other instance needs to be inserted to
	//			3. otherInstanceFirstIndex - the index of the first entry to insert from the other instance
	//			4. size - the size from the other instance to insert
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
    inline void InsertElementsFromOtherInstance( const OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >& other, const LargestUnsignedInteger thisInstanceFirstIndex, const LargestUnsignedInteger otherInstanceFirstIndex, const LargestUnsignedInteger size );


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
	//			2. thisInstanceFirstIndex - the index at which the data from the other instance needs to be inserted to
	//			3. otherInstanceFirstIndex - the index of the first entry to insert from the other instance
	//			4. size - the size from the other instance to insert
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
    inline void InsertElementsFromOtherInstance( OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >&& other, const LargestUnsignedInteger thisInstanceFirstIndex, const LargestUnsignedInteger otherInstanceFirstIndex, const LargestUnsignedInteger size );


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
	//			2. index - the index at which the data needs to be inserted to
	//			3. size - the size of the data the pointer points to
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
	inline void InsertElementsFromRawData( const DataType* dataPointer, const LargestUnsignedInteger index, const LargestUnsignedInteger size );


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
	//			1. index - the first index from which data should be removed
	//			2. size - the number of entries to remove
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
	inline void Remove( const LargestUnsignedInteger index, const LargestUnsignedInteger size );


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
	//			other - a reference to the instance that should be compared with this object
	//
	//      Information returned to the user :
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
	inline Boolean operator==( const SelfType& other ) const;


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
	//			other - a reference to the instance that should be compared with this object
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
	inline Boolean operator!=( const SelfType& other ) const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to get a reference the value inside the required entry
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			index - the index of the required entry
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
    //      A reference to the value inside the required entry
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. The given index is smaller then the array size
	//		3. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline DataType& operator[]( const LargestUnsignedInteger index );


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to get a constant reference the value inside the required entry
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			index - the index of the required entry
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
    //      A constant reference to the value inside the required entry
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. The given index is smaller then the array size
	//		3. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline const DataType& operator[]( const LargestUnsignedInteger index ) const;


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

		void Display();

	)  //  End of debug tool


private:


	// This object will store the size of a page
	LargestUnsignedInteger member_pageSize;

	// This object will store the index of the first entry used in the first page
	LargestUnsignedInteger member_indexOfFirstEntryUsedInFirstPageIndex;

	// This object will store the size of the pages array
	LargestUnsignedInteger member_size;

	// This object will store the pages
	Vector< DataType* > member_pages;


	// Static data members do not belong to any instance, they belong to the object. Like every global variable it is created with the
	// start of the program and only destroyed when the program ends. The access to the static member is bound to this object of course


	// This object will store memory size in bytes in main memory that will be used to store the files contents
	static const LargestUnsignedInteger member_defaultPageSizeInBytes;


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of
	// the interface, but rather help implement it :


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to get the page index and the entry index in the page of the given index
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			index - the required index of the entry
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		An object that contains the page index and the entry index in the page of the given index
	//
	//  Expectations :
	//
	//		1. The given index must be smaller then the instance size
	//		2.
	//
	//  Possible errors :
	//
	//		NONE 
	//
	inline CentralProcessingUnit::DivisonResultUnsignedInteger64bits GetPageIndexAndEntryIndexInPage__Private( const LargestUnsignedInteger index ) const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to remove the required pages. It will first release the memory, and then delete the pointers
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. firstPageIndexThatNeedsToBeRemoved - the index of the first page that needs to be removed
	//			2. numberOfPagesThatNeedsToBeRemoved - the number of pages that needs to be removed
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
	//		1. The given index must be smaller then the instance size
	//		2. The given index plus the size to remove must be smaller then the instance size
	//		3. 
	//
	//  Possible errors :
	//
	//		NONE 
	//
	inline void RemovePages__Private( const LargestUnsignedInteger firstPageIndexThatNeedsToBeRemoved, const LargestUnsignedInteger numberOfPagesThatNeedsToBeRemoved );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to add memory space for new data. The current data that the index point to, will be pushed towards the ending
	// 		of the pages array. In other words the current data that the index point to will come after the new data
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. index - the index of at which the data needs to be inserted
	//			2. size - the size of the data that needs to be inserted
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
	//		1. The given index must be smaller or equal to the instance size
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	inline void AllocateLargerMemorySpaceAndCopyTheCurrentDataToTheNewLocation__Private( const LargestUnsignedInteger index, const LargestUnsignedInteger size );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to allocate more pages at the beginning
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			size - the number of pages that needs to be added at the beginning
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
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	inline LargestUnsignedInteger AllocateAdditionalPagesAtTheBeginning__Private( const LargestUnsignedInteger size );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to allocate more pages at the ending
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			size - the number of pages that needs to be added at the ending
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
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	inline void AllocateAdditionalPagesAtTheEnding__Private( const LargestUnsignedInteger size, const LargestUnsignedInteger sizeLeftToUseInTheEnding );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to move entries towards the beginning of the pages array. This means that the source index must be larger
	//		then the destination index. The reason for the absolute index, is that there are cases where new pages where allocated
	//		at the beginning of the pages array, and entries needs to be moved from the old first page to those new allocated pages
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. absoluteSourceIndex - the index from the entries needs to be moved from
	//			2. absoluteDestinationIndex - the index to which the entries needs to be moved to
	//			3. sizeToMove - the number of entries to move
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
	//		1. The source index is larger then the destination index
	//		2. The number of entries to move is larger then 0
	//		3. 
	//
	//  Possible errors :
	//
	//		NONE
	//
    inline void MoveEntriesTowardsTheBeginning__Private( const LargestUnsignedInteger absoluteSourceIndex, const LargestUnsignedInteger absoluteDestinationIndex, const LargestUnsignedInteger sizeToMove );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to move entries towards the ending of the pages array. This means that the source index must be larger
	//		then the destination index
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. absoluteSourceIndex - the index from the entries needs to be moved from
	//			2. absoluteDestinationIndex - the index to which the entries needs to be moved to
	//			3. sizeToMove - the number of entries to move
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
	//		1. The source index is smaller then the destination index
	//		2. The number of entries to move is larger then 0
	//		3. 
	//
	//  Possible errors :
	//
	//		NONE
	//
    inline void MoveEntriesTowardsTheEnding__Private( const LargestUnsignedInteger absoluteSourceIndex, const LargestUnsignedInteger absoluteDestinationIndex, const LargestUnsignedInteger sizeToMove );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to copy the data from the other instance into this instance. The data will be added starting from the provided
	//		index. It allows setting the data starting from an offset on the other instance until the required size
	//
	//		Note 1 - if the data should be added to the end of the instance, provide as index the current size of the instance
	//		Note 2 - if the instance is in default state, the only valid index to insert datat to is 0
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. other - a constant reference to other memory handler
	//			2. thisInstanceFirstIndex - the index at which the data from the other instance needs to be inserted to
	//			3. otherInstanceFirstIndex - the index of the first entry to insert from the other instance
	//			4. size - the size from the other instance to insert
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
    inline void CopyDataFromOtherInstanceToThisInstance__Private( const OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >& other, const LargestUnsignedInteger thisInstanceFirstIndex, const LargestUnsignedInteger otherInstanceFirstIndex, const LargestUnsignedInteger size );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to copy the data from the other instance into this instance. The data will be added starting from the provided
	//		index. It allows setting the data starting from an offset on the other instance until the required size. This overload is for 
	//		constant reference to pages array, which have contiguous memory spaces and the operation can be performed much faster
	//
	//		Note 1 - if the data should be added to the end of the instance, provide as index the current size of the instance
	//		Note 2 - if the instance is in default state, the only valid index to insert datat to is 0
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. other - a constant reference to other memory handler
	//			2. thisInstanceFirstIndex - the index at which the data from the other instance needs to be inserted to
	//			3. otherInstanceFirstIndex - the index of the first entry to insert from the other instance
	//			4. size - the size from the other instance to insert
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
	template< typename OtherPagesArrayMemoryManagerType = MainMemoryManager >
    inline void CopyDataFromOtherInstanceToThisInstance__Private( const PagesArray< DataType, OtherPagesArrayMemoryManagerType >& other, const LargestUnsignedInteger thisInstanceFirstIndex, const LargestUnsignedInteger otherInstanceFirstIndex, const LargestUnsignedInteger size );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to copy the data from the other instance into this instance. The data will be added starting from the provided
	//		index. It allows setting the data starting from an offset on the other instance until the required size. This overload is for 
	//		constant reference to vector, which have contiguous memory space and the operation can be performed much faster
	//
	//		Note 1 - if the data should be added to the end of the instance, provide as index the current size of the instance
	//		Note 2 - if the instance is in default state, the only valid index to insert datat to is 0
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. other - a constant reference to other memory handler
	//			2. thisInstanceFirstIndex - the index at which the data from the other instance needs to be inserted to
	//			3. otherInstanceFirstIndex - the index of the first entry to insert from the other instance
	//			4. size - the size from the other instance to insert
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
	template< typename OtherHeapArrayMemoryManagerType = MainMemoryManager >
    inline void CopyDataFromOtherInstanceToThisInstance__Private( const Vector< DataType, OtherHeapArrayMemoryManagerType >& other, const LargestUnsignedInteger thisInstanceFirstIndex, const LargestUnsignedInteger otherInstanceFirstIndex, const LargestUnsignedInteger size );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to copy the data from the other instance into this instance. The data will be copied starting from the provided
	//		index. It allows setting the data starting from an offset on the other instance until the required size. This overload is for 
	//		rvalue reference instances, that the data can be moved from and there is no need to copy
	//
	//		Note 1 - if the data should be added to the end of the instance, provide as index the current size of the instance
	//		Note 2 - if the instance is in default state, the only valid index to insert datat to is 0
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. other - a constant reference to other memory handler
	//			2. thisInstanceFirstIndex - the index at which the data from the other instance needs to be inserted to
	//			3. otherInstanceFirstIndex - the index of the first entry to insert from the other instance
	//			4. size - the size from the other instance to insert
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
    //		NONE
	//
    template< template< typename, typename > class OtherMemoryHandlerType, typename OtherMemoryHandlerMemoryManagerType = MainMemoryManager >
    inline void CopyDataFromOtherInstanceToThisInstance__Private( OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >&& other, const LargestUnsignedInteger thisInstanceFirstIndex, const LargestUnsignedInteger otherInstanceFirstIndex, const LargestUnsignedInteger size );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to copy the data from the other instance into this instance. The data will be copied starting from the provided
	//		index. It allows setting the data starting from an offset on the other instance until the required size. This overload is for 
	//		rvalue reference instances to pages array, which have contiguous memory spaces and the operation can be performed much faster, 
	//		that the data can be moved from and there is no need to copy
	//
	//		Note 1 - if the data should be added to the end of the instance, provide as index the current size of the instance
	//		Note 2 - if the instance is in default state, the only valid index to insert datat to is 0
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. other - a constant reference to a pages array
	//			2. thisInstanceFirstIndex - the index at which the data from the other instance needs to be inserted to
	//			3. otherInstanceFirstIndex - the index of the first entry to insert from the other instance
	//			4. size - the size from the other instance to insert
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
    //		NONE
	//
	template< typename OtherPagesArrayMemoryManagerType = MainMemoryManager >
    inline void CopyDataFromOtherInstanceToThisInstance__Private( PagesArray< DataType, OtherPagesArrayMemoryManagerType >&& other, const LargestUnsignedInteger thisInstanceFirstIndex, const LargestUnsignedInteger otherInstanceFirstIndex, const LargestUnsignedInteger size );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to copy the data from the other instance into this instance. The data will be copied starting from the provided
	//		index. It allows setting the data starting from an offset on the other instance until the required size. This overload is for 
	//		rvalue reference instances to vector, which have contiguous memory space and the operation can be performed much faster, 
	//		that the data can be moved from and there is no need to copy
	//
	//		Note 1 - if the data should be added to the end of the instance, provide as index the current size of the instance
	//		Note 2 - if the instance is in default state, the only valid index to insert datat to is 0
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. other - a constant reference to an vector
	//			2. thisInstanceFirstIndex - the index at which the data from the other instance needs to be inserted to
	//			3. otherInstanceFirstIndex - the index of the first entry to insert from the other instance
	//			4. size - the size from the other instance to insert
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
    //		NONE
	//
	template< typename OtherHeapArrayMemoryManagerType = MainMemoryManager >
    inline void CopyDataFromOtherInstanceToThisInstance__Private( Vector< DataType, OtherHeapArrayMemoryManagerType >&& other, const LargestUnsignedInteger thisInstanceFirstIndex, const LargestUnsignedInteger otherInstanceFirstIndex, const LargestUnsignedInteger size );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to compare the content of this instance with other pages array instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			other - a constant reference to an other instance
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		True if the instances are identical, and false otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
    //		NONE
	//
	template< typename OtherPagesArrayMemoryManagerType = MainMemoryManager >
    inline Boolean CompareWithOtherInstance__Private( const PagesArray< DataType, OtherPagesArrayMemoryManagerType >& other ) const;


};  //  Class PagesArray


// Initialize the default page size in bytes
template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType >
const LargestUnsignedInteger PagesArray< DataType, MemoryManagerType >::member_defaultPageSizeInBytes = GigaByte( 2UL );