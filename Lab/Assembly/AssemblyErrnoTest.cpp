#include <unistd.h>
#include <errno.h>

int main()  
{

	char buffer[100] = {0};

	read( 0, buffer, 2 );

 errno = 3; return 0;
}