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
template< Concepts::Integer IntegerType >
class TemplateObjectWithAllOperatorsOverloaded NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = TemplateObjectWithAllOperatorsOverloaded< IntegerType >;


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
	explicit inline TemplateObjectWithAllOperatorsOverloaded();


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
	//			startingValue - the initial value to construct the instance with
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
	explicit inline TemplateObjectWithAllOperatorsOverloaded( IntegerType startingValue );


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
	inline TemplateObjectWithAllOperatorsOverloaded( const SelfType& other );


	// Method Information :
	//
	//  Description :
	//
    //      Assignment operator, can handle with self assignment and instances in default state
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			other - a reference to the object that should be copied
	//
	//		Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//   	A reference to this object
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline SelfType& operator=( const SelfType& other );


	// Method Information :
	//
	//  Description :
	//
    //      Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances in default state
	//
	//  Required arguments :
	//
	//   	User information needed :
	//
	//          other - a reference to the object that should be moved
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
	inline TemplateObjectWithAllOperatorsOverloaded( TemplateObjectWithAllOperatorsOverloaded&& other );


	// Method Information :
	//
	//  Description :
	//
    //      Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state
	//
	//  Required arguments :
	//
	//   	User information needed :
	//
	//          other - a reference to the object that should be moved
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//   	A reference to this object
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline SelfType& operator=( SelfType&& other );


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
	inline void Swap( SelfType& other );


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
	inline ~TemplateObjectWithAllOperatorsOverloaded() = default;


	// This part will contain all the get and set methods for the members of the object :


	GetByValue_Creator( GetInteger, member_integer, IntegerType )


	// The following methods declare the overloaded operators for the object :


    IntegerType operator+( const TemplateObjectWithAllOperatorsOverloaded& other ) const { return ( member_integer + other.member_integer ); }
    IntegerType operator-( const TemplateObjectWithAllOperatorsOverloaded& other ) const { return ( member_integer - other.member_integer ); }
    IntegerType operator*( const TemplateObjectWithAllOperatorsOverloaded& other ) const { return ( member_integer * other.member_integer ); }
    IntegerType operator/( const TemplateObjectWithAllOperatorsOverloaded& other ) const { return ( member_integer / other.member_integer ); }
    IntegerType operator%( const TemplateObjectWithAllOperatorsOverloaded& other ) const { return ( member_integer % other.member_integer ); }

    TemplateObjectWithAllOperatorsOverloaded& operator+=( const TemplateObjectWithAllOperatorsOverloaded& other ) { member_integer += other.member_integer; return ( *this ); }
    TemplateObjectWithAllOperatorsOverloaded& operator-=( const TemplateObjectWithAllOperatorsOverloaded& other ) { member_integer -= other.member_integer; return ( *this ); }
    TemplateObjectWithAllOperatorsOverloaded& operator*=( const TemplateObjectWithAllOperatorsOverloaded& other ) { member_integer *= other.member_integer; return ( *this ); }
    TemplateObjectWithAllOperatorsOverloaded& operator/=( const TemplateObjectWithAllOperatorsOverloaded& other ) { member_integer /= other.member_integer; return ( *this ); }
    TemplateObjectWithAllOperatorsOverloaded& operator%=( const TemplateObjectWithAllOperatorsOverloaded& other ) { member_integer %= other.member_integer; return ( *this ); }

    Boolean operator==( const TemplateObjectWithAllOperatorsOverloaded& other ) const { return ( member_integer == other.member_integer ); }
    Boolean operator!=( const TemplateObjectWithAllOperatorsOverloaded& other ) const { return ( member_integer != other.member_integer ); }
    Boolean operator>( const TemplateObjectWithAllOperatorsOverloaded& other ) const { return ( member_integer > other.member_integer ); }
    Boolean operator<( const TemplateObjectWithAllOperatorsOverloaded& other ) const { return ( member_integer < other.member_integer ); }
    Boolean operator>=( const TemplateObjectWithAllOperatorsOverloaded& other ) const { return ( member_integer >= other.member_integer ); }
    Boolean operator<=( const TemplateObjectWithAllOperatorsOverloaded& other ) const { return ( member_integer <= other.member_integer ); }


private:


	// This object will store the integer this object manages
	IntegerType member_integer;


};  //  Class TemplateObjectWithAllOperatorsOverloaded