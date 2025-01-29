namespace Universe
{


namespace MultiThread
{



// The purpose of the enumeration is to allow picking the required access type to the resource
enum class AccessType
{
	View,

	Edit,

	EditThenViewWithoutLettingOtherThreadsOfExecutionEditBetween
};



// Class Information :
//
//  Purpose :
//
//		Use this object to perform a scoped synchronized access. This means that at construction of instance of this object, a synchronized access
//		instance is provided. This object uses it to lock, which means it will lock the synchronized access once its turn arrives. From there
//		it will only unlock the synchronized access once the scope, in which the instance was declared, ends 
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
class ScopedViewAndEditSynchronization NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = ScopedViewAndEditSynchronization;


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
	//			1. viewAndEditSynchronizationTool - a pointer to the view and edit synchronizztion tool
	//			2. accessType - an enumeration of the required access to the resource
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
	explicit inline ScopedViewAndEditSynchronization( ViewAndEditSynchronization* const viewAndEditSynchronizationTool, const AccessType accessType = AccessType::View );


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
	inline ~ScopedViewAndEditSynchronization();


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to notify that the current thread of execution has finished editing the resource, and now only requires to
	//		view it. This method should only be called if the access type is 'EditThenViewWithoutLettingOtherThreadsOfExecutionEditBetween'
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
	//		1. The access type for the resource is 'EditThenViewWithoutLettingOtherThreadsOfExecutionEditBetween'
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

	)  //  End of debug tool


private:


    // Disable all copy and move related methods, this include the copy constructor, move constructor, assignment operator and move assignment operator
    DisableCopyAndMove( ScopedViewAndEditSynchronization );


    // This pointer will store the memory address of the view and edit synchronization tool
    ViewAndEditSynchronization* member_viewAndEditSynchronizationTool;

    // This enumeration will store the access type required to the resource
    AccessType member_accessType;

    // This boolean will only be used in the case that the access type is 'EditThenViewWithoutLettingOtherThreadsOfExecutionEditBetween'
    // to notify if the 'DoneEditing' method was already called or not
    Boolean member_wasDoneEditingCalled;


};  //  Class ScopedViewAndEditSynchronization