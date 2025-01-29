namespace Universe
{



// ************************************************************************************************************************************************************************** //
// **														   				   OPTIMIZED ARITHMETICS                                                                       ** //
// ************************************************************************************************************************************************************************** //



    // This macro should be used when performing the division opertaion, where the divisor is a power of 2
    //
    #define DivideByTwo( dividend ) ( dividend >> 1 )

    // This macro should be used when performing the division opertaion, where the divisor is a power of 2
    //
    #define MultiplyByTwo( dividend ) ( dividend << 1 )



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
	class Arithmetics NotForInheritance
	{
	public:


		// Create a type definition for this object
		using SelfType = Arithmetics;


		// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object.
		// Satic functions only have access to static data members, which also don't belong to any instance, this means all other data members
		// can not be used. The only purpose then of declaring a static function is when a private static data member needs to be manipulated,
		// or some functionality needed that does not involve the non static data members


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the sign of the given value
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          value - the value to extract the sign from
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      True if the value is positive, and false in case its negative
		//
		//  Expectations :
		//
		//		1. The template type should be numeric type
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< Concepts::Numeric NumericType >
		EnsureRetrunValueIsUsed static inline constexpr Boolean Sign( const NumericType value );


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the absolute value. The abosulte value, is the absolute 'distance' from zero, which means the sign does not matter
		//		and it will always be positive :
		//
		//			 8   ->   8
		//			-8   ->   8
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          value - the value to extract the absolute value from
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      The absolute value of the given value
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< Concepts::UnsignedNumeric UnsignedNumericType >
		EnsureRetrunValueIsUsed static inline constexpr UnsignedNumericType AbsoluteValue( const UnsignedNumericType value );


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the absolute value. The abosulte value, is the absolute 'distance' from zero, which means the sign does not matter
		//		and it will always be positive :
		//
		//			 8   ->   8
		//			-8   ->   8
		//
		//		The method only works with signed numeric types.
		//
		//		Note - in case the value is negative minimum value in integers, the absolute value can not be represented using the same signed integer size
		//		in bytes. This is because on the positive side, an extra value is added which is '0' while the negative side does not have this unique
		//		value, and therefore can store one more value. For example :
		//
		//			SignedInteger8bits - positive maximum value  ->   127
		//			SignedInteger8bits - negative minimum value  ->  -128
		//
		//		As can be seen there is no way to store the absolute value '128' with a signed integer of size 1 byte
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          value - the value to extract the absolute value from
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      The absolute value of the given value
		//
		//  Expectations :
		//
		//		1. The given value is not the negative minimum value, if the numeric type is signed integer
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< Concepts::SignedNumeric SignedNumericType >
		EnsureRetrunValueIsUsed static inline constexpr SignedNumericType AbsoluteValue( const SignedNumericType value );


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the absolute difference. The abosulte difference, is the absolute 'distance' from between the values, which 
		//		means the sign does not matter and it will always be positive :
		//
		//			 3 and 8   ->   5
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          1. firstValue - the first value to measure the difference between
		//			2. secondValue - the second value to measure the difference between
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      The absolute difference between the values
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< Concepts::UnsignedNumeric UnsignedNumericType >
		EnsureRetrunValueIsUsed inline constexpr UnsignedNumericType AbsoluteDifference( const UnsignedNumericType firstValue, const UnsignedNumericType secondValue );


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the absolute difference. The abosulte difference, is the absolute 'distance' from between the values, which 
		//		means the sign does not matter and it will always be positive :
		//
		//			 -3 and 8    ->   11
		//			 -3 and -8   ->   5
		//			 11 and 8    ->   3
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          1. firstValue - the first value to measure the difference between
		//			2. secondValue - the second value to measure the difference between
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      The absolute difference between the values
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< Concepts::SignedNumeric SignedNumericType >
		EnsureRetrunValueIsUsed inline constexpr SignedNumericType AbsoluteDifference( const SignedNumericType firstValue, const SignedNumericType secondValue );


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the absolute value in an unsigned integer type with the same size as the template type. The abosulte value, is the
		//		absolute 'distance' from zero, which means the sign does not matter and it will always be positive :
		//
		//			 8   ->   8
		//			-8   ->   8
		//
		//		The method only works with signed numeric types.
		//
		//		Note - in case the value is negative minimum value in integers, the absolute value can not be represented using the same signed integer size
		//		in bytes. This is because on the positive side, an extra value is added which is '0' while the negative side does not have this unique
		//		value, and therefore can store one more value. For example :
		//
		//			SignedInteger8bits - positive maximum value  ->   127
		//			SignedInteger8bits - negative minimum value  ->  -128
		//
		//		As can be seen there is no way to store the absolute value '128' with a signed integer of size 1 byte. This method purpose is to solve 
		//		this problem
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          value - the value to extract the absolute value from
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      The absolute value of the given value
		//
		//  Expectations :
		//
		//		1. The template type should be a signed integer type
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< Concepts::SignedInteger SignedIntegerType >
		EnsureRetrunValueIsUsed static inline constexpr typename ToUnsigned< SignedIntegerType >::Type AbsoluteValueReturnAsUnsignedIntegerWithTheSameSize( const SignedIntegerType value );


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to check if the given value divides by two with no remainder. Note - the value zero will return true
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			value - the value to check if divides by two with no remainder
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//		True if the value divides by two with no remainder, and false otherwise
		//
		//  Expectations :
		//
		//		1. The template type should be integer type
		//		2. 
		//
		//  Possible errors :
		//
		//      They will come
		//
		template< Concepts::Integer IntegerType >
		EnsureRetrunValueIsUsed static inline constexpr Boolean IsEven( const IntegerType value );


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to check if the given integer value is a power of 2. The sign of the value does not effect the result
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
		//      True if the given integer value is a power of 2, and false otherwise
		//
		//  Expectations :
		//
		//		1. The template type should be integer type
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< Concepts::Integer IntegerType >
		EnsureRetrunValueIsUsed static inline constexpr Boolean IsPowerOfTwo( const IntegerType value );


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to multiply, the power will determine the value of times, by itself
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. base - the value that will be multiplied by itself
		//			2. exponent - this will determine the value of times the base will be multiplied by itself
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		The base multiplied by itself the value of times the exponent determines
		//
		//  Expectations :
		//
		//		1. The result should be in the range of the template numeric type, or an overflow will occuer
		//		2. The template type should be numeric type
		//		3. In case the template type is an integer, the power should not be a negative value, because integer can not store fractions
		//		4. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< Concepts::Numeric NumericType >
		EnsureRetrunValueIsUsed static inline constexpr NumericType Power( const NumericType base, const NumericType exponent );


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to find the next value that divides with no remainder by the divisor. Note - in case the starting value is
		//		positive, the next value will be a larger positive value, but in case it is a negative value, then the next value will be
		//		a lower negative value, for example :
		//
		//			Starting value 		Divisor 		Next value that divides with no remainder
		//
		//				 11					   8 								16
		//				-11 				   8 								-8
		//
		//		The sign of the divisor as no effect on the result, only the absolute value of it!
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          1. startingvalue - the value that the search will begin from
		//			2. divisor - this is the value that the next value needs to divide by with no remainder
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      The next value that divides with no remainder by the divisor
		//
		//  Expectations :
		//
		//		1. The template type should be integer type
		//		2. The divisor must not be 0
		//		3. 
		//
		//  Possible errors :
		//
		//      They will come
		//
		template< Concepts::Integer IntegerType >
		EnsureRetrunValueIsUsed static inline constexpr IntegerType GetNextValueThatDividesWithNoRemainder( const IntegerType startingvalue, const IntegerType divisor );


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to find the previous value that divides with no remainder by the divisor. Note - in case the starting value is
		//		positive, the next value will be a smaller positive value, but in case it is a negative value, then the previous value will be
		//		a higher negative value, for example :
		//
		//			Starting value 		Divisor 		previous value that divides with no remainder
		//
		//				 11					   8 								 8
		//				-11 				   8 								-16
		//
		//		The sign of the divisor as no effect on the result, only the absolute value of it!
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          1. startingvalue - the value that the search will begin from
		//			2. divisor - this is the value that the previous value needs to divide by with no remainder
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      The previous value that divides with no remainder by the divisor
		//
		//  Expectations :
		//
		//		1. The template type should be integer type
		//		2. The divisor must not be 0
		//		3. 
		//
		//  Possible errors :
		//
		//      They will come
		//
		template< Concepts::Integer IntegerType >
		EnsureRetrunValueIsUsed static inline constexpr IntegerType GetPreviousValueThatDividesWithNoRemainder( const IntegerType startingvalue, const IntegerType divisor );


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
		NoInstances( Arithmetics );


	};  //  Class Arithmetics