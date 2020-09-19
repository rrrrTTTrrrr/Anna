#include <functional>
#include <iostream> 

using namespace std;

void lol( int a, double yy )
{
	cout << a << " " << yy << endl;
}

int main()  
{

	try
    {

    	std::invoke( lol, 9, 9.8 );

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}