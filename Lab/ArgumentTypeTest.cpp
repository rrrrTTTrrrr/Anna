#include <iostream> 


using namespace std;



template<typename T> struct argument_type;
template<typename T, typename U> struct argument_type<T(U)> { typedef U type; };


int main()  
{
	int y = 8;
	
	argument_type< void( y ) >::type m = 9;

	m += 9;

	cout << m << endl;


	return ( 0 );
}