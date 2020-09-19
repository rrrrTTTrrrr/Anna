#include <iostream> 

using namespace std;



template< typename Fract >
class Test
{
public:



private:

};  //  class Test


template<>
class Test< 89 >
{
public:



private:

};  //  class Test



int main()  
{

	try
    {



    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}