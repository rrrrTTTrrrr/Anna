namespace Universe
{


namespace Test
{



// Class Information :
//
//  Purpose :
//
//		Artifical Inteligence
//
//  Description :
//
//		1. This object is used only to wrap some static methods, which can be used without any instance of the object. Then this object is
//		   an interface which conatins only static methods, and does not need to never be instantied
//
//		2. This object has all the methods to create, destory, copy and move disabled to ensure that no instances of it will be created
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
class Functions
{
public:


    // Create a type definition for this object
    using SelfType = Functions;


	// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions
	// only have access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only
	// purpose then of declaring a static function is when a private static data member needs to be manipulated, or some functionality needed that
	// does not involve the non static data members


	static inline UnsignedInteger32bits Function_1( UnsignedInteger32bits, UnsignedInteger64bits );

	static inline UnsignedInteger32bits Function_2( UnsignedInteger32bits, UnsignedInteger64bits, UnsignedInteger64bits );

	static inline void Function_3();

	static inline UnsignedInteger32bits Function_4();

    static inline void Function_5( UnsignedInteger32bits, UnsignedInteger64bits );

    static inline void Function_6( UnsignedInteger32bits*, UnsignedInteger64bits* );

    static inline void Function_7( UnsignedInteger64bits* array, UnsignedInteger64bits arraySize );


private:


	// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
	NoInstances( Functions );


};  //  Class Functions	