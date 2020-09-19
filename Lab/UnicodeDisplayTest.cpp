#include <iostream> 

#include "../../Utilities/Exception/Exception.h"  //


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
		unsigned int dd = 56;

		cout << dd << endl;

		


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