#include <iostream> 

#include "../Root/Content/Metaprogramming/MetaprogrammingMacros/MetaprogrammingMacros.hpp"

using namespace std;
using namespace Universe;


class Test
{
public:

	void Lo() {}

private:

};  //  class Test



int main()  
{

	try
    {

    	Test mm = MOVE( Test() );

    	mm.Lo();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}