#include <iostream> 

using namespace std;


#define Rolandd( F ) Roland< decltype( F ) >( F )


class Test
{
public:

	template< typename F >
	static void Roland( F jj ) { std::cout << jj << std::endl; }


private:

};  //  class Test



int main()  
{

	try
    {

    	Test::Roland( 56 );

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}