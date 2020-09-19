#include <iostream> 
#include <map>
#include <string>
#include <array>

using namespace std;




int main()  
{

	try
    {

    	map< std::array< int, 3 >, int > mm;

    	array< int, 3 > oo = { 1,2,3 };

    	mm[ oo ] = 8;

    	std::cout << mm[ oo ] << std::endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}