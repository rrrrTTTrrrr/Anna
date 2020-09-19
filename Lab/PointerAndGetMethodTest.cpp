#include <iostream> 


#include "../../Utilities/DataTypes/Pointer/Pointer.hpp"

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

    	DataTypes::Pointer< int > aa( new int[67], 67 );

    	long* mm = aa.Get< long >();

    	++mm;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}