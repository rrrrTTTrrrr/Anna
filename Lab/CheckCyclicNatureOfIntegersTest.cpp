#include <iostream> 

using namespace std;





int main()  
{

	try
    {

    	char tt = 0;

    	for ( int i = 0; i < 500 ; ++i )
    	{
    		tt += 1;

    		std::cout << (int)tt << std::endl;
    	}


    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}