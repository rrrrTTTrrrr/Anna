#include <iostream> 

using namespace std;




class Test
{
public:

	Test() : m_t( new int[2] ) { m_t[0] = 1; m_t[1] = 2; }

	void Print() { cout << *m_t << endl; }

	friend void operator++( Test& t );

private:

	int* m_t;

};  //  class Test

void operator++( Test& t ) { ++t.m_t; }

int main()  
{

	try
	{

		Test t;

		t.Print();

		++t;

		t.Print();





	}
	catch ( const exception& exception )
	{
		cout << exception.what() << endl;
	}


	return ( 0 );
}
