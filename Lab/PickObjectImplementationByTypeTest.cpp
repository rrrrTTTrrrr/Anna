#include <iostream> 

#include "../../TheBottom/Types/TypeChecks/CommonFunctionality/SubstitutionFailureIsNotAnError/ProvideTypeOnlyIfAssertionIsTrue/ProvideTypeOnlyIfAssertionIsTrue.hpp"

using namespace std;
using namespace Universe;


template< int tt >
class Test
{
public:

	Test( typename Types::ProvideTypeOnlyIfAssertionIsTrue< tt == 8 >::Type* = nullptr ) { cout << "Yeah" << endl; }
	Test( typename Types::ProvideTypeOnlyIfAssertionIsTrue< tt == 9 >::Type* = nullptr ) { cout << "No" << endl; }

private:

};  //  class Test



int main()  
{

	try
    {

    	Test< 8 > uu;
    	Test< 9 > yy;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}