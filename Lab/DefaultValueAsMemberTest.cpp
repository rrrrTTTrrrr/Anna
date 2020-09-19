#include <iostream> 

using namespace std;


class Test
{
public:


	void tgh( int kk = Slook ) { std::cout << kk << std::endl; }

	static int Slook;

};  //  class Test

int Test::Slook = 89;

int main()  
{

	try
    {

    	Test ll;

    	ll.tgh();

    	Test::Slook = 789;

    	ll.tgh();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}