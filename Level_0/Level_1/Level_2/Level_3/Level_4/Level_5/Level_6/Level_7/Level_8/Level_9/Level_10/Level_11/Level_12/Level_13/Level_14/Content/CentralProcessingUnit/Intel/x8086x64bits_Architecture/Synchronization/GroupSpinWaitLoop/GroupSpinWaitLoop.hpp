namespace Universe
{


namespace CentralProcessingUnit
{



// Class Information :
//
//  Purpose :
//
//		Use this object to create a lock for some purpose. This lock will be placed in the stack, this means that in order to share this lock across threads or
//      processes, there should be one instance and a reference to it must be passed to each other process or thread of execution. Therefore, this object has no
//      copy or move operations
//
//  Description :
//
//      1. This object is used as a base object in inheritance. Therefore it must have a few methods virtual. When an object has a virtual method, the C++ automatically
//		   creates a table with all the pointers to the virtual methods, where the pointer to the table is stored in the beginning of the object. The problem arises
//		   when a new method needs to be created with the same signature as one in the base object, and the use of pointers. Take a look at next example :
//
//             class Base
//             {
//                 void Display() { cout << "Lord" << endl; }
//             };
//
//             class Derived : public Base
//             {
//                 void Display(); { cout << "Help Me" << endl; }    -> Derived inherits Display from Base but needs another behavior
//             };
//
//         Now if a call is made :
//
//             Base* base = new Base;
//             Derived* derived = new Derived;
//
//             base->Display( 5 );   -> Outputs "Lord"
//             derived->Display();   -> Outputs "Help Me"
//
//         So far so good, a normal method is called by the static type of the pointer. This means no matter what the object the pointer is pointing to it will call
//		   the method of the type he was declared as. This is a problematic behavior in inheritance, we need to point to derived objects with base pointers and that
//		   the correct method will be called. But now :
//
//             void Do( Base* base ) { base->Display(); }
//
//             Base* base = new Base;
//             Derived* derived = new Derived;
//
//             Do( base );        -> Outputs "Lord"
//             Do( derived );     -> Outputs "Lord"
//
//         This is what virtual allow in C++, instead of calling the method by the static type in compilation, the call to the method is picked dynamically by the actual
//		   type of the object. This is done by the pointer in the beginning of the object that points to the virtual table of the type. Of course it can be overloaded
//		   to the derived, but then if there is a deep inheritance a method will be needed to be overloaded for each one
//
//      2. This object contains an instance of the object "State" to allow each instance of this object to have a defined state
//
// 		3. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by providing 3 keywords :
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
//							 suffix _IMP
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
class GroupSpinWaitLoop NotForInheritance
{
public:


    // Create a type definition for this object
    using SelfType = GroupSpinWaitLoop;


    // The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler
    // generates a basic behavior for them :


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
	inline GroupSpinWaitLoop();


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
	inline ~GroupSpinWaitLoop() = default;


    // The following methods give access and manipulate the data inside this object :


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to add this instance into the spin wait loop queue and wait until it is allowed to proceed
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
    //      1. The intel documentation is correct
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    inline void Wait();


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to notify that this instance has done using and the next one can stop waiting
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
    //      1. A call to the method 'WaitUntilAllowedToLockToEnsureOnlyThisThreadWillContinue' needs to happen before this method
    //      2. 
    //
    //  Possible errors :
    //
    //      NONE
    //
    inline void ReleaseCurrentWaitingGroupThreadsOfExecution();


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
		static void UnitTest();

        static void* UnitTest_Add( void* argument );

        struct UnitTest_ArgumentsToFunction
        {
            GroupSpinWaitLoop* groupSpinWaitLoopPointer;
            UnsignedInteger64bits* sharedMemoryPointer;
        };

	)  //  End of debug tool


private:


    // Disable all copy and move related methods, this include the copy constructor, move constructor, assignment operator and move assignment operator
    DisableCopyAndMove( GroupSpinWaitLoop );


    // This object will be used to identify the current group of threads of execution waiting to continue. Each request to wait, will trigger a read
    // operation on the current group identifier value. It will be used to determine when the group of threads of execution should stop waiting and
    // continue. When a request to release is triggered, the group identifer value will be incremented by 1. This will signal all threads of execution
    // to stop waiting and continue
    MultiThread::Atomic< UnsignedInteger64bits > member_groupIdentifier;


};  //  Class GroupSpinWaitLoop