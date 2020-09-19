#include <iostream> 


using namespace std;




void yoo()
{
	__asm__ volatile ( "mov R13, 8888888\n\t" );
}


int main()  
{


	yoo(  );

	long y = 0;


	__asm__ volatile ( "JO dada\n\t"
						"movq %0, 111\n\t"
						"JMP end\n\t"
						"dada:\n\t"
						"movq %0, 222\n\t"
						"end:\n\t"
						: "=ir" (y)
						: : );

	std::cout << y << std::endl;


	long t = 0;

	__asm__ volatile ( "LAHF\n\t"
						"pop ax\n\t"
						"bt ax, 1\n\t"
						"JC dadaa\n\t"
						"movq %0, 333\n\t"
						"JMP endr\n\t"
						"dadaa:\n\t"
						"movq %0, 444\n\t"
						"endr:\n\t"
						: "=ir" (t)
						: : );

	std::cout << t << std::endl;


    return ( 0 );
}