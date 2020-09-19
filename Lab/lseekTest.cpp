#include <iostream> 
       #include <sys/types.h>
       #include <unistd.h>
	#include <fcntl.h>
using namespace std;


class Test
{
public:



private:

};  //  class Test

int main()  
{

	try
	{

		int fd = open( "dudi.txt", O_RDONLY );

		int size = lseek( fd, 0, SEEK_END );

		cout << size << endl;
		
	}
	catch ( const exception& exception )
	{
		cout << exception.what() << endl;
	}


	return ( 0 );
}
