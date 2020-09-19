#include <iostream>


#include "/home/rrrrtttrrrr/Anna/AnnaVersions/Anna_1093/Root/FunctionalityBranch/Level_0/Level_1/Level_2/Content/FunctionsAndMethods/InvokableObject/InvokableObject.hpp"


#include "/home/rrrrtttrrrr/Anna/AnnaVersions/Anna_1093/Root/FunctionalityBranch/Level_0/Content/Error/Exception/Exception.hpp"


using namespace std;
using namespace Universe;


int Foo()
{
    std::cout << "Wow" << std::endl;

    return ( 8);
}

int Foo1( int )
{
    std::cout << "Wow11111" << std::endl;

    return ( 8);
}

void Foo2( int )
{
    std::cout << "Wow22222" << std::endl;

}

void Foo3( int, int )
{
    std::cout << "Wow33333" << std::endl;

}

class Functorrr
{
public:

    void operator()() { std::cout << "Come on" << std::endl; }
};

class Dumb
{
public:

    void Dumber() { std::cout << "Hiddddad" << std::endl; }
    void Dumber2() const { std::cout << "Hiddddad" << std::endl; }
};

int main()
{

    try
    {

        InvokableObject ll( Foo );
        ll();
        InvokableObject lle( ll );
        lle();

        InvokableObject ll1( Foo1 );
        ll1( 45 );
        InvokableObject ll1e( ll1 );
        ll1e( 45 );

        InvokableObject ll2( Foo2 );
        ll2( 45 );
        InvokableObject ll2e( ll2 );
        ll2e( 45 );

        InvokableObject ll3( Foo3 );
        ll3( 45, 89 );
        InvokableObject ll3e( ll3 );
        ll3e( 45, 89 );

        InvokableObject ll4( []() { std::cout << "Cool" << std::endl; } );
        ll4();
        InvokableObject ll4e( ll4 );
        ll4e();

        int hh = 900;
        InvokableObject ll5( [hh]() { std::cout << hh << std::endl; } );
        ll5();
        InvokableObject ll5e( ll5 );
        ll5e();

        Functorrr dd;
        InvokableObject ll6( dd );
        ll6();
        InvokableObject ll6e( ll6 );
        ll6e();

        const Functorrr dd1;
        InvokableObject ll7( dd1 );
        ll7();
        InvokableObject ll7e( ll7 );
        ll7e();

        Dumb ddd;
        InvokableObject ll8( &Dumb::Dumber );
        ll8( ddd );
        InvokableObject ll8e( ll8 );
        ll8e( ddd );

        const Dumb ddd1;
        InvokableObject ll9( &Dumb::Dumber2 );
        ll9( ddd1 );
        InvokableObject ll9e( ll9 );
        ll9e( ddd1 );

    }
    catch ( const Error::Exception& exception )
    {
    	exception.TellMe();
    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}


