#include <iostream> 


#include  "../../Utilities/ErrorHandling/Exception.h"  //  Class Exception


using namespace std;
using namespace Universe;

template< typename T >
class Test
{
private:

		class Proxy;
public:


	Test() : mt( new T[34] ) { cout << "Test COnstructor" << endl; }

	Proxy operator[]( T y ) { return ( Proxy( *this, y ) ); }

private:

	T* mt;

	void COpyOnWrite() { cout << "Fuck this world" << endl; }

	class Proxy
	{
	public:

		Proxy( Test< T >& t, T y ) : yy( y ), tt( t ) { cout << "Proxy constructor" << endl; }

		Test< T >& operator=( T u ) { tt.COpyOnWrite(); tt.mt[yy] = u; cout << tt.mt[yy] << endl; return tt; }

		Proxy( const Proxy& other ) : yy( other.yy ), tt( other.tt ) {}

		Proxy& operator=( const Proxy& other ) { yy = other.yy; tt = other.tt; }

	private:

		T yy;

		Test< T >& tt;
	};

};  //  class Test

int main()  
{

	try
	{


		Test< int > tt;

		tt[5] = 67;


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