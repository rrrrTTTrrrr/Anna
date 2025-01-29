namespace Universe
{


namespace Linux
{



// There are 2 functions provided by Linux to display the text message associated with errno :
//
//  1. perror - displays the string passed to it, followed by a colon and space, and then the textual representation of the current errno value
//
//  2. strerror - returns a pointer to the textual representation of the current error value



// Use the following macro to throw an errno exception
//
#define ThrowErrnoException throw( Linux::ErrnoException( __FILE__, __FUNCTION__, __LINE__ ) )



// Class Information :
//
//  Purpose :
//
//		Artifical Inteligence
//
//  Description :
//
//		1. This object is used as a base object in inheritance. Therefore it must have a few methods virtual. When an object has a virtual method, the
//		   C++ automatically creates a table with all the pointers to the virtual methods, where the pointer to the table is stored in the beginning of
//		   the object. The problem arises when a new method needs to be created with the same signature as one in the base object, and the use of pointers.
//		   Take a look at next example :
//
//				class Base
//				{
//				    void Display() { cout << "Lord" << endl; }
//				};
//
//				class Derived : public Base
//				{
//				    void Display(); { cout << "Help Me" << endl; }    -> Derived inherits Display from Base but needs another behavior
//				};
//
//         Now if a call is made :
//
//				Base* base = new Base;
//				Derived* derived = new Derived;
//
//				base->Display( 5 );   -> Outputs "Lord"
//				derived->Display();   -> Outputs "Help Me"
//
//         So far so good, a normal method is called by the static type of the pointer. This means no matter what the object the pointer is
//		   pointing to it will call the method of the type he was declared as. This is a problematic behavior in inheritance, we need to point
//		   to derived objects with base pointers and that the correct method will be called. But now :
//
//				void Do( Base* base ) { base->Display(); }
//
//				Base* base = new Base;
//				Derived* derived = new Derived;
//
//				Do( base );        -> Outputs "Lord"
//				Do( derived );     -> Outputs "Lord"
//
//         This is what virtual allow in C++, instead of calling the method by the static type in compilation, the call to the method is picked
//		   dynamically by the actual type of the object. This is done by the pointer in the beginning of the object that points to the virtual
//		   table of the type. Of course it can be overloaded to the derived, but then if there is a deep inheritance a method will be needed to
//		   be overloaded for each one
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
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
class ErrnoException : public Error::Exception
{
public:


	// Create a type definition for this object
	using SelfType = ErrnoException;


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
	inline ErrnoException();


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
    //          1. fileName - an ascii string with the file name from which the exception was thrown
    //          2. functionName - an ascii string with the function name from which the exception was thrown
    //          3. lineNumber - the number of line from which the exception was thrown
    //          4. errorMessage - the memory address of the user error message
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
    //      1. The given pointer to the file name is not NULL
    //      2. The given pointer to the function name is not NULL
    //      3. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	explicit inline ErrnoException( const char* const fileName, const char* const functionName, const SignedInteger32bits lineNumber );


	// Method Information :
	//
	//  Description :
	//
	//		Copy constructor, will operate correctly even if the other object is in default state
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//          other - a reference to the instance that should be copied
	//
	//		Information returned to the user :
	//
	//          NONE
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
	inline ErrnoException( const SelfType& other );


	// Add the following infrastructure to the object :
	//
	//		1. Assigenment operator
	//		2. Move constructor
	//		3. Move assigenment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure_ForInheritance( ErrnoException )


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
	virtual ~ErrnoException() = default;


	// The following methods declare the overloaded operators for the object :


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
	EnsureRetrunValueIsUsed Boolean operator==( const SelfType& other ) const;


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
		static void Test() __attribute__ (( __unused__ ));

	)  //  End of debug tool


};  //  Class ErrnoException