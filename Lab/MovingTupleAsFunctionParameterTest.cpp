#include <iostream> 
#include "../../Infrastructure/Abilities/Tuple/Tuple.hpp"

using namespace std;
using namespace Universe;

// template< typename... args >
// class Test
// {
// public:

// 	void Lol( const Abilities::Tuple< args... >& mm )
// 	{
// 		mm.Entry< 0 >() = 9;
// 	}

// private:

// };  //  class Test

template< typename... args >
void Lols( Abilities::Tuple<args...> ll )
{
	Abilities::Tuple< int > ll( 12 );
	ll.
	ll.Entry< 0 >() = 9;
}

int main()  
{

	try
    {

    	// Test< int > tt;

    	// tt.Lol( Abilities::Tuple< int >( 8 ) );

    	Lols< int >( Abilities::Tuple< int >( 8 ) );


    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}