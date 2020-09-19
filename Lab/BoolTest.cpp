#include <iostream> 


using namespace std;


int main()  
{
	bool a = false;
	unsigned char b = 1;
	for ( int i = 7 ; i > -1 ; --i )
	{
		if ( ( a << i ) & b )
		{
			cout << "1" << " ";
		}
		else
		{
			cout << "0" << " ";
		}

	}

	return ( 0 );
}