#include <iostream> 

using namespace std;


template< typename T >
class Test
{
public:

	template< typename Tr, typename std::enable_if< std::is_integral< Tr >::value, int >::type = 0 >
	static inline void Foo( Tr );

	template< typename Tr, typename std::enable_if< std::is_integral< Tr >::value == false, int >::type = 0 >
	static inline void Foo( Tr );


private:

};  //  class Test

template< typename T >
template< typename Tr, typename std::enable_if< std::is_integral< Tr >::value, int >::type >
inline void Test< T >::Foo( Tr ) { std::cout << "Love" << std::endl; }

template< typename T >
template< typename Tr, typename std::enable_if< std::is_integral< Tr >::value == false, int >::type >
inline void Test< T >::Foo( Tr ) { std::cout << "Me" << std::endl; }


int main()  
{

	try
    {

    	Test< int >::Foo( std::string() );

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}