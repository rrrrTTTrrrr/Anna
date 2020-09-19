#include <iostream> 


template< typename T >
class Test;

template< typename T >
T operator+( T& lhs, Test< T >& rhs );

template< typename T >
class Test
{
public:

	Test( T m ) : m_t( m ) {}

private:

	T m_t;

	friend T operator+<>( T& lhs, Test& rhs );

};  //  class Test


template< typename T >
T operator+( T& lhs, Test< T >& rhs )
{
	return ( lhs + rhs.m_t );
}


int main()  
{
	Test< int > tt( 7 );

	int t = 8;

	std::cout << t + tt << std::endl; 

	return ( 0 );
}