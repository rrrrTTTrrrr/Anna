#include <iostream> 

using namespace std;




int main()  
{

	try
    {

    	float ii = 0;

    	float uu = std::numeric_limits< float >::max();

    	while ( uu > std::numeric_limits< unsigned long >::max() )
    	{
    		uu -= std::numeric_limits< unsigned long >::max();

    	std::cout <<  ii << std::endl;

    		++ii;
    	}






    	// double ppp = 0;

    	// std::cout << (double)( ppp - 1) << std::endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}