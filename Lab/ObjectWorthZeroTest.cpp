#include <iostream> 

using namespace std;


class Test
{
public:

	Test() { cout << "WOOOOOOW" << endl; }

private:

};  //  class Test

int main()  
{

	try
	{

		Test t = 0;



	}
	catch ( const exception& exception )
	{
		cout << exception.what() << endl;
	}


	return ( 0 );
}
