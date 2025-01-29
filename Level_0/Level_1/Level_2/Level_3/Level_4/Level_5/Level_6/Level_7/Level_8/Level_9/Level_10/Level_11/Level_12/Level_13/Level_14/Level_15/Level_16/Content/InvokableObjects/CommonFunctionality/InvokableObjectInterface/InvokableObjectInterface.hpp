namespace Universe
{



// Class Information :
//
//  Purpose :
//
//		Artifical Inteligence
//
//  Description :
//
//		1. The main purpose of an interface is to ensure that the group of objects which inherit from it, will be forced to implement some
//		   functionality. The interface will only decalre some methods, without implementing them. The point is that all the inherting objects
//		   will have to implement the lacking functionality. Methods that are only declared, and do not have implementation in the object, are
//		   called pure virtual methods. The syntax for pure virtual methods is :
//
//				virtual void PureVirutalMethod( UnsignedInteger64bits number ) = 0;
//
//		   A pure virtual method means, that the object 'lacks' some part of the implementation, and therefore no instances of the object
//		   can be created, because it is not a 'complete object'. Now, each object that inherits from it, will be forced to implement that
//		   missing functionality, and instances of the inherting object can exist. As said above this is good to ensure a group of objects
//		   implement some functionality, but it also gives the ability to point only to the 'interface part' of the object and use it without
//		   actually knowing the exact type of the object. This is used, for example, to create containers of pointers to different objects,
//		   that all inherit from the same object, and this is also valid to base objects that are not pure interfaces
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
template< typename ReturnType, typename... ArgumentTypes >
class InvokableObjectInterface
{
public:


	// Create a type definition for this object
	using SelfType = InvokableObjectInterface< ReturnType, ArgumentTypes... >;


	// This macro will be used to add all the infrastructure of an interface. All the methods will have the default behaviour generated by the compiler :
	//
	//		1. Defualt constructor
	//		2. Copy constructor
	//		3. Assignment operator
	//		4. Move constructor
	//		5. Move assignment operator
	//		6. Destructor
	//
	InterfaceInfrastructure_ForInheritance( InvokableObjectInterface )


	// The following methods declare the overloaded operators for the object, which each inherting object will have to implement :


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to invoke the object, using the given arguments. This operator will give instances of this object the
	//		ability to be used as if they are functions. This version is for constant instances
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			arguments - the arguments required to invoke the function the instance points too
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The return value from calling the function
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. The given function failes and throws an exception
	//		2.
	//
	virtual ReturnType operator()( ArgumentTypes... arguments ) = 0;


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to invoke the object, using the given arguments. This operator will give instances of this object the
	//		ability to be used as if they are functions. This version is for constant instances
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			arguments - the arguments required to invoke the function the instance points too
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The return value from calling the function
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. The given function failes and throws an exception
	//		2.
	//
	virtual ReturnType operator()( ArgumentTypes... arguments ) const = 0;


};  //  Class BaseFunction



}  //  Namespace Universe