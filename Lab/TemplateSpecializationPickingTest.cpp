#include <iostream> 

using namespace std;

template< typename... types >
class Test
{
public:

	static void Display() { std::cout << "I am horny" << std::endl; }

private:

};  //  class Test

template< typename first, typename second, typename... types >
class Test< first, second, types... >
{
public:

	static void Display() { std::cout << "Fuck my needs" << std::endl; }

private:

};  //  class Test



int main()  
{

	try
    {

    	Test<>::Display();

    	Test< int >::Display();

    	Test< int, double >::Display();

    	Test< int, int, int >::Display();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}