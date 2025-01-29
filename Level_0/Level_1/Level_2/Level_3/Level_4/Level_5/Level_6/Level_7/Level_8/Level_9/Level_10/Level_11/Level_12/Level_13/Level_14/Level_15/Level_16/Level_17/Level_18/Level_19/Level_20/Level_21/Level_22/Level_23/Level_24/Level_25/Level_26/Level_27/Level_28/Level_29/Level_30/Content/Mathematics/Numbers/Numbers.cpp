#ifndef  NUMBERS_CPP
#define  NUMBERS_CPP


#include "Numbers.hpp"


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe 
{

    namespace Mathematics
    {



		// // Initialize the static look up table for the prime numbers. It will be initialize over a size of 1MegaByte which means that it could store up
		// // to 65536 first prime numbers
		// const InitializeConstantArrayUsingMethod< UnsignedInteger64bits, Numbers::member_primeNumbersLookupTableSize > Numbers::member_primeNumbersLookupTable( []( UnsignedInteger64bits* primeNumbersLookupTable, UnsignedInteger64bits lookupTableSize ) -> void
		// {
		// 	// Set the first prime number which is 2
		// 	primeNumbersLookupTable[0] = 2UL;

		// 	// Set the second prime number which is 3
		// 	primeNumbersLookupTable[1] = 3UL;

		// 	// Loop on all the entries of the look up table and set them with the required prime numbers
		// 	for ( UnsignedInteger64bits lookupTableIndex = 2UL ; lookupTableIndex < lookupTableSize ; ++lookupTableIndex )
		// 	{
		// 		// Provide the previous prime number to the method, which will calculate the next prime number, and store it into the required entry
		// 		primeNumbersLookupTable[ lookupTableIndex ] = CalculateNextPrimeNumber__Private( primeNumbersLookupTable[ lookupTableIndex - 1UL ] );
		// 	}

		// } );

























//  ********************************************************************   STATIC FUNCTIONS IMPLEMENTATION   ********************************************************************










































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
		// UnsignedInteger64bits Numbers::Get( UnsignedInteger64bits primeNumberIndex )
		// {

		// 	// Check if the index is smaller then the size of the prime numbers look up table
		// 	if ( primeNumberIndex < member_primeNumbersLookupTableSize )
		// 	{
		// 		// The required prime number exist in the look up table

		// 		// Return the required prime number
		// 		return ( member_primeNumbersLookupTable[ primeNumberIndex ] );
		// 	}

		// 	// The required prime number needs to be calculated

		// 	// This object will store the required prime number. Initialize it with the last prime number in the look up table, to start the search from it
		// 	UnsignedInteger64bits primeNumber = member_primeNumbersLookupTable[ member_primeNumbersLookupTableSize - 1UL ];

		// 	// Loop until the required prime number
		// 	for ( UnsignedInteger64bits index = member_primeNumbersLookupTableSize ; index <= primeNumberIndex ; ++index )
		// 	{
		// 		// Provide the current prime number to the method, which will calculate the next prime number
		// 		primeNumber = CalculateNextPrimeNumber__Private( primeNumber );
		// 	}

		// 	// Return the required prime number
		// 	return ( primeNumber );
		// }


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
		Boolean Numbers::PrimalityTest( UnsignedInteger64bits number )719
		{
		    // Each method that interacts with the user directly needs to ensure that the given data is valid
			Assert( ( number != 0UL ), "The given number should not be 0" )

			// Check if the last bit of the number is ON or OFF, if the bit is OFF, this means that the number is even and it divides by 2 with no
			// remainder. The second condition is to check if the number is 1, which is not a prime number. In both cases return false
			ReturnValueIfExpressionIsTrue( ( ( ( number & 1 ) == 0UL ) || ( number == 1UL ) ), false )

			// Check if the number is 3 or 5, which are the two first prime numbers
			ReturnValueIfExpressionIsTrue( ( ( number == 3UL ) || ( number == 5UL ) ), true )

			// This object will store the result of dividing the number with the divisor
			UnsignedInteger64bits result = 0UL;

			// This object will store the current divisor. It is initialized to 4 only to make the loop condition pass, and then the first real divisor
			// is calculated
			UnsignedInteger64bits divisor = 4UL;

			// The loop rational - in the first iteration the the order is the smallest, which means that the divisor will be the largest. In each
			// passing iteration the order increases, and the divisor decreases but much stronger. The point is that there is no need to check 
			// behind the point that the order is larger or equal from the divisor

			// Loop until the order is larger or equal to the divisor
			for ( UnsignedInteger64bits order = 3UL ; order < divisor ; order += 2UL )
			{
				// Calculate the current divier
				divisor = ( number / order );

				// Calculate the quotient of the number and the divisor
				result = ( number / divisor );

				// In integer arithemtics, if the quotient has a part after the decimal point, it will be removed, rounded down, towards the natural
				// number. Therefore if dividing a number by some divisor, and the multiplying the result, by the same divisor, if the result is the
				// same as the number started from, this means that the number divides by the divisor with no remainder
				ReturnValueIfExpressionIsTrue( ( ( result * divisor ) == number ), false )
			}

			// The number is prime
			return ( true );
		}


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
		UnsignedInteger64bits Numbers::LargestDivisorThatTheQuotientHasNoRemainder( UnsignedInteger64bits number )
		{
		    // Each method that interacts with the user directly needs to ensure that the given data is valid
			Assert( ( number != 0UL ), "The given number should not be 0" )
			Assert( ( PrimalityTest( number ) == false ), "The given number should not be prime" )

			// This object will store the result of dividing the number with the divisor
			UnsignedInteger64bits result = 0UL;

			// This object will store the current divisor. It is initialized to 3 only to make the loop condition pass, and then the first real divisor
			// is calculated
			UnsignedInteger64bits divisor = 3UL;

			// The loop rational - in the first iteration the the order is the smallest, which means that the divisor will be the largest. In each
			// passing iteration the order increases, and the divisor decreases but much stronger. The point is that there is no need to check 
			// behind the point that the order is larger or equal from the divisor

			// Loop until the order is larger or equal to the divisor
			for ( UnsignedInteger64bits order = 2UL ; order < divisor ; order += 1UL )
			{
				// Calculate the current divier
				divisor = ( number / order );

				// Calculate the quotient of the number and the divisor
				result = ( number / divisor );

				// In integer arithemtics, if the quotient has a part after the decimal point, it will be removed, rounded down, towards the natural
				// number. Therefore if dividing a number by some divisor, and the multiplying the result, by the same divisor, if the result is the
				// same as the number started from, this means that the number divides by the divisor with no remainder
				if ( ( result * divisor ) == number )
				{
					// The divisor was found

					// Break the loop
					break;
				}

			}

			// Return the divisor
			return ( divisor );
		}


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
		UnsignedInteger64bits Numbers::SmallestDivisorThatTheQuotientHasNoRemainder( UnsignedInteger64bits number )
		{		
		    // Each method that interacts with the user directly needs to ensure that the given data is valid
			Assert( ( number != 0UL ), "The given number should not be 0" )
			Assert( ( PrimalityTest( number ) == false ), "The given number should not be prime" )

			// Check if the last bit of the number is ON or OFF, if the bit is OFF, this means that the number is even and it divides by 2 with no
			// remainder
			ReturnValueIfExpressionIsTrue( ( ( number & 1 ) == 0UL ), 2UL )

			// This object will store the current divisor. It is initialized to 3 because 2 was already checked
			UnsignedInteger64bits divisor = 3UL;

			// Loop until the smallest divisor was found
			while ( true )
			{

				// Check if the dividend dividies with no remainder by the divisor
				if ( ( number % divisor ) == 0UL )
				{
					// The smallest divisor was found

					// Break the loop
					break;
				}


				// Increment the divisor to the next number
				divisor += 1UL;
			}

			// Return the divisor
			return ( divisor );
		}


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
		Memory::DynamicArray< UnsignedInteger64bits > Numbers::AllDivisorsThatTheQuotientHasNoRemainder( UnsignedInteger64bits number )
		{
		    // Each method that interacts with the user directly needs to ensure that the given data is valid
			Assert( ( number != 0UL ), "The given number should not be 0" )
			Assert( ( PrimalityTest( number ) == false ), "The given number should not be prime" )

			// This object will store all the divisors found for the current number, that the quotient has no remainder
			Memory::DynamicArray< UnsignedInteger64bits > divisors;

			// Find the smallest divisor and add to the array
			divisors.AddData( 0UL, SmallestDivisorThatTheQuotientHasNoRemainder( number ) );

			// This object will store the jump size between numbers that needs to be checked. If the number is even then, all the numbers between
			// the smallest and largest divisor needs to be checked also. Otherwise, if the number is odd, only the odd numbers needs to be checked.
			// Take the result of the modulo operation on the number by 2, this will give either zero in case the number divides by 2 with no
			// remainder, and 1 in case it doesn't. And then add 1 to the result, to pass on all the numbers or only on the odd ones
			UnsignedInteger64bits incrementSizeBetweenIterations = ( number % 2UL ) + 1UL;

			// Loop on the required numbers between the smallest and largest divisors and check if they match also. The loop will start from the
			// smallest divisor plus the increment size, because if the smallest divisor is even then the next divisor to check is the next number,
			// meaning plus 1, and if it even the next number to check is plus 2. If a divisor is found it means that the result of the division is
			// also a divisor, therefore when the current divisor checked divided by the number produce a smaller result then the divisor itself
			// then the loop can be stopped
			for ( UnsignedInteger64bits currentDivisor = ( divisors[0] + incrementSizeBetweenIterations ) ; currentDivisor < ( number / currentDivisor ) ; currentDivisor += incrementSizeBetweenIterations )
			{

				// Check if the number divides by the current divisor without a remainder
				if ( ( number % currentDivisor ) == 0UL )
				{
					// The current divisor match!

					// Add it to the array
					divisors.AddData( divisors.Size(), currentDivisor );
				}

			}

			// This object will store the current size of the divisors array
			UnsignedInteger64bits divisorsArraySize = divisors.Size();

			// Loop on all the divisors found, divide the number by them, and add the quotient as a divisor as well
			for ( UnsignedInteger64bits divisorsIndex = ( divisorsArraySize - 1 ) ; divisorsIndex > 0UL ; --divisorsIndex )
			{
				// Add the quotient of the number divided by the current divisor
				divisors.AddData( divisors.Size(), ( number / divisors[ divisorsIndex ] ) );
			}

			// Only the largest divisor left to be added
			divisors.AddData( divisors.Size(), ( number / divisors[0] ) );

			// Return the array with all the divisors of the number
			return ( MOVE( divisors ) );
		}


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
		Boolean Numbers::CommonDivisorTest( UnsignedInteger64bits number1, UnsignedInteger64bits number2 )
		{
		    // Each method that interacts with the user directly needs to ensure that the given data is valid
			Assert( ( number1 != 0UL ), "The given first number should not be 0" )
			Assert( ( number2 != 0UL ), "The given second number should not be 0" )
			Assert( ( PrimalityTest( number1 ) == false ), "The given first number should not be prime" )
			Assert( ( PrimalityTest( number2 ) == false ), "The given second number should not be prime" )
			Assert( ( number1 != number2 ), "The given numbers should be different" )

			// Check if the last bit of the numbers is ON or OFF, if the bit is OFF, this means that the numbers are even and divides by 2 with no
			// remainder
			ReturnValueIfExpressionIsTrue( ( ( ( number1 & 1 ) == 0UL ) && ( ( number2 & 1 ) == 0UL ) ), true )

			// Check if one of the number is 2, and the other one does not divide by 2
			ReturnValueIfExpressionIsTrue( ( ( ( number1 == 2UL ) || ( number2 == 2UL ) ) && ( ( ( number1 & 1 ) == 1UL ) || ( ( number2 & 1 ) == 1UL ) ) ), false )


			// Now it is known that at least one of the numbers is odd, which means that the common divisor must be odd if it exist

			// This object will store the larger number
			UnsignedInteger64bits largerNumber = 0UL;

			// This object will store all the divisors of the smaller number
			Memory::DynamicArray< UnsignedInteger64bits > smallerNumberDivisors;

			// Check which of the number is smaller
			if ( number1 < number2 )
			{
				// The first number is smaller

				// Store the larger number
				largerNumber = number2;

				// Find all the divisors of the first number
				smallerNumberDivisors = MOVE( AllDivisorsThatTheQuotientHasNoRemainder( number1 ) );
			}
			else
			{
				// The second number is smaller

				// Store the larger number
				largerNumber = number1;

				// Find all the divisors of the second number
				smallerNumberDivisors = MOVE( AllDivisorsThatTheQuotientHasNoRemainder( number2 ) );	
			}

			// Loop on all the divisors of the smaller number, and check if at least one of them also proudce a quotient that has no remainder when the
			// larger number divides by it
			for ( UnsignedInteger64bits smallerNumberDivisorsIndex = 0UL ; smallerNumberDivisorsIndex < smallerNumberDivisors.Size() ; ++smallerNumberDivisorsIndex )
			{
				// Check if the current divisor of the smaller number also is a divisor of the larger number
				ReturnValueIfExpressionIsTrue( ( ( largerNumber % smallerNumberDivisors[ smallerNumberDivisorsIndex ] ) == 0UL ), true )
			}

			// If the control of the method reached so far, then there are no common divisors for the 2 numbers, return false
			return ( false );
		}


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
		Memory::DynamicArray< UnsignedInteger64bits > Numbers::CommonDivisors( UnsignedInteger64bits number1, UnsignedInteger64bits number2 )
		{
		    // Each method that interacts with the user directly needs to ensure that the given data is valid
			Assert( ( number1 != 0UL ), "The given first number should not be 0" )
			Assert( ( number2 != 0UL ), "The given second number should not be 0" )
			Assert( ( number1 != number2 ), "The given numbers should be different" )
			Assert( ( CommonDivisorTest( number1, number2 ) == true ), "The given numbers should have at least one common divisor" )

			// This object will store all coomon divisors of the two numbers
			Memory::DynamicArray< UnsignedInteger64bits > commonDivisors;

			// This object will store the larger number
			UnsignedInteger64bits largerNumber = 0UL;

			// This object will store all the divisors of the smaller number
			Memory::DynamicArray< UnsignedInteger64bits > smallerNumberDivisors;

			// Check which of the number is smaller
			if ( number1 < number2 )
			{
				// The first number is smaller

				// Store the larger number
				largerNumber = number2;

				// Find all the divisors of the first number
				smallerNumberDivisors = MOVE( AllDivisorsThatTheQuotientHasNoRemainder( number1 ) );
			}
			else
			{
				// The second number is smaller

				// Store the larger number
				largerNumber = number1;

				// Find all the divisors of the second number
				smallerNumberDivisors = MOVE( AllDivisorsThatTheQuotientHasNoRemainder( number2 ) );	
			}

			// Loop on all the divisors of the smaller number, and check if at least one of them also proudce a quotient that has no remainder when the
			// larger number divides by it
			for ( UnsignedInteger64bits smallerNumberDivisorsIndex = 0UL ; smallerNumberDivisorsIndex < smallerNumberDivisors.Size() ; ++smallerNumberDivisorsIndex )
			{
			
				// Check if the current divisor of the smaller number also is a divisor of the larger number
				if ( ( largerNumber % smallerNumberDivisors[ smallerNumberDivisorsIndex ] ) == 0UL )
				{
					// The current divisor is a common one!

					// Add the current divisor to the array
					commonDivisors.AddData( commonDivisors.Size(), smallerNumberDivisors[ smallerNumberDivisorsIndex ] );
				}

			}

			// Return a copy of the common divisors array
			return ( MOVE( commonDivisors ) );
		}


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
		UnsignedInteger64bits Numbers::LargestCommonDivisor( UnsignedInteger64bits number1, UnsignedInteger64bits number2 )
		{
		    // Each method that interacts with the user directly needs to ensure that the given data is valid
			Assert( ( number1 != 0UL ), "The given first number should not be 0" )
			Assert( ( number2 != 0UL ), "The given second number should not be 0" )
			Assert( ( number1 != number2 ), "The given numbers should be different" )
			Assert( ( CommonDivisorTest( number1, number2 ) == true ), "The given numbers should have at least one common divisor" )

			// This object will store the larger number
			UnsignedInteger64bits largerNumber = 0UL;

			// This object will store all the divisors of the smaller number
			Memory::DynamicArray< UnsignedInteger64bits > smallerNumberDivisors;

			// Check which of the number is smaller
			if ( number1 < number2 )
			{
				// The first number is smaller

				// Store the larger number
				largerNumber = number2;

				// Find all the divisors of the first number
				smallerNumberDivisors = MOVE( AllDivisorsThatTheQuotientHasNoRemainder( number1 ) );
			}
			else
			{
				// The second number is smaller

				// Store the larger number
				largerNumber = number1;

				// Find all the divisors of the second number
				smallerNumberDivisors = MOVE( AllDivisorsThatTheQuotientHasNoRemainder( number2 ) );	
			}

			// Loop on all the divisors of the smaller number, and check if at least one of them also proudce a quotient that has no remainder when the
			// larger number divides by it
			for ( UnsignedInteger64bits smallerNumberDivisorsIndex = ( smallerNumberDivisors.Size() - 1UL ) ; smallerNumberDivisorsIndex > 0UL  ; --smallerNumberDivisorsIndex )
			{
				// Check if the current divisor of the smaller number also is a divisor of the larger number, then it is the largest divisor, return a
				// copy of it
				ReturnValueIfExpressionIsTrue( ( ( largerNumber % smallerNumberDivisors[ smallerNumberDivisorsIndex ] ) == 0UL ), smallerNumberDivisors[ smallerNumberDivisorsIndex ] )
			}

			// If control reached here, then any of the larger divisors of the smaller number, are also a divisors of the larger number. It is also known
			// that there is at least one common divisor which means that the divisor in the first entry is the required one
			return ( smallerNumberDivisors[0] );		
		}


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
		UnsignedInteger64bits Numbers::SmallestCommonDivisor( UnsignedInteger64bits number1, UnsignedInteger64bits number2 )
		{
		    // Each method that interacts with the user directly needs to ensure that the given data is valid
			Assert( ( number1 != 0UL ), "The given first number should not be 0" )
			Assert( ( number2 != 0UL ), "The given second number should not be 0" )
			Assert( ( number1 != number2 ), "The given numbers should be different" )
			Assert( ( CommonDivisorTest( number1, number2 ) == true ), "The given numbers should have at least one common divisor" )

			// This object will store the larger number
			UnsignedInteger64bits largerNumber = 0UL;

			// This object will store all the divisors of the smaller number
			Memory::DynamicArray< UnsignedInteger64bits > smallerNumberDivisors;

			// Check which of the number is smaller
			if ( number1 < number2 )
			{
				// The first number is smaller

				// Store the larger number
				largerNumber = number2;

				// Find all the divisors of the first number
				smallerNumberDivisors = MOVE( AllDivisorsThatTheQuotientHasNoRemainder( number1 ) );
			}
			else
			{
				// The second number is smaller

				// Store the larger number
				largerNumber = number1;

				// Find all the divisors of the second number
				smallerNumberDivisors = MOVE( AllDivisorsThatTheQuotientHasNoRemainder( number2 ) );	
			}

			// Loop on all the divisors of the smaller number, and check if at least one of them also proudce a quotient that has no remainder when the
			// larger number divides by it
			for ( UnsignedInteger64bits smallerNumberDivisorsIndex = 0UL ; smallerNumberDivisorsIndex < ( smallerNumberDivisors.Size() - 1UL )  ; ++smallerNumberDivisorsIndex )
			{
				// Check if the current divisor of the smaller number also is a divisor of the larger number, then it is the smallest divisor, return a
				// copy of it
				ReturnValueIfExpressionIsTrue( ( ( largerNumber % smallerNumberDivisors[ smallerNumberDivisorsIndex ] ) == 0UL ), smallerNumberDivisors[ smallerNumberDivisorsIndex ] )
			}

			// If control reached here, then any of the smaller divisors of the smaller number, are also a divisors of the larger number. It is also known
			// that there is at least one common divisor which means that the divisor in the last entry is the required one
			return ( smallerNumberDivisors[ smallerNumberDivisors.Size() - 1UL ] );
		}


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
		UnsignedInteger64bits Numbers::SmallestCommonMultiple( UnsignedInteger64bits number1, UnsignedInteger64bits number2 )
		{
		    // Each method that interacts with the user directly needs to ensure that the given data is valid
			Assert( ( number1 != 0UL ), "The given first number should not be 0" )
			Assert( ( number2 != 0UL ), "The given second number should not be 0" )

			// Check if one of the numbers is 1, which means the other number is the smallest common multiple because all the numbers divide by one
			// with no remainder
			ReturnValueIfExpressionIsTrue( ( number1 == 1UL ), number2 )
			ReturnValueIfExpressionIsTrue( ( number2 == 1UL ), number1 )

			// Check if both numbers are the same, then just return the number
			ReturnValueIfExpressionIsTrue( ( number1 == number2 ), number1 )

			// This variable will store the larger number
			UnsignedInteger64bits largerNumber = 0UL;

			// This variable will store the smaller number
			UnsignedInteger64bits smallerNumber = 0UL;

			// Check which of the numbers is smaller
			if ( number1 < number2 )
			{
				// The first number is smaller

				// Check if the second number divides by the first number with no remainder, which means that the common multiple is the second number
				ReturnValueIfExpressionIsTrue( ( ( number2 % number1 ) == 0UL ), number2 )

				// Store the larger and smaller numbers
				largerNumber = number2;
				smallerNumber = number1;
			}
			else
			{
				// The second number is smaller

				// Check if the first number divides by the second number with no remainder, which means that the common multiple is the first number
				ReturnValueIfExpressionIsTrue( ( ( number1 % number2 ) == 0UL ), number1 )

				// Store the larger and smaller numbers
				largerNumber = number1;
				smallerNumber = number2;
			}

			// This variable will store the multiplication of the given numbers. The multiplication of the numbers is divided by the two numbers
			// with no remainder, and will be taken as in case no smaller number is found. This is also the stop condition for the loop, because
			// it sets a known number to match the criteria so if a number was not found before it should be picked
			UnsignedInteger64bits numbersMultiplication = ( number1 * number2 );

			// This variable will store the current multiplication of the larger number and the number of times in the loop
			UnsignedInteger64bits currentMultiplicationOfLargerNumber = ( largerNumber * 2UL );

			// This variable will store the current number of times to multiply the larger number, it will be initialized to 3, because 1 was already
			// checked, and the current multiplication was initialized with 2, which will be checked in the first iteration
			UnsignedInteger64bits numberOfTimesToMultiplyLargerNumber = 3UL;

			// Loop until a number match the criteria or the numbers multiplication was reached
			while ( currentMultiplicationOfLargerNumber < numbersMultiplication )
			{
				// Check if the smaller number divides with no remainder in the current multiplication of the larger number with the required number
				// of times
				ReturnValueIfExpressionIsTrue( ( ( currentMultiplicationOfLargerNumber % smallerNumber ) == 0 ), currentMultiplicationOfLargerNumber )

				// Calculate the current multiplication
				currentMultiplicationOfLargerNumber = ( largerNumber * numberOfTimesToMultiplyLargerNumber );

				// Increment the number of time to multiply the larger number by 1
				numberOfTimesToMultiplyLargerNumber += 1UL;
			}

			// If the control of the method reached, here it means no smaller number then the numbers multiplication met the requirements. Return the
			// numbers multiplication
			return ( numbersMultiplication );
		}





























//	********************************************************************   PRIVATE METHODS IMPLEMENTATION   *********************************************************************
































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
		//			primeNumber - the prime number from which the start for the next prime number should start 
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
		UnsignedInteger64bits Numbers::CalculateNextPrimeNumber__Private( UnsignedInteger64bits primeNumber )
		{
			// Assert all the requirements on the template arguments provided to the object. To perform a compile time assert the C++ language provides 
	        // the keyword 'static_assert', which receives an expression and an error message to display if the expression result is false. The important
	        // thing is that the expression is evaluted during compile time, and therefore if the expression is false the compilation will be terminated
	        // and the error message will be displayed. This method should not be used, because it does nothing during run time
	        CompileTimeAssert( ( TypeCheck_Integer< UnsignedInteger64bits >::Result() == true ), "SignedToUnsigned::CompileTimeAssert - The given type should be integer" );

			// This object will store the next prime number
			UnsignedInteger64bits nextPrimeNumber = primeNumber + 2UL;

			// This object will store the current number that should be divided by the number checked if its a prime number
			UnsignedInteger64bits divisor = 3UL;

			// This object will store half of the prime number candidate value, this will be used to stop the loop, because the last number that needs to be checked
			// is the number before it
			UnsignedInteger64bits limit = ( nextPrimeNumber / 3UL ) + 1UL;

			// Loop until a number that does not divide without remainder by any of the numbers smaller then it
			while ( true )
			{
				// Increment the limit by 1
				limit += 1UL;

				// Check if the current prime number candidate has the tens digit '5', which means it divids with no remainder by 5
				if ( ( nextPrimeNumber % 10 ) == 5 )
				{
					// The current prime number candidate has the tens digit '5'

					// Increment the prime number candidate by 2
					nextPrimeNumber += 2UL;

					// Continue to the next candidate
					continue;
				}

				// Loop on all the numbers smaller then the current prime number candidate
				for ( divisor = 3UL ; divisor <= limit ; divisor += 2UL )
				{

					// Check if the current prime number candidate divides with no raminder
					if ( ( nextPrimeNumber % divisor ) == 0UL )
					{
						// The prime number candidate divides with no ramainder by the divisor

						// The current candidate is not a prime number, break the loop
						break;
					}

				}

				// Check the reason that the inner loop ended
				if ( divisor >= limit )
				{
					// The loop passed all the range and didn't find a number that the prime number candidate, divides by without a remainder

					// The next prime number was found, break the loop
					break;
				}

				// Increment the prime number candidate by 2
				nextPrimeNumber += 2UL;
			}

			// Return the next prime number
			return ( nextPrimeNumber );
		}




































// *********************************************************************************   TESTING   ********************************************************************************




































		DEBUG_TOOL(

			// Method Information :
			//
			//  Description :
			//
			//		This method is used to test the object. It is not part of the implementation, it is only used to find problem with the code that does implement
			//		the functionality
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
			//		1. true - if the object passed the test
			//		2. false - otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		1. An assertion failed - class Exception is thrown
			//		2. There is no more free memory space - class std::bad_alloc is thrown
			//		3. 
			//
			void Numbers::Test()
			{
				Assert( ( PrimalityTest( 17UL ) == true ), "Test failed - 1" )
				Assert( ( PrimalityTest( 3UL ) == true ), "Test failed - 2" )
				Assert( ( PrimalityTest( 8UL ) == false ), "Test failed - 3" )
				Assert( ( PrimalityTest( 47UL ) == true ), "Test failed - 4" )

				Assert( ( PrimalityTest( 9973UL ) == true ), "Test failed - 5" )
				Assert( ( PrimalityTest( 9967UL ) == true ), "Test failed - 6" )
				Assert( ( PrimalityTest( 9949UL ) == true ), "Test failed - 7" )
				Assert( ( PrimalityTest( 9941UL ) == true ), "Test failed - 8" )
				Assert( ( PrimalityTest( 9931UL ) == true ), "Test failed - 9" )
				Assert( ( PrimalityTest( 9929UL ) == true ), "Test failed - 10" )
				Assert( ( PrimalityTest( 9923UL ) == true ), "Test failed - 11" )
				Assert( ( PrimalityTest( 9907UL ) == true ), "Test failed - 12" )
				Assert( ( PrimalityTest( 9901UL ) == true ), "Test failed - 13" )
				Assert( ( PrimalityTest( 9887UL ) == true ), "Test failed - 14" )
				Assert( ( PrimalityTest( 9883UL ) == true ), "Test failed - 15" )
				Assert( ( PrimalityTest( 9871UL ) == true ), "Test failed - 16" )

				Assert( ( PrimalityTest( 9971UL ) == false ), "Test failed - 17" )
				Assert( ( PrimalityTest( 9962UL ) == false ), "Test failed - 18" )
				Assert( ( PrimalityTest( 9943UL ) == false ), "Test failed - 19" )
				Assert( ( PrimalityTest( 9945UL ) == false ), "Test failed - 20" )
				Assert( ( PrimalityTest( 9933UL ) == false ), "Test failed - 21" )
				Assert( ( PrimalityTest( 9927UL ) == false ), "Test failed - 22" )
				Assert( ( PrimalityTest( 9921UL ) == false ), "Test failed - 23" )
				Assert( ( PrimalityTest( 9909UL ) == false ), "Test failed - 24" )
				Assert( ( PrimalityTest( 9903UL ) == false ), "Test failed - 25" )
				Assert( ( PrimalityTest( 9882UL ) == false ), "Test failed - 26" )
				Assert( ( PrimalityTest( 9885UL ) == false ), "Test failed - 27" )
				Assert( ( PrimalityTest( 9870UL ) == false ), "Test failed - 28" )


				// // Enable this only to check the performance, so far not the best but starting to be better
				// UnsignedInteger64bits nn = 987489137713739199UL;

				// for ( int index = 0 ; index < 300 ; ++ index )
				// {
				// 	std::cout << PrimalityTest( nn + index ) << std::endl;
				// }


				Assert( ( LargestDivisorThatTheQuotientHasNoRemainder( 8UL ) == 4UL ), "Test failed - 29" )
				Assert( ( LargestDivisorThatTheQuotientHasNoRemainder( 9UL ) == 3UL ), "Test failed - 30" )
				Assert( ( LargestDivisorThatTheQuotientHasNoRemainder( 12UL ) == 6UL ), "Test failed - 31" )
				Assert( ( LargestDivisorThatTheQuotientHasNoRemainder( 15UL ) == 5UL ), "Test failed - 32" )
				Assert( ( LargestDivisorThatTheQuotientHasNoRemainder( 144UL ) == 72UL ), "Test failed - 33" )
				Assert( ( LargestDivisorThatTheQuotientHasNoRemainder( 45UL ) == 15UL ), "Test failed - 34" )
				Assert( ( LargestDivisorThatTheQuotientHasNoRemainder( 90UL ) == 45UL ), "Test failed - 35" )
				Assert( ( LargestDivisorThatTheQuotientHasNoRemainder( 93UL ) == 31UL ), "Test failed - 36" )
				Assert( ( LargestDivisorThatTheQuotientHasNoRemainder( 12345UL ) == 4115UL ), "Test failed - 37" )
				Assert( ( LargestDivisorThatTheQuotientHasNoRemainder( 34567UL ) == 2659UL ), "Test failed - 38" )
				Assert( ( LargestDivisorThatTheQuotientHasNoRemainder( 45797UL ) == 1117UL ), "Test failed - 39" )


				Assert( ( SmallestDivisorThatTheQuotientHasNoRemainder( 8UL ) == 2UL ), "Test failed - 40" )
				Assert( ( SmallestDivisorThatTheQuotientHasNoRemainder( 16UL ) == 2UL ), "Test failed - 41" )
				Assert( ( SmallestDivisorThatTheQuotientHasNoRemainder( 12464UL ) == 2UL ), "Test failed - 42" )
				Assert( ( SmallestDivisorThatTheQuotientHasNoRemainder( 34565456342UL ) == 2UL ), "Test failed - 43" )
				Assert( ( SmallestDivisorThatTheQuotientHasNoRemainder( 12222222222222UL ) == 2UL ), "Test failed - 44" )
				Assert( ( SmallestDivisorThatTheQuotientHasNoRemainder( 22633365UL ) == 3UL ), "Test failed - 45" )
				Assert( ( SmallestDivisorThatTheQuotientHasNoRemainder( 69002381UL ) == 7UL ), "Test failed - 46" )
				Assert( ( SmallestDivisorThatTheQuotientHasNoRemainder( 9805939UL ) == 11UL ), "Test failed - 47" )
				Assert( ( SmallestDivisorThatTheQuotientHasNoRemainder( 12294625131UL ) == 3UL ), "Test failed - 48" )


				auto testAllDivisors_1 = MOVE( AllDivisorsThatTheQuotientHasNoRemainder( 24 ) );

				Assert( ( testAllDivisors_1[0] == 2UL ), "Test failed - 49" )
				Assert( ( testAllDivisors_1[1] == 3UL ), "Test failed - 50" )
				Assert( ( testAllDivisors_1[2] == 4UL ), "Test failed - 51" )
				Assert( ( testAllDivisors_1[3] == 6UL ), "Test failed - 52" )
				Assert( ( testAllDivisors_1[4] == 8UL ), "Test failed - 53" )
				Assert( ( testAllDivisors_1[5] == 12UL ), "Test failed - 54" )


				auto testAllDivisors_2 = MOVE( AllDivisorsThatTheQuotientHasNoRemainder( 40 ) );

				Assert( ( testAllDivisors_2[0] == 2UL ), "Test failed - 55" )
				Assert( ( testAllDivisors_2[1] == 4UL ), "Test failed - 56" )
				Assert( ( testAllDivisors_2[2] == 5UL ), "Test failed - 57" )
				Assert( ( testAllDivisors_2[3] == 8UL ), "Test failed - 58" )
				Assert( ( testAllDivisors_2[4] == 10UL ), "Test failed - 59" )
				Assert( ( testAllDivisors_2[5] == 20UL ), "Test failed - 60" )


				auto testAllDivisors_3 = MOVE( AllDivisorsThatTheQuotientHasNoRemainder( 123 ) );

				Assert( ( testAllDivisors_3[0] == 3UL ), "Test failed - 61" )
				Assert( ( testAllDivisors_3[1] == 41UL ), "Test failed - 62" )


				auto testAllDivisors_4 = MOVE( AllDivisorsThatTheQuotientHasNoRemainder( 11324 ) );
				
				Assert( ( testAllDivisors_4[0] == 2UL ), "Test failed - 63" )
				Assert( ( testAllDivisors_4[1] == 4UL ), "Test failed - 64" )
				Assert( ( testAllDivisors_4[2] == 19UL ), "Test failed - 65" )
				Assert( ( testAllDivisors_4[3] == 38UL ), "Test failed - 66" )
				Assert( ( testAllDivisors_4[4] == 76UL ), "Test failed - 67" )
				Assert( ( testAllDivisors_4[5] == 149UL ), "Test failed - 68" )
				Assert( ( testAllDivisors_4[6] == 298UL ), "Test failed - 69" )
				Assert( ( testAllDivisors_4[7] == 596UL ), "Test failed - 70" )
				Assert( ( testAllDivisors_4[8] == 2831UL ), "Test failed - 71" )
				Assert( ( testAllDivisors_4[9] == 5662UL ), "Test failed - 72" )


				UnsignedInteger64bits multiplier1 = 457UL;
				UnsignedInteger64bits multiplier2 = 5687UL;

				for ( UnsignedInteger64bits number = 3UL ; number < 534UL ; ++number )
				{
					Assert( ( CommonDivisorTest( number * multiplier1, number * multiplier2 ) == true ), "Test failed - 73" )
				}

				UnsignedInteger64bits multiplier3 = 111111UL;

				for ( UnsignedInteger64bits number = 3UL ; number < 534UL ; ++number )
				{
					Assert( ( CommonDivisorTest( number * multiplier1 * multiplier3, number * multiplier2 * multiplier3 ) == true ), "Test failed - 74" )

					multiplier3 -= 77UL;
				}

				Assert( ( PrimalityTest( 5UL ) == true ), "Test failed - 75" )
				Assert( ( CommonDivisorTest( 2UL, 87UL ) == false ), "Test failed - 76" )

			}

		)  //  End of debug tool











	}  //  Namespace Mathematics

}  //  Namespace Universe


#endif  //  NUMBERS_CPP





