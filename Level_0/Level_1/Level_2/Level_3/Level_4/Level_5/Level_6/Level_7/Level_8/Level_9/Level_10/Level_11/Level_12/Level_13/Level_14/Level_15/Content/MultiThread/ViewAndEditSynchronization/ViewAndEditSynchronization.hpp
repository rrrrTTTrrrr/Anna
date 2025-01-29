namespace Universe
{


namespace MultiThread
{



// Class Information :
//
//  Purpose :
//
//		The purpose of the object is to allow to synchronize between threads, where some of the threads can execute together, while others
//		must block and continue execution of the specific code alone. For example, some of the threads access data, but does not change it,
//		so there is no problem that has many threads will access the data. On the other hand when a thread wants to change the data, it must
//		block all other threads, perform the action and only than to let other threads access the data
//
//  Description :
//
//		1. There is a few key assumptions that must be in mind when using the object :
//
//			1. Destructor and Copy constructor are not synchronized - this means that it is up to the user of the object to ensure, that
//			   a reference or pointer to the same instance of this object in multiple threds of execution, will not be used both in 
//			   destruction and construction of another instance by copying or moving it. In other words, the user of the object must
//			   ensure, that a reference or pointer to an instance given to another thread of execution will be valid!
//			2. Destructor is not synchronized with the viewing and editing of the instance - this means that the user of the object must
//			   finish all reading and writing operations through the instance in the thread of execution the destructor was called from
//
// 		2. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
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
//		3. The object contains a counter and a spin wait loop. The counter is for the amount of threads that currently were allowed to continue
//		   and allow other threads to continue as well. The spin wait loop is used to ensure that only one thread has access to the counter
//		   everytime. Than the implementation is, a thread waits until it can lock the spin wait loop and ensure that only it got access to
//		   the counter. Now it depends on the thread purpose, if the thread allows other thread to continue as well, it will only increment
//		   the counter by one, and than release the spin wait loop for the next thread. If the thread needs to block other threads, it will
//		   wait until the counter is zero, which means no other thread is currently in the flow, and just than it can continue. When the
//		   thread has done, the behavior also depends on the type of thread. For threads that allow other threads to continue as well, all 
//		   there is to do is to decrement the counter by one, while threads that require other threads to be blocked, needs to release the
//		   spin wait loop so other threads can access the counter
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
class ViewAndEditSynchronization NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = ViewAndEditSynchronization;


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
	inline ViewAndEditSynchronization();


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
	inline ~ViewAndEditSynchronization() = default;


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to view the resource. All threads of execution that request to view, can do it simultaneously, as they
	//		are not changing the resource. Only when a thread of execution require to edit the resource, all other threads of execution
	//		are blocked for the duration
	//		
	//		Note - the thread of execution should call the following method when done viewing - 'DoneViewing'
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
	inline void View();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to edit the resource. All other threads of execution will be blocked for the duration. The editing will only
	//		start after all previous threads of execution will finish using the resource, viewers and editors
	//
	//		Note - the thread of execution should call the following method when done editing - 'DoneEditing'
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
	inline void Edit();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to edit the resource, and when finished the ability to switch to viewing and allow other threads of execution
	//		to view the resource as well. All other threads of execution will be blocked for the duration of the editing. The editing will 
	//		only start after all previous threads of execution will finish using the resource, viewers and editors
	//
	//		Note - the thread of execution should call the following method when done editing - 'DoneEditing', and when also done viewing
	//		call the method 'DoneViewing'
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
	inline void EditThenViewWithoutLettingOtherThreadsOfExecutionEditBetween();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to notify that this thread of execution has finished viewing the resource
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
	//		1. The method 'View' or 'EditThenViewWithoutLettingOtherThreadsOfExecutionEditBetween' was called prior to this call
	//		2.
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void DoneViewing();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to notify that this thread of execution has finished editing the resource
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
	//		1. The method 'Edit' or 'EditThenViewWithoutLettingOtherThreadsOfExecutionEditBetween' was called prior to this call
	//		2.
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void DoneEditing();


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

		static void* UnitTest_Read( void* argument );

		static void* UnitTest_Write( void* argument );

        struct UnitTest_ArgumentsToFunction
        {
            ViewAndEditSynchronization* testInstance;
            UnsignedInteger64bits* testCounter;
            UnsignedInteger64bits numberOfAdditionsToExecute;
        };

	)  //  End of debug tool


private:


    // Disable all copy and move related methods, this include the copy constructor, move constructor, assignment operator and move assignment operator
    DisableCopyAndMove( ViewAndEditSynchronization );


	// This object will store the number of threads that were allowed to continue. When the thread will finish the work it will
	// decrement this counter by one to notify that it has finished
	Atomic< SignedInteger64bits > member_numberOfViewingThreadsOfExecution;

	// This object will be used to synchronize between different users of the instance to ensure that ceratin sections are accessed
	// in the right order
	CentralProcessingUnit::SpinWaitLoop member_spinWaitLoopToSynchronizeThreadsOfExecution;


};  //  Class ViewAndEditSynchronization