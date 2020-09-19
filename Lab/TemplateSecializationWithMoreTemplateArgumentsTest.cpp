#include <iostream> 

using namespace std;


template< typename Lord, std::size_t gggg = 0 >
class Test
{
public:

	void Dis() { std::cout << "Ghost" << std::endl; }

private:

};  //  class Test


template< typename Lord >
class Test< Lord, 0 >
{
public:

	void Dis() { std::cout << "Ludachris" << std::endl; }

private:

};  //  class Test





int main()  
{

	try
    {

    	Test< int > mm;
    	mm.Dis();

		Test< int, 5 > mm1;
    	mm1.Dis();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}