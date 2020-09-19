#include <iostream> 

using namespace std;


template< class T >
class Test
{
public:


	static void Lord() { std::cout << "Annaaaaaa" << std::endl; }


	static int mm;

private:

};  //  class Test

template<>
int Test< int >::mm = 198;

template<>
int Test< double >::mm = 12323;


int main()  
{

	try
    {

    	std::cout << Test< int >::mm << std::endl;
    	std::cout << Test< double >::mm << std::endl;

    	void (*fgg)() = &Test<int>::Lord;

    	(*fgg)();

    	using Type = Test< int >;

    	Type tt;


    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}