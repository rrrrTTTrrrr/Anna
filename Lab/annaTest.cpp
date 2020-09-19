#include <iostream> 


int dudu( int a, int b, int c )
{
	if ( ( a > b ) && ( a > c ) )
	{
		return ( a );
	}
	else if ( ( b > c ) && ( b > a ) )
	{
		return ( b );
	}

	return ( c );
}

int ana( int a, int b ) 
{
	return ( a+b );
}


int main()  
{
	int a = 8;
	int b = 9;
	int c = 11;


	std::cout << dudu( a, b, c ) << std::endl;
    std::cout << ana( a, b ) << std::endl;

	return ( 0 );

}