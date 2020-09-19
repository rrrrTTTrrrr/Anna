#include <iostream> 

#include "../../Utilities/Exception/Exception.h"  
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

		char ss = 3;

		unsigned char tt = 0;

		tt |= ss;

		DisplayObjectBits( &tt, 1 );

		short yy = 0;

		yy |= ss;

		DisplayObjectBits( &yy, 2 );




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