#include <iostream> 
#include "../Root/Content/Metaprogramming/CommonFunctionality/CompareTypes/CompareTypes.hpp"
#include "../Root/FunctionalityBranch/Level_0/Level_1/Content/BuiltInTypesWrapper/Bit/Bit.hpp"

using namespace std;
using namespace Universe;


class Test
{
public:



private:

};  //  class Test



int main()  
{

	try
    {

    	std::cout << (int)true << std::endl;
    	std::cout << (int)false << std::endl;


    	std::cout << CompareTypes< Bit< int >, int >::Result() << std::endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}