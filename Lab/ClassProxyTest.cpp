#include <iostream> 


#include  "../../Utilities/ErrorHandling/Exception.h"  //  Class Exception


using namespace std;
using namespace Universe;


class Test
{
private:

	int* m_tt;

	class TestProxy
	{
	public:

		TestProxy( Test& test, unsigned int yy ) : m_test( test ), m_yy( yy ) { cout << "TestProxy constructor" << endl; }

		void dis() { m_test.Display(); }

		Test& operator+=( int rho ) { m_test.m_tt[6] = rho; return m_test; }

	private:

		Test& m_test;

		unsigned int m_yy;
	};

public:

	Test( int tt ) : m_tt( new int[tt] ) { cout << "Test constructor" << endl; }

	~Test() { delete[] m_tt; cout << "Test destructor" << endl; }

	void Display() const { cout << "Test Test Test" << endl; }

	TestProxy operator[]( unsigned int yy ) { return ( TestProxy( *this, 34 ) );  }



};  //  class Test

int main()  
{

	try
	{

		Test nn( 54 );

		nn[32] += 34;


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