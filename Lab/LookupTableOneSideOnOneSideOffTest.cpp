#include <iostream> 


using namespace std;


int main()  
{
	// 2 BYTES

	cout << "2 BYTES" << endl;

	// All bits on above

	unsigned short mm = ~0;

	for ( int i = 0 ; i < 16 ; ++ i )
	{
		unsigned short rr = ~( 1 << i );
		mm &= rr;
		cout << mm << ",";
	}

	cout << endl;

	// All bits off above

	unsigned short mm1 = 1;

	for ( int i = 0 ; i < 16 ; ++ i )
	{
		unsigned short rr = ( 1 << i );
		mm1 |= rr;
		cout << mm1 << ",";
	}

	cout << endl;

	// All bits on above and including

	unsigned short mm2 = ~0;
	cout << mm2 << ",";

	for ( int i = 1 ; i < 16 ; ++ i )
	{
		unsigned short rr = ~( 1 << (i-1) );
		mm2 &= rr;
		cout << mm2 << ",";
	}

	cout << endl;

	// All bits off above and including

	unsigned short mm3 = 0;
	cout << mm3 << ",";

	for ( int i = 1 ; i < 16 ; ++ i )
	{
		unsigned short rr = ( 1 << (i-1) );
		mm3 |= rr;
		cout << mm3 << ",";
	}

	cout << endl << endl;

	// 4 BYTES

	cout << "4 BYTES" << endl;

	// All bits on above

	unsigned int mm4 = ~0;

	for ( int i = 0 ; i < 32 ; ++ i )
	{
		unsigned int rr = ~( 1 << i );
		mm4 &= rr;
		cout << mm4 << ",";
	}

	cout << endl;

	// All bits off above

	unsigned int mm5 = 1;

	for ( int i = 0 ; i < 32 ; ++ i )
	{
		unsigned int rr = ( 1 << i );
		mm5 |= rr;
		cout << mm5 << ",";
	}

	cout << endl;

	// All bits on above and including

	unsigned int mm6 = ~0;
	cout << mm6 << ",";

	for ( int i = 1 ; i < 32 ; ++ i )
	{
		unsigned int rr = ~( 1 << (i-1) );
		mm6 &= rr;
		cout << mm6 << ",";
	}

	cout << endl;

	// All bits off above and including

	unsigned int mm7 = 0;
	cout << mm7 << ",";

	for ( int i = 1 ; i < 32 ; ++ i )
	{
		unsigned int rr = ( 1 << (i-1) );
		mm7 |= rr;
		cout << mm7 << ",";
	}

	cout << endl << endl;

	// 8 BYTES

	cout << "8 BYTES" << endl;

	// All bits on above

	unsigned long mm8 = ~0;

	for ( int i = 0 ; i < 64 ; ++ i )
	{
		unsigned long rr = ~( 1UL << i );
		mm8 &= rr;
		cout << mm8 << "UL,";
	}

	cout << endl;

	// All bits off above

	unsigned long mm9 = 1;

	for ( int i = 0 ; i < 64 ; ++ i )
	{
		unsigned long rr = ( 1UL << i );
		mm9 |= rr;
		cout << mm9 << "UL,";
	}

	cout << endl;

	// All bits on above and including

	unsigned long mm10 = ~0;
	cout << mm10 << "UL,";

	for ( int i = 1 ; i < 64 ; ++ i )
	{
		unsigned long rr = ~( 1UL << (i-1) );
		mm10 &= rr;
		cout << mm10 << "UL,";
	}

	cout << endl;

	// All bits off above and including

	unsigned long mm11 = 0;
	cout << mm11 << "UL,";

	for ( int i = 1 ; i < 64 ; ++ i )
	{
		unsigned long rr = ( 1UL << (i-1) );
		mm11 |= rr;
		cout << mm11 << "UL,";
	}

	cout << endl;

    return ( 0 );
}