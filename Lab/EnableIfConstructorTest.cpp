#include <iostream> 

using namespace std;

template< typename T >
class Test
{
public:

	template< typename U = int, typename std::enable_if< std::is_integral< U >::value >::type* = nullptr >
	Test() { std::cout << "Lord" << std::endl; }

	template< typename std::enable_if< std::is_same< T, double >::value >::type* = nullptr >
	Test() { std::cout << "Wowww" << std::endl; }

	void SI() {}

private:

};  //  class Test



int main()  
{

	try
    {

    	Test< int > uu;

    	uu.SI();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}