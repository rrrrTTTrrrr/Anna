#include <iostream> 


using namespace std;





class Test
{
public:

	Test( int yy ) : m_t( Get( yy ) ) { cout << m_t << endl; }

	int Get( int yy ) { m_t = yy + 1; }

private:

	int m_t;

};  //  class Test

int main()  
{

	try
    {

    	Test a( 8 );

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}