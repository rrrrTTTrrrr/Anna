#include <iostream> 
#include "../../BasicFunctionality/Metadata/CheckType/SubstitutionFailureIsNotAnError/ProvideTypeOnlyIfAssertionIsTrue.hpp"

using namespace std;

// #if !defined( _UUUUUUU )
// #error "Fuckkkkkkkkkkkkkkkkkk"
// #endif


// template<bool b, typename std::enable_if<b>::type* = nullptr>
// void my_static_assert() 
// {
//     std::cout << "Assertion OK\n";
// }

// template<>
// void my_static_assert< false, ch >() 
// {
//     std::cout << "Assertion OK,kmkkkkkkkkkk\n";
// }

int main()  
{

	try
    {

    	static_assert( ( 0 > 2 ), "Lolllllllllllllllllllllllll" );
    	// my_static_assert< 0 >();
    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}