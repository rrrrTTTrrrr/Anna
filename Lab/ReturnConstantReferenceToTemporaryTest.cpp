#include <iostream> 

using namespace std;


class Test
{
public:

	void Dis() const { std::cout << "Godddddd" << std::endl; }

private:

};  //  class Test



Test gg()
{
	return ( Test() );
}



int main()  
{

	try
    {

    	Test& uu = gg();

    	uu.Dis();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}