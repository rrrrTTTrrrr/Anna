#include <iostream> 
#include "../../TheBottom/Types/Metaprogramming/TypeCheck/Constant/TypeCheck_Constant/TypeCheck_Constant.hpp"  //  Class TypeCheck_Constant
#include "../../TheBottom/Types/Metaprogramming/CommonFunctionality/IntegralConstant/IntegralConstant.hpp"
#include "../../TheBottom/Types/Metaprogramming/CommonFunctionality/ChooseBetweenTwoTypes/ChooseBetweenTwoTypes.hpp"
#include "../../TheBottom/Types/Metaprogramming/CommonFunctionality/AssertConditionsOnParameterPack/AssertConditionsOnParameterPack.hpp"

using namespace std;
using namespace Universe;
using namespace Types;


template<typename... Conds>
  struct and_
  : public Types::IntegralConstant< bool, true >
  { };

template<typename Cond, typename... Conds>
  struct and_<Cond, Conds...>
  : public Types::ChooseBetweenTwoTypes<Cond::Value(), and_<Conds...>, Types::IntegralConstant< bool, false >>::Type
  { };


template<typename... T>
  using areCopyConstructible = and_<Types::TypeCheck_Constant<T>...>;


// template< typename... Conditions >
// class AssertConditionsOnParameterPack : public IntegralConstant< Boolean, true >
// {};

// template< typename Condition, typename... Conditions >
// class AssertConditionsOnParameterPack< Condition, Conditions... > : public ChooseBetweenTwoTypes< Condition::Value(), AssertConditionsOnParameterPack< Conditions... >, IntegralConstant< Boolean, false > >::Type
// {};

// template< typename... ParameterPack >
// using DoesParameterPackContainConstantTypes = AssertConditionsOnParameterPack< TypeCheck_Constant< ParameterPack >... >;


int main()  
{

	try
    {

		std::cout << areCopyConstructible< const int, const int, const int >::Value() << std::endl;    	
		std::cout << DoesParameterPackContainConstantTypes< const int, int, const int >::Value() << std::endl;    	


    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}