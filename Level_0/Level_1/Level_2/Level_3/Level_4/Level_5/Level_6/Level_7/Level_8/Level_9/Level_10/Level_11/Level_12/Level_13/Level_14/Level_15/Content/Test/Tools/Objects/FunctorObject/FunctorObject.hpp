namespace Universe
{


namespace Test
{


// Template Class Information :
//
//  Purpose :
//
//		Artifical Inteligence
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
//		3. Template arguments :
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
template< typename Type, typename ReturnType, typename... ArgumentsTypes >
class FunctorObject final
{
public:


	// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
	// the compiler generates a basic behavior for them if possible :


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
	explicit inline FunctorObject( const UnsignedInteger64bits size );


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
	inline FunctorObject( const FunctorObject< Type, ReturnType, ArgumentsTypes... >& other );


	// Method Information :
	//
	//  Description :
	//
	//      This method is used to swap the content between this instance and the other one
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			other - a reference to the instance that should be swaped
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//      NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//      They will come
	//
	inline void Swap( FunctorObject< Type, ReturnType, ArgumentsTypes... >& other );


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
	inline ~FunctorObject();


	// The following methods declare the overloaded operators for the object :


	// Method Information :
	//
	//  Description :
	//
	//		The purpose of this method is to allow an instance of the object that will implement it, to be called as if it were a function
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			arguments - any argument the object that will implement this operator will need
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		Any return value needed by the implementing object
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline ReturnType operator()( ReturnType value );


	// Method Information :
	//
	//  Description :
	//
	//		The purpose of this method is to allow an instance of the object that will implement it, to be called as if it were a function
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			arguments - any argument the object that will implement this operator will need
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		Any return value needed by the implementing object
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline ReturnType operator()( ReturnType value ) const;


    // Method Information :
    //
    //  Description :
    //
    //      Use to get reference to an entry
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          index - the index of the entry required
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      A reference to the required object
    //
	//  Expectations :
	//
	//		NONE
	//
    //  Possible errors :
    //
    //		They will come
    //
    inline Type& operator[]( unsigned long index ) const;


private :


	// This object will store an array allocated on the heap memory segment
	Type* member_array;

	// This object will store the array size
	UnsignedInteger64bits member_size;


};  //  Class FunctorObject