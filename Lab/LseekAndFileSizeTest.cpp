#include <iostream> 
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
 


using namespace std;


class Test
{
public:



private:

};  //  class Test

int main()  
{
	int fd = open( "NewFile.cpp", O_RDONLY, S_IRWXU );

	if ( -1 == fd )
	{
		perror( "Fuckkkk" );

		return 1;
	}

	cout << lseek( fd, 0, SEEK_END ) << endl;



	return ( 0 );
}