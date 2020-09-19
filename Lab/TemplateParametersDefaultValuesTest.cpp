#include <iostream> 


using namespace std;

template< typename T >
class Ass
{
public:
	Ass() { cout << "Lama??" << endl; }
};

template< template< typename T > class Ass, typename L = void >
class Test
{
public:

	Test() { Ass< L > tt; cout << "WOW" << endl; }

private:



};  //  class Test

int main()  
{

	try
    {

    	Test< Ass > m;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}