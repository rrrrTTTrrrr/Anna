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

    	int pp = 89;

    	int* oo = &pp;

    	int*& dd = oo;

    	std::cout << dd << std::endl;

    	*dd = 44;

    	std::cout << *dd << std::endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}