namespace Universe
{


namespace Memory
{



// The divide "/" operaotr yields the quotient, and the modulo % operator yields the remainder from the division of the first expression by the second. If the 
// second operand of "/" or "%" is 0 the behavior is undefined. If both operands are nonnegative then the remainder is nonnegative, if not the sign of the remainder 
// is implementation dependent



// If the operand of the modulo is a power of 2, it used to be possible to compute it as :
//
//          n % b ( power of 2 )  =  n & ( b - 1 )
//
// The new standard requires that it be computed as :
//
//          n < 0 ? n | -b : n & ( b - 1 )
//
// Likewise, the divide operation can not be written as a simple shift, even on hardware that supports arithmetic shifts, instead, on such systems, an expression 
// like ->  n / 16 must be written as :
//
//          n < 0 ? ( n + 15 ) >> 4 : n >> 4



// The result of a subtraction generating a negative number in an unsigned type is well defined :
//
// A computation involving unsigned operands can never overflow, because a result that cannot be represented by the resulting unsigned integer type is reduced 
// modulo the number that is one greater than the largest value that can be represented by the resulting type
//
// Example ->  (unsigned int)0 - (unsigned int)1  =  -1 % ( UNSIGNED_INT_MAX_VALUE + 1 )  =  UNSIGNED_INT_MAX_VALUE
//
// Explenation :
//
// When working with unsigned types, modular arithmetic ( also known as "wrap around" behavior ) is applied. To understand modular arithmetic, the clock can be 
// used. If the hour is cuurently 9 am, adding 4 hours to it would bring us to the hour 1 pm, which is equal to the operation :
//
//          ( 9 + 4 ) % 12 = 1
//
// but the other way should give also a correct answer, if the current hour is 1 pm, going back 4 hours should give 9 am, which is equal to the operation :
//
//          ( 1 - 4 ) % 12 = 9



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
class BitArray NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = BitArray;


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
	//		NONE
	//
	inline BitArray();


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
	//			size - the number of bits for the bit array
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
	//		1. The size should be larger then 0
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	explicit inline BitArray( const LargestUnsignedInteger size );


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
	inline BitArray( const SelfType& other );


	// This macro will be used to add all the functionality that is similiar in each object ( beside the name of the object ). It is done
	// as a macro to allow simple text manipulation, instead of inherting it through an object, which becomes a problem when an object
	// inherits from 2 objects, the first is any object, but the second is an object that also inhrits from the first object. This can be
	// solved through virtual inheritance but then can only be one instance of it. Furthermore, each object in the system will need to
	// inherit from it, which will cause inheritance 'chaos'. Therefore, this macro will be used to add the following methods to each object :
	//
	//		1. Assigenment operator
	//		2. Move constructor
	//		3. Move assigenment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure( BitArray )


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
	inline ~BitArray();


	// This part will contain all the get and set methods for the members of the object :


