#include <iostream> 
#include <thread>

using namespace std;
class Test
{
public:



private:

};  //  class Test



void One( unsigned long* address )
{
	unsigned long counter = 0;


	for ( unsigned long index = 0 ; index < 10000000 ; ++index )
	{

            __asm__ volatile ( 	"MOV RAX, 1;"
            					"LOCK XADD %[Address], RAX;"
            					"CMP RAX, 1;"
            					"JNE END%=;"
            					"INC %[Counter];"
            					"END%=:"
                                : [Address] "+m" ( *address ), [Counter] "=m" ( counter )
                                : "m" ( *address ) 
                                : "memory", "cc", "%rax" );                                                                 

    }

    std::cout << counter << std::endl;
}

void Two( unsigned long* address )
{
	unsigned long counter = 0;


	for ( unsigned long index = 0 ; index < 10000000 ; ++index )
	{

            __asm__ volatile ( 	"MOV RAX, 2;"
            					"LOCK XCHG %[Address], RAX;"
            					"CMP RAX, 2;"
            					"JNE END%=;"
            					"INC %[Counter];"
            					"END%=:"
                                : [Address] "+m" ( *address ), [Counter] "=m" ( counter )
                                : "m" ( *address ) 
                                : "memory", "cc", "%rax" );                                                                 

    }

    std::cout << counter << std::endl;
}


typedef struct ll
{
	char jj[789];
	unsigned long cos;
}Goro;


 		Goro pp;

int main()  
{

	try
    {


 		pp.cos = 69;
 		   	
    	std::thread tt( &One, &pp.cos );
    	std::thread tt1( &One, &pp.cos );
    	std::thread tt2( &One, &pp.cos );
    	std::thread tt3( &One, &pp.cos );
    	std::thread tt4( &One, &pp.cos );
    	std::thread tt5( &One, &pp.cos );
    	std::thread tt6( &One, &pp.cos );
    	std::thread tt7( &One, &pp.cos );
    	std::thread tt8( &One, &pp.cos );    	
    	std::thread tt9( &One, &pp.cos );
    	std::thread tt10( &One, &pp.cos );
    	std::thread tt11( &One, &pp.cos );
    	std::thread tt12( &One, &pp.cos );
    	std::thread tt13( &One, &pp.cos );
    	std::thread tt14( &One, &pp.cos );
    	std::thread tt15( &One, &pp.cos );
    	std::thread tt16( &One, &pp.cos );
    	std::thread tt17( &One, &pp.cos );
    	std::thread tt18( &One, &pp.cos );

    	std::thread tt19( &Two, &pp.cos );
    	std::thread tt20( &Two, &pp.cos );
    	std::thread tt21( &Two, &pp.cos );
    	std::thread tt22( &Two, &pp.cos );
    	std::thread tt23( &Two, &pp.cos );
    	std::thread tt24( &Two, &pp.cos );
    	std::thread tt25( &Two, &pp.cos );
    	std::thread tt26( &Two, &pp.cos );
    	std::thread tt27( &Two, &pp.cos );    	
    	std::thread tt28( &Two, &pp.cos );
    	std::thread tt29( &Two, &pp.cos );
    	std::thread tt30( &Two, &pp.cos );
    	std::thread tt31( &Two, &pp.cos );
    	std::thread tt32( &Two, &pp.cos );
    	std::thread tt33( &Two, &pp.cos );
    	std::thread tt34( &Two, &pp.cos );
    	std::thread tt35( &Two, &pp.cos );
    	std::thread tt36( &Two, &pp.cos );
    	std::thread tt37( &Two, &pp.cos );

    	unsigned long lkj = 0;

    	for ( unsigned long i = 0 ; i < 100000000 ; ++i )
    	{
    		++pp.jj[i%789];

    		lkj = pp.cos;

    		++lkj;
    	}

    	tt.join();
    	tt1.join();
    	tt2.join();
    	tt3.join();
    	tt4.join();
    	tt5.join();
    	tt6.join();
    	tt7.join();
    	tt8.join();
    	tt9.join();
    	tt10.join();
    	tt11.join();
    	tt12.join();
    	tt13.join();
    	tt14.join();
    	tt15.join();
    	tt16.join();
    	tt17.join();
    	tt18.join();
    	tt19.join();
    	tt20.join();
    	tt21.join();
    	tt22.join();
    	tt23.join();
    	tt24.join();
    	tt25.join();
    	tt26.join();
    	tt27.join();
    	tt28.join();
    	tt29.join();
    	tt30.join();
    	tt31.join();
    	tt32.join();
    	tt33.join();
    	tt34.join();
    	tt35.join();
    	tt36.join();
    	tt37.join();

    	std::cout << pp.cos << std::endl;


    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}