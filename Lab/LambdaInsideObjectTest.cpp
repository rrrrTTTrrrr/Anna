#include <iostream> 

using namespace std;


class Test
{
public:

	void Lambddd( bool (*ff)( int t ) ) { ff( 89 ); }

	void fGEEE() { int tt = 0; Lambddd( [tt]( int u ) -> bool { std::cout << u << std::endl;  return( true); } ); std::cout << tt << std::endl; }


private:

};  //  class Test



int main()  
{

	try
    {

    	Test tt;

    	tt.fGEEE();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}