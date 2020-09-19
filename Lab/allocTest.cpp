#include <iostream> 

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

		char* ptr = new char[1024000000 * 3];

		++ptr;

	}
	catch ( const exception& exception )
	{
		cout << exception.what() << endl;
	}


	return ( 0 );
}
