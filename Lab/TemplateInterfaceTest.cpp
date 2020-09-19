#include <iostream> 


#include "../../Utilities/ErrorHandling/Exception/Exception.hpp"


using namespace std;
using namespace Universe;

template< typename T >
class Test
{
public:

	static void Fuck( const char* g );


private:

};  //  class Test


template< typename T >
void Test< T >::Fuck( const char* g )
{
	throw( T( g ) );
}

int main()  
{

	try
	{

		Test< ErrorHandling::Exception >::Fuck( "Lorddddddddd" );

  	}
	catch ( const ErrorHandling::Exception& exception )
	{
		exception.What();
	}
	catch ( const exception& stdException )
	{
		cout << stdException.what() << endl;
	}

	return ( 0 );
}