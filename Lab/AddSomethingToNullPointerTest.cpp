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

    	int* pointer = 0 ;

    	pointer += 56;


    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}