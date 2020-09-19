

int main()  
{
	int y = 0;
	__asm__ volatile ( "LOCK ADD DWORD PTR %0, 8"
						: "+im" ( y )
						: "im" (y) : "memory" );

	++y;

    return ( 0 );
}