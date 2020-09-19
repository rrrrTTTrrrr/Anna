#include <iostream> 

using namespace std;


template< typename T >
class Test
{
public:

	template< typename... Args >
	Test( Args... rr ) { DIs( rr... ); }

	void DIs( int kk, double ll ) { std::cout << kk << std::endl; std::cout << ll << std::endl;  }

private:


};  //  class Test



int main()  
{

	try
    {

    	Test< int > rr( 5, 88.12 );

    	rr.DIs( 8, 9 );

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}