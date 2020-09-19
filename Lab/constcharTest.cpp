#include <iostream> 

using namespace std;


class Test
{
public:



private:

};  //  class Test


const char* Print()
{
	return ( "Lord almighty" );
}

int main()  
{

	const char* e = Print();

	cout << e << endl;



	try
	{





	}
	catch ( const exception& exception )
	{
		cout << exception.what() << endl;
	}


	return ( 0 );
}
