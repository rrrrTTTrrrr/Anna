#include <iostream> 


using namespace std;
class Test
{
public:



private:

};  //  class Test



void Display( Args... args )
{
	cout << "Worked" << endl;
}


template< typename FuncSig, typename  >
void Call( FuncSig* func, Args... args )
{
	(*func)( args );
}





int main()  
{

	try
    {

    	Call< void (*)( Args... args ) >( &Display, 8, 9, 10 );

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}