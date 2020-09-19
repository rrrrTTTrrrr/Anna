#include <iostream> 


using namespace std;
template< typename T >
class Test
{
public:

	void Display() { std::cout << "Lord\n"; }

private:

};  //  class Test

class Test1 : private Test< int >
{
};

class Test2 : public Test< int >, public Test1
{};




int main()  
{

	try
    {



    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}