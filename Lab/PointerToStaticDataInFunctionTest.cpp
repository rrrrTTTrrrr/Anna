#include <iostream> 


using namespace std;

char* lol()
{
	static char mm = 'A';

	return ( &mm );
}

template< typename lol, typename UseThisToInitializeStaticMember >
class Wrap
{
public:

	Wrap( UseThisToInitializeStaticMember jj ) { (*jj)( &mm ); std::cout << "Constructor" << std::endl; }

	lol mm;
};

void gggg( int* kk )
{
	*kk = 98;
}

const int* gogo()
{
	static const Wrap< int, void (*)( int* ) > wrrr( gggg );

	std::cout << wrrr.mm << std::endl;

	return ( &wrrr.mm );
}

int main()  
{

	try
    {

    	char* lk = lol();

    	std::cout << *lk << std::endl;

    	gogo();
    	gogo();
    	gogo();
    	gogo();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}