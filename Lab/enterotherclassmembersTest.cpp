#include <iostream> 

using namespace std;


class Test
{
public:

	Test( int y ) : m_t( y ) {}
	Test( const Test& other ) : m_t( other.m_t ) {}

	void Print() { cout << m_t << endl; }

private:

	int m_t;

};  //  class Test




int main()  
{

	try
	{

		Test t( 12 );

		Test t1( t );

		t1.Print();



	}
	catch ( const int& exception )
	{

	}


		return ( 0 );
}
