#include <iostream> 

using namespace std;


class Test
{
public:

	void Display() { std::cout << ff << std::endl; }

private:

	int ff;

};  //  class Test



int main()  
{

	try
    {

    	Test yy;

    	yy.Display();

    	Test mm( yy );

    	mm.Display();

    	Test oo;

    	oo = yy;

    	oo = mm;

    	oo.Display();

    	Test jj( std::move( yy ) );

    	jj.Display();

    	jj = std::move( mm );

    	jj.Display();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}