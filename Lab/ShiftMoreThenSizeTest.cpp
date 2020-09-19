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

		char tt = 67;

		tt <<= 66;



	}
	catch ( const exception& exception )
	{
		cout << exception.what() << endl;
	}


	return ( 0 );
}