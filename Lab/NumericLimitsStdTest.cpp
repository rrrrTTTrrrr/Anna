#include <iostream> 
#include <limits>

using namespace std;


class Test
{
public:



private:

};  //  class Test



int main()  
{

	try
    {

    	std::cout << std::numeric_limits< bool >::lowest() << std::endl;

    	std::cout << std::numeric_limits< long >::min() << std::endl;
    	std::cout << std::numeric_limits< long >::max() << std::endl;

    	std::cout << sizeof( long ) << std::endl;

    	long oo = 9223372036854775807;

    	std::cout << oo << std::endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}