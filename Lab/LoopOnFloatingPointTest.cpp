#include <iostream> 

using namespace std;





int main()  
{

	try
    {

  //   	double limit = 0.756454234;
		// double number = 1;

  //   	for ( int i = 0 ; i < 10 ; ++i )
  //   	{
  //   		number /= 10;

	    	// for ( double number = 0.000000000001 ; number < 0.1 ; number += 0.000000000001 )
	    	// {
	    	// 	std::cout << number << std::endl;
	    	// }

    		double kk = 3.0;

    		kk -= 4.0;

    		std::cout << kk << std::endl;
    		std::cout << ( kk * -1 ) << std::endl;

	    // }

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}