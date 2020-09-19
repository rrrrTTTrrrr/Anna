#include <iostream> 


using namespace std;


class Test
{
public:

	Test( int s ) : m_s( s ) {}
	virtual void Do() = 0;


private:

	int m_s;

};  //  class Test


class Test1 : public Test
{
public:

	Test1( int s, int d ) : Test( s ), m_d( d ) {}
	virtual void Do() { cout << m_d << endl; }


private:

	int m_d;

};  //  class Test1



int main()  
{

	try
    {

    	Test1 t( 8, 9 );

    	t.Do();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}