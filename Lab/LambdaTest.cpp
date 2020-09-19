#include <iostream> 


using namespace std;
class Test
{
public:

	Test( void (*pp)( int* mm ) ) { (*pp)( &jj ); }

private:

	int jj;

};  //  class Test

int main()  
{

	try
    {

    	Test mm( []( int* pp ) { std::cout << *pp << std::endl; } );

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}