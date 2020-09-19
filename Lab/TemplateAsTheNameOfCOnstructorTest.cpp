#include <iostream> 


using namespace std;

template< typename T >
class Test
{
public:

	T() { cout << "Yeah" << endl; }

private:

};  //  class Test

class tOT
{
	
};

int main()  
{

	try
    {




    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}