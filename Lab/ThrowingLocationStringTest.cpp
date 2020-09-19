#include <iostream>
#include <string>

using namespace std;


void foo()
{
    	std::cout << __FILE__ << std::endl;
    	std::cout << __LINE__ << std::endl;
    	std::cout << __func__ << std::endl;	
}


int main()  
{

	try
    {

    	std::cout << __FILE__ << std::endl;
    	std::cout << __LINE__ << std::endl;
    	std::cout << __func__ << std::endl;


    	foo();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}