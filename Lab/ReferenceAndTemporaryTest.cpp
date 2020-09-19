#include <iostream> 


using namespace std;
class Test
{
public:

	Test() {}

	~Test() {}

	void Display() const { cout << "Noooooo" << endl; }

private:

};  //  class Test


void Funcf( const Test& test )
{
	test.Display();
}

int main()  
{

	try
    {

    	Funcf( Test() );

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}