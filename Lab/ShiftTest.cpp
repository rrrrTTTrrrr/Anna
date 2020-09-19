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

		int s = 1 << 2;

		cout << s << endl;

		int s1 = (char)1 << 8;
		
		cout << s1 << endl;

		int r = 1 << 15;

		char s2 = r;

		cout << s2 << endl;

		char t = ~0 << 2;

		cout << t << endl;

	}
	catch ( const exception& exception )
	{
		cout << exception.what() << endl;
	}


	return ( 0 );
}