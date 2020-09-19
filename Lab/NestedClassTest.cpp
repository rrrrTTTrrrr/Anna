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

	explicit inline Test( int size );

	inline TestProxy operator[]( int index );


private:

	T* m_t;

	class TestProxy
	{
	public:

		explicit inline TestProxy( Test< T >& test, int index );

		inline Test< T >& operator=( T other );


	private:

		Test< T >& m_test;
		int m_index;

		
	};  //  class Test

};  //  class Test


template< typename T >
inline Test< T >::Test(int size  ): m_t( new T[ size ] )
{}

template< typename T >
inline typename Test< T >::TestProxy Test< T >::operator[]( int index ) 
{ return ( TestProxy( *this, index ) ); }


template< typename T >
inline Test< T >::TestProxy::TestProxy( Test< T >& test, int index ) : m_test( test ), m_index( index ) { cout << "Constructed" << endl; }

template< typename T >
inline Test< T >& Test< T >::TestProxy::operator=( T other ) { m_test.m_t[m_index] = other; return m_test; }

int main()  
{

	try
	{


		Test< int > tt( 89 );

		tt[44] = 67;


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