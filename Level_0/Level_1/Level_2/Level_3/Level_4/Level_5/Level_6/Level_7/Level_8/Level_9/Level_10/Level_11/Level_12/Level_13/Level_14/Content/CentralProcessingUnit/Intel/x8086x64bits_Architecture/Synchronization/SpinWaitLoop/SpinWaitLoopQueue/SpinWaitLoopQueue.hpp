namespace Universe
{


namespace CentralProcessingUnit
{



// Class Information :
//
//  Purpose :
//
//		The process used to allow the spin wait loop is to use 2 integers, the first represents the current request in the queue that was allowed to 
//      stop waiting. The second is the 'queue' itself, Each request increments this value to notify of its will to get a turn also. Each instance of
//      this object will be shared among all the requests to provide the state of the queue, and who should stop waiting. Each instance of this object 
//      is initialized to the state :
//
//              member_currentRequestAllowedToStopWaiting = 0
//              member_spinWaitQueue = 0
//
//      The reason is, each request will notify that it wants a turn by incrementing the spin wait queue member by 1. This operation also stores 
//      the old state of the instance into its own thread's context register, this old state will be used in the first iteration of the spin wait
//      loop to check if it should wait or not. If the 2 members are equal it means it should stop waiting, but if they are not it should spin wait
//      loop until they are. Finally each should notify that it has done, by incrementing the current request allowed to stop waiting member. Now, 
//      the first request will increment by 1, and in the initialization the members match, so it will be allowed to not wait, but every one trying
//      to get a turn from now, will be given that the members mismatch and should wait until the curent requester is done.
//
//      The instance layout :
//
//                                                                spin wait loop queue            current request allowed to 
//                                                                                                        stop waiting
//                                                        ___________________________________ ___________________________________
//                                                        |                                 | |                                 |
//                                   Address   ->         00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
//                                                        |                                                                     |
//                                               High significant bit                                                 Low significant bit
//
//  Description :
//
//      1. This object does not contain a 'State' instance to ensure 8 byte alignment
//
// 		2. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by providing 3 keywords :
//
//				1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the obejct using the tools
//							presented here. This part will usually contain only methods and not data members. If a data member is public all the encapsulation is
//							lost, so it should be avoided in most cases
//
//				2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will be able to access
//							   all the data and methods inside this part. This part will usually containt some methods and few data members
//
//				3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object and all the
//							 methods the developer needed to implement the interface presented in the public part. Every method in this part will end with the
//							 suffix __Private
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
class SpinWaitLoopQueue NotForInheritance
{
public:


	// Create a type definition for this object
    using SelfType = SpinWaitLoopQueue;


    // This number represents the current request in the queue that was allowed to stop waiting
    UnsignedInteger32bits member_currentRequestAllowedToStopWaiting;

    // This will be the queue that stores the requests
    UnsignedInteger32bits member_spinWaitQueue;
    

    // This object only needs default constructor. After the initialization the instances are taken as one unit of 8 bytes, instead of accessing
    // each member to allow that the value from memory be read, manipulated ( in this case increments of 1 to one of the members ), and then stored
    // back to memory without any other central processing unit access 


    // Method Information :
    //
    //  Description :
    //
	//   	Default Constructor,
	//
	//  Required arguments :
	//
	//   	User information needed :
	//
	//          NONE
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//   	NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline SpinWaitLoopQueue();


	// Method Information :
	//
	//  Description :
	//
	//   	Destructor, does not throw
	//
	//  Required arguments :
	//
	//   	User information needed :
	//
	//          NONE
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//   	NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline ~SpinWaitLoopQueue() = default;


	DEBUG_TOOL(

		// This part of the object is dedicated for testing :


		// Method Information :
		//
		//  Description :
		//
		//      This method is used to test the object. It is not part of the implementation, it is only used to find problems with the code
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
    DisableCopyAndMove( SpinWaitLoopQueue );


};  //  Class SpinWaitLoopQueue