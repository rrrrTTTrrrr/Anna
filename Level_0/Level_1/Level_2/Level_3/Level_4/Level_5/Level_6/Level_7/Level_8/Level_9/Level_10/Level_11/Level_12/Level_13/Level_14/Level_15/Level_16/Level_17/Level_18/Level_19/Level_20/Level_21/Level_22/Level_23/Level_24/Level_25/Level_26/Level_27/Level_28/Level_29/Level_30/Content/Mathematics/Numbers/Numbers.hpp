#ifndef NUMBERS_HPP
#define NUMBERS_HPP


#include "../../../../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../../../../../../Content/Metaprogramming/MetaprogrammingMacros/MetaprogrammingMacros.hpp"  //  Macro MOVE
#include "../../../../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../../../../../../../Content/BuiltInTypesWrapper/InitializeConstantArrayUsingMethod/InitializeConstantArrayUsingMethod.hpp"  //  Class InitializeConstantArrayUsingMethod
#include "../../../../../../Content/Memory/SequentialPlatforms/DynamicArray/DynamicArray.hpp"  //  Class DynamicArray


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe
{

    namespace Mathematics
    {



		// Prime number :
		//
		// A prime number is a natural number greater than 1 that cannot be formed by multiplying two smaller natural numbers. A natural number greate than 1
		// that is not prime is called a composite number. Primes are central in number theory because of the fundamental theorem of arithemtic - every natural
		// number greater than 1 is either a prime itself or can be factorized as a product of primes that is unique up to their order.
		//
		// There are infinitely many primes, as there are infinitely many numbers. No known simple formula separates prime numbers from composite numbers. 
		// However the distribution of primes within the natural numbers in the large can be statistically modelled. The first result in that direction
		// is the prime number theorem, which says that the probability of a randomly chosen number being prime is inversely proportional to its number
		// of digits, that is, to its logarithm



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
		class Numbers
		{
		public:


			// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions
			// only have access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only
			// purpose then of declaring a static function is when a private static data member needs to be manipulated, or some functionality needed that
			// does not involve the non static data members


			// // Method Information :
			// //
			// //  Description :
			// //
			// //		Use this method to get the prime number represented by the index. For example :
			// //
			// //			index = 0  means the first prime number which is 2
			// //			index = 1  means the first prime number which is 3
			// //			index = 2  means the first prime number which is 5
			// //			.
			// //			.
			// //			.
			// //
			// //  Required arguments :
			// //
			// //		User information needed :
			// //
			// //			index - the index of the required prime number
			// //
			// //		Information returned to the user :
			// //
			// //			NONE
			// //
			// //  Return value :
			// //
			// //		The prime number represented by the index
			// //
			// //  Expectations :
			// //
			// //		NONE
			// //
			// //  Possible errors :
			// //
			// //		They will come
			// //
			// static UnsignedInteger64bits Get( UnsignedInteger64bits primeNumberIndex );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to check if the given number is prime
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			number - the number that needs to be checked for primality
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		A boolean with the value true if the number is prime, and false otherwise
			//
			//  Expectations :
			//
			//		1. The given number should not be 0
			//		2.
			//
			//  Possible errors :
			//
			//		They will come
			//
			static Boolean PrimalityTest( UnsignedInteger64bits number );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to get the largest divisor of the dividend, that gives a quotient which is a natural number, that the remainder of the 
			//		division is zero
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			number - the number that the largest divisor needs to be calculated for
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		The largest divisor of the dividend, that gives a quotient which is a natural number, that the remainder of the division is zero
			//
			//  Expectations :
			//
			//		1. The given number should not be 0
			//		2. The given number is not a prime number
			//		3. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			static UnsignedInteger64bits LargestDivisorThatTheQuotientHasNoRemainder( UnsignedInteger64bits number );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to get the smallest divisor of the dividend, that gives a quotient which is a natural number, that the remainder of the 
			//		division is zero
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			number - the number that the smallest divisor needs to be calculated for
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		The smallest divisor of the dividend, that gives a quotient which is a natural number, that the remainder of the division is zero
			//
			//  Expectations :
			//
			//		1. The given number should not be 0
			//		2. The given number is not a prime number
			//		3. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			static UnsignedInteger64bits SmallestDivisorThatTheQuotientHasNoRemainder( UnsignedInteger64bits number );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to get all the divisors of the dividend, that gives a quotient which is a natural number, that the remainder of the 
			//		division is zero
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			number - the number that the divisors needs to be calculated for
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		All divisors of the dividend, that gives a quotient which is a natural number, that the remainder of the division is zero
			//
			//  Expectations :
			//
			//		1. The given number should not be 0
			//		2. The given number is not a prime number
			//		3. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			static Memory::DynamicArray< UnsignedInteger64bits > AllDivisorsThatTheQuotientHasNoRemainder( UnsignedInteger64bits number );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to check if the given numbers have at least one common divisor
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. number1 - the first number to check for common divisor
			//			2. number2 - the second number to check for common divisor
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		A boolean with the value true if both numbers have a common divisor
			//
			//  Expectations :
			//
			//		1. The first number should not be 0
			//		2. The second number should not be 0
			//		3. The given first number is not a prime number
			//		4. The given second number is not a prime number
			//		5. The given numbers should be different
			//		6. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			static Boolean CommonDivisorTest( UnsignedInteger64bits number1, UnsignedInteger64bits number2 );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to get all the common divisors, if exist, of the two numbers
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. number1 - the first number for the common divisors
			//			2. number2 - the second number for the common divisors
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		An array with all the common divisors if exist
			//
			//  Expectations :
			//
			//		1. The first number should not be 0
			//		2. The second number should not be 0
			//		3. The given first number is not a prime number
			//		4. The given second number is not a prime number
			//		5. The given numbers should be different
			//		6. The given numbers has at least one common divisor
			//		7. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			static Memory::DynamicArray< UnsignedInteger64bits > CommonDivisors( UnsignedInteger64bits number1, UnsignedInteger64bits number2 );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to get the largest common divisor for the given two numbers
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. number1 - the first number to check for the largest common divisor
			//			2. number2 - the second number to check for the largest common divisor
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		The largest common divisor of both numbers
			//
			//  Expectations :
			//
			//		1. The first number should not be 0
			//		2. The second number should not be 0
			//		3. The given first number is not a prime number
			//		4. The given second number is not a prime number
			//		5. The given numbers should be different
			//		6. The given numbers has at least one common divisor
			//		7. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			static UnsignedInteger64bits LargestCommonDivisor( UnsignedInteger64bits number1, UnsignedInteger64bits number2 );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to get the smallest common divisor for the given two numbers
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. number1 - the first number to check for the smallest common divisor
			//			2. number2 - the second number to check for the smallest common divisor
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		The smallest common divisor of both numbers
			//
			//  Expectations :
			//
			//		1. The first number should not be 0
			//		2. The second number should not be 0
			//		3. The given first number is not a prime number
			//		4. The given second number is not a prime number
			//		5. The given numbers should be different
			//		6. The given numbers has at least one common divisor
			//		7. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			static UnsignedInteger64bits SmallestCommonDivisor( UnsignedInteger64bits number1, UnsignedInteger64bits number2 );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to get the smallest number that when dividing each of the given numbers there will be no remainder 
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. number1 - the first number
			//			2. number2 - the second number
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		The smallest number that when dividing each of the given numbers there will be no remainder
			//
			//  Expectations :
			//
			//		1. The first number should not be 0
			//		2. The second number should not be 0
			//		3. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			static UnsignedInteger64bits SmallestCommonMultiple( UnsignedInteger64bits number1, UnsignedInteger64bits number2 );


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
				static void Test() __attribute__ (( __unused__ ));

			)  //  End of debug tool


		private:


			// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
			NoInstances( Numbers )


			// Static data members do not belong to any instance, they belong to the object. Like every global variable it is created with the start of the program
			// and only destroyed when the program ends. The access to the static member is bound to this object of course


			// // This object will store the prime numbers look up table
			// static constexpr UnsignedInteger64bits member_primeNumbersLookupTableSize = 65536UL;


			// // This array will act as a look up table, to store the prime numbers already calculated, to ensure that for each prime number the calculation to find
			// // it will only be done once
			// static const InitializeConstantArrayUsingMethod< UnsignedInteger64bits, member_primeNumbersLookupTableSize > member_primeNumbersLookupTable;


			// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
			// rather help implement it :


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to calculate the next prime number after the one provided
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			Numbers - the prime number from which the start for the next prime number should start 
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		The next prime number after the one provided
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			static UnsignedInteger64bits CalculateNextPrimeNumber__Private( UnsignedInteger64bits Numbers );


		};  //  Class Numbers




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************








































































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************














































	}  //  Namespace Mathematics

}  //  Namespace Universe


#endif  // NUMBERS_HPP