#include <iostream> 

#include <unistd.h>


using namespace std;


int main()  
{

	try
    {

    	char buffer[100] = {0};

    	cout << read( 0, buffer, 1 ) << endl;

    	cout << buffer << endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}