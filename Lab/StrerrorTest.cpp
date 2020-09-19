#include <iostream> 


#include <errno.h>
#include <cstring>  //  Function strerror

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

		errno = 7;

		char* rr = strerror( errno );

		cout << rr << endl;

	}
	catch ( const exception& exception )
	{
		cout << exception.what() << endl;
	}


	return ( 0 );
}