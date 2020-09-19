#include <iostream> 
#include "../Abilities/Tuple/Tuple.hpp"

using namespace std;

template< int N, int... I >
class Test : public Test< N - 1, N - 1, I... >
{
public:
	Test() { std::cout << ( N - 1 ) << std::endl; }

	int Size() { return N; }

};  //  class Test

template< int... I >
class Test< 0, I... >
{
public:
		Test() { std::cout << 0 << std::endl; }
};  //  class Test


void ror( int y, long s )
{
    cout << ++y << " " << ++s << endl;
}



int main()  
{

	try
    {

    	Test< 3 > m;

    	// Test< 3 > y = m;

    	// std::cout << m.Size() << endl;

    	// std::cout << y.Size() << endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}