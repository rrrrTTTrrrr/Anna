#include <iostream> 


#include  "../../Utilities/ErrorHandling/Exception.h"  //  Class Exception


using namespace std;
using namespace Universe;

template< typename T >
class Test
{
protected:

	class Proxy
	{
	public:

		Proxy( Test< T >& test, int index ) : m_test( test ), m_index( index ) {}

		Proxy( const Proxy& other ) : m_test( other.m_test ), m_index( other.m_index ) {}

		Test< T >& operator=( T value ) { m_test.m_t[m_index] = value; return m_test; }

	private:

		Test< T >& m_test;
		int m_index;
	};

public:


	Test( int yy ) : m_t( new T[yy] ) {}

	Proxy operator[]( int index ) { return( Proxy( *this, 8 ) ); }


private:

	T* m_t;

};  //  class Test


class Po : public Test< int >
{
public:

	Po( int yy ) : Test( yy ) {}

	void Display( int index ) { cout << m_t[index] << endl; }

};

int main()  
{

	try
	{


		Test< int > tt( 78 );

		tt[45] = 89;

		Po rr( 67 );

		rr[67] = 87;

		rr.Display( 67 );




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