#include <iostream> 

using namespace std;

template< typename T, typename Y >
class Test;

template< typename T >
class Test< T, int >
{
public:

	Test(){}

	Test( const Test< T, int >& other );

	void Display() const { cout << "Good" << endl; }

private:

};  //  class Test

template< typename T >
Test< T, int >::Test( const Test< T, int >& other )
{
	other.Display();
}


int main()  
{

	try
    {

    	Test< int, int > pp;
    	Test< int, int > mm( pp );

    	mm.Display();



    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}