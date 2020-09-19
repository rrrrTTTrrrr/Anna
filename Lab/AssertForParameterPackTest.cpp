#include <iostream> 

#include "../Root/Content/Metaprogramming/CommonFunctionality/AssertAllTrue/AssertAllTrue.hpp" 

using namespace std;
using namespace Universe;


template< typename... Args >
class Test
{
public:

	void Dis() { std::cout << AssertAllTrue< is_integral< Args >::value... >::Value() << std::endl; }

private:

};  //  class Test



int main()  
{

	try
    {

    	Test< int, std::string > uu;

    	uu.Dis();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}