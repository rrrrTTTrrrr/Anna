#include <iostream> 

using namespace std;


class Test
{
public:

	void Lol() {};

private:

};  //  class Test



int main()  
{

	try
    {

    	std::cout << std::is_constructible< Test >::value << std::endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}