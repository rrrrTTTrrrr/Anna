#include <iostream> 

using namespace std;


class Test
{
public:

	virtual static void foo() = 0;

private:

};  //  class Test


class Test1 : public Test
{
public:

	static void foo() {}

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