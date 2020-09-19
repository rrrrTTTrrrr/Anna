#include <iostream> 

using namespace std;


void Print( int& r ) { cout << "Reference" << endl; }
void Print( int r ) { cout << "Copy" << endl; }

int main()  
{

	try
	{

		Print( 8 );

		int a = 8;

		Print( a );



	}
	catch ( const exception& exception )
	{
		cout << exception.what() << endl;
	}


	return ( 0 );
}
