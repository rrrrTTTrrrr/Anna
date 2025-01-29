namespace Universe
{


namespace Memory
{



// Template Class Information :
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
//			2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will
//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few
//						   data members
//
//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this
//						 part will end with the suffix __Private
//
//		2. Template arguments :
//
//			1. Type - any type
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< Concepts::RawButPointerIsAllowed DataType >
class DoubleLinkedListNode NotForInheritance
{
public:


    // Create a type definition for this object
    using SelfType = DoubleLinkedListNode< DataType >;


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
	//			1. data - a constant reference to the data to store in the instance
	//			2. nextNode - the memory address of of the next node
	//			3. previousNode - the memory address of of the previous node
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
	explicit inline DoubleLinkedListNode( const DataType& data, SelfType* const nextNode = nullptr, SelfType* const previousNode = nullptr );


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
	//			1. data - an rvalue reference to the data to store in the instance
	//			2. nextNode - the memory address of of the next node
	//			3. previousNode - the memory address of of the previous node
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
	explicit inline DoubleLinkedListNode( DataType&& data, SelfType* const nextNode = nullptr, SelfType* const previousNode = nullptr );


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
	inline ~DoubleLinkedListNode() = default;


	// This part will contain all the get and set methods for the members of the object :


	GetByReference_Creator( /* GetMethodName */ Data, /* MemberName */ member_data, /* MemberType */ DataType )
	GetByConstantReference_Creator( /* GetMethodName */ Data, /* MemberName */ member_data, /* MemberType */ DataType )

	GetByValue_Creator( /* GetMethodName */ NextNode, /* MemberName */ member_nextNode, /* MemberType */ SelfType* )
	SetPointerByValue_Creator( /* SetMethodName */ SetNextNode, /* MemberName */ member_nextNode, /* MemberType */ SelfType )

	GetByValue_Creator( /* GetMethodName */ PreviousNode, /* MemberName */ member_previousNode, /* MemberType */ SelfType* )
	SetPointerByValue_Creator( /* SetMethodName */ SetPreviousNode, /* MemberName */ member_previousNode, /* MemberType */ SelfType )


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


    // Disable all copy and move related methods
    DisableCopyAndMove( DoubleLinkedListNode );


	// This object will store the data
	DataType member_data;

	// This object will store the memory address of the next node
	SelfType* member_nextNode;

	// This object will store the memory address of the previous node
	SelfType* member_previousNode;


};  //  Class DoubleLinkedListNode