namespace Universe
{


    namespace Error
    {



// Use the following macro to throw an exception
//
#define ThrowException( ErrorMessage ) throw( Error::Exception( __FILE__, __FUNCTION__, __LINE__, ErrorMessage ) )



// Class Information :
//
//  Purpose :
//
//		This object is a package sent up in the function stack to describe an exception from correct behavior. Every function that can deal with 
//		the condition should catch it, and perform the required operations. If non of the functions will catch the exception the execution will 
//		terminate. The termination method can be set to ensure clean up and such
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
//		2. This object contains an instance of the object "InstanceState" to allow each instance of this object to have a defined state
//
//		3. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
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
class Exception
{
public:


    // Create a type definition for this object
    using SelfType = Exception;


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
	//          NONE
	//
	//      Information returned to the user :
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
	inline Exception();


    // Method Information :
    //
    //  Description :
    //
    //      Constructor,
    //
    //  Required arguments :
    //
    //          1. fileName - an ascii string with the file name from which the exception was thrown
    //          2. functionName - an ascii string with the function name from which the exception was thrown
    //          3. lineNumber - the number of line from which the exception was thrown
    //          4. errorMessage - the memory address of the user error message
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
    //      1. The given pointer to the file name is not NULL
    //      2. The given pointer to the function name is not NULL
    //      3. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    explicit inline Exception( const char* fileName, const char* functionName, SignedInteger32bits lineNumber, const char* errorMessage );


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
	inline Exception( const SelfType& other );


	// Add the following infrastructure to the object :
	//
	//		1. Assigenment operator
	//		2. Move constructor
	//		3. Move assigenment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure_ForInheritance( Exception )


	// Method Information :
	//
	//  Description :
	//
	//		Destructor, does not throw. Declared virtual to ensure correct deletion for derived objects
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//          NONE
	//
	//      Information returned to the user :
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
	virtual ~Exception() = default;


	// The following methods are the interface of the object :


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to get a pointer to the error message
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
    //      A pointer to the error message
    //
	//  Expectations :
	//
    //      1. The instance contains an error message
    //      2. 
	//
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed inline const AsciiCharacter* ErrorMessage() const;


	// The following methods declare the overloaded operators for the object :


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
	//          other - a reference to the instance that should be compared with this object
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
	//      Use this operator to check if the this instance does not match the other
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          other - a reference to the instance that should be compared with this object
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
		static void UnitTest() __attribute__ (( __unused__ ));

	)  //  End of debug tool


private:


    // This object will store the error message
    AsciiCharacter member_formattedErrorMessage[512];


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
	// rather help implement it :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to count the number of digits in the given integer
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          integer - the integer to count the number of digits for
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      The number of digits in the given integer
	//
	//  Expectations :
	//
    //		1. The given template type should be integer type
    //		2. 
	//
	//  Possible errors :
	//
    //		They will come
	//
    template< Concepts::Integer IntegerType >
	EnsureRetrunValueIsUsed static LargestUnsignedInteger NumberOfDigits__Private( const IntegerType integer );


    // Template method Information :
    //
    //  Description :
    //
    //      Use this method to convert the signed integer into an ascii string of digits
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //			1. destinationStringPointer - the destination memory space to store the digits of the integer
    //			2. integer - the integer that should be converted to an ascii string of digits
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      True if the integer was converted to string successfully, and false otherwise
    //
	//  Expectations :
    //
    //      1. The given pointer is not NULL	
    //		2. The pointer points to a memory space sufficient to contain all the digits of the integer
    //		3.
    //
    //  Possible errors :
    //
    //		NONE
    //
    EnsureRetrunValueIsUsed static Boolean IntegerToStringOfDigits__Private( AsciiCharacter* const destinationStringPointer, const SignedInteger32bits integer );


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to copy the content of an ascii string to the required destination
    //
    //  Required arguments :
    //
    //      User information needed :
    //
	//			1. sourceAsciiString - a pointer to the memory address of the ascii string to copy
	//			2. destinationAsciiString - a pointer to the memory address to copy the ascii string to
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      A boolean with the value true if the method was successful and false otherwise
    //
    //  Expectations :
    //
    //      1. The given source pointer is not NULL
    //      2. The given destination pointer is not NULL
    //		3. The source ascii string ends with a null terminator ( 0 )
    //		4. The destination pointer points to a memory address with enough memory space to contain the ascii string ( this can not be checked )
    //		5.
    //
    //  Possible errors :
    //
    //      They will come
    //
	EnsureRetrunValueIsUsed static Boolean CopyAsciiString__Private( const AsciiCharacter* const sourceAsciiString, AsciiCharacter* const destinationAsciiString );


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to format the error message that will be dispayed to the user
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. fileName - an ascii string with the file name from which the exception was thrown
    //          2. functionName - an ascii string with the function name from which the exception was thrown
    //          3. lineNumber - the number of line from which the exception was thrown
    //          4. errorMessage - the memory address of the user error message
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
    //      1. The given pointer to the file name is not NULL
    //      2. The given pointer to the function name is not NULL
    //      3. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    void FormatErrorMessage__Private( const char* fileName, const char* functionName, SignedInteger32bits lineNumber, const char* errorMessage );


};  //  Class Exception