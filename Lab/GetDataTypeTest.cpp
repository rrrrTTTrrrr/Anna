#include <iostream> 
#include <stdio.h>

using namespace std;

/* Get the name of a type */
#define typena(x) _Generic((x), char: "char", default: "other")



int main()  
{
	int x = 0;

	char* bb = typena( x );

	return ( 0 );
}