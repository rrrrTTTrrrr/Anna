#include <iostream> 


#include  "../../Utilities/ErrorHandling/Exception.h"  //  Class Exception


using namespace std;
using namespace Universe;

class Test
{
public:

	Test( int yy ) : m_t( new int[yy] ) { Test gg( 3.2 ); }

	Test( double tt ) : m_t( new int[8] ) { cout << tt << endl; }

private:

	int* m_t;

};  //  class Test

int main()  
{



		Test tt( 7 );





	return ( 0 );
}