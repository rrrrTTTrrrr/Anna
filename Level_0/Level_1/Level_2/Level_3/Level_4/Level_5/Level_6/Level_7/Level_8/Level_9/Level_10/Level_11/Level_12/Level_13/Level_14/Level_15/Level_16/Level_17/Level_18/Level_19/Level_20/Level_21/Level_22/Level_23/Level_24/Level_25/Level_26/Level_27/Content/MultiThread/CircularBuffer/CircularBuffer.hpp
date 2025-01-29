namespace Universe
{


namespace MultiThread
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
template< Concepts::Object Type, LargestUnsignedInteger CircularBufferSize > requires ( ( CircularBufferSize > 0UL ) && ( Arithmetics::IsPowerOfTwo< UnsignedInteger64bits >( CircularBufferSize ) == true ) )
class CircularBuffer NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = CircularBuffer< Type, CircularBufferSize >;


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
	//		1. There is no more free memory space - Class Error::Exception is thrown
	//		2. 
	//
	inline CircularBuffer();


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
	inline ~CircularBuffer() = default;


	// This part will contain all the get and set methods for the members of the object :


	GetByValue_Creator( /* GetMethodName */ Size, /* MemberName */ CircularBufferSize, /* MemberType */ LargestSignedInteger )


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to push data into the buffer
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. data - a universal reference to the required data
	//			2. timeoutInSeconds - the time in seconds allowed to the method to try and push the data to the buffer
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		True if the data was successfully pushed to the buffer, and false if the timeout was reached
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename UniversalReferenceType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceType, Type >::Result == true )
	EnsureRetrunValueIsUsed inline Boolean Push( UniversalReferenceType&& data, const LargestUnsignedInteger timeoutInSeconds = 2UL );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to pop data from the buffer
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. data - a reference to the memory that the poped data will be stored in
	//			2. timeoutInSeconds - the time in seconds allowed to the method to try and pop the data from the buffer
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		True if the data was successfully poped from the buffer, and false if the timeout was reached
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Boolean Pop( Type& data, const LargestUnsignedInteger timeoutInSeconds = 2UL );


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
	DisableCopyAndMove( CircularBuffer );


	// This object will store the mask that will help perform the circular nature of the buffer. The push and pop indices will be incremented
	// alawys, and the mask will be used to ensure the value is always withing the range of the possible indices. Finally the fact that the
	// incrementing maximum value possible for the unsigned integer by one makes the value return to zero will be used. Since the size of
	// circular buffer is always a power of 2, the mask will contain all the bits on until and include the only bit that is on in the size
	LargestSignedInteger member_mask;

	// This object will store the items of the circular buffer
	Type member_circularBuffer[ CircularBufferSize ];

	// This index will be used to determine the next location to add an item
	Atomic< LargestSignedInteger > member_pushIndex;

	// This index will be used to determine the next location to remove an item
	Atomic< LargestSignedInteger > member_popIndex;

	// This object will be used to synchronize the adding and removing of items from the circular buffer. This is needed for 2 reasons, the first
	// is to ensure that the data is set into the location before it can be popped, since the index at which the data will be stored is picked first.
	// The second is to ensure that when the buffer is full the push will only happen after the location was used
	UnsignedInteger8bits member_isFree[ CircularBufferSize ];


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of
	// the interface, but rather help implement it :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to chcek if the buffer is full
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			pushIndex - the index to use for testing if the buffer is full
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		True if the buffer is full, and false otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Boolean IsFull__Private( const LargestSignedInteger pushIndex ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to chcek if the buffer is empty
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			popIndex - the index to use for testing if the buffer is empty
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		True if the buffer is empty, and false otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Boolean IsEmpty__Private( const LargestSignedInteger popIndex ) const;


};  //  Class CircularBuffer