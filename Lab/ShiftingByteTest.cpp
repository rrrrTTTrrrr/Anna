#include <iostream> 

#include "../../Utilities/BitsAndBytes/BitsAndBytes.hpp"


using namespace std;
using namespace Universe;

class Test
{
public:



private:

};  //  class Test

int main()  
{
	char tt = 63;

	BitsAndBytes::DisplayObjectBits( &tt, 1 );

	tt <<= 3;

	BitsAndBytes::DisplayObjectBits( &tt, 1 );

	tt >>= 3;

	BitsAndBytes::DisplayObjectBits( &tt, 1 );

	return ( 0 );
}