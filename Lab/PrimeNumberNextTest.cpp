#include <iostream> 

using namespace std;


unsigned long Next( unsigned long primeNumber )
{
	// This object will store the next prime number
	unsigned long nextPrimeNumber = primeNumber + 2UL;

	// This object will store the current number that should be divide by the number checked if its a prime number
	unsigned long divider = 3UL;

	// This object will store half of the prime number candidate value, this will be used to stop the loop, because the last number that needs to be checked
	// is the number before it
	unsigned long limit = ( nextPrimeNumber / 3UL ) + 1UL;

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
		for ( divider = 3UL ; divider <= limit ; divider += 2UL )
		{

			// Check if the current prime number candidate divides with no raminder
			if ( ( nextPrimeNumber % divider ) == 0UL )
			{
				// The prime number candidate divides with no ramainder by the divider

				// The current candidate is not a prime number, break the loop
				break;
			}

		}

		// Check the reason that the inner loop ended
		if ( divider >= limit )
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



int main()  
{

	try
    {

    	std::cout << "Lord" << std::endl;

    	unsigned long nn = 47;
    	// unsigned long numberOf = 0;

    	for ( int i = 0 ; i < 100000 ; ++i )
    	{
    		nn = Next( nn );

    		std::cout << nn << std::endl;
    	}

    	// while ( nn < 1000000 )
    	// {
    	// 	nn = Next( nn );

    	// 	++numberOf;
    	// }

    	// std::cout << numberOf << std::endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}