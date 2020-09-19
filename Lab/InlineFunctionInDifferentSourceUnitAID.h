

#include <iostream>




template< typename T >
class Test
{
public:

	Test( int yy ) : m_t( new T ) { *m_t = yy; }

private:

	T* m_t;

	template< typename O >
	friend inline void Display( Test< O >& oo );
};



template< typename O >
inline void Display( Test< O >& oo )
{
	std::cout << *oo.m_t << std::endl;
}