#include <iostream> 

using namespace std;




template< typename... args >
void Funion1( args... )
{
	std::cout << "Foooooo" << std::endl;
}

template< typename... args >
void Funion( args... rr )
{
	Funion1( rr... );
}





int main()  
{

	try
    {

    	Funion( 100, 89, 78, 45 );

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}