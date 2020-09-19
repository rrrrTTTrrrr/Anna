#include <iostream> 

using namespace std;


#define Lord( a, b, c, d ) std::cout << a << std::endl << b << std::endl << c << std::endl << d << std::endl;
#define SINGLE_ARG(...) __VA_ARGS__
#define Kas( a ) a::Display();

template< class T, class Y >
class Test
{
public:

	Test() {}

	static void Display() { std::cout << "Fuckkkk" << std::endl; }

private:

};  //  class Test



int main()  
{

	try
    {


    	Kas( Test<int COMMA int> )

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}