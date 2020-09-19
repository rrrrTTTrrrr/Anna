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

    	double tt = 56;

    	std::cout << ( tt / 2 ) << std::endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}