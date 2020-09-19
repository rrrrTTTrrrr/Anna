#include <iostream> 


using namespace std;

class Test
{
public:



private:

};  //  class Test

int main()  
{

	unsigned int ss = ~0;

	cout << ss << endl;

	ss = ss + 678;

	cout << ss << endl;

	cout << ( -8 % 6 ) << endl;

	int ss1 = 0x7FFFFFFF;

	cout << ss1 << endl;

	ss1 = ss1 + 1;

	cout << ss1 << endl;

	ss1 = ss1 + 1;

	cout << ss1 << endl;

	return ( 0 );
}