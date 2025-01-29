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
//		1. This object is used only to wrap some static methods, which can be used without any instance of the object
//
//		2. This object has all the methods to create, destory, copy and move disabled to ensure that no instances of it will be created
//
// 		3. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
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
class TypeIdentification NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = TypeIdentification;


	// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object.
	// Satic functions only have access to static data members, which also don't belong to any instance, this means all other data members
	// can not be used. The only purpose then of declaring a static function is when a private static data member needs to be manipulated,
	// or some functionality needed that does not involve the non static data members


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to get the identification number of the template type object
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
    //      The identification number of the template type object
    //
    //  Exceptions :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come 
    //
    template< typename Type >
    EnsureRetrunValueIsUsed static inline UnsignedInteger64bits Get();


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to get the number of types that are using this object to create an identification number
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
    //      The number of types that are using this object to create an identification number
    //
    //  Exceptions :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come 
    //
    EnsureRetrunValueIsUsed static inline UnsignedInteger64bits NumberOfTypes();


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


	// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
	NoInstances( TypeIdentification );


	// Static data members do not belong to any instance, they belong to the object. Like every global variable it is created with the
	// start of the program and only destroyed when the program ends. The access to the static member is bound to this object of course


    // This object will act as a counter. It will serve 2 purposes, the first as it's name imply it will count the total number of objects using this object
    // in the program, and secondly it will be used to give each template type a different ID
    static UnsignedInteger64bits member_numberOfTypes;


};  //  Class TypeIdentification