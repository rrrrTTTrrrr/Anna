#include <iostream> 

using namespace std;


template< int N >
class Test
{
public:

	// Test( typename std::enable_if< N == 1, int >::type = 0 ) { std::cout << "Lover" << std::endl; }
	// Test( typename std::enable_if< N != 1, int >::type = 0 ) { std::cout << "Bopy" << std::endl; }




	void Display() {}

private:

};  //  class Test

template< int N >
	typename std::enable_if< N == 1 >::type Testy() { std::cout << "Lover" << std::endl; }

	template< int N >
	typename std::enable_if< N != 1 >::type Testy() { std::cout << "Bopy" << std::endl; }



int main()  
{

	try
    {

    	Testy< 1 >();

    	Testy< 2 >();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}