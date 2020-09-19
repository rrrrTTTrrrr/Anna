#include <iostream> 

using namespace std;


class Test
{
public:

	Test() : m( new int(8) ) {}

	Test( int y ) : Test() { throw( exception() ); *m = y; }

	~Test() { if ( m != nullptr ) { delete m; } std::cout << "Lol" << std::endl; }

private:

	int* m;

};  //  class Test



int main()  
{

	try
    {

    	Test( 45 );

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}