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

    	int yy = 34 * 89;

    	yy *= 345;

    	yy *= 45;

    	yy *= 455;

    	yy += yy;


    	int uu = numeric_limits< int >::max();

    	std::cout << numeric_limits< int >::max() << std::endl;
    	std::cout << numeric_limits< int >::min() << std::endl;

    	std::cout << yy << std::endl;
    	std::cout << uu << std::endl;


    	std::cout << ( -5 % -2 ) << std::endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}