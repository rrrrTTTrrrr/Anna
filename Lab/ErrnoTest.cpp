#include <iostream> 

#include <errno.h> 
#include <string.h>

using namespace std;


class Test
{
public:



private:

};  //  class Test

void PrintErrno()
{
	cout << errno << endl;
}

int main() 
{
	errno = 8;

	PrintErrno();


	return ( 0 );
}
