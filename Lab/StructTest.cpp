#include <iostream> 

using namespace std;




typedef struct Test
{
public:

	Test() { cout << "Thxxxx" << endl; }

private:

}Test;  //  class Test

int main()  
{

	try
	{

		Test t;



	}
	catch ( const exception& exception )
	{
		cout << exception.what() << endl;
	}


	return ( 0 );
}