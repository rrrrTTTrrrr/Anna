#include <iostream> 


#include  "../../Utilities/ErrorHandling/Exception.h"  //  Class Exception
#include "InlineFunctionInDifferentSourceUnitAID.h"


using namespace std;
using namespace Universe;


int main()  
{

	try
	{


		Test< int > tt( 77 );

		Display( tt );


	}
	catch ( const Exception& exception )
	{
		exception.What();
	}
    catch ( const exception& exception )
	{
		cout << exception.what() << endl;
	}


	return ( 0 );
}