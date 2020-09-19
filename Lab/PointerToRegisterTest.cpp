#include <iostream> 


using namespace std;



register long* pppp asm ( "RAX" );


template< typename T >
class Test
{
public:

	Test() {}



private:

};  //  class Test

int main()  
{

	try
    {
    	long y = 0;



    	__asm__ volatile ( "MOV RAX, 5555\n\t"
    					   "MOV %1, 7888\n\t"
    					   "MOV %0, %1\n\t"
    	          : "=r" ( y )
    	          : "r" ( pppp )
    	          : "memory" );

    	std::cout << y << std::endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}