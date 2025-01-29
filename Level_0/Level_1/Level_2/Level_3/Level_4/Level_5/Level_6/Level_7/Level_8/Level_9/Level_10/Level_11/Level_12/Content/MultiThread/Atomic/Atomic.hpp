namespace Universe
{


namespace MultiThread
{



// Class Information :
//
//  Purpose :
//
//		The purpose is to create a coherent variable across system memory and caches of all the central processing units sharing them
//
//  Description :
//
// 		1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
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
template< Concepts::BuiltIn BuiltInType >
class Atomic NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = Atomic< BuiltInType >;


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
	inline Atomic();


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
	//			value - this value will be used to initialize the variable
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
	explicit inline Atomic( const BuiltInType value );


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
	//		    other - a reference to the instance that should be copied
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
	inline Atomic( const SelfType& other );


	// Add the following infrastructure to the object :
	//
	//		1. Assigenment operator
	//		2. Move constructor
	//		3. Move assigenment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure( Atomic )


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
	inline ~Atomic() = default;


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the value of the variable. The value will be read from system memory, passing the cache, to ensure
	//		that the value giving is the most updated
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
	//		The value of the variable
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline BuiltInType Load() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to set the value of the variable. The value will be written to system memory, and all other central processing
	//		units caches will be invalidated to ensure, that all have a coherent veiw of the variable's value
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			newValue - the new value of the variable
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
	inline void SetValue( const BuiltInType newValue );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to increment the variable by the required amount, while ensuring that all the relevent central processing
	//		units using the same system memory have a coherent view of it
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    valueToAdd - this value will be added to the current value of the variable
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The old value of the variable before the addition
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline BuiltInType AddAndReturnOldValue( const BuiltInType valueToAdd );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to decrement the variable by the required amount, while ensuring that all the relevent central processing
	//		units using the same system memory have a coherent view of it
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    valueToSubtract - this value will be subtracted from the current value of the variable
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The old value of the variable before the subtraction
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline BuiltInType SubtractAndReturnOldValue( const BuiltInType valueToSubtract );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to compare the value stored in this instance with the other value. In case the comparison is true, the required
	//		new value will be stored in this instance instead
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	// 			1. expectedValue - the current value inside this instance will be compared with this value
	//			2. desiredValue - this value will be stored inside this instance instead of the current one if the comparison is true 
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A boolean with the value true in case the comparison result was true, and false otherwise. Also if the actual and expected value
	//		mismatch the actual value will be stored in the expected value instead 
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Boolean CompareTheActualValueWithTheExpectedAndIfEqualSetTheDesiredValue( BuiltInType& expectedValue, const BuiltInType desiredValue );


	// The following methods declare the overloaded operators for the object :


	// Method Information :
	//
	//  Description :
	//
	//		This operator will be used to allow implicit conversion to the value stroed in this instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    NONE
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		The value stroed in this instance
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline operator BuiltInType() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to increment the variable by the required amount, while ensuring that all the relevent central processing
	//		units using the same system memory have a coherent view of it
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    value - the value to set
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A reference to this instance
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline SelfType& operator=( const BuiltInType value );


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to increment the variable by the required amount, while ensuring that all the relevent central processing
	//		units using the same system memory have a coherent view of it
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    valueToAdd - this value will be added to the current value of the variable
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A reference to this instance
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline SelfType& operator+=( const BuiltInType valueToAdd );


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to decrement the variable by the required amount, while ensuring that all the relevent central processing
	//		units using the same system memory have a coherent view of it
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    valueToSubtract - this value will be subtracted from the current value of the variable
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A reference to this instance
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline SelfType& operator-=( const BuiltInType valueToSubtract );


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
		static inline void UnitTest() __attribute__ (( __unused__ ));

	)  //  End of debug tool


private:


	// This object will store the variable. All the central processing units using the same system memory that the variable will be stored
	// in, will always have a choerent view of the variable. The caches are updated as well
	BuiltInType member_variable;


};  //  Class Atomic