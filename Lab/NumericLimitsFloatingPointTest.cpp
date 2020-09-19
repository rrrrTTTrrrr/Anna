#include <iostream> 

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

    	std::cout << std::numeric_limits< float >::min() << std::endl;
    	std::cout << std::numeric_limits< float >::max() << std::endl;

    	std::cout << std::numeric_limits< double >::min() << std::endl;
    	std::cout << std::numeric_limits< double >::max() << std::endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}