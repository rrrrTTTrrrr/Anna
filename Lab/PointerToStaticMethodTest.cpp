#include <iostream> 

using namespace std;


class Test
{
public:

	static void Display() { std::cout << "Lorddd" << std::endl; }

private:

};  //  class Test



int main()  
{

	try
    {

    	void (*ff)() = &Test::Display;

    	(*ff)();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}