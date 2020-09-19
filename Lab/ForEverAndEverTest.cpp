#include <iostream> 

using namespace std;


template< typename... Ts >
class Test
{
public:

	Test( Ts... )  {  }

	void Dis() { std::cout << "Lord" << std::endl; }

	template< typename... Ss >
	void ff( Ss... rr ) { Test< Ss... > tt( rr... ); tt.Dis(); }

private:

	int m;
	int i;

};  //  class Test



int main()  
{

	try
    {

    	Test< int, int > mm( 5,6 );

    	mm.ff< int, int >( 8, 9 );

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}