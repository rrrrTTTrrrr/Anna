#include <iostream> 
#include <typeinfo>

using namespace std;




class TestHKLMSDKMKDnndkck
{
	TestHKLMSDKMKDnndkck( int m ) : m_t( m ) {}

	int m_t;
};


int main()  
{

	int x = 0;

	cout << typeid( x ).name() << endl;  // result - i

	unsigned int x1 = 0;

	cout << typeid( x1 ).name() << endl;  // result - j

	char x2 = 0;

	cout << typeid( x2 ).name() << endl;  // result - c

	unsigned char x3 = 0;

	cout << typeid( x3 ).name() << endl;  // result - h

	short x4 = 0;

	cout << typeid( x4 ).name() << endl;  // result - s

	unsigned short x5 = 0;

	cout << typeid( x5 ).name() << endl;  // result - t

	double x6 = 0;

	cout << typeid( x6 ).name() << endl;  // result - d

	long double x7 = 0;

	cout << typeid( x7 ).name() << endl;  // result - e

	long x8 = ~0;

	cout << typeid( x8 ).name() << endl;  // result - l

	long long x9 = ~0;

	cout << typeid( x9 ).name() << endl;  // result - x

	unsigned long x11 = ~0;

	cout << typeid( x11 ).name() << endl;  // result - m

	unsigned long long x13 = ~0;

	cout << typeid( x13 ).name() << endl;  // result - y

	float x12 = 0;

	cout << typeid( x12 ).name() << endl;  // result - f

	// TestHKLMSDKMKDnndkck m( 1 );

	cout << typeid( TestHKLMSDKMKDnndkck ).name() << endl;  // result - 20TestHKLMSDKMKDnndkck - the length and then the name

	cout << sizeof( long long ) << endl;

	cout << x11 << endl;

	cout << x13 << endl;


	return ( 0 );
}