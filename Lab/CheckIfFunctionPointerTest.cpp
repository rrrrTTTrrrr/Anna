#include <stdio.h>
#include <iostream> 

using namespace std;

template< typename T >
class Test : public std::false_type
{

};  //  class Test


template< typename T, typename U >
class Test< T U::* > : public std::true_type
{

};  //  class Test


class RR
{
	void FK() {}
	int DG() const { return 99; }
	void DOG( int, short ) volatile {}
};


// template<class>
// struct is_function : std::false_type { };
 
// // specialization for regular functions
// template<class Ret, class... Args>
// struct is_function<Ret(Args...)> : std::true_type {};
 
// // specialization for variadic functions such as std::printf
// template<class Ret, class... Args>
// struct is_function<Ret(Args......)> : std::true_type {};


void Foo()
{

}


class SOO
{
public:

    int operator()() { std::cout << "Mega" << std::endl; return ( 1234 ); }

};


int main()  
{

	try
    {

        SOO kk;

        kk();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}