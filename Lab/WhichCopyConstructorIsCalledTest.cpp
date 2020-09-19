#include <iostream> 


using namespace std;

class Test
{
public:

	Test( int jj ) : m_t( jj ) {}

	Test( const Test& other ) : m_t( other.m_t ) { cout << "Test" << endl; }

	virtual void Display() { cout << "1" << endl; }

private:

	int m_t;

};  //  class Test


class Testing : public Test
{
public:

	Testing( int jj ) : Test( jj ), m_y( new int[78] ) {}

	Testing( const Testing& other ) : Test( other ), m_y( other.m_y ) { cout << "Testing" << endl; }

	virtual void Display() { cout << "2" << endl; }

private:

	int* m_y;

};  //  class Testing


void Poll( Test* test )
{
	test->Display();
}


int main()  
{

	try
    {

    	Testing tt( 78 );

    	Poll( &tt );

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}