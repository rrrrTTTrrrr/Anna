namespace Universe
{


namespace Memory
{



// What is the behavior of the operator 'new' in the following case :
//
//		new int[0]
//
// When the value of the expression in a direct new declarator is zero, the allocation function is called to allocate an array with no elements.
// The effect of dereferencing a pointer returned as a request for zero size is undefiend. Even if the size of the space requested is zero the
// request can fail. 
//
// This means that there is no well defined manner across all platforms to dereference the memory returned from the call of new with zero size,
// and it should be deleted. The intent is to have operator new implementable by calling malloc and calloc, so the rules are substantially the
// same. C++ differs from C in requiring a zero request to return a non null pointer



// Placement new :
//
// Placement new allows you to constrcut an object on memory that's already allocated.
//
// Standard C++ also supports placement new operator, which constructs an object on a pre-allocated buffer. This is useful when building a memory
// pool, a garbage collector or simply when performance and exception safety are paramount ( there's no danger of allocation failure since the memory
// has already been allocated, and constructing an object on a pre-allocated buffer takes less time )



// In order to create an array of objects, for example :
//
//      Class* classArray = new Class[34];
//
// The given class must have default constructor, or else the compiler does not know how to initialize the area



// In C++ an inner class is by default a friend of the class it is decalred within. This means that if a reference to the outer class is given to 
// the inner class, it can acess every member of the outer class 



// Class size in C++ :
//
// To a first order approximation, the size of an object is the sum of the sizes of its constituent data members. Ths size will never be smaller 
// than this. More precisely, the compiler is entitled to insert padding space between data members to ensure that each data member meets the 
// alignment requirements of the platform. Some platforms are very strict about alignment, while others ( x86 ) are more forgiving, but will 
// perform significantly better with proper alignment. So, even the compiler optimization setting can affect the object size.
//
// Inheritance and virtual functions add an additional complication. Member functions of a class do not take up "per object" space, but the 
// existence of virtual functions in that class's interface generally implies the existence of a virtual table, essentially a lookup table 
// of function pointers used to dynamically resolve the proper function implementation to call at runtime. The virtual table is accessed 
// generally via a pointer stored in each object/
//
// Derived class objects also include all data members of their base classes. Finally, access specifiers ( public, private, protected ) grant 
// the compiler certain leeway with packing of data members



// When aggregate initializers ( initializers in {} ) are used in the "traditional" ANSI C language ( C89/90 ), an individual initializer must 
// be supplied for each structure member in order, beginning with the first, for example :
//
//      struct S { int a, b, c, d; };
//
//      struct S s = { 1, 2, 3, 4 };
//
// 1 for `s.a`, 2 for `s.b` and so on...
//
// You are not required to specify initializers for all members, i.e. you can stop at any time ( remaining members will be zero-initialized ). 
// If for some reason you only cared to explicitly initialize the third member of the structure, you had to supply "dummy" explicit initializers 
// for the first and the second members ( just to get to the desired third ), for example :
//
// We only care to explicitly initialize `s.c`
//
//      struct S s = { 0, 0, 3 };
//
// but we have to explicitly initialize `s.a` and `s.b` as well
//
// Or abandon specific initialization entirely ( likely replacing it with generic = { 0 } ) and use a subsequent assignment to specific members, 
// for example :
//
//      struct S s = { 0 };
//      s.c = 3;
//
// One notable benefit of this assignment-based approach is that it is independent from the position of member c in the declaration of struct S. 
// The new specification of C language ( C99 ) allows you to use "tagged" initializers by supplying the desired member name within the {}, for 
// example :
//
//      struct S s = { .c = 3 };
//
// That way you only explicitly initialize the desired member(s) ( and have the compiler to zero-initialize the rest ). This not only saves you 
// some typing but also makes the aggregate initializers independent from the order in which the members are specified in the struct type declaration.
//
// Aggregate initializers, can be used with arrays, too. And C99 supports "tagged" initialization with arrays as well. How the "tags" look in case 
// of an array is illustrated by the following example :
//
//      int a[10] = { [5] = 3 };
//
// It is worth noting one more time that C language continues to stick to the "all or nothing" approach to aggregate initialization: if you specify 
// an explicit initializer for just one ( or some ) members of a struct or an array, the whole aggregate ( struct or array ) gets initialized, and 
// the members without explicit initializers get zero-initialized



// Template Class Information :
//
//  Purpose :
//
//		Use this object to store multiple instances of the same type. The size of the array is provided as an argument to the constructor
//		which means that is allocated during run time, and therefore it will be placed on the heap memory segment
//
//  Description :
//
//		1. This object contains an instance of the object "InstanceState" to allow each instance of this object to have a defined state
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
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType = MainMemoryManager >
class Vector
{
public:


    // Create a type definition for this object
    using SelfType = Vector< DataType, MemoryManagerType >;

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
	inline Vector();


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
	explicit inline Vector( const LargestUnsignedInteger size, const DataType& data = ActAccordingToType::GetDefaultInstance< DataType >() );


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
	explicit inline Vector( const OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >& other, const LargestUnsignedInteger startingIndexOnOtherInstance, const LargestUnsignedInteger sizeFromOther );


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
	explicit inline Vector( OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >&& other, const LargestUnsignedInteger startingIndexOnOtherInstance, const LargestUnsignedInteger sizeFromOther );


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
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	inline Vector( const SelfType& other );


	// This macro will be used to all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
	// simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
	// any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
	// be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
	// macro will be used to add the following methods to each object :
	//
	//		1. Assignment operator
	//		2. Move constructor
	//		3. Move assignment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure_ForInheritance( Vector )


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
	virtual ~Vector();


	// This part will contain all the get and set methods for the members of the object :


	GetByValue_Creator( /* GetMethodName */ Size, /* MemberName */ member_size, /* MemberType */ LargestUnsignedInteger )
	GetByValue_Creator( /* GetMethodName */ DataPointer, /* MemberName */ member_vectorPointer, /* MemberType */ DataType* )


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
	EnsureRetrunValueIsUsed inline Boolean operator!=( const SelfType& other ) const;


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
	EnsureRetrunValueIsUsed inline DataType& operator[]( const LargestUnsignedInteger index );


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
		static void UnitTest() __attribute__ (( __unused__ ));

	)  //  End of debug tool


private:


	// This object will store the memory address of the memory space allocated for the array on the heap memory segment
	DataType* member_vectorPointer;

	// This object will store the size of the array
	LargestUnsignedInteger member_size;


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
	// rather help implement it :


	// Method Information :
	//
	//  Description :
	//
    //		Use this method to allocate a larger memory space, according to the required size to add, and copy the current data into it, leaving
    //		a new free memory space to be used 
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. addMemorySpaceStartingFromThisIndex - the first index from which memory space should be added to the array instance
	//			2. sizeToAdd - the number of entries needed to be added
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
	//		1. The given index should be smaller or equal to the array size
	//		2. The given size should be larger then 0
	//		3. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	inline void AllocateLargerMemorySpaceAndCopyTheCurrentDataToTheNewLocation__Private( const LargestUnsignedInteger addMemorySpaceStartingFromThisIndex, const LargestUnsignedInteger sizeToAdd );


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
    void CopyDataFromOtherInstanceToThisInstance__Private( const OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >& other, const LargestUnsignedInteger firstIndexInThisInstance, const LargestUnsignedInteger firstIndexOnOtherInstance, const LargestUnsignedInteger sizeToAdd );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to copy the data from the other instance into this instance. The data will be added starting from the provided
	//		index. It allows setting the data starting from an offset on the other instance until the required size. This overload is for 
	//		constant reference to heap array, which have contiguous memory space and the operation can be performed much faster
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
	template< typename OtherVectorMemoryManagerType = MainMemoryManager >
    void CopyDataFromOtherInstanceToThisInstance__Private( const Vector< DataType, OtherVectorMemoryManagerType >& other, const LargestUnsignedInteger firstIndexInThisInstance, const LargestUnsignedInteger firstIndexOnOtherInstance, const LargestUnsignedInteger sizeToAdd );


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
    //		NONE
	//
    template< template< typename, typename > class OtherMemoryHandlerType, typename OtherMemoryHandlerMemoryManagerType = MainMemoryManager >
    void CopyDataFromOtherInstanceToThisInstance__Private( OtherMemoryHandlerType< DataType, OtherMemoryHandlerMemoryManagerType >&& other, const LargestUnsignedInteger firstIndexInThisInstance, const LargestUnsignedInteger firstIndexOnOtherInstance, const LargestUnsignedInteger sizeToAdd );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to copy the data from the other instance into this instance. The data will be copied starting from the provided
	//		index. It allows setting the data starting from an offset on the other instance until the required size. This overload is for 
	//		rvalue reference instances to heap array, which have contiguous memory space and the operation can be performed much faster, 
	//		that the data can be moved from and there is no need to copy
	//
	//		Note 1 - if the data should be added to the end of the instance, provide as index the current size of the instance
	//		Note 2 - if the instance is in default state, the only valid index to insert datat to is 0
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. other - a constant reference to an heap array
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
    //		NONE
	//
	template< typename OtherVectorMemoryManagerType = MainMemoryManager >
    void CopyDataFromOtherInstanceToThisInstance__Private( Vector< DataType, OtherVectorMemoryManagerType >&& other, const LargestUnsignedInteger firstIndexInThisInstance, const LargestUnsignedInteger firstIndexOnOtherInstance, const LargestUnsignedInteger sizeToAdd );


};  //  Class Vector