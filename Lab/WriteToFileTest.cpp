#include <iostream> 
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>


#include  "../../Utilities/ErrorHandling/Exception.h"  //  Class Exception


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
		int amount = 0;

		int fd = open( "Loser.cpp", O_RDWR | O_CREAT, S_IRWXU );

		if ( -1 == fd )
		{
			perror( "Fuck :" );
		}

		char buffer[1024] = {0};

		amount = write( fd, "It fuckc fucked fucked", 22 );

		if ( 22 != amount )
		{
			perror( "Fuckkkkk :" );
		}

		lseek( fd, 0, SEEK_SET );

		read( fd, buffer, 22 );

		cout << buffer << endl;

		close( fd );

		fd = open( "Loser.cpp", O_RDWR | O_TRUNC );

		amount = write( fd, "It fuckc fucked fuckedKKKK", 26 );

		if ( 26 != amount )
		{
			perror( "Fuckkkkk :" );
		}

		lseek( fd, 0, SEEK_SET );

		read( fd, buffer, 26 );

		cout << buffer << endl;


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