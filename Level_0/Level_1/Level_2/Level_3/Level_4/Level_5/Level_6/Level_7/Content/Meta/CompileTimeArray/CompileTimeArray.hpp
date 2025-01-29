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
//		2. Template arguments :
//
//			1.
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< Concepts::Numeric NumericType, NumericType... Values > requires ( sizeof...( Values ) > 0 )
class CompileTimeArray NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = CompileTimeArray< NumericType, Values... >;


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
	constexpr inline CompileTimeArray();


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
	inline ~CompileTimeArray() = default;


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the size of the array, or in other words the number of values in the template pack. This is a constant expression
	//		method, which means that the value can be calculated durign compile time and used as literal to prevent any run time calculations and use
	//		of memory. The index is passed as a template argument
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
	EnsureRetrunValueIsUsed constexpr LargestUnsignedInteger Size() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the value in a specific entry. This is a constant expression method, which means that the value can be
	//		calculated durign compile time and used as literal to prevent any run time calculations and use of memory. The index is passed
	//		as a template argument
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
	template< LargestUnsignedInteger Index > requires ( Index < sizeof...( Values ) )
	EnsureRetrunValueIsUsed constexpr NumericType Entry() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method check if the array conatins a certain value. This is a constant expression method, which means that the value can be
	//		calculated durign compile time and used as literal to prevent any run time calculations and use of memory. The value is passed
	//		as a template argument
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
	template< NumericType Value >
	EnsureRetrunValueIsUsed constexpr Boolean DoesValueExist() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method get the maximum value in the array. This is a constant expression method, which means that the value can be
	//		calculated durign compile time and used as literal to prevent any run time calculations and use of memory
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
	EnsureRetrunValueIsUsed constexpr NumericType Maximum() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method get the minimum value in the array. This is a constant expression method, which means that the value can be
	//		calculated durign compile time and used as literal to prevent any run time calculations and use of memory
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
	EnsureRetrunValueIsUsed constexpr NumericType Minimum() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method get the sum of all the value in the array. This is a constant expression method, which means that the value can be
	//		calculated durign compile time and used as literal to prevent any run time calculations and use of memory
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
	EnsureRetrunValueIsUsed constexpr NumericType Sum() const;


	// The following methods declare the overloaded operators for the object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to check if the this instance match the other. This overload will always return true, as it accept only instances
	//		of this object, which means that the values are the same. This is a constant expression method, which means that the value can be
	//		calculated durign compile time and used as literal to prevent any run time calculations and use of memory
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a reference to the instance that should be compared with this object
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		Always true
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed constexpr Boolean operator==( const SelfType& other ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to check if the this instance match the other. This overload will always return false, as it accept only instances
	//		of other objects, which means that the values are different. This is a constant expression method, which means that the value can be
	//		calculated durign compile time and used as literal to prevent any run time calculations and use of memory
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a reference to the instance that should be compared with this object
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		Always false
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename OtherCompileTimeArrayType > requires ( CompareRegardlessOfTemplateArguments< OtherCompileTimeArrayType, CompileTimeArray< NumericType, Values... > >::Result )
	EnsureRetrunValueIsUsed constexpr Boolean operator==( const OtherCompileTimeArrayType& other ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to check if the this instance match the other. This overload will always return false, as it accept only instances
	//		of this object, which means that the values are the same. This is a constant expression method, which means that the value can be
	//		calculated durign compile time and used as literal to prevent any run time calculations and use of memory
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a reference to the instance that should be compared with this object
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		Always false
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed constexpr Boolean operator!=( const SelfType& other ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to check if the this instance match the other. This overload will always return true, as it accept only instances
	//		of other objects, which means that the values are different. This is a constant expression method, which means that the value can be
	//		calculated durign compile time and used as literal to prevent any run time calculations and use of memory
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a reference to the instance that should be compared with this object
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		Always true
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename OtherCompileTimeArrayType > requires ( CompareRegardlessOfTemplateArguments< OtherCompileTimeArrayType, CompileTimeArray< NumericType, Values... > >::Result )
	EnsureRetrunValueIsUsed constexpr Boolean operator!=( const OtherCompileTimeArrayType& other ) const;


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


	// Disable all copy and move related methods, this include the copy constructor, move constructor, assignment operator and move assignment operator
	DisableCopyAndMove( CompileTimeArray );


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of
	// the interface, but rather help implement it :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the value in a specific entry. This overload will recursively pill the template pack type by type, each 
	//		time decrementing the index by until 0, which than the other overload will be used as the base case to end the compile time
	//		recursion and return the required value. This is a constant expression method, which means that the value can be calculated 
	//		durign compile time and used as literal to prevent any run time calculations and use of memory 
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
	//		The value in a specific entry
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< LargestUnsignedInteger Index, NumericType ExposedValue, NumericType... RestOfValues > requires ( ( Index < sizeof...( Values ) ) && ( Index > 0 ) )
	EnsureRetrunValueIsUsed constexpr NumericType Entry__Private() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the value in a specific entry. This overload is the base case to end the recursion, when the index reaches 0,
	//		And return the value. This is a constant expression method, which means that the value can be calculated durign compile time and used 
	//		as literal to prevent any run time calculations and use of memory 
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
	//		The value in a specific entry
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< LargestUnsignedInteger Index, NumericType ExposedValue, NumericType... RestOfValues > requires ( Index == 0 )
	EnsureRetrunValueIsUsed constexpr NumericType Entry__Private() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to check if a certain value exists. This overload will check if the exposed value match, and if not will perform
	//		a compile time recursive call on all the values, until the base case to stop the compile time recursion is reached, which is only
	//		one last value. This is a constant expression method, which means that the value can be calculated durign compile time and used 
	//		as literal to prevent any run time calculations and use of memory 
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
	//		True if the value exist in the array, and false otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< NumericType Value, NumericType ExposedValue, NumericType NextExposedValue, NumericType... RestOfValues >
	EnsureRetrunValueIsUsed constexpr Boolean DoesValueExist__Private() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to check if a certain value exists. This overload is the base case to the stop the compile time recursion. It will
	//		check if the last exposed value matches and return the result. This is a constant expression method, which means that the value can 
	//		be calculated durign compile time and used as literal to prevent any run time calculations and use of memory 
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
	//		True if the value exist in the array, and false otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< NumericType Value, NumericType ExposedValue >
	EnsureRetrunValueIsUsed constexpr Boolean DoesValueExist__Private() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the maximum value in the array. This overload will check which one of the first or second exposed values 
	//		is larger, and will use it to perform a compile time recursive call with the next value in the template pack. Finally, the recursion
	//		will be stopped when there are only 2 last values to compare, and in that case the other overload will be called. This is a constant
	//		expression method, which means that the value can be calculated durign compile time and used as literal to prevent any run time 
	//		calculations and use of memory 
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
	//		The maximum value in the array
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< NumericType FirstExposedValue, NumericType SecondExposedValue, NumericType NextExposedValue, NumericType... RestOfValues >
	EnsureRetrunValueIsUsed constexpr NumericType Maximum__Private() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the maximum value in the array. This overload is the base case to stop the compile time recursion. It will
	//		be used when only 2 last values to compare are left, and it will return the larger one. This is a constant expression method, which
	//		means that the value can be calculated durign compile time and used as literal to prevent any run time calculations and use of memory
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
	//		The maximum value in the array
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< NumericType FirstExposedValue, NumericType SecondExposedValue >
	EnsureRetrunValueIsUsed constexpr NumericType Maximum__Private() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the minimum value in the array. This overload will check which one of the first or second exposed values 
	//		is smaller, and will use it to perform a compile time recursive call with the next value in the template pack. Finally, the recursion
	//		will be stopped when there are only 2 last values to compare, and in that case the other overload will be called. This is a constant
	//		expression method, which means that the value can be calculated durign compile time and used as literal to prevent any run time 
	//		calculations and use of memory 
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
	//		The minimum value in the array
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< NumericType FirstExposedValue, NumericType SecondExposedValue, NumericType NextExposedValue, NumericType... RestOfValues >
	EnsureRetrunValueIsUsed constexpr NumericType Minimum__Private() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the minimum value in the array. This overload is the base case to stop the compile time recursion. It will
	//		be used when only 2 last values to compare are left, and it will return the smaller one. This is a constant expression method, which
	//		means that the value can be calculated durign compile time and used as literal to prevent any run time calculations and use of memory
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
	//		The minimum value in the array
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< NumericType FirstExposedValue, NumericType SecondExposedValue >
	EnsureRetrunValueIsUsed constexpr NumericType Minimum__Private() const;


};  //  Class CompileTimeArray