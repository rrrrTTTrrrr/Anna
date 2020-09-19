#include <iostream> 

using namespace std;


struct Test
{




	char g_file[];

};  //  class Test



int main()  
{

	try
    {

    	Test kk;

    	kk.g_file[0] = 'h';

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}