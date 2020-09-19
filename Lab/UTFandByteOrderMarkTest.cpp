#include <iostream> 
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

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
		int fd = open( "gggg.cpp", O_RDONLY );

		if ( -1 == fd )
		{
			perror( "Open failed - " );
		}

		char buffer[128] = {0};

		int tt = read( fd, buffer, 128 );

		cout << tt << endl;

		DisplayObjectBits( buffer, tt );

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