namespace Universe
{



// Both "class" and "typename" within C++ indicate a type parameter since the keywords do not hold any platform significance – for example, class is 
// not meant to suggest a native type nor is typename meant to suggest a CLI type. Rather, both equivalently indicate that the name following represents
// a parameterized type placeholder that will be replaced by a user-specfied actual type. The reason for the two keywords is historical. In the original 
// template specification, Stroustrup reused the existing class keyword to specify a type parameter rather than introduce a new keyword that might of 
// course break existing programs. It wasn’t that a new keyword wasn’t considered — just that it wasn’t considered necessary given its potential 
// disruption. And up until the ISO-C++ standard, this was the only way to declare a type parameter. Reuses of existing keywords seems to always sow 
// confusion. What we found is that beginners were whether the use of the class constrained or limited the type arguments a user could specify to be class 
// types rather than, say, a built-in or pointer type. So, there was some feeling that not having introduced a new keyword was a mistake. During 
// standardization, certain constructs were discovered within a template definition that resolved to expressions although they were meant to indicate 
// declarations. For example,
//
//	template <class T>
//
//	class Demonstration {
//
//	public:
//
//	void method() {
//
//	    T::A *aObj; // oops …
//
//	     // …
//
//	};
//
// While the statement containing aObj is intended by the programmer to be interpreted as the declaration of a pointer to a nested type A within 
// the type parameter T, the language grammar interprets it as an arithmetic expression multiplying the static member A of type T with aObj and 
// throwing away the result. Isn’t that annoying! ( This sort of dilemna is not possible within generics – there is no way to safely verify that 
// any T contains an A so that the runtime can safely construct an instance of the generic type ). The committee decided that a new keyword was 
// just the ticket to get the compiler off its unfortunate obsession with expressions. The new keyword was the self-describing typename. When applied 
// to a statement, such as :
//
//	typename T::A* a6; // declare pointer to T’s A
//
// it instructs the compiler to treat the subsequent statement as a declaration. Since the keyword was on the payroll, heck, why not fix the confusion 
// caused by the original decision to reuse the class keyword. Of course, given the extensive body of existing code and books and articles and talks and 
// postings using the class keyword, they chose to also retain support for that use of the keyword as well. So that’s why you have both.



// The main point of a class is to manage resources ( In theory every class should maintain one and only one resource ), one of the important aspects of 
// managing a resource is performance, the amount of time every operation take should be as minimal as possible, the basic operations should take almost 
// the same as when working with the resource without the class covering it



// Size of reference types :
//
// From the standard - when the 'sizeof' operator is applied to a reference or a reference type, the result is the size of the referenced type!
//
// For example :
//
//		sizeof( double& ) == sizeof( double )
//		sizeof( int&& ) == sizeof( int )
//
// Reference is not a pointer. It is an alias of an object. Sometimes, the compiler chooses to implement this by using a pointer. But often,
// it implements it by doing nothing at all. By simply generate code which referes directly to the original object.



// Class Information :
//
//  Purpose :
//
//		The purpose of this object is to stroe static methods that will be able to choose the correct process to perform the action according
//		to the type provided. For example, to reset an instance, it is different if the instance is of built in type type, because it does not
//		contain the reset method, which does exist for objects. Therefore, if the type is built in it should just be set to 0, and if not
//		the reset method of the object should be used
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
class ActAccordingToType
{
public:


	// Create a type definition for this object
	using SelfType = ActAccordingToType;


	// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions
	// only have access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only
	// purpose then of declaring a static function is when a private static data member needs to be manipulated, or some functionality needed that
	// does not involve the non static data members


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to reset the given instance according to its type. This implementation of the method will be for built in type types. It will
	//		set the reference to 0
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			instance - a reference to the instance to reset
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
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
	template< Concepts::BuiltIn Type >
	static inline void Reset( Type& instance );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to reset the given instance according to its type. This implementation of the method will be for non built in type types. This
	//		means that this object has a reset method, which will be called
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			instance - a reference to the instance to reset
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
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
	template< Concepts::NotBuiltIn Type >
	static inline void Reset( Type& instance );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to reset the given instance according to its type. This implementation of the method will be for built in type types. It will
	//		return the value 0
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
	//		The value 0
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
	template< Concepts::BuiltIn Type >
	EnsureRetrunValueIsUsed static inline Type GetDefaultInstance();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to reset the given instance according to its type. This implementation of the method will be for non built in type types. It
	//		will return an instance created using the default constructor
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
	//		A default constructed instance
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
	template< Concepts::NotBuiltIn Type >
	EnsureRetrunValueIsUsed static inline Type GetDefaultInstance();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to compare two instances of the object type given as template argument. This method will be used with objects that 
	//		has implemented the equal or smaller comparison operator '<='
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. first - a constant reference to the instance. This is the instance that will be checked if it is equal or smaller then the second
	//			1. second - a constant reference to the instance. This is the instance that will be checked if it is equal or larger then the first
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		True if the first instance is equal or smaller then the second instance, and false otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< Concepts::ObjectWithIsSmallerOperator ObjectWithIsSmallerOperatorType >
	EnsureRetrunValueIsUsed inline Boolean IsFirstInstanceEqualOrSmallerThenTheSecond( const ObjectWithIsSmallerOperatorType& first, const ObjectWithIsSmallerOperatorType& second );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to compare two instances of the object type given as template argument. This method will be used with objects that 
	//		has implemented the equal or larger comparison operator '>='
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. first - a constant reference to the instance. This is the instance that will be checked if it is equal or smaller then the second
	//			1. second - a constant reference to the instance. This is the instance that will be checked if it is equal or larger then the first
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		True if the first instance is equal or smaller then the second instance, and false otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< Concepts::ObjectWithIsLargerOperatorAndIsSmallerOpeatorDoesNotExist ObjectWithIsLargerOperatorAndIsSmallerOpeatorDoesNotExistType >
	EnsureRetrunValueIsUsed inline Boolean IsFirstInstanceEqualOrSmallerThenTheSecond( const ObjectWithIsLargerOperatorAndIsSmallerOpeatorDoesNotExistType& first, const ObjectWithIsLargerOperatorAndIsSmallerOpeatorDoesNotExistType& second );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to compare two instances of the object type given as template argument. This method will be used with objects that 
	//		has implemented the smaller comparison operator '<'
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. first - a constant reference to the instance. This is the instance that will be checked if it is smaller then the second
	//			1. second - a constant reference to the instance. This is the instance that will be checked if it is larger then the first
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		True if the first instance is smaller then the second instance, and false otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< Concepts::ObjectWithIsSmallerOperator ObjectWithIsSmallerOperatorType >
	EnsureRetrunValueIsUsed static inline Boolean IsFirstInstanceSmallerThenTheSecond( const ObjectWithIsSmallerOperatorType& first, const ObjectWithIsSmallerOperatorType& second );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to compare two instances of the object type given as template argument. This method will be used with objects that 
	//		has implemented the larger comparison operator '>'
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. first - a constant reference to the instance. This is the instance that will be checked if it is smaller then the second
	//			1. second - a constant reference to the instance. This is the instance that will be checked if it is larger then the first
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		True if the first instance is smaller then the second instance, and false otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< Concepts::ObjectWithIsLargerOperatorAndIsSmallerOpeatorDoesNotExist ObjectWithIsLargerOperatorAndIsSmallerOpeatorDoesNotExistType >
	EnsureRetrunValueIsUsed static inline Boolean IsFirstInstanceSmallerThenTheSecond( const ObjectWithIsLargerOperatorAndIsSmallerOpeatorDoesNotExistType& first, const ObjectWithIsLargerOperatorAndIsSmallerOpeatorDoesNotExistType& second );


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
	NoInstances( ActAccordingToType );


};  //  Class ActAccordingToType