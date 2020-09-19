#include <iostream> 

using namespace std;


#define Test1( DDD, tt ) Test< decltype( DDD ) > tt( DDD )

template< typename T >
class Test
{
public:

	Test( T m ) : m_t( m ) {}

	void Foo() { std::cout << "Lordddd =" << m_t << std::endl; }

private:

	T m_t;

};  //  class Test



int main()  
{

	try
    {

    	Test1( 45, kk );

    	kk.Foo();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}