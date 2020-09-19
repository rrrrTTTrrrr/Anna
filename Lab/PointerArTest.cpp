#include <iostream> 


using namespace std;



int main()  
{
	int d = 0;

	int d1 = 3;

	d1 += 1; 

	int* dd = &d;
	// int* dd1 = &d1;

	dd += 1;

	cout << dd << endl;

	dd = reinterpret_cast< int* >( 0x828a345678 );

	dd[-1] = 8;


	return ( 0 );
}