	GetByValue_Creator( /* GetMethodName */ Size, /* MemberName */ member_size, /* MemberType */ LargestUnsignedInteger )


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to set all the bits of the bit array on
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          NONE
	//
	//      Information returned to the user :
	//
	//          NONE
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
	//      They will come
	//
	inline void SetAllBitsOn();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to set all the bits of the bit array off
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          NONE
	//
	//      Information returned to the user :
	//
	//          NONE
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
	//      They will come
	//
	inline void SetAllBitsOff();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to search for all the bits with state off
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          NONE
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      A memory handler instance that contains indices of the amount of bits found in the bit array with state off
	//
	//  Expectations :
	//
	//		1. The instance is ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< template< typename... > class ResultMemoryHandlerType >
	EnsureRetrunValueIsUsed inline ResultMemoryHandlerType< LargestUnsignedInteger > SearchForAllBitsWithStateOff() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to search for bits with state off. The search will end when the required amount of bits were located
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          numberOfBitsToFind - the number of apperances to locate starting from the beginning
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      A memory handler instance that contains indices of the amount of bits found in the bit array with state off. The memory handler
	//		size should be checked, as there might be less bits with state off then requested
	//
	//  Expectations :
	//
	//		1. The instance is ready
	//		2. The number of bits with state off to find is higher then 0
	//		3. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< template< typename... > class ResultMemoryHandlerType >
	EnsureRetrunValueIsUsed inline ResultMemoryHandlerType< LargestUnsignedInteger > SearchForBitsWithStateOff( const LargestUnsignedInteger numberOfBitsToFind ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to search for bits with state off. The search will end when the required amount of bits were located
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          1. numberOfBitsToFind - the number of apperances to locate starting from the beginning
	//			2. storeOffsetToBitsWithStateOffPointer - a pointer with memory address where the result of the search will be stored
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		The actual number of bits with state off found
	//
	//  Expectations :
	//
	//		1. The instance is ready
	//		2. The number of bits with state off to find is higher then 0
	//		3. The given pointer with the memory address to store the results must not be NULL
	//		4. Enough memory was allocated to store the search result
	//		5. 
	//
	//  Possible errors :
	//
	//		NONE
	//
	EnsureRetrunValueIsUsed inline LargestUnsignedInteger SearchForBitsWithStateOff( const LargestUnsignedInteger numberOfBitsToFind, LargestUnsignedInteger* const storeOffsetToBitsWithStateOffPointer ) const;


	// The following methods declare the overloaded operators for the object :


    // Method Information :
    //
    //  Description :
    //
    //      Use this operator to get the required bit
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          index - the index of the required bit
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      A 'Bit' instance that points to the required bit
    //
    //  Expectations :
    //
    //      1. The given index should be smaller then the number of bits in the array
    //		2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline Bit< UnsignedInteger8bits > operator[]( const LargestUnsignedInteger index );


    // Method Information :
    //
    //  Description :
    //
    //      Use this operator to get the required bit
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          index - the index of the required bit
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      A constant 'Bit' instance that points to the required bit
    //
    //  Expectations :
    //
    //      1. The given index should be smaller then the number of bits in the array
    //		2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline const Bit< UnsignedInteger8bits > operator[]( const LargestUnsignedInteger index ) const;


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


	// This object will store the number of bits
	LargestUnsignedInteger member_size;

	// This object will store the number of bytes it requires to store all the bits
	LargestUnsignedInteger member_numberOfBytes;

	// This pointer will store the memory address of the bit array
	UnsignedInteger8bits* member_bitArrayPointer;


	// Static data members do not belong to any instance, they belong to the object. Like every global variable it is created with the
	// start of the program and only destroyed when the program ends. The access to the static member is bound to this object of course


	// This object will act as a lookup table to optimize the search for bits with state off
	static const Vector< Vector< UnsignedInteger8bits > > member_lookupTableToOptimizeSearchForBitsWithStateOff;


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
	// rather help implement it :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to search for bits with state off. The search will end when the required amount of bits were located
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          1. numberOfBitsToFind - the number of apperances to locate starting from the beginning
	//			2. storeOffsetToBitsWithStateOffPointer - a pointer with memory address where the result of the search will be stored
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		The actual number of bits with state off found
	//
	//  Expectations :
	//
	//		1. The instance is ready
	//		2. The number of bits with state off to find is higher then 0
	//		3. The given pointer with the memory address to store the results must not be NULL
	//		4. Enough memory was allocated to store the search result
	//		5. 
	//
	//  Possible errors :
	//
	//		NONE
	//
    template< typename ResultMemoryHandlerType >
    EnsureRetrunValueIsUsed inline LargestUnsignedInteger SearchForBitsWithStateOff__Private( const LargestUnsignedInteger numberOfBitsToFind, ResultMemoryHandlerType storeOffsetToBitsWithStateOff ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get a copy of the last byte with all the added bits on, at the end of the bit array, that are used as 
	//		padding, to meet the 8 bits boundary
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
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline UnsignedInteger8bits GetCopyOfTheLastByteWithTheBitsOnWhichAreOnlyForPadding__Private() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get a copy of the last byte with all the added bits off, at the end of the bit array, that are used as 
	//		padding, to meet the 8 bits boundary
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
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline UnsignedInteger8bits GetCopyOfTheLastByteWithTheBitsOffWhichAreOnlyForPadding__Private() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to create the lookup table that will be used to optimize the search for bits with state off
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
	//		A 2D heap array that contains the lookup table that will be used to optimize the search for bits with state off
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed static inline Vector< Vector< UnsignedInteger8bits > > CreateLookupTableToOptimizeSearchForBitsWithStateOff__Private();


};  //  Class BitArray