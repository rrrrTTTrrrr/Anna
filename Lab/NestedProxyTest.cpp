#include <iostream> 


#include  "../../Utilities/ErrorHandling/Exception.h"  //  Class Exception


using namespace std;
using namespace Universe;

template< typename T >
class Test
{
private:

		class TestProxy;
public:

	Test( int yy ) : m_a( new T[yy] ) {}

	Test::TestProxy operator[]( unsigned int yy ) { return ( TestProxy( *this, yy ) ); }

private:

	T* m_a;

	class TestProxy
	{
	public:

		TestProxy( Test< T >& test, unsigned int yy ) : m_object( test ), m_entry( yy ) {}

		void operator=( T un ) { if ( un != m_object.m_a[ m_entry ] ) { cout << "Yeah" << endl; } }

	private:

		Test< T >& m_object;

		unsigned int m_entry;
	};

};  //  class Test

int main()  
{

	try
	{


		Test< int > tt( 9 );

		tt[4] = 67;


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