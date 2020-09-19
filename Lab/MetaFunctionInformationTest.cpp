#include <iostream> 

using namespace std;



void Foo()
{

	cout << __FUNCTION__ << endl;
	cout << __PRETTY_FUNCTION__ << endl;
}



int main()  
{

	try
    {

    	Foo();


    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}