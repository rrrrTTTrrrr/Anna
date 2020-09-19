#include <iostream> 
#include <string>
#include "../../TheBottom/Types/Metaprogramming/CommonFunctionality/AssertConditionsOnParameterPack/AssertConditionsOnParameterPack_OR.hpp"
#include "../../TheBottom/Types/Metaprogramming/CommonFunctionality/SubstitutionFailureIsNotAnError/ProvideTypeOnlyIfAssertionIsTrue/ProvideTypeOnlyIfAssertionIsTrue.hpp"


using namespace std;
using namespace Universe;



template< typename Ex, typename Enable = void, typename... TT >
class Test;

template< typename Ex, typename... TT >
class Test< Ex, typename std::enable_if< std::is_integral< Ex >::value >::type, TT... >
{
public:

	void Display() { std::cout << "1" << std::endl; }

private:

};  //  class Test

template< typename Ex, typename... TT >
class Test< Ex, typename std::enable_if< std::is_integral< Ex >::value == false >::type, TT... >
{
public:

	void Display() { std::cout << "2" << std::endl; }

private:

};  //  class Test



template< typename Ex = void, typename... TT >
class Test_1;

template< typename... TT >
class Test_1< typename Types::ProvideTypeOnlyIfAssertionIsTrue< Types::DoesParameterPackContainAtLeastOneConstantType< TT... >::Value() == false && Types::DoesParameterPackContainAtLeastOneReferenceType< TT... >::Value() == false >::Type, TT... >
{
public:

	void Display() { std::cout << "1" << std::endl; }

private:

};  //  class Test_1

template< typename... TT >
class Test_1< typename Types::ProvideTypeOnlyIfAssertionIsTrue< Types::DoesParameterPackContainAtLeastOneConstantType< TT... >::Value() == true >::Type, TT... >
{
public:

	void Display() { std::cout << "2" << std::endl; std::cout << Types::DoesParameterPackContainAtLeastOneConstantType< Ex, TT... >::Value() << std::endl; }

private:

};  //  class Test_1


int main()  
{

	try
    {

    	Test< int > tt;

    	tt.Display();

    	Test< std::string > tt1;

    	tt1.Display();

    	Test_1< void > tt2;

    	tt2.Display();

    	Test_1< void, int, const long > tt3;

    	tt3.Display();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}