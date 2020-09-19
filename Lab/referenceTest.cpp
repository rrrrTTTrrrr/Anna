#include <iostream> 

using namespace std;


int* aaa;


void Print( int& ac )
{
	aaa[7] = ac;
}

int main()  
{

	try
	{
		aaa = new int[28];

		Print( 85 );

		cout << aaa[7] << endl;


	}
	catch ( const Exception& exception )
	{
		cout << exception.What() << endl;
	}


		return ( 0 );
}
