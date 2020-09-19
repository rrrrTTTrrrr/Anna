#include <iostream> 


using namespace std;


#define Move( Y ) static_cast< decltype( Y )&& >( Y )



class Test
{
public:

	Test() : m_t( new int[8] ) {}
	~Test() { delete m_t; }
	Test( Test&& other ) : m_t( other.m_t ) { other.m_t = 0; cout << "Move constructor" << endl; }
	Test& operator=( Test&& other ) { m_t = other.m_t; other.m_t = 0; cout << "Move assigenment operator" << endl; return ( *this ); }

private:

	int* m_t;

};  //  class Test

int main()  
{

	try
    {

    	Test mm;

    	Test mm1;

    	mm1 = Move( mm );



    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}