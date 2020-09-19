#include <iostream> 

using namespace std;


class Test
{
public:

	virtual ~Test() {}

protected:

	virtual void Foo() = 0;

	//void Loo() { std::cout << "Dragon" << std::endl; }

private:

};  //  class Test


class Test1 : protected Test
{
public:

	virtual ~Test1() {}

	//virtual void Foo() { std::cout << "Lordd" << std::endl; }


protected:


};

class Test3 : protected Test
{
public:

	virtual ~Test3() {}

	//virtual void Foo() { std::cout << "Fairy" << std::endl; }


protected:


};


class Test2 : protected Test1, protected Test3
{
public:

	virtual ~Test2() {}

	//virtual void EE() { Loo(); }
	virtual void Foo() { std::cout << "Fairy" << std::endl; }


protected:


};



int main()  
{

	try
    {

    	//Test1 tt;

    	//tt.Foo();

    	Test2 kk;

    	kk.Foo();

    	//Test2 rr;

    	//rr.EE();
    	//rr.Foo();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}