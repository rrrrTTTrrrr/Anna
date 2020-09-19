#include <iostream> 
#include <unistd.h>
#include <fcntl.h>

using namespace std;




int main()  
{

	try
	{

		int in = 0;

		int fd = open( "ErrnoTest.cpp", O_RDWR );

		read( fd, &in, 1 );

		cout << (char)in << endl;



	}
	catch ( const exception& exception )
	{
		cout << exception.what() << endl;
	}


	return ( 0 );
}
