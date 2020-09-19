#include <iostream> 



using namespace std;

class Test
{
public:



private:

};  //  class Test

int main()  
{

	// const on regular variable :

	// const int tt = 8;

	// tt = 9;

	// const and pointers :

	int tt = 9;

	int tt1 = 10;

	const int* ptt = &tt;

	cout << *ptt << endl;

	ptt = &tt1;

	cout << *ptt << endl;

	// *ptt = 34;

	int* const ptt1 = &tt;

	// ptt1 = &tt1;

	*ptt1 = 87;

	return ( 0 );
}