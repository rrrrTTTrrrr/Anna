#include <iostream> 

using namespace std;


class Test
{
public:

	Test() { std::cout << "Yeahh" << std::endl; }

	Test( const Test& other ) : Test() { std::cout << "Fuckkk" << std::endl; other.TT(); }

	void TT() const {}

private:

};  //  class Test



int main()  
{

	try
    {

    	Test tt;

    	Test tt1( tt );

    	tt = tt1;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}