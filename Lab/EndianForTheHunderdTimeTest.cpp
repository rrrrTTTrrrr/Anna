#include <iostream> 

using namespace std;




int main()  
{

	try
    {

    	unsigned int ii = 42;

    	std::cout << *reinterpret_cast< unsigned char* >( &ii ) << std::endl;
    	std::cout << (int)*( reinterpret_cast< unsigned char* >( &ii ) + 3 ) << std::endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}