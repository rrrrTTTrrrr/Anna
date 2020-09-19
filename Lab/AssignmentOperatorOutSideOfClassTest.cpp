#include <iostream> 


#include  "../../Utilities/ErrorHandling/Exception.h"  //  Class Exception


using namespace std;
using namespace Universe;

class Test
{
public:

	Test( int ff ) : m_t( ff ) {}

private:


	int m_t;

	friend int& operator=( int& mm, const Test& lf );


};  //  class Test


int& operator=( int& mm, const Test& lf )
{
	mm = lf.m_t;

	return ( mm );
}


int main()  
{

	try
	{

		Test oo( 78 );

		int r = 67;

		r = oo;



	}
	catch ( const Exception& exception )
	{
		exception.What();
	}
    catch ( const exception& exception )
	{
		cout << exception.what() << endl;
	}


	return ( 0 );
}