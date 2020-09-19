#include <iostream> 


using namespace std;
class Test
{
public:



private:

};  //  class Test

#define Kot( tt ) \
\
	std::cout << #tt << std::endl;\
\
	std::cout << "COOL" << std::endl;\

#define STRINGIFY(x) #x

#define Lol( tt ) std::cout << #tt"Lorde" << std::endl;

#define Templatell( yy, tt ) \
\
class yy ## Lord\
{\
public:\
	yy ## Lord( int j ) : m_i( j ) { std::cout << #tt << std::endl; }\
 	yy ## Lord operator tt( const yy ## Lord& other ) const { return ( yy ## Lord( m_i tt other.m_i ) ); }\
 	void Display() { std::cout << m_i << std::endl; }\
private:\
	int m_i;\
};\

Templatell( ro, + )


int main()  
{

	try
    {

    	Kot( + )

    	roLord LL( 9 );
    	roLord LL1( 10 );

    	roLord LL2 = ( LL + LL1 );

    	LL2.Display();

    	Lol( Man )
    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}