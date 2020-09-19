#include <iostream> 

using namespace std;


void Foo( int& yy )
{
	std::cout << yy << std::endl;
}


int main()  
{

	try
    {

    	Foo( 89 );

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}