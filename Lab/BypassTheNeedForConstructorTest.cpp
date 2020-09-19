#include <iostream> 
#include <type_traits>

using namespace std;


template< typename Type >
Type&& BypassTheNeedForConstructor();

template< typename... >
using SequenceOfTypesToVoid = void;

// template< typename, typename = SequenceOfTypesToVoid<> >
// class HasMember_Type : public std::false_type
// {};

// template< typename T >
// class HasMember_Type< T, SequenceOfTypesToVoid< typename T::Type > : public std::true_type
// {};


template< typename, typename = SequenceOfTypesToVoid<> >
class HasMember : public std::false_type
{};

template< typename T >
class HasMember< T, SequenceOfTypesToVoid< decltype( &T::operator+ ) > > : public std::true_type
{};
	
// template< typename, typename = SequenceOfTypesToVoid<> >
// class has_pre_increment_member : public std::false_type 
// {};

// template< typename T >
// class has_pre_increment_member<T, SequenceOfTypesToVoid<decltype( BypassTheNeedForConstructor<T&>().hgjfh )> > : public std::true_type 
// {};




class Test final
{
public:

	Test( const Test& ) {}

	int Foo() {return 9;}
	//static void Hoo() {}

    int operator+(int);

	int grk;

private:

	int hgjfh;

};  //  class Test



//decltype( BypassTheNeedForConstructor< void >() ) Kooo() { std::cout << "Kldf" << std::endl; }

int main()  
{

	try
    {
    	int kk = 89;

    	decltype( BypassTheNeedForConstructor< Test >().Foo() ) jj = kk;

    	std::cout << jj << std::endl;

    	std::cout << HasMember< Test >::value << std::endl;

    	//Kooo();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}