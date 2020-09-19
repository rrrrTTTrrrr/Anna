#include <iostream> 

using namespace std;



class Test
{
public:

	virtual void Foo() = 0; 

	virtual ~Test() {}

private:

};  //  class Test


class Test1 : public Test
{
public:

	virtual void Foo() { std::cout << "Alfrad" << std::endl; }

	virtual ~Test1() {}

private:

};  //  class Test


class Test4
{
public:

	Test4( int, Test& other ) : mm(other) {}

	virtual ~Test4() {}

	void Dark() { mm.Foo(); }


private:

	Test& mm;


};  //  class Test

class FFF : public Test1, public Test4
{
public:


	FFF() : Test1(), Test4( 8, *this ) {}

};



int main()  
{

	try
    {

    	FFF rr;

    	rr.Dark();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}