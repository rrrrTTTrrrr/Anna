#include <iostream> 

using namespace std;


class Test
{
public:

	virtual void Foo() = 0; 

	virtual ~Test() {}

private:

};  //  class Test


class Test1
{
public:

	virtual void Foo() = 0; 

	virtual ~Test1() {}

private:

};  //  class Test


class Testy : public Test, public Test1
{
public:

	virtual void Foo() { std::cout << "WOwo" << std::endl; }

	virtual ~Testy() {}
};


int main()  
{

	try
    {

    	Testy uu;

    	uu.Foo();

    	Test1* rr = &uu;

    	rr->Foo();

    	Test* rrd = &uu;

    	rrd->Foo();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}