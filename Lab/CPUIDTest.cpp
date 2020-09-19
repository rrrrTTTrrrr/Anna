#include <iostream> 


using namespace std;
class Test
{
public:



private:

};  //  class Test

int main()  
{

	try
    {

    	unsigned int mm = 0;

    	char buffer[13] = {0};




    	__asm__ volatile ( 	"MOV EAX, 0;"
    						"CPUID;"
    						"MOV %[MM], EAX;"
    						"MOV %[MM1], EBX;"
    						"MOV %[MM2], EDX;"
    						"MOV %[MM3], ECX;"

    						: [MM] "=m" ( mm ), [MM1] "=m" ( *((unsigned int*)buffer) ), [MM2] "=m" ( *(((unsigned int*)buffer) + 1) ), [MM3] "=m" ( *(((unsigned int*)buffer) + 2) )
    						: 
    						: "memory", "%eax", "%ebx", "%ecx", "%edx" );

    	std::cout << mm << std::endl;
    	std::cout << buffer << std::endl;

    	unsigned int gg = 0;


    	unsigned int* tt = &gg;

    	std::cout << tt << std::endl;

    	__asm__ volatile ( "MOV %0, 67;"
    						: "=m" ( *tt )
    						: "m" ( *tt )
    						: "memory");

    	std::cout << gg << std::endl;
    	std::cout << tt << std::endl;
    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}