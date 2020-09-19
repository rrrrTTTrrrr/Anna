#include <iostream> 

using namespace std;


class Test
{
public:



private:

};  //  class Test



int main()  
{

	try
    {

    	for ( char i = 0 ; i < 127 ; ++i )
    	{
    		cout << (int)i << "  -  " << i << endl;
    	}

    	cout << (int)127 << "  -  " << (char)127 << endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}