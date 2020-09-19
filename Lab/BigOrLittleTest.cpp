#include <iostream> 


#include "../../Utilities/BasicUtilities/cpp_BasicUtilities.h"

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

		cout << LittleOrBigEndian() << endl;



	}
	catch ( const exception& exception )
	{
		cout << exception.what() << endl;
	}


	return ( 0 );
}