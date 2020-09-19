#include <iostream> 


using namespace std;
class Test
{
public:

	Test() : g(0), hh(0) {}


	int g;
	int hh;

};  //  class Test

int main()  
{

	try
    {

    	Test tt;

    	*((int*)&tt) = 8;
    	*(((int*)&tt) + 1 ) = 100;

    	std::cout << tt.g << "\n";
    	std::cout << tt.hh << "\n";
    	std::cout << sizeof( Test ) << "\n";

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}