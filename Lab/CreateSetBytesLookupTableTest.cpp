#include <iostream> 
#include "../../Utilities/ErrorHandling/Display/Display.hpp"
#include "../../Utilities/Encoding/Hexadecimal/Hexadecimal.hpp"

using namespace std;
using namespace Universe;

class Test
{
public:



private:

};  //  class Test

int main()  
{
	unsigned long tt1 = 0;

	for ( unsigned char tt = 0 ; tt < 255 ; ++tt )
	{
		tt1 = tt;

		for ( unsigned int rr  = 1 ; rr < 8 ; ++rr )
		{
			tt1 <<= 8;

			tt1 |= tt;
		}

		Encoding::Hexadecimal< unsigned long >( tt1 ).GetHexadecimalRepresentation().Display();

		cout << ",";

		if ( ( ( ( tt + 1 ) % 4 ) == 0 ) && ( tt != 0 ) )
		{
			cout << endl;
		}

		// ErrorHandling::Display::Bits( &tt1, 8 );
	}

	return ( 0 );
}