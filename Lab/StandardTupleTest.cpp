#include <tuple>
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

    	//int jj = 90;

    	std::tuple< int > yy;

    	std::cout << std::get< 0 >( yy ) << std::endl;


    	const int&& uu = int();

    	std::cout << uu << std::endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}