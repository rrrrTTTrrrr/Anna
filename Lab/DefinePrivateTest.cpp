#include <iostream> 


using namespace std;
class Test
{
public:

	static void Display() { cout << Lord << endl; }

private:

	#define Lord Amigoooooooooooooo

};  //  class Test

int main()  
{

	try
    {

    	Test::Display();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}