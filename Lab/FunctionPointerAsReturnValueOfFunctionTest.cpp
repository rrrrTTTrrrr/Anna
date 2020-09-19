#include <iostream> 

using namespace std;


void Func1( int m )
{
	std::cout << "Wow    " << m << std::endl;
}


using fp = void (*)( int );

fp Roottt()
{
	return ( Func1 );
}



int main()  
{

	try
    {

    	Roottt()( 98 );

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}