#include <iostream> 


using namespace std;


template< typename TYPE >
class Test
{
public:

	Test( TYPE y ) : m_t( y ) {}

	virtual TYPE GetData() const = 0;

	TYPE m_t;

private:

	template< typename OTHER >
    friend inline int operator~( const OTHER& instance );

};  //  class Test

template< typename OTHER >
template< typename TYPEE >
inline int operator~( const OTHER& instance )
{
	return ( ~( instance.GetData() ) );
}

template< typename OO >
class Test1 : public Test< int >
{
public:

	Test1( OO RR ) : Test( 5 ), m_oo( RR ) {}

	virtual int GetData() const { return ( m_t ); }

	OO m_oo;
};





int main()  
{

	try
    {

    	Test1< long > tt( 15 );

    	cout << (~tt) << endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}