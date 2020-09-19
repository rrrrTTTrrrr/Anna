#include <iostream> 
#include <functional>
using namespace std;


class Test
{
public:

	int jj()
	{
		std::cout << "WOw" << std::endl;

		return ( 8 );
	}

private:

};  //  class Test

int jj()
{
	std::cout << "WOw" << std::endl;

	return ( 8 );
}

int jj1(int u )
{
	std::cout << u << std::endl;

	return ( 8 );
}

template< typename T >
class Lambda
{
public: 

	Lambda( T lamm ) : lam( lamm ) {}

	void operator()() { lam(); }

private:

	T lam;

};

template< typename L >
void Foo( Lambda< L > jj )
{
	jj();
}

int Goey()
{
	return ( 56 );
}


class Functorrr
{
public:

    void operator()() { std::cout << "Come on" << std::endl; }
};

int main()  
{

	try
    {

    	int uu = 89;

    	std::function< void() > ff = [uu]() -> void { std::cout << uu << std::endl; };

    	ff();

    	std::function< int() > ff1 = jj;

    	ff1();

    	std::function< int(int) > ff2 = jj1;

    	ff2(56);

    	ff2 = [uu](int) -> int { std::cout << uu << std::endl; return ( 8 ); };

    	ff2(445);


    	Lambda mm( [uu]() -> void { std::cout << uu << std::endl; } );

    	mm();

    	Foo( Lambda( [uu]() -> void { std::cout << uu << std::endl; } ) );

    	std::function< int() > ff6 = Goey;

    	std::cout << ff6() << std::endl;

    	Functorrr ggff;
    	std::function gtt( ggff );
    	gtt();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}