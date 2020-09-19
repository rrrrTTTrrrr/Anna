#include <iostream> 


#include  "../../Utilities/ErrorHandling/Exception.h"  //  Class Exception


using namespace std;
using namespace Universe;

template< typename T >
class Test
{
public:

	Test( T m ) : m_t( m ) {}

	template< typename O >
	friend O operator+=( O& lso, Test< O >& rso );

private:

	T m_t;

};  //  class Test

template< typename T >
T operator+=( T& lso, Test< T >& rso )
{
	lso += rso.m_t;

	return ( lso );
}

int main()  
{

	try
	{


		Test< int > tt( 78 );

		int y = 9;

		y += tt;

		cout << y << endl;


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