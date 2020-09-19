#include <iostream> 

using namespace std;


template< class T >
void Funcc()
{
	std::cout << "Wow" << std::endl;
}



int main()  
{

	try
    {

    	void (*rr)() = &Funcc< int >;

    	(*rr)();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}