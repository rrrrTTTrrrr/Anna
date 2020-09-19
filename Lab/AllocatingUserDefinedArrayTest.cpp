#include <iostream> 


using namespace std;
class Test
{
public:

	Test() { cout << "Jissus" << endl; }

private:

};  //  class Test

int main()  
{

	try
    {

    	Test* m = new Test[5];

    	++m;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}