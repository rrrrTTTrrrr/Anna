#include <iostream> 
#include "../Root/Content/Metaprogramming/Move/Move.hpp"

using namespace std;
using namespace Universe;



class Test
{
public:

	Test() { std::cout << "WOw" << std::endl; }

	Test( const Test& ) { std::cout << "WOwrrrrrr" << std::endl; }

	Test( Test&& other ) { other.Look(); std::cout << "Koer" << std::endl; }

	void Look() {}

private:

};  //  class Test



int main()  
{

	try
    {

    	Test oo;

    	Test& yy = oo;

    	Test gg = MOVE( yy );

    	gg.Look();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}