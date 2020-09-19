#include <iostream> 

using namespace std;


class Boo
{
public:

	Boo( int oo ) : m_i( oo ) {}

private:

	int m_i;
};

class Chaka
{
public:

	Chaka( double oo ) : m_i( oo ) {}

private:

	double m_i;
};

class Test
{
public:

	Test( Boo, Chaka ) { std::cout << "Lobby" << std::endl; }

private:

};  //  class Test



int main()  
{

	try
    {

    	Test( 89, 98.8909 );

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}