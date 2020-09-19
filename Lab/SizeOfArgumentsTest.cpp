#include <iostream> 


using namespace std;

template< int... args >
void Funcy()
{
	cout << sizeof...( args ) << endl;
}

int main()  
{

	try
    {

    	Funcy< 1,2,3,4,5,6,7,8,8 >();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}