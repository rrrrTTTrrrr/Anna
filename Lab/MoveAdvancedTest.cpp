#include <iostream> 

using namespace std;


class Test
{
public:

	void Set( int u ) { ss = u; }

	int Get() { return ( ss ); }

	int&& Move() { return ( std::move( ss ) ); }

	void SetByMove( int&& f ) { ss = f; f = 0; }


	int ss;

};  //  class Test



int main()  
{

	try
    {

    	Test kk;
    	Test ll;

    	kk.Set( 89 );

    	ll.SetByMove( kk.Move() );

    	std::cout << kk.ss << std::endl;
    	std::cout << ll.ss << std::endl;
    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}