#include <iostream> 
#include <unistd.h>
#include <dirent.h>


using namespace std;


class Test
{
public:



private:

};  //  class Test

int main()  
{


	DIR* dd = opendir( "/home/david/Documents" );

	char buffer[256] = {0};

	getcwd( buffer, 256 );

	cout << buffer << endl;




	return ( 0 );
}