#include <iostream>


using namespace std;


template< int T >
class Test
{
public:
	Test( long value ) { __asm__ volatile ( "MOV RAX, %[value]" : : [value] "ir" ( value ) : ); }
};


int main()
{
	cout << sizeof( Test< 8 > ) << endl;
	
	long y = 0;

	Test< 8 > t( 60L );

	__asm__ volatile ( "MOV %[y], RAX" : [y] "=ir" ( y ) :: "memory" );

	cout << y << endl;

	return ( 0 );
}