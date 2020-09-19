#include <iostream> 

#include "../Root/Content/Metaprogramming/CommonFunctionality/CompareTypes/CompareTypes.hpp"

using namespace std;


class Test
{
public:



private:

};  //  class Test


class Test1 : public Test
{
public:



private:

};  //  class Test



int main()  
{

	try
    {

    	std::cout << Universe::CompareTypes< Test1, Test >::Result() << std::endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}