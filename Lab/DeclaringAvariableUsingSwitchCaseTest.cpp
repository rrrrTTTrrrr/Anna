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
    	int b = 1;

    	switch ( b )
    	{
    		case 1 :
    		{
    			int u = 9;
    			break;
    		}
    		default :
    			int sd = 11;
    	}

    	std::cout << u << std::endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}