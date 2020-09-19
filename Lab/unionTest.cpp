#include <iostream> 

using namespace std;


class Test
{
public:



private:

};  //  class Test


union ss
{
	int s;
	int d;
};


int main()  
{

	try
	{

		union ss r;

		r.s = 8;

		cout << r.s << endl;

		r.d = 10;

		cout << r.d << endl;

		
		cout << r.s << endl;


	}
	catch ( const exception& exception )
	{
		cout << exception.what() << endl;
	}


	return ( 0 );
}
