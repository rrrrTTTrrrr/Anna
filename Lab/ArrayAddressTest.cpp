#include <stdio.h> 



int main()  
{
	int x[] = {1,2};

	int *p = &x[1];

	if ( ( p -1 ) == x )
	{
		printf( "Losssssserr" );
	}


    return ( 0 );
}