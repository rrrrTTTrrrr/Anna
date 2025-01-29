namespace Universe
{


namespace MultiThread
{



// Class Information :
//
//  Purpose :
//
//		Use this object to perform a scoped spin wait loop. This means that at construction of instance of this object, a spin wait loop
//		instance is provided. This object uses it to lock, which means it will lock the spin wait loop once its turn arrives. From there
//		it will only unlock the spin wait loop once the scope, in which the instance was declared, ends 
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
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
class ScopedSpinWaitLoop NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = ScopedSpinWaitLoop;


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
	//			spinWaitLoop - a pointer with the memory address of the spin wait loop instance to operate on
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
	//		1. The pointer to the spin wait loop should not be NULL
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	explicit inline ScopedSpinWaitLoop( CentralProcessingUnit::SpinWaitLoop* const spinWaitLoop );


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
	inline ~ScopedSpinWaitLoop();


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


    // Disable all copy and move related methods, this include the copy constructor, move constructor, assignment operator and move assignment operator
    DisableCopyAndMove( ScopedSpinWaitLoop );


    // This pointer will store the memory address of the spin wait loop instance that this instance will operate on
    CentralProcessingUnit::SpinWaitLoop* member_spinWaitLoop;


};  //  Class ScopedSpinWaitLoop