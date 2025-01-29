namespace Universe
{


namespace Random
{


namespace RunTimeGenerator
{



// A non type template argument provided within a template argument list is an expression whose value can be determined at compile time. Such
// arguments must be constant expressions, addresses of functions or objects with external linkage or addresses of static class members. String
// literals are objects with internal linkage and can not be used, as well as global pointers and floating points literals due to the posibility
// of rounding off errors. 
//
// Non constant expressions can't be parsed and substituted during compile time. They could change during run time which would required the
// generation of a new template during run time, which isn't possible because templates are a compile time concept. Here is what the standard
// allows for non type template parameters :
//
//	1. Integral or enumeration type
//	2. Pointer to object or pointer to function
//	3. lvalue reference to object or lvalue reference to function
//	4. pointer to member
//	5. std::nullptr_t



// Modulo :
//
//		positive % positive = positive
//
//		positive % negative = positive
//
//		negative % positive = negative
//
//		negative % negative = negative
//
// Totally fucked up!!!



// All static initializers should be designed to avoid triggering static initialization order fiasco ( SIOF ). Static initializers in the
// same translation unit are executed in the order of their declaration in the file. However, initialization order across multiple
// translation units is not defined. A static initialization order fiasco arises when a static initializer depends on another, which
// is in another translation unit.
//
// Then depending on the phase of the Moon, either both objects will initialize in the right order and everything will work, or they
// will initialize in the opposite order, which will cause the use of non yet constructed instance, which will cause undefined behavior!



// Class Information :
//
//  Purpose :
//
//		Use this object to generate a random instance. There are 2 possibilites, the first is that the required type for the random generator
//		is integer, which means a number needs to be randomed. The second is for actual objects, that to create a random instance, the constructor
//		the generate a random instance needs to be called. The point of this object is to make the choice between the two invisible to the user
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
class Numeric
{
public:


	// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions
	// only have access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only
	// purpose then of declaring a static function is when a private static data member needs to be manipulated, or some functionality needed that
	// does not involve the non static data members


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to generate a random number within the given range
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			range - this will be used to set the limits for the possible random values
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		A random generated integer number between the minimum and maximum of the range
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< Concepts::Integer IntegerType >
	EnsureRetrunValueIsUsed static inline IntegerType Next( const Range< IntegerType >& range = Range< IntegerType >() );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to generate a random floating point number in the given range
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			range - this will be used to set the limits for the possible random values
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		A random generated floating point number between the minimum and maximum of the range
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< Concepts::FloatingPoint FloatingPointType >
	static inline FloatingPointType Next( const Range< FloatingPointType >& range = Range< FloatingPointType >() );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to generate a random floating point number in the given range
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			range - this will be used to set the limits for the possible random values, but since there is only 2 options there is no point of using it
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		A random generated boolean number
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	static inline Boolean Next( const Range< Boolean >& = Range< Boolean >() );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method fill the given object with random values
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. objectTypeGenerateRandomInstanceArguments - any argument needed to generate a random instance of the template object type
	//			2. rangeForValues - the possible values for the random generate values
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
	template< Concepts::Numeric NumericType, typename ObjectThatImplementSquareBracketsOperatorAndSizeMethodType >
	static inline void SetMultipleNext( ObjectThatImplementSquareBracketsOperatorAndSizeMethodType& objectThatImplementSquareBracketsOperatorAndSizeMethodInstance, const Range< NumericType >& rangeForValues = Range< NumericType >() );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method fill the given contiguous memory with random values
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			1. pointerToArray - a pointer to a memory address that contains multiple elements of the numeric type
	//			2. size - the number of elements in the array
	//			3. rangeForValues - the possible values for the random generate values
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
	template< Concepts::Numeric NumericType >
	static inline void SetMultipleNextRawPointer( NumericType* const pointerToArray, const LargestUnsignedInteger size, const Range< NumericType >& rangeForValues = Range< NumericType >() );


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
	NoInstances( Numeric );


};  //  Class Numeric
