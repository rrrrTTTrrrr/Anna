#include <iostream> 


using namespace std;

class Test
{
public:
static const char* Display()
{
	std::cout << __FUNCTION__ << std::endl;

	return ( __FUNCTION__ );
}

const char* Display1()
{
	std::cout << __FUNCTION__ << std::endl;

	return ( __FUNCTION__ );
}

};

int main()  
{

	try
    {

    	Test::Display();

    	decltype( &Test::Display ) LOL = &Test::Display;

    	(*LOL)();

    	const char* mm = Test::Display();

    	cout << mm << endl;

    	Test t;

    	t.Display1();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}