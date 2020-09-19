#include <iostream> 


using namespace std;


int main()  
{

	try
    {

    	int a= 8;

    	a == 8 ? cout << "Lol" << endl : cout << "Why?" << endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}