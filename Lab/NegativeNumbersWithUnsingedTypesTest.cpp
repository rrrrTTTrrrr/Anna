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

		unsigned char st = 8;

		if ( ( st - 9 ) < 0 )
		{
			cout << "Works" << endl;
		}

		unsigned char st1 = st - 9;

		if ( 0 == st1 )
		{
			cout << "Yeahhhh" << endl;
		}

		cout << ( -1 % 3 ) << endl;

		unsigned int yy = (unsigned int)0 - (unsigned int)1;

		cout << yy << endl;

	}
	catch ( const exception& exception )
	{
		cout << exception.what() << endl;
	}


	return ( 0 );
}