#include <iostream> 


using namespace std;


class Test
{
public:

	static Test& GetHandle() { static Test t; cout << &t << endl; return ( t ); }

	~Test() { cout << "Destructor" << endl; }

	void Dis() {}

private:

	Test() { cout << "Constructor" << endl; }

};  //  class Test

int main()  
{
	Test& t = Test::GetHandle();

	cout << "In dis - " << &t << endl;

	t.Dis();

	return ( 0 );
}