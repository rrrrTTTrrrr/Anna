#include <iostream> 

using namespace std;


	constexpr unsigned long GigaByte( unsigned long SizeInGigaByte )
	{
		// To convert between MegaBytes to single bytes the following method is used :
		//
		//		GigaByte = 1024 MegaByte = ( 1024 * 1024 ) KiloByte = ( 1024 * 1024 * 1024 ) Bytes
		//
		// Then,
		//
		//		6 GigaByte = 6 * ( 1024 * 1024 * 1024 ) Bytes

		// Multiply the given size in GigaByte by 1024 three times, and return the result
		return ( SizeInGigaByte * ( 1024UL * 1024UL * 1024UL ) );
	}

int main()  
{

	try
    {

    	// int jj = 9;

    	// int* pp = &jj;


    	std::cout << (( 43 + 7 ) & ~7) << std::endl;
    	std::cout << (43 & ~7) << std::endl;
    	std::cout << (55 & ~7) << std::endl;
    	std::cout << (21 & ~7) << std::endl;
    	std::cout << (127 & ~7) << std::endl;
    	std::cout << (88 & ~7) << std::endl;
    	std::cout << (44 & ~7) << std::endl;

    	int m = 45;

    	std::cout << GigaByte( 34 ) << std::endl;
    	std::cout << GigaByte( m ) << std::endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}


//00101011


