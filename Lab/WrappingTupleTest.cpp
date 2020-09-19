#include <iostream> 
#include "../Root/FunctionalityBranch/Level_0/Level_1/Content/BindObjects/Tuple/Tuple.hpp"
#include "../Root/Content/Metaprogramming/CommonFunctionality/Sequences/IncrementingIntegerSequenceGenerator/IncrementingIntegerSequenceGenerator.hpp"

using namespace std;
using namespace Universe;


void Sergio( int uu, short yy, IncrementingIntegerSequenceHolder< ArgumentIndices... > )
{
	std::cout << uu << " " << yy << std::endl;
}


int main()  
{

	try
    {

    	Tuple< int, short > uu( 56, 89 );

    	Sergio( uu );

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}