#include <iostream> 
#include "../../TheBottom/Types/Metaprogramming/CommonFunctionality/IntegralConstant/IntegralConstant.hpp"


using namespace std;
using namespace Universe;


template< typename TT >
class ConstantOrNot : public Types::IntegralConstant< bool, false >
{};

template< typename TT >
class ConstantOrNot< const TT > : public Types::IntegralConstant< bool, true >
{};



int main()  
{

	try
    {

    	std::cout << ConstantOrNot< int >::Value() << std::endl;
    	std::cout << ConstantOrNot< const int >::Value() << std::endl;
    	std::cout << ConstantOrNot< std::string >::Value() << std::endl;
    	std::cout << ConstantOrNot< const std::string >::Value() << std::endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}