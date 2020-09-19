#include <iostream> 

#include <unistd.h>
#include  "../../Utilities/Exception/Exception.h"  //


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

		char* tt = new char[4096];

		getcwd( tt, 4096 );

		cout << tt << endl;



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