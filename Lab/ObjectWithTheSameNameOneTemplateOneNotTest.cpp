#include <iostream> 

using namespace std;

class Test
{
public:

	Test() { cout << "Whoreeeeeeeeeeeeeeeeeee" << endl; }

private:

};  //  class Test

template< typename Type >
class Test
{
public:

	Test() { cout << "Wow this is nice" << endl; }

private:

};  //  class Test




int main()  
{

	try
    {

    	Test< int > mm;

    	Test yy;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}