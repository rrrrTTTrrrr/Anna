#include <iostream> 

using namespace std;


template< typename rr >
class Test
{
public:

	Test( rr uu ) : kk(uu) {}

private:

	rr kk;

};  //  class Test

template<>
class Test< int >
{
public:
Test() {}

void Display() { cout << "Youuuu" << endl; }

};


int main()  
{

	try
    {

    	Test< long > oo( 890 );

    	Test< int > uu;

    	uu.Display();



    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}