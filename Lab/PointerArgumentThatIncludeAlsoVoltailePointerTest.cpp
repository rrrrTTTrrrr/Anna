#include <iostream> 

using namespace std;


#define Skill( mm ) Funco< decltype( mm ) >( mm );

template< typename T >
void Funco( T pp )
{
	++pp;
	std::cout << "Worked" << std::endl;
}



int main()  
{

	try
    {

    	int* ii = 0;

    	Skill( ii )

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}