#include <iostream> 

using namespace std;


void Foo( int m, int u )
{
	++m;
	--u;

	std::cout << "Please let me like somebody" << std::endl;
}



int main()  
{

	try
    {

		using fp = void ()( int, int );

    	fp* mm = Foo;

    	(*mm)( 8,9 );

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}