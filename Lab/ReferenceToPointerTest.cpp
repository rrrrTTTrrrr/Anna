#include <iostream> 

using namespace std;


class Test
{
public:



private:

};  //  class Test


void Display( const char*& str )
{
	cout << *str << endl;

	str = "Fuck";

	const char* str2 = str;
}


int main()  
{

	try
    {

    	const char* str = "Mother";

    	Display( str );

    	cout << str << endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}