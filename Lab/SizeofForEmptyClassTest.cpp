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

    	std::cout << sizeof( Test ) << std::endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}