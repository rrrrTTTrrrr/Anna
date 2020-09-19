#include <iostream> 


#include "../../Utilities/GeneralPurposeContainers/Know/BasicTypesArithmetic.hpp"

using namespace std;
using namespace Universe;

template< typename TYPE >
class Test : public GeneralPurposeContainers::BasicTypesArithmetic< Test< TYPE >, TYPE >
{
public:

	Test( TYPE yy ) : mm( yy ) {}

	TYPE& Data() { return mm; }

private:

	TYPE mm;

};  //  class Test

int main()  
{
	Test< int > a( 2 );
	Test< int > b( 3 );

	cout << ( a += b ).Data() << endl;




	return ( 0 );
}