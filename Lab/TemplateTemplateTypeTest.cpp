#include <iostream> 

using namespace std;


template< typename T >
class Test
{
public:

	Test() { std::cout << "Fuck mMy" << std::endl; }

private:

};  //  class Test


template< template< typename > class D, typename F >
class Test2
{
public:

	Test2() { D< F >(); std::cout << "Worked" << std::endl; }
};



int main()  
{

	try
    {

    	Test2< Test, int >();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}