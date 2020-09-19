#include <iostream> 

using namespace std;

int Foo( int, int )
{
	std::cout << "Worked" << std::endl;

	return 9;
}

const char* mm;

void Raz()
{
	std::cout << "Worked" << std::endl;

	mm = __FUNCTION__;
}

template< typename T >
class Frr
{

public:


	Frr( T func ) { (*func)( 8, 9); }

	int m_i;


};

template <typename R, typename ... Types> 
constexpr std::integral_constant<unsigned, sizeof ...(Types)> getArgumentCount( R(*)(Types ...))
{
   return std::integral_constant<unsigned, sizeof ...(Types)>{};
}


int uu[4];

int main()  
{

	try
    {

    	std::cout << getArgumentCount( Foo ).value << std::endl;
    	std::cout << getArgumentCount( Raz ).value << std::endl;
    	std::cout << getArgumentCount( Foo ).value << std::endl;
    	Raz();
    	std::cout << mm << std::endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}