#include <iostream> 


using namespace std;





int main()  
{

	try
    {

    	wind gg = 9;

    	std::cout << gg << std::endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}