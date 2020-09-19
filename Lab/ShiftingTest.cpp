#include <iostream> 

#include "../../Utilities/BasicUtilities/BasicOperations/Bits/BitsOperations.h"


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

		unsigned char girl = 1;

		DisplayObjectBits( &girl, 1 );



	}
	catch ( const exception& exception )
	{
		cout << exception.what() << endl;
	}


	return ( 0 );
}