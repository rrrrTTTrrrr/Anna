#include <iostream> 


using namespace std;

template< typename T >
class Test
{
public:

	Test( T m ) : m_t( m ) {}

	virtual void Display() = 0;

protected:

	T m_t;

private:


};  //  class Test

template< typename T >
class Test1 : public Test< T >
{
public:

	Test1( T m ) : Test< T >( m ) {}

	Test1& operator=( Test1< T > other ) { Test< T >::m_t = other.m_t; }

	Test1& operator=( Test1< T >&& other ) { Test< T >::m_t = other.m_t; }

	void Look() { Display(); }

private:

	virtual void Display() { cout << Test< T >::m_t << endl; }

protected:

private:

};  //  class Test


int main()  
{
	Test1< int > t( 7 );

	t.Look();

	Test1< int > tt = static_cast< Test1< int >&& >( t );


	return ( 0 );
}