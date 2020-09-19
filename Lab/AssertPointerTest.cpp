#include <iostream> 

#include "../../TheBottom/ErrorHandling/Exception/Exception.hpp"
#include "../../TheBottom/ErrorHandling/Assert/Assert.hpp"

using namespace std;
using namespace Universe;



int main()  
{

	try
    {

    	int* pp = 0;

    	AssertPointer_MACRO( pp, Monster::Klfkkl )

    }
	catch ( const ErrorHandling::Exception& rrxception )
    {
    	rrxception.TellMe();
    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}