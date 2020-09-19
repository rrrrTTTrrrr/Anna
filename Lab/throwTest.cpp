#include <iostream> 


#include "../Utilities/ErrorHandling/Exception.h"


using namespace std;
using namespace Universe;


class Test
{
public:



private:

};  //  class Test

int main()  
{

	try
	{


		throw ( Exception( CreateErrorMessage( "File constructor failed" ) ) );


	}
	catch ( const Exception& exception )
	{
		cout << exception.What() << endl;
	}


		return ( 0 );
}
