#include <iostream> 


using namespace std;

class Test
{
public:

	virtual void Display() = 0;

private:

};  //  class Test

class Test1 : public Test
{
public:


private:

};  //  class Test1

class Test2 : public Test1
{
public:

	void Display() { cout << "David" << endl; }

private:

};  //  class Test1

int main()  
{

	try
    {

    	Test2 tt;

    	tt.Display();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}