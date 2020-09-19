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
		unsigned char c = 15;

		cout << ( c & (char)0xF0) << endl;

		cout << ( c & (char)0x0F) << endl;




	}
	catch ( const exception& exception )
	{
		cout << exception.what() << endl;
	}


	return ( 0 );
}