#include <iostream> 

using namespace std;


#define mm "ArrayOf"



#include "mmAsciiStringsTest.cpp"


int main()  
{

	try
    {

    	std::cout << mm "My name is " << std::endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}