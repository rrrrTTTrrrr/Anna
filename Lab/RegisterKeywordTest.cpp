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

		register int dd = 9;

		std::cout << dd << "\n";

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}