#ifndef RATIONALNUMBER_CPP
#define RATIONALNUMBER_CPP


#include "RationalNumber.hpp"


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../../../../../../../../../../TestBranch/SanityCheck/SanityCheck.hpp"  //  Class SanityCheck
#endif


namespace Universe 
{

	namespace Mathematics
    {



















//  ************************************************************************   OPERATORS IMPLEMENTATION   ***********************************************************************


































        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to add the right side operand instance to this instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - a reference to another rational number instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        A reference to this object
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        // 
        RationalNumber& RationalNumber::operator+=( const RationalNumber& rightSideOperand )
        {
        	// Fraction addition :
        	//
        	//		a   c   a * ( common denominator / b ) + c ( common denominator / d )
        	//		- + - = -------------------------------------------------------------
        	// 		b   d                      common denominator

        	// Find the common denominator, which is the smallest common multiple of the 2 instances denominators
        	UnsignedInteger64bits commonDenominator = Numbers::SmallestCommonMultiple( member_denominator, rightSideOperand.member_denominator );

        	// This variable will store the multiplication of the numerator of this instane with the quotient of the common denominator and the 
        	// denominator of this instance
        	UnsignedInteger64bits thisModifiedNumerator = ( member_numerator * ( commonDenominator / member_denominator ) );

        	// This variable will store the multiplication of the numerator of the other instane with the quotient of the common denominator and 
        	// the denominator of the other instance
        	UnsignedInteger64bits otherModifiedNumerator = ( rightSideOperand.member_numerator * ( commonDenominator / rightSideOperand.member_denominator ) );

        	// Check if the sign of both instances is the same
        	if ( member_sign == rightSideOperand.member_sign )
        	{
        		// The sign is the same for both rational numbers

				// The new numerator is the sum of the two
	        	member_numerator = ( thisModifiedNumerator + otherModifiedNumerator );
	        }
	        // The signs are not the same, check if this numerator is larger or equal to the other numerator
	        else if ( thisModifiedNumerator >= otherModifiedNumerator )
	        {
	        	// The modified numerator of this instance is larger or equal then the modified numerator of the other instance

	        	// All there is to do is to subtract the other modified numerator from this modified numerator. This behaviour is correct because no
	        	// matter if the negative sign is for this or the other instance, the operation between the modified numerators will still be subtraction.
	        	// Furthermore the sign of this instance will not change
	        	member_numerator = ( thisModifiedNumerator - otherModifiedNumerator );
	        }
	        else
	        {
	        	// The modified numerator of this instance is smaller then the modified numerator of the other instance

	        	// All there is to do is to subtract this modified numerator from the other modified numerator. This behaviour is correct because no
	        	// matter if the negative sign is for this or the other instance, the operation between the modified numerators will still be subtraction
	        	member_numerator = ( otherModifiedNumerator - thisModifiedNumerator );

	        	// The last stage is to change the sign according to the sign in the other instance
	        	member_sign = rightSideOperand.member_sign;
	        }

        	// And all there is left to do, is to set the denominator of this instance to the common denominator
        	member_denominator = commonDenominator;

			// Set the simplified form of the rational number
			SimplifiedForm__Private();

        	// Return a reference to this instance
            return ( *this );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to subtract from the rational number in this instance the data inside the right side operand object
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - a reference to another rational number instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        A reference to this object
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        RationalNumber& RationalNumber::operator-=( const RationalNumber& rightSideOperand )
        {
        	// Fraction subtraction :
        	//
        	//		a   c   a * ( common denominator / b ) - c ( common denominator / d )
        	//		- - - = -------------------------------------------------------------
        	// 		b   d                      common denominator

        	// Find the common denominator, which is the smallest common multiple of the 2 instances denominators
        	UnsignedInteger64bits commonDenominator = Numbers::SmallestCommonMultiple( member_denominator, rightSideOperand.member_denominator );

        	// This variable will store the multiplication of the numerator of this instane with the quotient of the common denominator and the 
        	// denominator of this instance
        	UnsignedInteger64bits thisModifiedNumerator = ( member_numerator * ( commonDenominator / member_denominator ) );

        	// This variable will store the multiplication of the numerator of the other instane with the quotient of the common denominator and 
        	// the denominator of the other instance
        	UnsignedInteger64bits otherModifiedNumerator = ( rightSideOperand.member_numerator * ( commonDenominator / rightSideOperand.member_denominator ) );

        	// Check if the sign of both instances is different
        	if ( member_sign != rightSideOperand.member_sign )
        	{
        		// The sign is not the same for both rational numbers

				// The new numerator is the sum of the two
	        	member_numerator = ( thisModifiedNumerator + otherModifiedNumerator );
	        }
	        // The signs are the same, check if this numerator is larger or equal to the other numerator
	        else if ( thisModifiedNumerator >= otherModifiedNumerator )
	        {
	        	// The modified numerator of this instance is larger or equal then the modified numerator of the other instance

	        	// All there is to do is to subtract the other modified numerator from this modified numerator. This behaviour is correct because no
	        	// matter if the negative sign is for this or the other instance, the operation between the modified numerators will still be subtraction.
	        	// Furthermore the sign of this instance will not change
	        	member_numerator = ( thisModifiedNumerator - otherModifiedNumerator );
	        }
	        else
	        {
	        	// The modified numerator of this instance is smaller then the modified numerator of the other instance

	        	// All there is to do is to subtract this modified numerator from the other modified numerator. This behaviour is correct because no
	        	// matter if the negative sign is for this or the other instance, the operation between the modified numerators will still be subtraction
	        	member_numerator = ( otherModifiedNumerator - thisModifiedNumerator );

	        	// The last stage is to change the sign according to the sign in the other instance
	        	member_sign = rightSideOperand.member_sign;
	        }

        	// And all there is left to do, is to set the denominator of this instance to the common denominator
        	member_denominator = commonDenominator;

			// Set the simplified form of the rational number
			SimplifiedForm__Private();

        	// Return a reference to this instance
            return ( *this );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the rational number in this instance is larger then the data inside the right side operand object
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - a reference to another rational number instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		True if the rational number in this instance is larger then the righe side operand, and false otherwise
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come 
        //  
        Boolean RationalNumber::operator>( const RationalNumber& rightSideOperand ) const
        {            
        	// Check if the two rational numbers are the same
        	ReturnValueIfExpressionIsTrue( ( *this == rightSideOperand ), false )

        	// Check if the rational number is positive and the right side operand is negative, which means the rational number in this 
        	// instance is larger
        	ReturnValueIfExpressionIsTrue( ( ( member_sign == 1 ) && ( rightSideOperand.member_sign == -1 ) ), true )

        	// Check if the rational number is negative and the right side operand is positive, which means the rational number in this 
        	// instance is smaller
        	ReturnValueIfExpressionIsTrue( ( ( member_sign == -1 ) && ( rightSideOperand.member_sign == 1 ) ), false )

        	// Both rational numbers have the same sign!

        	// Find the common denominator, which is the smallest common multiple of the 2 instances denominators
        	UnsignedInteger64bits commonDenominator = Numbers::SmallestCommonMultiple( member_denominator, rightSideOperand.member_denominator );

        	// This variable will store the multiplication of the numerator of this instane with the quotient of the common denominator and the 
        	// denominator of this instance
        	UnsignedInteger64bits thisModifiedNumerator = ( member_numerator * ( commonDenominator / member_denominator ) );

        	// This variable will store the multiplication of the numerator of the other instane with the quotient of the common denominator and 
        	// the denominator of the other instance
        	UnsignedInteger64bits otherModifiedNumerator = ( rightSideOperand.member_numerator * ( commonDenominator / rightSideOperand.member_denominator ) );

        	// Check if both instances sign is positive
        	if ( ( member_sign == 1 ) && ( rightSideOperand.member_sign == 1 ) )
        	{
        		// Both instances are positive

        		// Check which numerator will be larger with the common denominator, and return the result
        		ReturnValueIfExpressionIsTrue( ( thisModifiedNumerator < otherModifiedNumerator ), false )
        	}
        	else
        	{
        		// Both instances are negative

        		// Check which numerator will be larger with the common denominator, and return the result
        		ReturnValueIfExpressionIsTrue( ( thisModifiedNumerator > otherModifiedNumerator ), false )
        	}

        	// If control of the method reached here then this instance rational number is larger then the righe side operand, return true
        	return ( true );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the rational number in this instance is smaller then the data inside the right side operand object
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - a reference to another rational number instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		True if the rational number in this instance is smaller then the righe side operand, and false otherwise
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come 
        //  
        Boolean RationalNumber::operator <( const RationalNumber& rightSideOperand ) const
        {            
        	// Check if the two rational numbers are the same
        	ReturnValueIfExpressionIsTrue( ( *this == rightSideOperand ), false )

        	// Check if the rational number is positive and the right side operand is negative, which means the rational number in this 
        	// instance is larger
        	ReturnValueIfExpressionIsTrue( ( ( member_sign == 1 ) && ( rightSideOperand.member_sign == -1 ) ), false )

        	// Check if the rational number is negative and the right side operand is positive, which means the rational number in this 
        	// instance is smaller
        	ReturnValueIfExpressionIsTrue( ( ( member_sign == -1 ) && ( rightSideOperand.member_sign == 1 ) ), true )

        	// Both rational numbers have the same sign!

        	// Find the common denominator, which is the smallest common multiple of the 2 instances denominators
        	UnsignedInteger64bits commonDenominator = Numbers::SmallestCommonMultiple( member_denominator, rightSideOperand.member_denominator );

        	// This variable will store the multiplication of the numerator of this instane with the quotient of the common denominator and the 
        	// denominator of this instance
        	UnsignedInteger64bits thisModifiedNumerator = ( member_numerator * ( commonDenominator / member_denominator ) );

        	// This variable will store the multiplication of the numerator of the other instane with the quotient of the common denominator and 
        	// the denominator of the other instance
        	UnsignedInteger64bits otherModifiedNumerator = ( rightSideOperand.member_numerator * ( commonDenominator / rightSideOperand.member_denominator ) );

        	// Check if both instances sign is positive
        	if ( ( member_sign == 1 ) && ( rightSideOperand.member_sign == 1 ) )
        	{
        		// Both instances are positive

        		// Check which numerator will be larger with the common denominator, and return the result
        		ReturnValueIfExpressionIsTrue( ( thisModifiedNumerator > otherModifiedNumerator ), false )
        	}
        	else
        	{
        		// Both instances are negative

        		// Check which numerator will be larger with the common denominator, and return the result
        		ReturnValueIfExpressionIsTrue( ( thisModifiedNumerator < otherModifiedNumerator ), false )
        	}

        	// If control of the method reached here then this instance rational number is smaller then the righe side operand, return true
        	return ( true );
        }


































//	********************************************************************   PRIVATE METHODS IMPLEMENTATION   *********************************************************************

































		// Method Information :
		//
		//  Description :
		//
		//		Use this method to convert the rational number to simplified form. A rational number is written in its simplified form if the numerator
		//		and denominator have no common factor
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
		//      NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		void RationalNumber::SimplifiedForm__Private()
		{
			// Check if the numerator is 0 or 1, and if the denominator is 1, which means that the rational is in simplified form already
			ReturnIfExpressionIsTrue( ( member_numerator == 0UL ) || ( member_numerator == 1UL ) || ( member_denominator == 1UL ) )

			// Check if the numerator and denominator are equal
			if ( member_numerator == member_denominator )
			{
				// The numerator and denominator are equal

				// Set the numerator and denominator to 1
				member_numerator = 1UL;
				member_denominator = 1UL;

				// Nothing else needs to be done
				return;
			}

			// Check if the numerator is a divisor of the denominator or the upside down
			if ( member_numerator > member_denominator )
			{
				// The numerator is larger then the denominator

				// Check if the numerator divides by the denominator with no remainder
				if ( ( member_numerator % member_denominator ) == 0 )
				{
					// The numerator divides by the denominator with no remainder

					// Divide the numerator by the denominator
					member_numerator /= member_denominator;

					// Set the denominator to 1, becasue dividing a number by itself gives a quotient of 1
					member_denominator = 1UL;

					// Nothing else needs to be done
					return;
				}

			}
			else
			{
				// The denominator is larger then the numerator

				// Check if the denominator divides by the numerator with no remainder
				if ( ( member_denominator % member_numerator ) == 0 )
				{
					// The denominator divides by the numerator with no remainder

					// Divide the denominator by the numerator 
					member_denominator /= member_numerator;

					// Set the numerator to 1, becasue dividing a number by itself gives a quotient of 1
					member_numerator = 1UL;

					// Nothing else needs to be done
					return;
				}

			}

			// Check if the numerator or the denominator are prime numbers, which means the rational number is already in the simplified form
			ReturnIfExpressionIsTrue( Numbers::PrimalityTest( member_numerator ) == true )
			ReturnIfExpressionIsTrue( Numbers::PrimalityTest( member_denominator ) == true )

			// This object will store the currrent largest common divisor of the numerator and denominator
			UnsignedInteger64bits largestCommonDivisor = 0;

			// Loop until there no more common divisors
			while ( ( Numbers::PrimalityTest( member_numerator ) == false ) && ( Numbers::PrimalityTest( member_denominator ) == false ) && ( Numbers::CommonDivisorTest( member_numerator, member_denominator ) == true ) )
			{
				// Calculate the largest common divisor of the numerator and denominator
				largestCommonDivisor = Numbers::LargestCommonDivisor( member_numerator, member_denominator );

				// Divide the numerator and denominator by the largest common divisor
				member_numerator /= largestCommonDivisor;
				member_denominator /= largestCommonDivisor;
			}

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
			void RationalNumber::Test()
			{
				// Perform a sanity to ensure that all the methods that are common among all objects, for example defualt constructor, copy constructor,
				// destructor, swap and more, seem to work correctly
				Testing::SanityCheck::Full< RationalNumber COMMA UnsignedInteger64bits COMMA UnsignedInteger64bits COMMA Boolean >();

				// Create a test instance
				RationalNumber testRationalNumber_1( 2, 87 );

				// Assert that the operation performed correctly
				Assert_Test( ( ( testRationalNumber_1.member_numerator == 2UL ) && ( testRationalNumber_1.member_denominator == 87UL ) ) )

				// Create a test instance
				RationalNumber testRationalNumber_2( 4, 87 );

				// Assert that the operation performed correctly
				Assert_Test( ( ( testRationalNumber_2.member_numerator == 4UL ) && ( testRationalNumber_2.member_denominator == 87UL ) ) )

				// Create a test instance
				RationalNumber testRationalNumber_3( 4, 88 );

				// Assert that the operation performed correctly
				Assert_Test( ( ( testRationalNumber_3.member_numerator == 1UL ) && ( testRationalNumber_3.member_denominator == 22UL ) ) )

				// Create a test instance
				RationalNumber testRationalNumber_4( 3, 7 );

				// Assert that the operation performed correctly
				Assert_Test( ( ( testRationalNumber_4.member_numerator == 3UL ) && ( testRationalNumber_4.member_denominator == 7UL ) ) )

				// Create a test instance
				RationalNumber testRationalNumber_5( 0, 7 );

				// Assert that the operation performed correctly
				Assert_Test( ( ( testRationalNumber_5.member_numerator == 0UL ) && ( testRationalNumber_5.member_denominator == 7UL ) ) )

				// Create a test instance
				RationalNumber testRationalNumber_6( 80, 450 );

				// Assert that the operation performed correctly
				Assert_Test( ( ( testRationalNumber_6.member_numerator == 8UL ) && ( testRationalNumber_6.member_denominator == 45UL ) ) )

				// Create a test instance
				RationalNumber testRationalNumber_7( 1, 3 );

				// Try the addition operator
				testRationalNumber_7 += 8UL;

				// Assert that the operation performed correctly
				Assert_Test( ( ( testRationalNumber_7.member_numerator == 25UL ) && ( testRationalNumber_7.member_denominator == 3UL ) ) )

				// Try the addition operator
				testRationalNumber_7 += 3UL;

				// Assert that the operation performed correctly
				Assert_Test( ( ( testRationalNumber_7.member_numerator == 34UL ) && ( testRationalNumber_7.member_denominator == 3UL ) ) )

				// Try the subtraction operator
				testRationalNumber_7 -= 3UL;

				// Assert that the operation performed correctly
				Assert_Test( ( ( testRationalNumber_7.member_numerator == 25UL ) && ( testRationalNumber_7.member_denominator == 3UL ) ) )

				// Try the subtraction operator
				testRationalNumber_7 -= 8UL;

				// Assert that the operation performed correctly
				Assert_Test( ( ( testRationalNumber_7.member_numerator == 1UL ) && ( testRationalNumber_7.member_denominator == 3UL ) ) )

				// Create a test instance
				RationalNumber testRationalNumber_8( 1, 3 );

				// Try the addition operator
				testRationalNumber_7 += testRationalNumber_8;

				// Assert that the operation performed correctly
				Assert_Test( ( ( testRationalNumber_7.member_numerator == 2UL ) && ( testRationalNumber_7.member_denominator == 3UL ) ) )

				// Try the addition operator
				testRationalNumber_7 += testRationalNumber_8;

				// Assert that the operation performed correctly
				Assert_Test( ( ( testRationalNumber_7.member_numerator == 1UL ) && ( testRationalNumber_7.member_denominator == 1UL ) ) )

				// Try the addition operator
				testRationalNumber_8 += testRationalNumber_7;

				// Assert that the operation performed correctly
				Assert_Test( ( ( testRationalNumber_8.member_numerator == 4UL ) && ( testRationalNumber_8.member_denominator == 3UL ) ) )

				// Try the addition operator
				testRationalNumber_8 += testRationalNumber_7;

				// Assert that the operation performed correctly
				Assert_Test( ( ( testRationalNumber_8.member_numerator == 7UL ) && ( testRationalNumber_8.member_denominator == 3UL ) ) )

				// Try the addition operator
				testRationalNumber_8 += testRationalNumber_7;

				// Assert that the operation performed correctly
				Assert_Test( ( ( testRationalNumber_8.member_numerator == 10UL ) && ( testRationalNumber_8.member_denominator == 3UL ) ) )

				// Create a test instance
				RationalNumber testRationalNumber_9( 3, 8 );

				// Try the addition operator
				testRationalNumber_8 += testRationalNumber_9;

				// Assert that the operation performed correctly
				Assert_Test( ( ( testRationalNumber_8.member_numerator == 89UL ) && ( testRationalNumber_8.member_denominator == 24UL ) ) )

				// Try the addition operator
				testRationalNumber_8 += testRationalNumber_9;

				// Assert that the operation performed correctly
				Assert_Test( ( ( testRationalNumber_8.member_numerator == 49UL ) && ( testRationalNumber_8.member_denominator == 12UL ) ) )

				// Create a test instance
				RationalNumber testRationalNumber_10( 7, 11 );

				// Try the addition operator
				testRationalNumber_8 += testRationalNumber_10;

				// Assert that the operation performed correctly
				Assert_Test( ( ( testRationalNumber_8.member_numerator == 623UL ) && ( testRationalNumber_8.member_denominator == 132UL ) ) )

				// Try the subtraction operator
				testRationalNumber_8 -= testRationalNumber_10;

				// Assert that the operation performed correctly
				Assert_Test( ( ( testRationalNumber_8.member_numerator == 49UL ) && ( testRationalNumber_8.member_denominator == 12UL ) ) )

				// Try the subtraction operator
				testRationalNumber_8 -= testRationalNumber_9;

				// Assert that the operation performed correctly
				Assert_Test( ( ( testRationalNumber_8.member_numerator == 89UL ) && ( testRationalNumber_8.member_denominator == 24UL ) ) )

				// Try the subtraction operator
				testRationalNumber_8 -= testRationalNumber_9;

				// Assert that the operation performed correctly
				Assert_Test( ( ( testRationalNumber_8.member_numerator == 10UL ) && ( testRationalNumber_8.member_denominator == 3UL ) ) )

				// Create two test instances
				RationalNumber testRationalNumber_11( 7, 11 );
				RationalNumber testRationalNumber_12( 8, 11 );

				// Assert that the operation performed correctly
				Assert_Test( ( testRationalNumber_11 < testRationalNumber_12 ) == true )
				Assert_Test( ( testRationalNumber_11 > testRationalNumber_12 ) == false )

				// Create two test instances
				RationalNumber testRationalNumber_13( 7, 12 );
				RationalNumber testRationalNumber_14( 8, 11 );

				// Assert that the operation performed correctly
				Assert_Test( ( testRationalNumber_13 < testRationalNumber_14 ) == true )
				Assert_Test( ( testRationalNumber_13 > testRationalNumber_14 ) == false )

				// Create two test instances
				RationalNumber testRationalNumber_15( 45, 12, false );
				RationalNumber testRationalNumber_16( 870, 11 );

				// Assert that the operation performed correctly
				Assert_Test( ( testRationalNumber_15 < testRationalNumber_16 ) == true )
				Assert_Test( ( testRationalNumber_15 > testRationalNumber_16 ) == false )

				// Create two test instances
				RationalNumber testRationalNumber_17( 45, 12, false );
				RationalNumber testRationalNumber_18( 870, 11, false );

				// Assert that the operation performed correctly
				Assert_Test( ( testRationalNumber_17 < testRationalNumber_18 ) == false )
				Assert_Test( ( testRationalNumber_17 > testRationalNumber_18 ) == true )

                // Create a test instance                
				RationalNumber testRationalNumber_19 = ( 56UL + testRationalNumber_18 );

                // Assert that the operation performed correctly
                Assert_Test( ( ( testRationalNumber_19.member_numerator == 1486UL ) && ( testRationalNumber_19.member_denominator == 11UL ) ) )
			}

		)  //  End of debug tool











	}  //  Namespace Mathematics


}  //  Namespace Universe


#endif  //  RATIONALNUMBER_CPP





