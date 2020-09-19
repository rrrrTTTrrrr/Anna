#include <iostream>
#include <sys/syscall.h>
#include <unistd.h>





int main()  
{
	// syscall( SYS_write, 1, "Hello, world!\n", 14 );

	// const char* pp = "Livingggggggg";

	// __asm__ volatile ( "MOVQ RAX, 4\n\t"
	// 				   "MOVQ RDI, 1\n\t"
	// 				   "MOVQ RSI, %0\n\t"
	// 				   "MOVQ RDX, 13\n\t"
	// 				   "SYSCALL\n\t"
	// 				   :
	// 				   : "ir" ( pp )
	// 				   : );


	// register long mm asm("RDX") = 89;

	__asm__ volatile ( "MOVQ RAX, 66\n\t" );

	// std::cout << mm << std::endl;
	std::cout << __NR_read << std::endl;
	std::cout << __NR_write << std::endl;
	std::cout << __NR_lseek << std::endl;

    return ( 0 );
}