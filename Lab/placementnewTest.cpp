#include <iostream> 
#include <new>

using namespace std;


class Test
{
public:

	Test( int s ) : m_a(s) {}

	void Print() { cout << m_a << endl; }

private:
	int m_a;

};  //  class Test

int main()  
{

	try
	{

		char* s = new char[4];

		Test* t = new( s ) Test( 8 ); 

		t->Print();

		cout << (int)*s << endl;

	}
	catch ( const exception& exception )
	{
		cout << exception.what() << endl;
	}


	return ( 0 );
}
