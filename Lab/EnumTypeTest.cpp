#include <iostream> 

using namespace std;


class Test
{
public:

	Test() = delete;

	Test( const Test& other ) = delete;
	Test( Test&& other ) = delete;
	Test& operator=( const Test& other ) = delete;
	Test& operator=( Test&& other ) = delete;

	~Test() = delete;


};  //  class Test

template< typename T >
class Foo
{
public:

	Foo() { std::cout << "Lord" << std::endl; }
};


int main()  
{

	try
    {

    	Foo< Test >();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}