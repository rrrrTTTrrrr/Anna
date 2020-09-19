#include <iostream> 
#include <stdlib.h>


using namespace std;


int main()  
{

	try
    {

    	char* my = (char*)malloc( 0x7FFFFFFFFFFFFFFF );

    	cout << 0x7FFFFFFFFFFFFFFF << endl;

    	++my;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}