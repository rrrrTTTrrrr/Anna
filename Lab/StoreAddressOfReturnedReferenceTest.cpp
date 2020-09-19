#include <iostream> 

using namespace std;


int jsdnjfnjkd = 0;



int& Kff( int& jj )
{
	jj = 9;

	return ( jj );
}




int main()  
{

	try
    {

    	int* kk = &Kff( jsdnjfnjkd );

    	std::cout << *kk << std::endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}