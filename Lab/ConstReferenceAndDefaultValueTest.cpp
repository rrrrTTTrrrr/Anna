#include <iostream> 

using namespace std;


class Test
{
public:

	void Foo( const int& uu = 0 ) { cout << uu << endl; }

private:

};  //  class Test



int main()  
{

	try
    {

    	Test jj;

    	jj.Foo();

    	jj.Foo( 98 );

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}