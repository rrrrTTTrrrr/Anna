namespace Universe
{


namespace Memory
{



// Create an enumeration to describe the two states of a bit. This way when the user wants to set or check the state of a bit it can
// be done using the enumeration, instead of writing '0' or '1', which is much more readable
enum class BitState
{
    ON,
    OFF
};



// Template Class Information :
//
//  Purpose :
//
//		Use this object to manipulate single bits from the set of bits the given template type has
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
//		4. Template arguments :
//
//			1. Type -
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< Concepts::Integer IntegerType >
class Bit NotForInheritance
{
public:


    // Create a type definition for this object
    using SelfType = Bit< IntegerType >;


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
	inline Bit();


    // Method Information :
    //
    //  Description :
    //
    //      Constructor,
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. pointer - a pointer containing the memory of an instance of the given templte type object
    //          2. bitIndex - this offset will be used to determine the required bit
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
    //      1. The given pointer is not NULL
    //      2. The given bit index is in the range of the given template type object size
    //      3. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    explicit inline Bit( IntegerType* const pointer, const UnsignedInteger64bits bitIndex = 0UL );


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
	//		They will come
	//
	inline Bit( const SelfType& other );


	// This macro will be used to all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
	// simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
	// any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
	// be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
	// macro will be used to add the following methods to each object :
	//
    //      1. Assignment operator
    //      2. Move constructor
    //      3. Move assignment operator
    //      4. Swap
    //      5. Reset
	//
	ObjectInfrastructure( Bit )


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
	inline ~Bit() = default;


    // This part will contain all the get and set methods for the members of the object :


    GetByValue_Creator( /* Method Name */ MemoryAddress, /* Member to work on */ member_memoryAddress, /* Return value type */ IntegerType* )
    GetByValue_Creator( /* Method Name */ BitIndex, /* Member to work on */ member_bitIndex, /* Return value type */ UnsignedInteger64bits )


    // The following methods give access and manipulate the data inside this object :


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to get the bit index in the byte he is in
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
    //      The bit index in the byte it is in
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline UnsignedInteger64bits BitIndexInItsByte() const;


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to point the instance to a different bit
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          bitIndex - the new index for the bit that the instance will now point too
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
    //      1. The instance should be ready
    //      2. The new given bit index should be in the range of the template type object size
    //      3. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    inline void SetBitIndex( const UnsignedInteger8bits bitIndex );


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to get the state of the bit ON or OFF
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
    //      An enumeration describing the bit state, either on or off
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline BitState State() const;


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to set the state of the bit
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          State - a boolean describing the required state for the bit
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
    //      1. The instance should be ready
    //      2. The given state should be 1 or 0
    //      3. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    inline void SetState( const BitState State );


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the bit is on
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
    //      True if the bit is on, and false otherwise
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline Boolean IsOn() const;


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the bit is off
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
    //      True if the bit is off, and false otherwise
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline Boolean IsOff() const;


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to set the state of the bit ON
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
    //      1. The instance should be ready
    //      2. The given state should be 1 or 0
    //      3. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    inline void TurnOn();


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to set the state of the bit OFF
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
    //      1. The instance should be ready
    //      2. The given state should be 1 or 0
    //      3. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    inline void TurnOff();


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to set the bit to the opposite state of the current one ( ON to OFF, and OFF to ON )
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
    //      1. The instance should be ready
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    inline void SetOppositeState();


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to get a string with text describing the state of the bit
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
    //      A string with text describing the state of the bit. If the bit is ON then "ON", and "OFF" otherwise
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. 
    //
    //  Possible errors :
    //
    //      1. There is no more free memory space - Class Error::Exception is thrown
    //      2. 
    //
    EnsureRetrunValueIsUsed inline Language::String ToString();


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to get the number of characters that are needed to store the bit state in this instance as string
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
    //      The number of characters that are needed to store the bit state in this instance as string
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      NONE 
    //
    EnsureRetrunValueIsUsed inline LargestUnsignedInteger NumberOfCharactersRequiredToStoreAsString() const;


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to convert the bit state to string. The delimiter between the day of the month, month and year can be configured
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. stringPointer - a pointer with the memory address to which to store the bit state as string
    //          2. delimiter - the character that will separate the day of the month, month and year
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      The number of characters that are needed to store the bit state in this instance as string
    //
    //  Expectations :
    //
    //      1. The given string pointer is not NULL
    //      2.
    //
    //  Possible errors :
    //
    //
    //
    EnsureRetrunValueIsUsed inline LargestUnsignedInteger SetAsString( Language::Character* const stringPointer ) const;


	// The following methods declare the overloaded operators for the object :


    // Method Information :
    //
    //  Description :
    //
    //      Assignment operator, used to set the state of the bit using an integer with the value 1 ( ON ) or 0 ( OFF )
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          state - this boolean will be used to determine the bit state
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      A reference to this instance
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    inline SelfType& operator=( const BitState state );


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
    //          other - a reference to the instance that should be compared with this instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      1. true - if the 2 instances are the same
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. The other instance should not be in default state
    //      3. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline Boolean operator==( const SelfType& other ) const;


    // Method Information :
    //
    //  Description :
    //
    //      Use this operator to check if the this instance match the given state
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          state - check if the bit is in this state
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      1. true - if the bit is in the required state
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline Boolean operator==( const BitState state ) const;


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
    //          other - a reference to the instance that should be compared with this instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      1. true - if the 2 instances are not the same
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. The other instance should not be in default state
    //      3. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline Boolean operator!=( const SelfType& other ) const;


    // Method Information :
    //
    //  Description :
    //
    //      Use this operator to check if the this instance does not match the given state
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          state - check if the bit is not in this state
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      1. true - if the bit is not in the required state
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline Boolean operator!=( const BitState state ) const;


    // Method Information :
    //
    //  Description :
    //
    //      Use this operator to get the result of the and ( & ) operation between this instance and the other
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          other - a reference to other instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      An integer ( with the value 1 or 0 ) describing the result of the and operation
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. The other instance should not be in default state
    //      3. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline BitState operator&( const SelfType& other ) const;


    // Method Information :
    //
    //  Description :
    //
    //      Use this operator to get the result of the and ( & ) operation between this instance and the boolean
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          state - a boolean
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      An integer ( with the value 1 or 0 ) describing the result of the and operation
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline BitState operator&( const BitState state ) const;


    // Method Information :
    //
    //  Description :
    //
    //      Use this operator to get the result of the or ( | ) operation between this instance and the other
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          other - a reference to other instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      An integer ( with the value 1 or 0 ) describing the result of the or operation
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. The other instance should not be in default state
    //      3. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline BitState operator|( const SelfType& other ) const;


    // Method Information :
    //
    //  Description :
    //
    //      Use this operator to get the result of the or ( | ) operation between this instance and the boolean
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          state - a boolean
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      An integer ( with the value 1 or 0 ) describing the result of the or operation
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline BitState operator|( const BitState state ) const;


    // Method Information :
    //
    //  Description :
    //
    //      Use this operator to get the result of the xor ( ^ ) operation between this instance and the other
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          other - a reference to other instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      An integer ( with the value 1 or 0 ) describing the result of the xor operation
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. The other instance should not be in default state
    //      3. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline BitState operator^( const SelfType& other ) const;


    // Method Information :
    //
    //  Description :
    //
    //      Use this operator to get the result of the xor ( ^ ) operation between this instance and the boolean
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          state - a boolean
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      An integer ( with the value 1 or 0 ) describing the result of the xor operation
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline BitState operator^( const BitState state ) const;


    // Method Information :
    //
    //  Description :
    //
    //      Use this operator to set the result of the and ( & ) operation between this instance and the other
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          other - a reference to other instance
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
    //      1. The instance should be ready
    //      2. The other instance should not be in default state
    //      3. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    inline SelfType& operator&=( const SelfType& other );


    // Method Information :
    //
    //  Description :
    //
    //      Use this operator to set the result of the and ( & ) operation between this instance and the boolean
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          state - a boolean
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
    //      1. The instance should be ready
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    inline SelfType& operator&=( const BitState state );


    // Method Information :
    //
    //  Description :
    //
    //      Use this operator to set the result of the or ( | ) operation between this instance and the other
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          other - a reference to other instance
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
    //      1. The instance should be ready
    //      2. The other instance should not be in default state
    //      3. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    inline SelfType& operator|=( const SelfType& other );


    // Method Information :
    //
    //  Description :
    //
    //      Use this operator to set the result of the or ( | ) operation between this instance and the boolean
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          state - a boolean
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
    //      1. The instance should be ready
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    inline SelfType& operator|=( const BitState state );


    // Method Information :
    //
    //  Description :
    //
    //      Use this operator to set the result of the xor ( ^ ) operation between this instance and the other
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          other - a reference to other instance
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
    //      1. The instance should be ready
    //      2. The other instance should not be in default state
    //      3. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    inline SelfType& operator^=( const SelfType& other );


    // Method Information :
    //
    //  Description :
    //
    //      Use this operator to set the result of the xor ( ^ ) operation between this instance and the boolean
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          state - a boolean
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
    //      1. The instance should be ready
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    inline SelfType& operator^=( const BitState state );


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


    // This object will store the memory address that the bit index will be offset from
    IntegerType* member_memoryAddress;

    // This object will store the index of the required bit. The index will be used to determine the offset to the bit, but it is important to notice that
    // Intel uses big endian encoding which means that for each byte the bit accesible as 0 is the lowest significant bit, which is always "farest" from
    // the pointer that points :
    //
    //          Bytes memory address    -->                   0x01       0x02
    //                                                          |         |
    //          Bytes                   -->                     00000000  00000000
    //                                                                 |         |
    //          Lowest significant bit  -->                            *         *
    //
    // Then the index provided will be determined from the lowest significant bit in the first byte the memory address points too, and from there the index
    // will be used to determine the required bit 
    UnsignedInteger64bits member_bitIndex;


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
	// rather help implement it :


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to get a reference to the byte that contains the bit
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
    //      A reference to the byte that contains the bit
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline UnsignedInteger8bits& GetReferenceToTheByteThatContainsTheBit__Private();


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to get a constant reference to the byte that contains the bit
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
    //      A constant reference to the byte that contains the bit
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline const UnsignedInteger8bits& GetReferenceToTheByteThatContainsTheBit__Private() const;


    // Method Information :
    //
    //  Description :
    //  
    //      Use to get a byte with all the bits OFF beside one bit in the same location as the bit managed by the instance that will be ON
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
    //      A byte with all the bits OFF beside one bit in the same location as the bit managed by the instance that will be ON
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline UnsignedInteger8bits GetByteWithOnebitOnInTheRequiredIndex__Private() const;


    // Method Information :
    //
    //  Description :
    //  
    //      Use to get a byte with all the bits ON beside one bit in the same location as the bit managed by the instance that will be OFF
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
    //      A byte with all the bits ON beside one bit in the same location as the bit managed by the instance that will be OFF
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline UnsignedInteger8bits GetByteWithOnebitOffInTheRequiredIndex__Private() const;


	// Friend class or friend function can access private and protected members of other object in which it is declared as friend. It is sometimes useful
	// to allow a particular object to access private members of other object. The declration of such function is private, because these functions are part
	// of the implemntation, which the user should not be aware of. The use of this functions is not limited to the object's scope. One of the problems that
	// friend declaration solves is when the object needs to be as a right side operand in expressions. Every method in the object is implicitly added a pointer
	// to the location of the object data with the name "this", and to enable this the method must be called from an existing instance. This means that the
	// object can only be implemented as the left side operand of an expression with methods, and friend functions and objects does not have this limitation


    // Function Information :
    //
    //  Description :
    //
    //      Create the operator "~" so the use would be the same as with regular bits. This method is declared and defined outside of the bit object scope becuase this 
    //      operator comes before the object, which means it must receive the object
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          bit - a reference to the Bit instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      An integer ( 1 or 0 ) containing the negotiated state of the bit 
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< Concepts::Integer INTEGER_TYPE >
    friend inline BitState operator~( const Bit< INTEGER_TYPE >& bit );


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
    //          1. state - a boolean
    //          2. other - a reference to the instance that should be compared with this instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      1. true - if the 2 instances are the same
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. The other instance should not be in default state
    //      3. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< Concepts::Integer INTEGER_TYPE >
    friend inline Boolean operator==( const BitState state, const Bit< INTEGER_TYPE >& other );


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
    //          1. state - a boolean
    //          2. other - a reference to the instance that should be compared with this instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      1. true - if the 2 instances are not the same
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. The other instance should not be in default state
    //      3. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< Concepts::Integer INTEGER_TYPE >
    friend inline Boolean operator!=( const BitState state, const Bit< INTEGER_TYPE >& other );


};  //  Class Bit