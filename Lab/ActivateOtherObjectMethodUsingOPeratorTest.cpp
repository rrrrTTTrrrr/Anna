#include <iostream> 


using namespace std;

class Test
{
public:

	Test() {}

	void Display() { cout << "It worked" << endl; }

	void Display() const { cout << "Wooooowww" << endl; }

private:

};  //  class Test

class Test1
{
public:

	Test1( Test& test ) : m_t( test ) {}

	Test* operator->() { return &m_t; }

	Test const* operator->() const { return &m_t; }

	operator Test() { return m_t; }

private:

	Test& m_t;

};  //  class Test

int main()  
{

	try
    {

    	Test m_t;

    	Test1 m_tt( m_t );

    	const Test1 m_ttt( m_t );

    	m_tt->Display();

    	m_ttt->Display();
    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}