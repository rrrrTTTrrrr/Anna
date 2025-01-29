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
template< Concepts::FunctorWithoutReturnValue TaskType >
class WorkersThreadsOfExecution NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = WorkersThreadsOfExecution< TaskType, CircularBufferSize >;

	// Create a type definition for the task function signature
	using TaskFunctionType = void ( TaskType& );


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
	explicit inline WorkersThreadsOfExecution(  const LargestUnsignedInteger numberOfThreadsOfExecution = 1UL, const LargestUnsignedInteger circularBufferSize = 4096UL );


	// Add the following infrastructure to the object :
	//
	//		1. Assigenment operator
	//		2. Move constructor
	//		3. Move assigenment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure( WorkersThreadsOfExecution )


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
	inline ~WorkersThreadsOfExecution();


	// This part will contain all the get and set methods for the members of the object :


	GetByValue_Creator( /* GetMethodName */, /* MemberName */ , /* MemberType */ )
	SetByValue_Creator( /* SetMethodName */, /* MemberName */, /* MemberType */ )


	// The following methods give access and manipulate the data inside this object :



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
	DisableCopyAndMove( WorkersThreadsOfExecution );


	// This object will store the tasks that needs to be performed by the threads of execution in the pool
	CircularBuffer< TaskType, CircularBufferSize > member_tasks;

	// This object will store the threads of execution that will perform the tasks
	SequentialDataStructure< ThreadOfExecution< TaskFunctionType > > member_threadsOfExecution;

	// This object will be used to stop the threads of execution when the time comes
	Atomic< Boolean > member_shouldStop;


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of
	// the interface, but rather help implement it :


	// Method Information :
	//
	//  Description :
	//
	//		This method will run in the threads of execution. It will wait for a task to be pushed to the circular buffer. When it happens it
	//		will pop the task and perform it
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
	inline void WaitForTasksToArriveAndExecute__Private();


};  //  Class WorkersThreadsOfExecution