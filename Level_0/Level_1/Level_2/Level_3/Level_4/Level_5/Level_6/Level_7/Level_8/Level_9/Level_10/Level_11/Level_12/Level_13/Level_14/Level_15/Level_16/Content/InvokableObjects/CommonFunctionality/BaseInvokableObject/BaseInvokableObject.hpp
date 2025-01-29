namespace Universe
{



// Class Information :
//
//  Purpose :
//
//		This object will be used as the base object for each type of pointer to invokable entity, to provide the information which common to all
//		of them
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
//		4. Template arguments :
//
//			1. Type -
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< typename ReturnValueType, typename... ArgumentTypes >
class BaseInvokableObject
{
public:


    // The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
	// the compiler generates a basic behavior for them if possible :


	// Method Information :
	//
	//  Description :
	//
	//		Default constructor,
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
	inline BaseInvokableObject() = default;


	// Method Information :
	//
	//  Description :
	//
	//		Copy constructor, will operate correctly even if the other instance is in default state or self assignment
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			other - a reference to the instance that should be copied
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
	inline BaseInvokableObject( const BaseInvokableObject< ReturnValueType, ArgumentTypes... >& other ) = default;


	// Method Information :
	//
	//  Description :
	//
	//      Assignment operator, can handle with self assignment and instances in default state
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          other - a reference to the object that should be copied
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      A reference to this object
	//
	//  Excpectations :
	//
	//      NONE
	//
	//  Possible errors :
	//
	//      They will come
	//
	inline BaseInvokableObject< ReturnValueType, ArgumentTypes... >& operator=( const BaseInvokableObject< ReturnValueType, ArgumentTypes... >& other ) = default;


	// Method Information :
	//
	//  Description :
	//
	//      Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances in default state
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          other - a reference to the object that should be moved
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      NONE
	//
	//  Excpectations :
	//
	//      NONE
	//
	//  Possible errors :
	//
	//      They will come
	//
	inline BaseInvokableObject( BaseInvokableObject< ReturnValueType, ArgumentTypes... >&& other ) = default;


	// Method Information :
	//
	//  Description :
	//
	//      Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          other - a reference to the object that should be moved
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      A reference to this object
	//
	//  Excpectations :
	//
	//      NONE
	//
	//  Possible errors :
	//
	//      They will come
	//
	inline BaseInvokableObject< ReturnValueType, ArgumentTypes... >& operator=( BaseInvokableObject< ReturnValueType, ArgumentTypes... >&& other ) = default;


	// The following methods are the interface of the object :


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to check if the function needs argumetns to be called
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
	//		A boolean with the value true if the function needs arguments to be called, and false otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed constexpr Boolean ArgumentsNeeded() const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to get the number of arguments required to invoke the function
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
	//		The number of arguments required to invoke the function. The result is 0 if there are no arguments needed
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed constexpr UnsignedInteger64bits ArgumentsNumber() const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to check if the function has a return value 
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
	//		A boolean with the value true if the function has a return value, and false otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed constexpr Boolean ReturnValueExist() const;


};  //  Class BaseInvokableObject