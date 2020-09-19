#include <iostream> 

using namespace std;


class Test
{
public:

	Test() { std::cout << mm << std::endl; }

	void DIs() { std::cout << mm << std::endl; }

private:

	static int mm;

};  //  class Test

int Test::mm = 89;

int main()  
{

	try
    {

    	Test kk;

    	kk.DIs();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}