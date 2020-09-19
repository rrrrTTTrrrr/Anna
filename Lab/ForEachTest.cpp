#include <iostream> 

using namespace std;


class Test
{
public:

	template< typename F >
	void ForEach( const F& rr ) { for ( int i = 0 ; i < 20 ; ++i ) { rr( arr + i ); } }

private:

	int arr[20] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};

};  //  class Test

void Foo( int* ff )
{
	std::cout << *ff << std::endl;
}


class Frr
{
public:

	void Foo( int* ff ) { static int i = 0; arr[i++] = *ff; }

	void operator()(int* ff) { Foo( ff ); }

	void Dos() { for( int i = 0 ; i < 20 ; ++i) { std::cout << arr[i] << std::endl; } }

private:

	int arr[20] = {0};
};


int main()  
{

	try
    {

    	Test yy;

    	yy.ForEach( &Foo );

    	// Frr frr;

    	// frr.Dos();


    	// yy.ForEach( frr );

    	// frr.Dos();

    	yy.ForEach( []( int* ff ) -> void { std::cout<< *ff << std::endl; } );


    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}