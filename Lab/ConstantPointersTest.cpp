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

    	int u = 8;

    	int* const ii = &u;
    	int const*  ii1 = &u;

    	++ii;
    	++ii1;


    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}