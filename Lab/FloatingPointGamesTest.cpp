#include <iostream> 

using namespace std;


class Test
{
public:



private:

};  //  class Test



int main()  
{

	try
    {

    	double yy = -89.0001;

    	std::cout << ( yy == 89.0001 ) << std::endl;

    	for ( long unsigned int i = ( sizeof( double ) * 8 - 1 ) ; i > 0 ; --i )
    	{
    		if ( (long unsigned int)yy & (1 << i) )
    		{
    			std::cout << "1 ";
    		}
    		else
    		{
    			std::cout << "0 ";    			
    		}
    	}

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}