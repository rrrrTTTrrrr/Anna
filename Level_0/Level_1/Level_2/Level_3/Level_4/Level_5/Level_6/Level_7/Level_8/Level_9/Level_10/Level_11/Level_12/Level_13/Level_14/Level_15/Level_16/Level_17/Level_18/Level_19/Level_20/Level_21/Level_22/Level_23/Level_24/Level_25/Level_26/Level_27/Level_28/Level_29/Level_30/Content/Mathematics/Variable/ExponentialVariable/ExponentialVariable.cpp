#include "ExponentialVariable.hpp"


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../../../../../../../../../../../../../../../../../Test/GeneralTests/SanityCheck/SanityCheck.hpp"  //  Class SanityCheck
#endif


namespace Universe 
{

	namespace Mathematics
    {



//	***************************************************************   PUBLIC METHODS IMPLEMENTATION - INTERFACE   ***************************************************************



		FloatingPoint64bits ExponentialVariable::Value( FloatingPoint64bits value ) const
		{
			// Check if the power sign is negative
			if ( member_power < 0 )
			{
				// The power sign is negative

				// Because the power sign is negative the value raised by the power needs to be the denominator of a fraction where the numerator is 1. 
				// Multiply the fraction by coefficient, and return the result
				return ( member_coefficient * ( 1 / Arithmetic::RaiseBaseByThePower< FloatingPoint64bits >( value, Arithmetic::AbsoluteValue< FloatingPoint64bits >( member_power ) ) ) ); 
			}

			// Raise the value by the power, multiply by the coefficient, and return the result
			return ( member_coefficient * Arithmetic::RaiseBaseByThePower< FloatingPoint64bits >( value, member_power ) ); 
		}




// *********************************************************************************   TESTING   ********************************************************************************



		//DEBUG_TOOL(

			void ExponentialVariable::Test()
			{
				// Create a tuple with the constraints
				Tuple< Range< FloatingPoint64bits > COMMA Range< FloatingPoint64bits > > constraintsTuple( Range< FloatingPoint64bits >( 1, 10000 ), Range< FloatingPoint64bits >( 1, 10 ) );

				// Perform a sanity to ensure that all the methods that are common among all objects, for example defualt constructor, copy constructor,
				// destructor, swap and more, seem to work correctly
				Testing::SanityCheck< ExponentialVariable COMMA Tuple< Range< FloatingPoint64bits > COMMA Range< FloatingPoint64bits > > COMMA FloatingPoint64bits COMMA FloatingPoint64bits >::Full( constraintsTuple );

				// Create a test instance
				ExponentialVariable testExponentialVariable_1( 45, 3 );

				// Check the results
				Assert_Test( testExponentialVariable_1.Value( 2 ) == 360 );
				Assert_Test( testExponentialVariable_1.Value( 1 ) == 45 );
				Assert_Test( testExponentialVariable_1.Value( 0 ) == 0 );
				Assert_Test( testExponentialVariable_1.Value( 10 ) == 45000 );

				// Create a test instance of signed nature
				ExponentialVariable testExponentialVariable_2( 2, 3 );

				// Check the results
				Assert_Test( testExponentialVariable_2.Value( 2 ) == 16 );
				Assert_Test( testExponentialVariable_2.Value( 1 ) == 2 );
				Assert_Test( testExponentialVariable_2.Value( 0 ) == 0 );
				Assert_Test( testExponentialVariable_2.Value( 10 ) == 2000 );
				Assert_Test( testExponentialVariable_2.Value( -1 ) == -2 );
				Assert_Test( testExponentialVariable_2.Value( -8 ) == -1024 ) ;
			}

	//)  //  End of debug tool



	}  //  Namespace Mathematics


}  //  Namespace Universe