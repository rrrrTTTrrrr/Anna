#include <iostream> 


using namespace std;

template< typename T >
class Test
{
public:

	Test() { cout << "Daaaa" << endl; }


	Test( T i ) { cout << i << "          MaaaaM" << endl; }

private:

};  //  class Test

int main()  
{

	try
    {

    	Test< long >( 8 );

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}