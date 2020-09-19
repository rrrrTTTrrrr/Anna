#include <iostream> 

using namespace std;


class Test
{
public:


	template< typename T >
	template< typename Y >
	static void Lord()
	{
		std::cout << "Love" << std::endl;
	}


private:

};  //  class Test



int main()  
{

	try
    {

    	Test::Lord< int >();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}